# File : zxid/Net/Makefile.PL
# $Id: Makefile.PL,v 1.3 2009-09-07 16:13:02 sampo Exp $
use ExtUtils::MakeMaker;
WriteMakefile(
  NAME    => "Net::SAML",
  INC     => '-I.. -I/apps/openssl/std/include -I/apps/include',
  LIBS    => ["-L.. -L/apps/openssl/std/lib -L/apps/lib -lzxid -lcrypto -lcurl -ldl -lz"],
  OBJECT  => "SAML_wrap.o"
);
