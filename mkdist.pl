#!/usr/bin/perl
# Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing. See file COPYING.
# $Id: mkdist.pl,v 1.4 2009-08-30 15:09:26 sampo Exp $
# 22.9.2006, created --Sampo

$dir = shift;

sub copy_file {
    my ($file) = @_;
    #system "/apps/bin/git add $file"; return;
    if (open F, "<$file") {
	open D, ">$dir/$file" or die "Cant write($dir/$file): $!";
	while ($x = <F>) {
	    print D $x;
	}
	close D;
	close F;
    } else {
	warn "Difficulties with file($file): $!";
    }
    #system 'cp', $file, $dir;
}

while ($_ = <STDIN>) {
    next if /^\s*\#/;
    ($file) = /^(\S+)/;
    next if !$file;
    if (substr($file, -1) eq ';') {   # Multiple filenames per line optimization
	for $file (split /;\s+/) {
	    copy_file($file);
	}
    } else {
	copy_file($file);
    }
}

#EOF
