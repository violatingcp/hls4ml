#ifndef _ADD_HPP
#define _ADD_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_1_T, class _INPUT_2_T, class _LAYER_T, typename _CONFIG, int _N_1, int _N_2> 
void _add( 
        hls::stream<_INPUT_1_T> input_1[_N_1], 
        hls::stream<_INPUT_2_T> input_2[_N_2], 
        hls::stream<_LAYER_T> output[_N_1]
        ){



        
        
    if(!input_1[0].empty()){
      nnet::add<_INPUT_1_T, _INPUT_2_T, _LAYER_T,_CONFIG>(input_1, input_2, output);
    }

}
#endif
