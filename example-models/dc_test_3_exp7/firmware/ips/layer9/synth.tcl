set arg_0 "-I . -DN_1=OUT_HEIGHT_8*OUT_WIDTH_8*N_FILT_8 -DN_2=OUT_HEIGHT_8*OUT_WIDTH_8*N_FILT_8"
set arg_1 "-DCONFIG=relu_config9"
set arg_2 "-DINPUT_T=layer8_t -DLAYER_T=layer9_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type relu_stream


source ../common/build.tcl

