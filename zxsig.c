/* zxsig.c  -  Signature generation and validation
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxsig.c,v 1.29 2010-01-08 02:10:09 sampo Exp $
 *
 * 29.9.2006, created --Sampo
 * 23.9.2007, added XML ENC support --Sampo
 * 8.10.2007, added XML signing support --Sampo
 * 4.10.2008, improved documentation --Sampo
 * 1.12.2010, improved logging of canonicalizations --Sampo
 */

#include <memory.h>
#include <string.h>

#ifdef USE_OPENSSL
#include <openssl/x509.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
#endif

#include "errmac.h"
#include "platform.h"
#include "zx.h"
#include "zxid.h"
#include "zxidutil.h"
#include "zxidconf.h"
#include "c/zx-data.h"   /* For the XMLDSIG code. */
#include "c/zx-const.h"

ZXID_DECL struct zx_ds_KeyInfo_s* zxid_key_info(zxid_conf* cf, struct zx_elem_s* father, X509* x);

//static char*
#define priv_key_missing_msg "Private key missing. Perhaps you have not installed one in the certificate file in the /var/zxid/pem directory (or other directory if configured, see previous error messages for file reading trouble)? Other reasons: permissions do not allow reading the key (current uid=%d gid=%d), the directory permissions do not allow reading, the private key file is empty, wrong format, or corrupt; or the private key is protected with a password (remove password prior to use with zxid). See http://zxid.org/html/zxid-cot.html for further help."

/*(i) Sign, using XML-DSIG, some XML data in the ~sref~ array. The XML data is canonicalized
 * and the signature is generated and returned. Typically the caller will then insert the
 * signature to the original data structure and canonicalize for transport.
 *
 * c::        ZX context. Used for memory allocation.
 * n::        Number of elements in the sref array
 * sref::     An array of <reference id, xml canon> tuples that are
 *     to be signed. See zxid_add_header_refs() for preparing sref array.
 * cert::     Certificate (public key) used for signing
 * priv_key:: Private key used for signing
 * return::   Signature as XML data, or 0 if failure.
 *
 * *Steps*
 *
 * 1. Canon tag(s) to sign (done by caller), pass as sig refs
 * 2. Sha1 each sig ref
 * 3. Construct the Signature element
 * 4. Attach signature to the element (done by caller)
 *
 * *Typical XML-DSIG Signature*
 *
 *   <ds:Signature xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
 *     <ds:SignedInfo>
 *       <ds:CanonicalizationMethod Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"/>
 *       <ds:SignatureMethod Algorithm="http://www.w3.org/2000/09/xmldsig#rsa-sha1"/>
 *       <ds:Reference URI="#CREDm7unLxp2sOXQYfDR8E4F">
 *         <ds:Transforms>
 *           <ds:Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"/>
 *           <ds:Transform Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#">
 *             <ec:InclusiveNamespaces
 *                 xmlns:ec="http://www.w3.org/2001/10/xml-exc-c14n#"
 *                 PrefixList="xasa"/></></>
 *         <ds:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha1"/>
 *         <ds:DigestValue>I2wmlQu11nvfSepvzor29kAZwAo=</></></>
 *     <ds:SignatureValue>
 *       FK6X9qO8qZntp3CeFbA7gpG9n9rWyJWlzSXy0vKNspwMGdl8HPfOGcXEs2Ts=</></>
 */

/* Called by:  zxid_anoint_a7n, zxid_anoint_sso_resp, zxid_az_soap x3, zxid_idp_soap_dispatch x2, zxid_idp_sso, zxid_mk_art_deref, zxid_sp_mni_soap, zxid_sp_slo_soap, zxid_sp_soap_dispatch x7, zxid_ssos_anreq, zxid_wsf_sign */
struct zx_ds_Signature_s* zxsig_sign(struct zx_ctx* c, int n, struct zxsig_ref* sref, X509* cert, EVP_PKEY* priv_key)
{
  char sha1[20];
  char* sigu;
  int siglen;
  RSA* rsa;
  DSA* dsa;
  struct zx_str* ss;
  struct zx_str* b64;
  struct zx_ds_Reference_s* ref;
  struct zx_ds_Signature_s* sig = zx_NEW_ds_Signature(c,0);
  struct zx_ds_SignedInfo_s* si = sig->SignedInfo = zx_NEW_ds_SignedInfo(c, &sig->gg);
  si->CanonicalizationMethod = zx_NEW_ds_CanonicalizationMethod(c, &si->gg);
  si->CanonicalizationMethod->Algorithm = zx_ref_attr(c, &si->CanonicalizationMethod->gg, zx_Algorithm_ATTR, CANON_ALGO);
  si->SignatureMethod = zx_NEW_ds_SignatureMethod(c, &si->gg);
  si->SignatureMethod->Algorithm = zx_ref_attr(c, &si->SignatureMethod->gg, zx_Algorithm_ATTR, SIG_ALGO);

