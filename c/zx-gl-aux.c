/* c/zx-gl-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-gl-data.h"



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

#define EL_NAME   gl_AreaComparison
#define EL_STRUCT zx_gl_AreaComparison_s
#define EL_NS     gl
#define EL_TAG    AreaComparison

/* FUNC(zx_FREE_gl_AreaComparison) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->itemID, free_strs);
  zx_free_attr(c, x->returnLocation, free_strs);

  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      for (e = x->CivilData; e; e = en) {
	  en = (struct zx_gl_CivilData_s*)e->gg.g.n;
	  zx_FREE_gl_CivilData(c, e, free_strs);
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      for (e = x->shape; e; e = en) {
	  en = (struct zx_gl_shape_s*)e->gg.g.n;
	  zx_FREE_gl_shape(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_AreaComparison) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_AreaComparison_s* zx_NEW_gl_AreaComparison(struct zx_ctx* c)
{
  struct zx_gl_AreaComparison_s* x = ZX_ZALLOC(c, struct zx_gl_AreaComparison_s);
  x->gg.g.tok = zx_gl_AreaComparison_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_AreaComparison) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->itemID);
  zx_dup_attr(c, x->returnLocation);

  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_shape(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_AreaComparison) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_AreaComparison_s* zx_DEEP_CLONE_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x, int dup_strs)
{
  x = (struct zx_gl_AreaComparison_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_AreaComparison_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->itemID = zx_clone_attr(c, x->itemID);
  x->returnLocation = zx_clone_attr(c, x->returnLocation);

  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      struct zx_gl_CivilData_s* enn;
      for (enn = 0, e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CivilData(c, e, dup_strs);
	  if (!enn)
	      x->CivilData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      struct zx_gl_shape_s* enn;
      for (enn = 0, e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_shape(c, e, dup_strs);
	  if (!enn)
	      x->shape = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_AreaComparison) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CivilData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_shape(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_AreaComparison) */

int zx_WALK_WO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Box
#define EL_STRUCT zx_gl_Box_s
#define EL_NS     gl
#define EL_TAG    Box

/* FUNC(zx_FREE_gl_Box) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Box) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Box_s* zx_NEW_gl_Box(struct zx_ctx* c)
{
  struct zx_gl_Box_s* x = ZX_ZALLOC(c, struct zx_gl_Box_s);
  x->gg.g.tok = zx_gl_Box_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Box) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Box) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Box_s* zx_DEEP_CLONE_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x, int dup_strs)
{
  x = (struct zx_gl_Box_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Box_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Box) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Box) */

int zx_WALK_WO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ChangeArea
#define EL_STRUCT zx_gl_ChangeArea_s
#define EL_NS     gl
#define EL_TAG    ChangeArea

/* FUNC(zx_FREE_gl_ChangeArea) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->event, free_strs);

  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      for (e = x->CivilData; e; e = en) {
	  en = (struct zx_gl_CivilData_s*)e->gg.g.n;
	  zx_FREE_gl_CivilData(c, e, free_strs);
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      for (e = x->shape; e; e = en) {
	  en = (struct zx_gl_shape_s*)e->gg.g.n;
	  zx_FREE_gl_shape(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ChangeArea) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ChangeArea_s* zx_NEW_gl_ChangeArea(struct zx_ctx* c)
{
  struct zx_gl_ChangeArea_s* x = ZX_ZALLOC(c, struct zx_gl_ChangeArea_s);
  x->gg.g.tok = zx_gl_ChangeArea_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ChangeArea) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->event);

  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_shape(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_ChangeArea) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ChangeArea_s* zx_DEEP_CLONE_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x, int dup_strs)
{
  x = (struct zx_gl_ChangeArea_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ChangeArea_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->event = zx_clone_attr(c, x->event);

  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      struct zx_gl_CivilData_s* enn;
      for (enn = 0, e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CivilData(c, e, dup_strs);
	  if (!enn)
	      x->CivilData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      struct zx_gl_shape_s* enn;
      for (enn = 0, e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_shape(c, e, dup_strs);
	  if (!enn)
	      x->shape = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_ChangeArea) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CivilData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_shape(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_ChangeArea) */

int zx_WALK_WO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_CircularArcArea
#define EL_STRUCT zx_gl_CircularArcArea_s
#define EL_NS     gl
#define EL_TAG    CircularArcArea

/* FUNC(zx_FREE_gl_CircularArcArea) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->inRadius, free_strs);
  zx_free_simple_elems(c, x->outRadius, free_strs);
  zx_free_simple_elems(c, x->startAngle, free_strs);
  zx_free_simple_elems(c, x->stopAngle, free_strs);
  zx_free_simple_elems(c, x->angularUnit, free_strs);
  zx_free_simple_elems(c, x->distanceUnit, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_CircularArcArea) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_CircularArcArea_s* zx_NEW_gl_CircularArcArea(struct zx_ctx* c)
{
  struct zx_gl_CircularArcArea_s* x = ZX_ZALLOC(c, struct zx_gl_CircularArcArea_s);
  x->gg.g.tok = zx_gl_CircularArcArea_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_CircularArcArea) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }
  zx_dup_strs_simple_elems(c, x->inRadius);
  zx_dup_strs_simple_elems(c, x->outRadius);
  zx_dup_strs_simple_elems(c, x->startAngle);
  zx_dup_strs_simple_elems(c, x->stopAngle);
  zx_dup_strs_simple_elems(c, x->angularUnit);
  zx_dup_strs_simple_elems(c, x->distanceUnit);

}

/* FUNC(zx_DEEP_CLONE_gl_CircularArcArea) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_CircularArcArea_s* zx_DEEP_CLONE_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x, int dup_strs)
{
  x = (struct zx_gl_CircularArcArea_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_CircularArcArea_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->inRadius = zx_deep_clone_simple_elems(c,x->inRadius, dup_strs);
  x->outRadius = zx_deep_clone_simple_elems(c,x->outRadius, dup_strs);
  x->startAngle = zx_deep_clone_simple_elems(c,x->startAngle, dup_strs);
  x->stopAngle = zx_deep_clone_simple_elems(c,x->stopAngle, dup_strs);
  x->angularUnit = zx_deep_clone_simple_elems(c,x->angularUnit, dup_strs);
  x->distanceUnit = zx_deep_clone_simple_elems(c,x->distanceUnit, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_CircularArcArea) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->inRadius, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->outRadius, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->startAngle, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->stopAngle, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->angularUnit, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->distanceUnit, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_CircularArcArea) */

int zx_WALK_WO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_CircularArea
#define EL_STRUCT zx_gl_CircularArea_s
#define EL_NS     gl
#define EL_TAG    CircularArea

/* FUNC(zx_FREE_gl_CircularArea) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->radius, free_strs);
  zx_free_simple_elems(c, x->distanceUnit, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_CircularArea) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_CircularArea_s* zx_NEW_gl_CircularArea(struct zx_ctx* c)
{
  struct zx_gl_CircularArea_s* x = ZX_ZALLOC(c, struct zx_gl_CircularArea_s);
  x->gg.g.tok = zx_gl_CircularArea_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_CircularArea) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }
  zx_dup_strs_simple_elems(c, x->radius);
  zx_dup_strs_simple_elems(c, x->distanceUnit);

}

/* FUNC(zx_DEEP_CLONE_gl_CircularArea) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_CircularArea_s* zx_DEEP_CLONE_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x, int dup_strs)
{
  x = (struct zx_gl_CircularArea_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_CircularArea_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->radius = zx_deep_clone_simple_elems(c,x->radius, dup_strs);
  x->distanceUnit = zx_deep_clone_simple_elems(c,x->distanceUnit, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_CircularArea) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->radius, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->distanceUnit, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_CircularArea) */

int zx_WALK_WO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_CivilData
#define EL_STRUCT zx_gl_CivilData_s
#define EL_NS     gl
#define EL_TAG    CivilData

/* FUNC(zx_FREE_gl_CivilData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PostalAddress, free_strs);
  {
      struct zx_gl_LPostalAddress_s* e;
      struct zx_gl_LPostalAddress_s* en;
      for (e = x->LPostalAddress; e; e = en) {
	  en = (struct zx_gl_LPostalAddress_s*)e->gg.g.n;
	  zx_FREE_gl_LPostalAddress(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->PostalCode, free_strs);
  zx_free_simple_elems(c, x->L, free_strs);
  {
      struct zx_gl_LL_s* e;
      struct zx_gl_LL_s* en;
      for (e = x->LL; e; e = en) {
	  en = (struct zx_gl_LL_s*)e->gg.g.n;
	  zx_FREE_gl_LL(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->St, free_strs);
  {
      struct zx_gl_LSt_s* e;
      struct zx_gl_LSt_s* en;
      for (e = x->LSt; e; e = en) {
	  en = (struct zx_gl_LSt_s*)e->gg.g.n;
	  zx_FREE_gl_LSt(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->C, free_strs);
  zx_free_simple_elems(c, x->MNC, free_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_CivilData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_CivilData_s* zx_NEW_gl_CivilData(struct zx_ctx* c)
{
  struct zx_gl_CivilData_s* x = ZX_ZALLOC(c, struct zx_gl_CivilData_s);
  x->gg.g.tok = zx_gl_CivilData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_CivilData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PostalAddress);
  {
      struct zx_gl_LPostalAddress_s* e;
      for (e = x->LPostalAddress; e; e = (struct zx_gl_LPostalAddress_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LPostalAddress(c, e);
  }
  zx_dup_strs_simple_elems(c, x->PostalCode);
  zx_dup_strs_simple_elems(c, x->L);
  {
      struct zx_gl_LL_s* e;
      for (e = x->LL; e; e = (struct zx_gl_LL_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LL(c, e);
  }
  zx_dup_strs_simple_elems(c, x->St);
  {
      struct zx_gl_LSt_s* e;
      for (e = x->LSt; e; e = (struct zx_gl_LSt_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LSt(c, e);
  }
  zx_dup_strs_simple_elems(c, x->C);
  zx_dup_strs_simple_elems(c, x->MNC);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_CivilData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_CivilData_s* zx_DEEP_CLONE_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x, int dup_strs)
{
  x = (struct zx_gl_CivilData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_CivilData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PostalAddress = zx_deep_clone_simple_elems(c,x->PostalAddress, dup_strs);
  {
      struct zx_gl_LPostalAddress_s* e;
      struct zx_gl_LPostalAddress_s* en;
      struct zx_gl_LPostalAddress_s* enn;
      for (enn = 0, e = x->LPostalAddress; e; e = (struct zx_gl_LPostalAddress_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LPostalAddress(c, e, dup_strs);
	  if (!enn)
	      x->LPostalAddress = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->PostalCode = zx_deep_clone_simple_elems(c,x->PostalCode, dup_strs);
  x->L = zx_deep_clone_simple_elems(c,x->L, dup_strs);
  {
      struct zx_gl_LL_s* e;
      struct zx_gl_LL_s* en;
      struct zx_gl_LL_s* enn;
      for (enn = 0, e = x->LL; e; e = (struct zx_gl_LL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LL(c, e, dup_strs);
	  if (!enn)
	      x->LL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->St = zx_deep_clone_simple_elems(c,x->St, dup_strs);
  {
      struct zx_gl_LSt_s* e;
      struct zx_gl_LSt_s* en;
      struct zx_gl_LSt_s* enn;
      for (enn = 0, e = x->LSt; e; e = (struct zx_gl_LSt_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LSt(c, e, dup_strs);
	  if (!enn)
	      x->LSt = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->C = zx_deep_clone_simple_elems(c,x->C, dup_strs);
  x->MNC = zx_deep_clone_simple_elems(c,x->MNC, dup_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_CivilData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PostalAddress, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_LPostalAddress_s* e;
      for (e = x->LPostalAddress; e; e = (struct zx_gl_LPostalAddress_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LPostalAddress(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->PostalCode, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->L, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_LL_s* e;
      for (e = x->LL; e; e = (struct zx_gl_LL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->St, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_LSt_s* e;
      for (e = x->LSt; e; e = (struct zx_gl_LSt_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LSt(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->C, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->MNC, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_CivilData) */

int zx_WALK_WO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ComparisonResult
#define EL_STRUCT zx_gl_ComparisonResult_s
#define EL_NS     gl
#define EL_TAG    ComparisonResult

/* FUNC(zx_FREE_gl_ComparisonResult) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ItemIDRef, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ComparisonResult) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ComparisonResult_s* zx_NEW_gl_ComparisonResult(struct zx_ctx* c)
{
  struct zx_gl_ComparisonResult_s* x = ZX_ZALLOC(c, struct zx_gl_ComparisonResult_s);
  x->gg.g.tok = zx_gl_ComparisonResult_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ComparisonResult) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ItemIDRef);


}

/* FUNC(zx_DEEP_CLONE_gl_ComparisonResult) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ComparisonResult_s* zx_DEEP_CLONE_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x, int dup_strs)
{
  x = (struct zx_gl_ComparisonResult_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ComparisonResult_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ItemIDRef = zx_clone_attr(c, x->ItemIDRef);


  return x;
}

/* FUNC(zx_WALK_SO_gl_ComparisonResult) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_ComparisonResult) */

int zx_WALK_WO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_CoordinateReferenceSystem
#define EL_STRUCT zx_gl_CoordinateReferenceSystem_s
#define EL_NS     gl
#define EL_TAG    CoordinateReferenceSystem

