/* c/zx-md-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-md-data.h"



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

#define EL_NAME   md_AdditionalMetadataLocation
#define EL_STRUCT zx_md_AdditionalMetadataLocation_s
#define EL_NS     md
#define EL_TAG    AdditionalMetadataLocation

/* FUNC(zx_FREE_md_AdditionalMetadataLocation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->namespace_is_cxx_keyword, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AdditionalMetadataLocation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AdditionalMetadataLocation_s* zx_NEW_md_AdditionalMetadataLocation(struct zx_ctx* c)
{
  struct zx_md_AdditionalMetadataLocation_s* x = ZX_ZALLOC(c, struct zx_md_AdditionalMetadataLocation_s);
  x->gg.g.tok = zx_md_AdditionalMetadataLocation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AdditionalMetadataLocation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->namespace_is_cxx_keyword);


}

/* FUNC(zx_DEEP_CLONE_md_AdditionalMetadataLocation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AdditionalMetadataLocation_s* zx_DEEP_CLONE_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x, int dup_strs)
{
  x = (struct zx_md_AdditionalMetadataLocation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AdditionalMetadataLocation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->namespace_is_cxx_keyword = zx_clone_attr(c, x->namespace_is_cxx_keyword);


  return x;
}

/* FUNC(zx_WALK_SO_md_AdditionalMetadataLocation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_AdditionalMetadataLocation) */

int zx_WALK_WO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AffiliationDescriptor
#define EL_STRUCT zx_md_AffiliationDescriptor_s
#define EL_NS     md
#define EL_TAG    AffiliationDescriptor

/* FUNC(zx_FREE_md_AffiliationDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->affiliationOwnerID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AffiliateMember, free_strs);
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AffiliationDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AffiliationDescriptor_s* zx_NEW_md_AffiliationDescriptor(struct zx_ctx* c)
{
  struct zx_md_AffiliationDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_AffiliationDescriptor_s);
  x->gg.g.tok = zx_md_AffiliationDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AffiliationDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->affiliationOwnerID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AffiliateMember);
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_AffiliationDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AffiliationDescriptor_s* zx_DEEP_CLONE_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_AffiliationDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AffiliationDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->affiliationOwnerID = zx_clone_attr(c, x->affiliationOwnerID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AffiliateMember = zx_deep_clone_simple_elems(c,x->AffiliateMember, dup_strs);
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_AffiliationDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AffiliateMember, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_AffiliationDescriptor) */

int zx_WALK_WO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_ArtifactResolutionService
#define EL_STRUCT zx_md_ArtifactResolutionService_s
#define EL_NS     md
#define EL_TAG    ArtifactResolutionService

/* FUNC(zx_FREE_md_ArtifactResolutionService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_ArtifactResolutionService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_ArtifactResolutionService_s* zx_NEW_md_ArtifactResolutionService(struct zx_ctx* c)
{
  struct zx_md_ArtifactResolutionService_s* x = ZX_ZALLOC(c, struct zx_md_ArtifactResolutionService_s);
  x->gg.g.tok = zx_md_ArtifactResolutionService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_ArtifactResolutionService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_ArtifactResolutionService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_ArtifactResolutionService_s* zx_DEEP_CLONE_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x, int dup_strs)
{
  x = (struct zx_md_ArtifactResolutionService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_ArtifactResolutionService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_ArtifactResolutionService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_ArtifactResolutionService) */

int zx_WALK_WO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AssertionConsumerService
#define EL_STRUCT zx_md_AssertionConsumerService_s
#define EL_NS     md
#define EL_TAG    AssertionConsumerService

/* FUNC(zx_FREE_md_AssertionConsumerService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AssertionConsumerService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AssertionConsumerService_s* zx_NEW_md_AssertionConsumerService(struct zx_ctx* c)
{
  struct zx_md_AssertionConsumerService_s* x = ZX_ZALLOC(c, struct zx_md_AssertionConsumerService_s);
  x->gg.g.tok = zx_md_AssertionConsumerService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AssertionConsumerService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_AssertionConsumerService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AssertionConsumerService_s* zx_DEEP_CLONE_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x, int dup_strs)
{
  x = (struct zx_md_AssertionConsumerService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AssertionConsumerService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_AssertionConsumerService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_AssertionConsumerService) */

int zx_WALK_WO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AssertionIDRequestService
#define EL_STRUCT zx_md_AssertionIDRequestService_s
#define EL_NS     md
#define EL_TAG    AssertionIDRequestService

/* FUNC(zx_FREE_md_AssertionIDRequestService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AssertionIDRequestService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AssertionIDRequestService_s* zx_NEW_md_AssertionIDRequestService(struct zx_ctx* c)
{
  struct zx_md_AssertionIDRequestService_s* x = ZX_ZALLOC(c, struct zx_md_AssertionIDRequestService_s);
  x->gg.g.tok = zx_md_AssertionIDRequestService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AssertionIDRequestService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_AssertionIDRequestService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AssertionIDRequestService_s* zx_DEEP_CLONE_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x, int dup_strs)
{
  x = (struct zx_md_AssertionIDRequestService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AssertionIDRequestService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_AssertionIDRequestService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_AssertionIDRequestService) */

int zx_WALK_WO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AttributeAuthorityDescriptor
#define EL_STRUCT zx_md_AttributeAuthorityDescriptor_s
#define EL_NS     md
#define EL_TAG    AttributeAuthorityDescriptor

/* FUNC(zx_FREE_md_AttributeAuthorityDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->errorURL, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_md_AttributeService_s* e;
      struct zx_md_AttributeService_s* en;
      for (e = x->AttributeService; e; e = en) {
	  en = (struct zx_md_AttributeService_s*)e->gg.g.n;
	  zx_FREE_md_AttributeService(c, e, free_strs);
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      for (e = x->AssertionIDRequestService; e; e = en) {
	  en = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n;
	  zx_FREE_md_AssertionIDRequestService(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NameIDFormat, free_strs);
  zx_free_simple_elems(c, x->AttributeProfile, free_strs);
  {
      struct zx_sa_Attribute_s* e;
      struct zx_sa_Attribute_s* en;
      for (e = x->Attribute; e; e = en) {
	  en = (struct zx_sa_Attribute_s*)e->gg.g.n;
	  zx_FREE_sa_Attribute(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AttributeAuthorityDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AttributeAuthorityDescriptor_s* zx_NEW_md_AttributeAuthorityDescriptor(struct zx_ctx* c)
{
  struct zx_md_AttributeAuthorityDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_AttributeAuthorityDescriptor_s);
  x->gg.g.tok = zx_md_AttributeAuthorityDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AttributeAuthorityDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->errorURL);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AttributeService_s* e;
      for (e = x->AttributeService; e; e = (struct zx_md_AttributeService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AttributeService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AssertionIDRequestService(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NameIDFormat);
  zx_dup_strs_simple_elems(c, x->AttributeProfile);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Attribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_AttributeAuthorityDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AttributeAuthorityDescriptor_s* zx_DEEP_CLONE_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_AttributeAuthorityDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AttributeAuthorityDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->errorURL = zx_clone_attr(c, x->errorURL);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AttributeService_s* e;
      struct zx_md_AttributeService_s* en;
      struct zx_md_AttributeService_s* enn;
      for (enn = 0, e = x->AttributeService; e; e = (struct zx_md_AttributeService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AttributeService(c, e, dup_strs);
	  if (!enn)
	      x->AttributeService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      struct zx_md_AssertionIDRequestService_s* enn;
      for (enn = 0, e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AssertionIDRequestService(c, e, dup_strs);
	  if (!enn)
	      x->AssertionIDRequestService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NameIDFormat = zx_deep_clone_simple_elems(c,x->NameIDFormat, dup_strs);
  x->AttributeProfile = zx_deep_clone_simple_elems(c,x->AttributeProfile, dup_strs);
  {
      struct zx_sa_Attribute_s* e;
      struct zx_sa_Attribute_s* en;
      struct zx_sa_Attribute_s* enn;
      for (enn = 0, e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Attribute(c, e, dup_strs);
	  if (!enn)
	      x->Attribute = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_AttributeAuthorityDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AttributeService_s* e;
      for (e = x->AttributeService; e; e = (struct zx_md_AttributeService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AttributeService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AssertionIDRequestService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NameIDFormat, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AttributeProfile, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Attribute(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_AttributeAuthorityDescriptor) */

