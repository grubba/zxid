/* c/zx-ds-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ds-data.h"



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

#define EL_NAME   ds_CanonicalizationMethod
#define EL_STRUCT zx_ds_CanonicalizationMethod_s
#define EL_NS     ds
#define EL_TAG    CanonicalizationMethod

/* FUNC(zx_FREE_ds_CanonicalizationMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_CanonicalizationMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_CanonicalizationMethod_s* zx_NEW_ds_CanonicalizationMethod(struct zx_ctx* c)
{
  struct zx_ds_CanonicalizationMethod_s* x = ZX_ZALLOC(c, struct zx_ds_CanonicalizationMethod_s);
  x->gg.g.tok = zx_ds_CanonicalizationMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_CanonicalizationMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);


}

/* FUNC(zx_DEEP_CLONE_ds_CanonicalizationMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_CanonicalizationMethod_s* zx_DEEP_CLONE_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x, int dup_strs)
{
  x = (struct zx_ds_CanonicalizationMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_CanonicalizationMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);


  return x;
}

/* FUNC(zx_WALK_SO_ds_CanonicalizationMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ds_CanonicalizationMethod) */

int zx_WALK_WO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_DSAKeyValue
#define EL_STRUCT zx_ds_DSAKeyValue_s
#define EL_NS     ds
#define EL_TAG    DSAKeyValue

/* FUNC(zx_FREE_ds_DSAKeyValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->P, free_strs);
  zx_free_simple_elems(c, x->Q, free_strs);
  zx_free_simple_elems(c, x->G, free_strs);
  zx_free_simple_elems(c, x->Y, free_strs);
  zx_free_simple_elems(c, x->J, free_strs);
  zx_free_simple_elems(c, x->Seed, free_strs);
  zx_free_simple_elems(c, x->PgenCounter, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_DSAKeyValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_DSAKeyValue_s* zx_NEW_ds_DSAKeyValue(struct zx_ctx* c)
{
  struct zx_ds_DSAKeyValue_s* x = ZX_ZALLOC(c, struct zx_ds_DSAKeyValue_s);
  x->gg.g.tok = zx_ds_DSAKeyValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_DSAKeyValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->P);
  zx_dup_strs_simple_elems(c, x->Q);
  zx_dup_strs_simple_elems(c, x->G);
  zx_dup_strs_simple_elems(c, x->Y);
  zx_dup_strs_simple_elems(c, x->J);
  zx_dup_strs_simple_elems(c, x->Seed);
  zx_dup_strs_simple_elems(c, x->PgenCounter);

}

/* FUNC(zx_DEEP_CLONE_ds_DSAKeyValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_DSAKeyValue_s* zx_DEEP_CLONE_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x, int dup_strs)
{
  x = (struct zx_ds_DSAKeyValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_DSAKeyValue_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->P = zx_deep_clone_simple_elems(c,x->P, dup_strs);
  x->Q = zx_deep_clone_simple_elems(c,x->Q, dup_strs);
  x->G = zx_deep_clone_simple_elems(c,x->G, dup_strs);
  x->Y = zx_deep_clone_simple_elems(c,x->Y, dup_strs);
  x->J = zx_deep_clone_simple_elems(c,x->J, dup_strs);
  x->Seed = zx_deep_clone_simple_elems(c,x->Seed, dup_strs);
  x->PgenCounter = zx_deep_clone_simple_elems(c,x->PgenCounter, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_DSAKeyValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->P, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Q, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->G, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Y, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->J, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Seed, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PgenCounter, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_DSAKeyValue) */

int zx_WALK_WO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_DigestMethod
#define EL_STRUCT zx_ds_DigestMethod_s
#define EL_NS     ds
#define EL_TAG    DigestMethod

/* FUNC(zx_FREE_ds_DigestMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_DigestMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_DigestMethod_s* zx_NEW_ds_DigestMethod(struct zx_ctx* c)
{
  struct zx_ds_DigestMethod_s* x = ZX_ZALLOC(c, struct zx_ds_DigestMethod_s);
  x->gg.g.tok = zx_ds_DigestMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_DigestMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);


}

/* FUNC(zx_DEEP_CLONE_ds_DigestMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_DigestMethod_s* zx_DEEP_CLONE_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x, int dup_strs)
{
  x = (struct zx_ds_DigestMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_DigestMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);


  return x;
}

/* FUNC(zx_WALK_SO_ds_DigestMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ds_DigestMethod) */

int zx_WALK_WO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_KeyInfo
#define EL_STRUCT zx_ds_KeyInfo_s
#define EL_NS     ds
#define EL_TAG    KeyInfo

