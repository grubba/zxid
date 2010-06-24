/* c/zx-m20-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-m20-data.h"



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

#define EL_NAME   m20_AdditionalMetaLocation
#define EL_STRUCT zx_m20_AdditionalMetaLocation_s
#define EL_NS     m20
#define EL_TAG    AdditionalMetaLocation

/* FUNC(zx_FREE_m20_AdditionalMetaLocation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->namespace_is_cxx_keyword, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_AdditionalMetaLocation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_AdditionalMetaLocation_s* zx_NEW_m20_AdditionalMetaLocation(struct zx_ctx* c)
{
  struct zx_m20_AdditionalMetaLocation_s* x = ZX_ZALLOC(c, struct zx_m20_AdditionalMetaLocation_s);
  x->gg.g.tok = zx_m20_AdditionalMetaLocation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_AdditionalMetaLocation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->namespace_is_cxx_keyword);


}

/* FUNC(zx_DEEP_CLONE_m20_AdditionalMetaLocation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_AdditionalMetaLocation_s* zx_DEEP_CLONE_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x, int dup_strs)
{
  x = (struct zx_m20_AdditionalMetaLocation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_AdditionalMetaLocation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->namespace_is_cxx_keyword = zx_clone_attr(c, x->namespace_is_cxx_keyword);


  return x;
}

/* FUNC(zx_WALK_SO_m20_AdditionalMetaLocation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_m20_AdditionalMetaLocation) */

int zx_WALK_WO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_AffiliationDescriptor
#define EL_STRUCT zx_m20_AffiliationDescriptor_s
#define EL_NS     m20
#define EL_TAG    AffiliationDescriptor

/* FUNC(zx_FREE_m20_AffiliationDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->affiliationOwnerID, free_strs);
  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  zx_free_simple_elems(c, x->AffiliateMember, free_strs);
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
      }
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      struct zx_m20_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_KeyDescriptor(c, e, free_strs);
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

/* FUNC(zx_NEW_m20_AffiliationDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_AffiliationDescriptor_s* zx_NEW_m20_AffiliationDescriptor(struct zx_ctx* c)
{
  struct zx_m20_AffiliationDescriptor_s* x = ZX_ZALLOC(c, struct zx_m20_AffiliationDescriptor_s);
  x->gg.g.tok = zx_m20_AffiliationDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_AffiliationDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->affiliationOwnerID);
  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->validUntil);

  zx_dup_strs_simple_elems(c, x->AffiliateMember);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_KeyDescriptor(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_m20_AffiliationDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_AffiliationDescriptor_s* zx_DEEP_CLONE_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x, int dup_strs)
{
  x = (struct zx_m20_AffiliationDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_AffiliationDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->affiliationOwnerID = zx_clone_attr(c, x->affiliationOwnerID);
  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->id = zx_clone_attr(c, x->id);
  x->validUntil = zx_clone_attr(c, x->validUntil);

  x->AffiliateMember = zx_deep_clone_simple_elems(c,x->AffiliateMember, dup_strs);
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      struct zx_m20_KeyDescriptor_s* en;
      struct zx_m20_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
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

/* FUNC(zx_WALK_SO_m20_AffiliationDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AffiliateMember, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_KeyDescriptor(c, e, ctx, callback);
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

/* FUNC(zx_WALK_WO_m20_AffiliationDescriptor) */

int zx_WALK_WO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_AssertionConsumerServiceURL
#define EL_STRUCT zx_m20_AssertionConsumerServiceURL_s
#define EL_NS     m20
#define EL_TAG    AssertionConsumerServiceURL

/* FUNC(zx_FREE_m20_AssertionConsumerServiceURL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->isDefault, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_AssertionConsumerServiceURL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_AssertionConsumerServiceURL_s* zx_NEW_m20_AssertionConsumerServiceURL(struct zx_ctx* c)
{
  struct zx_m20_AssertionConsumerServiceURL_s* x = ZX_ZALLOC(c, struct zx_m20_AssertionConsumerServiceURL_s);
  x->gg.g.tok = zx_m20_AssertionConsumerServiceURL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_AssertionConsumerServiceURL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->isDefault);


}

/* FUNC(zx_DEEP_CLONE_m20_AssertionConsumerServiceURL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_AssertionConsumerServiceURL_s* zx_DEEP_CLONE_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x, int dup_strs)
{
  x = (struct zx_m20_AssertionConsumerServiceURL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_AssertionConsumerServiceURL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->isDefault = zx_clone_attr(c, x->isDefault);


  return x;
}

/* FUNC(zx_WALK_SO_m20_AssertionConsumerServiceURL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_m20_AssertionConsumerServiceURL) */

