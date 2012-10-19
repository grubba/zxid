/* zxidconf.h  -  Configuration of ZXID
 * Copyright (c) 2012 Synergetics (sampo@synergetics.be), All Rights Reserved.
 * Copyright (c) 2009-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidconf.h,v 1.51 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 29.8.2009, added PDP_URL --Sampo
 * 7.1.2010,  added WSC and WSP signing options --Sampo
 * 12.2.2011, added proxy IdP related options --Sampo
 * 10.12.2011, added VPATH, VURL, BUTTON_URL, delete ORG_URL --Sampo
 * 17.8.2012, added audit bus configuration --Sampo
 *
 * Most of the configuration options can be set via configuration
 * file /var/zxid/zxid.conf or using -O command line flag(s). In
 * config file or on command line you should omit the ZXID_ prefix
 * and use attribute=value syntax separated by newlines or & characters
 * (the parser implements CGI query string syntax with extension that
 * also \n is accepted as separator).
 *
 * N.B. The options marked as "(compile)" can not be set on command line
 * or configuration file. They require a recompile.
 */

#ifndef _zxidconf_h
#define _zxidconf_h

/*(c) Compile time configuration enforcement
 * Whether configuration is entirely determined at compile time by this file
 * or whether it is possible to use a config file or provide options on
 * command line using -c flags (such as via shell script wrapper) or via ZXID_CONF
 * environment variable. When zxid is used as a library, it depends on application to
 * call zxid_parse_conf().
 * Generally we recommend you leave these turned on (1). */

#define ZXID_CONF_FILE 1     /* (compile) */
#define ZXID_CONF_FLAG 1     /* (compile) ZXID_CONF environment variable and -c flag enable. */
#define ZXID_SHOW_CONF 1     /* Whether configuration is viewable from URL?o=d */

/*(c) ZXID configuration and working directory path
 * Where metadata cache and session files are created. Note that the directory
 * is not hashed: you should use a file system that scales easily to oodles
 * of small files in one directory. Say `make dir' to create the directory
 * with proper layout. If you change it here, also edit Makefile. */
#ifndef ZXID_PATH
#ifdef MINGW
#define ZXID_PATH  "c:/var/zxid/"
#else
#define ZXID_PATH  "/var/zxid/"
#endif
#endif

#define ZXID_PATH_MAX_RECURS_EXPAND_DEPTH 5  /* (compile) Max no of incls, nested PATH or VPATH */

/*(c) VPATH - PATH for a virtual server
 *
 * The VPATH allows different configuration PATH for different
 * virtual servers (multihoming) to exist, thus allowing
 * different zxid.conf files and different /var/zxid/ subdirectory.
 * If the config file <PATH><VPATH>zxid.conf exists (i.e. /var/zxid/<VPATH>zxid.conf
 * when using default PATH), then the PATH configuration variable is changed
 * to point to the VPATH, and the virtual host specific config file is read.
 *
 * VPATH is rendered by first inserting current PATH, unless VPATH starts by '/',
 * and then rendering each ordinary letter as is, but expanding the
 * following % (percent) specifications, inline:
 *
 *   %%  expands as single percent sign
 *   %a  access protocol prefix, e.g. "https://" or "http://"
 *   %h  the contents of environment variable HTTP_HOST (see CGI spec) This
 *       usually ends in :port if the port is nonstandard (thus usually
 *       you do not need %p or %P).
 *   %p  the contents of environment variable SERVER_PORT (see CGI spec)
 *   %s  the contents of environment variable SCRIPT_NAME (see CGI spec)
 *
 * > N.B. All other %-specs are reserved for future expansion
 *
 * After % expansion, the values are squashed to file path safe character set. In
 * particular, the / (slash) characters are converted to _ (underscore).
 *
 * VPATH is not really a configuration option on its own right (there is
 * no corresponding entry in struct zxid_conf), but rather a directive
 * that instructs on point of occurrance the PATH variable (see zxid.h)
 * to change and configuration file to be read.
 *
 * Default value: "%h/" (see definition of PATH for example).
 * See also: VURL
 */

#define ZXID_VPATH "%h/"

/*(c) SP Nickname for IdP User Interface
 * IMPORTANT: You should really configure this option.
 * The nice name may be used by IdP user interface to refer to the SP. It
 * is usually a short human readable name or description. It will also
 * appear in metadata as Organization/OrganizationDisplayName */
#define ZXID_NICE_NAME "ZXID configuration NICE_NAME: Set this to describe your site to humans"

/*(c) Branding button image URL for user interfaces (optional).
 * IdP BUTTON_URL is (may be) shown in SP IdP selection screens as
 * a button (provided that IDP_LIST_METH=2 (IDP_LIST_BRAND)) that
 * user can click to login using that IdP.
 *
 * SP BUTTON_URL is shown by IdP login screen so user understands which SP
 * requested the SSO. In this use, the "button" is not (usually?) clickable.
 *
 * BUTTON_URL will also appear in metadata as Organization/OrganizationURL,
 * see symlabs-saml-displayname-2008.pdf (submitted to OASIS SSTC) for
 * specification.
 *
 * The BUTTON_URL MUST contain substring "saml2_icon" and size designator (see spec),
 * to distinguish it from other uses of SAML2 MD Organization/OrganizationURL (which
 * are unspecified, but presumably include home page URL; original SAML2 MD spec
 * was too loose). ZXID only supports the usage as button image URL (as of 20111210).
 * BUTTON_URL is typically absolute URL (relative would not make sense as it
 * is referenced from other web site referring to your web site).
 *
 * Typical value::  https://your-site.com/your_brand_saml2_icon_150x60.png
 *
 * Other possible values:: Depending on SP user interface, you may
 *     use any of
 *
 *       https://your-site.com/your_brand_saml2_icon_468x60.png
 *       https://your-site.com/your_brand_saml2_icon_150x60.png
 *       https://your-site.com/your_brand_saml2_icon_16x16.png
 *
 *     This allows different types of user interfaces to be rendered, see
 *     PREF_BUTTON_SIZE config option. Check with your Trust Operator
 *     organization to understand the convention they use.
 *
 *     > N.B. As of 20111210, you can only specify one in configuration and
 *     > your own metadata, but any number are tolerated in foreign metadata.
 *
 * If BUTTON_URL is not supplied (the default (0)), the NICE_NAME, and
 * possibly EntityID, is displayed instead. */
#define ZXID_BUTTON_URL 0  /* By default no button URL is supplied. */

/*(c) Preferred branding button size (squash or ignore others)
 * See description of BUTTON_URL, above, for general notion of branding button.
 *
 * Since different user interfaces may require different sizes of branding button,
 * many SAML2 metadata provide several. PREF_BUTTON_SIZE must be a substring
 * of the OrganizationURL for it to be considered as preferred branding button.
 * Branding button will also have "saml2_icon" as substring. Lacking correct size,
 * any other branding button may be squashed to fit the right size, or textual
 * NICE_NAME and possibly EntityID may be displayed instead. Value SHOULD be
 * one of "468x60" (banners only mode, typically one per row), "150x60" (default,
 * multicolumn mode), "16x16" (detailed listing mode, typically with
 * OreanizationDisplayName and EntityID displayed as well). */
