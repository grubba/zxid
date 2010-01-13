#!/usr/bin/perl
# 4.9.2009, Sampo Kellomaki (sampo@iki.fi)
# $Id: xml-pretty.pl,v 1.1 2009-09-05 02:23:41 sampo Exp $
#
# Pretty Print XML  --  Make XML almost human readable
#
# Usage: cat foo.saml | ./zxdecode | ./xml-pretty.pl

use XML::Simple;
use Data::Dumper;

undef $/;
$xml = <STDIN>;
$xx = XMLin $xml, ForceArray=>1, KeepRoot=>1;  # , KeyAttr => [ 'id', 'name' ]

#print Dumper $xx;
print XMLout $xx, AttrIndent=>1, KeepRoot=>1;  # , NoSort=>1

__END__
