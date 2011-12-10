#!/bin/sh

echo "Content-Type: text/plain"
echo "Set-Cookie: envtest=foo; path=/; secure;"
echo
pwd
env | sort
ulimit -a
id
cat /proc/sys/kernel/core_pattern
