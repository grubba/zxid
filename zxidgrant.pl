#!/usr/bin/perl
# Copyright (c) 2014 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id$
#
# 14.2.2014, created --Sampo
#
# Process a Grant Token (see zxid-idp.pd sec 4.5.6 Provisioning Using Grant Tokens)
#
# CGI / QUERY_STRING variables
#   c  $cmd    Command
#   g          Grant Token

$cpath = '/var/zxid/idp';

$usage = <<USAGE;
Web GUI for attribute selection and privacy preferences
Usage: http://localhost:8081/zxidgrant.pl?QUERY_STRING
       ./zxidgrant.pl -a QUERY_STRING
         -a Ascii mode
USAGE
    ;
die $usage if $ARGV[0] =~ /^-[Hh?]/;

use Net::SAML;
use Time::Local;
use Data::Dumper;

close STDERR;
open STDERR, ">>/var/tmp/zxid.stderr" or die "Cant open error log: $!";
select STDERR; $|=1; select STDOUT;

($sec,$min,$hour,$mday,$mon,$year) = gmtime(time);
$ts = sprintf "%04d%02d%02d-%02d%02d%02d", $year+1900, $mon+1, $mday, $hour, $min, $sec;
#warn "$$: START env: " . Dumper(\%ENV);

$ENV{QUERY_STRING} ||= shift;
$qs = $ENV{QUERY_STRING};
cgidec($qs);
($grant, undef, $ses_from_grant) = $cgi{'g'} =~ /^(.*?)(:s=(.*?))?$/;
$cgi{'s'} = $ses_from_grant if $ses_from_grant;

if ($ENV{CONTENT_LENGTH}) {
    sysread STDIN, $qs, $ENV{CONTENT_LENGTH};
    #warn "GOT($qs) $ENV{CONTENT_LENGTH}";
    cgidec($qs);
}

$confdata = readall("${cpath}zxid.conf",1);
($ses_cookie_name) = $confdata =~ /^SES_COOKIE_NAME=(.*)$/m;
$ses_cookie_name ||= 'ZXIDSES';
($ses_from_cookie) = $ENV{HTTP_COOKIE} =~ /$ses_cookie_name=([^; \t]+)/;

warn "$$ s-from-c($ses_from_cookie) cgi: " . Dumper(\%cgi);
$cf = Net::SAML::new_conf_to_cf("CPATH=$cpath");

### Due to circumstances, zxididp typically will not have set the cookie so we need to set it here

if (!$ses_from_cookie) {
    $ses_from_cookie = $cgi{'s'};
    $setcookie = "\r\nSet-Cookie: $ses_cookie_name=$ses_from_cookie";
}
if ($cgi{'s'}) {
    if ($cgi{'s'} ne $ses_from_cookie) {
	$cgi{'s'} = $ses_from_cookie;
	$setcookie = "\r\nSet-Cookie: $ses_cookie_name=$ses_from_cookie";
    }
} else {
    $cgi{'s'} = $ses_from_cookie;
    $setcookie = "\r\nSet-Cookie: $ses_cookie_name=$ses_from_cookie";
}

$sesdata = readall("${cpath}ses/$cgi{'s'}/.ses", 1);
$persona = readall("${cpath}ses/$cgi{'s'}/.persona", 1);
if (!length $sesdata) {
    $qs = $qs ? "$qs&" : "";
    $qs .= "o=F&redirafter=$ENV{SCRIPT_NAME}?g=$grant:s=X";
    warn "No session! Need to login($cgi{'s'}).  qs($qs)";
    $res = Net::SAML::simple_cf($cf, -1, $qs, undef, 0x3fff); # 0x1829
    cgidec($res);
    warn "$$: SSO done($res): " . Dumper(\%cgi);
    # *** figure out the IdP session
    $sesdata = readall("${cpath}ses/XXX/.ses",1);
    $persona = readall("${cpath}ses/XXX/.persona",1);
}
(undef, undef, undef, undef, $uid) = split /\|/, $sesdata;
warn "uid($uid) sesdata($sesdata)";

sub uridec {
    my ($val) = @_;
    $val =~ s/\+/ /g;
    $val =~ s/%([0-9a-f]{2})/chr(hex($1))/gsex;  # URI decode
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
    my ($f, $nofatal) = @_;
    my ($pkg, $srcfile, $line) = caller;
    undef $/;         # Read all in, without breaking on lines
    open F, "<$f" or do { if ($nofatal) { warn "$srcfile:$line: Cant read($f): $!"; return undef; } else { die "$srcfile:$line: Cant read($f): $!"; } };
    binmode F;
    my $x = <F>;
    close F;
    return $x;
}

### Safely add a line to log

