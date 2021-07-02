set arg_0 "-I . -DN_1=17 -DN_2=10"
set arg_1 "-DCONFIG=config12"
set arg_2 "-DINPUT_T=layer11_t -DLAYER_T=layer12_t"
set arg_3 "-DN_WEIGHTS=160 -DWEIGHTS=w12  -DBIASES=b12"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

