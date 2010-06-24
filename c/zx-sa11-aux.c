/* c/zx-sa11-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sa11-data.h"



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

#define EL_NAME   sa11_Action
#define EL_STRUCT zx_sa11_Action_s
#define EL_NS     sa11
#define EL_TAG    Action

/* FUNC(zx_FREE_sa11_Action) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Action(struct zx_ctx* c, struct zx_sa11_Action_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Namespace, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_Action) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Action_s* zx_NEW_sa11_Action(struct zx_ctx* c)
{
  struct zx_sa11_Action_s* x = ZX_ZALLOC(c, struct zx_sa11_Action_s);
  x->gg.g.tok = zx_sa11_Action_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Action) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Action(struct zx_ctx* c, struct zx_sa11_Action_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Namespace);


}

/* FUNC(zx_DEEP_CLONE_sa11_Action) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Action_s* zx_DEEP_CLONE_sa11_Action(struct zx_ctx* c, struct zx_sa11_Action_s* x, int dup_strs)
{
  x = (struct zx_sa11_Action_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Action_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Namespace = zx_clone_attr(c, x->Namespace);


  return x;
}

/* FUNC(zx_WALK_SO_sa11_Action) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Action(struct zx_ctx* c, struct zx_sa11_Action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_Action) */

int zx_WALK_WO_sa11_Action(struct zx_ctx* c, struct zx_sa11_Action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_Advice
#define EL_STRUCT zx_sa11_Advice_s
#define EL_NS     sa11
#define EL_TAG    Advice

/* FUNC(zx_FREE_sa11_Advice) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Advice(struct zx_ctx* c, struct zx_sa11_Advice_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AssertionIDReference, free_strs);
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      for (e = x->Assertion; e; e = en) {
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
  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      for (e = x->sa_Assertion; e; e = en) {
	  en = (struct zx_sa_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa_Assertion(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_Advice) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Advice_s* zx_NEW_sa11_Advice(struct zx_ctx* c)
{
  struct zx_sa11_Advice_s* x = ZX_ZALLOC(c, struct zx_sa11_Advice_s);
  x->gg.g.tok = zx_sa11_Advice_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Advice) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Advice(struct zx_ctx* c, struct zx_sa11_Advice_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AssertionIDReference);
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Assertion(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Assertion(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->sa_Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Assertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_Advice) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Advice_s* zx_DEEP_CLONE_sa11_Advice(struct zx_ctx* c, struct zx_sa11_Advice_s* x, int dup_strs)
{
  x = (struct zx_sa11_Advice_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Advice_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AssertionIDReference = zx_deep_clone_simple_elems(c,x->AssertionIDReference, dup_strs);
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
  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      struct zx_sa_Assertion_s* enn;
      for (enn = 0, e = x->sa_Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->sa_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa11_Advice) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Advice(struct zx_ctx* c, struct zx_sa11_Advice_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AssertionIDReference, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
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
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->sa_Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_Advice) */

int zx_WALK_WO_sa11_Advice(struct zx_ctx* c, struct zx_sa11_Advice_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_Assertion
#define EL_STRUCT zx_sa11_Assertion_s
#define EL_NS     sa11
#define EL_TAG    Assertion

/* FUNC(zx_FREE_sa11_Assertion) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Assertion(struct zx_ctx* c, struct zx_sa11_Assertion_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AssertionID, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->Issuer, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);

  {
      struct zx_sa11_Conditions_s* e;
      struct zx_sa11_Conditions_s* en;
      for (e = x->Conditions; e; e = en) {
	  en = (struct zx_sa11_Conditions_s*)e->gg.g.n;
	  zx_FREE_sa11_Conditions(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_Advice_s* e;
      struct zx_sa11_Advice_s* en;
      for (e = x->Advice; e; e = en) {
	  en = (struct zx_sa11_Advice_s*)e->gg.g.n;
	  zx_FREE_sa11_Advice(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Statement, free_strs);
  {
      struct zx_sa11_SubjectStatement_s* e;
      struct zx_sa11_SubjectStatement_s* en;
      for (e = x->SubjectStatement; e; e = en) {
	  en = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n;
	  zx_FREE_sa11_SubjectStatement(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      struct zx_sa11_AuthenticationStatement_s* en;
      for (e = x->AuthenticationStatement; e; e = en) {
	  en = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n;
	  zx_FREE_sa11_AuthenticationStatement(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      struct zx_sa11_AuthorizationDecisionStatement_s* en;
      for (e = x->AuthorizationDecisionStatement; e; e = en) {
	  en = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n;
	  zx_FREE_sa11_AuthorizationDecisionStatement(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      struct zx_sa11_AttributeStatement_s* en;
      for (e = x->AttributeStatement; e; e = en) {
	  en = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n;
	  zx_FREE_sa11_AttributeStatement(c, e, free_strs);
      }
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      struct zx_xasa_XACMLAuthzDecisionStatement_s* en;
      for (e = x->XACMLAuthzDecisionStatement; e; e = en) {
	  en = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n;
	  zx_FREE_xasa_XACMLAuthzDecisionStatement(c, e, free_strs);
      }
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      struct zx_xasa_XACMLPolicyStatement_s* en;
      for (e = x->XACMLPolicyStatement; e; e = en) {
	  en = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n;
	  zx_FREE_xasa_XACMLPolicyStatement(c, e, free_strs);
      }
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* en;
      for (e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = en) {
	  en = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n;
	  zx_FREE_xasacd1_XACMLAuthzDecisionStatement(c, e, free_strs);
      }
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      struct zx_xasacd1_XACMLPolicyStatement_s* en;
      for (e = x->xasacd1_XACMLPolicyStatement; e; e = en) {
	  en = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n;
	  zx_FREE_xasacd1_XACMLPolicyStatement(c, e, free_strs);
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

/* FUNC(zx_NEW_sa11_Assertion) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Assertion_s* zx_NEW_sa11_Assertion(struct zx_ctx* c)
{
  struct zx_sa11_Assertion_s* x = ZX_ZALLOC(c, struct zx_sa11_Assertion_s);
  x->gg.g.tok = zx_sa11_Assertion_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Assertion) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Assertion(struct zx_ctx* c, struct zx_sa11_Assertion_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AssertionID);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->Issuer);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);

  {
      struct zx_sa11_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa11_Conditions_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Conditions(c, e);
  }
  {
      struct zx_sa11_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa11_Advice_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Advice(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Statement);
  {
      struct zx_sa11_SubjectStatement_s* e;
      for (e = x->SubjectStatement; e; e = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_SubjectStatement(c, e);
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      for (e = x->AuthenticationStatement; e; e = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AuthenticationStatement(c, e);
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      for (e = x->AuthorizationDecisionStatement; e; e = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AuthorizationDecisionStatement(c, e);
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AttributeStatement(c, e);
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      for (e = x->XACMLAuthzDecisionStatement; e; e = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_xasa_XACMLAuthzDecisionStatement(c, e);
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      for (e = x->XACMLPolicyStatement; e; e = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_xasa_XACMLPolicyStatement(c, e);
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      for (e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_xasacd1_XACMLAuthzDecisionStatement(c, e);
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      for (e = x->xasacd1_XACMLPolicyStatement; e; e = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_xasacd1_XACMLPolicyStatement(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_Assertion) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Assertion_s* zx_DEEP_CLONE_sa11_Assertion(struct zx_ctx* c, struct zx_sa11_Assertion_s* x, int dup_strs)
{
  x = (struct zx_sa11_Assertion_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Assertion_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AssertionID = zx_clone_attr(c, x->AssertionID);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->Issuer = zx_clone_attr(c, x->Issuer);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);

  {
      struct zx_sa11_Conditions_s* e;
      struct zx_sa11_Conditions_s* en;
      struct zx_sa11_Conditions_s* enn;
      for (enn = 0, e = x->Conditions; e; e = (struct zx_sa11_Conditions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Conditions(c, e, dup_strs);
	  if (!enn)
	      x->Conditions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_Advice_s* e;
      struct zx_sa11_Advice_s* en;
      struct zx_sa11_Advice_s* enn;
      for (enn = 0, e = x->Advice; e; e = (struct zx_sa11_Advice_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Advice(c, e, dup_strs);
	  if (!enn)
	      x->Advice = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Statement = zx_deep_clone_simple_elems(c,x->Statement, dup_strs);
  {
      struct zx_sa11_SubjectStatement_s* e;
      struct zx_sa11_SubjectStatement_s* en;
      struct zx_sa11_SubjectStatement_s* enn;
      for (enn = 0, e = x->SubjectStatement; e; e = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_SubjectStatement(c, e, dup_strs);
	  if (!enn)
	      x->SubjectStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      struct zx_sa11_AuthenticationStatement_s* en;
      struct zx_sa11_AuthenticationStatement_s* enn;
      for (enn = 0, e = x->AuthenticationStatement; e; e = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AuthenticationStatement(c, e, dup_strs);
	  if (!enn)
	      x->AuthenticationStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      struct zx_sa11_AuthorizationDecisionStatement_s* en;
      struct zx_sa11_AuthorizationDecisionStatement_s* enn;
      for (enn = 0, e = x->AuthorizationDecisionStatement; e; e = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AuthorizationDecisionStatement(c, e, dup_strs);
	  if (!enn)
	      x->AuthorizationDecisionStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      struct zx_sa11_AttributeStatement_s* en;
      struct zx_sa11_AttributeStatement_s* enn;
      for (enn = 0, e = x->AttributeStatement; e; e = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AttributeStatement(c, e, dup_strs);
	  if (!enn)
	      x->AttributeStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      struct zx_xasa_XACMLAuthzDecisionStatement_s* en;
      struct zx_xasa_XACMLAuthzDecisionStatement_s* enn;
      for (enn = 0, e = x->XACMLAuthzDecisionStatement; e; e = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasa_XACMLAuthzDecisionStatement(c, e, dup_strs);
	  if (!enn)
	      x->XACMLAuthzDecisionStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      struct zx_xasa_XACMLPolicyStatement_s* en;
      struct zx_xasa_XACMLPolicyStatement_s* enn;
      for (enn = 0, e = x->XACMLPolicyStatement; e; e = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasa_XACMLPolicyStatement(c, e, dup_strs);
	  if (!enn)
	      x->XACMLPolicyStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* en;
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* enn;
      for (enn = 0, e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasacd1_XACMLAuthzDecisionStatement(c, e, dup_strs);
	  if (!enn)
	      x->xasacd1_XACMLAuthzDecisionStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      struct zx_xasacd1_XACMLPolicyStatement_s* en;
      struct zx_xasacd1_XACMLPolicyStatement_s* enn;
      for (enn = 0, e = x->xasacd1_XACMLPolicyStatement; e; e = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasacd1_XACMLPolicyStatement(c, e, dup_strs);
	  if (!enn)
	      x->xasacd1_XACMLPolicyStatement = en;
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

/* FUNC(zx_WALK_SO_sa11_Assertion) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Assertion(struct zx_ctx* c, struct zx_sa11_Assertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa11_Conditions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Conditions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa11_Advice_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Advice(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Statement, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sa11_SubjectStatement_s* e;
      for (e = x->SubjectStatement; e; e = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_SubjectStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      for (e = x->AuthenticationStatement; e; e = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AuthenticationStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      for (e = x->AuthorizationDecisionStatement; e; e = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AuthorizationDecisionStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AttributeStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      for (e = x->XACMLAuthzDecisionStatement; e; e = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasa_XACMLAuthzDecisionStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      for (e = x->XACMLPolicyStatement; e; e = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasa_XACMLPolicyStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      for (e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasacd1_XACMLAuthzDecisionStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      for (e = x->xasacd1_XACMLPolicyStatement; e; e = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasacd1_XACMLPolicyStatement(c, e, ctx, callback);
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

/* FUNC(zx_WALK_WO_sa11_Assertion) */

int zx_WALK_WO_sa11_Assertion(struct zx_ctx* c, struct zx_sa11_Assertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_Attribute
#define EL_STRUCT zx_sa11_Attribute_s
#define EL_NS     sa11
#define EL_TAG    Attribute

/* FUNC(zx_FREE_sa11_Attribute) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Attribute(struct zx_ctx* c, struct zx_sa11_Attribute_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeName, free_strs);
  zx_free_attr(c, x->AttributeNamespace, free_strs);

  {
      struct zx_sa11_AttributeValue_s* e;
      struct zx_sa11_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_sa11_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_sa11_AttributeValue(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_Attribute) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Attribute_s* zx_NEW_sa11_Attribute(struct zx_ctx* c)
{
  struct zx_sa11_Attribute_s* x = ZX_ZALLOC(c, struct zx_sa11_Attribute_s);
  x->gg.g.tok = zx_sa11_Attribute_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Attribute) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Attribute(struct zx_ctx* c, struct zx_sa11_Attribute_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeName);
  zx_dup_attr(c, x->AttributeNamespace);

  {
      struct zx_sa11_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa11_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AttributeValue(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_Attribute) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Attribute_s* zx_DEEP_CLONE_sa11_Attribute(struct zx_ctx* c, struct zx_sa11_Attribute_s* x, int dup_strs)
{
  x = (struct zx_sa11_Attribute_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Attribute_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeName = zx_clone_attr(c, x->AttributeName);
  x->AttributeNamespace = zx_clone_attr(c, x->AttributeNamespace);

  {
      struct zx_sa11_AttributeValue_s* e;
      struct zx_sa11_AttributeValue_s* en;
      struct zx_sa11_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_sa11_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa11_Attribute) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Attribute(struct zx_ctx* c, struct zx_sa11_Attribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa11_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_Attribute) */

int zx_WALK_WO_sa11_Attribute(struct zx_ctx* c, struct zx_sa11_Attribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AttributeDesignator
#define EL_STRUCT zx_sa11_AttributeDesignator_s
#define EL_NS     sa11
#define EL_TAG    AttributeDesignator

/* FUNC(zx_FREE_sa11_AttributeDesignator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AttributeDesignator(struct zx_ctx* c, struct zx_sa11_AttributeDesignator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeName, free_strs);
  zx_free_attr(c, x->AttributeNamespace, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_AttributeDesignator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AttributeDesignator_s* zx_NEW_sa11_AttributeDesignator(struct zx_ctx* c)
{
  struct zx_sa11_AttributeDesignator_s* x = ZX_ZALLOC(c, struct zx_sa11_AttributeDesignator_s);
  x->gg.g.tok = zx_sa11_AttributeDesignator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AttributeDesignator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AttributeDesignator(struct zx_ctx* c, struct zx_sa11_AttributeDesignator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeName);
  zx_dup_attr(c, x->AttributeNamespace);


}

/* FUNC(zx_DEEP_CLONE_sa11_AttributeDesignator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AttributeDesignator_s* zx_DEEP_CLONE_sa11_AttributeDesignator(struct zx_ctx* c, struct zx_sa11_AttributeDesignator_s* x, int dup_strs)
{
  x = (struct zx_sa11_AttributeDesignator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AttributeDesignator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeName = zx_clone_attr(c, x->AttributeName);
  x->AttributeNamespace = zx_clone_attr(c, x->AttributeNamespace);


  return x;
}

/* FUNC(zx_WALK_SO_sa11_AttributeDesignator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AttributeDesignator(struct zx_ctx* c, struct zx_sa11_AttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_AttributeDesignator) */

int zx_WALK_WO_sa11_AttributeDesignator(struct zx_ctx* c, struct zx_sa11_AttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AttributeStatement
#define EL_STRUCT zx_sa11_AttributeStatement_s
#define EL_NS     sa11
#define EL_TAG    AttributeStatement

/* FUNC(zx_FREE_sa11_AttributeStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AttributeStatement(struct zx_ctx* c, struct zx_sa11_AttributeStatement_s* x, int free_strs)
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
  {
      struct zx_sa11_Attribute_s* e;
      struct zx_sa11_Attribute_s* en;
      for (e = x->Attribute; e; e = en) {
	  en = (struct zx_sa11_Attribute_s*)e->gg.g.n;
	  zx_FREE_sa11_Attribute(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_AttributeStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AttributeStatement_s* zx_NEW_sa11_AttributeStatement(struct zx_ctx* c)
{
  struct zx_sa11_AttributeStatement_s* x = ZX_ZALLOC(c, struct zx_sa11_AttributeStatement_s);
  x->gg.g.tok = zx_sa11_AttributeStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AttributeStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AttributeStatement(struct zx_ctx* c, struct zx_sa11_AttributeStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa11_Attribute_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Attribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_AttributeStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AttributeStatement_s* zx_DEEP_CLONE_sa11_AttributeStatement(struct zx_ctx* c, struct zx_sa11_AttributeStatement_s* x, int dup_strs)
{
  x = (struct zx_sa11_AttributeStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AttributeStatement_s), dup_strs);
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
  {
      struct zx_sa11_Attribute_s* e;
      struct zx_sa11_Attribute_s* en;
      struct zx_sa11_Attribute_s* enn;
      for (enn = 0, e = x->Attribute; e; e = (struct zx_sa11_Attribute_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Attribute(c, e, dup_strs);
	  if (!enn)
	      x->Attribute = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa11_AttributeStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AttributeStatement(struct zx_ctx* c, struct zx_sa11_AttributeStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_sa11_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa11_Attribute_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Attribute(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_AttributeStatement) */

int zx_WALK_WO_sa11_AttributeStatement(struct zx_ctx* c, struct zx_sa11_AttributeStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AttributeValue
#define EL_STRUCT zx_sa11_AttributeValue_s
#define EL_NS     sa11
#define EL_TAG    AttributeValue

/* FUNC(zx_FREE_sa11_AttributeValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AttributeValue(struct zx_ctx* c, struct zx_sa11_AttributeValue_s* x, int free_strs)
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

/* FUNC(zx_NEW_sa11_AttributeValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AttributeValue_s* zx_NEW_sa11_AttributeValue(struct zx_ctx* c)
{
  struct zx_sa11_AttributeValue_s* x = ZX_ZALLOC(c, struct zx_sa11_AttributeValue_s);
  x->gg.g.tok = zx_sa11_AttributeValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AttributeValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AttributeValue(struct zx_ctx* c, struct zx_sa11_AttributeValue_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_di12_ResourceOffering_s* e;
      for (e = x->ResourceOffering; e; e = (struct zx_di12_ResourceOffering_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ResourceOffering(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  zx_DUP_STRS_a_EndpointReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_AttributeValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AttributeValue_s* zx_DEEP_CLONE_sa11_AttributeValue(struct zx_ctx* c, struct zx_sa11_AttributeValue_s* x, int dup_strs)
{
  x = (struct zx_sa11_AttributeValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AttributeValue_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sa11_AttributeValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AttributeValue(struct zx_ctx* c, struct zx_sa11_AttributeValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_AttributeValue) */

int zx_WALK_WO_sa11_AttributeValue(struct zx_ctx* c, struct zx_sa11_AttributeValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AudienceRestrictionCondition
#define EL_STRUCT zx_sa11_AudienceRestrictionCondition_s
#define EL_NS     sa11
#define EL_TAG    AudienceRestrictionCondition

/* FUNC(zx_FREE_sa11_AudienceRestrictionCondition) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AudienceRestrictionCondition(struct zx_ctx* c, struct zx_sa11_AudienceRestrictionCondition_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Audience, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_AudienceRestrictionCondition) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AudienceRestrictionCondition_s* zx_NEW_sa11_AudienceRestrictionCondition(struct zx_ctx* c)
{
  struct zx_sa11_AudienceRestrictionCondition_s* x = ZX_ZALLOC(c, struct zx_sa11_AudienceRestrictionCondition_s);
  x->gg.g.tok = zx_sa11_AudienceRestrictionCondition_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AudienceRestrictionCondition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AudienceRestrictionCondition(struct zx_ctx* c, struct zx_sa11_AudienceRestrictionCondition_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Audience);

}

/* FUNC(zx_DEEP_CLONE_sa11_AudienceRestrictionCondition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AudienceRestrictionCondition_s* zx_DEEP_CLONE_sa11_AudienceRestrictionCondition(struct zx_ctx* c, struct zx_sa11_AudienceRestrictionCondition_s* x, int dup_strs)
{
  x = (struct zx_sa11_AudienceRestrictionCondition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AudienceRestrictionCondition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Audience = zx_deep_clone_simple_elems(c,x->Audience, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sa11_AudienceRestrictionCondition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AudienceRestrictionCondition(struct zx_ctx* c, struct zx_sa11_AudienceRestrictionCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Audience, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_AudienceRestrictionCondition) */

int zx_WALK_WO_sa11_AudienceRestrictionCondition(struct zx_ctx* c, struct zx_sa11_AudienceRestrictionCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AuthenticationStatement
#define EL_STRUCT zx_sa11_AuthenticationStatement_s
#define EL_NS     sa11
#define EL_TAG    AuthenticationStatement

/* FUNC(zx_FREE_sa11_AuthenticationStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AuthenticationStatement(struct zx_ctx* c, struct zx_sa11_AuthenticationStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AuthenticationInstant, free_strs);
  zx_free_attr(c, x->AuthenticationMethod, free_strs);

  {
      struct zx_sa11_Subject_s* e;
      struct zx_sa11_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa11_Subject_s*)e->gg.g.n;
	  zx_FREE_sa11_Subject(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_SubjectLocality_s* e;
      struct zx_sa11_SubjectLocality_s* en;
      for (e = x->SubjectLocality; e; e = en) {
	  en = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n;
	  zx_FREE_sa11_SubjectLocality(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      struct zx_sa11_AuthorityBinding_s* en;
      for (e = x->AuthorityBinding; e; e = en) {
	  en = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n;
	  zx_FREE_sa11_AuthorityBinding(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_AuthenticationStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AuthenticationStatement_s* zx_NEW_sa11_AuthenticationStatement(struct zx_ctx* c)
{
  struct zx_sa11_AuthenticationStatement_s* x = ZX_ZALLOC(c, struct zx_sa11_AuthenticationStatement_s);
  x->gg.g.tok = zx_sa11_AuthenticationStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AuthenticationStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AuthenticationStatement(struct zx_ctx* c, struct zx_sa11_AuthenticationStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AuthenticationInstant);
  zx_dup_attr(c, x->AuthenticationMethod);

  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_SubjectLocality(c, e);
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      for (e = x->AuthorityBinding; e; e = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AuthorityBinding(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_AuthenticationStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AuthenticationStatement_s* zx_DEEP_CLONE_sa11_AuthenticationStatement(struct zx_ctx* c, struct zx_sa11_AuthenticationStatement_s* x, int dup_strs)
{
  x = (struct zx_sa11_AuthenticationStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AuthenticationStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AuthenticationInstant = zx_clone_attr(c, x->AuthenticationInstant);
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
  {
      struct zx_sa11_SubjectLocality_s* e;
      struct zx_sa11_SubjectLocality_s* en;
      struct zx_sa11_SubjectLocality_s* enn;
      for (enn = 0, e = x->SubjectLocality; e; e = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_SubjectLocality(c, e, dup_strs);
	  if (!enn)
	      x->SubjectLocality = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      struct zx_sa11_AuthorityBinding_s* en;
      struct zx_sa11_AuthorityBinding_s* enn;
      for (enn = 0, e = x->AuthorityBinding; e; e = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AuthorityBinding(c, e, dup_strs);
	  if (!enn)
	      x->AuthorityBinding = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa11_AuthenticationStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AuthenticationStatement(struct zx_ctx* c, struct zx_sa11_AuthenticationStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_sa11_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_SubjectLocality(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      for (e = x->AuthorityBinding; e; e = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AuthorityBinding(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_AuthenticationStatement) */

int zx_WALK_WO_sa11_AuthenticationStatement(struct zx_ctx* c, struct zx_sa11_AuthenticationStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AuthorityBinding
#define EL_STRUCT zx_sa11_AuthorityBinding_s
#define EL_NS     sa11
#define EL_TAG    AuthorityBinding

/* FUNC(zx_FREE_sa11_AuthorityBinding) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AuthorityBinding(struct zx_ctx* c, struct zx_sa11_AuthorityBinding_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AuthorityKind, free_strs);
  zx_free_attr(c, x->Binding, free_strs);
  zx_free_attr(c, x->Location, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_AuthorityBinding) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AuthorityBinding_s* zx_NEW_sa11_AuthorityBinding(struct zx_ctx* c)
{
  struct zx_sa11_AuthorityBinding_s* x = ZX_ZALLOC(c, struct zx_sa11_AuthorityBinding_s);
  x->gg.g.tok = zx_sa11_AuthorityBinding_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AuthorityBinding) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AuthorityBinding(struct zx_ctx* c, struct zx_sa11_AuthorityBinding_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AuthorityKind);
  zx_dup_attr(c, x->Binding);
  zx_dup_attr(c, x->Location);


}

/* FUNC(zx_DEEP_CLONE_sa11_AuthorityBinding) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AuthorityBinding_s* zx_DEEP_CLONE_sa11_AuthorityBinding(struct zx_ctx* c, struct zx_sa11_AuthorityBinding_s* x, int dup_strs)
{
  x = (struct zx_sa11_AuthorityBinding_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AuthorityBinding_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AuthorityKind = zx_clone_attr(c, x->AuthorityKind);
  x->Binding = zx_clone_attr(c, x->Binding);
  x->Location = zx_clone_attr(c, x->Location);


  return x;
}

/* FUNC(zx_WALK_SO_sa11_AuthorityBinding) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AuthorityBinding(struct zx_ctx* c, struct zx_sa11_AuthorityBinding_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_AuthorityBinding) */

int zx_WALK_WO_sa11_AuthorityBinding(struct zx_ctx* c, struct zx_sa11_AuthorityBinding_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_AuthorizationDecisionStatement
#define EL_STRUCT zx_sa11_AuthorizationDecisionStatement_s
#define EL_NS     sa11
#define EL_TAG    AuthorizationDecisionStatement

/* FUNC(zx_FREE_sa11_AuthorizationDecisionStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_AuthorizationDecisionStatement(struct zx_ctx* c, struct zx_sa11_AuthorizationDecisionStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Decision, free_strs);
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

/* FUNC(zx_NEW_sa11_AuthorizationDecisionStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_AuthorizationDecisionStatement_s* zx_NEW_sa11_AuthorizationDecisionStatement(struct zx_ctx* c)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* x = ZX_ZALLOC(c, struct zx_sa11_AuthorizationDecisionStatement_s);
  x->gg.g.tok = zx_sa11_AuthorizationDecisionStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_AuthorizationDecisionStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_AuthorizationDecisionStatement(struct zx_ctx* c, struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Decision);
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

/* FUNC(zx_DEEP_CLONE_sa11_AuthorizationDecisionStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_AuthorizationDecisionStatement_s* zx_DEEP_CLONE_sa11_AuthorizationDecisionStatement(struct zx_ctx* c, struct zx_sa11_AuthorizationDecisionStatement_s* x, int dup_strs)
{
  x = (struct zx_sa11_AuthorizationDecisionStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_AuthorizationDecisionStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Decision = zx_clone_attr(c, x->Decision);
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

/* FUNC(zx_WALK_SO_sa11_AuthorizationDecisionStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_AuthorizationDecisionStatement(struct zx_ctx* c, struct zx_sa11_AuthorizationDecisionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_AuthorizationDecisionStatement) */

int zx_WALK_WO_sa11_AuthorizationDecisionStatement(struct zx_ctx* c, struct zx_sa11_AuthorizationDecisionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_Conditions
#define EL_STRUCT zx_sa11_Conditions_s
#define EL_NS     sa11
#define EL_TAG    Conditions

/* FUNC(zx_FREE_sa11_Conditions) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Conditions(struct zx_ctx* c, struct zx_sa11_Conditions_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->NotBefore, free_strs);
  zx_free_attr(c, x->NotOnOrAfter, free_strs);

  {
      struct zx_sa11_AudienceRestrictionCondition_s* e;
      struct zx_sa11_AudienceRestrictionCondition_s* en;
      for (e = x->AudienceRestrictionCondition; e; e = en) {
	  en = (struct zx_sa11_AudienceRestrictionCondition_s*)e->gg.g.n;
	  zx_FREE_sa11_AudienceRestrictionCondition(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_DoNotCacheCondition_s* e;
      struct zx_sa11_DoNotCacheCondition_s* en;
      for (e = x->DoNotCacheCondition; e; e = en) {
	  en = (struct zx_sa11_DoNotCacheCondition_s*)e->gg.g.n;
	  zx_FREE_sa11_DoNotCacheCondition(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Condition, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_Conditions) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Conditions_s* zx_NEW_sa11_Conditions(struct zx_ctx* c)
{
  struct zx_sa11_Conditions_s* x = ZX_ZALLOC(c, struct zx_sa11_Conditions_s);
  x->gg.g.tok = zx_sa11_Conditions_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Conditions) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Conditions(struct zx_ctx* c, struct zx_sa11_Conditions_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->NotBefore);
  zx_dup_attr(c, x->NotOnOrAfter);

  {
      struct zx_sa11_AudienceRestrictionCondition_s* e;
      for (e = x->AudienceRestrictionCondition; e; e = (struct zx_sa11_AudienceRestrictionCondition_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_AudienceRestrictionCondition(c, e);
  }
  {
      struct zx_sa11_DoNotCacheCondition_s* e;
      for (e = x->DoNotCacheCondition; e; e = (struct zx_sa11_DoNotCacheCondition_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_DoNotCacheCondition(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Condition);

}

/* FUNC(zx_DEEP_CLONE_sa11_Conditions) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Conditions_s* zx_DEEP_CLONE_sa11_Conditions(struct zx_ctx* c, struct zx_sa11_Conditions_s* x, int dup_strs)
{
  x = (struct zx_sa11_Conditions_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Conditions_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->NotBefore = zx_clone_attr(c, x->NotBefore);
  x->NotOnOrAfter = zx_clone_attr(c, x->NotOnOrAfter);

  {
      struct zx_sa11_AudienceRestrictionCondition_s* e;
      struct zx_sa11_AudienceRestrictionCondition_s* en;
      struct zx_sa11_AudienceRestrictionCondition_s* enn;
      for (enn = 0, e = x->AudienceRestrictionCondition; e; e = (struct zx_sa11_AudienceRestrictionCondition_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_AudienceRestrictionCondition(c, e, dup_strs);
	  if (!enn)
	      x->AudienceRestrictionCondition = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_DoNotCacheCondition_s* e;
      struct zx_sa11_DoNotCacheCondition_s* en;
      struct zx_sa11_DoNotCacheCondition_s* enn;
      for (enn = 0, e = x->DoNotCacheCondition; e; e = (struct zx_sa11_DoNotCacheCondition_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_DoNotCacheCondition(c, e, dup_strs);
	  if (!enn)
	      x->DoNotCacheCondition = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Condition = zx_deep_clone_simple_elems(c,x->Condition, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sa11_Conditions) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Conditions(struct zx_ctx* c, struct zx_sa11_Conditions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_AudienceRestrictionCondition_s* e;
      for (e = x->AudienceRestrictionCondition; e; e = (struct zx_sa11_AudienceRestrictionCondition_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_AudienceRestrictionCondition(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_DoNotCacheCondition_s* e;
      for (e = x->DoNotCacheCondition; e; e = (struct zx_sa11_DoNotCacheCondition_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_DoNotCacheCondition(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Condition, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_Conditions) */

int zx_WALK_WO_sa11_Conditions(struct zx_ctx* c, struct zx_sa11_Conditions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_DoNotCacheCondition
#define EL_STRUCT zx_sa11_DoNotCacheCondition_s
#define EL_NS     sa11
#define EL_TAG    DoNotCacheCondition

/* FUNC(zx_FREE_sa11_DoNotCacheCondition) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_DoNotCacheCondition(struct zx_ctx* c, struct zx_sa11_DoNotCacheCondition_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_DoNotCacheCondition) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_DoNotCacheCondition_s* zx_NEW_sa11_DoNotCacheCondition(struct zx_ctx* c)
{
  struct zx_sa11_DoNotCacheCondition_s* x = ZX_ZALLOC(c, struct zx_sa11_DoNotCacheCondition_s);
  x->gg.g.tok = zx_sa11_DoNotCacheCondition_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_DoNotCacheCondition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_DoNotCacheCondition(struct zx_ctx* c, struct zx_sa11_DoNotCacheCondition_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_sa11_DoNotCacheCondition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_DoNotCacheCondition_s* zx_DEEP_CLONE_sa11_DoNotCacheCondition(struct zx_ctx* c, struct zx_sa11_DoNotCacheCondition_s* x, int dup_strs)
{
  x = (struct zx_sa11_DoNotCacheCondition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_DoNotCacheCondition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_sa11_DoNotCacheCondition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_DoNotCacheCondition(struct zx_ctx* c, struct zx_sa11_DoNotCacheCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_DoNotCacheCondition) */

int zx_WALK_WO_sa11_DoNotCacheCondition(struct zx_ctx* c, struct zx_sa11_DoNotCacheCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_Evidence
#define EL_STRUCT zx_sa11_Evidence_s
#define EL_NS     sa11
#define EL_TAG    Evidence

/* FUNC(zx_FREE_sa11_Evidence) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Evidence(struct zx_ctx* c, struct zx_sa11_Evidence_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AssertionIDReference, free_strs);
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

/* FUNC(zx_NEW_sa11_Evidence) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Evidence_s* zx_NEW_sa11_Evidence(struct zx_ctx* c)
{
  struct zx_sa11_Evidence_s* x = ZX_ZALLOC(c, struct zx_sa11_Evidence_s);
  x->gg.g.tok = zx_sa11_Evidence_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Evidence) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Evidence(struct zx_ctx* c, struct zx_sa11_Evidence_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AssertionIDReference);
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Assertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_Evidence) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Evidence_s* zx_DEEP_CLONE_sa11_Evidence(struct zx_ctx* c, struct zx_sa11_Evidence_s* x, int dup_strs)
{
  x = (struct zx_sa11_Evidence_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Evidence_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AssertionIDReference = zx_deep_clone_simple_elems(c,x->AssertionIDReference, dup_strs);
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

/* FUNC(zx_WALK_SO_sa11_Evidence) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Evidence(struct zx_ctx* c, struct zx_sa11_Evidence_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AssertionIDReference, ctx, callback);
  if (ret)
    return ret;
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

/* FUNC(zx_WALK_WO_sa11_Evidence) */

int zx_WALK_WO_sa11_Evidence(struct zx_ctx* c, struct zx_sa11_Evidence_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_NameIdentifier
#define EL_STRUCT zx_sa11_NameIdentifier_s
#define EL_NS     sa11
#define EL_TAG    NameIdentifier

/* FUNC(zx_FREE_sa11_NameIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_NameIdentifier(struct zx_ctx* c, struct zx_sa11_NameIdentifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_NameIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_NameIdentifier_s* zx_NEW_sa11_NameIdentifier(struct zx_ctx* c)
{
  struct zx_sa11_NameIdentifier_s* x = ZX_ZALLOC(c, struct zx_sa11_NameIdentifier_s);
  x->gg.g.tok = zx_sa11_NameIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_NameIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_NameIdentifier(struct zx_ctx* c, struct zx_sa11_NameIdentifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->NameQualifier);


}

/* FUNC(zx_DEEP_CLONE_sa11_NameIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_NameIdentifier_s* zx_DEEP_CLONE_sa11_NameIdentifier(struct zx_ctx* c, struct zx_sa11_NameIdentifier_s* x, int dup_strs)
{
  x = (struct zx_sa11_NameIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_NameIdentifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);


  return x;
}

/* FUNC(zx_WALK_SO_sa11_NameIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_NameIdentifier(struct zx_ctx* c, struct zx_sa11_NameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_NameIdentifier) */

int zx_WALK_WO_sa11_NameIdentifier(struct zx_ctx* c, struct zx_sa11_NameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_Subject
#define EL_STRUCT zx_sa11_Subject_s
#define EL_NS     sa11
#define EL_TAG    Subject

/* FUNC(zx_FREE_sa11_Subject) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_Subject(struct zx_ctx* c, struct zx_sa11_Subject_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_NameIdentifier_s* e;
      struct zx_sa11_NameIdentifier_s* en;
      for (e = x->NameIdentifier; e; e = en) {
	  en = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n;
	  zx_FREE_sa11_NameIdentifier(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      struct zx_sa11_SubjectConfirmation_s* en;
      for (e = x->SubjectConfirmation; e; e = en) {
	  en = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n;
	  zx_FREE_sa11_SubjectConfirmation(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_Subject) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_Subject_s* zx_NEW_sa11_Subject(struct zx_ctx* c)
{
  struct zx_sa11_Subject_s* x = ZX_ZALLOC(c, struct zx_sa11_Subject_s);
  x->gg.g.tok = zx_sa11_Subject_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_Subject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_Subject(struct zx_ctx* c, struct zx_sa11_Subject_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_NameIdentifier(c, e);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_SubjectConfirmation(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_Subject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_Subject_s* zx_DEEP_CLONE_sa11_Subject(struct zx_ctx* c, struct zx_sa11_Subject_s* x, int dup_strs)
{
  x = (struct zx_sa11_Subject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_Subject_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_NameIdentifier_s* e;
      struct zx_sa11_NameIdentifier_s* en;
      struct zx_sa11_NameIdentifier_s* enn;
      for (enn = 0, e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_NameIdentifier(c, e, dup_strs);
	  if (!enn)
	      x->NameIdentifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      struct zx_sa11_SubjectConfirmation_s* en;
      struct zx_sa11_SubjectConfirmation_s* enn;
      for (enn = 0, e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_SubjectConfirmation(c, e, dup_strs);
	  if (!enn)
	      x->SubjectConfirmation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa11_Subject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_Subject(struct zx_ctx* c, struct zx_sa11_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_NameIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_SubjectConfirmation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_Subject) */

int zx_WALK_WO_sa11_Subject(struct zx_ctx* c, struct zx_sa11_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_SubjectConfirmation
#define EL_STRUCT zx_sa11_SubjectConfirmation_s
#define EL_NS     sa11
#define EL_TAG    SubjectConfirmation

/* FUNC(zx_FREE_sa11_SubjectConfirmation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_SubjectConfirmation(struct zx_ctx* c, struct zx_sa11_SubjectConfirmation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->ConfirmationMethod, free_strs);
  zx_free_simple_elems(c, x->SubjectConfirmationData, free_strs);
  {
      struct zx_ds_KeyInfo_s* e;
      struct zx_ds_KeyInfo_s* en;
      for (e = x->KeyInfo; e; e = en) {
	  en = (struct zx_ds_KeyInfo_s*)e->gg.g.n;
	  zx_FREE_ds_KeyInfo(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_SubjectConfirmation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_SubjectConfirmation_s* zx_NEW_sa11_SubjectConfirmation(struct zx_ctx* c)
{
  struct zx_sa11_SubjectConfirmation_s* x = ZX_ZALLOC(c, struct zx_sa11_SubjectConfirmation_s);
  x->gg.g.tok = zx_sa11_SubjectConfirmation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_SubjectConfirmation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_SubjectConfirmation(struct zx_ctx* c, struct zx_sa11_SubjectConfirmation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->ConfirmationMethod);
  zx_dup_strs_simple_elems(c, x->SubjectConfirmationData);
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_SubjectConfirmation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_SubjectConfirmation_s* zx_DEEP_CLONE_sa11_SubjectConfirmation(struct zx_ctx* c, struct zx_sa11_SubjectConfirmation_s* x, int dup_strs)
{
  x = (struct zx_sa11_SubjectConfirmation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_SubjectConfirmation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->ConfirmationMethod = zx_deep_clone_simple_elems(c,x->ConfirmationMethod, dup_strs);
  x->SubjectConfirmationData = zx_deep_clone_simple_elems(c,x->SubjectConfirmationData, dup_strs);
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

  return x;
}

/* FUNC(zx_WALK_SO_sa11_SubjectConfirmation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_SubjectConfirmation(struct zx_ctx* c, struct zx_sa11_SubjectConfirmation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->ConfirmationMethod, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SubjectConfirmationData, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa11_SubjectConfirmation) */

int zx_WALK_WO_sa11_SubjectConfirmation(struct zx_ctx* c, struct zx_sa11_SubjectConfirmation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_SubjectLocality
#define EL_STRUCT zx_sa11_SubjectLocality_s
#define EL_NS     sa11
#define EL_TAG    SubjectLocality

/* FUNC(zx_FREE_sa11_SubjectLocality) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_SubjectLocality(struct zx_ctx* c, struct zx_sa11_SubjectLocality_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->DNSAddress, free_strs);
  zx_free_attr(c, x->IPAddress, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa11_SubjectLocality) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_SubjectLocality_s* zx_NEW_sa11_SubjectLocality(struct zx_ctx* c)
{
  struct zx_sa11_SubjectLocality_s* x = ZX_ZALLOC(c, struct zx_sa11_SubjectLocality_s);
  x->gg.g.tok = zx_sa11_SubjectLocality_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_SubjectLocality) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_SubjectLocality(struct zx_ctx* c, struct zx_sa11_SubjectLocality_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->DNSAddress);
  zx_dup_attr(c, x->IPAddress);


}

/* FUNC(zx_DEEP_CLONE_sa11_SubjectLocality) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_SubjectLocality_s* zx_DEEP_CLONE_sa11_SubjectLocality(struct zx_ctx* c, struct zx_sa11_SubjectLocality_s* x, int dup_strs)
{
  x = (struct zx_sa11_SubjectLocality_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_SubjectLocality_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->DNSAddress = zx_clone_attr(c, x->DNSAddress);
  x->IPAddress = zx_clone_attr(c, x->IPAddress);


  return x;
}

/* FUNC(zx_WALK_SO_sa11_SubjectLocality) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_SubjectLocality(struct zx_ctx* c, struct zx_sa11_SubjectLocality_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_SubjectLocality) */

int zx_WALK_WO_sa11_SubjectLocality(struct zx_ctx* c, struct zx_sa11_SubjectLocality_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa11_SubjectStatement
#define EL_STRUCT zx_sa11_SubjectStatement_s
#define EL_NS     sa11
#define EL_TAG    SubjectStatement

/* FUNC(zx_FREE_sa11_SubjectStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa11_SubjectStatement(struct zx_ctx* c, struct zx_sa11_SubjectStatement_s* x, int free_strs)
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

/* FUNC(zx_NEW_sa11_SubjectStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa11_SubjectStatement_s* zx_NEW_sa11_SubjectStatement(struct zx_ctx* c)
{
  struct zx_sa11_SubjectStatement_s* x = ZX_ZALLOC(c, struct zx_sa11_SubjectStatement_s);
  x->gg.g.tok = zx_sa11_SubjectStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa11_SubjectStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa11_SubjectStatement(struct zx_ctx* c, struct zx_sa11_SubjectStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa11_SubjectStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa11_SubjectStatement_s* zx_DEEP_CLONE_sa11_SubjectStatement(struct zx_ctx* c, struct zx_sa11_SubjectStatement_s* x, int dup_strs)
{
  x = (struct zx_sa11_SubjectStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa11_SubjectStatement_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sa11_SubjectStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa11_SubjectStatement(struct zx_ctx* c, struct zx_sa11_SubjectStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa11_SubjectStatement) */

int zx_WALK_WO_sa11_SubjectStatement(struct zx_ctx* c, struct zx_sa11_SubjectStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sa11-aux.c */