#define ZXID_PREF_BUTTON_SIZE "150x60"

/*(c) Web Site URL - root of EntityID
 * IMPORTANT: Failure to config this option may block zxid from operating.
 * URL for most zxid operations. It must end in whatever triggers
 * the ZXID functionality in the web server. The hostname
 * and port number should match the server under which zxid CGI is accessible.
 * N.B. There is no explicit way to configure Entity ID (Provider ID) for
 * the zxid SP. The Entity ID is always of form ZXID_URL?o=B, for example
 *   https://sp1.zxidsp.org:8443/zxid?o=B */
#define ZXID_URL "https://sp1.please-set-URL-zxid.conf-variable-to-some-useful-site-dep-value.org:8443/zxidhlo"

/*(c) VURL - URL for a virtual server
 *
 * The VURL allows different URL for different
 * virtual servers (multihoming) to be generated automatically based
 * on the (CGI) environment variables. However, often you would
 * override the URL in /var/zxid/zxid.conf
 *
 * In VURL each ordinary letter is rendered as is, but the
 * following % (percent) specifications are expanded inline:
 *
 *   %%  expands as single percent sign
 *   %a  access protocol prefix, e.g. "https://" or "http://"
 *   %h  the contents of environment variable HTTP_HOST (see CGI spec). This
 *       usually ends in :port if the port is nonstandard (thus usually
 *       you do not need %p or %P).
 *   %p  the contents of environment variable SERVER_PORT (see CGI spec).
 *   %P  Similar to %p, but renders a colon before the portnumber, unless
 *       the SERVER_PORT is 443 or 80, in which case nothing is rendered.
 *       This deals with default ports of the http and https protocols.
 *   %s  the contents of environment variable SCRIPT_NAME (see CGI spec)
 *
 * > N.B. All other %-specs are reserved for future expansion
 *
 * VURL is not really a configuration option on its own right (there is
 * no corresponding entry in struct zxid_conf), but rather a directive
 * that instructs, on point of its occurrance, the URL variable (see zxid.h)
 * to be computed. It will not have any effect unless evaluted at run time,
 * thus this "default value" is rather moot. You really need to specify
 * VURL in your own configuration.
 *
 * Default value: "%a%h%s"
 * See also: VPATH
 */
#define ZXID_VURL "%a%h%s"

/*(c) Override standard EntityID Construction
 * The best practise is that SP Entity ID is chosen by the SP (and not
 * forced upon SP by IdP). In ZXID this is done by setting ZXID_URL,
 * see above. However, should you have to work with an obstinate IdP
 * that refuses to follow this best practise, you can use this option
 * to manually set the Entity ID. Not following the best practise
 * breaks automatic metadata exchange (Auto-CoT). Recommended
 * value: leave as 0 so that Entity ID is formed from ZXID_URL */
#define ZXID_NON_STANDARD_ENTITYID 0

/*(c) Allow omission of o=B, i.e. make the URL be the entity ID. */
#define ZXID_BARE_URL_ENTITYID 0

/*(c) Illadviced ACS URL Hack
 * Sometimes an illadvised authority may impose to you Assertion
 * Consumer Service URL, this URL happens to be different than
 * ZXID uses, and you do not have political leverage to change
 * these decisions. In those times you can use this hack to
 * try to map the imposed URL to the one that works in ZXID.
 * Normally you should register at IdP to use the ZXID default
 * URLs (the easiest way to do this is to use metadata). This
 * config option only works in mod_auth_saml. */
#define ZXID_REDIRECT_HACK_IMPOSED_URL 0
#define ZXID_REDIRECT_HACK_ZXID_URL 0

/*(c) Additional Metadata Fields. Safe to leave all as NULL.
 * The LOCALITY, STATE, and COUNTRY will appear in certificates
 * so you may want to set them to sensible values. */
#define ZXID_ORG_NAME "Unspecified ORG_NAME conf variable"
#define ZXID_LOCALITY "Lisboa"
#define ZXID_STATE    "Lisboa"
#define ZXID_COUNTRY  "PT"
#define ZXID_CONTACT_ORG 0
#define ZXID_CONTACT_NAME 0
#define ZXID_CONTACT_EMAIL 0
#define ZXID_CONTACT_TEL 0

/*(c) If set (by default this is always set when URL is set, you have to
 * explicitly unset it if you do not want it), causes IdP to include
 * fedusername attribute in the assertion. The value of this attribute
 * will be the (persistent) nameid followed by @ sign and this suffix,
 * for example: FXyysxhM4F6d3DIwrtoiFdi0i@zxidp.org
 *
 * The fedusername attribute is a helper for the SP web sites that
 * are fixated on the notion of needing a username and/or requiring
 * the username to look like an email. By packaging the psedonym this
 * way it is easy to get them to work with minimal modification.
 * N.B. Although it looks like an email address, it is not. Do not try
 * sending mail to it (unless you hack your mailserver to understand it).
 */
#define ZXID_FEDUSERNAME_SUFFIX "set-this-or-url-to-site-dependent-value"

/*(c) IdP Attribute Generation Options
 * 0x01  If fedusername is generated, also generate
 *       urn:oid:1.3.6.1.4.1.5923.1.1.1.6 (aka ~eduPersonPrincipalName~)
 */
#define ZXID_IDPATOPT 0x01

/*(c) Common Domain Cookie URL
 * URL for reading Common Domain Cookie. It must end in "zxid". The hostname
 * and port number should match the server under which zxid CGI is accessible.
 * Specifying empty CDC_URL disables CDC check in zxid_simple() API. */
/*#define ZXID_CDC_URL "https://sp1.zxidcommon.org:8443/zxid"*/
/*#define ZXID_CDC_URL "https://a-sp.cot.projectliberty.org:8443/zxid"*/
#define ZXID_CDC_URL "" /* CDC disabled */

/*(c) CDC designated IdP Handling
 * How to handle CDC designated IdP. See zxid.h for explanation of constants. */
#define ZXID_CDC_CHOICE ZXID_CDC_CHOICE_UI_PREF

