#ifndef _POOLING2D_CL_1X1_HPP
#define _POOLING2D_CL_1X1_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_T, class _LAYER_T, typename _CONFIG, int _N_INPUT, int _N_OUTPUT> 
void _pooling2d_cl_1x1( 
        hls::stream<_INPUT_T> input[_N_INPUT], 
        hls::stream<_LAYER_T> output[_N_OUTPUT]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


        
    if(!input[0].empty()){
      //std::cout << "RUNNING POOL" << std::endl;
      nnet::pooling2d_cl_1x1<_INPUT_T,_LAYER_T,_CONFIG>(input,output);

    }


}
#endif