/* FUNC(zx_FREE_ds_KeyInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  zx_free_simple_elems(c, x->KeyName, free_strs);
  {
      struct zx_ds_KeyValue_s* e;
      struct zx_ds_KeyValue_s* en;
      for (e = x->KeyValue; e; e = en) {
	  en = (struct zx_ds_KeyValue_s*)e->gg.g.n;
	  zx_FREE_ds_KeyValue(c, e, free_strs);
      }
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      struct zx_ds_RetrievalMethod_s* en;
      for (e = x->RetrievalMethod; e; e = en) {
	  en = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n;
	  zx_FREE_ds_RetrievalMethod(c, e, free_strs);
      }
  }
  {
      struct zx_ds_X509Data_s* e;
      struct zx_ds_X509Data_s* en;
      for (e = x->X509Data; e; e = en) {
	  en = (struct zx_ds_X509Data_s*)e->gg.g.n;
	  zx_FREE_ds_X509Data(c, e, free_strs);
      }
  }
  {
      struct zx_ds_PGPData_s* e;
      struct zx_ds_PGPData_s* en;
      for (e = x->PGPData; e; e = en) {
	  en = (struct zx_ds_PGPData_s*)e->gg.g.n;
	  zx_FREE_ds_PGPData(c, e, free_strs);
      }
  }
  {
      struct zx_ds_SPKIData_s* e;
      struct zx_ds_SPKIData_s* en;
      for (e = x->SPKIData; e; e = en) {
	  en = (struct zx_ds_SPKIData_s*)e->gg.g.n;
	  zx_FREE_ds_SPKIData(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MgmtData, free_strs);
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

/* FUNC(zx_NEW_ds_KeyInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_KeyInfo_s* zx_NEW_ds_KeyInfo(struct zx_ctx* c)
{
  struct zx_ds_KeyInfo_s* x = ZX_ZALLOC(c, struct zx_ds_KeyInfo_s);
  x->gg.g.tok = zx_ds_KeyInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_KeyInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  zx_dup_strs_simple_elems(c, x->KeyName);
  {
      struct zx_ds_KeyValue_s* e;
      for (e = x->KeyValue; e; e = (struct zx_ds_KeyValue_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyValue(c, e);
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      for (e = x->RetrievalMethod; e; e = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_RetrievalMethod(c, e);
  }
  {
      struct zx_ds_X509Data_s* e;
      for (e = x->X509Data; e; e = (struct zx_ds_X509Data_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_X509Data(c, e);
  }
  {
      struct zx_ds_PGPData_s* e;
      for (e = x->PGPData; e; e = (struct zx_ds_PGPData_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_PGPData(c, e);
  }
  {
      struct zx_ds_SPKIData_s* e;
      for (e = x->SPKIData; e; e = (struct zx_ds_SPKIData_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_SPKIData(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MgmtData);
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptedKey(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_KeyInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_KeyInfo_s* zx_DEEP_CLONE_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x, int dup_strs)
{
  x = (struct zx_ds_KeyInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_KeyInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  x->KeyName = zx_deep_clone_simple_elems(c,x->KeyName, dup_strs);
  {
      struct zx_ds_KeyValue_s* e;
      struct zx_ds_KeyValue_s* en;
      struct zx_ds_KeyValue_s* enn;
      for (enn = 0, e = x->KeyValue; e; e = (struct zx_ds_KeyValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_KeyValue(c, e, dup_strs);
	  if (!enn)
	      x->KeyValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      struct zx_ds_RetrievalMethod_s* en;
      struct zx_ds_RetrievalMethod_s* enn;
      for (enn = 0, e = x->RetrievalMethod; e; e = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_RetrievalMethod(c, e, dup_strs);
	  if (!enn)
	      x->RetrievalMethod = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_X509Data_s* e;
      struct zx_ds_X509Data_s* en;
      struct zx_ds_X509Data_s* enn;
      for (enn = 0, e = x->X509Data; e; e = (struct zx_ds_X509Data_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_X509Data(c, e, dup_strs);
	  if (!enn)
	      x->X509Data = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_PGPData_s* e;
      struct zx_ds_PGPData_s* en;
      struct zx_ds_PGPData_s* enn;
      for (enn = 0, e = x->PGPData; e; e = (struct zx_ds_PGPData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_PGPData(c, e, dup_strs);
	  if (!enn)
	      x->PGPData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_SPKIData_s* e;
      struct zx_ds_SPKIData_s* en;
      struct zx_ds_SPKIData_s* enn;
      for (enn = 0, e = x->SPKIData; e; e = (struct zx_ds_SPKIData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_SPKIData(c, e, dup_strs);
	  if (!enn)
	      x->SPKIData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MgmtData = zx_deep_clone_simple_elems(c,x->MgmtData, dup_strs);
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

/* FUNC(zx_WALK_SO_ds_KeyInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->KeyName, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_ds_KeyValue_s* e;
      for (e = x->KeyValue; e; e = (struct zx_ds_KeyValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_KeyValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      for (e = x->RetrievalMethod; e; e = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_RetrievalMethod(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_X509Data_s* e;
      for (e = x->X509Data; e; e = (struct zx_ds_X509Data_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_X509Data(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_PGPData_s* e;
      for (e = x->PGPData; e; e = (struct zx_ds_PGPData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_PGPData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_SPKIData_s* e;
      for (e = x->SPKIData; e; e = (struct zx_ds_SPKIData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_SPKIData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MgmtData, ctx, callback);
  if (ret)
    return ret;
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

/* FUNC(zx_WALK_WO_ds_KeyInfo) */

int zx_WALK_WO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_KeyValue
#define EL_STRUCT zx_ds_KeyValue_s
#define EL_NS     ds
#define EL_TAG    KeyValue

