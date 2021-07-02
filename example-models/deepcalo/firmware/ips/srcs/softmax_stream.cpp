#include <iostream>

#include "_softmax_stream.hpp"
#include "layer_params.h"


void softmax_stream( 
        hls::stream<INPUT_T> input[N_1], 
        hls::stream<LAYER_T> output[N_2]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


  _softmax_stream<INPUT_T, LAYER_T, CONFIG, N_1, N_2> (input, output) ;

}
