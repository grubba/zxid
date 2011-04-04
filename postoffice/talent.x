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

$| = 1;
undef $/;

open STDERR, ">>/tmp/talent.err";   # Helps CGI debugging where web server eats the stderr

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

$conf = "PATH=/home/sampo/zxid/postoffice/conf/&URL=https://talent.workjobs.co.uk/talent.x&NICE_NAME=Work Jobs Talent Management&ORG_NAME=Work Jobs&ORG_URL=http://synergetics.be/&IDP_SEL_TEMPL_FILE=talent-idpsel.html";
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

<title>Work Jobs Talent Manager</title>
<link type="text/css" rel=stylesheet href="talent.css">
<link rel="shortcut icon" href="/synergetics.ico" type="image/x-icon" />
<body bgcolor=white>
<h1 class=zxtop>Work Jobs Talent Management (user logged in, session active)</h1>
<img align=right src="synergetics_logo.png">

$az
sesid: $sid
HTML
    ;

if ($cgi{'cmp'}) {
print <<HTML
<h3>Talent Comparison to $cgi{'targetpos'}</h3>
<form method=post>
<input type=hidden name=s value="$sid">
<table>
<tr><th>Skill</th><th>$cgi{'targetpos'}</th><th>You</th><th>Suggested Actions</th></tr>
<tr><th>Java</th><td>Required</td><td>Yes</td><td>&nbsp</td></tr>
<tr><th>PHP</th><td>Required</td><td>No</td><td><a href="">Courses</a></td></tr>
<tr><th>Perl</th><td>Plus</td><td>No</td><td>&nbsp</td></tr>
<tr><th>C</th><td>-</td><td>Yes</td><td>&nbsp</td></tr>
<tr><th>C++</th><td>-</td><td>-</td><td>&nbsp</td></tr>
</table>
<input type=submit name=ok value=" OK ">
</form>
<hr>
HTML
    ;
} else {
print <<HTML
<h3>Choose Target for Talent Comparison</h3>
<form method=post>
<input type=hidden name=s value="$sid">
<select name=targetpos>
<option value="">(choose)
<option value="junior">Junior Developer
<option value="senior">Senior Developer
</select>
<input type=submit name=cmp value=" Compare to My Profile ">
</form>
<hr>
HTML
    ;
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
