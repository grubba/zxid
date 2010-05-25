# zxid/Makefile  -  How to build ZXID
# Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
# Author: Sampo Kellomaki (sampo@iki.fi)
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id: Makefile,v 1.154 2010-01-08 02:10:09 sampo Exp $
# 15.10.2006, refactor sources to be per namespace --Sampo
# 19.1.2006, added new zxid_simple() / Hello World targets and JNI --Sampo
# 26.2.2007, tweaks for the great SOAP merger, WSC support --Sampo
# 3.3.2007,  added many service schemata --Sampo
# 22.2.2008, added mod_auth_saml --Sampo
# 14.4.2008, added SAML POST-SimpleSign binding and Orange APIs --Sampo
# 25.8.2009, added improvements from TAS3 workshop in Lisbon --Sampo
# 29.8.2009, merged in smime support --Sampo
# 15.9.2009, added TAS3 packaging --Sampo
# 14.11.2009, added yubikey support --Sampo
# 12.2.2010, added pthread support --Sampo
# 25.2.2010, added gcov support --Sampo
#
# Build so far only tested on Linux, Solaris 8 and MacOS 10.3. This
# makefile needs gmake-3.78 or newer.
# (See dietlibc (fefe.de) Makefile for some useful wizardry.)
# Try `make help'
#
# N.B. Before you edit this file, consider overriding select options in
#      localconf.mk (see below for details).
#
# gcc's '-ffunction-sections' + '-fdata-sections' options. (dead code elimn.)

vpath %.c ../zxid
vpath %.h ../zxid

default: seehelp precheck zxid zxidhlo zxididp zxidhlowsf zxidsimple zxidwsctool zxlogview zxidhrxmlwsc zxidhrxmlwsp zxdecode zxcot zxpasswd zxcall

all: default precheck_apache samlmod phpzxid javazxid apachezxid smime zxidwspcgi

### This is the authorative spot to set version number. Document in Changes file.
### c/zxidvers.h is generated from these, see `make updatevers'
ZXIDVERSION=0x000057
ZXIDREL=0.57

### Where package is installed (use `make PREFIX=/your/path' to change)
PREFIX=/usr/local/zxid/$(ZXIDREL)

### Where runtime configuration and temporary data is kept.
### If you change the following, be sure to edit zxidconf.h as
### well. N.B. Trailing / (forward slash) is needed.
ZXID_PATH=/var/zxid/

###
### Module selection options (you should enable all, unless building embedded)
###

ENA_SSO=1
ENA_SAML2=1
ENA_FF12=1
ENA_SAML11=1
ENA_WSF=1
ENA_WSF2=1
ENA_WSF11=1
ENA_XACML2=1
ENA_WST=1
ENA_SMIME=1
ENA_TAS3=1

###
### Environment dependent options and dependency packages
###

TOP=$(shell pwd)
CURL_ROOT=/usr/local
OPENSSL_ROOT=/usr/local/ssl
PHP_CONFIG=php-config
CSHARP_CONFIG=true
PY_CONFIG=true
RUBY_CONFIG=true
APACHE_ROOT=/usr/local/httpd

ECHO=echo
SED=sed
PERL=perl
XSD2SG_PL= ../pd/xsd2sg.pl
XSD2SG=$(PERL) $(XSD2SG_PL)
PULVERIZE=$(PERL) ./pulverize.pl
GPERF=gperf
SWIG=swig
AR=ar -crs
ARX=ar -x
CC=gcc
LD=gcc
SHARED_FLAGS=-shared --export-all-symbols -Wl,-whole-archive -Wl,--allow-multiple-definition
SHARED_CLOSE=-Wl,-no-whole-archive
CFLAGS=-g -fpic -fmessage-length=0 -Wno-unused-label -Wno-unknown-pragmas -fno-strict-aliasing
#CFLAGS += -Os    # gcc-3.4.6 miscompiles with -Os on ix86
CFLAGS += -Wall -Wno-parentheses -DMAYBE_UNUSED='__attribute__ ((unused))'
#LDFLAGS += -Wl,--gc-sections
LIBZXID=-L. -lzxid

ifeq ($(ENA_PG),1)

###
### To compile for profiling your should run make ENA_PG=1
### See also: make gcov, make lcov (and lcovhtml directory), man gcov, man gprof
### N.B. ccache seems to be incompatible with profiling.
###

#CDEF += -DMUTEX_DEBUG
CFLAGS += -pg -ftest-coverage -fprofile-arcs
LDFLAGS += -pg -ftest-coverage -fprofile-arcs

else

# -ffunction-sections is incompatible with profiling

CFLAGS += -ffunction-sections -fdata-sections

endif

###
### Java options (watch out javac running out of heap)
###

JAR=jar
JAVAC=javac
JAVAC_FLAGS=-J-Xmx128m -g
# JNI library name is very platform dependent (see macosx and mingw)
ZXIDJNI_SO=zxidjava/libzxidjni.so
# find / -name jni.h; find / -name jni_md.h
JNI_INC=-I/usr/java/include -I/usr/java/include/linux
# Path where HttpServlet supplied by your application server resides: find / -name servlet-api.jar
SERVLET_PATH=../apache-tomcat-5.5.20/common/lib/servlet-api.jar
#SERVLET_PATH=../apache-tomcat-6.0.18/lib/servlet-api.jar

# Without cURL the Artifact Profile, WSC, and metadata fetch features are disabled.
CDEF+= -DUSE_CURL
# Without OpenSSL signing and signature verification are not possible
CDEF+= -DUSE_OPENSSL
# Using PTHREAD helps to avoid problems in multithreaded programs, such as Java servlets
CDEF+= -DUSE_PTHREAD

### To change any of the above options, you can either supply
### alternate values on make command line, like `make PREFIX=/your/path'
### or you can create localconf.mk file to hold your options. This
### file is included here, but if it's missing, no problem.

-include localconf.mk

# Try find / -name ap_config.h; find / -name apr.h
APACHE_INCLUDE ?= -I$(APACHE_ROOT)/include
APR_INCLUDE    ?= -I$(APACHE_ROOT)/srclib/apr-util/include
APACHE_MODULES ?= $(APACHE_ROOT)/modules

### Compute options based on local modifications

CDIR+= -I. -I$(TOP) -I$(OPENSSL_ROOT)/include -I$(CURL_ROOT)/include
CDIR+= $(APACHE_INCLUDE) $(APR_INCLUDE)
CDEF+= -D_REENTRANT -DDEBUG
LIBS+= -lpthread -L$(CURL_ROOT)/lib -L$(OPENSSL_ROOT)/lib -lcurl -lssl -lcrypto -lz
#LIBS+=-ldl

# Following ld flags as well as C flag -ffunction-sections are a quest to
# eliminate unused functions from final link.
#LDFLAGS= -Wl,-O -Wl,2 --gc-sections

####################################################################
### Platform dependent options (choose one with `make TARGET=foo')
###

ifeq ($(TARGET),xsol8)

# Cross compilation for Solaris 8 target (on Linux host) Invoke as `make TARGET=xsol8'
# You must have the cross compiler installed in /apps/gcc/sol8 and in path. Similarily
# the cross binutils must be in path.
#    export PATH=/apps/gcc/sol8/bin:/apps/binutils/sol8/bin:$PATH

SYSROOT=/apps/gcc/sol8/sysroot
CROSS_COMPILE=1
CC=sparc-sun-solaris2.8-gcc
LD=sparc-sun-solaris2.8-gcc
CDEF+=-DSUNOS -DBYTE_ORDER=4321 -DBIG_ENDIAN=4321
LIBS+=-lxnet -lsocket

else
ifeq ($(TARGET),sol8)

# Flags for Solaris 8 native compile (with gc and gnu binutils) (BIG_ENDIAN BYTE_ORDER)
CDEF+=-DSUNOS -DBYTE_ORDER=4321 -DBIG_ENDIAN=4321
LIBS+=-lxnet -lsocket

else
ifeq ($(TARGET),macosx)

# Flags for MacOS 10 / Darwin native compile (gcc + Apple linker)
#   alias ldd='otool -L'
#   alias strace=ktrace or dtrace or dtruss
CFLAGS=-g -fPIC -fmessage-length=0 -Wno-unused-label -Wno-unknown-pragmas -fno-strict-aliasing
CDEF+=-DMACOSX
JNI_INC=-I/System/Library/Frameworks/JavaVM.framework/Versions/CurrentJDK/Headers
SHARED_FLAGS=-dylib -all_load -bundle
SHARED_CLOSE=
ZXIDJNI_SO=zxidjava/libzxidjni.jnilib
#SHARED_FLAGS=-dylib -all_load -keep_private_externs 
#OPENSSL_ROOT=/Developer/SDKs/MacOSX10.4u.sdk/usr
#CURL_ROOT=/Developer/SDKs/MacOSX10.4u.sdk/usr

else
ifeq ($(TARGET),xmingw)

# Cross compilation for MINGW target (on Linux host). Invoke
# as `make zxid.dll TARGET=xmingw'
# You must have the cross compiler installed in /apps/gcc/mingw and in
# path. Similarily the cross binutils must be in path.
#    export PATH=/apps/gcc/mingw/bin:/apps/binutils/mingw/bin:$PATH
#
# For best results use the same cross compiler for compiling the dependency
# libraries like curl, openssl, and zlib. Furthermore: your cross compiler
# should be for MinGW target, not for Cygwin (i.e. default compiler of Cygwin
# may have trouble due to linking against cygwin dependent libraries).
#
# Cross compiling curl
#   CPPFLAGS='-I/apps/gcc/mingw/sysroot/include' LDFLAGS='-L/apps/gcc/mingw/sysroot/lib' LIBS='-lz' ./configure --prefix=/usr --with-ssl=/apps/gcc/mingw/sysroot --without-gnutls --enable-thread --enable-nonblocking --host=i586-pc-mingw32 --with-random=/random.txt --disable-shared -enable-static
#   # Despite apparent misdetection of ar, the compile finishes
#   make
#   cp lib/.libs/libcurl* /apps/gcc/mingw/sysroot/lib
#   cp -r include/curl/ /apps/gcc/mingw/sysroot/include
#
# Symbol hunting
#   undefined reference to `WinMain@16'               --> add -Wl,-no-whole-archive after all libs
#   undefined reference to `_imp__curl_easy_setopt'   --> compile with -DCURL_STATICLIB
#   undefined reference to `_imp__curl_easy_strerror' --> compile with -DCURL_STATICLIB
#   undefined reference to `timeGetTime@0'            --> add -lwinmm

SYSROOT=/apps/gcc/mingw/sysroot
CROSS_COMPILE=1
CC=/apps/gcc/mingw/bin/i586-pc-mingw32-gcc
LD=/apps/gcc/mingw/bin/i586-pc-mingw32-gcc
AR=/apps/binutils/mingw/bin/i586-pc-mingw32-ar -crs
ARX=/apps/binutils/mingw/bin/i586-pc-mingw32-ar -x
CDEF+=-DMINGW -DUSE_LOCK=flock -DCURL_STATICLIB
CURL_ROOT=/apps/gcc/mingw/sysroot
OPENSSL_ROOT=/apps/gcc/mingw/sysroot
ZXIDJNI_SO=zxidjava/zxidjni.dll
ifeq ($(SHARED),1)
LIBZXID=-L. -lzxiddll
endif

-include xmingw.mk

