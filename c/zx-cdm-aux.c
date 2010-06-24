/* c/zx-cdm-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-cdm-data.h"



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

#define EL_NAME   cdm_ADR
#define EL_STRUCT zx_cdm_ADR_s
#define EL_NS     cdm
#define EL_TAG    ADR

/* FUNC(zx_FREE_cdm_ADR) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  zx_free_simple_elems(c, x->HOME, free_strs);
  zx_free_simple_elems(c, x->WORK, free_strs);
  zx_free_simple_elems(c, x->POSTAL, free_strs);
  zx_free_simple_elems(c, x->PARCEL, free_strs);
  zx_free_simple_elems(c, x->DOM, free_strs);
  zx_free_simple_elems(c, x->INTL, free_strs);
  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_POBOX_s* e;
      struct zx_cdm_POBOX_s* en;
      for (e = x->POBOX; e; e = en) {
	  en = (struct zx_cdm_POBOX_s*)e->gg.g.n;
	  zx_FREE_cdm_POBOX(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_EXTADR_s* e;
      struct zx_cdm_EXTADR_s* en;
      for (e = x->EXTADR; e; e = en) {
	  en = (struct zx_cdm_EXTADR_s*)e->gg.g.n;
	  zx_FREE_cdm_EXTADR(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_STREET_s* e;
      struct zx_cdm_STREET_s* en;
      for (e = x->STREET; e; e = en) {
	  en = (struct zx_cdm_STREET_s*)e->gg.g.n;
	  zx_FREE_cdm_STREET(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      struct zx_cdm_LOCALITY_s* en;
      for (e = x->LOCALITY; e; e = en) {
	  en = (struct zx_cdm_LOCALITY_s*)e->gg.g.n;
	  zx_FREE_cdm_LOCALITY(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_REGION_s* e;
      struct zx_cdm_REGION_s* en;
      for (e = x->REGION; e; e = en) {
	  en = (struct zx_cdm_REGION_s*)e->gg.g.n;
	  zx_FREE_cdm_REGION(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_PCODE_s* e;
      struct zx_cdm_PCODE_s* en;
      for (e = x->PCODE; e; e = en) {
	  en = (struct zx_cdm_PCODE_s*)e->gg.g.n;
	  zx_FREE_cdm_PCODE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CTRY_s* e;
      struct zx_cdm_CTRY_s* en;
      for (e = x->CTRY; e; e = en) {
	  en = (struct zx_cdm_CTRY_s*)e->gg.g.n;
	  zx_FREE_cdm_CTRY(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_ADR) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_ADR_s* zx_NEW_cdm_ADR(struct zx_ctx* c)
{
  struct zx_cdm_ADR_s* x = ZX_ZALLOC(c, struct zx_cdm_ADR_s);
  x->gg.g.tok = zx_cdm_ADR_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_ADR) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  zx_dup_strs_simple_elems(c, x->HOME);
  zx_dup_strs_simple_elems(c, x->WORK);
  zx_dup_strs_simple_elems(c, x->POSTAL);
  zx_dup_strs_simple_elems(c, x->PARCEL);
  zx_dup_strs_simple_elems(c, x->DOM);
  zx_dup_strs_simple_elems(c, x->INTL);
  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_POBOX_s* e;
      for (e = x->POBOX; e; e = (struct zx_cdm_POBOX_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_POBOX(c, e);
  }
  {
      struct zx_cdm_EXTADR_s* e;
      for (e = x->EXTADR; e; e = (struct zx_cdm_EXTADR_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_EXTADR(c, e);
  }
  {
      struct zx_cdm_STREET_s* e;
      for (e = x->STREET; e; e = (struct zx_cdm_STREET_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_STREET(c, e);
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      for (e = x->LOCALITY; e; e = (struct zx_cdm_LOCALITY_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LOCALITY(c, e);
  }
  {
      struct zx_cdm_REGION_s* e;
      for (e = x->REGION; e; e = (struct zx_cdm_REGION_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_REGION(c, e);
  }
  {
      struct zx_cdm_PCODE_s* e;
      for (e = x->PCODE; e; e = (struct zx_cdm_PCODE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_PCODE(c, e);
  }
  {
      struct zx_cdm_CTRY_s* e;
      for (e = x->CTRY; e; e = (struct zx_cdm_CTRY_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CTRY(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_ADR) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_ADR_s* zx_DEEP_CLONE_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x, int dup_strs)
{
  x = (struct zx_cdm_ADR_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_ADR_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  x->HOME = zx_deep_clone_simple_elems(c,x->HOME, dup_strs);
  x->WORK = zx_deep_clone_simple_elems(c,x->WORK, dup_strs);
  x->POSTAL = zx_deep_clone_simple_elems(c,x->POSTAL, dup_strs);
  x->PARCEL = zx_deep_clone_simple_elems(c,x->PARCEL, dup_strs);
  x->DOM = zx_deep_clone_simple_elems(c,x->DOM, dup_strs);
  x->INTL = zx_deep_clone_simple_elems(c,x->INTL, dup_strs);
  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_POBOX_s* e;
      struct zx_cdm_POBOX_s* en;
      struct zx_cdm_POBOX_s* enn;
      for (enn = 0, e = x->POBOX; e; e = (struct zx_cdm_POBOX_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_POBOX(c, e, dup_strs);
	  if (!enn)
	      x->POBOX = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_EXTADR_s* e;
      struct zx_cdm_EXTADR_s* en;
      struct zx_cdm_EXTADR_s* enn;
      for (enn = 0, e = x->EXTADR; e; e = (struct zx_cdm_EXTADR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_EXTADR(c, e, dup_strs);
	  if (!enn)
	      x->EXTADR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_STREET_s* e;
      struct zx_cdm_STREET_s* en;
      struct zx_cdm_STREET_s* enn;
      for (enn = 0, e = x->STREET; e; e = (struct zx_cdm_STREET_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_STREET(c, e, dup_strs);
	  if (!enn)
	      x->STREET = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      struct zx_cdm_LOCALITY_s* en;
      struct zx_cdm_LOCALITY_s* enn;
      for (enn = 0, e = x->LOCALITY; e; e = (struct zx_cdm_LOCALITY_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LOCALITY(c, e, dup_strs);
	  if (!enn)
	      x->LOCALITY = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_REGION_s* e;
      struct zx_cdm_REGION_s* en;
      struct zx_cdm_REGION_s* enn;
      for (enn = 0, e = x->REGION; e; e = (struct zx_cdm_REGION_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_REGION(c, e, dup_strs);
	  if (!enn)
	      x->REGION = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_PCODE_s* e;
      struct zx_cdm_PCODE_s* en;
      struct zx_cdm_PCODE_s* enn;
      for (enn = 0, e = x->PCODE; e; e = (struct zx_cdm_PCODE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_PCODE(c, e, dup_strs);
	  if (!enn)
	      x->PCODE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CTRY_s* e;
      struct zx_cdm_CTRY_s* en;
      struct zx_cdm_CTRY_s* enn;
      for (enn = 0, e = x->CTRY; e; e = (struct zx_cdm_CTRY_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CTRY(c, e, dup_strs);
	  if (!enn)
	      x->CTRY = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_ADR) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->HOME, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->WORK, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->POSTAL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PARCEL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DOM, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->INTL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_POBOX_s* e;
      for (e = x->POBOX; e; e = (struct zx_cdm_POBOX_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_POBOX(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_EXTADR_s* e;
      for (e = x->EXTADR; e; e = (struct zx_cdm_EXTADR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_EXTADR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_STREET_s* e;
      for (e = x->STREET; e; e = (struct zx_cdm_STREET_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_STREET(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      for (e = x->LOCALITY; e; e = (struct zx_cdm_LOCALITY_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LOCALITY(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_REGION_s* e;
      for (e = x->REGION; e; e = (struct zx_cdm_REGION_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_REGION(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_PCODE_s* e;
      for (e = x->PCODE; e; e = (struct zx_cdm_PCODE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_PCODE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CTRY_s* e;
      for (e = x->CTRY; e; e = (struct zx_cdm_CTRY_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CTRY(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_ADR) */

int zx_WALK_WO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_AGENT
#define EL_STRUCT zx_cdm_AGENT_s
#define EL_NS     cdm
#define EL_TAG    AGENT

/* FUNC(zx_FREE_cdm_AGENT) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_vCard_s* e;
      struct zx_cdm_vCard_s* en;
      for (e = x->vCard; e; e = en) {
	  en = (struct zx_cdm_vCard_s*)e->gg.g.n;
	  zx_FREE_cdm_vCard(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      for (e = x->EXTVAL; e; e = en) {
	  en = (struct zx_cdm_EXTVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_EXTVAL(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_AGENT) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_AGENT_s* zx_NEW_cdm_AGENT(struct zx_ctx* c)
{
  struct zx_cdm_AGENT_s* x = ZX_ZALLOC(c, struct zx_cdm_AGENT_s);
  x->gg.g.tok = zx_cdm_AGENT_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_AGENT) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_vCard_s* e;
      for (e = x->vCard; e; e = (struct zx_cdm_vCard_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_vCard(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_EXTVAL(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_AGENT) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_AGENT_s* zx_DEEP_CLONE_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x, int dup_strs)
{
  x = (struct zx_cdm_AGENT_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_AGENT_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_vCard_s* e;
      struct zx_cdm_vCard_s* en;
      struct zx_cdm_vCard_s* enn;
      for (enn = 0, e = x->vCard; e; e = (struct zx_cdm_vCard_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_vCard(c, e, dup_strs);
	  if (!enn)
	      x->vCard = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      struct zx_cdm_EXTVAL_s* enn;
      for (enn = 0, e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_EXTVAL(c, e, dup_strs);
	  if (!enn)
	      x->EXTVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_AGENT) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_vCard_s* e;
      for (e = x->vCard; e; e = (struct zx_cdm_vCard_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_vCard(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_EXTVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_AGENT) */

int zx_WALK_WO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_BDAY
#define EL_STRUCT zx_cdm_BDAY_s
#define EL_NS     cdm
#define EL_TAG    BDAY

/* FUNC(zx_FREE_cdm_BDAY) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_BDAY) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_BDAY_s* zx_NEW_cdm_BDAY(struct zx_ctx* c)
{
  struct zx_cdm_BDAY_s* x = ZX_ZALLOC(c, struct zx_cdm_BDAY_s);
  x->gg.g.tok = zx_cdm_BDAY_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_BDAY) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_BDAY) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_BDAY_s* zx_DEEP_CLONE_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x, int dup_strs)
{
  x = (struct zx_cdm_BDAY_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_BDAY_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_BDAY) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_BDAY) */

int zx_WALK_WO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_BINVAL
#define EL_STRUCT zx_cdm_BINVAL_s
#define EL_NS     cdm
#define EL_TAG    BINVAL

/* FUNC(zx_FREE_cdm_BINVAL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_BINVAL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_BINVAL_s* zx_NEW_cdm_BINVAL(struct zx_ctx* c)
{
  struct zx_cdm_BINVAL_s* x = ZX_ZALLOC(c, struct zx_cdm_BINVAL_s);
  x->gg.g.tok = zx_cdm_BINVAL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_BINVAL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_BINVAL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_BINVAL_s* zx_DEEP_CLONE_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x, int dup_strs)
{
  x = (struct zx_cdm_BINVAL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_BINVAL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_BINVAL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_BINVAL) */

int zx_WALK_WO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CALADRURI
#define EL_STRUCT zx_cdm_CALADRURI_s
#define EL_NS     cdm
#define EL_TAG    CALADRURI

/* FUNC(zx_FREE_cdm_CALADRURI) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);

  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      for (e = x->URI; e; e = en) {
	  en = (struct zx_cdm_URI_s*)e->gg.g.n;
	  zx_FREE_cdm_URI(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CALADRURI) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CALADRURI_s* zx_NEW_cdm_CALADRURI(struct zx_ctx* c)
{
  struct zx_cdm_CALADRURI_s* x = ZX_ZALLOC(c, struct zx_cdm_CALADRURI_s);
  x->gg.g.tok = zx_cdm_CALADRURI_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CALADRURI) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);

  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_URI(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_CALADRURI) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CALADRURI_s* zx_DEEP_CLONE_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x, int dup_strs)
{
  x = (struct zx_cdm_CALADRURI_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CALADRURI_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);

  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      struct zx_cdm_URI_s* enn;
      for (enn = 0, e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_URI(c, e, dup_strs);
	  if (!enn)
	      x->URI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_CALADRURI) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_URI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_CALADRURI) */

int zx_WALK_WO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CALURI
#define EL_STRUCT zx_cdm_CALURI_s
#define EL_NS     cdm
#define EL_TAG    CALURI

/* FUNC(zx_FREE_cdm_CALURI) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);

  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      for (e = x->URI; e; e = en) {
	  en = (struct zx_cdm_URI_s*)e->gg.g.n;
	  zx_FREE_cdm_URI(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CALURI) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CALURI_s* zx_NEW_cdm_CALURI(struct zx_ctx* c)
{
  struct zx_cdm_CALURI_s* x = ZX_ZALLOC(c, struct zx_cdm_CALURI_s);
  x->gg.g.tok = zx_cdm_CALURI_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CALURI) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);

  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_URI(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_CALURI) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CALURI_s* zx_DEEP_CLONE_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x, int dup_strs)
{
  x = (struct zx_cdm_CALURI_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CALURI_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);

  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      struct zx_cdm_URI_s* enn;
      for (enn = 0, e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_URI(c, e, dup_strs);
	  if (!enn)
	      x->URI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_CALURI) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_URI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_CALURI) */

int zx_WALK_WO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CAPURI
#define EL_STRUCT zx_cdm_CAPURI_s
#define EL_NS     cdm
#define EL_TAG    CAPURI

