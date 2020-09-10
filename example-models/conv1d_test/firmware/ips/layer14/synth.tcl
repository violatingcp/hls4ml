set arg_0 "-I . -DN_1=9 -DN_2=8"
set arg_1 "-DCONFIG=config14"
set arg_2 "-DINPUT_T=layer13_t -DLAYER_T=layer14_t"
set arg_3 "-DN_WEIGHTS=3968 -DWEIGHTS=w14  -DBIASES=b14"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