# -lws2_32  -lmingw32  -u _imp__curl_easy_setopt -u _imp__curl_easy_strerror
WIN_LIBS= -L$(CURL_ROOT)/lib -L$(OPENSSL_ROOT)/lib -lcurl -lssl -lcrypto -lz -lwinmm -lwsock32 -lgdi32 -lkernel32
LIBS= -mconsole $(WIN_LIBS)
#SHARED_FLAGS=-shared --export-all-symbols -Wl,-whole-archive -Wl,-no-undefined -Wl,--enable-runtime-reloc -Wl,-whole-archive
SHARED_FLAGS=-Wl,--add-stdcall-alias -shared --export-all-symbols -Wl,-whole-archive -Wl,-no-undefined -Wl,--enable-runtime-pseudo-reloc -Wl,--allow-multiple-definition
CFLAGS=-g -fmessage-length=0 -Wno-unused-label -Wno-unknown-pragmas -fno-strict-aliasing  -mno-cygwin

# java.lang.UnsatisfiedLinkError: Given procedure could not be found
# -mno-cygwin -mrtd -Wl,--kill-at -Wl,--add-stdcall-alias
# http://www.inonit.com/cygwin/jni/helloWorld/c.html
# http://www.1702.org/jniswigdll.html
# http://maba.wordpress.com/2004/07/28/generating-dll-files-for-jni-under-windowscygwingcc/

else
ifeq ($(TARGET),mingw)

CDEF+=-DMINGW -DUSE_LOCK=flock -DCURL_STATICLIB
CURL_ROOT=/usr/local
OPENSSL_ROOT=/usr/local/ssl
WIN_LIBS= -L$(CURL_ROOT)/lib -L$(OPENSSL_ROOT)/lib -lcurl -lssl -lcrypto -lz -lwinmm -lwsock32 -lgdi32 -lkernel32
LIBS= -mconsole $(WIN_LIBS)
SHARED_FLAGS=-Wl,--add-stdcall-alias -shared --export-all-symbols -Wl,-whole-archive -Wl,-no-undefined -Wl,--enable-runtime-pseudo-reloc -Wl,--allow-multiple-definition
CFLAGS=-g -fmessage-length=0 -Wno-unused-label -Wno-unknown-pragmas -fno-strict-aliasing -mno-cygwin
ZXIDJNI_SO=zxidjava/zxidjni.dll
ifeq ($(SHARED),1)
LIBZXID=-L. -lzxiddll
endif

else
ifeq ($(TARGET),cygwin)

CDEF+=-DCYGWIN -DUSE_LOCK=dummy_no_flock -DCURL_STATICLIB -DLOCK_UN=0
CURL_ROOT=/usr/local
OPENSSL_ROOT=/usr/local/ssl
MOD_AUTH_SAML_LIBS=-lapr-1 -lhttpd2core

else

# Flags for Linux 2.6 native compile (gcc + gnu binutils)
CDEF+=-DLINUX

endif
endif
endif
endif
endif
endif

CFLAGS+= $(CDEF) $(CDIR)

####################################################################
### End of platform dependent options, start of dependencies and
### targets (mortals can look, but should not edit).
###

ZXID_LIB_OBJ=zxidsimp.o zxidpool.o zxidpsso.o zxidsso.o zxidslo.o zxiddec.o zxidspx.o zxididpx.o zxidmni.o zxidpep.o zxidmk.o zxida7n.o zxidses.o zxiduser.o zxidcgi.o zxidconf.o zxidecp.o zxidcdc.o zxidloc.o zxidlib.o zxidmeta.o zxidcurl.o zxidepr.o zxida7n.o ykcrc.o ykaes.o
ZX_OBJ=zxlib.o zxns.o zxutil.o zxlog.o zxsig.o zxcrypto.o c/license.o c/zx-attrs.o c/zx-elems.o
WSF_OBJ=zxidmkwsf.o zxidwsc.o zxidwsp.o zxiddi.o
SMIME_LIB_OBJ=certauth.o keygen.o pkcs12.o smime-enc.o smime-qry.o smime-vfy.o smimemime.o smimeutil.o

ifeq ($(PULVER),1)

# WARNING: THE PULVER OPTIONS ARE NOT CURRENTLY MAINTAINED AND ARE OUT OF DATE!
# Pulverize dependencies. These arrange some source files to be split
# to one-function-per-file format ("pulver") so that GNU ld will only
# pull in those files, i.e. functions, that are actually used. This is
# a workaround for GNU ld not having a dead function elimination
# feature.  You should do `make PULVER=1' for production or
# distribution build of this library as that will ensure smallest
# possible binaries for eventual users of the library.

PULVER_DEPS=pulver/c_saml2_dec_c.deps pulver/c_saml2_enc_c.deps \
	pulver/c_saml2_aux_c.deps pulver/c_saml2_getput_c.deps \
	pulver/c_saml2md_dec_c.deps pulver/c_saml2md_enc_c.deps \
	pulver/c_saml2md_aux_c.deps pulver/c_saml2md_getput_c.deps

c_saml2_dec_c_o=$(shell cat pulver/c_saml2_dec_c.deps)
c_saml2_enc_c_o=$(shell cat pulver/c_saml2_enc_c.deps)
c_saml2_aux_c_o=$(shell cat pulver/c_saml2_aux_c.deps)
c_saml2_getput_c_o=$(shell pulver/c_saml2_getput_c.deps)

#pulver/c_saml2_dec_c.deps $(c_saml2_dec_c_o:.o=.c): c/saml2-dec.c	

pulver/c_saml2_dec_c.deps: c/saml2-dec.c	
	$(PULVERIZE) pulver c/saml2-dec.c >pulver/c_saml2_dec_c.deps

#pulver/c_saml2_enc_c.deps $(c_saml2_enc_c_o:%.o=%.c): c/saml2-enc.c	

pulver/c_saml2_enc_c.deps $(foo:%.o=%.c): c/saml2-enc.c	
	$(PULVERIZE) pulver c/saml2-enc.c >pulver/c_saml2_enc_c.deps

pulver/c_saml2_aux_c.deps $(c_saml2_aux_c_o:.o=.c): c/saml2-aux.c	
	$(PULVERIZE) pulver c/saml2-aux.c >pulver/c_saml2_aux_c.deps
pulver/c_saml2_getput_c.deps $(c_saml2_getput_c_o:.o=.c): c/saml2-getput.c	
	$(PULVERIZE) pulver c/saml2-getput.c >pulver/c_saml2_getput_c.deps

c_saml2md_dec_c_o=$(shell cat pulver/c_saml2md_dec_c.deps)
c_saml2md_enc_c_o=$(shell cat pulver/c_saml2md_enc_c.deps)
c_saml2md_aux_c_o=$(shell cat pulver/c_saml2md_aux_c.deps)
c_saml2md_getput_c_o=$(shell pulver/c_saml2md_getput_c.deps)

pulver/c_saml2md_dec_c.deps $(c_saml2md_dec_c_o:.o=.c): c/saml2md-dec.c	
	$(PULVERIZE) pulver c/saml2md-dec.c >pulver/c_saml2md_dec_c.deps
pulver/c_saml2md_enc_c.deps $(c_saml2md_enc_c_o:.o=.c): c/saml2md-enc.c	
	$(PULVERIZE) pulver c/saml2md-enc.c >pulver/c_saml2md_enc_c.deps
pulver/c_saml2md_aux_c.deps $(c_saml2md_aux_c_o:.o=.c): c/saml2md-aux.c	
	$(PULVERIZE) pulver c/saml2md-aux.c >pulver/c_saml2md_aux_c.deps
pulver/c_saml2md_getput_c.deps $(c_saml2md_getput_c_o:.o=.c): c/saml2md-getput.c	
	$(PULVERIZE) pulver c/saml2md-getput.c >pulver/c_saml2md_getput_c.deps

#-include pulver/c_saml2_dec_c.deps
#-include pulver/c_saml2_enc_c.deps
#-include pulver/c_saml2_aux_c.deps
#-include pulver/c_saml2_getput_c.deps

ZX_OBJ += \
  $(c_saml2_dec_c_o)    $(c_saml2md_dec_c_o) \
  $(c_saml2_enc_c_o)    $(c_saml2md_enc_c_o) \
  $(c_saml2_aux_c_o)    $(c_saml2md_aux_c_o) \
  $(c_saml2_getput_c_o) $(c_saml2md_getput_c_o)

else

### Nonpulver deps

ifeq ($(ENA_SSO),1)

# Nonpulverized build. This will result in bigger binaries because gnu ld does
# not understand to do dead function elimination. However, this is faster to build.

#ZX_OBJ +=

endif

ifeq ($(ENA_WSF),1)

#WSF_OBJ +=

endif

endif

#ZXID_OBJ=zxid.o zxidlib.o zxidmeta.o $(ZX_OBJ)
ZXID_OBJ=zxid.o
ZXIDWSCTOOL_OBJ=zxidwsctool.o
ZXIDSP_OBJ=zxidsp.o
ZXIDHLO_OBJ=zxidhlo.o
ZXIDGSA_OBJ=zxidgsa.o
ZXIDHLOWSF_OBJ=zxidhlowsf.o
ZXIDSIMPLE_OBJ=zxidsimple.o
ZXBENCH_OBJ=zxbench.o
ZXIDSSOFINALIZETEST_OBJ=zxidssofinalizetest.o
ZXENCDECTEST_OBJ=zxencdectest.o
SFIS_OBJ=sfis.o
SFISGSA_OBJ=sfisgsa.o
ZXIDXMLTOOL_OBJ=zxidxmltool.o
ZXLOGVIEW_OBJ=zxlogview.o $(ZX_OBJ)
ZXIDHRXMLWSC_OBJ=zxidhrxmlwsc.o
ZXIDHRXMLWSP_OBJ=zxidhrxmlwsp.o
ZXIDIDP_OBJ=zxididp.o

#
# Schemata and potential xml document roots.
# See also sg/wsf-soap11.sg for a place to "glue" new functions in.
#

ZX_SG+=sg/xmldsig-core.sg sg/xenc-schema.sg sg/ec.sg

# SAML 2.0

ifeq ($(ENA_SAML2),1)

ZX_SG+=sg/saml-schema-assertion-2.0.sg sg/saml-schema-protocol-2.0.sg sg/saml-schema-ecp-2.0.sg sg/liberty-paos-v2.0.sg sg/wsf-soap11.sg
ZX_ROOTS+=-r sa:Assertion -r sa:NameID -r sp:NewID -r sp:AuthnRequest -r sp:Response
ZX_ROOTS+=-r sp:LogoutRequest -r sp:LogoutResponse
ZX_ROOTS+=-r sp:ManageNameIDRequest -r sp:ManageNameIDResponse
ZX_ROOTS+=-r e:Envelope -r e:Header -r e:Body

ZX_SG+=sg/saml-schema-metadata-2.0.sg
ZX_SG+=sg/shibboleth-metadata-1.0.sg
ZX_SG+=sg/sstc-saml-idp-discovery.sg
ZX_ROOTS+=-r md:EntityDescriptor -r md:EntitiesDescriptor

endif

# SAML 1.1

ifeq ($(ENA_SAML11),1)

ZX_SG += sg/oasis-sstc-saml-schema-protocol-1.1.sg sg/oasis-sstc-saml-schema-assertion-1.1.sg
ZX_ROOTS += -r sa11:Assertion -r sp11:Request -r sp11:Response

endif

# Liberty ID-FF 1.2

ifeq ($(ENA_FF12),1)

ZX_SG += sg/liberty-idff-protocols-schema-1.2-errata-v2.0.sg sg/liberty-authentication-context-v2.0.sg
ZX_ROOTS+= -r ff12:Assertion -r ff12:AuthnRequest -r ff12:AuthnResponse
ZX_ROOTS+= -r ff12:AuthnRequestEnvelope -r ff12:AuthnResponseEnvelope
ZX_ROOTS+= -r ff12:RegisterNameIdentifierRequest -r ff12:RegisterNameIdentifierResponse
ZX_ROOTS+= -r ff12:FederationTerminationNotification
ZX_ROOTS+= -r ff12:LogoutRequest -r ff12:LogoutResponse
ZX_ROOTS+= -r ff12:NameIdentifierMappingRequest -r ff12:NameIdentifierMappingResponse
ZX_SG+=    sg/liberty-metadata-v2.0.sg
ZX_ROOTS+= -r m20:EntityDescriptor -r m20:EntitiesDescriptor

