/* c/zx-b-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-b-data.h"



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

#define EL_NAME   b_ApplicationEPR
#define EL_STRUCT zx_b_ApplicationEPR_s
#define EL_NS     b
#define EL_TAG    ApplicationEPR

/* FUNC(zx_FREE_b_ApplicationEPR) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_ApplicationEPR(struct zx_ctx* c, struct zx_b_ApplicationEPR_s* x, int free_strs)
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

/* FUNC(zx_NEW_b_ApplicationEPR) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_ApplicationEPR_s* zx_NEW_b_ApplicationEPR(struct zx_ctx* c)
{
  struct zx_b_ApplicationEPR_s* x = ZX_ZALLOC(c, struct zx_b_ApplicationEPR_s);
  x->gg.g.tok = zx_b_ApplicationEPR_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_ApplicationEPR) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_ApplicationEPR(struct zx_ctx* c, struct zx_b_ApplicationEPR_s* x)
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

/* FUNC(zx_DEEP_CLONE_b_ApplicationEPR) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_ApplicationEPR_s* zx_DEEP_CLONE_b_ApplicationEPR(struct zx_ctx* c, struct zx_b_ApplicationEPR_s* x, int dup_strs)
{
  x = (struct zx_b_ApplicationEPR_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_ApplicationEPR_s), dup_strs);
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

/* FUNC(zx_WALK_SO_b_ApplicationEPR) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_ApplicationEPR(struct zx_ctx* c, struct zx_b_ApplicationEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_ApplicationEPR) */