  for (; n; --n, ++sref) {
    ref = zx_NEW_ds_Reference(c, &si->gg);
    ref->Transforms = zx_NEW_ds_Transforms(c, &ref->gg);
    ref->Transforms->Transform = zx_NEW_ds_Transform(c, &ref->Transforms->gg);
    ref->Transforms->Transform->Algorithm = zx_ref_attr(c, &ref->Transforms->Transform->gg, zx_Algorithm_ATTR, CANON_ALGO);

    ref->Transforms->Transform = zx_NEW_ds_Transform(c, &ref->Transforms->gg);
    ref->Transforms->Transform->Algorithm = zx_ref_attr(c, &ref->Transforms->Transform->gg, zx_Algorithm_ATTR, ENVELOPED_ALGO);
    
    ref->DigestMethod = zx_NEW_ds_DigestMethod(c, &ref->gg);
    ref->DigestMethod->Algorithm = zx_ref_attr(c, &ref->DigestMethod->gg, zx_Algorithm_ATTR, DIGEST_ALGO);
    
    ref->URI = zx_attrf(c, &ref->gg, zx_URI_ATTR, "#%.*s", sref->id->len, sref->id->s);
    SHA1((unsigned char*)sref->canon->s, sref->canon->len, (unsigned char*)sha1);
    b64 = zx_new_len_str(c, SIMPLE_BASE64_LEN(sizeof(sha1)));
    base64_fancy_raw(sha1, sizeof(sha1), b64->s, std_basis_64, 1<<31, 0, 0, '=');
    ref->DigestValue = zx_new_str_elem(c, &ref->gg, zx_ds_DigestValue_ELEM, b64);
    si->Reference = ref;  /* *** Need to reverse the list? */
    /* This debug print allows you to debug canonicalization reated signature
     * problems from signer's end. The verifier's end is aroind line zxsig.c:270
     * in zxsig_validate() */
    DD("SIG REF(#%.*s) SHA1(%.*s) CANON(%.*s)", sref->id->len, sref->id->s, b64->len, b64->s, sref->canon->len, sref->canon->s);
    D("SIG REF(#%.*s) SHA1(%.*s)", sref->id->len, sref->id->s, b64->len, b64->s);
    D_XML_BLOB(0, "SIG CANON", sref->canon->len, sref->canon->s);
    zx_reverse_elem_lists(&si->Reference->gg);
  }
  zx_reverse_elem_lists(&si->gg);
  
  c->enc_tail_opt = 0;
  ss = zx_EASY_ENC_elem(c, &si->gg);
  SHA1((unsigned char*)ss->s, ss->len, (unsigned char*)sha1);
  zx_str_free(c, ss);
  
  if (!priv_key) {
    ERR(priv_key_missing_msg, geteuid(), getegid());
    return 0;
  }

  switch (EVP_PKEY_type(priv_key->type)) {
  case EVP_PKEY_RSA:
    rsa = EVP_PKEY_get1_RSA(priv_key);
    siglen = RSA_size(rsa);
    sigu = ZX_ALLOC(c, siglen);
    
    if (!RSA_sign(NID_sha1, (unsigned char*)sha1, sizeof(sha1), (unsigned char*)sigu, (unsigned int*)&siglen, rsa)) {
      ERR("RSA_sign() failed. Bad certificate or private key? %p", rsa);
      zx_report_openssl_error("signing error");
      ZX_FREE(c, sigu);
      return 0;
    }
    break;
  case EVP_PKEY_DSA:
    dsa = EVP_PKEY_get1_DSA(priv_key);
    siglen = DSA_size(dsa);
    sigu = ZX_ALLOC(c, siglen);
    
    if (!DSA_sign(NID_sha1, (unsigned char*)sha1, sizeof(sha1), (unsigned char*)sigu, (unsigned int*)&siglen, dsa)) {
      ERR("DSA_sign() failed. Bad certificate or private key? %p", dsa);
      zx_report_openssl_error("signing error");
      ZX_FREE(c, sigu);
      return 0;
    }
    break;
  default:
    ERR("Unknown private key type 0x%x. Wrong or corrupt private key?", priv_key->type);
    return 0;
  }
  
  b64 = zx_new_len_str(c, SIMPLE_BASE64_LEN(siglen));
  base64_fancy_raw(sigu, siglen, b64->s, std_basis_64, 1<<31, 0, 0, '=');
  ZX_FREE(c, sigu);
  sig->SignatureValue = zx_NEW_ds_SignatureValue(c, &sig->gg);
  zx_add_content(c, &sig->SignatureValue->gg, b64);
  zx_reverse_elem_lists(&sig->gg);
  return sig;
}

/*() CRNL->NL canonicalization is specified in xml-c14n */

/* Called by:  zxsig_validate x2 */
static void zxsig_canon_crnl_inplace(struct zx_str* ss)
{
  char* p;
  char* lim;
  if (!ss || !ss->len || !ss->s) {
    ERR("Asked to canonicalize null or empty string %p", ss);
    return;
  }
  p = ss->s;
  lim = p + ss->len;
  while (p < lim) {
    p = memchr(p, 0x0d, lim-p);
    if (!p)
      break;
    --lim;
    D("Canonicalizing CRNL to NL %d", ((int)(lim-p)));
    memmove(p, p+1, lim-p);  /* *** could be more efficient */
  }
  ss->len = lim - ss->s;
}

/*(i) Validate XML-DSIG signature over XML data found in ~sref~ array.
 * Signature is validated agaist provided certificate, which
 * must have been previously looked up, usually using Issuer field of message
 * and metadata of the signing party. Trust in the certificate must have
 * been established by other means.
 *
 * c::      ZX context. Used for memory allocation.
 * cert::   Signing party's certificate (public key), typically from metadata. If NULL,
 *          then only the hashes (and hence canonicalization) are checked, but the
 *          public key crypto part is not performed, and ZXSIG_BAD_CERT is returned.
 * sig::    Parsed XML-DSIG data structure
 * n::      Number of elements in the sref array
 * sref::   An array of <reference sref, xml data structure blob> tuples that are
 *     referenced by the signature
 * return:: ZXSIG value. 0 (ZXSIG_OK) means success. Any other value is some sort of failure */

