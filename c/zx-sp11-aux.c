/* c/zx-sp11-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sp11-data.h"



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

#define EL_NAME   sp11_AttributeQuery
#define EL_STRUCT zx_sp11_AttributeQuery_s
#define EL_NS     sp11
#define EL_TAG    AttributeQuery

/* FUNC(zx_FREE_sp11_AttributeQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Resource, free_strs);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa11_Subject_s*)e->gg.g.n;
	  zx_FREE_sa11_Subject(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      struct zx_sa11_AttributeDesignator_s* en;
      for (e = x->AttributeDesignator; e; e = en) {
	  en = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n;
	  zx_FREE_sa11_AttributeDesignator(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_AttributeQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_AttributeQuery_s* zx_NEW_sp11_AttributeQuery(struct zx_ctx* c)
{
  struct zx_sp11_AttributeQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_AttributeQuery_s);
  x->gg.g.tok = zx_sp11_AttributeQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_AttributeQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Resource);

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      for (e = x->AttributeDesignator; e; e = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AttributeDesignator(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_AttributeQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_AttributeQuery_s* zx_DEEP_CLONE_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x, int dup_strs)
{
  x = (struct zx_sp11_AttributeQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_AttributeQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Resource = zx_clone_attr(c, x->Resource);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      struct zx_sa11_Subject_s* enn;
      for (enn = 0, e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Subject(c, e, dup_strs);
	  if (!enn)
	      x->Subject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      struct zx_sa11_AttributeDesignator_s* en;
      struct zx_sa11_AttributeDesignator_s* enn;
      for (enn = 0, e = x->AttributeDesignator; e; e = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AttributeDesignator(c, e, dup_strs);
	  if (!enn)
	      x->AttributeDesignator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_AttributeQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      for (e = x->AttributeDesignator; e; e = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AttributeDesignator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_AttributeQuery) */

int zx_WALK_WO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_AuthenticationQuery
#define EL_STRUCT zx_sp11_AuthenticationQuery_s
#define EL_NS     sp11
#define EL_TAG    AuthenticationQuery

/* FUNC(zx_FREE_sp11_AuthenticationQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AuthenticationMethod, free_strs);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa11_Subject_s*)e->gg.g.n;
	  zx_FREE_sa11_Subject(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_AuthenticationQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_AuthenticationQuery_s* zx_NEW_sp11_AuthenticationQuery(struct zx_ctx* c)
{
  struct zx_sp11_AuthenticationQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_AuthenticationQuery_s);
  x->gg.g.tok = zx_sp11_AuthenticationQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_AuthenticationQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AuthenticationMethod);

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_AuthenticationQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_AuthenticationQuery_s* zx_DEEP_CLONE_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x, int dup_strs)
{
  x = (struct zx_sp11_AuthenticationQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_AuthenticationQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AuthenticationMethod = zx_clone_attr(c, x->AuthenticationMethod);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      struct zx_sa11_Subject_s* enn;
      for (enn = 0, e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Subject(c, e, dup_strs);
	  if (!enn)
	      x->Subject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_AuthenticationQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_AuthenticationQuery) */

int zx_WALK_WO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_AuthorizationDecisionQuery
#define EL_STRUCT zx_sp11_AuthorizationDecisionQuery_s
#define EL_NS     sp11
#define EL_TAG    AuthorizationDecisionQuery

