set arg_0 "-I . -DN_INPUT=N_FILT_2 -DN_OUTPUT=N_FILT_4"
set arg_1 "-DCONFIG=config4"
set arg_2 "-DINPUT_T=layer3_t -DLAYER_T=layer4_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_channels_last


source ../common/build.tcl