int zx_WALK_WO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_ContactPerson
#define EL_STRUCT zx_m20_ContactPerson_s
#define EL_NS     m20
#define EL_TAG    ContactPerson

/* FUNC(zx_FREE_m20_ContactPerson) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->contactType, free_strs);
  zx_free_attr(c, x->libertyPrincipalIdentifier, free_strs);

  zx_free_simple_elems(c, x->Company, free_strs);
  zx_free_simple_elems(c, x->GivenName, free_strs);
  zx_free_simple_elems(c, x->SurName, free_strs);
  zx_free_simple_elems(c, x->EmailAddress, free_strs);
  zx_free_simple_elems(c, x->TelephoneNumber, free_strs);
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_ContactPerson) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_ContactPerson_s* zx_NEW_m20_ContactPerson(struct zx_ctx* c)
{
  struct zx_m20_ContactPerson_s* x = ZX_ZALLOC(c, struct zx_m20_ContactPerson_s);
  x->gg.g.tok = zx_m20_ContactPerson_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_ContactPerson) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->contactType);
  zx_dup_attr(c, x->libertyPrincipalIdentifier);

  zx_dup_strs_simple_elems(c, x->Company);
  zx_dup_strs_simple_elems(c, x->GivenName);
  zx_dup_strs_simple_elems(c, x->SurName);
  zx_dup_strs_simple_elems(c, x->EmailAddress);
  zx_dup_strs_simple_elems(c, x->TelephoneNumber);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_m20_ContactPerson) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_ContactPerson_s* zx_DEEP_CLONE_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x, int dup_strs)
{
  x = (struct zx_m20_ContactPerson_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_ContactPerson_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->contactType = zx_clone_attr(c, x->contactType);
  x->libertyPrincipalIdentifier = zx_clone_attr(c, x->libertyPrincipalIdentifier);

  x->Company = zx_deep_clone_simple_elems(c,x->Company, dup_strs);
  x->GivenName = zx_deep_clone_simple_elems(c,x->GivenName, dup_strs);
  x->SurName = zx_deep_clone_simple_elems(c,x->SurName, dup_strs);
  x->EmailAddress = zx_deep_clone_simple_elems(c,x->EmailAddress, dup_strs);
  x->TelephoneNumber = zx_deep_clone_simple_elems(c,x->TelephoneNumber, dup_strs);
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_m20_ContactPerson) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_m20_ContactPerson) */

int zx_WALK_WO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_EntitiesDescriptor
#define EL_STRUCT zx_m20_EntitiesDescriptor_s
#define EL_NS     m20
#define EL_TAG    EntitiesDescriptor

/* FUNC(zx_FREE_m20_EntitiesDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_m20_EntityDescriptor_s* e;
      struct zx_m20_EntityDescriptor_s* en;
      for (e = x->EntityDescriptor; e; e = en) {
	  en = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_EntityDescriptor(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_EntitiesDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_EntitiesDescriptor_s* zx_NEW_m20_EntitiesDescriptor(struct zx_ctx* c)
{
  struct zx_m20_EntitiesDescriptor_s* x = ZX_ZALLOC(c, struct zx_m20_EntitiesDescriptor_s);
  x->gg.g.tok = zx_m20_EntitiesDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_EntitiesDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_EntityDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_m20_EntitiesDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_EntitiesDescriptor_s* zx_DEEP_CLONE_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x, int dup_strs)
{
  x = (struct zx_m20_EntitiesDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_EntitiesDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_m20_EntityDescriptor_s* e;
      struct zx_m20_EntityDescriptor_s* en;
      struct zx_m20_EntityDescriptor_s* enn;
      for (enn = 0, e = x->EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_EntityDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->EntityDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_m20_EntitiesDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_EntityDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_m20_EntitiesDescriptor) */

int zx_WALK_WO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_EntityDescriptor
#define EL_STRUCT zx_m20_EntityDescriptor_s
#define EL_NS     m20
#define EL_TAG    EntityDescriptor

