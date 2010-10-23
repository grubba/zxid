#!/usr/bin/perl

use Net::SSLeay;

$exchange = 'audit.tas3.nottingham.ac.uk';
$port = 5672;  # default is 5672

$req = pack 'a4CCCC', 'AMQP', 1, 1, 1 ,0;

$tack = 0;
$channel = 0;

# vv00BEbe  = version (00), beginning and end bits at frame and segment level; 0x0f = single frame
$frame_hdr = pack 'CCnCCnN', 0x0f, $seg_type, $len, 0, $track, $channel, 0;

warn "len=".length($req);

#my (    $dest_serv, $port, $out_message, $crt_path, $key_path) = @_;
#my (    $dest_serv, $port, $out_message) = @_;
#my ($usessl, $site, $port, $req,         $crt_path, $key_path) = @_;

$reply = Net::SSLeay::tcpxcat(0, $host, $port, $req);

__END__

tomkirkham2: QPID Broker
[15:25:22] ? 89.200.142.218
[15:25:33] ? port 5671 ssl
[15:25:38] ? port 5672 non ssl
