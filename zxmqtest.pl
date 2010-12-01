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

/usr/src/qpidc-0.6

  - Advanced Message Queuing Protocol
    - http://jira.amqp.org/ (AMQP wiki)
    - 0MQ http://www.zeromq.org/  (LGPL)  (zmq-1.0.1.tar.gz, zeromq-2.0-alpha3.tar.gz)
    - http://qpid.apache.org/ (qpid-cpp-0.5.tar.gz)
    - http://www.rabbitmq.com/download.html

[AMQP06] "AMQP: A General-Purpose Middleware Standard" (a.k.a Advanced Message Queueing Protocol), 2006. File: amqp.0-10.pdf

/home/sampo/tas3/arch/amqp.0-10.pdf

--Sampo
