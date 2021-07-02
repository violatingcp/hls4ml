set arg_0 "-I . -DN_1=N_LAYER_48 -DN_2=N_LAYER_48"
set arg_1 "-DCONFIG=LeakyReLU_config51"
set arg_2 "-DINPUT_T=layer50_t -DLAYER_T=layer51_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type LeakyReLU_stream


source ../common/build.tcl

