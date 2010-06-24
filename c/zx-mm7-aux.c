/* c/zx-mm7-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-mm7-data.h"



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

#define EL_NAME   mm7_AdditionalInformation
#define EL_STRUCT zx_mm7_AdditionalInformation_s
#define EL_NS     mm7
#define EL_TAG    AdditionalInformation

/* FUNC(zx_FREE_mm7_AdditionalInformation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->href, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_AdditionalInformation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_AdditionalInformation_s* zx_NEW_mm7_AdditionalInformation(struct zx_ctx* c)
{
  struct zx_mm7_AdditionalInformation_s* x = ZX_ZALLOC(c, struct zx_mm7_AdditionalInformation_s);
  x->gg.g.tok = zx_mm7_AdditionalInformation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_AdditionalInformation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->href);


}

/* FUNC(zx_DEEP_CLONE_mm7_AdditionalInformation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_AdditionalInformation_s* zx_DEEP_CLONE_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x, int dup_strs)
{
  x = (struct zx_mm7_AdditionalInformation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_AdditionalInformation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->href = zx_clone_attr(c, x->href);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_AdditionalInformation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_AdditionalInformation) */

int zx_WALK_WO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Bcc
#define EL_STRUCT zx_mm7_Bcc_s
#define EL_NS     mm7
#define EL_TAG    Bcc

/* FUNC(zx_FREE_mm7_Bcc) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Bcc) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Bcc_s* zx_NEW_mm7_Bcc(struct zx_ctx* c)
{
  struct zx_mm7_Bcc_s* x = ZX_ZALLOC(c, struct zx_mm7_Bcc_s);
  x->gg.g.tok = zx_mm7_Bcc_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Bcc) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Bcc) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Bcc_s* zx_DEEP_CLONE_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x, int dup_strs)
{
  x = (struct zx_mm7_Bcc_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Bcc_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Bcc) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Bcc) */

int zx_WALK_WO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_CancelReq
#define EL_STRUCT zx_mm7_CancelReq_s
#define EL_NS     mm7
#define EL_TAG    CancelReq

/* FUNC(zx_FREE_mm7_CancelReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      for (e = x->SenderIdentification; e; e = en) {
	  en = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n;
	  zx_FREE_mm7_SenderIdentification(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageID, free_strs);
  {
      struct zx_mm7_Recipients_s* e;
      struct zx_mm7_Recipients_s* en;
      for (e = x->Recipients; e; e = en) {
	  en = (struct zx_mm7_Recipients_s*)e->gg.g.n;
	  zx_FREE_mm7_Recipients(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ApplicID, free_strs);
  zx_free_simple_elems(c, x->ReplyApplicID, free_strs);
  zx_free_simple_elems(c, x->AuxApplicInfo, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_CancelReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_CancelReq_s* zx_NEW_mm7_CancelReq(struct zx_ctx* c)
{
  struct zx_mm7_CancelReq_s* x = ZX_ZALLOC(c, struct zx_mm7_CancelReq_s);
  x->gg.g.tok = zx_mm7_CancelReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_CancelReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageID);
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Recipients(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ApplicID);
  zx_dup_strs_simple_elems(c, x->ReplyApplicID);
  zx_dup_strs_simple_elems(c, x->AuxApplicInfo);

}

/* FUNC(zx_DEEP_CLONE_mm7_CancelReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_CancelReq_s* zx_DEEP_CLONE_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_CancelReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_CancelReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      struct zx_mm7_SenderIdentification_s* enn;
      for (enn = 0, e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SenderIdentification(c, e, dup_strs);
	  if (!enn)
	      x->SenderIdentification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);
  {
      struct zx_mm7_Recipients_s* e;
      struct zx_mm7_Recipients_s* en;
      struct zx_mm7_Recipients_s* enn;
      for (enn = 0, e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Recipients(c, e, dup_strs);
	  if (!enn)
	      x->Recipients = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ApplicID = zx_deep_clone_simple_elems(c,x->ApplicID, dup_strs);
  x->ReplyApplicID = zx_deep_clone_simple_elems(c,x->ReplyApplicID, dup_strs);
  x->AuxApplicInfo = zx_deep_clone_simple_elems(c,x->AuxApplicInfo, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_CancelReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SenderIdentification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Recipients(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuxApplicInfo, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_CancelReq) */

int zx_WALK_WO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_CancelRsp
#define EL_STRUCT zx_mm7_CancelRsp_s
#define EL_NS     mm7
#define EL_TAG    CancelRsp

/* FUNC(zx_FREE_mm7_CancelRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_CancelRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_CancelRsp_s* zx_NEW_mm7_CancelRsp(struct zx_ctx* c)
{
  struct zx_mm7_CancelRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_CancelRsp_s);
  x->gg.g.tok = zx_mm7_CancelRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_CancelRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_CancelRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_CancelRsp_s* zx_DEEP_CLONE_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_CancelRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_CancelRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_CancelRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_CancelRsp) */

int zx_WALK_WO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Cc
#define EL_STRUCT zx_mm7_Cc_s
#define EL_NS     mm7
#define EL_TAG    Cc

/* FUNC(zx_FREE_mm7_Cc) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Cc) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Cc_s* zx_NEW_mm7_Cc(struct zx_ctx* c)
{
  struct zx_mm7_Cc_s* x = ZX_ZALLOC(c, struct zx_mm7_Cc_s);
  x->gg.g.tok = zx_mm7_Cc_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Cc) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Cc) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Cc_s* zx_DEEP_CLONE_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x, int dup_strs)
{
  x = (struct zx_mm7_Cc_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Cc_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Cc) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Cc) */

int zx_WALK_WO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Content
#define EL_STRUCT zx_mm7_Content_s
#define EL_NS     mm7
#define EL_TAG    Content

/* FUNC(zx_FREE_mm7_Content) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->allowAdaptations, free_strs);
  zx_free_attr(c, x->href, free_strs);
  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Content) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Content_s* zx_NEW_mm7_Content(struct zx_ctx* c)
{
  struct zx_mm7_Content_s* x = ZX_ZALLOC(c, struct zx_mm7_Content_s);
  x->gg.g.tok = zx_mm7_Content_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Content) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->allowAdaptations);
  zx_dup_attr(c, x->href);
  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_mm7_Content) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Content_s* zx_DEEP_CLONE_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x, int dup_strs)
{
  x = (struct zx_mm7_Content_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Content_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->allowAdaptations = zx_clone_attr(c, x->allowAdaptations);
  x->href = zx_clone_attr(c, x->href);
  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_Content) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_Content) */

int zx_WALK_WO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_DateTime
#define EL_STRUCT zx_mm7_DateTime_s
#define EL_NS     mm7
#define EL_TAG    DateTime

/* FUNC(zx_FREE_mm7_DateTime) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->sequence, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_DateTime) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_DateTime_s* zx_NEW_mm7_DateTime(struct zx_ctx* c)
{
  struct zx_mm7_DateTime_s* x = ZX_ZALLOC(c, struct zx_mm7_DateTime_s);
  x->gg.g.tok = zx_mm7_DateTime_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_DateTime) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->sequence);


}

/* FUNC(zx_DEEP_CLONE_mm7_DateTime) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_DateTime_s* zx_DEEP_CLONE_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x, int dup_strs)
{
  x = (struct zx_mm7_DateTime_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_DateTime_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->sequence = zx_clone_attr(c, x->sequence);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_DateTime) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_DateTime) */

int zx_WALK_WO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_DeliverReq
#define EL_STRUCT zx_mm7_DeliverReq_s
#define EL_NS     mm7
#define EL_TAG    DeliverReq

