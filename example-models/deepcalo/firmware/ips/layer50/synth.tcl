set arg_0 "-I . -DN_1=N_LAYER_48 -DN_2=-1"
set arg_1 "-DCONFIG=config50"
set arg_2 "-DINPUT_T=layer48_t -DLAYER_T=layer50_t"
set arg_3 "-DWEIGHTS=s50  -DBIASES=b50"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type normalize


source ../common/build.tcl

