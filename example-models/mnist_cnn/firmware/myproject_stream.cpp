//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>

#include "myproject_stream.h"

//hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/w4.h"
#include "weights/b4.h"
//#include "weights/w7.h"
//#include "weights/b7.h"
//#include "weights/w9.h"
//#include "weights/b9.h"

void myproject(
    input_t  input[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer10_out[N_LAYER_9],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=input1 complete dim=0 
    #pragma HLS ARRAY_RESHAPE variable=layer10_out complete dim=0 
    #pragma HLS INTERFACE ap_vld port=input1,layer10_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
    const_size_out_1 = N_LAYER_9;

    layer7_t layer7_full[OUT_WIDTH_6*OUT_HEIGHT_6*N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer7_full block factor=64
    unsigned index=0; 

    hls::stream<input_t>   sInput  [N_INPUT_3_1];
    hls::stream<result_t>  sOutput [N_FILT_6];
    #pragma HLS stream variable=sInput      depth=1
    #pragma HLS stream variable=sOutput     depth=1
    bool lReset = true;
    for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
     //Read in the input image to bottom row of buffer
     for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) {
      for(unsigned i2 = 0; i2 < N_INPUT_3_1; i2++) { 
       #pragma HLS UNROLL
       sInput[i2].write(input[i0*N_INPUT_2_1*N_INPUT_3_1+i1*N_INPUT_3_1+i2]);
      }
      subimage_stream(lReset,sInput,sOutput);
      lReset = false;
      for(unsigned i2 = 0; i2 < N_FILT_6; i2++) { 
       #pragma HLS UNROLL
       layer7_full[index] = sOutput[i2].read();
       index++;
      }
     }
   }
   //Now fill a dummy output so we don't run the million by million dense multiply
   layer9_t layer9_out[N_LAYER_9];
   #pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0     
   for(unsigned i0 = 0; i0 < N_LAYER_9; i0++) { 
     layer9_out[i0] = layer7_full[i0*100];
   }

   ////// Below is the actual end to the network
   //nnet::dense_large<layer6_t, layer7_t, config7>(layer6_out, layer7_out, w7, b7);

   //layer8_t layer8_out[N_LAYER_7];
   //#pragma HLS ARRAY_RESHAPE variable=layer8_out complete dim=0
   //nnet::relu<layer7_t, layer8_t, relu_config8>(layer7_out, layer8_out);

   //layer9_t layer9_out[N_LAYER_9];
   //#pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0
   //nnet::dense_large<layer8_t, layer9_t, config9>(layer8_out, layer9_out, w9, b9);
   nnet::softmax<layer9_t, result_t, softmax_config10>(layer9_out, layer10_out);    
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>  input[N_INPUT_3_1],
	      hls::stream<result_t> output[N_FILT_6]) { 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 288>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 18432>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b4, "b4.txt");
        //nnet::load_weights_from_txt<model_default_t, 1179648>(w7, "w7.txt");
        //nnet::load_weights_from_txt<model_default_t, 128>(b7, "b7.txt");
        //nnet::load_weights_from_txt<model_default_t, 1280>(w9, "w9.txt");
        //nnet::load_weights_from_txt<model_default_t, 10>(b9, "b9.txt");
        loaded_weights = true;
    }
#endif

    hls::stream<layer2_t> layer2_out[N_INPUT_3_1];
    #pragma HLS stream variable=layer2_out      depth=1
    nnet::conv_2d_large_stream<input_t,layer2_t,config2>(input,layer2_out,w2,b2);

    hls::stream<layer4_t> layer4_out[N_FILT_4];
    #pragma HLS stream variable=layer4_out      depth=1
    nnet::conv_2d_large_stream<layer4_t,layer4_t,config4>(layer2_out,layer4_out,w4,b4);

    hls::stream<layer6_t> layer6_out[N_FILT_6];
    #pragma HLS stream variable=layer6_out      depth=1
    nnet::pool_2d_large_stream<layer6_t,layer6_t,config6>(layer4_out,layer6_out);

}
