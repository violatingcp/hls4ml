set arg_0 "-I . -DN_1=257 -DN_2=1"
set arg_1 "-DCONFIG=config52"
set arg_2 "-DINPUT_T=layer51_t -DLAYER_T=layer52_t"
set arg_3 "-DN_WEIGHTS=256 -DWEIGHTS=w52  -DBIASES=b52"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

