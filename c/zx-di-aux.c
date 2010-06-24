/* c/zx-di-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-di-data.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   di_EndpointContext
#define EL_STRUCT zx_di_EndpointContext_s
#define EL_NS     di
#define EL_TAG    EndpointContext

/* FUNC(zx_FREE_di_EndpointContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_EndpointContext(struct zx_ctx* c, struct zx_di_EndpointContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Address, free_strs);
  {
      struct zx_sbf_Framework_s* e;
      struct zx_sbf_Framework_s* en;
      for (e = x->Framework; e; e = en) {
	  en = (struct zx_sbf_Framework_s*)e->gg.g.n;
	  zx_FREE_sbf_Framework(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SecurityMechID, free_strs);
  zx_free_simple_elems(c, x->Action, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_EndpointContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_EndpointContext_s* zx_NEW_di_EndpointContext(struct zx_ctx* c)
{
  struct zx_di_EndpointContext_s* x = ZX_ZALLOC(c, struct zx_di_EndpointContext_s);
  x->gg.g.tok = zx_di_EndpointContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_EndpointContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_EndpointContext(struct zx_ctx* c, struct zx_di_EndpointContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Address);
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n)
	  zx_DUP_STRS_sbf_Framework(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SecurityMechID);
  zx_dup_strs_simple_elems(c, x->Action);

}

/* FUNC(zx_DEEP_CLONE_di_EndpointContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_EndpointContext_s* zx_DEEP_CLONE_di_EndpointContext(struct zx_ctx* c, struct zx_di_EndpointContext_s* x, int dup_strs)
{
  x = (struct zx_di_EndpointContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_EndpointContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Address = zx_deep_clone_simple_elems(c,x->Address, dup_strs);
  {
      struct zx_sbf_Framework_s* e;
      struct zx_sbf_Framework_s* en;
      struct zx_sbf_Framework_s* enn;
      for (enn = 0, e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sbf_Framework(c, e, dup_strs);
	  if (!enn)
	      x->Framework = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);
  x->Action = zx_deep_clone_simple_elems(c,x->Action, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_EndpointContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_EndpointContext(struct zx_ctx* c, struct zx_di_EndpointContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Address, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sbf_Framework(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SecurityMechID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Action, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_EndpointContext) */