/* FUNC(zx_FREE_mm7_DeliverReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->MMSRelayServerID, free_strs);
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->VASPID, free_strs);
  zx_free_simple_elems(c, x->VASID, free_strs);
  zx_free_simple_elems(c, x->LinkedID, free_strs);
  {
      struct zx_mm7_Sender_s* e;
      struct zx_mm7_Sender_s* en;
      for (e = x->Sender; e; e = en) {
	  en = (struct zx_mm7_Sender_s*)e->gg.g.n;
	  zx_FREE_mm7_Sender(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Recipients_s* e;
      struct zx_mm7_Recipients_s* en;
      for (e = x->Recipients; e; e = en) {
	  en = (struct zx_mm7_Recipients_s*)e->gg.g.n;
	  zx_FREE_mm7_Recipients(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      struct zx_mm7_Previouslysentby_s* en;
      for (e = x->Previouslysentby; e; e = en) {
	  en = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n;
	  zx_FREE_mm7_Previouslysentby(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      struct zx_mm7_Previouslysentdateandtime_s* en;
      for (e = x->Previouslysentdateandtime; e; e = en) {
	  en = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n;
	  zx_FREE_mm7_Previouslysentdateandtime(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SenderSPI, free_strs);
  zx_free_simple_elems(c, x->RecipientSPI, free_strs);
  zx_free_simple_elems(c, x->TimeStamp, free_strs);
  zx_free_simple_elems(c, x->ReplyChargingID, free_strs);
  zx_free_simple_elems(c, x->Priority, free_strs);
  zx_free_simple_elems(c, x->Subject, free_strs);
  zx_free_simple_elems(c, x->ApplicID, free_strs);
  zx_free_simple_elems(c, x->ReplyApplicID, free_strs);
  zx_free_simple_elems(c, x->AuxApplicInfo, free_strs);
  {
      struct zx_mm7_UACapabilities_s* e;
      struct zx_mm7_UACapabilities_s* en;
      for (e = x->UACapabilities; e; e = en) {
	  en = (struct zx_mm7_UACapabilities_s*)e->gg.g.n;
	  zx_FREE_mm7_UACapabilities(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      for (e = x->Content; e; e = en) {
	  en = (struct zx_mm7_Content_s*)e->gg.g.n;
	  zx_FREE_mm7_Content(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      for (e = x->AdditionalInformation; e; e = en) {
	  en = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n;
	  zx_FREE_mm7_AdditionalInformation(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      for (e = x->MessageExtraData; e; e = en) {
	  en = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n;
	  zx_FREE_mm7_MessageExtraData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_DeliverReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_DeliverReq_s* zx_NEW_mm7_DeliverReq(struct zx_ctx* c)
{
  struct zx_mm7_DeliverReq_s* x = ZX_ZALLOC(c, struct zx_mm7_DeliverReq_s);
  x->gg.g.tok = zx_mm7_DeliverReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_DeliverReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->MMSRelayServerID);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->VASPID);
  zx_dup_strs_simple_elems(c, x->VASID);
  zx_dup_strs_simple_elems(c, x->LinkedID);
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Sender(c, e);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Recipients(c, e);
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      for (e = x->Previouslysentby; e; e = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Previouslysentby(c, e);
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      for (e = x->Previouslysentdateandtime; e; e = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Previouslysentdateandtime(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SenderSPI);
  zx_dup_strs_simple_elems(c, x->RecipientSPI);
  zx_dup_strs_simple_elems(c, x->TimeStamp);
  zx_dup_strs_simple_elems(c, x->ReplyChargingID);
  zx_dup_strs_simple_elems(c, x->Priority);
  zx_dup_strs_simple_elems(c, x->Subject);
  zx_dup_strs_simple_elems(c, x->ApplicID);
  zx_dup_strs_simple_elems(c, x->ReplyApplicID);
  zx_dup_strs_simple_elems(c, x->AuxApplicInfo);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_UACapabilities(c, e);
  }
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_MessageExtraData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_DeliverReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_DeliverReq_s* zx_DEEP_CLONE_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_DeliverReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_DeliverReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->MMSRelayServerID = zx_deep_clone_simple_elems(c,x->MMSRelayServerID, dup_strs);
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->VASPID = zx_deep_clone_simple_elems(c,x->VASPID, dup_strs);
  x->VASID = zx_deep_clone_simple_elems(c,x->VASID, dup_strs);
  x->LinkedID = zx_deep_clone_simple_elems(c,x->LinkedID, dup_strs);
  {
      struct zx_mm7_Sender_s* e;
      struct zx_mm7_Sender_s* en;
      struct zx_mm7_Sender_s* enn;
      for (enn = 0, e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Sender(c, e, dup_strs);
	  if (!enn)
	      x->Sender = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Recipients_s* e;
      struct zx_mm7_Recipients_s* en;
      struct zx_mm7_Recipients_s* enn;
      for (enn = 0, e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Recipients(c, e, dup_strs);
	  if (!enn)
	      x->Recipients = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      struct zx_mm7_Previouslysentby_s* en;
      struct zx_mm7_Previouslysentby_s* enn;
      for (enn = 0, e = x->Previouslysentby; e; e = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Previouslysentby(c, e, dup_strs);
	  if (!enn)
	      x->Previouslysentby = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      struct zx_mm7_Previouslysentdateandtime_s* en;
      struct zx_mm7_Previouslysentdateandtime_s* enn;
      for (enn = 0, e = x->Previouslysentdateandtime; e; e = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Previouslysentdateandtime(c, e, dup_strs);
	  if (!enn)
	      x->Previouslysentdateandtime = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SenderSPI = zx_deep_clone_simple_elems(c,x->SenderSPI, dup_strs);
  x->RecipientSPI = zx_deep_clone_simple_elems(c,x->RecipientSPI, dup_strs);
  x->TimeStamp = zx_deep_clone_simple_elems(c,x->TimeStamp, dup_strs);
  x->ReplyChargingID = zx_deep_clone_simple_elems(c,x->ReplyChargingID, dup_strs);
  x->Priority = zx_deep_clone_simple_elems(c,x->Priority, dup_strs);
  x->Subject = zx_deep_clone_simple_elems(c,x->Subject, dup_strs);
  x->ApplicID = zx_deep_clone_simple_elems(c,x->ApplicID, dup_strs);
  x->ReplyApplicID = zx_deep_clone_simple_elems(c,x->ReplyApplicID, dup_strs);
  x->AuxApplicInfo = zx_deep_clone_simple_elems(c,x->AuxApplicInfo, dup_strs);
  {
      struct zx_mm7_UACapabilities_s* e;
      struct zx_mm7_UACapabilities_s* en;
      struct zx_mm7_UACapabilities_s* enn;
      for (enn = 0, e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_UACapabilities(c, e, dup_strs);
	  if (!enn)
	      x->UACapabilities = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      struct zx_mm7_Content_s* enn;
      for (enn = 0, e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Content(c, e, dup_strs);
	  if (!enn)
	      x->Content = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      struct zx_mm7_AdditionalInformation_s* enn;
      for (enn = 0, e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_AdditionalInformation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalInformation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      struct zx_mm7_MessageExtraData_s* enn;
      for (enn = 0, e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_MessageExtraData(c, e, dup_strs);
	  if (!enn)
	      x->MessageExtraData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_DeliverReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MMSRelayServerID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->VASPID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VASID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->LinkedID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Sender(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Recipients(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      for (e = x->Previouslysentby; e; e = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Previouslysentby(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      for (e = x->Previouslysentdateandtime; e; e = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Previouslysentdateandtime(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SenderSPI, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RecipientSPI, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->TimeStamp, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyChargingID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Priority, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Subject, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuxApplicInfo, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_UACapabilities(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Content(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_AdditionalInformation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_MessageExtraData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_DeliverReq) */

int zx_WALK_WO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_DeliverRsp
#define EL_STRUCT zx_mm7_DeliverRsp_s
#define EL_NS     mm7
#define EL_TAG    DeliverRsp

/* FUNC(zx_FREE_mm7_DeliverRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      for (e = x->ServiceCode; e; e = en) {
	  en = (struct zx_mm7_ServiceCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ServiceCode(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_DeliverRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_DeliverRsp_s* zx_NEW_mm7_DeliverRsp(struct zx_ctx* c)
{
  struct zx_mm7_DeliverRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_DeliverRsp_s);
  x->gg.g.tok = zx_mm7_DeliverRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_DeliverRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ServiceCode(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_DeliverRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_DeliverRsp_s* zx_DEEP_CLONE_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_DeliverRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_DeliverRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      struct zx_mm7_ServiceCode_s* enn;
      for (enn = 0, e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ServiceCode(c, e, dup_strs);
	  if (!enn)
	      x->ServiceCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_DeliverRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ServiceCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_DeliverRsp) */

int zx_WALK_WO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_DeliveryCondition
#define EL_STRUCT zx_mm7_DeliveryCondition_s
#define EL_NS     mm7
#define EL_TAG    DeliveryCondition

/* FUNC(zx_FREE_mm7_DeliveryCondition) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->DC, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_DeliveryCondition) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_DeliveryCondition_s* zx_NEW_mm7_DeliveryCondition(struct zx_ctx* c)
{
  struct zx_mm7_DeliveryCondition_s* x = ZX_ZALLOC(c, struct zx_mm7_DeliveryCondition_s);
  x->gg.g.tok = zx_mm7_DeliveryCondition_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_DeliveryCondition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->DC);

}

/* FUNC(zx_DEEP_CLONE_mm7_DeliveryCondition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_DeliveryCondition_s* zx_DEEP_CLONE_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x, int dup_strs)
{
  x = (struct zx_mm7_DeliveryCondition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_DeliveryCondition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->DC = zx_deep_clone_simple_elems(c,x->DC, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_DeliveryCondition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->DC, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_DeliveryCondition) */

int zx_WALK_WO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_DeliveryReportReq
#define EL_STRUCT zx_mm7_DeliveryReportReq_s
#define EL_NS     mm7
#define EL_TAG    DeliveryReportReq

/* FUNC(zx_FREE_mm7_DeliveryReportReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->MMSRelayServerID, free_strs);
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageID, free_strs);
  {
      struct zx_mm7_Recipient_s* e;
      struct zx_mm7_Recipient_s* en;
      for (e = x->Recipient; e; e = en) {
	  en = (struct zx_mm7_Recipient_s*)e->gg.g.n;
	  zx_FREE_mm7_Recipient(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Sender_s* e;
      struct zx_mm7_Sender_s* en;
      for (e = x->Sender; e; e = en) {
	  en = (struct zx_mm7_Sender_s*)e->gg.g.n;
	  zx_FREE_mm7_Sender(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Date, free_strs);
  zx_free_simple_elems(c, x->MMStatus, free_strs);
  zx_free_simple_elems(c, x->MMStatusExtension, free_strs);
  zx_free_simple_elems(c, x->StatusText, free_strs);
  zx_free_simple_elems(c, x->ApplicID, free_strs);
  zx_free_simple_elems(c, x->ReplyApplicID, free_strs);
  zx_free_simple_elems(c, x->AuxApplicInfo, free_strs);
  {
      struct zx_mm7_UACapabilities_s* e;
      struct zx_mm7_UACapabilities_s* en;
      for (e = x->UACapabilities; e; e = en) {
	  en = (struct zx_mm7_UACapabilities_s*)e->gg.g.n;
	  zx_FREE_mm7_UACapabilities(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_DeliveryReportReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_DeliveryReportReq_s* zx_NEW_mm7_DeliveryReportReq(struct zx_ctx* c)
{
  struct zx_mm7_DeliveryReportReq_s* x = ZX_ZALLOC(c, struct zx_mm7_DeliveryReportReq_s);
  x->gg.g.tok = zx_mm7_DeliveryReportReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_DeliveryReportReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->MMSRelayServerID);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageID);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Recipient(c, e);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Sender(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Date);
  zx_dup_strs_simple_elems(c, x->MMStatus);
  zx_dup_strs_simple_elems(c, x->MMStatusExtension);
  zx_dup_strs_simple_elems(c, x->StatusText);
  zx_dup_strs_simple_elems(c, x->ApplicID);
  zx_dup_strs_simple_elems(c, x->ReplyApplicID);
  zx_dup_strs_simple_elems(c, x->AuxApplicInfo);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_UACapabilities(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_DeliveryReportReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_DeliveryReportReq_s* zx_DEEP_CLONE_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_DeliveryReportReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_DeliveryReportReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->MMSRelayServerID = zx_deep_clone_simple_elems(c,x->MMSRelayServerID, dup_strs);
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);
  {
      struct zx_mm7_Recipient_s* e;
      struct zx_mm7_Recipient_s* en;
      struct zx_mm7_Recipient_s* enn;
      for (enn = 0, e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Recipient(c, e, dup_strs);
	  if (!enn)
	      x->Recipient = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Sender_s* e;
      struct zx_mm7_Sender_s* en;
      struct zx_mm7_Sender_s* enn;
      for (enn = 0, e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Sender(c, e, dup_strs);
	  if (!enn)
	      x->Sender = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Date = zx_deep_clone_simple_elems(c,x->Date, dup_strs);
  x->MMStatus = zx_deep_clone_simple_elems(c,x->MMStatus, dup_strs);
  x->MMStatusExtension = zx_deep_clone_simple_elems(c,x->MMStatusExtension, dup_strs);
  x->StatusText = zx_deep_clone_simple_elems(c,x->StatusText, dup_strs);
  x->ApplicID = zx_deep_clone_simple_elems(c,x->ApplicID, dup_strs);
  x->ReplyApplicID = zx_deep_clone_simple_elems(c,x->ReplyApplicID, dup_strs);
  x->AuxApplicInfo = zx_deep_clone_simple_elems(c,x->AuxApplicInfo, dup_strs);
  {
      struct zx_mm7_UACapabilities_s* e;
      struct zx_mm7_UACapabilities_s* en;
      struct zx_mm7_UACapabilities_s* enn;
      for (enn = 0, e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_UACapabilities(c, e, dup_strs);
	  if (!enn)
	      x->UACapabilities = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_DeliveryReportReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MMSRelayServerID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Recipient(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Sender(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Date, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MMStatus, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MMStatusExtension, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->StatusText, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuxApplicInfo, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_UACapabilities(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_DeliveryReportReq) */

int zx_WALK_WO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_DeliveryReportRsp
#define EL_STRUCT zx_mm7_DeliveryReportRsp_s
#define EL_NS     mm7
#define EL_TAG    DeliveryReportRsp

/* FUNC(zx_FREE_mm7_DeliveryReportRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_DeliveryReportRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_DeliveryReportRsp_s* zx_NEW_mm7_DeliveryReportRsp(struct zx_ctx* c)
{
  struct zx_mm7_DeliveryReportRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_DeliveryReportRsp_s);
  x->gg.g.tok = zx_mm7_DeliveryReportRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_DeliveryReportRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_DeliveryReportRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_DeliveryReportRsp_s* zx_DEEP_CLONE_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_DeliveryReportRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_DeliveryReportRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_DeliveryReportRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_DeliveryReportRsp) */

