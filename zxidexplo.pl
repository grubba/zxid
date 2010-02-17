#!/usr/bin/perl
# Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id$
#
# 17.2.2010, created --Sampo
#
# Web GUI CGI for exploring ZXID logs and audit trail
#
# CGI / QUERY_STRING variables
#   c  $cmd    Command
#   d  $dir    Path to ZXID config directory, e.g: /var/zxid/ or /var/zxid/idp
#   e  $entid  Filter logs by Entity ID
#   n  $nid    Filter logs by Name ID
#   s  $sid    Filter logs by session ID

$usage = <<USAGE;
Web GUI CGI for exploring ZXID logs and audit trail
Usage: http://localhost:8081/zxidexplo.pl?QUERY_STRING
       ./zxidexplo.pl -a QUERY_STRING
         -a Ascii mode
USAGE
    ;

die $USAGE if $ARGV[0] =~ /^-[Hh?]/;
$ascii = shift if $ARGV[0] eq '-a';
syswrite STDOUT, "Content-Type: text/html\r\n\r\n" if !$ascii;

$ENV{QUERY_STRING} ||= shift;
$dir ||= '/var/zxid/';

print "<title>ZXID Log Explorer</title>\n<pre>\n";

open LOG, "./zxlogview ${dir}pem/logsign-nopw-cert.pem ${dir}pem/logenc-nopw-cert.pem <${dir}log/act|" or die "Cannot open log decoding pipe: $!";

while ($line = <LOG>) {

    # ----+ 104 PP - 20100217-151751.352 19700101-000000.501 -:- - - - -      zxcall N W GOTMD http://idp.tas3.eu/zxididp?o=B -
    ($pre, $len, $se, $sig, $ourts, $srcts, $ipport, $ent, $mid, $a7nid, $nid, $mm, $vvv, $res, $op, $para, @rest) = split /\s+/, $line;

    syswrite STDOUT, "$ourts $op\n";
}

close LOG;

syswrite STDOUT, "</pre>";

__END__
