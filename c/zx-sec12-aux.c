/* c/zx-sec12-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sec12-data.h"



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

#define EL_NAME   sec12_ProxyInfoConfirmationData
#define EL_STRUCT zx_sec12_ProxyInfoConfirmationData_s
#define EL_NS     sec12
#define EL_TAG    ProxyInfoConfirmationData

/* FUNC(zx_FREE_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  zx_free_simple_elems(c, x->AssertionIDReference, free_strs);
  zx_free_simple_elems(c, x->Issuer, free_strs);
  zx_free_simple_elems(c, x->IssueInstant, free_strs);
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

/* FUNC(zx_NEW_sec12_ProxyInfoConfirmationData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_ProxyInfoConfirmationData_s* zx_NEW_sec12_ProxyInfoConfirmationData(struct zx_ctx* c)
{
  struct zx_sec12_ProxyInfoConfirmationData_s* x = ZX_ZALLOC(c, struct zx_sec12_ProxyInfoConfirmationData_s);
  x->gg.g.tok = zx_sec12_ProxyInfoConfirmationData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  zx_dup_strs_simple_elems(c, x->AssertionIDReference);
  zx_dup_strs_simple_elems(c, x->Issuer);
  zx_dup_strs_simple_elems(c, x->IssueInstant);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ProxyInfoConfirmationData_s* zx_DEEP_CLONE_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, int dup_strs)
{
  x = (struct zx_sec12_ProxyInfoConfirmationData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ProxyInfoConfirmationData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  x->AssertionIDReference = zx_deep_clone_simple_elems(c,x->AssertionIDReference, dup_strs);
  x->Issuer = zx_deep_clone_simple_elems(c,x->Issuer, dup_strs);
  x->IssueInstant = zx_deep_clone_simple_elems(c,x->IssueInstant, dup_strs);
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

/* FUNC(zx_WALK_SO_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->Issuer, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->IssueInstant, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ProxyInfoConfirmationData) */

int zx_WALK_WO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_ProxySubject
#define EL_STRUCT zx_sec12_ProxySubject_s
#define EL_NS     sec12
#define EL_TAG    ProxySubject

/* FUNC(zx_FREE_sec12_ProxySubject) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, int free_strs)
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

/* FUNC(zx_NEW_sec12_ProxySubject) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_ProxySubject_s* zx_NEW_sec12_ProxySubject(struct zx_ctx* c)
{
  struct zx_sec12_ProxySubject_s* x = ZX_ZALLOC(c, struct zx_sec12_ProxySubject_s);
  x->gg.g.tok = zx_sec12_ProxySubject_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ProxySubject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x)
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

/* FUNC(zx_DEEP_CLONE_sec12_ProxySubject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ProxySubject_s* zx_DEEP_CLONE_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, int dup_strs)
{
  x = (struct zx_sec12_ProxySubject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ProxySubject_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sec12_ProxySubject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sec12_ProxySubject) */

int zx_WALK_WO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_ProxyTransitedStatement
#define EL_STRUCT zx_sec12_ProxyTransitedStatement_s
#define EL_NS     sec12
#define EL_TAG    ProxyTransitedStatement

/* FUNC(zx_FREE_sec12_ProxyTransitedStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, int free_strs)
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

/* FUNC(zx_NEW_sec12_ProxyTransitedStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_ProxyTransitedStatement_s* zx_NEW_sec12_ProxyTransitedStatement(struct zx_ctx* c)
{
  struct zx_sec12_ProxyTransitedStatement_s* x = ZX_ZALLOC(c, struct zx_sec12_ProxyTransitedStatement_s);
  x->gg.g.tok = zx_sec12_ProxyTransitedStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ProxyTransitedStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec12_ProxyTransitedStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ProxyTransitedStatement_s* zx_DEEP_CLONE_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, int dup_strs)
{
  x = (struct zx_sec12_ProxyTransitedStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ProxyTransitedStatement_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sec12_ProxyTransitedStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sec12_ProxyTransitedStatement) */

int zx_WALK_WO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_ResourceAccessStatement
#define EL_STRUCT zx_sec12_ResourceAccessStatement_s
#define EL_NS     sec12
#define EL_TAG    ResourceAccessStatement