/*(c) Metadata Fetching Options (Auto-CoT)
 * Following four boolean configuration options control how metadata
 * is obtained. The metadata can be in a cache (by default directory /var/zxid/cot)
 * or it can be fetched "on the fly" using the well known location (WKL) method.
 *
 * MD_FETCH:: controls whether fetching is performed. This necessitates
 *     that ZXID was linked with libcurl. If you do not enable fetching, you
 *     will need to populate the cache manually, perhaps by using a web browser
 *     to fetch the meta data xml files from well known location URLs (or other
 *     URLs if you know better). Or you could use zxidcot.pl?op=md or zxcot(1) tool.
 *
 *     N.B. Even if fetching is enabled, the fetch can still fail due to
 *     network connectivity issues or due to other end not supporting it.
 *
 * MD_POPULATE_CACHE:: controls whether ZXID will write the metadata to
 *     the on-disk cache. This requires ZXID_MD_FETCH to be enabled
 *     and the file system permissions of the cache directory (e.g. /var/zxid/cot)
 *     to allow writing.
 *
 * MD_CACHE_FIRST:: controls whether cache will be checked before fetching
 *     is attempted. If cache misses, ZXID_MD_FETCH governs whether fetch is tried.
 *
 * MD_CACHE_LAST:: If true, metadata is obtained from cache
 *     if fetch was disabled or failed.
 *
 * If you want to control manually your CoT (e.g. because human process is
 * needed to verify that all the paperwork is in place), set MD_FETCH to 0.
 *
 * If you want as automatic operation as possible, set all four to 1.
 */

#define ZXID_MD_FETCH          1   /* The Auto-CoT ena option */
#define ZXID_MD_POPULATE_CACHE 1
#define ZXID_MD_CACHE_FIRST    1
#define ZXID_MD_CACHE_LAST     1

/*(c) Whether to load CoT cache from a file containing the concatenated metadata
 * of the Circle of Trust. Some real world federations distribute their
 * metadata this way. Setting this to 0 disables the feature (default).
 * Setting this to file name or path enables this feature. */
#define ZXID_LOAD_COT_CACHE 0

/*(c) Automatic Self-signed Cert Generation (Auto-Cert)
 * If ZXID does not find one of the certificate plus private key pairs
 * it needs to operate, it will generate automatically a self-signed
 * certificate and private key and populate it to the assigned
 * place. The certificate will be valid until the end of the Unix
 * epoch (2037).  If you do not want this to happen, you should
 * disable this option and install the certificate - private key pairs
 * manually to
 *
 *   /var/zxid/pem/enc-nopw-cert.pem
 *   /var/zxid/pem/sign-nopw-cert.pem
 *   /var/zxid/pem/logenc-nopw-cert.pem
 *   /var/zxid/pem/logsign-nopw-cert.pem
 *   /var/zxid/pem/ssl-nopw-cert.pem
 *
 * Hint: you can use same certificate - private key pair for
 * all purposes. Just copy the file. */
#define ZXID_AUTO_CERT 1

/*(c) Authentication Request Signing
 * Whether AuthnReq is signed by SP (controls both metadata and actual behavior). */
#define ZXID_AUTHN_REQ_SIGN 1

/*(c) Assertion Signing
 * Whether SP insists that SSO assertions are signed. Affects metadata. The
 * actual insistence on signing is controlled by ZXID_NOSIG_FATAL, far below.
 * Boolean. Recommended value: 1. */
#define ZXID_WANT_SSO_A7N_SIGNED 1

/*(c) SSO SOAP Message Signing
 * Whether SOAP messages for ArtifactResolution, SLO, and MNI are signed. Whether
 * responses are signed as well. (*** doc) */
#define ZXID_SSO_SOAP_SIGN 1
#define ZXID_SSO_SOAP_RESP_SIGN 1

/*(c) IdP Signing Options
 * Which components should be signed by IdP in SSO Response and Assertion.
 * Bit mask:
 *   0x01  Assertion should be signed (default and highly recommended)
 *   0x02  The surrounding Response element should be signed
 *   0x03  Both Assertion and Response are signed. */
#define ZXID_SSO_SIGN 0x01

/*(c) NameID Encryption
 * Whether SLO and MNI requests emitted by ZXID will encrypt the
 * NameID (on received requests ZXID accepts either plain or encrypted
 * automatically and without configuration). (*** doc) */
#define ZXID_NAMEID_ENC 0x0f

/*(c) Assertion Encryption in POST
 * Whether to encrypt assertions when using POST bindings. */
#define ZXID_POST_A7N_ENC 1

/*(c) When producing EncryptedID, EncruptedAssertion, or EncryptedAttribute,
 * how is the EncryptedKey stored relative to EncryptedData
 *
 * 0x00  Sibling, without Recipient hint (interops with many commercial implementations and Shibboleth Sept 2010)
 * 0x01  Sibling, with Recipient hint (interops with many commercial implementations and Shibboleth as of August 2010)
 * 0x20  Nested method, i.e. EncryptedData/KeyInfo/EncryptedKey (interops with all versions of Shibboleth and many others)
 *
 * N.B:: SAML2 specs fail to say which approach is preferred, therefore both
 *     approaches are valid. In reading messages ZXID automatically understands both.
 *     This option only controls how outbound messages are generated so that others
 *     can understand them (ideally they would autodetect so we would not need this option).
 */
#define ZXID_ENCKEY_OPT 0x20

/*(c) Controls whether new fedarations can be created during discovery. */
#define ZXID_DI_ALLOW_CREATE '1'

/*(c) Controls the default NameID Format for discovery: p=persistent, t=transient */
#define ZXID_DI_NID_FMT 'p'

/*(c) Controls whether assertions emitted by discovery are encrypted.
 * It is highly recommended to encrypt the assertions to avoid man-in-the-middle
 * attacks. */
#define ZXID_DI_A7N_ENC 1

/*(c) Control how many levels of bootstraps are added to assertions. Normally
 * only first level is added, i.e. all available bootstraps are embedded in
 * the assertion, but the assertions of the embedded bootstraps only
 * get discovery bootstrap. 2 would cause the assertions of the first order
 * bootstraps to have further bootstraps embedded, etc. Since bootstrap
 * generation tends to be expensive and wasteful, you should use discovery
 * instead and leave BOOTSTRAP_LEVEL set to 1. */
#define ZXID_BOOTSTRAP_LEVEL 1

/*(c) WSC Signing Options
 * Which components of a web service request should be signed by WSC
 * Bit mask:
 *   0x01  SOAP Headers
 *   0x02  SOAP Body
 *   0x03  Both Headers and Body are signed. */
#define ZXID_WSC_SIGN 0x03

/*(c) WSP Signing Options
 * Which components of a web service response should be signed by WSP
 * Bit mask:
 *   0x01  SOAP Headers
 *   0x02  SOAP Body
 *   0x03  Both Headers and Body are signed. */
#define ZXID_WSP_SIGN 0x03

/*(c) OAUTH2 / OpenID-Connect1 id_token signing and encryption options
 * 'n': alg=none
 * 'h': alg=HS256 (HMAC using SHWA256)
 * 'r': alg=RS256 (RSA using SHA256)
 */
#define ZXID_OAZ_JWT_SIGENC_ALG 'n'

/*(c) Command that will be executed by zxidwspcgi to respond to a web service call. */
#ifndef ZXID_WSPCGICMD
#define ZXID_WSPCGICMD "./zxid-wspcgicmd.sh"
#endif