int zx_WALK_WO_b_ApplicationEPR(struct zx_ctx* c, struct zx_b_ApplicationEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_Consent
#define EL_STRUCT zx_b_Consent_s
#define EL_NS     b
#define EL_TAG    Consent

/* FUNC(zx_FREE_b_Consent) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_Consent(struct zx_ctx* c, struct zx_b_Consent_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->timestamp, free_strs);
  zx_free_attr(c, x->uri, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_Consent) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_Consent_s* zx_NEW_b_Consent(struct zx_ctx* c)
{
  struct zx_b_Consent_s* x = ZX_ZALLOC(c, struct zx_b_Consent_s);
  x->gg.g.tok = zx_b_Consent_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_Consent) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_Consent(struct zx_ctx* c, struct zx_b_Consent_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->timestamp);
  zx_dup_attr(c, x->uri);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b_Consent) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_Consent_s* zx_DEEP_CLONE_b_Consent(struct zx_ctx* c, struct zx_b_Consent_s* x, int dup_strs)
{
  x = (struct zx_b_Consent_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_Consent_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->timestamp = zx_clone_attr(c, x->timestamp);
  x->uri = zx_clone_attr(c, x->uri);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b_Consent) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_Consent(struct zx_ctx* c, struct zx_b_Consent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_Consent) */

int zx_WALK_WO_b_Consent(struct zx_ctx* c, struct zx_b_Consent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_CredentialsContext
#define EL_STRUCT zx_b_CredentialsContext_s
#define EL_NS     b
#define EL_TAG    CredentialsContext

/* FUNC(zx_FREE_b_CredentialsContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_CredentialsContext(struct zx_ctx* c, struct zx_b_CredentialsContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_sp_RequestedAuthnContext_s* e;
      struct zx_sp_RequestedAuthnContext_s* en;
      for (e = x->RequestedAuthnContext; e; e = en) {
	  en = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n;
	  zx_FREE_sp_RequestedAuthnContext(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SecurityMechID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_CredentialsContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_CredentialsContext_s* zx_NEW_b_CredentialsContext(struct zx_ctx* c)
{
  struct zx_b_CredentialsContext_s* x = ZX_ZALLOC(c, struct zx_b_CredentialsContext_s);
  x->gg.g.tok = zx_b_CredentialsContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_CredentialsContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_CredentialsContext(struct zx_ctx* c, struct zx_b_CredentialsContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_sp_RequestedAuthnContext_s* e;
      for (e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_RequestedAuthnContext(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SecurityMechID);

}

/* FUNC(zx_DEEP_CLONE_b_CredentialsContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_CredentialsContext_s* zx_DEEP_CLONE_b_CredentialsContext(struct zx_ctx* c, struct zx_b_CredentialsContext_s* x, int dup_strs)
{
  x = (struct zx_b_CredentialsContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_CredentialsContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

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
  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_b_CredentialsContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_CredentialsContext(struct zx_ctx* c, struct zx_b_CredentialsContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_RequestedAuthnContext_s* e;
      for (e = x->RequestedAuthnContext; e; e = (struct zx_sp_RequestedAuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_RequestedAuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SecurityMechID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_b_CredentialsContext) */

int zx_WALK_WO_b_CredentialsContext(struct zx_ctx* c, struct zx_b_CredentialsContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_EndpointUpdate
#define EL_STRUCT zx_b_EndpointUpdate_s
#define EL_NS     b
#define EL_TAG    EndpointUpdate

/* FUNC(zx_FREE_b_EndpointUpdate) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_EndpointUpdate(struct zx_ctx* c, struct zx_b_EndpointUpdate_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->notOnOrAfter, free_strs);
  zx_free_attr(c, x->updateType, free_strs);
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

/* FUNC(zx_NEW_b_EndpointUpdate) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_EndpointUpdate_s* zx_NEW_b_EndpointUpdate(struct zx_ctx* c)
{
  struct zx_b_EndpointUpdate_s* x = ZX_ZALLOC(c, struct zx_b_EndpointUpdate_s);
  x->gg.g.tok = zx_b_EndpointUpdate_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_EndpointUpdate) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_EndpointUpdate(struct zx_ctx* c, struct zx_b_EndpointUpdate_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->notOnOrAfter);
  zx_dup_attr(c, x->updateType);
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

/* FUNC(zx_DEEP_CLONE_b_EndpointUpdate) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_EndpointUpdate_s* zx_DEEP_CLONE_b_EndpointUpdate(struct zx_ctx* c, struct zx_b_EndpointUpdate_s* x, int dup_strs)
{
  x = (struct zx_b_EndpointUpdate_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_EndpointUpdate_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->id = zx_clone_attr(c, x->id);
  x->notOnOrAfter = zx_clone_attr(c, x->notOnOrAfter);
  x->updateType = zx_clone_attr(c, x->updateType);
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

/* FUNC(zx_WALK_SO_b_EndpointUpdate) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_EndpointUpdate(struct zx_ctx* c, struct zx_b_EndpointUpdate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_EndpointUpdate) */

int zx_WALK_WO_b_EndpointUpdate(struct zx_ctx* c, struct zx_b_EndpointUpdate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_Framework
#define EL_STRUCT zx_b_Framework_s
#define EL_NS     b
#define EL_TAG    Framework

/* FUNC(zx_FREE_b_Framework) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_Framework(struct zx_ctx* c, struct zx_b_Framework_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->version, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_Framework) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_Framework_s* zx_NEW_b_Framework(struct zx_ctx* c)
{
  struct zx_b_Framework_s* x = ZX_ZALLOC(c, struct zx_b_Framework_s);
  x->gg.g.tok = zx_b_Framework_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_Framework) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_Framework(struct zx_ctx* c, struct zx_b_Framework_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->version);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b_Framework) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_Framework_s* zx_DEEP_CLONE_b_Framework(struct zx_ctx* c, struct zx_b_Framework_s* x, int dup_strs)
{
  x = (struct zx_b_Framework_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_Framework_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->version = zx_clone_attr(c, x->version);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b_Framework) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_Framework(struct zx_ctx* c, struct zx_b_Framework_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_Framework) */

int zx_WALK_WO_b_Framework(struct zx_ctx* c, struct zx_b_Framework_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_InteractionService
#define EL_STRUCT zx_b_InteractionService_s
#define EL_NS     b
#define EL_TAG    InteractionService

/* FUNC(zx_FREE_b_InteractionService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_InteractionService(struct zx_ctx* c, struct zx_b_InteractionService_s* x, int free_strs)
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

/* FUNC(zx_NEW_b_InteractionService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_InteractionService_s* zx_NEW_b_InteractionService(struct zx_ctx* c)
{
  struct zx_b_InteractionService_s* x = ZX_ZALLOC(c, struct zx_b_InteractionService_s);
  x->gg.g.tok = zx_b_InteractionService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_InteractionService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_InteractionService(struct zx_ctx* c, struct zx_b_InteractionService_s* x)
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

/* FUNC(zx_DEEP_CLONE_b_InteractionService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_InteractionService_s* zx_DEEP_CLONE_b_InteractionService(struct zx_ctx* c, struct zx_b_InteractionService_s* x, int dup_strs)
{
  x = (struct zx_b_InteractionService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_InteractionService_s), dup_strs);
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

/* FUNC(zx_WALK_SO_b_InteractionService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_InteractionService(struct zx_ctx* c, struct zx_b_InteractionService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_InteractionService) */

int zx_WALK_WO_b_InteractionService(struct zx_ctx* c, struct zx_b_InteractionService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_ProcessingContext
#define EL_STRUCT zx_b_ProcessingContext_s
#define EL_NS     b
#define EL_TAG    ProcessingContext

/* FUNC(zx_FREE_b_ProcessingContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_ProcessingContext(struct zx_ctx* c, struct zx_b_ProcessingContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_ProcessingContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_ProcessingContext_s* zx_NEW_b_ProcessingContext(struct zx_ctx* c)
{
  struct zx_b_ProcessingContext_s* x = ZX_ZALLOC(c, struct zx_b_ProcessingContext_s);
  x->gg.g.tok = zx_b_ProcessingContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_ProcessingContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_ProcessingContext(struct zx_ctx* c, struct zx_b_ProcessingContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b_ProcessingContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_ProcessingContext_s* zx_DEEP_CLONE_b_ProcessingContext(struct zx_ctx* c, struct zx_b_ProcessingContext_s* x, int dup_strs)
{
  x = (struct zx_b_ProcessingContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_ProcessingContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b_ProcessingContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_ProcessingContext(struct zx_ctx* c, struct zx_b_ProcessingContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_ProcessingContext) */

int zx_WALK_WO_b_ProcessingContext(struct zx_ctx* c, struct zx_b_ProcessingContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_RedirectRequest
#define EL_STRUCT zx_b_RedirectRequest_s
#define EL_NS     b
#define EL_TAG    RedirectRequest

/* FUNC(zx_FREE_b_RedirectRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_RedirectRequest(struct zx_ctx* c, struct zx_b_RedirectRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->redirectURL, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_RedirectRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_RedirectRequest_s* zx_NEW_b_RedirectRequest(struct zx_ctx* c)
{
  struct zx_b_RedirectRequest_s* x = ZX_ZALLOC(c, struct zx_b_RedirectRequest_s);
  x->gg.g.tok = zx_b_RedirectRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_RedirectRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_RedirectRequest(struct zx_ctx* c, struct zx_b_RedirectRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->redirectURL);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b_RedirectRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_RedirectRequest_s* zx_DEEP_CLONE_b_RedirectRequest(struct zx_ctx* c, struct zx_b_RedirectRequest_s* x, int dup_strs)
{
  x = (struct zx_b_RedirectRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_RedirectRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->redirectURL = zx_clone_attr(c, x->redirectURL);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b_RedirectRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_RedirectRequest(struct zx_ctx* c, struct zx_b_RedirectRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_RedirectRequest) */

int zx_WALK_WO_b_RedirectRequest(struct zx_ctx* c, struct zx_b_RedirectRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_Sender
#define EL_STRUCT zx_b_Sender_s
#define EL_NS     b
#define EL_TAG    Sender

/* FUNC(zx_FREE_b_Sender) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_Sender(struct zx_ctx* c, struct zx_b_Sender_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->affiliationID, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->providerID, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_Sender) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_Sender_s* zx_NEW_b_Sender(struct zx_ctx* c)
{
  struct zx_b_Sender_s* x = ZX_ZALLOC(c, struct zx_b_Sender_s);
  x->gg.g.tok = zx_b_Sender_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_Sender) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_Sender(struct zx_ctx* c, struct zx_b_Sender_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->affiliationID);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->providerID);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b_Sender) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_Sender_s* zx_DEEP_CLONE_b_Sender(struct zx_ctx* c, struct zx_b_Sender_s* x, int dup_strs)
{
  x = (struct zx_b_Sender_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_Sender_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->affiliationID = zx_clone_attr(c, x->affiliationID);
  x->id = zx_clone_attr(c, x->id);
  x->providerID = zx_clone_attr(c, x->providerID);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b_Sender) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_Sender(struct zx_ctx* c, struct zx_b_Sender_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_Sender) */

int zx_WALK_WO_b_Sender(struct zx_ctx* c, struct zx_b_Sender_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_TargetIdentity
#define EL_STRUCT zx_b_TargetIdentity_s
#define EL_NS     b
#define EL_TAG    TargetIdentity

/* FUNC(zx_FREE_b_TargetIdentity) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_TargetIdentity(struct zx_ctx* c, struct zx_b_TargetIdentity_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

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
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      for (e = x->sa11_Assertion; e; e = en) {
	  en = (struct zx_sa11_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa11_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      struct zx_ff12_Assertion_s* en;
      for (e = x->ff12_Assertion; e; e = en) {
	  en = (struct zx_ff12_Assertion_s*)e->gg.g.n;
	  zx_FREE_ff12_Assertion(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_TargetIdentity) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_TargetIdentity_s* zx_NEW_b_TargetIdentity(struct zx_ctx* c)
{
  struct zx_b_TargetIdentity_s* x = ZX_ZALLOC(c, struct zx_b_TargetIdentity_s);
  x->gg.g.tok = zx_b_TargetIdentity_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_TargetIdentity) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_TargetIdentity(struct zx_ctx* c, struct zx_b_TargetIdentity_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

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
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Assertion(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Assertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_b_TargetIdentity) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_TargetIdentity_s* zx_DEEP_CLONE_b_TargetIdentity(struct zx_ctx* c, struct zx_b_TargetIdentity_s* x, int dup_strs)
{
  x = (struct zx_b_TargetIdentity_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_TargetIdentity_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

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
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      struct zx_sa11_Assertion_s* enn;
      for (enn = 0, e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->sa11_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      struct zx_ff12_Assertion_s* en;
      struct zx_ff12_Assertion_s* enn;
      for (enn = 0, e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->ff12_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_b_TargetIdentity) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_TargetIdentity(struct zx_ctx* c, struct zx_b_TargetIdentity_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_b_TargetIdentity) */

int zx_WALK_WO_b_TargetIdentity(struct zx_ctx* c, struct zx_b_TargetIdentity_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_Timeout
#define EL_STRUCT zx_b_Timeout_s
#define EL_NS     b
#define EL_TAG    Timeout

/* FUNC(zx_FREE_b_Timeout) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_Timeout(struct zx_ctx* c, struct zx_b_Timeout_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->maxProcessingTime, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_Timeout) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_Timeout_s* zx_NEW_b_Timeout(struct zx_ctx* c)
{
  struct zx_b_Timeout_s* x = ZX_ZALLOC(c, struct zx_b_Timeout_s);
  x->gg.g.tok = zx_b_Timeout_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_Timeout) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_Timeout(struct zx_ctx* c, struct zx_b_Timeout_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->maxProcessingTime);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b_Timeout) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_Timeout_s* zx_DEEP_CLONE_b_Timeout(struct zx_ctx* c, struct zx_b_Timeout_s* x, int dup_strs)
{
  x = (struct zx_b_Timeout_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_Timeout_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->maxProcessingTime = zx_clone_attr(c, x->maxProcessingTime);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b_Timeout) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_Timeout(struct zx_ctx* c, struct zx_b_Timeout_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b_Timeout) */

int zx_WALK_WO_b_Timeout(struct zx_ctx* c, struct zx_b_Timeout_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_UsageDirective
#define EL_STRUCT zx_b_UsageDirective_s
#define EL_NS     b
#define EL_TAG    UsageDirective

/* FUNC(zx_FREE_b_UsageDirective) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_UsageDirective(struct zx_ctx* c, struct zx_b_UsageDirective_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->ref, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_xa_Obligation_s* e;
      struct zx_xa_Obligation_s* en;
      for (e = x->Obligation; e; e = en) {
	  en = (struct zx_xa_Obligation_s*)e->gg.g.n;
	  zx_FREE_xa_Obligation(c, e, free_strs);
      }
  }
  {
      struct zx_tas3sol_Dict_s* e;
      struct zx_tas3sol_Dict_s* en;
      for (e = x->Dict; e; e = en) {
	  en = (struct zx_tas3sol_Dict_s*)e->gg.g.n;
	  zx_FREE_tas3sol_Dict(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_UsageDirective) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_UsageDirective_s* zx_NEW_b_UsageDirective(struct zx_ctx* c)
{
  struct zx_b_UsageDirective_s* x = ZX_ZALLOC(c, struct zx_b_UsageDirective_s);
  x->gg.g.tok = zx_b_UsageDirective_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_UsageDirective) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_UsageDirective(struct zx_ctx* c, struct zx_b_UsageDirective_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->ref);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Obligation(c, e);
  }
  {
      struct zx_tas3sol_Dict_s* e;
      for (e = x->Dict; e; e = (struct zx_tas3sol_Dict_s*)e->gg.g.n)
	  zx_DUP_STRS_tas3sol_Dict(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_b_UsageDirective) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_UsageDirective_s* zx_DEEP_CLONE_b_UsageDirective(struct zx_ctx* c, struct zx_b_UsageDirective_s* x, int dup_strs)
{
  x = (struct zx_b_UsageDirective_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_UsageDirective_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->ref = zx_clone_attr(c, x->ref);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

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
  {
      struct zx_tas3sol_Dict_s* e;
      struct zx_tas3sol_Dict_s* en;
      struct zx_tas3sol_Dict_s* enn;
      for (enn = 0, e = x->Dict; e; e = (struct zx_tas3sol_Dict_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_tas3sol_Dict(c, e, dup_strs);
	  if (!enn)
	      x->Dict = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_b_UsageDirective) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_UsageDirective(struct zx_ctx* c, struct zx_b_UsageDirective_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_tas3sol_Dict_s* e;
      for (e = x->Dict; e; e = (struct zx_tas3sol_Dict_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_tas3sol_Dict(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_b_UsageDirective) */

int zx_WALK_WO_b_UsageDirective(struct zx_ctx* c, struct zx_b_UsageDirective_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b_UserInteraction
#define EL_STRUCT zx_b_UserInteraction_s
#define EL_NS     b
#define EL_TAG    UserInteraction

/* FUNC(zx_FREE_b_UserInteraction) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b_UserInteraction(struct zx_ctx* c, struct zx_b_UserInteraction_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->interact, free_strs);
  zx_free_attr(c, x->language, free_strs);
  zx_free_attr(c, x->maxInteractTime, free_strs);
  zx_free_attr(c, x->redirect, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_b_InteractionService_s* e;
      struct zx_b_InteractionService_s* en;
      for (e = x->InteractionService; e; e = en) {
	  en = (struct zx_b_InteractionService_s*)e->gg.g.n;
	  zx_FREE_b_InteractionService(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b_UserInteraction) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b_UserInteraction_s* zx_NEW_b_UserInteraction(struct zx_ctx* c)
{
  struct zx_b_UserInteraction_s* x = ZX_ZALLOC(c, struct zx_b_UserInteraction_s);
  x->gg.g.tok = zx_b_UserInteraction_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b_UserInteraction) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b_UserInteraction(struct zx_ctx* c, struct zx_b_UserInteraction_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->interact);
  zx_dup_attr(c, x->language);
  zx_dup_attr(c, x->maxInteractTime);
  zx_dup_attr(c, x->redirect);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_b_InteractionService_s* e;
      for (e = x->InteractionService; e; e = (struct zx_b_InteractionService_s*)e->gg.g.n)
	  zx_DUP_STRS_b_InteractionService(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_b_UserInteraction) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b_UserInteraction_s* zx_DEEP_CLONE_b_UserInteraction(struct zx_ctx* c, struct zx_b_UserInteraction_s* x, int dup_strs)
{
  x = (struct zx_b_UserInteraction_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b_UserInteraction_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->interact = zx_clone_attr(c, x->interact);
  x->language = zx_clone_attr(c, x->language);
  x->maxInteractTime = zx_clone_attr(c, x->maxInteractTime);
  x->redirect = zx_clone_attr(c, x->redirect);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

  {
      struct zx_b_InteractionService_s* e;
      struct zx_b_InteractionService_s* en;
      struct zx_b_InteractionService_s* enn;
      for (enn = 0, e = x->InteractionService; e; e = (struct zx_b_InteractionService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_InteractionService(c, e, dup_strs);
	  if (!enn)
	      x->InteractionService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_b_UserInteraction) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b_UserInteraction(struct zx_ctx* c, struct zx_b_UserInteraction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_b_InteractionService_s* e;
      for (e = x->InteractionService; e; e = (struct zx_b_InteractionService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_InteractionService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_b_UserInteraction) */

int zx_WALK_WO_b_UserInteraction(struct zx_ctx* c, struct zx_b_UserInteraction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-b-aux.c */