/* FUNC(zx_FREE_ds_KeyValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_DSAKeyValue_s* e;
      struct zx_ds_DSAKeyValue_s* en;
      for (e = x->DSAKeyValue; e; e = en) {
	  en = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n;
	  zx_FREE_ds_DSAKeyValue(c, e, free_strs);
      }
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      struct zx_ds_RSAKeyValue_s* en;
      for (e = x->RSAKeyValue; e; e = en) {
	  en = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n;
	  zx_FREE_ds_RSAKeyValue(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_KeyValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_KeyValue_s* zx_NEW_ds_KeyValue(struct zx_ctx* c)
{
  struct zx_ds_KeyValue_s* x = ZX_ZALLOC(c, struct zx_ds_KeyValue_s);
  x->gg.g.tok = zx_ds_KeyValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_KeyValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_DSAKeyValue_s* e;
      for (e = x->DSAKeyValue; e; e = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_DSAKeyValue(c, e);
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      for (e = x->RSAKeyValue; e; e = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_RSAKeyValue(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_KeyValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_KeyValue_s* zx_DEEP_CLONE_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x, int dup_strs)
{
  x = (struct zx_ds_KeyValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_KeyValue_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_DSAKeyValue_s* e;
      struct zx_ds_DSAKeyValue_s* en;
      struct zx_ds_DSAKeyValue_s* enn;
      for (enn = 0, e = x->DSAKeyValue; e; e = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_DSAKeyValue(c, e, dup_strs);
	  if (!enn)
	      x->DSAKeyValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      struct zx_ds_RSAKeyValue_s* en;
      struct zx_ds_RSAKeyValue_s* enn;
      for (enn = 0, e = x->RSAKeyValue; e; e = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_RSAKeyValue(c, e, dup_strs);
	  if (!enn)
	      x->RSAKeyValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_KeyValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_DSAKeyValue_s* e;
      for (e = x->DSAKeyValue; e; e = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_DSAKeyValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      for (e = x->RSAKeyValue; e; e = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_RSAKeyValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_KeyValue) */

int zx_WALK_WO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_Manifest
#define EL_STRUCT zx_ds_Manifest_s
#define EL_NS     ds
#define EL_TAG    Manifest

/* FUNC(zx_FREE_ds_Manifest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_ds_Reference_s* e;
      struct zx_ds_Reference_s* en;
      for (e = x->Reference; e; e = en) {
	  en = (struct zx_ds_Reference_s*)e->gg.g.n;
	  zx_FREE_ds_Reference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_Manifest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_Manifest_s* zx_NEW_ds_Manifest(struct zx_ctx* c)
{
  struct zx_ds_Manifest_s* x = ZX_ZALLOC(c, struct zx_ds_Manifest_s);
  x->gg.g.tok = zx_ds_Manifest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_Manifest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Reference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_Manifest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_Manifest_s* zx_DEEP_CLONE_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x, int dup_strs)
{
  x = (struct zx_ds_Manifest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_Manifest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_ds_Reference_s* e;
      struct zx_ds_Reference_s* en;
      struct zx_ds_Reference_s* enn;
      for (enn = 0, e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Reference(c, e, dup_strs);
	  if (!enn)
	      x->Reference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_Manifest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Reference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_Manifest) */

int zx_WALK_WO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_Object
#define EL_STRUCT zx_ds_Object_s
#define EL_NS     ds
#define EL_TAG    Object

/* FUNC(zx_FREE_ds_Object) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Encoding, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->MimeType, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_Object) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_Object_s* zx_NEW_ds_Object(struct zx_ctx* c)
{
  struct zx_ds_Object_s* x = ZX_ZALLOC(c, struct zx_ds_Object_s);
  x->gg.g.tok = zx_ds_Object_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_Object) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Encoding);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->MimeType);


}

/* FUNC(zx_DEEP_CLONE_ds_Object) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_Object_s* zx_DEEP_CLONE_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x, int dup_strs)
{
  x = (struct zx_ds_Object_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_Object_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Encoding = zx_clone_attr(c, x->Encoding);
  x->Id = zx_clone_attr(c, x->Id);
  x->MimeType = zx_clone_attr(c, x->MimeType);


  return x;
}

/* FUNC(zx_WALK_SO_ds_Object) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ds_Object) */

int zx_WALK_WO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_PGPData
#define EL_STRUCT zx_ds_PGPData_s
#define EL_NS     ds
#define EL_TAG    PGPData

/* FUNC(zx_FREE_ds_PGPData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PGPKeyID, free_strs);
  zx_free_simple_elems(c, x->PGPKeyPacket, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_PGPData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_PGPData_s* zx_NEW_ds_PGPData(struct zx_ctx* c)
{
  struct zx_ds_PGPData_s* x = ZX_ZALLOC(c, struct zx_ds_PGPData_s);
  x->gg.g.tok = zx_ds_PGPData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_PGPData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PGPKeyID);
  zx_dup_strs_simple_elems(c, x->PGPKeyPacket);

}

/* FUNC(zx_DEEP_CLONE_ds_PGPData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_PGPData_s* zx_DEEP_CLONE_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x, int dup_strs)
{
  x = (struct zx_ds_PGPData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_PGPData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PGPKeyID = zx_deep_clone_simple_elems(c,x->PGPKeyID, dup_strs);
  x->PGPKeyPacket = zx_deep_clone_simple_elems(c,x->PGPKeyPacket, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_PGPData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PGPKeyID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PGPKeyPacket, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_PGPData) */

