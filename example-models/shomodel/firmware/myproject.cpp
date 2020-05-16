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

#include "myproject.h"

//hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/w8.h"
#include "weights/b8.h"
#include "weights/w10.h"
#include "weights/b10.h"
#include "weights/w12.h"
#include "weights/b12.h"
#include "weights/w14.h"
#include "weights/b14.h"
#include "weights/w16.h"
#include "weights/b16.h"
#include "weights/w18.h"
#include "weights/b18.h"

void myproject(
    input_t input[N_INPUT_1_1*N_INPUT_2_1],
    result_t layer19_out[N_LAYER_18],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=input complete dim=0 
    #pragma HLS ARRAY_RESHAPE variable=layer19_out complete dim=0 
    #pragma HLS INTERFACE ap_vld port=input,layer19_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1;
    const_size_out_1 = N_LAYER_18;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 32768>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w8, "w8.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b8, "b8.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w10, "w10.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w12, "w12.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b12, "b12.txt");
        nnet::load_weights_from_txt<model_default_t, 1277952>(w14, "w14.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b14, "b14.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w16, "w16.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b16, "b16.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(w18, "w18.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b18, "b18.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    hls::stream<input_t> sInput[N_INPUT_2_1];

    layer5_t layer5_out[N_OUTPUTS_4*N_FILT_4];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0

    bool iReset = true;
    for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
     for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
      #pragma HLS UNROLL
       if(i0*N_INPUT_2_1+i1 < N_INPUT_1_1*N_INPUT_2_1) { 
	  sInput[i1].write(input[i0*N_INPUT_2_1+i1]);
	  image_stream(iReset,sInput,layer5_out);
       } else { 
         input_t pVal = 0;
         sInput[i1].write(pVal);
      } 
      iReset = true;
     }
    }

   layer6_t layer6_out[N_LAYER_6];
   #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0
   nnet::dense_large<layer5_t, layer6_t, config6>(layer5_out, layer6_out, w6, b6);

   layer7_t layer7_out[N_LAYER_6];
   #pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0
   nnet::relu<layer6_t, layer7_t, relu_config7>(layer6_out, layer7_out);

   layer8_t layer8_out[N_LAYER_8];
   #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0
   nnet::dense_large<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8);

   layer9_t layer9_out[N_LAYER_8];
   #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0
   nnet::relu<layer8_t, layer9_t, relu_config9>(layer8_out, layer9_out);

   layer10_t layer10_out[N_LAYER_10];
   #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
   nnet::dense_large<layer9_t, layer10_t, config10>(layer9_out, layer10_out, w10, b10);

   layer11_t layer11_out[N_LAYER_10];
   #pragma HLS ARRAY_PARTITION variable=layer11_out complete dim=0
   nnet::relu<layer10_t, layer11_t, relu_config11>(layer10_out, layer11_out);

   layer12_t layer12_out[N_LAYER_12];
   #pragma HLS ARRAY_PARTITION variable=layer12_out complete dim=0
   nnet::dense_large<layer11_t, layer12_t, config12>(layer11_out, layer12_out, w12, b12);

   layer13_t layer13_out[N_LAYER_12];
   #pragma HLS ARRAY_PARTITION variable=layer13_out complete dim=0
   nnet::relu<layer12_t, layer13_t, relu_config13>(layer12_out, layer13_out);

   layer14_t layer14_out[N_LAYER_14];
   #pragma HLS ARRAY_PARTITION variable=layer14_out complete dim=0
   nnet::dense_large<layer13_t, layer14_t, config14>(layer13_out, layer14_out, w14, b14);

   layer15_t layer15_out[N_LAYER_14];
   #pragma HLS ARRAY_PARTITION variable=layer15_out complete dim=0
   nnet::relu<layer14_t, layer15_t, relu_config15>(layer14_out, layer15_out);

   layer16_t layer16_out[N_LAYER_16];
   #pragma HLS ARRAY_PARTITION variable=layer16_out complete dim=0
   nnet::dense_large<layer15_t, layer16_t, config16>(layer15_out, layer16_out, w16, b16);

   layer17_t layer17_out[N_LAYER_16];
   #pragma HLS ARRAY_PARTITION variable=layer17_out complete dim=0
   nnet::relu<layer16_t, layer17_t, relu_config17>(layer16_out, layer17_out);

   layer18_t layer18_out[N_LAYER_18];
   #pragma HLS ARRAY_PARTITION variable=layer18_out complete dim=0
   nnet::dense_large<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18, b18);
   nnet::relu<layer18_t, result_t, relu_config19>(layer18_out, layer19_out);

}

void image_stream(bool iReset,	      
		  hls::stream<input_t>  input[N_INPUT_2_1],
                  layer5_t              layer5_out[N_OUTPUTS_4*N_FILT_4]) { 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 3840>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 40960>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b4, "b4.txt");
        loaded_weights = true;
    }
#endif
   
   static hls::stream<layer2_t> layer2_out[N_FILT_2];
   #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0
   if(!input[0].empty()) nnet::conv_1d_stream<input_t, layer2_t, config2>(iReset,input, layer2_out, w2, b2);
   
   static hls::stream<layer4_t> layer4_out[N_FILT_4];
   #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0
   if(!layer2_out[0].empty()) nnet::conv_1d_stream<layer3_t, layer4_t, config4>(iReset,layer2_out, layer4_out, w4, b4);

   if(!layer4_out[0].empty()) nnet::flatten<layer4_t, layer5_t, config5>(layer4_out, layer5_out);
}
