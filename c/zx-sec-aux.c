/* c/zx-sec-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sec-data.h"



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

#define EL_NAME   sec_Token
#define EL_STRUCT zx_sec_Token_s
#define EL_NS     sec
#define EL_TAG    Token

/* FUNC(zx_FREE_sec_Token) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->ref, free_strs);
  zx_free_attr(c, x->usage, free_strs);

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

/* FUNC(zx_NEW_sec_Token) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec_Token_s* zx_NEW_sec_Token(struct zx_ctx* c)
{
  struct zx_sec_Token_s* x = ZX_ZALLOC(c, struct zx_sec_Token_s);
  x->gg.g.tok = zx_sec_Token_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec_Token) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->ref);
  zx_dup_attr(c, x->usage);

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

/* FUNC(zx_DEEP_CLONE_sec_Token) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec_Token_s* zx_DEEP_CLONE_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x, int dup_strs)
{
  x = (struct zx_sec_Token_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec_Token_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->ref = zx_clone_attr(c, x->ref);
  x->usage = zx_clone_attr(c, x->usage);

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

/* FUNC(zx_WALK_SO_sec_Token) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sec_Token) */

int zx_WALK_WO_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec_TokenPolicy
#define EL_STRUCT zx_sec_TokenPolicy_s
#define EL_NS     sec
#define EL_TAG    TokenPolicy

/* FUNC(zx_FREE_sec_TokenPolicy) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->issueTo, free_strs);
  zx_free_attr(c, x->type, free_strs);
  zx_free_attr(c, x->validUntil, free_strs);
  zx_free_attr(c, x->wantDSEPR, free_strs);

  {
      struct zx_sp_NameIDPolicy_s* e;
      struct zx_sp_NameIDPolicy_s* en;
      for (e = x->NameIDPolicy; e; e = en) {
	  en = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n;
	  zx_FREE_sp_NameIDPolicy(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec_TokenPolicy) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec_TokenPolicy_s* zx_NEW_sec_TokenPolicy(struct zx_ctx* c)
{
  struct zx_sec_TokenPolicy_s* x = ZX_ZALLOC(c, struct zx_sec_TokenPolicy_s);
  x->gg.g.tok = zx_sec_TokenPolicy_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec_TokenPolicy) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->issueTo);
  zx_dup_attr(c, x->type);
  zx_dup_attr(c, x->validUntil);
  zx_dup_attr(c, x->wantDSEPR);

  {
      struct zx_sp_NameIDPolicy_s* e;
      for (e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_NameIDPolicy(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec_TokenPolicy) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec_TokenPolicy_s* zx_DEEP_CLONE_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x, int dup_strs)
{
  x = (struct zx_sec_TokenPolicy_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec_TokenPolicy_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->issueTo = zx_clone_attr(c, x->issueTo);
  x->type = zx_clone_attr(c, x->type);
  x->validUntil = zx_clone_attr(c, x->validUntil);
  x->wantDSEPR = zx_clone_attr(c, x->wantDSEPR);

  {
      struct zx_sp_NameIDPolicy_s* e;
      struct zx_sp_NameIDPolicy_s* en;
      struct zx_sp_NameIDPolicy_s* enn;
      for (enn = 0, e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_NameIDPolicy(c, e, dup_strs);
	  if (!enn)
	      x->NameIDPolicy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec_TokenPolicy) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_NameIDPolicy_s* e;
      for (e = x->NameIDPolicy; e; e = (struct zx_sp_NameIDPolicy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_NameIDPolicy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec_TokenPolicy) */

int zx_WALK_WO_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec_TransitedProvider
#define EL_STRUCT zx_sec_TransitedProvider_s
#define EL_NS     sec
#define EL_TAG    TransitedProvider

/* FUNC(zx_FREE_sec_TransitedProvider) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->confirmationURI, free_strs);
  zx_free_attr(c, x->timeStamp, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec_TransitedProvider) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec_TransitedProvider_s* zx_NEW_sec_TransitedProvider(struct zx_ctx* c)
{
  struct zx_sec_TransitedProvider_s* x = ZX_ZALLOC(c, struct zx_sec_TransitedProvider_s);
  x->gg.g.tok = zx_sec_TransitedProvider_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec_TransitedProvider) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->confirmationURI);
  zx_dup_attr(c, x->timeStamp);


}

/* FUNC(zx_DEEP_CLONE_sec_TransitedProvider) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec_TransitedProvider_s* zx_DEEP_CLONE_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x, int dup_strs)
{
  x = (struct zx_sec_TransitedProvider_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec_TransitedProvider_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->confirmationURI = zx_clone_attr(c, x->confirmationURI);
  x->timeStamp = zx_clone_attr(c, x->timeStamp);


  return x;
}

/* FUNC(zx_WALK_SO_sec_TransitedProvider) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sec_TransitedProvider) */

int zx_WALK_WO_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec_TransitedProviderPath
#define EL_STRUCT zx_sec_TransitedProviderPath_s
#define EL_NS     sec
#define EL_TAG    TransitedProviderPath

/* FUNC(zx_FREE_sec_TransitedProviderPath) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sec_TransitedProvider_s* e;
      struct zx_sec_TransitedProvider_s* en;
      for (e = x->TransitedProvider; e; e = en) {
	  en = (struct zx_sec_TransitedProvider_s*)e->gg.g.n;
	  zx_FREE_sec_TransitedProvider(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec_TransitedProviderPath) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec_TransitedProviderPath_s* zx_NEW_sec_TransitedProviderPath(struct zx_ctx* c)
{
  struct zx_sec_TransitedProviderPath_s* x = ZX_ZALLOC(c, struct zx_sec_TransitedProviderPath_s);
  x->gg.g.tok = zx_sec_TransitedProviderPath_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec_TransitedProviderPath) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sec_TransitedProvider_s* e;
      for (e = x->TransitedProvider; e; e = (struct zx_sec_TransitedProvider_s*)e->gg.g.n)
	  zx_DUP_STRS_sec_TransitedProvider(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec_TransitedProviderPath) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec_TransitedProviderPath_s* zx_DEEP_CLONE_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x, int dup_strs)
{
  x = (struct zx_sec_TransitedProviderPath_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec_TransitedProviderPath_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sec_TransitedProvider_s* e;
      struct zx_sec_TransitedProvider_s* en;
      struct zx_sec_TransitedProvider_s* enn;
      for (enn = 0, e = x->TransitedProvider; e; e = (struct zx_sec_TransitedProvider_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec_TransitedProvider(c, e, dup_strs);
	  if (!enn)
	      x->TransitedProvider = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec_TransitedProviderPath) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sec_TransitedProvider_s* e;
      for (e = x->TransitedProvider; e; e = (struct zx_sec_TransitedProvider_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec_TransitedProvider(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec_TransitedProviderPath) */

int zx_WALK_WO_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sec-aux.c */
