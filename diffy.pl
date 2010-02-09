#!/usr/bin/perl
# 2.2.2010, Sampo Kellomaki (sampo@iki.fi)
# $Id$
#
# Usage: ./diffy.pl file1 file2

sub diff {
    my ($a, $b) = @_;
    my @a = split /\n/, $a;
    my @b = split /\n/, $b;
    print "\t- reference output\n\t+ testrun\n";
    my $i,$j,$n=10;
    print "\toutputs differ in length ($#a vs. $#b)\n" if $#a != $#b;
    for ($i=0, $j=0; $i <= $#a && $j <= $#b; ++$i, ++$j) {
	next if $a[$i] eq $b[$j];
	if (!--$n) {
	    print "\tToo many differences. Output truncated. Run real diff.\n";
	    last;
	}
	$a[$i] = substr($a[$i],0,80);
	$b[$j] = substr($b[$j],0,80);
	if ($a[$i+1] eq $b[$j]) {       # Extra line in a
	    print "\t".($i+1).": - $a[$i]\n";
	    ++$i;
	} elsif ($a[$i] eq $b[$j+1]) {  # Extra line in b
	    print "\t".($j+1).": + $b[$j]\n";
	    ++$j;
	} else {
	    print "\t".($i+1).": - $a[$i]\n\t".($j+1).": + $b[$j]\n";
	}
    }
    if ($n) {
	for (; $i <= $#a; ++$i) {
	    if (!--$n) {
		print "\tToo many differences. Output truncated. Run real diff.\n";
		last;
	    }
	    print "\t".($i+1).": - $a[$i]\n";
	}
    }
    if ($n) {
	for (; $j <= $#b; ++$j) {
	    if (!--$n) {
		print "\tToo many differences. Output truncated. Run real diff.\n";
		last;
	    }
	    print "\t".($j+1).": - $a[$j]\n";
	}
    }
}

$line_len = 160;

sub char_diff {
    my ($a, $b) = @_;
    my @a = split //, $a;
    my @b = split //, $b;
    my ($i, $j, $a_line, $b_line, $diff_line);
    for ($i = $j = 0; $i <= $#a && $j <= $#b; ++$i, ++$j) {
	#warn "CHAR $i $j  $a[$i]  $b[$j]  " . (($a[$i] eq $b[$j])?'':'***');
	if (length $diff_line >= $line_len) {
	    print "$a_line\n";
	    print "$b_line\n";
	    print "$diff_line\n";
	    $a_line = $b_line = $diff_line = '';
	}
	$a_line .= $a[$i];
	$b_line .= $b[$j];
	if ($a[$i] eq $b[$j]) {
	    $diff_line .= ' ';
	} else {
	    $diff_line .= '*';
	}
    }

    print "$a_line\n";
    print "$b_line\n";
    print "$diff_line\n";
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

($file1, $file2) = @ARGV;

$data1 = readall $file1;
$data2 = readall $file2;

char_diff($data1, $data2);
#diff($data1, $data2);

__END__