/* FUNC(zx_FREE_m20_EntityDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->providerID, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_m20_IDPDescriptor_s* e;
      struct zx_m20_IDPDescriptor_s* en;
      for (e = x->IDPDescriptor; e; e = en) {
	  en = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_IDPDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      struct zx_m20_SPDescriptor_s* en;
      for (e = x->SPDescriptor; e; e = en) {
	  en = (struct zx_m20_SPDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_SPDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      struct zx_m20_AffiliationDescriptor_s* en;
      for (e = x->AffiliationDescriptor; e; e = en) {
	  en = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_AffiliationDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      struct zx_m20_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_m20_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_m20_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_m20_Organization_s* e;
      struct zx_m20_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_m20_Organization_s*)e->gg.g.n;
	  zx_FREE_m20_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
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

/* FUNC(zx_NEW_m20_EntityDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_EntityDescriptor_s* zx_NEW_m20_EntityDescriptor(struct zx_ctx* c)
{
  struct zx_m20_EntityDescriptor_s* x = ZX_ZALLOC(c, struct zx_m20_EntityDescriptor_s);
  x->gg.g.tok = zx_m20_EntityDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_EntityDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->providerID);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_m20_IDPDescriptor_s* e;
      for (e = x->IDPDescriptor; e; e = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_IDPDescriptor(c, e);
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      for (e = x->SPDescriptor; e; e = (struct zx_m20_SPDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_SPDescriptor(c, e);
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_AffiliationDescriptor(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Organization(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_m20_EntityDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_EntityDescriptor_s* zx_DEEP_CLONE_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x, int dup_strs)
{
  x = (struct zx_m20_EntityDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_EntityDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->id = zx_clone_attr(c, x->id);
  x->providerID = zx_clone_attr(c, x->providerID);
  x->validUntil = zx_clone_attr(c, x->validUntil);

  {
      struct zx_m20_IDPDescriptor_s* e;
      struct zx_m20_IDPDescriptor_s* en;
      struct zx_m20_IDPDescriptor_s* enn;
      for (enn = 0, e = x->IDPDescriptor; e; e = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_IDPDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->IDPDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      struct zx_m20_SPDescriptor_s* en;
      struct zx_m20_SPDescriptor_s* enn;
      for (enn = 0, e = x->SPDescriptor; e; e = (struct zx_m20_SPDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_SPDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->SPDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      struct zx_m20_AffiliationDescriptor_s* en;
      struct zx_m20_AffiliationDescriptor_s* enn;
      for (enn = 0, e = x->AffiliationDescriptor; e; e = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_AffiliationDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->AffiliationDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      struct zx_m20_ContactPerson_s* en;
      struct zx_m20_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_Organization_s* e;
      struct zx_m20_Organization_s* en;
      struct zx_m20_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
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

/* FUNC(zx_WALK_SO_m20_EntityDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_m20_IDPDescriptor_s* e;
      for (e = x->IDPDescriptor; e; e = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_IDPDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      for (e = x->SPDescriptor; e; e = (struct zx_m20_SPDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_SPDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_AffiliationDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
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

/* FUNC(zx_WALK_WO_m20_EntityDescriptor) */

int zx_WALK_WO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_Extension
#define EL_STRUCT zx_m20_Extension_s
#define EL_NS     m20
#define EL_TAG    Extension

/* FUNC(zx_FREE_m20_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_Extension_s* zx_NEW_m20_Extension(struct zx_ctx* c)
{
  struct zx_m20_Extension_s* x = ZX_ZALLOC(c, struct zx_m20_Extension_s);
  x->gg.g.tok = zx_m20_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_m20_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_Extension_s* zx_DEEP_CLONE_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x, int dup_strs)
{
  x = (struct zx_m20_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_m20_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_m20_Extension) */

int zx_WALK_WO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_IDPDescriptor
#define EL_STRUCT zx_m20_IDPDescriptor_s
#define EL_NS     m20
#define EL_TAG    IDPDescriptor