/* Called by:  main x5, sig_validate x2, wsse_sec_validate, zxid_chk_sig, zxid_sp_sso_finalize, zxid_wsc_valid_re_env, zxid_wsf_validate_a7n, zxid_wsp_validate_env */
int zxsig_validate(struct zx_ctx* c, X509* cert, struct zx_ds_Signature_s* sig, int n, struct zxsig_ref* sref)
{
  EVP_PKEY* evp_pkey;
  struct rsa_st* rsa_pkey;
  struct dsa_st* dsa_pkey;
  int siz, verdict, nn;
  char* old_sig_raw;
  char* lim;
  char* p;
  char* q;
  char md_calc[20];   /* SHA1 is 160 bits. */
  char md_given[20];  /* SHA1 is 160 bits. */
  struct zx_ns_s* ns;
  struct zx_str* ss;
  struct zx_str* dv;
  struct zxsig_ref* ssref;
  struct zx_ds_Transform_s* xform;
  struct zx_str* algo;
  c->exclude_sig = sig;

  /* Figure out inclusive namespaces, if any. */
  c->inc_ns = 0;
  if (c->canon_inopt & ZXID_CANON_INOPT_SHIB215IDP_INCLUSIVENAMESPACES) {
    INFO("Warning: Processing <InclusiveNamespaces> has been disabled (config option CANON_INOPT=1). The canonicalization may not be fully xml-exc-c14n compatible (but it may enable interoperation with an IdP that is not fully compatible). %x", c->canon_inopt);
  } else {
    for (ssref = sref, nn = n; nn; --nn, ++ssref) {
      if (!ssref->sref->Transforms)
	continue;
      for (xform = ssref->sref->Transforms->Transform;
	   xform;
	   xform = (void*)xform->gg.g.n) {
	if (xform->gg.g.tok != zx_ds_Transform_ELEM)
	  continue;
	ss = xform->InclusiveNamespaces ? &xform->InclusiveNamespaces->PrefixList->g : 0;
	if (!ss || !ss->len)
	  continue;
	for (p = ss->s, lim = p + ss->len; p < lim; ) {
	  q = memchr(p, ' ', lim-p);
	  if (!q)
	    siz = lim-p;
	  else
	    siz = q - p;
	  ns = zx_prefix_seen(c, siz, p);
	  if (!ns) {
	    INFO("InclusiveNamespaces/@PrefixList contains unknown ns prefix(%.*s)", siz, p);
	    p += siz + 1;
	    continue;
	  }
	  p += siz + 1;
	  if (!zx_in_inc_ns(c, ns)) {
	    ns->inc_n = c->inc_ns;
	    c->inc_ns = ns;
	  }
	}
      }
    }
  }
  c->inc_ns_len = c->inc_ns;
  zx_pop_seen(sref->pop_seen);

  algo = &sref->sref->DigestMethod->Algorithm->g;
  for (; n; --n, ++sref) {
    c->enc_tail_opt = 0;
    ss = zx_EASY_ENC_elem(c, sref->blob);
    zxsig_canon_crnl_inplace(ss);
    if (       ZX_STR_ENDS_IN_CONST(algo, "#sha1")) {
      SHA1((unsigned char*)ss->s, ss->len, (unsigned char*)md_calc);
      siz = 20;
    } else if (ZX_STR_ENDS_IN_CONST(algo, "#md5")) {
      MD5((unsigned char*)ss->s, ss->len, (unsigned char*)md_calc);
      siz = 16;
    } else {
      ERR("Unknown digest algo(%.*s) in sref(%.*s). Only SHA1 and MD5 are supported.",
	  algo->len, algo->s, sref->sref->URI->g.len, sref->sref->URI->g.s);
      ZX_FREE(c, ss);
      return ZXSIG_BAD_DALGO;
    }
    dv = ZX_GET_CONTENT(sref->sref->DigestValue);
    if (dv->len != SIMPLE_BASE64_LEN(siz)) {
      ERR("Message digest(%.*s) length incorrect (%d vs. %d) at sref(%.*s)",
	  dv->len, dv->s, dv->len, SIMPLE_BASE64_LEN(siz),
	  sref->sref->URI->g.len, sref->sref->URI->g.s);
      ZX_FREE(c, ss);
      return ZXSIG_DIGEST_LEN;
    }
    unbase64_raw(dv->s, dv->s + dv->len, md_given, zx_std_index_64);
    if (memcmp(md_calc, md_given, siz)) {
      /* See also debug print of original canonicalization for signature
       * generation around line zxsig.c:115 in zxsig_sign() */
      DD("Message digest(%.*s) mismatch at sref(%.*s), canon blob(%.*s)", dv->len, dv->s, sref->sref->URI->g.len, sref->sref->URI->g.s, ss->len, ss->s);
      ERR("Message digest(%.*s) mismatch at sref(%.*s)", dv->len, dv->s, sref->sref->URI->g.len, sref->sref->URI->g.s);
      D_XML_BLOB(0, "VFY FAIL CANON BLOB", ss->len, ss->s);
      ZX_FREE(c, ss);
      return ZXSIG_BAD_DIGEST;
    }
    ZX_FREE(c, ss);
  }
  if (!cert) {
    ERR("No certificate supplied. Only hashes (and hence canonicalization) verified. %d",0);
    return ZXSIG_BAD_CERT;
  }
  c->exclude_sig = 0;
  c->enc_tail_opt = 0;
  ss = zx_EASY_ENC_elem(c, &sig->SignedInfo->gg);
  zxsig_canon_crnl_inplace(ss);
  algo = &sig->SignedInfo->SignatureMethod->Algorithm->g;
  evp_pkey = X509_get_pubkey(cert);
  if (!evp_pkey) goto certerr;

  dv = ZX_GET_CONTENT(sig->SignatureValue);
  old_sig_raw = ZX_ALLOC(c, SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(dv->len));
  lim = unbase64_raw(dv->s, dv->s + dv->len, old_sig_raw, zx_std_index_64);
  if (       ZX_STR_ENDS_IN_CONST(algo, "#rsa-sha1")) {
    /* PKCS#1 v2.0 */
    rsa_pkey = EVP_PKEY_get1_RSA(evp_pkey);
    if (!rsa_pkey) goto certerr;
    SHA1((unsigned char*)ss->s, ss->len, (unsigned char*)md_calc);
    DD("VFY rsa-sha1 (PKCS#1 v2.0) canon sigInfo(%.*s) %d", ss->len, ss->s, hexdmp("inner sha1: ", md_calc,20,20));
    verdict = RSA_verify(NID_sha1, (unsigned char*)md_calc, 20, (unsigned char*)old_sig_raw, lim - old_sig_raw, rsa_pkey);
    if (!verdict) goto vfyerr;
  } else if (ZX_STR_ENDS_IN_CONST(algo, "#dsa-sha1")) {
    dsa_pkey = EVP_PKEY_get1_DSA(evp_pkey);
    if (!dsa_pkey) goto certerr;
    SHA1((unsigned char*)ss->s, ss->len, (unsigned char*)md_calc);
    DD("VFY dsa-sha1 canon sigInfo(%.*s) %d", ss->len, ss->s,hexdmp("inner sha1: ",md_calc,20,20));
    verdict = DSA_verify(NID_sha1, (unsigned char*)md_calc, 20, (unsigned char*)old_sig_raw, lim - old_sig_raw, dsa_pkey);
    if (!verdict) goto vfyerr;
  } else if (ZX_STR_ENDS_IN_CONST(algo, "#rsa-md5")) {
    rsa_pkey = EVP_PKEY_get1_RSA(evp_pkey);
    if (!rsa_pkey) goto certerr;
    MD5((unsigned char*)ss->s, ss->len, (unsigned char*)md_calc);
    DD("VFY rsa-md5 canon sigInfo(%.*s) %d", ss->len, ss->s, hexdmp("inner md5: ",md_calc,16,16));
    verdict = RSA_verify(NID_md5, (unsigned char*)md_calc, 16, (unsigned char*)old_sig_raw, lim - old_sig_raw, rsa_pkey);
    if (!verdict) goto vfyerr;
  } else if (ZX_STR_ENDS_IN_CONST(algo, "#dsa-md5")) {
    dsa_pkey = EVP_PKEY_get1_DSA(evp_pkey);
    if (!dsa_pkey) goto certerr;
    MD5((unsigned char*)ss->s, ss->len, (unsigned char*)md_calc);
    DD("VFY dsa-md5 canon sigInfo(%.*s) %d", ss->len, ss->s, hexdmp("inner md5: ",md_calc,16,16));
    verdict = DSA_verify(NID_md5, (unsigned char*)md_calc, 16, (unsigned char*)old_sig_raw, lim - old_sig_raw, dsa_pkey);
    if (!verdict) goto vfyerr;
  } else {
    ERR("Unknown digest algo(%.*s) in sref(%.*s). Only SHA1 and MD5 are supported.",
	sref->sref->DigestMethod->Algorithm->g.len, sref->sref->DigestMethod->Algorithm->g.s,
	sref->sref->URI->g.len, sref->sref->URI->g.s);
    ZX_FREE(c, ss);
    return ZXSIG_BAD_SALGO;
  }  
  ZX_FREE(c, ss);
  return ZXSIG_OK;

certerr:
  ERR("Certificate error. Maybe the certificate does not have any public key type=0x%x matching the algorithm(%.*s)? Or corrupt or wrong cert?", evp_pkey?evp_pkey->type:-1, algo?algo->len:0, algo?algo->s:"");
  zx_report_openssl_error("certificate error");
  ZX_FREE(c, ss);
  return ZXSIG_BAD_CERT;

vfyerr:
  zx_report_openssl_error("verification error");
  DD("VFY FAIL canon sigInfo(%.*s) %d", ss->len, ss->s,hexdmp("inner md_calc: ", md_calc, 20, 20));
  ERR("VFY FAIL canon sigInfo md %d", hexdmp("inner md_calc: ", md_calc, 20, 20));
  D_XML_BLOB(0, "VFY FAIL CANON SIGINFO", ss->len, ss->s);
  ZX_FREE(c, ss);
  return ZXSIG_VFY_FAIL;
}