int zx_WALK_WO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AttributeConsumingService
#define EL_STRUCT zx_md_AttributeConsumingService_s
#define EL_NS     md
#define EL_TAG    AttributeConsumingService

/* FUNC(zx_FREE_md_AttributeConsumingService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);

  {
      struct zx_md_ServiceName_s* e;
      struct zx_md_ServiceName_s* en;
      for (e = x->ServiceName; e; e = en) {
	  en = (struct zx_md_ServiceName_s*)e->gg.g.n;
	  zx_FREE_md_ServiceName(c, e, free_strs);
      }
  }
  {
      struct zx_md_ServiceDescription_s* e;
      struct zx_md_ServiceDescription_s* en;
      for (e = x->ServiceDescription; e; e = en) {
	  en = (struct zx_md_ServiceDescription_s*)e->gg.g.n;
	  zx_FREE_md_ServiceDescription(c, e, free_strs);
      }
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      struct zx_md_RequestedAttribute_s* en;
      for (e = x->RequestedAttribute; e; e = en) {
	  en = (struct zx_md_RequestedAttribute_s*)e->gg.g.n;
	  zx_FREE_md_RequestedAttribute(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AttributeConsumingService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AttributeConsumingService_s* zx_NEW_md_AttributeConsumingService(struct zx_ctx* c)
{
  struct zx_md_AttributeConsumingService_s* x = ZX_ZALLOC(c, struct zx_md_AttributeConsumingService_s);
  x->gg.g.tok = zx_md_AttributeConsumingService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AttributeConsumingService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);

  {
      struct zx_md_ServiceName_s* e;
      for (e = x->ServiceName; e; e = (struct zx_md_ServiceName_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ServiceName(c, e);
  }
  {
      struct zx_md_ServiceDescription_s* e;
      for (e = x->ServiceDescription; e; e = (struct zx_md_ServiceDescription_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ServiceDescription(c, e);
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      for (e = x->RequestedAttribute; e; e = (struct zx_md_RequestedAttribute_s*)e->gg.g.n)
	  zx_DUP_STRS_md_RequestedAttribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_AttributeConsumingService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AttributeConsumingService_s* zx_DEEP_CLONE_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x, int dup_strs)
{
  x = (struct zx_md_AttributeConsumingService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AttributeConsumingService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);

  {
      struct zx_md_ServiceName_s* e;
      struct zx_md_ServiceName_s* en;
      struct zx_md_ServiceName_s* enn;
      for (enn = 0, e = x->ServiceName; e; e = (struct zx_md_ServiceName_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ServiceName(c, e, dup_strs);
	  if (!enn)
	      x->ServiceName = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ServiceDescription_s* e;
      struct zx_md_ServiceDescription_s* en;
      struct zx_md_ServiceDescription_s* enn;
      for (enn = 0, e = x->ServiceDescription; e; e = (struct zx_md_ServiceDescription_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ServiceDescription(c, e, dup_strs);
	  if (!enn)
	      x->ServiceDescription = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      struct zx_md_RequestedAttribute_s* en;
      struct zx_md_RequestedAttribute_s* enn;
      for (enn = 0, e = x->RequestedAttribute; e; e = (struct zx_md_RequestedAttribute_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_RequestedAttribute(c, e, dup_strs);
	  if (!enn)
	      x->RequestedAttribute = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_AttributeConsumingService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_md_ServiceName_s* e;
      for (e = x->ServiceName; e; e = (struct zx_md_ServiceName_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ServiceName(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ServiceDescription_s* e;
      for (e = x->ServiceDescription; e; e = (struct zx_md_ServiceDescription_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ServiceDescription(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      for (e = x->RequestedAttribute; e; e = (struct zx_md_RequestedAttribute_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_RequestedAttribute(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_AttributeConsumingService) */

int zx_WALK_WO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AttributeService
#define EL_STRUCT zx_md_AttributeService_s
#define EL_NS     md
#define EL_TAG    AttributeService

/* FUNC(zx_FREE_md_AttributeService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AttributeService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AttributeService_s* zx_NEW_md_AttributeService(struct zx_ctx* c)
{
  struct zx_md_AttributeService_s* x = ZX_ZALLOC(c, struct zx_md_AttributeService_s);
  x->gg.g.tok = zx_md_AttributeService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AttributeService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_AttributeService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AttributeService_s* zx_DEEP_CLONE_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x, int dup_strs)
{
  x = (struct zx_md_AttributeService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AttributeService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_AttributeService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_AttributeService) */

int zx_WALK_WO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AuthnAuthorityDescriptor
#define EL_STRUCT zx_md_AuthnAuthorityDescriptor_s
#define EL_NS     md
#define EL_TAG    AuthnAuthorityDescriptor

/* FUNC(zx_FREE_md_AuthnAuthorityDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->errorURL, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      struct zx_md_AuthnQueryService_s* en;
      for (e = x->AuthnQueryService; e; e = en) {
	  en = (struct zx_md_AuthnQueryService_s*)e->gg.g.n;
	  zx_FREE_md_AuthnQueryService(c, e, free_strs);
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      for (e = x->AssertionIDRequestService; e; e = en) {
	  en = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n;
	  zx_FREE_md_AssertionIDRequestService(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NameIDFormat, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AuthnAuthorityDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AuthnAuthorityDescriptor_s* zx_NEW_md_AuthnAuthorityDescriptor(struct zx_ctx* c)
{
  struct zx_md_AuthnAuthorityDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_AuthnAuthorityDescriptor_s);
  x->gg.g.tok = zx_md_AuthnAuthorityDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AuthnAuthorityDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->errorURL);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      for (e = x->AuthnQueryService; e; e = (struct zx_md_AuthnQueryService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AuthnQueryService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AssertionIDRequestService(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NameIDFormat);

}

/* FUNC(zx_DEEP_CLONE_md_AuthnAuthorityDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AuthnAuthorityDescriptor_s* zx_DEEP_CLONE_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_AuthnAuthorityDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AuthnAuthorityDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->errorURL = zx_clone_attr(c, x->errorURL);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      struct zx_md_AuthnQueryService_s* en;
      struct zx_md_AuthnQueryService_s* enn;
      for (enn = 0, e = x->AuthnQueryService; e; e = (struct zx_md_AuthnQueryService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AuthnQueryService(c, e, dup_strs);
	  if (!enn)
	      x->AuthnQueryService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      struct zx_md_AssertionIDRequestService_s* enn;
      for (enn = 0, e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AssertionIDRequestService(c, e, dup_strs);
	  if (!enn)
	      x->AssertionIDRequestService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NameIDFormat = zx_deep_clone_simple_elems(c,x->NameIDFormat, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_md_AuthnAuthorityDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      for (e = x->AuthnQueryService; e; e = (struct zx_md_AuthnQueryService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AuthnQueryService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AssertionIDRequestService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NameIDFormat, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_AuthnAuthorityDescriptor) */

