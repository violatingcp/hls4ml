set arg_0 "-I . -DN_INPUT=N_FILT_154 -DN_OUTPUT=N_FILT_157"
set arg_1 "-DCONFIG=config157"
set arg_2 "-DINPUT_T=layer156_t -DLAYER_T=layer159_t"
set arg_3 "-DN_WEIGHTS=2359296 -DWEIGHTS=w157  -DBIASES=b157"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

