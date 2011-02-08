#!/usr/bin/perl
# Copyright (c) 2010-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id$
#
# 9.2.2011, adapted from zximport-htpasswd.pl --Sampo
#
# Commandline for importing .htpasswd file to /var/zxid/idpuid

$usage = <<USAGE;
Commandline for importing LDIF file to /var/zxid/idpuid
Usage: ./zximport-ldif.pl <foo.ldif
USAGE
    ;
die $USAGE if $ARGV[0] =~ /^-[Hh?]/;

#$dir = '/tmp/idpuid';
$dir = '/var/zxid/idpuid';

$uidn = 1;

use Data::Dumper;

sub writeall {
    my ($f,$d) = @_;
    open F, ">$f" or die "Cant write($f): $!";
    binmode F;
    flock F, 2;    # Exclusive
    print F $d;
    flock F, 8;    
    close F;
}

sub mkuser {
    my ($uid, $pw, $at) = @_;
    chomp $crypt;
    mkdir "$dir/$uid" or die "Cant mkdir $dir/$uid: $!";
    mkdir "$dir/$uid/.bs" or die "Cant mkdir $dir/$uid/.bs: $!";
    mkdir "$dir/$uid/.ykspent" or die "Cant mkdir $dir/$uid/.ykspent: $!";
    writeall("$dir/$uid/.pw", $pw);
    writeall("$dir/$uid/.bs/.at", $at);
}


undef $/;
$x = <STDIN>;
@recs = split /\r?\n\r?\n/, $x;
for $rec (@recs) {
    next if $rec =~ /^\s*$/;
    warn "REC1($rec)";
    $idpnid = $uid = $pw = '';
    $rec =~ s/^dn: .*?\r?\n//m;
    ($idpnid) = $rec =~ /^idpnid: (.*?)$/m;
    $rec =~ s/^idpnid: .*?\r?\n//m;
    ($uid) = $rec =~ /^uid: (.*?)$/m;
    $rec =~ s/^uid: .*?\r?\n//m;
    ($pw) = $rec =~ /^password: (.*?)$/m;
    $rec =~ s/^password: .*?\r?\n//m;
    ($cn) = $rec =~ /^cn: (.*?)$/m;
    $rec =~ s/^cn: .*?\r?\n//m;
    $rec =~ s/^urn:oasis:names:tc:xacml:1.0:subject:subject-id: .*?\r?\n//m;
    warn "REC2($rec) idpnid($idpnid) uid($uid) pw($pw) cn($cn)";
    $uid ||= "user".$uidn++;
    $pw  ||= "tas123";
    $cn  ||= "Mr. $uid";
    warn "REC3($rec) idpnid($idpnid) uid($uid) pw($pw) cn($cn)";
    mkuser($uid, $pw, "cn: $cn\n$rec\n");
    # if ($idpnid) *** too complicated as this depends on SP as well
}

__END__
