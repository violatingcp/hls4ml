set arg_0 "-I . -DN_INPUT=N_FILT_18 -DN_OUTPUT=N_FILT_22"
set arg_1 "-DCONFIG=config22"
set arg_2 "-DINPUT_T=layer21_t -DLAYER_T=layer25_t"
set arg_3 "-DN_WEIGHTS=36864 -DWEIGHTS=w22  -DBIASES=b22"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_large_channels_last_port


source ../common/build.tcl