/* FUNC(zx_FREE_sec12_ResourceAccessStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, int free_strs)
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
      struct zx_sec12_ProxySubject_s* e;
      struct zx_sec12_ProxySubject_s* en;
      for (e = x->ProxySubject; e; e = en) {
	  en = (struct zx_sec12_ProxySubject_s*)e->gg.g.n;
	  zx_FREE_sec12_ProxySubject(c, e, free_strs);
      }
  }
  {
      struct zx_sec12_SessionContext_s* e;
      struct zx_sec12_SessionContext_s* en;
      for (e = x->SessionContext; e; e = en) {
	  en = (struct zx_sec12_SessionContext_s*)e->gg.g.n;
	  zx_FREE_sec12_SessionContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec12_ResourceAccessStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_ResourceAccessStatement_s* zx_NEW_sec12_ResourceAccessStatement(struct zx_ctx* c)
{
  struct zx_sec12_ResourceAccessStatement_s* x = ZX_ZALLOC(c, struct zx_sec12_ResourceAccessStatement_s);
  x->gg.g.tok = zx_sec12_ResourceAccessStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ResourceAccessStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }
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
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  zx_DUP_STRS_sec12_ProxySubject(c, e);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sec12_SessionContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec12_ResourceAccessStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ResourceAccessStatement_s* zx_DEEP_CLONE_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, int dup_strs)
{
  x = (struct zx_sec12_ResourceAccessStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ResourceAccessStatement_s), dup_strs);
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
      struct zx_sec12_ProxySubject_s* e;
      struct zx_sec12_ProxySubject_s* en;
      struct zx_sec12_ProxySubject_s* enn;
      for (enn = 0, e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec12_ProxySubject(c, e, dup_strs);
	  if (!enn)
	      x->ProxySubject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sec12_SessionContext_s* e;
      struct zx_sec12_SessionContext_s* en;
      struct zx_sec12_SessionContext_s* enn;
      for (enn = 0, e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec12_SessionContext(c, e, dup_strs);
	  if (!enn)
	      x->SessionContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ResourceAccessStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec12_ProxySubject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec12_SessionContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ResourceAccessStatement) */

int zx_WALK_WO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_SessionContext
#define EL_STRUCT zx_sec12_SessionContext_s
#define EL_NS     sec12
#define EL_TAG    SessionContext

/* FUNC(zx_FREE_sec12_SessionContext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AssertionIssueInstant, free_strs);
  zx_free_attr(c, x->AuthenticationInstant, free_strs);
  zx_free_attr(c, x->SessionIndex, free_strs);

  {
      struct zx_sec12_SessionSubject_s* e;
      struct zx_sec12_SessionSubject_s* en;
      for (e = x->SessionSubject; e; e = en) {
	  en = (struct zx_sec12_SessionSubject_s*)e->gg.g.n;
	  zx_FREE_sec12_SessionSubject(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ProviderID, free_strs);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      struct zx_ff12_RequestAuthnContext_s* en;
      for (e = x->RequestAuthnContext; e; e = en) {
	  en = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n;
	  zx_FREE_ff12_RequestAuthnContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec12_SessionContext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_SessionContext_s* zx_NEW_sec12_SessionContext(struct zx_ctx* c)
{
  struct zx_sec12_SessionContext_s* x = ZX_ZALLOC(c, struct zx_sec12_SessionContext_s);
  x->gg.g.tok = zx_sec12_SessionContext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_SessionContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AssertionIssueInstant);
  zx_dup_attr(c, x->AuthenticationInstant);
  zx_dup_attr(c, x->SessionIndex);

  {
      struct zx_sec12_SessionSubject_s* e;
      for (e = x->SessionSubject; e; e = (struct zx_sec12_SessionSubject_s*)e->gg.g.n)
	  zx_DUP_STRS_sec12_SessionSubject(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ProviderID);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_RequestAuthnContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec12_SessionContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_SessionContext_s* zx_DEEP_CLONE_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, int dup_strs)
{
  x = (struct zx_sec12_SessionContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_SessionContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AssertionIssueInstant = zx_clone_attr(c, x->AssertionIssueInstant);
  x->AuthenticationInstant = zx_clone_attr(c, x->AuthenticationInstant);
  x->SessionIndex = zx_clone_attr(c, x->SessionIndex);

  {
      struct zx_sec12_SessionSubject_s* e;
      struct zx_sec12_SessionSubject_s* en;
      struct zx_sec12_SessionSubject_s* enn;
      for (enn = 0, e = x->SessionSubject; e; e = (struct zx_sec12_SessionSubject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec12_SessionSubject(c, e, dup_strs);
	  if (!enn)
	      x->SessionSubject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
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

  return x;
}

/* FUNC(zx_WALK_SO_sec12_SessionContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sec12_SessionSubject_s* e;
      for (e = x->SessionSubject; e; e = (struct zx_sec12_SessionSubject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec12_SessionSubject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_SessionContext) */

