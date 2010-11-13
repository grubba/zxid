#!/usr/bin/perl
# 2.2.2010, Sampo Kellomaki (sampo@iki.fi)

$usage = <<USAGE;
Test driver for ZXID
Usage: http://localhost:8081/zxtest.pl?tst=XML1
       ./zxtest.pl -a [-x] tst=XML1    # Run specific test
       ./zxtest.pl -a [-x] ntst=XML    # Run all tests except specified
         -a Ascii mode
         -x Print exec command lines to stderr
USAGE
    ;

$cvsid = '$Id$';
($rev) = (split /\s+/, $cvsid)[2];

use Encode;
use Digest::MD5;
use Digest::SHA1;
use Net::SSLeay qw(get_httpx post_httpx make_headers make_form);  # Need Net::SSLeay-1.24
#use WWW::Curl::Easy;    # HTTP client library, see curl.haxx.se
#use WWW::Curl::Multi;
use XML::Simple;
#use Net::SMTP;
#use MIME::Base64;  # plain=decode_base64(b64)   # RFC3548
#sub decode_safe_base64 { my ($x) = @_; $x=~tr[-_][+/]; return decode_base64 $x; }
#sub encode_safe_base64 { my ($x) = @_; $x = encode_base64 $x, ''; $x=~tr[+/][-_]; return $x; }
use Data::Dumper;
use Time::HiRes;

die $usage if $ARGV[0] =~ /^--?[hH?]/;
$trace = 0;

# Where error log goes tail -f zxtest.err
#open STDERR, ">>zxtest.err";

select STDERR; $| = 1; select STDOUT; $| = 1;
warn "START pid=$$ $cvsid qs($ENV{'QUERY_STRING'})";
$ascii = shift if $ARGV[0] eq '-a';
syswrite STDOUT, "Content-Type: text/html\r\n\r\n" if !$ascii;

### N.B. Ignoring SIGCHLD breaks return value of system() and $?
#$x=system "false"; warn "x($x) q($?) $!";
#$SIG{CHLD} = 'IGNORE';  # No zombies, please (subprocesses for delayed ops).
#$x=system "false"; warn "x($x) q($?) $!";

$uname_minus_s = `uname -s`;
chop $uname_minus_s;

### Library Functions

sub writeall {
    my ($f,$d) = @_;
    open F, ">$f" or die "Cant write($f): $!";
    binmode F;
    flock F, 2;    # Exclusive
    print F $d;
    flock F, 8;    
    close F;
}

sub readall {
    my ($f) = @_;
    my ($pkg, $srcfile, $line) = caller;
    undef $/;         # Read all in, without breaking on lines
    open F, "<$f" or die "$srcfile:$line: Cant read($f): $!";
    binmode F;
    flock F, 1;
    my $x = <F>;
    flock F, 8;
    close F;
    return $x;
}

sub cgiout {
    my ($hdr, $mime, $body, $isbin) = @_;
    warn "Len body preenc=".length($body);
    $body = encode_utf8($body);
    warn "Len body postenc=".length($body);
    syswrite STDOUT, "${hdr}Content-Type: $mime\r\nContent-Length: ".length($body)."\r\n\r\n$body";

    if ($isbin > 0) {  # 0 = proto, 1 = html, 2 = true binary
	#warn "cgiout(${hdr}Content-Type: $mime\r\nContent-Length: ".length($body)."\r\n\r\n(binary($isbin) body omitted from log)";
	warn "-- cgiout $$ hdr(${hdr}) mime($mime) len=".length($body)." bin($isbin)";
    } else {
	#warn "cgiout(${hdr}Content-Type: $mime\r\nContent-Length: ".length($body)."\r\n\r\n$body)";
	warn "-- cgiout $$ hdr(${hdr}) mime($mime) len=".length($body)." body($body)";
    }
}

sub cgidec {
    my ($d) = @_;
    my %qs;
    for $nv (split '&', $d) {
	($n, $v) = split '=', $nv, 2;
	$qs{$n} = $v;
    }
    return \%qs;
}

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