/* FUNC(zx_FREE_cdm_CAPURI) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);

  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      for (e = x->URI; e; e = en) {
	  en = (struct zx_cdm_URI_s*)e->gg.g.n;
	  zx_FREE_cdm_URI(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CAPURI) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CAPURI_s* zx_NEW_cdm_CAPURI(struct zx_ctx* c)
{
  struct zx_cdm_CAPURI_s* x = ZX_ZALLOC(c, struct zx_cdm_CAPURI_s);
  x->gg.g.tok = zx_cdm_CAPURI_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CAPURI) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);

  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_URI(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_CAPURI) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CAPURI_s* zx_DEEP_CLONE_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x, int dup_strs)
{
  x = (struct zx_cdm_CAPURI_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CAPURI_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);

  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      struct zx_cdm_URI_s* enn;
      for (enn = 0, e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_URI(c, e, dup_strs);
	  if (!enn)
	      x->URI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_CAPURI) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_URI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_CAPURI) */

int zx_WALK_WO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CATEGORIES
#define EL_STRUCT zx_cdm_CATEGORIES_s
#define EL_NS     cdm
#define EL_TAG    CATEGORIES

/* FUNC(zx_FREE_cdm_CATEGORIES) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_KEYWORD_s* e;
      struct zx_cdm_KEYWORD_s* en;
      for (e = x->KEYWORD; e; e = en) {
	  en = (struct zx_cdm_KEYWORD_s*)e->gg.g.n;
	  zx_FREE_cdm_KEYWORD(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CATEGORIES) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CATEGORIES_s* zx_NEW_cdm_CATEGORIES(struct zx_ctx* c)
{
  struct zx_cdm_CATEGORIES_s* x = ZX_ZALLOC(c, struct zx_cdm_CATEGORIES_s);
  x->gg.g.tok = zx_cdm_CATEGORIES_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CATEGORIES) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_KEYWORD_s* e;
      for (e = x->KEYWORD; e; e = (struct zx_cdm_KEYWORD_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_KEYWORD(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_CATEGORIES) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CATEGORIES_s* zx_DEEP_CLONE_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x, int dup_strs)
{
  x = (struct zx_cdm_CATEGORIES_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CATEGORIES_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_KEYWORD_s* e;
      struct zx_cdm_KEYWORD_s* en;
      struct zx_cdm_KEYWORD_s* enn;
      for (enn = 0, e = x->KEYWORD; e; e = (struct zx_cdm_KEYWORD_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_KEYWORD(c, e, dup_strs);
	  if (!enn)
	      x->KEYWORD = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_CATEGORIES) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_KEYWORD_s* e;
      for (e = x->KEYWORD; e; e = (struct zx_cdm_KEYWORD_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_KEYWORD(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_CATEGORIES) */

int zx_WALK_WO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CLASS
#define EL_STRUCT zx_cdm_CLASS_s
#define EL_NS     cdm
#define EL_TAG    CLASS

/* FUNC(zx_FREE_cdm_CLASS) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);

  zx_free_simple_elems(c, x->PUBLIC, free_strs);
  zx_free_simple_elems(c, x->PRIVATE, free_strs);
  zx_free_simple_elems(c, x->CONFIDENTIAL, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CLASS) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CLASS_s* zx_NEW_cdm_CLASS(struct zx_ctx* c)
{
  struct zx_cdm_CLASS_s* x = ZX_ZALLOC(c, struct zx_cdm_CLASS_s);
  x->gg.g.tok = zx_cdm_CLASS_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CLASS) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);

  zx_dup_strs_simple_elems(c, x->PUBLIC);
  zx_dup_strs_simple_elems(c, x->PRIVATE);
  zx_dup_strs_simple_elems(c, x->CONFIDENTIAL);

}

/* FUNC(zx_DEEP_CLONE_cdm_CLASS) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CLASS_s* zx_DEEP_CLONE_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x, int dup_strs)
{
  x = (struct zx_cdm_CLASS_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CLASS_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);

  x->PUBLIC = zx_deep_clone_simple_elems(c,x->PUBLIC, dup_strs);
  x->PRIVATE = zx_deep_clone_simple_elems(c,x->PRIVATE, dup_strs);
  x->CONFIDENTIAL = zx_deep_clone_simple_elems(c,x->CONFIDENTIAL, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_cdm_CLASS) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PUBLIC, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PRIVATE, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->CONFIDENTIAL, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_CLASS) */

int zx_WALK_WO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CRED
#define EL_STRUCT zx_cdm_CRED_s
#define EL_NS     cdm
#define EL_TAG    CRED

/* FUNC(zx_FREE_cdm_CRED) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CRED) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CRED_s* zx_NEW_cdm_CRED(struct zx_ctx* c)
{
  struct zx_cdm_CRED_s* x = ZX_ZALLOC(c, struct zx_cdm_CRED_s);
  x->gg.g.tok = zx_cdm_CRED_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CRED) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_CRED) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CRED_s* zx_DEEP_CLONE_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x, int dup_strs)
{
  x = (struct zx_cdm_CRED_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CRED_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_CRED) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_CRED) */

int zx_WALK_WO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_CTRY
#define EL_STRUCT zx_cdm_CTRY_s
#define EL_NS     cdm
#define EL_TAG    CTRY

/* FUNC(zx_FREE_cdm_CTRY) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_CTRY) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_CTRY_s* zx_NEW_cdm_CTRY(struct zx_ctx* c)
{
  struct zx_cdm_CTRY_s* x = ZX_ZALLOC(c, struct zx_cdm_CTRY_s);
  x->gg.g.tok = zx_cdm_CTRY_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_CTRY) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_CTRY) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_CTRY_s* zx_DEEP_CLONE_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x, int dup_strs)
{
  x = (struct zx_cdm_CTRY_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_CTRY_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_CTRY) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_CTRY) */

int zx_WALK_WO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_DESC
#define EL_STRUCT zx_cdm_DESC_s
#define EL_NS     cdm
#define EL_TAG    DESC

/* FUNC(zx_FREE_cdm_DESC) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_DESC) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_DESC_s* zx_NEW_cdm_DESC(struct zx_ctx* c)
{
  struct zx_cdm_DESC_s* x = ZX_ZALLOC(c, struct zx_cdm_DESC_s);
  x->gg.g.tok = zx_cdm_DESC_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_DESC) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_DESC) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_DESC_s* zx_DEEP_CLONE_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x, int dup_strs)
{
  x = (struct zx_cdm_DESC_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_DESC_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_DESC) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_DESC) */

int zx_WALK_WO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_EMAIL
#define EL_STRUCT zx_cdm_EMAIL_s
#define EL_NS     cdm
#define EL_TAG    EMAIL

/* FUNC(zx_FREE_cdm_EMAIL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  zx_free_simple_elems(c, x->HOME, free_strs);
  zx_free_simple_elems(c, x->WORK, free_strs);
  zx_free_simple_elems(c, x->INTERNET, free_strs);
  zx_free_simple_elems(c, x->PREF, free_strs);
  zx_free_simple_elems(c, x->X400, free_strs);
  {
      struct zx_cdm_USERID_s* e;
      struct zx_cdm_USERID_s* en;
      for (e = x->USERID; e; e = en) {
	  en = (struct zx_cdm_USERID_s*)e->gg.g.n;
	  zx_FREE_cdm_USERID(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_EMAIL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_EMAIL_s* zx_NEW_cdm_EMAIL(struct zx_ctx* c)
{
  struct zx_cdm_EMAIL_s* x = ZX_ZALLOC(c, struct zx_cdm_EMAIL_s);
  x->gg.g.tok = zx_cdm_EMAIL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_EMAIL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  zx_dup_strs_simple_elems(c, x->HOME);
  zx_dup_strs_simple_elems(c, x->WORK);
  zx_dup_strs_simple_elems(c, x->INTERNET);
  zx_dup_strs_simple_elems(c, x->PREF);
  zx_dup_strs_simple_elems(c, x->X400);
  {
      struct zx_cdm_USERID_s* e;
      for (e = x->USERID; e; e = (struct zx_cdm_USERID_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_USERID(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_EMAIL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_EMAIL_s* zx_DEEP_CLONE_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x, int dup_strs)
{
  x = (struct zx_cdm_EMAIL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_EMAIL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  x->HOME = zx_deep_clone_simple_elems(c,x->HOME, dup_strs);
  x->WORK = zx_deep_clone_simple_elems(c,x->WORK, dup_strs);
  x->INTERNET = zx_deep_clone_simple_elems(c,x->INTERNET, dup_strs);
  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  x->X400 = zx_deep_clone_simple_elems(c,x->X400, dup_strs);
  {
      struct zx_cdm_USERID_s* e;
      struct zx_cdm_USERID_s* en;
      struct zx_cdm_USERID_s* enn;
      for (enn = 0, e = x->USERID; e; e = (struct zx_cdm_USERID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_USERID(c, e, dup_strs);
	  if (!enn)
	      x->USERID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_EMAIL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->HOME, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->WORK, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->INTERNET, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->X400, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_USERID_s* e;
      for (e = x->USERID; e; e = (struct zx_cdm_USERID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_USERID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_EMAIL) */

int zx_WALK_WO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_EXTADR
#define EL_STRUCT zx_cdm_EXTADR_s
#define EL_NS     cdm
#define EL_TAG    EXTADR

/* FUNC(zx_FREE_cdm_EXTADR) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_EXTADR) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_EXTADR_s* zx_NEW_cdm_EXTADR(struct zx_ctx* c)
{
  struct zx_cdm_EXTADR_s* x = ZX_ZALLOC(c, struct zx_cdm_EXTADR_s);
  x->gg.g.tok = zx_cdm_EXTADR_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_EXTADR) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_EXTADR) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_EXTADR_s* zx_DEEP_CLONE_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x, int dup_strs)
{
  x = (struct zx_cdm_EXTADR_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_EXTADR_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_EXTADR) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_EXTADR) */

int zx_WALK_WO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_EXTVAL
#define EL_STRUCT zx_cdm_EXTVAL_s
#define EL_NS     cdm
#define EL_TAG    EXTVAL

/* FUNC(zx_FREE_cdm_EXTVAL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_EXTVAL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_EXTVAL_s* zx_NEW_cdm_EXTVAL(struct zx_ctx* c)
{
  struct zx_cdm_EXTVAL_s* x = ZX_ZALLOC(c, struct zx_cdm_EXTVAL_s);
  x->gg.g.tok = zx_cdm_EXTVAL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_EXTVAL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_EXTVAL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_EXTVAL_s* zx_DEEP_CLONE_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x, int dup_strs)
{
  x = (struct zx_cdm_EXTVAL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_EXTVAL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_EXTVAL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_EXTVAL) */

int zx_WALK_WO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_FAMILY
#define EL_STRUCT zx_cdm_FAMILY_s
#define EL_NS     cdm
#define EL_TAG    FAMILY

/* FUNC(zx_FREE_cdm_FAMILY) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_FAMILY) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_FAMILY_s* zx_NEW_cdm_FAMILY(struct zx_ctx* c)
{
  struct zx_cdm_FAMILY_s* x = ZX_ZALLOC(c, struct zx_cdm_FAMILY_s);
  x->gg.g.tok = zx_cdm_FAMILY_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_FAMILY) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_FAMILY) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_FAMILY_s* zx_DEEP_CLONE_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x, int dup_strs)
{
  x = (struct zx_cdm_FAMILY_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_FAMILY_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_FAMILY) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_FAMILY) */

int zx_WALK_WO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_FBURL
#define EL_STRUCT zx_cdm_FBURL_s
#define EL_NS     cdm
#define EL_TAG    FBURL

/* FUNC(zx_FREE_cdm_FBURL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);

  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      for (e = x->URI; e; e = en) {
	  en = (struct zx_cdm_URI_s*)e->gg.g.n;
	  zx_FREE_cdm_URI(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_FBURL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_FBURL_s* zx_NEW_cdm_FBURL(struct zx_ctx* c)
{
  struct zx_cdm_FBURL_s* x = ZX_ZALLOC(c, struct zx_cdm_FBURL_s);
  x->gg.g.tok = zx_cdm_FBURL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_FBURL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);

  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_URI(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_FBURL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_FBURL_s* zx_DEEP_CLONE_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x, int dup_strs)
{
  x = (struct zx_cdm_FBURL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_FBURL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);

  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_URI_s* e;
      struct zx_cdm_URI_s* en;
      struct zx_cdm_URI_s* enn;
      for (enn = 0, e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_URI(c, e, dup_strs);
	  if (!enn)
	      x->URI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_FBURL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_URI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_FBURL) */

int zx_WALK_WO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_FN
#define EL_STRUCT zx_cdm_FN_s
#define EL_NS     cdm
#define EL_TAG    FN

/* FUNC(zx_FREE_cdm_FN) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_FN) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_FN_s* zx_NEW_cdm_FN(struct zx_ctx* c)
{
  struct zx_cdm_FN_s* x = ZX_ZALLOC(c, struct zx_cdm_FN_s);
  x->gg.g.tok = zx_cdm_FN_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_FN) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_FN) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_FN_s* zx_DEEP_CLONE_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x, int dup_strs)
{
  x = (struct zx_cdm_FN_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_FN_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_FN) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_FN) */

int zx_WALK_WO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_GEO
#define EL_STRUCT zx_cdm_GEO_s
#define EL_NS     cdm
#define EL_TAG    GEO