int zx_WALK_WO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AuthnQueryService
#define EL_STRUCT zx_md_AuthnQueryService_s
#define EL_NS     md
#define EL_TAG    AuthnQueryService

/* FUNC(zx_FREE_md_AuthnQueryService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AuthnQueryService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AuthnQueryService_s* zx_NEW_md_AuthnQueryService(struct zx_ctx* c)
{
  struct zx_md_AuthnQueryService_s* x = ZX_ZALLOC(c, struct zx_md_AuthnQueryService_s);
  x->gg.g.tok = zx_md_AuthnQueryService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AuthnQueryService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_AuthnQueryService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AuthnQueryService_s* zx_DEEP_CLONE_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x, int dup_strs)
{
  x = (struct zx_md_AuthnQueryService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AuthnQueryService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_AuthnQueryService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_AuthnQueryService) */

int zx_WALK_WO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_AuthzService
#define EL_STRUCT zx_md_AuthzService_s
#define EL_NS     md
#define EL_TAG    AuthzService

/* FUNC(zx_FREE_md_AuthzService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_AuthzService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_AuthzService_s* zx_NEW_md_AuthzService(struct zx_ctx* c)
{
  struct zx_md_AuthzService_s* x = ZX_ZALLOC(c, struct zx_md_AuthzService_s);
  x->gg.g.tok = zx_md_AuthzService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_AuthzService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_AuthzService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_AuthzService_s* zx_DEEP_CLONE_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x, int dup_strs)
{
  x = (struct zx_md_AuthzService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_AuthzService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_AuthzService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_AuthzService) */

int zx_WALK_WO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_ContactPerson
#define EL_STRUCT zx_md_ContactPerson_s
#define EL_NS     md
#define EL_TAG    ContactPerson

/* FUNC(zx_FREE_md_ContactPerson) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->contactType, free_strs);

  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Company, free_strs);
  zx_free_simple_elems(c, x->GivenName, free_strs);
  zx_free_simple_elems(c, x->SurName, free_strs);
  zx_free_simple_elems(c, x->EmailAddress, free_strs);
  zx_free_simple_elems(c, x->TelephoneNumber, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_ContactPerson) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_ContactPerson_s* zx_NEW_md_ContactPerson(struct zx_ctx* c)
{
  struct zx_md_ContactPerson_s* x = ZX_ZALLOC(c, struct zx_md_ContactPerson_s);
  x->gg.g.tok = zx_md_ContactPerson_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_ContactPerson) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->contactType);

  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Company);
  zx_dup_strs_simple_elems(c, x->GivenName);
  zx_dup_strs_simple_elems(c, x->SurName);
  zx_dup_strs_simple_elems(c, x->EmailAddress);
  zx_dup_strs_simple_elems(c, x->TelephoneNumber);

}

/* FUNC(zx_DEEP_CLONE_md_ContactPerson) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_ContactPerson_s* zx_DEEP_CLONE_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x, int dup_strs)
{
  x = (struct zx_md_ContactPerson_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_ContactPerson_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->contactType = zx_clone_attr(c, x->contactType);

  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Company = zx_deep_clone_simple_elems(c,x->Company, dup_strs);
  x->GivenName = zx_deep_clone_simple_elems(c,x->GivenName, dup_strs);
  x->SurName = zx_deep_clone_simple_elems(c,x->SurName, dup_strs);
  x->EmailAddress = zx_deep_clone_simple_elems(c,x->EmailAddress, dup_strs);
  x->TelephoneNumber = zx_deep_clone_simple_elems(c,x->TelephoneNumber, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_md_ContactPerson) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Company, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->GivenName, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SurName, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->EmailAddress, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->TelephoneNumber, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_ContactPerson) */

int zx_WALK_WO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_EncryptionMethod
#define EL_STRUCT zx_md_EncryptionMethod_s
#define EL_NS     md
#define EL_TAG    EncryptionMethod

/* FUNC(zx_FREE_md_EncryptionMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);

  zx_free_simple_elems(c, x->KeySize, free_strs);
  zx_free_simple_elems(c, x->OAEPparams, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_EncryptionMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_EncryptionMethod_s* zx_NEW_md_EncryptionMethod(struct zx_ctx* c)
{
  struct zx_md_EncryptionMethod_s* x = ZX_ZALLOC(c, struct zx_md_EncryptionMethod_s);
  x->gg.g.tok = zx_md_EncryptionMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_EncryptionMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);

  zx_dup_strs_simple_elems(c, x->KeySize);
  zx_dup_strs_simple_elems(c, x->OAEPparams);

}

/* FUNC(zx_DEEP_CLONE_md_EncryptionMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_EncryptionMethod_s* zx_DEEP_CLONE_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x, int dup_strs)
{
  x = (struct zx_md_EncryptionMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_EncryptionMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);

  x->KeySize = zx_deep_clone_simple_elems(c,x->KeySize, dup_strs);
  x->OAEPparams = zx_deep_clone_simple_elems(c,x->OAEPparams, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_md_EncryptionMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->KeySize, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->OAEPparams, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_EncryptionMethod) */

int zx_WALK_WO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_EntitiesDescriptor
#define EL_STRUCT zx_md_EntitiesDescriptor_s
#define EL_NS     md
#define EL_TAG    EntitiesDescriptor

/* FUNC(zx_FREE_md_EntitiesDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->Name, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      struct zx_md_EntityDescriptor_s* en;
      for (e = x->EntityDescriptor; e; e = en) {
	  en = (struct zx_md_EntityDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_EntityDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      struct zx_md_EntitiesDescriptor_s* en;
      for (e = x->EntitiesDescriptor; e; e = en) {
	  en = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_EntitiesDescriptor(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_EntitiesDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_EntitiesDescriptor_s* zx_NEW_md_EntitiesDescriptor(struct zx_ctx* c)
{
  struct zx_md_EntitiesDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_EntitiesDescriptor_s);
  x->gg.g.tok = zx_md_EntitiesDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_EntitiesDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->Name);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_EntityDescriptor(c, e);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_EntitiesDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_EntitiesDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_EntitiesDescriptor_s* zx_DEEP_CLONE_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_EntitiesDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_EntitiesDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->Name = zx_clone_attr(c, x->Name);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      struct zx_md_EntityDescriptor_s* en;
      struct zx_md_EntityDescriptor_s* enn;
      for (enn = 0, e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_EntityDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->EntityDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      struct zx_md_EntitiesDescriptor_s* en;
      struct zx_md_EntitiesDescriptor_s* enn;
      for (enn = 0, e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_EntitiesDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->EntitiesDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_EntitiesDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_EntityDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_EntitiesDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_EntitiesDescriptor) */

int zx_WALK_WO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_EntityDescriptor
#define EL_STRUCT zx_md_EntityDescriptor_s
#define EL_NS     md
#define EL_TAG    EntityDescriptor

