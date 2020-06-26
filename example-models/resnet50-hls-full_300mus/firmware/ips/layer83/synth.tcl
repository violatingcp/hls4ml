set arg_0 "-I . -DN_INPUT=N_FILT_80 -DN_OUTPUT=N_FILT_83"
set arg_1 "-DCONFIG=config83"
set arg_2 "-DINPUT_T=layer82_t -DLAYER_T=layer85_t"
set arg_3 "-DN_WEIGHTS=589824 -DWEIGHTS=w83  -DBIASES=b83"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

