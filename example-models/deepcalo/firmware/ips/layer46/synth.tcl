set arg_0 "-I . -DN_1=N_LAYER_44 -DN_2=-1"
set arg_1 "-DCONFIG=config46"
set arg_2 "-DINPUT_T=layer44_t -DLAYER_T=layer46_t"
set arg_3 "-DWEIGHTS=s46  -DBIASES=b46"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type normalize


source ../common/build.tcl

