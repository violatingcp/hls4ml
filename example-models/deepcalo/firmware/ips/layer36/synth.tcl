set arg_0 "-I . -DN_INPUT=N_FILT_35 -DN_OUTPUT=N_FILT_36"
set arg_1 "-DCONFIG=config36"
set arg_2 "-DINPUT_T=layer35_t -DLAYER_T=layer39_t"
set arg_3 "-DN_WEIGHTS=294912 -DWEIGHTS=w36  -DBIASES=b36"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

