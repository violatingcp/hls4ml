set arg_0 "-I . -DN_INPUT=N_FILT_8 -DN_OUTPUT=N_FILT_9"
set arg_1 "-DCONFIG=config9"
set arg_2 "-DINPUT_T=layer8_t -DLAYER_T=layer12_t"
set arg_3 "-DN_WEIGHTS=4608 -DWEIGHTS=w9  -DBIASES=b9"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl
