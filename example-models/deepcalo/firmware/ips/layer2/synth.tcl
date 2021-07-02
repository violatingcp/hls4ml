set arg_0 "-I . -DN_1=N_INPUT_3_1 -DN_2=N_INPUT_3_1"
set arg_1 "-DCONFIG=config2"
set arg_2 "-DINPUT_T=input_t -DLAYER_T=layer2_t"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type upsampling2d_stream


source ../common/build.tcl