endif

# Liberty ID-WSF 2.0

ifeq ($(ENA_WSF2),1)

ZX_SG += sg/ws-addr-1.0.sg
ZX_SG += sg/wss-secext-1.0.sg sg/wss-util-1.0.sg
ZX_SG += sg/liberty-idwsf-soap-binding.sg sg/liberty-idwsf-soap-binding-v2.0.sg
ZX_SG += sg/liberty-idwsf-security-mechanisms-v2.0.sg sg/liberty-idwsf-disco-svc-v2.0.sg
ZX_SG += sg/liberty-idwsf-interaction-svc-v2.0.sg sg/liberty-idwsf-utility-v2.0.sg
ZX_SG += sg/id-dap.sg sg/liberty-idwsf-subs-v1.0.sg sg/liberty-idwsf-dst-v2.1.sg
ZX_SG += sg/liberty-idwsf-idmapping-svc-v2.0.sg sg/liberty-idwsf-people-service-v1.0.sg
ZX_SG += sg/liberty-idwsf-authn-svc-v2.0.sg sg/xml.sg sg/xsi.sg sg/xs.sg sg/id-mm7-R6-1-4.sg
ZX_SG += sg/lib-id-sis-cb-proto.sg sg/lib-id-sis-cb-cdm.sg sg/liberty-id-sis-gl-v1.0-14.sg
ZX_SG += sg/liberty-idwsf-dp-v1.0.sg sg/liberty-idwsf-idp-v1.0.sg
ZX_SG += sg/liberty-idwsf-pmm-v1.0.sg sg/liberty-idwsf-prov-v1.0.sg
ZX_SG += sg/liberty-idwsf-shps-v1.0.sg
ZX_SG += sg/hr-xml-sampo.sg sg/id-hrxml.sg
ZX_SG += sg/demo-media-v1.0.sg
ZX_ROOTS+= -r a:EndpointReference
ZX_ROOTS+= -r hrxml:Candidate

#ZX_SG += sg/saml-schema-assertion-2.0.sg sg/saml-schema-protocol-2.0.sg sg/xmldsig-core.sg sg/xenc-schema.sg sg/saml-schema-metadata-2.0.sg sg/oasis-sstc-saml-schema-protocol-1.1.sg sg/oasis-sstc-saml-schema-assertion-1.1.sg sg/liberty-idff-protocols-schema-1.2-errata-v2.0.sg sg/liberty-authentication-context-v2.0.sg

endif

# Liberty ID-WSF 1.1

ifeq ($(ENA_WSF11),1)

ZX_SG += sg/liberty-idwsf-soap-binding-v1.2.sg  sg/liberty-idwsf-security-mechanisms-v1.2.sg
ZX_SG += sg/liberty-idwsf-disco-svc-v1.2.sg     sg/liberty-idwsf-interaction-svc-v1.1.sg

endif

# OASIS XACML 2.0 (and committee draft 1)

ifeq ($(ENA_XACML2),1)

ZX_SG += sg/access_control-xacml-2.0-context-schema-os.sg
ZX_SG += sg/access_control-xacml-2.0-policy-schema-os.sg
ZX_SG += sg/access_control-xacml-2.0-saml-assertion-schema-os.sg
ZX_SG += sg/access_control-xacml-2.0-saml-protocol-schema-os.sg
ZX_SG += sg/xacml-2.0-profile-saml2.0-v2-schema-protocol-cd-1.sg
ZX_SG += sg/xacml-2.0-profile-saml2.0-v2-schema-assertion-cd-1.sg
ZX_ROOTS += -r xasp:XACMLAuthzDecisionQuery -r xasp:XACMLPolicyQuery
ZX_ROOTS += -r xaspcd1:XACMLAuthzDecisionQuery -r xaspcd1:XACMLPolicyQuery

endif

# WS-Trust

ifeq ($(ENA_WST),1)

ZX_SG += sg/ws-trust-1.3.sg sg/ws-policy.sg sg/ws-secureconversation-1.3.sg

endif

# WS-Trust

ifeq ($(ENA_TAS3),1)

ZX_SG += sg/tas3.sg sg/tas3sol.sg

endif

#
# Generated files (the zxid/c subdirectory) (see also Manifest if you add files)
#

ZX_GEN_H=\
 c/zx-a-data.h    c/zx-di12-data.h  c/zx-lu-data.h    c/zx-xenc-data.h \
 c/zx-ac-data.h   c/zx-m20-data.h   c/zx-sec-data.h   c/zx-exca-data.h \
 c/zx-b-data.h    c/zx-ds-data.h    c/zx-md-data.h    c/zx-sec12-data.h \
 c/zx-b12-data.h  c/zx-e-data.h     c/zx-ns.h         c/zx-sp-data.h \
 c/zx-ff12-data.h c/zx-sa-data.h    c/zx-sp11-data.h \
 c/zx-data.h      c/zx-is-data.h    c/zx-sa11-data.h  c/zx-wsse-data.h \
 c/zx-di-data.h   c/zx-is12-data.h  c/zx-sbf-data.h   c/zx-wsu-data.h \
 c/zx-ecp-data.h  c/zx-paos-data.h  c/zx-dap-data.h   c/zx-ps-data.h \
 c/zx-im-data.h   c/zx-as-data.h    c/zx-subs-data.h  c/zx-dst-data.h \
 c/zx-cb-data.h   c/zx-cdm-data.h   c/zx-gl-data.h    c/zx-mm7-data.h \
 c/zx-wst-data.h  c/zx-wsp-data.h   c/zx-wsc-data.h \
 c/zx-xa-data.h   c/zx-xac-data.h   c/zx-xasa-data.h  c/zx-xasp-data.h \
 c/zx-xasacd1-data.h  c/zx-xaspcd1-data.h \
 c/zx-dp-data.h   c/zx-pmm-data.h   c/zx-prov-data.h  c/zx-idp-data.h        c/zx-shps-data.h \
 c/zx-demomed-data.h c/zx-hrxml-data.h c/zx-idhrxml-data.h \
 c/zx-xsi-data.h  c/zx-xs-data.h    c/zx-xml-data.h \
 c/zx-tas3-data.h  c/zx-tas3sol-data.h c/zx-shibmd-data.h c/zx-idpdisc-data.h

ZX_GEN_C=\
 c/zx-a-aux.c      c/zx-di12-dec.c    c/zx-is-enc.c      c/zx-sa11-dec.c     c/zx-sp11-dec.c \
 c/zx-a-dec.c      c/zx-di12-enc.c    c/zx-is-getput.c   c/zx-sa11-enc.c     c/zx-sp11-enc.c \
 c/zx-a-enc.c      c/zx-di12-getput.c c/zx-is12-aux.c    c/zx-sa11-getput.c  c/zx-sp11-getput.c \
 c/zx-a-getput.c   c/zx-is12-dec.c    c/zx-sbf-aux.c     c/zx-wsse-aux.c \
 c/zx-ac-aux.c     c/zx-is12-enc.c    c/zx-sbf-dec.c     c/zx-wsse-dec.c \
 c/zx-ac-dec.c     c/zx-is12-getput.c c/zx-sbf-enc.c     c/zx-wsse-enc.c \
 c/zx-ac-enc.c     c/zx-lu-aux.c      c/zx-sbf-getput.c  c/zx-wsse-getput.c \
 c/zx-ac-getput.c  c/zx-ds-aux.c      c/zx-lu-dec.c      c/zx-wsu-aux.c \
 c/zx-ds-dec.c     c/zx-lu-enc.c      c/zx-wsu-dec.c \
 c/zx-aux.c        c/zx-ds-enc.c      c/zx-lu-getput.c   c/zx-wsu-enc.c \
 c/zx-b-aux.c      c/zx-ds-getput.c   c/zx-m20-aux.c     c/zx-wsu-getput.c \
 c/zx-b-dec.c      c/zx-e-aux.c       c/zx-m20-dec.c     c/zx-sec-aux.c      c/zx-xenc-aux.c \
 c/zx-b-enc.c      c/zx-e-dec.c       c/zx-m20-enc.c     c/zx-sec-dec.c      c/zx-xenc-dec.c \
 c/zx-b-getput.c   c/zx-e-enc.c       c/zx-m20-getput.c  c/zx-sec-enc.c      c/zx-xenc-enc.c \
 c/zx-b12-aux.c    c/zx-e-getput.c    c/zx-md-aux.c      c/zx-sec-getput.c   c/zx-xenc-getput.c \
 c/zx-b12-dec.c    c/zx-md-dec.c      c/zx-sec12-aux.c \
 c/zx-b12-enc.c    c/zx-enc.c         c/zx-md-enc.c      c/zx-sec12-dec.c \
 c/zx-b12-getput.c c/zx-ff12-aux.c    c/zx-md-getput.c   c/zx-sec12-enc.c \
 c/zx-dec.c        c/zx-ff12-dec.c    c/zx-ns.c          c/zx-sec12-getput.c \
 c/zx-di-aux.c     c/zx-ff12-enc.c    c/zx-sa-aux.c      c/zx-sp-aux.c \
 c/zx-di-dec.c     c/zx-ff12-getput.c c/zx-sa-dec.c      c/zx-sp-dec.c \
 c/zx-di-enc.c     c/zx-getput.c      c/zx-sa-enc.c      c/zx-sp-enc.c \
 c/zx-di-getput.c  c/zx-is-aux.c      c/zx-sa-getput.c   c/zx-sp-getput.c \
 c/zx-di12-aux.c   c/zx-is-dec.c      c/zx-sa11-aux.c    c/zx-sp11-aux.c \
 c/zx-ecp-aux.c    c/zx-ecp-dec.c     c/zx-ecp-enc.c     c/zx-ecp-getput.c \
 c/zx-paos-aux.c   c/zx-paos-dec.c    c/zx-paos-enc.c    c/zx-paos-getput.c \
 c/zx-dap-aux.c    c/zx-dap-dec.c     c/zx-dap-enc.c     c/zx-dap-getput.c \
 c/zx-ps-aux.c     c/zx-ps-dec.c      c/zx-ps-enc.c      c/zx-ps-getput.c \
 c/zx-im-aux.c     c/zx-im-dec.c      c/zx-im-enc.c      c/zx-im-getput.c \
 c/zx-as-aux.c     c/zx-as-dec.c      c/zx-as-enc.c      c/zx-as-getput.c \
 c/zx-subs-aux.c   c/zx-subs-dec.c    c/zx-subs-enc.c    c/zx-subs-getput.c \
 c/zx-dst-aux.c    c/zx-dst-dec.c     c/zx-dst-enc.c     c/zx-dst-getput.c \
 c/zx-cb-aux.c     c/zx-cb-dec.c      c/zx-cb-enc.c      c/zx-cb-getput.c \
 c/zx-cdm-aux.c    c/zx-cdm-dec.c     c/zx-cdm-enc.c     c/zx-cdm-getput.c \
 c/zx-gl-aux.c     c/zx-gl-dec.c      c/zx-gl-enc.c      c/zx-gl-getput.c \
 c/zx-mm7-aux.c    c/zx-mm7-dec.c     c/zx-mm7-enc.c     c/zx-mm7-getput.c \
 c/zx-wst-aux.c    c/zx-wst-dec.c     c/zx-wst-enc.c     c/zx-wst-getput.c \
 c/zx-wsp-aux.c    c/zx-wsp-dec.c     c/zx-wsp-enc.c     c/zx-wsp-getput.c \
 c/zx-wsc-aux.c    c/zx-wsc-dec.c     c/zx-wsc-enc.c     c/zx-wsc-getput.c \
 c/zx-xa-aux.c     c/zx-xa-dec.c      c/zx-xa-enc.c      c/zx-xa-getput.c \
 c/zx-xac-aux.c    c/zx-xac-dec.c     c/zx-xac-enc.c     c/zx-xac-getput.c \
 c/zx-xasa-aux.c   c/zx-xasa-dec.c    c/zx-xasa-enc.c    c/zx-xasa-getput.c \
 c/zx-xasacd1-aux.c   c/zx-xasacd1-dec.c    c/zx-xasacd1-enc.c    c/zx-xasacd1-getput.c \
 c/zx-xasp-aux.c   c/zx-xasp-dec.c    c/zx-xasp-enc.c    c/zx-xasp-getput.c \
 c/zx-xaspcd1-aux.c   c/zx-xaspcd1-dec.c    c/zx-xaspcd1-enc.c    c/zx-xaspcd1-getput.c \
 c/zx-dp-aux.c     c/zx-dp-dec.c      c/zx-dp-enc.c      c/zx-dp-getput.c \
 c/zx-pmm-aux.c    c/zx-pmm-dec.c     c/zx-pmm-enc.c     c/zx-pmm-getput.c \
 c/zx-prov-aux.c   c/zx-prov-dec.c    c/zx-prov-enc.c    c/zx-prov-getput.c \
 c/zx-idp-aux.c    c/zx-idp-dec.c     c/zx-idp-enc.c     c/zx-idp-getput.c \
 c/zx-shps-aux.c   c/zx-shps-dec.c    c/zx-shps-enc.c    c/zx-shps-getput.c \
 c/zx-exca-aux.c   c/zx-exca-dec.c    c/zx-exca-enc.c    c/zx-exca-getput.c \
 c/zx-hrxml-aux.c  c/zx-hrxml-dec.c   c/zx-hrxml-enc.c   c/zx-hrxml-getput.c \
 c/zx-idhrxml-aux.c c/zx-idhrxml-dec.c c/zx-idhrxml-enc.c c/zx-idhrxml-getput.c \
 c/zx-demomed-aux.c c/zx-demomed-dec.c c/zx-demomed-enc.c c/zx-demomed-getput.c \
 c/zx-xsi-aux.c     c/zx-xsi-dec.c     c/zx-xsi-enc.c     c/zx-xsi-getput.c \
 c/zx-xs-aux.c      c/zx-xs-dec.c      c/zx-xs-enc.c      c/zx-xs-getput.c \
 c/zx-xml-aux.c     c/zx-xml-dec.c     c/zx-xml-enc.c     c/zx-xml-getput.c \
 c/zx-tas3-aux.c    c/zx-tas3-dec.c    c/zx-tas3-enc.c    c/zx-tas3-getput.c \
 c/zx-tas3sol-aux.c c/zx-tas3sol-dec.c c/zx-tas3sol-enc.c c/zx-tas3sol-getput.c \
 c/zx-shibmd-aux.c  c/zx-shibmd-dec.c  c/zx-shibmd-enc.c  c/zx-shibmd-getput.c \
 c/zx-idpdisc-aux.c  c/zx-idpdisc-dec.c  c/zx-idpdisc-enc.c  c/zx-idpdisc-getput.c

