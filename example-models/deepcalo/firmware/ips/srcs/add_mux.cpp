#include <iostream>

#include "_add_mux.hpp"
#include "layer_params.h"


void add_mux( 
        hls::stream<INPUT_1_T> input_1[N_1], 
        hls::stream<INPUT_2_T> input_2[N_2],
        hls::stream<LAYER_T> output[N_1]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input_1
#pragma HLS INTERFACE axis both port=input_2
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW

  _add_mux<INPUT_1_T, INPUT_2_T, LAYER_T, CONFIG, N_1, N_2> (input_1, input_2, output) ;

}