/*(c) Bit length of identifiers, unguessability
 * How many random bits to use in an ID. It would be useful if this was
 * such that it produces nice unpadded base64 string, i.e. multiple of 24 bits.
 * Longer IDs reduce chances of random collision (most code does not
 * check uniqueness of ID) and may increase security. For security purposes
 * 144 bits is probably good enough. The unguessability of ID has security
 * implications, among others, in session IDs. You may want to use less than
 * 144 bits if your application could benefit from shorter IDs (e.g. you target
 * browsers with length constrained URLs) and does not need to be
 * secure against attacks with government level resources.
 * E.g:  24 bits ==  3 bytes ==  4 safe_base64 chars,
 *       48 bits ==  6 bytes ==  8 safe_base64 chars,
 *      120 bits == 15 bytes == 20 safe_base64 chars,
 *      144 bits == 18 bytes == 24 safe_base64 chars */
#define ZXID_ID_BITS 144      /* (compile) */
#define ZXID_ID_MAX_BITS 168  /* used for static buffer allocation (compile) */

/*(c) True randomness vs. pseudorandom source
 * Whether true randomness is obtained.
 * 0=use OpenSSL RAND_pseudo_bytes(), which usually uses /dev/urandom
 * 1=use OpenSSL RAND_bytes(), which usually uses /dev/random
 *
 * Although true randomness may be more secure, it is operationally
 * problematic because if not enough randomness is available, the
 * system will block (stop) until enough randomness arrives. Generally
 * true randomness is not feasible in a server environment unless
 * you have a hardware random number generator. */
#define ZXID_TRUE_RAND 0  /* (compile) */

/*(c) Session Archival Directory
 * If set to a string, indicates a file system directory to which
 * dead sessions are moved (sessions are files). This directory
 * must be on the same file system as active session directory,
 * usually /var/zxid/ses, for example /var/zxid/oldses.
 * You may want to archive old sessions because they contain
 * the SSO assertions that allowed the users to log in. This
 * may have legal value for your application, you may even be required
 * by law to keep this audit trail. On the other hand, other
 * jurisdictions will require you to delete this information.
 *
 * If set to 0, causes old sessions to be unlink(2)'d. */
#define ZXID_SES_ARCH_DIR 0  /* 0=Remove dead sessions. */

/*(c) Session cookies.
 * For original Netscape cookie spec see: http://curl.haxx.se/rfc/cookie_spec.html (Oct2007)
 *
 * If SES_COOKIE_NAME is nonempty string, then
 * zxid_simple() will look for said cookie and use it as session ID.
 * It will also attempt to set a cookie by that name when new session
 * is created (but this may rely on some support in the calling app,
 * generally the need to set a cookie is expressed by presence of
 * setcookie attribute in the LDIF entry. setcookie specifies what
 * should appear in the Set-Cookie HTTP header of HTTP response). */
#ifndef ZXID_SES_COOKIE_NAME
#define ZXID_SES_COOKIE_NAME "ZXIDSES"
#endif

/*(c) PTM hint cookie
 * If PTM_COOKIE_NAME is nonempty string, then
 * zxid_simple() will attempt to set a cookie by that name when new session
 * is created (but this may rely on some support in the calling app,
 * generally the need to set a cookie is expressed by presence of
 * setcookie attribute in the LDIF entry. setcookie specifies what
 * should appear in the Set-Cookie HTTP header of HTTP response). */
#define ZXID_PTM_COOKIE_NAME "ZXIDPTM"

/*(c) Local user account management.
 * This is optional unless you require IdP
 * initiated ManageNameID requests to work. Local user account management
 * may be useful on its own right if your application does not yet have
 * such system. If it already has, you probably want to continue to use
 * the application's own system. Local accounts are stored under
 * /var/zxid/user/SHA1 */
#define ZXID_USER_LOCAL 1

/*(c) Mini IdP
 * Whether limited IdP functionality is enabled. Affects generated metadata. */
#define ZXID_IDP_ENA 0

/*(c) IdP Proxying, i.e. IdP can be SP towards another IdP. */
#define ZXID_IDP_PXY_ENA 0

/*(c) Identity Mapper and People Service
 * Whether limited Identity Mapper and People Service functionality is enabled.
 * For this to work, IDP_ENA=1 is needed. */
#define ZXID_IMPS_ENA 0

/*(c) Mini Authentication Service
 * Whether limited Authentication Service functionality is enabled.
 * Please note that the AuthenticationService impmenetation at present (2010)
 * is incomplete and fails to properly authenticate and authorize the caller
 * system entity, i.e. anyone who knows a username and password can call it. */
#define ZXID_AS_ENA 0

/*(c) Dummy PDP
 * Whether limited PDP functionality is enabled. */
#define ZXID_PDP_ENA 1

/*(c) IdP Insitence on Signed AuthnReq
 * Must AuthnReq be signed (controls both IdP metadata and actual behavior, i.e. the check). */
#define ZXID_WANT_AUTHN_REQ_SIGNED 1

/*() Maximum filesystem path length used in /var/zxid tree. */
#define ZXID_MAX_BUF 1024  /* (compile) */

/*(c) Logging Options
 * See zxid-log.pd for further explanation. Generally you
 * need error and activity logs to know yourself what is going on.
 * You need the issue logs to know whether other's claims towards you are justified.
 * You need the rely logs to hold others responsible. The bits of the
 * value are as follows
 * 0x00    Don't log.
 * 0x01    Log enable
 * 0x06    Signing options    
 *         0:: no signing (Px)
 *         2:: sha1 MD only (Sx)
 *         4:: RSA-SHA1 (Rx)
 *         6:: DSA-SHA1 (Dx)
 * 0x08    reserved
 * 0x70    Encryption options
 *         0x00:: no encryption (xP)
 *         0x10:: zip-base64 (xZ)
 *         0x20:: RSA-AES (xA)
 *         0x30:: RSA-3DES (xT)
 *         0x40:: Symmetric AES (xB)
 *         0x50:: Symmetric 3DES (xU)
 *         0x60:: reserved
 *         0x70:: reserved
 * 0x80    reserved
 *
 * N.B. Every encryption and signature has computational cost so be sure to factor this
 * in when doing benchmarks - or disable log enc and sign when performance is at premium.
 *
 * Log signing may help you to argue that log evidence was (not) tampered with.
 * The private key for signing must be available in /var/zxid/pem/logsign-nopw-cert.pem
 *
 * Log encryption may help to keep the logs confidential.
 * For RSA modes the public key for encryption must be available
 * in /var/zxid/pem/logenc-nopw-cert.pem. For symmetric encryption the key
 * is the sha1 hash of file /var/zxid/pem/logenc.key
 * All modes, except for 0, also RFC1951 zip compress the log line and safe-base64 encode
 * the result of the encryption.
 */

