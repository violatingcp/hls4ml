set arg_0 "-I . -DN_INPUT=N_FILT_38 -DN_OUTPUT=N_FILT_41"
set arg_1 "-DCONFIG=config41"
set arg_2 "-DINPUT_T=layer40_t -DLAYER_T=layer43_t"
set arg_3 "-DN_WEIGHTS=147456 -DWEIGHTS=w41  -DBIASES=b41"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

