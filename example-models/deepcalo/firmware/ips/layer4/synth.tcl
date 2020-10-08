set arg_0 "-I . -DN_INPUT=N_CHANNEL_2 -DN_OUTPUT=N_FILT_4"
set arg_1 "-DCONFIG=config4"
set arg_2 "-DINPUT_T=layer3_t -DLAYER_T=layer7_t"
set arg_3 "-DN_WEIGHTS=1600 -DWEIGHTS=w4  -DBIASES=b4"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

