set arg_0 "-I . -DN_INPUT=N_FILT_9 -DN_OUTPUT=N_FILT_13"
set arg_1 "-DCONFIG=config13"
set arg_2 "-DINPUT_T=layer12_t -DLAYER_T=layer16_t"
set arg_3 "-DN_WEIGHTS=9216 -DWEIGHTS=w13  -DBIASES=b13"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

