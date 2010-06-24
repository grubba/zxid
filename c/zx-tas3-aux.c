/* c/zx-tas3-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-tas3-data.h"



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

#define EL_NAME   tas3_Credentials
#define EL_STRUCT zx_tas3_Credentials_s
#define EL_NS     tas3
#define EL_TAG    Credentials

/* FUNC(zx_FREE_tas3_Credentials) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->usage, free_strs);
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
  {
      struct zx_xac_Attribute_s* e;
      struct zx_xac_Attribute_s* en;
      for (e = x->xac_Attribute; e; e = en) {
	  en = (struct zx_xac_Attribute_s*)e->gg.g.n;
	  zx_FREE_xac_Attribute(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_tas3_Credentials) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3_Credentials_s* zx_NEW_tas3_Credentials(struct zx_ctx* c)
{
  struct zx_tas3_Credentials_s* x = ZX_ZALLOC(c, struct zx_tas3_Credentials_s);
  x->gg.g.tok = zx_tas3_Credentials_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3_Credentials) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->usage);
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
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->xac_Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  zx_DUP_STRS_xac_Attribute(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_tas3_Credentials) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3_Credentials_s* zx_DEEP_CLONE_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x, int dup_strs)
{
  x = (struct zx_tas3_Credentials_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3_Credentials_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->usage = zx_clone_attr(c, x->usage);
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
  {
      struct zx_xac_Attribute_s* e;
      struct zx_xac_Attribute_s* en;
      struct zx_xac_Attribute_s* enn;
      for (enn = 0, e = x->xac_Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xac_Attribute(c, e, dup_strs);
	  if (!enn)
	      x->xac_Attribute = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_tas3_Credentials) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->xac_Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xac_Attribute(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_tas3_Credentials) */

int zx_WALK_WO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   tas3_ESLApply
#define EL_STRUCT zx_tas3_ESLApply_s
#define EL_NS     tas3
#define EL_TAG    ESLApply

/* FUNC(zx_FREE_tas3_ESLApply) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_tas3_ESLRef_s* e;
      struct zx_tas3_ESLRef_s* en;
      for (e = x->ESLRef; e; e = en) {
	  en = (struct zx_tas3_ESLRef_s*)e->gg.g.n;
	  zx_FREE_tas3_ESLRef(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Obligation_s* e;
      struct zx_xa_Obligation_s* en;
      for (e = x->Obligation; e; e = en) {
	  en = (struct zx_xa_Obligation_s*)e->gg.g.n;
	  zx_FREE_xa_Obligation(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_tas3_ESLApply) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3_ESLApply_s* zx_NEW_tas3_ESLApply(struct zx_ctx* c)
{
  struct zx_tas3_ESLApply_s* x = ZX_ZALLOC(c, struct zx_tas3_ESLApply_s);
  x->gg.g.tok = zx_tas3_ESLApply_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3_ESLApply) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_tas3_ESLRef_s* e;
      for (e = x->ESLRef; e; e = (struct zx_tas3_ESLRef_s*)e->gg.g.n)
	  zx_DUP_STRS_tas3_ESLRef(c, e);
  }
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Obligation(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_tas3_ESLApply) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3_ESLApply_s* zx_DEEP_CLONE_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x, int dup_strs)
{
  x = (struct zx_tas3_ESLApply_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3_ESLApply_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_tas3_ESLRef_s* e;
      struct zx_tas3_ESLRef_s* en;
      struct zx_tas3_ESLRef_s* enn;
      for (enn = 0, e = x->ESLRef; e; e = (struct zx_tas3_ESLRef_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_tas3_ESLRef(c, e, dup_strs);
	  if (!enn)
	      x->ESLRef = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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

  return x;
}

/* FUNC(zx_WALK_SO_tas3_ESLApply) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_tas3_ESLRef_s* e;
      for (e = x->ESLRef; e; e = (struct zx_tas3_ESLRef_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_tas3_ESLRef(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Obligation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_tas3_ESLApply) */

int zx_WALK_WO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   tas3_ESLPolicies
#define EL_STRUCT zx_tas3_ESLPolicies_s
#define EL_NS     tas3
#define EL_TAG    ESLPolicies

