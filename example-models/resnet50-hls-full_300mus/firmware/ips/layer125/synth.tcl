set arg_0 "-I . -DN_INPUT=N_FILT_122 -DN_OUTPUT=N_FILT_125"
set arg_1 "-DCONFIG=config125"
set arg_2 "-DINPUT_T=layer124_t -DLAYER_T=layer127_t"
set arg_3 "-DN_WEIGHTS=589824 -DWEIGHTS=w125  -DBIASES=b125"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

