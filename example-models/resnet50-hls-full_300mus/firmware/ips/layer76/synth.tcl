set arg_0 "-I . -DN_INPUT=N_FILT_73 -DN_OUTPUT=N_FILT_76"
set arg_1 "-DCONFIG=config76"
set arg_2 "-DINPUT_T=layer75_t -DLAYER_T=layer77_t"
set arg_3 "-DN_WEIGHTS=65536 -DWEIGHTS=w76  -DBIASES=b76"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_1x1_port


source ../common/build.tcl

