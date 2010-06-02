/* zxidmkwsf.c  -  Handwritten nitty-gritty functions for constructing various elems
 * Copyright (c) 2010 Sampo Kellomaki <sampo@iki.fi>, All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidmkwsf.c,v 1.12 2009-11-24 23:53:40 sampo Exp $
 *
 * 12.1.2007, created --Sampo
 * 7.10.2008, added documentation --Sampo
 * 15.11.2009, added ID-WSF <lu:Status> --Sampo
 * 25.5.2010, added SOAP fault, tas3:Status, error formatting --Sampo
 */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "wsf.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* *** What correct API should look like? This is still in flux
 * and the initial goal is just to make single query for single
 * service. All other complicated options and multi service queries
 * will come in later releases. */

/*() Create ID-WSF protocol <lu:Status> element, given various levels of error input.
 *
 * sc1:: First level status code
 * sc2:: Second level status code, if any
 * msg:: First level status message
 * ref:: First level Status/@ref. Ref is used to point to culprit XML element, if any.
 * returns:: lu:Status data structure with fields populated.
 *
 * See also: zxid_mk_fault() */

/* Called by:  zxid_di_query x4, zxid_idp_as_do x3, zxid_mk_fault, zxid_mk_lu_Status, zxid_mk_tas3_Status */
struct zx_lu_Status_s* zxid_mk_lu_Status(zxid_conf* cf, const char* sc1, const char* sc2, const char* msg, const char* ref)
{
  struct zx_lu_Status_s* st = zx_NEW_lu_Status(cf->ctx);
  st->code = zx_dup_str(cf->ctx, STRNULLCHKQ(sc1));
  if (msg)
    st->comment = zx_dup_str(cf->ctx, msg);
  if (ref)
    st->ref = zx_dup_str(cf->ctx, ref);
  if (sc2)
    st->Status = zxid_mk_lu_Status(cf, sc2, 0, 0, 0);
  return st;
}

/*() Create TAS3 application level Status (error) header. */

/* Called by: */
zxid_tas3_status* zxid_mk_tas3_status(zxid_conf* cf, const char* ctlpt, const char* sc1, const char* sc2, const char* msg, const char* ref)
{
  zxid_tas3_status* st = zx_NEW_tas3_Status(cf->ctx);
  if (ctlpt)
    st->ctlpt = zx_dup_str(cf->ctx, ctlpt);
  st->code = zx_dup_str(cf->ctx, STRNULLCHKQ(sc1));
  if (msg)
    st->comment = zx_dup_str(cf->ctx, msg);
  if (ref)
    st->ref = zx_dup_str(cf->ctx, ref);
  if (sc2)
    st->Status = zxid_mk_lu_Status(cf, sc2, 0, 0, 0);
  st->mustUnderstand = zx_dup_str(cf->ctx, "0");
  return st;
}

/*() Create SOAP Fault element (see Table 2 of [SOAPBind2], pp.12-13)
 *
 * fa:: Optional fault actor, such as one of the TAS3 control points (ctlpt)
 * fc:: Fault code. Should be "e:Client" or "e:Server".
 * fs:: Fault string. Human readable string explanation of the fault.
 * sc1:: First level status code (to be placed inside <detail> element)
 * sc2:: Second level status code, if any
 * msg:: First level status message
 * ref:: First level Status/@ref. Ref is used to point to culprit XML element, if any.
 * returns:: Fault data structure with fields populated.
 *
 * See also: zxid_mk_lu_Status()
 */

/* Called by:  zxid_wsf_validate_a7n x5, zxid_wsp_validate x11 */
struct zx_e_Fault_s* zxid_mk_fault(zxid_conf* cf, const char* fa, const char* fc, const char* fs, const char* sc1, const char* sc2, const char* msg, const char* ref)
{
  struct zx_e_Fault_s* flt = zx_NEW_e_Fault(cf->ctx);
  if (fa)
    flt->faultactor = zx_dup_simple_elem(cf->ctx, fa);
  flt->faultcode = zx_dup_simple_elem(cf->ctx, fc?fc:"e:Client");
  if (fs)
    flt->faultstring = zx_dup_simple_elem(cf->ctx, fs);
  if (sc1) {
    flt->detail = zx_NEW_e_detail(cf->ctx);
    flt->detail->Status = zxid_mk_lu_Status(cf, sc1, sc2, msg, ref);
  }
  return flt;
}

