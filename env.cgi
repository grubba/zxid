#!/bin/sh

echo content-type: text/plain
echo
pwd
env | sort
ulimit -a
id
cat /proc/sys/kernel/core_pattern
