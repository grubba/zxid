/* c/zx-sp-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sp-data.h"



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

#define EL_NAME   sp_ArtifactResolve
#define EL_STRUCT zx_sp_ArtifactResolve_s
#define EL_NS     sp
#define EL_TAG    ArtifactResolve

/* FUNC(zx_FREE_sp_ArtifactResolve) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_ArtifactResolve(struct zx_ctx* c, struct zx_sp_ArtifactResolve_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Artifact, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_ArtifactResolve) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_ArtifactResolve_s* zx_NEW_sp_ArtifactResolve(struct zx_ctx* c)
{
  struct zx_sp_ArtifactResolve_s* x = ZX_ZALLOC(c, struct zx_sp_ArtifactResolve_s);
  x->gg.g.tok = zx_sp_ArtifactResolve_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_ArtifactResolve) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_ArtifactResolve(struct zx_ctx* c, struct zx_sp_ArtifactResolve_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Artifact);

}

/* FUNC(zx_DEEP_CLONE_sp_ArtifactResolve) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_ArtifactResolve_s* zx_DEEP_CLONE_sp_ArtifactResolve(struct zx_ctx* c, struct zx_sp_ArtifactResolve_s* x, int dup_strs)
{
  x = (struct zx_sp_ArtifactResolve_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_ArtifactResolve_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Artifact = zx_deep_clone_simple_elems(c,x->Artifact, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_ArtifactResolve) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_ArtifactResolve(struct zx_ctx* c, struct zx_sp_ArtifactResolve_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Artifact, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_ArtifactResolve) */

