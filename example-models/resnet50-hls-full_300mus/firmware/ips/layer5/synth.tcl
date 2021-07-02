set arg_0 "-I . -DN_INPUT=N_FILT_2 -DN_OUTPUT=N_FILT_5"
set arg_1 "-DCONFIG=config5"
set arg_2 "-DINPUT_T=layer4_t -DLAYER_T=layer5_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_cl


source ../common/build.tcl

