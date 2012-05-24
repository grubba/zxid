#!/bin/sh
# 20120524 sampo@synergetics.be
# This shell script sets local environment variables right for compliation.
# It tends to be needed in Sampo's complex environment where there are
# choices of compilers at different paths, etc. Others can just say `make'

LIBRARY_PATH=/usr/lib/i386-linux-gnu:/lib/i386-linux-gnu PATH=/usr/bin:/bin make $*

#EOF