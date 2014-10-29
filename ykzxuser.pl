#!/usr/bin/perl
# 20091214 Sampo Kellomaki (sampo@iki.fi)
#
# echo '0059181 beefvj 00000000e72d 3a14906fa4d6838a50 jvh' | ykzxuser.pl

$uiddir = shift || '/var/zxid/idpuid';

while ($x = <STDIN>) {
    ($yknum, $extuid, $intuid, $key, $who) = split /\s+/, $x, 5;
    system "echo -n $key | ./zxpasswd -d -t y -new $extuid $uiddir";
    system "mkdir $uiddir/$extuid/.bs";
    system "echo 'cn: $who' >$uiddir/$extuid/.bs/.at";
}

__END__