int zx_WALK_WO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Details
#define EL_STRUCT zx_mm7_Details_s
#define EL_NS     mm7
#define EL_TAG    Details

/* FUNC(zx_FREE_mm7_Details) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Details) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Details_s* zx_NEW_mm7_Details(struct zx_ctx* c)
{
  struct zx_mm7_Details_s* x = ZX_ZALLOC(c, struct zx_mm7_Details_s);
  x->gg.g.tok = zx_mm7_Details_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Details) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_mm7_Details) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Details_s* zx_DEEP_CLONE_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x, int dup_strs)
{
  x = (struct zx_mm7_Details_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Details_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_mm7_Details) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_Details) */

int zx_WALK_WO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Extension
#define EL_STRUCT zx_mm7_Extension_s
#define EL_NS     mm7
#define EL_TAG    Extension

/* FUNC(zx_FREE_mm7_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      struct zx_mm7_IdentityAddressingToken_s* en;
      for (e = x->IdentityAddressingToken; e; e = en) {
	  en = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n;
	  zx_FREE_mm7_IdentityAddressingToken(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      for (e = x->MessageExtraData; e; e = en) {
	  en = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n;
	  zx_FREE_mm7_MessageExtraData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Extension_s* zx_NEW_mm7_Extension(struct zx_ctx* c)
{
  struct zx_mm7_Extension_s* x = ZX_ZALLOC(c, struct zx_mm7_Extension_s);
  x->gg.g.tok = zx_mm7_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      for (e = x->IdentityAddressingToken; e; e = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_IdentityAddressingToken(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_MessageExtraData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Extension_s* zx_DEEP_CLONE_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x, int dup_strs)
{
  x = (struct zx_mm7_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      struct zx_mm7_IdentityAddressingToken_s* en;
      struct zx_mm7_IdentityAddressingToken_s* enn;
      for (enn = 0, e = x->IdentityAddressingToken; e; e = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_IdentityAddressingToken(c, e, dup_strs);
	  if (!enn)
	      x->IdentityAddressingToken = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      struct zx_mm7_MessageExtraData_s* enn;
      for (enn = 0, e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_MessageExtraData(c, e, dup_strs);
	  if (!enn)
	      x->MessageExtraData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      for (e = x->IdentityAddressingToken; e; e = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_IdentityAddressingToken(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_MessageExtraData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Extension) */

int zx_WALK_WO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_IdentityAddressingToken
#define EL_STRUCT zx_mm7_IdentityAddressingToken_s
#define EL_NS     mm7
#define EL_TAG    IdentityAddressingToken

/* FUNC(zx_FREE_mm7_IdentityAddressingToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->CredentialRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_IdentityAddressingToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_IdentityAddressingToken_s* zx_NEW_mm7_IdentityAddressingToken(struct zx_ctx* c)
{
  struct zx_mm7_IdentityAddressingToken_s* x = ZX_ZALLOC(c, struct zx_mm7_IdentityAddressingToken_s);
  x->gg.g.tok = zx_mm7_IdentityAddressingToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_IdentityAddressingToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->CredentialRef);

}

/* FUNC(zx_DEEP_CLONE_mm7_IdentityAddressingToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_IdentityAddressingToken_s* zx_DEEP_CLONE_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x, int dup_strs)
{
  x = (struct zx_mm7_IdentityAddressingToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_IdentityAddressingToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->CredentialRef = zx_deep_clone_simple_elems(c,x->CredentialRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_IdentityAddressingToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->CredentialRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_IdentityAddressingToken) */

int zx_WALK_WO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_MessageExtraData
#define EL_STRUCT zx_mm7_MessageExtraData_s
#define EL_NS     mm7
#define EL_TAG    MessageExtraData

/* FUNC(zx_FREE_mm7_MessageExtraData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_element_s* e;
      struct zx_mm7_element_s* en;
      for (e = x->element; e; e = en) {
	  en = (struct zx_mm7_element_s*)e->gg.g.n;
	  zx_FREE_mm7_element(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_MessageExtraData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_MessageExtraData_s* zx_NEW_mm7_MessageExtraData(struct zx_ctx* c)
{
  struct zx_mm7_MessageExtraData_s* x = ZX_ZALLOC(c, struct zx_mm7_MessageExtraData_s);
  x->gg.g.tok = zx_mm7_MessageExtraData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_MessageExtraData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_element_s* e;
      for (e = x->element; e; e = (struct zx_mm7_element_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_element(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_MessageExtraData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_MessageExtraData_s* zx_DEEP_CLONE_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x, int dup_strs)
{
  x = (struct zx_mm7_MessageExtraData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_MessageExtraData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_element_s* e;
      struct zx_mm7_element_s* en;
      struct zx_mm7_element_s* enn;
      for (enn = 0, e = x->element; e; e = (struct zx_mm7_element_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_element(c, e, dup_strs);
	  if (!enn)
	      x->element = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_MessageExtraData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_element_s* e;
      for (e = x->element; e; e = (struct zx_mm7_element_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_element(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_MessageExtraData) */

int zx_WALK_WO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Number
#define EL_STRUCT zx_mm7_Number_s
#define EL_NS     mm7
#define EL_TAG    Number

/* FUNC(zx_FREE_mm7_Number) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->addressCoding, free_strs);
  zx_free_attr(c, x->displayOnly, free_strs);
  zx_free_attr(c, x->id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Number) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Number_s* zx_NEW_mm7_Number(struct zx_ctx* c)
{
  struct zx_mm7_Number_s* x = ZX_ZALLOC(c, struct zx_mm7_Number_s);
  x->gg.g.tok = zx_mm7_Number_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Number) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->addressCoding);
  zx_dup_attr(c, x->displayOnly);
  zx_dup_attr(c, x->id);


}

/* FUNC(zx_DEEP_CLONE_mm7_Number) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Number_s* zx_DEEP_CLONE_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x, int dup_strs)
{
  x = (struct zx_mm7_Number_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Number_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->addressCoding = zx_clone_attr(c, x->addressCoding);
  x->displayOnly = zx_clone_attr(c, x->displayOnly);
  x->id = zx_clone_attr(c, x->id);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_Number) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_Number) */

int zx_WALK_WO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_PreferredChannels
#define EL_STRUCT zx_mm7_PreferredChannels_s
#define EL_NS     mm7
#define EL_TAG    PreferredChannels

/* FUNC(zx_FREE_mm7_PreferredChannels) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->DeliverUsing, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_PreferredChannels) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_PreferredChannels_s* zx_NEW_mm7_PreferredChannels(struct zx_ctx* c)
{
  struct zx_mm7_PreferredChannels_s* x = ZX_ZALLOC(c, struct zx_mm7_PreferredChannels_s);
  x->gg.g.tok = zx_mm7_PreferredChannels_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_PreferredChannels) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->DeliverUsing);

}

/* FUNC(zx_DEEP_CLONE_mm7_PreferredChannels) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_PreferredChannels_s* zx_DEEP_CLONE_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x, int dup_strs)
{
  x = (struct zx_mm7_PreferredChannels_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_PreferredChannels_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->DeliverUsing = zx_deep_clone_simple_elems(c,x->DeliverUsing, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_PreferredChannels) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->DeliverUsing, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_PreferredChannels) */

int zx_WALK_WO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Previouslysentby
#define EL_STRUCT zx_mm7_Previouslysentby_s
#define EL_NS     mm7
#define EL_TAG    Previouslysentby

/* FUNC(zx_FREE_mm7_Previouslysentby) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_UserAgent_s* e;
      struct zx_mm7_UserAgent_s* en;
      for (e = x->UserAgent; e; e = en) {
	  en = (struct zx_mm7_UserAgent_s*)e->gg.g.n;
	  zx_FREE_mm7_UserAgent(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Previouslysentby) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Previouslysentby_s* zx_NEW_mm7_Previouslysentby(struct zx_ctx* c)
{
  struct zx_mm7_Previouslysentby_s* x = ZX_ZALLOC(c, struct zx_mm7_Previouslysentby_s);
  x->gg.g.tok = zx_mm7_Previouslysentby_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Previouslysentby) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_UserAgent_s* e;
      for (e = x->UserAgent; e; e = (struct zx_mm7_UserAgent_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_UserAgent(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Previouslysentby) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Previouslysentby_s* zx_DEEP_CLONE_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x, int dup_strs)
{
  x = (struct zx_mm7_Previouslysentby_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Previouslysentby_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_UserAgent_s* e;
      struct zx_mm7_UserAgent_s* en;
      struct zx_mm7_UserAgent_s* enn;
      for (enn = 0, e = x->UserAgent; e; e = (struct zx_mm7_UserAgent_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_UserAgent(c, e, dup_strs);
	  if (!enn)
	      x->UserAgent = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Previouslysentby) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_UserAgent_s* e;
      for (e = x->UserAgent; e; e = (struct zx_mm7_UserAgent_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_UserAgent(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Previouslysentby) */

int zx_WALK_WO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Previouslysentdateandtime
#define EL_STRUCT zx_mm7_Previouslysentdateandtime_s
#define EL_NS     mm7
#define EL_TAG    Previouslysentdateandtime

/* FUNC(zx_FREE_mm7_Previouslysentdateandtime) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_DateTime_s* e;
      struct zx_mm7_DateTime_s* en;
      for (e = x->DateTime; e; e = en) {
	  en = (struct zx_mm7_DateTime_s*)e->gg.g.n;
	  zx_FREE_mm7_DateTime(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Previouslysentdateandtime) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Previouslysentdateandtime_s* zx_NEW_mm7_Previouslysentdateandtime(struct zx_ctx* c)
{
  struct zx_mm7_Previouslysentdateandtime_s* x = ZX_ZALLOC(c, struct zx_mm7_Previouslysentdateandtime_s);
  x->gg.g.tok = zx_mm7_Previouslysentdateandtime_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Previouslysentdateandtime) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_DateTime_s* e;
      for (e = x->DateTime; e; e = (struct zx_mm7_DateTime_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_DateTime(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Previouslysentdateandtime) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Previouslysentdateandtime_s* zx_DEEP_CLONE_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x, int dup_strs)
{
  x = (struct zx_mm7_Previouslysentdateandtime_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Previouslysentdateandtime_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_DateTime_s* e;
      struct zx_mm7_DateTime_s* en;
      struct zx_mm7_DateTime_s* enn;
      for (enn = 0, e = x->DateTime; e; e = (struct zx_mm7_DateTime_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_DateTime(c, e, dup_strs);
	  if (!enn)
	      x->DateTime = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Previouslysentdateandtime) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_DateTime_s* e;
      for (e = x->DateTime; e; e = (struct zx_mm7_DateTime_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_DateTime(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Previouslysentdateandtime) */

int zx_WALK_WO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_QueryStatusReq
#define EL_STRUCT zx_mm7_QueryStatusReq_s
#define EL_NS     mm7
#define EL_TAG    QueryStatusReq

