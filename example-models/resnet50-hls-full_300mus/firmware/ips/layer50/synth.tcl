set arg_0 "-I . -DN_INPUT=N_FILT_44 -DN_OUTPUT=N_FILT_50"
set arg_1 "-DCONFIG=config50"
set arg_2 "-DINPUT_T=layer181_t -DLAYER_T=layer52_t"
set arg_3 "-DN_WEIGHTS=65536 -DWEIGHTS=w50  -DBIASES=b50"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

