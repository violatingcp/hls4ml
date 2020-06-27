set arg_0 "-I . -DN_INPUT=N_FILT_138 -DN_OUTPUT=N_FILT_142"
set arg_1 "-DCONFIG=config142"
set arg_2 "-DINPUT_T=layer190_t -DLAYER_T=layer144_t"
set arg_3 "-DN_WEIGHTS=524288 -DWEIGHTS=w142  -DBIASES=b142"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

