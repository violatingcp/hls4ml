set arg_0 "-I . -DN_1=2048 -DN_2=1000"
set arg_1 "-DCONFIG=config175"
set arg_2 "-DINPUT_T=layer174_t -DLAYER_T=layer175_t"
set arg_3 "-DN_WEIGHTS=1024000 -DWEIGHTS=w175  -DBIASES=b175"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_large


source ../common/build.tcl