/* FUNC(zx_FREE_cdm_GEO) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_LAT_s* e;
      struct zx_cdm_LAT_s* en;
      for (e = x->LAT; e; e = en) {
	  en = (struct zx_cdm_LAT_s*)e->gg.g.n;
	  zx_FREE_cdm_LAT(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_LON_s* e;
      struct zx_cdm_LON_s* en;
      for (e = x->LON; e; e = en) {
	  en = (struct zx_cdm_LON_s*)e->gg.g.n;
	  zx_FREE_cdm_LON(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_GEO) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_GEO_s* zx_NEW_cdm_GEO(struct zx_ctx* c)
{
  struct zx_cdm_GEO_s* x = ZX_ZALLOC(c, struct zx_cdm_GEO_s);
  x->gg.g.tok = zx_cdm_GEO_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_GEO) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_LAT_s* e;
      for (e = x->LAT; e; e = (struct zx_cdm_LAT_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LAT(c, e);
  }
  {
      struct zx_cdm_LON_s* e;
      for (e = x->LON; e; e = (struct zx_cdm_LON_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LON(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_GEO) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_GEO_s* zx_DEEP_CLONE_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x, int dup_strs)
{
  x = (struct zx_cdm_GEO_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_GEO_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_LAT_s* e;
      struct zx_cdm_LAT_s* en;
      struct zx_cdm_LAT_s* enn;
      for (enn = 0, e = x->LAT; e; e = (struct zx_cdm_LAT_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LAT(c, e, dup_strs);
	  if (!enn)
	      x->LAT = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_LON_s* e;
      struct zx_cdm_LON_s* en;
      struct zx_cdm_LON_s* enn;
      for (enn = 0, e = x->LON; e; e = (struct zx_cdm_LON_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LON(c, e, dup_strs);
	  if (!enn)
	      x->LON = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_GEO) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_LAT_s* e;
      for (e = x->LAT; e; e = (struct zx_cdm_LAT_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LAT(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_LON_s* e;
      for (e = x->LON; e; e = (struct zx_cdm_LON_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LON(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_GEO) */

int zx_WALK_WO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_GIVEN
#define EL_STRUCT zx_cdm_GIVEN_s
#define EL_NS     cdm
#define EL_TAG    GIVEN

/* FUNC(zx_FREE_cdm_GIVEN) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_GIVEN) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_GIVEN_s* zx_NEW_cdm_GIVEN(struct zx_ctx* c)
{
  struct zx_cdm_GIVEN_s* x = ZX_ZALLOC(c, struct zx_cdm_GIVEN_s);
  x->gg.g.tok = zx_cdm_GIVEN_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_GIVEN) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_GIVEN) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_GIVEN_s* zx_DEEP_CLONE_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x, int dup_strs)
{
  x = (struct zx_cdm_GIVEN_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_GIVEN_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_GIVEN) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_GIVEN) */

int zx_WALK_WO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_JABBERID
#define EL_STRUCT zx_cdm_JABBERID_s
#define EL_NS     cdm
#define EL_TAG    JABBERID

/* FUNC(zx_FREE_cdm_JABBERID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_JABBERID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_JABBERID_s* zx_NEW_cdm_JABBERID(struct zx_ctx* c)
{
  struct zx_cdm_JABBERID_s* x = ZX_ZALLOC(c, struct zx_cdm_JABBERID_s);
  x->gg.g.tok = zx_cdm_JABBERID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_JABBERID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_JABBERID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_JABBERID_s* zx_DEEP_CLONE_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x, int dup_strs)
{
  x = (struct zx_cdm_JABBERID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_JABBERID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_JABBERID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_JABBERID) */

int zx_WALK_WO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_KEY
#define EL_STRUCT zx_cdm_KEY_s
#define EL_NS     cdm
#define EL_TAG    KEY

/* FUNC(zx_FREE_cdm_KEY) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_cdm_TYPE_s* e;
      struct zx_cdm_TYPE_s* en;
      for (e = x->TYPE; e; e = en) {
	  en = (struct zx_cdm_TYPE_s*)e->gg.g.n;
	  zx_FREE_cdm_TYPE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CRED_s* e;
      struct zx_cdm_CRED_s* en;
      for (e = x->CRED; e; e = en) {
	  en = (struct zx_cdm_CRED_s*)e->gg.g.n;
	  zx_FREE_cdm_CRED(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_KEY) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_KEY_s* zx_NEW_cdm_KEY(struct zx_ctx* c)
{
  struct zx_cdm_KEY_s* x = ZX_ZALLOC(c, struct zx_cdm_KEY_s);
  x->gg.g.tok = zx_cdm_KEY_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_KEY) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_CRED_s* e;
      for (e = x->CRED; e; e = (struct zx_cdm_CRED_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CRED(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_KEY) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_KEY_s* zx_DEEP_CLONE_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x, int dup_strs)
{
  x = (struct zx_cdm_KEY_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_KEY_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_cdm_TYPE_s* e;
      struct zx_cdm_TYPE_s* en;
      struct zx_cdm_TYPE_s* enn;
      for (enn = 0, e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_TYPE(c, e, dup_strs);
	  if (!enn)
	      x->TYPE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CRED_s* e;
      struct zx_cdm_CRED_s* en;
      struct zx_cdm_CRED_s* enn;
      for (enn = 0, e = x->CRED; e; e = (struct zx_cdm_CRED_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CRED(c, e, dup_strs);
	  if (!enn)
	      x->CRED = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_KEY) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_TYPE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CRED_s* e;
      for (e = x->CRED; e; e = (struct zx_cdm_CRED_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CRED(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_KEY) */

int zx_WALK_WO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_KEYWORD
#define EL_STRUCT zx_cdm_KEYWORD_s
#define EL_NS     cdm
#define EL_TAG    KEYWORD

/* FUNC(zx_FREE_cdm_KEYWORD) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_KEYWORD) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_KEYWORD_s* zx_NEW_cdm_KEYWORD(struct zx_ctx* c)
{
  struct zx_cdm_KEYWORD_s* x = ZX_ZALLOC(c, struct zx_cdm_KEYWORD_s);
  x->gg.g.tok = zx_cdm_KEYWORD_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_KEYWORD) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_KEYWORD) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_KEYWORD_s* zx_DEEP_CLONE_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x, int dup_strs)
{
  x = (struct zx_cdm_KEYWORD_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_KEYWORD_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_KEYWORD) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_KEYWORD) */

int zx_WALK_WO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LABEL
#define EL_STRUCT zx_cdm_LABEL_s
#define EL_NS     cdm
#define EL_TAG    LABEL

/* FUNC(zx_FREE_cdm_LABEL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  zx_free_simple_elems(c, x->HOME, free_strs);
  zx_free_simple_elems(c, x->WORK, free_strs);
  zx_free_simple_elems(c, x->POSTAL, free_strs);
  zx_free_simple_elems(c, x->PARCEL, free_strs);
  zx_free_simple_elems(c, x->DOM, free_strs);
  zx_free_simple_elems(c, x->INTL, free_strs);
  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_LINE_s* e;
      struct zx_cdm_LINE_s* en;
      for (e = x->LINE; e; e = en) {
	  en = (struct zx_cdm_LINE_s*)e->gg.g.n;
	  zx_FREE_cdm_LINE(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LABEL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LABEL_s* zx_NEW_cdm_LABEL(struct zx_ctx* c)
{
  struct zx_cdm_LABEL_s* x = ZX_ZALLOC(c, struct zx_cdm_LABEL_s);
  x->gg.g.tok = zx_cdm_LABEL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LABEL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  zx_dup_strs_simple_elems(c, x->HOME);
  zx_dup_strs_simple_elems(c, x->WORK);
  zx_dup_strs_simple_elems(c, x->POSTAL);
  zx_dup_strs_simple_elems(c, x->PARCEL);
  zx_dup_strs_simple_elems(c, x->DOM);
  zx_dup_strs_simple_elems(c, x->INTL);
  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_LINE_s* e;
      for (e = x->LINE; e; e = (struct zx_cdm_LINE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LINE(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_LABEL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LABEL_s* zx_DEEP_CLONE_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x, int dup_strs)
{
  x = (struct zx_cdm_LABEL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LABEL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  x->HOME = zx_deep_clone_simple_elems(c,x->HOME, dup_strs);
  x->WORK = zx_deep_clone_simple_elems(c,x->WORK, dup_strs);
  x->POSTAL = zx_deep_clone_simple_elems(c,x->POSTAL, dup_strs);
  x->PARCEL = zx_deep_clone_simple_elems(c,x->PARCEL, dup_strs);
  x->DOM = zx_deep_clone_simple_elems(c,x->DOM, dup_strs);
  x->INTL = zx_deep_clone_simple_elems(c,x->INTL, dup_strs);
  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_LINE_s* e;
      struct zx_cdm_LINE_s* en;
      struct zx_cdm_LINE_s* enn;
      for (enn = 0, e = x->LINE; e; e = (struct zx_cdm_LINE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LINE(c, e, dup_strs);
	  if (!enn)
	      x->LINE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_LABEL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->HOME, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->WORK, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->POSTAL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PARCEL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DOM, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->INTL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_LINE_s* e;
      for (e = x->LINE; e; e = (struct zx_cdm_LINE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LINE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_LABEL) */

int zx_WALK_WO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LAT
#define EL_STRUCT zx_cdm_LAT_s
#define EL_NS     cdm
#define EL_TAG    LAT

/* FUNC(zx_FREE_cdm_LAT) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LAT) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LAT_s* zx_NEW_cdm_LAT(struct zx_ctx* c)
{
  struct zx_cdm_LAT_s* x = ZX_ZALLOC(c, struct zx_cdm_LAT_s);
  x->gg.g.tok = zx_cdm_LAT_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LAT) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_LAT) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LAT_s* zx_DEEP_CLONE_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x, int dup_strs)
{
  x = (struct zx_cdm_LAT_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LAT_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_LAT) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_LAT) */

int zx_WALK_WO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LINE
#define EL_STRUCT zx_cdm_LINE_s
#define EL_NS     cdm
#define EL_TAG    LINE

/* FUNC(zx_FREE_cdm_LINE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LINE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LINE_s* zx_NEW_cdm_LINE(struct zx_ctx* c)
{
  struct zx_cdm_LINE_s* x = ZX_ZALLOC(c, struct zx_cdm_LINE_s);
  x->gg.g.tok = zx_cdm_LINE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LINE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_LINE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LINE_s* zx_DEEP_CLONE_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x, int dup_strs)
{
  x = (struct zx_cdm_LINE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LINE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_LINE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_LINE) */

int zx_WALK_WO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LISTMEMBER
#define EL_STRUCT zx_cdm_LISTMEMBER_s
#define EL_NS     cdm
#define EL_TAG    LISTMEMBER

/* FUNC(zx_FREE_cdm_LISTMEMBER) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LISTMEMBER) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LISTMEMBER_s* zx_NEW_cdm_LISTMEMBER(struct zx_ctx* c)
{
  struct zx_cdm_LISTMEMBER_s* x = ZX_ZALLOC(c, struct zx_cdm_LISTMEMBER_s);
  x->gg.g.tok = zx_cdm_LISTMEMBER_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LISTMEMBER) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_LISTMEMBER) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LISTMEMBER_s* zx_DEEP_CLONE_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x, int dup_strs)
{
  x = (struct zx_cdm_LISTMEMBER_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LISTMEMBER_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_LISTMEMBER) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_LISTMEMBER) */

int zx_WALK_WO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LOCALITY
#define EL_STRUCT zx_cdm_LOCALITY_s
#define EL_NS     cdm
#define EL_TAG    LOCALITY

/* FUNC(zx_FREE_cdm_LOCALITY) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LOCALITY) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LOCALITY_s* zx_NEW_cdm_LOCALITY(struct zx_ctx* c)
{
  struct zx_cdm_LOCALITY_s* x = ZX_ZALLOC(c, struct zx_cdm_LOCALITY_s);
  x->gg.g.tok = zx_cdm_LOCALITY_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LOCALITY) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_LOCALITY) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LOCALITY_s* zx_DEEP_CLONE_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x, int dup_strs)
{
  x = (struct zx_cdm_LOCALITY_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LOCALITY_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_LOCALITY) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_LOCALITY) */

int zx_WALK_WO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LOGO
#define EL_STRUCT zx_cdm_LOGO_s
#define EL_NS     cdm
#define EL_TAG    LOGO

/* FUNC(zx_FREE_cdm_LOGO) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_TYPE_s* e;
      struct zx_cdm_TYPE_s* en;
      for (e = x->TYPE; e; e = en) {
	  en = (struct zx_cdm_TYPE_s*)e->gg.g.n;
	  zx_FREE_cdm_TYPE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      struct zx_cdm_BINVAL_s* en;
      for (e = x->BINVAL; e; e = en) {
	  en = (struct zx_cdm_BINVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_BINVAL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      for (e = x->EXTVAL; e; e = en) {
	  en = (struct zx_cdm_EXTVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_EXTVAL(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LOGO) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LOGO_s* zx_NEW_cdm_LOGO(struct zx_ctx* c)
{
  struct zx_cdm_LOGO_s* x = ZX_ZALLOC(c, struct zx_cdm_LOGO_s);
  x->gg.g.tok = zx_cdm_LOGO_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LOGO) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_EXTVAL(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_LOGO) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LOGO_s* zx_DEEP_CLONE_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x, int dup_strs)
{
  x = (struct zx_cdm_LOGO_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LOGO_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_TYPE_s* e;
      struct zx_cdm_TYPE_s* en;
      struct zx_cdm_TYPE_s* enn;
      for (enn = 0, e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_TYPE(c, e, dup_strs);
	  if (!enn)
	      x->TYPE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      struct zx_cdm_BINVAL_s* en;
      struct zx_cdm_BINVAL_s* enn;
      for (enn = 0, e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_BINVAL(c, e, dup_strs);
	  if (!enn)
	      x->BINVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      struct zx_cdm_EXTVAL_s* enn;
      for (enn = 0, e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_EXTVAL(c, e, dup_strs);
	  if (!enn)
	      x->EXTVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_LOGO) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_TYPE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_BINVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_EXTVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_LOGO) */

int zx_WALK_WO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_LON
#define EL_STRUCT zx_cdm_LON_s
#define EL_NS     cdm
#define EL_TAG    LON