/* FUNC(zx_FREE_m20_IDPDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_m20_KeyDescriptor_s* e;
      struct zx_m20_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_KeyDescriptor(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SoapEndpoint, free_strs);
  zx_free_simple_elems(c, x->SingleLogoutServiceURL, free_strs);
  zx_free_simple_elems(c, x->SingleLogoutServiceReturnURL, free_strs);
  zx_free_simple_elems(c, x->FederationTerminationServiceURL, free_strs);
  zx_free_simple_elems(c, x->FederationTerminationServiceReturnURL, free_strs);
  zx_free_simple_elems(c, x->FederationTerminationNotificationProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->SingleLogoutProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->RegisterNameIdentifierProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->RegisterNameIdentifierServiceURL, free_strs);
  zx_free_simple_elems(c, x->RegisterNameIdentifierServiceReturnURL, free_strs);
  zx_free_simple_elems(c, x->NameIdentifierMappingProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->NameIdentifierMappingEncryptionProfile, free_strs);
  {
      struct zx_m20_Organization_s* e;
      struct zx_m20_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_m20_Organization_s*)e->gg.g.n;
	  zx_FREE_m20_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      struct zx_m20_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_m20_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_m20_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      struct zx_m20_AdditionalMetaLocation_s* en;
      for (e = x->AdditionalMetaLocation; e; e = en) {
	  en = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n;
	  zx_FREE_m20_AdditionalMetaLocation(c, e, free_strs);
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
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
  zx_free_simple_elems(c, x->SingleSignOnServiceURL, free_strs);
  zx_free_simple_elems(c, x->SingleSignOnProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->AuthnServiceURL, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_IDPDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_IDPDescriptor_s* zx_NEW_m20_IDPDescriptor(struct zx_ctx* c)
{
  struct zx_m20_IDPDescriptor_s* x = ZX_ZALLOC(c, struct zx_m20_IDPDescriptor_s);
  x->gg.g.tok = zx_m20_IDPDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_IDPDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_KeyDescriptor(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SoapEndpoint);
  zx_dup_strs_simple_elems(c, x->SingleLogoutServiceURL);
  zx_dup_strs_simple_elems(c, x->SingleLogoutServiceReturnURL);
  zx_dup_strs_simple_elems(c, x->FederationTerminationServiceURL);
  zx_dup_strs_simple_elems(c, x->FederationTerminationServiceReturnURL);
  zx_dup_strs_simple_elems(c, x->FederationTerminationNotificationProtocolProfile);
  zx_dup_strs_simple_elems(c, x->SingleLogoutProtocolProfile);
  zx_dup_strs_simple_elems(c, x->RegisterNameIdentifierProtocolProfile);
  zx_dup_strs_simple_elems(c, x->RegisterNameIdentifierServiceURL);
  zx_dup_strs_simple_elems(c, x->RegisterNameIdentifierServiceReturnURL);
  zx_dup_strs_simple_elems(c, x->NameIdentifierMappingProtocolProfile);
  zx_dup_strs_simple_elems(c, x->NameIdentifierMappingEncryptionProfile);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Organization(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_AdditionalMetaLocation(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SingleSignOnServiceURL);
  zx_dup_strs_simple_elems(c, x->SingleSignOnProtocolProfile);
  zx_dup_strs_simple_elems(c, x->AuthnServiceURL);

}

/* FUNC(zx_DEEP_CLONE_m20_IDPDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_IDPDescriptor_s* zx_DEEP_CLONE_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x, int dup_strs)
{
  x = (struct zx_m20_IDPDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_IDPDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->id = zx_clone_attr(c, x->id);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

  {
      struct zx_m20_KeyDescriptor_s* e;
      struct zx_m20_KeyDescriptor_s* en;
      struct zx_m20_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SoapEndpoint = zx_deep_clone_simple_elems(c,x->SoapEndpoint, dup_strs);
  x->SingleLogoutServiceURL = zx_deep_clone_simple_elems(c,x->SingleLogoutServiceURL, dup_strs);
  x->SingleLogoutServiceReturnURL = zx_deep_clone_simple_elems(c,x->SingleLogoutServiceReturnURL, dup_strs);
  x->FederationTerminationServiceURL = zx_deep_clone_simple_elems(c,x->FederationTerminationServiceURL, dup_strs);
  x->FederationTerminationServiceReturnURL = zx_deep_clone_simple_elems(c,x->FederationTerminationServiceReturnURL, dup_strs);
  x->FederationTerminationNotificationProtocolProfile = zx_deep_clone_simple_elems(c,x->FederationTerminationNotificationProtocolProfile, dup_strs);
  x->SingleLogoutProtocolProfile = zx_deep_clone_simple_elems(c,x->SingleLogoutProtocolProfile, dup_strs);
  x->RegisterNameIdentifierProtocolProfile = zx_deep_clone_simple_elems(c,x->RegisterNameIdentifierProtocolProfile, dup_strs);
  x->RegisterNameIdentifierServiceURL = zx_deep_clone_simple_elems(c,x->RegisterNameIdentifierServiceURL, dup_strs);
  x->RegisterNameIdentifierServiceReturnURL = zx_deep_clone_simple_elems(c,x->RegisterNameIdentifierServiceReturnURL, dup_strs);
  x->NameIdentifierMappingProtocolProfile = zx_deep_clone_simple_elems(c,x->NameIdentifierMappingProtocolProfile, dup_strs);
  x->NameIdentifierMappingEncryptionProfile = zx_deep_clone_simple_elems(c,x->NameIdentifierMappingEncryptionProfile, dup_strs);
  {
      struct zx_m20_Organization_s* e;
      struct zx_m20_Organization_s* en;
      struct zx_m20_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      struct zx_m20_ContactPerson_s* en;
      struct zx_m20_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      struct zx_m20_AdditionalMetaLocation_s* en;
      struct zx_m20_AdditionalMetaLocation_s* enn;
      for (enn = 0, e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_AdditionalMetaLocation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalMetaLocation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
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
  x->SingleSignOnServiceURL = zx_deep_clone_simple_elems(c,x->SingleSignOnServiceURL, dup_strs);
  x->SingleSignOnProtocolProfile = zx_deep_clone_simple_elems(c,x->SingleSignOnProtocolProfile, dup_strs);
  x->AuthnServiceURL = zx_deep_clone_simple_elems(c,x->AuthnServiceURL, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_m20_IDPDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SoapEndpoint, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleLogoutServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleLogoutServiceReturnURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FederationTerminationServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FederationTerminationServiceReturnURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FederationTerminationNotificationProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleLogoutProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RegisterNameIdentifierProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RegisterNameIdentifierServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RegisterNameIdentifierServiceReturnURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->NameIdentifierMappingProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->NameIdentifierMappingEncryptionProfile, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_AdditionalMetaLocation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
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
  ret = zx_walk_so_simple_elems(c, x->SingleSignOnServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleSignOnProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuthnServiceURL, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_m20_IDPDescriptor) */