/* FUNC(zx_FREE_sp11_AuthorizationDecisionQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Resource, free_strs);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa11_Subject_s*)e->gg.g.n;
	  zx_FREE_sa11_Subject(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_Action_s* e;
      struct zx_sa11_Action_s* en;
      for (e = x->Action; e; e = en) {
	  en = (struct zx_sa11_Action_s*)e->gg.g.n;
	  zx_FREE_sa11_Action(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_Evidence_s* e;
      struct zx_sa11_Evidence_s* en;
      for (e = x->Evidence; e; e = en) {
	  en = (struct zx_sa11_Evidence_s*)e->gg.g.n;
	  zx_FREE_sa11_Evidence(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_AuthorizationDecisionQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_AuthorizationDecisionQuery_s* zx_NEW_sp11_AuthorizationDecisionQuery(struct zx_ctx* c)
{
  struct zx_sp11_AuthorizationDecisionQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_AuthorizationDecisionQuery_s);
  x->gg.g.tok = zx_sp11_AuthorizationDecisionQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_AuthorizationDecisionQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Resource);

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa11_Action_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Action(c, e);
  }
  {
      struct zx_sa11_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa11_Evidence_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Evidence(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_AuthorizationDecisionQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_AuthorizationDecisionQuery_s* zx_DEEP_CLONE_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x, int dup_strs)
{
  x = (struct zx_sp11_AuthorizationDecisionQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_AuthorizationDecisionQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Resource = zx_clone_attr(c, x->Resource);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      struct zx_sa11_Subject_s* enn;
      for (enn = 0, e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Subject(c, e, dup_strs);
	  if (!enn)
	      x->Subject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_Action_s* e;
      struct zx_sa11_Action_s* en;
      struct zx_sa11_Action_s* enn;
      for (enn = 0, e = x->Action; e; e = (struct zx_sa11_Action_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Action(c, e, dup_strs);
	  if (!enn)
	      x->Action = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_Evidence_s* e;
      struct zx_sa11_Evidence_s* en;
      struct zx_sa11_Evidence_s* enn;
      for (enn = 0, e = x->Evidence; e; e = (struct zx_sa11_Evidence_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Evidence(c, e, dup_strs);
	  if (!enn)
	      x->Evidence = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_AuthorizationDecisionQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa11_Action_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Action(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa11_Evidence_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Evidence(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_AuthorizationDecisionQuery) */

int zx_WALK_WO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_Request
#define EL_STRUCT zx_sp11_Request_s
#define EL_NS     sp11
#define EL_TAG    Request

/* FUNC(zx_FREE_sp11_Request) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->RequestID, free_strs);

  zx_free_simple_elems(c, x->RespondWith, free_strs);
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Query, free_strs);
  {
      struct zx_sp11_SubjectQuery_s* e;
      struct zx_sp11_SubjectQuery_s* en;
      for (e = x->SubjectQuery; e; e = en) {
	  en = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n;
	  zx_FREE_sp11_SubjectQuery(c, e, free_strs);
      }
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      struct zx_sp11_AuthenticationQuery_s* en;
      for (e = x->AuthenticationQuery; e; e = en) {
	  en = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n;
	  zx_FREE_sp11_AuthenticationQuery(c, e, free_strs);
      }
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      struct zx_sp11_AttributeQuery_s* en;
      for (e = x->AttributeQuery; e; e = en) {
	  en = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n;
	  zx_FREE_sp11_AttributeQuery(c, e, free_strs);
      }
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      struct zx_sp11_AuthorizationDecisionQuery_s* en;
      for (e = x->AuthorizationDecisionQuery; e; e = en) {
	  en = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n;
	  zx_FREE_sp11_AuthorizationDecisionQuery(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AssertionIDReference, free_strs);
  zx_free_simple_elems(c, x->AssertionArtifact, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_Request) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_Request_s* zx_NEW_sp11_Request(struct zx_ctx* c)
{
  struct zx_sp11_Request_s* x = ZX_ZALLOC(c, struct zx_sp11_Request_s);
  x->gg.g.tok = zx_sp11_Request_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_Request) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->RequestID);

  zx_dup_strs_simple_elems(c, x->RespondWith);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Query);
  {
      struct zx_sp11_SubjectQuery_s* e;
      for (e = x->SubjectQuery; e; e = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_SubjectQuery(c, e);
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      for (e = x->AuthenticationQuery; e; e = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_AuthenticationQuery(c, e);
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_AttributeQuery(c, e);
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      for (e = x->AuthorizationDecisionQuery; e; e = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_AuthorizationDecisionQuery(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AssertionIDReference);
  zx_dup_strs_simple_elems(c, x->AssertionArtifact);

}

/* FUNC(zx_DEEP_CLONE_sp11_Request) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_Request_s* zx_DEEP_CLONE_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x, int dup_strs)
{
  x = (struct zx_sp11_Request_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_Request_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->RequestID = zx_clone_attr(c, x->RequestID);

  x->RespondWith = zx_deep_clone_simple_elems(c,x->RespondWith, dup_strs);
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
  x->Query = zx_deep_clone_simple_elems(c,x->Query, dup_strs);
  {
      struct zx_sp11_SubjectQuery_s* e;
      struct zx_sp11_SubjectQuery_s* en;
      struct zx_sp11_SubjectQuery_s* enn;
      for (enn = 0, e = x->SubjectQuery; e; e = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_SubjectQuery(c, e, dup_strs);
	  if (!enn)
	      x->SubjectQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      struct zx_sp11_AuthenticationQuery_s* en;
      struct zx_sp11_AuthenticationQuery_s* enn;
      for (enn = 0, e = x->AuthenticationQuery; e; e = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_AuthenticationQuery(c, e, dup_strs);
	  if (!enn)
	      x->AuthenticationQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      struct zx_sp11_AttributeQuery_s* en;
      struct zx_sp11_AttributeQuery_s* enn;
      for (enn = 0, e = x->AttributeQuery; e; e = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_AttributeQuery(c, e, dup_strs);
	  if (!enn)
	      x->AttributeQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      struct zx_sp11_AuthorizationDecisionQuery_s* en;
      struct zx_sp11_AuthorizationDecisionQuery_s* enn;
      for (enn = 0, e = x->AuthorizationDecisionQuery; e; e = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_AuthorizationDecisionQuery(c, e, dup_strs);
	  if (!enn)
	      x->AuthorizationDecisionQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AssertionIDReference = zx_deep_clone_simple_elems(c,x->AssertionIDReference, dup_strs);
  x->AssertionArtifact = zx_deep_clone_simple_elems(c,x->AssertionArtifact, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sp11_Request) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->RespondWith, ctx, callback);
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
  ret = zx_walk_so_simple_elems(c, x->Query, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp11_SubjectQuery_s* e;
      for (e = x->SubjectQuery; e; e = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_SubjectQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      for (e = x->AuthenticationQuery; e; e = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_AuthenticationQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_AttributeQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      for (e = x->AuthorizationDecisionQuery; e; e = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_AuthorizationDecisionQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AssertionIDReference, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AssertionArtifact, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_Request) */

