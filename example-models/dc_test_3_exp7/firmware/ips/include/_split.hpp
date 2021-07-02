#ifndef _SPLIT_HPP
#define _SPLIT_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_T, class _LAYER_T, typename _CONFIG, int _N> 
void _split( 
        hls::stream<_INPUT_T> input[_N], 
        hls::stream<_LAYER_T> output_1[_N],
        hls::stream<_LAYER_T> output_2[_N]
        ){



        
        
    if(!input[0].empty()){
      //nnet::split<_INPUT_T,_LAYER_T,_CONFIG>(input,output_1, output_2);
      nnet::split<_INPUT_T,_LAYER_T,_CONFIG>(input,output_1, output_2);
      //nnet::split<layer5_t, layer177_t, config177>(input, output_1, output_2);
    }

}
#endif
