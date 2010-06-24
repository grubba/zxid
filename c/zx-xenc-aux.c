/* c/zx-xenc-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xenc-data.h"



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

#define EL_NAME   xenc_AgreementMethod
#define EL_STRUCT zx_xenc_AgreementMethod_s
#define EL_NS     xenc
#define EL_TAG    AgreementMethod

/* FUNC(zx_FREE_xenc_AgreementMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_AgreementMethod(struct zx_ctx* c, struct zx_xenc_AgreementMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);

  zx_free_simple_elems(c, x->KA_Nonce, free_strs);
  {
      struct zx_xenc_OriginatorKeyInfo_s* e;
      struct zx_xenc_OriginatorKeyInfo_s* en;
      for (e = x->OriginatorKeyInfo; e; e = en) {
	  en = (struct zx_xenc_OriginatorKeyInfo_s*)e->gg.g.n;
	  zx_FREE_xenc_OriginatorKeyInfo(c, e, free_strs);
      }
  }
  {
      struct zx_xenc_RecipientKeyInfo_s* e;
      struct zx_xenc_RecipientKeyInfo_s* en;
      for (e = x->RecipientKeyInfo; e; e = en) {
	  en = (struct zx_xenc_RecipientKeyInfo_s*)e->gg.g.n;
	  zx_FREE_xenc_RecipientKeyInfo(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_AgreementMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_AgreementMethod_s* zx_NEW_xenc_AgreementMethod(struct zx_ctx* c)
{
  struct zx_xenc_AgreementMethod_s* x = ZX_ZALLOC(c, struct zx_xenc_AgreementMethod_s);
  x->gg.g.tok = zx_xenc_AgreementMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_AgreementMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_AgreementMethod(struct zx_ctx* c, struct zx_xenc_AgreementMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);

  zx_dup_strs_simple_elems(c, x->KA_Nonce);
  {
      struct zx_xenc_OriginatorKeyInfo_s* e;
      for (e = x->OriginatorKeyInfo; e; e = (struct zx_xenc_OriginatorKeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_OriginatorKeyInfo(c, e);
  }
  {
      struct zx_xenc_RecipientKeyInfo_s* e;
      for (e = x->RecipientKeyInfo; e; e = (struct zx_xenc_RecipientKeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_RecipientKeyInfo(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_AgreementMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_AgreementMethod_s* zx_DEEP_CLONE_xenc_AgreementMethod(struct zx_ctx* c, struct zx_xenc_AgreementMethod_s* x, int dup_strs)
{
  x = (struct zx_xenc_AgreementMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_AgreementMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);

  x->KA_Nonce = zx_deep_clone_simple_elems(c,x->KA_Nonce, dup_strs);
  {
      struct zx_xenc_OriginatorKeyInfo_s* e;
      struct zx_xenc_OriginatorKeyInfo_s* en;
      struct zx_xenc_OriginatorKeyInfo_s* enn;
      for (enn = 0, e = x->OriginatorKeyInfo; e; e = (struct zx_xenc_OriginatorKeyInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_OriginatorKeyInfo(c, e, dup_strs);
	  if (!enn)
	      x->OriginatorKeyInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xenc_RecipientKeyInfo_s* e;
      struct zx_xenc_RecipientKeyInfo_s* en;
      struct zx_xenc_RecipientKeyInfo_s* enn;
      for (enn = 0, e = x->RecipientKeyInfo; e; e = (struct zx_xenc_RecipientKeyInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_RecipientKeyInfo(c, e, dup_strs);
	  if (!enn)
	      x->RecipientKeyInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xenc_AgreementMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_AgreementMethod(struct zx_ctx* c, struct zx_xenc_AgreementMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->KA_Nonce, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_xenc_OriginatorKeyInfo_s* e;
      for (e = x->OriginatorKeyInfo; e; e = (struct zx_xenc_OriginatorKeyInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_OriginatorKeyInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xenc_RecipientKeyInfo_s* e;
      for (e = x->RecipientKeyInfo; e; e = (struct zx_xenc_RecipientKeyInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_RecipientKeyInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_AgreementMethod) */

