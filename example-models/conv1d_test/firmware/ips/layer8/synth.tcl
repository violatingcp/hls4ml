set arg_0 "-I . -DN_1=33 -DN_2=32"
set arg_1 "-DCONFIG=config8"
set arg_2 "-DINPUT_T=layer7_t -DLAYER_T=layer8_t"
set arg_3 "-DN_WEIGHTS=1024 -DWEIGHTS=w8  -DBIASES=b8"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