/* FUNC(zx_FREE_mm7_QueryStatusReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_TransactionID_s* e;
      struct zx_mm7_TransactionID_s* en;
      for (e = x->TransactionID; e; e = en) {
	  en = (struct zx_mm7_TransactionID_s*)e->gg.g.n;
	  zx_FREE_mm7_TransactionID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageType, free_strs);
  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->VASPID, free_strs);
  zx_free_simple_elems(c, x->VASID, free_strs);
  zx_free_simple_elems(c, x->MessageID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_QueryStatusReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_QueryStatusReq_s* zx_NEW_mm7_QueryStatusReq(struct zx_ctx* c)
{
  struct zx_mm7_QueryStatusReq_s* x = ZX_ZALLOC(c, struct zx_mm7_QueryStatusReq_s);
  x->gg.g.tok = zx_mm7_QueryStatusReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_QueryStatusReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_TransactionID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageType);
  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->VASPID);
  zx_dup_strs_simple_elems(c, x->VASID);
  zx_dup_strs_simple_elems(c, x->MessageID);

}

/* FUNC(zx_DEEP_CLONE_mm7_QueryStatusReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_QueryStatusReq_s* zx_DEEP_CLONE_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_QueryStatusReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_QueryStatusReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_TransactionID_s* e;
      struct zx_mm7_TransactionID_s* en;
      struct zx_mm7_TransactionID_s* enn;
      for (enn = 0, e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_TransactionID(c, e, dup_strs);
	  if (!enn)
	      x->TransactionID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageType = zx_deep_clone_simple_elems(c,x->MessageType, dup_strs);
  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->VASPID = zx_deep_clone_simple_elems(c,x->VASPID, dup_strs);
  x->VASID = zx_deep_clone_simple_elems(c,x->VASID, dup_strs);
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_QueryStatusReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_TransactionID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VASPID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VASID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_QueryStatusReq) */

int zx_WALK_WO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_QueryStatusRsp
#define EL_STRUCT zx_mm7_QueryStatusRsp_s
#define EL_NS     mm7
#define EL_TAG    QueryStatusRsp

/* FUNC(zx_FREE_mm7_QueryStatusRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_TransactionID_s* e;
      struct zx_mm7_TransactionID_s* en;
      for (e = x->TransactionID; e; e = en) {
	  en = (struct zx_mm7_TransactionID_s*)e->gg.g.n;
	  zx_FREE_mm7_TransactionID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageType, free_strs);
  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->StatusCode, free_strs);
  zx_free_simple_elems(c, x->StatusText, free_strs);
  {
      struct zx_mm7_Details_s* e;
      struct zx_mm7_Details_s* en;
      for (e = x->Details; e; e = en) {
	  en = (struct zx_mm7_Details_s*)e->gg.g.n;
	  zx_FREE_mm7_Details(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_QueryStatusRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_QueryStatusRsp_s* zx_NEW_mm7_QueryStatusRsp(struct zx_ctx* c)
{
  struct zx_mm7_QueryStatusRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_QueryStatusRsp_s);
  x->gg.g.tok = zx_mm7_QueryStatusRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_QueryStatusRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_TransactionID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageType);
  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->StatusCode);
  zx_dup_strs_simple_elems(c, x->StatusText);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Details(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_QueryStatusRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_QueryStatusRsp_s* zx_DEEP_CLONE_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_QueryStatusRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_QueryStatusRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_TransactionID_s* e;
      struct zx_mm7_TransactionID_s* en;
      struct zx_mm7_TransactionID_s* enn;
      for (enn = 0, e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_TransactionID(c, e, dup_strs);
	  if (!enn)
	      x->TransactionID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageType = zx_deep_clone_simple_elems(c,x->MessageType, dup_strs);
  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->StatusCode = zx_deep_clone_simple_elems(c,x->StatusCode, dup_strs);
  x->StatusText = zx_deep_clone_simple_elems(c,x->StatusText, dup_strs);
  {
      struct zx_mm7_Details_s* e;
      struct zx_mm7_Details_s* en;
      struct zx_mm7_Details_s* enn;
      for (enn = 0, e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Details(c, e, dup_strs);
	  if (!enn)
	      x->Details = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_QueryStatusRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_TransactionID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->StatusCode, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->StatusText, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Details(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_QueryStatusRsp) */

int zx_WALK_WO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_RFC2822Address
#define EL_STRUCT zx_mm7_RFC2822Address_s
#define EL_NS     mm7
#define EL_TAG    RFC2822Address

/* FUNC(zx_FREE_mm7_RFC2822Address) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->addressCoding, free_strs);
  zx_free_attr(c, x->displayOnly, free_strs);
  zx_free_attr(c, x->id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_RFC2822Address) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_RFC2822Address_s* zx_NEW_mm7_RFC2822Address(struct zx_ctx* c)
{
  struct zx_mm7_RFC2822Address_s* x = ZX_ZALLOC(c, struct zx_mm7_RFC2822Address_s);
  x->gg.g.tok = zx_mm7_RFC2822Address_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_RFC2822Address) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->addressCoding);
  zx_dup_attr(c, x->displayOnly);
  zx_dup_attr(c, x->id);


}

/* FUNC(zx_DEEP_CLONE_mm7_RFC2822Address) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_RFC2822Address_s* zx_DEEP_CLONE_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x, int dup_strs)
{
  x = (struct zx_mm7_RFC2822Address_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_RFC2822Address_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->addressCoding = zx_clone_attr(c, x->addressCoding);
  x->displayOnly = zx_clone_attr(c, x->displayOnly);
  x->id = zx_clone_attr(c, x->id);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_RFC2822Address) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_RFC2822Address) */

int zx_WALK_WO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_RSErrorRsp
#define EL_STRUCT zx_mm7_RSErrorRsp_s
#define EL_NS     mm7
#define EL_TAG    RSErrorRsp

/* FUNC(zx_FREE_mm7_RSErrorRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_RSErrorRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_RSErrorRsp_s* zx_NEW_mm7_RSErrorRsp(struct zx_ctx* c)
{
  struct zx_mm7_RSErrorRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_RSErrorRsp_s);
  x->gg.g.tok = zx_mm7_RSErrorRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_RSErrorRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_RSErrorRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_RSErrorRsp_s* zx_DEEP_CLONE_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_RSErrorRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_RSErrorRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_RSErrorRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_RSErrorRsp) */

int zx_WALK_WO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ReadReplyReq
#define EL_STRUCT zx_mm7_ReadReplyReq_s
#define EL_NS     mm7
#define EL_TAG    ReadReplyReq

/* FUNC(zx_FREE_mm7_ReadReplyReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->MMSRelayServerID, free_strs);
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageID, free_strs);
  {
      struct zx_mm7_Recipient_s* e;
      struct zx_mm7_Recipient_s* en;
      for (e = x->Recipient; e; e = en) {
	  en = (struct zx_mm7_Recipient_s*)e->gg.g.n;
	  zx_FREE_mm7_Recipient(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Sender_s* e;
      struct zx_mm7_Sender_s* en;
      for (e = x->Sender; e; e = en) {
	  en = (struct zx_mm7_Sender_s*)e->gg.g.n;
	  zx_FREE_mm7_Sender(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->TimeStamp, free_strs);
  zx_free_simple_elems(c, x->MMStatus, free_strs);
  zx_free_simple_elems(c, x->StatusText, free_strs);
  zx_free_simple_elems(c, x->ApplicID, free_strs);
  zx_free_simple_elems(c, x->ReplyApplicID, free_strs);
  zx_free_simple_elems(c, x->AuxApplicInfo, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ReadReplyReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ReadReplyReq_s* zx_NEW_mm7_ReadReplyReq(struct zx_ctx* c)
{
  struct zx_mm7_ReadReplyReq_s* x = ZX_ZALLOC(c, struct zx_mm7_ReadReplyReq_s);
  x->gg.g.tok = zx_mm7_ReadReplyReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ReadReplyReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->MMSRelayServerID);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageID);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Recipient(c, e);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Sender(c, e);
  }
  zx_dup_strs_simple_elems(c, x->TimeStamp);
  zx_dup_strs_simple_elems(c, x->MMStatus);
  zx_dup_strs_simple_elems(c, x->StatusText);
  zx_dup_strs_simple_elems(c, x->ApplicID);
  zx_dup_strs_simple_elems(c, x->ReplyApplicID);
  zx_dup_strs_simple_elems(c, x->AuxApplicInfo);

}

/* FUNC(zx_DEEP_CLONE_mm7_ReadReplyReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ReadReplyReq_s* zx_DEEP_CLONE_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_ReadReplyReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ReadReplyReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->MMSRelayServerID = zx_deep_clone_simple_elems(c,x->MMSRelayServerID, dup_strs);
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);
  {
      struct zx_mm7_Recipient_s* e;
      struct zx_mm7_Recipient_s* en;
      struct zx_mm7_Recipient_s* enn;
      for (enn = 0, e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Recipient(c, e, dup_strs);
	  if (!enn)
	      x->Recipient = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Sender_s* e;
      struct zx_mm7_Sender_s* en;
      struct zx_mm7_Sender_s* enn;
      for (enn = 0, e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Sender(c, e, dup_strs);
	  if (!enn)
	      x->Sender = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->TimeStamp = zx_deep_clone_simple_elems(c,x->TimeStamp, dup_strs);
  x->MMStatus = zx_deep_clone_simple_elems(c,x->MMStatus, dup_strs);
  x->StatusText = zx_deep_clone_simple_elems(c,x->StatusText, dup_strs);
  x->ApplicID = zx_deep_clone_simple_elems(c,x->ApplicID, dup_strs);
  x->ReplyApplicID = zx_deep_clone_simple_elems(c,x->ReplyApplicID, dup_strs);
  x->AuxApplicInfo = zx_deep_clone_simple_elems(c,x->AuxApplicInfo, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_ReadReplyReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MMSRelayServerID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Recipient(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Sender(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->TimeStamp, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MMStatus, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->StatusText, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuxApplicInfo, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_ReadReplyReq) */

int zx_WALK_WO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ReadReplyRsp
#define EL_STRUCT zx_mm7_ReadReplyRsp_s
#define EL_NS     mm7
#define EL_TAG    ReadReplyRsp

/* FUNC(zx_FREE_mm7_ReadReplyRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ReadReplyRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ReadReplyRsp_s* zx_NEW_mm7_ReadReplyRsp(struct zx_ctx* c)
{
  struct zx_mm7_ReadReplyRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_ReadReplyRsp_s);
  x->gg.g.tok = zx_mm7_ReadReplyRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ReadReplyRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_ReadReplyRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ReadReplyRsp_s* zx_DEEP_CLONE_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_ReadReplyRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ReadReplyRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_ReadReplyRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_ReadReplyRsp) */

int zx_WALK_WO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Recipient
#define EL_STRUCT zx_mm7_Recipient_s
#define EL_NS     mm7
#define EL_TAG    Recipient

/* FUNC(zx_FREE_mm7_Recipient) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Recipient) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Recipient_s* zx_NEW_mm7_Recipient(struct zx_ctx* c)
{
  struct zx_mm7_Recipient_s* x = ZX_ZALLOC(c, struct zx_mm7_Recipient_s);
  x->gg.g.tok = zx_mm7_Recipient_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Recipient) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Recipient) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Recipient_s* zx_DEEP_CLONE_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x, int dup_strs)
{
  x = (struct zx_mm7_Recipient_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Recipient_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Recipient) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Recipient) */

