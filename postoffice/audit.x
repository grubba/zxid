#!/usr/bin/perl
# Copyright (c) 2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id: zxidhlo.pl,v 1.7 2009-11-14 22:44:43 sampo Exp $
# 16.1.2007, created --Sampo
# 14.11.2009, Added zxid_az() example --Sampo

use Net::SAML;
use Data::Dumper;

$dir = '/home/sampo/zxid/postoffice/conf/';

$| = 1;

open STDERR, ">>/tmp/audit.err";   # Helps CGI debugging where web server eats the stderr

sub uridec {
    my ($val) = @_;
    $val =~ s/\+/ /g;
    $val =~ s/%([0-9a-f]{2})/chr(hex($1))/gsexi;  # URI decode
    return $val;
}

sub cgidec {
    my ($d) = @_;
    for my $nv (split '&', $d) {
	my ($n, $v) = split '=', $nv, 2;
	$cgi{$n} = uridec($v);
    }
}

$conf = "PATH=/home/sampo/zxid/postoffice/conf/&URL=https://idp.postoffice.co.uk/audit.x&NICE_NAME=Audit Dashboard by Post Office&ORG_NAME=Post Office&ORG_URL=http://postoffice.co.uk/&IDP_SEL_TEMPL_FILE=audit-idpsel.html";
$cf = Net::SAML::new_conf_to_cf($conf);
$qs = $ENV{'QUERY_STRING'};
$qs = <STDIN> if $qs =~ /o=P/;
cgidec($qs);
$res = Net::SAML::simple_cf($cf, -1, $qs, undef, 0x1fff);
$op = substr($res, 0, 1);

# *** add code to parse the LDIF in $res into a hash of attributes

($sid) = $res =~ /^sesid: (.*)$/m;

if (Net::SAML::az_cf($cf, "Action=Show", $sid)) {
    $az = "Permit.\n";
} else {
    $az = "<b>Deny.</b> Normally page would not be shown, but we show session attributes for debugging purposes.\n";
}

print <<HTML
CONTENT-TYPE: text/html

<title>Audit Dashboard</title>
<link type="text/css" rel=stylesheet href="an.css">
<link rel="shortcut icon" href="/favicon.ico" type="image/x-icon" />
<body bgcolor=white>
<h1 class=zxtop>Audit Dashboard (user logged in, session active)</h1>
<img align=right src="post_logo.gif">

$az
sesid: $sid
HTML
    ;

open EVS, "<${dir}log/audit.evs"
    or print "<div class=zxerr>Failed to open ${dir}log/audit.evs ($!)</div>";

if ($cgi{'tail'}) {
    print <<HTML;
<h3>Monitor</h3>
<form method=post>
<input type=hidden name=s value="$sid">
<input type=submit name=stop value=" Stop ">
</form>
<hr>
HTML
    ;
    seek EVS,0,2;
    while (1) {
	warn "read loop";
	$line = <EVS>;
	print $line;
	sleep 1;
    }
} else {
    seek EVS,-2048,2;
    @lines = <EVS>;
    print <<HTML;
<h3>Last 10 Events</h3>
<form method=post>
<input type=hidden name=s value="$sid">
<input type=submit name=tail value=" Monitor ">
</form>
<hr>
HTML
;
    for ($i = $#lines-10; $i < $#lines; ++$i) {
	print $lines[$i];
    }
}
print Net::SAML::fed_mgmt_cf($cf, undef, -1, $sid, 0x1900);

print <<HTML
<a href="#" onClick="vis('techopt',1);">Show Technical Options</a>
<div id=techopt>
<h3>Technical options</h3>
<textarea cols=100 rows=10>
$res
</textarea><br>
<a href="#" onClick="vis('techopt',0);">Hide Technical Options</a>
</div>
<img align=right src="synergetics_logo.png">
<br clear=right>
<div class=zxbot><a class=zx href="/index.html">Demo Index</a> | <a class=zx href="http://synergetics.be/">Synergetics</a></div>

<script language="javascript" type="text/javascript"><!--
function vis(el, state) { document.getElementById(el).style.display=state?"block":"none"; }
vis("techopt",0);
//--></script>
HTML
    ;

exit;

__END__
