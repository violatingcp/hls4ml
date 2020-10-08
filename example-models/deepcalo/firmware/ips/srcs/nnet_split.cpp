#include <iostream>

#include "_split.hpp"
#include "layer_params.h"


void nnet_split( 
        hls::stream<INPUT_T> input[N], 
        hls::stream<LAYER_T> output_1[N],
        hls::stream<LAYER_T> output_2[N]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output_1
#pragma HLS INTERFACE axis both port=output_2

#pragma HLS DATAFLOW

  _split<INPUT_T, LAYER_T, CONFIG, N> (input, output_1, output_2) ;

}
