set arg_0 "-I . -DN_INPUT=N_FILT_164 -DN_OUTPUT=N_FILT_167"
set arg_1 "-DCONFIG=config167"
set arg_2 "-DINPUT_T=layer166_t -DLAYER_T=layer169_t"
set arg_3 "-DN_WEIGHTS=1179648 -DWEIGHTS=w167  -DBIASES=b167"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_cl_port


source ../common/build.tcl