int zx_WALK_WO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_Response
#define EL_STRUCT zx_sp11_Response_s
#define EL_NS     sp11
#define EL_TAG    Response

/* FUNC(zx_FREE_sp11_Response) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->Recipient, free_strs);
  zx_free_attr(c, x->ResponseID, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_sp11_Status_s* e;
      struct zx_sp11_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp11_Status_s*)e->gg.g.n;
	  zx_FREE_sp11_Status(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      for (e = x->Assertion; e; e = en) {
	  en = (struct zx_sa11_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa11_Assertion(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_Response) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_Response_s* zx_NEW_sp11_Response(struct zx_ctx* c)
{
  struct zx_sp11_Response_s* x = ZX_ZALLOC(c, struct zx_sp11_Response_s);
  x->gg.g.tok = zx_sp11_Response_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_Response) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->Recipient);
  zx_dup_attr(c, x->ResponseID);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_Status(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Assertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_Response) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_Response_s* zx_DEEP_CLONE_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x, int dup_strs)
{
  x = (struct zx_sp11_Response_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_Response_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->Recipient = zx_clone_attr(c, x->Recipient);
  x->ResponseID = zx_clone_attr(c, x->ResponseID);

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
      struct zx_sp11_Status_s* e;
      struct zx_sp11_Status_s* en;
      struct zx_sp11_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      struct zx_sa11_Assertion_s* enn;
      for (enn = 0, e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_Response) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_Response) */

int zx_WALK_WO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_Status
#define EL_STRUCT zx_sp11_Status_s
#define EL_NS     sp11
#define EL_TAG    Status

/* FUNC(zx_FREE_sp11_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp11_StatusCode_s* e;
      struct zx_sp11_StatusCode_s* en;
      for (e = x->StatusCode; e; e = en) {
	  en = (struct zx_sp11_StatusCode_s*)e->gg.g.n;
	  zx_FREE_sp11_StatusCode(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->StatusMessage, free_strs);
  {
      struct zx_sp11_StatusDetail_s* e;
      struct zx_sp11_StatusDetail_s* en;
      for (e = x->StatusDetail; e; e = en) {
	  en = (struct zx_sp11_StatusDetail_s*)e->gg.g.n;
	  zx_FREE_sp11_StatusDetail(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_Status_s* zx_NEW_sp11_Status(struct zx_ctx* c)
{
  struct zx_sp11_Status_s* x = ZX_ZALLOC(c, struct zx_sp11_Status_s);
  x->gg.g.tok = zx_sp11_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_StatusCode(c, e);
  }
  zx_dup_strs_simple_elems(c, x->StatusMessage);
  {
      struct zx_sp11_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp11_StatusDetail_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_StatusDetail(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_Status_s* zx_DEEP_CLONE_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x, int dup_strs)
{
  x = (struct zx_sp11_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sp11_StatusCode_s* e;
      struct zx_sp11_StatusCode_s* en;
      struct zx_sp11_StatusCode_s* enn;
      for (enn = 0, e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_StatusCode(c, e, dup_strs);
	  if (!enn)
	      x->StatusCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->StatusMessage = zx_deep_clone_simple_elems(c,x->StatusMessage, dup_strs);
  {
      struct zx_sp11_StatusDetail_s* e;
      struct zx_sp11_StatusDetail_s* en;
      struct zx_sp11_StatusDetail_s* enn;
      for (enn = 0, e = x->StatusDetail; e; e = (struct zx_sp11_StatusDetail_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_StatusDetail(c, e, dup_strs);
	  if (!enn)
	      x->StatusDetail = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_StatusCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->StatusMessage, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp11_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp11_StatusDetail_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_StatusDetail(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_Status) */

