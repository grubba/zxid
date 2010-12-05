#!/bin/sh
# 20101122 sampo@iki.fi
# Silly tests just to improve test coverage
# http://sp1.zxidsp.org:8081/zxidhlo?o=E
# http://sp.tas3.pt:8080/zxidservlet/appdemo
# http://idp.tas3.pt:8081/zxididp?o=F
# gprof zxcall

./zxcall -dc -din 2 -q -v --
./zxcall -s FOO
./zxcall -s FOO -l
./zxcall -n -u 'http://localhost/'
./zxcot -q -v -a -- </dev/null
echo foo | ./zxdecode -sha1 -q -v --
echo foo | ./zxdecode -d -b -z -i 2 --  # Dumps core
./zxdecode -d -i 2 </dev/null
./zxdecode -d -i 2 -b -B -z -Z </dev/null
./zxencdectest -h -q -v --
./zxencdectest -d -di test -q -v -rf -rg -ra -wo /tmp -rand /tmp -egd /tmp -uid 1111 -- </dev/null
./zxencdectest -license
./zxencdectest -r 1 <t/ibm-enc-a7n.xml  # Dumps core
./zxencdectest -r 2
./zxididp -h --
./zxpasswd -d -s foo # too few args
./zxpasswd -q -v --
./zxpasswd -d -l foo /impossible
./zxpasswd -l
echo -n 60e1cbb066c6c5179defd4974303dd33 | ./zxpasswd -t y -c testy tmp/test/
echo -n 60e1cbb066c6c5179defd4974303dd33 | ./zxpasswd -t x -c testy tmp/test/
echo -n 60e1cbb066c6c5179defd4974303dd33 | ./zxpasswd -t x -c testy2 tmp/test/
./zxlogview -q -v -- </dev/null
./zxlogview -d -di test -rf -ra </dev/null
./zxcot -c PATH=/foo -d -dc
./zxcot -e http://localhost Abstract http://localhost urn:x-testi | ./zxcot -n -b
./zxcot /impossible
rm -rf tmp/test
./zxmkdirs.sh tmp/test/
./zxcot -c PATH=tmp/test/ -m

#EOF