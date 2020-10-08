set arg_0 "-I . -DN_INPUT=N_FILT_26 -DN_OUTPUT=N_FILT_27"
set arg_1 "-DCONFIG=config27"
set arg_2 "-DINPUT_T=layer26_t -DLAYER_T=layer30_t"
set arg_3 "-DN_WEIGHTS=73728 -DWEIGHTS=w27  -DBIASES=b27"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

