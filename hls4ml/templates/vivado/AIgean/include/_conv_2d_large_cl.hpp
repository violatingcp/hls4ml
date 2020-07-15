#ifndef _CONV_2D_LARGE_CL_HPP
#define _CONV_2D_LARGE_CL_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_T, class _LAYER_T, typename _CONFIG, int _N_INPUT, int _N_OUTPUT> 
void _conv_2d_large_cl( 
        hls::stream<_INPUT_T> input[_N_INPUT], 
        hls::stream<_LAYER_T> output[_N_OUTPUT],
        typename _CONFIG::weight_t weights[_CONFIG::filt_height * _CONFIG::filt_width * (_CONFIG::n_chan) * (_CONFIG::n_filt)/_CONFIG::mult_config::merge_factor],
        typename _CONFIG::bias_t biases[_CONFIG::n_filt]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW
        
        
    while(!input[0].empty()){
      nnet::conv_2d_large_cl<_INPUT_T,_LAYER_T,_CONFIG>(input,output, weights, biases);
    }


}
#endif
