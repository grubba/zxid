#!/usr/bin/perl
# Copyright (c) 2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id: zxidhlo.pl,v 1.7 2009-11-14 22:44:43 sampo Exp $
#
# Audit daemon. Read from various logs and print to audit event log --Sampo
#
# 4.4.2011, reated --Sampo

use Net::SAML;
use Data::Dumper;

$dir = '/home/sampo/zxid/postoffice/conf/';

$| = 1;

#open STDERR, ">>/tmp/audit.err";   # Helps CGI debugging where web server eats the stderr

open EVS, ">>${dir}log/audit.evs" or die "Failed to open ${dir}log/audit.evs for writing: $!";

open IDP, "<${dir}idplog/act" or die "Failed to open ${dir}idplog/act for reading: $!";
seek IDP,0,2;

seek EVS,0,2;
while (1) {
    warn "read";
    $line = <IDP>;
    print EVS "$line<br>";
    sleep 1;
}

exit;

__END__