/* FUNC(zx_FREE_gl_CoordinateReferenceSystem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_Identifier_s* e;
      struct zx_gl_Identifier_s* en;
      for (e = x->Identifier; e; e = en) {
	  en = (struct zx_gl_Identifier_s*)e->gg.g.n;
	  zx_FREE_gl_Identifier(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_CoordinateReferenceSystem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_CoordinateReferenceSystem_s* zx_NEW_gl_CoordinateReferenceSystem(struct zx_ctx* c)
{
  struct zx_gl_CoordinateReferenceSystem_s* x = ZX_ZALLOC(c, struct zx_gl_CoordinateReferenceSystem_s);
  x->gg.g.tok = zx_gl_CoordinateReferenceSystem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_CoordinateReferenceSystem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_Identifier_s* e;
      for (e = x->Identifier; e; e = (struct zx_gl_Identifier_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Identifier(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_CoordinateReferenceSystem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_CoordinateReferenceSystem_s* zx_DEEP_CLONE_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x, int dup_strs)
{
  x = (struct zx_gl_CoordinateReferenceSystem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_CoordinateReferenceSystem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_Identifier_s* e;
      struct zx_gl_Identifier_s* en;
      struct zx_gl_Identifier_s* enn;
      for (enn = 0, e = x->Identifier; e; e = (struct zx_gl_Identifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Identifier(c, e, dup_strs);
	  if (!enn)
	      x->Identifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_CoordinateReferenceSystem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Identifier_s* e;
      for (e = x->Identifier; e; e = (struct zx_gl_Identifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Identifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_CoordinateReferenceSystem) */

int zx_WALK_WO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Create
#define EL_STRUCT zx_gl_Create_s
#define EL_NS     gl
#define EL_TAG    Create

/* FUNC(zx_FREE_gl_Create) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_gl_ResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      struct zx_gl_Subscription_s* en;
      for (e = x->Subscription; e; e = en) {
	  en = (struct zx_gl_Subscription_s*)e->gg.g.n;
	  zx_FREE_gl_Subscription(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CreateItem_s* e;
      struct zx_gl_CreateItem_s* en;
      for (e = x->CreateItem; e; e = en) {
	  en = (struct zx_gl_CreateItem_s*)e->gg.g.n;
	  zx_FREE_gl_CreateItem(c, e, free_strs);
      }
  }
  {
      struct zx_gl_ItemSelection_s* e;
      struct zx_gl_ItemSelection_s* en;
      for (e = x->ItemSelection; e; e = en) {
	  en = (struct zx_gl_ItemSelection_s*)e->gg.g.n;
	  zx_FREE_gl_ItemSelection(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Create) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Create_s* zx_NEW_gl_Create(struct zx_ctx* c)
{
  struct zx_gl_Create_s* x = ZX_ZALLOC(c, struct zx_gl_Create_s);
  x->gg.g.tok = zx_gl_Create_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Create) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Subscription(c, e);
  }
  {
      struct zx_gl_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_gl_CreateItem_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CreateItem(c, e);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Create) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Create_s* zx_DEEP_CLONE_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x, int dup_strs)
{
  x = (struct zx_gl_Create_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Create_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      struct zx_gl_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      struct zx_gl_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      struct zx_gl_Subscription_s* en;
      struct zx_gl_Subscription_s* enn;
      for (enn = 0, e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Subscription(c, e, dup_strs);
	  if (!enn)
	      x->Subscription = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CreateItem_s* e;
      struct zx_gl_CreateItem_s* en;
      struct zx_gl_CreateItem_s* enn;
      for (enn = 0, e = x->CreateItem; e; e = (struct zx_gl_CreateItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CreateItem(c, e, dup_strs);
	  if (!enn)
	      x->CreateItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_ItemSelection_s* e;
      struct zx_gl_ItemSelection_s* en;
      struct zx_gl_ItemSelection_s* enn;
      for (enn = 0, e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ItemSelection(c, e, dup_strs);
	  if (!enn)
	      x->ItemSelection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Create) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Subscription(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_gl_CreateItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CreateItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ItemSelection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Create) */

int zx_WALK_WO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_CreateItem
#define EL_STRUCT zx_gl_CreateItem_s
#define EL_NS     gl
#define EL_TAG    CreateItem

/* FUNC(zx_FREE_gl_CreateItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->itemID, free_strs);
  zx_free_attr(c, x->objectType, free_strs);

  {
      struct zx_gl_NewData_s* e;
      struct zx_gl_NewData_s* en;
      for (e = x->NewData; e; e = en) {
	  en = (struct zx_gl_NewData_s*)e->gg.g.n;
	  zx_FREE_gl_NewData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_CreateItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_CreateItem_s* zx_NEW_gl_CreateItem(struct zx_ctx* c)
{
  struct zx_gl_CreateItem_s* x = ZX_ZALLOC(c, struct zx_gl_CreateItem_s);
  x->gg.g.tok = zx_gl_CreateItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_CreateItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->itemID);
  zx_dup_attr(c, x->objectType);

  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_NewData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_CreateItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_CreateItem_s* zx_DEEP_CLONE_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x, int dup_strs)
{
  x = (struct zx_gl_CreateItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_CreateItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->itemID = zx_clone_attr(c, x->itemID);
  x->objectType = zx_clone_attr(c, x->objectType);

  {
      struct zx_gl_NewData_s* e;
      struct zx_gl_NewData_s* en;
      struct zx_gl_NewData_s* enn;
      for (enn = 0, e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_NewData(c, e, dup_strs);
	  if (!enn)
	      x->NewData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_CreateItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_NewData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_CreateItem) */

int zx_WALK_WO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_CreateResponse
#define EL_STRUCT zx_gl_CreateResponse_s
#define EL_NS     gl
#define EL_TAG    CreateResponse

/* FUNC(zx_FREE_gl_CreateResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->timeStamp, free_strs);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_gl_Status_s*)e->gg.g.n;
	  zx_FREE_gl_Status(c, e, free_strs);
      }
  }
  {
      struct zx_gl_ItemData_s* e;
      struct zx_gl_ItemData_s* en;
      for (e = x->ItemData; e; e = en) {
	  en = (struct zx_gl_ItemData_s*)e->gg.g.n;
	  zx_FREE_gl_ItemData(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_CreateResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_CreateResponse_s* zx_NEW_gl_CreateResponse(struct zx_ctx* c)
{
  struct zx_gl_CreateResponse_s* x = ZX_ZALLOC(c, struct zx_gl_CreateResponse_s);
  x->gg.g.tok = zx_gl_CreateResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_CreateResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->timeStamp);

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Status(c, e);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ItemData(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_CreateResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_CreateResponse_s* zx_DEEP_CLONE_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x, int dup_strs)
{
  x = (struct zx_gl_CreateResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_CreateResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->timeStamp = zx_clone_attr(c, x->timeStamp);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      struct zx_gl_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_ItemData_s* e;
      struct zx_gl_ItemData_s* en;
      struct zx_gl_ItemData_s* enn;
      for (enn = 0, e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ItemData(c, e, dup_strs);
	  if (!enn)
	      x->ItemData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_CreateResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ItemData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_CreateResponse) */

int zx_WALK_WO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Credential
#define EL_STRUCT zx_gl_Credential_s
#define EL_NS     gl
#define EL_TAG    Credential

/* FUNC(zx_FREE_gl_Credential) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->notOnOrAfter, free_strs);

  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      for (e = x->Assertion; e; e = en) {
	  en = (struct zx_sa_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa_Assertion(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Credential) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Credential_s* zx_NEW_gl_Credential(struct zx_ctx* c)
{
  struct zx_gl_Credential_s* x = ZX_ZALLOC(c, struct zx_gl_Credential_s);
  x->gg.g.tok = zx_gl_Credential_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Credential) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->notOnOrAfter);

  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Assertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Credential) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Credential_s* zx_DEEP_CLONE_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x, int dup_strs)
{
  x = (struct zx_gl_Credential_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Credential_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->notOnOrAfter = zx_clone_attr(c, x->notOnOrAfter);

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

  return x;
}

/* FUNC(zx_WALK_SO_gl_Credential) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Credential) */

int zx_WALK_WO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Data
#define EL_STRUCT zx_gl_Data_s
#define EL_NS     gl
#define EL_TAG    Data

/* FUNC(zx_FREE_gl_Data) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->itemIDRef, free_strs);
  zx_free_attr(c, x->nextOffset, free_strs);
  zx_free_attr(c, x->notSorted, free_strs);
  zx_free_attr(c, x->remaining, free_strs);
  zx_free_attr(c, x->setID, free_strs);
  zx_free_attr(c, x->changeFormat, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Data) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Data_s* zx_NEW_gl_Data(struct zx_ctx* c)
{
  struct zx_gl_Data_s* x = ZX_ZALLOC(c, struct zx_gl_Data_s);
  x->gg.g.tok = zx_gl_Data_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Data) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->itemIDRef);
  zx_dup_attr(c, x->nextOffset);
  zx_dup_attr(c, x->notSorted);
  zx_dup_attr(c, x->remaining);
  zx_dup_attr(c, x->setID);
  zx_dup_attr(c, x->changeFormat);


}

/* FUNC(zx_DEEP_CLONE_gl_Data) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Data_s* zx_DEEP_CLONE_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x, int dup_strs)
{
  x = (struct zx_gl_Data_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Data_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->itemIDRef = zx_clone_attr(c, x->itemIDRef);
  x->nextOffset = zx_clone_attr(c, x->nextOffset);
  x->notSorted = zx_clone_attr(c, x->notSorted);
  x->remaining = zx_clone_attr(c, x->remaining);
  x->setID = zx_clone_attr(c, x->setID);
  x->changeFormat = zx_clone_attr(c, x->changeFormat);


  return x;
}

/* FUNC(zx_WALK_SO_gl_Data) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_Data) */

int zx_WALK_WO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Delete
#define EL_STRUCT zx_gl_Delete_s
#define EL_NS     gl
#define EL_TAG    Delete

/* FUNC(zx_FREE_gl_Delete) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_gl_ResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_DeleteItem_s* e;
      struct zx_gl_DeleteItem_s* en;
      for (e = x->DeleteItem; e; e = en) {
	  en = (struct zx_gl_DeleteItem_s*)e->gg.g.n;
	  zx_FREE_gl_DeleteItem(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Delete) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Delete_s* zx_NEW_gl_Delete(struct zx_ctx* c)
{
  struct zx_gl_Delete_s* x = ZX_ZALLOC(c, struct zx_gl_Delete_s);
  x->gg.g.tok = zx_gl_Delete_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Delete) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_gl_DeleteItem_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_DeleteItem(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Delete) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Delete_s* zx_DEEP_CLONE_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x, int dup_strs)
{
  x = (struct zx_gl_Delete_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Delete_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      struct zx_gl_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      struct zx_gl_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_DeleteItem_s* e;
      struct zx_gl_DeleteItem_s* en;
      struct zx_gl_DeleteItem_s* enn;
      for (enn = 0, e = x->DeleteItem; e; e = (struct zx_gl_DeleteItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_DeleteItem(c, e, dup_strs);
	  if (!enn)
	      x->DeleteItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Delete) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_gl_DeleteItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_DeleteItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Delete) */

int zx_WALK_WO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_DeleteItem
#define EL_STRUCT zx_gl_DeleteItem_s
#define EL_NS     gl
#define EL_TAG    DeleteItem

/* FUNC(zx_FREE_gl_DeleteItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->itemID, free_strs);
  zx_free_attr(c, x->notChangedSince, free_strs);
  zx_free_attr(c, x->objectType, free_strs);
  zx_free_attr(c, x->predefined, free_strs);

  zx_free_simple_elems(c, x->Select, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_DeleteItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_DeleteItem_s* zx_NEW_gl_DeleteItem(struct zx_ctx* c)
{
  struct zx_gl_DeleteItem_s* x = ZX_ZALLOC(c, struct zx_gl_DeleteItem_s);
  x->gg.g.tok = zx_gl_DeleteItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_DeleteItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->itemID);
  zx_dup_attr(c, x->notChangedSince);
  zx_dup_attr(c, x->objectType);
  zx_dup_attr(c, x->predefined);

  zx_dup_strs_simple_elems(c, x->Select);

}

/* FUNC(zx_DEEP_CLONE_gl_DeleteItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_DeleteItem_s* zx_DEEP_CLONE_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x, int dup_strs)
{
  x = (struct zx_gl_DeleteItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_DeleteItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->itemID = zx_clone_attr(c, x->itemID);
  x->notChangedSince = zx_clone_attr(c, x->notChangedSince);
  x->objectType = zx_clone_attr(c, x->objectType);
  x->predefined = zx_clone_attr(c, x->predefined);

  x->Select = zx_deep_clone_simple_elems(c,x->Select, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_DeleteItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Select, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_DeleteItem) */

int zx_WALK_WO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_DeleteResponse
#define EL_STRUCT zx_gl_DeleteResponse_s
#define EL_NS     gl
#define EL_TAG    DeleteResponse

/* FUNC(zx_FREE_gl_DeleteResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_gl_Status_s*)e->gg.g.n;
	  zx_FREE_gl_Status(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_DeleteResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_DeleteResponse_s* zx_NEW_gl_DeleteResponse(struct zx_ctx* c)
{
  struct zx_gl_DeleteResponse_s* x = ZX_ZALLOC(c, struct zx_gl_DeleteResponse_s);
  x->gg.g.tok = zx_gl_DeleteResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_DeleteResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Status(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_DeleteResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_DeleteResponse_s* zx_DEEP_CLONE_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x, int dup_strs)
{
  x = (struct zx_gl_DeleteResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_DeleteResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      struct zx_gl_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_DeleteResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_DeleteResponse) */

int zx_WALK_WO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_EllipticalArea
#define EL_STRUCT zx_gl_EllipticalArea_s
#define EL_NS     gl
#define EL_TAG    EllipticalArea