/* FUNC(zx_FREE_md_EntityDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->entityID, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      struct zx_md_RoleDescriptor_s* en;
      for (e = x->RoleDescriptor; e; e = en) {
	  en = (struct zx_md_RoleDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_RoleDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      struct zx_md_IDPSSODescriptor_s* en;
      for (e = x->IDPSSODescriptor; e; e = en) {
	  en = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n;
	  zx_FREE_md_IDPSSODescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      struct zx_md_SPSSODescriptor_s* en;
      for (e = x->SPSSODescriptor; e; e = en) {
	  en = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n;
	  zx_FREE_md_SPSSODescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      struct zx_md_AuthnAuthorityDescriptor_s* en;
      for (e = x->AuthnAuthorityDescriptor; e; e = en) {
	  en = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_AuthnAuthorityDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      struct zx_md_AttributeAuthorityDescriptor_s* en;
      for (e = x->AttributeAuthorityDescriptor; e; e = en) {
	  en = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_AttributeAuthorityDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      struct zx_md_PDPDescriptor_s* en;
      for (e = x->PDPDescriptor; e; e = en) {
	  en = (struct zx_md_PDPDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_PDPDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      struct zx_md_AffiliationDescriptor_s* en;
      for (e = x->AffiliationDescriptor; e; e = en) {
	  en = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_AffiliationDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      struct zx_md_AdditionalMetadataLocation_s* en;
      for (e = x->AdditionalMetadataLocation; e; e = en) {
	  en = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n;
	  zx_FREE_md_AdditionalMetadataLocation(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_EntityDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_EntityDescriptor_s* zx_NEW_md_EntityDescriptor(struct zx_ctx* c)
{
  struct zx_md_EntityDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_EntityDescriptor_s);
  x->gg.g.tok = zx_md_EntityDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_EntityDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->entityID);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      for (e = x->RoleDescriptor; e; e = (struct zx_md_RoleDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_RoleDescriptor(c, e);
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      for (e = x->IDPSSODescriptor; e; e = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_IDPSSODescriptor(c, e);
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      for (e = x->SPSSODescriptor; e; e = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_SPSSODescriptor(c, e);
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      for (e = x->AuthnAuthorityDescriptor; e; e = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AuthnAuthorityDescriptor(c, e);
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      for (e = x->AttributeAuthorityDescriptor; e; e = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AttributeAuthorityDescriptor(c, e);
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      for (e = x->PDPDescriptor; e; e = (struct zx_md_PDPDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_PDPDescriptor(c, e);
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AffiliationDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      for (e = x->AdditionalMetadataLocation; e; e = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AdditionalMetadataLocation(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_EntityDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_EntityDescriptor_s* zx_DEEP_CLONE_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_EntityDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_EntityDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->entityID = zx_clone_attr(c, x->entityID);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      struct zx_md_RoleDescriptor_s* en;
      struct zx_md_RoleDescriptor_s* enn;
      for (enn = 0, e = x->RoleDescriptor; e; e = (struct zx_md_RoleDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_RoleDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->RoleDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      struct zx_md_IDPSSODescriptor_s* en;
      struct zx_md_IDPSSODescriptor_s* enn;
      for (enn = 0, e = x->IDPSSODescriptor; e; e = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_IDPSSODescriptor(c, e, dup_strs);
	  if (!enn)
	      x->IDPSSODescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      struct zx_md_SPSSODescriptor_s* en;
      struct zx_md_SPSSODescriptor_s* enn;
      for (enn = 0, e = x->SPSSODescriptor; e; e = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_SPSSODescriptor(c, e, dup_strs);
	  if (!enn)
	      x->SPSSODescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      struct zx_md_AuthnAuthorityDescriptor_s* en;
      struct zx_md_AuthnAuthorityDescriptor_s* enn;
      for (enn = 0, e = x->AuthnAuthorityDescriptor; e; e = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AuthnAuthorityDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->AuthnAuthorityDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      struct zx_md_AttributeAuthorityDescriptor_s* en;
      struct zx_md_AttributeAuthorityDescriptor_s* enn;
      for (enn = 0, e = x->AttributeAuthorityDescriptor; e; e = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AttributeAuthorityDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->AttributeAuthorityDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      struct zx_md_PDPDescriptor_s* en;
      struct zx_md_PDPDescriptor_s* enn;
      for (enn = 0, e = x->PDPDescriptor; e; e = (struct zx_md_PDPDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_PDPDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->PDPDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      struct zx_md_AffiliationDescriptor_s* en;
      struct zx_md_AffiliationDescriptor_s* enn;
      for (enn = 0, e = x->AffiliationDescriptor; e; e = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AffiliationDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->AffiliationDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      struct zx_md_AdditionalMetadataLocation_s* en;
      struct zx_md_AdditionalMetadataLocation_s* enn;
      for (enn = 0, e = x->AdditionalMetadataLocation; e; e = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AdditionalMetadataLocation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalMetadataLocation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_EntityDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      for (e = x->RoleDescriptor; e; e = (struct zx_md_RoleDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_RoleDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      for (e = x->IDPSSODescriptor; e; e = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_IDPSSODescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      for (e = x->SPSSODescriptor; e; e = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_SPSSODescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      for (e = x->AuthnAuthorityDescriptor; e; e = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AuthnAuthorityDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      for (e = x->AttributeAuthorityDescriptor; e; e = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AttributeAuthorityDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      for (e = x->PDPDescriptor; e; e = (struct zx_md_PDPDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_PDPDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AffiliationDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      for (e = x->AdditionalMetadataLocation; e; e = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AdditionalMetadataLocation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_EntityDescriptor) */

int zx_WALK_WO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_Extensions
#define EL_STRUCT zx_md_Extensions_s
#define EL_NS     md
#define EL_TAG    Extensions

/* FUNC(zx_FREE_md_Extensions) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_shibmd_Scope_s* e;
      struct zx_shibmd_Scope_s* en;
      for (e = x->Scope; e; e = en) {
	  en = (struct zx_shibmd_Scope_s*)e->gg.g.n;
	  zx_FREE_shibmd_Scope(c, e, free_strs);
      }
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      struct zx_shibmd_KeyAuthority_s* en;
      for (e = x->KeyAuthority; e; e = en) {
	  en = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n;
	  zx_FREE_shibmd_KeyAuthority(c, e, free_strs);
      }
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      struct zx_idpdisc_DiscoveryResponse_s* en;
      for (e = x->DiscoveryResponse; e; e = en) {
	  en = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n;
	  zx_FREE_idpdisc_DiscoveryResponse(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_Extensions) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_Extensions_s* zx_NEW_md_Extensions(struct zx_ctx* c)
{
  struct zx_md_Extensions_s* x = ZX_ZALLOC(c, struct zx_md_Extensions_s);
  x->gg.g.tok = zx_md_Extensions_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_Extensions) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_shibmd_Scope_s* e;
      for (e = x->Scope; e; e = (struct zx_shibmd_Scope_s*)e->gg.g.n)
	  zx_DUP_STRS_shibmd_Scope(c, e);
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      for (e = x->KeyAuthority; e; e = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n)
	  zx_DUP_STRS_shibmd_KeyAuthority(c, e);
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      for (e = x->DiscoveryResponse; e; e = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idpdisc_DiscoveryResponse(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_Extensions) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_Extensions_s* zx_DEEP_CLONE_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x, int dup_strs)
{
  x = (struct zx_md_Extensions_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_Extensions_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_shibmd_Scope_s* e;
      struct zx_shibmd_Scope_s* en;
      struct zx_shibmd_Scope_s* enn;
      for (enn = 0, e = x->Scope; e; e = (struct zx_shibmd_Scope_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shibmd_Scope(c, e, dup_strs);
	  if (!enn)
	      x->Scope = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      struct zx_shibmd_KeyAuthority_s* en;
      struct zx_shibmd_KeyAuthority_s* enn;
      for (enn = 0, e = x->KeyAuthority; e; e = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shibmd_KeyAuthority(c, e, dup_strs);
	  if (!enn)
	      x->KeyAuthority = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      struct zx_idpdisc_DiscoveryResponse_s* en;
      struct zx_idpdisc_DiscoveryResponse_s* enn;
      for (enn = 0, e = x->DiscoveryResponse; e; e = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idpdisc_DiscoveryResponse(c, e, dup_strs);
	  if (!enn)
	      x->DiscoveryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_Extensions) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_shibmd_Scope_s* e;
      for (e = x->Scope; e; e = (struct zx_shibmd_Scope_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shibmd_Scope(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      for (e = x->KeyAuthority; e; e = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shibmd_KeyAuthority(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      for (e = x->DiscoveryResponse; e; e = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idpdisc_DiscoveryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_Extensions) */