int zx_WALK_WO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_RSAKeyValue
#define EL_STRUCT zx_ds_RSAKeyValue_s
#define EL_NS     ds
#define EL_TAG    RSAKeyValue

/* FUNC(zx_FREE_ds_RSAKeyValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Modulus, free_strs);
  zx_free_simple_elems(c, x->Exponent, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_RSAKeyValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_RSAKeyValue_s* zx_NEW_ds_RSAKeyValue(struct zx_ctx* c)
{
  struct zx_ds_RSAKeyValue_s* x = ZX_ZALLOC(c, struct zx_ds_RSAKeyValue_s);
  x->gg.g.tok = zx_ds_RSAKeyValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_RSAKeyValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Modulus);
  zx_dup_strs_simple_elems(c, x->Exponent);

}

/* FUNC(zx_DEEP_CLONE_ds_RSAKeyValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_RSAKeyValue_s* zx_DEEP_CLONE_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x, int dup_strs)
{
  x = (struct zx_ds_RSAKeyValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_RSAKeyValue_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Modulus = zx_deep_clone_simple_elems(c,x->Modulus, dup_strs);
  x->Exponent = zx_deep_clone_simple_elems(c,x->Exponent, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_RSAKeyValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Modulus, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Exponent, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_RSAKeyValue) */

int zx_WALK_WO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_Reference
#define EL_STRUCT zx_ds_Reference_s
#define EL_NS     ds
#define EL_TAG    Reference

/* FUNC(zx_FREE_ds_Reference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->Type, free_strs);
  zx_free_attr(c, x->URI, free_strs);

  {
      struct zx_ds_Transforms_s* e;
      struct zx_ds_Transforms_s* en;
      for (e = x->Transforms; e; e = en) {
	  en = (struct zx_ds_Transforms_s*)e->gg.g.n;
	  zx_FREE_ds_Transforms(c, e, free_strs);
      }
  }
  {
      struct zx_ds_DigestMethod_s* e;
      struct zx_ds_DigestMethod_s* en;
      for (e = x->DigestMethod; e; e = en) {
	  en = (struct zx_ds_DigestMethod_s*)e->gg.g.n;
	  zx_FREE_ds_DigestMethod(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->DigestValue, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_Reference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_Reference_s* zx_NEW_ds_Reference(struct zx_ctx* c)
{
  struct zx_ds_Reference_s* x = ZX_ZALLOC(c, struct zx_ds_Reference_s);
  x->gg.g.tok = zx_ds_Reference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_Reference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->Type);
  zx_dup_attr(c, x->URI);

  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Transforms(c, e);
  }
  {
      struct zx_ds_DigestMethod_s* e;
      for (e = x->DigestMethod; e; e = (struct zx_ds_DigestMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_DigestMethod(c, e);
  }
  zx_dup_strs_simple_elems(c, x->DigestValue);

}

/* FUNC(zx_DEEP_CLONE_ds_Reference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_Reference_s* zx_DEEP_CLONE_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x, int dup_strs)
{
  x = (struct zx_ds_Reference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_Reference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);
  x->Type = zx_clone_attr(c, x->Type);
  x->URI = zx_clone_attr(c, x->URI);

  {
      struct zx_ds_Transforms_s* e;
      struct zx_ds_Transforms_s* en;
      struct zx_ds_Transforms_s* enn;
      for (enn = 0, e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Transforms(c, e, dup_strs);
	  if (!enn)
	      x->Transforms = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_DigestMethod_s* e;
      struct zx_ds_DigestMethod_s* en;
      struct zx_ds_DigestMethod_s* enn;
      for (enn = 0, e = x->DigestMethod; e; e = (struct zx_ds_DigestMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_DigestMethod(c, e, dup_strs);
	  if (!enn)
	      x->DigestMethod = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->DigestValue = zx_deep_clone_simple_elems(c,x->DigestValue, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_Reference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Transforms(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_DigestMethod_s* e;
      for (e = x->DigestMethod; e; e = (struct zx_ds_DigestMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_DigestMethod(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->DigestValue, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_Reference) */

int zx_WALK_WO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_RetrievalMethod
#define EL_STRUCT zx_ds_RetrievalMethod_s
#define EL_NS     ds
#define EL_TAG    RetrievalMethod

