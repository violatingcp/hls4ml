set arg_0 "-I . -DN_INPUT=N_FILT_148 -DN_OUTPUT=N_FILT_154"
set arg_1 "-DCONFIG=config154"
set arg_2 "-DINPUT_T=layer191_t -DLAYER_T=layer156_t"
set arg_3 "-DN_WEIGHTS=1048576 -DWEIGHTS=w154  -DBIASES=b154"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

