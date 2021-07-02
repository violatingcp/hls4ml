set arg_0 "-I . -DN_INPUT=N_INPUT_3_1 -DN_OUTPUT=N_FILT_2"
set arg_1 "-DCONFIG=config2"
set arg_2 "-DINPUT_T=input_t -DLAYER_T=layer2_t"
set arg_3 "-DN_WEIGHTS=36 -DWEIGHTS=w2  -DBIASES=b2"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

