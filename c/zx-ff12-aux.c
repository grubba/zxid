/* c/zx-ff12-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ff12-data.h"



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

#define EL_NAME   ff12_Assertion
#define EL_STRUCT zx_ff12_Assertion_s
#define EL_NS     ff12
#define EL_TAG    Assertion

/* FUNC(zx_FREE_ff12_Assertion) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AssertionID, free_strs);
  zx_free_attr(c, x->InResponseTo, free_strs);
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

/* FUNC(zx_NEW_ff12_Assertion) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_Assertion_s* zx_NEW_ff12_Assertion(struct zx_ctx* c)
{
  struct zx_ff12_Assertion_s* x = ZX_ZALLOC(c, struct zx_ff12_Assertion_s);
  x->gg.g.tok = zx_ff12_Assertion_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_Assertion) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AssertionID);
  zx_dup_attr(c, x->InResponseTo);
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

/* FUNC(zx_DEEP_CLONE_ff12_Assertion) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_Assertion_s* zx_DEEP_CLONE_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x, int dup_strs)
{
  x = (struct zx_ff12_Assertion_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_Assertion_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AssertionID = zx_clone_attr(c, x->AssertionID);
  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
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

/* FUNC(zx_WALK_SO_ff12_Assertion) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_Assertion) */

int zx_WALK_WO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_AuthenticationStatement
#define EL_STRUCT zx_ff12_AuthenticationStatement_s
#define EL_NS     ff12
#define EL_TAG    AuthenticationStatement

/* FUNC(zx_FREE_ff12_AuthenticationStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AuthenticationInstant, free_strs);
  zx_free_attr(c, x->AuthenticationMethod, free_strs);
  zx_free_attr(c, x->ReauthenticateOnOrAfter, free_strs);
  zx_free_attr(c, x->SessionIndex, free_strs);

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
  {
      struct zx_ff12_AuthnContext_s* e;
      struct zx_ff12_AuthnContext_s* en;
      for (e = x->AuthnContext; e; e = en) {
	  en = (struct zx_ff12_AuthnContext_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_AuthenticationStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_AuthenticationStatement_s* zx_NEW_ff12_AuthenticationStatement(struct zx_ctx* c)
{
  struct zx_ff12_AuthenticationStatement_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthenticationStatement_s);
  x->gg.g.tok = zx_ff12_AuthenticationStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_AuthenticationStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AuthenticationInstant);
  zx_dup_attr(c, x->AuthenticationMethod);
  zx_dup_attr(c, x->ReauthenticateOnOrAfter);
  zx_dup_attr(c, x->SessionIndex);

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
  {
      struct zx_ff12_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_ff12_AuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_AuthenticationStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_AuthenticationStatement_s* zx_DEEP_CLONE_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x, int dup_strs)
{
  x = (struct zx_ff12_AuthenticationStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_AuthenticationStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AuthenticationInstant = zx_clone_attr(c, x->AuthenticationInstant);
  x->AuthenticationMethod = zx_clone_attr(c, x->AuthenticationMethod);
  x->ReauthenticateOnOrAfter = zx_clone_attr(c, x->ReauthenticateOnOrAfter);
  x->SessionIndex = zx_clone_attr(c, x->SessionIndex);

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
  {
      struct zx_ff12_AuthnContext_s* e;
      struct zx_ff12_AuthnContext_s* en;
      struct zx_ff12_AuthnContext_s* enn;
      for (enn = 0, e = x->AuthnContext; e; e = (struct zx_ff12_AuthnContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnContext(c, e, dup_strs);
	  if (!enn)
	      x->AuthnContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ff12_AuthenticationStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_ff12_AuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_AuthenticationStatement) */

int zx_WALK_WO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_AuthnContext
#define EL_STRUCT zx_ff12_AuthnContext_s
#define EL_NS     ff12
#define EL_TAG    AuthnContext

/* FUNC(zx_FREE_ff12_AuthnContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AuthnContextClassRef, free_strs);
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      struct zx_ac_AuthenticationContextStatement_s* en;
      for (e = x->AuthenticationContextStatement; e; e = en) {
	  en = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n;
	  zx_FREE_ac_AuthenticationContextStatement(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AuthnContextStatementRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_AuthnContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_AuthnContext_s* zx_NEW_ff12_AuthnContext(struct zx_ctx* c)
{
  struct zx_ff12_AuthnContext_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnContext_s);
  x->gg.g.tok = zx_ff12_AuthnContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_AuthnContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AuthnContextClassRef);
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      for (e = x->AuthenticationContextStatement; e; e = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_AuthenticationContextStatement(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AuthnContextStatementRef);

}

/* FUNC(zx_DEEP_CLONE_ff12_AuthnContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_AuthnContext_s* zx_DEEP_CLONE_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x, int dup_strs)
{
  x = (struct zx_ff12_AuthnContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_AuthnContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AuthnContextClassRef = zx_deep_clone_simple_elems(c,x->AuthnContextClassRef, dup_strs);
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      struct zx_ac_AuthenticationContextStatement_s* en;
      struct zx_ac_AuthenticationContextStatement_s* enn;
      for (enn = 0, e = x->AuthenticationContextStatement; e; e = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_AuthenticationContextStatement(c, e, dup_strs);
	  if (!enn)
	      x->AuthenticationContextStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AuthnContextStatementRef = zx_deep_clone_simple_elems(c,x->AuthnContextStatementRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_AuthnContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      for (e = x->AuthenticationContextStatement; e; e = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_AuthenticationContextStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AuthnContextStatementRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_AuthnContext) */

int zx_WALK_WO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_AuthnRequest
#define EL_STRUCT zx_ff12_AuthnRequest_s
#define EL_NS     ff12
#define EL_TAG    AuthnRequest