/*() Set current fault of the session. If current fault is set, the zxid_wsp_decorate()
 * function will generate a SOAP Fault response instead of normal SOAP response. If
 * you wish to return application response in situation where fault has been
 * detected, you can use this function to reset the current fault to null. */

/* Called by:  zxid_wsf_validate_a7n x5, zxid_wsp_validate x12 */
void zxid_set_fault(zxid_conf* cf, zxid_ses* ses, struct zx_e_Fault_s* flt) {
  if (ses->curflt) /* Free the previous fault */
    zx_FREE_e_Fault(cf->ctx, ses->curflt, 1);
  ses->curflt = flt;
}

/*() Read current fault of the session. NULL return means that there was no fault. */

/* Called by: */
struct zx_e_Fault_s* zxid_get_fault(zxid_conf* cf, zxid_ses* ses) {
  return ses->curflt;
}

/* Called by: */
char* zxid_get_tas3_fault_sc1(zxid_conf* cf, struct zx_e_Fault_s* flt) {
  if (!flt || !flt->faultcode || !flt->faultcode->content || !flt->faultcode->content->s)
    return 0;
  return zx_str_to_c(cf->ctx, flt->faultcode->content);
}
/* Called by: */
char* zxid_get_tas3_fault_sc2(zxid_conf* cf, struct zx_e_Fault_s* flt) {
  if (!flt || !flt->detail || !flt->detail->Status || !flt->detail->Status->code || !flt->detail->Status->code->s)
    return 0;
  return zx_str_to_c(cf->ctx, flt->detail->Status->code);
}
/* Called by: */
char* zxid_get_tas3_fault_comment(zxid_conf* cf, struct zx_e_Fault_s* flt) {
  if (!flt || !flt->faultstring || !flt->faultstring->content || !flt->faultstring->content->s)
    return 0;
  return zx_str_to_c(cf->ctx, flt->faultstring->content);
}
/* Called by: */
char* zxid_get_tas3_fault_ref(zxid_conf* cf, struct zx_e_Fault_s* flt) {
  if (!flt || !flt->detail || !flt->detail->Status || !flt->detail->Status->ref || !flt->detail->Status->ref->s)
    return 0;
  return zx_str_to_c(cf->ctx, flt->detail->Status->ref);
}
/* Called by: */
char* zxid_get_tas3_fault_actor(zxid_conf* cf, struct zx_e_Fault_s* flt) {
  if (!flt || !flt->faultactor || !flt->faultactor->content || !flt->faultactor->content->s)
    return 0;
  return zx_str_to_c(cf->ctx, flt->faultactor->content);
}

/*() Set current TAS3 Status of the session. If current Status is set, the zxid_wsp_decorate()
 * function will generate a TAS3 status header. */

/* Called by:  zxid_wsp_validate */
void zxid_set_tas3_status(zxid_conf* cf, zxid_ses* ses, zxid_tas3_status* status) {
  if (ses->curstatus) /* Free the previous fault */
    zx_FREE_tas3_Status(cf->ctx, ses->curstatus, 1);
  ses->curstatus = status;
}

/*() Read current fault of the session. NULL return means that there was no fault. */

/* Called by: */
zxid_tas3_status* zxid_get_tas3_status(zxid_conf* cf, zxid_ses* ses) {
  return ses->curstatus;
}

/* Called by: */
char* zxid_get_tas3_status_sc1(zxid_conf* cf, zxid_tas3_status* st) {
  if (!st || !st->code || !st->code->s)
    return 0;
  return zx_str_to_c(cf->ctx, st->code);
}
/* Called by: */
char* zxid_get_tas3_status_sc2(zxid_conf* cf, zxid_tas3_status* st) {
  if (!st || !st->Status || !st->Status->code || !st->Status->code->s)
    return 0;
  return zx_str_to_c(cf->ctx, st->Status->code);
}
/* Called by: */
char* zxid_get_tas3_status_comment(zxid_conf* cf, zxid_tas3_status* st) {
  if (!st || !st->comment || !st->comment->s)
    return 0;
  return zx_str_to_c(cf->ctx, st->comment);
}
/* Called by: */
char* zxid_get_tas3_status_ref(zxid_conf* cf, zxid_tas3_status* st) {
  if (!st || !st->ref || !st->ref->s)
    return 0;
  return zx_str_to_c(cf->ctx, st->ref);
}
/* Called by: */
char* zxid_get_tas3_status_ctlpt(zxid_conf* cf, zxid_tas3_status* st) {
  if (!st || !st->ctlpt || !st->ctlpt->s)
    return 0;
  return zx_str_to_c(cf->ctx, st->ctlpt);
}

