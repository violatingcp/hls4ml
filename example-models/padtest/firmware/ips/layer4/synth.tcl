set arg_0 "-I . -DN_1=OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2 -DN_2=OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2"
set arg_1 "-DCONFIG=Relu_config4"
set arg_2 "-DINPUT_T=layer3_t -DLAYER_T=layer4_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type Relu_stream


source ../common/build.tcl

