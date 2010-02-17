/* zxidconf.h  -  Configuration of ZXID SP CGI
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
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
 * command line using -O flags (such as via shell script wrapper). When zxid
 * is used as a library, it depends on application to call zxid_parse_conf().
 * Generally we recommend you leave these turned on (1). */

#define ZXID_CONF_FILE 1     /* (compile) */
#define ZXID_CONF_FLAG 1     /* (compile) */
#define ZXID_MAX_CONF  4096  /* (compile) Maximum size of conf file. */
#define ZXID_SHOW_CONF 1     /* Whether configuration is viewable from url o=d */

/*(c) ZXID configuration and working directory path
 * Where metadata cache and session files are created. Note that the directory
 * is not hashed: you should use a file system that scales easily to oodles
 * of small files in one directory. Say `make dir' to create the directory
 * with proper layout. If you change it here, also edit Makefile. */
#define ZXID_PATH "/var/zxid/"

/*(c) SP Nickname for IdP User Interface
 * The nice name may be used by IdP user interface to refer to the SP. It is usually
 * be short human readable name or description. */
#define ZXID_NICE_NAME "ZXID Demo SP"

/*(c) Web Site URL - root of EntityID
 * URL for most zxid operations. It must end in whatever triggers
 * the ZXID functionality in the web server. The hostname
 * and port number should match the server under which zxid CGI is accessible.
 * N.B. There is no explicit way to configure Entity ID (Provider ID) for
 * the zxid SP. The Entity ID is always of form ZXID_URL?o=B, for example
 *   https://sp1.zxidsp.org:8443/zxid?o=B */
#define ZXID_URL "https://sp1.zxidsp.org:8443/zxid"
/*#define ZXID_URL "https://a-sp.liberty-iop.org:8443/zxid"*/

/*(c) Override standard EntityID Construction
 * The best practise is that SP Entity ID is chosen by the SP (and not
 * forced upon SP by IdP). In ZXID this is done by setting ZXID_URL,
 * see above. However, should you have to work with an obstinate IdP
 * that refuses to follow this best practise, you can use this option
 * to manually set the Entity ID. Not following the best practise
 * breaks automatic metadata exchange (Auto-CoT). Recommended
 * value: leave as 0 so that Entity ID is formed from ZXID_URL */
#define ZXID_NON_STANDARD_ENTITYID 0

/*(c) Illadviced ACS URL Hack
 * Sometimes an illadvised authority may impose to you Assertion
 * Consumer Service URL, this URL happens to be different than
 * ZXID uses, and you do not have political leverage to change
 * these decisions. In those times you can use this hack to
 * try to map the imposed URL to the one that works in ZXID.
 * Normally you should register at IdP to use the ZXID default
 * URLs (easiest way to do this is to use metadata). This
 * only works in mod_auth_saml. */
#define ZXID_REDIRECT_HACK_IMPOSED_URL 0
#define ZXID_REDIRECT_HACK_ZXID_URL 0

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
 * Following four boolean configuration options control how (IdP) metadata
 * is obtained. The metadata can be in a cache (by default directory /var/zxid/cot)
 * or it can be fetched "on the fly" using the well known location (WKL) method.
 *
 * ZXID_MD_FETCH:: controls whether fetching is performed. This necessitates
 *     that ZXID was linked with libcurl. If you do not enable fetching, you
 *     will need to populate the cache manually, perhaps by using a web browser
 *     to fetch the meta data xml files from well known location URLs (or other
 *     URLs if you know better).
 *
 * ZXID_MD_POPULATE_CACHE:: controls whether ZXID will write the metadata to
 *     the on-disk cache. This requires ZXID_MD_FETCH to be enabled
 *     and the file system permissions of the cache directory (e.g. /var/zxid/cot)
 *     to allow writing.
 *
 * ZXID_MD_CACHE_FIRST:: controls whether cache will be checked before fetching
 *     is attempted. If cache misses, ZXID_MD_FETCH governs whether fetch is tried.
 *
 * ZXID_MD_CACHE_LAST:: If true, metadata is obtained from cache
 *     if fetch was disabled or failed.
 *
 * If you want to control manually your CoT (e.g. because human process is
 * needed to verify that all the paperwork is in place), set ZXID_MD_FETCH to 0.
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
 * If ZXID does not find one of the certificate plus private key
 * pairs it needs to operate, it will generate automatically
 * a self-signed certificate and private key and populate it to
 * the assigned place. The certificate will be valid for 30 years.
 * If you do not want this to happen, you should disable this option
 * and install the certificate - private key pairs manually to
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
 * Whether AuthnReq is signed SP (controls both metadata and actual behavior). */
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
 * the assertion are , but the assertions of the embedded bootstraps only
 * get discovery bootstrap. 2 would cause the assertions of the first order
 * boostraps to have further bootstraps embedded, etc. Since bootstrap
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

