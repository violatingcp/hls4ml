set arg_0 "-I . -DN_INPUT=N_FILT_31 -DN_OUTPUT=N_FILT_34"
set arg_1 "-DCONFIG=config34"
set arg_2 "-DINPUT_T=layer33_t -DLAYER_T=layer35_t"
set arg_3 "-DN_WEIGHTS=8192 -DWEIGHTS=w34  -DBIASES=b34"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

