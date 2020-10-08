set arg_0 "-I . -DN_1=OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5 -DN_2=OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5"
set arg_1 "-DCONFIG=relu_config6"
set arg_2 "-DINPUT_T=layer5_t -DLAYER_T=layer6_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type relu_stream


source ../common/build.tcl

