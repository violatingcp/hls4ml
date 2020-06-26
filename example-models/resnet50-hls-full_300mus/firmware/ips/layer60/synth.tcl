set arg_0 "-I . -DN_INPUT=N_FILT_56 -DN_OUTPUT=N_FILT_60"
set arg_1 "-DCONFIG=config60"
set arg_2 "-DINPUT_T=layer182_t -DLAYER_T=layer62_t"
set arg_3 "-DN_WEIGHTS=65536 -DWEIGHTS=w60  -DBIASES=b60"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