int zx_WALK_WO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_KeyDescriptor
#define EL_STRUCT zx_m20_KeyDescriptor_s
#define EL_NS     m20
#define EL_TAG    KeyDescriptor

/* FUNC(zx_FREE_m20_KeyDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->use, free_strs);

  zx_free_simple_elems(c, x->EncryptionMethod, free_strs);
  zx_free_simple_elems(c, x->KeySize, free_strs);
  {
      struct zx_ds_KeyInfo_s* e;
      struct zx_ds_KeyInfo_s* en;
      for (e = x->KeyInfo; e; e = en) {
	  en = (struct zx_ds_KeyInfo_s*)e->gg.g.n;
	  zx_FREE_ds_KeyInfo(c, e, free_strs);
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_KeyDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_KeyDescriptor_s* zx_NEW_m20_KeyDescriptor(struct zx_ctx* c)
{
  struct zx_m20_KeyDescriptor_s* x = ZX_ZALLOC(c, struct zx_m20_KeyDescriptor_s);
  x->gg.g.tok = zx_m20_KeyDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_KeyDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->use);

  zx_dup_strs_simple_elems(c, x->EncryptionMethod);
  zx_dup_strs_simple_elems(c, x->KeySize);
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_m20_KeyDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_KeyDescriptor_s* zx_DEEP_CLONE_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x, int dup_strs)
{
  x = (struct zx_m20_KeyDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_KeyDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->use = zx_clone_attr(c, x->use);

  x->EncryptionMethod = zx_deep_clone_simple_elems(c,x->EncryptionMethod, dup_strs);
  x->KeySize = zx_deep_clone_simple_elems(c,x->KeySize, dup_strs);
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
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_m20_KeyDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->EncryptionMethod, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->KeySize, ctx, callback);
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
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_m20_KeyDescriptor) */

int zx_WALK_WO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_Organization
#define EL_STRUCT zx_m20_Organization_s
#define EL_NS     m20
#define EL_TAG    Organization