/*(c) Command that will be executed by zxidwspcgi to respond to a web service call. */
#define ZXID_WSPCGICMD "./zxid-wspcgicmd.sh"

/*(c) Bit length of identifiers, unguessability
 * How many random bits to use in an ID. It would be useful if this was
 * such that it produces nice unpadded base64 string, i.e. multiple of 24 bits.
 * Longer IDs reduce chances of random collision (most code does not
 * check uniqueness of ID) and may increase security. For security purposes
 * 144 bits is probably good enugh. The unguessability of ID has security
 * implications, among others, in session IDs. You may want to use less than
 * 144 bits if your application could benefit from shorter IDs (e.g. you target
 * browsers with length constrained URLs) and does not need to be
 * secure against attacks with government level resources.
 * E.g:  24 bits ==  3 bytes ==  4 base64 chars,
 *       48 bits ==  6 bytes ==  8 base64 chars,
 *      120 bits == 15 bytes == 20 base64 chars,
 *      144 bits == 18 bytes == 24 base64 chars */
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
 * you have hardware random number generator. */
#define ZXID_TRUE_RAND 0  /* (compile) */

/*(c) Session Archival Directory
 * If set to a string, indicates a file system directory to which
 * dead sessions are moved (sessions are files). This directory
 * must be on the same file system as active session directory,
 * usually /var/zxid/ses, for example /var/zxid/oldses.
 * You may want to archieve old sessions because they contain
 * the SSO assertions that allowed the users to log in. This
 * may have legal value for your application, you may even be required
 * by law to keep this audit trail.
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

#define ZXID_SES_COOKIE_NAME "ZXIDSES"

/*(c) Local user account management.
 * This is optional unless you require IdP
 * initiated ManageNameID requests to work. Local user account management
 * may be useful on its own right if your application does not yet have
 * such system. If it has, you probably want to continue to use
 * the application's own system. Local accounts are stored under
 * /var/zxid/user/SHA1 */

#define ZXID_USER_LOCAL 1

/*(c) Mini IdP
 * Whether limited IdP functionality is enabled. Affects generated metadata. */
#define ZXID_IDP_ENA 0

/*(c) Mini IdP
 * Whether limited Authentication Service functionality is enabled.
 * Please note that the AuthenticationService impmenetation at present (2010)
 * is incomplete and fails to properly authenticate and authorize the caller,
 * i.e. anyone who knows a username and password can call it. */
#define ZXID_AS_ENA 0

/*(c) Dummy PDP
 * Whether limited PDP functionality is enabled. */
#define ZXID_PDP_ENA 1

/*(c) IdP Insitence on Signed AuthnReq
 * Must AuthnReq be signed (controls both IdP metadata and actual behavior, i.e. the check). */
#define ZXID_WANT_AUTHN_REQ_SIGNED 1

/*() Maximum filesystem path used in /var/zxid tree. */
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

/*(c) Assertion validation options.
 * These MUST all be turned on (and assertions signed)
 * if you want to rely on assertions to hold the other party liable. */

#define ZXID_SIG_FATAL      1 /* Signature validation error is fatal (prevents SSO) */
#define ZXID_NOSIG_FATAL    1 /* Missing signature is fatal (prevents SSO) */
#define ZXID_MSG_SIG_OK     1 /* Message layer signature (e.g. SimpleSign) is sufficeint when assertion signature is missing. */
#define ZXID_AUDIENCE_FATAL 1 /* Whether AudienceRestriction is checked. */
#define ZXID_TIMEOUT_FATAL  1 /* Whether NotBefore and NotOnOrAfter are checked */
#define ZXID_DUP_A7N_FATAL  1 /* Whether duplication of AssertionID is considered fatal. */
#define ZXID_DUP_MSG_FATAL  1 /* Whether duplication of MessageID or message is considered fatal. */

