/* c/zx-sa-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sa-data.h"



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

#define EL_NAME   sa_Action
#define EL_STRUCT zx_sa_Action_s
#define EL_NS     sa
#define EL_TAG    Action

/* FUNC(zx_FREE_sa_Action) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Action(struct zx_ctx* c, struct zx_sa_Action_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Namespace, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_Action) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Action_s* zx_NEW_sa_Action(struct zx_ctx* c)
{
  struct zx_sa_Action_s* x = ZX_ZALLOC(c, struct zx_sa_Action_s);
  x->gg.g.tok = zx_sa_Action_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Action) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Action(struct zx_ctx* c, struct zx_sa_Action_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Namespace);


}

/* FUNC(zx_DEEP_CLONE_sa_Action) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Action_s* zx_DEEP_CLONE_sa_Action(struct zx_ctx* c, struct zx_sa_Action_s* x, int dup_strs)
{
  x = (struct zx_sa_Action_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Action_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Namespace = zx_clone_attr(c, x->Namespace);


  return x;
}

/* FUNC(zx_WALK_SO_sa_Action) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Action(struct zx_ctx* c, struct zx_sa_Action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_Action) */

int zx_WALK_WO_sa_Action(struct zx_ctx* c, struct zx_sa_Action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Advice
#define EL_STRUCT zx_sa_Advice_s
#define EL_NS     sa
#define EL_TAG    Advice

/* FUNC(zx_FREE_sa_Advice) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Advice(struct zx_ctx* c, struct zx_sa_Advice_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AssertionIDRef, free_strs);
  zx_free_simple_elems(c, x->AssertionURIRef, free_strs);
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

/* FUNC(zx_NEW_sa_Advice) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Advice_s* zx_NEW_sa_Advice(struct zx_ctx* c)
{
  struct zx_sa_Advice_s* x = ZX_ZALLOC(c, struct zx_sa_Advice_s);
  x->gg.g.tok = zx_sa_Advice_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Advice) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Advice(struct zx_ctx* c, struct zx_sa_Advice_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AssertionIDRef);
  zx_dup_strs_simple_elems(c, x->AssertionURIRef);
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

/* FUNC(zx_DEEP_CLONE_sa_Advice) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Advice_s* zx_DEEP_CLONE_sa_Advice(struct zx_ctx* c, struct zx_sa_Advice_s* x, int dup_strs)
{
  x = (struct zx_sa_Advice_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Advice_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AssertionIDRef = zx_deep_clone_simple_elems(c,x->AssertionIDRef, dup_strs);
  x->AssertionURIRef = zx_deep_clone_simple_elems(c,x->AssertionURIRef, dup_strs);
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

/* FUNC(zx_WALK_SO_sa_Advice) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Advice(struct zx_ctx* c, struct zx_sa_Advice_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AssertionIDRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AssertionURIRef, ctx, callback);
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

/* FUNC(zx_WALK_WO_sa_Advice) */

int zx_WALK_WO_sa_Advice(struct zx_ctx* c, struct zx_sa_Advice_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Assertion
#define EL_STRUCT zx_sa_Assertion_s
#define EL_NS     sa
#define EL_TAG    Assertion

/* FUNC(zx_FREE_sa_Assertion) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Assertion(struct zx_ctx* c, struct zx_sa_Assertion_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

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
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa_Subject_s*)e->gg.g.n;
	  zx_FREE_sa_Subject(c, e, free_strs);
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
      struct zx_sa_Advice_s* e;
      struct zx_sa_Advice_s* en;
      for (e = x->Advice; e; e = en) {
	  en = (struct zx_sa_Advice_s*)e->gg.g.n;
	  zx_FREE_sa_Advice(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Statement_s* e;
      struct zx_sa_Statement_s* en;
      for (e = x->Statement; e; e = en) {
	  en = (struct zx_sa_Statement_s*)e->gg.g.n;
	  zx_FREE_sa_Statement(c, e, free_strs);
      }
  }
  {
      struct zx_sa_AuthnStatement_s* e;
      struct zx_sa_AuthnStatement_s* en;
      for (e = x->AuthnStatement; e; e = en) {
	  en = (struct zx_sa_AuthnStatement_s*)e->gg.g.n;
	  zx_FREE_sa_AuthnStatement(c, e, free_strs);
      }
  }
  {
      struct zx_sa_AuthzDecisionStatement_s* e;
      struct zx_sa_AuthzDecisionStatement_s* en;
      for (e = x->AuthzDecisionStatement; e; e = en) {
	  en = (struct zx_sa_AuthzDecisionStatement_s*)e->gg.g.n;
	  zx_FREE_sa_AuthzDecisionStatement(c, e, free_strs);
      }
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      struct zx_sa_AttributeStatement_s* en;
      for (e = x->AttributeStatement; e; e = en) {
	  en = (struct zx_sa_AttributeStatement_s*)e->gg.g.n;
	  zx_FREE_sa_AttributeStatement(c, e, free_strs);
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


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_Assertion) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Assertion_s* zx_NEW_sa_Assertion(struct zx_ctx* c)
{
  struct zx_sa_Assertion_s* x = ZX_ZALLOC(c, struct zx_sa_Assertion_s);
  x->gg.g.tok = zx_sa_Assertion_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Assertion) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Assertion(struct zx_ctx* c, struct zx_sa_Assertion_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

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
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }
  {
      struct zx_sa_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa_Conditions_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Conditions(c, e);
  }
  {
      struct zx_sa_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa_Advice_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Advice(c, e);
  }
  {
      struct zx_sa_Statement_s* e;
      for (e = x->Statement; e; e = (struct zx_sa_Statement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Statement(c, e);
  }
  {
      struct zx_sa_AuthnStatement_s* e;
      for (e = x->AuthnStatement; e; e = (struct zx_sa_AuthnStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AuthnStatement(c, e);
  }
  {
      struct zx_sa_AuthzDecisionStatement_s* e;
      for (e = x->AuthzDecisionStatement; e; e = (struct zx_sa_AuthzDecisionStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AuthzDecisionStatement(c, e);
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AttributeStatement(c, e);
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

}

/* FUNC(zx_DEEP_CLONE_sa_Assertion) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Assertion_s* zx_DEEP_CLONE_sa_Assertion(struct zx_ctx* c, struct zx_sa_Assertion_s* x, int dup_strs)
{
  x = (struct zx_sa_Assertion_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Assertion_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

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
      struct zx_sa_Advice_s* e;
      struct zx_sa_Advice_s* en;
      struct zx_sa_Advice_s* enn;
      for (enn = 0, e = x->Advice; e; e = (struct zx_sa_Advice_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Advice(c, e, dup_strs);
	  if (!enn)
	      x->Advice = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_Statement_s* e;
      struct zx_sa_Statement_s* en;
      struct zx_sa_Statement_s* enn;
      for (enn = 0, e = x->Statement; e; e = (struct zx_sa_Statement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Statement(c, e, dup_strs);
	  if (!enn)
	      x->Statement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_AuthnStatement_s* e;
      struct zx_sa_AuthnStatement_s* en;
      struct zx_sa_AuthnStatement_s* enn;
      for (enn = 0, e = x->AuthnStatement; e; e = (struct zx_sa_AuthnStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AuthnStatement(c, e, dup_strs);
	  if (!enn)
	      x->AuthnStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_AuthzDecisionStatement_s* e;
      struct zx_sa_AuthzDecisionStatement_s* en;
      struct zx_sa_AuthzDecisionStatement_s* enn;
      for (enn = 0, e = x->AuthzDecisionStatement; e; e = (struct zx_sa_AuthzDecisionStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AuthzDecisionStatement(c, e, dup_strs);
	  if (!enn)
	      x->AuthzDecisionStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      struct zx_sa_AttributeStatement_s* en;
      struct zx_sa_AttributeStatement_s* enn;
      for (enn = 0, e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AttributeStatement(c, e, dup_strs);
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

  return x;
}

/* FUNC(zx_WALK_SO_sa_Assertion) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Assertion(struct zx_ctx* c, struct zx_sa_Assertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Subject(c, e, ctx, callback);
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
      struct zx_sa_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa_Advice_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Advice(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Statement_s* e;
      for (e = x->Statement; e; e = (struct zx_sa_Statement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Statement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_AuthnStatement_s* e;
      for (e = x->AuthnStatement; e; e = (struct zx_sa_AuthnStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AuthnStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_AuthzDecisionStatement_s* e;
      for (e = x->AuthzDecisionStatement; e; e = (struct zx_sa_AuthzDecisionStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AuthzDecisionStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AttributeStatement(c, e, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_Assertion) */

int zx_WALK_WO_sa_Assertion(struct zx_ctx* c, struct zx_sa_Assertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Attribute
#define EL_STRUCT zx_sa_Attribute_s
#define EL_NS     sa
#define EL_TAG    Attribute

/* FUNC(zx_FREE_sa_Attribute) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Attribute(struct zx_ctx* c, struct zx_sa_Attribute_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->FriendlyName, free_strs);
  zx_free_attr(c, x->Name, free_strs);
  zx_free_attr(c, x->NameFormat, free_strs);

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

/* FUNC(zx_NEW_sa_Attribute) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Attribute_s* zx_NEW_sa_Attribute(struct zx_ctx* c)
{
  struct zx_sa_Attribute_s* x = ZX_ZALLOC(c, struct zx_sa_Attribute_s);
  x->gg.g.tok = zx_sa_Attribute_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Attribute) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Attribute(struct zx_ctx* c, struct zx_sa_Attribute_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->FriendlyName);
  zx_dup_attr(c, x->Name);
  zx_dup_attr(c, x->NameFormat);

  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AttributeValue(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_Attribute) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Attribute_s* zx_DEEP_CLONE_sa_Attribute(struct zx_ctx* c, struct zx_sa_Attribute_s* x, int dup_strs)
{
  x = (struct zx_sa_Attribute_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Attribute_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->FriendlyName = zx_clone_attr(c, x->FriendlyName);
  x->Name = zx_clone_attr(c, x->Name);
  x->NameFormat = zx_clone_attr(c, x->NameFormat);

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

/* FUNC(zx_WALK_SO_sa_Attribute) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Attribute(struct zx_ctx* c, struct zx_sa_Attribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_Attribute) */

int zx_WALK_WO_sa_Attribute(struct zx_ctx* c, struct zx_sa_Attribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_AttributeStatement
#define EL_STRUCT zx_sa_AttributeStatement_s
#define EL_NS     sa
#define EL_TAG    AttributeStatement

/* FUNC(zx_FREE_sa_AttributeStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_AttributeStatement(struct zx_ctx* c, struct zx_sa_AttributeStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Attribute_s* e;
      struct zx_sa_Attribute_s* en;
      for (e = x->Attribute; e; e = en) {
	  en = (struct zx_sa_Attribute_s*)e->gg.g.n;
	  zx_FREE_sa_Attribute(c, e, free_strs);
      }
  }
  {
      struct zx_sa_EncryptedAttribute_s* e;
      struct zx_sa_EncryptedAttribute_s* en;
      for (e = x->EncryptedAttribute; e; e = en) {
	  en = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedAttribute(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_AttributeStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_AttributeStatement_s* zx_NEW_sa_AttributeStatement(struct zx_ctx* c)
{
  struct zx_sa_AttributeStatement_s* x = ZX_ZALLOC(c, struct zx_sa_AttributeStatement_s);
  x->gg.g.tok = zx_sa_AttributeStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_AttributeStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_AttributeStatement(struct zx_ctx* c, struct zx_sa_AttributeStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Attribute(c, e);
  }
  {
      struct zx_sa_EncryptedAttribute_s* e;
      for (e = x->EncryptedAttribute; e; e = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedAttribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_AttributeStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_AttributeStatement_s* zx_DEEP_CLONE_sa_AttributeStatement(struct zx_ctx* c, struct zx_sa_AttributeStatement_s* x, int dup_strs)
{
  x = (struct zx_sa_AttributeStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_AttributeStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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
  {
      struct zx_sa_EncryptedAttribute_s* e;
      struct zx_sa_EncryptedAttribute_s* en;
      struct zx_sa_EncryptedAttribute_s* enn;
      for (enn = 0, e = x->EncryptedAttribute; e; e = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedAttribute(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedAttribute = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa_AttributeStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_AttributeStatement(struct zx_ctx* c, struct zx_sa_AttributeStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
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
  {
      struct zx_sa_EncryptedAttribute_s* e;
      for (e = x->EncryptedAttribute; e; e = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedAttribute(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_AttributeStatement) */

int zx_WALK_WO_sa_AttributeStatement(struct zx_ctx* c, struct zx_sa_AttributeStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_AttributeValue
#define EL_STRUCT zx_sa_AttributeValue_s
#define EL_NS     sa
#define EL_TAG    AttributeValue

/* FUNC(zx_FREE_sa_AttributeValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_AttributeValue(struct zx_ctx* c, struct zx_sa_AttributeValue_s* x, int free_strs)
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

/* FUNC(zx_NEW_sa_AttributeValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_AttributeValue_s* zx_NEW_sa_AttributeValue(struct zx_ctx* c)
{
  struct zx_sa_AttributeValue_s* x = ZX_ZALLOC(c, struct zx_sa_AttributeValue_s);
  x->gg.g.tok = zx_sa_AttributeValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_AttributeValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_AttributeValue(struct zx_ctx* c, struct zx_sa_AttributeValue_s* x)
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

/* FUNC(zx_DEEP_CLONE_sa_AttributeValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_AttributeValue_s* zx_DEEP_CLONE_sa_AttributeValue(struct zx_ctx* c, struct zx_sa_AttributeValue_s* x, int dup_strs)
{
  x = (struct zx_sa_AttributeValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_AttributeValue_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sa_AttributeValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_AttributeValue(struct zx_ctx* c, struct zx_sa_AttributeValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_AttributeValue) */

int zx_WALK_WO_sa_AttributeValue(struct zx_ctx* c, struct zx_sa_AttributeValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_AudienceRestriction
#define EL_STRUCT zx_sa_AudienceRestriction_s
#define EL_NS     sa
#define EL_TAG    AudienceRestriction

/* FUNC(zx_FREE_sa_AudienceRestriction) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_AudienceRestriction(struct zx_ctx* c, struct zx_sa_AudienceRestriction_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Audience, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_AudienceRestriction) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_AudienceRestriction_s* zx_NEW_sa_AudienceRestriction(struct zx_ctx* c)
{
  struct zx_sa_AudienceRestriction_s* x = ZX_ZALLOC(c, struct zx_sa_AudienceRestriction_s);
  x->gg.g.tok = zx_sa_AudienceRestriction_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_AudienceRestriction) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_AudienceRestriction(struct zx_ctx* c, struct zx_sa_AudienceRestriction_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Audience);

}

/* FUNC(zx_DEEP_CLONE_sa_AudienceRestriction) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_AudienceRestriction_s* zx_DEEP_CLONE_sa_AudienceRestriction(struct zx_ctx* c, struct zx_sa_AudienceRestriction_s* x, int dup_strs)
{
  x = (struct zx_sa_AudienceRestriction_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_AudienceRestriction_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Audience = zx_deep_clone_simple_elems(c,x->Audience, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sa_AudienceRestriction) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_AudienceRestriction(struct zx_ctx* c, struct zx_sa_AudienceRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_AudienceRestriction) */

int zx_WALK_WO_sa_AudienceRestriction(struct zx_ctx* c, struct zx_sa_AudienceRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_AuthnContext
#define EL_STRUCT zx_sa_AuthnContext_s
#define EL_NS     sa
#define EL_TAG    AuthnContext

/* FUNC(zx_FREE_sa_AuthnContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_AuthnContext(struct zx_ctx* c, struct zx_sa_AuthnContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AuthnContextClassRef, free_strs);
  zx_free_simple_elems(c, x->AuthnContextDecl, free_strs);
  zx_free_simple_elems(c, x->AuthnContextDeclRef, free_strs);
  zx_free_simple_elems(c, x->AuthenticatingAuthority, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_AuthnContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_AuthnContext_s* zx_NEW_sa_AuthnContext(struct zx_ctx* c)
{
  struct zx_sa_AuthnContext_s* x = ZX_ZALLOC(c, struct zx_sa_AuthnContext_s);
  x->gg.g.tok = zx_sa_AuthnContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_AuthnContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_AuthnContext(struct zx_ctx* c, struct zx_sa_AuthnContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AuthnContextClassRef);
  zx_dup_strs_simple_elems(c, x->AuthnContextDecl);
  zx_dup_strs_simple_elems(c, x->AuthnContextDeclRef);
  zx_dup_strs_simple_elems(c, x->AuthenticatingAuthority);

}

/* FUNC(zx_DEEP_CLONE_sa_AuthnContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_AuthnContext_s* zx_DEEP_CLONE_sa_AuthnContext(struct zx_ctx* c, struct zx_sa_AuthnContext_s* x, int dup_strs)
{
  x = (struct zx_sa_AuthnContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_AuthnContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AuthnContextClassRef = zx_deep_clone_simple_elems(c,x->AuthnContextClassRef, dup_strs);
  x->AuthnContextDecl = zx_deep_clone_simple_elems(c,x->AuthnContextDecl, dup_strs);
  x->AuthnContextDeclRef = zx_deep_clone_simple_elems(c,x->AuthnContextDeclRef, dup_strs);
  x->AuthenticatingAuthority = zx_deep_clone_simple_elems(c,x->AuthenticatingAuthority, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sa_AuthnContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_AuthnContext(struct zx_ctx* c, struct zx_sa_AuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->AuthnContextDecl, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuthnContextDeclRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuthenticatingAuthority, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_AuthnContext) */

int zx_WALK_WO_sa_AuthnContext(struct zx_ctx* c, struct zx_sa_AuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_AuthnStatement
#define EL_STRUCT zx_sa_AuthnStatement_s
#define EL_NS     sa
#define EL_TAG    AuthnStatement

/* FUNC(zx_FREE_sa_AuthnStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_AuthnStatement(struct zx_ctx* c, struct zx_sa_AuthnStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AuthnInstant, free_strs);
  zx_free_attr(c, x->SessionIndex, free_strs);
  zx_free_attr(c, x->SessionNotOnOrAfter, free_strs);

  {
      struct zx_sa_SubjectLocality_s* e;
      struct zx_sa_SubjectLocality_s* en;
      for (e = x->SubjectLocality; e; e = en) {
	  en = (struct zx_sa_SubjectLocality_s*)e->gg.g.n;
	  zx_FREE_sa_SubjectLocality(c, e, free_strs);
      }
  }
  {
      struct zx_sa_AuthnContext_s* e;
      struct zx_sa_AuthnContext_s* en;
      for (e = x->AuthnContext; e; e = en) {
	  en = (struct zx_sa_AuthnContext_s*)e->gg.g.n;
	  zx_FREE_sa_AuthnContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_AuthnStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_AuthnStatement_s* zx_NEW_sa_AuthnStatement(struct zx_ctx* c)
{
  struct zx_sa_AuthnStatement_s* x = ZX_ZALLOC(c, struct zx_sa_AuthnStatement_s);
  x->gg.g.tok = zx_sa_AuthnStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_AuthnStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_AuthnStatement(struct zx_ctx* c, struct zx_sa_AuthnStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AuthnInstant);
  zx_dup_attr(c, x->SessionIndex);
  zx_dup_attr(c, x->SessionNotOnOrAfter);

  {
      struct zx_sa_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa_SubjectLocality_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_SubjectLocality(c, e);
  }
  {
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AuthnContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_AuthnStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_AuthnStatement_s* zx_DEEP_CLONE_sa_AuthnStatement(struct zx_ctx* c, struct zx_sa_AuthnStatement_s* x, int dup_strs)
{
  x = (struct zx_sa_AuthnStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_AuthnStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AuthnInstant = zx_clone_attr(c, x->AuthnInstant);
  x->SessionIndex = zx_clone_attr(c, x->SessionIndex);
  x->SessionNotOnOrAfter = zx_clone_attr(c, x->SessionNotOnOrAfter);

  {
      struct zx_sa_SubjectLocality_s* e;
      struct zx_sa_SubjectLocality_s* en;
      struct zx_sa_SubjectLocality_s* enn;
      for (enn = 0, e = x->SubjectLocality; e; e = (struct zx_sa_SubjectLocality_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_SubjectLocality(c, e, dup_strs);
	  if (!enn)
	      x->SubjectLocality = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_AuthnContext_s* e;
      struct zx_sa_AuthnContext_s* en;
      struct zx_sa_AuthnContext_s* enn;
      for (enn = 0, e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AuthnContext(c, e, dup_strs);
	  if (!enn)
	      x->AuthnContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa_AuthnStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_AuthnStatement(struct zx_ctx* c, struct zx_sa_AuthnStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa_SubjectLocality_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_SubjectLocality(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_AuthnStatement) */

int zx_WALK_WO_sa_AuthnStatement(struct zx_ctx* c, struct zx_sa_AuthnStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_AuthzDecisionStatement
#define EL_STRUCT zx_sa_AuthzDecisionStatement_s
#define EL_NS     sa
#define EL_TAG    AuthzDecisionStatement

/* FUNC(zx_FREE_sa_AuthzDecisionStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_AuthzDecisionStatement(struct zx_ctx* c, struct zx_sa_AuthzDecisionStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Decision, free_strs);
  zx_free_attr(c, x->Resource, free_strs);

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

/* FUNC(zx_NEW_sa_AuthzDecisionStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_AuthzDecisionStatement_s* zx_NEW_sa_AuthzDecisionStatement(struct zx_ctx* c)
{
  struct zx_sa_AuthzDecisionStatement_s* x = ZX_ZALLOC(c, struct zx_sa_AuthzDecisionStatement_s);
  x->gg.g.tok = zx_sa_AuthzDecisionStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_AuthzDecisionStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_AuthzDecisionStatement(struct zx_ctx* c, struct zx_sa_AuthzDecisionStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Decision);
  zx_dup_attr(c, x->Resource);

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

/* FUNC(zx_DEEP_CLONE_sa_AuthzDecisionStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_AuthzDecisionStatement_s* zx_DEEP_CLONE_sa_AuthzDecisionStatement(struct zx_ctx* c, struct zx_sa_AuthzDecisionStatement_s* x, int dup_strs)
{
  x = (struct zx_sa_AuthzDecisionStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_AuthzDecisionStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Decision = zx_clone_attr(c, x->Decision);
  x->Resource = zx_clone_attr(c, x->Resource);

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

/* FUNC(zx_WALK_SO_sa_AuthzDecisionStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_AuthzDecisionStatement(struct zx_ctx* c, struct zx_sa_AuthzDecisionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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

/* FUNC(zx_WALK_WO_sa_AuthzDecisionStatement) */

int zx_WALK_WO_sa_AuthzDecisionStatement(struct zx_ctx* c, struct zx_sa_AuthzDecisionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_BaseID
#define EL_STRUCT zx_sa_BaseID_s
#define EL_NS     sa
#define EL_TAG    BaseID

/* FUNC(zx_FREE_sa_BaseID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_BaseID(struct zx_ctx* c, struct zx_sa_BaseID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->NameQualifier, free_strs);
  zx_free_attr(c, x->SPNameQualifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_BaseID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_BaseID_s* zx_NEW_sa_BaseID(struct zx_ctx* c)
{
  struct zx_sa_BaseID_s* x = ZX_ZALLOC(c, struct zx_sa_BaseID_s);
  x->gg.g.tok = zx_sa_BaseID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_BaseID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_BaseID(struct zx_ctx* c, struct zx_sa_BaseID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->NameQualifier);
  zx_dup_attr(c, x->SPNameQualifier);


}

/* FUNC(zx_DEEP_CLONE_sa_BaseID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_BaseID_s* zx_DEEP_CLONE_sa_BaseID(struct zx_ctx* c, struct zx_sa_BaseID_s* x, int dup_strs)
{
  x = (struct zx_sa_BaseID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_BaseID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);
  x->SPNameQualifier = zx_clone_attr(c, x->SPNameQualifier);


  return x;
}

/* FUNC(zx_WALK_SO_sa_BaseID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_BaseID(struct zx_ctx* c, struct zx_sa_BaseID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_BaseID) */

int zx_WALK_WO_sa_BaseID(struct zx_ctx* c, struct zx_sa_BaseID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Conditions
#define EL_STRUCT zx_sa_Conditions_s
#define EL_NS     sa
#define EL_TAG    Conditions

/* FUNC(zx_FREE_sa_Conditions) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Conditions(struct zx_ctx* c, struct zx_sa_Conditions_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->NotBefore, free_strs);
  zx_free_attr(c, x->NotOnOrAfter, free_strs);

  zx_free_simple_elems(c, x->Condition, free_strs);
  {
      struct zx_sa_AudienceRestriction_s* e;
      struct zx_sa_AudienceRestriction_s* en;
      for (e = x->AudienceRestriction; e; e = en) {
	  en = (struct zx_sa_AudienceRestriction_s*)e->gg.g.n;
	  zx_FREE_sa_AudienceRestriction(c, e, free_strs);
      }
  }
  {
      struct zx_sa_OneTimeUse_s* e;
      struct zx_sa_OneTimeUse_s* en;
      for (e = x->OneTimeUse; e; e = en) {
	  en = (struct zx_sa_OneTimeUse_s*)e->gg.g.n;
	  zx_FREE_sa_OneTimeUse(c, e, free_strs);
      }
  }
  {
      struct zx_sa_ProxyRestriction_s* e;
      struct zx_sa_ProxyRestriction_s* en;
      for (e = x->ProxyRestriction; e; e = en) {
	  en = (struct zx_sa_ProxyRestriction_s*)e->gg.g.n;
	  zx_FREE_sa_ProxyRestriction(c, e, free_strs);
      }
  }
  {
      struct zx_idp_SubjectRestriction_s* e;
      struct zx_idp_SubjectRestriction_s* en;
      for (e = x->SubjectRestriction; e; e = en) {
	  en = (struct zx_idp_SubjectRestriction_s*)e->gg.g.n;
	  zx_FREE_idp_SubjectRestriction(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_Conditions) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Conditions_s* zx_NEW_sa_Conditions(struct zx_ctx* c)
{
  struct zx_sa_Conditions_s* x = ZX_ZALLOC(c, struct zx_sa_Conditions_s);
  x->gg.g.tok = zx_sa_Conditions_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Conditions) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Conditions(struct zx_ctx* c, struct zx_sa_Conditions_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->NotBefore);
  zx_dup_attr(c, x->NotOnOrAfter);

  zx_dup_strs_simple_elems(c, x->Condition);
  {
      struct zx_sa_AudienceRestriction_s* e;
      for (e = x->AudienceRestriction; e; e = (struct zx_sa_AudienceRestriction_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AudienceRestriction(c, e);
  }
  {
      struct zx_sa_OneTimeUse_s* e;
      for (e = x->OneTimeUse; e; e = (struct zx_sa_OneTimeUse_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_OneTimeUse(c, e);
  }
  {
      struct zx_sa_ProxyRestriction_s* e;
      for (e = x->ProxyRestriction; e; e = (struct zx_sa_ProxyRestriction_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_ProxyRestriction(c, e);
  }
  {
      struct zx_idp_SubjectRestriction_s* e;
      for (e = x->SubjectRestriction; e; e = (struct zx_idp_SubjectRestriction_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_SubjectRestriction(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_Conditions) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Conditions_s* zx_DEEP_CLONE_sa_Conditions(struct zx_ctx* c, struct zx_sa_Conditions_s* x, int dup_strs)
{
  x = (struct zx_sa_Conditions_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Conditions_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->NotBefore = zx_clone_attr(c, x->NotBefore);
  x->NotOnOrAfter = zx_clone_attr(c, x->NotOnOrAfter);

  x->Condition = zx_deep_clone_simple_elems(c,x->Condition, dup_strs);
  {
      struct zx_sa_AudienceRestriction_s* e;
      struct zx_sa_AudienceRestriction_s* en;
      struct zx_sa_AudienceRestriction_s* enn;
      for (enn = 0, e = x->AudienceRestriction; e; e = (struct zx_sa_AudienceRestriction_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AudienceRestriction(c, e, dup_strs);
	  if (!enn)
	      x->AudienceRestriction = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_OneTimeUse_s* e;
      struct zx_sa_OneTimeUse_s* en;
      struct zx_sa_OneTimeUse_s* enn;
      for (enn = 0, e = x->OneTimeUse; e; e = (struct zx_sa_OneTimeUse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_OneTimeUse(c, e, dup_strs);
	  if (!enn)
	      x->OneTimeUse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_ProxyRestriction_s* e;
      struct zx_sa_ProxyRestriction_s* en;
      struct zx_sa_ProxyRestriction_s* enn;
      for (enn = 0, e = x->ProxyRestriction; e; e = (struct zx_sa_ProxyRestriction_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_ProxyRestriction(c, e, dup_strs);
	  if (!enn)
	      x->ProxyRestriction = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_SubjectRestriction_s* e;
      struct zx_idp_SubjectRestriction_s* en;
      struct zx_idp_SubjectRestriction_s* enn;
      for (enn = 0, e = x->SubjectRestriction; e; e = (struct zx_idp_SubjectRestriction_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_SubjectRestriction(c, e, dup_strs);
	  if (!enn)
	      x->SubjectRestriction = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa_Conditions) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Conditions(struct zx_ctx* c, struct zx_sa_Conditions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Condition, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sa_AudienceRestriction_s* e;
      for (e = x->AudienceRestriction; e; e = (struct zx_sa_AudienceRestriction_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AudienceRestriction(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_OneTimeUse_s* e;
      for (e = x->OneTimeUse; e; e = (struct zx_sa_OneTimeUse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_OneTimeUse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_ProxyRestriction_s* e;
      for (e = x->ProxyRestriction; e; e = (struct zx_sa_ProxyRestriction_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_ProxyRestriction(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_SubjectRestriction_s* e;
      for (e = x->SubjectRestriction; e; e = (struct zx_idp_SubjectRestriction_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_SubjectRestriction(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_Conditions) */

int zx_WALK_WO_sa_Conditions(struct zx_ctx* c, struct zx_sa_Conditions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_EncryptedAssertion
#define EL_STRUCT zx_sa_EncryptedAssertion_s
#define EL_NS     sa
#define EL_TAG    EncryptedAssertion

/* FUNC(zx_FREE_sa_EncryptedAssertion) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_EncryptedAssertion(struct zx_ctx* c, struct zx_sa_EncryptedAssertion_s* x, int free_strs)
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

/* FUNC(zx_NEW_sa_EncryptedAssertion) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_EncryptedAssertion_s* zx_NEW_sa_EncryptedAssertion(struct zx_ctx* c)
{
  struct zx_sa_EncryptedAssertion_s* x = ZX_ZALLOC(c, struct zx_sa_EncryptedAssertion_s);
  x->gg.g.tok = zx_sa_EncryptedAssertion_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_EncryptedAssertion) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_EncryptedAssertion(struct zx_ctx* c, struct zx_sa_EncryptedAssertion_s* x)
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

/* FUNC(zx_DEEP_CLONE_sa_EncryptedAssertion) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_EncryptedAssertion_s* zx_DEEP_CLONE_sa_EncryptedAssertion(struct zx_ctx* c, struct zx_sa_EncryptedAssertion_s* x, int dup_strs)
{
  x = (struct zx_sa_EncryptedAssertion_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_EncryptedAssertion_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sa_EncryptedAssertion) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_EncryptedAssertion(struct zx_ctx* c, struct zx_sa_EncryptedAssertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_EncryptedAssertion) */

int zx_WALK_WO_sa_EncryptedAssertion(struct zx_ctx* c, struct zx_sa_EncryptedAssertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_EncryptedAttribute
#define EL_STRUCT zx_sa_EncryptedAttribute_s
#define EL_NS     sa
#define EL_TAG    EncryptedAttribute

/* FUNC(zx_FREE_sa_EncryptedAttribute) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_EncryptedAttribute(struct zx_ctx* c, struct zx_sa_EncryptedAttribute_s* x, int free_strs)
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

/* FUNC(zx_NEW_sa_EncryptedAttribute) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_EncryptedAttribute_s* zx_NEW_sa_EncryptedAttribute(struct zx_ctx* c)
{
  struct zx_sa_EncryptedAttribute_s* x = ZX_ZALLOC(c, struct zx_sa_EncryptedAttribute_s);
  x->gg.g.tok = zx_sa_EncryptedAttribute_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_EncryptedAttribute) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_EncryptedAttribute(struct zx_ctx* c, struct zx_sa_EncryptedAttribute_s* x)
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

/* FUNC(zx_DEEP_CLONE_sa_EncryptedAttribute) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_EncryptedAttribute_s* zx_DEEP_CLONE_sa_EncryptedAttribute(struct zx_ctx* c, struct zx_sa_EncryptedAttribute_s* x, int dup_strs)
{
  x = (struct zx_sa_EncryptedAttribute_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_EncryptedAttribute_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sa_EncryptedAttribute) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_EncryptedAttribute(struct zx_ctx* c, struct zx_sa_EncryptedAttribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_EncryptedAttribute) */

int zx_WALK_WO_sa_EncryptedAttribute(struct zx_ctx* c, struct zx_sa_EncryptedAttribute_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_EncryptedID
#define EL_STRUCT zx_sa_EncryptedID_s
#define EL_NS     sa
#define EL_TAG    EncryptedID

/* FUNC(zx_FREE_sa_EncryptedID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_EncryptedID(struct zx_ctx* c, struct zx_sa_EncryptedID_s* x, int free_strs)
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

/* FUNC(zx_NEW_sa_EncryptedID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_EncryptedID_s* zx_NEW_sa_EncryptedID(struct zx_ctx* c)
{
  struct zx_sa_EncryptedID_s* x = ZX_ZALLOC(c, struct zx_sa_EncryptedID_s);
  x->gg.g.tok = zx_sa_EncryptedID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_EncryptedID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_EncryptedID(struct zx_ctx* c, struct zx_sa_EncryptedID_s* x)
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

/* FUNC(zx_DEEP_CLONE_sa_EncryptedID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_EncryptedID_s* zx_DEEP_CLONE_sa_EncryptedID(struct zx_ctx* c, struct zx_sa_EncryptedID_s* x, int dup_strs)
{
  x = (struct zx_sa_EncryptedID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_EncryptedID_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sa_EncryptedID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_EncryptedID(struct zx_ctx* c, struct zx_sa_EncryptedID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_EncryptedID) */

int zx_WALK_WO_sa_EncryptedID(struct zx_ctx* c, struct zx_sa_EncryptedID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Evidence
#define EL_STRUCT zx_sa_Evidence_s
#define EL_NS     sa
#define EL_TAG    Evidence

/* FUNC(zx_FREE_sa_Evidence) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Evidence(struct zx_ctx* c, struct zx_sa_Evidence_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AssertionIDRef, free_strs);
  zx_free_simple_elems(c, x->AssertionURIRef, free_strs);
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

/* FUNC(zx_NEW_sa_Evidence) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Evidence_s* zx_NEW_sa_Evidence(struct zx_ctx* c)
{
  struct zx_sa_Evidence_s* x = ZX_ZALLOC(c, struct zx_sa_Evidence_s);
  x->gg.g.tok = zx_sa_Evidence_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Evidence) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Evidence(struct zx_ctx* c, struct zx_sa_Evidence_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AssertionIDRef);
  zx_dup_strs_simple_elems(c, x->AssertionURIRef);
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

/* FUNC(zx_DEEP_CLONE_sa_Evidence) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Evidence_s* zx_DEEP_CLONE_sa_Evidence(struct zx_ctx* c, struct zx_sa_Evidence_s* x, int dup_strs)
{
  x = (struct zx_sa_Evidence_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Evidence_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AssertionIDRef = zx_deep_clone_simple_elems(c,x->AssertionIDRef, dup_strs);
  x->AssertionURIRef = zx_deep_clone_simple_elems(c,x->AssertionURIRef, dup_strs);
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

/* FUNC(zx_WALK_SO_sa_Evidence) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Evidence(struct zx_ctx* c, struct zx_sa_Evidence_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AssertionIDRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AssertionURIRef, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_Evidence) */

int zx_WALK_WO_sa_Evidence(struct zx_ctx* c, struct zx_sa_Evidence_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Issuer
#define EL_STRUCT zx_sa_Issuer_s
#define EL_NS     sa
#define EL_TAG    Issuer

/* FUNC(zx_FREE_sa_Issuer) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Issuer(struct zx_ctx* c, struct zx_sa_Issuer_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);
  zx_free_attr(c, x->SPNameQualifier, free_strs);
  zx_free_attr(c, x->SPProvidedID, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_Issuer) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Issuer_s* zx_NEW_sa_Issuer(struct zx_ctx* c)
{
  struct zx_sa_Issuer_s* x = ZX_ZALLOC(c, struct zx_sa_Issuer_s);
  x->gg.g.tok = zx_sa_Issuer_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Issuer) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Issuer(struct zx_ctx* c, struct zx_sa_Issuer_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->NameQualifier);
  zx_dup_attr(c, x->SPNameQualifier);
  zx_dup_attr(c, x->SPProvidedID);


}

/* FUNC(zx_DEEP_CLONE_sa_Issuer) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Issuer_s* zx_DEEP_CLONE_sa_Issuer(struct zx_ctx* c, struct zx_sa_Issuer_s* x, int dup_strs)
{
  x = (struct zx_sa_Issuer_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Issuer_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);
  x->SPNameQualifier = zx_clone_attr(c, x->SPNameQualifier);
  x->SPProvidedID = zx_clone_attr(c, x->SPProvidedID);


  return x;
}

/* FUNC(zx_WALK_SO_sa_Issuer) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Issuer(struct zx_ctx* c, struct zx_sa_Issuer_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_Issuer) */

int zx_WALK_WO_sa_Issuer(struct zx_ctx* c, struct zx_sa_Issuer_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_NameID
#define EL_STRUCT zx_sa_NameID_s
#define EL_NS     sa
#define EL_TAG    NameID

/* FUNC(zx_FREE_sa_NameID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_NameID(struct zx_ctx* c, struct zx_sa_NameID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);
  zx_free_attr(c, x->SPNameQualifier, free_strs);
  zx_free_attr(c, x->SPProvidedID, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_NameID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_NameID_s* zx_NEW_sa_NameID(struct zx_ctx* c)
{
  struct zx_sa_NameID_s* x = ZX_ZALLOC(c, struct zx_sa_NameID_s);
  x->gg.g.tok = zx_sa_NameID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_NameID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_NameID(struct zx_ctx* c, struct zx_sa_NameID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->NameQualifier);
  zx_dup_attr(c, x->SPNameQualifier);
  zx_dup_attr(c, x->SPProvidedID);


}

/* FUNC(zx_DEEP_CLONE_sa_NameID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_NameID_s* zx_DEEP_CLONE_sa_NameID(struct zx_ctx* c, struct zx_sa_NameID_s* x, int dup_strs)
{
  x = (struct zx_sa_NameID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_NameID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);
  x->SPNameQualifier = zx_clone_attr(c, x->SPNameQualifier);
  x->SPProvidedID = zx_clone_attr(c, x->SPProvidedID);


  return x;
}

/* FUNC(zx_WALK_SO_sa_NameID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_NameID(struct zx_ctx* c, struct zx_sa_NameID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_NameID) */

int zx_WALK_WO_sa_NameID(struct zx_ctx* c, struct zx_sa_NameID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_OneTimeUse
#define EL_STRUCT zx_sa_OneTimeUse_s
#define EL_NS     sa
#define EL_TAG    OneTimeUse

/* FUNC(zx_FREE_sa_OneTimeUse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_OneTimeUse(struct zx_ctx* c, struct zx_sa_OneTimeUse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_OneTimeUse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_OneTimeUse_s* zx_NEW_sa_OneTimeUse(struct zx_ctx* c)
{
  struct zx_sa_OneTimeUse_s* x = ZX_ZALLOC(c, struct zx_sa_OneTimeUse_s);
  x->gg.g.tok = zx_sa_OneTimeUse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_OneTimeUse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_OneTimeUse(struct zx_ctx* c, struct zx_sa_OneTimeUse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_sa_OneTimeUse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_OneTimeUse_s* zx_DEEP_CLONE_sa_OneTimeUse(struct zx_ctx* c, struct zx_sa_OneTimeUse_s* x, int dup_strs)
{
  x = (struct zx_sa_OneTimeUse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_OneTimeUse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_sa_OneTimeUse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_OneTimeUse(struct zx_ctx* c, struct zx_sa_OneTimeUse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_OneTimeUse) */

int zx_WALK_WO_sa_OneTimeUse(struct zx_ctx* c, struct zx_sa_OneTimeUse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_ProxyRestriction
#define EL_STRUCT zx_sa_ProxyRestriction_s
#define EL_NS     sa
#define EL_TAG    ProxyRestriction

/* FUNC(zx_FREE_sa_ProxyRestriction) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_ProxyRestriction(struct zx_ctx* c, struct zx_sa_ProxyRestriction_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Count, free_strs);

  zx_free_simple_elems(c, x->Audience, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_ProxyRestriction) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_ProxyRestriction_s* zx_NEW_sa_ProxyRestriction(struct zx_ctx* c)
{
  struct zx_sa_ProxyRestriction_s* x = ZX_ZALLOC(c, struct zx_sa_ProxyRestriction_s);
  x->gg.g.tok = zx_sa_ProxyRestriction_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_ProxyRestriction) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_ProxyRestriction(struct zx_ctx* c, struct zx_sa_ProxyRestriction_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Count);

  zx_dup_strs_simple_elems(c, x->Audience);

}

/* FUNC(zx_DEEP_CLONE_sa_ProxyRestriction) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_ProxyRestriction_s* zx_DEEP_CLONE_sa_ProxyRestriction(struct zx_ctx* c, struct zx_sa_ProxyRestriction_s* x, int dup_strs)
{
  x = (struct zx_sa_ProxyRestriction_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_ProxyRestriction_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Count = zx_clone_attr(c, x->Count);

  x->Audience = zx_deep_clone_simple_elems(c,x->Audience, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sa_ProxyRestriction) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_ProxyRestriction(struct zx_ctx* c, struct zx_sa_ProxyRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_ProxyRestriction) */

int zx_WALK_WO_sa_ProxyRestriction(struct zx_ctx* c, struct zx_sa_ProxyRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Statement
#define EL_STRUCT zx_sa_Statement_s
#define EL_NS     sa
#define EL_TAG    Statement

/* FUNC(zx_FREE_sa_Statement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Statement(struct zx_ctx* c, struct zx_sa_Statement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);

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

/* FUNC(zx_NEW_sa_Statement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Statement_s* zx_NEW_sa_Statement(struct zx_ctx* c)
{
  struct zx_sa_Statement_s* x = ZX_ZALLOC(c, struct zx_sa_Statement_s);
  x->gg.g.tok = zx_sa_Statement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Statement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Statement(struct zx_ctx* c, struct zx_sa_Statement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);

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

/* FUNC(zx_DEEP_CLONE_sa_Statement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Statement_s* zx_DEEP_CLONE_sa_Statement(struct zx_ctx* c, struct zx_sa_Statement_s* x, int dup_strs)
{
  x = (struct zx_sa_Statement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Statement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);

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

/* FUNC(zx_WALK_SO_sa_Statement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Statement(struct zx_ctx* c, struct zx_sa_Statement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_Statement) */

int zx_WALK_WO_sa_Statement(struct zx_ctx* c, struct zx_sa_Statement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_Subject
#define EL_STRUCT zx_sa_Subject_s
#define EL_NS     sa
#define EL_TAG    Subject

/* FUNC(zx_FREE_sa_Subject) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_Subject(struct zx_ctx* c, struct zx_sa_Subject_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


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
      struct zx_sa_SubjectConfirmation_s* e;
      struct zx_sa_SubjectConfirmation_s* en;
      for (e = x->SubjectConfirmation; e; e = en) {
	  en = (struct zx_sa_SubjectConfirmation_s*)e->gg.g.n;
	  zx_FREE_sa_SubjectConfirmation(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_Subject) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_Subject_s* zx_NEW_sa_Subject(struct zx_ctx* c)
{
  struct zx_sa_Subject_s* x = ZX_ZALLOC(c, struct zx_sa_Subject_s);
  x->gg.g.tok = zx_sa_Subject_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_Subject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_Subject(struct zx_ctx* c, struct zx_sa_Subject_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


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
      struct zx_sa_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa_SubjectConfirmation_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_SubjectConfirmation(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_Subject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_Subject_s* zx_DEEP_CLONE_sa_Subject(struct zx_ctx* c, struct zx_sa_Subject_s* x, int dup_strs)
{
  x = (struct zx_sa_Subject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_Subject_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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
      struct zx_sa_SubjectConfirmation_s* e;
      struct zx_sa_SubjectConfirmation_s* en;
      struct zx_sa_SubjectConfirmation_s* enn;
      for (enn = 0, e = x->SubjectConfirmation; e; e = (struct zx_sa_SubjectConfirmation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_SubjectConfirmation(c, e, dup_strs);
	  if (!enn)
	      x->SubjectConfirmation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa_Subject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_Subject(struct zx_ctx* c, struct zx_sa_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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
      struct zx_sa_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa_SubjectConfirmation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_SubjectConfirmation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_Subject) */

int zx_WALK_WO_sa_Subject(struct zx_ctx* c, struct zx_sa_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_SubjectConfirmation
#define EL_STRUCT zx_sa_SubjectConfirmation_s
#define EL_NS     sa
#define EL_TAG    SubjectConfirmation

/* FUNC(zx_FREE_sa_SubjectConfirmation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_SubjectConfirmation(struct zx_ctx* c, struct zx_sa_SubjectConfirmation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Method, free_strs);

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
      struct zx_sa_SubjectConfirmationData_s* e;
      struct zx_sa_SubjectConfirmationData_s* en;
      for (e = x->SubjectConfirmationData; e; e = en) {
	  en = (struct zx_sa_SubjectConfirmationData_s*)e->gg.g.n;
	  zx_FREE_sa_SubjectConfirmationData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_SubjectConfirmation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_SubjectConfirmation_s* zx_NEW_sa_SubjectConfirmation(struct zx_ctx* c)
{
  struct zx_sa_SubjectConfirmation_s* x = ZX_ZALLOC(c, struct zx_sa_SubjectConfirmation_s);
  x->gg.g.tok = zx_sa_SubjectConfirmation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_SubjectConfirmation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_SubjectConfirmation(struct zx_ctx* c, struct zx_sa_SubjectConfirmation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Method);

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
      struct zx_sa_SubjectConfirmationData_s* e;
      for (e = x->SubjectConfirmationData; e; e = (struct zx_sa_SubjectConfirmationData_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_SubjectConfirmationData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_SubjectConfirmation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_SubjectConfirmation_s* zx_DEEP_CLONE_sa_SubjectConfirmation(struct zx_ctx* c, struct zx_sa_SubjectConfirmation_s* x, int dup_strs)
{
  x = (struct zx_sa_SubjectConfirmation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_SubjectConfirmation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Method = zx_clone_attr(c, x->Method);

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
      struct zx_sa_SubjectConfirmationData_s* e;
      struct zx_sa_SubjectConfirmationData_s* en;
      struct zx_sa_SubjectConfirmationData_s* enn;
      for (enn = 0, e = x->SubjectConfirmationData; e; e = (struct zx_sa_SubjectConfirmationData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_SubjectConfirmationData(c, e, dup_strs);
	  if (!enn)
	      x->SubjectConfirmationData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sa_SubjectConfirmation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_SubjectConfirmation(struct zx_ctx* c, struct zx_sa_SubjectConfirmation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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
      struct zx_sa_SubjectConfirmationData_s* e;
      for (e = x->SubjectConfirmationData; e; e = (struct zx_sa_SubjectConfirmationData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_SubjectConfirmationData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_SubjectConfirmation) */

int zx_WALK_WO_sa_SubjectConfirmation(struct zx_ctx* c, struct zx_sa_SubjectConfirmation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_SubjectConfirmationData
#define EL_STRUCT zx_sa_SubjectConfirmationData_s
#define EL_NS     sa
#define EL_TAG    SubjectConfirmationData

/* FUNC(zx_FREE_sa_SubjectConfirmationData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_SubjectConfirmationData(struct zx_ctx* c, struct zx_sa_SubjectConfirmationData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Address, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->NotBefore, free_strs);
  zx_free_attr(c, x->NotOnOrAfter, free_strs);
  zx_free_attr(c, x->Recipient, free_strs);
  zx_free_attr(c, x->type, free_strs);

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

/* FUNC(zx_NEW_sa_SubjectConfirmationData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_SubjectConfirmationData_s* zx_NEW_sa_SubjectConfirmationData(struct zx_ctx* c)
{
  struct zx_sa_SubjectConfirmationData_s* x = ZX_ZALLOC(c, struct zx_sa_SubjectConfirmationData_s);
  x->gg.g.tok = zx_sa_SubjectConfirmationData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_SubjectConfirmationData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_SubjectConfirmationData(struct zx_ctx* c, struct zx_sa_SubjectConfirmationData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Address);
  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->NotBefore);
  zx_dup_attr(c, x->NotOnOrAfter);
  zx_dup_attr(c, x->Recipient);
  zx_dup_attr(c, x->type);

  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_SubjectConfirmationData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_SubjectConfirmationData_s* zx_DEEP_CLONE_sa_SubjectConfirmationData(struct zx_ctx* c, struct zx_sa_SubjectConfirmationData_s* x, int dup_strs)
{
  x = (struct zx_sa_SubjectConfirmationData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_SubjectConfirmationData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Address = zx_clone_attr(c, x->Address);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->NotBefore = zx_clone_attr(c, x->NotBefore);
  x->NotOnOrAfter = zx_clone_attr(c, x->NotOnOrAfter);
  x->Recipient = zx_clone_attr(c, x->Recipient);
  x->type = zx_clone_attr(c, x->type);

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

/* FUNC(zx_WALK_SO_sa_SubjectConfirmationData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_SubjectConfirmationData(struct zx_ctx* c, struct zx_sa_SubjectConfirmationData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sa_SubjectConfirmationData) */

int zx_WALK_WO_sa_SubjectConfirmationData(struct zx_ctx* c, struct zx_sa_SubjectConfirmationData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_SubjectLocality
#define EL_STRUCT zx_sa_SubjectLocality_s
#define EL_NS     sa
#define EL_TAG    SubjectLocality

/* FUNC(zx_FREE_sa_SubjectLocality) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_SubjectLocality(struct zx_ctx* c, struct zx_sa_SubjectLocality_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Address, free_strs);
  zx_free_attr(c, x->DNSName, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sa_SubjectLocality) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_SubjectLocality_s* zx_NEW_sa_SubjectLocality(struct zx_ctx* c)
{
  struct zx_sa_SubjectLocality_s* x = ZX_ZALLOC(c, struct zx_sa_SubjectLocality_s);
  x->gg.g.tok = zx_sa_SubjectLocality_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_SubjectLocality) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_SubjectLocality(struct zx_ctx* c, struct zx_sa_SubjectLocality_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Address);
  zx_dup_attr(c, x->DNSName);


}

/* FUNC(zx_DEEP_CLONE_sa_SubjectLocality) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_SubjectLocality_s* zx_DEEP_CLONE_sa_SubjectLocality(struct zx_ctx* c, struct zx_sa_SubjectLocality_s* x, int dup_strs)
{
  x = (struct zx_sa_SubjectLocality_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_SubjectLocality_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Address = zx_clone_attr(c, x->Address);
  x->DNSName = zx_clone_attr(c, x->DNSName);


  return x;
}

/* FUNC(zx_WALK_SO_sa_SubjectLocality) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_SubjectLocality(struct zx_ctx* c, struct zx_sa_SubjectLocality_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_SubjectLocality) */

int zx_WALK_WO_sa_SubjectLocality(struct zx_ctx* c, struct zx_sa_SubjectLocality_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sa_TestElem
#define EL_STRUCT zx_sa_TestElem_s
#define EL_NS     sa
#define EL_TAG    TestElem

/* FUNC(zx_FREE_sa_TestElem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sa_TestElem(struct zx_ctx* c, struct zx_sa_TestElem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


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

/* FUNC(zx_NEW_sa_TestElem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sa_TestElem_s* zx_NEW_sa_TestElem(struct zx_ctx* c)
{
  struct zx_sa_TestElem_s* x = ZX_ZALLOC(c, struct zx_sa_TestElem_s);
  x->gg.g.tok = zx_sa_TestElem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sa_TestElem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sa_TestElem(struct zx_ctx* c, struct zx_sa_TestElem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AttributeValue(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sa_TestElem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sa_TestElem_s* zx_DEEP_CLONE_sa_TestElem(struct zx_ctx* c, struct zx_sa_TestElem_s* x, int dup_strs)
{
  x = (struct zx_sa_TestElem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sa_TestElem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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

/* FUNC(zx_WALK_SO_sa_TestElem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sa_TestElem(struct zx_ctx* c, struct zx_sa_TestElem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sa_TestElem) */

int zx_WALK_WO_sa_TestElem(struct zx_ctx* c, struct zx_sa_TestElem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sa-aux.c */
