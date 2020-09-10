set arg_0 "-I . -DN_1=N_LAYER_14 -DN_2=N_LAYER_14"
set arg_1 "-DCONFIG=relu_config15"
set arg_2 "-DINPUT_T=layer14_t -DLAYER_T=layer15_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type relu_stream


source ../common/build.tcl

