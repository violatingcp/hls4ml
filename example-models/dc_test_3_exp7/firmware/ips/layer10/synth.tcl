set arg_0 "-I . -DN_1=144 -DN_2=16"
set arg_1 "-DCONFIG=config10"
set arg_2 "-DINPUT_T=layer9_t -DLAYER_T=layer10_t"
set arg_3 "-DN_WEIGHTS=2304 -DWEIGHTS=w10  -DBIASES=b10"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