/* FUNC(zx_FREE_cdm_LON) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_LON) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_LON_s* zx_NEW_cdm_LON(struct zx_ctx* c)
{
  struct zx_cdm_LON_s* x = ZX_ZALLOC(c, struct zx_cdm_LON_s);
  x->gg.g.tok = zx_cdm_LON_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_LON) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_LON) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_LON_s* zx_DEEP_CLONE_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x, int dup_strs)
{
  x = (struct zx_cdm_LON_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_LON_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_LON) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_LON) */

int zx_WALK_WO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_MAILER
#define EL_STRUCT zx_cdm_MAILER_s
#define EL_NS     cdm
#define EL_TAG    MAILER

/* FUNC(zx_FREE_cdm_MAILER) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_MAILER) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_MAILER_s* zx_NEW_cdm_MAILER(struct zx_ctx* c)
{
  struct zx_cdm_MAILER_s* x = ZX_ZALLOC(c, struct zx_cdm_MAILER_s);
  x->gg.g.tok = zx_cdm_MAILER_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_MAILER) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_MAILER) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_MAILER_s* zx_DEEP_CLONE_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x, int dup_strs)
{
  x = (struct zx_cdm_MAILER_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_MAILER_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_MAILER) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_MAILER) */

int zx_WALK_WO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_MIDDLE
#define EL_STRUCT zx_cdm_MIDDLE_s
#define EL_NS     cdm
#define EL_TAG    MIDDLE

/* FUNC(zx_FREE_cdm_MIDDLE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_MIDDLE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_MIDDLE_s* zx_NEW_cdm_MIDDLE(struct zx_ctx* c)
{
  struct zx_cdm_MIDDLE_s* x = ZX_ZALLOC(c, struct zx_cdm_MIDDLE_s);
  x->gg.g.tok = zx_cdm_MIDDLE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_MIDDLE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_MIDDLE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_MIDDLE_s* zx_DEEP_CLONE_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x, int dup_strs)
{
  x = (struct zx_cdm_MIDDLE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_MIDDLE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_MIDDLE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_MIDDLE) */

int zx_WALK_WO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_N
#define EL_STRUCT zx_cdm_N_s
#define EL_NS     cdm
#define EL_TAG    N

/* FUNC(zx_FREE_cdm_N) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_FAMILY_s* e;
      struct zx_cdm_FAMILY_s* en;
      for (e = x->FAMILY; e; e = en) {
	  en = (struct zx_cdm_FAMILY_s*)e->gg.g.n;
	  zx_FREE_cdm_FAMILY(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_GIVEN_s* e;
      struct zx_cdm_GIVEN_s* en;
      for (e = x->GIVEN; e; e = en) {
	  en = (struct zx_cdm_GIVEN_s*)e->gg.g.n;
	  zx_FREE_cdm_GIVEN(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      struct zx_cdm_MIDDLE_s* en;
      for (e = x->MIDDLE; e; e = en) {
	  en = (struct zx_cdm_MIDDLE_s*)e->gg.g.n;
	  zx_FREE_cdm_MIDDLE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_PREFIX_s* e;
      struct zx_cdm_PREFIX_s* en;
      for (e = x->PREFIX; e; e = en) {
	  en = (struct zx_cdm_PREFIX_s*)e->gg.g.n;
	  zx_FREE_cdm_PREFIX(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      struct zx_cdm_SUFFIX_s* en;
      for (e = x->SUFFIX; e; e = en) {
	  en = (struct zx_cdm_SUFFIX_s*)e->gg.g.n;
	  zx_FREE_cdm_SUFFIX(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_N) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_N_s* zx_NEW_cdm_N(struct zx_ctx* c)
{
  struct zx_cdm_N_s* x = ZX_ZALLOC(c, struct zx_cdm_N_s);
  x->gg.g.tok = zx_cdm_N_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_N) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_FAMILY_s* e;
      for (e = x->FAMILY; e; e = (struct zx_cdm_FAMILY_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_FAMILY(c, e);
  }
  {
      struct zx_cdm_GIVEN_s* e;
      for (e = x->GIVEN; e; e = (struct zx_cdm_GIVEN_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_GIVEN(c, e);
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      for (e = x->MIDDLE; e; e = (struct zx_cdm_MIDDLE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_MIDDLE(c, e);
  }
  {
      struct zx_cdm_PREFIX_s* e;
      for (e = x->PREFIX; e; e = (struct zx_cdm_PREFIX_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_PREFIX(c, e);
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      for (e = x->SUFFIX; e; e = (struct zx_cdm_SUFFIX_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_SUFFIX(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_N) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_N_s* zx_DEEP_CLONE_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x, int dup_strs)
{
  x = (struct zx_cdm_N_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_N_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_FAMILY_s* e;
      struct zx_cdm_FAMILY_s* en;
      struct zx_cdm_FAMILY_s* enn;
      for (enn = 0, e = x->FAMILY; e; e = (struct zx_cdm_FAMILY_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_FAMILY(c, e, dup_strs);
	  if (!enn)
	      x->FAMILY = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_GIVEN_s* e;
      struct zx_cdm_GIVEN_s* en;
      struct zx_cdm_GIVEN_s* enn;
      for (enn = 0, e = x->GIVEN; e; e = (struct zx_cdm_GIVEN_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_GIVEN(c, e, dup_strs);
	  if (!enn)
	      x->GIVEN = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      struct zx_cdm_MIDDLE_s* en;
      struct zx_cdm_MIDDLE_s* enn;
      for (enn = 0, e = x->MIDDLE; e; e = (struct zx_cdm_MIDDLE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_MIDDLE(c, e, dup_strs);
	  if (!enn)
	      x->MIDDLE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_PREFIX_s* e;
      struct zx_cdm_PREFIX_s* en;
      struct zx_cdm_PREFIX_s* enn;
      for (enn = 0, e = x->PREFIX; e; e = (struct zx_cdm_PREFIX_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_PREFIX(c, e, dup_strs);
	  if (!enn)
	      x->PREFIX = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      struct zx_cdm_SUFFIX_s* en;
      struct zx_cdm_SUFFIX_s* enn;
      for (enn = 0, e = x->SUFFIX; e; e = (struct zx_cdm_SUFFIX_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_SUFFIX(c, e, dup_strs);
	  if (!enn)
	      x->SUFFIX = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_N) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_FAMILY_s* e;
      for (e = x->FAMILY; e; e = (struct zx_cdm_FAMILY_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_FAMILY(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_GIVEN_s* e;
      for (e = x->GIVEN; e; e = (struct zx_cdm_GIVEN_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_GIVEN(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      for (e = x->MIDDLE; e; e = (struct zx_cdm_MIDDLE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_MIDDLE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_PREFIX_s* e;
      for (e = x->PREFIX; e; e = (struct zx_cdm_PREFIX_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_PREFIX(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      for (e = x->SUFFIX; e; e = (struct zx_cdm_SUFFIX_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_SUFFIX(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_N) */

int zx_WALK_WO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_NICKNAME
#define EL_STRUCT zx_cdm_NICKNAME_s
#define EL_NS     cdm
#define EL_TAG    NICKNAME

/* FUNC(zx_FREE_cdm_NICKNAME) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_NICKNAME) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_NICKNAME_s* zx_NEW_cdm_NICKNAME(struct zx_ctx* c)
{
  struct zx_cdm_NICKNAME_s* x = ZX_ZALLOC(c, struct zx_cdm_NICKNAME_s);
  x->gg.g.tok = zx_cdm_NICKNAME_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_NICKNAME) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_NICKNAME) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_NICKNAME_s* zx_DEEP_CLONE_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x, int dup_strs)
{
  x = (struct zx_cdm_NICKNAME_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_NICKNAME_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_NICKNAME) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_NICKNAME) */

int zx_WALK_WO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_NOTE
#define EL_STRUCT zx_cdm_NOTE_s
#define EL_NS     cdm
#define EL_TAG    NOTE

/* FUNC(zx_FREE_cdm_NOTE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_NOTE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_NOTE_s* zx_NEW_cdm_NOTE(struct zx_ctx* c)
{
  struct zx_cdm_NOTE_s* x = ZX_ZALLOC(c, struct zx_cdm_NOTE_s);
  x->gg.g.tok = zx_cdm_NOTE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_NOTE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_NOTE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_NOTE_s* zx_DEEP_CLONE_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x, int dup_strs)
{
  x = (struct zx_cdm_NOTE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_NOTE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_NOTE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_NOTE) */

int zx_WALK_WO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_NUMBER
#define EL_STRUCT zx_cdm_NUMBER_s
#define EL_NS     cdm
#define EL_TAG    NUMBER

/* FUNC(zx_FREE_cdm_NUMBER) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_NUMBER) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_NUMBER_s* zx_NEW_cdm_NUMBER(struct zx_ctx* c)
{
  struct zx_cdm_NUMBER_s* x = ZX_ZALLOC(c, struct zx_cdm_NUMBER_s);
  x->gg.g.tok = zx_cdm_NUMBER_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_NUMBER) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_NUMBER) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_NUMBER_s* zx_DEEP_CLONE_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x, int dup_strs)
{
  x = (struct zx_cdm_NUMBER_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_NUMBER_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_NUMBER) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_NUMBER) */

int zx_WALK_WO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_ORG
#define EL_STRUCT zx_cdm_ORG_s
#define EL_NS     cdm
#define EL_TAG    ORG

/* FUNC(zx_FREE_cdm_ORG) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_ORGNAME_s* e;
      struct zx_cdm_ORGNAME_s* en;
      for (e = x->ORGNAME; e; e = en) {
	  en = (struct zx_cdm_ORGNAME_s*)e->gg.g.n;
	  zx_FREE_cdm_ORGNAME(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      struct zx_cdm_ORGUNIT_s* en;
      for (e = x->ORGUNIT; e; e = en) {
	  en = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n;
	  zx_FREE_cdm_ORGUNIT(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_ORG) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_ORG_s* zx_NEW_cdm_ORG(struct zx_ctx* c)
{
  struct zx_cdm_ORG_s* x = ZX_ZALLOC(c, struct zx_cdm_ORG_s);
  x->gg.g.tok = zx_cdm_ORG_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_ORG) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_ORGNAME_s* e;
      for (e = x->ORGNAME; e; e = (struct zx_cdm_ORGNAME_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_ORGNAME(c, e);
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      for (e = x->ORGUNIT; e; e = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_ORGUNIT(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_ORG) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_ORG_s* zx_DEEP_CLONE_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x, int dup_strs)
{
  x = (struct zx_cdm_ORG_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_ORG_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_ORGNAME_s* e;
      struct zx_cdm_ORGNAME_s* en;
      struct zx_cdm_ORGNAME_s* enn;
      for (enn = 0, e = x->ORGNAME; e; e = (struct zx_cdm_ORGNAME_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_ORGNAME(c, e, dup_strs);
	  if (!enn)
	      x->ORGNAME = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      struct zx_cdm_ORGUNIT_s* en;
      struct zx_cdm_ORGUNIT_s* enn;
      for (enn = 0, e = x->ORGUNIT; e; e = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_ORGUNIT(c, e, dup_strs);
	  if (!enn)
	      x->ORGUNIT = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_ORG) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_ORGNAME_s* e;
      for (e = x->ORGNAME; e; e = (struct zx_cdm_ORGNAME_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_ORGNAME(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      for (e = x->ORGUNIT; e; e = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_ORGUNIT(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_ORG) */

int zx_WALK_WO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_ORGNAME
#define EL_STRUCT zx_cdm_ORGNAME_s
#define EL_NS     cdm
#define EL_TAG    ORGNAME

/* FUNC(zx_FREE_cdm_ORGNAME) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_ORGNAME) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_ORGNAME_s* zx_NEW_cdm_ORGNAME(struct zx_ctx* c)
{
  struct zx_cdm_ORGNAME_s* x = ZX_ZALLOC(c, struct zx_cdm_ORGNAME_s);
  x->gg.g.tok = zx_cdm_ORGNAME_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_ORGNAME) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_ORGNAME) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_ORGNAME_s* zx_DEEP_CLONE_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x, int dup_strs)
{
  x = (struct zx_cdm_ORGNAME_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_ORGNAME_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_ORGNAME) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_ORGNAME) */

int zx_WALK_WO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_ORGUNIT
#define EL_STRUCT zx_cdm_ORGUNIT_s
#define EL_NS     cdm
#define EL_TAG    ORGUNIT

/* FUNC(zx_FREE_cdm_ORGUNIT) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_ORGUNIT) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_ORGUNIT_s* zx_NEW_cdm_ORGUNIT(struct zx_ctx* c)
{
  struct zx_cdm_ORGUNIT_s* x = ZX_ZALLOC(c, struct zx_cdm_ORGUNIT_s);
  x->gg.g.tok = zx_cdm_ORGUNIT_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_ORGUNIT) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_ORGUNIT) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_ORGUNIT_s* zx_DEEP_CLONE_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x, int dup_strs)
{
  x = (struct zx_cdm_ORGUNIT_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_ORGUNIT_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_ORGUNIT) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_ORGUNIT) */

int zx_WALK_WO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_PCODE
#define EL_STRUCT zx_cdm_PCODE_s
#define EL_NS     cdm
#define EL_TAG    PCODE

/* FUNC(zx_FREE_cdm_PCODE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_PCODE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_PCODE_s* zx_NEW_cdm_PCODE(struct zx_ctx* c)
{
  struct zx_cdm_PCODE_s* x = ZX_ZALLOC(c, struct zx_cdm_PCODE_s);
  x->gg.g.tok = zx_cdm_PCODE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_PCODE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_PCODE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_PCODE_s* zx_DEEP_CLONE_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x, int dup_strs)
{
  x = (struct zx_cdm_PCODE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_PCODE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_PCODE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_PCODE) */