/* FUNC(zx_FREE_ff12_AuthnRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->RequestID, free_strs);
  zx_free_attr(c, x->consent, free_strs);

  zx_free_simple_elems(c, x->RespondWith, free_strs);
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  zx_free_simple_elems(c, x->AffiliationID, free_strs);
  zx_free_simple_elems(c, x->NameIDPolicy, free_strs);
  zx_free_simple_elems(c, x->ForceAuthn, free_strs);
  zx_free_simple_elems(c, x->IsPassive, free_strs);
  zx_free_simple_elems(c, x->ProtocolProfile, free_strs);
  zx_free_simple_elems(c, x->AssertionConsumerServiceID, free_strs);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      struct zx_ff12_RequestAuthnContext_s* en;
      for (e = x->RequestAuthnContext; e; e = en) {
	  en = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n;
	  zx_FREE_ff12_RequestAuthnContext(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->RelayState, free_strs);
  {
      struct zx_ff12_Scoping_s* e;
      struct zx_ff12_Scoping_s* en;
      for (e = x->Scoping; e; e = en) {
	  en = (struct zx_ff12_Scoping_s*)e->gg.g.n;
	  zx_FREE_ff12_Scoping(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_AuthnRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_AuthnRequest_s* zx_NEW_ff12_AuthnRequest(struct zx_ctx* c)
{
  struct zx_ff12_AuthnRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnRequest_s);
  x->gg.g.tok = zx_ff12_AuthnRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_AuthnRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->RequestID);
  zx_dup_attr(c, x->consent);

  zx_dup_strs_simple_elems(c, x->RespondWith);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  zx_dup_strs_simple_elems(c, x->AffiliationID);
  zx_dup_strs_simple_elems(c, x->NameIDPolicy);
  zx_dup_strs_simple_elems(c, x->ForceAuthn);
  zx_dup_strs_simple_elems(c, x->IsPassive);
  zx_dup_strs_simple_elems(c, x->ProtocolProfile);
  zx_dup_strs_simple_elems(c, x->AssertionConsumerServiceID);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_RequestAuthnContext(c, e);
  }
  zx_dup_strs_simple_elems(c, x->RelayState);
  {
      struct zx_ff12_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_ff12_Scoping_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Scoping(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_AuthnRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_AuthnRequest_s* zx_DEEP_CLONE_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x, int dup_strs)
{
  x = (struct zx_ff12_AuthnRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_AuthnRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->RequestID = zx_clone_attr(c, x->RequestID);
  x->consent = zx_clone_attr(c, x->consent);

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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  x->AffiliationID = zx_deep_clone_simple_elems(c,x->AffiliationID, dup_strs);
  x->NameIDPolicy = zx_deep_clone_simple_elems(c,x->NameIDPolicy, dup_strs);
  x->ForceAuthn = zx_deep_clone_simple_elems(c,x->ForceAuthn, dup_strs);
  x->IsPassive = zx_deep_clone_simple_elems(c,x->IsPassive, dup_strs);
  x->ProtocolProfile = zx_deep_clone_simple_elems(c,x->ProtocolProfile, dup_strs);
  x->AssertionConsumerServiceID = zx_deep_clone_simple_elems(c,x->AssertionConsumerServiceID, dup_strs);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      struct zx_ff12_RequestAuthnContext_s* en;
      struct zx_ff12_RequestAuthnContext_s* enn;
      for (enn = 0, e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_RequestAuthnContext(c, e, dup_strs);
	  if (!enn)
	      x->RequestAuthnContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->RelayState = zx_deep_clone_simple_elems(c,x->RelayState, dup_strs);
  {
      struct zx_ff12_Scoping_s* e;
      struct zx_ff12_Scoping_s* en;
      struct zx_ff12_Scoping_s* enn;
      for (enn = 0, e = x->Scoping; e; e = (struct zx_ff12_Scoping_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Scoping(c, e, dup_strs);
	  if (!enn)
	      x->Scoping = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ff12_AuthnRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AffiliationID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->NameIDPolicy, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ForceAuthn, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->IsPassive, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ProtocolProfile, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AssertionConsumerServiceID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_RequestAuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->RelayState, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_ff12_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_ff12_Scoping_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Scoping(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_AuthnRequest) */

int zx_WALK_WO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_AuthnRequestEnvelope
#define EL_STRUCT zx_ff12_AuthnRequestEnvelope_s
#define EL_NS     ff12
#define EL_TAG    AuthnRequestEnvelope

/* FUNC(zx_FREE_ff12_AuthnRequestEnvelope) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      struct zx_ff12_AuthnRequest_s* en;
      for (e = x->AuthnRequest; e; e = en) {
	  en = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnRequest(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  zx_free_simple_elems(c, x->ProviderName, free_strs);
  zx_free_simple_elems(c, x->AssertionConsumerServiceURL, free_strs);
  {
      struct zx_ff12_IDPList_s* e;
      struct zx_ff12_IDPList_s* en;
      for (e = x->IDPList; e; e = en) {
	  en = (struct zx_ff12_IDPList_s*)e->gg.g.n;
	  zx_FREE_ff12_IDPList(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->IsPassive, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_AuthnRequestEnvelope) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_AuthnRequestEnvelope_s* zx_NEW_ff12_AuthnRequestEnvelope(struct zx_ctx* c)
{
  struct zx_ff12_AuthnRequestEnvelope_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnRequestEnvelope_s);
  x->gg.g.tok = zx_ff12_AuthnRequestEnvelope_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_AuthnRequestEnvelope) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnRequest(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  zx_dup_strs_simple_elems(c, x->ProviderName);
  zx_dup_strs_simple_elems(c, x->AssertionConsumerServiceURL);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_IDPList(c, e);
  }
  zx_dup_strs_simple_elems(c, x->IsPassive);

}

/* FUNC(zx_DEEP_CLONE_ff12_AuthnRequestEnvelope) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_AuthnRequestEnvelope_s* zx_DEEP_CLONE_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x, int dup_strs)
{
  x = (struct zx_ff12_AuthnRequestEnvelope_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_AuthnRequestEnvelope_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      struct zx_ff12_AuthnRequest_s* en;
      struct zx_ff12_AuthnRequest_s* enn;
      for (enn = 0, e = x->AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnRequest(c, e, dup_strs);
	  if (!enn)
	      x->AuthnRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  x->ProviderName = zx_deep_clone_simple_elems(c,x->ProviderName, dup_strs);
  x->AssertionConsumerServiceURL = zx_deep_clone_simple_elems(c,x->AssertionConsumerServiceURL, dup_strs);
  {
      struct zx_ff12_IDPList_s* e;
      struct zx_ff12_IDPList_s* en;
      struct zx_ff12_IDPList_s* enn;
      for (enn = 0, e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_IDPList(c, e, dup_strs);
	  if (!enn)
	      x->IDPList = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->IsPassive = zx_deep_clone_simple_elems(c,x->IsPassive, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_AuthnRequestEnvelope) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ProviderName, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AssertionConsumerServiceURL, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_IDPList(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->IsPassive, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_AuthnRequestEnvelope) */

