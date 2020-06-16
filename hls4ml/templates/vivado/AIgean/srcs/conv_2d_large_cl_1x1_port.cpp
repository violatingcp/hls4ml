#include <iostream>

#include "_conv_2d_large_cl_1x1.hpp"
#include "layer_params.h"


void conv_2d_large_cl_1x1_port( 
        hls::stream<INPUT_T> input[N_INPUT], 
        hls::stream<LAYER_T> output[N_OUTPUT],
        model_default_t WEIGHTS[N_WEIGHTS]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


  _conv_2d_large_cl_1x1<INPUT_T, LAYER_T, CONFIG, N_INPUT, N_OUTPUT> (input, output, WEIGHTS, BIASES) ;

}