/* FUNC(zx_FREE_tas3_ESLPolicies) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->usage, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_tas3_ESLApply_s* e;
      struct zx_tas3_ESLApply_s* en;
      for (e = x->ESLApply; e; e = en) {
	  en = (struct zx_tas3_ESLApply_s*)e->gg.g.n;
	  zx_FREE_tas3_ESLApply(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_tas3_ESLPolicies) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3_ESLPolicies_s* zx_NEW_tas3_ESLPolicies(struct zx_ctx* c)
{
  struct zx_tas3_ESLPolicies_s* x = ZX_ZALLOC(c, struct zx_tas3_ESLPolicies_s);
  x->gg.g.tok = zx_tas3_ESLPolicies_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3_ESLPolicies) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->usage);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_tas3_ESLApply_s* e;
      for (e = x->ESLApply; e; e = (struct zx_tas3_ESLApply_s*)e->gg.g.n)
	  zx_DUP_STRS_tas3_ESLApply(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_tas3_ESLPolicies) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3_ESLPolicies_s* zx_DEEP_CLONE_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x, int dup_strs)
{
  x = (struct zx_tas3_ESLPolicies_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3_ESLPolicies_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->usage = zx_clone_attr(c, x->usage);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

  {
      struct zx_tas3_ESLApply_s* e;
      struct zx_tas3_ESLApply_s* en;
      struct zx_tas3_ESLApply_s* enn;
      for (enn = 0, e = x->ESLApply; e; e = (struct zx_tas3_ESLApply_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_tas3_ESLApply(c, e, dup_strs);
	  if (!enn)
	      x->ESLApply = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_tas3_ESLPolicies) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_tas3_ESLApply_s* e;
      for (e = x->ESLApply; e; e = (struct zx_tas3_ESLApply_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_tas3_ESLApply(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_tas3_ESLPolicies) */

int zx_WALK_WO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   tas3_ESLRef
#define EL_STRUCT zx_tas3_ESLRef_s
#define EL_NS     tas3
#define EL_TAG    ESLRef

/* FUNC(zx_FREE_tas3_ESLRef) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ref, free_strs);
  zx_free_attr(c, x->xpath, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_tas3_ESLRef) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3_ESLRef_s* zx_NEW_tas3_ESLRef(struct zx_ctx* c)
{
  struct zx_tas3_ESLRef_s* x = ZX_ZALLOC(c, struct zx_tas3_ESLRef_s);
  x->gg.g.tok = zx_tas3_ESLRef_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3_ESLRef) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ref);
  zx_dup_attr(c, x->xpath);


}

/* FUNC(zx_DEEP_CLONE_tas3_ESLRef) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3_ESLRef_s* zx_DEEP_CLONE_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x, int dup_strs)
{
  x = (struct zx_tas3_ESLRef_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3_ESLRef_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ref = zx_clone_attr(c, x->ref);
  x->xpath = zx_clone_attr(c, x->xpath);


  return x;
}

/* FUNC(zx_WALK_SO_tas3_ESLRef) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_tas3_ESLRef) */

int zx_WALK_WO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   tas3_Status
#define EL_STRUCT zx_tas3_Status_s
#define EL_NS     tas3
#define EL_TAG    Status

/* FUNC(zx_FREE_tas3_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->code, free_strs);
  zx_free_attr(c, x->comment, free_strs);
  zx_free_attr(c, x->ctlpt, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->ref, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

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

/* FUNC(zx_NEW_tas3_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3_Status_s* zx_NEW_tas3_Status(struct zx_ctx* c)
{
  struct zx_tas3_Status_s* x = ZX_ZALLOC(c, struct zx_tas3_Status_s);
  x->gg.g.tok = zx_tas3_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->code);
  zx_dup_attr(c, x->comment);
  zx_dup_attr(c, x->ctlpt);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->ref);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_tas3_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3_Status_s* zx_DEEP_CLONE_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x, int dup_strs)
{
  x = (struct zx_tas3_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->code = zx_clone_attr(c, x->code);
  x->comment = zx_clone_attr(c, x->comment);
  x->ctlpt = zx_clone_attr(c, x->ctlpt);
  x->id = zx_clone_attr(c, x->id);
  x->ref = zx_clone_attr(c, x->ref);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

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

/* FUNC(zx_WALK_SO_tas3_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_tas3_Status) */

int zx_WALK_WO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-tas3-aux.c */
