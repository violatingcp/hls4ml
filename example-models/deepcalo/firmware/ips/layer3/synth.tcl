set arg_0 "-I . -DN_1=N_CHANNEL_2 -DN_2=4"
set arg_1 "-DCONFIG=config3"
set arg_2 "-DINPUT_T=layer2_t -DLAYER_T=layer3_t"
set arg_3 "-DWEIGHTS=s3  -DBIASES=b3"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type normalize


source ../common/build.tcl

