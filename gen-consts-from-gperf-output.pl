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
    print "/* $i: $ARGV[$i] */\n";
    if ($suffix eq '_ELEM') {
	($ns) = $ARGV[$i] =~ /zx_([A-Za-z0-9]+)_/;
	$ns .= '_' if $ns;
    }
    #($y) = $x =~ /struct zx_[A-Za-z0-9_]+_tok $ARGV[$i]\[\] =\s+\{\s+(.*?)\s+\};/s;
    ($y) = $x =~ /struct\s+zx_[A-Za-z0-9_]+\s+$ARGV[$i]\[\] =\s+\{\s+(.*?)\s+\};/s;
    #warn "$i: $ARGV[$i] tab($y)";  # Output can be rather sizeable
    $y =~ s/\#line \d+ ".*?"\n//gs;
    $y =~ s/^\s*\{//s;
    $y =~ s/\}$//s;
    #warn "$i: ($ARGV[$i]) got($y)";
    @a = split /\},\s+\{/s, $y;
    $j = 0;
    for $z (@a) {
	if ($suffix eq '_NS') {
	    ($name) = $z =~ /^".*?",\s*[^,]+,\s*[^,]+,\s*"(.*?)",/;
	} else {
	    ($name) = $z =~ /^"(.*?)"/;
	}
	$name ||= "pad_$j";
	$name = "$prefix${ns}${name}$suffix";
	$k = 1;
	while ($name_used{$name}++) {
	    ++$k;
	    $name =~ s/(_\d+)?$/_$k/;
	}
	if ($suffix eq '_ELEM') {
	    printf "#define $name\t(zx_${ns}NS | 0x%06x)\n", $j;
	    die "Danger of exhaustation of ELEM space $name" if $j > 0x0000ff00;
	} elsif ($suffix eq '_NS') {
	    printf "#define $name\t0x%08x\n", $j << 16;
	    die "Danger of exhaustation of NS space $name" if $j >250;
	} else {
	    printf "#define $name\t0x%06x\n", $j;
	    die "Danger of exhaustation of ATTR space $name" if $j > 0x0000ff00;
	}
	++$j;
    }
    print "#define ${prefix}${ns}${suffix}_MAX\t$j\n";
}
print "#endif\n";
#EOF
