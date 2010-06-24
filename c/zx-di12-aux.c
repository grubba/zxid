/* c/zx-di12-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-di12-data.h"



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

#define EL_NAME   di12_AuthenticateRequester
#define EL_STRUCT zx_di12_AuthenticateRequester_s
#define EL_NS     di12
#define EL_TAG    AuthenticateRequester

/* FUNC(zx_FREE_di12_AuthenticateRequester) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_AuthenticateRequester(struct zx_ctx* c, struct zx_di12_AuthenticateRequester_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->descriptionIDRefs, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_AuthenticateRequester) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_AuthenticateRequester_s* zx_NEW_di12_AuthenticateRequester(struct zx_ctx* c)
{
  struct zx_di12_AuthenticateRequester_s* x = ZX_ZALLOC(c, struct zx_di12_AuthenticateRequester_s);
  x->gg.g.tok = zx_di12_AuthenticateRequester_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_AuthenticateRequester) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_AuthenticateRequester(struct zx_ctx* c, struct zx_di12_AuthenticateRequester_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->descriptionIDRefs);


}

/* FUNC(zx_DEEP_CLONE_di12_AuthenticateRequester) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_AuthenticateRequester_s* zx_DEEP_CLONE_di12_AuthenticateRequester(struct zx_ctx* c, struct zx_di12_AuthenticateRequester_s* x, int dup_strs)
{
  x = (struct zx_di12_AuthenticateRequester_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_AuthenticateRequester_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->descriptionIDRefs = zx_clone_attr(c, x->descriptionIDRefs);


  return x;
}

/* FUNC(zx_WALK_SO_di12_AuthenticateRequester) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_AuthenticateRequester(struct zx_ctx* c, struct zx_di12_AuthenticateRequester_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_AuthenticateRequester) */

