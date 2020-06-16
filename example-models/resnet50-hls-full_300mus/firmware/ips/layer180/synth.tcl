set arg_0 "-I . -DN=N_FILT_34" 
set arg_1 "-DCONFIG=config180"
set arg_2 "-DINPUT_T=layer37_t -DLAYER_T=layer180_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type nnet_split


source ../common/build.tcl