/* FUNC(zx_FREE_ds_RetrievalMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Type, free_strs);
  zx_free_attr(c, x->URI, free_strs);

  {
      struct zx_ds_Transforms_s* e;
      struct zx_ds_Transforms_s* en;
      for (e = x->Transforms; e; e = en) {
	  en = (struct zx_ds_Transforms_s*)e->gg.g.n;
	  zx_FREE_ds_Transforms(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_RetrievalMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_RetrievalMethod_s* zx_NEW_ds_RetrievalMethod(struct zx_ctx* c)
{
  struct zx_ds_RetrievalMethod_s* x = ZX_ZALLOC(c, struct zx_ds_RetrievalMethod_s);
  x->gg.g.tok = zx_ds_RetrievalMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_RetrievalMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Type);
  zx_dup_attr(c, x->URI);

  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Transforms(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_RetrievalMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_RetrievalMethod_s* zx_DEEP_CLONE_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x, int dup_strs)
{
  x = (struct zx_ds_RetrievalMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_RetrievalMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Type = zx_clone_attr(c, x->Type);
  x->URI = zx_clone_attr(c, x->URI);

  {
      struct zx_ds_Transforms_s* e;
      struct zx_ds_Transforms_s* en;
      struct zx_ds_Transforms_s* enn;
      for (enn = 0, e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Transforms(c, e, dup_strs);
	  if (!enn)
	      x->Transforms = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_RetrievalMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Transforms(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_RetrievalMethod) */

int zx_WALK_WO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_SPKIData
#define EL_STRUCT zx_ds_SPKIData_s
#define EL_NS     ds
#define EL_TAG    SPKIData

/* FUNC(zx_FREE_ds_SPKIData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->SPKISexp, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_SPKIData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_SPKIData_s* zx_NEW_ds_SPKIData(struct zx_ctx* c)
{
  struct zx_ds_SPKIData_s* x = ZX_ZALLOC(c, struct zx_ds_SPKIData_s);
  x->gg.g.tok = zx_ds_SPKIData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_SPKIData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->SPKISexp);

}

/* FUNC(zx_DEEP_CLONE_ds_SPKIData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_SPKIData_s* zx_DEEP_CLONE_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x, int dup_strs)
{
  x = (struct zx_ds_SPKIData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_SPKIData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->SPKISexp = zx_deep_clone_simple_elems(c,x->SPKISexp, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_SPKIData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SPKISexp, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_SPKIData) */

int zx_WALK_WO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_Signature
#define EL_STRUCT zx_ds_Signature_s
#define EL_NS     ds
#define EL_TAG    Signature

/* FUNC(zx_FREE_ds_Signature) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_ds_SignedInfo_s* e;
      struct zx_ds_SignedInfo_s* en;
      for (e = x->SignedInfo; e; e = en) {
	  en = (struct zx_ds_SignedInfo_s*)e->gg.g.n;
	  zx_FREE_ds_SignedInfo(c, e, free_strs);
      }
  }
  {
      struct zx_ds_SignatureValue_s* e;
      struct zx_ds_SignatureValue_s* en;
      for (e = x->SignatureValue; e; e = en) {
	  en = (struct zx_ds_SignatureValue_s*)e->gg.g.n;
	  zx_FREE_ds_SignatureValue(c, e, free_strs);
      }
  }
  {
      struct zx_ds_KeyInfo_s* e;
      struct zx_ds_KeyInfo_s* en;
      for (e = x->KeyInfo; e; e = en) {
	  en = (struct zx_ds_KeyInfo_s*)e->gg.g.n;
	  zx_FREE_ds_KeyInfo(c, e, free_strs);
      }
  }
  {
      struct zx_ds_Object_s* e;
      struct zx_ds_Object_s* en;
      for (e = x->Object; e; e = en) {
	  en = (struct zx_ds_Object_s*)e->gg.g.n;
	  zx_FREE_ds_Object(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_Signature) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_Signature_s* zx_NEW_ds_Signature(struct zx_ctx* c)
{
  struct zx_ds_Signature_s* x = ZX_ZALLOC(c, struct zx_ds_Signature_s);
  x->gg.g.tok = zx_ds_Signature_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_Signature) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  {
      struct zx_ds_SignedInfo_s* e;
      for (e = x->SignedInfo; e; e = (struct zx_ds_SignedInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_SignedInfo(c, e);
  }
  {
      struct zx_ds_SignatureValue_s* e;
      for (e = x->SignatureValue; e; e = (struct zx_ds_SignatureValue_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_SignatureValue(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }
  {
      struct zx_ds_Object_s* e;
      for (e = x->Object; e; e = (struct zx_ds_Object_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Object(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_Signature) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_Signature_s* zx_DEEP_CLONE_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x, int dup_strs)
{
  x = (struct zx_ds_Signature_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_Signature_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_ds_SignedInfo_s* e;
      struct zx_ds_SignedInfo_s* en;
      struct zx_ds_SignedInfo_s* enn;
      for (enn = 0, e = x->SignedInfo; e; e = (struct zx_ds_SignedInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_SignedInfo(c, e, dup_strs);
	  if (!enn)
	      x->SignedInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_SignatureValue_s* e;
      struct zx_ds_SignatureValue_s* en;
      struct zx_ds_SignatureValue_s* enn;
      for (enn = 0, e = x->SignatureValue; e; e = (struct zx_ds_SignatureValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_SignatureValue(c, e, dup_strs);
	  if (!enn)
	      x->SignatureValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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
  {
      struct zx_ds_Object_s* e;
      struct zx_ds_Object_s* en;
      struct zx_ds_Object_s* enn;
      for (enn = 0, e = x->Object; e; e = (struct zx_ds_Object_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Object(c, e, dup_strs);
	  if (!enn)
	      x->Object = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_Signature) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_SignedInfo_s* e;
      for (e = x->SignedInfo; e; e = (struct zx_ds_SignedInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_SignedInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_SignatureValue_s* e;
      for (e = x->SignatureValue; e; e = (struct zx_ds_SignatureValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_SignatureValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_KeyInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_Object_s* e;
      for (e = x->Object; e; e = (struct zx_ds_Object_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Object(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_Signature) */

