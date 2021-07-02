set arg_0 "-I . -DN_1=9 -DN_2=4"
set arg_1 "-DCONFIG=config18"
set arg_2 "-DINPUT_T=layer17_t -DLAYER_T=layer18_t"
set arg_3 "-DN_WEIGHTS=32 -DWEIGHTS=w18  -DBIASES=b18"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