sub append {
    my ($t,$line) = @_;
    my ($p,$f,$l)=caller;
    #warn "LOCK append_lock ($t at $f line $l)" if $locktrace;
    #lock $append_lock;  # Guard against file handle confusion
    if (open(T4, ">>$t")) {
        flock T4, 2; # Exclusive

        seek(T4, 0, 2);  # Go to absolute end of file (someone could have
                         # written to the file while we were waiting for
                         # flock)
        print T4 $line;
        flock T4, 8;
        close T4;
        return 1;
    } else {
        warn "$$: Cant append `$t' ($! at $f line $l)";
        return 0;
    }
}

#######################################################################
### Typical idiom for loops (not supported directly by bangbang)
###    <!--REPEAT-->
###    <b>!!EDITION</b>: Pub date !!DATE
###    <!--END_REPEAT-->
###
### $t = filex::slurp('edition.ht');
### $t =~ s/<!--REPEAT-->(.*)<!--END_REPEAT-->/!!REPEAT/s;
### $repeat = $1;
### for $ed (1425, 1426) {
###	my %s = (EDITION => $ed, DATE => $shortdate{$ed});
###	($x = $repeat) =~ s/!!(\w+)/$s{$1}/g;
###	$accu .= $x;
### }
### $subst{REPEAT} = $accu;
###
### Typical idiom for ifs (supported directly by bangbang)
###    <!--IF(NEW)-->
###      <h3>Yes</h3>
###    <!--ELSE(NEW)-->
###      <h3>Else</h3>
###    <!--FI(NEW)-->
###
### bangbang(\$p, \%subst);   # modifies template $p in place
###
### The conditions can contain ! (not), && (and), and || (or) boolean
### operators. Parenthesis are not supported. No whitespace should be
### inserted between variables and operators.

sub eval_cond {
    my ($cond, $sr) = @_;
    my ($a,$op,$b);
  or_loop: for my $and_clause (split /\|\|/, $cond) {  # split by or
	for my $var (split /&&/, $and_clause) {
	    if (($a,$op,$b) = $var =~ /^(\w+)([<>=!]+)(\w+)$/) {
		$a = $$sr{$a} if $a !~ /^\d+$/;
		$b = $$sr{$b} if $b !~ /^\d+$/;
		next or_loop if $op eq '==' && $a ne $b;   # short circuit fail
		next or_loop if $op eq '!=' && $a eq $b;
		next or_loop if $op eq '<'  && $a >= $b;
		next or_loop if $op eq '>'  && $a <= $b;
		next or_loop if $op eq '<=' && $a >  $b;
		next or_loop if $op eq '>=' && $a <  $b;
	    } else {
		if (substr($var,0,1)eq'!') {
		    next or_loop if $$sr{substr($var,1)};  # short circuit fail
		} else {
		    next or_loop if !$$sr{$var};           # short circuit fail
		}
	    }
	}
	return 1;  # true: all ANDs were ok --> short circuit success
    }
    return ();  # false: all ORs failed
}

sub bangbang {
    my ($pr, $sr) = @_;

    ### Early substitutions
    my $n = 0;
    $n++ while $n<5 && $$pr =~ s/!%!(\w+)/$$sr{$1}/g;
    warn "$n levels of early substitution" if $n>=3;

    #warn "=======>$$pr<=======";
    1 while  # Process as many times as possible, handles nested ifs
    #do { warn "===>$$pr<===\n\n\n " if $x eq 'po_a' } while  # Debug
    #warn "==>$$sr{$3}:$1:$2:$3<==\n" while  # Debug
    #                     1-cond          2-then  3-else
	$$pr =~ s/<!--IF\(([\w!|&=<>]+)\)-->(.*?)
	          (?:<!--ELSE\(\1\)-->(.*?))?
		  <!--FI\(\1\)-->
	       / eval_cond($1,$sr) ? $2 : $3 /gsex;
    
    $n = 0;
    #do { $n++; warn "\n===>$$pr<===\n " if $x eq 'A105-pt'; } while $$pr =~ s/!!(\w+)/$$sr{$1}/g;
    $n++ while $n<20 && $$pr =~ s/!!(\w+)/$$sr{$1}/g;  # Do any remaining substitutions as many times it takes
    warn "$n levels of variable substitution" if $n>=10;
}

### $accu .= filex::bang($templ, 'err here', A=>"b", C=>"d");

sub bangbang_templ {
    my ($templr, $hr) = @_;
    bangbang($templr, $hr);
    my $len = length $$templr;
    syswrite STDOUT, "Content-Type: text/html\r\nContent-Length: $len$setcookie\r\n\r\n$templr";
    exit;
}

sub show_templ {
    my ($templ, $hr) = @_;
    $templ = readall($templ);
    $templ =~ s/!!(\w+)/$$hr{$1}/gs;
    my $len = length $templ;
    syswrite STDOUT, "Content-Type: text/html\r\nContent-Length: $len$setcookie\r\n\r\n$templ";
    exit;
}