/* FUNC(zx_FREE_m20_Organization) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_m20_OrganizationName_s* e;
      struct zx_m20_OrganizationName_s* en;
      for (e = x->OrganizationName; e; e = en) {
	  en = (struct zx_m20_OrganizationName_s*)e->gg.g.n;
	  zx_FREE_m20_OrganizationName(c, e, free_strs);
      }
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      struct zx_m20_OrganizationDisplayName_s* en;
      for (e = x->OrganizationDisplayName; e; e = en) {
	  en = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n;
	  zx_FREE_m20_OrganizationDisplayName(c, e, free_strs);
      }
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      struct zx_m20_OrganizationURL_s* en;
      for (e = x->OrganizationURL; e; e = en) {
	  en = (struct zx_m20_OrganizationURL_s*)e->gg.g.n;
	  zx_FREE_m20_OrganizationURL(c, e, free_strs);
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_Organization) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_Organization_s* zx_NEW_m20_Organization(struct zx_ctx* c)
{
  struct zx_m20_Organization_s* x = ZX_ZALLOC(c, struct zx_m20_Organization_s);
  x->gg.g.tok = zx_m20_Organization_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_Organization) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_m20_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_m20_OrganizationName_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_OrganizationName(c, e);
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_OrganizationDisplayName(c, e);
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_m20_OrganizationURL_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_OrganizationURL(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_m20_Organization) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_Organization_s* zx_DEEP_CLONE_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x, int dup_strs)
{
  x = (struct zx_m20_Organization_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_Organization_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_m20_OrganizationName_s* e;
      struct zx_m20_OrganizationName_s* en;
      struct zx_m20_OrganizationName_s* enn;
      for (enn = 0, e = x->OrganizationName; e; e = (struct zx_m20_OrganizationName_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_OrganizationName(c, e, dup_strs);
	  if (!enn)
	      x->OrganizationName = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      struct zx_m20_OrganizationDisplayName_s* en;
      struct zx_m20_OrganizationDisplayName_s* enn;
      for (enn = 0, e = x->OrganizationDisplayName; e; e = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_OrganizationDisplayName(c, e, dup_strs);
	  if (!enn)
	      x->OrganizationDisplayName = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      struct zx_m20_OrganizationURL_s* en;
      struct zx_m20_OrganizationURL_s* enn;
      for (enn = 0, e = x->OrganizationURL; e; e = (struct zx_m20_OrganizationURL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_OrganizationURL(c, e, dup_strs);
	  if (!enn)
	      x->OrganizationURL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_m20_Organization) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_m20_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_m20_OrganizationName_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_OrganizationName(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_OrganizationDisplayName(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_m20_OrganizationURL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_OrganizationURL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_m20_Organization) */

int zx_WALK_WO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_OrganizationDisplayName
#define EL_STRUCT zx_m20_OrganizationDisplayName_s
#define EL_NS     m20
#define EL_TAG    OrganizationDisplayName

/* FUNC(zx_FREE_m20_OrganizationDisplayName) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_OrganizationDisplayName) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_OrganizationDisplayName_s* zx_NEW_m20_OrganizationDisplayName(struct zx_ctx* c)
{
  struct zx_m20_OrganizationDisplayName_s* x = ZX_ZALLOC(c, struct zx_m20_OrganizationDisplayName_s);
  x->gg.g.tok = zx_m20_OrganizationDisplayName_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_OrganizationDisplayName) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_m20_OrganizationDisplayName) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_OrganizationDisplayName_s* zx_DEEP_CLONE_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x, int dup_strs)
{
  x = (struct zx_m20_OrganizationDisplayName_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_OrganizationDisplayName_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_m20_OrganizationDisplayName) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_m20_OrganizationDisplayName) */

int zx_WALK_WO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_OrganizationName
#define EL_STRUCT zx_m20_OrganizationName_s
#define EL_NS     m20
#define EL_TAG    OrganizationName

/* FUNC(zx_FREE_m20_OrganizationName) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_OrganizationName) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_OrganizationName_s* zx_NEW_m20_OrganizationName(struct zx_ctx* c)
{
  struct zx_m20_OrganizationName_s* x = ZX_ZALLOC(c, struct zx_m20_OrganizationName_s);
  x->gg.g.tok = zx_m20_OrganizationName_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_OrganizationName) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_m20_OrganizationName) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_OrganizationName_s* zx_DEEP_CLONE_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x, int dup_strs)
{
  x = (struct zx_m20_OrganizationName_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_OrganizationName_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_m20_OrganizationName) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_m20_OrganizationName) */

int zx_WALK_WO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_OrganizationURL
#define EL_STRUCT zx_m20_OrganizationURL_s
#define EL_NS     m20
#define EL_TAG    OrganizationURL

/* FUNC(zx_FREE_m20_OrganizationURL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_OrganizationURL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_OrganizationURL_s* zx_NEW_m20_OrganizationURL(struct zx_ctx* c)
{
  struct zx_m20_OrganizationURL_s* x = ZX_ZALLOC(c, struct zx_m20_OrganizationURL_s);
  x->gg.g.tok = zx_m20_OrganizationURL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_OrganizationURL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);


}

/* FUNC(zx_DEEP_CLONE_m20_OrganizationURL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_OrganizationURL_s* zx_DEEP_CLONE_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x, int dup_strs)
{
  x = (struct zx_m20_OrganizationURL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_OrganizationURL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);


  return x;
}

/* FUNC(zx_WALK_SO_m20_OrganizationURL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_m20_OrganizationURL) */