int zx_WALK_WO_sp_ArtifactResolve(struct zx_ctx* c, struct zx_sp_ArtifactResolve_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_ArtifactResponse
#define EL_STRUCT zx_sp_ArtifactResponse_s
#define EL_NS     sp
#define EL_TAG    ArtifactResponse

/* FUNC(zx_FREE_sp_ArtifactResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_ArtifactResponse(struct zx_ctx* c, struct zx_sp_ArtifactResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp_Status_s*)e->gg.g.n;
	  zx_FREE_sp_Status(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Response_s* e;
      struct zx_sp_Response_s* en;
      for (e = x->Response; e; e = en) {
	  en = (struct zx_sp_Response_s*)e->gg.g.n;
	  zx_FREE_sp_Response(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_ArtifactResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_ArtifactResponse_s* zx_NEW_sp_ArtifactResponse(struct zx_ctx* c)
{
  struct zx_sp_ArtifactResponse_s* x = ZX_ZALLOC(c, struct zx_sp_ArtifactResponse_s);
  x->gg.g.tok = zx_sp_ArtifactResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_ArtifactResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_ArtifactResponse(struct zx_ctx* c, struct zx_sp_ArtifactResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Status(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Response(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_ArtifactResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_ArtifactResponse_s* zx_DEEP_CLONE_sp_ArtifactResponse(struct zx_ctx* c, struct zx_sp_ArtifactResponse_s* x, int dup_strs)
{
  x = (struct zx_sp_ArtifactResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_ArtifactResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      struct zx_sp_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Response_s* e;
      struct zx_sp_Response_s* en;
      struct zx_sp_Response_s* enn;
      for (enn = 0, e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Response(c, e, dup_strs);
	  if (!enn)
	      x->Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_ArtifactResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_ArtifactResponse(struct zx_ctx* c, struct zx_sp_ArtifactResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_ArtifactResponse) */

int zx_WALK_WO_sp_ArtifactResponse(struct zx_ctx* c, struct zx_sp_ArtifactResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_AssertionIDRequest
#define EL_STRUCT zx_sp_AssertionIDRequest_s
#define EL_NS     sp
#define EL_TAG    AssertionIDRequest

/* FUNC(zx_FREE_sp_AssertionIDRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_AssertionIDRequest(struct zx_ctx* c, struct zx_sp_AssertionIDRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AssertionIDRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_AssertionIDRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_AssertionIDRequest_s* zx_NEW_sp_AssertionIDRequest(struct zx_ctx* c)
{
  struct zx_sp_AssertionIDRequest_s* x = ZX_ZALLOC(c, struct zx_sp_AssertionIDRequest_s);
  x->gg.g.tok = zx_sp_AssertionIDRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_AssertionIDRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_AssertionIDRequest(struct zx_ctx* c, struct zx_sp_AssertionIDRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AssertionIDRef);

}

/* FUNC(zx_DEEP_CLONE_sp_AssertionIDRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_AssertionIDRequest_s* zx_DEEP_CLONE_sp_AssertionIDRequest(struct zx_ctx* c, struct zx_sp_AssertionIDRequest_s* x, int dup_strs)
{
  x = (struct zx_sp_AssertionIDRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_AssertionIDRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AssertionIDRef = zx_deep_clone_simple_elems(c,x->AssertionIDRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_AssertionIDRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_AssertionIDRequest(struct zx_ctx* c, struct zx_sp_AssertionIDRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AssertionIDRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_AssertionIDRequest) */

int zx_WALK_WO_sp_AssertionIDRequest(struct zx_ctx* c, struct zx_sp_AssertionIDRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_AttributeQuery
#define EL_STRUCT zx_sp_AttributeQuery_s
#define EL_NS     sp
#define EL_TAG    AttributeQuery

/* FUNC(zx_FREE_sp_AttributeQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_AttributeQuery(struct zx_ctx* c, struct zx_sp_AttributeQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa_Subject_s*)e->gg.g.n;
	  zx_FREE_sa_Subject(c, e, free_strs);
      }
  }
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

/* FUNC(zx_NEW_sp_AttributeQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_AttributeQuery_s* zx_NEW_sp_AttributeQuery(struct zx_ctx* c)
{
  struct zx_sp_AttributeQuery_s* x = ZX_ZALLOC(c, struct zx_sp_AttributeQuery_s);
  x->gg.g.tok = zx_sp_AttributeQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_AttributeQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_AttributeQuery(struct zx_ctx* c, struct zx_sp_AttributeQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Attribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_AttributeQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_AttributeQuery_s* zx_DEEP_CLONE_sp_AttributeQuery(struct zx_ctx* c, struct zx_sp_AttributeQuery_s* x, int dup_strs)
{
  x = (struct zx_sp_AttributeQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_AttributeQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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

/* FUNC(zx_WALK_SO_sp_AttributeQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_AttributeQuery(struct zx_ctx* c, struct zx_sp_AttributeQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
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

/* FUNC(zx_WALK_WO_sp_AttributeQuery) */

int zx_WALK_WO_sp_AttributeQuery(struct zx_ctx* c, struct zx_sp_AttributeQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_AuthnQuery
#define EL_STRUCT zx_sp_AuthnQuery_s
#define EL_NS     sp
#define EL_TAG    AuthnQuery

/* FUNC(zx_FREE_sp_AuthnQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_AuthnQuery(struct zx_ctx* c, struct zx_sp_AuthnQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->SessionIndex, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa_Subject_s*)e->gg.g.n;
	  zx_FREE_sa_Subject(c, e, free_strs);
      }
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      struct zx_sp_RequestedAuthnContext_s* en;
      for (e = x->RequestedAuthnContext; e; e = en) {
	  en = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n;
	  zx_FREE_sp_RequestedAuthnContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_AuthnQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_AuthnQuery_s* zx_NEW_sp_AuthnQuery(struct zx_ctx* c)
{
  struct zx_sp_AuthnQuery_s* x = ZX_ZALLOC(c, struct zx_sp_AuthnQuery_s);
  x->gg.g.tok = zx_sp_AuthnQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_AuthnQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_AuthnQuery(struct zx_ctx* c, struct zx_sp_AuthnQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->SessionIndex);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      for (e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_RequestedAuthnContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_AuthnQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_AuthnQuery_s* zx_DEEP_CLONE_sp_AuthnQuery(struct zx_ctx* c, struct zx_sp_AuthnQuery_s* x, int dup_strs)
{
  x = (struct zx_sp_AuthnQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_AuthnQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->SessionIndex = zx_clone_attr(c, x->SessionIndex);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      struct zx_sp_RequestedAuthnContext_s* en;
      struct zx_sp_RequestedAuthnContext_s* enn;
      for (enn = 0, e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_RequestedAuthnContext(c, e, dup_strs);
	  if (!enn)
	      x->RequestedAuthnContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_AuthnQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_AuthnQuery(struct zx_ctx* c, struct zx_sp_AuthnQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      for (e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_RequestedAuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_AuthnQuery) */

int zx_WALK_WO_sp_AuthnQuery(struct zx_ctx* c, struct zx_sp_AuthnQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_AuthnRequest
#define EL_STRUCT zx_sp_AuthnRequest_s
#define EL_NS     sp
#define EL_TAG    AuthnRequest

/* FUNC(zx_FREE_sp_AuthnRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_AuthnRequest(struct zx_ctx* c, struct zx_sp_AuthnRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AssertionConsumerServiceIndex, free_strs);
  zx_free_attr(c, x->AssertionConsumerServiceURL, free_strs);
  zx_free_attr(c, x->AttributeConsumingServiceIndex, free_strs);
  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ForceAuthn, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IsPassive, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->ProtocolBinding, free_strs);
  zx_free_attr(c, x->ProviderName, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa_Subject_s*)e->gg.g.n;
	  zx_FREE_sa_Subject(c, e, free_strs);
      }
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      struct zx_sp_NameIDPolicy_s* en;
      for (e = x->NameIDPolicy; e; e = en) {
	  en = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n;
	  zx_FREE_sp_NameIDPolicy(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Conditions_s* e;
      struct zx_sa_Conditions_s* en;
      for (e = x->Conditions; e; e = en) {
	  en = (struct zx_sa_Conditions_s*)e->gg.g.n;
	  zx_FREE_sa_Conditions(c, e, free_strs);
      }
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      struct zx_sp_RequestedAuthnContext_s* en;
      for (e = x->RequestedAuthnContext; e; e = en) {
	  en = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n;
	  zx_FREE_sp_RequestedAuthnContext(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Scoping_s* e;
      struct zx_sp_Scoping_s* en;
      for (e = x->Scoping; e; e = en) {
	  en = (struct zx_sp_Scoping_s*)e->gg.g.n;
	  zx_FREE_sp_Scoping(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_AuthnRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_AuthnRequest_s* zx_NEW_sp_AuthnRequest(struct zx_ctx* c)
{
  struct zx_sp_AuthnRequest_s* x = ZX_ZALLOC(c, struct zx_sp_AuthnRequest_s);
  x->gg.g.tok = zx_sp_AuthnRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_AuthnRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_AuthnRequest(struct zx_ctx* c, struct zx_sp_AuthnRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AssertionConsumerServiceIndex);
  zx_dup_attr(c, x->AssertionConsumerServiceURL);
  zx_dup_attr(c, x->AttributeConsumingServiceIndex);
  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ForceAuthn);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IsPassive);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->ProtocolBinding);
  zx_dup_attr(c, x->ProviderName);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      for (e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_NameIDPolicy(c, e);
  }
  {
      struct zx_sa_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa_Conditions_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Conditions(c, e);
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      for (e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_RequestedAuthnContext(c, e);
  }
  {
      struct zx_sp_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_sp_Scoping_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Scoping(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_AuthnRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_AuthnRequest_s* zx_DEEP_CLONE_sp_AuthnRequest(struct zx_ctx* c, struct zx_sp_AuthnRequest_s* x, int dup_strs)
{
  x = (struct zx_sp_AuthnRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_AuthnRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AssertionConsumerServiceIndex = zx_clone_attr(c, x->AssertionConsumerServiceIndex);
  x->AssertionConsumerServiceURL = zx_clone_attr(c, x->AssertionConsumerServiceURL);
  x->AttributeConsumingServiceIndex = zx_clone_attr(c, x->AttributeConsumingServiceIndex);
  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ForceAuthn = zx_clone_attr(c, x->ForceAuthn);
  x->ID = zx_clone_attr(c, x->ID);
  x->IsPassive = zx_clone_attr(c, x->IsPassive);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->ProtocolBinding = zx_clone_attr(c, x->ProtocolBinding);
  x->ProviderName = zx_clone_attr(c, x->ProviderName);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
  {
      struct zx_sp_NameIDPolicy_s* e;
      struct zx_sp_NameIDPolicy_s* en;
      struct zx_sp_NameIDPolicy_s* enn;
      for (enn = 0, e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_NameIDPolicy(c, e, dup_strs);
	  if (!enn)
	      x->NameIDPolicy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_Conditions_s* e;
      struct zx_sa_Conditions_s* en;
      struct zx_sa_Conditions_s* enn;
      for (enn = 0, e = x->Conditions; e; e = (struct zx_sa_Conditions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Conditions(c, e, dup_strs);
	  if (!enn)
	      x->Conditions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      struct zx_sp_RequestedAuthnContext_s* en;
      struct zx_sp_RequestedAuthnContext_s* enn;
      for (enn = 0, e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_RequestedAuthnContext(c, e, dup_strs);
	  if (!enn)
	      x->RequestedAuthnContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Scoping_s* e;
      struct zx_sp_Scoping_s* en;
      struct zx_sp_Scoping_s* enn;
      for (enn = 0, e = x->Scoping; e; e = (struct zx_sp_Scoping_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Scoping(c, e, dup_strs);
	  if (!enn)
	      x->Scoping = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_AuthnRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_AuthnRequest(struct zx_ctx* c, struct zx_sp_AuthnRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      for (e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_NameIDPolicy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa_Conditions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Conditions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_RequestedAuthnContext_s* e;
      for (e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_RequestedAuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_sp_Scoping_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Scoping(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_AuthnRequest) */

int zx_WALK_WO_sp_AuthnRequest(struct zx_ctx* c, struct zx_sp_AuthnRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_AuthzDecisionQuery
#define EL_STRUCT zx_sp_AuthzDecisionQuery_s
#define EL_NS     sp
#define EL_TAG    AuthzDecisionQuery

/* FUNC(zx_FREE_sp_AuthzDecisionQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_AuthzDecisionQuery(struct zx_ctx* c, struct zx_sp_AuthzDecisionQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Resource, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa_Subject_s*)e->gg.g.n;
	  zx_FREE_sa_Subject(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Action_s* e;
      struct zx_sa_Action_s* en;
      for (e = x->Action; e; e = en) {
	  en = (struct zx_sa_Action_s*)e->gg.g.n;
	  zx_FREE_sa_Action(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Evidence_s* e;
      struct zx_sa_Evidence_s* en;
      for (e = x->Evidence; e; e = en) {
	  en = (struct zx_sa_Evidence_s*)e->gg.g.n;
	  zx_FREE_sa_Evidence(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_AuthzDecisionQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_AuthzDecisionQuery_s* zx_NEW_sp_AuthzDecisionQuery(struct zx_ctx* c)
{
  struct zx_sp_AuthzDecisionQuery_s* x = ZX_ZALLOC(c, struct zx_sp_AuthzDecisionQuery_s);
  x->gg.g.tok = zx_sp_AuthzDecisionQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_AuthzDecisionQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_AuthzDecisionQuery(struct zx_ctx* c, struct zx_sp_AuthzDecisionQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Resource);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }
  {
      struct zx_sa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa_Action_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Action(c, e);
  }
  {
      struct zx_sa_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa_Evidence_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Evidence(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_AuthzDecisionQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_AuthzDecisionQuery_s* zx_DEEP_CLONE_sp_AuthzDecisionQuery(struct zx_ctx* c, struct zx_sp_AuthzDecisionQuery_s* x, int dup_strs)
{
  x = (struct zx_sp_AuthzDecisionQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_AuthzDecisionQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Resource = zx_clone_attr(c, x->Resource);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
  {
      struct zx_sa_Action_s* e;
      struct zx_sa_Action_s* en;
      struct zx_sa_Action_s* enn;
      for (enn = 0, e = x->Action; e; e = (struct zx_sa_Action_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Action(c, e, dup_strs);
	  if (!enn)
	      x->Action = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_Evidence_s* e;
      struct zx_sa_Evidence_s* en;
      struct zx_sa_Evidence_s* enn;
      for (enn = 0, e = x->Evidence; e; e = (struct zx_sa_Evidence_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Evidence(c, e, dup_strs);
	  if (!enn)
	      x->Evidence = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_AuthzDecisionQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_AuthzDecisionQuery(struct zx_ctx* c, struct zx_sp_AuthzDecisionQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa_Action_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Action(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa_Evidence_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Evidence(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_AuthzDecisionQuery) */

int zx_WALK_WO_sp_AuthzDecisionQuery(struct zx_ctx* c, struct zx_sp_AuthzDecisionQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_Extensions
#define EL_STRUCT zx_sp_Extensions_s
#define EL_NS     sp
#define EL_TAG    Extensions

/* FUNC(zx_FREE_sp_Extensions) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_Extensions(struct zx_ctx* c, struct zx_sp_Extensions_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_Extensions) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_Extensions_s* zx_NEW_sp_Extensions(struct zx_ctx* c)
{
  struct zx_sp_Extensions_s* x = ZX_ZALLOC(c, struct zx_sp_Extensions_s);
  x->gg.g.tok = zx_sp_Extensions_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_Extensions) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_Extensions(struct zx_ctx* c, struct zx_sp_Extensions_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_sp_Extensions) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_Extensions_s* zx_DEEP_CLONE_sp_Extensions(struct zx_ctx* c, struct zx_sp_Extensions_s* x, int dup_strs)
{
  x = (struct zx_sp_Extensions_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_Extensions_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_sp_Extensions) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_Extensions(struct zx_ctx* c, struct zx_sp_Extensions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sp_Extensions) */

int zx_WALK_WO_sp_Extensions(struct zx_ctx* c, struct zx_sp_Extensions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_IDPEntry
#define EL_STRUCT zx_sp_IDPEntry_s
#define EL_NS     sp
#define EL_TAG    IDPEntry

/* FUNC(zx_FREE_sp_IDPEntry) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_IDPEntry(struct zx_ctx* c, struct zx_sp_IDPEntry_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Loc, free_strs);
  zx_free_attr(c, x->Name, free_strs);
  zx_free_attr(c, x->ProviderID, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_IDPEntry) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_IDPEntry_s* zx_NEW_sp_IDPEntry(struct zx_ctx* c)
{
  struct zx_sp_IDPEntry_s* x = ZX_ZALLOC(c, struct zx_sp_IDPEntry_s);
  x->gg.g.tok = zx_sp_IDPEntry_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_IDPEntry) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_IDPEntry(struct zx_ctx* c, struct zx_sp_IDPEntry_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Loc);
  zx_dup_attr(c, x->Name);
  zx_dup_attr(c, x->ProviderID);


}

/* FUNC(zx_DEEP_CLONE_sp_IDPEntry) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_IDPEntry_s* zx_DEEP_CLONE_sp_IDPEntry(struct zx_ctx* c, struct zx_sp_IDPEntry_s* x, int dup_strs)
{
  x = (struct zx_sp_IDPEntry_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_IDPEntry_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Loc = zx_clone_attr(c, x->Loc);
  x->Name = zx_clone_attr(c, x->Name);
  x->ProviderID = zx_clone_attr(c, x->ProviderID);


  return x;
}

/* FUNC(zx_WALK_SO_sp_IDPEntry) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_IDPEntry(struct zx_ctx* c, struct zx_sp_IDPEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sp_IDPEntry) */

int zx_WALK_WO_sp_IDPEntry(struct zx_ctx* c, struct zx_sp_IDPEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_IDPList
#define EL_STRUCT zx_sp_IDPList_s
#define EL_NS     sp
#define EL_TAG    IDPList

/* FUNC(zx_FREE_sp_IDPList) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_IDPList(struct zx_ctx* c, struct zx_sp_IDPList_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp_IDPEntry_s* e;
      struct zx_sp_IDPEntry_s* en;
      for (e = x->IDPEntry; e; e = en) {
	  en = (struct zx_sp_IDPEntry_s*)e->gg.g.n;
	  zx_FREE_sp_IDPEntry(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->GetComplete, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_IDPList) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_IDPList_s* zx_NEW_sp_IDPList(struct zx_ctx* c)
{
  struct zx_sp_IDPList_s* x = ZX_ZALLOC(c, struct zx_sp_IDPList_s);
  x->gg.g.tok = zx_sp_IDPList_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_IDPList) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_IDPList(struct zx_ctx* c, struct zx_sp_IDPList_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_sp_IDPEntry_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_IDPEntry(c, e);
  }
  zx_dup_strs_simple_elems(c, x->GetComplete);

}

/* FUNC(zx_DEEP_CLONE_sp_IDPList) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_IDPList_s* zx_DEEP_CLONE_sp_IDPList(struct zx_ctx* c, struct zx_sp_IDPList_s* x, int dup_strs)
{
  x = (struct zx_sp_IDPList_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_IDPList_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp_IDPEntry_s* e;
      struct zx_sp_IDPEntry_s* en;
      struct zx_sp_IDPEntry_s* enn;
      for (enn = 0, e = x->IDPEntry; e; e = (struct zx_sp_IDPEntry_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_IDPEntry(c, e, dup_strs);
	  if (!enn)
	      x->IDPEntry = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->GetComplete = zx_deep_clone_simple_elems(c,x->GetComplete, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_IDPList) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_IDPList(struct zx_ctx* c, struct zx_sp_IDPList_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_sp_IDPEntry_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_IDPEntry(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->GetComplete, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_IDPList) */

int zx_WALK_WO_sp_IDPList(struct zx_ctx* c, struct zx_sp_IDPList_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_LogoutRequest
#define EL_STRUCT zx_sp_LogoutRequest_s
#define EL_NS     sp
#define EL_TAG    LogoutRequest

/* FUNC(zx_FREE_sp_LogoutRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_LogoutRequest(struct zx_ctx* c, struct zx_sp_LogoutRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->NotOnOrAfter, free_strs);
  zx_free_attr(c, x->Reason, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_BaseID_s* e;
      struct zx_sa_BaseID_s* en;
      for (e = x->BaseID; e; e = en) {
	  en = (struct zx_sa_BaseID_s*)e->gg.g.n;
	  zx_FREE_sa_BaseID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      for (e = x->NameID; e; e = en) {
	  en = (struct zx_sa_NameID_s*)e->gg.g.n;
	  zx_FREE_sa_NameID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      for (e = x->EncryptedID; e; e = en) {
	  en = (struct zx_sa_EncryptedID_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SessionIndex, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_LogoutRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_LogoutRequest_s* zx_NEW_sp_LogoutRequest(struct zx_ctx* c)
{
  struct zx_sp_LogoutRequest_s* x = ZX_ZALLOC(c, struct zx_sp_LogoutRequest_s);
  x->gg.g.tok = zx_sp_LogoutRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_LogoutRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_LogoutRequest(struct zx_ctx* c, struct zx_sp_LogoutRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->NotOnOrAfter);
  zx_dup_attr(c, x->Reason);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_BaseID_s* e;
      for (e = x->BaseID; e; e = (struct zx_sa_BaseID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_BaseID(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_NameID(c, e);
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SessionIndex);

}

/* FUNC(zx_DEEP_CLONE_sp_LogoutRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_LogoutRequest_s* zx_DEEP_CLONE_sp_LogoutRequest(struct zx_ctx* c, struct zx_sp_LogoutRequest_s* x, int dup_strs)
{
  x = (struct zx_sp_LogoutRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_LogoutRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->NotOnOrAfter = zx_clone_attr(c, x->NotOnOrAfter);
  x->Reason = zx_clone_attr(c, x->Reason);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_BaseID_s* e;
      struct zx_sa_BaseID_s* en;
      struct zx_sa_BaseID_s* enn;
      for (enn = 0, e = x->BaseID; e; e = (struct zx_sa_BaseID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_BaseID(c, e, dup_strs);
	  if (!enn)
	      x->BaseID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      struct zx_sa_EncryptedID_s* enn;
      for (enn = 0, e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SessionIndex = zx_deep_clone_simple_elems(c,x->SessionIndex, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_LogoutRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_LogoutRequest(struct zx_ctx* c, struct zx_sp_LogoutRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_BaseID_s* e;
      for (e = x->BaseID; e; e = (struct zx_sa_BaseID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_BaseID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_NameID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SessionIndex, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_LogoutRequest) */

int zx_WALK_WO_sp_LogoutRequest(struct zx_ctx* c, struct zx_sp_LogoutRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_LogoutResponse
#define EL_STRUCT zx_sp_LogoutResponse_s
#define EL_NS     sp
#define EL_TAG    LogoutResponse

/* FUNC(zx_FREE_sp_LogoutResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_LogoutResponse(struct zx_ctx* c, struct zx_sp_LogoutResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp_Status_s*)e->gg.g.n;
	  zx_FREE_sp_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_LogoutResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_LogoutResponse_s* zx_NEW_sp_LogoutResponse(struct zx_ctx* c)
{
  struct zx_sp_LogoutResponse_s* x = ZX_ZALLOC(c, struct zx_sp_LogoutResponse_s);
  x->gg.g.tok = zx_sp_LogoutResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_LogoutResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_LogoutResponse(struct zx_ctx* c, struct zx_sp_LogoutResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_LogoutResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_LogoutResponse_s* zx_DEEP_CLONE_sp_LogoutResponse(struct zx_ctx* c, struct zx_sp_LogoutResponse_s* x, int dup_strs)
{
  x = (struct zx_sp_LogoutResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_LogoutResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      struct zx_sp_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_LogoutResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_LogoutResponse(struct zx_ctx* c, struct zx_sp_LogoutResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_LogoutResponse) */

int zx_WALK_WO_sp_LogoutResponse(struct zx_ctx* c, struct zx_sp_LogoutResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_ManageNameIDRequest
#define EL_STRUCT zx_sp_ManageNameIDRequest_s
#define EL_NS     sp
#define EL_TAG    ManageNameIDRequest

/* FUNC(zx_FREE_sp_ManageNameIDRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_ManageNameIDRequest(struct zx_ctx* c, struct zx_sp_ManageNameIDRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      for (e = x->NameID; e; e = en) {
	  en = (struct zx_sa_NameID_s*)e->gg.g.n;
	  zx_FREE_sa_NameID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      for (e = x->EncryptedID; e; e = en) {
	  en = (struct zx_sa_EncryptedID_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NewID, free_strs);
  {
      struct zx_sp_NewEncryptedID_s* e;
      struct zx_sp_NewEncryptedID_s* en;
      for (e = x->NewEncryptedID; e; e = en) {
	  en = (struct zx_sp_NewEncryptedID_s*)e->gg.g.n;
	  zx_FREE_sp_NewEncryptedID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Terminate, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_ManageNameIDRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_ManageNameIDRequest_s* zx_NEW_sp_ManageNameIDRequest(struct zx_ctx* c)
{
  struct zx_sp_ManageNameIDRequest_s* x = ZX_ZALLOC(c, struct zx_sp_ManageNameIDRequest_s);
  x->gg.g.tok = zx_sp_ManageNameIDRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_ManageNameIDRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_ManageNameIDRequest(struct zx_ctx* c, struct zx_sp_ManageNameIDRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_NameID(c, e);
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NewID);
  {
      struct zx_sp_NewEncryptedID_s* e;
      for (e = x->NewEncryptedID; e; e = (struct zx_sp_NewEncryptedID_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_NewEncryptedID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Terminate);

}

/* FUNC(zx_DEEP_CLONE_sp_ManageNameIDRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_ManageNameIDRequest_s* zx_DEEP_CLONE_sp_ManageNameIDRequest(struct zx_ctx* c, struct zx_sp_ManageNameIDRequest_s* x, int dup_strs)
{
  x = (struct zx_sp_ManageNameIDRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_ManageNameIDRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      struct zx_sa_EncryptedID_s* enn;
      for (enn = 0, e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NewID = zx_deep_clone_simple_elems(c,x->NewID, dup_strs);
  {
      struct zx_sp_NewEncryptedID_s* e;
      struct zx_sp_NewEncryptedID_s* en;
      struct zx_sp_NewEncryptedID_s* enn;
      for (enn = 0, e = x->NewEncryptedID; e; e = (struct zx_sp_NewEncryptedID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_NewEncryptedID(c, e, dup_strs);
	  if (!enn)
	      x->NewEncryptedID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Terminate = zx_deep_clone_simple_elems(c,x->Terminate, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_ManageNameIDRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_ManageNameIDRequest(struct zx_ctx* c, struct zx_sp_ManageNameIDRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_NameID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NewID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp_NewEncryptedID_s* e;
      for (e = x->NewEncryptedID; e; e = (struct zx_sp_NewEncryptedID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_NewEncryptedID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Terminate, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_ManageNameIDRequest) */

int zx_WALK_WO_sp_ManageNameIDRequest(struct zx_ctx* c, struct zx_sp_ManageNameIDRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_ManageNameIDResponse
#define EL_STRUCT zx_sp_ManageNameIDResponse_s
#define EL_NS     sp
#define EL_TAG    ManageNameIDResponse

/* FUNC(zx_FREE_sp_ManageNameIDResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_ManageNameIDResponse(struct zx_ctx* c, struct zx_sp_ManageNameIDResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp_Status_s*)e->gg.g.n;
	  zx_FREE_sp_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_ManageNameIDResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_ManageNameIDResponse_s* zx_NEW_sp_ManageNameIDResponse(struct zx_ctx* c)
{
  struct zx_sp_ManageNameIDResponse_s* x = ZX_ZALLOC(c, struct zx_sp_ManageNameIDResponse_s);
  x->gg.g.tok = zx_sp_ManageNameIDResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_ManageNameIDResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_ManageNameIDResponse(struct zx_ctx* c, struct zx_sp_ManageNameIDResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_ManageNameIDResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_ManageNameIDResponse_s* zx_DEEP_CLONE_sp_ManageNameIDResponse(struct zx_ctx* c, struct zx_sp_ManageNameIDResponse_s* x, int dup_strs)
{
  x = (struct zx_sp_ManageNameIDResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_ManageNameIDResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      struct zx_sp_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_ManageNameIDResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_ManageNameIDResponse(struct zx_ctx* c, struct zx_sp_ManageNameIDResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_ManageNameIDResponse) */

int zx_WALK_WO_sp_ManageNameIDResponse(struct zx_ctx* c, struct zx_sp_ManageNameIDResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_NameIDMappingRequest
#define EL_STRUCT zx_sp_NameIDMappingRequest_s
#define EL_NS     sp
#define EL_TAG    NameIDMappingRequest

/* FUNC(zx_FREE_sp_NameIDMappingRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_NameIDMappingRequest(struct zx_ctx* c, struct zx_sp_NameIDMappingRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sa_BaseID_s* e;
      struct zx_sa_BaseID_s* en;
      for (e = x->BaseID; e; e = en) {
	  en = (struct zx_sa_BaseID_s*)e->gg.g.n;
	  zx_FREE_sa_BaseID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      for (e = x->NameID; e; e = en) {
	  en = (struct zx_sa_NameID_s*)e->gg.g.n;
	  zx_FREE_sa_NameID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      for (e = x->EncryptedID; e; e = en) {
	  en = (struct zx_sa_EncryptedID_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedID(c, e, free_strs);
      }
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      struct zx_sp_NameIDPolicy_s* en;
      for (e = x->NameIDPolicy; e; e = en) {
	  en = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n;
	  zx_FREE_sp_NameIDPolicy(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_NameIDMappingRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_NameIDMappingRequest_s* zx_NEW_sp_NameIDMappingRequest(struct zx_ctx* c)
{
  struct zx_sp_NameIDMappingRequest_s* x = ZX_ZALLOC(c, struct zx_sp_NameIDMappingRequest_s);
  x->gg.g.tok = zx_sp_NameIDMappingRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_NameIDMappingRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_NameIDMappingRequest(struct zx_ctx* c, struct zx_sp_NameIDMappingRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_BaseID_s* e;
      for (e = x->BaseID; e; e = (struct zx_sa_BaseID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_BaseID(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_NameID(c, e);
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedID(c, e);
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      for (e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_NameIDPolicy(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_NameIDMappingRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_NameIDMappingRequest_s* zx_DEEP_CLONE_sp_NameIDMappingRequest(struct zx_ctx* c, struct zx_sp_NameIDMappingRequest_s* x, int dup_strs)
{
  x = (struct zx_sp_NameIDMappingRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_NameIDMappingRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_BaseID_s* e;
      struct zx_sa_BaseID_s* en;
      struct zx_sa_BaseID_s* enn;
      for (enn = 0, e = x->BaseID; e; e = (struct zx_sa_BaseID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_BaseID(c, e, dup_strs);
	  if (!enn)
	      x->BaseID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      struct zx_sa_EncryptedID_s* enn;
      for (enn = 0, e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      struct zx_sp_NameIDPolicy_s* en;
      struct zx_sp_NameIDPolicy_s* enn;
      for (enn = 0, e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_NameIDPolicy(c, e, dup_strs);
	  if (!enn)
	      x->NameIDPolicy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_NameIDMappingRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_NameIDMappingRequest(struct zx_ctx* c, struct zx_sp_NameIDMappingRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_BaseID_s* e;
      for (e = x->BaseID; e; e = (struct zx_sa_BaseID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_BaseID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_NameID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_NameIDPolicy_s* e;
      for (e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_NameIDPolicy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_NameIDMappingRequest) */

int zx_WALK_WO_sp_NameIDMappingRequest(struct zx_ctx* c, struct zx_sp_NameIDMappingRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_NameIDMappingResponse
#define EL_STRUCT zx_sp_NameIDMappingResponse_s
#define EL_NS     sp
#define EL_TAG    NameIDMappingResponse

/* FUNC(zx_FREE_sp_NameIDMappingResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_NameIDMappingResponse(struct zx_ctx* c, struct zx_sp_NameIDMappingResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp_Status_s*)e->gg.g.n;
	  zx_FREE_sp_Status(c, e, free_strs);
      }
  }
  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      for (e = x->NameID; e; e = en) {
	  en = (struct zx_sa_NameID_s*)e->gg.g.n;
	  zx_FREE_sa_NameID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      for (e = x->EncryptedID; e; e = en) {
	  en = (struct zx_sa_EncryptedID_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedID(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_NameIDMappingResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_NameIDMappingResponse_s* zx_NEW_sp_NameIDMappingResponse(struct zx_ctx* c)
{
  struct zx_sp_NameIDMappingResponse_s* x = ZX_ZALLOC(c, struct zx_sp_NameIDMappingResponse_s);
  x->gg.g.tok = zx_sp_NameIDMappingResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_NameIDMappingResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_NameIDMappingResponse(struct zx_ctx* c, struct zx_sp_NameIDMappingResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Status(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_NameID(c, e);
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedID(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_NameIDMappingResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_NameIDMappingResponse_s* zx_DEEP_CLONE_sp_NameIDMappingResponse(struct zx_ctx* c, struct zx_sp_NameIDMappingResponse_s* x, int dup_strs)
{
  x = (struct zx_sp_NameIDMappingResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_NameIDMappingResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      struct zx_sp_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
      struct zx_sa_EncryptedID_s* e;
      struct zx_sa_EncryptedID_s* en;
      struct zx_sa_EncryptedID_s* enn;
      for (enn = 0, e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_NameIDMappingResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_NameIDMappingResponse(struct zx_ctx* c, struct zx_sp_NameIDMappingResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_NameID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_EncryptedID_s* e;
      for (e = x->EncryptedID; e; e = (struct zx_sa_EncryptedID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_NameIDMappingResponse) */

int zx_WALK_WO_sp_NameIDMappingResponse(struct zx_ctx* c, struct zx_sp_NameIDMappingResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_NameIDPolicy
#define EL_STRUCT zx_sp_NameIDPolicy_s
#define EL_NS     sp
#define EL_TAG    NameIDPolicy

/* FUNC(zx_FREE_sp_NameIDPolicy) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_NameIDPolicy(struct zx_ctx* c, struct zx_sp_NameIDPolicy_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AllowCreate, free_strs);
  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->SPNameQualifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_NameIDPolicy) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_NameIDPolicy_s* zx_NEW_sp_NameIDPolicy(struct zx_ctx* c)
{
  struct zx_sp_NameIDPolicy_s* x = ZX_ZALLOC(c, struct zx_sp_NameIDPolicy_s);
  x->gg.g.tok = zx_sp_NameIDPolicy_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_NameIDPolicy) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_NameIDPolicy(struct zx_ctx* c, struct zx_sp_NameIDPolicy_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AllowCreate);
  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->SPNameQualifier);


}

/* FUNC(zx_DEEP_CLONE_sp_NameIDPolicy) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_NameIDPolicy_s* zx_DEEP_CLONE_sp_NameIDPolicy(struct zx_ctx* c, struct zx_sp_NameIDPolicy_s* x, int dup_strs)
{
  x = (struct zx_sp_NameIDPolicy_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_NameIDPolicy_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AllowCreate = zx_clone_attr(c, x->AllowCreate);
  x->Format = zx_clone_attr(c, x->Format);
  x->SPNameQualifier = zx_clone_attr(c, x->SPNameQualifier);


  return x;
}

/* FUNC(zx_WALK_SO_sp_NameIDPolicy) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_NameIDPolicy(struct zx_ctx* c, struct zx_sp_NameIDPolicy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sp_NameIDPolicy) */

int zx_WALK_WO_sp_NameIDPolicy(struct zx_ctx* c, struct zx_sp_NameIDPolicy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_NewEncryptedID
#define EL_STRUCT zx_sp_NewEncryptedID_s
#define EL_NS     sp
#define EL_TAG    NewEncryptedID

/* FUNC(zx_FREE_sp_NewEncryptedID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_NewEncryptedID(struct zx_ctx* c, struct zx_sp_NewEncryptedID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xenc_EncryptedData_s* e;
      struct zx_xenc_EncryptedData_s* en;
      for (e = x->EncryptedData; e; e = en) {
	  en = (struct zx_xenc_EncryptedData_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptedData(c, e, free_strs);
      }
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      struct zx_xenc_EncryptedKey_s* en;
      for (e = x->EncryptedKey; e; e = en) {
	  en = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptedKey(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_NewEncryptedID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_NewEncryptedID_s* zx_NEW_sp_NewEncryptedID(struct zx_ctx* c)
{
  struct zx_sp_NewEncryptedID_s* x = ZX_ZALLOC(c, struct zx_sp_NewEncryptedID_s);
  x->gg.g.tok = zx_sp_NewEncryptedID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_NewEncryptedID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_NewEncryptedID(struct zx_ctx* c, struct zx_sp_NewEncryptedID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptedData(c, e);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptedKey(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_NewEncryptedID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_NewEncryptedID_s* zx_DEEP_CLONE_sp_NewEncryptedID(struct zx_ctx* c, struct zx_sp_NewEncryptedID_s* x, int dup_strs)
{
  x = (struct zx_sp_NewEncryptedID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_NewEncryptedID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xenc_EncryptedData_s* e;
      struct zx_xenc_EncryptedData_s* en;
      struct zx_xenc_EncryptedData_s* enn;
      for (enn = 0, e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptedData(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      struct zx_xenc_EncryptedKey_s* en;
      struct zx_xenc_EncryptedKey_s* enn;
      for (enn = 0, e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptedKey(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedKey = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_NewEncryptedID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_NewEncryptedID(struct zx_ctx* c, struct zx_sp_NewEncryptedID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptedData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptedKey(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_NewEncryptedID) */

int zx_WALK_WO_sp_NewEncryptedID(struct zx_ctx* c, struct zx_sp_NewEncryptedID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_RequestedAuthnContext
#define EL_STRUCT zx_sp_RequestedAuthnContext_s
#define EL_NS     sp
#define EL_TAG    RequestedAuthnContext

/* FUNC(zx_FREE_sp_RequestedAuthnContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_RequestedAuthnContext(struct zx_ctx* c, struct zx_sp_RequestedAuthnContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Comparison, free_strs);

  zx_free_simple_elems(c, x->AuthnContextClassRef, free_strs);
  zx_free_simple_elems(c, x->AuthnContextDeclRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_RequestedAuthnContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_RequestedAuthnContext_s* zx_NEW_sp_RequestedAuthnContext(struct zx_ctx* c)
{
  struct zx_sp_RequestedAuthnContext_s* x = ZX_ZALLOC(c, struct zx_sp_RequestedAuthnContext_s);
  x->gg.g.tok = zx_sp_RequestedAuthnContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_RequestedAuthnContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_RequestedAuthnContext(struct zx_ctx* c, struct zx_sp_RequestedAuthnContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Comparison);

  zx_dup_strs_simple_elems(c, x->AuthnContextClassRef);
  zx_dup_strs_simple_elems(c, x->AuthnContextDeclRef);

}

/* FUNC(zx_DEEP_CLONE_sp_RequestedAuthnContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_RequestedAuthnContext_s* zx_DEEP_CLONE_sp_RequestedAuthnContext(struct zx_ctx* c, struct zx_sp_RequestedAuthnContext_s* x, int dup_strs)
{
  x = (struct zx_sp_RequestedAuthnContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_RequestedAuthnContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Comparison = zx_clone_attr(c, x->Comparison);

  x->AuthnContextClassRef = zx_deep_clone_simple_elems(c,x->AuthnContextClassRef, dup_strs);
  x->AuthnContextDeclRef = zx_deep_clone_simple_elems(c,x->AuthnContextDeclRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_RequestedAuthnContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_RequestedAuthnContext(struct zx_ctx* c, struct zx_sp_RequestedAuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AuthnContextClassRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuthnContextDeclRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_RequestedAuthnContext) */

int zx_WALK_WO_sp_RequestedAuthnContext(struct zx_ctx* c, struct zx_sp_RequestedAuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_Response
#define EL_STRUCT zx_sp_Response_s
#define EL_NS     sp
#define EL_TAG    Response

/* FUNC(zx_FREE_sp_Response) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_Response(struct zx_ctx* c, struct zx_sp_Response_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp_Status_s*)e->gg.g.n;
	  zx_FREE_sp_Status(c, e, free_strs);
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
  {
      struct zx_sa_EncryptedAssertion_s* e;
      struct zx_sa_EncryptedAssertion_s* en;
      for (e = x->EncryptedAssertion; e; e = en) {
	  en = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedAssertion(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_Response) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_Response_s* zx_NEW_sp_Response(struct zx_ctx* c)
{
  struct zx_sp_Response_s* x = ZX_ZALLOC(c, struct zx_sp_Response_s);
  x->gg.g.tok = zx_sp_Response_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_Response) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_Response(struct zx_ctx* c, struct zx_sp_Response_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Status(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Assertion(c, e);
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedAssertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_Response) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_Response_s* zx_DEEP_CLONE_sp_Response(struct zx_ctx* c, struct zx_sp_Response_s* x, int dup_strs)
{
  x = (struct zx_sp_Response_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_Response_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Status_s* e;
      struct zx_sp_Status_s* en;
      struct zx_sp_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
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
  {
      struct zx_sa_EncryptedAssertion_s* e;
      struct zx_sa_EncryptedAssertion_s* en;
      struct zx_sa_EncryptedAssertion_s* enn;
      for (enn = 0, e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedAssertion(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedAssertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_Response) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_Response(struct zx_ctx* c, struct zx_sp_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Status(c, e, ctx, callback);
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
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedAssertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_Response) */

int zx_WALK_WO_sp_Response(struct zx_ctx* c, struct zx_sp_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_Scoping
#define EL_STRUCT zx_sp_Scoping_s
#define EL_NS     sp
#define EL_TAG    Scoping

/* FUNC(zx_FREE_sp_Scoping) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_Scoping(struct zx_ctx* c, struct zx_sp_Scoping_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ProxyCount, free_strs);

  {
      struct zx_sp_IDPList_s* e;
      struct zx_sp_IDPList_s* en;
      for (e = x->IDPList; e; e = en) {
	  en = (struct zx_sp_IDPList_s*)e->gg.g.n;
	  zx_FREE_sp_IDPList(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->RequesterID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_Scoping) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_Scoping_s* zx_NEW_sp_Scoping(struct zx_ctx* c)
{
  struct zx_sp_Scoping_s* x = ZX_ZALLOC(c, struct zx_sp_Scoping_s);
  x->gg.g.tok = zx_sp_Scoping_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_Scoping) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_Scoping(struct zx_ctx* c, struct zx_sp_Scoping_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ProxyCount);

  {
      struct zx_sp_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_sp_IDPList_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_IDPList(c, e);
  }
  zx_dup_strs_simple_elems(c, x->RequesterID);

}

/* FUNC(zx_DEEP_CLONE_sp_Scoping) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_Scoping_s* zx_DEEP_CLONE_sp_Scoping(struct zx_ctx* c, struct zx_sp_Scoping_s* x, int dup_strs)
{
  x = (struct zx_sp_Scoping_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_Scoping_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ProxyCount = zx_clone_attr(c, x->ProxyCount);

  {
      struct zx_sp_IDPList_s* e;
      struct zx_sp_IDPList_s* en;
      struct zx_sp_IDPList_s* enn;
      for (enn = 0, e = x->IDPList; e; e = (struct zx_sp_IDPList_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_IDPList(c, e, dup_strs);
	  if (!enn)
	      x->IDPList = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->RequesterID = zx_deep_clone_simple_elems(c,x->RequesterID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp_Scoping) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_Scoping(struct zx_ctx* c, struct zx_sp_Scoping_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_sp_IDPList_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_IDPList(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->RequesterID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_Scoping) */

int zx_WALK_WO_sp_Scoping(struct zx_ctx* c, struct zx_sp_Scoping_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_Status
#define EL_STRUCT zx_sp_Status_s
#define EL_NS     sp
#define EL_TAG    Status

/* FUNC(zx_FREE_sp_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_Status(struct zx_ctx* c, struct zx_sp_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp_StatusCode_s* e;
      struct zx_sp_StatusCode_s* en;
      for (e = x->StatusCode; e; e = en) {
	  en = (struct zx_sp_StatusCode_s*)e->gg.g.n;
	  zx_FREE_sp_StatusCode(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->StatusMessage, free_strs);
  {
      struct zx_sp_StatusDetail_s* e;
      struct zx_sp_StatusDetail_s* en;
      for (e = x->StatusDetail; e; e = en) {
	  en = (struct zx_sp_StatusDetail_s*)e->gg.g.n;
	  zx_FREE_sp_StatusDetail(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_Status_s* zx_NEW_sp_Status(struct zx_ctx* c)
{
  struct zx_sp_Status_s* x = ZX_ZALLOC(c, struct zx_sp_Status_s);
  x->gg.g.tok = zx_sp_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_Status(struct zx_ctx* c, struct zx_sp_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp_StatusCode_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_StatusCode(c, e);
  }
  zx_dup_strs_simple_elems(c, x->StatusMessage);
  {
      struct zx_sp_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp_StatusDetail_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_StatusDetail(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_Status_s* zx_DEEP_CLONE_sp_Status(struct zx_ctx* c, struct zx_sp_Status_s* x, int dup_strs)
{
  x = (struct zx_sp_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp_StatusCode_s* e;
      struct zx_sp_StatusCode_s* en;
      struct zx_sp_StatusCode_s* enn;
      for (enn = 0, e = x->StatusCode; e; e = (struct zx_sp_StatusCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_StatusCode(c, e, dup_strs);
	  if (!enn)
	      x->StatusCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->StatusMessage = zx_deep_clone_simple_elems(c,x->StatusMessage, dup_strs);
  {
      struct zx_sp_StatusDetail_s* e;
      struct zx_sp_StatusDetail_s* en;
      struct zx_sp_StatusDetail_s* enn;
      for (enn = 0, e = x->StatusDetail; e; e = (struct zx_sp_StatusDetail_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_StatusDetail(c, e, dup_strs);
	  if (!enn)
	      x->StatusDetail = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_Status(struct zx_ctx* c, struct zx_sp_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp_StatusCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_StatusCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->StatusMessage, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp_StatusDetail_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_StatusDetail(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_Status) */

int zx_WALK_WO_sp_Status(struct zx_ctx* c, struct zx_sp_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_StatusCode
#define EL_STRUCT zx_sp_StatusCode_s
#define EL_NS     sp
#define EL_TAG    StatusCode

/* FUNC(zx_FREE_sp_StatusCode) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_StatusCode(struct zx_ctx* c, struct zx_sp_StatusCode_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Value, free_strs);

  {
      struct zx_sp_StatusCode_s* e;
      struct zx_sp_StatusCode_s* en;
      for (e = x->StatusCode; e; e = en) {
	  en = (struct zx_sp_StatusCode_s*)e->gg.g.n;
	  zx_FREE_sp_StatusCode(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_StatusCode) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_StatusCode_s* zx_NEW_sp_StatusCode(struct zx_ctx* c)
{
  struct zx_sp_StatusCode_s* x = ZX_ZALLOC(c, struct zx_sp_StatusCode_s);
  x->gg.g.tok = zx_sp_StatusCode_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_StatusCode) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_StatusCode(struct zx_ctx* c, struct zx_sp_StatusCode_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Value);

  {
      struct zx_sp_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp_StatusCode_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_StatusCode(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_StatusCode) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_StatusCode_s* zx_DEEP_CLONE_sp_StatusCode(struct zx_ctx* c, struct zx_sp_StatusCode_s* x, int dup_strs)
{
  x = (struct zx_sp_StatusCode_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_StatusCode_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Value = zx_clone_attr(c, x->Value);

  {
      struct zx_sp_StatusCode_s* e;
      struct zx_sp_StatusCode_s* en;
      struct zx_sp_StatusCode_s* enn;
      for (enn = 0, e = x->StatusCode; e; e = (struct zx_sp_StatusCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_StatusCode(c, e, dup_strs);
	  if (!enn)
	      x->StatusCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp_StatusCode) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_StatusCode(struct zx_ctx* c, struct zx_sp_StatusCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp_StatusCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_StatusCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp_StatusCode) */

int zx_WALK_WO_sp_StatusCode(struct zx_ctx* c, struct zx_sp_StatusCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_StatusDetail
#define EL_STRUCT zx_sp_StatusDetail_s
#define EL_NS     sp
#define EL_TAG    StatusDetail

/* FUNC(zx_FREE_sp_StatusDetail) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_StatusDetail(struct zx_ctx* c, struct zx_sp_StatusDetail_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp_StatusDetail) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_StatusDetail_s* zx_NEW_sp_StatusDetail(struct zx_ctx* c)
{
  struct zx_sp_StatusDetail_s* x = ZX_ZALLOC(c, struct zx_sp_StatusDetail_s);
  x->gg.g.tok = zx_sp_StatusDetail_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_StatusDetail) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_StatusDetail(struct zx_ctx* c, struct zx_sp_StatusDetail_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_sp_StatusDetail) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_StatusDetail_s* zx_DEEP_CLONE_sp_StatusDetail(struct zx_ctx* c, struct zx_sp_StatusDetail_s* x, int dup_strs)
{
  x = (struct zx_sp_StatusDetail_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_StatusDetail_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_sp_StatusDetail) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_StatusDetail(struct zx_ctx* c, struct zx_sp_StatusDetail_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sp_StatusDetail) */

int zx_WALK_WO_sp_StatusDetail(struct zx_ctx* c, struct zx_sp_StatusDetail_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp_SubjectQuery
#define EL_STRUCT zx_sp_SubjectQuery_s
#define EL_NS     sp
#define EL_TAG    SubjectQuery

/* FUNC(zx_FREE_sp_SubjectQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp_SubjectQuery(struct zx_ctx* c, struct zx_sp_SubjectQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Consent, free_strs);
  zx_free_attr(c, x->Destination, free_strs);
  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_sa_Issuer_s*)e->gg.g.n;
	  zx_FREE_sa_Issuer(c, e, free_strs);
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      for (e = x->Extensions; e; e = en) {
	  en = (struct zx_sp_Extensions_s*)e->gg.g.n;
	  zx_FREE_sp_Extensions(c, e, free_strs);
      }
  }
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

/* FUNC(zx_NEW_sp_SubjectQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp_SubjectQuery_s* zx_NEW_sp_SubjectQuery(struct zx_ctx* c)
{
  struct zx_sp_SubjectQuery_s* x = ZX_ZALLOC(c, struct zx_sp_SubjectQuery_s);
  x->gg.g.tok = zx_sp_SubjectQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp_SubjectQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp_SubjectQuery(struct zx_ctx* c, struct zx_sp_SubjectQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Consent);
  zx_dup_attr(c, x->Destination);
  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Issuer(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Extensions(c, e);
  }
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp_SubjectQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp_SubjectQuery_s* zx_DEEP_CLONE_sp_SubjectQuery(struct zx_ctx* c, struct zx_sp_SubjectQuery_s* x, int dup_strs)
{
  x = (struct zx_sp_SubjectQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp_SubjectQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Consent = zx_clone_attr(c, x->Consent);
  x->Destination = zx_clone_attr(c, x->Destination);
  x->ID = zx_clone_attr(c, x->ID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Version = zx_clone_attr(c, x->Version);

  {
      struct zx_sa_Issuer_s* e;
      struct zx_sa_Issuer_s* en;
      struct zx_sa_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
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
      struct zx_sp_Extensions_s* e;
      struct zx_sp_Extensions_s* en;
      struct zx_sp_Extensions_s* enn;
      for (enn = 0, e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Extensions(c, e, dup_strs);
	  if (!enn)
	      x->Extensions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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

/* FUNC(zx_WALK_SO_sp_SubjectQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp_SubjectQuery(struct zx_ctx* c, struct zx_sp_SubjectQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_sa_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Issuer(c, e, ctx, callback);
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
      struct zx_sp_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_sp_Extensions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Extensions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
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

/* FUNC(zx_WALK_WO_sp_SubjectQuery) */

int zx_WALK_WO_sp_SubjectQuery(struct zx_ctx* c, struct zx_sp_SubjectQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sp-aux.c */
