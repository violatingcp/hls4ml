set arg_0 "-I . -DN_INPUT=N_FILT_4 -DN_OUTPUT=N_FILT_5"
set arg_1 "-DCONFIG=config5"
set arg_2 "-DINPUT_T=layer4_t -DLAYER_T=layer5_t"
set arg_3 "-DN_WEIGHTS=288 -DWEIGHTS=w5  -DBIASES=b5"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