int zx_WALK_WO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_IDPSSODescriptor
#define EL_STRUCT zx_md_IDPSSODescriptor_s
#define EL_NS     md
#define EL_TAG    IDPSSODescriptor

/* FUNC(zx_FREE_md_IDPSSODescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->WantAuthnRequestsSigned, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->errorURL, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      struct zx_md_ArtifactResolutionService_s* en;
      for (e = x->ArtifactResolutionService; e; e = en) {
	  en = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n;
	  zx_FREE_md_ArtifactResolutionService(c, e, free_strs);
      }
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      struct zx_md_SingleLogoutService_s* en;
      for (e = x->SingleLogoutService; e; e = en) {
	  en = (struct zx_md_SingleLogoutService_s*)e->gg.g.n;
	  zx_FREE_md_SingleLogoutService(c, e, free_strs);
      }
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      struct zx_md_ManageNameIDService_s* en;
      for (e = x->ManageNameIDService; e; e = en) {
	  en = (struct zx_md_ManageNameIDService_s*)e->gg.g.n;
	  zx_FREE_md_ManageNameIDService(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NameIDFormat, free_strs);
  {
      struct zx_md_SingleSignOnService_s* e;
      struct zx_md_SingleSignOnService_s* en;
      for (e = x->SingleSignOnService; e; e = en) {
	  en = (struct zx_md_SingleSignOnService_s*)e->gg.g.n;
	  zx_FREE_md_SingleSignOnService(c, e, free_strs);
      }
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      struct zx_md_NameIDMappingService_s* en;
      for (e = x->NameIDMappingService; e; e = en) {
	  en = (struct zx_md_NameIDMappingService_s*)e->gg.g.n;
	  zx_FREE_md_NameIDMappingService(c, e, free_strs);
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      for (e = x->AssertionIDRequestService; e; e = en) {
	  en = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n;
	  zx_FREE_md_AssertionIDRequestService(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AttributeProfile, free_strs);
  {
      struct zx_sa_Attribute_s* e;
      struct zx_sa_Attribute_s* en;
      for (e = x->Attribute; e; e = en) {
	  en = (struct zx_sa_Attribute_s*)e->gg.g.n;
	  zx_FREE_sa_Attribute(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_IDPSSODescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_IDPSSODescriptor_s* zx_NEW_md_IDPSSODescriptor(struct zx_ctx* c)
{
  struct zx_md_IDPSSODescriptor_s* x = ZX_ZALLOC(c, struct zx_md_IDPSSODescriptor_s);
  x->gg.g.tok = zx_md_IDPSSODescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_IDPSSODescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->WantAuthnRequestsSigned);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->errorURL);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ArtifactResolutionService(c, e);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_SingleLogoutService(c, e);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ManageNameIDService(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NameIDFormat);
  {
      struct zx_md_SingleSignOnService_s* e;
      for (e = x->SingleSignOnService; e; e = (struct zx_md_SingleSignOnService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_SingleSignOnService(c, e);
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      for (e = x->NameIDMappingService; e; e = (struct zx_md_NameIDMappingService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_NameIDMappingService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AssertionIDRequestService(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AttributeProfile);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Attribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_IDPSSODescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_IDPSSODescriptor_s* zx_DEEP_CLONE_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_IDPSSODescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_IDPSSODescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->WantAuthnRequestsSigned = zx_clone_attr(c, x->WantAuthnRequestsSigned);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->errorURL = zx_clone_attr(c, x->errorURL);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      struct zx_md_ArtifactResolutionService_s* en;
      struct zx_md_ArtifactResolutionService_s* enn;
      for (enn = 0, e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ArtifactResolutionService(c, e, dup_strs);
	  if (!enn)
	      x->ArtifactResolutionService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      struct zx_md_SingleLogoutService_s* en;
      struct zx_md_SingleLogoutService_s* enn;
      for (enn = 0, e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_SingleLogoutService(c, e, dup_strs);
	  if (!enn)
	      x->SingleLogoutService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      struct zx_md_ManageNameIDService_s* en;
      struct zx_md_ManageNameIDService_s* enn;
      for (enn = 0, e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ManageNameIDService(c, e, dup_strs);
	  if (!enn)
	      x->ManageNameIDService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NameIDFormat = zx_deep_clone_simple_elems(c,x->NameIDFormat, dup_strs);
  {
      struct zx_md_SingleSignOnService_s* e;
      struct zx_md_SingleSignOnService_s* en;
      struct zx_md_SingleSignOnService_s* enn;
      for (enn = 0, e = x->SingleSignOnService; e; e = (struct zx_md_SingleSignOnService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_SingleSignOnService(c, e, dup_strs);
	  if (!enn)
	      x->SingleSignOnService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      struct zx_md_NameIDMappingService_s* en;
      struct zx_md_NameIDMappingService_s* enn;
      for (enn = 0, e = x->NameIDMappingService; e; e = (struct zx_md_NameIDMappingService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_NameIDMappingService(c, e, dup_strs);
	  if (!enn)
	      x->NameIDMappingService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      struct zx_md_AssertionIDRequestService_s* enn;
      for (enn = 0, e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AssertionIDRequestService(c, e, dup_strs);
	  if (!enn)
	      x->AssertionIDRequestService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AttributeProfile = zx_deep_clone_simple_elems(c,x->AttributeProfile, dup_strs);
  {
      struct zx_sa_Attribute_s* e;
      struct zx_sa_Attribute_s* en;
      struct zx_sa_Attribute_s* enn;
      for (enn = 0, e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Attribute(c, e, dup_strs);
	  if (!enn)
	      x->Attribute = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_IDPSSODescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ArtifactResolutionService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_SingleLogoutService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ManageNameIDService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NameIDFormat, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_md_SingleSignOnService_s* e;
      for (e = x->SingleSignOnService; e; e = (struct zx_md_SingleSignOnService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_SingleSignOnService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      for (e = x->NameIDMappingService; e; e = (struct zx_md_NameIDMappingService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_NameIDMappingService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AssertionIDRequestService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AttributeProfile, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Attribute(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_IDPSSODescriptor) */

int zx_WALK_WO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_KeyDescriptor
#define EL_STRUCT zx_md_KeyDescriptor_s
#define EL_NS     md
#define EL_TAG    KeyDescriptor

