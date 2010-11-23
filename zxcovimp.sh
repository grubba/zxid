#!/bin/sh
# 20101122 sampo@iki.fi
# Silly tests just to improve test coverage

./zxcall -dc -din 2 -q -v --
./zxcall -s FOO
./zxcot -q -v -a -- </dev/null
echo foo | ./zxdecode -sha1 -q -v --
echo foo | ./zxdecode -d -b -z -i 2 --  # Dumps core
./zxencdectest -h -q -v --
./zxencdectest -license
./zxencdectest -r 1 <t/ibm-enc-a7n.xml  # Dumps core
./zxencdectest -r 2
./zxididp -h --
./zxpasswd -q -v --
./zxlogview -q -v -- </dev/null

#EOF