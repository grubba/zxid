#!/usr/bin/perl
# Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing. See file COPYING.
# $Id: gen-consts-from-gperf-output.pl,v 1.5 2009-08-30 15:09:26 sampo Exp $
# 28.5.2006, created --Sampo
#
# Digest gperf generated hash tables and generate corresponding constants
# Usage: cat gperf-gen*.c | ./gen-consts-from-gperf-output.pl PREFIX SUFFIX table tab ... >const.h

undef $/;
$x = <STDIN>;

$prefix = shift;
$suffix = shift;

print "/* generated file, do not edit! $prefix $suffix\n * \$Id\$ */\n";
print "#ifndef _$prefix$suffix\n";
print "#define _$prefix$suffix\n";

for ($i = 0; $i <= $#ARGV; ++$i) {
    ($y) = $x =~ /struct zx_tok $ARGV[$i]\[\] =\s+\{\s+(.*?)\s+\};/s;
    $y =~ s/\#line \d+ ".*?"\n//gs;
    $y =~ s/^\s*\{//s;
    $y =~ s/\}$//s;
    #warn "$i: ($ARGV[$i]) got($y)";
    @a = split /\},\s+\{/s, $y;
    $j = 0;
    for $z (@a) {
	($name, $ns) = $z =~ /^"(.*?)",\s+"(.*?)"(,\s+[A-Za-z0-9_]+(\s*\+\s*[A-Za-z0-9_]+)?)?$/;
	$ns .= '_' if $ns;
	print "#define $prefix${ns}${name}$suffix\t$j\n";
	++$j;
    }
    print "#define ${prefix}${suffix}_MAX\t$j\n";
}
print "#endif\n";
#EOF