/* FUNC(zx_FREE_md_KeyDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->use, free_strs);

  {
      struct zx_ds_KeyInfo_s* e;
      struct zx_ds_KeyInfo_s* en;
      for (e = x->KeyInfo; e; e = en) {
	  en = (struct zx_ds_KeyInfo_s*)e->gg.g.n;
	  zx_FREE_ds_KeyInfo(c, e, free_strs);
      }
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      struct zx_md_EncryptionMethod_s* en;
      for (e = x->EncryptionMethod; e; e = en) {
	  en = (struct zx_md_EncryptionMethod_s*)e->gg.g.n;
	  zx_FREE_md_EncryptionMethod(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_KeyDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_KeyDescriptor_s* zx_NEW_md_KeyDescriptor(struct zx_ctx* c)
{
  struct zx_md_KeyDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_KeyDescriptor_s);
  x->gg.g.tok = zx_md_KeyDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_KeyDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->use);

  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_md_EncryptionMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_md_EncryptionMethod(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_KeyDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_KeyDescriptor_s* zx_DEEP_CLONE_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_KeyDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_KeyDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->use = zx_clone_attr(c, x->use);

  {
      struct zx_ds_KeyInfo_s* e;
      struct zx_ds_KeyInfo_s* en;
      struct zx_ds_KeyInfo_s* enn;
      for (enn = 0, e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_KeyInfo(c, e, dup_strs);
	  if (!enn)
	      x->KeyInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      struct zx_md_EncryptionMethod_s* en;
      struct zx_md_EncryptionMethod_s* enn;
      for (enn = 0, e = x->EncryptionMethod; e; e = (struct zx_md_EncryptionMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_EncryptionMethod(c, e, dup_strs);
	  if (!enn)
	      x->EncryptionMethod = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_KeyDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_KeyInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_md_EncryptionMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_EncryptionMethod(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_KeyDescriptor) */

int zx_WALK_WO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_ManageNameIDService
#define EL_STRUCT zx_md_ManageNameIDService_s
#define EL_NS     md
#define EL_TAG    ManageNameIDService

/* FUNC(zx_FREE_md_ManageNameIDService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_ManageNameIDService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_ManageNameIDService_s* zx_NEW_md_ManageNameIDService(struct zx_ctx* c)
{
  struct zx_md_ManageNameIDService_s* x = ZX_ZALLOC(c, struct zx_md_ManageNameIDService_s);
  x->gg.g.tok = zx_md_ManageNameIDService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_ManageNameIDService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_ManageNameIDService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_ManageNameIDService_s* zx_DEEP_CLONE_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x, int dup_strs)
{
  x = (struct zx_md_ManageNameIDService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_ManageNameIDService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_ManageNameIDService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_ManageNameIDService) */

int zx_WALK_WO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_NameIDMappingService
#define EL_STRUCT zx_md_NameIDMappingService_s
#define EL_NS     md
#define EL_TAG    NameIDMappingService

/* FUNC(zx_FREE_md_NameIDMappingService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_NameIDMappingService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_NameIDMappingService_s* zx_NEW_md_NameIDMappingService(struct zx_ctx* c)
{
  struct zx_md_NameIDMappingService_s* x = ZX_ZALLOC(c, struct zx_md_NameIDMappingService_s);
  x->gg.g.tok = zx_md_NameIDMappingService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_NameIDMappingService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_NameIDMappingService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_NameIDMappingService_s* zx_DEEP_CLONE_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x, int dup_strs)
{
  x = (struct zx_md_NameIDMappingService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_NameIDMappingService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_NameIDMappingService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_NameIDMappingService) */

int zx_WALK_WO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_Organization
#define EL_STRUCT zx_md_Organization_s
#define EL_NS     md
#define EL_TAG    Organization

/* FUNC(zx_FREE_md_Organization) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_OrganizationName_s* e;
      struct zx_md_OrganizationName_s* en;
      for (e = x->OrganizationName; e; e = en) {
	  en = (struct zx_md_OrganizationName_s*)e->gg.g.n;
	  zx_FREE_md_OrganizationName(c, e, free_strs);
      }
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      struct zx_md_OrganizationDisplayName_s* en;
      for (e = x->OrganizationDisplayName; e; e = en) {
	  en = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n;
	  zx_FREE_md_OrganizationDisplayName(c, e, free_strs);
      }
  }
  {
      struct zx_md_OrganizationURL_s* e;
      struct zx_md_OrganizationURL_s* en;
      for (e = x->OrganizationURL; e; e = en) {
	  en = (struct zx_md_OrganizationURL_s*)e->gg.g.n;
	  zx_FREE_md_OrganizationURL(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_Organization) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_Organization_s* zx_NEW_md_Organization(struct zx_ctx* c)
{
  struct zx_md_Organization_s* x = ZX_ZALLOC(c, struct zx_md_Organization_s);
  x->gg.g.tok = zx_md_Organization_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_Organization) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_md_OrganizationName_s*)e->gg.g.n)
	  zx_DUP_STRS_md_OrganizationName(c, e);
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n)
	  zx_DUP_STRS_md_OrganizationDisplayName(c, e);
  }
  {
      struct zx_md_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_md_OrganizationURL_s*)e->gg.g.n)
	  zx_DUP_STRS_md_OrganizationURL(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_Organization) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_Organization_s* zx_DEEP_CLONE_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x, int dup_strs)
{
  x = (struct zx_md_Organization_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_Organization_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_OrganizationName_s* e;
      struct zx_md_OrganizationName_s* en;
      struct zx_md_OrganizationName_s* enn;
      for (enn = 0, e = x->OrganizationName; e; e = (struct zx_md_OrganizationName_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_OrganizationName(c, e, dup_strs);
	  if (!enn)
	      x->OrganizationName = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      struct zx_md_OrganizationDisplayName_s* en;
      struct zx_md_OrganizationDisplayName_s* enn;
      for (enn = 0, e = x->OrganizationDisplayName; e; e = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_OrganizationDisplayName(c, e, dup_strs);
	  if (!enn)
	      x->OrganizationDisplayName = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_OrganizationURL_s* e;
      struct zx_md_OrganizationURL_s* en;
      struct zx_md_OrganizationURL_s* enn;
      for (enn = 0, e = x->OrganizationURL; e; e = (struct zx_md_OrganizationURL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_OrganizationURL(c, e, dup_strs);
	  if (!enn)
	      x->OrganizationURL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_Organization) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_md_OrganizationName_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_OrganizationName(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_OrganizationDisplayName(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_md_OrganizationURL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_OrganizationURL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_Organization) */

int zx_WALK_WO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_OrganizationDisplayName
#define EL_STRUCT zx_md_OrganizationDisplayName_s
#define EL_NS     md
#define EL_TAG    OrganizationDisplayName

/* FUNC(zx_FREE_md_OrganizationDisplayName) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_OrganizationDisplayName) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_OrganizationDisplayName_s* zx_NEW_md_OrganizationDisplayName(struct zx_ctx* c)
{
  struct zx_md_OrganizationDisplayName_s* x = ZX_ZALLOC(c, struct zx_md_OrganizationDisplayName_s);
  x->gg.g.tok = zx_md_OrganizationDisplayName_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_OrganizationDisplayName) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_md_OrganizationDisplayName) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_OrganizationDisplayName_s* zx_DEEP_CLONE_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x, int dup_strs)
{
  x = (struct zx_md_OrganizationDisplayName_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_OrganizationDisplayName_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_md_OrganizationDisplayName) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_OrganizationDisplayName) */

int zx_WALK_WO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_OrganizationName
#define EL_STRUCT zx_md_OrganizationName_s
#define EL_NS     md
#define EL_TAG    OrganizationName

/* FUNC(zx_FREE_md_OrganizationName) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_OrganizationName) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_OrganizationName_s* zx_NEW_md_OrganizationName(struct zx_ctx* c)
{
  struct zx_md_OrganizationName_s* x = ZX_ZALLOC(c, struct zx_md_OrganizationName_s);
  x->gg.g.tok = zx_md_OrganizationName_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_OrganizationName) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_md_OrganizationName) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_OrganizationName_s* zx_DEEP_CLONE_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x, int dup_strs)
{
  x = (struct zx_md_OrganizationName_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_OrganizationName_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_md_OrganizationName) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_OrganizationName) */

