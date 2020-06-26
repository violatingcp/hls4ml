set arg_0 "-I . -DN_INPUT=N_FILT_105 -DN_OUTPUT=N_FILT_108"
set arg_1 "-DCONFIG=config108"
set arg_2 "-DINPUT_T=layer107_t -DLAYER_T=layer109_t"
set arg_3 "-DN_WEIGHTS=262144 -DWEIGHTS=w108  -DBIASES=b108"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

