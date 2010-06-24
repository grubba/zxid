/* c/zx-xasacd1-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xasacd1-data.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   xasacd1_ReferencedPolicies
#define EL_STRUCT zx_xasacd1_ReferencedPolicies_s
#define EL_NS     xasacd1
#define EL_TAG    ReferencedPolicies

/* FUNC(zx_FREE_xasacd1_ReferencedPolicies) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Policy_s* e;
      struct zx_xa_Policy_s* en;
      for (e = x->Policy; e; e = en) {
	  en = (struct zx_xa_Policy_s*)e->gg.g.n;
	  zx_FREE_xa_Policy(c, e, free_strs);
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


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xasacd1_ReferencedPolicies) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xasacd1_ReferencedPolicies_s* zx_NEW_xasacd1_ReferencedPolicies(struct zx_ctx* c)
{
  struct zx_xasacd1_ReferencedPolicies_s* x = ZX_ZALLOC(c, struct zx_xasacd1_ReferencedPolicies_s);
  x->gg.g.tok = zx_xasacd1_ReferencedPolicies_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xasacd1_ReferencedPolicies) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicySet(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xasacd1_ReferencedPolicies) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xasacd1_ReferencedPolicies_s* zx_DEEP_CLONE_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x, int dup_strs)
{
  x = (struct zx_xasacd1_ReferencedPolicies_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xasacd1_ReferencedPolicies_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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

  return x;
}

/* FUNC(zx_WALK_SO_xasacd1_ReferencedPolicies) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Policy(c, e, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xasacd1_ReferencedPolicies) */

int zx_WALK_WO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   xasacd1_XACMLAuthzDecisionStatement
#define EL_STRUCT zx_xasacd1_XACMLAuthzDecisionStatement_s
#define EL_NS     xasacd1
#define EL_TAG    XACMLAuthzDecisionStatement

/* FUNC(zx_FREE_xasacd1_XACMLAuthzDecisionStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xac_Response_s* e;
      struct zx_xac_Response_s* en;
      for (e = x->Response; e; e = en) {
	  en = (struct zx_xac_Response_s*)e->gg.g.n;
	  zx_FREE_xac_Response(c, e, free_strs);
      }
  }
  {
      struct zx_xac_Request_s* e;
      struct zx_xac_Request_s* en;
      for (e = x->Request; e; e = en) {
	  en = (struct zx_xac_Request_s*)e->gg.g.n;
	  zx_FREE_xac_Request(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xasacd1_XACMLAuthzDecisionStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xasacd1_XACMLAuthzDecisionStatement_s* zx_NEW_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x = ZX_ZALLOC(c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s);
  x->gg.g.tok = zx_xasacd1_XACMLAuthzDecisionStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xasacd1_XACMLAuthzDecisionStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xac_Response_s* e;
      for (e = x->Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_xac_Response(c, e);
  }
  {
      struct zx_xac_Request_s* e;
      for (e = x->Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  zx_DUP_STRS_xac_Request(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xasacd1_XACMLAuthzDecisionStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xasacd1_XACMLAuthzDecisionStatement_s* zx_DEEP_CLONE_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x, int dup_strs)
{
  x = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xasacd1_XACMLAuthzDecisionStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xac_Response_s* e;
      struct zx_xac_Response_s* en;
      struct zx_xac_Response_s* enn;
      for (enn = 0, e = x->Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xac_Response(c, e, dup_strs);
	  if (!enn)
	      x->Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xac_Request_s* e;
      struct zx_xac_Request_s* en;
      struct zx_xac_Request_s* enn;
      for (enn = 0, e = x->Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xac_Request(c, e, dup_strs);
	  if (!enn)
	      x->Request = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xasacd1_XACMLAuthzDecisionStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xac_Response_s* e;
      for (e = x->Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xac_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xac_Request_s* e;
      for (e = x->Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xac_Request(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xasacd1_XACMLAuthzDecisionStatement) */

int zx_WALK_WO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   xasacd1_XACMLPolicyStatement
#define EL_STRUCT zx_xasacd1_XACMLPolicyStatement_s
#define EL_NS     xasacd1
#define EL_TAG    XACMLPolicyStatement

/* FUNC(zx_FREE_xasacd1_XACMLPolicyStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Policy_s* e;
      struct zx_xa_Policy_s* en;
      for (e = x->Policy; e; e = en) {
	  en = (struct zx_xa_Policy_s*)e->gg.g.n;
	  zx_FREE_xa_Policy(c, e, free_strs);
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
      struct zx_xasacd1_ReferencedPolicies_s* e;
      struct zx_xasacd1_ReferencedPolicies_s* en;
      for (e = x->ReferencedPolicies; e; e = en) {
	  en = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n;
	  zx_FREE_xasacd1_ReferencedPolicies(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xasacd1_XACMLPolicyStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xasacd1_XACMLPolicyStatement_s* zx_NEW_xasacd1_XACMLPolicyStatement(struct zx_ctx* c)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* x = ZX_ZALLOC(c, struct zx_xasacd1_XACMLPolicyStatement_s);
  x->gg.g.tok = zx_xasacd1_XACMLPolicyStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xasacd1_XACMLPolicyStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicySet(c, e);
  }
  {
      struct zx_xasacd1_ReferencedPolicies_s* e;
      for (e = x->ReferencedPolicies; e; e = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n)
	  zx_DUP_STRS_xasacd1_ReferencedPolicies(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xasacd1_XACMLPolicyStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xasacd1_XACMLPolicyStatement_s* zx_DEEP_CLONE_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x, int dup_strs)
{
  x = (struct zx_xasacd1_XACMLPolicyStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xasacd1_XACMLPolicyStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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
      struct zx_xasacd1_ReferencedPolicies_s* e;
      struct zx_xasacd1_ReferencedPolicies_s* en;
      struct zx_xasacd1_ReferencedPolicies_s* enn;
      for (enn = 0, e = x->ReferencedPolicies; e; e = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasacd1_ReferencedPolicies(c, e, dup_strs);
	  if (!enn)
	      x->ReferencedPolicies = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xasacd1_XACMLPolicyStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Policy(c, e, ctx, callback);
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
      struct zx_xasacd1_ReferencedPolicies_s* e;
      for (e = x->ReferencedPolicies; e; e = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasacd1_ReferencedPolicies(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xasacd1_XACMLPolicyStatement) */

int zx_WALK_WO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-xasacd1-aux.c */