/*(c) Web service request and response validation options. For the token
 * in the request, the assertion validation options apply. */
#define ZXID_WSP_NOSIG_FATAL 1 /* Missing Security/Signature is fatal. */
#define ZXID_NOTIMESTAMP_FATAL 1 /* Missing Security/Timestamp is fatal. */

/*(c) Time Slop
 * Because clock sychronization amoung the servers in the CoT is unlikely
 * to be perfect, not to speak of timezone misconfigurations and the
 * dreaded officially introduced time errors (e.g. daylight "savings" time),
 * you can configure some slop in how the timeout is evaluated. For production
 * use something like 60 seconds could be a good value. 3600 = 1 hour, 86400 = 1 day. */
#define ZXID_BEFORE_SLOP    86400  /* Number of seconds before that is acceptable. */
#define ZXID_AFTER_SLOP     86400  /* Number of seconds after that is acceptable. */

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
 * set, the latter value will be used by zxid_az(). If you
 * always want to explicitly call zxid_az() and do not want
 * zxid_simple() to make implicit calls to PDP, just set
 * PDP_CALL_URL and leave PDP_URL as 0. */
#define ZXID_PDP_URL 0
#define ZXID_PDP_CALL_URL 0

/*(c) Which version of XACML to speak */

#define ZXID_XASP_VERS "2.0"

/*(c) XACML Attributes ns$A$rule$b$ext */

#define ZXID_PEPMAP "env$*$$$;subj$idpnid$rename$urn:oasis:names:tc:xacml:1.0:subject:subject-id$;subj$role$$$;rsrc$rs$rename$urn:oasis:names:tc:xacml:1.0:resource:resource-id$;act$Action$rename$urn:oasis:names:tc:xacml:1.0:action:action-id$;env$ZXID_PEPvers$$$;$cookie$del$$;$setcookie$del$$"

//#define ZXID_XACML2_SUBJ  "idpnid=$idpnid&role=$role"
//#define ZXID_XACML2_RSRC  "URL=$URL"
//#define ZXID_XACML2_ACT   "Action=$Action"
//#define ZXID_XACML2_ENV   "ZXID_PEPVers"

/*(c) Whitelists and blacklists for the primitive local PDP. Comma separated lists. */

#define ZXID_LOCALPDP_ROLE_PERMIT 0   /* Whitelist of roles (empty: anything goes) */
#define ZXID_LOCALPDP_ROLE_DENY   "local_deny"      /* Blacklist of roles */
#define ZXID_LOCALPDP_IDPNID_PERMIT 0 /* Whitelist of permitted users (empty: anything goes) */
#define ZXID_LOCALPDP_IDPNID_DENY "denynid" /* Blacklist of denied users */

/* ----------------------------------------------------------------------------- */
/*(c) Simple API HTML customization.
 * These allow simple branding and customization.
 * If these options are not enough for you, consider simply rendering your own forms. */

/*(c) Whether to show more technical fields in the GUI. Normally they
 * are hidden and POST profile is used */
#define ZXID_SHOW_TECH 0

/*(c) Body tag for the ZXID generated pages.
 * Edit this to change the colors. */
#define ZXID_BODY_TAG "<body bgcolor=\"#330033\" text=\"#ffaaff\" link=\"#ffddff\" vlink=\"#aa44aa\" alink=\"#ffffff\"><font face=sans>"  /* (compile) */

#define ZXID_IDP_SEL_START "<title>ZXID SP SSO: Choose IdP</title>" ZXID_BODY_TAG "<h1>ZXID SP Federated SSO (user NOT logged in, no session)</h1>\n"

#define ZXID_IDP_SEL_NEW_IDP "<h3>Login Using New IdP</h3>\n<i>A new IdP is one whose metadata we do not have yet. We need to know the IdP URL (aka Entity ID) in order to fetch the metadata using the well known location method. You will need to ask the adminstrator of the IdP to tell you what the EntityID is.</i>\n<p>IdP URL <input name=e size=80><input type=submit name=l0 value=\" Login \"><br>\n"

