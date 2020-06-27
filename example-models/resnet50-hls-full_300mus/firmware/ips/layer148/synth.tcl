set arg_0 "-I . -DN_INPUT=N_FILT_145 -DN_OUTPUT=N_FILT_148"
set arg_1 "-DCONFIG=config148"
set arg_2 "-DINPUT_T=layer147_t -DLAYER_T=layer149_t"
set arg_3 "-DN_WEIGHTS=1048576 -DWEIGHTS=w148  -DBIASES=b148"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

