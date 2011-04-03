#!/bin/sh
id >>/tmp/debug
LD_LIBRARY_PATH=/apps/lib ZXID_CONF=PATH=/home/sampo/zxid/postoffice/conf/idp ../zxididp