int zx_WALK_WO_xenc_AgreementMethod(struct zx_ctx* c, struct zx_xenc_AgreementMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_CipherData
#define EL_STRUCT zx_xenc_CipherData_s
#define EL_NS     xenc
#define EL_TAG    CipherData

/* FUNC(zx_FREE_xenc_CipherData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_CipherData(struct zx_ctx* c, struct zx_xenc_CipherData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->CipherValue, free_strs);
  {
      struct zx_xenc_CipherReference_s* e;
      struct zx_xenc_CipherReference_s* en;
      for (e = x->CipherReference; e; e = en) {
	  en = (struct zx_xenc_CipherReference_s*)e->gg.g.n;
	  zx_FREE_xenc_CipherReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_CipherData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_CipherData_s* zx_NEW_xenc_CipherData(struct zx_ctx* c)
{
  struct zx_xenc_CipherData_s* x = ZX_ZALLOC(c, struct zx_xenc_CipherData_s);
  x->gg.g.tok = zx_xenc_CipherData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_CipherData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_CipherData(struct zx_ctx* c, struct zx_xenc_CipherData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->CipherValue);
  {
      struct zx_xenc_CipherReference_s* e;
      for (e = x->CipherReference; e; e = (struct zx_xenc_CipherReference_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_CipherReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_CipherData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_CipherData_s* zx_DEEP_CLONE_xenc_CipherData(struct zx_ctx* c, struct zx_xenc_CipherData_s* x, int dup_strs)
{
  x = (struct zx_xenc_CipherData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_CipherData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->CipherValue = zx_deep_clone_simple_elems(c,x->CipherValue, dup_strs);
  {
      struct zx_xenc_CipherReference_s* e;
      struct zx_xenc_CipherReference_s* en;
      struct zx_xenc_CipherReference_s* enn;
      for (enn = 0, e = x->CipherReference; e; e = (struct zx_xenc_CipherReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_CipherReference(c, e, dup_strs);
	  if (!enn)
	      x->CipherReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xenc_CipherData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_CipherData(struct zx_ctx* c, struct zx_xenc_CipherData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->CipherValue, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_xenc_CipherReference_s* e;
      for (e = x->CipherReference; e; e = (struct zx_xenc_CipherReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_CipherReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_CipherData) */

int zx_WALK_WO_xenc_CipherData(struct zx_ctx* c, struct zx_xenc_CipherData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_CipherReference
#define EL_STRUCT zx_xenc_CipherReference_s
#define EL_NS     xenc
#define EL_TAG    CipherReference

/* FUNC(zx_FREE_xenc_CipherReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_CipherReference(struct zx_ctx* c, struct zx_xenc_CipherReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->URI, free_strs);

  {
      struct zx_xenc_Transforms_s* e;
      struct zx_xenc_Transforms_s* en;
      for (e = x->Transforms; e; e = en) {
	  en = (struct zx_xenc_Transforms_s*)e->gg.g.n;
	  zx_FREE_xenc_Transforms(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_CipherReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_CipherReference_s* zx_NEW_xenc_CipherReference(struct zx_ctx* c)
{
  struct zx_xenc_CipherReference_s* x = ZX_ZALLOC(c, struct zx_xenc_CipherReference_s);
  x->gg.g.tok = zx_xenc_CipherReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_CipherReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_CipherReference(struct zx_ctx* c, struct zx_xenc_CipherReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->URI);

  {
      struct zx_xenc_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_xenc_Transforms_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_Transforms(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_CipherReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_CipherReference_s* zx_DEEP_CLONE_xenc_CipherReference(struct zx_ctx* c, struct zx_xenc_CipherReference_s* x, int dup_strs)
{
  x = (struct zx_xenc_CipherReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_CipherReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->URI = zx_clone_attr(c, x->URI);

  {
      struct zx_xenc_Transforms_s* e;
      struct zx_xenc_Transforms_s* en;
      struct zx_xenc_Transforms_s* enn;
      for (enn = 0, e = x->Transforms; e; e = (struct zx_xenc_Transforms_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_Transforms(c, e, dup_strs);
	  if (!enn)
	      x->Transforms = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xenc_CipherReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_CipherReference(struct zx_ctx* c, struct zx_xenc_CipherReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xenc_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_xenc_Transforms_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_Transforms(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_CipherReference) */

int zx_WALK_WO_xenc_CipherReference(struct zx_ctx* c, struct zx_xenc_CipherReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_DataReference
#define EL_STRUCT zx_xenc_DataReference_s
#define EL_NS     xenc
#define EL_TAG    DataReference

/* FUNC(zx_FREE_xenc_DataReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_DataReference(struct zx_ctx* c, struct zx_xenc_DataReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->URI, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_DataReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_DataReference_s* zx_NEW_xenc_DataReference(struct zx_ctx* c)
{
  struct zx_xenc_DataReference_s* x = ZX_ZALLOC(c, struct zx_xenc_DataReference_s);
  x->gg.g.tok = zx_xenc_DataReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_DataReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_DataReference(struct zx_ctx* c, struct zx_xenc_DataReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->URI);


}

/* FUNC(zx_DEEP_CLONE_xenc_DataReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_DataReference_s* zx_DEEP_CLONE_xenc_DataReference(struct zx_ctx* c, struct zx_xenc_DataReference_s* x, int dup_strs)
{
  x = (struct zx_xenc_DataReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_DataReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->URI = zx_clone_attr(c, x->URI);


  return x;
}

/* FUNC(zx_WALK_SO_xenc_DataReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_DataReference(struct zx_ctx* c, struct zx_xenc_DataReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xenc_DataReference) */

int zx_WALK_WO_xenc_DataReference(struct zx_ctx* c, struct zx_xenc_DataReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_EncryptedData
#define EL_STRUCT zx_xenc_EncryptedData_s
#define EL_NS     xenc
#define EL_TAG    EncryptedData

/* FUNC(zx_FREE_xenc_EncryptedData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_EncryptedData(struct zx_ctx* c, struct zx_xenc_EncryptedData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Encoding, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->MimeType, free_strs);
  zx_free_attr(c, x->Type, free_strs);

  {
      struct zx_xenc_EncryptionMethod_s* e;
      struct zx_xenc_EncryptionMethod_s* en;
      for (e = x->EncryptionMethod; e; e = en) {
	  en = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptionMethod(c, e, free_strs);
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
      struct zx_xenc_CipherData_s* e;
      struct zx_xenc_CipherData_s* en;
      for (e = x->CipherData; e; e = en) {
	  en = (struct zx_xenc_CipherData_s*)e->gg.g.n;
	  zx_FREE_xenc_CipherData(c, e, free_strs);
      }
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      struct zx_xenc_EncryptionProperties_s* en;
      for (e = x->EncryptionProperties; e; e = en) {
	  en = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptionProperties(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_EncryptedData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_EncryptedData_s* zx_NEW_xenc_EncryptedData(struct zx_ctx* c)
{
  struct zx_xenc_EncryptedData_s* x = ZX_ZALLOC(c, struct zx_xenc_EncryptedData_s);
  x->gg.g.tok = zx_xenc_EncryptedData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_EncryptedData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_EncryptedData(struct zx_ctx* c, struct zx_xenc_EncryptedData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Encoding);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->MimeType);
  zx_dup_attr(c, x->Type);

  {
      struct zx_xenc_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptionMethod(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }
  {
      struct zx_xenc_CipherData_s* e;
      for (e = x->CipherData; e; e = (struct zx_xenc_CipherData_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_CipherData(c, e);
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      for (e = x->EncryptionProperties; e; e = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptionProperties(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_EncryptedData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_EncryptedData_s* zx_DEEP_CLONE_xenc_EncryptedData(struct zx_ctx* c, struct zx_xenc_EncryptedData_s* x, int dup_strs)
{
  x = (struct zx_xenc_EncryptedData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_EncryptedData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Encoding = zx_clone_attr(c, x->Encoding);
  x->Id = zx_clone_attr(c, x->Id);
  x->MimeType = zx_clone_attr(c, x->MimeType);
  x->Type = zx_clone_attr(c, x->Type);

  {
      struct zx_xenc_EncryptionMethod_s* e;
      struct zx_xenc_EncryptionMethod_s* en;
      struct zx_xenc_EncryptionMethod_s* enn;
      for (enn = 0, e = x->EncryptionMethod; e; e = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptionMethod(c, e, dup_strs);
	  if (!enn)
	      x->EncryptionMethod = en;
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
      struct zx_xenc_CipherData_s* e;
      struct zx_xenc_CipherData_s* en;
      struct zx_xenc_CipherData_s* enn;
      for (enn = 0, e = x->CipherData; e; e = (struct zx_xenc_CipherData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_CipherData(c, e, dup_strs);
	  if (!enn)
	      x->CipherData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      struct zx_xenc_EncryptionProperties_s* en;
      struct zx_xenc_EncryptionProperties_s* enn;
      for (enn = 0, e = x->EncryptionProperties; e; e = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptionProperties(c, e, dup_strs);
	  if (!enn)
	      x->EncryptionProperties = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xenc_EncryptedData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_EncryptedData(struct zx_ctx* c, struct zx_xenc_EncryptedData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xenc_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptionMethod(c, e, ctx, callback);
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
      struct zx_xenc_CipherData_s* e;
      for (e = x->CipherData; e; e = (struct zx_xenc_CipherData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_CipherData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      for (e = x->EncryptionProperties; e; e = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptionProperties(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_EncryptedData) */

int zx_WALK_WO_xenc_EncryptedData(struct zx_ctx* c, struct zx_xenc_EncryptedData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_EncryptedKey
#define EL_STRUCT zx_xenc_EncryptedKey_s
#define EL_NS     xenc
#define EL_TAG    EncryptedKey

/* FUNC(zx_FREE_xenc_EncryptedKey) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_EncryptedKey(struct zx_ctx* c, struct zx_xenc_EncryptedKey_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Encoding, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->MimeType, free_strs);
  zx_free_attr(c, x->Recipient, free_strs);
  zx_free_attr(c, x->Type, free_strs);

  {
      struct zx_xenc_EncryptionMethod_s* e;
      struct zx_xenc_EncryptionMethod_s* en;
      for (e = x->EncryptionMethod; e; e = en) {
	  en = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptionMethod(c, e, free_strs);
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
      struct zx_xenc_CipherData_s* e;
      struct zx_xenc_CipherData_s* en;
      for (e = x->CipherData; e; e = en) {
	  en = (struct zx_xenc_CipherData_s*)e->gg.g.n;
	  zx_FREE_xenc_CipherData(c, e, free_strs);
      }
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      struct zx_xenc_EncryptionProperties_s* en;
      for (e = x->EncryptionProperties; e; e = en) {
	  en = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptionProperties(c, e, free_strs);
      }
  }
  {
      struct zx_xenc_ReferenceList_s* e;
      struct zx_xenc_ReferenceList_s* en;
      for (e = x->ReferenceList; e; e = en) {
	  en = (struct zx_xenc_ReferenceList_s*)e->gg.g.n;
	  zx_FREE_xenc_ReferenceList(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->CarriedKeyName, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_EncryptedKey) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_EncryptedKey_s* zx_NEW_xenc_EncryptedKey(struct zx_ctx* c)
{
  struct zx_xenc_EncryptedKey_s* x = ZX_ZALLOC(c, struct zx_xenc_EncryptedKey_s);
  x->gg.g.tok = zx_xenc_EncryptedKey_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_EncryptedKey) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_EncryptedKey(struct zx_ctx* c, struct zx_xenc_EncryptedKey_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Encoding);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->MimeType);
  zx_dup_attr(c, x->Recipient);
  zx_dup_attr(c, x->Type);

  {
      struct zx_xenc_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptionMethod(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }
  {
      struct zx_xenc_CipherData_s* e;
      for (e = x->CipherData; e; e = (struct zx_xenc_CipherData_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_CipherData(c, e);
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      for (e = x->EncryptionProperties; e; e = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptionProperties(c, e);
  }
  {
      struct zx_xenc_ReferenceList_s* e;
      for (e = x->ReferenceList; e; e = (struct zx_xenc_ReferenceList_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_ReferenceList(c, e);
  }
  zx_dup_strs_simple_elems(c, x->CarriedKeyName);

}

/* FUNC(zx_DEEP_CLONE_xenc_EncryptedKey) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_EncryptedKey_s* zx_DEEP_CLONE_xenc_EncryptedKey(struct zx_ctx* c, struct zx_xenc_EncryptedKey_s* x, int dup_strs)
{
  x = (struct zx_xenc_EncryptedKey_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_EncryptedKey_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Encoding = zx_clone_attr(c, x->Encoding);
  x->Id = zx_clone_attr(c, x->Id);
  x->MimeType = zx_clone_attr(c, x->MimeType);
  x->Recipient = zx_clone_attr(c, x->Recipient);
  x->Type = zx_clone_attr(c, x->Type);

  {
      struct zx_xenc_EncryptionMethod_s* e;
      struct zx_xenc_EncryptionMethod_s* en;
      struct zx_xenc_EncryptionMethod_s* enn;
      for (enn = 0, e = x->EncryptionMethod; e; e = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptionMethod(c, e, dup_strs);
	  if (!enn)
	      x->EncryptionMethod = en;
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
      struct zx_xenc_CipherData_s* e;
      struct zx_xenc_CipherData_s* en;
      struct zx_xenc_CipherData_s* enn;
      for (enn = 0, e = x->CipherData; e; e = (struct zx_xenc_CipherData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_CipherData(c, e, dup_strs);
	  if (!enn)
	      x->CipherData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      struct zx_xenc_EncryptionProperties_s* en;
      struct zx_xenc_EncryptionProperties_s* enn;
      for (enn = 0, e = x->EncryptionProperties; e; e = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptionProperties(c, e, dup_strs);
	  if (!enn)
	      x->EncryptionProperties = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xenc_ReferenceList_s* e;
      struct zx_xenc_ReferenceList_s* en;
      struct zx_xenc_ReferenceList_s* enn;
      for (enn = 0, e = x->ReferenceList; e; e = (struct zx_xenc_ReferenceList_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_ReferenceList(c, e, dup_strs);
	  if (!enn)
	      x->ReferenceList = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->CarriedKeyName = zx_deep_clone_simple_elems(c,x->CarriedKeyName, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xenc_EncryptedKey) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_EncryptedKey(struct zx_ctx* c, struct zx_xenc_EncryptedKey_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xenc_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_xenc_EncryptionMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptionMethod(c, e, ctx, callback);
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
      struct zx_xenc_CipherData_s* e;
      for (e = x->CipherData; e; e = (struct zx_xenc_CipherData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_CipherData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xenc_EncryptionProperties_s* e;
      for (e = x->EncryptionProperties; e; e = (struct zx_xenc_EncryptionProperties_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptionProperties(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xenc_ReferenceList_s* e;
      for (e = x->ReferenceList; e; e = (struct zx_xenc_ReferenceList_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_ReferenceList(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->CarriedKeyName, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_EncryptedKey) */

int zx_WALK_WO_xenc_EncryptedKey(struct zx_ctx* c, struct zx_xenc_EncryptedKey_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_EncryptionMethod
#define EL_STRUCT zx_xenc_EncryptionMethod_s
#define EL_NS     xenc
#define EL_TAG    EncryptionMethod

/* FUNC(zx_FREE_xenc_EncryptionMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_EncryptionMethod(struct zx_ctx* c, struct zx_xenc_EncryptionMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);

  zx_free_simple_elems(c, x->KeySize, free_strs);
  zx_free_simple_elems(c, x->OAEPparams, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_EncryptionMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_EncryptionMethod_s* zx_NEW_xenc_EncryptionMethod(struct zx_ctx* c)
{
  struct zx_xenc_EncryptionMethod_s* x = ZX_ZALLOC(c, struct zx_xenc_EncryptionMethod_s);
  x->gg.g.tok = zx_xenc_EncryptionMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_EncryptionMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_EncryptionMethod(struct zx_ctx* c, struct zx_xenc_EncryptionMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);

  zx_dup_strs_simple_elems(c, x->KeySize);
  zx_dup_strs_simple_elems(c, x->OAEPparams);

}

/* FUNC(zx_DEEP_CLONE_xenc_EncryptionMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_EncryptionMethod_s* zx_DEEP_CLONE_xenc_EncryptionMethod(struct zx_ctx* c, struct zx_xenc_EncryptionMethod_s* x, int dup_strs)
{
  x = (struct zx_xenc_EncryptionMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_EncryptionMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);

  x->KeySize = zx_deep_clone_simple_elems(c,x->KeySize, dup_strs);
  x->OAEPparams = zx_deep_clone_simple_elems(c,x->OAEPparams, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xenc_EncryptionMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_EncryptionMethod(struct zx_ctx* c, struct zx_xenc_EncryptionMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->KeySize, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->OAEPparams, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_EncryptionMethod) */

int zx_WALK_WO_xenc_EncryptionMethod(struct zx_ctx* c, struct zx_xenc_EncryptionMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_EncryptionProperties
#define EL_STRUCT zx_xenc_EncryptionProperties_s
#define EL_NS     xenc
#define EL_TAG    EncryptionProperties

/* FUNC(zx_FREE_xenc_EncryptionProperties) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_EncryptionProperties(struct zx_ctx* c, struct zx_xenc_EncryptionProperties_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_xenc_EncryptionProperty_s* e;
      struct zx_xenc_EncryptionProperty_s* en;
      for (e = x->EncryptionProperty; e; e = en) {
	  en = (struct zx_xenc_EncryptionProperty_s*)e->gg.g.n;
	  zx_FREE_xenc_EncryptionProperty(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_EncryptionProperties) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_EncryptionProperties_s* zx_NEW_xenc_EncryptionProperties(struct zx_ctx* c)
{
  struct zx_xenc_EncryptionProperties_s* x = ZX_ZALLOC(c, struct zx_xenc_EncryptionProperties_s);
  x->gg.g.tok = zx_xenc_EncryptionProperties_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_EncryptionProperties) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_EncryptionProperties(struct zx_ctx* c, struct zx_xenc_EncryptionProperties_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  {
      struct zx_xenc_EncryptionProperty_s* e;
      for (e = x->EncryptionProperty; e; e = (struct zx_xenc_EncryptionProperty_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_EncryptionProperty(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_EncryptionProperties) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_EncryptionProperties_s* zx_DEEP_CLONE_xenc_EncryptionProperties(struct zx_ctx* c, struct zx_xenc_EncryptionProperties_s* x, int dup_strs)
{
  x = (struct zx_xenc_EncryptionProperties_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_EncryptionProperties_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_xenc_EncryptionProperty_s* e;
      struct zx_xenc_EncryptionProperty_s* en;
      struct zx_xenc_EncryptionProperty_s* enn;
      for (enn = 0, e = x->EncryptionProperty; e; e = (struct zx_xenc_EncryptionProperty_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_EncryptionProperty(c, e, dup_strs);
	  if (!enn)
	      x->EncryptionProperty = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xenc_EncryptionProperties) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_EncryptionProperties(struct zx_ctx* c, struct zx_xenc_EncryptionProperties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xenc_EncryptionProperty_s* e;
      for (e = x->EncryptionProperty; e; e = (struct zx_xenc_EncryptionProperty_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_EncryptionProperty(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_EncryptionProperties) */

int zx_WALK_WO_xenc_EncryptionProperties(struct zx_ctx* c, struct zx_xenc_EncryptionProperties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_EncryptionProperty
#define EL_STRUCT zx_xenc_EncryptionProperty_s
#define EL_NS     xenc
#define EL_TAG    EncryptionProperty

/* FUNC(zx_FREE_xenc_EncryptionProperty) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_EncryptionProperty(struct zx_ctx* c, struct zx_xenc_EncryptionProperty_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->Target, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_EncryptionProperty) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_EncryptionProperty_s* zx_NEW_xenc_EncryptionProperty(struct zx_ctx* c)
{
  struct zx_xenc_EncryptionProperty_s* x = ZX_ZALLOC(c, struct zx_xenc_EncryptionProperty_s);
  x->gg.g.tok = zx_xenc_EncryptionProperty_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_EncryptionProperty) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_EncryptionProperty(struct zx_ctx* c, struct zx_xenc_EncryptionProperty_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->Target);


}

/* FUNC(zx_DEEP_CLONE_xenc_EncryptionProperty) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_EncryptionProperty_s* zx_DEEP_CLONE_xenc_EncryptionProperty(struct zx_ctx* c, struct zx_xenc_EncryptionProperty_s* x, int dup_strs)
{
  x = (struct zx_xenc_EncryptionProperty_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_EncryptionProperty_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);
  x->Target = zx_clone_attr(c, x->Target);


  return x;
}

/* FUNC(zx_WALK_SO_xenc_EncryptionProperty) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_EncryptionProperty(struct zx_ctx* c, struct zx_xenc_EncryptionProperty_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xenc_EncryptionProperty) */

int zx_WALK_WO_xenc_EncryptionProperty(struct zx_ctx* c, struct zx_xenc_EncryptionProperty_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_KeyReference
#define EL_STRUCT zx_xenc_KeyReference_s
#define EL_NS     xenc
#define EL_TAG    KeyReference

/* FUNC(zx_FREE_xenc_KeyReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_KeyReference(struct zx_ctx* c, struct zx_xenc_KeyReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->URI, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_KeyReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_KeyReference_s* zx_NEW_xenc_KeyReference(struct zx_ctx* c)
{
  struct zx_xenc_KeyReference_s* x = ZX_ZALLOC(c, struct zx_xenc_KeyReference_s);
  x->gg.g.tok = zx_xenc_KeyReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_KeyReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_KeyReference(struct zx_ctx* c, struct zx_xenc_KeyReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->URI);


}

/* FUNC(zx_DEEP_CLONE_xenc_KeyReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_KeyReference_s* zx_DEEP_CLONE_xenc_KeyReference(struct zx_ctx* c, struct zx_xenc_KeyReference_s* x, int dup_strs)
{
  x = (struct zx_xenc_KeyReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_KeyReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->URI = zx_clone_attr(c, x->URI);


  return x;
}

/* FUNC(zx_WALK_SO_xenc_KeyReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_KeyReference(struct zx_ctx* c, struct zx_xenc_KeyReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xenc_KeyReference) */

int zx_WALK_WO_xenc_KeyReference(struct zx_ctx* c, struct zx_xenc_KeyReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_OriginatorKeyInfo
#define EL_STRUCT zx_xenc_OriginatorKeyInfo_s
#define EL_NS     xenc
#define EL_TAG    OriginatorKeyInfo

/* FUNC(zx_FREE_xenc_OriginatorKeyInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_OriginatorKeyInfo(struct zx_ctx* c, struct zx_xenc_OriginatorKeyInfo_s* x, int free_strs)
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

/* FUNC(zx_NEW_xenc_OriginatorKeyInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_OriginatorKeyInfo_s* zx_NEW_xenc_OriginatorKeyInfo(struct zx_ctx* c)
{
  struct zx_xenc_OriginatorKeyInfo_s* x = ZX_ZALLOC(c, struct zx_xenc_OriginatorKeyInfo_s);
  x->gg.g.tok = zx_xenc_OriginatorKeyInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_OriginatorKeyInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_OriginatorKeyInfo(struct zx_ctx* c, struct zx_xenc_OriginatorKeyInfo_s* x)
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

/* FUNC(zx_DEEP_CLONE_xenc_OriginatorKeyInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_OriginatorKeyInfo_s* zx_DEEP_CLONE_xenc_OriginatorKeyInfo(struct zx_ctx* c, struct zx_xenc_OriginatorKeyInfo_s* x, int dup_strs)
{
  x = (struct zx_xenc_OriginatorKeyInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_OriginatorKeyInfo_s), dup_strs);
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

/* FUNC(zx_WALK_SO_xenc_OriginatorKeyInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_OriginatorKeyInfo(struct zx_ctx* c, struct zx_xenc_OriginatorKeyInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xenc_OriginatorKeyInfo) */

int zx_WALK_WO_xenc_OriginatorKeyInfo(struct zx_ctx* c, struct zx_xenc_OriginatorKeyInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_RecipientKeyInfo
#define EL_STRUCT zx_xenc_RecipientKeyInfo_s
#define EL_NS     xenc
#define EL_TAG    RecipientKeyInfo

/* FUNC(zx_FREE_xenc_RecipientKeyInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_RecipientKeyInfo(struct zx_ctx* c, struct zx_xenc_RecipientKeyInfo_s* x, int free_strs)
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

/* FUNC(zx_NEW_xenc_RecipientKeyInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_RecipientKeyInfo_s* zx_NEW_xenc_RecipientKeyInfo(struct zx_ctx* c)
{
  struct zx_xenc_RecipientKeyInfo_s* x = ZX_ZALLOC(c, struct zx_xenc_RecipientKeyInfo_s);
  x->gg.g.tok = zx_xenc_RecipientKeyInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_RecipientKeyInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_RecipientKeyInfo(struct zx_ctx* c, struct zx_xenc_RecipientKeyInfo_s* x)
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

/* FUNC(zx_DEEP_CLONE_xenc_RecipientKeyInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_RecipientKeyInfo_s* zx_DEEP_CLONE_xenc_RecipientKeyInfo(struct zx_ctx* c, struct zx_xenc_RecipientKeyInfo_s* x, int dup_strs)
{
  x = (struct zx_xenc_RecipientKeyInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_RecipientKeyInfo_s), dup_strs);
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

/* FUNC(zx_WALK_SO_xenc_RecipientKeyInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_RecipientKeyInfo(struct zx_ctx* c, struct zx_xenc_RecipientKeyInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xenc_RecipientKeyInfo) */

int zx_WALK_WO_xenc_RecipientKeyInfo(struct zx_ctx* c, struct zx_xenc_RecipientKeyInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_ReferenceList
#define EL_STRUCT zx_xenc_ReferenceList_s
#define EL_NS     xenc
#define EL_TAG    ReferenceList

/* FUNC(zx_FREE_xenc_ReferenceList) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_ReferenceList(struct zx_ctx* c, struct zx_xenc_ReferenceList_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xenc_DataReference_s* e;
      struct zx_xenc_DataReference_s* en;
      for (e = x->DataReference; e; e = en) {
	  en = (struct zx_xenc_DataReference_s*)e->gg.g.n;
	  zx_FREE_xenc_DataReference(c, e, free_strs);
      }
  }
  {
      struct zx_xenc_KeyReference_s* e;
      struct zx_xenc_KeyReference_s* en;
      for (e = x->KeyReference; e; e = en) {
	  en = (struct zx_xenc_KeyReference_s*)e->gg.g.n;
	  zx_FREE_xenc_KeyReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xenc_ReferenceList) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_ReferenceList_s* zx_NEW_xenc_ReferenceList(struct zx_ctx* c)
{
  struct zx_xenc_ReferenceList_s* x = ZX_ZALLOC(c, struct zx_xenc_ReferenceList_s);
  x->gg.g.tok = zx_xenc_ReferenceList_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_ReferenceList) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_ReferenceList(struct zx_ctx* c, struct zx_xenc_ReferenceList_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xenc_DataReference_s* e;
      for (e = x->DataReference; e; e = (struct zx_xenc_DataReference_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_DataReference(c, e);
  }
  {
      struct zx_xenc_KeyReference_s* e;
      for (e = x->KeyReference; e; e = (struct zx_xenc_KeyReference_s*)e->gg.g.n)
	  zx_DUP_STRS_xenc_KeyReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_ReferenceList) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_ReferenceList_s* zx_DEEP_CLONE_xenc_ReferenceList(struct zx_ctx* c, struct zx_xenc_ReferenceList_s* x, int dup_strs)
{
  x = (struct zx_xenc_ReferenceList_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_ReferenceList_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xenc_DataReference_s* e;
      struct zx_xenc_DataReference_s* en;
      struct zx_xenc_DataReference_s* enn;
      for (enn = 0, e = x->DataReference; e; e = (struct zx_xenc_DataReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_DataReference(c, e, dup_strs);
	  if (!enn)
	      x->DataReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xenc_KeyReference_s* e;
      struct zx_xenc_KeyReference_s* en;
      struct zx_xenc_KeyReference_s* enn;
      for (enn = 0, e = x->KeyReference; e; e = (struct zx_xenc_KeyReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xenc_KeyReference(c, e, dup_strs);
	  if (!enn)
	      x->KeyReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xenc_ReferenceList) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_ReferenceList(struct zx_ctx* c, struct zx_xenc_ReferenceList_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xenc_DataReference_s* e;
      for (e = x->DataReference; e; e = (struct zx_xenc_DataReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_DataReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xenc_KeyReference_s* e;
      for (e = x->KeyReference; e; e = (struct zx_xenc_KeyReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xenc_KeyReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xenc_ReferenceList) */

int zx_WALK_WO_xenc_ReferenceList(struct zx_ctx* c, struct zx_xenc_ReferenceList_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xenc_Transforms
#define EL_STRUCT zx_xenc_Transforms_s
#define EL_NS     xenc
#define EL_TAG    Transforms

/* FUNC(zx_FREE_xenc_Transforms) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xenc_Transforms(struct zx_ctx* c, struct zx_xenc_Transforms_s* x, int free_strs)
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

/* FUNC(zx_NEW_xenc_Transforms) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xenc_Transforms_s* zx_NEW_xenc_Transforms(struct zx_ctx* c)
{
  struct zx_xenc_Transforms_s* x = ZX_ZALLOC(c, struct zx_xenc_Transforms_s);
  x->gg.g.tok = zx_xenc_Transforms_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xenc_Transforms) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xenc_Transforms(struct zx_ctx* c, struct zx_xenc_Transforms_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ds_Transform_s* e;
      for (e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Transform(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xenc_Transforms) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xenc_Transforms_s* zx_DEEP_CLONE_xenc_Transforms(struct zx_ctx* c, struct zx_xenc_Transforms_s* x, int dup_strs)
{
  x = (struct zx_xenc_Transforms_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xenc_Transforms_s), dup_strs);
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

/* FUNC(zx_WALK_SO_xenc_Transforms) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xenc_Transforms(struct zx_ctx* c, struct zx_xenc_Transforms_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xenc_Transforms) */

int zx_WALK_WO_xenc_Transforms(struct zx_ctx* c, struct zx_xenc_Transforms_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-xenc-aux.c */