/* FUNC(zx_FREE_gl_EllipticalArea) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->angle, free_strs);
  zx_free_simple_elems(c, x->semiMajor, free_strs);
  zx_free_simple_elems(c, x->semiMinor, free_strs);
  zx_free_simple_elems(c, x->angularUnit, free_strs);
  zx_free_simple_elems(c, x->distanceUnit, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_EllipticalArea) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_EllipticalArea_s* zx_NEW_gl_EllipticalArea(struct zx_ctx* c)
{
  struct zx_gl_EllipticalArea_s* x = ZX_ZALLOC(c, struct zx_gl_EllipticalArea_s);
  x->gg.g.tok = zx_gl_EllipticalArea_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_EllipticalArea) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }
  zx_dup_strs_simple_elems(c, x->angle);
  zx_dup_strs_simple_elems(c, x->semiMajor);
  zx_dup_strs_simple_elems(c, x->semiMinor);
  zx_dup_strs_simple_elems(c, x->angularUnit);
  zx_dup_strs_simple_elems(c, x->distanceUnit);

}

/* FUNC(zx_DEEP_CLONE_gl_EllipticalArea) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_EllipticalArea_s* zx_DEEP_CLONE_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x, int dup_strs)
{
  x = (struct zx_gl_EllipticalArea_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_EllipticalArea_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->angle = zx_deep_clone_simple_elems(c,x->angle, dup_strs);
  x->semiMajor = zx_deep_clone_simple_elems(c,x->semiMajor, dup_strs);
  x->semiMinor = zx_deep_clone_simple_elems(c,x->semiMinor, dup_strs);
  x->angularUnit = zx_deep_clone_simple_elems(c,x->angularUnit, dup_strs);
  x->distanceUnit = zx_deep_clone_simple_elems(c,x->distanceUnit, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_EllipticalArea) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->angle, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->semiMajor, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->semiMinor, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->angularUnit, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->distanceUnit, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_EllipticalArea) */

int zx_WALK_WO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_EncryptedResourceID
#define EL_STRUCT zx_gl_EncryptedResourceID_s
#define EL_NS     gl
#define EL_TAG    EncryptedResourceID

/* FUNC(zx_FREE_gl_EncryptedResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x, int free_strs)
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

/* FUNC(zx_NEW_gl_EncryptedResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_EncryptedResourceID_s* zx_NEW_gl_EncryptedResourceID(struct zx_ctx* c)
{
  struct zx_gl_EncryptedResourceID_s* x = ZX_ZALLOC(c, struct zx_gl_EncryptedResourceID_s);
  x->gg.g.tok = zx_gl_EncryptedResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_EncryptedResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x)
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

/* FUNC(zx_DEEP_CLONE_gl_EncryptedResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_EncryptedResourceID_s* zx_DEEP_CLONE_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x, int dup_strs)
{
  x = (struct zx_gl_EncryptedResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_EncryptedResourceID_s), dup_strs);
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

/* FUNC(zx_WALK_SO_gl_EncryptedResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_EncryptedResourceID) */

int zx_WALK_WO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Extension
#define EL_STRUCT zx_gl_Extension_s
#define EL_NS     gl
#define EL_TAG    Extension

/* FUNC(zx_FREE_gl_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Extension_s* zx_NEW_gl_Extension(struct zx_ctx* c)
{
  struct zx_gl_Extension_s* x = ZX_ZALLOC(c, struct zx_gl_Extension_s);
  x->gg.g.tok = zx_gl_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_gl_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Extension_s* zx_DEEP_CLONE_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x, int dup_strs)
{
  x = (struct zx_gl_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_gl_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_Extension) */

int zx_WALK_WO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_GeometryCollection
#define EL_STRUCT zx_gl_GeometryCollection_s
#define EL_NS     gl
#define EL_TAG    GeometryCollection

/* FUNC(zx_FREE_gl_GeometryCollection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      for (e = x->shape; e; e = en) {
	  en = (struct zx_gl_shape_s*)e->gg.g.n;
	  zx_FREE_gl_shape(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_GeometryCollection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_GeometryCollection_s* zx_NEW_gl_GeometryCollection(struct zx_ctx* c)
{
  struct zx_gl_GeometryCollection_s* x = ZX_ZALLOC(c, struct zx_gl_GeometryCollection_s);
  x->gg.g.tok = zx_gl_GeometryCollection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_GeometryCollection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_shape(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_GeometryCollection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_GeometryCollection_s* zx_DEEP_CLONE_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x, int dup_strs)
{
  x = (struct zx_gl_GeometryCollection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_GeometryCollection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      struct zx_gl_shape_s* enn;
      for (enn = 0, e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_shape(c, e, dup_strs);
	  if (!enn)
	      x->shape = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_GeometryCollection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_shape(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_GeometryCollection) */

int zx_WALK_WO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Identifier
#define EL_STRUCT zx_gl_Identifier_s
#define EL_NS     gl
#define EL_TAG    Identifier

/* FUNC(zx_FREE_gl_Identifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->code, free_strs);
  zx_free_simple_elems(c, x->codeSpace, free_strs);
  zx_free_simple_elems(c, x->edition, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Identifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Identifier_s* zx_NEW_gl_Identifier(struct zx_ctx* c)
{
  struct zx_gl_Identifier_s* x = ZX_ZALLOC(c, struct zx_gl_Identifier_s);
  x->gg.g.tok = zx_gl_Identifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Identifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->code);
  zx_dup_strs_simple_elems(c, x->codeSpace);
  zx_dup_strs_simple_elems(c, x->edition);

}

/* FUNC(zx_DEEP_CLONE_gl_Identifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Identifier_s* zx_DEEP_CLONE_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x, int dup_strs)
{
  x = (struct zx_gl_Identifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Identifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->code = zx_deep_clone_simple_elems(c,x->code, dup_strs);
  x->codeSpace = zx_deep_clone_simple_elems(c,x->codeSpace, dup_strs);
  x->edition = zx_deep_clone_simple_elems(c,x->edition, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_Identifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->code, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->codeSpace, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->edition, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Identifier) */

int zx_WALK_WO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ItemData
#define EL_STRUCT zx_gl_ItemData_s
#define EL_NS     gl
#define EL_TAG    ItemData

/* FUNC(zx_FREE_gl_ItemData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->itemIDRef, free_strs);
  zx_free_attr(c, x->notSorted, free_strs);
  zx_free_attr(c, x->changeFormat, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ItemData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ItemData_s* zx_NEW_gl_ItemData(struct zx_ctx* c)
{
  struct zx_gl_ItemData_s* x = ZX_ZALLOC(c, struct zx_gl_ItemData_s);
  x->gg.g.tok = zx_gl_ItemData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ItemData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->itemIDRef);
  zx_dup_attr(c, x->notSorted);
  zx_dup_attr(c, x->changeFormat);


}

/* FUNC(zx_DEEP_CLONE_gl_ItemData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ItemData_s* zx_DEEP_CLONE_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x, int dup_strs)
{
  x = (struct zx_gl_ItemData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ItemData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->itemIDRef = zx_clone_attr(c, x->itemIDRef);
  x->notSorted = zx_clone_attr(c, x->notSorted);
  x->changeFormat = zx_clone_attr(c, x->changeFormat);


  return x;
}

/* FUNC(zx_WALK_SO_gl_ItemData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_ItemData) */

int zx_WALK_WO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ItemSelection
#define EL_STRUCT zx_gl_ItemSelection_s
#define EL_NS     gl
#define EL_TAG    ItemSelection

/* FUNC(zx_FREE_gl_ItemSelection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_AreaComparison_s* e;
      struct zx_gl_AreaComparison_s* en;
      for (e = x->AreaComparison; e; e = en) {
	  en = (struct zx_gl_AreaComparison_s*)e->gg.g.n;
	  zx_FREE_gl_AreaComparison(c, e, free_strs);
      }
  }
  {
      struct zx_gl_eqop_s* e;
      struct zx_gl_eqop_s* en;
      for (e = x->eqop; e; e = en) {
	  en = (struct zx_gl_eqop_s*)e->gg.g.n;
	  zx_FREE_gl_eqop(c, e, free_strs);
      }
  }
  {
      struct zx_gl_geoinfo_s* e;
      struct zx_gl_geoinfo_s* en;
      for (e = x->geoinfo; e; e = en) {
	  en = (struct zx_gl_geoinfo_s*)e->gg.g.n;
	  zx_FREE_gl_geoinfo(c, e, free_strs);
      }
  }
  {
      struct zx_gl_loc_type_s* e;
      struct zx_gl_loc_type_s* en;
      for (e = x->loc_type; e; e = en) {
	  en = (struct zx_gl_loc_type_s*)e->gg.g.n;
	  zx_FREE_gl_loc_type(c, e, free_strs);
      }
  }
  {
      struct zx_gl_prio_s* e;
      struct zx_gl_prio_s* en;
      for (e = x->prio; e; e = en) {
	  en = (struct zx_gl_prio_s*)e->gg.g.n;
	  zx_FREE_gl_prio(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ItemSelection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ItemSelection_s* zx_NEW_gl_ItemSelection(struct zx_ctx* c)
{
  struct zx_gl_ItemSelection_s* x = ZX_ZALLOC(c, struct zx_gl_ItemSelection_s);
  x->gg.g.tok = zx_gl_ItemSelection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ItemSelection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_AreaComparison(c, e);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_eqop(c, e);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_geoinfo(c, e);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_loc_type(c, e);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_prio(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_ItemSelection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ItemSelection_s* zx_DEEP_CLONE_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x, int dup_strs)
{
  x = (struct zx_gl_ItemSelection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ItemSelection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_AreaComparison_s* e;
      struct zx_gl_AreaComparison_s* en;
      struct zx_gl_AreaComparison_s* enn;
      for (enn = 0, e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_AreaComparison(c, e, dup_strs);
	  if (!enn)
	      x->AreaComparison = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_eqop_s* e;
      struct zx_gl_eqop_s* en;
      struct zx_gl_eqop_s* enn;
      for (enn = 0, e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_eqop(c, e, dup_strs);
	  if (!enn)
	      x->eqop = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_geoinfo_s* e;
      struct zx_gl_geoinfo_s* en;
      struct zx_gl_geoinfo_s* enn;
      for (enn = 0, e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_geoinfo(c, e, dup_strs);
	  if (!enn)
	      x->geoinfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_loc_type_s* e;
      struct zx_gl_loc_type_s* en;
      struct zx_gl_loc_type_s* enn;
      for (enn = 0, e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_loc_type(c, e, dup_strs);
	  if (!enn)
	      x->loc_type = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_prio_s* e;
      struct zx_gl_prio_s* en;
      struct zx_gl_prio_s* enn;
      for (enn = 0, e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_prio(c, e, dup_strs);
	  if (!enn)
	      x->prio = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_ItemSelection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_AreaComparison(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_eqop(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_geoinfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_loc_type(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_prio(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_ItemSelection) */

int zx_WALK_WO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_LL
#define EL_STRUCT zx_gl_LL_s
#define EL_NS     gl
#define EL_TAG    LL

/* FUNC(zx_FREE_gl_LL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);
  zx_free_attr(c, x->script, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_LL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_LL_s* zx_NEW_gl_LL(struct zx_ctx* c)
{
  struct zx_gl_LL_s* x = ZX_ZALLOC(c, struct zx_gl_LL_s);
  x->gg.g.tok = zx_gl_LL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_LL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);
  zx_dup_attr(c, x->script);


}

/* FUNC(zx_DEEP_CLONE_gl_LL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_LL_s* zx_DEEP_CLONE_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x, int dup_strs)
{
  x = (struct zx_gl_LL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_LL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);
  x->script = zx_clone_attr(c, x->script);


  return x;
}

/* FUNC(zx_WALK_SO_gl_LL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_LL) */

int zx_WALK_WO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_LPostalAddress
#define EL_STRUCT zx_gl_LPostalAddress_s
#define EL_NS     gl
#define EL_TAG    LPostalAddress

/* FUNC(zx_FREE_gl_LPostalAddress) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);
  zx_free_attr(c, x->script, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_LPostalAddress) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_LPostalAddress_s* zx_NEW_gl_LPostalAddress(struct zx_ctx* c)
{
  struct zx_gl_LPostalAddress_s* x = ZX_ZALLOC(c, struct zx_gl_LPostalAddress_s);
  x->gg.g.tok = zx_gl_LPostalAddress_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_LPostalAddress) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);
  zx_dup_attr(c, x->script);


}

/* FUNC(zx_DEEP_CLONE_gl_LPostalAddress) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_LPostalAddress_s* zx_DEEP_CLONE_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x, int dup_strs)
{
  x = (struct zx_gl_LPostalAddress_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_LPostalAddress_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);
  x->script = zx_clone_attr(c, x->script);


  return x;
}

/* FUNC(zx_WALK_SO_gl_LPostalAddress) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_LPostalAddress) */

int zx_WALK_WO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_LSt
#define EL_STRUCT zx_gl_LSt_s
#define EL_NS     gl
#define EL_TAG    LSt

/* FUNC(zx_FREE_gl_LSt) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->lang, free_strs);
  zx_free_attr(c, x->script, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_LSt) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_LSt_s* zx_NEW_gl_LSt(struct zx_ctx* c)
{
  struct zx_gl_LSt_s* x = ZX_ZALLOC(c, struct zx_gl_LSt_s);
  x->gg.g.tok = zx_gl_LSt_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_LSt) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->lang);
  zx_dup_attr(c, x->script);


}

/* FUNC(zx_DEEP_CLONE_gl_LSt) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_LSt_s* zx_DEEP_CLONE_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x, int dup_strs)
{
  x = (struct zx_gl_LSt_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_LSt_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->lang = zx_clone_attr(c, x->lang);
  x->script = zx_clone_attr(c, x->script);


  return x;
}

/* FUNC(zx_WALK_SO_gl_LSt) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_LSt) */

int zx_WALK_WO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_LineString
#define EL_STRUCT zx_gl_LineString_s
#define EL_NS     gl
#define EL_TAG    LineString

/* FUNC(zx_FREE_gl_LineString) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_LineString) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_LineString_s* zx_NEW_gl_LineString(struct zx_ctx* c)
{
  struct zx_gl_LineString_s* x = ZX_ZALLOC(c, struct zx_gl_LineString_s);
  x->gg.g.tok = zx_gl_LineString_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_LineString) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_LineString) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_LineString_s* zx_DEEP_CLONE_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x, int dup_strs)
{
  x = (struct zx_gl_LineString_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_LineString_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_LineString) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_LineString) */

