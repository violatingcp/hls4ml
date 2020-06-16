set arg_0 "-I . -DN=N_FILT_5" 
set arg_1 "-DCONFIG=config177"
set arg_2 "-DINPUT_T=layer5_t -DLAYER_T=layer177_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type nnet_split


source ../common/build.tcl