int zx_WALK_WO_di_EndpointContext(struct zx_ctx* c, struct zx_di_EndpointContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_Framework
#define EL_STRUCT zx_di_Framework_s
#define EL_NS     di
#define EL_TAG    Framework

/* FUNC(zx_FREE_di_Framework) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_Framework(struct zx_ctx* c, struct zx_di_Framework_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->version, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_Framework) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_Framework_s* zx_NEW_di_Framework(struct zx_ctx* c)
{
  struct zx_di_Framework_s* x = ZX_ZALLOC(c, struct zx_di_Framework_s);
  x->gg.g.tok = zx_di_Framework_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_Framework) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_Framework(struct zx_ctx* c, struct zx_di_Framework_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->version);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_di_Framework) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_Framework_s* zx_DEEP_CLONE_di_Framework(struct zx_ctx* c, struct zx_di_Framework_s* x, int dup_strs)
{
  x = (struct zx_di_Framework_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_Framework_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->version = zx_clone_attr(c, x->version);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_di_Framework) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_Framework(struct zx_ctx* c, struct zx_di_Framework_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di_Framework) */

int zx_WALK_WO_di_Framework(struct zx_ctx* c, struct zx_di_Framework_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_Keys
#define EL_STRUCT zx_di_Keys_s
#define EL_NS     di
#define EL_TAG    Keys

/* FUNC(zx_FREE_di_Keys) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_Keys(struct zx_ctx* c, struct zx_di_Keys_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


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

/* FUNC(zx_NEW_di_Keys) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_Keys_s* zx_NEW_di_Keys(struct zx_ctx* c)
{
  struct zx_di_Keys_s* x = ZX_ZALLOC(c, struct zx_di_Keys_s);
  x->gg.g.tok = zx_di_Keys_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_Keys) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_Keys(struct zx_ctx* c, struct zx_di_Keys_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_KeyDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_Keys) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_Keys_s* zx_DEEP_CLONE_di_Keys(struct zx_ctx* c, struct zx_di_Keys_s* x, int dup_strs)
{
  x = (struct zx_di_Keys_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_Keys_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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

/* FUNC(zx_WALK_SO_di_Keys) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_Keys(struct zx_ctx* c, struct zx_di_Keys_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
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

/* FUNC(zx_WALK_WO_di_Keys) */

int zx_WALK_WO_di_Keys(struct zx_ctx* c, struct zx_di_Keys_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_Options
#define EL_STRUCT zx_di_Options_s
#define EL_NS     di
#define EL_TAG    Options

/* FUNC(zx_FREE_di_Options) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_Options(struct zx_ctx* c, struct zx_di_Options_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Option, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_Options) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_Options_s* zx_NEW_di_Options(struct zx_ctx* c)
{
  struct zx_di_Options_s* x = ZX_ZALLOC(c, struct zx_di_Options_s);
  x->gg.g.tok = zx_di_Options_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_Options) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_Options(struct zx_ctx* c, struct zx_di_Options_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Option);

}

/* FUNC(zx_DEEP_CLONE_di_Options) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_Options_s* zx_DEEP_CLONE_di_Options(struct zx_ctx* c, struct zx_di_Options_s* x, int dup_strs)
{
  x = (struct zx_di_Options_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_Options_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Option = zx_deep_clone_simple_elems(c,x->Option, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_Options) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_Options(struct zx_ctx* c, struct zx_di_Options_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di_Options) */

int zx_WALK_WO_di_Options(struct zx_ctx* c, struct zx_di_Options_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_Query
#define EL_STRUCT zx_di_Query_s
#define EL_NS     di
#define EL_TAG    Query

/* FUNC(zx_FREE_di_Query) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_Query(struct zx_ctx* c, struct zx_di_Query_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_RequestedService_s* e;
      struct zx_di_RequestedService_s* en;
      for (e = x->RequestedService; e; e = en) {
	  en = (struct zx_di_RequestedService_s*)e->gg.g.n;
	  zx_FREE_di_RequestedService(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_Query) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_Query_s* zx_NEW_di_Query(struct zx_ctx* c)
{
  struct zx_di_Query_s* x = ZX_ZALLOC(c, struct zx_di_Query_s);
  x->gg.g.tok = zx_di_Query_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_Query) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_Query(struct zx_ctx* c, struct zx_di_Query_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_RequestedService_s* e;
      for (e = x->RequestedService; e; e = (struct zx_di_RequestedService_s*)e->gg.g.n)
	  zx_DUP_STRS_di_RequestedService(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_Query) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_Query_s* zx_DEEP_CLONE_di_Query(struct zx_ctx* c, struct zx_di_Query_s* x, int dup_strs)
{
  x = (struct zx_di_Query_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_Query_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_RequestedService_s* e;
      struct zx_di_RequestedService_s* en;
      struct zx_di_RequestedService_s* enn;
      for (enn = 0, e = x->RequestedService; e; e = (struct zx_di_RequestedService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_RequestedService(c, e, dup_strs);
	  if (!enn)
	      x->RequestedService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_Query) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_Query(struct zx_ctx* c, struct zx_di_Query_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di_RequestedService_s* e;
      for (e = x->RequestedService; e; e = (struct zx_di_RequestedService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_RequestedService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_Query) */

int zx_WALK_WO_di_Query(struct zx_ctx* c, struct zx_di_Query_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_QueryResponse
#define EL_STRUCT zx_di_QueryResponse_s
#define EL_NS     di
#define EL_TAG    QueryResponse

/* FUNC(zx_FREE_di_QueryResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_QueryResponse(struct zx_ctx* c, struct zx_di_QueryResponse_s* x, int free_strs)
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
      struct zx_a_EndpointReference_s* e;
      struct zx_a_EndpointReference_s* en;
      for (e = x->EndpointReference; e; e = en) {
	  en = (struct zx_a_EndpointReference_s*)e->gg.g.n;
	  zx_FREE_a_EndpointReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_QueryResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_QueryResponse_s* zx_NEW_di_QueryResponse(struct zx_ctx* c)
{
  struct zx_di_QueryResponse_s* x = ZX_ZALLOC(c, struct zx_di_QueryResponse_s);
  x->gg.g.tok = zx_di_QueryResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_QueryResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_QueryResponse(struct zx_ctx* c, struct zx_di_QueryResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  zx_DUP_STRS_a_EndpointReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_QueryResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_QueryResponse_s* zx_DEEP_CLONE_di_QueryResponse(struct zx_ctx* c, struct zx_di_QueryResponse_s* x, int dup_strs)
{
  x = (struct zx_di_QueryResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_QueryResponse_s), dup_strs);
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
      struct zx_a_EndpointReference_s* e;
      struct zx_a_EndpointReference_s* en;
      struct zx_a_EndpointReference_s* enn;
      for (enn = 0, e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_EndpointReference(c, e, dup_strs);
	  if (!enn)
	      x->EndpointReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_QueryResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_QueryResponse(struct zx_ctx* c, struct zx_di_QueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_EndpointReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_QueryResponse) */

int zx_WALK_WO_di_QueryResponse(struct zx_ctx* c, struct zx_di_QueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_RequestedService
#define EL_STRUCT zx_di_RequestedService_s
#define EL_NS     di
#define EL_TAG    RequestedService

/* FUNC(zx_FREE_di_RequestedService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_RequestedService(struct zx_ctx* c, struct zx_di_RequestedService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->reqID, free_strs);
  zx_free_attr(c, x->resultsType, free_strs);

  zx_free_simple_elems(c, x->ServiceType, free_strs);
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_di_Options_s* e;
      struct zx_di_Options_s* en;
      for (e = x->Options; e; e = en) {
	  en = (struct zx_di_Options_s*)e->gg.g.n;
	  zx_FREE_di_Options(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SecurityMechID, free_strs);
  {
      struct zx_di_Framework_s* e;
      struct zx_di_Framework_s* en;
      for (e = x->Framework; e; e = en) {
	  en = (struct zx_di_Framework_s*)e->gg.g.n;
	  zx_FREE_di_Framework(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Action, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_RequestedService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_RequestedService_s* zx_NEW_di_RequestedService(struct zx_ctx* c)
{
  struct zx_di_RequestedService_s* x = ZX_ZALLOC(c, struct zx_di_RequestedService_s);
  x->gg.g.tok = zx_di_RequestedService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_RequestedService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_RequestedService(struct zx_ctx* c, struct zx_di_RequestedService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->reqID);
  zx_dup_attr(c, x->resultsType);

  zx_dup_strs_simple_elems(c, x->ServiceType);
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_di_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di_Options_s*)e->gg.g.n)
	  zx_DUP_STRS_di_Options(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SecurityMechID);
  {
      struct zx_di_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_di_Framework_s*)e->gg.g.n)
	  zx_DUP_STRS_di_Framework(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Action);

}

/* FUNC(zx_DEEP_CLONE_di_RequestedService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_RequestedService_s* zx_DEEP_CLONE_di_RequestedService(struct zx_ctx* c, struct zx_di_RequestedService_s* x, int dup_strs)
{
  x = (struct zx_di_RequestedService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_RequestedService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->reqID = zx_clone_attr(c, x->reqID);
  x->resultsType = zx_clone_attr(c, x->resultsType);

  x->ServiceType = zx_deep_clone_simple_elems(c,x->ServiceType, dup_strs);
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  {
      struct zx_di_Options_s* e;
      struct zx_di_Options_s* en;
      struct zx_di_Options_s* enn;
      for (enn = 0, e = x->Options; e; e = (struct zx_di_Options_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_Options(c, e, dup_strs);
	  if (!enn)
	      x->Options = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);
  {
      struct zx_di_Framework_s* e;
      struct zx_di_Framework_s* en;
      struct zx_di_Framework_s* enn;
      for (enn = 0, e = x->Framework; e; e = (struct zx_di_Framework_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_Framework(c, e, dup_strs);
	  if (!enn)
	      x->Framework = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Action = zx_deep_clone_simple_elems(c,x->Action, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_RequestedService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_RequestedService(struct zx_ctx* c, struct zx_di_RequestedService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_di_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di_Options_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_Options(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SecurityMechID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_di_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_di_Framework_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_Framework(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Action, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_RequestedService) */

int zx_WALK_WO_di_RequestedService(struct zx_ctx* c, struct zx_di_RequestedService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SecurityContext
#define EL_STRUCT zx_di_SecurityContext_s
#define EL_NS     di
#define EL_TAG    SecurityContext

/* FUNC(zx_FREE_di_SecurityContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SecurityContext(struct zx_ctx* c, struct zx_di_SecurityContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SecurityMechID, free_strs);
  {
      struct zx_sec_Token_s* e;
      struct zx_sec_Token_s* en;
      for (e = x->Token; e; e = en) {
	  en = (struct zx_sec_Token_s*)e->gg.g.n;
	  zx_FREE_sec_Token(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SecurityContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SecurityContext_s* zx_NEW_di_SecurityContext(struct zx_ctx* c)
{
  struct zx_di_SecurityContext_s* x = ZX_ZALLOC(c, struct zx_di_SecurityContext_s);
  x->gg.g.tok = zx_di_SecurityContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SecurityContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SecurityContext(struct zx_ctx* c, struct zx_di_SecurityContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SecurityMechID);
  {
      struct zx_sec_Token_s* e;
      for (e = x->Token; e; e = (struct zx_sec_Token_s*)e->gg.g.n)
	  zx_DUP_STRS_sec_Token(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SecurityContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SecurityContext_s* zx_DEEP_CLONE_di_SecurityContext(struct zx_ctx* c, struct zx_di_SecurityContext_s* x, int dup_strs)
{
  x = (struct zx_di_SecurityContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SecurityContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);
  {
      struct zx_sec_Token_s* e;
      struct zx_sec_Token_s* en;
      struct zx_sec_Token_s* enn;
      for (enn = 0, e = x->Token; e; e = (struct zx_sec_Token_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec_Token(c, e, dup_strs);
	  if (!enn)
	      x->Token = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_SecurityContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SecurityContext(struct zx_ctx* c, struct zx_di_SecurityContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_sec_Token_s* e;
      for (e = x->Token; e; e = (struct zx_sec_Token_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec_Token(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SecurityContext) */

int zx_WALK_WO_di_SecurityContext(struct zx_ctx* c, struct zx_di_SecurityContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_ServiceContext
#define EL_STRUCT zx_di_ServiceContext_s
#define EL_NS     di
#define EL_TAG    ServiceContext

/* FUNC(zx_FREE_di_ServiceContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_ServiceContext(struct zx_ctx* c, struct zx_di_ServiceContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->ServiceType, free_strs);
  {
      struct zx_di_Options_s* e;
      struct zx_di_Options_s* en;
      for (e = x->Options; e; e = en) {
	  en = (struct zx_di_Options_s*)e->gg.g.n;
	  zx_FREE_di_Options(c, e, free_strs);
      }
  }
  {
      struct zx_di_EndpointContext_s* e;
      struct zx_di_EndpointContext_s* en;
      for (e = x->EndpointContext; e; e = en) {
	  en = (struct zx_di_EndpointContext_s*)e->gg.g.n;
	  zx_FREE_di_EndpointContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_ServiceContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_ServiceContext_s* zx_NEW_di_ServiceContext(struct zx_ctx* c)
{
  struct zx_di_ServiceContext_s* x = ZX_ZALLOC(c, struct zx_di_ServiceContext_s);
  x->gg.g.tok = zx_di_ServiceContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_ServiceContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_ServiceContext(struct zx_ctx* c, struct zx_di_ServiceContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->ServiceType);
  {
      struct zx_di_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di_Options_s*)e->gg.g.n)
	  zx_DUP_STRS_di_Options(c, e);
  }
  {
      struct zx_di_EndpointContext_s* e;
      for (e = x->EndpointContext; e; e = (struct zx_di_EndpointContext_s*)e->gg.g.n)
	  zx_DUP_STRS_di_EndpointContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_ServiceContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_ServiceContext_s* zx_DEEP_CLONE_di_ServiceContext(struct zx_ctx* c, struct zx_di_ServiceContext_s* x, int dup_strs)
{
  x = (struct zx_di_ServiceContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_ServiceContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->ServiceType = zx_deep_clone_simple_elems(c,x->ServiceType, dup_strs);
  {
      struct zx_di_Options_s* e;
      struct zx_di_Options_s* en;
      struct zx_di_Options_s* enn;
      for (enn = 0, e = x->Options; e; e = (struct zx_di_Options_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_Options(c, e, dup_strs);
	  if (!enn)
	      x->Options = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_EndpointContext_s* e;
      struct zx_di_EndpointContext_s* en;
      struct zx_di_EndpointContext_s* enn;
      for (enn = 0, e = x->EndpointContext; e; e = (struct zx_di_EndpointContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_EndpointContext(c, e, dup_strs);
	  if (!enn)
	      x->EndpointContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_ServiceContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_ServiceContext(struct zx_ctx* c, struct zx_di_ServiceContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_di_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di_Options_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_Options(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_EndpointContext_s* e;
      for (e = x->EndpointContext; e; e = (struct zx_di_EndpointContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_EndpointContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_ServiceContext) */

int zx_WALK_WO_di_ServiceContext(struct zx_ctx* c, struct zx_di_ServiceContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMD
#define EL_STRUCT zx_di_SvcMD_s
#define EL_NS     di
#define EL_TAG    SvcMD

/* FUNC(zx_FREE_di_SvcMD) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMD(struct zx_ctx* c, struct zx_di_SvcMD_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->svcMDID, free_strs);

  zx_free_simple_elems(c, x->Abstract, free_strs);
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_di_ServiceContext_s* e;
      struct zx_di_ServiceContext_s* en;
      for (e = x->ServiceContext; e; e = en) {
	  en = (struct zx_di_ServiceContext_s*)e->gg.g.n;
	  zx_FREE_di_ServiceContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMD) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMD_s* zx_NEW_di_SvcMD(struct zx_ctx* c)
{
  struct zx_di_SvcMD_s* x = ZX_ZALLOC(c, struct zx_di_SvcMD_s);
  x->gg.g.tok = zx_di_SvcMD_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMD) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMD(struct zx_ctx* c, struct zx_di_SvcMD_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->svcMDID);

  zx_dup_strs_simple_elems(c, x->Abstract);
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_di_ServiceContext_s* e;
      for (e = x->ServiceContext; e; e = (struct zx_di_ServiceContext_s*)e->gg.g.n)
	  zx_DUP_STRS_di_ServiceContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMD) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMD_s* zx_DEEP_CLONE_di_SvcMD(struct zx_ctx* c, struct zx_di_SvcMD_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMD_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMD_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->svcMDID = zx_clone_attr(c, x->svcMDID);

  x->Abstract = zx_deep_clone_simple_elems(c,x->Abstract, dup_strs);
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  {
      struct zx_di_ServiceContext_s* e;
      struct zx_di_ServiceContext_s* en;
      struct zx_di_ServiceContext_s* enn;
      for (enn = 0, e = x->ServiceContext; e; e = (struct zx_di_ServiceContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_ServiceContext(c, e, dup_strs);
	  if (!enn)
	      x->ServiceContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMD) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMD(struct zx_ctx* c, struct zx_di_SvcMD_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Abstract, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_di_ServiceContext_s* e;
      for (e = x->ServiceContext; e; e = (struct zx_di_ServiceContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_ServiceContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMD) */

int zx_WALK_WO_di_SvcMD(struct zx_ctx* c, struct zx_di_SvcMD_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDAssociationAdd
#define EL_STRUCT zx_di_SvcMDAssociationAdd_s
#define EL_NS     di
#define EL_TAG    SvcMDAssociationAdd

/* FUNC(zx_FREE_di_SvcMDAssociationAdd) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDAssociationAdd(struct zx_ctx* c, struct zx_di_SvcMDAssociationAdd_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SvcMDID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDAssociationAdd) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDAssociationAdd_s* zx_NEW_di_SvcMDAssociationAdd(struct zx_ctx* c)
{
  struct zx_di_SvcMDAssociationAdd_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDAssociationAdd_s);
  x->gg.g.tok = zx_di_SvcMDAssociationAdd_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDAssociationAdd) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDAssociationAdd(struct zx_ctx* c, struct zx_di_SvcMDAssociationAdd_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SvcMDID);

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDAssociationAdd) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDAssociationAdd_s* zx_DEEP_CLONE_di_SvcMDAssociationAdd(struct zx_ctx* c, struct zx_di_SvcMDAssociationAdd_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDAssociationAdd_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDAssociationAdd_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDAssociationAdd) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDAssociationAdd(struct zx_ctx* c, struct zx_di_SvcMDAssociationAdd_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDAssociationAdd) */

int zx_WALK_WO_di_SvcMDAssociationAdd(struct zx_ctx* c, struct zx_di_SvcMDAssociationAdd_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDAssociationAddResponse
#define EL_STRUCT zx_di_SvcMDAssociationAddResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDAssociationAddResponse

/* FUNC(zx_FREE_di_SvcMDAssociationAddResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDAssociationAddResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationAddResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_di_SvcMDAssociationAddResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDAssociationAddResponse_s* zx_NEW_di_SvcMDAssociationAddResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDAssociationAddResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDAssociationAddResponse_s);
  x->gg.g.tok = zx_di_SvcMDAssociationAddResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDAssociationAddResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDAssociationAddResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationAddResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDAssociationAddResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDAssociationAddResponse_s* zx_DEEP_CLONE_di_SvcMDAssociationAddResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationAddResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDAssociationAddResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDAssociationAddResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_di_SvcMDAssociationAddResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDAssociationAddResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationAddResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di_SvcMDAssociationAddResponse) */

int zx_WALK_WO_di_SvcMDAssociationAddResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationAddResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDAssociationDelete
#define EL_STRUCT zx_di_SvcMDAssociationDelete_s
#define EL_NS     di
#define EL_TAG    SvcMDAssociationDelete

/* FUNC(zx_FREE_di_SvcMDAssociationDelete) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDAssociationDelete(struct zx_ctx* c, struct zx_di_SvcMDAssociationDelete_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SvcMDID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDAssociationDelete) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDAssociationDelete_s* zx_NEW_di_SvcMDAssociationDelete(struct zx_ctx* c)
{
  struct zx_di_SvcMDAssociationDelete_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDAssociationDelete_s);
  x->gg.g.tok = zx_di_SvcMDAssociationDelete_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDAssociationDelete) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDAssociationDelete(struct zx_ctx* c, struct zx_di_SvcMDAssociationDelete_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SvcMDID);

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDAssociationDelete) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDAssociationDelete_s* zx_DEEP_CLONE_di_SvcMDAssociationDelete(struct zx_ctx* c, struct zx_di_SvcMDAssociationDelete_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDAssociationDelete_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDAssociationDelete_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDAssociationDelete) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDAssociationDelete(struct zx_ctx* c, struct zx_di_SvcMDAssociationDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDAssociationDelete) */

int zx_WALK_WO_di_SvcMDAssociationDelete(struct zx_ctx* c, struct zx_di_SvcMDAssociationDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDAssociationDeleteResponse
#define EL_STRUCT zx_di_SvcMDAssociationDeleteResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDAssociationDeleteResponse

/* FUNC(zx_FREE_di_SvcMDAssociationDeleteResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDAssociationDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationDeleteResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_di_SvcMDAssociationDeleteResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDAssociationDeleteResponse_s* zx_NEW_di_SvcMDAssociationDeleteResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDAssociationDeleteResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDAssociationDeleteResponse_s);
  x->gg.g.tok = zx_di_SvcMDAssociationDeleteResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDAssociationDeleteResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDAssociationDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationDeleteResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDAssociationDeleteResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDAssociationDeleteResponse_s* zx_DEEP_CLONE_di_SvcMDAssociationDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationDeleteResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDAssociationDeleteResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDAssociationDeleteResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_di_SvcMDAssociationDeleteResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDAssociationDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di_SvcMDAssociationDeleteResponse) */

int zx_WALK_WO_di_SvcMDAssociationDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDAssociationQuery
#define EL_STRUCT zx_di_SvcMDAssociationQuery_s
#define EL_NS     di
#define EL_TAG    SvcMDAssociationQuery

/* FUNC(zx_FREE_di_SvcMDAssociationQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDAssociationQuery(struct zx_ctx* c, struct zx_di_SvcMDAssociationQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SvcMDID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDAssociationQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDAssociationQuery_s* zx_NEW_di_SvcMDAssociationQuery(struct zx_ctx* c)
{
  struct zx_di_SvcMDAssociationQuery_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDAssociationQuery_s);
  x->gg.g.tok = zx_di_SvcMDAssociationQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDAssociationQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDAssociationQuery(struct zx_ctx* c, struct zx_di_SvcMDAssociationQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SvcMDID);

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDAssociationQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDAssociationQuery_s* zx_DEEP_CLONE_di_SvcMDAssociationQuery(struct zx_ctx* c, struct zx_di_SvcMDAssociationQuery_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDAssociationQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDAssociationQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDAssociationQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDAssociationQuery(struct zx_ctx* c, struct zx_di_SvcMDAssociationQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDAssociationQuery) */

int zx_WALK_WO_di_SvcMDAssociationQuery(struct zx_ctx* c, struct zx_di_SvcMDAssociationQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDAssociationQueryResponse
#define EL_STRUCT zx_di_SvcMDAssociationQueryResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDAssociationQueryResponse

/* FUNC(zx_FREE_di_SvcMDAssociationQueryResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDAssociationQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationQueryResponse_s* x, int free_strs)
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
  zx_free_simple_elems(c, x->SvcMDID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDAssociationQueryResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDAssociationQueryResponse_s* zx_NEW_di_SvcMDAssociationQueryResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDAssociationQueryResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDAssociationQueryResponse_s);
  x->gg.g.tok = zx_di_SvcMDAssociationQueryResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDAssociationQueryResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDAssociationQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationQueryResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SvcMDID);

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDAssociationQueryResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDAssociationQueryResponse_s* zx_DEEP_CLONE_di_SvcMDAssociationQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationQueryResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDAssociationQueryResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDAssociationQueryResponse_s), dup_strs);
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
  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDAssociationQueryResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDAssociationQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationQueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDAssociationQueryResponse) */

int zx_WALK_WO_di_SvcMDAssociationQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDAssociationQueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDDelete
#define EL_STRUCT zx_di_SvcMDDelete_s
#define EL_NS     di
#define EL_TAG    SvcMDDelete

/* FUNC(zx_FREE_di_SvcMDDelete) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDDelete(struct zx_ctx* c, struct zx_di_SvcMDDelete_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SvcMDID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDDelete) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDDelete_s* zx_NEW_di_SvcMDDelete(struct zx_ctx* c)
{
  struct zx_di_SvcMDDelete_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDDelete_s);
  x->gg.g.tok = zx_di_SvcMDDelete_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDDelete) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDDelete(struct zx_ctx* c, struct zx_di_SvcMDDelete_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SvcMDID);

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDDelete) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDDelete_s* zx_DEEP_CLONE_di_SvcMDDelete(struct zx_ctx* c, struct zx_di_SvcMDDelete_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDDelete_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDDelete_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDDelete) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDDelete(struct zx_ctx* c, struct zx_di_SvcMDDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDDelete) */

int zx_WALK_WO_di_SvcMDDelete(struct zx_ctx* c, struct zx_di_SvcMDDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDDeleteResponse
#define EL_STRUCT zx_di_SvcMDDeleteResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDDeleteResponse

/* FUNC(zx_FREE_di_SvcMDDeleteResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDDeleteResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_di_SvcMDDeleteResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDDeleteResponse_s* zx_NEW_di_SvcMDDeleteResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDDeleteResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDDeleteResponse_s);
  x->gg.g.tok = zx_di_SvcMDDeleteResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDDeleteResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDDeleteResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDDeleteResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDDeleteResponse_s* zx_DEEP_CLONE_di_SvcMDDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDDeleteResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDDeleteResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDDeleteResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_di_SvcMDDeleteResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di_SvcMDDeleteResponse) */

int zx_WALK_WO_di_SvcMDDeleteResponse(struct zx_ctx* c, struct zx_di_SvcMDDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDQuery
#define EL_STRUCT zx_di_SvcMDQuery_s
#define EL_NS     di
#define EL_TAG    SvcMDQuery

/* FUNC(zx_FREE_di_SvcMDQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDQuery(struct zx_ctx* c, struct zx_di_SvcMDQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SvcMDID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDQuery_s* zx_NEW_di_SvcMDQuery(struct zx_ctx* c)
{
  struct zx_di_SvcMDQuery_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDQuery_s);
  x->gg.g.tok = zx_di_SvcMDQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDQuery(struct zx_ctx* c, struct zx_di_SvcMDQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SvcMDID);

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDQuery_s* zx_DEEP_CLONE_di_SvcMDQuery(struct zx_ctx* c, struct zx_di_SvcMDQuery_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDQuery(struct zx_ctx* c, struct zx_di_SvcMDQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDQuery) */

int zx_WALK_WO_di_SvcMDQuery(struct zx_ctx* c, struct zx_di_SvcMDQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDQueryResponse
#define EL_STRUCT zx_di_SvcMDQueryResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDQueryResponse

/* FUNC(zx_FREE_di_SvcMDQueryResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDQueryResponse_s* x, int free_strs)
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
      struct zx_di_SvcMD_s* e;
      struct zx_di_SvcMD_s* en;
      for (e = x->SvcMD; e; e = en) {
	  en = (struct zx_di_SvcMD_s*)e->gg.g.n;
	  zx_FREE_di_SvcMD(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDQueryResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDQueryResponse_s* zx_NEW_di_SvcMDQueryResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDQueryResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDQueryResponse_s);
  x->gg.g.tok = zx_di_SvcMDQueryResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDQueryResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDQueryResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_di_SvcMD_s* e;
      for (e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMD(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDQueryResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDQueryResponse_s* zx_DEEP_CLONE_di_SvcMDQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDQueryResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDQueryResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDQueryResponse_s), dup_strs);
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
      struct zx_di_SvcMD_s* e;
      struct zx_di_SvcMD_s* en;
      struct zx_di_SvcMD_s* enn;
      for (enn = 0, e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMD(c, e, dup_strs);
	  if (!enn)
	      x->SvcMD = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDQueryResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDQueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_di_SvcMD_s* e;
      for (e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMD(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDQueryResponse) */

int zx_WALK_WO_di_SvcMDQueryResponse(struct zx_ctx* c, struct zx_di_SvcMDQueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDRegister
#define EL_STRUCT zx_di_SvcMDRegister_s
#define EL_NS     di
#define EL_TAG    SvcMDRegister

/* FUNC(zx_FREE_di_SvcMDRegister) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDRegister(struct zx_ctx* c, struct zx_di_SvcMDRegister_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_SvcMD_s* e;
      struct zx_di_SvcMD_s* en;
      for (e = x->SvcMD; e; e = en) {
	  en = (struct zx_di_SvcMD_s*)e->gg.g.n;
	  zx_FREE_di_SvcMD(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDRegister) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDRegister_s* zx_NEW_di_SvcMDRegister(struct zx_ctx* c)
{
  struct zx_di_SvcMDRegister_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDRegister_s);
  x->gg.g.tok = zx_di_SvcMDRegister_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDRegister) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDRegister(struct zx_ctx* c, struct zx_di_SvcMDRegister_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_SvcMD_s* e;
      for (e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMD(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDRegister) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDRegister_s* zx_DEEP_CLONE_di_SvcMDRegister(struct zx_ctx* c, struct zx_di_SvcMDRegister_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDRegister_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDRegister_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_SvcMD_s* e;
      struct zx_di_SvcMD_s* en;
      struct zx_di_SvcMD_s* enn;
      for (enn = 0, e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMD(c, e, dup_strs);
	  if (!enn)
	      x->SvcMD = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDRegister) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDRegister(struct zx_ctx* c, struct zx_di_SvcMDRegister_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di_SvcMD_s* e;
      for (e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMD(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDRegister) */

int zx_WALK_WO_di_SvcMDRegister(struct zx_ctx* c, struct zx_di_SvcMDRegister_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDRegisterResponse
#define EL_STRUCT zx_di_SvcMDRegisterResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDRegisterResponse

/* FUNC(zx_FREE_di_SvcMDRegisterResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDRegisterResponse(struct zx_ctx* c, struct zx_di_SvcMDRegisterResponse_s* x, int free_strs)
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
  zx_free_simple_elems(c, x->SvcMDID, free_strs);
  {
      struct zx_di_Keys_s* e;
      struct zx_di_Keys_s* en;
      for (e = x->Keys; e; e = en) {
	  en = (struct zx_di_Keys_s*)e->gg.g.n;
	  zx_FREE_di_Keys(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDRegisterResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDRegisterResponse_s* zx_NEW_di_SvcMDRegisterResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDRegisterResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDRegisterResponse_s);
  x->gg.g.tok = zx_di_SvcMDRegisterResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDRegisterResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDRegisterResponse(struct zx_ctx* c, struct zx_di_SvcMDRegisterResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SvcMDID);
  {
      struct zx_di_Keys_s* e;
      for (e = x->Keys; e; e = (struct zx_di_Keys_s*)e->gg.g.n)
	  zx_DUP_STRS_di_Keys(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDRegisterResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDRegisterResponse_s* zx_DEEP_CLONE_di_SvcMDRegisterResponse(struct zx_ctx* c, struct zx_di_SvcMDRegisterResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDRegisterResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDRegisterResponse_s), dup_strs);
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
  x->SvcMDID = zx_deep_clone_simple_elems(c,x->SvcMDID, dup_strs);
  {
      struct zx_di_Keys_s* e;
      struct zx_di_Keys_s* en;
      struct zx_di_Keys_s* enn;
      for (enn = 0, e = x->Keys; e; e = (struct zx_di_Keys_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_Keys(c, e, dup_strs);
	  if (!enn)
	      x->Keys = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDRegisterResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDRegisterResponse(struct zx_ctx* c, struct zx_di_SvcMDRegisterResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->SvcMDID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_di_Keys_s* e;
      for (e = x->Keys; e; e = (struct zx_di_Keys_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_Keys(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDRegisterResponse) */

int zx_WALK_WO_di_SvcMDRegisterResponse(struct zx_ctx* c, struct zx_di_SvcMDRegisterResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDReplace
#define EL_STRUCT zx_di_SvcMDReplace_s
#define EL_NS     di
#define EL_TAG    SvcMDReplace

/* FUNC(zx_FREE_di_SvcMDReplace) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDReplace(struct zx_ctx* c, struct zx_di_SvcMDReplace_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_SvcMD_s* e;
      struct zx_di_SvcMD_s* en;
      for (e = x->SvcMD; e; e = en) {
	  en = (struct zx_di_SvcMD_s*)e->gg.g.n;
	  zx_FREE_di_SvcMD(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_di_SvcMDReplace) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDReplace_s* zx_NEW_di_SvcMDReplace(struct zx_ctx* c)
{
  struct zx_di_SvcMDReplace_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDReplace_s);
  x->gg.g.tok = zx_di_SvcMDReplace_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDReplace) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDReplace(struct zx_ctx* c, struct zx_di_SvcMDReplace_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_SvcMD_s* e;
      for (e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMD(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDReplace) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDReplace_s* zx_DEEP_CLONE_di_SvcMDReplace(struct zx_ctx* c, struct zx_di_SvcMDReplace_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDReplace_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDReplace_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di_SvcMD_s* e;
      struct zx_di_SvcMD_s* en;
      struct zx_di_SvcMD_s* enn;
      for (enn = 0, e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMD(c, e, dup_strs);
	  if (!enn)
	      x->SvcMD = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_di_SvcMDReplace) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDReplace(struct zx_ctx* c, struct zx_di_SvcMDReplace_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_di_SvcMD_s* e;
      for (e = x->SvcMD; e; e = (struct zx_di_SvcMD_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMD(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_di_SvcMDReplace) */

int zx_WALK_WO_di_SvcMDReplace(struct zx_ctx* c, struct zx_di_SvcMDReplace_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   di_SvcMDReplaceResponse
#define EL_STRUCT zx_di_SvcMDReplaceResponse_s
#define EL_NS     di
#define EL_TAG    SvcMDReplaceResponse

/* FUNC(zx_FREE_di_SvcMDReplaceResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_di_SvcMDReplaceResponse(struct zx_ctx* c, struct zx_di_SvcMDReplaceResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_di_SvcMDReplaceResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_di_SvcMDReplaceResponse_s* zx_NEW_di_SvcMDReplaceResponse(struct zx_ctx* c)
{
  struct zx_di_SvcMDReplaceResponse_s* x = ZX_ZALLOC(c, struct zx_di_SvcMDReplaceResponse_s);
  x->gg.g.tok = zx_di_SvcMDReplaceResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_di_SvcMDReplaceResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_di_SvcMDReplaceResponse(struct zx_ctx* c, struct zx_di_SvcMDReplaceResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_di_SvcMDReplaceResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_di_SvcMDReplaceResponse_s* zx_DEEP_CLONE_di_SvcMDReplaceResponse(struct zx_ctx* c, struct zx_di_SvcMDReplaceResponse_s* x, int dup_strs)
{
  x = (struct zx_di_SvcMDReplaceResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_di_SvcMDReplaceResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_di_SvcMDReplaceResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_di_SvcMDReplaceResponse(struct zx_ctx* c, struct zx_di_SvcMDReplaceResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_di_SvcMDReplaceResponse) */

int zx_WALK_WO_di_SvcMDReplaceResponse(struct zx_ctx* c, struct zx_di_SvcMDReplaceResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-di-aux.c */