/*() Walk through the OpenSSL error stack and dump it to the stderr.
 *
 * logkey:: Way for caller to indicate what the OpenSSL errors are all about
 * return:: Number of open SSL errors processed, or 0 if none. Often ignored. */

/* Called by:  main, zx_EVP_CIPHER_key_length, zx_get_rsa_pub_from_cert x2, zx_raw_cipher, zx_rsa_priv_dec, zx_rsa_priv_enc, zx_rsa_pub_dec, zx_rsa_pub_enc, zxid_mk_at_cert x2, zxid_mk_self_sig_cert x4, zxlog_write_line, zxsig_data x2, zxsig_sign x2, zxsig_validate x2, zxsig_verify_data x5 */
int zx_report_openssl_error(const char* logkey)
{
  char buf[256];
  unsigned long err;
  const char* file;
  const char* data;
  int flags, line, n_err = 0;
  buf[0] = 0;
  while ((err = ERR_get_error_line_data((const char**)&file, &line, (const char**)&data, &flags))) {
    ERR_error_string_n(err, buf, sizeof(buf));
    buf[sizeof(buf)-1] = 0;
    ERR("%s: OpenSSL error(%lu) %s (%s:%d): %s %x", logkey, err,
	buf, STRNULLCHK(file), line,
	(data && (flags & ERR_TXT_STRING)) ? data : "?", flags);
  }
  return n_err;
}

/* --------------- Raw data signing and verification. These are building blocks. -------------- */

/*() Sign a blob of data using rsa-sha1 or dsa-sha1 algorithm.
 *
 * c::        ZX context. Used for memory allocation.
 * len::      Length of the raw data
 * data::     Raw data to sign
 * sig::      Result parameter. Raw binary signature data will be returned via this parameter.
 * priv_key:: Private key used for signing.
 * lk::       Log key. Used to make logs and error messages more meaningful.
 * return::   -1 on failure. Upon success the length of the raw signature data. */

