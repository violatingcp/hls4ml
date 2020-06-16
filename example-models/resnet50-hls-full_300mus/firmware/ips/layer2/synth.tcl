set arg_0 "-I . -DN_INPUT=N_INPUT_1_1 -DN_OUTPUT=N_FILT_2"
set arg_1 "-DCONFIG=config2"
set arg_2 "-DINPUT_T=input_t -DLAYER_T=layer4_t"
set arg_3 "-DN_WEIGHTS=4704 -DWEIGHTS=w2  -DBIASES=b2"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