int zx_WALK_WO_di12_AuthenticateRequester(struct zx_ctx* c, struct zx_di12_AuthenticateRequester_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_AuthenticateSessionContext
#define EL_STRUCT zx_di12_AuthenticateSessionContext_s
#define EL_NS     di12
#define EL_TAG    AuthenticateSessionContext

/* FUNC(zx_FREE_di12_AuthenticateSessionContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_AuthenticateSessionContext(struct zx_ctx* c, struct zx_di12_AuthenticateSessionContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->descriptionIDRefs, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_AuthenticateSessionContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_AuthenticateSessionContext_s* zx_NEW_di12_AuthenticateSessionContext(struct zx_ctx* c)
{
  struct zx_di12_AuthenticateSessionContext_s* x = ZX_ZALLOC(c, struct zx_di12_AuthenticateSessionContext_s);
  x->gg.g.tok = zx_di12_AuthenticateSessionContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_AuthenticateSessionContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_AuthenticateSessionContext(struct zx_ctx* c, struct zx_di12_AuthenticateSessionContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->descriptionIDRefs);


}

/* FUNC(zx_DEEP_CLONE_di12_AuthenticateSessionContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_AuthenticateSessionContext_s* zx_DEEP_CLONE_di12_AuthenticateSessionContext(struct zx_ctx* c, struct zx_di12_AuthenticateSessionContext_s* x, int dup_strs)
{
  x = (struct zx_di12_AuthenticateSessionContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_AuthenticateSessionContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->descriptionIDRefs = zx_clone_attr(c, x->descriptionIDRefs);


  return x;
}

/* FUNC(zx_WALK_SO_di12_AuthenticateSessionContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_AuthenticateSessionContext(struct zx_ctx* c, struct zx_di12_AuthenticateSessionContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_AuthenticateSessionContext) */

int zx_WALK_WO_di12_AuthenticateSessionContext(struct zx_ctx* c, struct zx_di12_AuthenticateSessionContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_AuthorizeRequester
#define EL_STRUCT zx_di12_AuthorizeRequester_s
#define EL_NS     di12
#define EL_TAG    AuthorizeRequester

/* FUNC(zx_FREE_di12_AuthorizeRequester) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_AuthorizeRequester(struct zx_ctx* c, struct zx_di12_AuthorizeRequester_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->descriptionIDRefs, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_AuthorizeRequester) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_AuthorizeRequester_s* zx_NEW_di12_AuthorizeRequester(struct zx_ctx* c)
{
  struct zx_di12_AuthorizeRequester_s* x = ZX_ZALLOC(c, struct zx_di12_AuthorizeRequester_s);
  x->gg.g.tok = zx_di12_AuthorizeRequester_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_AuthorizeRequester) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_AuthorizeRequester(struct zx_ctx* c, struct zx_di12_AuthorizeRequester_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->descriptionIDRefs);


}

/* FUNC(zx_DEEP_CLONE_di12_AuthorizeRequester) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_AuthorizeRequester_s* zx_DEEP_CLONE_di12_AuthorizeRequester(struct zx_ctx* c, struct zx_di12_AuthorizeRequester_s* x, int dup_strs)
{
  x = (struct zx_di12_AuthorizeRequester_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_AuthorizeRequester_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->descriptionIDRefs = zx_clone_attr(c, x->descriptionIDRefs);


  return x;
}

/* FUNC(zx_WALK_SO_di12_AuthorizeRequester) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_AuthorizeRequester(struct zx_ctx* c, struct zx_di12_AuthorizeRequester_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_AuthorizeRequester) */

int zx_WALK_WO_di12_AuthorizeRequester(struct zx_ctx* c, struct zx_di12_AuthorizeRequester_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Credentials
#define EL_STRUCT zx_di12_Credentials_s
#define EL_NS     di12
#define EL_TAG    Credentials

/* FUNC(zx_FREE_di12_Credentials) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Credentials(struct zx_ctx* c, struct zx_di12_Credentials_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Credentials) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Credentials_s* zx_NEW_di12_Credentials(struct zx_ctx* c)
{
  struct zx_di12_Credentials_s* x = ZX_ZALLOC(c, struct zx_di12_Credentials_s);
  x->gg.g.tok = zx_di12_Credentials_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Credentials) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Credentials(struct zx_ctx* c, struct zx_di12_Credentials_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_di12_Credentials) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Credentials_s* zx_DEEP_CLONE_di12_Credentials(struct zx_ctx* c, struct zx_di12_Credentials_s* x, int dup_strs)
{
  x = (struct zx_di12_Credentials_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Credentials_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_di12_Credentials) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Credentials(struct zx_ctx* c, struct zx_di12_Credentials_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_Credentials) */

int zx_WALK_WO_di12_Credentials(struct zx_ctx* c, struct zx_di12_Credentials_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Description
#define EL_STRUCT zx_di12_Description_s
#define EL_NS     di12
#define EL_TAG    Description

/* FUNC(zx_FREE_di12_Description) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Description(struct zx_ctx* c, struct zx_di12_Description_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  zx_free_simple_elems(c, x->SecurityMechID, free_strs);
  zx_free_simple_elems(c, x->CredentialRef, free_strs);
  zx_free_simple_elems(c, x->WsdlURI, free_strs);
  zx_free_simple_elems(c, x->ServiceNameRef, free_strs);
  zx_free_simple_elems(c, x->Endpoint, free_strs);
  zx_free_simple_elems(c, x->SoapAction, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Description) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Description_s* zx_NEW_di12_Description(struct zx_ctx* c)
{
  struct zx_di12_Description_s* x = ZX_ZALLOC(c, struct zx_di12_Description_s);
  x->gg.g.tok = zx_di12_Description_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Description) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Description(struct zx_ctx* c, struct zx_di12_Description_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  zx_dup_strs_simple_elems(c, x->SecurityMechID);
  zx_dup_strs_simple_elems(c, x->CredentialRef);
  zx_dup_strs_simple_elems(c, x->WsdlURI);
  zx_dup_strs_simple_elems(c, x->ServiceNameRef);
  zx_dup_strs_simple_elems(c, x->Endpoint);
  zx_dup_strs_simple_elems(c, x->SoapAction);

}

/* FUNC(zx_DEEP_CLONE_di12_Description) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Description_s* zx_DEEP_CLONE_di12_Description(struct zx_ctx* c, struct zx_di12_Description_s* x, int dup_strs)
{
  x = (struct zx_di12_Description_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Description_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);
  x->CredentialRef = zx_deep_clone_simple_elems(c,x->CredentialRef, dup_strs);
  x->WsdlURI = zx_deep_clone_simple_elems(c,x->WsdlURI, dup_strs);
  x->ServiceNameRef = zx_deep_clone_simple_elems(c,x->ServiceNameRef, dup_strs);
  x->Endpoint = zx_deep_clone_simple_elems(c,x->Endpoint, dup_strs);
  x->SoapAction = zx_deep_clone_simple_elems(c,x->SoapAction, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di12_Description) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Description(struct zx_ctx* c, struct zx_di12_Description_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SecurityMechID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->CredentialRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->WsdlURI, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ServiceNameRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Endpoint, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SoapAction, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_Description) */

int zx_WALK_WO_di12_Description(struct zx_ctx* c, struct zx_di12_Description_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_EncryptResourceID
#define EL_STRUCT zx_di12_EncryptResourceID_s
#define EL_NS     di12
#define EL_TAG    EncryptResourceID

/* FUNC(zx_FREE_di12_EncryptResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_EncryptResourceID(struct zx_ctx* c, struct zx_di12_EncryptResourceID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->descriptionIDRefs, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_EncryptResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_EncryptResourceID_s* zx_NEW_di12_EncryptResourceID(struct zx_ctx* c)
{
  struct zx_di12_EncryptResourceID_s* x = ZX_ZALLOC(c, struct zx_di12_EncryptResourceID_s);
  x->gg.g.tok = zx_di12_EncryptResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_EncryptResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_EncryptResourceID(struct zx_ctx* c, struct zx_di12_EncryptResourceID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->descriptionIDRefs);


}

/* FUNC(zx_DEEP_CLONE_di12_EncryptResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_EncryptResourceID_s* zx_DEEP_CLONE_di12_EncryptResourceID(struct zx_ctx* c, struct zx_di12_EncryptResourceID_s* x, int dup_strs)
{
  x = (struct zx_di12_EncryptResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_EncryptResourceID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->descriptionIDRefs = zx_clone_attr(c, x->descriptionIDRefs);


  return x;
}

/* FUNC(zx_WALK_SO_di12_EncryptResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_EncryptResourceID(struct zx_ctx* c, struct zx_di12_EncryptResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_EncryptResourceID) */

int zx_WALK_WO_di12_EncryptResourceID(struct zx_ctx* c, struct zx_di12_EncryptResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_EncryptedResourceID
#define EL_STRUCT zx_di12_EncryptedResourceID_s
#define EL_NS     di12
#define EL_TAG    EncryptedResourceID

/* FUNC(zx_FREE_di12_EncryptedResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_EncryptedResourceID(struct zx_ctx* c, struct zx_di12_EncryptedResourceID_s* x, int free_strs)
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

/* FUNC(zx_NEW_di12_EncryptedResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_EncryptedResourceID_s* zx_NEW_di12_EncryptedResourceID(struct zx_ctx* c)
{
  struct zx_di12_EncryptedResourceID_s* x = ZX_ZALLOC(c, struct zx_di12_EncryptedResourceID_s);
  x->gg.g.tok = zx_di12_EncryptedResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_EncryptedResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_EncryptedResourceID(struct zx_ctx* c, struct zx_di12_EncryptedResourceID_s* x)
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

/* FUNC(zx_DEEP_CLONE_di12_EncryptedResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_EncryptedResourceID_s* zx_DEEP_CLONE_di12_EncryptedResourceID(struct zx_ctx* c, struct zx_di12_EncryptedResourceID_s* x, int dup_strs)
{
  x = (struct zx_di12_EncryptedResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_EncryptedResourceID_s), dup_strs);
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

/* FUNC(zx_WALK_SO_di12_EncryptedResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_EncryptedResourceID(struct zx_ctx* c, struct zx_di12_EncryptedResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_EncryptedResourceID) */

int zx_WALK_WO_di12_EncryptedResourceID(struct zx_ctx* c, struct zx_di12_EncryptedResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Extension
#define EL_STRUCT zx_di12_Extension_s
#define EL_NS     di12
#define EL_TAG    Extension

/* FUNC(zx_FREE_di12_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Extension(struct zx_ctx* c, struct zx_di12_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Extension_s* zx_NEW_di12_Extension(struct zx_ctx* c)
{
  struct zx_di12_Extension_s* x = ZX_ZALLOC(c, struct zx_di12_Extension_s);
  x->gg.g.tok = zx_di12_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Extension(struct zx_ctx* c, struct zx_di12_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_di12_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Extension_s* zx_DEEP_CLONE_di12_Extension(struct zx_ctx* c, struct zx_di12_Extension_s* x, int dup_strs)
{
  x = (struct zx_di12_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_di12_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Extension(struct zx_ctx* c, struct zx_di12_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_Extension) */

int zx_WALK_WO_di12_Extension(struct zx_ctx* c, struct zx_di12_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_InsertEntry
#define EL_STRUCT zx_di12_InsertEntry_s
#define EL_NS     di12
#define EL_TAG    InsertEntry

/* FUNC(zx_FREE_di12_InsertEntry) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_InsertEntry(struct zx_ctx* c, struct zx_di12_InsertEntry_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di12_ResourceOffering_s* e;
      struct zx_di12_ResourceOffering_s* en;
      for (e = x->ResourceOffering; e; e = en) {
	  en = (struct zx_di12_ResourceOffering_s*)e->gg.g.n;
	  zx_FREE_di12_ResourceOffering(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_InsertEntry) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_InsertEntry_s* zx_NEW_di12_InsertEntry(struct zx_ctx* c)
{
  struct zx_di12_InsertEntry_s* x = ZX_ZALLOC(c, struct zx_di12_InsertEntry_s);
  x->gg.g.tok = zx_di12_InsertEntry_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_InsertEntry) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_InsertEntry(struct zx_ctx* c, struct zx_di12_InsertEntry_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di12_ResourceOffering_s* e;
      for (e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ResourceOffering(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_InsertEntry) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_InsertEntry_s* zx_DEEP_CLONE_di12_InsertEntry(struct zx_ctx* c, struct zx_di12_InsertEntry_s* x, int dup_strs)
{
  x = (struct zx_di12_InsertEntry_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_InsertEntry_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di12_ResourceOffering_s* e;
      struct zx_di12_ResourceOffering_s* en;
      struct zx_di12_ResourceOffering_s* enn;
      for (enn = 0, e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ResourceOffering(c, e, dup_strs);
	  if (!enn)
	      x->ResourceOffering = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_InsertEntry) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_InsertEntry(struct zx_ctx* c, struct zx_di12_InsertEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_ResourceOffering_s* e;
      for (e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ResourceOffering(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_InsertEntry) */

int zx_WALK_WO_di12_InsertEntry(struct zx_ctx* c, struct zx_di12_InsertEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Modify
#define EL_STRUCT zx_di12_Modify_s
#define EL_NS     di12
#define EL_TAG    Modify

/* FUNC(zx_FREE_di12_Modify) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Modify(struct zx_ctx* c, struct zx_di12_Modify_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_di12_ResourceID_s* e;
      struct zx_di12_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_di12_ResourceID_s*)e->gg.g.n;
	  zx_FREE_di12_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      struct zx_di12_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_di12_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_di12_InsertEntry_s* e;
      struct zx_di12_InsertEntry_s* en;
      for (e = x->InsertEntry; e; e = en) {
	  en = (struct zx_di12_InsertEntry_s*)e->gg.g.n;
	  zx_FREE_di12_InsertEntry(c, e, free_strs);
      }
  }
  {
      struct zx_di12_RemoveEntry_s* e;
      struct zx_di12_RemoveEntry_s* en;
      for (e = x->RemoveEntry; e; e = en) {
	  en = (struct zx_di12_RemoveEntry_s*)e->gg.g.n;
	  zx_FREE_di12_RemoveEntry(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Modify) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Modify_s* zx_NEW_di12_Modify(struct zx_ctx* c)
{
  struct zx_di12_Modify_s* x = ZX_ZALLOC(c, struct zx_di12_Modify_s);
  x->gg.g.tok = zx_di12_Modify_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Modify) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Modify(struct zx_ctx* c, struct zx_di12_Modify_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ResourceID(c, e);
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_EncryptedResourceID(c, e);
  }
  {
      struct zx_di12_InsertEntry_s* e;
      for (e = x->InsertEntry; e; e = (struct zx_di12_InsertEntry_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_InsertEntry(c, e);
  }
  {
      struct zx_di12_RemoveEntry_s* e;
      for (e = x->RemoveEntry; e; e = (struct zx_di12_RemoveEntry_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_RemoveEntry(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_Modify) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Modify_s* zx_DEEP_CLONE_di12_Modify(struct zx_ctx* c, struct zx_di12_Modify_s* x, int dup_strs)
{
  x = (struct zx_di12_Modify_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Modify_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_di12_ResourceID_s* e;
      struct zx_di12_ResourceID_s* en;
      struct zx_di12_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      struct zx_di12_EncryptedResourceID_s* en;
      struct zx_di12_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_InsertEntry_s* e;
      struct zx_di12_InsertEntry_s* en;
      struct zx_di12_InsertEntry_s* enn;
      for (enn = 0, e = x->InsertEntry; e; e = (struct zx_di12_InsertEntry_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_InsertEntry(c, e, dup_strs);
	  if (!enn)
	      x->InsertEntry = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_RemoveEntry_s* e;
      struct zx_di12_RemoveEntry_s* en;
      struct zx_di12_RemoveEntry_s* enn;
      for (enn = 0, e = x->RemoveEntry; e; e = (struct zx_di12_RemoveEntry_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_RemoveEntry(c, e, dup_strs);
	  if (!enn)
	      x->RemoveEntry = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_Modify) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Modify(struct zx_ctx* c, struct zx_di12_Modify_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_InsertEntry_s* e;
      for (e = x->InsertEntry; e; e = (struct zx_di12_InsertEntry_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_InsertEntry(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_RemoveEntry_s* e;
      for (e = x->RemoveEntry; e; e = (struct zx_di12_RemoveEntry_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_RemoveEntry(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_Modify) */

int zx_WALK_WO_di12_Modify(struct zx_ctx* c, struct zx_di12_Modify_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_ModifyResponse
#define EL_STRUCT zx_di12_ModifyResponse_s
#define EL_NS     di12
#define EL_TAG    ModifyResponse

/* FUNC(zx_FREE_di12_ModifyResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_ModifyResponse(struct zx_ctx* c, struct zx_di12_ModifyResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->newEntryIDs, free_strs);

  {
      struct zx_di12_Status_s* e;
      struct zx_di12_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_di12_Status_s*)e->gg.g.n;
	  zx_FREE_di12_Status(c, e, free_strs);
      }
  }
  {
      struct zx_di12_Extension_s* e;
      struct zx_di12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_di12_Extension_s*)e->gg.g.n;
	  zx_FREE_di12_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_ModifyResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_ModifyResponse_s* zx_NEW_di12_ModifyResponse(struct zx_ctx* c)
{
  struct zx_di12_ModifyResponse_s* x = ZX_ZALLOC(c, struct zx_di12_ModifyResponse_s);
  x->gg.g.tok = zx_di12_ModifyResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_ModifyResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_ModifyResponse(struct zx_ctx* c, struct zx_di12_ModifyResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->newEntryIDs);

  {
      struct zx_di12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Status(c, e);
  }
  {
      struct zx_di12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_di12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_ModifyResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_ModifyResponse_s* zx_DEEP_CLONE_di12_ModifyResponse(struct zx_ctx* c, struct zx_di12_ModifyResponse_s* x, int dup_strs)
{
  x = (struct zx_di12_ModifyResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_ModifyResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->newEntryIDs = zx_clone_attr(c, x->newEntryIDs);

  {
      struct zx_di12_Status_s* e;
      struct zx_di12_Status_s* en;
      struct zx_di12_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_Extension_s* e;
      struct zx_di12_Extension_s* en;
      struct zx_di12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_di12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_ModifyResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_ModifyResponse(struct zx_ctx* c, struct zx_di12_ModifyResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_di12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_ModifyResponse) */

int zx_WALK_WO_di12_ModifyResponse(struct zx_ctx* c, struct zx_di12_ModifyResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Options
#define EL_STRUCT zx_di12_Options_s
#define EL_NS     di12
#define EL_TAG    Options

/* FUNC(zx_FREE_di12_Options) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Options(struct zx_ctx* c, struct zx_di12_Options_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Option, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Options) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Options_s* zx_NEW_di12_Options(struct zx_ctx* c)
{
  struct zx_di12_Options_s* x = ZX_ZALLOC(c, struct zx_di12_Options_s);
  x->gg.g.tok = zx_di12_Options_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Options) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Options(struct zx_ctx* c, struct zx_di12_Options_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Option);

}

/* FUNC(zx_DEEP_CLONE_di12_Options) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Options_s* zx_DEEP_CLONE_di12_Options(struct zx_ctx* c, struct zx_di12_Options_s* x, int dup_strs)
{
  x = (struct zx_di12_Options_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Options_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Option = zx_deep_clone_simple_elems(c,x->Option, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di12_Options) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Options(struct zx_ctx* c, struct zx_di12_Options_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Option, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_Options) */

int zx_WALK_WO_di12_Options(struct zx_ctx* c, struct zx_di12_Options_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Query
#define EL_STRUCT zx_di12_Query_s
#define EL_NS     di12
#define EL_TAG    Query

/* FUNC(zx_FREE_di12_Query) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Query(struct zx_ctx* c, struct zx_di12_Query_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_di12_ResourceID_s* e;
      struct zx_di12_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_di12_ResourceID_s*)e->gg.g.n;
	  zx_FREE_di12_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      struct zx_di12_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_di12_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_di12_RequestedServiceType_s* e;
      struct zx_di12_RequestedServiceType_s* en;
      for (e = x->RequestedServiceType; e; e = en) {
	  en = (struct zx_di12_RequestedServiceType_s*)e->gg.g.n;
	  zx_FREE_di12_RequestedServiceType(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Query) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Query_s* zx_NEW_di12_Query(struct zx_ctx* c)
{
  struct zx_di12_Query_s* x = ZX_ZALLOC(c, struct zx_di12_Query_s);
  x->gg.g.tok = zx_di12_Query_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Query) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Query(struct zx_ctx* c, struct zx_di12_Query_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ResourceID(c, e);
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_EncryptedResourceID(c, e);
  }
  {
      struct zx_di12_RequestedServiceType_s* e;
      for (e = x->RequestedServiceType; e; e = (struct zx_di12_RequestedServiceType_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_RequestedServiceType(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_Query) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Query_s* zx_DEEP_CLONE_di12_Query(struct zx_ctx* c, struct zx_di12_Query_s* x, int dup_strs)
{
  x = (struct zx_di12_Query_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Query_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_di12_ResourceID_s* e;
      struct zx_di12_ResourceID_s* en;
      struct zx_di12_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      struct zx_di12_EncryptedResourceID_s* en;
      struct zx_di12_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_RequestedServiceType_s* e;
      struct zx_di12_RequestedServiceType_s* en;
      struct zx_di12_RequestedServiceType_s* enn;
      for (enn = 0, e = x->RequestedServiceType; e; e = (struct zx_di12_RequestedServiceType_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_RequestedServiceType(c, e, dup_strs);
	  if (!enn)
	      x->RequestedServiceType = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_Query) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Query(struct zx_ctx* c, struct zx_di12_Query_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_RequestedServiceType_s* e;
      for (e = x->RequestedServiceType; e; e = (struct zx_di12_RequestedServiceType_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_RequestedServiceType(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_Query) */

int zx_WALK_WO_di12_Query(struct zx_ctx* c, struct zx_di12_Query_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_QueryResponse
#define EL_STRUCT zx_di12_QueryResponse_s
#define EL_NS     di12
#define EL_TAG    QueryResponse

/* FUNC(zx_FREE_di12_QueryResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_QueryResponse(struct zx_ctx* c, struct zx_di12_QueryResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_di12_Status_s* e;
      struct zx_di12_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_di12_Status_s*)e->gg.g.n;
	  zx_FREE_di12_Status(c, e, free_strs);
      }
  }
  {
      struct zx_di12_ResourceOffering_s* e;
      struct zx_di12_ResourceOffering_s* en;
      for (e = x->ResourceOffering; e; e = en) {
	  en = (struct zx_di12_ResourceOffering_s*)e->gg.g.n;
	  zx_FREE_di12_ResourceOffering(c, e, free_strs);
      }
  }
  {
      struct zx_di12_Credentials_s* e;
      struct zx_di12_Credentials_s* en;
      for (e = x->Credentials; e; e = en) {
	  en = (struct zx_di12_Credentials_s*)e->gg.g.n;
	  zx_FREE_di12_Credentials(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_QueryResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_QueryResponse_s* zx_NEW_di12_QueryResponse(struct zx_ctx* c)
{
  struct zx_di12_QueryResponse_s* x = ZX_ZALLOC(c, struct zx_di12_QueryResponse_s);
  x->gg.g.tok = zx_di12_QueryResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_QueryResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_QueryResponse(struct zx_ctx* c, struct zx_di12_QueryResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_di12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Status(c, e);
  }
  {
      struct zx_di12_ResourceOffering_s* e;
      for (e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ResourceOffering(c, e);
  }
  {
      struct zx_di12_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_di12_Credentials_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Credentials(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_QueryResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_QueryResponse_s* zx_DEEP_CLONE_di12_QueryResponse(struct zx_ctx* c, struct zx_di12_QueryResponse_s* x, int dup_strs)
{
  x = (struct zx_di12_QueryResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_QueryResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_di12_Status_s* e;
      struct zx_di12_Status_s* en;
      struct zx_di12_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_ResourceOffering_s* e;
      struct zx_di12_ResourceOffering_s* en;
      struct zx_di12_ResourceOffering_s* enn;
      for (enn = 0, e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ResourceOffering(c, e, dup_strs);
	  if (!enn)
	      x->ResourceOffering = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_Credentials_s* e;
      struct zx_di12_Credentials_s* en;
      struct zx_di12_Credentials_s* enn;
      for (enn = 0, e = x->Credentials; e; e = (struct zx_di12_Credentials_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Credentials(c, e, dup_strs);
	  if (!enn)
	      x->Credentials = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_QueryResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_QueryResponse(struct zx_ctx* c, struct zx_di12_QueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_ResourceOffering_s* e;
      for (e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ResourceOffering(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_di12_Credentials_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Credentials(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_QueryResponse) */

int zx_WALK_WO_di12_QueryResponse(struct zx_ctx* c, struct zx_di12_QueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_RemoveEntry
#define EL_STRUCT zx_di12_RemoveEntry_s
#define EL_NS     di12
#define EL_TAG    RemoveEntry

/* FUNC(zx_FREE_di12_RemoveEntry) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_RemoveEntry(struct zx_ctx* c, struct zx_di12_RemoveEntry_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->entryID, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_RemoveEntry) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_RemoveEntry_s* zx_NEW_di12_RemoveEntry(struct zx_ctx* c)
{
  struct zx_di12_RemoveEntry_s* x = ZX_ZALLOC(c, struct zx_di12_RemoveEntry_s);
  x->gg.g.tok = zx_di12_RemoveEntry_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_RemoveEntry) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_RemoveEntry(struct zx_ctx* c, struct zx_di12_RemoveEntry_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->entryID);


}

/* FUNC(zx_DEEP_CLONE_di12_RemoveEntry) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_RemoveEntry_s* zx_DEEP_CLONE_di12_RemoveEntry(struct zx_ctx* c, struct zx_di12_RemoveEntry_s* x, int dup_strs)
{
  x = (struct zx_di12_RemoveEntry_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_RemoveEntry_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->entryID = zx_clone_attr(c, x->entryID);


  return x;
}

/* FUNC(zx_WALK_SO_di12_RemoveEntry) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_RemoveEntry(struct zx_ctx* c, struct zx_di12_RemoveEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_RemoveEntry) */

int zx_WALK_WO_di12_RemoveEntry(struct zx_ctx* c, struct zx_di12_RemoveEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_RequestedServiceType
#define EL_STRUCT zx_di12_RequestedServiceType_s
#define EL_NS     di12
#define EL_TAG    RequestedServiceType

/* FUNC(zx_FREE_di12_RequestedServiceType) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_RequestedServiceType(struct zx_ctx* c, struct zx_di12_RequestedServiceType_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->ServiceType, free_strs);
  {
      struct zx_di12_Options_s* e;
      struct zx_di12_Options_s* en;
      for (e = x->Options; e; e = en) {
	  en = (struct zx_di12_Options_s*)e->gg.g.n;
	  zx_FREE_di12_Options(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_RequestedServiceType) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_RequestedServiceType_s* zx_NEW_di12_RequestedServiceType(struct zx_ctx* c)
{
  struct zx_di12_RequestedServiceType_s* x = ZX_ZALLOC(c, struct zx_di12_RequestedServiceType_s);
  x->gg.g.tok = zx_di12_RequestedServiceType_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_RequestedServiceType) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_RequestedServiceType(struct zx_ctx* c, struct zx_di12_RequestedServiceType_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->ServiceType);
  {
      struct zx_di12_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Options(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_RequestedServiceType) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_RequestedServiceType_s* zx_DEEP_CLONE_di12_RequestedServiceType(struct zx_ctx* c, struct zx_di12_RequestedServiceType_s* x, int dup_strs)
{
  x = (struct zx_di12_RequestedServiceType_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_RequestedServiceType_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->ServiceType = zx_deep_clone_simple_elems(c,x->ServiceType, dup_strs);
  {
      struct zx_di12_Options_s* e;
      struct zx_di12_Options_s* en;
      struct zx_di12_Options_s* enn;
      for (enn = 0, e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Options(c, e, dup_strs);
	  if (!enn)
	      x->Options = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_RequestedServiceType) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_RequestedServiceType(struct zx_ctx* c, struct zx_di12_RequestedServiceType_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->ServiceType, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_di12_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Options(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_RequestedServiceType) */

int zx_WALK_WO_di12_RequestedServiceType(struct zx_ctx* c, struct zx_di12_RequestedServiceType_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_ResourceID
#define EL_STRUCT zx_di12_ResourceID_s
#define EL_NS     di12
#define EL_TAG    ResourceID

/* FUNC(zx_FREE_di12_ResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_ResourceID(struct zx_ctx* c, struct zx_di12_ResourceID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_ResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_ResourceID_s* zx_NEW_di12_ResourceID(struct zx_ctx* c)
{
  struct zx_di12_ResourceID_s* x = ZX_ZALLOC(c, struct zx_di12_ResourceID_s);
  x->gg.g.tok = zx_di12_ResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_ResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_ResourceID(struct zx_ctx* c, struct zx_di12_ResourceID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);


}

/* FUNC(zx_DEEP_CLONE_di12_ResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_ResourceID_s* zx_DEEP_CLONE_di12_ResourceID(struct zx_ctx* c, struct zx_di12_ResourceID_s* x, int dup_strs)
{
  x = (struct zx_di12_ResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_ResourceID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);


  return x;
}

/* FUNC(zx_WALK_SO_di12_ResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_ResourceID(struct zx_ctx* c, struct zx_di12_ResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di12_ResourceID) */

int zx_WALK_WO_di12_ResourceID(struct zx_ctx* c, struct zx_di12_ResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_ResourceOffering
#define EL_STRUCT zx_di12_ResourceOffering_s
#define EL_NS     di12
#define EL_TAG    ResourceOffering

/* FUNC(zx_FREE_di12_ResourceOffering) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_ResourceOffering(struct zx_ctx* c, struct zx_di12_ResourceOffering_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->entryID, free_strs);

  {
      struct zx_di12_ResourceID_s* e;
      struct zx_di12_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_di12_ResourceID_s*)e->gg.g.n;
	  zx_FREE_di12_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      struct zx_di12_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_di12_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_di12_ServiceInstance_s* e;
      struct zx_di12_ServiceInstance_s* en;
      for (e = x->ServiceInstance; e; e = en) {
	  en = (struct zx_di12_ServiceInstance_s*)e->gg.g.n;
	  zx_FREE_di12_ServiceInstance(c, e, free_strs);
      }
  }
  {
      struct zx_di12_Options_s* e;
      struct zx_di12_Options_s* en;
      for (e = x->Options; e; e = en) {
	  en = (struct zx_di12_Options_s*)e->gg.g.n;
	  zx_FREE_di12_Options(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Abstract, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_ResourceOffering) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_ResourceOffering_s* zx_NEW_di12_ResourceOffering(struct zx_ctx* c)
{
  struct zx_di12_ResourceOffering_s* x = ZX_ZALLOC(c, struct zx_di12_ResourceOffering_s);
  x->gg.g.tok = zx_di12_ResourceOffering_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_ResourceOffering) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_ResourceOffering(struct zx_ctx* c, struct zx_di12_ResourceOffering_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->entryID);

  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ResourceID(c, e);
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_EncryptedResourceID(c, e);
  }
  {
      struct zx_di12_ServiceInstance_s* e;
      for (e = x->ServiceInstance; e; e = (struct zx_di12_ServiceInstance_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ServiceInstance(c, e);
  }
  {
      struct zx_di12_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Options(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Abstract);

}

/* FUNC(zx_DEEP_CLONE_di12_ResourceOffering) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_ResourceOffering_s* zx_DEEP_CLONE_di12_ResourceOffering(struct zx_ctx* c, struct zx_di12_ResourceOffering_s* x, int dup_strs)
{
  x = (struct zx_di12_ResourceOffering_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_ResourceOffering_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->entryID = zx_clone_attr(c, x->entryID);

  {
      struct zx_di12_ResourceID_s* e;
      struct zx_di12_ResourceID_s* en;
      struct zx_di12_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      struct zx_di12_EncryptedResourceID_s* en;
      struct zx_di12_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_ServiceInstance_s* e;
      struct zx_di12_ServiceInstance_s* en;
      struct zx_di12_ServiceInstance_s* enn;
      for (enn = 0, e = x->ServiceInstance; e; e = (struct zx_di12_ServiceInstance_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ServiceInstance(c, e, dup_strs);
	  if (!enn)
	      x->ServiceInstance = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_Options_s* e;
      struct zx_di12_Options_s* en;
      struct zx_di12_Options_s* enn;
      for (enn = 0, e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Options(c, e, dup_strs);
	  if (!enn)
	      x->Options = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Abstract = zx_deep_clone_simple_elems(c,x->Abstract, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di12_ResourceOffering) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_ResourceOffering(struct zx_ctx* c, struct zx_di12_ResourceOffering_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_ServiceInstance_s* e;
      for (e = x->ServiceInstance; e; e = (struct zx_di12_ServiceInstance_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ServiceInstance(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Options(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Abstract, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_ResourceOffering) */

int zx_WALK_WO_di12_ResourceOffering(struct zx_ctx* c, struct zx_di12_ResourceOffering_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_ServiceInstance
#define EL_STRUCT zx_di12_ServiceInstance_s
#define EL_NS     di12
#define EL_TAG    ServiceInstance

/* FUNC(zx_FREE_di12_ServiceInstance) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_ServiceInstance(struct zx_ctx* c, struct zx_di12_ServiceInstance_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->ServiceType, free_strs);
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_di12_Description_s* e;
      struct zx_di12_Description_s* en;
      for (e = x->Description; e; e = en) {
	  en = (struct zx_di12_Description_s*)e->gg.g.n;
	  zx_FREE_di12_Description(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_ServiceInstance) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_ServiceInstance_s* zx_NEW_di12_ServiceInstance(struct zx_ctx* c)
{
  struct zx_di12_ServiceInstance_s* x = ZX_ZALLOC(c, struct zx_di12_ServiceInstance_s);
  x->gg.g.tok = zx_di12_ServiceInstance_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_ServiceInstance) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_ServiceInstance(struct zx_ctx* c, struct zx_di12_ServiceInstance_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->ServiceType);
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_di12_Description_s* e;
      for (e = x->Description; e; e = (struct zx_di12_Description_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Description(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_ServiceInstance) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_ServiceInstance_s* zx_DEEP_CLONE_di12_ServiceInstance(struct zx_ctx* c, struct zx_di12_ServiceInstance_s* x, int dup_strs)
{
  x = (struct zx_di12_ServiceInstance_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_ServiceInstance_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->ServiceType = zx_deep_clone_simple_elems(c,x->ServiceType, dup_strs);
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  {
      struct zx_di12_Description_s* e;
      struct zx_di12_Description_s* en;
      struct zx_di12_Description_s* enn;
      for (enn = 0, e = x->Description; e; e = (struct zx_di12_Description_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Description(c, e, dup_strs);
	  if (!enn)
	      x->Description = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_ServiceInstance) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_ServiceInstance(struct zx_ctx* c, struct zx_di12_ServiceInstance_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->ServiceType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_di12_Description_s* e;
      for (e = x->Description; e; e = (struct zx_di12_Description_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Description(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_ServiceInstance) */

int zx_WALK_WO_di12_ServiceInstance(struct zx_ctx* c, struct zx_di12_ServiceInstance_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di12_Status
#define EL_STRUCT zx_di12_Status_s
#define EL_NS     di12
#define EL_TAG    Status

/* FUNC(zx_FREE_di12_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di12_Status(struct zx_ctx* c, struct zx_di12_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->code, free_strs);
  zx_free_attr(c, x->comment, free_strs);
  zx_free_attr(c, x->ref, free_strs);

  {
      struct zx_di12_Status_s* e;
      struct zx_di12_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_di12_Status_s*)e->gg.g.n;
	  zx_FREE_di12_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di12_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di12_Status_s* zx_NEW_di12_Status(struct zx_ctx* c)
{
  struct zx_di12_Status_s* x = ZX_ZALLOC(c, struct zx_di12_Status_s);
  x->gg.g.tok = zx_di12_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di12_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di12_Status(struct zx_ctx* c, struct zx_di12_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->code);
  zx_dup_attr(c, x->comment);
  zx_dup_attr(c, x->ref);

  {
      struct zx_di12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di12_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di12_Status_s* zx_DEEP_CLONE_di12_Status(struct zx_ctx* c, struct zx_di12_Status_s* x, int dup_strs)
{
  x = (struct zx_di12_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di12_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->code = zx_clone_attr(c, x->code);
  x->comment = zx_clone_attr(c, x->comment);
  x->ref = zx_clone_attr(c, x->ref);

  {
      struct zx_di12_Status_s* e;
      struct zx_di12_Status_s* en;
      struct zx_di12_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di12_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di12_Status(struct zx_ctx* c, struct zx_di12_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_di12_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di12_Status) */

int zx_WALK_WO_di12_Status(struct zx_ctx* c, struct zx_di12_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-di12-aux.c */