/*() Low level constructor for discovery <di:RequestedService>. */

/* Called by:  zxid_mk_di_query */
static struct zx_di_RequestedService_s* zxid_mk_di_req_svc(zxid_conf* cf, int req_id, const char* svc_type, const char* url, const char* di_opt, const char* action)
{
  struct zx_di_RequestedService_s* rs = zx_NEW_di_RequestedService(cf->ctx);
#if 0
  rs->reqID = zx_strf(cf->ctx, "RS%x", req_id);
  rs->resultType = zx_ref_str(cf->ctx, "all");  /* OPTIONAL: "best", "only-one" */
  rs->SecurityMechID = zx_ref_simple_elem(cf->ctx, WSF20_SEC_MECH_TLS_BEARER);
  rs->SecurityMechID = zx_ref_simple_elem(cf->ctx, WSF20_SEC_MECH_TLS_SAML2);
#endif
  rs->Framework = zx_NEW_di_Framework(cf->ctx);
  rs->Framework->version = zx_ref_str(cf->ctx, "2.0");  /* Request specific framework, omit=any */
  if (svc_type)
    rs->ServiceType = zx_ref_simple_elem(cf->ctx, svc_type);
  if (url)
    rs->ProviderID = zx_ref_simple_elem(cf->ctx, url);
  if (di_opt) {
    rs->Options = zx_NEW_di_Options(cf->ctx);
    /* N.B: We adopt here a simplification that there can only be one option, but it
     * can be fully generic URI, including a query string. If it is desireable to
     * support additional options, dollar ($) could be used as a separator. */
    rs->Options->Option = zx_ref_simple_elem(cf->ctx, di_opt);
  }
  if (action)
    rs->Action = zx_ref_simple_elem(cf->ctx, action);
  return rs;
}

/*() Low level constructor for discovery <di:Query>. */

/* Called by:  main x2, zxid_get_epr */
struct zx_di_Query_s* zxid_mk_di_query(zxid_conf* cf, const char* svc_type, const char* url, const char* di_opt, const char* action)
{
  struct zx_di_Query_s* q = zx_NEW_di_Query(cf->ctx);
  q->RequestedService = zxid_mk_di_req_svc(cf, 1, svc_type, url, di_opt, action);
  return q;
}

/*() Low level constructor for WSA <Address>. */

/* Called by:  zxid_wsc_prep, zxid_wsf_decor */
struct zx_a_Address_s* zxid_mk_addr(zxid_conf* cf, struct zx_str* url)
{
  struct zx_a_Address_s* addr = zx_NEW_a_Address(cf->ctx);
  addr->gg.content = url;
  return addr;
}

/* --------------- DAP: Select and QueryItem -------------- */

/*() Low level constructor for <dap:Select>. */

/* Called by:  main x4 */
struct zx_dap_Select_s* zxid_mk_dap_select(zxid_conf* cf, char* dn, char* filter, char* attributes, int derefaliases, int scope, int sizelimit, int timelimit, int typesonly)
{
  struct zx_dap_Select_s* sel = zx_NEW_dap_Select(cf->ctx);
  if (dn)           sel->dn = zx_ref_simple_elem(cf->ctx, dn);
  if (filter)       sel->filter = zx_ref_simple_elem(cf->ctx, filter);
  if (attributes)   sel->attributes = zx_ref_str(cf->ctx, attributes);
  if (derefaliases) sel->derefaliases = zx_strf(cf->ctx, "%d", derefaliases);
  if (scope)        sel->scope = zx_strf(cf->ctx, "%d", scope);
  if (sizelimit)    sel->sizelimit = zx_strf(cf->ctx, "%d", sizelimit);
  if (timelimit)    sel->timelimit = zx_strf(cf->ctx, "%d", timelimit);
  if (typesonly)    sel->typesonly = zx_ref_str(cf->ctx, ZXID_TRUE);
  return sel;
}