int zx_WALK_WO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_LinearRing
#define EL_STRUCT zx_gl_LinearRing_s
#define EL_NS     gl
#define EL_TAG    LinearRing

/* FUNC(zx_FREE_gl_LinearRing) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_LinearRing) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_LinearRing_s* zx_NEW_gl_LinearRing(struct zx_ctx* c)
{
  struct zx_gl_LinearRing_s* x = ZX_ZALLOC(c, struct zx_gl_LinearRing_s);
  x->gg.g.tok = zx_gl_LinearRing_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_LinearRing) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_LinearRing) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_LinearRing_s* zx_DEEP_CLONE_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x, int dup_strs)
{
  x = (struct zx_gl_LinearRing_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_LinearRing_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_LinearRing) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_LinearRing) */

int zx_WALK_WO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Modification
#define EL_STRUCT zx_gl_Modification_s
#define EL_NS     gl
#define EL_TAG    Modification

/* FUNC(zx_FREE_gl_Modification) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->itemID, free_strs);
  zx_free_attr(c, x->notChangedSince, free_strs);
  zx_free_attr(c, x->objectType, free_strs);
  zx_free_attr(c, x->overrideAllowed, free_strs);

  zx_free_simple_elems(c, x->Select, free_strs);
  {
      struct zx_gl_NewData_s* e;
      struct zx_gl_NewData_s* en;
      for (e = x->NewData; e; e = en) {
	  en = (struct zx_gl_NewData_s*)e->gg.g.n;
	  zx_FREE_gl_NewData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Modification) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Modification_s* zx_NEW_gl_Modification(struct zx_ctx* c)
{
  struct zx_gl_Modification_s* x = ZX_ZALLOC(c, struct zx_gl_Modification_s);
  x->gg.g.tok = zx_gl_Modification_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Modification) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->itemID);
  zx_dup_attr(c, x->notChangedSince);
  zx_dup_attr(c, x->objectType);
  zx_dup_attr(c, x->overrideAllowed);

  zx_dup_strs_simple_elems(c, x->Select);
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_NewData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Modification) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Modification_s* zx_DEEP_CLONE_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x, int dup_strs)
{
  x = (struct zx_gl_Modification_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Modification_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->itemID = zx_clone_attr(c, x->itemID);
  x->notChangedSince = zx_clone_attr(c, x->notChangedSince);
  x->objectType = zx_clone_attr(c, x->objectType);
  x->overrideAllowed = zx_clone_attr(c, x->overrideAllowed);

  x->Select = zx_deep_clone_simple_elems(c,x->Select, dup_strs);
  {
      struct zx_gl_NewData_s* e;
      struct zx_gl_NewData_s* en;
      struct zx_gl_NewData_s* enn;
      for (enn = 0, e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_NewData(c, e, dup_strs);
	  if (!enn)
	      x->NewData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Modification) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Select, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_NewData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Modification) */

int zx_WALK_WO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Modify
#define EL_STRUCT zx_gl_Modify_s
#define EL_NS     gl
#define EL_TAG    Modify

/* FUNC(zx_FREE_gl_Modify) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_gl_ResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      struct zx_gl_Subscription_s* en;
      for (e = x->Subscription; e; e = en) {
	  en = (struct zx_gl_Subscription_s*)e->gg.g.n;
	  zx_FREE_gl_Subscription(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Modification_s* e;
      struct zx_gl_Modification_s* en;
      for (e = x->Modification; e; e = en) {
	  en = (struct zx_gl_Modification_s*)e->gg.g.n;
	  zx_FREE_gl_Modification(c, e, free_strs);
      }
  }
  {
      struct zx_gl_ItemSelection_s* e;
      struct zx_gl_ItemSelection_s* en;
      for (e = x->ItemSelection; e; e = en) {
	  en = (struct zx_gl_ItemSelection_s*)e->gg.g.n;
	  zx_FREE_gl_ItemSelection(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Modify) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Modify_s* zx_NEW_gl_Modify(struct zx_ctx* c)
{
  struct zx_gl_Modify_s* x = ZX_ZALLOC(c, struct zx_gl_Modify_s);
  x->gg.g.tok = zx_gl_Modify_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Modify) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Subscription(c, e);
  }
  {
      struct zx_gl_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_gl_Modification_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Modification(c, e);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Modify) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Modify_s* zx_DEEP_CLONE_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x, int dup_strs)
{
  x = (struct zx_gl_Modify_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Modify_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      struct zx_gl_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      struct zx_gl_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      struct zx_gl_Subscription_s* en;
      struct zx_gl_Subscription_s* enn;
      for (enn = 0, e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Subscription(c, e, dup_strs);
	  if (!enn)
	      x->Subscription = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Modification_s* e;
      struct zx_gl_Modification_s* en;
      struct zx_gl_Modification_s* enn;
      for (enn = 0, e = x->Modification; e; e = (struct zx_gl_Modification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Modification(c, e, dup_strs);
	  if (!enn)
	      x->Modification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_ItemSelection_s* e;
      struct zx_gl_ItemSelection_s* en;
      struct zx_gl_ItemSelection_s* enn;
      for (enn = 0, e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ItemSelection(c, e, dup_strs);
	  if (!enn)
	      x->ItemSelection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Modify) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Subscription(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_gl_Modification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Modification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ItemSelection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Modify) */

int zx_WALK_WO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ModifyResponse
#define EL_STRUCT zx_gl_ModifyResponse_s
#define EL_NS     gl
#define EL_TAG    ModifyResponse

/* FUNC(zx_FREE_gl_ModifyResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->timeStamp, free_strs);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_gl_Status_s*)e->gg.g.n;
	  zx_FREE_gl_Status(c, e, free_strs);
      }
  }
  {
      struct zx_gl_ItemData_s* e;
      struct zx_gl_ItemData_s* en;
      for (e = x->ItemData; e; e = en) {
	  en = (struct zx_gl_ItemData_s*)e->gg.g.n;
	  zx_FREE_gl_ItemData(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ModifyResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ModifyResponse_s* zx_NEW_gl_ModifyResponse(struct zx_ctx* c)
{
  struct zx_gl_ModifyResponse_s* x = ZX_ZALLOC(c, struct zx_gl_ModifyResponse_s);
  x->gg.g.tok = zx_gl_ModifyResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ModifyResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->timeStamp);

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Status(c, e);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ItemData(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_ModifyResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ModifyResponse_s* zx_DEEP_CLONE_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x, int dup_strs)
{
  x = (struct zx_gl_ModifyResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ModifyResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->timeStamp = zx_clone_attr(c, x->timeStamp);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      struct zx_gl_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_ItemData_s* e;
      struct zx_gl_ItemData_s* en;
      struct zx_gl_ItemData_s* enn;
      for (enn = 0, e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ItemData(c, e, dup_strs);
	  if (!enn)
	      x->ItemData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_ModifyResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ItemData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_ModifyResponse) */

int zx_WALK_WO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_MultiLineString
#define EL_STRUCT zx_gl_MultiLineString_s
#define EL_NS     gl
#define EL_TAG    MultiLineString

/* FUNC(zx_FREE_gl_MultiLineString) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_LineString_s* e;
      struct zx_gl_LineString_s* en;
      for (e = x->LineString; e; e = en) {
	  en = (struct zx_gl_LineString_s*)e->gg.g.n;
	  zx_FREE_gl_LineString(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_MultiLineString) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_MultiLineString_s* zx_NEW_gl_MultiLineString(struct zx_ctx* c)
{
  struct zx_gl_MultiLineString_s* x = ZX_ZALLOC(c, struct zx_gl_MultiLineString_s);
  x->gg.g.tok = zx_gl_MultiLineString_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_MultiLineString) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LineString(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_MultiLineString) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_MultiLineString_s* zx_DEEP_CLONE_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x, int dup_strs)
{
  x = (struct zx_gl_MultiLineString_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_MultiLineString_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_LineString_s* e;
      struct zx_gl_LineString_s* en;
      struct zx_gl_LineString_s* enn;
      for (enn = 0, e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LineString(c, e, dup_strs);
	  if (!enn)
	      x->LineString = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_MultiLineString) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LineString(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_MultiLineString) */

int zx_WALK_WO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_MultiPoint
#define EL_STRUCT zx_gl_MultiPoint_s
#define EL_NS     gl
#define EL_TAG    MultiPoint

/* FUNC(zx_FREE_gl_MultiPoint) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_Point_s* e;
      struct zx_gl_Point_s* en;
      for (e = x->Point; e; e = en) {
	  en = (struct zx_gl_Point_s*)e->gg.g.n;
	  zx_FREE_gl_Point(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_MultiPoint) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_MultiPoint_s* zx_NEW_gl_MultiPoint(struct zx_ctx* c)
{
  struct zx_gl_MultiPoint_s* x = ZX_ZALLOC(c, struct zx_gl_MultiPoint_s);
  x->gg.g.tok = zx_gl_MultiPoint_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_MultiPoint) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Point(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_MultiPoint) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_MultiPoint_s* zx_DEEP_CLONE_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x, int dup_strs)
{
  x = (struct zx_gl_MultiPoint_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_MultiPoint_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_Point_s* e;
      struct zx_gl_Point_s* en;
      struct zx_gl_Point_s* enn;
      for (enn = 0, e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Point(c, e, dup_strs);
	  if (!enn)
	      x->Point = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_MultiPoint) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Point(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_MultiPoint) */

int zx_WALK_WO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_MultiPolygon
#define EL_STRUCT zx_gl_MultiPolygon_s
#define EL_NS     gl
#define EL_TAG    MultiPolygon

/* FUNC(zx_FREE_gl_MultiPolygon) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_Polygon_s* e;
      struct zx_gl_Polygon_s* en;
      for (e = x->Polygon; e; e = en) {
	  en = (struct zx_gl_Polygon_s*)e->gg.g.n;
	  zx_FREE_gl_Polygon(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Box_s* e;
      struct zx_gl_Box_s* en;
      for (e = x->Box; e; e = en) {
	  en = (struct zx_gl_Box_s*)e->gg.g.n;
	  zx_FREE_gl_Box(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CircularArea_s* e;
      struct zx_gl_CircularArea_s* en;
      for (e = x->CircularArea; e; e = en) {
	  en = (struct zx_gl_CircularArea_s*)e->gg.g.n;
	  zx_FREE_gl_CircularArea(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      struct zx_gl_CircularArcArea_s* en;
      for (e = x->CircularArcArea; e; e = en) {
	  en = (struct zx_gl_CircularArcArea_s*)e->gg.g.n;
	  zx_FREE_gl_CircularArcArea(c, e, free_strs);
      }
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      struct zx_gl_EllipticalArea_s* en;
      for (e = x->EllipticalArea; e; e = en) {
	  en = (struct zx_gl_EllipticalArea_s*)e->gg.g.n;
	  zx_FREE_gl_EllipticalArea(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_MultiPolygon) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_MultiPolygon_s* zx_NEW_gl_MultiPolygon(struct zx_ctx* c)
{
  struct zx_gl_MultiPolygon_s* x = ZX_ZALLOC(c, struct zx_gl_MultiPolygon_s);
  x->gg.g.tok = zx_gl_MultiPolygon_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_MultiPolygon) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Polygon(c, e);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Box(c, e);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CircularArea(c, e);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CircularArcArea(c, e);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_EllipticalArea(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_MultiPolygon) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_MultiPolygon_s* zx_DEEP_CLONE_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x, int dup_strs)
{
  x = (struct zx_gl_MultiPolygon_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_MultiPolygon_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_Polygon_s* e;
      struct zx_gl_Polygon_s* en;
      struct zx_gl_Polygon_s* enn;
      for (enn = 0, e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Polygon(c, e, dup_strs);
	  if (!enn)
	      x->Polygon = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Box_s* e;
      struct zx_gl_Box_s* en;
      struct zx_gl_Box_s* enn;
      for (enn = 0, e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Box(c, e, dup_strs);
	  if (!enn)
	      x->Box = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CircularArea_s* e;
      struct zx_gl_CircularArea_s* en;
      struct zx_gl_CircularArea_s* enn;
      for (enn = 0, e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CircularArea(c, e, dup_strs);
	  if (!enn)
	      x->CircularArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      struct zx_gl_CircularArcArea_s* en;
      struct zx_gl_CircularArcArea_s* enn;
      for (enn = 0, e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CircularArcArea(c, e, dup_strs);
	  if (!enn)
	      x->CircularArcArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      struct zx_gl_EllipticalArea_s* en;
      struct zx_gl_EllipticalArea_s* enn;
      for (enn = 0, e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_EllipticalArea(c, e, dup_strs);
	  if (!enn)
	      x->EllipticalArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_MultiPolygon) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Polygon(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Box(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CircularArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CircularArcArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_EllipticalArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_MultiPolygon) */

int zx_WALK_WO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_NewData
#define EL_STRUCT zx_gl_NewData_s
#define EL_NS     gl
#define EL_TAG    NewData

/* FUNC(zx_FREE_gl_NewData) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_NewData) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_NewData_s* zx_NEW_gl_NewData(struct zx_ctx* c)
{
  struct zx_gl_NewData_s* x = ZX_ZALLOC(c, struct zx_gl_NewData_s);
  x->gg.g.tok = zx_gl_NewData_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_NewData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_gl_NewData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_NewData_s* zx_DEEP_CLONE_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x, int dup_strs)
{
  x = (struct zx_gl_NewData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_NewData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_gl_NewData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_NewData) */

int zx_WALK_WO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Notification
#define EL_STRUCT zx_gl_Notification_s
#define EL_NS     gl
#define EL_TAG    Notification