ifeq ($(ENA_GEN),1)

### Schema based code generation
### If this runs over and over again, check timestamps in sg/ directory, or make -d -p

c/zx-attrs.gperf c/zx-elems.gperf $(ZX_GEN_C) $(ZX_GEN_H): $(ZX_SG) dec-templ.c enc-templ.c aux-templ.c getput-templ.c
	@which $(XSD2SG) || ( echo "You need to install xsd2sg.pl from Plaindoc distribution at http://zxid.org/plaindoc/pd.html. Not found $(XSD2SG)" && exit 2 )
	$(XSD2SG) -z zx -gen c/zx -p zx_ $(ZX_ROOTS) -S $(ZX_SG) >/dev/null

c/zx-attrs.c: c/zx-attrs.gperf
	@which $(GPERF) || ( echo "You need to install gperf from ftp.gnu.org. Not found $(GPERF)" && exit 2 )
	$(GPERF) -t -D -C -T -l -G -W zx_attrs -N zx_attr2tok $< | \
          $(SED) -e 's/lengthtable/zx_attrs_lens/' \
	         -e 's/static const struct zx_tok/const struct zx_tok/' >$@

c/zx-elems.c: c/zx-elems.gperf
	@which $(GPERF) || ( echo "You need to install gperf from ftp.gnu.org. Not found $(GPERF)" && exit 2 )
	$(GPERF) -t -D -C -T -l -G -W zx_elems -N zx_elem2tok $< | \
          $(SED) -e 's/lengthtable/zx_elems_lens/' \
	         -e 's/static const struct zx_tok/const struct zx_tok/' >$@

c/zx-const.h: c/zx-attrs.c c/zx-elems.c
	cat c/zx-attrs.c | $(PERL) gen-consts-from-gperf-output.pl zx_ _ATTR zx_attrs >$@
	cat c/zx-elems.c | $(PERL) gen-consts-from-gperf-output.pl zx_ _ELEM zx_elems >>$@

# Other

# N.B. echo(1) command of some shells, such as dash, is broken such that the \n\ sequence
# is not preserved.

c/license.c: LICENSE-2.0.txt
	$(ECHO) 'char* license = ' >$@
	$(ECHO) '"Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.\n\' >>$@ #'
	$(ECHO) 'Author: Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\' >>$@ #'
	$(SED) -e 's/"/\\"/g' -e 's/$$/\\n\\/' LICENSE-2.0.txt >>$@
	$(ECHO) '";' >>$@

c/zxidvers.h:
	$(ECHO) "#ifndef _zxidvers_h" >c/zxidvers.h
	$(ECHO) "#define _zxidvers_h" >>c/zxidvers.h
	$(ECHO) "#define ZXID_VERSION $(ZXIDVERSION)" >>c/zxidvers.h
	$(ECHO) "#define ZXID_REL \"$(ZXIDREL)\"" >>c/zxidvers.h
	$(ECHO) "#define ZXID_COMPILE_DATE \"`date +%s`\"" >>c/zxidvers.h
	$(ECHO) "#endif" >>c/zxidvers.h

# $(ZXID_OBJ:.o=.c) $(WSF_OBJ:.o=.c) zxdecode.c zxcot.c zxpasswd.c zxidhlo.c zxidsp.c zxidsimple.c $(ZX_OBJ:.o=.c) $(ZX_GEN_H) $(ZX_GEN_C) c/zx-const.h c/zxidvers.h

gen: c/zxidvers.h c/license.c c/zx-const.h c/zx-attrs.gperf

genwrap: gen zxidjava/zxid_wrap.c Net/SAML_wrap.c php/zxid_wrap.c py/zxid_wrap.c ruby/zxid_wrap.c csharp/zxid_wrap.c

# make cleany && make genwrap ENA_GEN=1 && make all ENA_GEN=1

endif

updatevers:
	rm -f c/zxidvers.h
	$(MAKE) c/zxidvers.h ENA_GEN=1

###
###  Perl Modules
###

# Main Net::SAML module - high level APIs

ifeq ($(ENA_GEN),1)

Net/SAML_wrap.c Net/SAML.pm: $(ZX_GEN_H) zxid.h zxid.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	$(SWIG) -o Net/SAML_wrap.c -perl zxid.i
	$(PERL) -pi -e 's/\*zxid_/*/i; s/\*SAML2?_/*/i' Net/SAML.pm

# Net::SAML::Metadata - low level metadata APIs

Metadata/Metadata_wrap.c Metadata/Metadata.pm: $(ZX_GEN_H) zxidmd.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	$(SWIG) -o Metadata/Metadata_wrap.c -perl zxidmd.i
	$(PERL) -pi -e 's/\*SAML2?_/*/i' Metadata/Metadata.pm

# Net::SAML::Raw - low level assertion and protocol APIs

Raw/Raw_wrap.c Raw/Raw.pm: $(ZX_GEN_H) zxidraw.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	$(SWIG) -o Raw/Raw_wrap.c -perl zxidraw.i
	$(PERL) -pi -e 's/\*SAML2?_/*/i' Raw/Raw.pm

# Net::WSF::WSC - high level APIs for implementing WSC

WSC/WSC_wrap.c WSC/WSC.pm: $(ZX_GEN_H) zxwsc.h wsc.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	$(SWIG) -o WSC/WSC_wrap.c -perl wsc.i
	$(PERL) -pi -e 's/\*zxwsc_/*/i; s/\*SAML2?_/*/i' WSC/WSC.pm

# Net::WSF::Raw - low level protocol APIs

WSF_Raw/Raw_wrap.c WSF_Raw/Raw.pm: $(ZX_GEN_H) wsfraw.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	$(SWIG) -o WSF_Raw/Raw_wrap.c -perl wsfraw.i
	$(PERL) -pi -e 's/\*zxwsc_/*/i; s/\*SAML2?_/*/i' WSF_Raw/Raw.pm

endif

# Overall

samlmod Net/Makefile: Net/SAML_wrap.c Net/SAML.pm libzxid.a
	cd Net; $(PERL) Makefile.PL && $(MAKE)

samlmod_install: Net/Makefile
	cd Net; $(MAKE) install

mdmod: Metadata/Metadata_wrap.c Metadata/Metadata.pm
	cd Metadata; $(PERL) Makefile.PL && $(MAKE)

rawmod: Raw/Raw.pm Raw/Raw_wrap.c
	cd Raw; $(PERL) Makefile.PL && $(MAKE)

wscmod: WSC/WSC.pm WSC/WSC_wrap.c
	cd WSC; $(PERL) Makefile.PL && $(MAKE)

wsfrawmod: WSF_Raw/Raw.pm WSF_Raw/Raw_wrap.c
	cd WSF_Raw; $(PERL) Makefile.PL && $(MAKE)

perlmod: samlmod

perlzxid: samlmod

perlzxid_install: samlmod_install