/*() Low level constructor for <dap:QueryItem>. */

/* Called by:  main x3 */
struct zx_dap_QueryItem_s* zxid_mk_dap_query_item(zxid_conf* cf, struct zx_dap_Select_s* sel, char* objtype, char* predef, char* sort, char* changed_since, int incl_common_attr, int offset, int count, char* setreq, char* setid, char* contingent_itemidref)
{
  struct zx_dap_QueryItem_s* qi = zx_NEW_dap_QueryItem(cf->ctx);
  qi->Select = sel;
  if (objtype)       qi->objectType = zx_ref_str(cf->ctx, objtype);
  if (changed_since) qi->changedSince = zx_ref_str(cf->ctx, changed_since);
  if (predef)        qi->predefined = zx_ref_str(cf->ctx, predef);
  if (sort)          qi->Sort = zx_ref_simple_elem(cf->ctx, sort);

#if 0
  /* ID-DAP specification only allows ChangeFormat == "currentElements"
   * and in fact recommends omitting it altogether. */
  if (changed_elems)
    qi->ChangeFormat = zx_ref_simple_elem(cf->ctx, "changedElements");
  if (curr_elems) {
    if (qi->ChangeFormat)
      qi->ChangeFormat->g.n = (struct zx_node_s*)zx_ref_simple_elem(cf->ctx, "currentElements");
    else
      qi->ChangeFormat = zx_ref_simple_elem(cf->ctx, "currentElements");
  }
#endif

  if (incl_common_attr) qi->includeCommonAttributes = zx_ref_str(cf->ctx, ZXID_TRUE);
  if (offset)           qi->offset = zx_strf(cf->ctx, "%d", offset);
  if (count)            qi->count = zx_strf(cf->ctx, "%d", count);
  
  if (setreq) qi->setReq = zx_ref_str(cf->ctx, setreq);  /* Request new set */
  if (setid)  qi->setID = zx_ref_str(cf->ctx, setid);    /* Continue to use existing set */
  
  qi->itemID = zxid_mk_id(cf, "qi", ZXID_ID_BITS);
  
  if (contingent_itemidref) {
    qi->itemIDRef = zx_ref_str(cf->ctx, contingent_itemidref);
    qi->contingency = zx_ref_str(cf->ctx, ZXID_TRUE);
  }
  return qi;
}

/* --------------- DAP: Test -------------- */

/*() Low level constructor for <dap:TestOp>. */

/* Called by:  main */
struct zx_dap_TestOp_s* zxid_mk_dap_testop(zxid_conf* cf, char* dn, char* filter, char* attributes, int derefaliases, int scope, int sizelimit, int timelimit, int typesonly)
{
  struct zx_dap_TestOp_s* sel = zx_NEW_dap_TestOp(cf->ctx);
  if (dn)           sel->dn = zx_ref_simple_elem(cf->ctx, dn);
  if (filter)       sel->filter = zx_ref_simple_elem(cf->ctx, filter);
  if (attributes)   sel->attributes = zx_ref_str(cf->ctx, attributes);
  if (derefaliases) sel->derefaliases = zx_strf(cf->ctx, "%d", derefaliases);
  if (scope)        sel->scope = zx_strf(cf->ctx, "%d", scope);
  if (sizelimit)    sel->sizelimit = zx_strf(cf->ctx, "%d", sizelimit);
  if (timelimit)    sel->timelimit = zx_strf(cf->ctx, "%d", timelimit);
  if (typesonly)    sel->typesonly = zx_ref_str(cf->ctx, ZXID_TRUE);
  return sel;
}

/*() Low level constructor for <dap:TestItem>. */

/* Called by:  main */
struct zx_dap_TestItem_s* zxid_mk_dap_test_item(zxid_conf* cf, struct zx_dap_TestOp_s* top, char* objtype, char* predef)
{
  struct zx_dap_TestItem_s* ti = zx_NEW_dap_TestItem(cf->ctx);
  ti->TestOp = top;
  ti->id = ti->itemID = zxid_mk_id(cf, "ti", ZXID_ID_BITS);
  if (objtype) ti->objectType = zx_ref_str(cf->ctx, objtype);
  if (predef)  ti->predefined = zx_ref_str(cf->ctx, predef);
  return ti;
}