/* Called by:  zxid_saml2_post_enc, zxid_saml2_redir_enc, zxlog_write_line x2 */
int zxsig_data(struct zx_ctx* c, int len, const char* data, char** sig, EVP_PKEY* priv_key, const char* lk)
{
  RSA* rsa;
  DSA* dsa;
  char sha1[20];  /* 160 bits */
  SHA1((unsigned char*)data, len, (unsigned char*)sha1);
  
  DD("%s: data(%.*s)", lk, len, data);
  DD("%s: data above %d", lk, hexdump("data: ", data, data+len, 4096));
  DD("%s: sha1 above %d", lk, hexdump("sha1: ", sha1, sha1+20, 20));

  if (!priv_key) {
    ERR(priv_key_missing_msg, geteuid(), getegid());
    return 0;
  }

  switch (EVP_PKEY_type(priv_key->type)) {
  case EVP_PKEY_RSA:
    rsa = EVP_PKEY_get1_RSA(priv_key);
    len = RSA_size(rsa);
    *sig = ZX_ALLOC(c, len);
    if (RSA_sign(NID_sha1, (unsigned char*)sha1, 20, (unsigned char*)*sig, (unsigned int*)&len, rsa))  /* PKCS#1 v2.0 */
      return len;
    ERR("%s: signing data failed. Perhaps you have bad, or no, RSA private key(%p) len=%d data=%p", lk, rsa, len, data);
    zx_report_openssl_error(lk);
    return -1;
  case EVP_PKEY_DSA:
    dsa = EVP_PKEY_get1_DSA(priv_key);
    len = DSA_size(dsa);
    *sig = ZX_ALLOC(c, len);
    if (DSA_sign(NID_sha1, (unsigned char*)sha1, 20, (unsigned char*)*sig, (unsigned int*)&len, dsa))  /* PKCS#1 v2.0 */
      return len;
    ERR("%s: signing data failed. Perhaps you have bad, or no, DSA private key(%p) len=%d data=%p", lk, dsa, len, data);
    zx_report_openssl_error(lk);
    return -1;
  default:
    ERR("%s: Unknown private key type 0x%x. Wrong or corrupt private key?", lk, priv_key->type);
    return -1;
  }
}

/*() Verify a signature over a blob of data using rsa-sha1 algorithm.
 *
 * len::      Length of the raw data
 * data::     Raw data to sign
 * siglen::   Length of the raw binary signature data
 * sig::      Raw binary signature data
 * cert::     Certificate used for signing
 * lk::       Log key. Used to make logs and error messages more meaningful
 * return::   ZX_SIG value. o (ZXSIG_OK) means success. Other values mean failure of some sort. */

/* Called by:  main, zxid_decode_redir_or_post, zxlog_zsig_verify_print */
int zxsig_verify_data(int len, char* data, int siglen, char* sig, X509* cert, char* lk)
{
  int verdict;
  EVP_PKEY* evp_pubk;
  struct rsa_st* rsa_pubk;
  struct dsa_st* dsa_pubk;
  char sha1[20];  /* 160 bits */
  SHA1((unsigned char*)data, len, (unsigned char*)sha1);
  
  DD("%s: vfy data above %d", lk, hexdump("data: ", data, data+len, 4096));
  DD("%s: vfy sig above %d",  lk, hexdump("sig: ",  sig,  sig+siglen, 4096));
  DD("%s: vfy sha1 above %d", lk, hexdump("sha1: ", sha1, sha1+20, 20));
  
  evp_pubk = X509_get_pubkey(cert);
  if (!evp_pubk) {
    ERR("%s: Verify failed to get public key from certificate (perhaps you have not supplied any certificate, or it is corrupt or of wrong type) %p", lk, cert);
    zx_report_openssl_error("zxsig rsa vfy get_pub");
    return ZXSIG_BAD_CERT;
  }
  switch (EVP_PKEY_type(evp_pubk->type)) {
  case EVP_PKEY_RSA:
    rsa_pubk = EVP_PKEY_get1_RSA(evp_pubk);
    if (!rsa_pubk) {
      ERR("RSA vfy: failed to extract RSA get public key from certificate (perhaps you have not supplied any certificate, or it is corrupt or of wrong type) %p", cert);
      zx_report_openssl_error("zxsig rsa vfy rsa get_pub rsa");
      return ZXSIG_BAD_CERT;
    }
  
    verdict = RSA_verify(NID_sha1, (unsigned char*)sha1, 20, (unsigned char*)sig, siglen, rsa_pubk);  /* PKCS#1 v2.0 */
    if (!verdict) {
      ERR("RSA signature verify in %s data failed. Perhaps you have bad or no certificate(%p) len=%d data=%p siglen=%d sig=%p", lk, cert, len, data, siglen, sig);
      zx_report_openssl_error(lk);
      D("RSA_vfy(%s) sig above %d",  lk, hexdump("sig: ",  sig,  sig+siglen, 4096));
      return ZXSIG_VFY_FAIL;
    } else {
      D("RSA verify OK %d", verdict);
      return 0;
    }
  case EVP_PKEY_DSA:
    dsa_pubk = EVP_PKEY_get1_DSA(evp_pubk);
    if (!dsa_pubk) {
      ERR("DSA vfy: failed to extract DSA get public key from certificate (perhaps you have not supplied any certificate, or it is corrupt or of wrong type) %p", cert);
      zx_report_openssl_error("zxsig dsa vfy dsa get_pub dsa");
      return ZXSIG_BAD_CERT;
    }
  
    verdict = DSA_verify(NID_sha1, (unsigned char*)sha1, 20, (unsigned char*)sig, siglen, dsa_pubk);  /* PKCS#1 v2.0 */
    if (!verdict) {
      ERR("DSA signature verify in %s data failed. Perhaps you have bad or no certificate(%p) len=%d data=%p siglen=%d sig=%p", lk, cert, len, data, siglen, sig);
      zx_report_openssl_error(lk);
      D("DSA_vfy(%s) sig above %d",  lk, hexdump("sig: ",  sig,  sig+siglen, 4096));
      return ZXSIG_VFY_FAIL;
    } else {
      D("DSA verify OK %d", verdict);
      return 0;
    }
  default:
    ERR("%s: Unknown public key type 0x%x. Wrong or corrupt certificate key?", lk, evp_pubk->type);
    return -1;
  }    
}