int zx_WALK_WO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_AuthnResponse
#define EL_STRUCT zx_ff12_AuthnResponse_s
#define EL_NS     ff12
#define EL_TAG    AuthnResponse

/* FUNC(zx_FREE_ff12_AuthnResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->InResponseTo, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->Recipient, free_strs);
  zx_free_attr(c, x->ResponseID, free_strs);
  zx_free_attr(c, x->consent, free_strs);

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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  zx_free_simple_elems(c, x->RelayState, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_AuthnResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_AuthnResponse_s* zx_NEW_ff12_AuthnResponse(struct zx_ctx* c)
{
  struct zx_ff12_AuthnResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnResponse_s);
  x->gg.g.tok = zx_ff12_AuthnResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_AuthnResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->InResponseTo);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->Recipient);
  zx_dup_attr(c, x->ResponseID);
  zx_dup_attr(c, x->consent);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  zx_dup_strs_simple_elems(c, x->RelayState);

}

/* FUNC(zx_DEEP_CLONE_ff12_AuthnResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_AuthnResponse_s* zx_DEEP_CLONE_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x, int dup_strs)
{
  x = (struct zx_ff12_AuthnResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_AuthnResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->InResponseTo = zx_clone_attr(c, x->InResponseTo);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->Recipient = zx_clone_attr(c, x->Recipient);
  x->ResponseID = zx_clone_attr(c, x->ResponseID);
  x->consent = zx_clone_attr(c, x->consent);

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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  x->RelayState = zx_deep_clone_simple_elems(c,x->RelayState, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_AuthnResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RelayState, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_AuthnResponse) */

int zx_WALK_WO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_AuthnResponseEnvelope
#define EL_STRUCT zx_ff12_AuthnResponseEnvelope_s
#define EL_NS     ff12
#define EL_TAG    AuthnResponseEnvelope

/* FUNC(zx_FREE_ff12_AuthnResponseEnvelope) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      struct zx_ff12_AuthnResponse_s* en;
      for (e = x->AuthnResponse; e; e = en) {
	  en = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnResponse(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AssertionConsumerServiceURL, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_AuthnResponseEnvelope) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_AuthnResponseEnvelope_s* zx_NEW_ff12_AuthnResponseEnvelope(struct zx_ctx* c)
{
  struct zx_ff12_AuthnResponseEnvelope_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnResponseEnvelope_s);
  x->gg.g.tok = zx_ff12_AuthnResponseEnvelope_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_AuthnResponseEnvelope) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnResponse(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AssertionConsumerServiceURL);

}

/* FUNC(zx_DEEP_CLONE_ff12_AuthnResponseEnvelope) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_AuthnResponseEnvelope_s* zx_DEEP_CLONE_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x, int dup_strs)
{
  x = (struct zx_ff12_AuthnResponseEnvelope_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_AuthnResponseEnvelope_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      struct zx_ff12_AuthnResponse_s* en;
      struct zx_ff12_AuthnResponse_s* enn;
      for (enn = 0, e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnResponse(c, e, dup_strs);
	  if (!enn)
	      x->AuthnResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AssertionConsumerServiceURL = zx_deep_clone_simple_elems(c,x->AssertionConsumerServiceURL, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_AuthnResponseEnvelope) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AssertionConsumerServiceURL, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_AuthnResponseEnvelope) */

int zx_WALK_WO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_EncryptableNameIdentifier
#define EL_STRUCT zx_ff12_EncryptableNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    EncryptableNameIdentifier

/* FUNC(zx_FREE_ff12_EncryptableNameIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);
  zx_free_attr(c, x->Nonce, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_EncryptableNameIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_EncryptableNameIdentifier_s* zx_NEW_ff12_EncryptableNameIdentifier(struct zx_ctx* c)
{
  struct zx_ff12_EncryptableNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_EncryptableNameIdentifier_s);
  x->gg.g.tok = zx_ff12_EncryptableNameIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_EncryptableNameIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->NameQualifier);
  zx_dup_attr(c, x->Nonce);


}

/* FUNC(zx_DEEP_CLONE_ff12_EncryptableNameIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_EncryptableNameIdentifier_s* zx_DEEP_CLONE_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x, int dup_strs)
{
  x = (struct zx_ff12_EncryptableNameIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_EncryptableNameIdentifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);
  x->Nonce = zx_clone_attr(c, x->Nonce);


  return x;
}

/* FUNC(zx_WALK_SO_ff12_EncryptableNameIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_EncryptableNameIdentifier) */

