/* c/zx-is12-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-is12-data.h"



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

#define EL_NAME   is12_Confirm
#define EL_STRUCT zx_is12_Confirm_s
#define EL_NS     is12
#define EL_TAG    Confirm

/* FUNC(zx_FREE_is12_Confirm) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Confirm(struct zx_ctx* c, struct zx_is12_Confirm_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->name, free_strs);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      for (e = x->Help; e; e = en) {
	  en = (struct zx_is12_Help_s*)e->gg.g.n;
	  zx_FREE_is12_Help(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Hint, free_strs);
  zx_free_simple_elems(c, x->Label, free_strs);
  zx_free_simple_elems(c, x->Value, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Confirm) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Confirm_s* zx_NEW_is12_Confirm(struct zx_ctx* c)
{
  struct zx_is12_Confirm_s* x = ZX_ZALLOC(c, struct zx_is12_Confirm_s);
  x->gg.g.tok = zx_is12_Confirm_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Confirm) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Confirm(struct zx_ctx* c, struct zx_is12_Confirm_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->name);

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Help(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Hint);
  zx_dup_strs_simple_elems(c, x->Label);
  zx_dup_strs_simple_elems(c, x->Value);

}

/* FUNC(zx_DEEP_CLONE_is12_Confirm) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Confirm_s* zx_DEEP_CLONE_is12_Confirm(struct zx_ctx* c, struct zx_is12_Confirm_s* x, int dup_strs)
{
  x = (struct zx_is12_Confirm_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Confirm_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->name = zx_clone_attr(c, x->name);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      struct zx_is12_Help_s* enn;
      for (enn = 0, e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Help(c, e, dup_strs);
	  if (!enn)
	      x->Help = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Hint = zx_deep_clone_simple_elems(c,x->Hint, dup_strs);
  x->Label = zx_deep_clone_simple_elems(c,x->Label, dup_strs);
  x->Value = zx_deep_clone_simple_elems(c,x->Value, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_is12_Confirm) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Confirm(struct zx_ctx* c, struct zx_is12_Confirm_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Help(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Hint, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Label, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Value, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_Confirm) */