perlclean:
	@$(ECHO) ------------------ Making perlclean
	rm -rf Net/blib Net/*~ Net/*.o Net/Makefile Net/Makefile.old Net/SAML.bs
	rm -rf Metadata/blib Metadata/*~ Metadata/*.o Metadata/Makefile Metadata/Makefile.old Metadata/Metadata.bs
	rm -rf Raw/blib Raw/*~ Raw/*.o Raw/Makefile Raw/Makefile.old Raw/Raw.bs
	rm -rf WSC/blib WSC/*~ WSC/*.o WSC/Makefile WSC/Makefile.old WSC/WSC.bs
	rm -rf WSF_Raw/blib WSF_Raw/*~ WSF_Raw/*.o WSF_Raw/Makefile WSF_Raw/Makefile.old WSF_Raw/Raw.bs

perlcleaner: perlclean
	@$(ECHO) ------------------ Making perlcleaner
	rm -f Net/SAML.pm Net/SAML_wrap.c
	rm -f Metadata/Metadata_wrap.c Metadata/Metadata.pm
	rm -f Raw/Raw.pm Raw/Raw_wrap.c
	rm -f WSC/WSC.pm WSC/WSC_wrap.c
	rm -f WSF_Raw/Raw.pm WSF_Raw/Raw_wrap.c

###
###  PHP Module
###

ifeq ($(ENA_GEN),1)

php/zxid_wrap.c php/zxid.php php/php_zxid.h php/Makefile: $(ZX_GEN_H) zxid.h phpzxid.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	cd php; $(SWIG) -o zxid_wrap.c -noproxy -php ../phpzxid.i

endif

php/zxid_wrap.o: php/zxid_wrap.c
	$(CC) -c -o $@ `$(PHP_CONFIG) --includes` $(CFLAGS) $<

php/php_zxid.so: php/zxid_wrap.o libzxid.a
	$(LD) $(LDFLAGS) -o php/php_zxid.so -shared php/zxid_wrap.o $(LIBZXID) $(LIBS)

phpzxid: php/php_zxid.so

php/php_zxid.dll: php/php_zxid.so
	mv php/php_zxid.so php/php_zxid.dll

phpzxid_install: php/php_zxid.so
	@$(ECHO) Installing in `$(PHP_CONFIG) --extension-dir`
	mkdir -p `$(PHP_CONFIG) --extension-dir`
	cp $< `$(PHP_CONFIG) --extension-dir`

#cp zxid.ini `$(PHP_CONFIG) --extension-dir`

phpclean:
	rm -rf php/*.o php/*~ php/*.so

phpcleaner: phpclean
	rm -rf php/php_zxid.h php/zxid.php php/zxid_wrap.c

###
###  Python Module (*** Never tested)
###

ifeq ($(ENA_GEN),1)

py/zxid_wrap.c py/zxid.py py/Makefile: $(ZX_GEN_H) zxid.h pyzxid.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	cd py; $(SWIG) -o zxid_wrap.c -python ../pyzxid.i

endif

py/zxid_wrap.o: py/zxid_wrap.c
	$(CC) -c -o $@ `$(PY_CONFIG) --includes` $(CFLAGS) $<

py/py_zxid.so: py/zxid_wrap.o libzxid.a
	$(LD) $(LDFLAGS) -o py/py_zxid.so -shared py/zxid_wrap.o $(LIBZXID) $(LIBS)

pyzxid: py/py_zxid.so

pyzxid_install: py/py_zxid.so
	@$(ECHO) Installing in `$(PY_CONFIG) --extension-dir`
	mkdir -p `$(PY_CONFIG) --extension-dir`
	cp $< `$(PY_CONFIG) --extension-dir`

pyclean:
	rm -rf py/*.o py/*~ py/*.so

pycleaner: pyclean
	rm -rf py/zxid.py py/zxid_wrap.c

###
###  Ruby Module (*** Never tested)
###

ifeq ($(ENA_GEN),1)

ruby/zxid_wrap.c ruby/zxid.ruby ruby/Makefile: $(ZX_GEN_H) zxid.h rubyzxid.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	cd ruby; $(SWIG) -o zxid_wrap.c -ruby ../rubyzxid.i

endif

ruby/zxid_wrap.o: ruby/zxid_wrap.c
	$(CC) -c -o $@ `$(RUBY_CONFIG) --includes` $(CFLAGS) $<

ruby/ruby_zxid.so: ruby/zxid_wrap.o libzxid.a
	$(LD) $(LDFLAGS) -o ruby/ruby_zxid.so -shared ruby/zxid_wrap.o $(LIBZXID) $(LIBS)

rubyzxid: ruby/ruby_zxid.so

rubyzxid_install: ruby/ruby_zxid.so
	@$(ECHO) Installing in `$(RUBY_CONFIG) --extension-dir`
	mkdir -p `$(RUBY_CONFIG) --extension-dir`
	cp $< `$(RUBY_CONFIG) --extension-dir`

rubyclean:
	rm -rf ruby/*.o ruby/*~ ruby/*.so

rubycleaner: rubyclean
	rm -rf ruby/zxid.ruby ruby/zxid_wrap.c

###
###  C# (csharp) Module (*** Poorly tested)
###

ifeq ($(ENA_GEN),1)

csharp/zxid_wrap.c csharp/zxid.csharp csharp/Makefile: $(ZX_GEN_H) zxid.h csharpzxid.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	cd csharp; $(SWIG) -o zxid_wrap.c -noproxy -csharp ../csharpzxid.i

endif

csharp/zxid_wrap.o: csharp/zxid_wrap.c
	$(CC) -c -o $@ `$(CSHARP_CONFIG) --includes` $(CFLAGS) $<

csharp/csharp_zxid.so: csharp/zxid_wrap.o libzxid.a
	$(LD) $(LDFLAGS) -o csharp/csharp_zxid.so -shared csharp/zxid_wrap.o $(LIBZXID) $(LIBS)

csharpzxid: csharp/csharp_zxid.so

csharpzxid_install: csharp/csharp_zxid.so
	@$(ECHO) Installing in `$(CSHARP_CONFIG) --extension-dir`
	mkdir -p `$(CSHARP_CONFIG) --extension-dir`
	cp $< `$(CSHARP_CONFIG) --extension-dir`

csharpclean:
	rm -rf csharp/*.o csharp/*~ csharp/*.so

csharpcleaner: csharpclean
	rm -rf csharp/zxid.csharp csharp/zxid_wrap.c

###
###  Java JNI Module
###

ifeq ($(ENA_GEN),1)

zxidjava/zxid_wrap.c: $(ZX_GEN_H) zxid.h javazxid.i
	@which $(SWIG) || ( echo "You need to install swig from swig.org. Not found $(SWIG)" && exit 2 )
	cd zxidjava; $(SWIG) -noproxy -Dconst= -w451 -o zxid_wrap.c -java -package zxidjava ../javazxid.i
	$(PERL) -pi -e 's/SWIGTYPE_p_zxid_conf/zxid_conf/g' zxidjava/*.java
	mv zxidjava/SWIGTYPE_p_zxid_conf.java zxidjava/zxid_conf.java
	$(PERL) -pi -e 's/SWIGTYPE_p_zxid_ses/zxid_ses/g' zxidjava/*.java
	mv zxidjava/SWIGTYPE_p_zxid_ses.java zxidjava/zxid_ses.java
	$(PERL) -pi -e 's/(public static \w+ )zxid_/$$1/' zxidjava/zxidjni.java

endif

zxidjava/zxid_wrap.o: zxidjava/zxid_wrap.c
	$(CC) -c -o $@ $(JNI_INC) $(CFLAGS) $<

$(ZXIDJNI_SO): zxidjava/zxid_wrap.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $(SHARED_FLAGS) $< $(LIBZXID) $(LIBS) $(SHARED_CLOSE)

zxidjava/zxidjni.class: zxidjava/zxidjni.java
	cd zxidjava; $(JAVAC) $(JAVAC_FLAGS) *.java

zxid.class: zxid.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) zxidjava/*.java zxid.java

zxidhlo.class: zxidhlo.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) -classpath $(SERVLET_PATH) zxidjava/*.java zxidhlo.java

zxidsrvlet.class: zxidsrvlet.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) -classpath $(SERVLET_PATH) zxidjava/*.java zxidsrvlet.java

zxidappdemo.class: zxidappdemo.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) -classpath $(SERVLET_PATH) zxidjava/*.java zxidappdemo.java

zxidwspdemo.class: zxidwspdemo.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) -classpath $(SERVLET_PATH) zxidjava/*.java zxidwspdemo.java

zxidwspleaf.class: zxidwspleaf.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) -classpath $(SERVLET_PATH) zxidjava/*.java zxidwspleaf.java

zxidwscprepdemo.class: zxidwscprepdemo.java zxidjava/zxidjni.class
	$(JAVAC) $(JAVAC_FLAGS) -classpath $(SERVLET_PATH) zxidjava/*.java zxidwscprepdemo.java

zxidjava.jar: zxidjava/zxidjni.class zxidjava/README.zxid-java
	cp COPYING LICENSE-2.0.txt LICENSE.openssl LICENSE.ssleay zxidjava/
	$(JAR) cf zxidjava.jar zxidjava/*.class zxidjava/*.java zxidjava/COPYING zxidjava/LICENSE*

zxiddemo.war: zxidjava.jar
	mkdir -p zxidservlet/WEB-INF/classes/zxidjava/
	cp -f zxidjava.jar ./zxidservlet/WEB-INF/classes/
	cp -f ./servlet/WEB-INF/web.xml ./zxidservlet/WEB-INF/
	cp -f zxidsrvlet.class zxidappdemo.class zxidwscprepdemo.class zxidwspdemo.class zxidwspleaf.class zxidhlo.class zxidservlet/WEB-INF/classes/
	cd ./zxidservlet ; $(JAR) cf ../zxiddemo.war *; cd ../
	rm -rf zxidservlet

javazxid: $(ZXIDJNI_SO) zxidjava/zxidjni.class zxidhlo.class zxidsrvlet.class zxidappdemo.class zxidwscprepdemo.class zxidwspdemo.class zxidwspleaf.class zxidjava.jar zxiddemo.war

javazxid_install: $(ZXIDJNI_SO)
	@$(ECHO) "javazxid_install: Work in Progress. See zxid-java.pd"

# from Brian, somewhat obsoleted by zxiddemo.war
javazxid_war:
	mkdir -p zxidservlet/WEB-INF/classes/zxidjava/
	cp -f ./zxidjava/*.class ./zxidservlet/WEB-INF/classes/zxidjava/
	cp -f ./servlet/WEB-INF/web.xml ./zxidservlet/WEB-INF/
	cp -f zxidsrvlet.class zxidappdemo.class zxidwscprepdemo.class zxidwspdemo.class zxidwspleaf.class zxidhlo.class zxidservlet/WEB-INF/classes/
	cd ./zxidservlet ; $(JAR) cf ../zxidservlet.war *; cd ../
	rm -rf zxidservlet

#  rsync zxididp root@elsa:/var/zxid/webroot/apache-tomcat-5.5.20/webapps
#  mv zxidservlet.war $(WEBAPPS_PATH)/

javaclean:
	rm -rf zxidjava/*.o zxidjava/*~ zxidjava/*.so zxidjava/*.class *.class

javacleaner: javaclean
	rm -rf zxidjava/*.java zxidjava/zxid_wrap.c

###
### Apache authentication module
###

mod_auth_saml.so: mod_auth_saml.o libzxid.a
	$(LD) $(LDFLAGS) -o mod_auth_saml.so $(SHARED_FLAGS) mod_auth_saml.o $(SHARED_CLOSE) $(LIBZXID) $(LIBS) $(MOD_AUTH_SAML_LIBS)

mod_auth_saml.dll: mod_auth_saml.so
	mv mod_auth_saml.so mod_auth_saml.dll

mod_auth_saml:
	@$(ECHO) "mod_auth_saml: not an official target. Use make apachezxid"

precheck_apache:  precheck/chk-apache.o precheck/chk-apache
	precheck/chk-apache

apachezxid: precheck_apache precheck mod_auth_saml.so

apachezxid_install: mod_auth_saml.so
	cp $< $(APACHE_MODULES)

###
### Binaries
###

zxid: $(ZXID_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxid $(ZXID_OBJ) $(LIBZXID) $(LIBS)

zxcot: zxcot.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $< $(LIBZXID) $(LIBS)

zxdecode: zxdecode.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBZXID) $(LIBS)

zxpasswd: zxpasswd.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBZXID) $(LIBS)

zxcall: zxcall.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $< $(LIBZXID) $(LIBS)

zxidwspcgi: zxidwspcgi.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $< $(LIBZXID) $(LIBS)

zxidwsctool: $(ZXIDWSCTOOL_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidwsctool $(ZXIDWSCTOOL_OBJ) $(LIBZXID) $(LIBS)

zxidhlo: $(ZXIDHLO_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidhlo $(ZXIDHLO_OBJ) $(LIBZXID) $(LIBS)

zxidsp: $(ZXIDSP_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidsp $(ZXIDSP_OBJ) $(LIBZXID) $(LIBS)

zxididp: $(ZXIDIDP_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxididp $(ZXIDIDP_OBJ) $(LIBZXID) $(LIBS)

zxidgsa: $(ZXIDGSA_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidgsa $(ZXIDGSA_OBJ) $(LIBZXID) $(LIBS)

zxidhlowsf: $(ZXIDHLOWSF_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidhlowsf $(ZXIDHLOWSF_OBJ) $(LIBZXID) $(LIBS)

zxidsimple: $(ZXIDSIMPLE_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidsimple $(ZXIDSIMPLE_OBJ) $(LIBZXID) $(LIBS)

zxbench: $(ZXBENCH_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxbench $(ZXBENCH_OBJ) $(LIBZXID) $(LIBS)

zxidssofinalizetest: $(ZXIDSSOFINALIZETEST_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidssofinalizetest $(ZXIDSSOFINALIZETEST_OBJ) $(LIBZXID) $(LIBS)

zxencdectest: $(ZXENCDECTEST_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxencdectest $^ $(LIBZXID) $(LIBS)

sfis: $(SFIS_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o sfis $(SFIS_OBJ) $(LIBZXID) $(LIBS)

sfisgsa: $(SFISGSA_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o sfisgsa $(SFISGSA_OBJ) $(LIBZXID) $(LIBS)

zxidxmltool: $(ZXIDXMLTOOL_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidxmltool $^ $(LIBS)

zxlogview: $(ZXLOGVIEW_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxlogview $^ $(LIBS)

zxidhrxmlwsc: $(ZXIDHRXMLWSC_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidhrxmlwsc $(ZXIDHRXMLWSC_OBJ) $(LIBZXID) $(LIBS)

zxidhrxmlwsp: $(ZXIDHRXMLWSP_OBJ) libzxid.a
	$(LD) $(LDFLAGS) -o zxidhrxmlwsp $(ZXIDHRXMLWSP_OBJ) $(LIBZXID) $(LIBS)

zxidhrxml: zxidhrxmlwsc zxidhrxmlwsp

smime: smime.o libzxid.a
	$(LD) $(LDFLAGS) -o $@ $< $(LIBZXID) $(LIBS)

sizeof:
	$(CC) -o sizeof sizeof.c

###
### Libraries
###

ifeq ($(PULVER),1)

libzxid.a: $(ZXID_LIB_OBJ) $(ZX_OBJ)
	cat pulver/c_saml2_dec_c.deps      | xargs $(AR) libzxid.a
	cat pulver/c_saml2_enc_c.deps      | xargs $(AR) libzxid.a
	cat pulver/c_saml2_aux_c.deps      | xargs $(AR) libzxid.a
	cat pulver/c_saml2_getput_c.deps   | xargs $(AR) libzxid.a
	cat pulver/c_saml2md_dec_c.deps    | xargs $(AR) libzxid.a
	cat pulver/c_saml2md_enc_c.deps    | xargs $(AR) libzxid.a
	cat pulver/c_saml2md_aux_c.deps    | xargs $(AR) libzxid.a
	cat pulver/c_saml2md_getput_c.deps | xargs $(AR) libzxid.a
	$(AR) libzxid.a $(ZXID_LIB_OBJ)

#	$(foreach fil,$^,$(shell $(AR) libzxid.a $(fil)))

else

libzxid.a: $(ZX_GEN_C:.c=.o) $(ZXID_LIB_OBJ) $(ZX_OBJ) $(WSF_OBJ) $(SMIME_LIB_OBJ)
	$(AR) libzxid.a $^

endif

libzxid.so.0.0: libzxid.a
	$(LD) -o libzxid.so.0.0 $(SHARED_FLAGS) $^ $(SHARED_CLOSE)

zxid.dll libzxiddll.a: libzxid.a
	$(LD) -o zxid.dll $(SHARED_FLAGS) -Wl,--output-def,zxiddll.def,--out-implib,libzxiddll.a $^ $(SHARED_CLOSE) $(WIN_LIBS)

# N.B. Failing to supply -Wl,-no-whole-archive above will cause
# /apps/gcc/mingw/sysroot/lib/libmingw32.a(main.o):main.c:(.text+0x106): undefined reference to `WinMain@16'
# due to implicitly linked library libmingw32.a pulling in main. See also
# binutils ld info documentation (e.g. invocation/options specific to i386 PE
# targets).

###
### TAS3 Project Specific Targets
###

TAS3COMMONFILES=README.zxid-tas3 README.zxid Changes COPYING LICENSE-2.0.txt LICENSE.openssl LICENSE.ssleay Makefile zxmkdirs.sh

TAS3MAS=T3-SSO-ZXID-MODAUTHSAML_$(ZXIDREL)

tas3maspkg: mod_auth_saml.so
	rm -rf $(TAS3MAS) $(TAS3MAS).zip
	mkdir $(TAS3MAS)
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/'  < Manifest.T3-SSO-ZXID-MODAUTHSAML > $(TAS3MAS)/Manifest
	cp mod_auth_saml.so $(TAS3MAS)
	cp $(TAS3COMMONFILES) $(TAS3MAS)
	zip -r $(TAS3MAS).zip $(TAS3MAS)

TAS3PHP=T3-SSO-ZXID-PHP_$(ZXIDREL)

tas3phppkg: php/php_zxid.so
	rm -rf $(TAS3PHP) $(TAS3PHP).zip
	mkdir $(TAS3PHP)
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/' <Manifest.T3-SSO-ZXID-PHP >$(TAS3PHP)/Manifest
	cp *.php php/php_zxid.so php/zxid.php php/zxid.ini php/README.zxid-php zxid-php.pd $(TAS3PHP)
	cp $(TAS3COMMONFILES) $(TAS3PHP)
	zip -r $(TAS3PHP).zip $(TAS3PHP)

TAS3JAVA=T3-SSO-ZXID-JAVA_$(ZXIDREL)

tas3javapkg: $(ZXIDJNI_SO) zxidjava/zxidjni.class
	rm -rf $(TAS3JAVA) $(TAS3JAVA).zip
	mkdir $(TAS3JAVA)
	mkdir $(TAS3JAVA)/zxidjava
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/' <Manifest.T3-SSO-ZXID-JAVA >$(TAS3JAVA)/Manifest
	cp $(ZXIDJNI_SO) zxidjava/*.java zxidjava/*.class zxidjava/README.zxid-java zxid-java.pd $(TAS3JAVA)/zxidjava
	cp $(TAS3COMMONFILES) $(TAS3JAVA)
	zip -r $(TAS3JAVA).zip $(TAS3JAVA)

TAS3IDP=T3-IDP-ZXID_$(ZXIDREL)

tas3idppkg: zxididp zxpasswd zxcot zxdecode
	rm -rf $(TAS3IDP) $(TAS3IDP).zip
	mkdir $(TAS3IDP)
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/' < Manifest.T3-IDP-ZXID > $(TAS3IDP)/Manifest
	cp zxididp zxpasswd zxcot zxdecode zxid-idp.pd $(TAS3IDP)
	cp $(TAS3COMMONFILES) $(TAS3IDP)
	zip -r $(TAS3IDP).zip $(TAS3IDP)

TAS3LINUXX86=T3-ZXID-LINUX-X86_$(ZXIDREL)

tas3linuxx86pkg: zxididp zxpasswd zxcot zxdecode zxlogview mod_auth_saml.so php/php_zxid.so $(ZXIDJNI_SO) zxidjava/zxidjni.class
	rm -rf $(TAS3LINUXX86) $(TAS3LINUXX86).zip
	mkdir $(TAS3LINUXX86)
	mkdir $(TAS3LINUXX86)/zxidjava
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/' < Manifest.T3-ZXID-LINUX-X86 > $(TAS3LINUXX86)/Manifest
	cp mod_auth_saml.so $(TAS3LINUXX86)
	cp *.php php/php_zxid.so php/zxid.php php/zxid.ini php/README.zxid-php zxid-php.pd $(TAS3LINUXX86)
	cp zxididp zxpasswd zxcot zxdecode zxlogview zxid-idp.pd $(TAS3LINUXX86)
	cp $(ZXIDJNI_SO) zxidjava/*.java zxidjava/*.class zxidjava/README.zxid-java zxid-java.pd $(TAS3LINUXX86)/zxidjava
	cp $(TAS3COMMONFILES) $(TAS3LINUXX86)
	zip -r $(TAS3LINUXX86).zip $(TAS3LINUXX86)

TAS3WIN32=T3-ZXID-WIN32_$(ZXIDREL)

#tas3win32pkg: mod_auth_saml.so php/php_zxid.so
#	cp mod_auth_saml.so $(TAS3LINUXX86)
#	cp *.php php/php_zxid.dll php/zxid.php php/zxid.ini php/README.zxid-php zxid-php.pd $(TAS3LINUXX86)

tas3win32pkg: zxid.dll zxididp zxpasswd zxcot zxdecode zxlogview $(ZXIDJNI_SO) zxidjava/zxidjni.class zxidappdemo.class zxidjava.jar zxiddemo.war
	rm -rf $(TAS3WIN32) $(TAS3WIN32).zip
	mkdir $(TAS3WIN32)
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/' < Manifest.T3-ZXID-WIN32 > $(TAS3WIN32)/Manifest
	cp zxid.dll $(TAS3WIN32)/
	cp zxididp $(TAS3WIN32)/zxididp.exe
	cp zxpasswd $(TAS3WIN32)/zxpasswd.exe
	cp zxcot $(TAS3WIN32)/zxcot.exe
	cp zxdecode $(TAS3WIN32)/zxdecode.exe
	cp zxlogview $(TAS3WIN32)/zxlogview.exe
	cp zxid-idp.pd $(TAS3WIN32)
	cp mod_auth_saml.dll $(TAS3WIN32)
	cp *.php php/php_zxid.dll php/zxid.php php/zxid.ini php/README.zxid-php zxid-php.pd $(TAS3WIN32)
	cp $(ZXIDJNI_SO) $(TAS3WIN32)/
	cp zxidjava.jar zxiddemo.war zxid-java.pd $(TAS3WIN32)
	cp *.java *.class $(TAS3WIN32)
	cp $(TAS3COMMONFILES) $(TAS3WIN32)
	zip -r $(TAS3WIN32).zip $(TAS3WIN32)

TAS3SRC=T3-ZXID-SRC_$(ZXIDREL)

tas3srcpkg: zxid-$(ZXIDREL).tgz
	rm -rf $(TAS3SRC) $(TAS3SRC).zip
	mkdir $(TAS3SRC)
	$(SED) 's/^Version: .*/Version: $(ZXIDREL)/' < Manifest.T3-ZXID-SRC > $(TAS3SRC)/Manifest
	cp zxid-$(ZXIDREL).tgz $(TAS3SRC)
	cp README.zxid-tas3 Changes COPYING LICENSE-2.0.txt LICENSE.openssl LICENSE.ssleay $(TAS3SRC)
	zip -r $(TAS3SRC).zip $(TAS3SRC)

