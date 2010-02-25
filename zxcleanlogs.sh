#!/bin/sh
# 19.2.2010, Sampo Kellomaki (sampo@iki.fi)
# Clean away audit trail (looses audit trail, but saves space)
#
# Usage: ./zxcleanlogs.sh     # By default cleans /var/zxid/
#        ./zxcleanlogs.sh /var/zxid/idp

ZXID_PATH=$1
if [ "x$ZXID_PATH" = "x" ] ; then ZXID_PATH=/var/zxid/; fi

ZXDEL='ses/* log/act log/err log/rely/* log/issue/* tmp/*'

for d in $ZXDEL; do
  echo $ZXID_PATH$d
  rm -rf $ZXID_PATH$d
done

#EOF