sub spend_grant {
    my ($why) = @_;
    rename "${cpath}grant/$grant" => "${cpath}grant/.spent/$grant";
    append("${cpath}grant/.spent/$grant", "zx_g_spend: grant=$grant, uid=$uid, ts=$ts");
}

###
### MAIN
###

sub show_grant {
    my ($uid) = @_;
    my $templ = readall("grant-main.html");
    $templ =~ s/<!--REPEAT_GRANT-->(.*)<!--END_REPEAT_GRANT-->/!!REPEAT_GRANT/s;
    my $repeat_grant = $1;
    $repeat_grant =~ s/<!--REPEAT_ATTR-->(.*)<!--END_REPEAT_ATTR-->/!!REPEAT_ATTR/s;
    my $repeat_attr = $1;
    
    my $grant_manifest = readall("${cpath}grant/$grant",1);
    if (!length $grant_manifest) {
	warn "Grant token not found or invalid link. (${cpath}grant/$grant)";
	$cgi{ERR} = "Grant token not found or invalid link. Perhaps the token has already been consumed?";
	bangbang_templ(\$templ, \$cgi);
    }
    
    my $grant_no = 0;
    my @grants = split /\n\n/, $grant_manifest;
    for $gr (@grants) {
	++$grant_no;
	my %gr = $gr =~ /^(.+?): (.*?)$/gm;
	warn "$grant_no: grant: " . Dumper(\%gr);
	if ($g{'zx_g_notbefore'}) {
	    ($yyyy, $mm, $dd, $hour, $min, $sec, $msec) = $gr{'zx_g_notbefore'}
	    =~ /^(\d\d\d\d)(\d\d)(\d\d)(?:-(\d\d)(?:(\d\d)(?:(\d\d)(?:\.(\d\d\d))?)?)?)?/;
	    $secs = timegm($sec, $min, $hour, $dd, $mon-1, $yyyy-1900);
	    if (time < $secs) {
		warn "$grant_no: Grant token can not be spent yet. notbefore_secs=$secs";
		$cgi{ERR} = "Grant token can not be spent yet.";
		bangbang_templ(\$templ, \$cgi);
	    }
	}
	if ($g{'zx_g_expires'}) {
	    ($yyyy, $mm, $dd, $hour, $min, $sec, $msec) = $gr{'zx_g_expires'}
	    =~ /^(\d\d\d\d)(\d\d)(\d\d)(?:-(\d\d)(?:(\d\d)(?:(\d\d)(?:\.(\d\d\d))?)?)?)?/;
	    $secs = timegm($sec, $min, $hour, $dd, $mon-1, $yyyy-1900);
	    if (time >= $secs) {
		spend_grant('expired');
		warn "$grant_no: Grant token has expired. expires_secs=$secs";
		$cgi{ERR} = "Grant token has expired.";
		bangbang_templ(\$templ, \$cgi);
	    }
	}
	
	my $attrs = '';
	for my $name (sort keys %g) {
	    next if $name eq 'dn';
	    next if $name =~ /^zx_g_/;
	    next if $name =~ /^\s*\#/;  # Comments
	    my %at = (name => $name, val => $g{$name}, what => $g{"zx_g_doc_$name"} );
	    ($attr = $repeat_attr) =~ s/!!(\w+)/$at{$1}/gs;
	    $attrs .= $attr;
	}
	$gr{REPEAT_ATTR} = $attrs;
	
	$gr{'no'} = $grant_no;
	my ($op, $share, $eid) = $gr{'dn'} =~ /^op=(\w+),\s*share=(\w+),\s*eid=(.*?)$/;
	$gr{'eid'} = $eid;
	my $ent = Net::SAML::get_ent($cf, $eid);
	$gr{'dpy_name'} = Net::SAML::zxid_entity_s_dpy_name_get($ent);
	$gr{'button_url'} = Net::SAML::zxid_entity_s_button_url_get($ent);
	
	($grant_gui = $repeat_grant) =~ s/!!(\w+)/$gr{$1}/gs;
	$grant_guis .= $grant_gui;
    }
    
    $cgi{REPEAT_GRANT} = $grant_guis;
    $cgi{GTGUI} = 1;
    bangbang_templ(\$templ, \$cgi);
}

if ($cgi{'accept'}) {
    $cgi{MSG} = "Grant accepted by user (grant can not be used again).";
    #show_accept($uid, \%cgi);
}

if ($cgi{'decline'}) {
    $cgi{MSG} = "Grant declined by user (grant can not be used again).";
    my $templ = readall("grant-main.html");
    bangbang_templ(\$templ, \$cgi);
}

show_grant($uid);

__END__

https://zxidp.org/idpgrant.pl?g=G123abCDwd

