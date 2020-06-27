set arg_0 "-I . -DN_INPUT=N_FILT_170 -DN_OUTPUT=(N_FILT_174-1)"
set arg_1 "-DCONFIG=config174"
set arg_2 "-DINPUT_T=layer173_t -DLAYER_T=layer174_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_cl_1x1


source ../common/build.tcl

