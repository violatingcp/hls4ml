#include <iostream>

#include "_conv_2d_large_cl.hpp"
#include "layer_params.h"


void conv_2d_large_cl_port( 
        hls::stream<INPUT_T> input[N_INPUT], 
        hls::stream<LAYER_T> output[N_OUTPUT],
        model_weightdefault_t WEIGHTS[N_WEIGHTS]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


  _conv_2d_large_cl<INPUT_T, LAYER_T, CONFIG, N_INPUT, N_OUTPUT> (input, output, WEIGHTS, BIASES) ;

}