/* Most common combinations of the above flags. */
#define ZXLOG_OP_NOLOG        0x00
#define ZXLOG_OP_LOG          0x01
#define ZXLOG_OP_LOG_SIGN     0x05
#define ZXLOG_OP_LOG_ENC      0x21
#define ZXLOG_OP_LOG_SIGN_ENC 0x25

#if 1
/* Production settings to ship. */
#define ZXLOG_ERR        0x01  /* Log errors to /var/zxid/log/err */
#define ZXLOG_ACT        0x01  /* Log activity to /var/zxid/log/act */
#define ZXLOG_ISSUE_A7N  0x01  /* Log each issued assertion to /var/zxid/log/issue/SHA1/a7n/asn */
#define ZXLOG_ISSUE_MSG  0x01  /* Log each issued PDU to /var/zxid/log/issue/SHA1/msg/asn */
#define ZXLOG_RELY_A7N   0x01  /* Log each received assertion to /var/zxid/log/rely/SHA1/a7n/asn */
#define ZXLOG_RELY_MSG   0x01  /* Log each received PDU to /var/zxid/log/rely/SHA1/msg/MSGID */
#else
/* Test settings */
#define ZXLOG_ERR        0x00
#define ZXLOG_ACT        0x25
#define ZXLOG_ISSUE_A7N  0x23
#define ZXLOG_ISSUE_MSG  0x45
#define ZXLOG_RELY_A7N   0x41
#define ZXLOG_RELY_MSG   0x11
#endif

/*(c) How Audit Bus receipts are issued. 0x00 = no receipt, 0x01 = plain, 0x05 = RSA-SHA1 */

#define ZXBUS_RCPT 0x05

/*(c) Choice of log given Error or Action
 * Each operation has its status code and generally those lines that indicate
 * successful status (or intermediate status like "continue" or "redirect")
 * are considered normal activity. However, you may want to consider
 * carefully whether signature failure in assertion or message disqualifies
 * an operation as "activity". One approach is to simply log everything (errors and all) to
 * activity log and rely on some log analysis software to flag the errors. */
#define ZXLOG_ERR_IN_ACT     1  /* Log errors to /var/zxid/log/act (in addition to err) */
#define ZXLOG_ACT_IN_ERR     1  /* Log actions to /var/zxid/log/err (in addition to act) */
#define ZXLOG_SIGFAIL_IS_ERR 1  /* Log line with signature validation error to /var/zxid/log/err */

/*(c) Log level for activity log.
 * 0 = Only essential audit relevant events are logged. Note that
 *     there is no way to turn off logging audit relevant events.
 * 1 = Audit and external interactions
 * 2 = Audit, external interactions, and significant internal events
 * 3 and higher: reserved for future definition and debugging */
#define ZXLOG_LEVEL 2

/*(c) Per user activity logging.
 * This option enables logging in /var/zxid/idpuid/UID/.log some key
 * events such as authentication, SSO, and SLO. */
#define ZXID_LOGUSER 1

/*(c) Set debug option. You can also set this via zxid_set_opt().
 * 0 = debug output off
 * 1 = debug on
 * other values are reserved, experimental, or otherwise undocumented. */
#define ZXID_DEBUG 0

/*(c) Send debug output to a file. You can also set this via zxid_set_opt_cstr().
 * By default the debug output goes to stderr, which often goes to
 * web server's error_log. */
#define ZXID_DEBUG_LOG 0

/*(c) Audit Bus servers. Multiple, comma separated, URLs may be
 * specified (audit bus servers are instances of zxbusd, which see).
 * If no BUS_URL is configured, no audit bus logging is performed. */
#define ZXID_BUS_URL 0

/*(c) Audit bus password if not using ClientTLS. Generally using
 * ClientTLS is RECOMMENDED and the certificate is taken from
 * metadata encryption certificate field so there is nothing
 * special to configure here. However, if for some reason you
 * need to run plain TLS, with STOMP 1.1 passcode filed for authentication,
 * the set this option to the passcode. Note that using passcode is much
 * less secure than using ClientTLS. Another limitation of BUS_PW
 * approach is that it is shared across all audit bus servers. */
#define ZXID_BUS_PW 0

/*(c) Assertion validation options.
 * These MUST all be turned on (and assertions signed)
 * if you want to rely on assertions to hold the other party liable. */

#define ZXID_SIG_FATAL      1 /* Signature validation error is fatal (prevents SSO) */
#define ZXID_NOSIG_FATAL    1 /* Missing signature is fatal (prevents SSO) */
#define ZXID_MSG_SIG_OK     1 /* Message layer signature (e.g. SimpleSign) is sufficeint when assertion signature is missing. */
#define ZXID_AUDIENCE_FATAL 1 /* Whether AudienceRestriction is checked. */
#define ZXID_TIMEOUT_FATAL  1 /* Whether NotBefore and NotOnOrAfter are checked */
#define ZXID_DUP_A7N_FATAL  1 /* Whether duplicate AssertionID is considered fatal. */
#define ZXID_DUP_MSG_FATAL  1 /* Whether duplicate MessageID or message is considered fatal. */
#define ZXID_RELTO_FATAL    1 /* Whether failure to correlate RelatesTo to MessageID, or total lack of RelatesTo, is considered fatal. */

/*(c) Web service request and response validation options. For the token
 * in the request, the assertion validation options apply. */
#define ZXID_WSP_NOSIG_FATAL 1 /* Missing Security/Signature is fatal. */
#define ZXID_NOTIMESTAMP_FATAL 1 /* Missing Security/Timestamp is fatal. */

/*(c) XML canonicalization compatibility kludges */

#define ZXID_CANON_INOPT 0
/* Shibboleth 2.1.5 IdP miscanonicalizes by
 * ignoring InclusiveNamespaces/@PrefixList, yet
 * it still supplies such list. The miscanonicalization
 * leads namespaces missing. This has been reported to Scott Cantor as of 20101005 */
#define ZXID_CANON_INOPT_SHIB215IDP_INCLUSIVENAMESPACES 0x01

/*(c) XML encoding optimizations.
 * 1 = optimize close tag of empty elements as <ns:foo/> */
#define ZXID_ENC_TAIL_OPT 1

/*(c) SOAP Envelope validation options. In well configured and
 * bug free environment, you should not need any of these options.
 * Turning them on will reduce security as validations are not made.
 *
 * 0x01 Skip response header validation entirely, see zxid_wsc_valid_re_env()
 */
#define ZXID_VALID_OPT 0x00
#define ZXID_VALID_OPT_SKIP_RESP_HDR 0x01