int zx_WALK_WO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   m20_SPDescriptor
#define EL_STRUCT zx_m20_SPDescriptor_s
#define EL_NS     m20
#define EL_TAG    SPDescriptor

/* FUNC(zx_FREE_m20_SPDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->cacheDuration, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->protocolSupportEnumeration, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);

  {
      struct zx_m20_KeyDescriptor_s* e;
      struct zx_m20_KeyDescriptor_s* en;
      for (e = x->KeyDescriptor; e; e = en) {
	  en = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_KeyDescriptor(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SoapEndpoint, free_strs);
  zx_free_simple_elems(c, x->SingleLogoutServiceURL, free_strs);
  zx_free_simple_elems(c, x->SingleLogoutServiceReturnURL, free_strs);
  zx_free_simple_elems(c, x->FederationTerminationServiceURL, free_strs);
  zx_free_simple_elems(c, x->FederationTerminationServiceReturnURL, free_strs);
  zx_free_simple_elems(c, x->FederationTerminationNotificationProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->SingleLogoutProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->RegisterNameIdentifierProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->RegisterNameIdentifierServiceURL, free_strs);
  zx_free_simple_elems(c, x->RegisterNameIdentifierServiceReturnURL, free_strs);
  zx_free_simple_elems(c, x->NameIdentifierMappingProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->NameIdentifierMappingEncryptionProfile, free_strs);
  {
      struct zx_m20_Organization_s* e;
      struct zx_m20_Organization_s* en;
      for (e = x->Organization; e; e = en) {
	  en = (struct zx_m20_Organization_s*)e->gg.g.n;
	  zx_FREE_m20_Organization(c, e, free_strs);
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      struct zx_m20_ContactPerson_s* en;
      for (e = x->ContactPerson; e; e = en) {
	  en = (struct zx_m20_ContactPerson_s*)e->gg.g.n;
	  zx_FREE_m20_ContactPerson(c, e, free_strs);
      }
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      struct zx_m20_AdditionalMetaLocation_s* en;
      for (e = x->AdditionalMetaLocation; e; e = en) {
	  en = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n;
	  zx_FREE_m20_AdditionalMetaLocation(c, e, free_strs);
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_m20_Extension_s*)e->gg.g.n;
	  zx_FREE_m20_Extension(c, e, free_strs);
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
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      struct zx_m20_AssertionConsumerServiceURL_s* en;
      for (e = x->AssertionConsumerServiceURL; e; e = en) {
	  en = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n;
	  zx_FREE_m20_AssertionConsumerServiceURL(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AuthnRequestsSigned, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_m20_SPDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_m20_SPDescriptor_s* zx_NEW_m20_SPDescriptor(struct zx_ctx* c)
{
  struct zx_m20_SPDescriptor_s* x = ZX_ZALLOC(c, struct zx_m20_SPDescriptor_s);
  x->gg.g.tok = zx_m20_SPDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_m20_SPDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->cacheDuration);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->protocolSupportEnumeration);
  zx_dup_attr(c, x->validUntil);

  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_KeyDescriptor(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SoapEndpoint);
  zx_dup_strs_simple_elems(c, x->SingleLogoutServiceURL);
  zx_dup_strs_simple_elems(c, x->SingleLogoutServiceReturnURL);
  zx_dup_strs_simple_elems(c, x->FederationTerminationServiceURL);
  zx_dup_strs_simple_elems(c, x->FederationTerminationServiceReturnURL);
  zx_dup_strs_simple_elems(c, x->FederationTerminationNotificationProtocolProfile);
  zx_dup_strs_simple_elems(c, x->SingleLogoutProtocolProfile);
  zx_dup_strs_simple_elems(c, x->RegisterNameIdentifierProtocolProfile);
  zx_dup_strs_simple_elems(c, x->RegisterNameIdentifierServiceURL);
  zx_dup_strs_simple_elems(c, x->RegisterNameIdentifierServiceReturnURL);
  zx_dup_strs_simple_elems(c, x->NameIdentifierMappingProtocolProfile);
  zx_dup_strs_simple_elems(c, x->NameIdentifierMappingEncryptionProfile);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Organization(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_AdditionalMetaLocation(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      for (e = x->AssertionConsumerServiceURL; e; e = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_AssertionConsumerServiceURL(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AuthnRequestsSigned);

}

/* FUNC(zx_DEEP_CLONE_m20_SPDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_m20_SPDescriptor_s* zx_DEEP_CLONE_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x, int dup_strs)
{
  x = (struct zx_m20_SPDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_m20_SPDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->cacheDuration = zx_clone_attr(c, x->cacheDuration);
  x->id = zx_clone_attr(c, x->id);
  x->protocolSupportEnumeration = zx_clone_attr(c, x->protocolSupportEnumeration);
  x->validUntil = zx_clone_attr(c, x->validUntil);

  {
      struct zx_m20_KeyDescriptor_s* e;
      struct zx_m20_KeyDescriptor_s* en;
      struct zx_m20_KeyDescriptor_s* enn;
      for (enn = 0, e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_KeyDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->KeyDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SoapEndpoint = zx_deep_clone_simple_elems(c,x->SoapEndpoint, dup_strs);
  x->SingleLogoutServiceURL = zx_deep_clone_simple_elems(c,x->SingleLogoutServiceURL, dup_strs);
  x->SingleLogoutServiceReturnURL = zx_deep_clone_simple_elems(c,x->SingleLogoutServiceReturnURL, dup_strs);
  x->FederationTerminationServiceURL = zx_deep_clone_simple_elems(c,x->FederationTerminationServiceURL, dup_strs);
  x->FederationTerminationServiceReturnURL = zx_deep_clone_simple_elems(c,x->FederationTerminationServiceReturnURL, dup_strs);
  x->FederationTerminationNotificationProtocolProfile = zx_deep_clone_simple_elems(c,x->FederationTerminationNotificationProtocolProfile, dup_strs);
  x->SingleLogoutProtocolProfile = zx_deep_clone_simple_elems(c,x->SingleLogoutProtocolProfile, dup_strs);
  x->RegisterNameIdentifierProtocolProfile = zx_deep_clone_simple_elems(c,x->RegisterNameIdentifierProtocolProfile, dup_strs);
  x->RegisterNameIdentifierServiceURL = zx_deep_clone_simple_elems(c,x->RegisterNameIdentifierServiceURL, dup_strs);
  x->RegisterNameIdentifierServiceReturnURL = zx_deep_clone_simple_elems(c,x->RegisterNameIdentifierServiceReturnURL, dup_strs);
  x->NameIdentifierMappingProtocolProfile = zx_deep_clone_simple_elems(c,x->NameIdentifierMappingProtocolProfile, dup_strs);
  x->NameIdentifierMappingEncryptionProfile = zx_deep_clone_simple_elems(c,x->NameIdentifierMappingEncryptionProfile, dup_strs);
  {
      struct zx_m20_Organization_s* e;
      struct zx_m20_Organization_s* en;
      struct zx_m20_Organization_s* enn;
      for (enn = 0, e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Organization(c, e, dup_strs);
	  if (!enn)
	      x->Organization = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      struct zx_m20_ContactPerson_s* en;
      struct zx_m20_ContactPerson_s* enn;
      for (enn = 0, e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_ContactPerson(c, e, dup_strs);
	  if (!enn)
	      x->ContactPerson = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      struct zx_m20_AdditionalMetaLocation_s* en;
      struct zx_m20_AdditionalMetaLocation_s* enn;
      for (enn = 0, e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_AdditionalMetaLocation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalMetaLocation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      struct zx_m20_Extension_s* en;
      struct zx_m20_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
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
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      struct zx_m20_AssertionConsumerServiceURL_s* en;
      struct zx_m20_AssertionConsumerServiceURL_s* enn;
      for (enn = 0, e = x->AssertionConsumerServiceURL; e; e = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_AssertionConsumerServiceURL(c, e, dup_strs);
	  if (!enn)
	      x->AssertionConsumerServiceURL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AuthnRequestsSigned = zx_deep_clone_simple_elems(c,x->AuthnRequestsSigned, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_m20_SPDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_KeyDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SoapEndpoint, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleLogoutServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleLogoutServiceReturnURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FederationTerminationServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FederationTerminationServiceReturnURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FederationTerminationNotificationProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SingleLogoutProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RegisterNameIdentifierProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RegisterNameIdentifierServiceURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RegisterNameIdentifierServiceReturnURL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->NameIdentifierMappingProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->NameIdentifierMappingEncryptionProfile, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Organization(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_ContactPerson(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_AdditionalMetaLocation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_Extension(c, e, ctx, callback);
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
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      for (e = x->AssertionConsumerServiceURL; e; e = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_AssertionConsumerServiceURL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AuthnRequestsSigned, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_m20_SPDescriptor) */

int zx_WALK_WO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-m20-aux.c */