/* ------------- XML-ENC support -------------- */

/*() Symmetric key decryption using XML-ENC. The encryption algorithm is
 * auto-detected from the XML-ENC data.
 *
 * cf:: ZXID configuration object, used for memory allocation
 * ed:: Encrypted data as XML data structure
 * symkey:: Symmetric key used for decryption
 * return:: Decrypted data as zx_str. Caller should free this memory. */

/* Called by:  zxenc_privkey_dec */
struct zx_str* zxenc_symkey_dec(zxid_conf* cf, struct zx_xenc_EncryptedData_s* ed, struct zx_str* symkey)
{
  struct zx_str raw;
  struct zx_str* ss;
  char* lim;
  
  if (!ed || !ed->CipherData || !(ss = ZX_GET_CONTENT(ed->CipherData->CipherValue))) {
    ERR("EncryptedData element not found or malformed %p", ed->CipherData);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "EMISS", 0, "no EncryptedData");
    return 0;
  }
  
  if (!symkey) {
    ERR("Symmetric key missing. Perhaps public key operation to recover symmetric key failed (e.g. missing private key, or private key does not match public key). Perhaps the programmer simply failed to pass correct arguments to this function. %d", 0);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "EMISS", 0, "no symkey");
    return 0;
  }
  
  raw.s = ZX_ALLOC(cf->ctx, SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(ss->len));
  lim = unbase64_raw(ss->s, ss->s+ss->len, raw.s, zx_std_index_64);
  raw.len = lim - raw.s;
  
  ss = &ed->EncryptionMethod->Algorithm->g;
  if (sizeof(ENC_ALGO_TRIPLEDES_CBC)-1 == ss->len
      && !memcmp(ENC_ALGO_TRIPLEDES_CBC, ss->s, sizeof(ENC_ALGO_TRIPLEDES_CBC)-1)) {
    if (symkey->len != (192 >> 3)) goto wrong_key_len;
    ss = zx_raw_cipher(cf->ctx, "DES-EDE3-CBC", 0, symkey, raw.len-8, raw.s+8, 8, raw.s);

  } else if (sizeof(ENC_ALGO_AES128_CBC)-1 == ss->len
	     && !memcmp(ENC_ALGO_AES128_CBC, ss->s, sizeof(ENC_ALGO_AES128_CBC)-1)) {
    if (symkey->len != (128 >> 3)) goto wrong_key_len;
    ss = zx_raw_cipher(cf->ctx, "AES-128-CBC", 0, symkey, raw.len-16, raw.s+16, 16, raw.s);

  } else if (sizeof(ENC_ALGO_AES192_CBC)-1 == ss->len
	     && !memcmp(ENC_ALGO_AES192_CBC, ss->s, sizeof(ENC_ALGO_AES192_CBC)-1)) {
    if (symkey->len != (192 >> 3)) goto wrong_key_len;
    ss = zx_raw_cipher(cf->ctx, "AES-192-CBC", 0, symkey, raw.len-16, raw.s+16, 16, raw.s);    

  } else if (sizeof(ENC_ALGO_AES256_CBC)-1 == ss->len
	     && !memcmp(ENC_ALGO_AES256_CBC, ss->s, sizeof(ENC_ALGO_AES256_CBC)-1)) {
    if (symkey->len != (256 >> 3)) goto wrong_key_len;
    ss = zx_raw_cipher(cf->ctx, "AES-256-CBC", 0, symkey, raw.len-16, raw.s+16, 16, raw.s);
  } else {
    ERR("Unsupported key transformation method(%.*s)", ss->len, ss->s);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "ECRYPT", 0, "unsupported key transformation method");
    return 0;
  }
  ZX_FREE(cf->ctx, raw.s);
  DD("plain(%.*s)", ss->len, ss->s);
  D_XML_BLOB(cf, "PLAIN", ss->len, ss->s);
  return ss;

 wrong_key_len:
  ZX_FREE(cf->ctx, raw.s);
  ERR("Wrong key length %d for algo(%.*s)", symkey->len, ss->len, ss->s);
  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "ECRYPT", 0, "wrong key length");
  return 0;
}

/*() Private key decryption using XML-ENC. The encryption algorithm is
 * auto-detected from the XML-ENC data. The private key is looked up
 * from the configuration object.
 *
 * cf:: ZXID configuration object, used for memory allocation
 * ed:: Encrypted data as XML data structure
 * ek:: Symmetric encryption key data structure. If not supplied, the EncryptedKey
 *     element from EncryptedData is used
 * return:: Decrypted data as zx_str. Caller should free this memory. */

/* Called by:  zxid_dec_a7n, zxid_decrypt_nameid, zxid_decrypt_newnym, zxid_get_ses_sso_a7n */
struct zx_str* zxenc_privkey_dec(zxid_conf* cf, struct zx_xenc_EncryptedData_s* ed, struct zx_xenc_EncryptedKey_s* ek)
{
  EVP_PKEY* enc_pkey;
  RSA* rsa;
  struct zx_str raw;
  struct zx_str* symkey;
  struct zx_str* ss;
  char* lim;

  if (!ed) {
    ERR("Missing or malformed EncryptedData %d", 0);
    return 0;
  }

