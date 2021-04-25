set arg_0 "-I . -DN_INPUT=N_FILT_7 -DN_OUTPUT=N_FILT_8"
set arg_1 "-DCONFIG=config8"
set arg_2 "-DINPUT_T=layer7_t -DLAYER_T=layer8_t"
set arg_3 "-DN_WEIGHTS=1152 -DWEIGHTS=w8  -DBIASES=b8"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

