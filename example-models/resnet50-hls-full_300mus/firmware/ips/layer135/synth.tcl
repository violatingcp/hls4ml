set arg_0 "-I . -DN_INPUT=N_FILT_132 -DN_OUTPUT=N_FILT_135"
set arg_1 "-DCONFIG=config135"
set arg_2 "-DINPUT_T=layer134_t -DLAYER_T=layer137_t"
set arg_3 "-DN_WEIGHTS=294912 -DWEIGHTS=w135  -DBIASES=b135"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

