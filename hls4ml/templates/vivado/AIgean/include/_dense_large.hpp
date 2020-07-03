#ifndef _DENSE_LARGE_HPP
#define _DENSE_LARGE_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_T, class _LAYER_T, typename _CONFIG, int _N_1, int _N_2> 
void _dense_large( 
        hls::stream<_INPUT_T> input[_N_1], 
        hls::stream<_LAYER_T> output[_N_2],
        typename _CONFIG::weight_t weights[_CONFIG::n_in * _CONFIG::n_out/_CONFIG::merge_factor],
        typename _CONFIG::bias_t biases[_CONFIG::n_out]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW

    if(!input[0].empty()){
      nnet::dense_large_stream<_INPUT_T,_LAYER_T,_CONFIG>(input,output, weights, biases);

    }

}
#endif