#tas3rel: tas3idppkg tas3javapkg tas3phppkg tas3maspkg tas3srcpkg
#tas3copyrel: tas3rel
#	scp $(TAS3SRC).zip $(TAS3IDP).zip $(TAS3JAVA).zip $(TAS3PHP).zip $(TAS3MAS).zip tas3repo:pool-in

tas3rel: tas3linuxx86pkg tas3srcpkg

# tas3pool T3-ZXID-SRC_0.54.zip && tas3pool -u T3-ZXID-SRC_0.54.zip
# tas3pool T3-ZXID-LINUX-X86_0.54.zip && tas3pool -u T3-ZXID-LINUX-X86_0.54.zip
# tas3pool T3-ZXID-WIN32_0.56.zip

tas3copyrel: tas3rel
	scp $(TAS3SRC).zip $(TAS3LINUXX86).zip tas3repo:pool-in

###
### Precheck to help analyse compilation problems
###

precheck/chk-zlib: precheck/chk-zlib.o
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS)

precheck/chk-openssl: precheck/chk-openssl.o
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS)

precheck/chk-curl: precheck/chk-curl.o
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS)

precheck/chk-apache: precheck/chk-apache.o
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS)

ifeq ($(CROSS_COMPILE),1)
precheck: precheck/chk-zlib.o precheck/chk-zlib precheck/chk-openssl.o precheck/chk-openssl \
          precheck/chk-curl.o precheck/chk-curl
	@$(ECHO) "Cross compile simplified precheck ok."
	@$(ECHO)
