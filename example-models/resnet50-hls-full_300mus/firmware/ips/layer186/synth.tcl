set arg_0 "-I . -DN=N_FILT_98" 
set arg_1 "-DCONFIG=config186"
set arg_2 "-DINPUT_T=layer101_t -DLAYER_T=layer186_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type nnet_split


source ../common/build.tcl