int zx_WALK_WO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_EncryptedNameIdentifier
#define EL_STRUCT zx_ff12_EncryptedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    EncryptedNameIdentifier

/* FUNC(zx_FREE_ff12_EncryptedNameIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x, int free_strs)
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

/* FUNC(zx_NEW_ff12_EncryptedNameIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_EncryptedNameIdentifier_s* zx_NEW_ff12_EncryptedNameIdentifier(struct zx_ctx* c)
{
  struct zx_ff12_EncryptedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_EncryptedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_EncryptedNameIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_EncryptedNameIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x)
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

/* FUNC(zx_DEEP_CLONE_ff12_EncryptedNameIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_EncryptedNameIdentifier_s* zx_DEEP_CLONE_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x, int dup_strs)
{
  x = (struct zx_ff12_EncryptedNameIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_EncryptedNameIdentifier_s), dup_strs);
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

/* FUNC(zx_WALK_SO_ff12_EncryptedNameIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_EncryptedNameIdentifier) */

int zx_WALK_WO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_Extension
#define EL_STRUCT zx_ff12_Extension_s
#define EL_NS     ff12
#define EL_TAG    Extension

/* FUNC(zx_FREE_ff12_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_Extension_s* zx_NEW_ff12_Extension(struct zx_ctx* c)
{
  struct zx_ff12_Extension_s* x = ZX_ZALLOC(c, struct zx_ff12_Extension_s);
  x->gg.g.tok = zx_ff12_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_ff12_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_Extension_s* zx_DEEP_CLONE_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x, int dup_strs)
{
  x = (struct zx_ff12_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_ff12_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_Extension) */

int zx_WALK_WO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_FederationTerminationNotification
#define EL_STRUCT zx_ff12_FederationTerminationNotification_s
#define EL_NS     ff12
#define EL_TAG    FederationTerminationNotification

/* FUNC(zx_FREE_ff12_FederationTerminationNotification) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->RequestID, free_strs);
  zx_free_attr(c, x->consent, free_strs);

  zx_free_simple_elems(c, x->RespondWith, free_strs);
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_sa11_NameIdentifier_s* e;
      struct zx_sa11_NameIdentifier_s* en;
      for (e = x->NameIdentifier; e; e = en) {
	  en = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n;
	  zx_FREE_sa11_NameIdentifier(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_FederationTerminationNotification) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_FederationTerminationNotification_s* zx_NEW_ff12_FederationTerminationNotification(struct zx_ctx* c)
{
  struct zx_ff12_FederationTerminationNotification_s* x = ZX_ZALLOC(c, struct zx_ff12_FederationTerminationNotification_s);
  x->gg.g.tok = zx_ff12_FederationTerminationNotification_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_FederationTerminationNotification) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->RequestID);
  zx_dup_attr(c, x->consent);

  zx_dup_strs_simple_elems(c, x->RespondWith);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_NameIdentifier(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_FederationTerminationNotification) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_FederationTerminationNotification_s* zx_DEEP_CLONE_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x, int dup_strs)
{
  x = (struct zx_ff12_FederationTerminationNotification_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_FederationTerminationNotification_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->RequestID = zx_clone_attr(c, x->RequestID);
  x->consent = zx_clone_attr(c, x->consent);

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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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

  return x;
}

/* FUNC(zx_WALK_SO_ff12_FederationTerminationNotification) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_FederationTerminationNotification) */

int zx_WALK_WO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_IDPEntries
#define EL_STRUCT zx_ff12_IDPEntries_s
#define EL_NS     ff12
#define EL_TAG    IDPEntries

/* FUNC(zx_FREE_ff12_IDPEntries) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_IDPEntry_s* e;
      struct zx_ff12_IDPEntry_s* en;
      for (e = x->IDPEntry; e; e = en) {
	  en = (struct zx_ff12_IDPEntry_s*)e->gg.g.n;
	  zx_FREE_ff12_IDPEntry(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_IDPEntries) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_IDPEntries_s* zx_NEW_ff12_IDPEntries(struct zx_ctx* c)
{
  struct zx_ff12_IDPEntries_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPEntries_s);
  x->gg.g.tok = zx_ff12_IDPEntries_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_IDPEntries) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_ff12_IDPEntry_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_IDPEntry(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_IDPEntries) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_IDPEntries_s* zx_DEEP_CLONE_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x, int dup_strs)
{
  x = (struct zx_ff12_IDPEntries_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_IDPEntries_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_IDPEntry_s* e;
      struct zx_ff12_IDPEntry_s* en;
      struct zx_ff12_IDPEntry_s* enn;
      for (enn = 0, e = x->IDPEntry; e; e = (struct zx_ff12_IDPEntry_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_IDPEntry(c, e, dup_strs);
	  if (!enn)
	      x->IDPEntry = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ff12_IDPEntries) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ff12_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_ff12_IDPEntry_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_IDPEntry(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_IDPEntries) */

int zx_WALK_WO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_IDPEntry
#define EL_STRUCT zx_ff12_IDPEntry_s
#define EL_NS     ff12
#define EL_TAG    IDPEntry

/* FUNC(zx_FREE_ff12_IDPEntry) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->ProviderID, free_strs);
  zx_free_simple_elems(c, x->ProviderName, free_strs);
  zx_free_simple_elems(c, x->Loc, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_IDPEntry) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_IDPEntry_s* zx_NEW_ff12_IDPEntry(struct zx_ctx* c)
{
  struct zx_ff12_IDPEntry_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPEntry_s);
  x->gg.g.tok = zx_ff12_IDPEntry_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_IDPEntry) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->ProviderID);
  zx_dup_strs_simple_elems(c, x->ProviderName);
  zx_dup_strs_simple_elems(c, x->Loc);

}

/* FUNC(zx_DEEP_CLONE_ff12_IDPEntry) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_IDPEntry_s* zx_DEEP_CLONE_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x, int dup_strs)
{
  x = (struct zx_ff12_IDPEntry_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_IDPEntry_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  x->ProviderName = zx_deep_clone_simple_elems(c,x->ProviderName, dup_strs);
  x->Loc = zx_deep_clone_simple_elems(c,x->Loc, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_IDPEntry) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ProviderName, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Loc, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_IDPEntry) */

