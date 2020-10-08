set arg_0 "-I . -DN_INPUT=N_FILT_36 -DN_OUTPUT=N_FILT_40"
set arg_1 "-DCONFIG=config40"
set arg_2 "-DINPUT_T=layer39_t -DLAYER_T=layer43_t"
set arg_3 "-DN_WEIGHTS=589824 -DWEIGHTS=w40  -DBIASES=b40"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