int zx_WALK_WO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_SignatureMethod
#define EL_STRUCT zx_ds_SignatureMethod_s
#define EL_NS     ds
#define EL_TAG    SignatureMethod

/* FUNC(zx_FREE_ds_SignatureMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);

  zx_free_simple_elems(c, x->HMACOutputLength, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_SignatureMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_SignatureMethod_s* zx_NEW_ds_SignatureMethod(struct zx_ctx* c)
{
  struct zx_ds_SignatureMethod_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureMethod_s);
  x->gg.g.tok = zx_ds_SignatureMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_SignatureMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);

  zx_dup_strs_simple_elems(c, x->HMACOutputLength);

}

/* FUNC(zx_DEEP_CLONE_ds_SignatureMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_SignatureMethod_s* zx_DEEP_CLONE_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x, int dup_strs)
{
  x = (struct zx_ds_SignatureMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_SignatureMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);

  x->HMACOutputLength = zx_deep_clone_simple_elems(c,x->HMACOutputLength, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_SignatureMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->HMACOutputLength, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_SignatureMethod) */

int zx_WALK_WO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_SignatureProperties
#define EL_STRUCT zx_ds_SignatureProperties_s
#define EL_NS     ds
#define EL_TAG    SignatureProperties

/* FUNC(zx_FREE_ds_SignatureProperties) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_ds_SignatureProperty_s* e;
      struct zx_ds_SignatureProperty_s* en;
      for (e = x->SignatureProperty; e; e = en) {
	  en = (struct zx_ds_SignatureProperty_s*)e->gg.g.n;
	  zx_FREE_ds_SignatureProperty(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_SignatureProperties) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_SignatureProperties_s* zx_NEW_ds_SignatureProperties(struct zx_ctx* c)
{
  struct zx_ds_SignatureProperties_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureProperties_s);
  x->gg.g.tok = zx_ds_SignatureProperties_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_SignatureProperties) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  {
      struct zx_ds_SignatureProperty_s* e;
      for (e = x->SignatureProperty; e; e = (struct zx_ds_SignatureProperty_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_SignatureProperty(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_SignatureProperties) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_SignatureProperties_s* zx_DEEP_CLONE_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x, int dup_strs)
{
  x = (struct zx_ds_SignatureProperties_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_SignatureProperties_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_ds_SignatureProperty_s* e;
      struct zx_ds_SignatureProperty_s* en;
      struct zx_ds_SignatureProperty_s* enn;
      for (enn = 0, e = x->SignatureProperty; e; e = (struct zx_ds_SignatureProperty_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_SignatureProperty(c, e, dup_strs);
	  if (!enn)
	      x->SignatureProperty = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_SignatureProperties) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_SignatureProperty_s* e;
      for (e = x->SignatureProperty; e; e = (struct zx_ds_SignatureProperty_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_SignatureProperty(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_SignatureProperties) */

int zx_WALK_WO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_SignatureProperty
#define EL_STRUCT zx_ds_SignatureProperty_s
#define EL_NS     ds
#define EL_TAG    SignatureProperty

/* FUNC(zx_FREE_ds_SignatureProperty) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->Target, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_SignatureProperty) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_SignatureProperty_s* zx_NEW_ds_SignatureProperty(struct zx_ctx* c)
{
  struct zx_ds_SignatureProperty_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureProperty_s);
  x->gg.g.tok = zx_ds_SignatureProperty_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_SignatureProperty) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->Target);


}

/* FUNC(zx_DEEP_CLONE_ds_SignatureProperty) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_SignatureProperty_s* zx_DEEP_CLONE_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x, int dup_strs)
{
  x = (struct zx_ds_SignatureProperty_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_SignatureProperty_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);
  x->Target = zx_clone_attr(c, x->Target);


  return x;
}

/* FUNC(zx_WALK_SO_ds_SignatureProperty) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ds_SignatureProperty) */

int zx_WALK_WO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_SignatureValue
#define EL_STRUCT zx_ds_SignatureValue_s
#define EL_NS     ds
#define EL_TAG    SignatureValue

/* FUNC(zx_FREE_ds_SignatureValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_SignatureValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_SignatureValue_s* zx_NEW_ds_SignatureValue(struct zx_ctx* c)
{
  struct zx_ds_SignatureValue_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureValue_s);
  x->gg.g.tok = zx_ds_SignatureValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_SignatureValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_ds_SignatureValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_SignatureValue_s* zx_DEEP_CLONE_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x, int dup_strs)
{
  x = (struct zx_ds_SignatureValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_SignatureValue_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_ds_SignatureValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ds_SignatureValue) */

