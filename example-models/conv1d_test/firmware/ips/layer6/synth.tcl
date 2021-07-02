set arg_0 "-I . -DN_1=248 -DN_2=32"
set arg_1 "-DCONFIG=config6"
set arg_2 "-DINPUT_T=layer5_t -DLAYER_T=layer6_t"
set arg_3 "-DN_WEIGHTS=128 -DWEIGHTS=w6  -DBIASES=b6"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