int zx_WALK_WO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_IDPList
#define EL_STRUCT zx_ff12_IDPList_s
#define EL_NS     ff12
#define EL_TAG    IDPList

/* FUNC(zx_FREE_ff12_IDPList) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_IDPEntries_s* e;
      struct zx_ff12_IDPEntries_s* en;
      for (e = x->IDPEntries; e; e = en) {
	  en = (struct zx_ff12_IDPEntries_s*)e->gg.g.n;
	  zx_FREE_ff12_IDPEntries(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->GetComplete, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_IDPList) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_IDPList_s* zx_NEW_ff12_IDPList(struct zx_ctx* c)
{
  struct zx_ff12_IDPList_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPList_s);
  x->gg.g.tok = zx_ff12_IDPList_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_IDPList) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_IDPEntries_s* e;
      for (e = x->IDPEntries; e; e = (struct zx_ff12_IDPEntries_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_IDPEntries(c, e);
  }
  zx_dup_strs_simple_elems(c, x->GetComplete);

}

/* FUNC(zx_DEEP_CLONE_ff12_IDPList) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_IDPList_s* zx_DEEP_CLONE_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x, int dup_strs)
{
  x = (struct zx_ff12_IDPList_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_IDPList_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ff12_IDPEntries_s* e;
      struct zx_ff12_IDPEntries_s* en;
      struct zx_ff12_IDPEntries_s* enn;
      for (enn = 0, e = x->IDPEntries; e; e = (struct zx_ff12_IDPEntries_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_IDPEntries(c, e, dup_strs);
	  if (!enn)
	      x->IDPEntries = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->GetComplete = zx_deep_clone_simple_elems(c,x->GetComplete, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_IDPList) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ff12_IDPEntries_s* e;
      for (e = x->IDPEntries; e; e = (struct zx_ff12_IDPEntries_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_IDPEntries(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->GetComplete, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_IDPList) */

int zx_WALK_WO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_IDPProvidedNameIdentifier
#define EL_STRUCT zx_ff12_IDPProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    IDPProvidedNameIdentifier

/* FUNC(zx_FREE_ff12_IDPProvidedNameIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_IDPProvidedNameIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_IDPProvidedNameIdentifier_s* zx_NEW_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c)
{
  struct zx_ff12_IDPProvidedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPProvidedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_IDPProvidedNameIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_IDPProvidedNameIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->NameQualifier);


}

/* FUNC(zx_DEEP_CLONE_ff12_IDPProvidedNameIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_IDPProvidedNameIdentifier_s* zx_DEEP_CLONE_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x, int dup_strs)
{
  x = (struct zx_ff12_IDPProvidedNameIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_IDPProvidedNameIdentifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);


  return x;
}

/* FUNC(zx_WALK_SO_ff12_IDPProvidedNameIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_IDPProvidedNameIdentifier) */

int zx_WALK_WO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_LogoutRequest
#define EL_STRUCT zx_ff12_LogoutRequest_s
#define EL_NS     ff12
#define EL_TAG    LogoutRequest

/* FUNC(zx_FREE_ff12_LogoutRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->NotOnOrAfter, free_strs);
  zx_free_attr(c, x->RequestID, free_strs);
  zx_free_attr(c, x->consent, free_strs);

  zx_free_simple_elems(c, x->RespondWith, free_strs);
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_sa11_NameIdentifier_s* e;
      struct zx_sa11_NameIdentifier_s* en;
      for (e = x->NameIdentifier; e; e = en) {
	  en = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n;
	  zx_FREE_sa11_NameIdentifier(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SessionIndex, free_strs);
  zx_free_simple_elems(c, x->RelayState, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_LogoutRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_LogoutRequest_s* zx_NEW_ff12_LogoutRequest(struct zx_ctx* c)
{
  struct zx_ff12_LogoutRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_LogoutRequest_s);
  x->gg.g.tok = zx_ff12_LogoutRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_LogoutRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->NotOnOrAfter);
  zx_dup_attr(c, x->RequestID);
  zx_dup_attr(c, x->consent);

  zx_dup_strs_simple_elems(c, x->RespondWith);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_NameIdentifier(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SessionIndex);
  zx_dup_strs_simple_elems(c, x->RelayState);

}

/* FUNC(zx_DEEP_CLONE_ff12_LogoutRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_LogoutRequest_s* zx_DEEP_CLONE_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x, int dup_strs)
{
  x = (struct zx_ff12_LogoutRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_LogoutRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->NotOnOrAfter = zx_clone_attr(c, x->NotOnOrAfter);
  x->RequestID = zx_clone_attr(c, x->RequestID);
  x->consent = zx_clone_attr(c, x->consent);

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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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
  x->SessionIndex = zx_deep_clone_simple_elems(c,x->SessionIndex, dup_strs);
  x->RelayState = zx_deep_clone_simple_elems(c,x->RelayState, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_LogoutRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
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
  ret = zx_walk_so_simple_elems(c, x->SessionIndex, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RelayState, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_LogoutRequest) */

int zx_WALK_WO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_LogoutResponse
#define EL_STRUCT zx_ff12_LogoutResponse_s
#define EL_NS     ff12
#define EL_TAG    LogoutResponse