int zx_WALK_WO_is12_Confirm(struct zx_ctx* c, struct zx_is12_Confirm_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_EncryptedResourceID
#define EL_STRUCT zx_is12_EncryptedResourceID_s
#define EL_NS     is12
#define EL_TAG    EncryptedResourceID

/* FUNC(zx_FREE_is12_EncryptedResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_EncryptedResourceID(struct zx_ctx* c, struct zx_is12_EncryptedResourceID_s* x, int free_strs)
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

/* FUNC(zx_NEW_is12_EncryptedResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_EncryptedResourceID_s* zx_NEW_is12_EncryptedResourceID(struct zx_ctx* c)
{
  struct zx_is12_EncryptedResourceID_s* x = ZX_ZALLOC(c, struct zx_is12_EncryptedResourceID_s);
  x->gg.g.tok = zx_is12_EncryptedResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_EncryptedResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_EncryptedResourceID(struct zx_ctx* c, struct zx_is12_EncryptedResourceID_s* x)
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

/* FUNC(zx_DEEP_CLONE_is12_EncryptedResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_EncryptedResourceID_s* zx_DEEP_CLONE_is12_EncryptedResourceID(struct zx_ctx* c, struct zx_is12_EncryptedResourceID_s* x, int dup_strs)
{
  x = (struct zx_is12_EncryptedResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_EncryptedResourceID_s), dup_strs);
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

/* FUNC(zx_WALK_SO_is12_EncryptedResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_EncryptedResourceID(struct zx_ctx* c, struct zx_is12_EncryptedResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_is12_EncryptedResourceID) */

int zx_WALK_WO_is12_EncryptedResourceID(struct zx_ctx* c, struct zx_is12_EncryptedResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Extension
#define EL_STRUCT zx_is12_Extension_s
#define EL_NS     is12
#define EL_TAG    Extension

/* FUNC(zx_FREE_is12_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Extension(struct zx_ctx* c, struct zx_is12_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Extension_s* zx_NEW_is12_Extension(struct zx_ctx* c)
{
  struct zx_is12_Extension_s* x = ZX_ZALLOC(c, struct zx_is12_Extension_s);
  x->gg.g.tok = zx_is12_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Extension(struct zx_ctx* c, struct zx_is12_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_is12_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Extension_s* zx_DEEP_CLONE_is12_Extension(struct zx_ctx* c, struct zx_is12_Extension_s* x, int dup_strs)
{
  x = (struct zx_is12_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_is12_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Extension(struct zx_ctx* c, struct zx_is12_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_is12_Extension) */

int zx_WALK_WO_is12_Extension(struct zx_ctx* c, struct zx_is12_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Help
#define EL_STRUCT zx_is12_Help_s
#define EL_NS     is12
#define EL_TAG    Help

/* FUNC(zx_FREE_is12_Help) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Help(struct zx_ctx* c, struct zx_is12_Help_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->label, free_strs);
  zx_free_attr(c, x->link, free_strs);
  zx_free_attr(c, x->moreLink, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Help) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Help_s* zx_NEW_is12_Help(struct zx_ctx* c)
{
  struct zx_is12_Help_s* x = ZX_ZALLOC(c, struct zx_is12_Help_s);
  x->gg.g.tok = zx_is12_Help_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Help) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Help(struct zx_ctx* c, struct zx_is12_Help_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->label);
  zx_dup_attr(c, x->link);
  zx_dup_attr(c, x->moreLink);


}

/* FUNC(zx_DEEP_CLONE_is12_Help) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Help_s* zx_DEEP_CLONE_is12_Help(struct zx_ctx* c, struct zx_is12_Help_s* x, int dup_strs)
{
  x = (struct zx_is12_Help_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Help_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->label = zx_clone_attr(c, x->label);
  x->link = zx_clone_attr(c, x->link);
  x->moreLink = zx_clone_attr(c, x->moreLink);


  return x;
}

/* FUNC(zx_WALK_SO_is12_Help) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Help(struct zx_ctx* c, struct zx_is12_Help_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_is12_Help) */

int zx_WALK_WO_is12_Help(struct zx_ctx* c, struct zx_is12_Help_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Inquiry
#define EL_STRUCT zx_is12_Inquiry_s
#define EL_NS     is12
#define EL_TAG    Inquiry

/* FUNC(zx_FREE_is12_Inquiry) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Inquiry(struct zx_ctx* c, struct zx_is12_Inquiry_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->title, free_strs);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      for (e = x->Help; e; e = en) {
	  en = (struct zx_is12_Help_s*)e->gg.g.n;
	  zx_FREE_is12_Help(c, e, free_strs);
      }
  }
  {
      struct zx_is12_Select_s* e;
      struct zx_is12_Select_s* en;
      for (e = x->Select; e; e = en) {
	  en = (struct zx_is12_Select_s*)e->gg.g.n;
	  zx_FREE_is12_Select(c, e, free_strs);
      }
  }
  {
      struct zx_is12_Confirm_s* e;
      struct zx_is12_Confirm_s* en;
      for (e = x->Confirm; e; e = en) {
	  en = (struct zx_is12_Confirm_s*)e->gg.g.n;
	  zx_FREE_is12_Confirm(c, e, free_strs);
      }
  }
  {
      struct zx_is12_Text_s* e;
      struct zx_is12_Text_s* en;
      for (e = x->Text; e; e = en) {
	  en = (struct zx_is12_Text_s*)e->gg.g.n;
	  zx_FREE_is12_Text(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Inquiry) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Inquiry_s* zx_NEW_is12_Inquiry(struct zx_ctx* c)
{
  struct zx_is12_Inquiry_s* x = ZX_ZALLOC(c, struct zx_is12_Inquiry_s);
  x->gg.g.tok = zx_is12_Inquiry_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Inquiry) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Inquiry(struct zx_ctx* c, struct zx_is12_Inquiry_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->title);

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Help(c, e);
  }
  {
      struct zx_is12_Select_s* e;
      for (e = x->Select; e; e = (struct zx_is12_Select_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Select(c, e);
  }
  {
      struct zx_is12_Confirm_s* e;
      for (e = x->Confirm; e; e = (struct zx_is12_Confirm_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Confirm(c, e);
  }
  {
      struct zx_is12_Text_s* e;
      for (e = x->Text; e; e = (struct zx_is12_Text_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Text(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_Inquiry) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Inquiry_s* zx_DEEP_CLONE_is12_Inquiry(struct zx_ctx* c, struct zx_is12_Inquiry_s* x, int dup_strs)
{
  x = (struct zx_is12_Inquiry_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Inquiry_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->title = zx_clone_attr(c, x->title);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      struct zx_is12_Help_s* enn;
      for (enn = 0, e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Help(c, e, dup_strs);
	  if (!enn)
	      x->Help = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_is12_Select_s* e;
      struct zx_is12_Select_s* en;
      struct zx_is12_Select_s* enn;
      for (enn = 0, e = x->Select; e; e = (struct zx_is12_Select_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Select(c, e, dup_strs);
	  if (!enn)
	      x->Select = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_is12_Confirm_s* e;
      struct zx_is12_Confirm_s* en;
      struct zx_is12_Confirm_s* enn;
      for (enn = 0, e = x->Confirm; e; e = (struct zx_is12_Confirm_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Confirm(c, e, dup_strs);
	  if (!enn)
	      x->Confirm = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_is12_Text_s* e;
      struct zx_is12_Text_s* en;
      struct zx_is12_Text_s* enn;
      for (enn = 0, e = x->Text; e; e = (struct zx_is12_Text_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Text(c, e, dup_strs);
	  if (!enn)
	      x->Text = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_is12_Inquiry) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Inquiry(struct zx_ctx* c, struct zx_is12_Inquiry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Help(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_is12_Select_s* e;
      for (e = x->Select; e; e = (struct zx_is12_Select_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Select(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_is12_Confirm_s* e;
      for (e = x->Confirm; e; e = (struct zx_is12_Confirm_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Confirm(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_is12_Text_s* e;
      for (e = x->Text; e; e = (struct zx_is12_Text_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Text(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_Inquiry) */

int zx_WALK_WO_is12_Inquiry(struct zx_ctx* c, struct zx_is12_Inquiry_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_InteractionRequest
#define EL_STRUCT zx_is12_InteractionRequest_s
#define EL_NS     is12
#define EL_TAG    InteractionRequest

/* FUNC(zx_FREE_is12_InteractionRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_InteractionRequest(struct zx_ctx* c, struct zx_is12_InteractionRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->language, free_strs);
  zx_free_attr(c, x->maxInteractTime, free_strs);
  zx_free_attr(c, x->signed_is_c_keyword, free_strs);

  {
      struct zx_is12_Inquiry_s* e;
      struct zx_is12_Inquiry_s* en;
      for (e = x->Inquiry; e; e = en) {
	  en = (struct zx_is12_Inquiry_s*)e->gg.g.n;
	  zx_FREE_is12_Inquiry(c, e, free_strs);
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


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_InteractionRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_InteractionRequest_s* zx_NEW_is12_InteractionRequest(struct zx_ctx* c)
{
  struct zx_is12_InteractionRequest_s* x = ZX_ZALLOC(c, struct zx_is12_InteractionRequest_s);
  x->gg.g.tok = zx_is12_InteractionRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_InteractionRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_InteractionRequest(struct zx_ctx* c, struct zx_is12_InteractionRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->language);
  zx_dup_attr(c, x->maxInteractTime);
  zx_dup_attr(c, x->signed_is_c_keyword);

  {
      struct zx_is12_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is12_Inquiry_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Inquiry(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_KeyInfo(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_InteractionRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_InteractionRequest_s* zx_DEEP_CLONE_is12_InteractionRequest(struct zx_ctx* c, struct zx_is12_InteractionRequest_s* x, int dup_strs)
{
  x = (struct zx_is12_InteractionRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_InteractionRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->language = zx_clone_attr(c, x->language);
  x->maxInteractTime = zx_clone_attr(c, x->maxInteractTime);
  x->signed_is_c_keyword = zx_clone_attr(c, x->signed_is_c_keyword);

  {
      struct zx_is12_Inquiry_s* e;
      struct zx_is12_Inquiry_s* en;
      struct zx_is12_Inquiry_s* enn;
      for (enn = 0, e = x->Inquiry; e; e = (struct zx_is12_Inquiry_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Inquiry(c, e, dup_strs);
	  if (!enn)
	      x->Inquiry = en;
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

  return x;
}

/* FUNC(zx_WALK_SO_is12_InteractionRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_InteractionRequest(struct zx_ctx* c, struct zx_is12_InteractionRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is12_Inquiry_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Inquiry(c, e, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_InteractionRequest) */

int zx_WALK_WO_is12_InteractionRequest(struct zx_ctx* c, struct zx_is12_InteractionRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_InteractionResponse
#define EL_STRUCT zx_is12_InteractionResponse_s
#define EL_NS     is12
#define EL_TAG    InteractionResponse

/* FUNC(zx_FREE_is12_InteractionResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_InteractionResponse(struct zx_ctx* c, struct zx_is12_InteractionResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_is12_Status_s* e;
      struct zx_is12_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_is12_Status_s*)e->gg.g.n;
	  zx_FREE_is12_Status(c, e, free_strs);
      }
  }
  {
      struct zx_is12_InteractionStatement_s* e;
      struct zx_is12_InteractionStatement_s* en;
      for (e = x->InteractionStatement; e; e = en) {
	  en = (struct zx_is12_InteractionStatement_s*)e->gg.g.n;
	  zx_FREE_is12_InteractionStatement(c, e, free_strs);
      }
  }
  {
      struct zx_is12_Parameter_s* e;
      struct zx_is12_Parameter_s* en;
      for (e = x->Parameter; e; e = en) {
	  en = (struct zx_is12_Parameter_s*)e->gg.g.n;
	  zx_FREE_is12_Parameter(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_InteractionResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_InteractionResponse_s* zx_NEW_is12_InteractionResponse(struct zx_ctx* c)
{
  struct zx_is12_InteractionResponse_s* x = ZX_ZALLOC(c, struct zx_is12_InteractionResponse_s);
  x->gg.g.tok = zx_is12_InteractionResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_InteractionResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_InteractionResponse(struct zx_ctx* c, struct zx_is12_InteractionResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_is12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_is12_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Status(c, e);
  }
  {
      struct zx_is12_InteractionStatement_s* e;
      for (e = x->InteractionStatement; e; e = (struct zx_is12_InteractionStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_InteractionStatement(c, e);
  }
  {
      struct zx_is12_Parameter_s* e;
      for (e = x->Parameter; e; e = (struct zx_is12_Parameter_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Parameter(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_InteractionResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_InteractionResponse_s* zx_DEEP_CLONE_is12_InteractionResponse(struct zx_ctx* c, struct zx_is12_InteractionResponse_s* x, int dup_strs)
{
  x = (struct zx_is12_InteractionResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_InteractionResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_is12_Status_s* e;
      struct zx_is12_Status_s* en;
      struct zx_is12_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_is12_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_is12_InteractionStatement_s* e;
      struct zx_is12_InteractionStatement_s* en;
      struct zx_is12_InteractionStatement_s* enn;
      for (enn = 0, e = x->InteractionStatement; e; e = (struct zx_is12_InteractionStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_InteractionStatement(c, e, dup_strs);
	  if (!enn)
	      x->InteractionStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_is12_Parameter_s* e;
      struct zx_is12_Parameter_s* en;
      struct zx_is12_Parameter_s* enn;
      for (enn = 0, e = x->Parameter; e; e = (struct zx_is12_Parameter_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Parameter(c, e, dup_strs);
	  if (!enn)
	      x->Parameter = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_is12_InteractionResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_InteractionResponse(struct zx_ctx* c, struct zx_is12_InteractionResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_is12_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_is12_InteractionStatement_s* e;
      for (e = x->InteractionStatement; e; e = (struct zx_is12_InteractionStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_InteractionStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_is12_Parameter_s* e;
      for (e = x->Parameter; e; e = (struct zx_is12_Parameter_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Parameter(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_InteractionResponse) */

int zx_WALK_WO_is12_InteractionResponse(struct zx_ctx* c, struct zx_is12_InteractionResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_InteractionService
#define EL_STRUCT zx_is12_InteractionService_s
#define EL_NS     is12
#define EL_TAG    InteractionService

/* FUNC(zx_FREE_is12_InteractionService) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_InteractionService(struct zx_ctx* c, struct zx_is12_InteractionService_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->entryID, free_strs);

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
      struct zx_di12_ServiceInstance_s* e;
      struct zx_di12_ServiceInstance_s* en;
      for (e = x->ServiceInstance; e; e = en) {
	  en = (struct zx_di12_ServiceInstance_s*)e->gg.g.n;
	  zx_FREE_di12_ServiceInstance(c, e, free_strs);
      }
  }
  {
      struct zx_di12_Options_s* e;
      struct zx_di12_Options_s* en;
      for (e = x->Options; e; e = en) {
	  en = (struct zx_di12_Options_s*)e->gg.g.n;
	  zx_FREE_di12_Options(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Abstract, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_InteractionService) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_InteractionService_s* zx_NEW_is12_InteractionService(struct zx_ctx* c)
{
  struct zx_is12_InteractionService_s* x = ZX_ZALLOC(c, struct zx_is12_InteractionService_s);
  x->gg.g.tok = zx_is12_InteractionService_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_InteractionService) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_InteractionService(struct zx_ctx* c, struct zx_is12_InteractionService_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->entryID);

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
      struct zx_di12_ServiceInstance_s* e;
      for (e = x->ServiceInstance; e; e = (struct zx_di12_ServiceInstance_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ServiceInstance(c, e);
  }
  {
      struct zx_di12_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Options(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Abstract);

}

/* FUNC(zx_DEEP_CLONE_is12_InteractionService) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_InteractionService_s* zx_DEEP_CLONE_is12_InteractionService(struct zx_ctx* c, struct zx_is12_InteractionService_s* x, int dup_strs)
{
  x = (struct zx_is12_InteractionService_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_InteractionService_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->entryID = zx_clone_attr(c, x->entryID);

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
      struct zx_di12_ServiceInstance_s* e;
      struct zx_di12_ServiceInstance_s* en;
      struct zx_di12_ServiceInstance_s* enn;
      for (enn = 0, e = x->ServiceInstance; e; e = (struct zx_di12_ServiceInstance_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ServiceInstance(c, e, dup_strs);
	  if (!enn)
	      x->ServiceInstance = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_Options_s* e;
      struct zx_di12_Options_s* en;
      struct zx_di12_Options_s* enn;
      for (enn = 0, e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Options(c, e, dup_strs);
	  if (!enn)
	      x->Options = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Abstract = zx_deep_clone_simple_elems(c,x->Abstract, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_is12_InteractionService) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_InteractionService(struct zx_ctx* c, struct zx_is12_InteractionService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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
      struct zx_di12_ServiceInstance_s* e;
      for (e = x->ServiceInstance; e; e = (struct zx_di12_ServiceInstance_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ServiceInstance(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_Options_s* e;
      for (e = x->Options; e; e = (struct zx_di12_Options_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Options(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Abstract, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_InteractionService) */

int zx_WALK_WO_is12_InteractionService(struct zx_ctx* c, struct zx_is12_InteractionService_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_InteractionStatement
#define EL_STRUCT zx_is12_InteractionStatement_s
#define EL_NS     is12
#define EL_TAG    InteractionStatement

/* FUNC(zx_FREE_is12_InteractionStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_InteractionStatement(struct zx_ctx* c, struct zx_is12_InteractionStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_is12_Inquiry_s* e;
      struct zx_is12_Inquiry_s* en;
      for (e = x->Inquiry; e; e = en) {
	  en = (struct zx_is12_Inquiry_s*)e->gg.g.n;
	  zx_FREE_is12_Inquiry(c, e, free_strs);
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

/* FUNC(zx_NEW_is12_InteractionStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_InteractionStatement_s* zx_NEW_is12_InteractionStatement(struct zx_ctx* c)
{
  struct zx_is12_InteractionStatement_s* x = ZX_ZALLOC(c, struct zx_is12_InteractionStatement_s);
  x->gg.g.tok = zx_is12_InteractionStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_InteractionStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_InteractionStatement(struct zx_ctx* c, struct zx_is12_InteractionStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_is12_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is12_Inquiry_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Inquiry(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_InteractionStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_InteractionStatement_s* zx_DEEP_CLONE_is12_InteractionStatement(struct zx_ctx* c, struct zx_is12_InteractionStatement_s* x, int dup_strs)
{
  x = (struct zx_is12_InteractionStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_InteractionStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_is12_Inquiry_s* e;
      struct zx_is12_Inquiry_s* en;
      struct zx_is12_Inquiry_s* enn;
      for (enn = 0, e = x->Inquiry; e; e = (struct zx_is12_Inquiry_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Inquiry(c, e, dup_strs);
	  if (!enn)
	      x->Inquiry = en;
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

/* FUNC(zx_WALK_SO_is12_InteractionStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_InteractionStatement(struct zx_ctx* c, struct zx_is12_InteractionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is12_Inquiry_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Inquiry(c, e, ctx, callback);
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

/* FUNC(zx_WALK_WO_is12_InteractionStatement) */

int zx_WALK_WO_is12_InteractionStatement(struct zx_ctx* c, struct zx_is12_InteractionStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Item
#define EL_STRUCT zx_is12_Item_s
#define EL_NS     is12
#define EL_TAG    Item

/* FUNC(zx_FREE_is12_Item) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Item(struct zx_ctx* c, struct zx_is12_Item_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->label, free_strs);
  zx_free_attr(c, x->value, free_strs);

  zx_free_simple_elems(c, x->Hint, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Item) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Item_s* zx_NEW_is12_Item(struct zx_ctx* c)
{
  struct zx_is12_Item_s* x = ZX_ZALLOC(c, struct zx_is12_Item_s);
  x->gg.g.tok = zx_is12_Item_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Item) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Item(struct zx_ctx* c, struct zx_is12_Item_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->label);
  zx_dup_attr(c, x->value);

  zx_dup_strs_simple_elems(c, x->Hint);

}

/* FUNC(zx_DEEP_CLONE_is12_Item) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Item_s* zx_DEEP_CLONE_is12_Item(struct zx_ctx* c, struct zx_is12_Item_s* x, int dup_strs)
{
  x = (struct zx_is12_Item_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Item_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->label = zx_clone_attr(c, x->label);
  x->value = zx_clone_attr(c, x->value);

  x->Hint = zx_deep_clone_simple_elems(c,x->Hint, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_is12_Item) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Item(struct zx_ctx* c, struct zx_is12_Item_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Hint, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_Item) */

int zx_WALK_WO_is12_Item(struct zx_ctx* c, struct zx_is12_Item_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Parameter
#define EL_STRUCT zx_is12_Parameter_s
#define EL_NS     is12
#define EL_TAG    Parameter

/* FUNC(zx_FREE_is12_Parameter) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Parameter(struct zx_ctx* c, struct zx_is12_Parameter_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->name, free_strs);
  zx_free_attr(c, x->value, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Parameter) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Parameter_s* zx_NEW_is12_Parameter(struct zx_ctx* c)
{
  struct zx_is12_Parameter_s* x = ZX_ZALLOC(c, struct zx_is12_Parameter_s);
  x->gg.g.tok = zx_is12_Parameter_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Parameter) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Parameter(struct zx_ctx* c, struct zx_is12_Parameter_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->name);
  zx_dup_attr(c, x->value);


}

/* FUNC(zx_DEEP_CLONE_is12_Parameter) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Parameter_s* zx_DEEP_CLONE_is12_Parameter(struct zx_ctx* c, struct zx_is12_Parameter_s* x, int dup_strs)
{
  x = (struct zx_is12_Parameter_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Parameter_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->name = zx_clone_attr(c, x->name);
  x->value = zx_clone_attr(c, x->value);


  return x;
}

/* FUNC(zx_WALK_SO_is12_Parameter) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Parameter(struct zx_ctx* c, struct zx_is12_Parameter_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_is12_Parameter) */

int zx_WALK_WO_is12_Parameter(struct zx_ctx* c, struct zx_is12_Parameter_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_RedirectRequest
#define EL_STRUCT zx_is12_RedirectRequest_s
#define EL_NS     is12
#define EL_TAG    RedirectRequest

/* FUNC(zx_FREE_is12_RedirectRequest) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_RedirectRequest(struct zx_ctx* c, struct zx_is12_RedirectRequest_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->redirectURL, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_RedirectRequest) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_RedirectRequest_s* zx_NEW_is12_RedirectRequest(struct zx_ctx* c)
{
  struct zx_is12_RedirectRequest_s* x = ZX_ZALLOC(c, struct zx_is12_RedirectRequest_s);
  x->gg.g.tok = zx_is12_RedirectRequest_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_RedirectRequest) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_RedirectRequest(struct zx_ctx* c, struct zx_is12_RedirectRequest_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->redirectURL);


}

/* FUNC(zx_DEEP_CLONE_is12_RedirectRequest) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_RedirectRequest_s* zx_DEEP_CLONE_is12_RedirectRequest(struct zx_ctx* c, struct zx_is12_RedirectRequest_s* x, int dup_strs)
{
  x = (struct zx_is12_RedirectRequest_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_RedirectRequest_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->redirectURL = zx_clone_attr(c, x->redirectURL);


  return x;
}

/* FUNC(zx_WALK_SO_is12_RedirectRequest) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_RedirectRequest(struct zx_ctx* c, struct zx_is12_RedirectRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_is12_RedirectRequest) */

int zx_WALK_WO_is12_RedirectRequest(struct zx_ctx* c, struct zx_is12_RedirectRequest_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_ResourceID
#define EL_STRUCT zx_is12_ResourceID_s
#define EL_NS     is12
#define EL_TAG    ResourceID

/* FUNC(zx_FREE_is12_ResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_ResourceID(struct zx_ctx* c, struct zx_is12_ResourceID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_ResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_ResourceID_s* zx_NEW_is12_ResourceID(struct zx_ctx* c)
{
  struct zx_is12_ResourceID_s* x = ZX_ZALLOC(c, struct zx_is12_ResourceID_s);
  x->gg.g.tok = zx_is12_ResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_ResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_ResourceID(struct zx_ctx* c, struct zx_is12_ResourceID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);


}

/* FUNC(zx_DEEP_CLONE_is12_ResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_ResourceID_s* zx_DEEP_CLONE_is12_ResourceID(struct zx_ctx* c, struct zx_is12_ResourceID_s* x, int dup_strs)
{
  x = (struct zx_is12_ResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_ResourceID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);


  return x;
}

/* FUNC(zx_WALK_SO_is12_ResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_ResourceID(struct zx_ctx* c, struct zx_is12_ResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_is12_ResourceID) */

int zx_WALK_WO_is12_ResourceID(struct zx_ctx* c, struct zx_is12_ResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Select
#define EL_STRUCT zx_is12_Select_s
#define EL_NS     is12
#define EL_TAG    Select

/* FUNC(zx_FREE_is12_Select) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Select(struct zx_ctx* c, struct zx_is12_Select_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->multiple, free_strs);
  zx_free_attr(c, x->name, free_strs);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      for (e = x->Help; e; e = en) {
	  en = (struct zx_is12_Help_s*)e->gg.g.n;
	  zx_FREE_is12_Help(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Hint, free_strs);
  zx_free_simple_elems(c, x->Label, free_strs);
  zx_free_simple_elems(c, x->Value, free_strs);
  {
      struct zx_is12_Item_s* e;
      struct zx_is12_Item_s* en;
      for (e = x->Item; e; e = en) {
	  en = (struct zx_is12_Item_s*)e->gg.g.n;
	  zx_FREE_is12_Item(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Select) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Select_s* zx_NEW_is12_Select(struct zx_ctx* c)
{
  struct zx_is12_Select_s* x = ZX_ZALLOC(c, struct zx_is12_Select_s);
  x->gg.g.tok = zx_is12_Select_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Select) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Select(struct zx_ctx* c, struct zx_is12_Select_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->multiple);
  zx_dup_attr(c, x->name);

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Help(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Hint);
  zx_dup_strs_simple_elems(c, x->Label);
  zx_dup_strs_simple_elems(c, x->Value);
  {
      struct zx_is12_Item_s* e;
      for (e = x->Item; e; e = (struct zx_is12_Item_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Item(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_Select) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Select_s* zx_DEEP_CLONE_is12_Select(struct zx_ctx* c, struct zx_is12_Select_s* x, int dup_strs)
{
  x = (struct zx_is12_Select_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Select_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->multiple = zx_clone_attr(c, x->multiple);
  x->name = zx_clone_attr(c, x->name);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      struct zx_is12_Help_s* enn;
      for (enn = 0, e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Help(c, e, dup_strs);
	  if (!enn)
	      x->Help = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Hint = zx_deep_clone_simple_elems(c,x->Hint, dup_strs);
  x->Label = zx_deep_clone_simple_elems(c,x->Label, dup_strs);
  x->Value = zx_deep_clone_simple_elems(c,x->Value, dup_strs);
  {
      struct zx_is12_Item_s* e;
      struct zx_is12_Item_s* en;
      struct zx_is12_Item_s* enn;
      for (enn = 0, e = x->Item; e; e = (struct zx_is12_Item_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Item(c, e, dup_strs);
	  if (!enn)
	      x->Item = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_is12_Select) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Select(struct zx_ctx* c, struct zx_is12_Select_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Help(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Hint, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Label, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Value, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_is12_Item_s* e;
      for (e = x->Item; e; e = (struct zx_is12_Item_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Item(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_Select) */

int zx_WALK_WO_is12_Select(struct zx_ctx* c, struct zx_is12_Select_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Status
#define EL_STRUCT zx_is12_Status_s
#define EL_NS     is12
#define EL_TAG    Status

/* FUNC(zx_FREE_is12_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Status(struct zx_ctx* c, struct zx_is12_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->code, free_strs);
  zx_free_attr(c, x->comment, free_strs);
  zx_free_attr(c, x->ref, free_strs);

  {
      struct zx_is12_Status_s* e;
      struct zx_is12_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_is12_Status_s*)e->gg.g.n;
	  zx_FREE_is12_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Status_s* zx_NEW_is12_Status(struct zx_ctx* c)
{
  struct zx_is12_Status_s* x = ZX_ZALLOC(c, struct zx_is12_Status_s);
  x->gg.g.tok = zx_is12_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Status(struct zx_ctx* c, struct zx_is12_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->code);
  zx_dup_attr(c, x->comment);
  zx_dup_attr(c, x->ref);

  {
      struct zx_is12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_is12_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Status_s* zx_DEEP_CLONE_is12_Status(struct zx_ctx* c, struct zx_is12_Status_s* x, int dup_strs)
{
  x = (struct zx_is12_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->code = zx_clone_attr(c, x->code);
  x->comment = zx_clone_attr(c, x->comment);
  x->ref = zx_clone_attr(c, x->ref);

  {
      struct zx_is12_Status_s* e;
      struct zx_is12_Status_s* en;
      struct zx_is12_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_is12_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_is12_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Status(struct zx_ctx* c, struct zx_is12_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Status_s* e;
      for (e = x->Status; e; e = (struct zx_is12_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_Status) */

int zx_WALK_WO_is12_Status(struct zx_ctx* c, struct zx_is12_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_Text
#define EL_STRUCT zx_is12_Text_s
#define EL_NS     is12
#define EL_TAG    Text

/* FUNC(zx_FREE_is12_Text) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_Text(struct zx_ctx* c, struct zx_is12_Text_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->format, free_strs);
  zx_free_attr(c, x->maxChars, free_strs);
  zx_free_attr(c, x->minChars, free_strs);
  zx_free_attr(c, x->name, free_strs);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      for (e = x->Help; e; e = en) {
	  en = (struct zx_is12_Help_s*)e->gg.g.n;
	  zx_FREE_is12_Help(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Hint, free_strs);
  zx_free_simple_elems(c, x->Label, free_strs);
  zx_free_simple_elems(c, x->Value, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_Text) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_Text_s* zx_NEW_is12_Text(struct zx_ctx* c)
{
  struct zx_is12_Text_s* x = ZX_ZALLOC(c, struct zx_is12_Text_s);
  x->gg.g.tok = zx_is12_Text_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_Text) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_Text(struct zx_ctx* c, struct zx_is12_Text_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->format);
  zx_dup_attr(c, x->maxChars);
  zx_dup_attr(c, x->minChars);
  zx_dup_attr(c, x->name);

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_Help(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Hint);
  zx_dup_strs_simple_elems(c, x->Label);
  zx_dup_strs_simple_elems(c, x->Value);

}

/* FUNC(zx_DEEP_CLONE_is12_Text) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_Text_s* zx_DEEP_CLONE_is12_Text(struct zx_ctx* c, struct zx_is12_Text_s* x, int dup_strs)
{
  x = (struct zx_is12_Text_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_Text_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->format = zx_clone_attr(c, x->format);
  x->maxChars = zx_clone_attr(c, x->maxChars);
  x->minChars = zx_clone_attr(c, x->minChars);
  x->name = zx_clone_attr(c, x->name);

  {
      struct zx_is12_Help_s* e;
      struct zx_is12_Help_s* en;
      struct zx_is12_Help_s* enn;
      for (enn = 0, e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_Help(c, e, dup_strs);
	  if (!enn)
	      x->Help = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Hint = zx_deep_clone_simple_elems(c,x->Hint, dup_strs);
  x->Label = zx_deep_clone_simple_elems(c,x->Label, dup_strs);
  x->Value = zx_deep_clone_simple_elems(c,x->Value, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_is12_Text) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_Text(struct zx_ctx* c, struct zx_is12_Text_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is12_Help_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_Help(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Hint, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Label, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Value, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_Text) */

int zx_WALK_WO_is12_Text(struct zx_ctx* c, struct zx_is12_Text_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   is12_UserInteraction
#define EL_STRUCT zx_is12_UserInteraction_s
#define EL_NS     is12
#define EL_TAG    UserInteraction

/* FUNC(zx_FREE_is12_UserInteraction) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_is12_UserInteraction(struct zx_ctx* c, struct zx_is12_UserInteraction_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->interact, free_strs);
  zx_free_attr(c, x->language, free_strs);
  zx_free_attr(c, x->maxInteractTime, free_strs);
  zx_free_attr(c, x->redirect, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_is12_InteractionService_s* e;
      struct zx_is12_InteractionService_s* en;
      for (e = x->InteractionService; e; e = en) {
	  en = (struct zx_is12_InteractionService_s*)e->gg.g.n;
	  zx_FREE_is12_InteractionService(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_is12_UserInteraction) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_is12_UserInteraction_s* zx_NEW_is12_UserInteraction(struct zx_ctx* c)
{
  struct zx_is12_UserInteraction_s* x = ZX_ZALLOC(c, struct zx_is12_UserInteraction_s);
  x->gg.g.tok = zx_is12_UserInteraction_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_is12_UserInteraction) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_is12_UserInteraction(struct zx_ctx* c, struct zx_is12_UserInteraction_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->interact);
  zx_dup_attr(c, x->language);
  zx_dup_attr(c, x->maxInteractTime);
  zx_dup_attr(c, x->redirect);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_is12_InteractionService_s* e;
      for (e = x->InteractionService; e; e = (struct zx_is12_InteractionService_s*)e->gg.g.n)
	  zx_DUP_STRS_is12_InteractionService(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_is12_UserInteraction) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_is12_UserInteraction_s* zx_DEEP_CLONE_is12_UserInteraction(struct zx_ctx* c, struct zx_is12_UserInteraction_s* x, int dup_strs)
{
  x = (struct zx_is12_UserInteraction_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_is12_UserInteraction_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->interact = zx_clone_attr(c, x->interact);
  x->language = zx_clone_attr(c, x->language);
  x->maxInteractTime = zx_clone_attr(c, x->maxInteractTime);
  x->redirect = zx_clone_attr(c, x->redirect);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

  {
      struct zx_is12_InteractionService_s* e;
      struct zx_is12_InteractionService_s* en;
      struct zx_is12_InteractionService_s* enn;
      for (enn = 0, e = x->InteractionService; e; e = (struct zx_is12_InteractionService_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_is12_InteractionService(c, e, dup_strs);
	  if (!enn)
	      x->InteractionService = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_is12_UserInteraction) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_is12_UserInteraction(struct zx_ctx* c, struct zx_is12_UserInteraction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_is12_InteractionService_s* e;
      for (e = x->InteractionService; e; e = (struct zx_is12_InteractionService_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_is12_InteractionService(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_is12_UserInteraction) */

int zx_WALK_WO_is12_UserInteraction(struct zx_ctx* c, struct zx_is12_UserInteraction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-is12-aux.c */