/*(c) Time Slop
 * Because clock sychronization amoung the servers in the CoT is unlikely
 * to be perfect, not to speak of timezone misconfigurations and the
 * dreaded officially introduced time errors (e.g. daylight "savings" time),
 * you can configure some slop in how the timeout is evaluated. For production
 * use something like 60 seconds could be a good value. 3600 = 1 hour, 86400 = 1 day.
 * All servers of CoT MUST use GMT (aka UTC), not local timezones. You can synchronize
 * clocks with ntpdate pool.ntp.org (see man ntpdate).
 * Slop is used in assessing validity of assertions as well as message timestamps.
 * Time skew allows our end to lie about the time, e.g. if we are in GMT, but
 * the other end is not and therefore we are rejected. Note that the time skew
 * is same for all other ends, therefore this is not really a good solution.
 * Only good solution is to have all servers synchronized to GMT (UTC) as the specs say.
 * While flexibility is nice, there is enough rope here to hang yourself so don't do that. :-) */
#define ZXID_BEFORE_SLOP    39600 /* Number of seconds before that is acceptable. */
#define ZXID_AFTER_SLOP     7300  /* Number of seconds after that is acceptable. */

#define ZXID_TIMESKEW       0      /* Timeskew, in seconds, for timestamps we emit. */
#define ZXID_A7NTTL         3600   /* Time To Live for IdP issued Assertions */

/*(c) Redirect to Content
 * Should explicit redirect to content be used (vs. internal redir). With
 * internal redirect there is one over-the-wire transaction less, but
 * the URL appears as whatever was sent by the IdP. With explicit (302)
 * redirect the URL will appear as the true content URL, without the SAML SSO goo. */
#define ZXID_REDIR_TO_CONTENT 1

/*(c) ID-WSF SOAP Call parameters */

#define ZXID_MAX_SOAP_RETRY 5  /* Maximum retries due, e.g., EndpointMoved */

/*(c) Session Management Trigger Suffix
 * In mod_auth_saml the URL ending that triggers session management (e.g. SLO MNI). */
// *** remove #define ZXID_MOD_SAML_MGMT_SUFFIX "/saml"

/*(c) Attribute Prefix
 * In mod_auth_saml the prefix (potentially empty) for attributes brought into environment. */

#define ZXID_MOD_SAML_ATTR_PREFIX "SAML_"

/*(c) Fake Basic Auth by generating REMOTE_USER
 * In mod_auth_saml generate REMOTE_USER subprocess environment variable. */

#define ZXID_REMOTE_USER_ENA 1

/*(c) Query String if None Given */

#define ZXID_DEFAULTQS ""   /* Default Query String used by mod_auth_saml for protected page */

/*(c) Anonymous can see protected content
 * If ANON_OK is set and matches prefix of the local URL, SSO failure does
 * not block protected content from being
 * shown. While this usually is a security problem, in some circumstances
 * you may want to show error message or nonpersonalized content from the
 * application layer. If application checks that the SSO really happened,
 * then there is no security problem - the responsibility is application's.
 * Typically ANON_OK=/dir/ is used with IsPassive (fp=1) to implement personalization
 * if user already has session, but allow the user to access page anonymously
 * without logging in if he does not have session. */
#define ZXID_ANON_OK 0

/*(c) Required Authentication Context Class Ref.
 * This can be used
 * to ensure that the IdP has authenticated user sufficiently.
 * In some cases this can trigger step-up authentication.
 * Value should be dollar separated string of acceptable authn context
 * class refs, e.g. ""
 * If step-up authentication is triggered, you need to ensure the fa query
 * string argument of the IdP selection page also requests the desired
 * authentication contrext class reference.
 * If not specified, then any authentication context is acceptable. */
#define ZXID_REQUIRED_AUTHNCTX 0

/*(c) IdP: Authentication Context Class Ref for Passwords
 * What authentication context IdP issues for password authentication. The
 * problem here is that ZXID does not know whether transport layer is TLS (assumed).
 * If it is not, you should configure this to be
 * "urn:oasis:names:tc:SAML:2.0:ac:classes:Password"
 * or you can configure this according to your IdP operational policies. */
#define ZXID_ISSUE_AUTHNCTX_PW "urn:oasis:names:tc:SAML:2.0:ac:classes:PasswordProtectedTransport"

/*(c) IdP preference for ACS
 * If SP does not manifest preference regarding the binding for Assertion Consumer Service,
 * then this IdP preference is used, unless SP metadata indicates it can not
 * support this binding, in which case the first ACS from metadata is used. */
#define ZXID_IDP_PREF_ACS_BINDING "urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST"

/*(c) List of unsuppressible attributes. Every SSO and discovery will include
 * these attributes, if they are defined for the user. Comma separated list. */

#define ZXID_MANDATORY_ATTR "zxidvers,zxidloa"

/* ----------------------------------------------------------------------------- */
/*(c) Attribute Broker definitions */

#define ZXID_NEED "idpnid,affid,role$undisclosed,log$400000$$"
#define ZXID_WANT "*,authnctxlevel,sesid,setcookie,cookie,rs,cn$undisclosed,log$400000$$"
#define ZXID_ATTRSRC ""
#define ZXID_INMAP ""
#define ZXID_OUTMAP ""
//#define ZXID_SUPPRESS ""

/* ----------------------------------------------------------------------------- */
/*(c) Policy Decision Point (PDP) URLs
 * If PDP_URL is set, then the indicated PDP will be consulted in
 * the end of SSO, i.e. by zxid_simple().
 * PDP_CALL_URL is used if zxid_az() family of functions
 * are called. If PDP_CALL_URL is not set, but PDP_URL is
 * set, the PDP_URL value will be used by zxid_az(). If you
 * always want to explicitly call zxid_az() and do not want
 * zxid_simple() to make implicit calls to PDP, just set
 * PDP_CALL_URL and leave PDP_URL as 0. */
#define ZXID_PDP_URL 0
#define ZXID_PDP_CALL_URL 0

/*(c) Trust Policy Decision Point (PDP) URL If TRUSTPDP_URL is set and
 * appropriate discovery options are passed, then the indicated PDP
 * will be consulted during discovery processing to determine if a
 * service should be returned. Default value 0 prevents such processing. */
#define ZXID_TRUSTPDP_URL 0

/*(c) Enable discovery and web service call to perform TAS3 Credentials
 * and Privacy Negotiation call. For this to work, there must be discovery registration
 * for service type urn:tas3:cpn-agent as well. */
#define ZXID_CPN_ENA 0

/*(c) Kludgy options for AZ debugging and to work-around bugs of others.
 * 0x01: prevent WS-Security header in SOAP XACML requests.  */
#define ZXID_AZ_OPT 0

/*(c) Which version of XACML to speak, e.g. "2.0" or "2.0-cd1" or "xac-soap" */

#define ZXID_XASP_VERS "2.0"

/*(c) What to pass in XACML PolicySetIdReference when calling PDP.
 * Empty means not to pass PolicySetIdReference. */

#define ZXID_XA_POLICY_SET_ID_REF ""  /* *** implement */