int zx_WALK_WO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_PHONETIC
#define EL_STRUCT zx_cdm_PHONETIC_s
#define EL_NS     cdm
#define EL_TAG    PHONETIC

/* FUNC(zx_FREE_cdm_PHONETIC) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_PHONETIC) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_PHONETIC_s* zx_NEW_cdm_PHONETIC(struct zx_ctx* c)
{
  struct zx_cdm_PHONETIC_s* x = ZX_ZALLOC(c, struct zx_cdm_PHONETIC_s);
  x->gg.g.tok = zx_cdm_PHONETIC_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_PHONETIC) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_PHONETIC) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_PHONETIC_s* zx_DEEP_CLONE_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x, int dup_strs)
{
  x = (struct zx_cdm_PHONETIC_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_PHONETIC_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_PHONETIC) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_PHONETIC) */

int zx_WALK_WO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_PHOTO
#define EL_STRUCT zx_cdm_PHOTO_s
#define EL_NS     cdm
#define EL_TAG    PHOTO

/* FUNC(zx_FREE_cdm_PHOTO) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_TYPE_s* e;
      struct zx_cdm_TYPE_s* en;
      for (e = x->TYPE; e; e = en) {
	  en = (struct zx_cdm_TYPE_s*)e->gg.g.n;
	  zx_FREE_cdm_TYPE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      struct zx_cdm_BINVAL_s* en;
      for (e = x->BINVAL; e; e = en) {
	  en = (struct zx_cdm_BINVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_BINVAL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      for (e = x->EXTVAL; e; e = en) {
	  en = (struct zx_cdm_EXTVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_EXTVAL(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_PHOTO) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_PHOTO_s* zx_NEW_cdm_PHOTO(struct zx_ctx* c)
{
  struct zx_cdm_PHOTO_s* x = ZX_ZALLOC(c, struct zx_cdm_PHOTO_s);
  x->gg.g.tok = zx_cdm_PHOTO_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_PHOTO) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_EXTVAL(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_PHOTO) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_PHOTO_s* zx_DEEP_CLONE_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x, int dup_strs)
{
  x = (struct zx_cdm_PHOTO_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_PHOTO_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_TYPE_s* e;
      struct zx_cdm_TYPE_s* en;
      struct zx_cdm_TYPE_s* enn;
      for (enn = 0, e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_TYPE(c, e, dup_strs);
	  if (!enn)
	      x->TYPE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      struct zx_cdm_BINVAL_s* en;
      struct zx_cdm_BINVAL_s* enn;
      for (enn = 0, e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_BINVAL(c, e, dup_strs);
	  if (!enn)
	      x->BINVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      struct zx_cdm_EXTVAL_s* enn;
      for (enn = 0, e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_EXTVAL(c, e, dup_strs);
	  if (!enn)
	      x->EXTVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_PHOTO) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_TYPE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_BINVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_EXTVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_PHOTO) */

int zx_WALK_WO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_PHYSICALACCESS
#define EL_STRUCT zx_cdm_PHYSICALACCESS_s
#define EL_NS     cdm
#define EL_TAG    PHYSICALACCESS

/* FUNC(zx_FREE_cdm_PHYSICALACCESS) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_PHYSICALACCESS) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_PHYSICALACCESS_s* zx_NEW_cdm_PHYSICALACCESS(struct zx_ctx* c)
{
  struct zx_cdm_PHYSICALACCESS_s* x = ZX_ZALLOC(c, struct zx_cdm_PHYSICALACCESS_s);
  x->gg.g.tok = zx_cdm_PHYSICALACCESS_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_PHYSICALACCESS) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_PHYSICALACCESS) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_PHYSICALACCESS_s* zx_DEEP_CLONE_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x, int dup_strs)
{
  x = (struct zx_cdm_PHYSICALACCESS_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_PHYSICALACCESS_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_PHYSICALACCESS) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_PHYSICALACCESS) */

int zx_WALK_WO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_POBOX
#define EL_STRUCT zx_cdm_POBOX_s
#define EL_NS     cdm
#define EL_TAG    POBOX

/* FUNC(zx_FREE_cdm_POBOX) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_POBOX) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_POBOX_s* zx_NEW_cdm_POBOX(struct zx_ctx* c)
{
  struct zx_cdm_POBOX_s* x = ZX_ZALLOC(c, struct zx_cdm_POBOX_s);
  x->gg.g.tok = zx_cdm_POBOX_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_POBOX) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_POBOX) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_POBOX_s* zx_DEEP_CLONE_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x, int dup_strs)
{
  x = (struct zx_cdm_POBOX_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_POBOX_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_POBOX) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_POBOX) */

int zx_WALK_WO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_PREFIX
#define EL_STRUCT zx_cdm_PREFIX_s
#define EL_NS     cdm
#define EL_TAG    PREFIX

/* FUNC(zx_FREE_cdm_PREFIX) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_PREFIX) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_PREFIX_s* zx_NEW_cdm_PREFIX(struct zx_ctx* c)
{
  struct zx_cdm_PREFIX_s* x = ZX_ZALLOC(c, struct zx_cdm_PREFIX_s);
  x->gg.g.tok = zx_cdm_PREFIX_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_PREFIX) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_PREFIX) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_PREFIX_s* zx_DEEP_CLONE_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x, int dup_strs)
{
  x = (struct zx_cdm_PREFIX_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_PREFIX_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_PREFIX) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_PREFIX) */

int zx_WALK_WO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_PRODID
#define EL_STRUCT zx_cdm_PRODID_s
#define EL_NS     cdm
#define EL_TAG    PRODID

/* FUNC(zx_FREE_cdm_PRODID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_PRODID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_PRODID_s* zx_NEW_cdm_PRODID(struct zx_ctx* c)
{
  struct zx_cdm_PRODID_s* x = ZX_ZALLOC(c, struct zx_cdm_PRODID_s);
  x->gg.g.tok = zx_cdm_PRODID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_PRODID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_PRODID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_PRODID_s* zx_DEEP_CLONE_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x, int dup_strs)
{
  x = (struct zx_cdm_PRODID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_PRODID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_PRODID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_PRODID) */

int zx_WALK_WO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_REGION
#define EL_STRUCT zx_cdm_REGION_s
#define EL_NS     cdm
#define EL_TAG    REGION

/* FUNC(zx_FREE_cdm_REGION) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_REGION) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_REGION_s* zx_NEW_cdm_REGION(struct zx_ctx* c)
{
  struct zx_cdm_REGION_s* x = ZX_ZALLOC(c, struct zx_cdm_REGION_s);
  x->gg.g.tok = zx_cdm_REGION_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_REGION) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_REGION) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_REGION_s* zx_DEEP_CLONE_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x, int dup_strs)
{
  x = (struct zx_cdm_REGION_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_REGION_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_REGION) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_REGION) */

int zx_WALK_WO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_REV
#define EL_STRUCT zx_cdm_REV_s
#define EL_NS     cdm
#define EL_TAG    REV

/* FUNC(zx_FREE_cdm_REV) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_REV) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_REV_s* zx_NEW_cdm_REV(struct zx_ctx* c)
{
  struct zx_cdm_REV_s* x = ZX_ZALLOC(c, struct zx_cdm_REV_s);
  x->gg.g.tok = zx_cdm_REV_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_REV) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_REV) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_REV_s* zx_DEEP_CLONE_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x, int dup_strs)
{
  x = (struct zx_cdm_REV_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_REV_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_REV) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_REV) */

int zx_WALK_WO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_ROLE
#define EL_STRUCT zx_cdm_ROLE_s
#define EL_NS     cdm
#define EL_TAG    ROLE

/* FUNC(zx_FREE_cdm_ROLE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_ROLE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_ROLE_s* zx_NEW_cdm_ROLE(struct zx_ctx* c)
{
  struct zx_cdm_ROLE_s* x = ZX_ZALLOC(c, struct zx_cdm_ROLE_s);
  x->gg.g.tok = zx_cdm_ROLE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_ROLE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_ROLE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_ROLE_s* zx_DEEP_CLONE_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x, int dup_strs)
{
  x = (struct zx_cdm_ROLE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_ROLE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_ROLE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_ROLE) */

int zx_WALK_WO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_SORT_STRING
#define EL_STRUCT zx_cdm_SORT_STRING_s
#define EL_NS     cdm
#define EL_TAG    SORT_STRING

/* FUNC(zx_FREE_cdm_SORT_STRING) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_SORT_STRING) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_SORT_STRING_s* zx_NEW_cdm_SORT_STRING(struct zx_ctx* c)
{
  struct zx_cdm_SORT_STRING_s* x = ZX_ZALLOC(c, struct zx_cdm_SORT_STRING_s);
  x->gg.g.tok = zx_cdm_SORT_STRING_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_SORT_STRING) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_SORT_STRING) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_SORT_STRING_s* zx_DEEP_CLONE_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x, int dup_strs)
{
  x = (struct zx_cdm_SORT_STRING_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_SORT_STRING_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_SORT_STRING) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_SORT_STRING) */

int zx_WALK_WO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_SOUND
#define EL_STRUCT zx_cdm_SOUND_s
#define EL_NS     cdm
#define EL_TAG    SOUND

/* FUNC(zx_FREE_cdm_SOUND) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_PHONETIC_s* e;
      struct zx_cdm_PHONETIC_s* en;
      for (e = x->PHONETIC; e; e = en) {
	  en = (struct zx_cdm_PHONETIC_s*)e->gg.g.n;
	  zx_FREE_cdm_PHONETIC(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      struct zx_cdm_BINVAL_s* en;
      for (e = x->BINVAL; e; e = en) {
	  en = (struct zx_cdm_BINVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_BINVAL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      for (e = x->EXTVAL; e; e = en) {
	  en = (struct zx_cdm_EXTVAL_s*)e->gg.g.n;
	  zx_FREE_cdm_EXTVAL(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_SOUND) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_SOUND_s* zx_NEW_cdm_SOUND(struct zx_ctx* c)
{
  struct zx_cdm_SOUND_s* x = ZX_ZALLOC(c, struct zx_cdm_SOUND_s);
  x->gg.g.tok = zx_cdm_SOUND_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_SOUND) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_PHONETIC_s* e;
      for (e = x->PHONETIC; e; e = (struct zx_cdm_PHONETIC_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_PHONETIC(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_EXTVAL(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_SOUND) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_SOUND_s* zx_DEEP_CLONE_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x, int dup_strs)
{
  x = (struct zx_cdm_SOUND_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_SOUND_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_PHONETIC_s* e;
      struct zx_cdm_PHONETIC_s* en;
      struct zx_cdm_PHONETIC_s* enn;
      for (enn = 0, e = x->PHONETIC; e; e = (struct zx_cdm_PHONETIC_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_PHONETIC(c, e, dup_strs);
	  if (!enn)
	      x->PHONETIC = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      struct zx_cdm_BINVAL_s* en;
      struct zx_cdm_BINVAL_s* enn;
      for (enn = 0, e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_BINVAL(c, e, dup_strs);
	  if (!enn)
	      x->BINVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      struct zx_cdm_EXTVAL_s* en;
      struct zx_cdm_EXTVAL_s* enn;
      for (enn = 0, e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_EXTVAL(c, e, dup_strs);
	  if (!enn)
	      x->EXTVAL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_SOUND) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_PHONETIC_s* e;
      for (e = x->PHONETIC; e; e = (struct zx_cdm_PHONETIC_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_PHONETIC(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_BINVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_EXTVAL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_SOUND) */

int zx_WALK_WO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_STREET
#define EL_STRUCT zx_cdm_STREET_s
#define EL_NS     cdm
#define EL_TAG    STREET

/* FUNC(zx_FREE_cdm_STREET) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_STREET) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_STREET_s* zx_NEW_cdm_STREET(struct zx_ctx* c)
{
  struct zx_cdm_STREET_s* x = ZX_ZALLOC(c, struct zx_cdm_STREET_s);
  x->gg.g.tok = zx_cdm_STREET_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_STREET) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_STREET) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_STREET_s* zx_DEEP_CLONE_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x, int dup_strs)
{
  x = (struct zx_cdm_STREET_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_STREET_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_STREET) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_STREET) */

int zx_WALK_WO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_SUFFIX
#define EL_STRUCT zx_cdm_SUFFIX_s
#define EL_NS     cdm
#define EL_TAG    SUFFIX

/* FUNC(zx_FREE_cdm_SUFFIX) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_SUFFIX) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_SUFFIX_s* zx_NEW_cdm_SUFFIX(struct zx_ctx* c)
{
  struct zx_cdm_SUFFIX_s* x = ZX_ZALLOC(c, struct zx_cdm_SUFFIX_s);
  x->gg.g.tok = zx_cdm_SUFFIX_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_SUFFIX) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_SUFFIX) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_SUFFIX_s* zx_DEEP_CLONE_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x, int dup_strs)
{
  x = (struct zx_cdm_SUFFIX_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_SUFFIX_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_SUFFIX) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_SUFFIX) */

int zx_WALK_WO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_TEL
#define EL_STRUCT zx_cdm_TEL_s
#define EL_NS     cdm
#define EL_TAG    TEL