int zx_WALK_WO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_SignedInfo
#define EL_STRUCT zx_ds_SignedInfo_s
#define EL_NS     ds
#define EL_TAG    SignedInfo

/* FUNC(zx_FREE_ds_SignedInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_ds_CanonicalizationMethod_s* e;
      struct zx_ds_CanonicalizationMethod_s* en;
      for (e = x->CanonicalizationMethod; e; e = en) {
	  en = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n;
	  zx_FREE_ds_CanonicalizationMethod(c, e, free_strs);
      }
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      struct zx_ds_SignatureMethod_s* en;
      for (e = x->SignatureMethod; e; e = en) {
	  en = (struct zx_ds_SignatureMethod_s*)e->gg.g.n;
	  zx_FREE_ds_SignatureMethod(c, e, free_strs);
      }
  }
  {
      struct zx_ds_Reference_s* e;
      struct zx_ds_Reference_s* en;
      for (e = x->Reference; e; e = en) {
	  en = (struct zx_ds_Reference_s*)e->gg.g.n;
	  zx_FREE_ds_Reference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_SignedInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_SignedInfo_s* zx_NEW_ds_SignedInfo(struct zx_ctx* c)
{
  struct zx_ds_SignedInfo_s* x = ZX_ZALLOC(c, struct zx_ds_SignedInfo_s);
  x->gg.g.tok = zx_ds_SignedInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_SignedInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  {
      struct zx_ds_CanonicalizationMethod_s* e;
      for (e = x->CanonicalizationMethod; e; e = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_CanonicalizationMethod(c, e);
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      for (e = x->SignatureMethod; e; e = (struct zx_ds_SignatureMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_SignatureMethod(c, e);
  }
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Reference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_SignedInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_SignedInfo_s* zx_DEEP_CLONE_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x, int dup_strs)
{
  x = (struct zx_ds_SignedInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_SignedInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_ds_CanonicalizationMethod_s* e;
      struct zx_ds_CanonicalizationMethod_s* en;
      struct zx_ds_CanonicalizationMethod_s* enn;
      for (enn = 0, e = x->CanonicalizationMethod; e; e = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_CanonicalizationMethod(c, e, dup_strs);
	  if (!enn)
	      x->CanonicalizationMethod = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      struct zx_ds_SignatureMethod_s* en;
      struct zx_ds_SignatureMethod_s* enn;
      for (enn = 0, e = x->SignatureMethod; e; e = (struct zx_ds_SignatureMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_SignatureMethod(c, e, dup_strs);
	  if (!enn)
	      x->SignatureMethod = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ds_Reference_s* e;
      struct zx_ds_Reference_s* en;
      struct zx_ds_Reference_s* enn;
      for (enn = 0, e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Reference(c, e, dup_strs);
	  if (!enn)
	      x->Reference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_SignedInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_CanonicalizationMethod_s* e;
      for (e = x->CanonicalizationMethod; e; e = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_CanonicalizationMethod(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      for (e = x->SignatureMethod; e; e = (struct zx_ds_SignatureMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_SignatureMethod(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Reference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_SignedInfo) */

int zx_WALK_WO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_Transform
#define EL_STRUCT zx_ds_Transform_s
#define EL_NS     ds
#define EL_TAG    Transform

/* FUNC(zx_FREE_ds_Transform) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);

  zx_free_simple_elems(c, x->XPath, free_strs);
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      struct zx_exca_InclusiveNamespaces_s* en;
      for (e = x->InclusiveNamespaces; e; e = en) {
	  en = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n;
	  zx_FREE_exca_InclusiveNamespaces(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_Transform) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_Transform_s* zx_NEW_ds_Transform(struct zx_ctx* c)
{
  struct zx_ds_Transform_s* x = ZX_ZALLOC(c, struct zx_ds_Transform_s);
  x->gg.g.tok = zx_ds_Transform_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_Transform) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);

  zx_dup_strs_simple_elems(c, x->XPath);
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      for (e = x->InclusiveNamespaces; e; e = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n)
	  zx_DUP_STRS_exca_InclusiveNamespaces(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_Transform) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_Transform_s* zx_DEEP_CLONE_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x, int dup_strs)
{
  x = (struct zx_ds_Transform_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_Transform_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);

  x->XPath = zx_deep_clone_simple_elems(c,x->XPath, dup_strs);
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      struct zx_exca_InclusiveNamespaces_s* en;
      struct zx_exca_InclusiveNamespaces_s* enn;
      for (enn = 0, e = x->InclusiveNamespaces; e; e = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_exca_InclusiveNamespaces(c, e, dup_strs);
	  if (!enn)
	      x->InclusiveNamespaces = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_Transform) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->XPath, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      for (e = x->InclusiveNamespaces; e; e = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_exca_InclusiveNamespaces(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_Transform) */

int zx_WALK_WO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_Transforms
#define EL_STRUCT zx_ds_Transforms_s
#define EL_NS     ds
#define EL_TAG    Transforms

