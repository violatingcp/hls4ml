set arg_0 "-I . -DN_1=N_OUTPUTS_4*N_FILT_4 -DN_2=N_OUTPUTS_4*N_FILT_4"
set arg_1 "-DCONFIG=relu_config5"
set arg_2 "-DINPUT_T=layer4_t -DLAYER_T=layer5_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type relu_stream


source ../common/build.tcl

