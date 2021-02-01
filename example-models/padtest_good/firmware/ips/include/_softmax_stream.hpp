#ifndef _SOFTMAX_STREAM_HPP
#define _SOFTMAX_STREAM_HPP

#include <iostream>

#include "../../parameters.h"


template <class _INPUT_T, class _LAYER_T, typename _CONFIG, int _N_1, int _N_2> 
void _softmax_stream( 
        hls::stream<_INPUT_T> input[_N_1], 
        hls::stream<_LAYER_T> output[_N_2]
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW


//static int num_pixels_input = 0;
//static int num_pixels_output = 0;
    
//#if LOG_LEVEL > 0
//    if(!input[0].empty()){
//      num_pixels_input++;
//      //std::cout << "CONV_INPUT PIXEL: " << num_pixels_input << std::endl;
//      //for(int k=0; k<_N_INPUT; k++){
//      //  _INPUT_T val = input[k].read();
//      //  std::cout << "CONV_INPUT[" << k << "]: " << std::hex << val.range() << std::dec << std::endl; 
//      //  input[k].write(val);
//      //}
//    }
//#endif
        
        
    if(!input[0].empty()){
      //std::cout << "RUNNING CONV" << std::endl;
      nnet::softmax_stream<_INPUT_T,_LAYER_T,_CONFIG>(input,output);

    }

//#if LOG_LEVEL > 0
//    if(!output[0].empty()){
//      num_pixels_output++;
//      std::cout << "CONV_OUTPUT PIXEL: " << std::dec << num_pixels_output << std::endl;
//      for(int k=0; k<_N_OUTPUT; k++){
//        _LAYER_T val = output[k].read();
//        std::cout << "CONV_OUTPUT[" << k << "]: " << std::hex << val.range() << std::dec << std::endl; 
//        output[k].write(val);
//      }
//
//    }
//#endif

    //std::cout << "END CONV" << std::endl;

}
#endif