/* FUNC(zx_FREE_ds_Transforms) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_Transform_s* e;
      struct zx_ds_Transform_s* en;
      for (e = x->Transform; e; e = en) {
	  en = (struct zx_ds_Transform_s*)e->gg.g.n;
	  zx_FREE_ds_Transform(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_Transforms) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_Transforms_s* zx_NEW_ds_Transforms(struct zx_ctx* c)
{
  struct zx_ds_Transforms_s* x = ZX_ZALLOC(c, struct zx_ds_Transforms_s);
  x->gg.g.tok = zx_ds_Transforms_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_Transforms) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_Transform_s* e;
      for (e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Transform(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ds_Transforms) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_Transforms_s* zx_DEEP_CLONE_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x, int dup_strs)
{
  x = (struct zx_ds_Transforms_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_Transforms_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_Transform_s* e;
      struct zx_ds_Transform_s* en;
      struct zx_ds_Transform_s* enn;
      for (enn = 0, e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Transform(c, e, dup_strs);
	  if (!enn)
	      x->Transform = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ds_Transforms) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_Transform_s* e;
      for (e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Transform(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_Transforms) */

int zx_WALK_WO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_X509Data
#define EL_STRUCT zx_ds_X509Data_s
#define EL_NS     ds
#define EL_TAG    X509Data

/* FUNC(zx_FREE_ds_X509Data) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_X509IssuerSerial_s* e;
      struct zx_ds_X509IssuerSerial_s* en;
      for (e = x->X509IssuerSerial; e; e = en) {
	  en = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n;
	  zx_FREE_ds_X509IssuerSerial(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->X509SKI, free_strs);
  zx_free_simple_elems(c, x->X509SubjectName, free_strs);
  zx_free_simple_elems(c, x->X509Certificate, free_strs);
  zx_free_simple_elems(c, x->X509CRL, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_X509Data) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_X509Data_s* zx_NEW_ds_X509Data(struct zx_ctx* c)
{
  struct zx_ds_X509Data_s* x = ZX_ZALLOC(c, struct zx_ds_X509Data_s);
  x->gg.g.tok = zx_ds_X509Data_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_X509Data) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_X509IssuerSerial_s* e;
      for (e = x->X509IssuerSerial; e; e = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_X509IssuerSerial(c, e);
  }
  zx_dup_strs_simple_elems(c, x->X509SKI);
  zx_dup_strs_simple_elems(c, x->X509SubjectName);
  zx_dup_strs_simple_elems(c, x->X509Certificate);
  zx_dup_strs_simple_elems(c, x->X509CRL);

}

/* FUNC(zx_DEEP_CLONE_ds_X509Data) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_X509Data_s* zx_DEEP_CLONE_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x, int dup_strs)
{
  x = (struct zx_ds_X509Data_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_X509Data_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_X509IssuerSerial_s* e;
      struct zx_ds_X509IssuerSerial_s* en;
      struct zx_ds_X509IssuerSerial_s* enn;
      for (enn = 0, e = x->X509IssuerSerial; e; e = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_X509IssuerSerial(c, e, dup_strs);
	  if (!enn)
	      x->X509IssuerSerial = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->X509SKI = zx_deep_clone_simple_elems(c,x->X509SKI, dup_strs);
  x->X509SubjectName = zx_deep_clone_simple_elems(c,x->X509SubjectName, dup_strs);
  x->X509Certificate = zx_deep_clone_simple_elems(c,x->X509Certificate, dup_strs);
  x->X509CRL = zx_deep_clone_simple_elems(c,x->X509CRL, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_X509Data) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_X509IssuerSerial_s* e;
      for (e = x->X509IssuerSerial; e; e = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_X509IssuerSerial(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->X509SKI, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->X509SubjectName, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->X509Certificate, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->X509CRL, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_X509Data) */

int zx_WALK_WO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ds_X509IssuerSerial
#define EL_STRUCT zx_ds_X509IssuerSerial_s
#define EL_NS     ds
#define EL_TAG    X509IssuerSerial

/* FUNC(zx_FREE_ds_X509IssuerSerial) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->X509IssuerName, free_strs);
  zx_free_simple_elems(c, x->X509SerialNumber, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ds_X509IssuerSerial) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ds_X509IssuerSerial_s* zx_NEW_ds_X509IssuerSerial(struct zx_ctx* c)
{
  struct zx_ds_X509IssuerSerial_s* x = ZX_ZALLOC(c, struct zx_ds_X509IssuerSerial_s);
  x->gg.g.tok = zx_ds_X509IssuerSerial_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ds_X509IssuerSerial) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->X509IssuerName);
  zx_dup_strs_simple_elems(c, x->X509SerialNumber);

}

/* FUNC(zx_DEEP_CLONE_ds_X509IssuerSerial) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ds_X509IssuerSerial_s* zx_DEEP_CLONE_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x, int dup_strs)
{
  x = (struct zx_ds_X509IssuerSerial_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ds_X509IssuerSerial_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->X509IssuerName = zx_deep_clone_simple_elems(c,x->X509IssuerName, dup_strs);
  x->X509SerialNumber = zx_deep_clone_simple_elems(c,x->X509SerialNumber, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ds_X509IssuerSerial) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->X509IssuerName, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->X509SerialNumber, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ds_X509IssuerSerial) */

int zx_WALK_WO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-ds-aux.c */