/* FUNC(zx_FREE_ff12_LogoutResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x, int free_strs)
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
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_sp11_Status_s* e;
      struct zx_sp11_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp11_Status_s*)e->gg.g.n;
	  zx_FREE_sp11_Status(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->RelayState, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_LogoutResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_LogoutResponse_s* zx_NEW_ff12_LogoutResponse(struct zx_ctx* c)
{
  struct zx_ff12_LogoutResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_LogoutResponse_s);
  x->gg.g.tok = zx_ff12_LogoutResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_LogoutResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x)
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->RelayState);

}

/* FUNC(zx_DEEP_CLONE_ff12_LogoutResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_LogoutResponse_s* zx_DEEP_CLONE_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x, int dup_strs)
{
  x = (struct zx_ff12_LogoutResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_LogoutResponse_s), dup_strs);
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
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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
  x->RelayState = zx_deep_clone_simple_elems(c,x->RelayState, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_LogoutResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->RelayState, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_LogoutResponse) */

int zx_WALK_WO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_NameIdentifierMappingRequest
#define EL_STRUCT zx_ff12_NameIdentifierMappingRequest_s
#define EL_NS     ff12
#define EL_TAG    NameIdentifierMappingRequest

/* FUNC(zx_FREE_ff12_NameIdentifierMappingRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->IssueInstant, free_strs);
  zx_free_attr(c, x->MajorVersion, free_strs);
  zx_free_attr(c, x->MinorVersion, free_strs);
  zx_free_attr(c, x->RequestID, free_strs);
  zx_free_attr(c, x->consent, free_strs);

  zx_free_simple_elems(c, x->RespondWith, free_strs);
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_sa11_NameIdentifier_s* e;
      struct zx_sa11_NameIdentifier_s* en;
      for (e = x->NameIdentifier; e; e = en) {
	  en = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n;
	  zx_FREE_sa11_NameIdentifier(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->TargetNamespace, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_NameIdentifierMappingRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_NameIdentifierMappingRequest_s* zx_NEW_ff12_NameIdentifierMappingRequest(struct zx_ctx* c)
{
  struct zx_ff12_NameIdentifierMappingRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_NameIdentifierMappingRequest_s);
  x->gg.g.tok = zx_ff12_NameIdentifierMappingRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_NameIdentifierMappingRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->IssueInstant);
  zx_dup_attr(c, x->MajorVersion);
  zx_dup_attr(c, x->MinorVersion);
  zx_dup_attr(c, x->RequestID);
  zx_dup_attr(c, x->consent);

  zx_dup_strs_simple_elems(c, x->RespondWith);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_NameIdentifier(c, e);
  }
  zx_dup_strs_simple_elems(c, x->TargetNamespace);

}

/* FUNC(zx_DEEP_CLONE_ff12_NameIdentifierMappingRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_NameIdentifierMappingRequest_s* zx_DEEP_CLONE_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x, int dup_strs)
{
  x = (struct zx_ff12_NameIdentifierMappingRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_NameIdentifierMappingRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->IssueInstant = zx_clone_attr(c, x->IssueInstant);
  x->MajorVersion = zx_clone_attr(c, x->MajorVersion);
  x->MinorVersion = zx_clone_attr(c, x->MinorVersion);
  x->RequestID = zx_clone_attr(c, x->RequestID);
  x->consent = zx_clone_attr(c, x->consent);

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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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
  x->TargetNamespace = zx_deep_clone_simple_elems(c,x->TargetNamespace, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_NameIdentifierMappingRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
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
  ret = zx_walk_so_simple_elems(c, x->TargetNamespace, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_NameIdentifierMappingRequest) */

int zx_WALK_WO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_NameIdentifierMappingResponse
#define EL_STRUCT zx_ff12_NameIdentifierMappingResponse_s
#define EL_NS     ff12
#define EL_TAG    NameIdentifierMappingResponse

/* FUNC(zx_FREE_ff12_NameIdentifierMappingResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x, int free_strs)
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
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_sp11_Status_s* e;
      struct zx_sp11_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp11_Status_s*)e->gg.g.n;
	  zx_FREE_sp11_Status(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_NameIdentifier_s* e;
      struct zx_sa11_NameIdentifier_s* en;
      for (e = x->NameIdentifier; e; e = en) {
	  en = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n;
	  zx_FREE_sa11_NameIdentifier(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_NameIdentifierMappingResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_NameIdentifierMappingResponse_s* zx_NEW_ff12_NameIdentifierMappingResponse(struct zx_ctx* c)
{
  struct zx_ff12_NameIdentifierMappingResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_NameIdentifierMappingResponse_s);
  x->gg.g.tok = zx_ff12_NameIdentifierMappingResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_NameIdentifierMappingResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x)
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_Status(c, e);
  }
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_NameIdentifier(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_NameIdentifierMappingResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_NameIdentifierMappingResponse_s* zx_DEEP_CLONE_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x, int dup_strs)
{
  x = (struct zx_ff12_NameIdentifierMappingResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_NameIdentifierMappingResponse_s), dup_strs);
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
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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

  return x;
}

/* FUNC(zx_WALK_SO_ff12_NameIdentifierMappingResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_NameIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_NameIdentifierMappingResponse) */

int zx_WALK_WO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_OldProvidedNameIdentifier
#define EL_STRUCT zx_ff12_OldProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    OldProvidedNameIdentifier

/* FUNC(zx_FREE_ff12_OldProvidedNameIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_OldProvidedNameIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_OldProvidedNameIdentifier_s* zx_NEW_ff12_OldProvidedNameIdentifier(struct zx_ctx* c)
{
  struct zx_ff12_OldProvidedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_OldProvidedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_OldProvidedNameIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_OldProvidedNameIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->NameQualifier);


}

/* FUNC(zx_DEEP_CLONE_ff12_OldProvidedNameIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_OldProvidedNameIdentifier_s* zx_DEEP_CLONE_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x, int dup_strs)
{
  x = (struct zx_ff12_OldProvidedNameIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_OldProvidedNameIdentifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);


  return x;
}

/* FUNC(zx_WALK_SO_ff12_OldProvidedNameIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_OldProvidedNameIdentifier) */

