set arg_0 "-I . -DN_INPUT=N_FILT_112 -DN_OUTPUT=N_FILT_115"
set arg_1 "-DCONFIG=config115"
set arg_2 "-DINPUT_T=layer114_t -DLAYER_T=layer117_t"
set arg_3 "-DN_WEIGHTS=589824 -DWEIGHTS=w115  -DBIASES=b115"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

