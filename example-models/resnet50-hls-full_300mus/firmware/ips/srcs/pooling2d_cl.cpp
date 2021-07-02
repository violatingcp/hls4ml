#include <iostream>

#include "_pooling2d_cl.hpp"


void pooling2d_cl( 
        hls::stream<INPUT_T> input[N_INPUT], 
        hls::stream<LAYER_T> output[N_OUTPUT]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


  _pooling2d_cl<INPUT_T, LAYER_T, CONFIG, N_INPUT, N_OUTPUT> (input, output) ;

}