/*(c) Specify common XACML Attributes for PEPs in format ns$A$rule$b$ext (compile)
 * The ZXID_COMMAP can only be specified at compile time. At run time
 * each map has to be specified separately, sorry.
 * The order of processing rules has not been fixed yet, but
 * currently (Feb2011/R0.76) the first rule is processed last, e.g.
 * the "env$*$$$" stanza that appears as first below causes
 * all other attributes to be considered environment attributes.
 * See documentation for INMAP for syntax of the stanzas. */
#define ZXID_COMMAP       "env$*$$$;subj$idpnid$rename$urn:oasis:names:tc:xacml:1.0:subject:subject-id$;subj$urn:oasis:names:tc:xacml:1.0:subject:subject-id$$$;subj$urn:oid:1.3.6.1.4.1.5923.1.1.1.1$$$;subj$urn:oid:1.3.6.1.4.1.5923.1.1.1.7$$$;subj$eduPersonAffiliation$$$;subj$eduPersonEntitlement$$$;subj$role$$$;rsrc$rs$unsb64-inf$urn:oasis:names:tc:xacml:1.0:resource:resource-id$;rsrc$urn:oasis:names:tc:xacml:1.0:resource:resource-id$$$;act$Action$rename$urn:oasis:names:tc:xacml:1.0:action:action-id$;act$urn:oasis:names:tc:xacml:1.0:action:action-id$$$;env$ZXID_PEPvers$$$;$cookie$del$$;$setcookie$del$$;$setptmcookie$del$$"

/*(c) Specify XACML Attributes for SSO / frontchannel request in PEP in format ns$A$rule$b$ext */
#define ZXID_PEPMAP       ZXID_COMMAP

/*(c) Specify XACML Attributes for Request Outbound PEP at WSC (1) in format ns$A$rule$b$ext */
#define ZXID_PEPMAP_RQOUT ZXID_COMMAP

/*(c) Specify XACML Attributes for Request Inbound PEP at WSP (2) in format ns$A$rule$b$ext */
#define ZXID_PEPMAP_RQIN  ZXID_COMMAP

/*(c) Specify XACML Attributes for Response Outbound PEP at WSP (3) in format ns$A$rule$b$ext */
#define ZXID_PEPMAP_RSOUT ZXID_COMMAP

/*(c) Specify XACML Attributes for Response Inbound PEP at WSC (4) in format ns$A$rule$b$ext */
#define ZXID_PEPMAP_RSIN  ZXID_COMMAP

//#define ZXID_XACML2_SUBJ  "idpnid=$idpnid&role=$role"
//#define ZXID_XACML2_RSRC  "URL=$URL"
//#define ZXID_XACML2_ACT   "Action=$Action"
//#define ZXID_XACML2_ENV   "ZXID_PEPVers"

/*(c) Default AAMAP to pass all attributes (except dangerous ones) through.
 * idpsesid is blocked on grounds of being a sessionwide correlation handle. */
#define ZXID_DEFAULT_IDP_AAMAP "$*$$$;$idpsesid$del$$"  /* (compile) */

/*(c) Whitelists and blacklists for the primitive SSO local PDP. Comma separated lists. */

#define ZXID_LOCALPDP_ROLE_PERMIT 0   /* Whitelist of roles (empty: anything goes) */
#define ZXID_LOCALPDP_ROLE_DENY   "local_deny"      /* Blacklist of roles */
#define ZXID_LOCALPDP_IDPNID_PERMIT 0 /* Whitelist of permitted users (empty: anything goes) */
#define ZXID_LOCALPDP_IDPNID_DENY "denynid" /* Blacklist of denied users */

/*(c) Obligations we are willing to respect (unless an explicit UsageDirectives header
 * is specified by caller), require, generate, and accept. */
#define ZXID_WSC_LOCALPDP_OBL_PLEDGE  0  /* String: WSC pledged obligations in SOL notation */
#define ZXID_WSP_LOCALPDP_OBL_REQ     0  /* String: WSP required obligations in SOL notation */
#define ZXID_WSP_LOCALPDP_OBL_EMIT    0  /* String: WSP obligations emitted on resp */
#define ZXID_WSC_LOCALPDP_OBL_ACCEPT  0  /* String: WSC acceptable obligations in SOL notation */

/* ----------------------------------------------------------------------------- */
/*(c) Simple API HTML customization.
 * These allow simple branding and customization.
 * If these options are not enough for you, consider simply rendering your own forms. */

/*(c) Whether to show more technical fields in the GUI. Normally they
 * are hidden and POST profile is used */
#define ZXID_SHOW_TECH 0

/*(c) Body tag for some old ZXID generated pages. Edit this to change the colors. But usually
 * you should be editing stylesheet or template. */
#define ZXID_BODY_TAG "<body bgcolor=white>"  /* (compile) */

/*(c) Path for Template for IdP Selector Page. This template is used
 * by Service Provider to render the SP "login" screen which really
 * is the IdP selection screen (as the authentication login is done
 * on IdP side). */

#define ZXID_IDP_SEL_TEMPL_FILE "idpsel.html"

/*(c) Template for IdP Selector Page that is used if the
 * path does not work. This is really meant to be the last resort. */

#define ZXID_IDP_SEL_TEMPL "<title>ZXID SP SSO: Choose IdP</title>"\
  "<link type=\"text/css\" rel=stylesheet href=\"idpsel.css\"><body bgcolor=white>"\
  "<h1 class=zxtop>ZXID SP Federated SSO (user NOT logged in, no session)</h1>"\
  "<form method=get action=\"!!URL\">"\
  "<div class=zxerr>!!ERR</div><div class=zxmsg>!!MSG</div><div class=zxdbg>!!DBG</div>"\
  "<h3>Login Using New IdP</h3>"\
  "<i>A new IdP is one whose metadata we do not have yet. We need to know "\
  "the IdP URL (aka Entity ID) in order to fetch the metadata using the "\
  "well known location method. You will need to ask the adminstrator of "\
  "the IdP to tell you what the EntityID is.</i>"\
  "<p>IdP URL <input name=e size=60><input type=submit name=l0 value=\" Login \"><br>"\
  "Entity ID of this SP (click on the link to fetch the SP metadata): <a href=\"!!EID\">!!EID</a>"\
  "<p>!!IDP_LIST<h3>Technical options</h3>"\
  "<input type=hidden name=fc value=1><input type=hidden name=fn value=prstnt>"\
  "<!-- ZXID built-in defaults, see IDP_SEL_TEMPL in zxidconf.h and zxid-conf.pd for explanation -->"\
  "<input type=hidden name=fq value=\"\">"\
  "<input type=hidden name=fy value=\"\">"\
  "<input type=hidden name=fa value=\"\">"\
  "<input type=hidden name=fm value=\"\">"\
  "<input type=hidden name=fp value=0>"\
  "<input type=hidden name=ff value=0>"\
  "</form>"\
  "<div class=zxbot><a class=zx href=\"http://zxid.org/\">zxid.org</a>, !!VERSION (builtin)</div>"

