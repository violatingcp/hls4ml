set arg_0 "-I . -DN_INPUT=N_FILT_17 -DN_OUTPUT=N_FILT_18"
set arg_1 "-DCONFIG=config18"
set arg_2 "-DINPUT_T=layer17_t -DLAYER_T=layer21_t"
set arg_3 "-DN_WEIGHTS=18432 -DWEIGHTS=w18  -DBIASES=b18"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