int zx_WALK_WO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Recipients
#define EL_STRUCT zx_mm7_Recipients_s
#define EL_NS     mm7
#define EL_TAG    Recipients

/* FUNC(zx_FREE_mm7_Recipients) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_To_s* e;
      struct zx_mm7_To_s* en;
      for (e = x->To; e; e = en) {
	  en = (struct zx_mm7_To_s*)e->gg.g.n;
	  zx_FREE_mm7_To(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Cc_s* e;
      struct zx_mm7_Cc_s* en;
      for (e = x->Cc; e; e = en) {
	  en = (struct zx_mm7_Cc_s*)e->gg.g.n;
	  zx_FREE_mm7_Cc(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Bcc_s* e;
      struct zx_mm7_Bcc_s* en;
      for (e = x->Bcc; e; e = en) {
	  en = (struct zx_mm7_Bcc_s*)e->gg.g.n;
	  zx_FREE_mm7_Bcc(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Recipients) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Recipients_s* zx_NEW_mm7_Recipients(struct zx_ctx* c)
{
  struct zx_mm7_Recipients_s* x = ZX_ZALLOC(c, struct zx_mm7_Recipients_s);
  x->gg.g.tok = zx_mm7_Recipients_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Recipients) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_To_s* e;
      for (e = x->To; e; e = (struct zx_mm7_To_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_To(c, e);
  }
  {
      struct zx_mm7_Cc_s* e;
      for (e = x->Cc; e; e = (struct zx_mm7_Cc_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Cc(c, e);
  }
  {
      struct zx_mm7_Bcc_s* e;
      for (e = x->Bcc; e; e = (struct zx_mm7_Bcc_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Bcc(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Recipients) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Recipients_s* zx_DEEP_CLONE_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x, int dup_strs)
{
  x = (struct zx_mm7_Recipients_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Recipients_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_To_s* e;
      struct zx_mm7_To_s* en;
      struct zx_mm7_To_s* enn;
      for (enn = 0, e = x->To; e; e = (struct zx_mm7_To_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_To(c, e, dup_strs);
	  if (!enn)
	      x->To = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Cc_s* e;
      struct zx_mm7_Cc_s* en;
      struct zx_mm7_Cc_s* enn;
      for (enn = 0, e = x->Cc; e; e = (struct zx_mm7_Cc_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Cc(c, e, dup_strs);
	  if (!enn)
	      x->Cc = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Bcc_s* e;
      struct zx_mm7_Bcc_s* en;
      struct zx_mm7_Bcc_s* enn;
      for (enn = 0, e = x->Bcc; e; e = (struct zx_mm7_Bcc_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Bcc(c, e, dup_strs);
	  if (!enn)
	      x->Bcc = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Recipients) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_To_s* e;
      for (e = x->To; e; e = (struct zx_mm7_To_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_To(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Cc_s* e;
      for (e = x->Cc; e; e = (struct zx_mm7_Cc_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Cc(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Bcc_s* e;
      for (e = x->Bcc; e; e = (struct zx_mm7_Bcc_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Bcc(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Recipients) */

int zx_WALK_WO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ReplaceReq
#define EL_STRUCT zx_mm7_ReplaceReq_s
#define EL_NS     mm7
#define EL_TAG    ReplaceReq

/* FUNC(zx_FREE_mm7_ReplaceReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      for (e = x->SenderIdentification; e; e = en) {
	  en = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n;
	  zx_FREE_mm7_SenderIdentification(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageID, free_strs);
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      for (e = x->ServiceCode; e; e = en) {
	  en = (struct zx_mm7_ServiceCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ServiceCode(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->TimeStamp, free_strs);
  zx_free_simple_elems(c, x->ReadReply, free_strs);
  zx_free_simple_elems(c, x->EarliestDeliveryTime, free_strs);
  zx_free_simple_elems(c, x->DistributionIndicator, free_strs);
  zx_free_simple_elems(c, x->ContentClass, free_strs);
  zx_free_simple_elems(c, x->DRMContent, free_strs);
  zx_free_simple_elems(c, x->ApplicID, free_strs);
  zx_free_simple_elems(c, x->ReplyApplicID, free_strs);
  zx_free_simple_elems(c, x->AuxApplicInfo, free_strs);
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      for (e = x->Content; e; e = en) {
	  en = (struct zx_mm7_Content_s*)e->gg.g.n;
	  zx_FREE_mm7_Content(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      for (e = x->AdditionalInformation; e; e = en) {
	  en = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n;
	  zx_FREE_mm7_AdditionalInformation(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      for (e = x->MessageExtraData; e; e = en) {
	  en = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n;
	  zx_FREE_mm7_MessageExtraData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ReplaceReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ReplaceReq_s* zx_NEW_mm7_ReplaceReq(struct zx_ctx* c)
{
  struct zx_mm7_ReplaceReq_s* x = ZX_ZALLOC(c, struct zx_mm7_ReplaceReq_s);
  x->gg.g.tok = zx_mm7_ReplaceReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ReplaceReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageID);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ServiceCode(c, e);
  }
  zx_dup_strs_simple_elems(c, x->TimeStamp);
  zx_dup_strs_simple_elems(c, x->ReadReply);
  zx_dup_strs_simple_elems(c, x->EarliestDeliveryTime);
  zx_dup_strs_simple_elems(c, x->DistributionIndicator);
  zx_dup_strs_simple_elems(c, x->ContentClass);
  zx_dup_strs_simple_elems(c, x->DRMContent);
  zx_dup_strs_simple_elems(c, x->ApplicID);
  zx_dup_strs_simple_elems(c, x->ReplyApplicID);
  zx_dup_strs_simple_elems(c, x->AuxApplicInfo);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_MessageExtraData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_ReplaceReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ReplaceReq_s* zx_DEEP_CLONE_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_ReplaceReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ReplaceReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      struct zx_mm7_SenderIdentification_s* enn;
      for (enn = 0, e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SenderIdentification(c, e, dup_strs);
	  if (!enn)
	      x->SenderIdentification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      struct zx_mm7_ServiceCode_s* enn;
      for (enn = 0, e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ServiceCode(c, e, dup_strs);
	  if (!enn)
	      x->ServiceCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->TimeStamp = zx_deep_clone_simple_elems(c,x->TimeStamp, dup_strs);
  x->ReadReply = zx_deep_clone_simple_elems(c,x->ReadReply, dup_strs);
  x->EarliestDeliveryTime = zx_deep_clone_simple_elems(c,x->EarliestDeliveryTime, dup_strs);
  x->DistributionIndicator = zx_deep_clone_simple_elems(c,x->DistributionIndicator, dup_strs);
  x->ContentClass = zx_deep_clone_simple_elems(c,x->ContentClass, dup_strs);
  x->DRMContent = zx_deep_clone_simple_elems(c,x->DRMContent, dup_strs);
  x->ApplicID = zx_deep_clone_simple_elems(c,x->ApplicID, dup_strs);
  x->ReplyApplicID = zx_deep_clone_simple_elems(c,x->ReplyApplicID, dup_strs);
  x->AuxApplicInfo = zx_deep_clone_simple_elems(c,x->AuxApplicInfo, dup_strs);
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      struct zx_mm7_Content_s* enn;
      for (enn = 0, e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Content(c, e, dup_strs);
	  if (!enn)
	      x->Content = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      struct zx_mm7_AdditionalInformation_s* enn;
      for (enn = 0, e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_AdditionalInformation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalInformation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      struct zx_mm7_MessageExtraData_s* enn;
      for (enn = 0, e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_MessageExtraData(c, e, dup_strs);
	  if (!enn)
	      x->MessageExtraData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_ReplaceReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SenderIdentification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ServiceCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->TimeStamp, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReadReply, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->EarliestDeliveryTime, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DistributionIndicator, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ContentClass, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DRMContent, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuxApplicInfo, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Content(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_AdditionalInformation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_MessageExtraData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_ReplaceReq) */

int zx_WALK_WO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ReplaceRsp
#define EL_STRUCT zx_mm7_ReplaceRsp_s
#define EL_NS     mm7
#define EL_TAG    ReplaceRsp

/* FUNC(zx_FREE_mm7_ReplaceRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ReplaceRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ReplaceRsp_s* zx_NEW_mm7_ReplaceRsp(struct zx_ctx* c)
{
  struct zx_mm7_ReplaceRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_ReplaceRsp_s);
  x->gg.g.tok = zx_mm7_ReplaceRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ReplaceRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_ReplaceRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ReplaceRsp_s* zx_DEEP_CLONE_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_ReplaceRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ReplaceRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_ReplaceRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_ReplaceRsp) */

int zx_WALK_WO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ReplyCharging
#define EL_STRUCT zx_mm7_ReplyCharging_s
#define EL_NS     mm7
#define EL_TAG    ReplyCharging

/* FUNC(zx_FREE_mm7_ReplyCharging) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->replyChargingSize, free_strs);
  zx_free_attr(c, x->replyDeadline, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ReplyCharging) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ReplyCharging_s* zx_NEW_mm7_ReplyCharging(struct zx_ctx* c)
{
  struct zx_mm7_ReplyCharging_s* x = ZX_ZALLOC(c, struct zx_mm7_ReplyCharging_s);
  x->gg.g.tok = zx_mm7_ReplyCharging_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ReplyCharging) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->replyChargingSize);
  zx_dup_attr(c, x->replyDeadline);


}

/* FUNC(zx_DEEP_CLONE_mm7_ReplyCharging) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ReplyCharging_s* zx_DEEP_CLONE_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x, int dup_strs)
{
  x = (struct zx_mm7_ReplyCharging_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ReplyCharging_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->replyChargingSize = zx_clone_attr(c, x->replyChargingSize);
  x->replyDeadline = zx_clone_attr(c, x->replyDeadline);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_ReplyCharging) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_ReplyCharging) */

int zx_WALK_WO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Sender
#define EL_STRUCT zx_mm7_Sender_s
#define EL_NS     mm7
#define EL_TAG    Sender

/* FUNC(zx_FREE_mm7_Sender) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Sender) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Sender_s* zx_NEW_mm7_Sender(struct zx_ctx* c)
{
  struct zx_mm7_Sender_s* x = ZX_ZALLOC(c, struct zx_mm7_Sender_s);
  x->gg.g.tok = zx_mm7_Sender_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Sender) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Sender) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Sender_s* zx_DEEP_CLONE_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x, int dup_strs)
{
  x = (struct zx_mm7_Sender_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Sender_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Sender) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Sender) */

int zx_WALK_WO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_SenderAddress
#define EL_STRUCT zx_mm7_SenderAddress_s
#define EL_NS     mm7
#define EL_TAG    SenderAddress

/* FUNC(zx_FREE_mm7_SenderAddress) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_SenderAddress) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_SenderAddress_s* zx_NEW_mm7_SenderAddress(struct zx_ctx* c)
{
  struct zx_mm7_SenderAddress_s* x = ZX_ZALLOC(c, struct zx_mm7_SenderAddress_s);
  x->gg.g.tok = zx_mm7_SenderAddress_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_SenderAddress) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_SenderAddress) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_SenderAddress_s* zx_DEEP_CLONE_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x, int dup_strs)
{
  x = (struct zx_mm7_SenderAddress_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_SenderAddress_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_SenderAddress) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_SenderAddress) */

