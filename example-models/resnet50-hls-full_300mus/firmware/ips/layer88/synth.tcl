set arg_0 "-I . -DN_INPUT=N_FILT_76 -DN_OUTPUT=N_FILT_88"
set arg_1 "-DCONFIG=config88"
set arg_2 "-DINPUT_T=layer184_t -DLAYER_T=layer89_t"
set arg_3 "-DN_WEIGHTS=524288 -DWEIGHTS=w88  -DBIASES=b88"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

