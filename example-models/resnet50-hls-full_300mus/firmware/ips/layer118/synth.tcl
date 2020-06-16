set arg_0 "-I . -DN_INPUT=N_FILT_115 -DN_OUTPUT=N_FILT_118"
set arg_1 "-DCONFIG=config118"
set arg_2 "-DINPUT_T=layer117_t -DLAYER_T=layer119_t"
set arg_3 "-DN_WEIGHTS=131072 -DWEIGHTS=w118  -DBIASES=b118"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

