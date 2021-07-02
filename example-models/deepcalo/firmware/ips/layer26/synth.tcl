set arg_0 "-I . -DN_INPUT=N_FILT_22 -DN_OUTPUT=N_FILT_26"
set arg_1 "-DCONFIG=config26"
set arg_2 "-DINPUT_T=layer25_t -DLAYER_T=layer26_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_channels_last


source ../common/build.tcl