else
precheck: precheck/chk-zlib.o precheck/chk-zlib precheck/chk-openssl.o precheck/chk-openssl \
          precheck/chk-curl.o precheck/chk-curl
	precheck/chk-zlib
	precheck/chk-openssl
	precheck/chk-curl
	@$(ECHO) "Precheck ok."
	@$(ECHO)
endif

precheckclean:
	rm -f precheck/*.o
	rm -f precheck/chk-zlib	precheck/chk-openssl precheck/chk-curl precheck/chk-apache

###
### Test suite
###

t/cot:
	./mkdirs.sh t/

t/idpcot:
	./mkdirs.sh t/idp

t/wspcot:
	./mkdirs.sh t/wsp

t/wsp2cot:
	./mkdirs.sh t/wsp2

test: t/cot t/idp t/wsp t/wsp2 zxencdectest zxcall zxididp
	$(PERL) zxtest.pl -a

#test: test.o
#	$(CC) -o $@ $< $(LIBZXID) $(LIBS)

win32loadlibtest.exe: win32loadlibtest.o
	$(CC) -o $@ $<

### Test dynamic link library loading (on Windows)

zxidjava/testjni.class: zxidjava/testjni.java
	cd zxidjava; $(JAVAC) $(JAVAC_FLAGS) test*.java

zxidjava/testjni.o: zxidjava/testjni.c
	$(CC) -c -o $@ $(JNI_INC) $(CFLAGS) $<

zxidjava/libtestjni.a: zxidjava/testjni.o
	$(AR) $@ $^

zxidjava/testjni.dll: zxidjava/libtestjni.a
	$(LD) -o $@ $(SHARED_FLAGS) $^ $(SHARED_CLOSE)

zxidjava/testmain: zxidjava/testmain.o
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS)

testmain.class: testmain.java
	$(JAVAC) $(JAVAC_FLAGS) zxidjava/test*.java testmain.java

testdll: zxidjava/testmain zxidjava/testjni.dll testmain.class

testdll.zip: testdll
	zip $@ zxidjava/testmain zxidjava/testjni.dll testmain.class testmain.java zxidjava/test*.class zxidjava/test*.java

testdll.tar: testdll
	tar cf $@ zxidjava/testmain zxidjava/testjni.dll testmain.class testmain.java zxidjava/test*.class zxidjava/test*.java

testdllclean:
	rm -rf testmain.class zxidjava/test*.class zxidjava/test*.o zxidjava/testmain zxidjava/libtestjni.a zxidjava/test*.dll

testclean:
	rm -rf t/*ses t/*user t/*/uid t/*nid t/*log t/*cot t/*pem tmp/*.out tmp/*.err

###
### Installation (needs more work, try `make dir' or `make dir ZXID_PATH=/var/zxid/idp')
###  ./zxmkdirs.sh /var/zxid/idp
###

dir:
	./zxmkdirs.sh
	-cp default-cot/* $(ZXID_PATH)cot

#	cp zxid.pem $(ZXID_PATH)pem/sign-nopw-cert.pem
#	cp zxid.pem $(ZXID_PATH)pem/enc-nopw-cert.pem
#	cp zxid.pem $(ZXID_PATH)pem/logenc-nopw-cert.pem
#	cp zxid.pem $(ZXID_PATH)pem/logsign-nopw-cert.pem
#	cp zxid.pem $(ZXID_PATH)pem/logenc.key

dirs: dir
	@$(ECHO) "You should use `make dir' instead!"

install: zxid libzxid.a libzxid.so.0.0 dir
	@$(ECHO) "===== Installing in $(PREFIX) (to change do make install PREFIX=/your/path)"
	-mkdir -p $(PREFIX) $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/zxid
	cp zxidhlo zxididp $(PREFIX)/bin
	cp libzxid.a libzxid.so* $(PREFIX)/lib
	cp libzxid.so.0.0 $(PREFIX)/lib
	cp *.h c/*.h $(PREFIX)/include/zxid
	@$(ECHO) "You will need to copy zxidhlo binary where your web server can find it and"
	@$(ECHO) "make sure your web server is configured to recognize zxidhlo as a CGI script."
	@$(ECHO)
	@$(ECHO) "For a quick test, you can try putting following in your /etc/hosts:"
	@$(ECHO)
	@$(ECHO) "  127.0.0.1       localhost sp1.zxidcommon.org sp1.zxidsp.org"
	@$(ECHO)
	@$(ECHO) "and then run"
	@$(ECHO)
	@$(ECHO) "  mini_httpd -p 8443 -c zxid -S -E zxid.pem"
	@$(ECHO)
	@$(ECHO) "in the zxid build (usually distribution) directory and then point web browser to"
	@$(ECHO)
	@$(ECHO) "https://sp1.zxidsp.org:8443/zxid"
	@$(ECHO)

#
# Maintenance
#

tags:
	etags *.[hc] c/*.[hc]

SSL=/aino/openssl-0.9.8g
BB=/aino/busybox-1.11.1
#DS=~/ds
#DS=/d/sampo/ds4/ds
DS=/d/sampo/ds
SLIM=/d/sampo/slim
PD=/d/sampo/pd
APACHE=/aino/httpd-2.2.8

megatags:
	etags *.[hc] c/*.[hc] c/*.ds $(SSL)/*/*.[hc] $(SSL)/*/*/*.[hc] $(DS)/*/*.[hc] $(DS)/*/*.ds $(DS)/io/dsproxy-test.pl $(SLIM)/*/*.ds $(SLIM)/conf/*/*.ds $(PD)/xsd2sg.pl $(PD)/pd2tex $(BB)/*/*.[hc] $(BB)/*/*/*.[hc] $(BB)/*/*/*/*.[hc]

# $(APACHE)/*/*.[hc] $(APACHE)/*/*/*.[hc] $(APACHE)/*/*/*/*.[hc] $(APACHE)/*/*/*/*/*.[hc] $(APACHE)/*/*/*/*/*/*.[hc]

docclean:
	rm -f *.dbx *.tex

distclean: clean

cleanbin:
	rm -f zxid zxlogview zxbench zxencdectest libzxid.a libzxid.so* sizeof zxid.stderr
	rm -f zxidhlo zxidhlowsf zxidhrxmlwsc zxidhrxmlwsp zxidsimple zxidsp zxidwsctool
	rm -f zxidwspcgi zxidxfoobarwsp zxpasswd zxcot zxcall
	rm -f mod_auth_saml.so zxididp zxdecode

miniclean: perlclean phpclean pyclean rubyclean csharpclean javaclean docclean precheckclean
	@$(ECHO) ------------------ Making miniclean
	rm -f *.o zxid zxlogview zxbench zxencdectest libzxid.a libzxid.so* sizeof zxid.stderr
	rm -f zxidhlo zxidhlowsf zxidhrxmlwsc zxidhrxmlwsp zxidsimple zxidsp zxidwsctool
	rm -f mod_auth_saml.so zxididp
	rm -f core* *~ .*~ .\#* c/.*~ c/.\#* sg/*~ sg/.*~ sg/.\#* foo bar afr.*

# make cleany && make genwrap ENA_GEN=1 && make all ENA_GEN=1

