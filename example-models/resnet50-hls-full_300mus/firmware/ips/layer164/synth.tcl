set arg_0 "-I . -DN_INPUT=N_FILT_160 -DN_OUTPUT=N_FILT_164"
set arg_1 "-DCONFIG=config164"
set arg_2 "-DINPUT_T=layer192_t -DLAYER_T=layer166_t"
set arg_3 "-DN_WEIGHTS=524288 -DWEIGHTS=w164  -DBIASES=b164"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

