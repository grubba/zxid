#!/usr/bin/perl
# 20141006 standin for UMA code --Sampo

use Data::Dumper;
use Time::timegm qw(timegm);
use File::Copy;
use Cwd;
use filex qw(slurp barf bangbang bangbarf slurpbang cgi_split inc extract_popup parse_yyyymmdd);
open STDERR, ">>/var/tmp/pdblog.err";
select STDERR; $|=1; select STDOUT;
$cwd = cwd();

@wday = qw(Sun Mon Tue Wed Thu Fri Sat);  # Edit for your language, if you must
@mon = qw(Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec);
$secs = time();
($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = gmtime($secs);
#$ts = sprintf("%s, %d-%s-%04d, %02d:%02d", $wday[$wday], $mday, $mon[$mon], $year+1900,$hour,$min);
$ts = sprintf("%02dh%02d %s, %d-%s-%04d", $hour,$min,$wday[$wday], $mday, $mon[$mon], $year+1900);

undef $/;
$qs = <STDIN> if $ENV{REQUEST_METHOD} eq 'POST';
#warn "qs($qs)";
$qs .= '&' . $ENV{QUERY_STRING};
#warn "qs2($qs) filex::VERSION=$filex::VERSION";
$cgi = cgi_split($qs);

if ($$cgi{'o'} eq 'dyncli') {
    
} elsif ($$cgi{'o'} eq 'dyncli') {
} elsif ($$cgi{'o'} eq 'tokissue') {
} elsif ($$cgi{'o'} eq 'consent') {
} elsif ($$cgi{'o'} eq 'tokquery') {
} elsif ($$cgi{'o'} eq 'resreg') {
} elsif ($$cgi{'o'} eq 'permreg') {
} elsif ($$cgi{'o'} eq 'rpt') {
} elsif ($$cgi{'o'} eq 'azrq') {
} elsif ($$cgi{'o'} eq 'chooseaz') {
    warn "Acquire PAT from Az";
    warn "Register resource for protection at Az";
} else {
    print <<HTML;
Content-type: text/html

<title>ZXID Resource Server: Choose Az</title>
<h1>ZXID Resource Server: Choose Az</h1>

<ul>
<li><a href="?o=chooseaz&azissuer=https://zxidp.org/idp">https://zxidp.org/idp</a>
<li><a href="?o=chooseaz&azissuer=https://demo.nuveam.com">https://demo.nuveam.com</a>
<li><a href=""></a>
</ul>
HTML
;
}

__END__
echo $$ >>/tmp/env.cgi-ran

echo "Content-Type: text/plain"
echo "Set-Cookie: envtest=foo; path=/; secure;"
echo
pwd
env | sort
ulimit -a
id
cat /proc/sys/kernel/core_pattern
