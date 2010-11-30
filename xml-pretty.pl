#!/usr/bin/perl
# 4.9.2009, Sampo Kellomaki (sampo@iki.fi)
# $Id: xml-pretty.pl,v 1.1 2009-09-05 02:23:41 sampo Exp $
#
# Pretty Print XML  --  Make XML almost human readable
#
# Usage: cat foo.saml | ./zxdecode | ./xml-pretty.pl

use Data::Dumper;

undef $/;
$xml = <STDIN>;

if (0) {
    require XML::Simple;
    $xx = XML::Simple::XMLin $xml, ForceArray=>1, KeepRoot=>1;  # , KeyAttr => [ 'id', 'name' ]
    #warn Dumper $xx;
    print XML::Simple::XMLout $xx, AttrIndent=>1, KeepRoot=>1;  # , NoSort=>1
    exit;
}

$ascii = 2;

# See https://wiki.archlinux.org/index.php/Color_Bash_Prompt
sub red   { $ascii > 1 ? "\e[1;31m$_[0]\e[0m" : $_[0]; }  # red text
#sub green { $ascii > 1 ? "\e[1;32m$_[0]\e[0m" : $_[0]; }
#sub red    { $ascii > 1 ? "\e[1;41m$_[0]\e[0m" : $_[0]; }  # red background, black bold text
sub green  { $ascii > 1 ? "\e[1;42m$_[0]\e[0m" : $_[0]; }
sub redy   { $ascii > 1 ? "\e[41m$_[0]\e[0m" : $_[0]; }    # red background, black text (no bold)
sub greeny { $ascii > 1 ? "\e[42m$_[0]\e[0m" : $_[0]; }
sub yely { $ascii > 1 ? "\e[43m$_[0]\e[0m" : $_[0]; }

sub xml_pretty {
    my $res = '';
    my $indent = '';
    my ($x,$at,$noindent);
    for $x (split /(<\/?\w.*?>)/, $_[0]) {
	next if !length $x;
	#print "*";
	if ($x !~ /^</) {
	    if (length $x < 6) {
		chop $res;
		$res .= green($x);
		$noindent = 1;
	    } else {
		$res .= $indent.greeny($x)."\n";
	    }
	    next;
	}
	if ($x =~ /^<!--/) {
	    $res .= "$indent$x\n";
	    next;
	}
	if ($x =~ /^<\?/) {
	    $res .= "$indent$x\n";
	    next;
	}
	if ($x =~ /^<\//) {
	    substr($indent,-2) = '';
	    $x = red($x);
	    if ($noindent) {
		$res .= "</>";
	    } else {
		$res .= "$indent$x\n";
	    }
	    next;
	}
	if ($noindent) {
	    $noindent = 0;
	    $res .= "\n";
	}
	#            1               12   3   32 4  4
	if ($x =~ /^<([A-Za-z0-9_:-]+)(\s+(.*?))?(\/)?>$/) {
	    $res .= "$indent<".red($1);
	    for $at (split / /, $3) {
		my ($name,$val) = split /=/, $at, 2;
		$res .= "\n$indent    $name=".yely($val);
	    }
	    if ($4) {
		$res .= "/>\n";   
	    } else {
		$res .= ">\n";   
		$indent .= '  ';
	    }
	} else {
	    die "unprocessable start tag($x)";
	}
    }
    return $res;
}

print xml_pretty($xml);

__END__