int zx_WALK_WO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_SenderIdentification
#define EL_STRUCT zx_mm7_SenderIdentification_s
#define EL_NS     mm7
#define EL_TAG    SenderIdentification

/* FUNC(zx_FREE_mm7_SenderIdentification) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->VASPID, free_strs);
  zx_free_simple_elems(c, x->VASID, free_strs);
  {
      struct zx_mm7_SenderAddress_s* e;
      struct zx_mm7_SenderAddress_s* en;
      for (e = x->SenderAddress; e; e = en) {
	  en = (struct zx_mm7_SenderAddress_s*)e->gg.g.n;
	  zx_FREE_mm7_SenderAddress(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_SenderIdentification) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_SenderIdentification_s* zx_NEW_mm7_SenderIdentification(struct zx_ctx* c)
{
  struct zx_mm7_SenderIdentification_s* x = ZX_ZALLOC(c, struct zx_mm7_SenderIdentification_s);
  x->gg.g.tok = zx_mm7_SenderIdentification_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_SenderIdentification) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->VASPID);
  zx_dup_strs_simple_elems(c, x->VASID);
  {
      struct zx_mm7_SenderAddress_s* e;
      for (e = x->SenderAddress; e; e = (struct zx_mm7_SenderAddress_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SenderAddress(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_SenderIdentification) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_SenderIdentification_s* zx_DEEP_CLONE_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x, int dup_strs)
{
  x = (struct zx_mm7_SenderIdentification_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_SenderIdentification_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->VASPID = zx_deep_clone_simple_elems(c,x->VASPID, dup_strs);
  x->VASID = zx_deep_clone_simple_elems(c,x->VASID, dup_strs);
  {
      struct zx_mm7_SenderAddress_s* e;
      struct zx_mm7_SenderAddress_s* en;
      struct zx_mm7_SenderAddress_s* enn;
      for (enn = 0, e = x->SenderAddress; e; e = (struct zx_mm7_SenderAddress_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SenderAddress(c, e, dup_strs);
	  if (!enn)
	      x->SenderAddress = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_SenderIdentification) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->VASPID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VASID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_SenderAddress_s* e;
      for (e = x->SenderAddress; e; e = (struct zx_mm7_SenderAddress_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SenderAddress(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_SenderIdentification) */

int zx_WALK_WO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ServiceCode
#define EL_STRUCT zx_mm7_ServiceCode_s
#define EL_NS     mm7
#define EL_TAG    ServiceCode

/* FUNC(zx_FREE_mm7_ServiceCode) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ServiceCode) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ServiceCode_s* zx_NEW_mm7_ServiceCode(struct zx_ctx* c)
{
  struct zx_mm7_ServiceCode_s* x = ZX_ZALLOC(c, struct zx_mm7_ServiceCode_s);
  x->gg.g.tok = zx_mm7_ServiceCode_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ServiceCode) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_mm7_ServiceCode) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ServiceCode_s* zx_DEEP_CLONE_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x, int dup_strs)
{
  x = (struct zx_mm7_ServiceCode_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ServiceCode_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_mm7_ServiceCode) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_ServiceCode) */

int zx_WALK_WO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ShortCode
#define EL_STRUCT zx_mm7_ShortCode_s
#define EL_NS     mm7
#define EL_TAG    ShortCode

/* FUNC(zx_FREE_mm7_ShortCode) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->addressCoding, free_strs);
  zx_free_attr(c, x->displayOnly, free_strs);
  zx_free_attr(c, x->id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ShortCode) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ShortCode_s* zx_NEW_mm7_ShortCode(struct zx_ctx* c)
{
  struct zx_mm7_ShortCode_s* x = ZX_ZALLOC(c, struct zx_mm7_ShortCode_s);
  x->gg.g.tok = zx_mm7_ShortCode_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ShortCode) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->addressCoding);
  zx_dup_attr(c, x->displayOnly);
  zx_dup_attr(c, x->id);


}

/* FUNC(zx_DEEP_CLONE_mm7_ShortCode) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ShortCode_s* zx_DEEP_CLONE_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x, int dup_strs)
{
  x = (struct zx_mm7_ShortCode_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ShortCode_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->addressCoding = zx_clone_attr(c, x->addressCoding);
  x->displayOnly = zx_clone_attr(c, x->displayOnly);
  x->id = zx_clone_attr(c, x->id);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_ShortCode) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_ShortCode) */

int zx_WALK_WO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_Status
#define EL_STRUCT zx_mm7_Status_s
#define EL_NS     mm7
#define EL_TAG    Status

/* FUNC(zx_FREE_mm7_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->StatusCode, free_strs);
  zx_free_simple_elems(c, x->StatusText, free_strs);
  {
      struct zx_mm7_Details_s* e;
      struct zx_mm7_Details_s* en;
      for (e = x->Details; e; e = en) {
	  en = (struct zx_mm7_Details_s*)e->gg.g.n;
	  zx_FREE_mm7_Details(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_Status_s* zx_NEW_mm7_Status(struct zx_ctx* c)
{
  struct zx_mm7_Status_s* x = ZX_ZALLOC(c, struct zx_mm7_Status_s);
  x->gg.g.tok = zx_mm7_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->StatusCode);
  zx_dup_strs_simple_elems(c, x->StatusText);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Details(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_Status_s* zx_DEEP_CLONE_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x, int dup_strs)
{
  x = (struct zx_mm7_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->StatusCode = zx_deep_clone_simple_elems(c,x->StatusCode, dup_strs);
  x->StatusText = zx_deep_clone_simple_elems(c,x->StatusText, dup_strs);
  {
      struct zx_mm7_Details_s* e;
      struct zx_mm7_Details_s* en;
      struct zx_mm7_Details_s* enn;
      for (enn = 0, e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Details(c, e, dup_strs);
	  if (!enn)
	      x->Details = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->StatusCode, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->StatusText, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Details(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_Status) */

int zx_WALK_WO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_SubmitReq
#define EL_STRUCT zx_mm7_SubmitReq_s
#define EL_NS     mm7
#define EL_TAG    SubmitReq

