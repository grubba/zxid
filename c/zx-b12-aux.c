/* c/zx-b12-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-b12-data.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   b12_Consent
#define EL_STRUCT zx_b12_Consent_s
#define EL_NS     b12
#define EL_TAG    Consent

/* FUNC(zx_FREE_b12_Consent) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->timestamp, free_strs);
  zx_free_attr(c, x->uri, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b12_Consent) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b12_Consent_s* zx_NEW_b12_Consent(struct zx_ctx* c)
{
  struct zx_b12_Consent_s* x = ZX_ZALLOC(c, struct zx_b12_Consent_s);
  x->gg.g.tok = zx_b12_Consent_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b12_Consent) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->timestamp);
  zx_dup_attr(c, x->uri);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b12_Consent) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b12_Consent_s* zx_DEEP_CLONE_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x, int dup_strs)
{
  x = (struct zx_b12_Consent_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b12_Consent_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->timestamp = zx_clone_attr(c, x->timestamp);
  x->uri = zx_clone_attr(c, x->uri);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b12_Consent) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b12_Consent) */

int zx_WALK_WO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b12_Correlation
#define EL_STRUCT zx_b12_Correlation_s
#define EL_NS     b12
#define EL_TAG    Correlation

/* FUNC(zx_FREE_b12_Correlation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->messageID, free_strs);
  zx_free_attr(c, x->refToMessageID, free_strs);
  zx_free_attr(c, x->timestamp, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b12_Correlation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b12_Correlation_s* zx_NEW_b12_Correlation(struct zx_ctx* c)
{
  struct zx_b12_Correlation_s* x = ZX_ZALLOC(c, struct zx_b12_Correlation_s);
  x->gg.g.tok = zx_b12_Correlation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b12_Correlation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->messageID);
  zx_dup_attr(c, x->refToMessageID);
  zx_dup_attr(c, x->timestamp);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b12_Correlation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b12_Correlation_s* zx_DEEP_CLONE_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x, int dup_strs)
{
  x = (struct zx_b12_Correlation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b12_Correlation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->messageID = zx_clone_attr(c, x->messageID);
  x->refToMessageID = zx_clone_attr(c, x->refToMessageID);
  x->timestamp = zx_clone_attr(c, x->timestamp);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b12_Correlation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b12_Correlation) */

int zx_WALK_WO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b12_ProcessingContext
#define EL_STRUCT zx_b12_ProcessingContext_s
#define EL_NS     b12
#define EL_TAG    ProcessingContext

/* FUNC(zx_FREE_b12_ProcessingContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b12_ProcessingContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b12_ProcessingContext_s* zx_NEW_b12_ProcessingContext(struct zx_ctx* c)
{
  struct zx_b12_ProcessingContext_s* x = ZX_ZALLOC(c, struct zx_b12_ProcessingContext_s);
  x->gg.g.tok = zx_b12_ProcessingContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b12_ProcessingContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b12_ProcessingContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b12_ProcessingContext_s* zx_DEEP_CLONE_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x, int dup_strs)
{
  x = (struct zx_b12_ProcessingContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b12_ProcessingContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b12_ProcessingContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b12_ProcessingContext) */

int zx_WALK_WO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b12_Provider
#define EL_STRUCT zx_b12_Provider_s
#define EL_NS     b12
#define EL_TAG    Provider

/* FUNC(zx_FREE_b12_Provider) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->affiliationID, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->providerID, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b12_Provider) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b12_Provider_s* zx_NEW_b12_Provider(struct zx_ctx* c)
{
  struct zx_b12_Provider_s* x = ZX_ZALLOC(c, struct zx_b12_Provider_s);
  x->gg.g.tok = zx_b12_Provider_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b12_Provider) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->affiliationID);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->providerID);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b12_Provider) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b12_Provider_s* zx_DEEP_CLONE_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x, int dup_strs)
{
  x = (struct zx_b12_Provider_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b12_Provider_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->affiliationID = zx_clone_attr(c, x->affiliationID);
  x->id = zx_clone_attr(c, x->id);
  x->providerID = zx_clone_attr(c, x->providerID);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b12_Provider) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b12_Provider) */

int zx_WALK_WO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   b12_UsageDirective
#define EL_STRUCT zx_b12_UsageDirective_s
#define EL_NS     b12
#define EL_TAG    UsageDirective

/* FUNC(zx_FREE_b12_UsageDirective) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->ref, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_b12_UsageDirective) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_b12_UsageDirective_s* zx_NEW_b12_UsageDirective(struct zx_ctx* c)
{
  struct zx_b12_UsageDirective_s* x = ZX_ZALLOC(c, struct zx_b12_UsageDirective_s);
  x->gg.g.tok = zx_b12_UsageDirective_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_b12_UsageDirective) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->ref);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_b12_UsageDirective) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_b12_UsageDirective_s* zx_DEEP_CLONE_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x, int dup_strs)
{
  x = (struct zx_b12_UsageDirective_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_b12_UsageDirective_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->ref = zx_clone_attr(c, x->ref);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_b12_UsageDirective) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_b12_UsageDirective) */

int zx_WALK_WO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-b12-aux.c */