int zx_WALK_WO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_StatusCode
#define EL_STRUCT zx_sp11_StatusCode_s
#define EL_NS     sp11
#define EL_TAG    StatusCode

/* FUNC(zx_FREE_sp11_StatusCode) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Value, free_strs);

  {
      struct zx_sp11_StatusCode_s* e;
      struct zx_sp11_StatusCode_s* en;
      for (e = x->StatusCode; e; e = en) {
	  en = (struct zx_sp11_StatusCode_s*)e->gg.g.n;
	  zx_FREE_sp11_StatusCode(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_StatusCode) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_StatusCode_s* zx_NEW_sp11_StatusCode(struct zx_ctx* c)
{
  struct zx_sp11_StatusCode_s* x = ZX_ZALLOC(c, struct zx_sp11_StatusCode_s);
  x->gg.g.tok = zx_sp11_StatusCode_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_StatusCode) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Value);

  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_StatusCode(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_StatusCode) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_StatusCode_s* zx_DEEP_CLONE_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x, int dup_strs)
{
  x = (struct zx_sp11_StatusCode_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_StatusCode_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Value = zx_clone_attr(c, x->Value);

  {
      struct zx_sp11_StatusCode_s* e;
      struct zx_sp11_StatusCode_s* en;
      struct zx_sp11_StatusCode_s* enn;
      for (enn = 0, e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_StatusCode(c, e, dup_strs);
	  if (!enn)
	      x->StatusCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_StatusCode) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_StatusCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_StatusCode) */

int zx_WALK_WO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_StatusDetail
#define EL_STRUCT zx_sp11_StatusDetail_s
#define EL_NS     sp11
#define EL_TAG    StatusDetail

/* FUNC(zx_FREE_sp11_StatusDetail) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_StatusDetail) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_StatusDetail_s* zx_NEW_sp11_StatusDetail(struct zx_ctx* c)
{
  struct zx_sp11_StatusDetail_s* x = ZX_ZALLOC(c, struct zx_sp11_StatusDetail_s);
  x->gg.g.tok = zx_sp11_StatusDetail_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_StatusDetail) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_sp11_StatusDetail) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_StatusDetail_s* zx_DEEP_CLONE_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x, int dup_strs)
{
  x = (struct zx_sp11_StatusDetail_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_StatusDetail_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_sp11_StatusDetail) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sp11_StatusDetail) */

int zx_WALK_WO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sp11_SubjectQuery
#define EL_STRUCT zx_sp11_SubjectQuery_s
#define EL_NS     sp11
#define EL_TAG    SubjectQuery

/* FUNC(zx_FREE_sp11_SubjectQuery) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa11_Subject_s*)e->gg.g.n;
	  zx_FREE_sa11_Subject(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sp11_SubjectQuery) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sp11_SubjectQuery_s* zx_NEW_sp11_SubjectQuery(struct zx_ctx* c)
{
  struct zx_sp11_SubjectQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_SubjectQuery_s);
  x->gg.g.tok = zx_sp11_SubjectQuery_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sp11_SubjectQuery) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sp11_SubjectQuery) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sp11_SubjectQuery_s* zx_DEEP_CLONE_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x, int dup_strs)
{
  x = (struct zx_sp11_SubjectQuery_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sp11_SubjectQuery_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      struct zx_sa11_Subject_s* enn;
      for (enn = 0, e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Subject(c, e, dup_strs);
	  if (!enn)
	      x->Subject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sp11_SubjectQuery) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sp11_SubjectQuery) */

int zx_WALK_WO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sp11-aux.c */