/* FUNC(zx_FREE_gl_Notification) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->endReason, free_strs);
  zx_free_attr(c, x->expires, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->subscriptionID, free_strs);

  {
      struct zx_gl_ItemData_s* e;
      struct zx_gl_ItemData_s* en;
      for (e = x->ItemData; e; e = en) {
	  en = (struct zx_gl_ItemData_s*)e->gg.g.n;
	  zx_FREE_gl_ItemData(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Notification) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Notification_s* zx_NEW_gl_Notification(struct zx_ctx* c)
{
  struct zx_gl_Notification_s* x = ZX_ZALLOC(c, struct zx_gl_Notification_s);
  x->gg.g.tok = zx_gl_Notification_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Notification) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->endReason);
  zx_dup_attr(c, x->expires);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->subscriptionID);

  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ItemData(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Notification) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Notification_s* zx_DEEP_CLONE_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x, int dup_strs)
{
  x = (struct zx_gl_Notification_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Notification_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->endReason = zx_clone_attr(c, x->endReason);
  x->expires = zx_clone_attr(c, x->expires);
  x->id = zx_clone_attr(c, x->id);
  x->subscriptionID = zx_clone_attr(c, x->subscriptionID);

  {
      struct zx_gl_ItemData_s* e;
      struct zx_gl_ItemData_s* en;
      struct zx_gl_ItemData_s* enn;
      for (enn = 0, e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ItemData(c, e, dup_strs);
	  if (!enn)
	      x->ItemData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Notification) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ItemData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Notification) */

int zx_WALK_WO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Notify
#define EL_STRUCT zx_gl_Notify_s
#define EL_NS     gl
#define EL_TAG    Notify

/* FUNC(zx_FREE_gl_Notify) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->timeStamp, free_strs);

  {
      struct zx_gl_Notification_s* e;
      struct zx_gl_Notification_s* en;
      for (e = x->Notification; e; e = en) {
	  en = (struct zx_gl_Notification_s*)e->gg.g.n;
	  zx_FREE_gl_Notification(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Notify) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Notify_s* zx_NEW_gl_Notify(struct zx_ctx* c)
{
  struct zx_gl_Notify_s* x = ZX_ZALLOC(c, struct zx_gl_Notify_s);
  x->gg.g.tok = zx_gl_Notify_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Notify) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->timeStamp);

  {
      struct zx_gl_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_gl_Notification_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Notification(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Notify) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Notify_s* zx_DEEP_CLONE_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x, int dup_strs)
{
  x = (struct zx_gl_Notify_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Notify_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->timeStamp = zx_clone_attr(c, x->timeStamp);

  {
      struct zx_gl_Notification_s* e;
      struct zx_gl_Notification_s* en;
      struct zx_gl_Notification_s* enn;
      for (enn = 0, e = x->Notification; e; e = (struct zx_gl_Notification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Notification(c, e, dup_strs);
	  if (!enn)
	      x->Notification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Notify) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_gl_Notification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Notification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Notify) */

int zx_WALK_WO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_NotifyAdminTo
#define EL_STRUCT zx_gl_NotifyAdminTo_s
#define EL_NS     gl
#define EL_TAG    NotifyAdminTo

/* FUNC(zx_FREE_gl_NotifyAdminTo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  zx_free_simple_elems(c, x->SecurityMechID, free_strs);
  {
      struct zx_gl_Credential_s* e;
      struct zx_gl_Credential_s* en;
      for (e = x->Credential; e; e = en) {
	  en = (struct zx_gl_Credential_s*)e->gg.g.n;
	  zx_FREE_gl_Credential(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Endpoint, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_NotifyAdminTo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_NotifyAdminTo_s* zx_NEW_gl_NotifyAdminTo(struct zx_ctx* c)
{
  struct zx_gl_NotifyAdminTo_s* x = ZX_ZALLOC(c, struct zx_gl_NotifyAdminTo_s);
  x->gg.g.tok = zx_gl_NotifyAdminTo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_NotifyAdminTo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  zx_dup_strs_simple_elems(c, x->SecurityMechID);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Credential(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Endpoint);

}

/* FUNC(zx_DEEP_CLONE_gl_NotifyAdminTo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_NotifyAdminTo_s* zx_DEEP_CLONE_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x, int dup_strs)
{
  x = (struct zx_gl_NotifyAdminTo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_NotifyAdminTo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);
  {
      struct zx_gl_Credential_s* e;
      struct zx_gl_Credential_s* en;
      struct zx_gl_Credential_s* enn;
      for (enn = 0, e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Credential(c, e, dup_strs);
	  if (!enn)
	      x->Credential = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Endpoint = zx_deep_clone_simple_elems(c,x->Endpoint, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_NotifyAdminTo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SecurityMechID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Credential(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Endpoint, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_NotifyAdminTo) */

int zx_WALK_WO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_NotifyResponse
#define EL_STRUCT zx_gl_NotifyResponse_s
#define EL_NS     gl
#define EL_TAG    NotifyResponse

/* FUNC(zx_FREE_gl_NotifyResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_gl_Status_s*)e->gg.g.n;
	  zx_FREE_gl_Status(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_NotifyResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_NotifyResponse_s* zx_NEW_gl_NotifyResponse(struct zx_ctx* c)
{
  struct zx_gl_NotifyResponse_s* x = ZX_ZALLOC(c, struct zx_gl_NotifyResponse_s);
  x->gg.g.tok = zx_gl_NotifyResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_NotifyResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Status(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_NotifyResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_NotifyResponse_s* zx_DEEP_CLONE_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x, int dup_strs)
{
  x = (struct zx_gl_NotifyResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_NotifyResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      struct zx_gl_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_NotifyResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_NotifyResponse) */

int zx_WALK_WO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_NotifyTo
#define EL_STRUCT zx_gl_NotifyTo_s
#define EL_NS     gl
#define EL_TAG    NotifyTo

/* FUNC(zx_FREE_gl_NotifyTo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  zx_free_simple_elems(c, x->SecurityMechID, free_strs);
  {
      struct zx_gl_Credential_s* e;
      struct zx_gl_Credential_s* en;
      for (e = x->Credential; e; e = en) {
	  en = (struct zx_gl_Credential_s*)e->gg.g.n;
	  zx_FREE_gl_Credential(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Endpoint, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_NotifyTo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_NotifyTo_s* zx_NEW_gl_NotifyTo(struct zx_ctx* c)
{
  struct zx_gl_NotifyTo_s* x = ZX_ZALLOC(c, struct zx_gl_NotifyTo_s);
  x->gg.g.tok = zx_gl_NotifyTo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_NotifyTo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  zx_dup_strs_simple_elems(c, x->SecurityMechID);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Credential(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Endpoint);

}

/* FUNC(zx_DEEP_CLONE_gl_NotifyTo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_NotifyTo_s* zx_DEEP_CLONE_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x, int dup_strs)
{
  x = (struct zx_gl_NotifyTo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_NotifyTo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  x->SecurityMechID = zx_deep_clone_simple_elems(c,x->SecurityMechID, dup_strs);
  {
      struct zx_gl_Credential_s* e;
      struct zx_gl_Credential_s* en;
      struct zx_gl_Credential_s* enn;
      for (enn = 0, e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Credential(c, e, dup_strs);
	  if (!enn)
	      x->Credential = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Endpoint = zx_deep_clone_simple_elems(c,x->Endpoint, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_NotifyTo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->SecurityMechID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Credential(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Endpoint, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_NotifyTo) */

int zx_WALK_WO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Point
#define EL_STRUCT zx_gl_Point_s
#define EL_NS     gl
#define EL_TAG    Point

/* FUNC(zx_FREE_gl_Point) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      for (e = x->coord; e; e = en) {
	  en = (struct zx_gl_coord_s*)e->gg.g.n;
	  zx_FREE_gl_coord(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Point) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Point_s* zx_NEW_gl_Point(struct zx_ctx* c)
{
  struct zx_gl_Point_s* x = ZX_ZALLOC(c, struct zx_gl_Point_s);
  x->gg.g.tok = zx_gl_Point_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Point) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_coord(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Point) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Point_s* zx_DEEP_CLONE_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x, int dup_strs)
{
  x = (struct zx_gl_Point_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Point_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_coord_s* e;
      struct zx_gl_coord_s* en;
      struct zx_gl_coord_s* enn;
      for (enn = 0, e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_coord(c, e, dup_strs);
	  if (!enn)
	      x->coord = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Point) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_coord(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Point) */

int zx_WALK_WO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Polygon
#define EL_STRUCT zx_gl_Polygon_s
#define EL_NS     gl
#define EL_TAG    Polygon

/* FUNC(zx_FREE_gl_Polygon) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->gid, free_strs);
  zx_free_attr(c, x->srsName, free_strs);

  {
      struct zx_gl_outerBoundaryIs_s* e;
      struct zx_gl_outerBoundaryIs_s* en;
      for (e = x->outerBoundaryIs; e; e = en) {
	  en = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n;
	  zx_FREE_gl_outerBoundaryIs(c, e, free_strs);
      }
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      struct zx_gl_innerBoundaryIs_s* en;
      for (e = x->innerBoundaryIs; e; e = en) {
	  en = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n;
	  zx_FREE_gl_innerBoundaryIs(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Polygon) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Polygon_s* zx_NEW_gl_Polygon(struct zx_ctx* c)
{
  struct zx_gl_Polygon_s* x = ZX_ZALLOC(c, struct zx_gl_Polygon_s);
  x->gg.g.tok = zx_gl_Polygon_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Polygon) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->gid);
  zx_dup_attr(c, x->srsName);

  {
      struct zx_gl_outerBoundaryIs_s* e;
      for (e = x->outerBoundaryIs; e; e = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_outerBoundaryIs(c, e);
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      for (e = x->innerBoundaryIs; e; e = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_innerBoundaryIs(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Polygon) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Polygon_s* zx_DEEP_CLONE_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x, int dup_strs)
{
  x = (struct zx_gl_Polygon_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Polygon_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->gid = zx_clone_attr(c, x->gid);
  x->srsName = zx_clone_attr(c, x->srsName);

  {
      struct zx_gl_outerBoundaryIs_s* e;
      struct zx_gl_outerBoundaryIs_s* en;
      struct zx_gl_outerBoundaryIs_s* enn;
      for (enn = 0, e = x->outerBoundaryIs; e; e = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_outerBoundaryIs(c, e, dup_strs);
	  if (!enn)
	      x->outerBoundaryIs = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      struct zx_gl_innerBoundaryIs_s* en;
      struct zx_gl_innerBoundaryIs_s* enn;
      for (enn = 0, e = x->innerBoundaryIs; e; e = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_innerBoundaryIs(c, e, dup_strs);
	  if (!enn)
	      x->innerBoundaryIs = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Polygon) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_outerBoundaryIs_s* e;
      for (e = x->outerBoundaryIs; e; e = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_outerBoundaryIs(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      for (e = x->innerBoundaryIs; e; e = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_innerBoundaryIs(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Polygon) */

int zx_WALK_WO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Query
#define EL_STRUCT zx_gl_Query_s
#define EL_NS     gl
#define EL_TAG    Query

/* FUNC(zx_FREE_gl_Query) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      for (e = x->ResourceID; e; e = en) {
	  en = (struct zx_gl_ResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_ResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      for (e = x->EncryptedResourceID; e; e = en) {
	  en = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n;
	  zx_FREE_gl_EncryptedResourceID(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      struct zx_gl_Subscription_s* en;
      for (e = x->Subscription; e; e = en) {
	  en = (struct zx_gl_Subscription_s*)e->gg.g.n;
	  zx_FREE_gl_Subscription(c, e, free_strs);
      }
  }
  {
      struct zx_gl_QueryItem_s* e;
      struct zx_gl_QueryItem_s* en;
      for (e = x->QueryItem; e; e = en) {
	  en = (struct zx_gl_QueryItem_s*)e->gg.g.n;
	  zx_FREE_gl_QueryItem(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Query) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Query_s* zx_NEW_gl_Query(struct zx_ctx* c)
{
  struct zx_gl_Query_s* x = ZX_ZALLOC(c, struct zx_gl_Query_s);
  x->gg.g.tok = zx_gl_Query_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Query) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Subscription(c, e);
  }
  {
      struct zx_gl_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_gl_QueryItem_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_QueryItem(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Query) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Query_s* zx_DEEP_CLONE_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x, int dup_strs)
{
  x = (struct zx_gl_Query_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Query_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_gl_ResourceID_s* e;
      struct zx_gl_ResourceID_s* en;
      struct zx_gl_ResourceID_s* enn;
      for (enn = 0, e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ResourceID(c, e, dup_strs);
	  if (!enn)
	      x->ResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      struct zx_gl_EncryptedResourceID_s* en;
      struct zx_gl_EncryptedResourceID_s* enn;
      for (enn = 0, e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_EncryptedResourceID(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedResourceID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      struct zx_gl_Subscription_s* en;
      struct zx_gl_Subscription_s* enn;
      for (enn = 0, e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Subscription(c, e, dup_strs);
	  if (!enn)
	      x->Subscription = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_QueryItem_s* e;
      struct zx_gl_QueryItem_s* en;
      struct zx_gl_QueryItem_s* enn;
      for (enn = 0, e = x->QueryItem; e; e = (struct zx_gl_QueryItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_QueryItem(c, e, dup_strs);
	  if (!enn)
	      x->QueryItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Query) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_EncryptedResourceID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Subscription(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_gl_QueryItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_QueryItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Query) */

int zx_WALK_WO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_QueryItem
#define EL_STRUCT zx_gl_QueryItem_s
#define EL_NS     gl
#define EL_TAG    QueryItem

