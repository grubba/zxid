#!/usr/bin/perl
# Copyright (c) 2010-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id$
#
# 8.3.2010, created --Sampo
#
# Web GUI for creating new user, possibly in middle of login sequence.
# The AuthnRequest is preserved through new user creation by passing ar.

$usage = <<USAGE;
Web GUI for creating new user, possibly in middle of login sequence.
Usage: http://localhost:8081/zxidnewuser.pl?QUERY_STRING
       ./zxidatsel.pl -a QUERY_STRING
         -a Ascii mode
USAGE
    ;
die $USAGE if $ARGV[0] =~ /^-[Hh?]/;

#$dir = '/var/zxid/idp';
$dir = '/home/sampo/zxid/postoffice/conf/idp';

use Data::Dumper;

close STDERR;
open STDERR, ">>/var/tmp/zxid.stderr" or die "Cant open error log: $!";
select STDERR; $|=1; select STDOUT;

#warn "$$: START env: " . Dumper(\%ENV);

$ENV{QUERY_STRING} ||= shift;
cgidec($ENV{QUERY_STRING});

if ($ENV{CONTENT_LENGTH}) {
    sysread STDIN, $data, $ENV{CONTENT_LENGTH};
    #warn "GOT($data) $ENV{CONTENT_LENGTH}";
    cgidec($data);
}
warn "$$: cgi: " . Dumper(\%cgi);

sub uridec {
    my ($val) = @_;
    $val =~ s/\+/ /g;
    $val =~ s/%([0-9a-f]{2})/chr(hex($1))/gsexi;  # URI decode
    return $val;
}

sub urienc {
    my ($val) = @_;
    $val =~ s/([^A-Za-z0-9.,_-])/sprintf("%%%02x",ord($1))/gsex; # URI enc
    return $val;
}

sub cgidec {
    my ($d) = @_;
    for $nv (split '&', $d) {
	($n, $v) = split '=', $nv, 2;
	$cgi{$n} = uridec($v);
    }
}

sub readall {
    my ($f) = @_;
    my ($pkg, $srcfile, $line) = caller;
    undef $/;         # Read all in, without breaking on lines
    open F, "<$f" or die "$srcfile:$line: Cant read($f): $!";
    binmode F;
    my $x = <F>;
    close F;
    return $x;
}

sub show_templ {
    my ($templ, $hr) = @_;
    $templ = readall($templ);
    $templ =~ s/!!(\w+)/$$hr{$1}/gs;
    my $len = length $templ;
    syswrite STDOUT, "Content-Type: text/html\r\nContent-Length: $len\r\n\r\n$templ";
    exit;
}

sub redirect {
    my ($url) = @_;
    syswrite STDOUT, "Location: $url\r\n\r\n";
    exit;
}

### MAIN

if (length $cgi{'ok'}) {
    if (length $cgi{'au'} < 3 || length $cgi{'au'} > 40) {
	$cgi{'ERR'} = "Username must be at least 3 characters long (and no longer than 40 chars).";
    } elsif ($cgi{'au'} !~ /^[A-Za-z0-9_-]+$/s) {
	$cgi{'ERR'} = "Username can only contain characters [A-Za-z0-9_-]";
    } elsif (length $cgi{'ap'} < 5 || length $cgi{'ap'} > 80) {
	$cgi{'ERR'} = "Password must be at least 5 characters long (and no longer than 80 chars).";
    } elsif (-e "${dir}uid/$cgi{'au'}") {
	$cgi{'ERR'} = "Username already taken.";
    } else {
	warn "Creating new user($cgi{'au'})";
	open P, "|./zxpasswd -c $cgi{'au'}" or die "Cant open pipe to zxpasswd: $! $? $*";
	print P $cgi{'ap'};
	close P;
	warn "Populating user($cgi{'au'})";
	if (-e "${dir}uid/$cgi{'au'}") {
	    open LOG, ">${dir}uid/$cgi{'au'}/.log" or die "Cant open write .log: $!";
	    print LOG "Created ip=$ENV{REMOTE_ADDR}\n" or die "Cant write .log: $!";
	    close LOG or die "Cant close write .log: $!";

	    open IP, ">${dir}uid/$cgi{'au'}/.regip" or die "Cant open write .regip: $!";
	    print IP $ENV{REMOTE_ADDR} or die "Cant write .regip: $!";
	    close IP or die "Cant close write .regip: $!";

	    #mkdir "${dir}uid/$cgi{'au'}/.bs" or warn "Cant mkdir .bs: $!"; zxpasswd creates .bs
	    open AT, ">${dir}uid/$cgi{'au'}/.bs/.at" or die "Cant write .bs/.at: $!";
	    open OPTAT, ">${dir}uid/$cgi{'au'}/.bs/.optat" or die "Cant write .bs/.optat: $!";
	    
	    for $at (qw(cn title taxno o ou street citystc email im tel lang tag)) {
		$val = $cgi{$at};
		$val =~ s/[\r\n]//g;
		next if !length $val;
		if ($cgi{"${at}share"}) {
		    print AT "$at: $val\n";
		} else {
		    print OPTAT "$at: $val\n";
		}
	    }
	    
	    close AT;
	    close OPTAT;

	    if ($cgi{'zxidpurl'} && $cgi{'zxrfr'} && $cgi{'ar'}) {
		warn "Created user($cgi{'au'}). Redirecting back to IdP";
		redirect("$cgi{'zxidpurl'}?o=$cgi{'zxrfr'}&ar=$cgi{'ar'}");
	    } else {
		warn "Created user($cgi{'au'}). Redirecting back to index page.";
		redirect("/");
	    }
	} else {
	    $cgi{'ERR'} = "User creation failed. System error (${dir}uid/$cgi{'au'}).";
	}
    }
}

$cgi{'ip'} = $ENV{REMOTE_ADDR};
show_templ("newuser-main.html", \%cgi);

__END__
