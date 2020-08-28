#include <iostream>

#include "_pooling2d_cl_1x1.hpp"


void pooling2d_cl_1x1( 
        hls::stream<INPUT_T> input[N_INPUT], 
        hls::stream<LAYER_T> output[N_OUTPUT]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


  _pooling2d_cl_1x1<INPUT_T, LAYER_T, CONFIG, N_INPUT, N_OUTPUT> (input, output) ;

}
