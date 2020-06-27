set arg_0 "-I . -DN_INPUT=N_FILT_142 -DN_OUTPUT=N_FILT_145"
set arg_1 "-DCONFIG=config145"
set arg_2 "-DINPUT_T=layer144_t -DLAYER_T=layer147_t"
set arg_3 "-DN_WEIGHTS=2359296 -DWEIGHTS=w145  -DBIASES=b145"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