cleany: clean perlcleaner phpcleaner pycleaner rubycleaner csharpcleaner javacleaner
	@$(ECHO) ------------------ Making cleany
	rm -f c/*.[hc] c/*.gperf c/*.y
	rm -rf pulver; mkdir pulver

cleaner: cleany cleangcov
	@$(ECHO) ================== Making cleaner
	rm -f deps deps.dep c/*.deps

regen: clean perlcleaner phpcleaner pycleaner rubycleaner csharpcleaner javacleaner
	@$(ECHO) ================== Making regen
	rm -f c/*.[hc] c/*.gperf c/*.y deps deps.dep c/*.deps

# N.B. The clean and dist targets deliberately do not delete contents of
#      directory c/ although they are generated files. This is to allow
#      zxid to be built without the tools needed to generate those files.
clean: perlclean phpclean pyclean rubyclean csharpclean javaclean docclean precheckclean cleanbin
	@$(ECHO) ------------------ Making clean
	rm -f *.o c/*.o
	rm -f core* *~ .*~ .\#* c/.*~ c/.\#* sg/*~ sg/.*~ sg/.\#* foo bar afr.*

# zxcot -n -g http://federation.njedge.net/metadata/njedge-fed-metadata.xml

dist zxid-$(ZXIDREL).tgz:
	rm -rf zxid-$(ZXIDREL)
	mkdir zxid-$(ZXIDREL) zxid-$(ZXIDREL)/c zxid-$(ZXIDREL)/sg zxid-$(ZXIDREL)/t zxid-$(ZXIDREL)/tex  zxid-$(ZXIDREL)/html zxid-$(ZXIDREL)/pulver zxid-$(ZXIDREL)/Net zxid-$(ZXIDREL)/Metadata zxid-$(ZXIDREL)/Raw zxid-$(ZXIDREL)/WSC zxid-$(ZXIDREL)/WSF_Raw zxid-$(ZXIDREL)/php zxid-$(ZXIDREL)/zxidjava zxid-$(ZXIDREL)/servlet zxid-$(ZXIDREL)/servlet/WEB-INF zxid-$(ZXIDREL)/servlet/META-INF zxid-$(ZXIDREL)/default-cot zxid-$(ZXIDREL)/py zxid-$(ZXIDREL)/ruby zxid-$(ZXIDREL)/csharp zxid-$(ZXIDREL)/precheck zxid-$(ZXIDREL)/pers zxid-$(ZXIDREL)/intra zxid-$(ZXIDREL)/protected zxid-$(ZXIDREL)/strong zxid-$(ZXIDREL)/other
	(cd zxid-$(ZXIDREL); ln -s . zx)
	$(PERL) mkdist.pl zxid-$(ZXIDREL) <Manifest
	tar czf zxid-$(ZXIDREL).tgz zxid-$(ZXIDREL)

linbindist:
	rm -rf zxid-$(ZXIDREL)-ix86-linux-bin
	mkdir zxid-$(ZXIDREL)-ix86-linux-bin zxid-$(ZXIDREL)-ix86-linux-bin/c zxid-$(ZXIDREL)-ix86-linux-bin/sg zxid-$(ZXIDREL)-ix86-linux-bin/t  zxid-$(ZXIDREL)-ix86-linux-bin/tex  zxid-$(ZXIDREL)-ix86-linux-bin/html zxid-$(ZXIDREL)-ix86-linux-bin/pulver zxid-$(ZXIDREL)-ix86-linux-bin/Net zxid-$(ZXIDREL)-ix86-linux-bin/Metadata zxid-$(ZXIDREL)-ix86-linux-bin/Raw zxid-$(ZXIDREL)-ix86-linux-bin/WSC zxid-$(ZXIDREL)-ix86-linux-bin/WSF_Raw zxid-$(ZXIDREL)-ix86-linux-bin/php zxid-$(ZXIDREL)-ix86-linux-bin/zxidjava zxid-$(ZXIDREL)-ix86-linux-bin/servlet zxid-$(ZXIDREL)-ix86-linux-bin/servlet/WEB-INF
	(cd zxid-$(ZXIDREL)-ix86-linux-bin; ln -s . zx)
	$(PERL) mkdist.pl zxid-$(ZXIDREL)-ix86-linux-bin <Manifest.bin
	tar czf zxid-$(ZXIDREL)-ix86-linux-bin.tgz zxid-$(ZXIDREL)-ix86-linux-bin

winbindist:
	rm -rf zxid-$(ZXIDREL)-win32-bin
	mkdir zxid-$(ZXIDREL)-win32-bin zxid-$(ZXIDREL)-win32-bin/c zxid-$(ZXIDREL)-win32-bin/zxidjava  zxid-$(ZXIDREL)-win32-bin/php
	cp zxid.dll zxidhlo zxidsimple zxididp zxcot zxpasswd zxdecode zxlogview smime *.a *.def *.h *.java *.class *.war zxid-$(ZXIDREL)-win32-bin
	cp zxidjava/*.class $(ZXIDJNI_SO) zxidjava/zxid_wrap.c zxid-$(ZXIDREL)-win32-bin/zxidjava
	cp COPYING LICENSE-2.0.txt LICENSE.openssl LICENSE.ssleay README.zxid README.zxid-win32 zxid-$(ZXIDREL)-win32-bin
	cp c/*.h zxid-$(ZXIDREL)-win32-bin/c
	zip -r zxid-$(ZXIDREL)-win32-bin.zip zxid-$(ZXIDREL)-win32-bin

#	cp *.php mod_auth_saml.dll zxid-$(ZXIDREL)-win32-bin
#	cp php/*.php php/php_zxid.dll  zxid-$(ZXIDREL)-win32-bin/php


# To create release
#   make cleaner          # remember c/zxidvers.h
#   make dep ENA_GEN=1
#   make all ENA_GEN=1
#   make doc
#     pd2tex README.zxid
#     pd2tex index.pd
#     pd2tex apache.pd
#     pd2tex mod_auth_saml.pd
#   make dist
#   make copydist
#   make release
#   make relhtml
#   make clean
#   make TARGET=xmingw
#   make zxid.dll TARGET=xmingw
#   make winbindist
#   make winbinrel
#   make tas3rel
#   make tas3copyrel    # tas3pool -u T3-ZXID-LINUX-X86_0.54.zip
#   make gen ENA_GEN=1
# zxid.user@lists.unh.edu

copydist:
	scp zxid-$(ZXIDREL).tgz sampo@zxid.org:zxid.org

tex/%.pdf: %.pd
	pd2tex -noref -nortf -nodbx -nohtml $<

html/%.html: %.pd doc-inc.pd doc-end.pd
	pd2tex -noref -nortf -nodbx -notex $<

tex/README.zxid.pdf: README.zxid
	pd2tex -noref -nortf -nodbx -nohtml $<

html/README.zxid.html: README.zxid doc-inc.pd doc-end.pd
	pd2tex -noref -nortf -nodbx -notex README.zxid

DOC= html/README.zxid.html html/index.html html/apache.html html/mod_auth_saml.html html/zxid-simple.html html/zxid-install.html html/zxid-conf.html html/zxid-cot.html html/zxid-java.html html/zxid-log.html html/zxid-perl.html html/zxid-php.html html/zxid-raw.html html/zxid-wsf.html html/zxid-idp.html html/zxid-faq.html html/schemata.html

doc: $(DOC)

docpdf: $(DOC:html/%.html=tex/%.pdf)

cleandoc:
	rm -f $(DOC)

release:
	scp tex/README.zxid.pdf html/README.zxid-win32.html html/i-*.png zxid-frame.html sampo@zxid.org:zxid.org

winbinrel:
	scp zxid-$(ZXIDREL)-win32-bin.zip sampo@zxid.org:zxid.org

indexrel: html/index.html
	scp $< sampo@zxid.org:zxid.org

reldoc:
	scp $(DOC) sampo@zxid.org:zxid.org/html

relhtml:
	scp html/* sampo@zxid.org:zxid.org/html

refhtml:
	scp ref/html/* sampo@zxid.org:zxid.org/ref/html

zxidpcopytc: html/zxidp-user-terms.html html/zxidp-sp-terms.html
	scp html/zxidp-user-terms.html html/zxidp-sp-terms.html root@zxidp.org:/var/zxid/webroot/html

rsynclite:
	cd ..; rsync -a '--exclude=*.o' '--exclude=*.zip' '--exclude=TAGS' '--exclude=*.tgz' '--exclude=*.class' '--exclude=*.so' '--exclude=*.a'  '--exclude=zxlogview' '--exclude=zxidsimple'  '--exclude=zxidhlowsf'  '--exclude=zxidhlo' '--exclude=zxidsp' zxid mesozoic.homeip.net:

cvstag:
	cvs tag ZXID_ZXIDREL_$(ZXIDVERSION)

### Coverage analysis

gcov:
	@$(ECHO) "Remember to compile for profiling: make ENA_PG=1 && make gcov"
	gcov *.c */*.c

# gcov /a/d/sampo/zxid/zxidconf.gcda -o /a/d/sampo/zxid -b -c -a -p

covrep:
	echo "*** This rule seems broken"
	grep '#####:' *.c.gcov */*.c.gcov >uncovered.gcov
	total=`cat *.c.gcov */*.c.gcov | wc -l`
	inactive=`grep -e '-:' *.c.gcov */*.c.gcov | wc -l`
	uncov=`cat uncovered.gcov | wc -l`
	active=`expr $total - $inactive`
	percent=`expr $uncov \* 100 / $active`
	printf "Total source lines: %d, Active: %d, Not covered: %d (%.2f%%)\n" $total $active $uncov $percent

lcov:
	rm -rf lcovhtml; mkdir lcovhtml
	lcov -d . -c -no-checksum -o lcovhtml/zxid.info
	genhtml -t 'ZXID Code Coverage' -o lcovhtml lcovhtml/zxid.info

cleangcov:
	rm -f *.gcno *.gcda *.c.gcov *.y.gcov *.c-ann gmon.out
	rm -f */*.gcno */*.gcda */*.c.gcov */*.y.gcov */*.c-ann */gmon.out
	rm -f lcovhtml/zxid.info lcovhtml/zxid/*.html lcovhtml/zxid/c/*.html

### Call graphs and reference documentation

function.list: 
	$(PERL) ./call-anal.pl -n *.c >/dev/null

callgraph_annotate: 
	$(PERL) ./call-anal.pl *.c >callgraph.dot

callgraph: 
	$(PERL) ./call-anal.pl -n *.c >callgraph.dot
	dot -Tps main-call.dot -o main-call.ps
	dot -Tps callgraph.dot -o callgraph.ps  # slow

API_REF_SRC=aux-templ.c dec-templ.c enc-templ.c getput-templ.c \
 mod_auth_saml.c \
 zxcrypto.c zxida7n.c zxidcdc.c zxidcgi.c zxidconf.c zxidcurl.c \
 zxidecp.c zxidepr.c zxidlib.c zxidloc.c \
 zxidmeta.c zxidmk.c zxidmkwsf.c zxidmni.c zxidpep.c \
 zxidses.c zxidsimp.c zxidpool.c zxidslo.c zxidspx.c zxididpx.c zxiddec.c \
 zxidsso.c zxidpsso.c zxiddi.c \
 zxiduser.c zxidwsc.c zxidwsp.c \
 zxlib.c zxlog.c zxlogview.c zxns.c zxsig.c zxutil.c

refcall:
	$(PERL) ./call-anal.pl -n $(API_REF_SRC) >callgraph.dot

reference: refcall
	cd ref; pd2tex -noref -nortf -nodbx ref.pd
	cd ref/tex; pdflatex -file-line-error-style -interaction=errorstopmode ../ref.tex # Thrice so refs and index are right
	cd ref/tex #; pdflatex -file-line-error-style -interaction=errorstopmode ../ref.tex # Thrice so refs and index are right

ifeq ($(PULVER),1)

dep: $(PULVER_DEPS)
	rm -f deps.dep
	$(MAKE) deps.dep

deps: $(ZXID_OBJ:.o=.c) zxdecode.c zxcot.c zxpasswd.c zxidhlo.c zxidsimple.c $(ZX_OBJ:.o=.c) c/saml2-const.h c/saml2md-const.h c/wsf-const.h $(PULVER_DEPS) c/zxidvers.h
	@$(ECHO) ================== Making deps
	cat pulver/c_saml2_dec_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2_enc_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2_aux_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2_getput_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2md_dec_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2md_enc_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2md_aux_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	cat pulver/c_saml2md_getput_c.deps | xargs $(CC) $(CDEF) $(CDIR) -MM >>deps.dep
	$(CC) $(CDEF) $(CDIR) -MM $(ZXID_OBJ:.o=.c) zxdecode.c zxcot.c zxpasswd.c zxidhlo.c zxidsimple.c c/saml2-const.h c/saml2md-const.h >>deps.dep

#	$(ECHO) Deps built. $(foreach fil,$^,$(shell $(fil) >>deps.dep))

else

dep: deps

deps: $(ZXID_OBJ:.o=.c) $(WSF_OBJ:.o=.c) zxdecode.c zxcot.c zxpasswd.c zxidhlo.c zxidsp.c zxidsimple.c $(ZX_OBJ:.o=.c) $(ZX_GEN_H) $(ZX_GEN_C) c/zx-const.h c/zxidvers.h
	$(CC) $(CDEF) $(CDIR) -MM $^ >deps.dep

# make gen ENA_GEN=1

endif

# N.B. If deps target and the actual deps.dep file have same name,
# the deps target will be made every time deps is missing - even
# when attempting to run `make clean'

-include deps.dep

seehelp:
	@$(ECHO) "If you get compilation errors, try: make help"
	@$(ECHO) "Now trying to compile series of test programs to check dependencies..."
	@$(ECHO)

help:
	@$(ECHO) "ZXID $(ZXIDREL) make help (see zxid.org for further information)"
	@$(ECHO)
	@$(ECHO) "N.B.  There is no configure script. The Makefile works for all"
	@$(ECHO) "      supported platforms by provision of correct TARGET option."
	@$(ECHO) "N.B2: We distribute some generated files. If they are missing, you need"
	@$(ECHO) "      to regenerate them: make cleaner; make dep ENA_GEN=1"
	@$(ECHO)
	@$(ECHO) "To compile for Linux 2.6: make"
	@$(ECHO) "To compile for MacOS 10:  make TARGET=macosx"
	@$(ECHO) "To compile for Solaris 8: make TARGET=sol8"
	@$(ECHO) "To compile for Sparc Solaris 8 with cross compiler:"
	@$(ECHO) '  PATH=/apps/gcc/sol8/bin:/apps/binutils/sol8/bin:$$PATH make TARGET=xsol8'
	@$(ECHO)
	@$(ECHO) "If you get compilation or linking errors about missing this or that,"
	@$(ECHO) "the chances are that you need to override some make variables with"
	@$(ECHO) "paths that make sense in your local situation. The best way is to"
	@$(ECHO) "first study the Makefile and then add your overrides to localconf.mk"
	@$(ECHO) "or on make command line. Some of the most common ones:"
	@$(ECHO) "  CDEF          Additional -D flags needed on your platform"
	@$(ECHO) "  CDIR          Additional -I flags needed on your platform"
	@$(ECHO) "  LIBS          Additional -L and -l flags needed on your platform"
	@$(ECHO) "  CURL_ROOT     Where libcurl and its headers are installed"
	@$(ECHO) "  OPENSSL_ROOT  Where OpenSSL and its headers are installed"
	@$(ECHO) "  JAVAC         Where to find javac; where jdk is installed"
	@$(ECHO) "  JNI_INC       Where jni.h and jni_md.h are found"
	@$(ECHO) "  SERVLET_PATH  Where servlet-api.jar is found; where Tomcat is installed."
	@$(ECHO) "  SHARED        Set to 1 for shared object (DLL) build. Default: static."
	@$(ECHO)
	@$(ECHO) "Following make targets are available:"
	@$(ECHO)
	@egrep '^[a-z-]+:' Makefile

#EOF