  if (!ek && ed->KeyInfo)
    ek = ed->KeyInfo->EncryptedKey;  /* Nested EncryptionKey method (Shib 2010) */
  if (!ek || !ek->CipherData || !(ss = ZX_GET_CONTENT(ek->CipherData->CipherValue)) || !ss->len) {
    ERR("EncryptedKey element not found or malformed %p", ek->CipherData);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "EMISS", 0, "EncryptedKey not found");
    return 0;
  }
  
  raw.s = ZX_ALLOC(cf->ctx, SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(ss->len));
  lim = unbase64_raw(ss->s, ss->s+ss->len, raw.s, zx_std_index_64);
  raw.len = lim - raw.s;
  
  LOCK(cf->mx, "zxenc_privkey_dec");      
  if (!(enc_pkey = cf->enc_pkey))
    enc_pkey = cf->enc_pkey = zxid_read_private_key(cf, "enc-nopw-cert.pem");
  UNLOCK(cf->mx, "zxenc_privkey_dec");      
  if (!enc_pkey)
    return 0;
  
  if (!ek->EncryptionMethod || !(ss = &ek->EncryptionMethod->Algorithm->g) || !ss->len) {
    ERR("Missing or malformed EncryptionMethod %p", ek->EncryptionMethod);
    return 0;
  }
  
  if (sizeof(ENC_KEYTRAN_RSA_1_5)-1 == ss->len
      && !memcmp(ENC_KEYTRAN_RSA_1_5, ss->s, sizeof(ENC_KEYTRAN_RSA_1_5)-1)) {
    rsa = EVP_PKEY_get1_RSA(enc_pkey);
    symkey = zx_rsa_priv_dec(cf->ctx, &raw, rsa, RSA_PKCS1_PADDING);
  } else if (sizeof(ENC_KEYTRAN_RSA_OAEP)-1 == ss->len
	     && !memcmp(ENC_KEYTRAN_RSA_OAEP, ss->s, sizeof(ENC_KEYTRAN_RSA_OAEP)-1)) {
    rsa = EVP_PKEY_get1_RSA(enc_pkey);
    symkey = zx_rsa_priv_dec(cf->ctx, &raw, rsa, RSA_PKCS1_OAEP_PADDING);
  } else {
    ERR("Unsupported key transformation method(%.*s)", ss->len, ss->s);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "ECRYPT", 0, "unsupported key transformation method");
    return 0;
  }
  ZX_FREE(cf->ctx, raw.s);
  if (symkey) {
    ss = zxenc_symkey_dec(cf, ed, symkey);
    zx_str_free(cf->ctx, symkey);
    return ss;
  } else
    return 0;
}

/*() Symmetric key encryption using XML-ENC. The encryption algorith is
 * auto-detected from the XML-ENC data.
 *
 * cf:: ZXID configuration object, used for memory allocation
 * data:: Data blob to encrypt. Typically serialized XML
 * ed_id:: The value of the ~Id~ XML attribute of the <EncryptedData> element
 * symkey:: Raw symmetric key used for encryption
 * symkey_id:: The value of the ~Id~ XML attribute of the <EncryptedKey> element
 * return:: Encrypted data as XML data structure. Caller should free this memory.
 *
 * *Example of XML-ENC encrypted data using RetrievalMethod pointing to EncryptedID Id="EK38"*
 *
 *   <sa:EncryptedID>
 *     <e:EncryptedData
 *         xmlns:e="http://www.w3.org/2001/04/xmlenc#"
 *         Id="ED38"
 *         Type="http://www.w3.org/2001/04/xmlenc#Element">
 *       <e:EncryptionMethod Algorithm="http://www.w3.org/2001/04/xmlenc#aes128-cbc"/>
 *       <ds:KeyInfo xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
 *         <ds:RetrievalMethod
 *             Type="http://www.w3.org/2001/04/xmlenc#EncryptedKey"
 *             URI="#EK38"/></>                                            # N.B. hash
 *       <e:CipherData>
 *         <e:CipherValue>FWfOV7aytBE2xIMe...YTA3ImLf9JCM/vdLIMizMf1</></></>
 *
 *     <e:EncryptedKey xmlns:e="http://www.w3.org/2001/04/xmlenc#" Id="EK38">
 *       <e:EncryptionMethod Algorithm="http://www.w3.org/2001/04/xmlenc#rsa-1_5"/>
 *       <ds:KeyInfo xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
 *         <ds:X509Data>
 *           <ds:X509Certificate>***</></></>
 *       <e:CipherData>
 *         <e:CipherValue>xf5HkmQM68t...7zRbxkqtniIVnxBHjkA=</></>
 *       <e:ReferenceList>
 *         <e:DataReference URI="#ED38"/></></></>                         # N.B. hash
 *
 * Alternative formulation is to replace the EncryptedData/KeyInfo/RetrievalMethod
 * with EncryptedData/KeyInfo/EncryptedKey, i.e. inline the EncryptedKey. As of 2010
 * Shibboleth appears to support only this method.
 */

/* Called by:  zxenc_pubkey_enc */
struct zx_xenc_EncryptedData_s* zxenc_symkey_enc(zxid_conf* cf, struct zx_str* data, struct zx_str* ed_id, struct zx_str* symkey, struct zx_xenc_EncryptedKey_s* ek)
{
  struct zx_str* ss;
  struct zx_str* b64;
  struct zx_xenc_EncryptedData_s* ed = zx_NEW_xenc_EncryptedData(cf->ctx,0);
  ed->Id = zx_ref_len_attr(cf->ctx, &ed->gg, zx_Id_ATTR, ed_id->len, ed_id->s);
  ed->Type = zx_ref_attr(cf->ctx, &ed->gg, zx_Type_ATTR, "http://www.w3.org/2001/04/xmlenc#Element");
  ed->EncryptionMethod = zx_NEW_xenc_EncryptionMethod(cf->ctx, &ed->gg);
  ed->EncryptionMethod->Algorithm = zx_ref_attr(cf->ctx, &ed->EncryptionMethod->gg, zx_Algorithm_ATTR, ENC_ALGO);
  if (ek) {
    ed->KeyInfo = zx_NEW_ds_KeyInfo(cf->ctx, &ed->gg);
    if (cf->enckey_opt & 0x20) {
      D("Nested EncryptedKey %p", ek); /* Shibboleth early 2010 */
      ZX_ADD_KID(ed->KeyInfo, EncryptedKey, ek);
    } else {
      D("Sibling EncryptedKey with RetrievalMethod %p", ek);
      ed->KeyInfo->RetrievalMethod = zx_NEW_ds_RetrievalMethod(cf->ctx, &ed->KeyInfo->gg);
      ed->KeyInfo->RetrievalMethod->Type = zx_ref_attr(cf->ctx, &ed->KeyInfo->RetrievalMethod->gg, zx_Type_ATTR, "http://www.w3.org/2001/04/xmlenc#EncryptedKey");
      ed->KeyInfo->RetrievalMethod->URI = zx_attrf(cf->ctx, &ed->KeyInfo->RetrievalMethod->gg, zx_URI_ATTR, "#%.*s", ek->Id->g.len, ek->Id->g.s);
    }
  }
  DD("Plaintext(%.*s)", data->len, data->s);
  D_XML_BLOB(cf, "PLAINTEXT", data->len, data->s);
  ss = zx_raw_cipher(cf->ctx, "AES-128-CBC", 1, symkey, data->len, data->s, 16, 0);
  b64 = zx_new_len_str(cf->ctx, SIMPLE_BASE64_LEN(ss->len));
  base64_fancy_raw(ss->s, ss->len, b64->s, std_basis_64, 0, 0, 0, '=');
  zx_str_free(cf->ctx, ss);
  ed->CipherData = zx_NEW_xenc_CipherData(cf->ctx, &ed->gg);
  ed->CipherData->CipherValue = zx_new_str_elem(cf->ctx, &ed->CipherData->gg, zx_xenc_CipherValue_ELEM, b64);
  zx_reverse_elem_lists(&ed->gg);
  return ed;
}