/*(c) Choose the method for rendeing IdP list.
 * 0 = popup menu
 * 1 = buttons
 * 2 = branded image buttons (a la "nascar")
 * This configuration option is effective if !!IDP_LIST variable
 * is used in template. The variables !!IDP_POPUP, !!IDP_BUTTON, and !!IDP_BRAND
 * in template override this option. */
#define ZXID_IDP_LIST_METH 0

#define ZXID_IDP_LIST_POPUP   0
#define ZXID_IDP_LIST_BUTTON  1
#define ZXID_IDP_LIST_BRAND   2

/*(c) IdP Selector Page URL
 * If the IDP_SEL_TEMPL_FILE or IDP_SEL_TEMPL, above, is not sufficient for
 * your customization needs, you can provide URL to page of your own design.
 *This page will receive as query string argument the relay state.
 * 0 (zero) disables. */

#define ZXID_IDP_SEL_PAGE 0

/*(c) If user clicks "Create New User" he is redirected to this page. */

#define ZXID_NEW_USER_PAGE 0

/*(c) If user clicks on recover password, redirect to this page. */

#define ZXID_RECOVER_PASSWD 0

/*(c) If attribute selection is desired during SSO, redirect to this page. */

#define ZXID_ATSEL_PAGE 0

/*(c) Authentication Page URL
 * If the template customization options are not sufficient, you can
 * provide URL to page of your own design. If set, takes priority over AN_TEMPL_FILE.
 * 0 (zero) disables. */

#define ZXID_AN_PAGE 0

/*(c) Path for Template for IdP Authentication Page */

#define ZXID_AN_TEMPL_FILE "an-main.html"

/*(c) Template for IdP Authentication Page that is used if the
 * path does not work. This is really meant to be the last resort. */

#define ZXID_AN_TEMPL "<title>ZXID IdP: Authentication</title>"\
  "<link type=\"text/css\" rel=stylesheet href=\"an.css\"><body bgcolor=white>"\
  "<form method=get action=\"!!URL\">"\
  "<h1 class=zxtop>ZXID IdP Authentication for Federated SSO</h1>"\
  "<p>Entity ID of this IdP (click for the IdP metadata): <a href=\"!!EID\">!!EID</a><br>"\
  "<p>Login requested by <img src=\"!!SP_BUTTON_URL\"> !!SP_DPY_NAME (<a href=\"!!SP_EID\">!!SP_EID</a>)"\
  "<div class=zxerr>!!ERR</div><div class=zxmsg>!!MSG</div><div class=zxdbg>!!DBG</div>"\
  "User NOT logged in, no session."\
  "<h3>Please authenticate using one of the following methods:</h3>"\
  "<!--input type=checkbox name=at> Adjust attribute sharing after authentication-->"\
  "<ol><li> Yubikey <a href=\"http://yubico.com\"><img src=\"yubiright_16x16.gif\" width=16 height=16 border=0></a>:<input name=au><input type=submit name=alp value=\" Login \">"\
  "<li> User: <input name=au> Password: <input type=password name=ap><input type=submit name=alp value=\" Login \">"\
  "<li><input type=submit name=an value=\" Create New User \"></ol>"\
  "<input type=hidden name=fc value=1><input type=hidden name=fn value=prstnt><br>"\
  "<input type=hidden name=fq value=\"\"><input type=hidden name=fy value=\"\"><input type=hidden name=fa value=\"\"><input type=hidden name=fm value=\"\"><input type=hidden name=fp value=0><input type=hidden name=ff value=0><!-- ZXID built-in defaults, see AN_TEMPL zxidconf.h-->"\
  "<input type=hidden name=ar value=\"!!SSOREQ\">"\
  "<input type=hidden name=zxapp value=\"!!ZXAPP\">"\
  "</form><div class=zxbot><a href=\"http://zxid.org/\">zxid.org</a>, !!VERSION (builtin)</div>"

/*(c) Path for Template for POST profile page */

#define ZXID_POST_TEMPL_FILE "post.html"

/*(c) Template for POST profile age that is used if the
 * path does not work. This is really meant to be the last resort. */

#define ZXID_POST_TEMPL "<title>ZXID Post Profile</title>"\
  "<link type=\"text/css\" rel=stylesheet href=\"an.css\">"\
  "<body bgcolor=white OnLoad=\"document.forms[0].submit()\">"\
  "<form method=post action=\"!!ACTION_URL\">"\
  "<h1 class=zxtop>ZXID POST Profile POST</h1>"\
  "<div class=zxerr>!!ERR</div><div class=zxmsg>!!MSG</div><div class=zxdbg>!!DBG</div>"\
  "<input type=hidden name=!!SAML_ART value=\"!!SAML_RESP\">!!RS!!SIG"\
  "<input type=submit name=ok value=\" If JavaScript is not on, please click here to complete the transaction \">"\
  "</form><div class=zxbot><a href=\"http://zxid.org/\">zxid.org</a>, !!VERSION (builtin)</div>"

/*(c) Error Page URL
 * If the template customization options are not sufficient, you can
 * provide URL to page of your own design. If set, takes priority over ERR_TEMPL_FILE.
 * 0 (zero) disables. */

#define ZXID_ERR_PAGE 0

/*(c) Path for Template for Error Page */

#define ZXID_ERR_TEMPL_FILE "err.html"

/*(c) Template for Error Page that is used if the
 * path does not work. This is really meant to be the last resort. */

#define ZXID_ERR_TEMPL "<title>ZXID: Error</title>"\
  "<link type=\"text/css\" rel=stylesheet href=\"an.css\"><body bgcolor=white>"\
  "<form method=get action=\"!!URL\">"\
  "<h1 class=zxtop>ZXID Error Message</h1>"\
  "<div class=zxerr>!!ERR</div><div class=zxmsg>!!MSG</div><div class=zxdbg>!!DBG</div>"\
  "<input type=hidden name=zxapp value=\"!!ZXAPP\">"\
  "</form><div class=zxbot><a href=\"http://zxid.org/\">zxid.org</a>, !!VERSION (builtin)</div>"

#define ZXID_MGMT_START "<title>ZXID SP Mgmt</title><link type=\"text/css\" rel=stylesheet href=\"idpsel.css\"><body bgcolor=white><h1 class=zxtop>ZXID SP Management (user logged in, session active)</h1>\n"

#define ZXID_MGMT_LOGOUT "<input type=submit name=gl value=\" Local Logout \">\n<input type=submit name=gr value=\" Single Logout (R) \">\n<input type=submit name=gs value=\" Single Logout (S) \">\n"

#define ZXID_MGMT_DEFED "<input type=submit name=gt value=\" Defederate (R) \">\n<input type=submit name=gu value=\" Defederate (S) \">\n"

#define ZXID_MGMT_FOOTER  "<div class=zxbot><a class=zx href=\"http://zxid.org/\">zxid.org</a>, "
#define ZXID_MGMT_END     "</div>"

#endif
