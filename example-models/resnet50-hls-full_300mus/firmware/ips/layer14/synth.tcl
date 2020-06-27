set arg_0 "-I . -DN_INPUT=N_FILT_5 -DN_OUTPUT=N_FILT_14"
set arg_1 "-DCONFIG=config14"
set arg_2 "-DINPUT_T=layer177_t -DLAYER_T=layer15_t"
set arg_3 "-DN_WEIGHTS=16384 -DWEIGHTS=w14  -DBIASES=b14"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

