#include <iostream>

#include "_dense_large.hpp"
#include "layer_params.h"


void dense_large( 
        hls::stream<INPUT_T> input[N_1], 
        hls::stream<LAYER_T> output[N_2],
        model_weightdefault_t WEIGHTS[N_WEIGHTS]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


  _dense_large<INPUT_T, LAYER_T, CONFIG, N_1, N_2> (input, output, WEIGHTS, BIASES) ;

}