int zx_WALK_WO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_RegisterNameIdentifierRequest
#define EL_STRUCT zx_ff12_RegisterNameIdentifierRequest_s
#define EL_NS     ff12
#define EL_TAG    RegisterNameIdentifierRequest

/* FUNC(zx_FREE_ff12_RegisterNameIdentifierRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x, int free_strs)
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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      struct zx_ff12_IDPProvidedNameIdentifier_s* en;
      for (e = x->IDPProvidedNameIdentifier; e; e = en) {
	  en = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n;
	  zx_FREE_ff12_IDPProvidedNameIdentifier(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      struct zx_ff12_SPProvidedNameIdentifier_s* en;
      for (e = x->SPProvidedNameIdentifier; e; e = en) {
	  en = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n;
	  zx_FREE_ff12_SPProvidedNameIdentifier(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      struct zx_ff12_OldProvidedNameIdentifier_s* en;
      for (e = x->OldProvidedNameIdentifier; e; e = en) {
	  en = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n;
	  zx_FREE_ff12_OldProvidedNameIdentifier(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->RelayState, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_RegisterNameIdentifierRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_RegisterNameIdentifierRequest_s* zx_NEW_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c)
{
  struct zx_ff12_RegisterNameIdentifierRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_RegisterNameIdentifierRequest_s);
  x->gg.g.tok = zx_ff12_RegisterNameIdentifierRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_RegisterNameIdentifierRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x)
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_IDPProvidedNameIdentifier(c, e);
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      for (e = x->SPProvidedNameIdentifier; e; e = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_SPProvidedNameIdentifier(c, e);
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      for (e = x->OldProvidedNameIdentifier; e; e = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_OldProvidedNameIdentifier(c, e);
  }
  zx_dup_strs_simple_elems(c, x->RelayState);

}

/* FUNC(zx_DEEP_CLONE_ff12_RegisterNameIdentifierRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_RegisterNameIdentifierRequest_s* zx_DEEP_CLONE_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x, int dup_strs)
{
  x = (struct zx_ff12_RegisterNameIdentifierRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_RegisterNameIdentifierRequest_s), dup_strs);
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
  {
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      struct zx_ff12_IDPProvidedNameIdentifier_s* en;
      struct zx_ff12_IDPProvidedNameIdentifier_s* enn;
      for (enn = 0, e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_IDPProvidedNameIdentifier(c, e, dup_strs);
	  if (!enn)
	      x->IDPProvidedNameIdentifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      struct zx_ff12_SPProvidedNameIdentifier_s* en;
      struct zx_ff12_SPProvidedNameIdentifier_s* enn;
      for (enn = 0, e = x->SPProvidedNameIdentifier; e; e = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_SPProvidedNameIdentifier(c, e, dup_strs);
	  if (!enn)
	      x->SPProvidedNameIdentifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      struct zx_ff12_OldProvidedNameIdentifier_s* en;
      struct zx_ff12_OldProvidedNameIdentifier_s* enn;
      for (enn = 0, e = x->OldProvidedNameIdentifier; e; e = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_OldProvidedNameIdentifier(c, e, dup_strs);
	  if (!enn)
	      x->OldProvidedNameIdentifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->RelayState = zx_deep_clone_simple_elems(c,x->RelayState, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_RegisterNameIdentifierRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_IDPProvidedNameIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      for (e = x->SPProvidedNameIdentifier; e; e = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_SPProvidedNameIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      for (e = x->OldProvidedNameIdentifier; e; e = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_OldProvidedNameIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->RelayState, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_RegisterNameIdentifierRequest) */

int zx_WALK_WO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_RegisterNameIdentifierResponse
#define EL_STRUCT zx_ff12_RegisterNameIdentifierResponse_s
#define EL_NS     ff12
#define EL_TAG    RegisterNameIdentifierResponse

/* FUNC(zx_FREE_ff12_RegisterNameIdentifierResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x, int free_strs)
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
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ff12_Extension_s*)e->gg.g.n;
	  zx_FREE_ff12_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_sp11_Status_s* e;
      struct zx_sp11_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_sp11_Status_s*)e->gg.g.n;
	  zx_FREE_sp11_Status(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->RelayState, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_RegisterNameIdentifierResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_RegisterNameIdentifierResponse_s* zx_NEW_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c)
{
  struct zx_ff12_RegisterNameIdentifierResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_RegisterNameIdentifierResponse_s);
  x->gg.g.tok = zx_ff12_RegisterNameIdentifierResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_RegisterNameIdentifierResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x)
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->RelayState);

}

/* FUNC(zx_DEEP_CLONE_ff12_RegisterNameIdentifierResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_RegisterNameIdentifierResponse_s* zx_DEEP_CLONE_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x, int dup_strs)
{
  x = (struct zx_ff12_RegisterNameIdentifierResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_RegisterNameIdentifierResponse_s), dup_strs);
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
      struct zx_ff12_Extension_s* e;
      struct zx_ff12_Extension_s* en;
      struct zx_ff12_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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
  x->RelayState = zx_deep_clone_simple_elems(c,x->RelayState, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_RegisterNameIdentifierResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->RelayState, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_RegisterNameIdentifierResponse) */

int zx_WALK_WO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_RequestAuthnContext
#define EL_STRUCT zx_ff12_RequestAuthnContext_s
#define EL_NS     ff12
#define EL_TAG    RequestAuthnContext