int zx_WALK_WO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_OrganizationURL
#define EL_STRUCT zx_md_OrganizationURL_s
#define EL_NS     md
#define EL_TAG    OrganizationURL

/* FUNC(zx_FREE_md_OrganizationURL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_OrganizationURL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_OrganizationURL_s* zx_NEW_md_OrganizationURL(struct zx_ctx* c)
{
  struct zx_md_OrganizationURL_s* x = ZX_ZALLOC(c, struct zx_md_OrganizationURL_s);
  x->gg.g.tok = zx_md_OrganizationURL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_OrganizationURL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_md_OrganizationURL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_OrganizationURL_s* zx_DEEP_CLONE_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x, int dup_strs)
{
  x = (struct zx_md_OrganizationURL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_OrganizationURL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_md_OrganizationURL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_OrganizationURL) */

int zx_WALK_WO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_PDPDescriptor
#define EL_STRUCT zx_md_PDPDescriptor_s
#define EL_NS     md
#define EL_TAG    PDPDescriptor

/* FUNC(zx_FREE_md_PDPDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->errorURL, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_md_AuthzService_s* e;
      struct zx_md_AuthzService_s* en;
      for (e = x->AuthzService; e; e = en) {
	  en = (struct zx_md_AuthzService_s*)e->gg.g.n;
	  zx_FREE_md_AuthzService(c, e, free_strs);
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      for (e = x->AssertionIDRequestService; e; e = en) {
	  en = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n;
	  zx_FREE_md_AssertionIDRequestService(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NameIDFormat, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_PDPDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_PDPDescriptor_s* zx_NEW_md_PDPDescriptor(struct zx_ctx* c)
{
  struct zx_md_PDPDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_PDPDescriptor_s);
  x->gg.g.tok = zx_md_PDPDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_PDPDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->errorURL);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AuthzService_s* e;
      for (e = x->AuthzService; e; e = (struct zx_md_AuthzService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AuthzService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AssertionIDRequestService(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NameIDFormat);

}

/* FUNC(zx_DEEP_CLONE_md_PDPDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_PDPDescriptor_s* zx_DEEP_CLONE_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_PDPDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_PDPDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->errorURL = zx_clone_attr(c, x->errorURL);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AuthzService_s* e;
      struct zx_md_AuthzService_s* en;
      struct zx_md_AuthzService_s* enn;
      for (enn = 0, e = x->AuthzService; e; e = (struct zx_md_AuthzService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AuthzService(c, e, dup_strs);
	  if (!enn)
	      x->AuthzService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      struct zx_md_AssertionIDRequestService_s* en;
      struct zx_md_AssertionIDRequestService_s* enn;
      for (enn = 0, e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AssertionIDRequestService(c, e, dup_strs);
	  if (!enn)
	      x->AssertionIDRequestService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NameIDFormat = zx_deep_clone_simple_elems(c,x->NameIDFormat, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_md_PDPDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AuthzService_s* e;
      for (e = x->AuthzService; e; e = (struct zx_md_AuthzService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AuthzService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AssertionIDRequestService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NameIDFormat, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_PDPDescriptor) */

int zx_WALK_WO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_RequestedAttribute
#define EL_STRUCT zx_md_RequestedAttribute_s
#define EL_NS     md
#define EL_TAG    RequestedAttribute

/* FUNC(zx_FREE_md_RequestedAttribute) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->FriendlyName, free_strs);
  zx_free_attr(c, x->Name, free_strs);
  zx_free_attr(c, x->NameFormat, free_strs);
  zx_free_attr(c, x->isRequired, free_strs);

  {
      struct zx_sa_AttributeValue_s* e;
      struct zx_sa_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_sa_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_sa_AttributeValue(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_RequestedAttribute) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_RequestedAttribute_s* zx_NEW_md_RequestedAttribute(struct zx_ctx* c)
{
  struct zx_md_RequestedAttribute_s* x = ZX_ZALLOC(c, struct zx_md_RequestedAttribute_s);
  x->gg.g.tok = zx_md_RequestedAttribute_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_RequestedAttribute) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->FriendlyName);
  zx_dup_attr(c, x->Name);
  zx_dup_attr(c, x->NameFormat);
  zx_dup_attr(c, x->isRequired);

  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AttributeValue(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_RequestedAttribute) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_RequestedAttribute_s* zx_DEEP_CLONE_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x, int dup_strs)
{
  x = (struct zx_md_RequestedAttribute_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_RequestedAttribute_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->FriendlyName = zx_clone_attr(c, x->FriendlyName);
  x->Name = zx_clone_attr(c, x->Name);
  x->NameFormat = zx_clone_attr(c, x->NameFormat);
  x->isRequired = zx_clone_attr(c, x->isRequired);

  {
      struct zx_sa_AttributeValue_s* e;
      struct zx_sa_AttributeValue_s* en;
      struct zx_sa_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_RequestedAttribute) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_RequestedAttribute) */

int zx_WALK_WO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_RoleDescriptor
#define EL_STRUCT zx_md_RoleDescriptor_s
#define EL_NS     md
#define EL_TAG    RoleDescriptor

/* FUNC(zx_FREE_md_RoleDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->errorURL, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_RoleDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_RoleDescriptor_s* zx_NEW_md_RoleDescriptor(struct zx_ctx* c)
{
  struct zx_md_RoleDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_RoleDescriptor_s);
  x->gg.g.tok = zx_md_RoleDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_RoleDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->errorURL);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_RoleDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_RoleDescriptor_s* zx_DEEP_CLONE_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_RoleDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_RoleDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->errorURL = zx_clone_attr(c, x->errorURL);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_RoleDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_RoleDescriptor) */

int zx_WALK_WO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_SPSSODescriptor
#define EL_STRUCT zx_md_SPSSODescriptor_s
#define EL_NS     md
#define EL_TAG    SPSSODescriptor