if (0) {
sub resp_cb {
    my ($chunk,$curl_id) = @_;
    #warn "resp_cb curl_id($curl_id)";
    $resp{$curl_id} .= $chunk;
    return length $chunk; # OK
}

sub curl_reset_all {
    my ($curl) = @_;
    $curl->reset();
    sleep 5;
}

sub test_http {
    my ($curl, $cmd, $tsti, $expl, $timeout, $slow, $url) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    warn "\n======= $tsti =======";
    
    my $test = tst_link($tsti, $expl, $url);
    my $send_ts = Time::HiRes::time();
    $cmd{$curl_id} = $cmd;
    $key{$curl_id} = $koerkki;
    $qs{$curl_id} = '';
    $sesid{$curl_id} = '';
    warn "HERE1 ".Time::HiRes::time() if $timeout_trace;
    eval {
	warn "HERE2 ".Time::HiRes::time() if $timeout_trace;
	local $SIG{ALRM} = sub { die "TIMEOUT\n"; };
	warn "HERE3 ".Time::HiRes::time() if $timeout_trace;
	alarm $timeout;
	warn "HERE4 ".Time::HiRes::time() if $timeout_trace;
	send_http($curl, $url, 0);
	warn "HERE5 ".Time::HiRes::time() if $timeout_trace;
	wait_response();
	warn "HERE6 ".Time::HiRes::time() if $timeout_trace;
    };
    warn "HERE7 ".Time::HiRes::time() if $timeout_trace;
    alarm 0;
    warn "HERE8 ".Time::HiRes::time() if $timeout_trace;
    my $status = $@;
    warn "HERE9 ".Time::HiRes::time() if $timeout_trace;
    my $latency = substr(Time::HiRes::time() - $send_ts, 0, 5);
    if ($status eq "TIMEOUT\n") {
	tst_print('col1r', 'Timeout', $latency, $slow, $test, '');
	$@ = 0;
	warn "Timeout ($@) ".Time::HiRes::time();
	$timeout_trace = 1;
	curl_reset_all($curl);
    } elsif ($status) {
	tst_print('col1r', 'Conn. Err', $latency, $slow, $test, $status);
    } elsif ($laststatus ne 'OK') {
	tst_print('col1r', 'App Err', $latency, $slow, $test, $lasterror);
    } elsif ($latency > $slow) {
	tst_print('col1y', 'OK slow', $latency, $slow, $test, $lasterror);
    } else {
	tst_print('col1g', 'OK', $latency, $slow, $test, $lasterror);
    }
}

sub test_http_post {
    my ($curl, $cmd, $tsti, $expl, $timeout, $slow, $url, $body) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    warn "\n======= $tsti =======";

    my $test = tst_link($tsti, $expl, $url);
    my $send_ts = Time::HiRes::time();
    $cmd{$curl_id} = $cmd;
    $key{$curl_id} = $koerkki;
    $qs{$curl_id} = '';
    $sesid{$curl_id} = '';
    eval {
	local $SIG{ALRM} = sub { die "TIMEOUT\n"; };
	alarm $timeout;
	send_http_post($curl, $url, $body, 1);
	wait_response();
    };
    alarm 0;
    my $status = $@;
    my $latency = substr(Time::HiRes::time() - $send_ts, 0, 5);
    if ($status eq "TIMEOUT\n") {
	tst_print('col1r', 'Timeout', $latency, $slow, $test, '');
	$@ = 0;
	curl_reset_all($curl);
    } elsif ($status) {
	tst_print('col1r', 'Conn. Err', $latency, $slow, $test, $status);
    } elsif ($laststatus ne 'OK') {
	tst_print('col1r', 'App Err', $latency, $slow, $test, $lasterror);
    } elsif ($latency > $slow) {
	tst_print('col1y', 'OK slow', $latency, $slow, $test, $lasterror);
    } else {
	tst_print('col1g', 'OK', $latency, $slow, $test, $lasterror);
    }
}

### Create http connection handles. Each will correspnd to one session, i.e. set of cookies

$curl_id = 1;
$curlm = WWW::Curl::Multi->new;  # Multihandle, technically needed

#$curl = new WWW::Curl::Easy;  # Share curl handle so that cookies are shared
$curlA = new WWW::Curl::Easy;  # Share curl handle so that cookies are shared
$curlB = new WWW::Curl::Easy;  # Share curl handle so that cookies are shared
$curlC = new WWW::Curl::Easy;  # Share curl handle so that cookies are shared
$curlP = new WWW::Curl::Easy;  # Share curl handle so that cookies are shared

sub tA { test_http($curlA, @_); }
sub tB { test_http($curlB, @_); }
sub tC { test_http($curlC, @_); }
sub tD { test_http($curlD, @_); }
sub tP { test_http($curlP, @_); }

sub send_req {
    my ($what, $send_trace) = @_;
    my ($pkg, $srcfile, $line) = caller;
    $send_ts{$curl_id} = Time::HiRes::time();
    #my $curl = new WWW::Curl::Easy; # Globally created to preserve cookies
    my $curl = $curlP;
    $curl->setopt(CURLOPT_FOLLOWLOCATION, 1);
    $curl->setopt(CURLOPT_MAXREDIRS, 5);
    $curl->setopt(CURLOPT_UNRESTRICTED_AUTH, 1);
    #$curl->setopt(CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    #$curl->setopt(CURLOPT_USERPWD, "sampo:12345678");  # ***
    $curl->setopt(CURLOPT_COOKIEFILE, '');  # Empty file enables tracking cookies
    #open (my $fileb, ">", \$resp);            # Read into inmemory file
    #$curl->setopt(CURLOPT_WRITEDATA,$fileb);
    $curl->setopt(CURLOPT_WRITEFUNCTION, \&resp_cb);
    $curl->setopt(CURLOPT_FILE, $curl_id);
    $resp{$curl_id} = '';
    $curl->setopt(CURLOPT_HTTPGET, 1);
    my @hdr = ("User-Agent: wrevd-0.2-$rev");
    $curl->setopt(CURLOPT_HTTPHEADER, \@hdr);
    $easy_url{$curl_id} = "$dom$soap_endpoint/$what";  # Curl will reference mem so make sure it will not be garbage collected until the handle is
    $curl->setopt(CURLOPT_URL, $easy_url{$curl_id});
    warn "  $srcfile:$line: WS GET($easy_url{$curl_id}) curl_id($curl_id)" if $send_trace;
    $curl->setopt(CURLOPT_PRIVATE, $curl_id);
    $easy{$curl_id} = $curl;
    $curlm->add_handle($curl);
    ++$curl_id;
    ++$active_handles;
}

sub send_req_post_soap {
    my ($body) = @_;
    my ($pkg, $srcfile, $line) = caller;
    $send_ts{$curl_id} = Time::HiRes::time();
    #my $curl = new WWW::Curl::Easy; # Globally created to preserve cookies
    my $curl = $curlP;
    $curl->setopt(CURLOPT_FOLLOWLOCATION, 1);
    $curl->setopt(CURLOPT_MAXREDIRS, 5);
    $curl->setopt(CURLOPT_UNRESTRICTED_AUTH, 1);
    #$curl->setopt(CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    #$curl->setopt(CURLOPT_USERPWD, "sampo:12345678");  # ***
    $curl->setopt(CURLOPT_COOKIEFILE, '');  # Empty file enables tracking cookies
    #open (my $fileb, ">", \$resp);         # Read into inmemory file
    #$curl->setopt(CURLOPT_WRITEDATA,$fileb);
    $curl->setopt(CURLOPT_WRITEFUNCTION, \&resp_cb);
    $curl->setopt(CURLOPT_FILE, $curl_id);
    $resp{$curl_id} = '';
    $curl->setopt(CURLOPT_HTTPPOST, 1);   # SOAP Post

    #$curl->setopt(CURLOPT_POSTFIELDS, qq(<?xml version="1.0" encoding="utf-8"?><soap12:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap12="http://www.w3.org/2003/05/soap-envelope"><soap12:Body>$body</soap12:Body></soap12:Envelope>));
    # Curl will reference mem so make sure it will not be garbage collected until the handle is
    $easy_post{$curl_id} = qq(<?xml version="1.0" encoding="utf-8"?><soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/"><soap:Body>$body</soap:Body></soap:Envelope>);
    $curl->setopt(CURLOPT_POSTFIELDS, $easy_post{$curl_id});

    #my @hdr = ("Content-Type: application/soap+xml","User-Agent: wrevd-0.2");
    my @hdr = ("Content-Type: text/xml","User-Agent: wrevd-0.2-$rev",'SOAPAction: "http://timebi.com/UpdatePositions"');
    $curl->setopt(CURLOPT_HTTPHEADER, \@hdr);
    $easy_url{$curl_id} = "$dom$soap_endpoint";  # Curl will reference mem so make sure it will not be garbage collected until the handle is
    $curl->setopt(CURLOPT_URL, $easy_url{$curl_id});
    warn "$srcfile:$line: WS SOAP($body)" if $wstrace;
    $curl->setopt(CURLOPT_PRIVATE,$curl_id);
    $easy{$curl_id} = $curl;
    $curlm->add_handle($curl);
    ++$curl_id;
    ++$active_handles;
}

sub send_http {
    my ($curl, $url, $send_trace) = @_;
    my ($pkg, $srcfile, $line) = caller;
    $send_ts{$curl_id} = Time::HiRes::time();
    #my $curl = new WWW::Curl::Easy;   # see 1st arg
    $curl->setopt(CURLOPT_FOLLOWLOCATION, 1);
    $curl->setopt(CURLOPT_MAXREDIRS, 5);
    $curl->setopt(CURLOPT_UNRESTRICTED_AUTH, 1);
    $curl->setopt(CURLOPT_COOKIEFILE, ''); # Empty file enables cookie tracking
    $curl->setopt(CURLOPT_WRITEFUNCTION, \&resp_cb);
    $curl->setopt(CURLOPT_FILE, $curl_id);
    $resp{$curl_id} = '';
    $curl->setopt(CURLOPT_HTTPGET, 1);
    my @hdr = ("User-Agent: wrevd-0.2-$rev");
    $curl->setopt(CURLOPT_HTTPHEADER, \@hdr);
    $easy_url{$curl_id} = $url;  # Curl will reference mem so make sure it will not be garbage collected until the handle is
    $curl->setopt(CURLOPT_URL, $easy_url{$curl_id});
    warn "  $srcfile:$line: WS GET($easy_url{$curl_id}) curl_id($curl_id)" if $send_trace;
    $curl->setopt(CURLOPT_PRIVATE, $curl_id);
    $easy{$curl_id} = $curl;
    $curlm->add_handle($curl);
    ++$curl_id;
    ++$active_handles;
}

sub send_http_post {
    my ($curl, $url, $body, $send_trace) = @_;
    my ($pkg, $srcfile, $line) = caller;
    $send_ts{$curl_id} = Time::HiRes::time();
    #my $curl = new WWW::Curl::Easy;  # see 1st arg
    $curl->setopt(CURLOPT_FOLLOWLOCATION, 1);
    $curl->setopt(CURLOPT_MAXREDIRS, 5);
    $curl->setopt(CURLOPT_UNRESTRICTED_AUTH, 1);
    $curl->setopt(CURLOPT_COOKIEFILE, ''); # Empty file enables cookie tracking
    $curl->setopt(CURLOPT_WRITEFUNCTION, \&resp_cb);
    $curl->setopt(CURLOPT_FILE, $curl_id);

    #             1 1    234     4 5     53 2
    #$url =~ s%http(s)?://((([^:]+):([^@]+))@)?%%si;
    #if ($3) {  # inline specified username and password
    #warn "Basic-Auth($3) url($url)";
    #$curl->setopt(CURLOPT_USERPWD, $1);
    #}

    $resp{$curl_id} = '';
    $curl->setopt(CURLOPT_HTTPPOST, 1);
    $easy_post{$curl_id} = $body;
    $curl->setopt(CURLOPT_POSTFIELDS, $easy_post{$curl_id});
    my @hdr = ("User-Agent: wrevd-0.2-$rev");
    $curl->setopt(CURLOPT_HTTPHEADER, \@hdr);
    $easy_url{$curl_id} = $url;  # Curl will reference mem so make sure it will not be garbage collected until the handle is
    $curl->setopt(CURLOPT_URL, $easy_url{$curl_id});
    warn "  $srcfile:$line: WS POST($easy_url{$curl_id}) BODY($body) curl_id($curl_id)" if $send_trace;
    $curl->setopt(CURLOPT_PRIVATE, $curl_id);
    $easy{$curl_id} = $curl;
    $curlm->add_handle($curl);
    ++$curl_id;
    ++$active_handles;
}

sub wait_response {
    $laststatus = $lasterror = '';
    while ($active_handles) {
	warn "  curlm->perform loop active($active_handles) n=$n_resp vol=$v_resp avg_lat=".($n_resp?($tot_latency / $n_resp):0) if $trace;
	$tcid = $curl_id - 1;
	warn "  url($easy_url{$tcid}) curl_id($tcid)" if $trace;
	my $active_transfers = $curlm->perform;
	if ($active_transfers == $active_handles) {
	    #warn "  url($easy_url{$curl_id})";
	    select(undef, undef, undef, 0.1);
	    next;
	}
	warn "  url($easy_url{$tcid}) at=$active_transfers ah=$active_handles" if $trace;
	while (my ($id, $ret) = $curlm->info_read) {
	    next if !$id;
	    --$active_handles;
	    my $curle = $easy{$id};
	    delete $easy{$id}; # let curl handle get garbage collected, or we leak memory
	    delete $easy_post{$id};
	    $latency = Time::HiRes::time() - $send_ts{$id};
	    if ($ret) {
		warn "HTTP layer failed: ".$curle->errbuf."\nid=$id qs($qs{$id})\nurl($easy_url{$id})\nret($ret) id=$id latency=$latency";
		delete $easy_url{$id};
		next;
	    }
	    #warn "HTTP complete $id URL($easy_url{$id})";
	    $qs = cgidec $qs{$id};
	    $rsp = decode_utf8($resp{$id});
	    delete $resp{$id};
	    #warn "resp($rsp) id=$id latency=$latency ($send_ts{$id})" if $wstrace>1;
	    warn "resp($rsp) id=$id qsid($qs{$id}) latency=$latency\n\n" if $wstrace>1 && $$qs{'id'} ne 'intupd';
	    ++$n_resp;
	    $tot_latency += $latency;
	    $v_resp += length $rsp;
	    if (length $rsp) {
		if ($cmd{$id} eq 'PING'
		    || $cmd{$id} eq 'GENTOK'
		    || $cmd{$id} eq 'UPDTOK'
		    || $cmd{$id} eq 'GETTOK'
		    || $cmd{$id} eq 'GETLOC'
		    || $cmd{$id} eq 'GET'
		    || $cmd{$id} eq 'NOT'
		    || $cmd{$id} eq 'PUT'
		    || $cmd{$id} eq 'DEL'
		    || $cmd{$id} eq 'SIGNIN'
		    || $cmd{$id} eq 'LOGOUT'
		    || $cmd{$id} eq 'SRCHLOC'
		    || $cmd{$id} eq 'SRCHADR'
		    || $cmd{$id} eq 'WRSEND'
		    || $cmd{$id} eq 'SENDTWIT'
		    || $cmd{$id} eq 'SENDFB'
		    || $cmd{$id} eq 'SENDHQSMS'
		    || $cmd{$id} eq 'SEARCHADDR'
		    || $cmd{$id} eq 'SEARCHLOC') {
		    warn "Non XML cmd($cmd{$id}) url($easy_url{$id}) response($rsp)";
		} elsif ($cmd{$id} eq 'ST') {
		    warn "static response len=".length($rsp);
		} else {
		    # Wrapped in eval {} to avoid death of wrevd.pl when
		    # web service sends non XML error messages.
		    eval {
			$xx = XMLin $rsp, ForceArray => 1, KeyAttr => [];   # <== Decode XML
		    };
		    if ($@) {
			if (($lasterror) = $rsp =~ /^(.*?Exception.*?)\n/s) {
			    $cmd{$id} = 'exception';
			}
			warn "XMLin: $@";
			warn "cmd($cmd{$id}) resp($id)=($rsp)";
			$xx = undef;
		    }
		}
	    } else {
		warn "Empty response (possibly OK)";
		$xx = undef;
	    }
	    #warn "XML::Simple: " . Dumper($xx);

	    $user = $ses{$sesid{$id}}{'user'};
	    #warn "user($user) qs($qs{$id})" . Dumper($xx) if $wstrace && $$qs{'id'} ne 'intupd';
	    #printf WS_LOG "%.3f %2.3f %5d %4d %s %s %s\n", $send_ts{$id}, $latency, length($rsp), $id, $user, $key{$id}, $qs{$id}; #substr($qs{$id},0,30);
	    
	    if ($cmd{$id} eq 'PING'
		|| $cmd{$id} eq 'GENTOK'
		|| $cmd{$id} eq 'UPDTOK'
		|| $cmd{$id} eq 'GETTOK'
		|| $cmd{$id} eq 'GETLOC'
		|| $cmd{$id} eq 'GET'
		|| $cmd{$id} eq 'PUT'
		|| $cmd{$id} eq 'DEL'
		|| $cmd{$id} eq 'SIGNIN'
		|| $cmd{$id} eq 'LOGOUT'
		|| $cmd{$id} eq 'SRCHLOC'
		|| $cmd{$id} eq 'SRCHADR'
		|| $cmd{$id} eq 'WRSEND') {
		$lasterror = $rsp;
		eval { $rr = $jsonobj->decode($rsp); };
		if ($$rr[0]{'err'} && $$rr[0]{'err'} ne 'OK' && $$rr[0]{'err'} ne 'LAST') {
		    warn "err($$rr[0]{'err'})";
		    $laststatus = $$rr[0]{'err'};
		} else {
		    warn "OK err($$rr[0]{'err'})";
		    $laststatus = 'OK';
		}
	    } elsif ($cmd{$id} eq 'NOT') {
		$lasterror = $rsp;
		eval { $rr = $jsonobj->decode($rsp); };
		if ($$rr[0]{'err'} ne 'NA') {
		    $laststatus = "E=".$$rr[0]{'err'};
		} else {
		    $laststatus = 'OK';
		}
	    } elsif ($cmd{$id} eq 'NOP') {
		$lasterror = $rsp;
		eval { $rr = $jsonobj->decode($rsp); };
		if ($$rr[0]{'err'} ne 'NP') {
		    $laststatus = "E=".$$rr[0]{'err'};
		} else {
		    $laststatus = 'OK';
		}
	    } elsif ($cmd{$id} eq 'ST') {
		$laststatus = 'OK';
		$lasterror = "len=".length($rsp);
	    } elsif ($cmd{$id} eq 'ANSWER') {
		warn "ANSWER resp";
	    } elsif ($cmd{$id} eq 'RECORD') {
		warn "RECORD resp";		
	    } elsif ($cmd{$id} eq 'GET') {
		if (!$xx) {
		    process_error_response('BAD', $user, $sesid{$id}, $qs);
		} elsif(length @{$$xx{'ArrayOfTagRest'}}) {
		    process_ary_of_tag_rest_response($xx, $user, $sesid{$id}, $qs);
		} elsif(length @{$$xx{'Name'}}) {
		    process_timetag_response($xx, $user, $sesid{$id}, $qs);
		} else {
		    process_error_response('NA', $user, $sesid{$id}, $qs);
		}
	    #} elsif ($cmd{$id} eq 'DEL') {
            #	warn "DEL resp";
	    #	process_simple_response($xx, $user, $sesid{$id}, $qs);
	    #} elsif ($cmd{$id} eq 'PUT') {
	    #   warn "PUT resp";
	    #   process_simple_response($xx, $user, $sesid{$id}, $qs);
	    #} elsif ($cmd{$id} eq 'UPD') {
	    #	warn "UPD resp";
	    #	process_simple_response($xx, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'SENDHQSMS') {
		warn "SENDHQSMS resp";
		process_sent_hqsms_response($rsp, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'SENDTWIT') {
		warn "SENDTWIT resp";
		process_sent_twit_response($rsp, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'SENDFB') {
		warn "SENDFB resp";
		process_sent_fb_response($rsp, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'SEND') {
		warn "SEND resp";
		process_sent_response($xx, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'SEARCHLOC') {
		warn "SEARCHLOC resp";
		process_searchloc_response($rsp, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'SEARCHADDR') {
		warn "SEARCHADDR resp";
		process_searchaddr_response($rsp, $user, $sesid{$id}, $qs);
	    } elsif ($cmd{$id} eq 'HOSTIP') {
		warn "HOSTIP resp";
		process_hostip_response($rsp, $user, $sesid{$id}, $qs);
	    }
	    delete $easy_url{$id};
	    delete $cmd{$id};
	    delete $key{$id};
	    delete $sesid{$id};
	    delete $send_ts{$id};
	}
    }
}

### Run in context of inquiring user, typically only in the beginning.
### process_ary_of_tag_rest_response($xx, $user, $sesid{$id}, $qs);

sub process_tag_rests {
    my ($tr_ary, $user, $qs) = @_;
    my ($tagrest, $hr, $ohr, $x, $i, @json);
    for $tagrest (@{$$tr_ary{'TagRest'}}) {
	#warn "TAGREST qsid($$qs{'id'}): " . Dumper $tagrest if $$tagrest{'name'} eq 'paulo';
	# Send event, unless internal update (update triggered by timer on daemon)
	push @json, 1;
    }
    return @json;
}

sub process_ary_of_tag_rest_response {
    my ($xx, $user, $sesid, $qs) = @_;
    my ($tr_ary, $tagrest, $hr, $ohr, $x, $rq);
    my @json = ();
    for $tr_ary (@{$$xx{'ArrayOfTagRest'}}) {
	push @json, process_tag_rests($tr_ary, $user, $qs);
    }
    if ($#json >= 0) {
	$laststatus = 'OK';
	$lasterror = "Number of tag rests=".$#json+1;
    } else {
	$laststatus = 'ERRTR';
    }
}

### N.B. Runs in context of inquiring user and only sends messages (such
### as diffs or end result) to the inquiring user's sessions.

sub process_timetag_response {
    my ($xx, $user, $sesid, $qs) = @_;
    
    if (length $$xx{'Name'}[0]) {
	$laststatus = 'OK';
    } else {
	$laststatus = 'ERRTT';
    }
}

sub process_simple_response {
    my ($xx, $user, $sesid, $qs) = @_;
    $laststatus = 'OK';
}

sub process_error_response {
    my ($erro, $user, $sesid, $qs) = @_;
    warn "error($erro) user($user) sesid($sesid) qs(".Dumper($qs).")";
    $laststatus = $erro;
}

sub process_sent_response {
    my ($xx, $user, $sesid, $qs) = @_;
    $lasterror = 'OK'; # Need better check to verify if message really was sent
}
}


sub check_for_listener {
    my $port = shift @_;
    return 1 if $always_external_test_servers;  # avoid netstat 'cause it oopes Linux 2.5.74
    if ($uname_minus_s eq "SunOS" || $uname_minus_s eq "Darwin" || $uname_minus_s eq "AIX" || $uname_minus_s eq "Interix") {
	if (`netstat -an` =~ /\.$port\s+.+LISTEN$/m) {
	    return 1;
	}
    } elsif ($uname_minus_s eq "Linux") {
	if (`netstat -an` =~ /\:$port\s+.+LISTEN\s*/) {
	    return 1;
	}
    } elsif (substr($uname_minus_s, 0, 9) eq "CYGWIN_NT" || $uname_minus_s eq "Windows") {
	if (`netstat -an` =~ /\:$port\s+.+LISTENING\s*/) {
	    return 1;
	}
    } else {
	die "Can't determine system type($uname_minus_s)";
    }
    return 0;
}

# Launches a server, unless one is already listening on the targeted port,
# and arranges for logs to go to the right place.

sub launch_server {
#    for some tests to work with -e flag
#    my ($port, $log_file, @cmd_line, $file) = @_;
#    @cmd_line = "@cmd_line" . "$file";
    my ($port, $log_file, @cmd_line) = @_;
    my $pid;
    my $devnull = "</dev/null";
    if (substr($uname_minus_s, 0, 9) eq "CYGWIN_NT" || $uname_minus_s eq "Windows") {
    	$devnull = "<:NUL";
    }
    return if $host ne 'localhost';   # Presumably it was set up somewhere else
    return if check_for_listener($port);
    success_report() && die "Test server (port $port) died. Tried to relaunch"
	if $relaunch_testserver{$port}++;
    #warn "Launching @cmd_line";
    if ($pid = fork) {
        #warn "launched server $pid:: @cmd_line\n";
	wait_for_port($port) or kill_child($pid) and exit 1;
	return $pid;
    }
    die "fork($port) failed: $!" unless defined $pid;
    open STDIN, $devnull;  # Keep fd 0 occupied as it has special meaning
    warn "\nEXEC @cmd_line (>$log_file pid=$$)\n" if $show_exec;
    open STDOUT, ">>$log_file"
	or die "Redirect of STDOUT to $log_file failed: $!";
    open STDERR, ">&STDOUT" or die "Redirect of STDERR failed: $!";
    exec @cmd_line;
    die "exec($port) failed: $!";
}

#only kill the "ldap server", proxy that runs testserver.ldif
sub kill_server {
    my @process=split ' ',`ps -efa | grep dsproxy | grep testserver.ldif | grep -v "ps -efa"`;
    my $proc=$process[1];
    if ($proc){
	kill_child ($proc);
	#The next line initialize the relaunch counter
	$relaunch_testserver{$testserver_port}=0;
    }
}

sub tst_ok {
    my ($latency, $slow, $test) = @_;
    if ($latency > $slow) {
	tst_print('col1y', 'OK slow', $latency, $slow, $test, $lasterror);
    } else {
	tst_print('col1g', 'OK', $latency, $slow, $test, $lasterror);
    }
}

sub G {
    my ($cmd, $tsti, $expl, $timeout, $slow, $url) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    warn "\n======= $tsti =======";

    my ($page, $result, %headers);
    my ($proto, $host, $port, $localurl)
	= $url =~ m%^(https?)://([^:/]+)(?:(\d+))?(/.*?)$%i;
    my $usessl = ($proto =~ /^https$/i ? 1 : 0);

    my $test = tst_link($tsti, $expl, $url);
    my $send_ts = Time::HiRes::time();
    warn "HERE1 ".Time::HiRes::time() if $timeout_trace;
    eval {
	warn "HERE2 ".Time::HiRes::time() if $timeout_trace;
	local $SIG{ALRM} = sub { die "TIMEOUT\n"; };
	warn "HERE3 ".Time::HiRes::time() if $timeout_trace;
	alarm $timeout;
	warn "HERE4 ".Time::HiRes::time() if $timeout_trace;
	
	($page, $result, %headers)
	    = get_httpx($usessl, $host, $port, $localurl, $headers);

	warn "HERE6 ".Time::HiRes::time() if $timeout_trace;
    };
    warn "HERE7 ".Time::HiRes::time() if $timeout_trace;
    alarm 0;
    warn "HERE8 ".Time::HiRes::time() if $timeout_trace;
    my $status = $@;
    warn "HERE9 ".Time::HiRes::time() if $timeout_trace;
    my $latency = substr(Time::HiRes::time() - $send_ts, 0, 5);
    if ($status eq "TIMEOUT\n") {
	tst_print('col1r', 'Timeout', $latency, $slow, $test, '');
	$@ = 0;
	warn "Timeout ($@) ".Time::HiRes::time();
	$timeout_trace = 1;
    } elsif ($status) {
	tst_print('col1r', 'Conn. Err', $latency, $slow, $test, $status);
    } elsif ($laststatus ne 'OK') {
	tst_print('col1r', 'App Err', $latency, $slow, $test, $lasterror);
    } else {
	tst_ok($latency, $slow, $test);
    }
}

sub call_system {
    my ($test, $timeout, $slow, $command_line, $exitval) = @_;
    my $send_ts = Time::HiRes::time();
    $? = 0;
    warn "HERE1 ".Time::HiRes::time() if $timeout_trace;
    eval {
	warn "HERE2 ".Time::HiRes::time() if $timeout_trace;
	local $SIG{ALRM} = sub { die "TIMEOUT\n"; };
	warn "HERE3 ".Time::HiRes::time() if $timeout_trace;
	alarm $timeout;
	warn "HERE4 ".Time::HiRes::time() if $timeout_trace;

	warn "EXEC($command_line)\n" if $show_exec;
	system $command_line;
	#warn "ret($ret) exit($?): $!";
	warn "HERE6 ".Time::HiRes::time() if $timeout_trace;
    };
    warn "HERE7 ".Time::HiRes::time() if $timeout_trace;
    alarm 0;
    warn "HERE8 ".Time::HiRes::time() if $timeout_trace;
    my $latency = substr(Time::HiRes::time() - $send_ts, 0, 5);
    if ($@ eq "TIMEOUT\n") {
	tst_print('col1r', 'Timeout', $latency, $slow, $test, '');
	$@ = 0;
	warn "Timeout ($@) ".Time::HiRes::time();
	$timeout_trace = 1;
	return -1;
    } elsif ($@) {
	tst_print('col1r', 'Conn. Err', $latency, $slow, $test, $@);
	return -1;
    } elsif ($? != $exitval) {
	tst_print('col1r', 'App Err', $latency, $slow, $test, "exit=$?" . ($?==-1?"$!":""));
	return -1;
    }
    return $latency;
}

sub C {
    my ($tsti, $expl, $timeout, $slow, $command_line) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    warn "\n======= $tsti =======\n";

    my $test = tst_link($tsti, $expl, $url);
    my $latency = call_system($test, $timeout, $slow, $command_line);
    return if $latency == -1;
    tst_ok($latency, $slow, $test);
}

sub ED {  # enc-dec command with diff
    my ($tsti, $expl, $n_iter, $file, $exitval, $timeout) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    my $test = tst_link($tsti, $expl, '');
    my $slow = 0.01 * $n_iter;
    $timeout ||= 60;
    
    unlink "tmp/$tsti.out";
    
    my $latency = call_system($test, $timeout, $slow, "./zxencdectest -i $n_iter <$file >tmp/$tsti.out 2>tmp/tst.err", $exitval);
    return if $latency == -1;
    
    if (system "/usr/bin/diff t/$tsti.out tmp/$tsti.out") {
	tst_print('col1r', 'Diff Err', $latency, $slow, $test, '');
	return;
    }
    tst_ok($latency, $slow, $test);
}

sub ZXC {  # zxcall
    my ($tsti, $expl, $n_iter, $arg, $file) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    my $test = tst_link($tsti, $expl, '');
    my $slow = 0.3 * $n_iter;
    
    unlink "tmp/$tsti.out";
    
    my $latency = call_system($test, 60, $slow, "./zxcall -a http://idp.tas3.pt:8081/zxididp?o=B tastest:tas123 $arg <$file >tmp/$tsti.out 2>tmp/tst.err");
    return if $latency == -1;
    
    #if (system "/usr/bin/diff -u t/$tsti.out tmp/$tsti.out") {
    #	tst_print('col1r', 'Diff Err', $latency, $slow, $test, '');
    #	return;
    #}
    tst_ok($latency, $slow, $test);
}

sub CMD {  # zxpasswd command with diff
    my ($tsti, $expl, $cmd, $exitval, $timeout) = @_;
    return unless $tst eq 'all' || $tst eq substr($tsti,0,length $tst);
    return if $ntst && $ntst eq substr($tsti,0,length $ntst);
    my $test = tst_link($tsti, $expl, '');
    my $slow = 0.1;
    $timeout ||= 60;

    unlink "tmp/$tsti.out";
    
    my $latency = call_system($test, $timeout, $slow, "$cmd >tmp/$tsti.out 2>tmp/tst.err", $exitval);
    return if $latency == -1;
    
    if (system "/usr/bin/diff t/$tsti.out tmp/$tsti.out") {
	tst_print('col1r', 'Diff Err', $latency, $slow, $test, '');
	return;
    }
    tst_ok($latency, $slow, $test);
}

##################################################################
### START
###

if ($ARGV[0] eq '-x') {
    $show_exec = shift;
}

$cgi = cgidec($ENV{'QUERY_STRING'} || shift);
$tst = $$cgi{'tst'} || 'all';
$ntst = $$cgi{'ntst'};

my ($ss, $mm, $hh, $day, $mon, $year) = gmtime();
$ts = sprintf "%04d%02d%02d-%02d%02d%02d", $year+1900,$mon+1,$day,$hh,$mm,$ss;

# N.B. It appears that it is very important for the table-layout: fixed
#      to be complemented with width: specification at table and th/td level.
#
#     <table class=line width=980><tr><td class=$class1 width=80>$status</td><td class=col2 width=50>$latency</td><td class=col3 width=50>$slow</td><td class=col4 width=300>$test</td><td class=col5>$lasterror&nbsp;</td></tr></table>


#$out =
syswrite STDOUT, <<HTML if !$ascii;
<title>ZXTEST</title>
<style type="text/css" media="screen, projection">
table.line  {  table-layout: fixed; width: 980px;  }
table       {  table-layout: fixed; width: 980px;  }
td  {  vertical-align: top;  white-space: nowrap; }
td.col1  {  width=80px;  padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  }
td.col1r {  width=80px;  padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  background-color: red;  }
td.col1g {  width=80px;  padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  background-color: green;  }
td.col1y {  width=80px;  padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  background-color: yellow;  }
td.col2  {  width=50px;  padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  }
td.col3  {  width=50px;  padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  }
td.col4  {  width=300px; padding-left: 3px; padding-right: 7px; border-right: 1px dotted #066;  }
td.col5  {  width=500px; padding-left: 3px; padding-right: 3px; border-right: 0px;  white-space: normal; } 
</style>
<body bgcolor=white>
<h1>ZXID Testing Tool $ts</h1>
<a href="zxtest.pl">zxtest.pl</a>
<p>
HTML
    ;

sub tst_link {
    my ($tsti, $expl, $url) = @_;
    return "$tsti $expl" if $ascii;
    return qq(<a href="zxtest.pl?tst=$tsti">$tsti</a> <a href="$url">*</a> $expl);
}

sub tst_print {
    my ($class1, $status, $latency, $slow, $test, $lasterror) = @_;
    if ($ascii) {
	printf "%-8s %-5s %-5s %-50s %s\n", $status, $latency, $slow, $test, $lasterror;
    } else {
	syswrite STDOUT, "<table class=line><tr><td class=$class1>$status</td><td class=col2>$latency</td><td class=col3>$slow</td><td class=col4>$test</td><td class=col5>$lasterror&nbsp;</td></tr></table>\n";
    }
}

sub tA { test_http($curlA, @_); }
sub tB { test_http($curlB, @_); }
sub tC { test_http($curlC, @_); }
sub tD { test_http($curlD, @_); }
sub tP { test_http($curlP, @_); }

if ($ascii) {
    tst_print('col1', 'STATUS', 'SECS', 'GOAL', 'TEST NAME', 'MESSAGES');
} else {
    tst_print('col1', '<b>Status</b>', '<b>Secs</b>', '<b>Goal</b>', '<b>Test name</b>', '<b>Messages</b>');
}

### Service testing

CMD('CONF1', 'zxcall -dc dump config', "./zxcall -v -v -c PATH=/var/zxid/ -dc");

CMD('PW1', 'zxpasswd list user', "./zxpasswd -l tastest");
CMD('PW2', 'zxpasswd pw an ok', "echo tas123 | ./zxpasswd -v -a tastest");
CMD('PW3', 'zxpasswd pw an fail', "echo tas124 | ./zxpasswd -v -a tastest",1792);

CMD('COT1', 'zxcot list', "./zxcot");
CMD('COT2', 'zxcot list swap', "./zxcot -s");
CMD('COT3', 'zxcot list s2', "./zxcot -s -s");
CMD('COT4', 'zxcot get idp meta dry', "./zxcot -g http://idp.tas3.pt:8081/zxididp?o=B -n -v");
CMD('COT5', 'zxcot get sp meta dry', "./zxcot -g http://sp.tas3.pt:8080/zxidservlet/sso?o=B -n -v");
CMD('COT6', 'zxcot my meta', "./zxcot -m");

CMD('SIG1',  'sig vry shib resp', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <cal-private/shib-resp.xml");
CMD('SIG2',  'sig vry shib post', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <cal-private/shib-resp.qs");

CMD('SIG3',  'sig vry zxid resp', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/anrs1.xml");
CMD('SIG4',  'sig vry zxid post', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/anrs1.post");

CMD('SIG5',  'sig vry sm resp', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/siteminder-resp.xml");
CMD('SIG6',  'sig vry sm post', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/siteminder-resp.b64");

CMD('SIG7',  'sig vry shib resp undecl prefix deep', "./zxdecode -v -s -s <t/shib-a7n2.xml");  # fail due to inclusive ns prefix that is declared only deep in the document
CMD('SIG8',  'sig vry ping resp', "./zxdecode -v -s -s <t/ping-resp.xml");  # Ping miscanonicalizes. Fail due to lack of InclusiveNamespace/@PrefixList="xs" (and declares namespace deep in the document)
CMD('SIG9',  'sig vry ping post', "./zxdecode -v -s -s <t/ping-resp.qs");
CMD('SIG10', 'sig vry hp a7n',    "./zxdecode -v -s -s <t/hp-a7n.xml");
CMD('SIG11', 'sig vry hp post',   "./zxdecode -v -s -s <t/hp-idp-post-resp.cgi");
CMD('SIG12', 'sig vry hp resp',   "./zxdecode -v -s -s <t/hp-idp-post-resp.xml");
CMD('SIG13', 'sig vry hp resp2',  "./zxdecode -v -s -s <t/hp-idp-post-resp2.xml");
#CMD('SIG14', 'sig vry saml artifact request',  "./zxdecode -v -s -s <t/se-req2.xml"); # no a7n
CMD('SIG15', 'sig vry saml artifact response', "./zxdecode -v -s -s <t/se-resp.xml");
CMD('SIG16', 'sig vry saml artifact response', "./zxdecode -v -s -s <t/se-req.xml");
CMD('SIG17', 'sig vry saml artifact response', "./zxdecode -v -s -s <t/se-artif-resp.xml");
#CMD('SIG18', 'sig vry prstnt-a7n',  "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/prstnt-a7n.xml");  # RSA padding check fail (wrong private key)
CMD('SIG18b', 'sig vry prstnt-a7n',  "./zxdecode -v -s -s <t/prstnt-a7n.xml");

#CMD('SIG19', 'sig vry rsa-slo-req', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/rsa-slo-req.xml");
#CMD('SIG20', 'sig vry rsa-a7n', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/rsa-a7n.xml");  # RSA padding check fail (wrong private key)
CMD('SIG20b', 'sig vry rsa-a7n', "./zxdecode -v -s -s <t/rsa-a7n.xml");
#CMD('SIG21', 'sig vry rsa-a7n2', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/rsa-a7n2.xml");  # RSA padding check fail (wrong private key)
CMD('SIG21b', 'sig vry rsa-a7n2', "./zxdecode -v -s -s <t/rsa-a7n2.xml");
#CMD('SIG22', 'sig vry rsa-idp-post',  "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/rsa-idp-post-resp.cgi");  # RSA padding check fail (wrong private key)
CMD('SIG22b', 'sig vry rsa-idp-post',  "./zxdecode -v -s -s <t/rsa-idp-post-resp.cgi");

#CMD('SIG23', 'sig vry rsa-idp-post-enc-a7n', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/rsa-idp-post-resp2.cgi");  # RSA padding check fail (wrong private key)

#CMD('SIG24', 'sig vry protectednet-post-enc-a7n', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/protectednet-encrypted.txt");
#CMD('SIG25', 'sig vry protectednet-resp-enc-a7n', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/protectednet-encrypted.xml");

#CMD('SIG26', 'sig vry orange simple sign', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/orange1.post-simple-sign");  # No metadata
#CMD('SIG27', 'sig vry orange simple sign2', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/orange2-sig-data.b64");  # No metadata

#CMD('SIG28', 'sig vry ibm-enc-a7n', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/ibm-enc-a7n.xml");
#CMD('SIG29', 'sig vry ibm-resp-extra-ns', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/ibm-resp-extra-ns.xml");  # No a7n, no metadata

#CMD('SIG30', 'sig vry simplesamlphp enc a7n', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/encrypted-simplesamlphp.xml"); # Messed up by whitespace
#CMD('SIG31', 'sig vry simplesamlphp enc post', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/encrypted-simplesamlphp.txt"); # Messed up by whitespace

#CMD('SIG32', 'sig vry enc-nid-enc-attr', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/enc-nid-enc-attr.xml");  # wrong private key
CMD('SIG32b', 'sig vry enc-nid-enc-attr', "./zxdecode -v -s -s <t/enc-nid-enc-attr.xml");
#CMD('SIG33', 'sig vry a7n stijn', "./zxdecode -v -s -c AUDIENCE_FATAL=0 -c TIMEOUT_FATAL=0 -c DUP_A7N_FATAL=0 -c DUP_MSG_FATAL=0 <t/assertion-stijn-20100108.xml");  # Corrupt with non-printable chars
#CMD('SIG34', 'sig vry symsp-ibmidp-slo',     "./zxdecode -v -s -s <t/symsp-ibmidp-slo.xml");
#CMD('SIG35', 'sig vry symsp-symidp-slo',     "./zxdecode -v -s -s <t/symsp-symidp-slo-soap.xml");
#CMD('SIG36', 'sig vry zxidp-ki-old',     "./zxdecode -v -s -s <t/zxidp-ki-a7n-20100906.xml"); # ***fail canon
CMD('SIG37', 'sig vry', "./zxdecode -v -s -s <t/enve-sigval-err.xml");

ED('XML1',  'Decode-Encode SO and WO: ns-bug', 1000, 't/default-ns-bug.xml');
ED('XML2',  'Decode-Encode SO and WO: azrq1',  1000, 't/azrq1.xml');
ED('XML3',  'Decode-Encode SO and WO: azrs1',  1000, 't/azrs1.xml');
ED('XML4',  'Decode-Encode RIS malformed 1',   1,    't/risaris-bad.xml');
ED('XML5',  'Decode-Encode SO and WO: ana7n1', 1000, 't/ana7n1.xml');
ED('XML6',  'Decode-Encode SO and WO: anrq1',  1000, 't/anrq1.xml');
ED('XML7',  'Decode-Encode SO and WO: anrs1',  1000, 't/anrs1.xml');
ED('XML8',  'Decode-Encode SO and WO: dirq1',  1000, 't/dirq1.xml');
ED('XML9',  'Decode-Encode SO and WO: dirs1',  1000, 't/dirs1.xml');
ED('XML10', 'Decode-Encode SO and WO: dirq2',  1000, 't/dirq2.xml');
ED('XML11', 'Decode-Encode SO and WO: dia7n1', 1000, 't/dia7n1.xml');
ED('XML12', 'Decode-Encode SO and WO: epr1',   1000, 't/epr1.xml');
ED('XML13', 'Decode-Encode SO and WO: wsrq1',  1000, 't/wsrq1.xml');
ED('XML14', 'Decode-Encode SO and WO: wsrs1',  1000, 't/wsrs1.xml');
ED('XML15', 'Decode-Encode SO and WO: wsrq2',  1000, 't/wsrq2.xml');
ED('XML16', 'Decode-Encode SO and WO: wsrs2',  1000, 't/wsrs2.xml');
ED('XML17', 'Decode-Encode SO and WO: as-req',  1000, 't/as-req.xml');
ED('XML18', 'Decode-Encode SO and WO: as-resp', 1000, 't/as-resp.xml');
ED('XML19', 'Decode-Encode SO and WO: authnreq',1000, 't/authnreq.xml');
ED('XML20', 'Decode-Encode SO and WO: sun-md', 10, 't/sun-md.xml');
ED('XML21', 'Decode-Encode SO and WO: provisioning-req',  10, 't/pmdreg-req.xml');
ED('XML22', 'Decode-Encode SO and WO: provisioning-resp', 10, 't/pmdreg-resp.xml');
ED('XML23', 'Decode-Encode SO and WO: pds-create-uc1',    10, 't/pds-create-uc1.xml');
ED('XML24', 'Decode-Encode SO and WO: pds-query-uc1',     10, 't/pds-query-uc1.xml');
ED('XML25', 'Decode-Encode SO and WO: AdvClient hoard-trnsnt', 10, 't/ac-hoard-trnsnt.xml');
ED('XML26', 'Decode-Encode SO and WO: AdvClient ming-trnsnt',  10, 't/ac-ming-trnsnt.xml');
ED('XML27', 'Decode-Encode SO and WO: AdvClient ming-prstnt',  10, 't/ac-ming-prstnt.xml');
ED('XML28', 'Decode-Encode SO and WO: AdvClient ming-ntt',     10, 't/ac-ming-ntt.xml');
ED('XML29', 'Decode-Encode SO and WO: AdvClient ntt-fixed',    10, 't/ac-ming-ntt-fixed.xml');
ED('XML30', 'Decode-Encode SO and WO: zx a7n',    10, 't/a7n-len-err.xml');

# *** TODO: add EncDec for all other types of protocol messages
# *** TODO: add specific SSO signature validation tests

# *** TODO: benchmark raw RSA performance using logging w/ zxlogview

# *** TODO: set up test IdP using zxcot (for disco registrations and bootstrap) and zxpasswd
# *** TODO: set up test SP
# *** TODO: set up test WSP

ZXC('ZXC-AS1', 'Authentication Service call: SSO + AZ', 1000, "-az ''", '/dev/null');

ZXC('ZXC-IM1', 'Identity Mapping Service call', 1000, "-im http://sp.tas3.pt:8081/zxidhrxmlwsp?o=B", '/dev/null');

ZXC('ZXC-DI1', 'Discovery Service call', 1000, "-di '' -t urn:x-foobar -nd", '/dev/null');
ZXC('ZXC-DI2', 'List EPR cache', 1, "-l", '/dev/null');

ZXC('ZXC-WS1', 'AS + WSF call: idhrxml',  1000, "-t urn:id-sis-idhrxml:2007-06:dst-2.1", 't/id-hrxml-rq.xml');
ZXC('ZXC-WS2', 'AS + WSF call: x-foobar', 1000, "-t urn:x-foobar", 't/x-foobar-rq.xml');

# *** TODO: add through GUI testing for SSO
# *** TODO: via zxidhlo
# *** TODO: via mod_auth_saml
# *** TODO: via zxidhlo.php
# *** TODO: via Net::SAML
# *** TODO: via SSO servlet

if (0) {
#C('DBG1', 'Test exit value', 0.5, 0.1, "echo foo");
C('SRV1', 'mini_http -p 2301 idp', 5, 0.5, "");

tA('ST', 'ST1', 'static content bypass svn.zxid.org', 5, 0.5, "http://svn.zxid.org/wr/redx.png");
tP('ST', 'ST2', 'static content bypass zxid.org', 5, 0.5, "http://zxid.org/favicon.ico");
}

syswrite STDOUT, <<HTML if !$ascii;
</table>
<p><i>Hint: Click on test name to run just that test.</i>

[ <a href="zxtest.pl">zxtest.pl</a> 
| <a href="zxtest.pl?tst=XML">XML Encoding and Decoding</a> 
| <a href="zxtest.pl?tst=ZXC-WS">Web Service calls</a> ]

<hr>
<i>$cvsid</i>
HTML
    ;

__END__
#EOF