int zx_WALK_WO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_SessionContextStatement
#define EL_STRUCT zx_sec12_SessionContextStatement_s
#define EL_NS     sec12
#define EL_TAG    SessionContextStatement

/* FUNC(zx_FREE_sec12_SessionContextStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, int free_strs)
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
      struct zx_sec12_ProxySubject_s* e;
      struct zx_sec12_ProxySubject_s* en;
      for (e = x->ProxySubject; e; e = en) {
	  en = (struct zx_sec12_ProxySubject_s*)e->gg.g.n;
	  zx_FREE_sec12_ProxySubject(c, e, free_strs);
      }
  }
  {
      struct zx_sec12_SessionContext_s* e;
      struct zx_sec12_SessionContext_s* en;
      for (e = x->SessionContext; e; e = en) {
	  en = (struct zx_sec12_SessionContext_s*)e->gg.g.n;
	  zx_FREE_sec12_SessionContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec12_SessionContextStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_SessionContextStatement_s* zx_NEW_sec12_SessionContextStatement(struct zx_ctx* c)
{
  struct zx_sec12_SessionContextStatement_s* x = ZX_ZALLOC(c, struct zx_sec12_SessionContextStatement_s);
  x->gg.g.tok = zx_sec12_SessionContextStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_SessionContextStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Subject(c, e);
  }
  {
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  zx_DUP_STRS_sec12_ProxySubject(c, e);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sec12_SessionContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_sec12_SessionContextStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_SessionContextStatement_s* zx_DEEP_CLONE_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, int dup_strs)
{
  x = (struct zx_sec12_SessionContextStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_SessionContextStatement_s), dup_strs);
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
      struct zx_sec12_ProxySubject_s* e;
      struct zx_sec12_ProxySubject_s* en;
      struct zx_sec12_ProxySubject_s* enn;
      for (enn = 0, e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec12_ProxySubject(c, e, dup_strs);
	  if (!enn)
	      x->ProxySubject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sec12_SessionContext_s* e;
      struct zx_sec12_SessionContext_s* en;
      struct zx_sec12_SessionContext_s* enn;
      for (enn = 0, e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sec12_SessionContext(c, e, dup_strs);
	  if (!enn)
	      x->SessionContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_SessionContextStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec12_ProxySubject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sec12_SessionContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_SessionContextStatement) */

int zx_WALK_WO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_SessionSubject
#define EL_STRUCT zx_sec12_SessionSubject_s
#define EL_NS     sec12
#define EL_TAG    SessionSubject

/* FUNC(zx_FREE_sec12_SessionSubject) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, int free_strs)
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

/* FUNC(zx_NEW_sec12_SessionSubject) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_SessionSubject_s* zx_NEW_sec12_SessionSubject(struct zx_ctx* c)
{
  struct zx_sec12_SessionSubject_s* x = ZX_ZALLOC(c, struct zx_sec12_SessionSubject_s);
  x->gg.g.tok = zx_sec12_SessionSubject_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_SessionSubject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x)
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

/* FUNC(zx_DEEP_CLONE_sec12_SessionSubject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_SessionSubject_s* zx_DEEP_CLONE_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, int dup_strs)
{
  x = (struct zx_sec12_SessionSubject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_SessionSubject_s), dup_strs);
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

/* FUNC(zx_WALK_SO_sec12_SessionSubject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_sec12_SessionSubject) */

int zx_WALK_WO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   sec12_ValidityRestrictionCondition
#define EL_STRUCT zx_sec12_ValidityRestrictionCondition_s
#define EL_NS     sec12
#define EL_TAG    ValidityRestrictionCondition

/* FUNC(zx_FREE_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->NumberOfUses, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_sec12_ValidityRestrictionCondition) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_sec12_ValidityRestrictionCondition_s* zx_NEW_sec12_ValidityRestrictionCondition(struct zx_ctx* c)
{
  struct zx_sec12_ValidityRestrictionCondition_s* x = ZX_ZALLOC(c, struct zx_sec12_ValidityRestrictionCondition_s);
  x->gg.g.tok = zx_sec12_ValidityRestrictionCondition_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->NumberOfUses);

}

/* FUNC(zx_DEEP_CLONE_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ValidityRestrictionCondition_s* zx_DEEP_CLONE_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, int dup_strs)
{
  x = (struct zx_sec12_ValidityRestrictionCondition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ValidityRestrictionCondition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->NumberOfUses = zx_deep_clone_simple_elems(c,x->NumberOfUses, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->NumberOfUses, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ValidityRestrictionCondition) */

int zx_WALK_WO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sec12-aux.c */