/*#define ZXID_IDP_SEL_NEW_IDP "<h3>Login Using New IdP</h3>\n<i>A new IdP is one whose metadata we do not have yet. We need to know the IdP URL (aka Entity ID) in order to fetch the metadata using the well known location method. You will need to ask the adminstrator of the IdP to tell you what the EntityID is.</i>\n<p>IdP URL <input name=e size=80><input type=submit name=l1 value=\" Login (A2) \">\n<input type=submit name=l2 value=\" Login (P2) \"><br>\n"*/

#define ZXID_IDP_SEL_OUR_EID "Entity ID of this SP (click on the link to fetch the SP metadata): "

#define ZXID_IDP_SEL_TECH_USER "<h3>Technical options</h3><input type=checkbox name=fc value=1 checked> Create federation, NID Format: <select name=fn><option value=prstnt>Persistent<option value=trnsnt>Transient<option value=\"\">(none)</select><br>\n"

#define ZXID_IDP_SEL_TECH_SITE "<input type=hidden name=fq value=\"\"><input type=hidden name=fy value=\"\"><input type=hidden name=fa value=\"\"><input type=hidden name=fm value=\"\"><input type=hidden name=fp value=0><input type=hidden name=ff value=0><!-- ZXID built-in defaults, see IDP_SEL_TECH_SITE in zxidconf.h -->"

#define ZXID_IDP_SEL_FOOTER  "<hr><a href=\"http://zxid.org/\">zxid.org</a>, "
#define ZXID_IDP_SEL_END     "<!-- EOF -->"

/*(c) IdP Selector Page URL
 * If the above simple customization options are not sufficient, you can
 * provide URL to page of your own design. This page will receive as
 * query string argument the relay state.
 * 0 (zero) disables. */

#define ZXID_IDP_SEL_PAGE 0

#define ZXID_AN_START "<title>ZXID IdP: Authentication</title>" ZXID_BODY_TAG "<h1>ZXID IdP Authentication for Federated SSO (user NOT logged in, no session)</h1>\n<h3>Please authenticate yourself using one of the following methods:</h3>"

#define ZXID_AN_OUR_EID "Entity ID of this IdP (click on the link to fetch the IdP metadata): "

#define ZXID_AN_TECH_USER "<h3>Technical options</h3><input type=checkbox name=fc value=1 checked> Create federation, NID Format: <select name=fn><option value=prstnt>Persistent<option value=trnsnt>Transient<option value=\"\">(none)</select><br>\n"

#define ZXID_AN_TECH_SITE "<input type=hidden name=fq value=\"\"><input type=hidden name=fy value=\"\"><input type=hidden name=fa value=\"\"><input type=hidden name=fm value=\"\"><input type=hidden name=fp value=0><input type=hidden name=ff value=0><!-- ZXID built-in defaults, see IDP_SEL_TECH_SITE in zxidconf.h -->"

#define ZXID_AN_FOOTER  "<hr><a href=\"http://zxid.org/\">zxid.org</a>, "
#define ZXID_AN_END     "<!-- EOF -->"

/*(c) Authentication Page URL
 * If the above simple customization options are not sufficient, you can
 * provide URL to page of your own design.
 * 0 (zero) disables. */

#define ZXID_AN_PAGE 0

#define ZXID_MGMT_START "<title>ZXID SP Mgmt</title>" ZXID_BODY_TAG "<h1>ZXID SP Management (user logged in, session active)</h1>\n"

#define ZXID_MGMT_LOGOUT "<input type=submit name=gl value=\" Local Logout \">\n<input type=submit name=gr value=\" Single Logout (R) \">\n<input type=submit name=gs value=\" Single Logout (S) \">\n"

#define ZXID_MGMT_DEFED "<input type=submit name=gt value=\" Defederate (R) \">\n<input type=submit name=gu value=\" Defederate (S) \">\n"

#define ZXID_MGMT_FOOTER  "<hr><a href=\"http://zxid.org/\">zxid.org</a>, "
#define ZXID_MGMT_END     "<!-- EOF -->"

#endif