/*() Public key encryption using XML-ENC. The encryption algorithm is
 * auto-detected from the XML-ENC data.
 *
 * cf:: ZXID configuration object, used for memory allocation
 * data:: Data blob to encrypt. Typically serialized XML
 * ekp:: Result parameter. XML data structure corresponding to the <EncryptedKey>
 *     element will be returned. This is the encrypted symmetric key (which is
 *     pseudorandom generated inside this function). Usually used to set EncryptedKey
 *     field of EncryptedAssertion when using sister elements, aka RetrievalMethod, approach.
 *     When using nested EncryptedKey (Shib 2010) approach, leave null.
 * cert:: Certificate containing the public key used to encrypt the symmetric key
 * idsuffix:: Use to generate XML ~Id~ attributes for <EncryptedKey> and <EncryptedData>
 * return:: Encrypted data as XML data structure. Caller should free this memory. */

/* Called by:  zxid_mk_enc_a7n x2, zxid_mk_enc_id x2, zxid_mk_mni x2 */
struct zx_xenc_EncryptedData_s* zxenc_pubkey_enc(zxid_conf* cf, struct zx_str* data, struct zx_xenc_EncryptedKey_s** ekp, X509* cert, char* idsuffix, zxid_entity* meta)
{
  struct rsa_st* rsa_pkey;
  char symkey[128/8];
  struct zx_str symkey_ss;
  struct zx_str* ss;
  struct zx_str* b64;
  struct zx_xenc_EncryptedKey_s* ek = zx_NEW_xenc_EncryptedKey(cf->ctx,0);
  
  ek->Id = zx_attrf(cf->ctx, &ek->gg, zx_Id_ATTR, "EK%s", idsuffix);
  ek->EncryptionMethod = zx_NEW_xenc_EncryptionMethod(cf->ctx, &ek->gg);
  ek->EncryptionMethod->Algorithm = zx_ref_attr(cf->ctx, &ek->EncryptionMethod->gg, zx_Algorithm_ATTR, ENC_KEYTRAN_ALGO);
  ek->KeyInfo = zxid_key_info(cf, &ek->gg, cert);
  if (meta && cf->enckey_opt & 0x01) {
    /* This hack may help early 2010 vintage Shibboleth SP to work without nested EncryptedKey.
     * (personal communication w/Scott 20100906 --Sampo) */
    ek->Recipient = zx_dup_attr(cf->ctx, &ek->gg, zx_Recipient_ATTR, meta->eid);
  }
  
  zx_rand(symkey, sizeof(symkey));
  symkey_ss.len = sizeof(symkey);
  symkey_ss.s = symkey;
  rsa_pkey = zx_get_rsa_pub_from_cert(cert, "zxenc_pubkey_enc");
  if (!rsa_pkey)
    return 0;
  /* The padding setting MUST agree with ENC_KEYTRAN_ALGO setting (see near top of this file). */
#if 1
  ss = zx_rsa_pub_enc(cf->ctx, &symkey_ss, rsa_pkey, RSA_PKCS1_PADDING);
#else
  /* *** IBM did not interop with OAEP padding as of 20071025 */
  ss = zx_rsa_pub_enc(cf->ctx, &symkey_ss, rsa_pkey, RSA_PKCS1_OAEP_PADDING);
#endif
  
  b64 = zx_new_len_str(cf->ctx, SIMPLE_BASE64_LEN(ss->len));
  base64_fancy_raw(ss->s, ss->len, b64->s, std_basis_64, 0, 0, 0, '=');
  zx_str_free(cf->ctx, ss);
  ek->CipherData = zx_NEW_xenc_CipherData(cf->ctx, &ek->gg);
  ek->CipherData->CipherValue = zx_new_str_elem(cf->ctx, &ek->CipherData->gg, zx_xenc_CipherValue_ELEM, b64);
  ek->ReferenceList = zx_NEW_xenc_ReferenceList(cf->ctx, &ek->gg);
  ek->ReferenceList->DataReference = zx_NEW_xenc_DataReference(cf->ctx, &ek->ReferenceList->gg);
  ek->ReferenceList->DataReference->URI = zx_attrf(cf->ctx, &ek->ReferenceList->DataReference->gg, zx_URI_ATTR, "#ED%s", idsuffix);
  zx_reverse_elem_lists(&ek->gg);
  if (ekp)
    *ekp = ek;
  
  ss = zx_strf(cf->ctx, "ED%s", idsuffix);
  return zxenc_symkey_enc(cf, data, ss, &symkey_ss, ek);
}

/* EOF -- zxsig.c */
