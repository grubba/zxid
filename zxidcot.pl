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
#   e  $eid    Filter logs by Entity ID
#   n  $nid    Filter logs by Name ID
#   s  $sid    Filter logs by session ID

$usage = <<USAGE;
Web GUI for attribute selection and privacy preferences
Usage: http://localhost:8081/zxidatsel.pl?QUERY_STRING
       ./zxidatsel.pl -a QUERY_STRING
         -a Ascii mode
USAGE
    ;
die $USAGE if $ARGV[0] =~ /^-[Hh?]/;
$ascii = shift if $ARGV[0] eq '-a';

$dir = '/var/zxid/idp';

use Data::Dumper;

close STDERR;
open STDERR, ">>/var/tmp/zxid.stderr" or die "Cant open error log: $!";
select STDERR; $|=1; select STDOUT;

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

### Metadata

if ($cgi{'okmd'}) {
    system "./zxcot -e '$cgi{'endpoint'}' '$cgi{'abstract'}' '$cgi{'eid'}' '$cgi{'svctype'}' | ./zxcot -b /var/zxid/idpdimd/";
    redirect('/');
}

if ($cgi{'op'} eq 'md') {
    syswrite STDOUT, "Content-Type: text/html\r\n\r\n".<<HTML;
<title>ZXID IdP Circle of Trust Manager</title>
<link type="text/css" rel=stylesheet href="an.css">
<h1 class=zxtop>ZXID IdP Circle of Trust Manager</h1>

<h3>Metadata Registration</h3>

<form method=post xaction="zxidcot.pl">
Paste metadata here:<br>
<textarea name=mdxml cols=80 rows=10>
</textarea><br>
<input type=submit name="okmd" value="Submit Metadata">
</form>

<div class=zxbot>
<a class=zx href="http://zxid.org/">ZXID.org</a>
| <a class=zx href="http://www.tas3.eu/">TAS3.eu</a>
- <i></i>
</div>
HTML
    ;
    exit;
}

### Discovery Registration

if ($cgi{'okdireg'}) {
    warn "./zxcot -e '$cgi{'endpoint'}' '$cgi{'abstract'}' '$cgi{'eid'}' '$cgi{'svctype'}' | ./zxcot -b /var/zxid/idpdimd/";
    system "./zxcot -e '$cgi{'endpoint'}' '$cgi{'abstract'}' '$cgi{'eid'}' '$cgi{'svctype'}' | ./zxcot -b /var/zxid/idpdimd/";
    redirect('/');
}

if ($cgi{'op'} eq 'direg') {
    syswrite STDOUT, "Content-Type: text/html\r\n\r\n".<<HTML;
<title>ZXID IdP Circle of Trust Manager</title>
<link type="text/css" rel=stylesheet href="an.css">
<h1 class=zxtop>ZXID IdP Circle of Trust Manager</h1>

<h3>Discovery Registration</h3>

<form method=post xaction="zxidcot.pl">

<table>
<tr><th>Endpoint URL</th><td><input name=endpoint size=60></td></tr>
<tr><th>Abstract</th><td><input name=abstract size=60></td></tr>
<tr><th>Entity ID</th><td><input name=eid size=60></td></tr>
<tr><th>Service Type (URN)</th><td><input name=svctype size=60></td></tr>
</table>
<p><input type=submit name="okdireg" value="Submit Discovery Registration">
</form>

<div class=zxbot>
<a class=zx href="http://zxid.org/">ZXID.org</a>
| <a class=zx href="http://www.tas3.eu/">TAS3.eu</a>
- <i></i>
</div>
HTML
    ;
    exit;
}

show_templ("cot-main.html", $cgi);

__END__
