set arg_0 "-I . -DN_INPUT=N_FILT_5 -DN_OUTPUT=N_FILT_7"
set arg_1 "-DCONFIG=config7"
set arg_2 "-DINPUT_T=layer6_t -DLAYER_T=layer7_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_channels_last


source ../common/build.tcl