/* --------------- DAP: ResultQuery and Subscription -------------- */

/*() Low level constructor for <dap:ResultQuery>. */

/* Called by:  main */
struct zx_dap_ResultQuery_s* zxid_mk_dap_resquery(zxid_conf* cf, struct zx_dap_Select_s* sel, char* objtype, char* predef, char* sort, char* changed_since, int incl_common_attr, char* contingent_itemidref)
{
  struct zx_dap_ResultQuery_s* qi = zx_NEW_dap_ResultQuery(cf->ctx);
  qi->Select = sel;
  if (objtype)       qi->objectType = zx_ref_str(cf->ctx, objtype);
  if (changed_since) qi->changedSince = zx_ref_str(cf->ctx, changed_since);
  if (predef)        qi->predefined = zx_ref_str(cf->ctx, predef);
  if (sort)          qi->Sort = zx_ref_simple_elem(cf->ctx, sort);

#if 0
  /* ID-DAP specification only allows ChangeFormat == "currentElements"
   * and in fact recommends omitting it altogether. */
  if (changed_elems)
    qi->ChangeFormat = zx_ref_simple_elem(cf->ctx, "changedElements");
  if (curr_elems) {
    if (qi->ChangeFormat)
      qi->ChangeFormat->g.n = (struct zx_node_s*)zx_ref_simple_elem(cf->ctx, "currentElements");
    else
      qi->ChangeFormat = zx_ref_simple_elem(cf->ctx, "currentElements");
  }
#endif
  
  if (incl_common_attr) qi->includeCommonAttributes = zx_ref_str(cf->ctx, ZXID_TRUE);
  
  qi->itemID = zxid_mk_id(cf, "qi", ZXID_ID_BITS);
  
  if (contingent_itemidref) {
    qi->itemIDRef = zx_ref_str(cf->ctx, contingent_itemidref);
    qi->contingency = zx_ref_str(cf->ctx, ZXID_TRUE);
  }
  return qi;
}

/*() Low level constructor for <dap:Subscription>. */

/* Called by:  main */
struct zx_dap_Subscription_s* zxid_mk_dap_subscription(zxid_conf* cf, char* subsID, char* itemidref, struct zx_dap_ResultQuery_s* rq, char* aggreg, char* trig, char* starts, char* expires, int incl_data, char* admin_notif, char* notify_ref)
{
  struct zx_dap_Subscription_s* subs = zx_NEW_dap_Subscription(cf->ctx);
  if (itemidref) {
    subs->RefItem = zx_NEW_subs_RefItem(cf->ctx);
    subs->RefItem->itemIDRef = zx_ref_str(cf->ctx, itemidref);
    if (subsID)
      subs->RefItem->subscriptionID = zx_ref_str(cf->ctx, subsID);
  }
  subs->ResultQuery = rq;
  if (aggreg)  subs->Aggregation = zx_ref_simple_elem(cf->ctx, aggreg);
  if (trig)    subs->Trigger = zx_ref_simple_elem(cf->ctx, trig);
  if (starts)  subs->starts = zx_ref_str(cf->ctx, starts);
  if (expires) subs->expires = zx_ref_str(cf->ctx, expires);
  if (incl_data)   subs->includeData = zx_ref_str(cf->ctx, ZXID_TRUE);
  if (admin_notif) subs->adminNotifyToRef = zx_ref_str(cf->ctx, admin_notif);
  if (notify_ref)  subs->notifyToRef = zx_ref_str(cf->ctx, notify_ref);
  subs->subscriptionID = zxid_mk_id(cf, "subs", ZXID_ID_BITS);;
  return subs;
}

/* --------------- DAP: Query -------------- */

/*() Low level constructor for <dap:Query>. */

/* Called by:  main x3 */
struct zx_dap_Query_s* zxid_mk_dap_query(zxid_conf* cf, struct zx_dap_TestItem_s* tis, struct zx_dap_QueryItem_s* qis, struct zx_dap_Subscription_s* subs)
{
  struct zx_dap_Query_s* q = zx_NEW_dap_Query(cf->ctx);
  q->TestItem = tis;
  q->QueryItem = qis;
  q->Subscription = subs;
  q->itemID = zx_ref_str(cf->ctx, "QRY");
  return q;
}

/* EOF  --  zxidmkwsf.c */
