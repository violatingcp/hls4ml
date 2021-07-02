#ifndef _RELU_STREAM_HPP
#define _RELU_STREAM_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_T, class _LAYER_T, typename _CONFIG, int _N_1, int _N_2> 
void _relu_stream( 
        hls::stream<_INPUT_T> input[_N_1], 
        hls::stream<_LAYER_T> output[_N_2]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW
        
    if(!input[0].empty()){
      nnet::relu_stream<_INPUT_T,_LAYER_T,_CONFIG>(input,output);

    }

}
#endif