/* FUNC(zx_FREE_cdm_TEL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  zx_free_simple_elems(c, x->HOME, free_strs);
  zx_free_simple_elems(c, x->WORK, free_strs);
  zx_free_simple_elems(c, x->VOICE, free_strs);
  zx_free_simple_elems(c, x->FAX, free_strs);
  zx_free_simple_elems(c, x->PAGER, free_strs);
  zx_free_simple_elems(c, x->MSG, free_strs);
  zx_free_simple_elems(c, x->CELL, free_strs);
  zx_free_simple_elems(c, x->VIDEO, free_strs);
  zx_free_simple_elems(c, x->BBS, free_strs);
  zx_free_simple_elems(c, x->MODEM, free_strs);
  zx_free_simple_elems(c, x->ISDN, free_strs);
  zx_free_simple_elems(c, x->PCS, free_strs);
  zx_free_simple_elems(c, x->PREF, free_strs);
  {
      struct zx_cdm_NUMBER_s* e;
      struct zx_cdm_NUMBER_s* en;
      for (e = x->NUMBER; e; e = en) {
	  en = (struct zx_cdm_NUMBER_s*)e->gg.g.n;
	  zx_FREE_cdm_NUMBER(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_TEL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_TEL_s* zx_NEW_cdm_TEL(struct zx_ctx* c)
{
  struct zx_cdm_TEL_s* x = ZX_ZALLOC(c, struct zx_cdm_TEL_s);
  x->gg.g.tok = zx_cdm_TEL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_TEL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  zx_dup_strs_simple_elems(c, x->HOME);
  zx_dup_strs_simple_elems(c, x->WORK);
  zx_dup_strs_simple_elems(c, x->VOICE);
  zx_dup_strs_simple_elems(c, x->FAX);
  zx_dup_strs_simple_elems(c, x->PAGER);
  zx_dup_strs_simple_elems(c, x->MSG);
  zx_dup_strs_simple_elems(c, x->CELL);
  zx_dup_strs_simple_elems(c, x->VIDEO);
  zx_dup_strs_simple_elems(c, x->BBS);
  zx_dup_strs_simple_elems(c, x->MODEM);
  zx_dup_strs_simple_elems(c, x->ISDN);
  zx_dup_strs_simple_elems(c, x->PCS);
  zx_dup_strs_simple_elems(c, x->PREF);
  {
      struct zx_cdm_NUMBER_s* e;
      for (e = x->NUMBER; e; e = (struct zx_cdm_NUMBER_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_NUMBER(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_TEL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_TEL_s* zx_DEEP_CLONE_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x, int dup_strs)
{
  x = (struct zx_cdm_TEL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_TEL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  x->HOME = zx_deep_clone_simple_elems(c,x->HOME, dup_strs);
  x->WORK = zx_deep_clone_simple_elems(c,x->WORK, dup_strs);
  x->VOICE = zx_deep_clone_simple_elems(c,x->VOICE, dup_strs);
  x->FAX = zx_deep_clone_simple_elems(c,x->FAX, dup_strs);
  x->PAGER = zx_deep_clone_simple_elems(c,x->PAGER, dup_strs);
  x->MSG = zx_deep_clone_simple_elems(c,x->MSG, dup_strs);
  x->CELL = zx_deep_clone_simple_elems(c,x->CELL, dup_strs);
  x->VIDEO = zx_deep_clone_simple_elems(c,x->VIDEO, dup_strs);
  x->BBS = zx_deep_clone_simple_elems(c,x->BBS, dup_strs);
  x->MODEM = zx_deep_clone_simple_elems(c,x->MODEM, dup_strs);
  x->ISDN = zx_deep_clone_simple_elems(c,x->ISDN, dup_strs);
  x->PCS = zx_deep_clone_simple_elems(c,x->PCS, dup_strs);
  x->PREF = zx_deep_clone_simple_elems(c,x->PREF, dup_strs);
  {
      struct zx_cdm_NUMBER_s* e;
      struct zx_cdm_NUMBER_s* en;
      struct zx_cdm_NUMBER_s* enn;
      for (enn = 0, e = x->NUMBER; e; e = (struct zx_cdm_NUMBER_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_NUMBER(c, e, dup_strs);
	  if (!enn)
	      x->NUMBER = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_TEL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->HOME, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->WORK, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VOICE, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FAX, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PAGER, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MSG, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->CELL, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->VIDEO, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->BBS, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MODEM, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->ISDN, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PCS, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PREF, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_NUMBER_s* e;
      for (e = x->NUMBER; e; e = (struct zx_cdm_NUMBER_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_NUMBER(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_TEL) */

int zx_WALK_WO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_TITLE
#define EL_STRUCT zx_cdm_TITLE_s
#define EL_NS     cdm
#define EL_TAG    TITLE

/* FUNC(zx_FREE_cdm_TITLE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->group, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_TITLE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_TITLE_s* zx_NEW_cdm_TITLE(struct zx_ctx* c)
{
  struct zx_cdm_TITLE_s* x = ZX_ZALLOC(c, struct zx_cdm_TITLE_s);
  x->gg.g.tok = zx_cdm_TITLE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_TITLE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->group);


}

/* FUNC(zx_DEEP_CLONE_cdm_TITLE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_TITLE_s* zx_DEEP_CLONE_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x, int dup_strs)
{
  x = (struct zx_cdm_TITLE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_TITLE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->group = zx_clone_attr(c, x->group);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_TITLE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_TITLE) */

int zx_WALK_WO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_TYPE
#define EL_STRUCT zx_cdm_TYPE_s
#define EL_NS     cdm
#define EL_TAG    TYPE

/* FUNC(zx_FREE_cdm_TYPE) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_TYPE) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_TYPE_s* zx_NEW_cdm_TYPE(struct zx_ctx* c)
{
  struct zx_cdm_TYPE_s* x = ZX_ZALLOC(c, struct zx_cdm_TYPE_s);
  x->gg.g.tok = zx_cdm_TYPE_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_TYPE) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_TYPE) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_TYPE_s* zx_DEEP_CLONE_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x, int dup_strs)
{
  x = (struct zx_cdm_TYPE_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_TYPE_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_TYPE) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_TYPE) */

int zx_WALK_WO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_TZ
#define EL_STRUCT zx_cdm_TZ_s
#define EL_NS     cdm
#define EL_TAG    TZ

/* FUNC(zx_FREE_cdm_TZ) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_TZ) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_TZ_s* zx_NEW_cdm_TZ(struct zx_ctx* c)
{
  struct zx_cdm_TZ_s* x = ZX_ZALLOC(c, struct zx_cdm_TZ_s);
  x->gg.g.tok = zx_cdm_TZ_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_TZ) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_TZ) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_TZ_s* zx_DEEP_CLONE_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x, int dup_strs)
{
  x = (struct zx_cdm_TZ_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_TZ_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_TZ) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_TZ) */

int zx_WALK_WO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_UID
#define EL_STRUCT zx_cdm_UID_s
#define EL_NS     cdm
#define EL_TAG    UID

/* FUNC(zx_FREE_cdm_UID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_UID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_UID_s* zx_NEW_cdm_UID(struct zx_ctx* c)
{
  struct zx_cdm_UID_s* x = ZX_ZALLOC(c, struct zx_cdm_UID_s);
  x->gg.g.tok = zx_cdm_UID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_UID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_UID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_UID_s* zx_DEEP_CLONE_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x, int dup_strs)
{
  x = (struct zx_cdm_UID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_UID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_UID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_UID) */

int zx_WALK_WO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_URI
#define EL_STRUCT zx_cdm_URI_s
#define EL_NS     cdm
#define EL_TAG    URI

/* FUNC(zx_FREE_cdm_URI) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_URI) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_URI_s* zx_NEW_cdm_URI(struct zx_ctx* c)
{
  struct zx_cdm_URI_s* x = ZX_ZALLOC(c, struct zx_cdm_URI_s);
  x->gg.g.tok = zx_cdm_URI_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_URI) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_URI) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_URI_s* zx_DEEP_CLONE_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x, int dup_strs)
{
  x = (struct zx_cdm_URI_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_URI_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_URI) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_URI) */

int zx_WALK_WO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_URL
#define EL_STRUCT zx_cdm_URL_s
#define EL_NS     cdm
#define EL_TAG    URL

/* FUNC(zx_FREE_cdm_URL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_URL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_URL_s* zx_NEW_cdm_URL(struct zx_ctx* c)
{
  struct zx_cdm_URL_s* x = ZX_ZALLOC(c, struct zx_cdm_URL_s);
  x->gg.g.tok = zx_cdm_URL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_URL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_URL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_URL_s* zx_DEEP_CLONE_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x, int dup_strs)
{
  x = (struct zx_cdm_URL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_URL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_URL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_URL) */

int zx_WALK_WO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_USERID
#define EL_STRUCT zx_cdm_USERID_s
#define EL_NS     cdm
#define EL_TAG    USERID

/* FUNC(zx_FREE_cdm_USERID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_USERID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_USERID_s* zx_NEW_cdm_USERID(struct zx_ctx* c)
{
  struct zx_cdm_USERID_s* x = ZX_ZALLOC(c, struct zx_cdm_USERID_s);
  x->gg.g.tok = zx_cdm_USERID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_USERID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_USERID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_USERID_s* zx_DEEP_CLONE_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x, int dup_strs)
{
  x = (struct zx_cdm_USERID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_USERID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_USERID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_USERID) */

int zx_WALK_WO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_VERSION
#define EL_STRUCT zx_cdm_VERSION_s
#define EL_NS     cdm
#define EL_TAG    VERSION

/* FUNC(zx_FREE_cdm_VERSION) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);
  zx_free_attr(c, x->ACCTime, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);
  zx_free_attr(c, x->modifier, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_VERSION) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_VERSION_s* zx_NEW_cdm_VERSION(struct zx_ctx* c)
{
  struct zx_cdm_VERSION_s* x = ZX_ZALLOC(c, struct zx_cdm_VERSION_s);
  x->gg.g.tok = zx_cdm_VERSION_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_VERSION) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);
  zx_dup_attr(c, x->ACCTime);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);
  zx_dup_attr(c, x->modifier);


}

/* FUNC(zx_DEEP_CLONE_cdm_VERSION) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_VERSION_s* zx_DEEP_CLONE_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x, int dup_strs)
{
  x = (struct zx_cdm_VERSION_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_VERSION_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);
  x->ACCTime = zx_clone_attr(c, x->ACCTime);
  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);
  x->modifier = zx_clone_attr(c, x->modifier);


  return x;
}

/* FUNC(zx_WALK_SO_cdm_VERSION) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_cdm_VERSION) */

int zx_WALK_WO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   cdm_vCard
#define EL_STRUCT zx_cdm_vCard_s
#define EL_NS     cdm
#define EL_TAG    vCard

