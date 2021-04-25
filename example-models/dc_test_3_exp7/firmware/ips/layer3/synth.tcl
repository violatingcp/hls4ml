set arg_0 "-I . -DN_1=OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2 -DN_2=OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2"
set arg_1 "-DCONFIG=relu_config3"
set arg_2 "-DINPUT_T=layer2_t -DLAYER_T=layer3_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type relu_stream


source ../common/build.tcl

