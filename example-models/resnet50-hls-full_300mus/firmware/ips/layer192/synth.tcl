set arg_0 "-I . -DN=N_FILT_160" 
set arg_1 "-DCONFIG=config192"
set arg_2 "-DINPUT_T=layer163_t -DLAYER_T=layer192_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type nnet_split


source ../common/build.tcl

