set arg_0 "-I . -DN_INPUT=32 -DN_OUTPUT=32"
set arg_1 "-DCONFIG=config5"
set arg_2 "-DINPUT_T=layer4_t -DLAYER_T=layer5_t"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pad_cl


source ../common/build.tcl