/* FUNC(zx_FREE_gl_QueryItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->count, free_strs);
  zx_free_attr(c, x->offset, free_strs);
  zx_free_attr(c, x->setID, free_strs);
  zx_free_attr(c, x->setReq, free_strs);

  {
      struct zx_gl_AreaComparison_s* e;
      struct zx_gl_AreaComparison_s* en;
      for (e = x->AreaComparison; e; e = en) {
	  en = (struct zx_gl_AreaComparison_s*)e->gg.g.n;
	  zx_FREE_gl_AreaComparison(c, e, free_strs);
      }
  }
  {
      struct zx_gl_eqop_s* e;
      struct zx_gl_eqop_s* en;
      for (e = x->eqop; e; e = en) {
	  en = (struct zx_gl_eqop_s*)e->gg.g.n;
	  zx_FREE_gl_eqop(c, e, free_strs);
      }
  }
  {
      struct zx_gl_geoinfo_s* e;
      struct zx_gl_geoinfo_s* en;
      for (e = x->geoinfo; e; e = en) {
	  en = (struct zx_gl_geoinfo_s*)e->gg.g.n;
	  zx_FREE_gl_geoinfo(c, e, free_strs);
      }
  }
  {
      struct zx_gl_loc_type_s* e;
      struct zx_gl_loc_type_s* en;
      for (e = x->loc_type; e; e = en) {
	  en = (struct zx_gl_loc_type_s*)e->gg.g.n;
	  zx_FREE_gl_loc_type(c, e, free_strs);
      }
  }
  {
      struct zx_gl_prio_s* e;
      struct zx_gl_prio_s* en;
      for (e = x->prio; e; e = en) {
	  en = (struct zx_gl_prio_s*)e->gg.g.n;
	  zx_FREE_gl_prio(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_QueryItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_QueryItem_s* zx_NEW_gl_QueryItem(struct zx_ctx* c)
{
  struct zx_gl_QueryItem_s* x = ZX_ZALLOC(c, struct zx_gl_QueryItem_s);
  x->gg.g.tok = zx_gl_QueryItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_QueryItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->count);
  zx_dup_attr(c, x->offset);
  zx_dup_attr(c, x->setID);
  zx_dup_attr(c, x->setReq);

  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_AreaComparison(c, e);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_eqop(c, e);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_geoinfo(c, e);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_loc_type(c, e);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_prio(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_QueryItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_QueryItem_s* zx_DEEP_CLONE_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x, int dup_strs)
{
  x = (struct zx_gl_QueryItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_QueryItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->count = zx_clone_attr(c, x->count);
  x->offset = zx_clone_attr(c, x->offset);
  x->setID = zx_clone_attr(c, x->setID);
  x->setReq = zx_clone_attr(c, x->setReq);

  {
      struct zx_gl_AreaComparison_s* e;
      struct zx_gl_AreaComparison_s* en;
      struct zx_gl_AreaComparison_s* enn;
      for (enn = 0, e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_AreaComparison(c, e, dup_strs);
	  if (!enn)
	      x->AreaComparison = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_eqop_s* e;
      struct zx_gl_eqop_s* en;
      struct zx_gl_eqop_s* enn;
      for (enn = 0, e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_eqop(c, e, dup_strs);
	  if (!enn)
	      x->eqop = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_geoinfo_s* e;
      struct zx_gl_geoinfo_s* en;
      struct zx_gl_geoinfo_s* enn;
      for (enn = 0, e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_geoinfo(c, e, dup_strs);
	  if (!enn)
	      x->geoinfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_loc_type_s* e;
      struct zx_gl_loc_type_s* en;
      struct zx_gl_loc_type_s* enn;
      for (enn = 0, e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_loc_type(c, e, dup_strs);
	  if (!enn)
	      x->loc_type = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_prio_s* e;
      struct zx_gl_prio_s* en;
      struct zx_gl_prio_s* enn;
      for (enn = 0, e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_prio(c, e, dup_strs);
	  if (!enn)
	      x->prio = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_QueryItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_AreaComparison(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_eqop(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_geoinfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_loc_type(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_prio(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_QueryItem) */

int zx_WALK_WO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_QueryResponse
#define EL_STRUCT zx_gl_QueryResponse_s
#define EL_NS     gl
#define EL_TAG    QueryResponse

/* FUNC(zx_FREE_gl_QueryResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->itemIDRef, free_strs);
  zx_free_attr(c, x->timeStamp, free_strs);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_gl_Status_s*)e->gg.g.n;
	  zx_FREE_gl_Status(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Data_s* e;
      struct zx_gl_Data_s* en;
      for (e = x->Data; e; e = en) {
	  en = (struct zx_gl_Data_s*)e->gg.g.n;
	  zx_FREE_gl_Data(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_QueryResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_QueryResponse_s* zx_NEW_gl_QueryResponse(struct zx_ctx* c)
{
  struct zx_gl_QueryResponse_s* x = ZX_ZALLOC(c, struct zx_gl_QueryResponse_s);
  x->gg.g.tok = zx_gl_QueryResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_QueryResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->itemIDRef);
  zx_dup_attr(c, x->timeStamp);

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Status(c, e);
  }
  {
      struct zx_gl_Data_s* e;
      for (e = x->Data; e; e = (struct zx_gl_Data_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Data(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_QueryResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_QueryResponse_s* zx_DEEP_CLONE_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x, int dup_strs)
{
  x = (struct zx_gl_QueryResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_QueryResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->itemIDRef = zx_clone_attr(c, x->itemIDRef);
  x->timeStamp = zx_clone_attr(c, x->timeStamp);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      struct zx_gl_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Data_s* e;
      struct zx_gl_Data_s* en;
      struct zx_gl_Data_s* enn;
      for (enn = 0, e = x->Data; e; e = (struct zx_gl_Data_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Data(c, e, dup_strs);
	  if (!enn)
	      x->Data = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_QueryResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Data_s* e;
      for (e = x->Data; e; e = (struct zx_gl_Data_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Data(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_QueryResponse) */

int zx_WALK_WO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_RefItem
#define EL_STRUCT zx_gl_RefItem_s
#define EL_NS     gl
#define EL_TAG    RefItem

/* FUNC(zx_FREE_gl_RefItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ItemIDRef, free_strs);
  zx_free_attr(c, x->subscriptionID, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_RefItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_RefItem_s* zx_NEW_gl_RefItem(struct zx_ctx* c)
{
  struct zx_gl_RefItem_s* x = ZX_ZALLOC(c, struct zx_gl_RefItem_s);
  x->gg.g.tok = zx_gl_RefItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_RefItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ItemIDRef);
  zx_dup_attr(c, x->subscriptionID);


}

/* FUNC(zx_DEEP_CLONE_gl_RefItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_RefItem_s* zx_DEEP_CLONE_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x, int dup_strs)
{
  x = (struct zx_gl_RefItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_RefItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ItemIDRef = zx_clone_attr(c, x->ItemIDRef);
  x->subscriptionID = zx_clone_attr(c, x->subscriptionID);


  return x;
}

/* FUNC(zx_WALK_SO_gl_RefItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_RefItem) */

int zx_WALK_WO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ResourceID
#define EL_STRUCT zx_gl_ResourceID_s
#define EL_NS     gl
#define EL_TAG    ResourceID

/* FUNC(zx_FREE_gl_ResourceID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ResourceID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ResourceID_s* zx_NEW_gl_ResourceID(struct zx_ctx* c)
{
  struct zx_gl_ResourceID_s* x = ZX_ZALLOC(c, struct zx_gl_ResourceID_s);
  x->gg.g.tok = zx_gl_ResourceID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ResourceID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);


}

/* FUNC(zx_DEEP_CLONE_gl_ResourceID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ResourceID_s* zx_DEEP_CLONE_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x, int dup_strs)
{
  x = (struct zx_gl_ResourceID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ResourceID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);


  return x;
}

/* FUNC(zx_WALK_SO_gl_ResourceID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_ResourceID) */

int zx_WALK_WO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Status
#define EL_STRUCT zx_gl_Status_s
#define EL_NS     gl
#define EL_TAG    Status

/* FUNC(zx_FREE_gl_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->code, free_strs);
  zx_free_attr(c, x->comment, free_strs);
  zx_free_attr(c, x->ref, free_strs);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_gl_Status_s*)e->gg.g.n;
	  zx_FREE_gl_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Status_s* zx_NEW_gl_Status(struct zx_ctx* c)
{
  struct zx_gl_Status_s* x = ZX_ZALLOC(c, struct zx_gl_Status_s);
  x->gg.g.tok = zx_gl_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->code);
  zx_dup_attr(c, x->comment);
  zx_dup_attr(c, x->ref);

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Status_s* zx_DEEP_CLONE_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x, int dup_strs)
{
  x = (struct zx_gl_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->code = zx_clone_attr(c, x->code);
  x->comment = zx_clone_attr(c, x->comment);
  x->ref = zx_clone_attr(c, x->ref);

  {
      struct zx_gl_Status_s* e;
      struct zx_gl_Status_s* en;
      struct zx_gl_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Status) */

int zx_WALK_WO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Subscription
#define EL_STRUCT zx_gl_Subscription_s
#define EL_NS     gl
#define EL_TAG    Subscription

/* FUNC(zx_FREE_gl_Subscription) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->expires, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->includeData, free_strs);
  zx_free_attr(c, x->starts, free_strs);
  zx_free_attr(c, x->subscriptionID, free_strs);

  {
      struct zx_gl_ItemSelection_s* e;
      struct zx_gl_ItemSelection_s* en;
      for (e = x->ItemSelection; e; e = en) {
	  en = (struct zx_gl_ItemSelection_s*)e->gg.g.n;
	  zx_FREE_gl_ItemSelection(c, e, free_strs);
      }
  }
  {
      struct zx_gl_RefItem_s* e;
      struct zx_gl_RefItem_s* en;
      for (e = x->RefItem; e; e = en) {
	  en = (struct zx_gl_RefItem_s*)e->gg.g.n;
	  zx_FREE_gl_RefItem(c, e, free_strs);
      }
  }
  {
      struct zx_gl_NotifyTo_s* e;
      struct zx_gl_NotifyTo_s* en;
      for (e = x->NotifyTo; e; e = en) {
	  en = (struct zx_gl_NotifyTo_s*)e->gg.g.n;
	  zx_FREE_gl_NotifyTo(c, e, free_strs);
      }
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      struct zx_gl_NotifyAdminTo_s* en;
      for (e = x->NotifyAdminTo; e; e = en) {
	  en = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n;
	  zx_FREE_gl_NotifyAdminTo(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Aggregation, free_strs);
  {
      struct zx_gl_Trigger_s* e;
      struct zx_gl_Trigger_s* en;
      for (e = x->Trigger; e; e = en) {
	  en = (struct zx_gl_Trigger_s*)e->gg.g.n;
	  zx_FREE_gl_Trigger(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Subscription) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Subscription_s* zx_NEW_gl_Subscription(struct zx_ctx* c)
{
  struct zx_gl_Subscription_s* x = ZX_ZALLOC(c, struct zx_gl_Subscription_s);
  x->gg.g.tok = zx_gl_Subscription_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Subscription) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->expires);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->includeData);
  zx_dup_attr(c, x->starts);
  zx_dup_attr(c, x->subscriptionID);

  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_gl_RefItem_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_RefItem(c, e);
  }
  {
      struct zx_gl_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_gl_NotifyTo_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_NotifyTo(c, e);
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_NotifyAdminTo(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Aggregation);
  {
      struct zx_gl_Trigger_s* e;
      for (e = x->Trigger; e; e = (struct zx_gl_Trigger_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Trigger(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Subscription) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Subscription_s* zx_DEEP_CLONE_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x, int dup_strs)
{
  x = (struct zx_gl_Subscription_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Subscription_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->expires = zx_clone_attr(c, x->expires);
  x->id = zx_clone_attr(c, x->id);
  x->includeData = zx_clone_attr(c, x->includeData);
  x->starts = zx_clone_attr(c, x->starts);
  x->subscriptionID = zx_clone_attr(c, x->subscriptionID);

  {
      struct zx_gl_ItemSelection_s* e;
      struct zx_gl_ItemSelection_s* en;
      struct zx_gl_ItemSelection_s* enn;
      for (enn = 0, e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ItemSelection(c, e, dup_strs);
	  if (!enn)
	      x->ItemSelection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_RefItem_s* e;
      struct zx_gl_RefItem_s* en;
      struct zx_gl_RefItem_s* enn;
      for (enn = 0, e = x->RefItem; e; e = (struct zx_gl_RefItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_RefItem(c, e, dup_strs);
	  if (!enn)
	      x->RefItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_NotifyTo_s* e;
      struct zx_gl_NotifyTo_s* en;
      struct zx_gl_NotifyTo_s* enn;
      for (enn = 0, e = x->NotifyTo; e; e = (struct zx_gl_NotifyTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_NotifyTo(c, e, dup_strs);
	  if (!enn)
	      x->NotifyTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      struct zx_gl_NotifyAdminTo_s* en;
      struct zx_gl_NotifyAdminTo_s* enn;
      for (enn = 0, e = x->NotifyAdminTo; e; e = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_NotifyAdminTo(c, e, dup_strs);
	  if (!enn)
	      x->NotifyAdminTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Aggregation = zx_deep_clone_simple_elems(c,x->Aggregation, dup_strs);
  {
      struct zx_gl_Trigger_s* e;
      struct zx_gl_Trigger_s* en;
      struct zx_gl_Trigger_s* enn;
      for (enn = 0, e = x->Trigger; e; e = (struct zx_gl_Trigger_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Trigger(c, e, dup_strs);
	  if (!enn)
	      x->Trigger = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Subscription) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ItemSelection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_gl_RefItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_RefItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_gl_NotifyTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_NotifyTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_NotifyAdminTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Aggregation, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Trigger_s* e;
      for (e = x->Trigger; e; e = (struct zx_gl_Trigger_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Trigger(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Subscription) */

int zx_WALK_WO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_Trigger
#define EL_STRUCT zx_gl_Trigger_s
#define EL_NS     gl
#define EL_TAG    Trigger

