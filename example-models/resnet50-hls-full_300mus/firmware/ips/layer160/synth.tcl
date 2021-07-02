set arg_0 "-I . -DN_INPUT=N_FILT_157 -DN_OUTPUT=N_FILT_160"
set arg_1 "-DCONFIG=config160"
set arg_2 "-DINPUT_T=layer159_t -DLAYER_T=layer161_t"
set arg_3 "-DN_WEIGHTS=1048576 -DWEIGHTS=w160  -DBIASES=b160"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

