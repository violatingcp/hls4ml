set arg_0 "-I . -DN_1=N_LAYER_44 -DN_2=N_LAYER_44"
set arg_1 "-DCONFIG=LeakyReLU_config47"
set arg_2 "-DINPUT_T=layer46_t -DLAYER_T=layer47_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type LeakyReLU_stream


source ../common/build.tcl