/* FUNC(zx_FREE_cdm_vCard) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->modificationTime, free_strs);

  {
      struct zx_cdm_VERSION_s* e;
      struct zx_cdm_VERSION_s* en;
      for (e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = en) {
	  en = (struct zx_cdm_VERSION_s*)e->gg.g.n;
	  zx_FREE_cdm_VERSION(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->CARDID, free_strs);
  zx_free_simple_elems(c, x->DISTRIBUTIONLIST, free_strs);
  zx_free_simple_elems(c, x->SELF, free_strs);
  zx_free_simple_elems(c, x->FAVORITE, free_strs);
  {
      struct zx_cdm_FN_s* e;
      struct zx_cdm_FN_s* en;
      for (e = x->FN; e; e = en) {
	  en = (struct zx_cdm_FN_s*)e->gg.g.n;
	  zx_FREE_cdm_FN(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_N_s* e;
      struct zx_cdm_N_s* en;
      for (e = x->N; e; e = en) {
	  en = (struct zx_cdm_N_s*)e->gg.g.n;
	  zx_FREE_cdm_N(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      struct zx_cdm_LISTMEMBER_s* en;
      for (e = x->LISTMEMBER; e; e = en) {
	  en = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n;
	  zx_FREE_cdm_LISTMEMBER(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      struct zx_cdm_NICKNAME_s* en;
      for (e = x->NICKNAME; e; e = en) {
	  en = (struct zx_cdm_NICKNAME_s*)e->gg.g.n;
	  zx_FREE_cdm_NICKNAME(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_PHOTO_s* e;
      struct zx_cdm_PHOTO_s* en;
      for (e = x->PHOTO; e; e = en) {
	  en = (struct zx_cdm_PHOTO_s*)e->gg.g.n;
	  zx_FREE_cdm_PHOTO(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_BDAY_s* e;
      struct zx_cdm_BDAY_s* en;
      for (e = x->BDAY; e; e = en) {
	  en = (struct zx_cdm_BDAY_s*)e->gg.g.n;
	  zx_FREE_cdm_BDAY(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_ADR_s* e;
      struct zx_cdm_ADR_s* en;
      for (e = x->ADR; e; e = en) {
	  en = (struct zx_cdm_ADR_s*)e->gg.g.n;
	  zx_FREE_cdm_ADR(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_LABEL_s* e;
      struct zx_cdm_LABEL_s* en;
      for (e = x->LABEL; e; e = en) {
	  en = (struct zx_cdm_LABEL_s*)e->gg.g.n;
	  zx_FREE_cdm_LABEL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_TEL_s* e;
      struct zx_cdm_TEL_s* en;
      for (e = x->TEL; e; e = en) {
	  en = (struct zx_cdm_TEL_s*)e->gg.g.n;
	  zx_FREE_cdm_TEL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_EMAIL_s* e;
      struct zx_cdm_EMAIL_s* en;
      for (e = x->EMAIL; e; e = en) {
	  en = (struct zx_cdm_EMAIL_s*)e->gg.g.n;
	  zx_FREE_cdm_EMAIL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_JABBERID_s* e;
      struct zx_cdm_JABBERID_s* en;
      for (e = x->JABBERID; e; e = en) {
	  en = (struct zx_cdm_JABBERID_s*)e->gg.g.n;
	  zx_FREE_cdm_JABBERID(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_MAILER_s* e;
      struct zx_cdm_MAILER_s* en;
      for (e = x->MAILER; e; e = en) {
	  en = (struct zx_cdm_MAILER_s*)e->gg.g.n;
	  zx_FREE_cdm_MAILER(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_TZ_s* e;
      struct zx_cdm_TZ_s* en;
      for (e = x->TZ; e; e = en) {
	  en = (struct zx_cdm_TZ_s*)e->gg.g.n;
	  zx_FREE_cdm_TZ(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_GEO_s* e;
      struct zx_cdm_GEO_s* en;
      for (e = x->GEO; e; e = en) {
	  en = (struct zx_cdm_GEO_s*)e->gg.g.n;
	  zx_FREE_cdm_GEO(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_TITLE_s* e;
      struct zx_cdm_TITLE_s* en;
      for (e = x->TITLE; e; e = en) {
	  en = (struct zx_cdm_TITLE_s*)e->gg.g.n;
	  zx_FREE_cdm_TITLE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_ROLE_s* e;
      struct zx_cdm_ROLE_s* en;
      for (e = x->ROLE; e; e = en) {
	  en = (struct zx_cdm_ROLE_s*)e->gg.g.n;
	  zx_FREE_cdm_ROLE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_LOGO_s* e;
      struct zx_cdm_LOGO_s* en;
      for (e = x->LOGO; e; e = en) {
	  en = (struct zx_cdm_LOGO_s*)e->gg.g.n;
	  zx_FREE_cdm_LOGO(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_AGENT_s* e;
      struct zx_cdm_AGENT_s* en;
      for (e = x->AGENT; e; e = en) {
	  en = (struct zx_cdm_AGENT_s*)e->gg.g.n;
	  zx_FREE_cdm_AGENT(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_ORG_s* e;
      struct zx_cdm_ORG_s* en;
      for (e = x->ORG; e; e = en) {
	  en = (struct zx_cdm_ORG_s*)e->gg.g.n;
	  zx_FREE_cdm_ORG(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      struct zx_cdm_CATEGORIES_s* en;
      for (e = x->CATEGORIES; e; e = en) {
	  en = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n;
	  zx_FREE_cdm_CATEGORIES(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_NOTE_s* e;
      struct zx_cdm_NOTE_s* en;
      for (e = x->NOTE; e; e = en) {
	  en = (struct zx_cdm_NOTE_s*)e->gg.g.n;
	  zx_FREE_cdm_NOTE(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_PRODID_s* e;
      struct zx_cdm_PRODID_s* en;
      for (e = x->PRODID; e; e = en) {
	  en = (struct zx_cdm_PRODID_s*)e->gg.g.n;
	  zx_FREE_cdm_PRODID(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_REV_s* e;
      struct zx_cdm_REV_s* en;
      for (e = x->REV; e; e = en) {
	  en = (struct zx_cdm_REV_s*)e->gg.g.n;
	  zx_FREE_cdm_REV(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      struct zx_cdm_SORT_STRING_s* en;
      for (e = x->SORT_STRING; e; e = en) {
	  en = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n;
	  zx_FREE_cdm_SORT_STRING(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_SOUND_s* e;
      struct zx_cdm_SOUND_s* en;
      for (e = x->SOUND; e; e = en) {
	  en = (struct zx_cdm_SOUND_s*)e->gg.g.n;
	  zx_FREE_cdm_SOUND(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_UID_s* e;
      struct zx_cdm_UID_s* en;
      for (e = x->UID; e; e = en) {
	  en = (struct zx_cdm_UID_s*)e->gg.g.n;
	  zx_FREE_cdm_UID(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_URL_s* e;
      struct zx_cdm_URL_s* en;
      for (e = x->URL; e; e = en) {
	  en = (struct zx_cdm_URL_s*)e->gg.g.n;
	  zx_FREE_cdm_URL(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CLASS_s* e;
      struct zx_cdm_CLASS_s* en;
      for (e = x->CLASS; e; e = en) {
	  en = (struct zx_cdm_CLASS_s*)e->gg.g.n;
	  zx_FREE_cdm_CLASS(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_KEY_s* e;
      struct zx_cdm_KEY_s* en;
      for (e = x->KEY; e; e = en) {
	  en = (struct zx_cdm_KEY_s*)e->gg.g.n;
	  zx_FREE_cdm_KEY(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_DESC_s* e;
      struct zx_cdm_DESC_s* en;
      for (e = x->DESC; e; e = en) {
	  en = (struct zx_cdm_DESC_s*)e->gg.g.n;
	  zx_FREE_cdm_DESC(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      struct zx_cdm_PHYSICALACCESS_s* en;
      for (e = x->PHYSICALACCESS; e; e = en) {
	  en = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n;
	  zx_FREE_cdm_PHYSICALACCESS(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CALURI_s* e;
      struct zx_cdm_CALURI_s* en;
      for (e = x->CALURI; e; e = en) {
	  en = (struct zx_cdm_CALURI_s*)e->gg.g.n;
	  zx_FREE_cdm_CALURI(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CAPURI_s* e;
      struct zx_cdm_CAPURI_s* en;
      for (e = x->CAPURI; e; e = en) {
	  en = (struct zx_cdm_CAPURI_s*)e->gg.g.n;
	  zx_FREE_cdm_CAPURI(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      struct zx_cdm_CALADRURI_s* en;
      for (e = x->CALADRURI; e; e = en) {
	  en = (struct zx_cdm_CALADRURI_s*)e->gg.g.n;
	  zx_FREE_cdm_CALADRURI(c, e, free_strs);
      }
  }
  {
      struct zx_cdm_FBURL_s* e;
      struct zx_cdm_FBURL_s* en;
      for (e = x->FBURL; e; e = en) {
	  en = (struct zx_cdm_FBURL_s*)e->gg.g.n;
	  zx_FREE_cdm_FBURL(c, e, free_strs);
      }
  }
  {
      struct zx_cb_Extension_s* e;
      struct zx_cb_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_cb_Extension_s*)e->gg.g.n;
	  zx_FREE_cb_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_cdm_vCard) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_cdm_vCard_s* zx_NEW_cdm_vCard(struct zx_ctx* c)
{
  struct zx_cdm_vCard_s* x = ZX_ZALLOC(c, struct zx_cdm_vCard_s);
  x->gg.g.tok = zx_cdm_vCard_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_cdm_vCard) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->modificationTime);

  {
      struct zx_cdm_VERSION_s* e;
      for (e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = (struct zx_cdm_VERSION_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_VERSION(c, e);
  }
  zx_dup_strs_simple_elems(c, x->CARDID);
  zx_dup_strs_simple_elems(c, x->DISTRIBUTIONLIST);
  zx_dup_strs_simple_elems(c, x->SELF);
  zx_dup_strs_simple_elems(c, x->FAVORITE);
  {
      struct zx_cdm_FN_s* e;
      for (e = x->FN; e; e = (struct zx_cdm_FN_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_FN(c, e);
  }
  {
      struct zx_cdm_N_s* e;
      for (e = x->N; e; e = (struct zx_cdm_N_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_N(c, e);
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      for (e = x->LISTMEMBER; e; e = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LISTMEMBER(c, e);
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      for (e = x->NICKNAME; e; e = (struct zx_cdm_NICKNAME_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_NICKNAME(c, e);
  }
  {
      struct zx_cdm_PHOTO_s* e;
      for (e = x->PHOTO; e; e = (struct zx_cdm_PHOTO_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_PHOTO(c, e);
  }
  {
      struct zx_cdm_BDAY_s* e;
      for (e = x->BDAY; e; e = (struct zx_cdm_BDAY_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_BDAY(c, e);
  }
  {
      struct zx_cdm_ADR_s* e;
      for (e = x->ADR; e; e = (struct zx_cdm_ADR_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_ADR(c, e);
  }
  {
      struct zx_cdm_LABEL_s* e;
      for (e = x->LABEL; e; e = (struct zx_cdm_LABEL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LABEL(c, e);
  }
  {
      struct zx_cdm_TEL_s* e;
      for (e = x->TEL; e; e = (struct zx_cdm_TEL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_TEL(c, e);
  }
  {
      struct zx_cdm_EMAIL_s* e;
      for (e = x->EMAIL; e; e = (struct zx_cdm_EMAIL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_EMAIL(c, e);
  }
  {
      struct zx_cdm_JABBERID_s* e;
      for (e = x->JABBERID; e; e = (struct zx_cdm_JABBERID_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_JABBERID(c, e);
  }
  {
      struct zx_cdm_MAILER_s* e;
      for (e = x->MAILER; e; e = (struct zx_cdm_MAILER_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_MAILER(c, e);
  }
  {
      struct zx_cdm_TZ_s* e;
      for (e = x->TZ; e; e = (struct zx_cdm_TZ_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_TZ(c, e);
  }
  {
      struct zx_cdm_GEO_s* e;
      for (e = x->GEO; e; e = (struct zx_cdm_GEO_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_GEO(c, e);
  }
  {
      struct zx_cdm_TITLE_s* e;
      for (e = x->TITLE; e; e = (struct zx_cdm_TITLE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_TITLE(c, e);
  }
  {
      struct zx_cdm_ROLE_s* e;
      for (e = x->ROLE; e; e = (struct zx_cdm_ROLE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_ROLE(c, e);
  }
  {
      struct zx_cdm_LOGO_s* e;
      for (e = x->LOGO; e; e = (struct zx_cdm_LOGO_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_LOGO(c, e);
  }
  {
      struct zx_cdm_AGENT_s* e;
      for (e = x->AGENT; e; e = (struct zx_cdm_AGENT_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_AGENT(c, e);
  }
  {
      struct zx_cdm_ORG_s* e;
      for (e = x->ORG; e; e = (struct zx_cdm_ORG_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_ORG(c, e);
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      for (e = x->CATEGORIES; e; e = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CATEGORIES(c, e);
  }
  {
      struct zx_cdm_NOTE_s* e;
      for (e = x->NOTE; e; e = (struct zx_cdm_NOTE_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_NOTE(c, e);
  }
  {
      struct zx_cdm_PRODID_s* e;
      for (e = x->PRODID; e; e = (struct zx_cdm_PRODID_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_PRODID(c, e);
  }
  {
      struct zx_cdm_REV_s* e;
      for (e = x->REV; e; e = (struct zx_cdm_REV_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_REV(c, e);
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      for (e = x->SORT_STRING; e; e = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_SORT_STRING(c, e);
  }
  {
      struct zx_cdm_SOUND_s* e;
      for (e = x->SOUND; e; e = (struct zx_cdm_SOUND_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_SOUND(c, e);
  }
  {
      struct zx_cdm_UID_s* e;
      for (e = x->UID; e; e = (struct zx_cdm_UID_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_UID(c, e);
  }
  {
      struct zx_cdm_URL_s* e;
      for (e = x->URL; e; e = (struct zx_cdm_URL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_URL(c, e);
  }
  {
      struct zx_cdm_CLASS_s* e;
      for (e = x->CLASS; e; e = (struct zx_cdm_CLASS_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CLASS(c, e);
  }
  {
      struct zx_cdm_KEY_s* e;
      for (e = x->KEY; e; e = (struct zx_cdm_KEY_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_KEY(c, e);
  }
  {
      struct zx_cdm_DESC_s* e;
      for (e = x->DESC; e; e = (struct zx_cdm_DESC_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_DESC(c, e);
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      for (e = x->PHYSICALACCESS; e; e = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_PHYSICALACCESS(c, e);
  }
  {
      struct zx_cdm_CALURI_s* e;
      for (e = x->CALURI; e; e = (struct zx_cdm_CALURI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CALURI(c, e);
  }
  {
      struct zx_cdm_CAPURI_s* e;
      for (e = x->CAPURI; e; e = (struct zx_cdm_CAPURI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CAPURI(c, e);
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      for (e = x->CALADRURI; e; e = (struct zx_cdm_CALADRURI_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_CALADRURI(c, e);
  }
  {
      struct zx_cdm_FBURL_s* e;
      for (e = x->FBURL; e; e = (struct zx_cdm_FBURL_s*)e->gg.g.n)
	  zx_DUP_STRS_cdm_FBURL(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_cdm_vCard) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_cdm_vCard_s* zx_DEEP_CLONE_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x, int dup_strs)
{
  x = (struct zx_cdm_vCard_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_cdm_vCard_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->modificationTime = zx_clone_attr(c, x->modificationTime);

  {
      struct zx_cdm_VERSION_s* e;
      struct zx_cdm_VERSION_s* en;
      struct zx_cdm_VERSION_s* enn;
      for (enn = 0, e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = (struct zx_cdm_VERSION_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_VERSION(c, e, dup_strs);
	  if (!enn)
	      x->VERSION_is_Perl_MakeMaker_gobbled = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->CARDID = zx_deep_clone_simple_elems(c,x->CARDID, dup_strs);
  x->DISTRIBUTIONLIST = zx_deep_clone_simple_elems(c,x->DISTRIBUTIONLIST, dup_strs);
  x->SELF = zx_deep_clone_simple_elems(c,x->SELF, dup_strs);
  x->FAVORITE = zx_deep_clone_simple_elems(c,x->FAVORITE, dup_strs);
  {
      struct zx_cdm_FN_s* e;
      struct zx_cdm_FN_s* en;
      struct zx_cdm_FN_s* enn;
      for (enn = 0, e = x->FN; e; e = (struct zx_cdm_FN_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_FN(c, e, dup_strs);
	  if (!enn)
	      x->FN = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_N_s* e;
      struct zx_cdm_N_s* en;
      struct zx_cdm_N_s* enn;
      for (enn = 0, e = x->N; e; e = (struct zx_cdm_N_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_N(c, e, dup_strs);
	  if (!enn)
	      x->N = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      struct zx_cdm_LISTMEMBER_s* en;
      struct zx_cdm_LISTMEMBER_s* enn;
      for (enn = 0, e = x->LISTMEMBER; e; e = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LISTMEMBER(c, e, dup_strs);
	  if (!enn)
	      x->LISTMEMBER = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      struct zx_cdm_NICKNAME_s* en;
      struct zx_cdm_NICKNAME_s* enn;
      for (enn = 0, e = x->NICKNAME; e; e = (struct zx_cdm_NICKNAME_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_NICKNAME(c, e, dup_strs);
	  if (!enn)
	      x->NICKNAME = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_PHOTO_s* e;
      struct zx_cdm_PHOTO_s* en;
      struct zx_cdm_PHOTO_s* enn;
      for (enn = 0, e = x->PHOTO; e; e = (struct zx_cdm_PHOTO_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_PHOTO(c, e, dup_strs);
	  if (!enn)
	      x->PHOTO = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_BDAY_s* e;
      struct zx_cdm_BDAY_s* en;
      struct zx_cdm_BDAY_s* enn;
      for (enn = 0, e = x->BDAY; e; e = (struct zx_cdm_BDAY_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_BDAY(c, e, dup_strs);
	  if (!enn)
	      x->BDAY = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_ADR_s* e;
      struct zx_cdm_ADR_s* en;
      struct zx_cdm_ADR_s* enn;
      for (enn = 0, e = x->ADR; e; e = (struct zx_cdm_ADR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_ADR(c, e, dup_strs);
	  if (!enn)
	      x->ADR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_LABEL_s* e;
      struct zx_cdm_LABEL_s* en;
      struct zx_cdm_LABEL_s* enn;
      for (enn = 0, e = x->LABEL; e; e = (struct zx_cdm_LABEL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LABEL(c, e, dup_strs);
	  if (!enn)
	      x->LABEL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_TEL_s* e;
      struct zx_cdm_TEL_s* en;
      struct zx_cdm_TEL_s* enn;
      for (enn = 0, e = x->TEL; e; e = (struct zx_cdm_TEL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_TEL(c, e, dup_strs);
	  if (!enn)
	      x->TEL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_EMAIL_s* e;
      struct zx_cdm_EMAIL_s* en;
      struct zx_cdm_EMAIL_s* enn;
      for (enn = 0, e = x->EMAIL; e; e = (struct zx_cdm_EMAIL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_EMAIL(c, e, dup_strs);
	  if (!enn)
	      x->EMAIL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_JABBERID_s* e;
      struct zx_cdm_JABBERID_s* en;
      struct zx_cdm_JABBERID_s* enn;
      for (enn = 0, e = x->JABBERID; e; e = (struct zx_cdm_JABBERID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_JABBERID(c, e, dup_strs);
	  if (!enn)
	      x->JABBERID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_MAILER_s* e;
      struct zx_cdm_MAILER_s* en;
      struct zx_cdm_MAILER_s* enn;
      for (enn = 0, e = x->MAILER; e; e = (struct zx_cdm_MAILER_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_MAILER(c, e, dup_strs);
	  if (!enn)
	      x->MAILER = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_TZ_s* e;
      struct zx_cdm_TZ_s* en;
      struct zx_cdm_TZ_s* enn;
      for (enn = 0, e = x->TZ; e; e = (struct zx_cdm_TZ_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_TZ(c, e, dup_strs);
	  if (!enn)
	      x->TZ = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_GEO_s* e;
      struct zx_cdm_GEO_s* en;
      struct zx_cdm_GEO_s* enn;
      for (enn = 0, e = x->GEO; e; e = (struct zx_cdm_GEO_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_GEO(c, e, dup_strs);
	  if (!enn)
	      x->GEO = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_TITLE_s* e;
      struct zx_cdm_TITLE_s* en;
      struct zx_cdm_TITLE_s* enn;
      for (enn = 0, e = x->TITLE; e; e = (struct zx_cdm_TITLE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_TITLE(c, e, dup_strs);
	  if (!enn)
	      x->TITLE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_ROLE_s* e;
      struct zx_cdm_ROLE_s* en;
      struct zx_cdm_ROLE_s* enn;
      for (enn = 0, e = x->ROLE; e; e = (struct zx_cdm_ROLE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_ROLE(c, e, dup_strs);
	  if (!enn)
	      x->ROLE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_LOGO_s* e;
      struct zx_cdm_LOGO_s* en;
      struct zx_cdm_LOGO_s* enn;
      for (enn = 0, e = x->LOGO; e; e = (struct zx_cdm_LOGO_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_LOGO(c, e, dup_strs);
	  if (!enn)
	      x->LOGO = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_AGENT_s* e;
      struct zx_cdm_AGENT_s* en;
      struct zx_cdm_AGENT_s* enn;
      for (enn = 0, e = x->AGENT; e; e = (struct zx_cdm_AGENT_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_AGENT(c, e, dup_strs);
	  if (!enn)
	      x->AGENT = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_ORG_s* e;
      struct zx_cdm_ORG_s* en;
      struct zx_cdm_ORG_s* enn;
      for (enn = 0, e = x->ORG; e; e = (struct zx_cdm_ORG_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_ORG(c, e, dup_strs);
	  if (!enn)
	      x->ORG = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      struct zx_cdm_CATEGORIES_s* en;
      struct zx_cdm_CATEGORIES_s* enn;
      for (enn = 0, e = x->CATEGORIES; e; e = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CATEGORIES(c, e, dup_strs);
	  if (!enn)
	      x->CATEGORIES = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_NOTE_s* e;
      struct zx_cdm_NOTE_s* en;
      struct zx_cdm_NOTE_s* enn;
      for (enn = 0, e = x->NOTE; e; e = (struct zx_cdm_NOTE_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_NOTE(c, e, dup_strs);
	  if (!enn)
	      x->NOTE = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_PRODID_s* e;
      struct zx_cdm_PRODID_s* en;
      struct zx_cdm_PRODID_s* enn;
      for (enn = 0, e = x->PRODID; e; e = (struct zx_cdm_PRODID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_PRODID(c, e, dup_strs);
	  if (!enn)
	      x->PRODID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_REV_s* e;
      struct zx_cdm_REV_s* en;
      struct zx_cdm_REV_s* enn;
      for (enn = 0, e = x->REV; e; e = (struct zx_cdm_REV_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_REV(c, e, dup_strs);
	  if (!enn)
	      x->REV = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      struct zx_cdm_SORT_STRING_s* en;
      struct zx_cdm_SORT_STRING_s* enn;
      for (enn = 0, e = x->SORT_STRING; e; e = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_SORT_STRING(c, e, dup_strs);
	  if (!enn)
	      x->SORT_STRING = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_SOUND_s* e;
      struct zx_cdm_SOUND_s* en;
      struct zx_cdm_SOUND_s* enn;
      for (enn = 0, e = x->SOUND; e; e = (struct zx_cdm_SOUND_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_SOUND(c, e, dup_strs);
	  if (!enn)
	      x->SOUND = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_UID_s* e;
      struct zx_cdm_UID_s* en;
      struct zx_cdm_UID_s* enn;
      for (enn = 0, e = x->UID; e; e = (struct zx_cdm_UID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_UID(c, e, dup_strs);
	  if (!enn)
	      x->UID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_URL_s* e;
      struct zx_cdm_URL_s* en;
      struct zx_cdm_URL_s* enn;
      for (enn = 0, e = x->URL; e; e = (struct zx_cdm_URL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_URL(c, e, dup_strs);
	  if (!enn)
	      x->URL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CLASS_s* e;
      struct zx_cdm_CLASS_s* en;
      struct zx_cdm_CLASS_s* enn;
      for (enn = 0, e = x->CLASS; e; e = (struct zx_cdm_CLASS_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CLASS(c, e, dup_strs);
	  if (!enn)
	      x->CLASS = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_KEY_s* e;
      struct zx_cdm_KEY_s* en;
      struct zx_cdm_KEY_s* enn;
      for (enn = 0, e = x->KEY; e; e = (struct zx_cdm_KEY_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_KEY(c, e, dup_strs);
	  if (!enn)
	      x->KEY = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_DESC_s* e;
      struct zx_cdm_DESC_s* en;
      struct zx_cdm_DESC_s* enn;
      for (enn = 0, e = x->DESC; e; e = (struct zx_cdm_DESC_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_DESC(c, e, dup_strs);
	  if (!enn)
	      x->DESC = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      struct zx_cdm_PHYSICALACCESS_s* en;
      struct zx_cdm_PHYSICALACCESS_s* enn;
      for (enn = 0, e = x->PHYSICALACCESS; e; e = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_PHYSICALACCESS(c, e, dup_strs);
	  if (!enn)
	      x->PHYSICALACCESS = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CALURI_s* e;
      struct zx_cdm_CALURI_s* en;
      struct zx_cdm_CALURI_s* enn;
      for (enn = 0, e = x->CALURI; e; e = (struct zx_cdm_CALURI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CALURI(c, e, dup_strs);
	  if (!enn)
	      x->CALURI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CAPURI_s* e;
      struct zx_cdm_CAPURI_s* en;
      struct zx_cdm_CAPURI_s* enn;
      for (enn = 0, e = x->CAPURI; e; e = (struct zx_cdm_CAPURI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CAPURI(c, e, dup_strs);
	  if (!enn)
	      x->CAPURI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      struct zx_cdm_CALADRURI_s* en;
      struct zx_cdm_CALADRURI_s* enn;
      for (enn = 0, e = x->CALADRURI; e; e = (struct zx_cdm_CALADRURI_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_CALADRURI(c, e, dup_strs);
	  if (!enn)
	      x->CALADRURI = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cdm_FBURL_s* e;
      struct zx_cdm_FBURL_s* en;
      struct zx_cdm_FBURL_s* enn;
      for (enn = 0, e = x->FBURL; e; e = (struct zx_cdm_FBURL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cdm_FBURL(c, e, dup_strs);
	  if (!enn)
	      x->FBURL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_Extension_s* e;
      struct zx_cb_Extension_s* en;
      struct zx_cb_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_cdm_vCard) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_cdm_VERSION_s* e;
      for (e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = (struct zx_cdm_VERSION_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_VERSION(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->CARDID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->DISTRIBUTIONLIST, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SELF, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->FAVORITE, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_cdm_FN_s* e;
      for (e = x->FN; e; e = (struct zx_cdm_FN_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_FN(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_N_s* e;
      for (e = x->N; e; e = (struct zx_cdm_N_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_N(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      for (e = x->LISTMEMBER; e; e = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LISTMEMBER(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      for (e = x->NICKNAME; e; e = (struct zx_cdm_NICKNAME_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_NICKNAME(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_PHOTO_s* e;
      for (e = x->PHOTO; e; e = (struct zx_cdm_PHOTO_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_PHOTO(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_BDAY_s* e;
      for (e = x->BDAY; e; e = (struct zx_cdm_BDAY_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_BDAY(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_ADR_s* e;
      for (e = x->ADR; e; e = (struct zx_cdm_ADR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_ADR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_LABEL_s* e;
      for (e = x->LABEL; e; e = (struct zx_cdm_LABEL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LABEL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_TEL_s* e;
      for (e = x->TEL; e; e = (struct zx_cdm_TEL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_TEL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_EMAIL_s* e;
      for (e = x->EMAIL; e; e = (struct zx_cdm_EMAIL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_EMAIL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_JABBERID_s* e;
      for (e = x->JABBERID; e; e = (struct zx_cdm_JABBERID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_JABBERID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_MAILER_s* e;
      for (e = x->MAILER; e; e = (struct zx_cdm_MAILER_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_MAILER(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_TZ_s* e;
      for (e = x->TZ; e; e = (struct zx_cdm_TZ_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_TZ(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_GEO_s* e;
      for (e = x->GEO; e; e = (struct zx_cdm_GEO_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_GEO(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_TITLE_s* e;
      for (e = x->TITLE; e; e = (struct zx_cdm_TITLE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_TITLE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_ROLE_s* e;
      for (e = x->ROLE; e; e = (struct zx_cdm_ROLE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_ROLE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_LOGO_s* e;
      for (e = x->LOGO; e; e = (struct zx_cdm_LOGO_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_LOGO(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_AGENT_s* e;
      for (e = x->AGENT; e; e = (struct zx_cdm_AGENT_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_AGENT(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_ORG_s* e;
      for (e = x->ORG; e; e = (struct zx_cdm_ORG_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_ORG(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      for (e = x->CATEGORIES; e; e = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CATEGORIES(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_NOTE_s* e;
      for (e = x->NOTE; e; e = (struct zx_cdm_NOTE_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_NOTE(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_PRODID_s* e;
      for (e = x->PRODID; e; e = (struct zx_cdm_PRODID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_PRODID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_REV_s* e;
      for (e = x->REV; e; e = (struct zx_cdm_REV_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_REV(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      for (e = x->SORT_STRING; e; e = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_SORT_STRING(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_SOUND_s* e;
      for (e = x->SOUND; e; e = (struct zx_cdm_SOUND_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_SOUND(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_UID_s* e;
      for (e = x->UID; e; e = (struct zx_cdm_UID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_UID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_URL_s* e;
      for (e = x->URL; e; e = (struct zx_cdm_URL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_URL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CLASS_s* e;
      for (e = x->CLASS; e; e = (struct zx_cdm_CLASS_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CLASS(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_KEY_s* e;
      for (e = x->KEY; e; e = (struct zx_cdm_KEY_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_KEY(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_DESC_s* e;
      for (e = x->DESC; e; e = (struct zx_cdm_DESC_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_DESC(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      for (e = x->PHYSICALACCESS; e; e = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_PHYSICALACCESS(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CALURI_s* e;
      for (e = x->CALURI; e; e = (struct zx_cdm_CALURI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CALURI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CAPURI_s* e;
      for (e = x->CAPURI; e; e = (struct zx_cdm_CAPURI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CAPURI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      for (e = x->CALADRURI; e; e = (struct zx_cdm_CALADRURI_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_CALADRURI(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cdm_FBURL_s* e;
      for (e = x->FBURL; e; e = (struct zx_cdm_FBURL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cdm_FBURL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_cdm_vCard) */

int zx_WALK_WO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-cdm-aux.c */