/* FUNC(zx_FREE_ff12_RequestAuthnContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->AuthnContextClassRef, free_strs);
  zx_free_simple_elems(c, x->AuthnContextStatementRef, free_strs);
  zx_free_simple_elems(c, x->AuthnContextComparison, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_RequestAuthnContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_RequestAuthnContext_s* zx_NEW_ff12_RequestAuthnContext(struct zx_ctx* c)
{
  struct zx_ff12_RequestAuthnContext_s* x = ZX_ZALLOC(c, struct zx_ff12_RequestAuthnContext_s);
  x->gg.g.tok = zx_ff12_RequestAuthnContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_RequestAuthnContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->AuthnContextClassRef);
  zx_dup_strs_simple_elems(c, x->AuthnContextStatementRef);
  zx_dup_strs_simple_elems(c, x->AuthnContextComparison);

}

/* FUNC(zx_DEEP_CLONE_ff12_RequestAuthnContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_RequestAuthnContext_s* zx_DEEP_CLONE_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x, int dup_strs)
{
  x = (struct zx_ff12_RequestAuthnContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_RequestAuthnContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->AuthnContextClassRef = zx_deep_clone_simple_elems(c,x->AuthnContextClassRef, dup_strs);
  x->AuthnContextStatementRef = zx_deep_clone_simple_elems(c,x->AuthnContextStatementRef, dup_strs);
  x->AuthnContextComparison = zx_deep_clone_simple_elems(c,x->AuthnContextComparison, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ff12_RequestAuthnContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->AuthnContextStatementRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuthnContextComparison, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_RequestAuthnContext) */

int zx_WALK_WO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_SPProvidedNameIdentifier
#define EL_STRUCT zx_ff12_SPProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    SPProvidedNameIdentifier

/* FUNC(zx_FREE_ff12_SPProvidedNameIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Format, free_strs);
  zx_free_attr(c, x->NameQualifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_SPProvidedNameIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_SPProvidedNameIdentifier_s* zx_NEW_ff12_SPProvidedNameIdentifier(struct zx_ctx* c)
{
  struct zx_ff12_SPProvidedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_SPProvidedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_SPProvidedNameIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_SPProvidedNameIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Format);
  zx_dup_attr(c, x->NameQualifier);


}

/* FUNC(zx_DEEP_CLONE_ff12_SPProvidedNameIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_SPProvidedNameIdentifier_s* zx_DEEP_CLONE_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x, int dup_strs)
{
  x = (struct zx_ff12_SPProvidedNameIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_SPProvidedNameIdentifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Format = zx_clone_attr(c, x->Format);
  x->NameQualifier = zx_clone_attr(c, x->NameQualifier);


  return x;
}

/* FUNC(zx_WALK_SO_ff12_SPProvidedNameIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ff12_SPProvidedNameIdentifier) */

int zx_WALK_WO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_Scoping
#define EL_STRUCT zx_ff12_Scoping_s
#define EL_NS     ff12
#define EL_TAG    Scoping

/* FUNC(zx_FREE_ff12_Scoping) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->ProxyCount, free_strs);
  {
      struct zx_ff12_IDPList_s* e;
      struct zx_ff12_IDPList_s* en;
      for (e = x->IDPList; e; e = en) {
	  en = (struct zx_ff12_IDPList_s*)e->gg.g.n;
	  zx_FREE_ff12_IDPList(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_Scoping) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_Scoping_s* zx_NEW_ff12_Scoping(struct zx_ctx* c)
{
  struct zx_ff12_Scoping_s* x = ZX_ZALLOC(c, struct zx_ff12_Scoping_s);
  x->gg.g.tok = zx_ff12_Scoping_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_Scoping) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->ProxyCount);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_IDPList(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_Scoping) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_Scoping_s* zx_DEEP_CLONE_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x, int dup_strs)
{
  x = (struct zx_ff12_Scoping_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_Scoping_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->ProxyCount = zx_deep_clone_simple_elems(c,x->ProxyCount, dup_strs);
  {
      struct zx_ff12_IDPList_s* e;
      struct zx_ff12_IDPList_s* en;
      struct zx_ff12_IDPList_s* enn;
      for (enn = 0, e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_IDPList(c, e, dup_strs);
	  if (!enn)
	      x->IDPList = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ff12_Scoping) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->ProxyCount, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_IDPList(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_Scoping) */

int zx_WALK_WO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ff12_Subject
#define EL_STRUCT zx_ff12_Subject_s
#define EL_NS     ff12
#define EL_TAG    Subject

/* FUNC(zx_FREE_ff12_Subject) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x, int free_strs)
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
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      struct zx_ff12_IDPProvidedNameIdentifier_s* en;
      for (e = x->IDPProvidedNameIdentifier; e; e = en) {
	  en = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n;
	  zx_FREE_ff12_IDPProvidedNameIdentifier(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ff12_Subject) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ff12_Subject_s* zx_NEW_ff12_Subject(struct zx_ctx* c)
{
  struct zx_ff12_Subject_s* x = ZX_ZALLOC(c, struct zx_ff12_Subject_s);
  x->gg.g.tok = zx_ff12_Subject_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ff12_Subject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x)
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
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_IDPProvidedNameIdentifier(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ff12_Subject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ff12_Subject_s* zx_DEEP_CLONE_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x, int dup_strs)
{
  x = (struct zx_ff12_Subject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ff12_Subject_s), dup_strs);
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
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      struct zx_ff12_IDPProvidedNameIdentifier_s* en;
      struct zx_ff12_IDPProvidedNameIdentifier_s* enn;
      for (enn = 0, e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_IDPProvidedNameIdentifier(c, e, dup_strs);
	  if (!enn)
	      x->IDPProvidedNameIdentifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ff12_Subject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_IDPProvidedNameIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ff12_Subject) */

int zx_WALK_WO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-ff12-aux.c */
