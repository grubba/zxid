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

open STDERR, ">>/tmp/pds.err";   # Helps CGI debugging where web server eats the stderr

$conf = "PATH=/home/sampo/zxid/postoffice/conf/&URL=https://pds.skillsfundingagency.bis.gov.uk/pds.x&NICE_NAME=Skills Funding Agency PDS&ORG_NAME=Skills Funding Agency&ORG_URL=http://synergetics.be/&IDP_SEL_TEMPL_FILE=pds-idpsel.html";
$cf = Net::SAML::new_conf_to_cf($conf);
$qs = $ENV{'QUERY_STRING'};
$qs = <STDIN> if $qs =~ /o=P/;
$res = Net::SAML::simple_cf($cf, -1, $qs, undef, 0x1fff);
$op = substr($res, 0, 1);

# *** add code to parse the LDIF in $res into a hash of attributes

($sid) = $res =~ /^sesid: (.*)$/m;

if (Net::SAML::az_cf($cf, "Action=Show", $sid)) {
    $az = "Permit.\n";
} else {
    $az = "<b>Deny.</b> Normally page would not be shown, but we show session attributes for debugging purposes.\n";
}

print <<HTML;
CONTENT-TYPE: text/html

<title>Skills Funding Agency PDS: Logged in</title>
<frameset frameborder=0 framespacing=0 border=0 rows="100%,*" noresize>
<frame name=c src="http://82.195.143.12:8080/synergetics_H50/allHoreca.html" noresize scrolling=auto>
</frameset>
<noframes>
<body>
No frames support.
Enter <a href="http://82.195.143.12:8080/synergetics_H50/allHoreca.html">here</a>
or <a href="http://82.195.143.12:8080/synergetics.html">here</a>
</body>
</noframes>
HTML
    ;

warn "HERE99";
exit;

__END__

<link type="text/css" rel=stylesheet href="pds.css">
<link rel="shortcut icon" href="/synergetics.ico" type="image/x-icon" />

print <<HTML
CONTENT-TYPE: text/html

<title>Skills Funding Agency PDS</title>
<link type="text/css" rel=stylesheet href="pds.css">
<link rel="shortcut icon" href="/synergetics.ico" type="image/x-icon" />
<body bgcolor=white>
<h1 class=zxtop>Worka Jobs Talent Management (user logged in, session active)</h1>
<img align=right src="synergetics_logo.png">

$az
sesid: $sid
HTML
    ;
print Net::SAML::fed_mgmt_cf($cf, undef, -1, $sid, 0x1900);

print <<HTML
<a href="#" onClick="vis('techopt',1);">Show Technical Options</a>
<div id=techopt>
<h3>Technical options</h3>
<textarea>
$res
</textarea><br>
<a href="#" onClick="vis('techopt',0);">Hide Technical Options</a>
</div>
<br clear=right>
<div class=zxbot><a class=zx href="http://synergetics.be/">Synergetics</a></div>

<script language="javascript" type="text/javascript"><!--
function vis(el, state) { document.getElementById(el).style.display=state?"block":"none"; }
vis("techopt",0);
//--></script>
HTML
    ;
