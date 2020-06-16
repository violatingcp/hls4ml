set arg_0 "-I . -DN_INPUT=N_FILT_66 -DN_OUTPUT=N_FILT_70"
set arg_1 "-DCONFIG=config70"
set arg_2 "-DINPUT_T=layer183_t -DLAYER_T=layer72_t"
set arg_3 "-DN_WEIGHTS=32768 -DWEIGHTS=w70  -DBIASES=b70"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

