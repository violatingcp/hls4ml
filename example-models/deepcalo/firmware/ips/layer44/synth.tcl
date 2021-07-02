set arg_0 "-I . -DN_1=2304 -DN_2=256"
set arg_1 "-DCONFIG=config44"
set arg_2 "-DINPUT_T=layer43_t -DLAYER_T=layer44_t"
set arg_3 "-DN_WEIGHTS=589824 -DWEIGHTS=w44  -DBIASES=b44"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

