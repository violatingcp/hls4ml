set arg_0 "-I . -DN_INPUT=N_FILT_53 -DN_OUTPUT=N_FILT_56"
set arg_1 "-DCONFIG=config56"
set arg_2 "-DINPUT_T=layer55_t -DLAYER_T=layer57_t"
set arg_3 "-DN_WEIGHTS=32768 -DWEIGHTS=w56  -DBIASES=b56"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

