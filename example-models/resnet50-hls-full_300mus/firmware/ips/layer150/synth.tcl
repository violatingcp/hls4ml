set arg_0 "-I . -DN_INPUT=N_FILT_138 -DN_OUTPUT=N_FILT_150"
set arg_1 "-DCONFIG=config150"
set arg_2 "-DINPUT_T=layer190_t -DLAYER_T=layer151_t"
set arg_3 "-DN_WEIGHTS=2097152 -DWEIGHTS=w150  -DBIASES=b150"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