/* FUNC(zx_FREE_mm7_SubmitReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      for (e = x->SenderIdentification; e; e = en) {
	  en = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n;
	  zx_FREE_mm7_SenderIdentification(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Recipients_s* e;
      struct zx_mm7_Recipients_s* en;
      for (e = x->Recipients; e; e = en) {
	  en = (struct zx_mm7_Recipients_s*)e->gg.g.n;
	  zx_FREE_mm7_Recipients(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      struct zx_mm7_PreferredChannels_s* en;
      for (e = x->PreferredChannels; e; e = en) {
	  en = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n;
	  zx_FREE_mm7_PreferredChannels(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      for (e = x->ServiceCode; e; e = en) {
	  en = (struct zx_mm7_ServiceCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ServiceCode(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->LinkedID, free_strs);
  zx_free_simple_elems(c, x->MessageClass, free_strs);
  zx_free_simple_elems(c, x->TimeStamp, free_strs);
  {
      struct zx_mm7_ReplyCharging_s* e;
      struct zx_mm7_ReplyCharging_s* en;
      for (e = x->ReplyCharging; e; e = en) {
	  en = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n;
	  zx_FREE_mm7_ReplyCharging(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->EarliestDeliveryTime, free_strs);
  zx_free_simple_elems(c, x->ExpiryDate, free_strs);
  zx_free_simple_elems(c, x->DeliveryReport, free_strs);
  zx_free_simple_elems(c, x->ReadReply, free_strs);
  zx_free_simple_elems(c, x->Priority, free_strs);
  zx_free_simple_elems(c, x->Subject, free_strs);
  zx_free_simple_elems(c, x->ChargedParty, free_strs);
  zx_free_simple_elems(c, x->ChargedPartyID, free_strs);
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      struct zx_mm7_ThirdPartyPayer_s* en;
      for (e = x->ThirdPartyPayer; e; e = en) {
	  en = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n;
	  zx_FREE_mm7_ThirdPartyPayer(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->DistributionIndicator, free_strs);
  {
      struct zx_mm7_DeliveryCondition_s* e;
      struct zx_mm7_DeliveryCondition_s* en;
      for (e = x->DeliveryCondition; e; e = en) {
	  en = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n;
	  zx_FREE_mm7_DeliveryCondition(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ApplicID, free_strs);
  zx_free_simple_elems(c, x->ReplyApplicID, free_strs);
  zx_free_simple_elems(c, x->AuxApplicInfo, free_strs);
  zx_free_simple_elems(c, x->ContentClass, free_strs);
  zx_free_simple_elems(c, x->DRMContent, free_strs);
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      for (e = x->Content; e; e = en) {
	  en = (struct zx_mm7_Content_s*)e->gg.g.n;
	  zx_FREE_mm7_Content(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      for (e = x->AdditionalInformation; e; e = en) {
	  en = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n;
	  zx_FREE_mm7_AdditionalInformation(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      for (e = x->MessageExtraData; e; e = en) {
	  en = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n;
	  zx_FREE_mm7_MessageExtraData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_SubmitReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_SubmitReq_s* zx_NEW_mm7_SubmitReq(struct zx_ctx* c)
{
  struct zx_mm7_SubmitReq_s* x = ZX_ZALLOC(c, struct zx_mm7_SubmitReq_s);
  x->gg.g.tok = zx_mm7_SubmitReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_SubmitReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Recipients(c, e);
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      for (e = x->PreferredChannels; e; e = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_PreferredChannels(c, e);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ServiceCode(c, e);
  }
  zx_dup_strs_simple_elems(c, x->LinkedID);
  zx_dup_strs_simple_elems(c, x->MessageClass);
  zx_dup_strs_simple_elems(c, x->TimeStamp);
  {
      struct zx_mm7_ReplyCharging_s* e;
      for (e = x->ReplyCharging; e; e = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ReplyCharging(c, e);
  }
  zx_dup_strs_simple_elems(c, x->EarliestDeliveryTime);
  zx_dup_strs_simple_elems(c, x->ExpiryDate);
  zx_dup_strs_simple_elems(c, x->DeliveryReport);
  zx_dup_strs_simple_elems(c, x->ReadReply);
  zx_dup_strs_simple_elems(c, x->Priority);
  zx_dup_strs_simple_elems(c, x->Subject);
  zx_dup_strs_simple_elems(c, x->ChargedParty);
  zx_dup_strs_simple_elems(c, x->ChargedPartyID);
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      for (e = x->ThirdPartyPayer; e; e = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ThirdPartyPayer(c, e);
  }
  zx_dup_strs_simple_elems(c, x->DistributionIndicator);
  {
      struct zx_mm7_DeliveryCondition_s* e;
      for (e = x->DeliveryCondition; e; e = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_DeliveryCondition(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ApplicID);
  zx_dup_strs_simple_elems(c, x->ReplyApplicID);
  zx_dup_strs_simple_elems(c, x->AuxApplicInfo);
  zx_dup_strs_simple_elems(c, x->ContentClass);
  zx_dup_strs_simple_elems(c, x->DRMContent);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_MessageExtraData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_SubmitReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_SubmitReq_s* zx_DEEP_CLONE_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_SubmitReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_SubmitReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      struct zx_mm7_SenderIdentification_s* enn;
      for (enn = 0, e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SenderIdentification(c, e, dup_strs);
	  if (!enn)
	      x->SenderIdentification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Recipients_s* e;
      struct zx_mm7_Recipients_s* en;
      struct zx_mm7_Recipients_s* enn;
      for (enn = 0, e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Recipients(c, e, dup_strs);
	  if (!enn)
	      x->Recipients = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      struct zx_mm7_PreferredChannels_s* en;
      struct zx_mm7_PreferredChannels_s* enn;
      for (enn = 0, e = x->PreferredChannels; e; e = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_PreferredChannels(c, e, dup_strs);
	  if (!enn)
	      x->PreferredChannels = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      struct zx_mm7_ServiceCode_s* enn;
      for (enn = 0, e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ServiceCode(c, e, dup_strs);
	  if (!enn)
	      x->ServiceCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->LinkedID = zx_deep_clone_simple_elems(c,x->LinkedID, dup_strs);
  x->MessageClass = zx_deep_clone_simple_elems(c,x->MessageClass, dup_strs);
  x->TimeStamp = zx_deep_clone_simple_elems(c,x->TimeStamp, dup_strs);
  {
      struct zx_mm7_ReplyCharging_s* e;
      struct zx_mm7_ReplyCharging_s* en;
      struct zx_mm7_ReplyCharging_s* enn;
      for (enn = 0, e = x->ReplyCharging; e; e = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ReplyCharging(c, e, dup_strs);
	  if (!enn)
	      x->ReplyCharging = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->EarliestDeliveryTime = zx_deep_clone_simple_elems(c,x->EarliestDeliveryTime, dup_strs);
  x->ExpiryDate = zx_deep_clone_simple_elems(c,x->ExpiryDate, dup_strs);
  x->DeliveryReport = zx_deep_clone_simple_elems(c,x->DeliveryReport, dup_strs);
  x->ReadReply = zx_deep_clone_simple_elems(c,x->ReadReply, dup_strs);
  x->Priority = zx_deep_clone_simple_elems(c,x->Priority, dup_strs);
  x->Subject = zx_deep_clone_simple_elems(c,x->Subject, dup_strs);
  x->ChargedParty = zx_deep_clone_simple_elems(c,x->ChargedParty, dup_strs);
  x->ChargedPartyID = zx_deep_clone_simple_elems(c,x->ChargedPartyID, dup_strs);
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      struct zx_mm7_ThirdPartyPayer_s* en;
      struct zx_mm7_ThirdPartyPayer_s* enn;
      for (enn = 0, e = x->ThirdPartyPayer; e; e = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ThirdPartyPayer(c, e, dup_strs);
	  if (!enn)
	      x->ThirdPartyPayer = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->DistributionIndicator = zx_deep_clone_simple_elems(c,x->DistributionIndicator, dup_strs);
  {
      struct zx_mm7_DeliveryCondition_s* e;
      struct zx_mm7_DeliveryCondition_s* en;
      struct zx_mm7_DeliveryCondition_s* enn;
      for (enn = 0, e = x->DeliveryCondition; e; e = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_DeliveryCondition(c, e, dup_strs);
	  if (!enn)
	      x->DeliveryCondition = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ApplicID = zx_deep_clone_simple_elems(c,x->ApplicID, dup_strs);
  x->ReplyApplicID = zx_deep_clone_simple_elems(c,x->ReplyApplicID, dup_strs);
  x->AuxApplicInfo = zx_deep_clone_simple_elems(c,x->AuxApplicInfo, dup_strs);
  x->ContentClass = zx_deep_clone_simple_elems(c,x->ContentClass, dup_strs);
  x->DRMContent = zx_deep_clone_simple_elems(c,x->DRMContent, dup_strs);
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      struct zx_mm7_Content_s* enn;
      for (enn = 0, e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Content(c, e, dup_strs);
	  if (!enn)
	      x->Content = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      struct zx_mm7_AdditionalInformation_s* enn;
      for (enn = 0, e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_AdditionalInformation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalInformation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      struct zx_mm7_MessageExtraData_s* enn;
      for (enn = 0, e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_MessageExtraData(c, e, dup_strs);
	  if (!enn)
	      x->MessageExtraData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_SubmitReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SenderIdentification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Recipients(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      for (e = x->PreferredChannels; e; e = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_PreferredChannels(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ServiceCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->LinkedID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MessageClass, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->TimeStamp, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_ReplyCharging_s* e;
      for (e = x->ReplyCharging; e; e = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ReplyCharging(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->EarliestDeliveryTime, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ExpiryDate, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DeliveryReport, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReadReply, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Priority, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Subject, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ChargedParty, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ChargedPartyID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      for (e = x->ThirdPartyPayer; e; e = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ThirdPartyPayer(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->DistributionIndicator, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_DeliveryCondition_s* e;
      for (e = x->DeliveryCondition; e; e = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_DeliveryCondition(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReplyApplicID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->AuxApplicInfo, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ContentClass, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DRMContent, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Content(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_AdditionalInformation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_MessageExtraData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_SubmitReq) */

int zx_WALK_WO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_SubmitRsp
#define EL_STRUCT zx_mm7_SubmitRsp_s
#define EL_NS     mm7
#define EL_TAG    SubmitRsp

/* FUNC(zx_FREE_mm7_SubmitRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->MessageID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_SubmitRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_SubmitRsp_s* zx_NEW_mm7_SubmitRsp(struct zx_ctx* c)
{
  struct zx_mm7_SubmitRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_SubmitRsp_s);
  x->gg.g.tok = zx_mm7_SubmitRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_SubmitRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->MessageID);

}

/* FUNC(zx_DEEP_CLONE_mm7_SubmitRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_SubmitRsp_s* zx_DEEP_CLONE_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_SubmitRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_SubmitRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_SubmitRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_SubmitRsp) */

int zx_WALK_WO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_ThirdPartyPayer
#define EL_STRUCT zx_mm7_ThirdPartyPayer_s
#define EL_NS     mm7
#define EL_TAG    ThirdPartyPayer

/* FUNC(zx_FREE_mm7_ThirdPartyPayer) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_ThirdPartyPayer) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_ThirdPartyPayer_s* zx_NEW_mm7_ThirdPartyPayer(struct zx_ctx* c)
{
  struct zx_mm7_ThirdPartyPayer_s* x = ZX_ZALLOC(c, struct zx_mm7_ThirdPartyPayer_s);
  x->gg.g.tok = zx_mm7_ThirdPartyPayer_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_ThirdPartyPayer) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_ThirdPartyPayer) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_ThirdPartyPayer_s* zx_DEEP_CLONE_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x, int dup_strs)
{
  x = (struct zx_mm7_ThirdPartyPayer_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_ThirdPartyPayer_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_ThirdPartyPayer) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_ThirdPartyPayer) */

int zx_WALK_WO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_To
#define EL_STRUCT zx_mm7_To_s
#define EL_NS     mm7
#define EL_TAG    To

/* FUNC(zx_FREE_mm7_To) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_To) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_To_s* zx_NEW_mm7_To(struct zx_ctx* c)
{
  struct zx_mm7_To_s* x = ZX_ZALLOC(c, struct zx_mm7_To_s);
  x->gg.g.tok = zx_mm7_To_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_To) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_To) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_To_s* zx_DEEP_CLONE_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x, int dup_strs)
{
  x = (struct zx_mm7_To_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_To_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_To) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_To) */

int zx_WALK_WO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_TransactionID
#define EL_STRUCT zx_mm7_TransactionID_s
#define EL_NS     mm7
#define EL_TAG    TransactionID

/* FUNC(zx_FREE_mm7_TransactionID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->encodingStyle, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_TransactionID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_TransactionID_s* zx_NEW_mm7_TransactionID(struct zx_ctx* c)
{
  struct zx_mm7_TransactionID_s* x = ZX_ZALLOC(c, struct zx_mm7_TransactionID_s);
  x->gg.g.tok = zx_mm7_TransactionID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_TransactionID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->encodingStyle);
  zx_dup_attr(c, x->mustUnderstand);


}

/* FUNC(zx_DEEP_CLONE_mm7_TransactionID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_TransactionID_s* zx_DEEP_CLONE_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x, int dup_strs)
{
  x = (struct zx_mm7_TransactionID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_TransactionID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->actor = zx_clone_attr(c, x->actor);
  x->encodingStyle = zx_clone_attr(c, x->encodingStyle);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_TransactionID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_TransactionID) */

int zx_WALK_WO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_UACapabilities
#define EL_STRUCT zx_mm7_UACapabilities_s
#define EL_NS     mm7
#define EL_TAG    UACapabilities

/* FUNC(zx_FREE_mm7_UACapabilities) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->TimeStamp, free_strs);
  zx_free_attr(c, x->UAProf, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_UACapabilities) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_UACapabilities_s* zx_NEW_mm7_UACapabilities(struct zx_ctx* c)
{
  struct zx_mm7_UACapabilities_s* x = ZX_ZALLOC(c, struct zx_mm7_UACapabilities_s);
  x->gg.g.tok = zx_mm7_UACapabilities_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_UACapabilities) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->TimeStamp);
  zx_dup_attr(c, x->UAProf);


}

/* FUNC(zx_DEEP_CLONE_mm7_UACapabilities) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_UACapabilities_s* zx_DEEP_CLONE_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x, int dup_strs)
{
  x = (struct zx_mm7_UACapabilities_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_UACapabilities_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->TimeStamp = zx_clone_attr(c, x->TimeStamp);
  x->UAProf = zx_clone_attr(c, x->UAProf);


  return x;
}

/* FUNC(zx_WALK_SO_mm7_UACapabilities) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_mm7_UACapabilities) */

int zx_WALK_WO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_UserAgent
#define EL_STRUCT zx_mm7_UserAgent_s
#define EL_NS     mm7
#define EL_TAG    UserAgent

/* FUNC(zx_FREE_mm7_UserAgent) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->sequence, free_strs);

  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      for (e = x->RFC2822Address; e; e = en) {
	  en = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n;
	  zx_FREE_mm7_RFC2822Address(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      for (e = x->Number; e; e = en) {
	  en = (struct zx_mm7_Number_s*)e->gg.g.n;
	  zx_FREE_mm7_Number(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      for (e = x->ShortCode; e; e = en) {
	  en = (struct zx_mm7_ShortCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ShortCode(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_UserAgent) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_UserAgent_s* zx_NEW_mm7_UserAgent(struct zx_ctx* c)
{
  struct zx_mm7_UserAgent_s* x = ZX_ZALLOC(c, struct zx_mm7_UserAgent_s);
  x->gg.g.tok = zx_mm7_UserAgent_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_UserAgent) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->sequence);

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_UserAgent) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_UserAgent_s* zx_DEEP_CLONE_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x, int dup_strs)
{
  x = (struct zx_mm7_UserAgent_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_UserAgent_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->sequence = zx_clone_attr(c, x->sequence);

  {
      struct zx_mm7_RFC2822Address_s* e;
      struct zx_mm7_RFC2822Address_s* en;
      struct zx_mm7_RFC2822Address_s* enn;
      for (enn = 0, e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RFC2822Address(c, e, dup_strs);
	  if (!enn)
	      x->RFC2822Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      struct zx_mm7_Number_s* en;
      struct zx_mm7_Number_s* enn;
      for (enn = 0, e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Number(c, e, dup_strs);
	  if (!enn)
	      x->Number = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      struct zx_mm7_ShortCode_s* en;
      struct zx_mm7_ShortCode_s* enn;
      for (enn = 0, e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ShortCode(c, e, dup_strs);
	  if (!enn)
	      x->ShortCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_UserAgent) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RFC2822Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Number(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ShortCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_UserAgent) */

