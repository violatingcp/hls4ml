set arg_0 "-I . -DN_INPUT=N_FILT_128 -DN_OUTPUT=N_FILT_132"
set arg_1 "-DCONFIG=config132"
set arg_2 "-DINPUT_T=layer189_t -DLAYER_T=layer134_t"
set arg_3 "-DN_WEIGHTS=131072 -DWEIGHTS=w132  -DBIASES=b132"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

