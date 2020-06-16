set arg_0 "-I . -DN_1=N_FILT_12 -DN_2=N_FILT_12"
set arg_1 "-DCONFIG=config16"
set arg_2 "-DINPUT_1_T=layer13_t -DINPUT_2_T=layer15_t -DLAYER_T=layer17_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type add


source ../common/build.tcl