int zx_WALK_WO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_VASPErrorRsp
#define EL_STRUCT zx_mm7_VASPErrorRsp_s
#define EL_NS     mm7
#define EL_TAG    VASPErrorRsp

/* FUNC(zx_FREE_mm7_VASPErrorRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_VASPErrorRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_VASPErrorRsp_s* zx_NEW_mm7_VASPErrorRsp(struct zx_ctx* c)
{
  struct zx_mm7_VASPErrorRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_VASPErrorRsp_s);
  x->gg.g.tok = zx_mm7_VASPErrorRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_VASPErrorRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_VASPErrorRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_VASPErrorRsp_s* zx_DEEP_CLONE_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_VASPErrorRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_VASPErrorRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_VASPErrorRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_VASPErrorRsp) */

int zx_WALK_WO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_element
#define EL_STRUCT zx_mm7_element_s
#define EL_NS     mm7
#define EL_TAG    element

/* FUNC(zx_FREE_mm7_element) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->key, free_strs);
  zx_free_simple_elems(c, x->value, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_element) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_element_s* zx_NEW_mm7_element(struct zx_ctx* c)
{
  struct zx_mm7_element_s* x = ZX_ZALLOC(c, struct zx_mm7_element_s);
  x->gg.g.tok = zx_mm7_element_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_element) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->key);
  zx_dup_strs_simple_elems(c, x->value);

}

/* FUNC(zx_DEEP_CLONE_mm7_element) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_element_s* zx_DEEP_CLONE_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x, int dup_strs)
{
  x = (struct zx_mm7_element_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_element_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->key = zx_deep_clone_simple_elems(c,x->key, dup_strs);
  x->value = zx_deep_clone_simple_elems(c,x->value, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_element) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->key, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->value, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_element) */

int zx_WALK_WO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_extendedCancelReq
#define EL_STRUCT zx_mm7_extendedCancelReq_s
#define EL_NS     mm7
#define EL_TAG    extendedCancelReq

/* FUNC(zx_FREE_mm7_extendedCancelReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      for (e = x->SenderIdentification; e; e = en) {
	  en = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n;
	  zx_FREE_mm7_SenderIdentification(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_mm7_Extension_s*)e->gg.g.n;
	  zx_FREE_mm7_Extension(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->CancelID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_extendedCancelReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_extendedCancelReq_s* zx_NEW_mm7_extendedCancelReq(struct zx_ctx* c)
{
  struct zx_mm7_extendedCancelReq_s* x = ZX_ZALLOC(c, struct zx_mm7_extendedCancelReq_s);
  x->gg.g.tok = zx_mm7_extendedCancelReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_extendedCancelReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Extension(c, e);
  }
  zx_dup_strs_simple_elems(c, x->CancelID);

}

/* FUNC(zx_DEEP_CLONE_mm7_extendedCancelReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_extendedCancelReq_s* zx_DEEP_CLONE_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_extendedCancelReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_extendedCancelReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_SenderIdentification_s* e;
      struct zx_mm7_SenderIdentification_s* en;
      struct zx_mm7_SenderIdentification_s* enn;
      for (enn = 0, e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SenderIdentification(c, e, dup_strs);
	  if (!enn)
	      x->SenderIdentification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      struct zx_mm7_Extension_s* en;
      struct zx_mm7_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->CancelID = zx_deep_clone_simple_elems(c,x->CancelID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_mm7_extendedCancelReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SenderIdentification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->CancelID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_extendedCancelReq) */

int zx_WALK_WO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_extendedCancelRsp
#define EL_STRUCT zx_mm7_extendedCancelRsp_s
#define EL_NS     mm7
#define EL_TAG    extendedCancelRsp

/* FUNC(zx_FREE_mm7_extendedCancelRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_extendedCancelRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_extendedCancelRsp_s* zx_NEW_mm7_extendedCancelRsp(struct zx_ctx* c)
{
  struct zx_mm7_extendedCancelRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_extendedCancelRsp_s);
  x->gg.g.tok = zx_mm7_extendedCancelRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_extendedCancelRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_extendedCancelRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_extendedCancelRsp_s* zx_DEEP_CLONE_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_extendedCancelRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_extendedCancelRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_extendedCancelRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_extendedCancelRsp) */

int zx_WALK_WO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_extendedReplaceReq
#define EL_STRUCT zx_mm7_extendedReplaceReq_s
#define EL_NS     mm7
#define EL_TAG    extendedReplaceReq

/* FUNC(zx_FREE_mm7_extendedReplaceReq) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->VASPID, free_strs);
  zx_free_simple_elems(c, x->VASID, free_strs);
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      for (e = x->ServiceCode; e; e = en) {
	  en = (struct zx_mm7_ServiceCode_s*)e->gg.g.n;
	  zx_FREE_mm7_ServiceCode(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ReplaceID, free_strs);
  zx_free_simple_elems(c, x->TimeStamp, free_strs);
  zx_free_simple_elems(c, x->EarliestDeliveryTime, free_strs);
  zx_free_simple_elems(c, x->ExpiryDate, free_strs);
  zx_free_simple_elems(c, x->ReadReply, free_strs);
  zx_free_simple_elems(c, x->DeliveryReport, free_strs);
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      for (e = x->Content; e; e = en) {
	  en = (struct zx_mm7_Content_s*)e->gg.g.n;
	  zx_FREE_mm7_Content(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      for (e = x->AdditionalInformation; e; e = en) {
	  en = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n;
	  zx_FREE_mm7_AdditionalInformation(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      for (e = x->MessageExtraData; e; e = en) {
	  en = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n;
	  zx_FREE_mm7_MessageExtraData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_extendedReplaceReq) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_extendedReplaceReq_s* zx_NEW_mm7_extendedReplaceReq(struct zx_ctx* c)
{
  struct zx_mm7_extendedReplaceReq_s* x = ZX_ZALLOC(c, struct zx_mm7_extendedReplaceReq_s);
  x->gg.g.tok = zx_mm7_extendedReplaceReq_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_extendedReplaceReq) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->VASPID);
  zx_dup_strs_simple_elems(c, x->VASID);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ServiceCode(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ReplaceID);
  zx_dup_strs_simple_elems(c, x->TimeStamp);
  zx_dup_strs_simple_elems(c, x->EarliestDeliveryTime);
  zx_dup_strs_simple_elems(c, x->ExpiryDate);
  zx_dup_strs_simple_elems(c, x->ReadReply);
  zx_dup_strs_simple_elems(c, x->DeliveryReport);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_MessageExtraData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_extendedReplaceReq) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_extendedReplaceReq_s* zx_DEEP_CLONE_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x, int dup_strs)
{
  x = (struct zx_mm7_extendedReplaceReq_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_extendedReplaceReq_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->VASPID = zx_deep_clone_simple_elems(c,x->VASPID, dup_strs);
  x->VASID = zx_deep_clone_simple_elems(c,x->VASID, dup_strs);
  {
      struct zx_mm7_ServiceCode_s* e;
      struct zx_mm7_ServiceCode_s* en;
      struct zx_mm7_ServiceCode_s* enn;
      for (enn = 0, e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ServiceCode(c, e, dup_strs);
	  if (!enn)
	      x->ServiceCode = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ReplaceID = zx_deep_clone_simple_elems(c,x->ReplaceID, dup_strs);
  x->TimeStamp = zx_deep_clone_simple_elems(c,x->TimeStamp, dup_strs);
  x->EarliestDeliveryTime = zx_deep_clone_simple_elems(c,x->EarliestDeliveryTime, dup_strs);
  x->ExpiryDate = zx_deep_clone_simple_elems(c,x->ExpiryDate, dup_strs);
  x->ReadReply = zx_deep_clone_simple_elems(c,x->ReadReply, dup_strs);
  x->DeliveryReport = zx_deep_clone_simple_elems(c,x->DeliveryReport, dup_strs);
  {
      struct zx_mm7_Content_s* e;
      struct zx_mm7_Content_s* en;
      struct zx_mm7_Content_s* enn;
      for (enn = 0, e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Content(c, e, dup_strs);
	  if (!enn)
	      x->Content = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      struct zx_mm7_AdditionalInformation_s* en;
      struct zx_mm7_AdditionalInformation_s* enn;
      for (enn = 0, e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_AdditionalInformation(c, e, dup_strs);
	  if (!enn)
	      x->AdditionalInformation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      struct zx_mm7_MessageExtraData_s* en;
      struct zx_mm7_MessageExtraData_s* enn;
      for (enn = 0, e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_MessageExtraData(c, e, dup_strs);
	  if (!enn)
	      x->MessageExtraData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_extendedReplaceReq) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VASPID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VASID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ServiceCode(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ReplaceID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->TimeStamp, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->EarliestDeliveryTime, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ExpiryDate, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ReadReply, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DeliveryReport, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Content(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_AdditionalInformation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_MessageExtraData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_extendedReplaceReq) */

int zx_WALK_WO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   mm7_extendedReplaceRsp
#define EL_STRUCT zx_mm7_extendedReplaceRsp_s
#define EL_NS     mm7
#define EL_TAG    extendedReplaceRsp

/* FUNC(zx_FREE_mm7_extendedReplaceRsp) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->MM7Version, free_strs);
  zx_free_simple_elems(c, x->MessageID, free_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_mm7_Status_s*)e->gg.g.n;
	  zx_FREE_mm7_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_mm7_extendedReplaceRsp) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_mm7_extendedReplaceRsp_s* zx_NEW_mm7_extendedReplaceRsp(struct zx_ctx* c)
{
  struct zx_mm7_extendedReplaceRsp_s* x = ZX_ZALLOC(c, struct zx_mm7_extendedReplaceRsp_s);
  x->gg.g.tok = zx_mm7_extendedReplaceRsp_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_mm7_extendedReplaceRsp) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->MM7Version);
  zx_dup_strs_simple_elems(c, x->MessageID);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_mm7_extendedReplaceRsp) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_mm7_extendedReplaceRsp_s* zx_DEEP_CLONE_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x, int dup_strs)
{
  x = (struct zx_mm7_extendedReplaceRsp_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_mm7_extendedReplaceRsp_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->MM7Version = zx_deep_clone_simple_elems(c,x->MM7Version, dup_strs);
  x->MessageID = zx_deep_clone_simple_elems(c,x->MessageID, dup_strs);
  {
      struct zx_mm7_Status_s* e;
      struct zx_mm7_Status_s* en;
      struct zx_mm7_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_mm7_extendedReplaceRsp) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->MM7Version, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MessageID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_mm7_extendedReplaceRsp) */

int zx_WALK_WO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-mm7-aux.c */