/* FUNC(zx_FREE_md_SPSSODescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AuthnRequestsSigned, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->WantAssertionsSigned, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->errorURL, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_md_Extensions_s*)e->gg.g.n;
	  zx_FREE_md_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_md_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_KeyDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_md_Organization_s*)e->gg.g.n;
	  zx_FREE_md_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_md_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_md_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      struct zx_md_ArtifactResolutionService_s* en;
      for (e = x->ArtifactResolutionService; e; e = en) {
	  en = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n;
	  zx_FREE_md_ArtifactResolutionService(c, e, free_strs);
      }
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      struct zx_md_SingleLogoutService_s* en;
      for (e = x->SingleLogoutService; e; e = en) {
	  en = (struct zx_md_SingleLogoutService_s*)e->gg.g.n;
	  zx_FREE_md_SingleLogoutService(c, e, free_strs);
      }
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      struct zx_md_ManageNameIDService_s* en;
      for (e = x->ManageNameIDService; e; e = en) {
	  en = (struct zx_md_ManageNameIDService_s*)e->gg.g.n;
	  zx_FREE_md_ManageNameIDService(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NameIDFormat, free_strs);
  {
      struct zx_md_AssertionConsumerService_s* e;
      struct zx_md_AssertionConsumerService_s* en;
      for (e = x->AssertionConsumerService; e; e = en) {
	  en = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n;
	  zx_FREE_md_AssertionConsumerService(c, e, free_strs);
      }
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      struct zx_md_AttributeConsumingService_s* en;
      for (e = x->AttributeConsumingService; e; e = en) {
	  en = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n;
	  zx_FREE_md_AttributeConsumingService(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_SPSSODescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_SPSSODescriptor_s* zx_NEW_md_SPSSODescriptor(struct zx_ctx* c)
{
  struct zx_md_SPSSODescriptor_s* x = ZX_ZALLOC(c, struct zx_md_SPSSODescriptor_s);
  x->gg.g.tok = zx_md_SPSSODescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_SPSSODescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AuthnRequestsSigned);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->WantAssertionsSigned);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->errorURL);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ContactPerson(c, e);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ArtifactResolutionService(c, e);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_SingleLogoutService(c, e);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_ManageNameIDService(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NameIDFormat);
  {
      struct zx_md_AssertionConsumerService_s* e;
      for (e = x->AssertionConsumerService; e; e = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AssertionConsumerService(c, e);
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      for (e = x->AttributeConsumingService; e; e = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n)
	  zx_DUP_STRS_md_AttributeConsumingService(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_md_SPSSODescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_SPSSODescriptor_s* zx_DEEP_CLONE_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x, int dup_strs)
{
  x = (struct zx_md_SPSSODescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_SPSSODescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AuthnRequestsSigned = zx_clone_attr(c, x->AuthnRequestsSigned);
  x->ID = zx_clone_attr(c, x->ID);
  x->WantAssertionsSigned = zx_clone_attr(c, x->WantAssertionsSigned);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->errorURL = zx_clone_attr(c, x->errorURL);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

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
      struct zx_md_Extensions_s* e;
      struct zx_md_Extensions_s* en;
      struct zx_md_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      struct zx_md_KeyDescriptor_s* en;
      struct zx_md_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_Organization_s* e;
      struct zx_md_Organization_s* en;
      struct zx_md_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      struct zx_md_ContactPerson_s* en;
      struct zx_md_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      struct zx_md_ArtifactResolutionService_s* en;
      struct zx_md_ArtifactResolutionService_s* enn;
      for (enn = 0, e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ArtifactResolutionService(c, e, dup_strs);
	  if (!enn)
	      x->ArtifactResolutionService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      struct zx_md_SingleLogoutService_s* en;
      struct zx_md_SingleLogoutService_s* enn;
      for (enn = 0, e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_SingleLogoutService(c, e, dup_strs);
	  if (!enn)
	      x->SingleLogoutService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      struct zx_md_ManageNameIDService_s* en;
      struct zx_md_ManageNameIDService_s* enn;
      for (enn = 0, e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_ManageNameIDService(c, e, dup_strs);
	  if (!enn)
	      x->ManageNameIDService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NameIDFormat = zx_deep_clone_simple_elems(c,x->NameIDFormat, dup_strs);
  {
      struct zx_md_AssertionConsumerService_s* e;
      struct zx_md_AssertionConsumerService_s* en;
      struct zx_md_AssertionConsumerService_s* enn;
      for (enn = 0, e = x->AssertionConsumerService; e; e = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AssertionConsumerService(c, e, dup_strs);
	  if (!enn)
	      x->AssertionConsumerService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      struct zx_md_AttributeConsumingService_s* en;
      struct zx_md_AttributeConsumingService_s* enn;
      for (enn = 0, e = x->AttributeConsumingService; e; e = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_AttributeConsumingService(c, e, dup_strs);
	  if (!enn)
	      x->AttributeConsumingService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_md_SPSSODescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ArtifactResolutionService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_SingleLogoutService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_ManageNameIDService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NameIDFormat, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_md_AssertionConsumerService_s* e;
      for (e = x->AssertionConsumerService; e; e = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AssertionConsumerService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      for (e = x->AttributeConsumingService; e; e = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_AttributeConsumingService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_md_SPSSODescriptor) */

int zx_WALK_WO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_ServiceDescription
#define EL_STRUCT zx_md_ServiceDescription_s
#define EL_NS     md
#define EL_TAG    ServiceDescription

/* FUNC(zx_FREE_md_ServiceDescription) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_ServiceDescription) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_ServiceDescription_s* zx_NEW_md_ServiceDescription(struct zx_ctx* c)
{
  struct zx_md_ServiceDescription_s* x = ZX_ZALLOC(c, struct zx_md_ServiceDescription_s);
  x->gg.g.tok = zx_md_ServiceDescription_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_ServiceDescription) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_md_ServiceDescription) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_ServiceDescription_s* zx_DEEP_CLONE_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x, int dup_strs)
{
  x = (struct zx_md_ServiceDescription_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_ServiceDescription_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_md_ServiceDescription) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_ServiceDescription) */

int zx_WALK_WO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_ServiceName
#define EL_STRUCT zx_md_ServiceName_s
#define EL_NS     md
#define EL_TAG    ServiceName

/* FUNC(zx_FREE_md_ServiceName) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_ServiceName) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_ServiceName_s* zx_NEW_md_ServiceName(struct zx_ctx* c)
{
  struct zx_md_ServiceName_s* x = ZX_ZALLOC(c, struct zx_md_ServiceName_s);
  x->gg.g.tok = zx_md_ServiceName_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_ServiceName) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_md_ServiceName) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_ServiceName_s* zx_DEEP_CLONE_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x, int dup_strs)
{
  x = (struct zx_md_ServiceName_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_ServiceName_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_md_ServiceName) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_ServiceName) */

int zx_WALK_WO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_SingleLogoutService
#define EL_STRUCT zx_md_SingleLogoutService_s
#define EL_NS     md
#define EL_TAG    SingleLogoutService

/* FUNC(zx_FREE_md_SingleLogoutService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_SingleLogoutService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_SingleLogoutService_s* zx_NEW_md_SingleLogoutService(struct zx_ctx* c)
{
  struct zx_md_SingleLogoutService_s* x = ZX_ZALLOC(c, struct zx_md_SingleLogoutService_s);
  x->gg.g.tok = zx_md_SingleLogoutService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_SingleLogoutService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_SingleLogoutService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_SingleLogoutService_s* zx_DEEP_CLONE_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x, int dup_strs)
{
  x = (struct zx_md_SingleLogoutService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_SingleLogoutService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_SingleLogoutService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_SingleLogoutService) */

int zx_WALK_WO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   md_SingleSignOnService
#define EL_STRUCT zx_md_SingleSignOnService_s
#define EL_NS     md
#define EL_TAG    SingleSignOnService

/* FUNC(zx_FREE_md_SingleSignOnService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);
  zx_free_attr(c, x->ResponseLocation, free_strs);
  zx_free_attr(c, x->index, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_md_SingleSignOnService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_md_SingleSignOnService_s* zx_NEW_md_SingleSignOnService(struct zx_ctx* c)
{
  struct zx_md_SingleSignOnService_s* x = ZX_ZALLOC(c, struct zx_md_SingleSignOnService_s);
  x->gg.g.tok = zx_md_SingleSignOnService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_md_SingleSignOnService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);
  zx_dup_attr(c, x->ResponseLocation);
  zx_dup_attr(c, x->index);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_md_SingleSignOnService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_md_SingleSignOnService_s* zx_DEEP_CLONE_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x, int dup_strs)
{
  x = (struct zx_md_SingleSignOnService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_md_SingleSignOnService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);
  x->ResponseLocation = zx_clone_attr(c, x->ResponseLocation);
  x->index = zx_clone_attr(c, x->index);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_md_SingleSignOnService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_md_SingleSignOnService) */

int zx_WALK_WO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-md-aux.c */
