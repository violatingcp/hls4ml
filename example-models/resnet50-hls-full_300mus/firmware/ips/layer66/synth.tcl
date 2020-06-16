set arg_0 "-I . -DN_INPUT=N_FILT_63 -DN_OUTPUT=N_FILT_66"
set arg_1 "-DCONFIG=config66"
set arg_2 "-DINPUT_T=layer65_t -DLAYER_T=layer67_t"
set arg_3 "-DN_WEIGHTS=32768 -DWEIGHTS=w66  -DBIASES=b66"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