/* FUNC(zx_FREE_gl_Trigger) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Granularity, free_strs);
  zx_free_simple_elems(c, x->Interval, free_strs);
  {
      struct zx_gl_ms_action_s* e;
      struct zx_gl_ms_action_s* en;
      for (e = x->ms_action; e; e = en) {
	  en = (struct zx_gl_ms_action_s*)e->gg.g.n;
	  zx_FREE_gl_ms_action(c, e, free_strs);
      }
  }
  {
      struct zx_gl_ChangeArea_s* e;
      struct zx_gl_ChangeArea_s* en;
      for (e = x->ChangeArea; e; e = en) {
	  en = (struct zx_gl_ChangeArea_s*)e->gg.g.n;
	  zx_FREE_gl_ChangeArea(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_Trigger) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_Trigger_s* zx_NEW_gl_Trigger(struct zx_ctx* c)
{
  struct zx_gl_Trigger_s* x = ZX_ZALLOC(c, struct zx_gl_Trigger_s);
  x->gg.g.tok = zx_gl_Trigger_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_Trigger) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Granularity);
  zx_dup_strs_simple_elems(c, x->Interval);
  {
      struct zx_gl_ms_action_s* e;
      for (e = x->ms_action; e; e = (struct zx_gl_ms_action_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ms_action(c, e);
  }
  {
      struct zx_gl_ChangeArea_s* e;
      for (e = x->ChangeArea; e; e = (struct zx_gl_ChangeArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ChangeArea(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_Trigger) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_Trigger_s* zx_DEEP_CLONE_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x, int dup_strs)
{
  x = (struct zx_gl_Trigger_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_Trigger_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Granularity = zx_deep_clone_simple_elems(c,x->Granularity, dup_strs);
  x->Interval = zx_deep_clone_simple_elems(c,x->Interval, dup_strs);
  {
      struct zx_gl_ms_action_s* e;
      struct zx_gl_ms_action_s* en;
      struct zx_gl_ms_action_s* enn;
      for (enn = 0, e = x->ms_action; e; e = (struct zx_gl_ms_action_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ms_action(c, e, dup_strs);
	  if (!enn)
	      x->ms_action = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_ChangeArea_s* e;
      struct zx_gl_ChangeArea_s* en;
      struct zx_gl_ChangeArea_s* enn;
      for (enn = 0, e = x->ChangeArea; e; e = (struct zx_gl_ChangeArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ChangeArea(c, e, dup_strs);
	  if (!enn)
	      x->ChangeArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_Trigger) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Granularity, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Interval, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_ms_action_s* e;
      for (e = x->ms_action; e; e = (struct zx_gl_ms_action_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ms_action(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_ChangeArea_s* e;
      for (e = x->ChangeArea; e; e = (struct zx_gl_ChangeArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ChangeArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_Trigger) */

int zx_WALK_WO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_coord
#define EL_STRUCT zx_gl_coord_s
#define EL_NS     gl
#define EL_TAG    coord

/* FUNC(zx_FREE_gl_coord) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->X, free_strs);
  zx_free_simple_elems(c, x->Y, free_strs);
  zx_free_simple_elems(c, x->Z, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_coord) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_coord_s* zx_NEW_gl_coord(struct zx_ctx* c)
{
  struct zx_gl_coord_s* x = ZX_ZALLOC(c, struct zx_gl_coord_s);
  x->gg.g.tok = zx_gl_coord_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_coord) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->X);
  zx_dup_strs_simple_elems(c, x->Y);
  zx_dup_strs_simple_elems(c, x->Z);

}

/* FUNC(zx_DEEP_CLONE_gl_coord) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_coord_s* zx_DEEP_CLONE_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x, int dup_strs)
{
  x = (struct zx_gl_coord_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_coord_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->X = zx_deep_clone_simple_elems(c,x->X, dup_strs);
  x->Y = zx_deep_clone_simple_elems(c,x->Y, dup_strs);
  x->Z = zx_deep_clone_simple_elems(c,x->Z, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_gl_coord) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->X, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Y, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Z, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_coord) */

int zx_WALK_WO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_eqop
#define EL_STRUCT zx_gl_eqop_s
#define EL_NS     gl
#define EL_TAG    eqop

/* FUNC(zx_FREE_gl_eqop) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_resp_req_s* e;
      struct zx_gl_resp_req_s* en;
      for (e = x->resp_req; e; e = en) {
	  en = (struct zx_gl_resp_req_s*)e->gg.g.n;
	  zx_FREE_gl_resp_req(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ll_acc, free_strs);
  zx_free_simple_elems(c, x->hor_acc, free_strs);
  zx_free_simple_elems(c, x->alt_acc, free_strs);
  zx_free_simple_elems(c, x->max_loc_age, free_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_eqop) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_eqop_s* zx_NEW_gl_eqop(struct zx_ctx* c)
{
  struct zx_gl_eqop_s* x = ZX_ZALLOC(c, struct zx_gl_eqop_s);
  x->gg.g.tok = zx_gl_eqop_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_eqop) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_resp_req_s* e;
      for (e = x->resp_req; e; e = (struct zx_gl_resp_req_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_resp_req(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ll_acc);
  zx_dup_strs_simple_elems(c, x->hor_acc);
  zx_dup_strs_simple_elems(c, x->alt_acc);
  zx_dup_strs_simple_elems(c, x->max_loc_age);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_eqop) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_eqop_s* zx_DEEP_CLONE_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x, int dup_strs)
{
  x = (struct zx_gl_eqop_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_eqop_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_resp_req_s* e;
      struct zx_gl_resp_req_s* en;
      struct zx_gl_resp_req_s* enn;
      for (enn = 0, e = x->resp_req; e; e = (struct zx_gl_resp_req_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_resp_req(c, e, dup_strs);
	  if (!enn)
	      x->resp_req = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ll_acc = zx_deep_clone_simple_elems(c,x->ll_acc, dup_strs);
  x->hor_acc = zx_deep_clone_simple_elems(c,x->hor_acc, dup_strs);
  x->alt_acc = zx_deep_clone_simple_elems(c,x->alt_acc, dup_strs);
  x->max_loc_age = zx_deep_clone_simple_elems(c,x->max_loc_age, dup_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_eqop) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_resp_req_s* e;
      for (e = x->resp_req; e; e = (struct zx_gl_resp_req_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_resp_req(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ll_acc, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->hor_acc, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->alt_acc, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->max_loc_age, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_eqop) */

int zx_WALK_WO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_esrd
#define EL_STRUCT zx_gl_esrd_s
#define EL_NS     gl
#define EL_TAG    esrd

/* FUNC(zx_FREE_gl_esrd) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_esrd) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_esrd_s* zx_NEW_gl_esrd(struct zx_ctx* c)
{
  struct zx_gl_esrd_s* x = ZX_ZALLOC(c, struct zx_gl_esrd_s);
  x->gg.g.tok = zx_gl_esrd_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_esrd) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_gl_esrd) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_esrd_s* zx_DEEP_CLONE_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x, int dup_strs)
{
  x = (struct zx_gl_esrd_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_esrd_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_gl_esrd) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_esrd) */

int zx_WALK_WO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_esrk
#define EL_STRUCT zx_gl_esrk_s
#define EL_NS     gl
#define EL_TAG    esrk

/* FUNC(zx_FREE_gl_esrk) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_esrk) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_esrk_s* zx_NEW_gl_esrk(struct zx_ctx* c)
{
  struct zx_gl_esrk_s* x = ZX_ZALLOC(c, struct zx_gl_esrk_s);
  x->gg.g.tok = zx_gl_esrk_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_esrk) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_gl_esrk) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_esrk_s* zx_DEEP_CLONE_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x, int dup_strs)
{
  x = (struct zx_gl_esrk_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_esrk_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_gl_esrk) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_esrk) */

int zx_WALK_WO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_geoinfo
#define EL_STRUCT zx_gl_geoinfo_s
#define EL_NS     gl
#define EL_TAG    geoinfo

/* FUNC(zx_FREE_gl_geoinfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_CoordinateReferenceSystem_s* e;
      struct zx_gl_CoordinateReferenceSystem_s* en;
      for (e = x->CoordinateReferenceSystem; e; e = en) {
	  en = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n;
	  zx_FREE_gl_CoordinateReferenceSystem(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      for (e = x->CivilData; e; e = en) {
	  en = (struct zx_gl_CivilData_s*)e->gg.g.n;
	  zx_FREE_gl_CivilData(c, e, free_strs);
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      for (e = x->shape; e; e = en) {
	  en = (struct zx_gl_shape_s*)e->gg.g.n;
	  zx_FREE_gl_shape(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->speed, free_strs);
  zx_free_simple_elems(c, x->alt, free_strs);
  zx_free_simple_elems(c, x->direction, free_strs);
  zx_free_simple_elems(c, x->Heading, free_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_geoinfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_geoinfo_s* zx_NEW_gl_geoinfo(struct zx_ctx* c)
{
  struct zx_gl_geoinfo_s* x = ZX_ZALLOC(c, struct zx_gl_geoinfo_s);
  x->gg.g.tok = zx_gl_geoinfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_geoinfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_CoordinateReferenceSystem_s* e;
      for (e = x->CoordinateReferenceSystem; e; e = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CoordinateReferenceSystem(c, e);
  }
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_shape(c, e);
  }
  zx_dup_strs_simple_elems(c, x->speed);
  zx_dup_strs_simple_elems(c, x->alt);
  zx_dup_strs_simple_elems(c, x->direction);
  zx_dup_strs_simple_elems(c, x->Heading);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_geoinfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_geoinfo_s* zx_DEEP_CLONE_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x, int dup_strs)
{
  x = (struct zx_gl_geoinfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_geoinfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_CoordinateReferenceSystem_s* e;
      struct zx_gl_CoordinateReferenceSystem_s* en;
      struct zx_gl_CoordinateReferenceSystem_s* enn;
      for (enn = 0, e = x->CoordinateReferenceSystem; e; e = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CoordinateReferenceSystem(c, e, dup_strs);
	  if (!enn)
	      x->CoordinateReferenceSystem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      struct zx_gl_CivilData_s* enn;
      for (enn = 0, e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CivilData(c, e, dup_strs);
	  if (!enn)
	      x->CivilData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      struct zx_gl_shape_s* enn;
      for (enn = 0, e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_shape(c, e, dup_strs);
	  if (!enn)
	      x->shape = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->speed = zx_deep_clone_simple_elems(c,x->speed, dup_strs);
  x->alt = zx_deep_clone_simple_elems(c,x->alt, dup_strs);
  x->direction = zx_deep_clone_simple_elems(c,x->direction, dup_strs);
  x->Heading = zx_deep_clone_simple_elems(c,x->Heading, dup_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_geoinfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_CoordinateReferenceSystem_s* e;
      for (e = x->CoordinateReferenceSystem; e; e = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CoordinateReferenceSystem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CivilData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_shape(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->speed, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->alt, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->direction, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Heading, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_geoinfo) */

int zx_WALK_WO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_innerBoundaryIs
#define EL_STRUCT zx_gl_innerBoundaryIs_s
#define EL_NS     gl
#define EL_TAG    innerBoundaryIs

/* FUNC(zx_FREE_gl_innerBoundaryIs) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_LinearRing_s* e;
      struct zx_gl_LinearRing_s* en;
      for (e = x->LinearRing; e; e = en) {
	  en = (struct zx_gl_LinearRing_s*)e->gg.g.n;
	  zx_FREE_gl_LinearRing(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_innerBoundaryIs) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_innerBoundaryIs_s* zx_NEW_gl_innerBoundaryIs(struct zx_ctx* c)
{
  struct zx_gl_innerBoundaryIs_s* x = ZX_ZALLOC(c, struct zx_gl_innerBoundaryIs_s);
  x->gg.g.tok = zx_gl_innerBoundaryIs_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_innerBoundaryIs) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LinearRing(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_innerBoundaryIs) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_innerBoundaryIs_s* zx_DEEP_CLONE_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x, int dup_strs)
{
  x = (struct zx_gl_innerBoundaryIs_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_innerBoundaryIs_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_LinearRing_s* e;
      struct zx_gl_LinearRing_s* en;
      struct zx_gl_LinearRing_s* enn;
      for (enn = 0, e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LinearRing(c, e, dup_strs);
	  if (!enn)
	      x->LinearRing = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_innerBoundaryIs) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LinearRing(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_innerBoundaryIs) */

int zx_WALK_WO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_loc_type
#define EL_STRUCT zx_gl_loc_type_s
#define EL_NS     gl
#define EL_TAG    loc_type

/* FUNC(zx_FREE_gl_loc_type) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_loc_type) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_loc_type_s* zx_NEW_gl_loc_type(struct zx_ctx* c)
{
  struct zx_gl_loc_type_s* x = ZX_ZALLOC(c, struct zx_gl_loc_type_s);
  x->gg.g.tok = zx_gl_loc_type_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_loc_type) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_gl_loc_type) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_loc_type_s* zx_DEEP_CLONE_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x, int dup_strs)
{
  x = (struct zx_gl_loc_type_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_loc_type_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_gl_loc_type) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_loc_type) */

int zx_WALK_WO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_ms_action
#define EL_STRUCT zx_gl_ms_action_s
#define EL_NS     gl
#define EL_TAG    ms_action

/* FUNC(zx_FREE_gl_ms_action) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_ms_action) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_ms_action_s* zx_NEW_gl_ms_action(struct zx_ctx* c)
{
  struct zx_gl_ms_action_s* x = ZX_ZALLOC(c, struct zx_gl_ms_action_s);
  x->gg.g.tok = zx_gl_ms_action_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_ms_action) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_gl_ms_action) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_ms_action_s* zx_DEEP_CLONE_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x, int dup_strs)
{
  x = (struct zx_gl_ms_action_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_ms_action_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_gl_ms_action) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_ms_action) */

int zx_WALK_WO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_outerBoundaryIs
#define EL_STRUCT zx_gl_outerBoundaryIs_s
#define EL_NS     gl
#define EL_TAG    outerBoundaryIs

