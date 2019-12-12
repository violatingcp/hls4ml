#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/pharris/tmp3/test_hack7/hls4ml/example-models/resnet50-hls/myproject_prj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
