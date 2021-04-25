set arg_0 "-I . -DN_1=257 -DN_2=256"
set arg_1 "-DCONFIG=config48"
set arg_2 "-DINPUT_T=layer47_t -DLAYER_T=layer48_t"
set arg_3 "-DN_WEIGHTS=65536 -DWEIGHTS=w48  -DBIASES=b48"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