/* FUNC(zx_FREE_gl_outerBoundaryIs) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_LinearRing_s* e;
      struct zx_gl_LinearRing_s* en;
      for (e = x->LinearRing; e; e = en) {
	  en = (struct zx_gl_LinearRing_s*)e->gg.g.n;
	  zx_FREE_gl_LinearRing(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_outerBoundaryIs) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_outerBoundaryIs_s* zx_NEW_gl_outerBoundaryIs(struct zx_ctx* c)
{
  struct zx_gl_outerBoundaryIs_s* x = ZX_ZALLOC(c, struct zx_gl_outerBoundaryIs_s);
  x->gg.g.tok = zx_gl_outerBoundaryIs_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_outerBoundaryIs) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LinearRing(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_outerBoundaryIs) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_outerBoundaryIs_s* zx_DEEP_CLONE_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x, int dup_strs)
{
  x = (struct zx_gl_outerBoundaryIs_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_outerBoundaryIs_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_LinearRing_s* e;
      struct zx_gl_LinearRing_s* en;
      struct zx_gl_LinearRing_s* enn;
      for (enn = 0, e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LinearRing(c, e, dup_strs);
	  if (!enn)
	      x->LinearRing = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_outerBoundaryIs) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LinearRing(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_outerBoundaryIs) */

int zx_WALK_WO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_pd
#define EL_STRUCT zx_gl_pd_s
#define EL_NS     gl
#define EL_TAG    pd

/* FUNC(zx_FREE_gl_pd) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ACC, free_strs);

  zx_free_simple_elems(c, x->time, free_strs);
  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      for (e = x->CivilData; e; e = en) {
	  en = (struct zx_gl_CivilData_s*)e->gg.g.n;
	  zx_FREE_gl_CivilData(c, e, free_strs);
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      for (e = x->shape; e; e = en) {
	  en = (struct zx_gl_shape_s*)e->gg.g.n;
	  zx_FREE_gl_shape(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->alt, free_strs);
  zx_free_simple_elems(c, x->alt_acc, free_strs);
  zx_free_simple_elems(c, x->speed, free_strs);
  zx_free_simple_elems(c, x->direction, free_strs);
  zx_free_simple_elems(c, x->Heading, free_strs);
  zx_free_simple_elems(c, x->lev_conf, free_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_pd) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_pd_s* zx_NEW_gl_pd(struct zx_ctx* c)
{
  struct zx_gl_pd_s* x = ZX_ZALLOC(c, struct zx_gl_pd_s);
  x->gg.g.tok = zx_gl_pd_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_pd) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ACC);

  zx_dup_strs_simple_elems(c, x->time);
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_shape(c, e);
  }
  zx_dup_strs_simple_elems(c, x->alt);
  zx_dup_strs_simple_elems(c, x->alt_acc);
  zx_dup_strs_simple_elems(c, x->speed);
  zx_dup_strs_simple_elems(c, x->direction);
  zx_dup_strs_simple_elems(c, x->Heading);
  zx_dup_strs_simple_elems(c, x->lev_conf);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_pd) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_pd_s* zx_DEEP_CLONE_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x, int dup_strs)
{
  x = (struct zx_gl_pd_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_pd_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ACC = zx_clone_attr(c, x->ACC);

  x->time = zx_deep_clone_simple_elems(c,x->time, dup_strs);
  {
      struct zx_gl_CivilData_s* e;
      struct zx_gl_CivilData_s* en;
      struct zx_gl_CivilData_s* enn;
      for (enn = 0, e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CivilData(c, e, dup_strs);
	  if (!enn)
	      x->CivilData = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_shape_s* e;
      struct zx_gl_shape_s* en;
      struct zx_gl_shape_s* enn;
      for (enn = 0, e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_shape(c, e, dup_strs);
	  if (!enn)
	      x->shape = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->alt = zx_deep_clone_simple_elems(c,x->alt, dup_strs);
  x->alt_acc = zx_deep_clone_simple_elems(c,x->alt_acc, dup_strs);
  x->speed = zx_deep_clone_simple_elems(c,x->speed, dup_strs);
  x->direction = zx_deep_clone_simple_elems(c,x->direction, dup_strs);
  x->Heading = zx_deep_clone_simple_elems(c,x->Heading, dup_strs);
  x->lev_conf = zx_deep_clone_simple_elems(c,x->lev_conf, dup_strs);
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_pd) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->time, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CivilData(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_shape(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->alt, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->alt_acc, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->speed, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->direction, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Heading, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->lev_conf, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_pd) */

int zx_WALK_WO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_prio
#define EL_STRUCT zx_gl_prio_s
#define EL_NS     gl
#define EL_TAG    prio

/* FUNC(zx_FREE_gl_prio) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_prio) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_prio_s* zx_NEW_gl_prio(struct zx_ctx* c)
{
  struct zx_gl_prio_s* x = ZX_ZALLOC(c, struct zx_gl_prio_s);
  x->gg.g.tok = zx_gl_prio_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_prio) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_gl_prio) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_prio_s* zx_DEEP_CLONE_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x, int dup_strs)
{
  x = (struct zx_gl_prio_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_prio_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_gl_prio) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_prio) */

int zx_WALK_WO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_resp_req
#define EL_STRUCT zx_gl_resp_req_s
#define EL_NS     gl
#define EL_TAG    resp_req

/* FUNC(zx_FREE_gl_resp_req) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_resp_req) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_resp_req_s* zx_NEW_gl_resp_req(struct zx_ctx* c)
{
  struct zx_gl_resp_req_s* x = ZX_ZALLOC(c, struct zx_gl_resp_req_s);
  x->gg.g.tok = zx_gl_resp_req_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_resp_req) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->type);


}

/* FUNC(zx_DEEP_CLONE_gl_resp_req) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_resp_req_s* zx_DEEP_CLONE_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x, int dup_strs)
{
  x = (struct zx_gl_resp_req_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_resp_req_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->type = zx_clone_attr(c, x->type);


  return x;
}

/* FUNC(zx_WALK_SO_gl_resp_req) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_gl_resp_req) */

int zx_WALK_WO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   gl_shape
#define EL_STRUCT zx_gl_shape_s
#define EL_NS     gl
#define EL_TAG    shape

/* FUNC(zx_FREE_gl_shape) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_Point_s* e;
      struct zx_gl_Point_s* en;
      for (e = x->Point; e; e = en) {
	  en = (struct zx_gl_Point_s*)e->gg.g.n;
	  zx_FREE_gl_Point(c, e, free_strs);
      }
  }
  {
      struct zx_gl_LineString_s* e;
      struct zx_gl_LineString_s* en;
      for (e = x->LineString; e; e = en) {
	  en = (struct zx_gl_LineString_s*)e->gg.g.n;
	  zx_FREE_gl_LineString(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Polygon_s* e;
      struct zx_gl_Polygon_s* en;
      for (e = x->Polygon; e; e = en) {
	  en = (struct zx_gl_Polygon_s*)e->gg.g.n;
	  zx_FREE_gl_Polygon(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Box_s* e;
      struct zx_gl_Box_s* en;
      for (e = x->Box; e; e = en) {
	  en = (struct zx_gl_Box_s*)e->gg.g.n;
	  zx_FREE_gl_Box(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CircularArea_s* e;
      struct zx_gl_CircularArea_s* en;
      for (e = x->CircularArea; e; e = en) {
	  en = (struct zx_gl_CircularArea_s*)e->gg.g.n;
	  zx_FREE_gl_CircularArea(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      struct zx_gl_CircularArcArea_s* en;
      for (e = x->CircularArcArea; e; e = en) {
	  en = (struct zx_gl_CircularArcArea_s*)e->gg.g.n;
	  zx_FREE_gl_CircularArcArea(c, e, free_strs);
      }
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      struct zx_gl_EllipticalArea_s* en;
      for (e = x->EllipticalArea; e; e = en) {
	  en = (struct zx_gl_EllipticalArea_s*)e->gg.g.n;
	  zx_FREE_gl_EllipticalArea(c, e, free_strs);
      }
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      struct zx_gl_GeometryCollection_s* en;
      for (e = x->GeometryCollection; e; e = en) {
	  en = (struct zx_gl_GeometryCollection_s*)e->gg.g.n;
	  zx_FREE_gl_GeometryCollection(c, e, free_strs);
      }
  }
  {
      struct zx_gl_MultiLineString_s* e;
      struct zx_gl_MultiLineString_s* en;
      for (e = x->MultiLineString; e; e = en) {
	  en = (struct zx_gl_MultiLineString_s*)e->gg.g.n;
	  zx_FREE_gl_MultiLineString(c, e, free_strs);
      }
  }
  {
      struct zx_gl_MultiPoint_s* e;
      struct zx_gl_MultiPoint_s* en;
      for (e = x->MultiPoint; e; e = en) {
	  en = (struct zx_gl_MultiPoint_s*)e->gg.g.n;
	  zx_FREE_gl_MultiPoint(c, e, free_strs);
      }
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      struct zx_gl_MultiPolygon_s* en;
      for (e = x->MultiPolygon; e; e = en) {
	  en = (struct zx_gl_MultiPolygon_s*)e->gg.g.n;
	  zx_FREE_gl_MultiPolygon(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_gl_Extension_s*)e->gg.g.n;
	  zx_FREE_gl_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_gl_shape) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_gl_shape_s* zx_NEW_gl_shape(struct zx_ctx* c)
{
  struct zx_gl_shape_s* x = ZX_ZALLOC(c, struct zx_gl_shape_s);
  x->gg.g.tok = zx_gl_shape_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_gl_shape) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Point(c, e);
  }
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_LineString(c, e);
  }
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Polygon(c, e);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Box(c, e);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CircularArea(c, e);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CircularArcArea(c, e);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_EllipticalArea(c, e);
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      for (e = x->GeometryCollection; e; e = (struct zx_gl_GeometryCollection_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_GeometryCollection(c, e);
  }
  {
      struct zx_gl_MultiLineString_s* e;
      for (e = x->MultiLineString; e; e = (struct zx_gl_MultiLineString_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_MultiLineString(c, e);
  }
  {
      struct zx_gl_MultiPoint_s* e;
      for (e = x->MultiPoint; e; e = (struct zx_gl_MultiPoint_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_MultiPoint(c, e);
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      for (e = x->MultiPolygon; e; e = (struct zx_gl_MultiPolygon_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_MultiPolygon(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_gl_shape) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_gl_shape_s* zx_DEEP_CLONE_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x, int dup_strs)
{
  x = (struct zx_gl_shape_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_gl_shape_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_gl_Point_s* e;
      struct zx_gl_Point_s* en;
      struct zx_gl_Point_s* enn;
      for (enn = 0, e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Point(c, e, dup_strs);
	  if (!enn)
	      x->Point = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_LineString_s* e;
      struct zx_gl_LineString_s* en;
      struct zx_gl_LineString_s* enn;
      for (enn = 0, e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_LineString(c, e, dup_strs);
	  if (!enn)
	      x->LineString = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Polygon_s* e;
      struct zx_gl_Polygon_s* en;
      struct zx_gl_Polygon_s* enn;
      for (enn = 0, e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Polygon(c, e, dup_strs);
	  if (!enn)
	      x->Polygon = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Box_s* e;
      struct zx_gl_Box_s* en;
      struct zx_gl_Box_s* enn;
      for (enn = 0, e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Box(c, e, dup_strs);
	  if (!enn)
	      x->Box = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CircularArea_s* e;
      struct zx_gl_CircularArea_s* en;
      struct zx_gl_CircularArea_s* enn;
      for (enn = 0, e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CircularArea(c, e, dup_strs);
	  if (!enn)
	      x->CircularArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      struct zx_gl_CircularArcArea_s* en;
      struct zx_gl_CircularArcArea_s* enn;
      for (enn = 0, e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CircularArcArea(c, e, dup_strs);
	  if (!enn)
	      x->CircularArcArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      struct zx_gl_EllipticalArea_s* en;
      struct zx_gl_EllipticalArea_s* enn;
      for (enn = 0, e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_EllipticalArea(c, e, dup_strs);
	  if (!enn)
	      x->EllipticalArea = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      struct zx_gl_GeometryCollection_s* en;
      struct zx_gl_GeometryCollection_s* enn;
      for (enn = 0, e = x->GeometryCollection; e; e = (struct zx_gl_GeometryCollection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_GeometryCollection(c, e, dup_strs);
	  if (!enn)
	      x->GeometryCollection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_MultiLineString_s* e;
      struct zx_gl_MultiLineString_s* en;
      struct zx_gl_MultiLineString_s* enn;
      for (enn = 0, e = x->MultiLineString; e; e = (struct zx_gl_MultiLineString_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_MultiLineString(c, e, dup_strs);
	  if (!enn)
	      x->MultiLineString = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_MultiPoint_s* e;
      struct zx_gl_MultiPoint_s* en;
      struct zx_gl_MultiPoint_s* enn;
      for (enn = 0, e = x->MultiPoint; e; e = (struct zx_gl_MultiPoint_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_MultiPoint(c, e, dup_strs);
	  if (!enn)
	      x->MultiPoint = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      struct zx_gl_MultiPolygon_s* en;
      struct zx_gl_MultiPolygon_s* enn;
      for (enn = 0, e = x->MultiPolygon; e; e = (struct zx_gl_MultiPolygon_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_MultiPolygon(c, e, dup_strs);
	  if (!enn)
	      x->MultiPolygon = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      struct zx_gl_Extension_s* en;
      struct zx_gl_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_gl_shape) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Point(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_LineString(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Polygon(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Box(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CircularArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CircularArcArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_EllipticalArea(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      for (e = x->GeometryCollection; e; e = (struct zx_gl_GeometryCollection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_GeometryCollection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_MultiLineString_s* e;
      for (e = x->MultiLineString; e; e = (struct zx_gl_MultiLineString_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_MultiLineString(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_MultiPoint_s* e;
      for (e = x->MultiPoint; e; e = (struct zx_gl_MultiPoint_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_MultiPoint(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      for (e = x->MultiPolygon; e; e = (struct zx_gl_MultiPolygon_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_MultiPolygon(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_gl_shape) */

int zx_WALK_WO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-gl-aux.c */
