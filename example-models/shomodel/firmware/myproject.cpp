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
//#include "weights/w8.h"
#include "weights/b8.h"
#include "weights/w10.h"
#include "weights/b10.h"
#include "weights/w12.h"
#include "weights/b12.h"
//#include "weights/w14.h"
#include "weights/b14.h"
#include "weights/w16.h"
#include "weights/b16.h"
#include "weights/w18.h"
#include "weights/b18.h"

void myproject(
    input_t input[N_INPUT_1_1*N_INPUT_2_1],
    //result_t layer135_out[N_LAYER_12],
    result_t layer19_out[N_LAYER_18],
    model_default_t w8[262144],
    model_default_t w14[1277952],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS interface bram port=w8,w14
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
        //nnet::load_weights_from_txt<model_default_t, 1277952>(w14, "w14.txt");
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
    #pragma HLS STREAM variable=sInput depth=1 dim=1

    hls::stream<layer13_t>             layer135_out[N_LAYER_12];
    #pragma HLS STREAM variable=layer135_out depth=1 dim=1

    layer13_t             layer136_out[N_LAYER_12*N_OUTPUTS_4];
    //#pragma HLS STREAM variable=layer136_out depth=1 dim=1
    #pragma HLS ARRAY_PARTITION variable=layer136_out block factor=78

    bool iReset = true;
    unsigned pY = 0; 
    for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
      for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
       #pragma HLS UNROLL
       //if(i0*N_INPUT_2_1+i1 < N_INPUT_1_1*N_INPUT_2_1) { 
       //      sInput[i1].write(input[i0*N_INPUT_2_1+i1]);
       sInput[i1].write(input[i1]);
       //} else { 
       //input_t pVal = 0;
       //sInput[i1].write(pVal);
       //} 
      }
      image_stream(iReset,sInput,layer135_out,w8);
      if(!layer135_out[0].empty()) nnet::flatten2<layer13_t,layer13_t,config135>(layer135_out,layer136_out); 
      iReset = true;
   }

   layer14_t layer14_out[N_LAYER_14];
   #pragma HLS ARRAY_PARTITION variable=layer14_out complete
   //if(!layer136_out[(N_LAYER_12-1)*N_OUTPUTS_4].empty()) 
   nnet::dense_large<layer13_t, layer14_t, config14>(layer136_out, layer14_out, w14, b14);
   
   layer15_t layer15_out[N_LAYER_14];
   #pragma HLS ARRAY_PARTITION variable=layer15_out complete
   nnet::relu<layer14_t, layer15_t, relu_config15>(layer14_out, layer15_out);

   layer16_t layer16_out[N_LAYER_16];
   #pragma HLS ARRAY_PARTITION variable=layer16_out complete
   nnet::dense_large<layer15_t, layer16_t, config16>(layer15_out, layer16_out, w16, b16);

   layer17_t layer17_out[N_LAYER_16];
   #pragma HLS ARRAY_PARTITION variable=layer17_out complete
   nnet::relu<layer16_t, layer17_t, relu_config17>(layer16_out, layer17_out);

   layer18_t layer18_out[N_LAYER_18];
   #pragma HLS ARRAY_PARTITION variable=layer18_out complete
   nnet::dense_large<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18, b18);

   nnet::relu<layer18_t, result_t, relu_config19>(layer18_out, layer19_out);

   //hls::stream<layer14_t> layer14s_out[N_LAYER_14];
   //#pragma HLS STREAM variable=layer14_out depth=1 dim=1
   //for(int i0 = 0; i0 < N_LAYER_14; i0++) { 
   // #pragma HLS UNROLL
   // layer14s_out[i0].write(layer14_out[i0]); 
   //}

   //hls::stream<layer15_t> layer15_out[N_LAYER_14];
   //#pragma HLS STREAM variable=layer15_out depth=1 dim=1
   //if(!layer14s_out[0].empty()) nnet::relu_stream<layer14_t, layer15_t, relu_config15>(layer14s_out, layer15_out);

   //hls::stream<layer16_t> layer16_out[N_LAYER_16];
   //#pragma HLS STREAM variable=layer16_out depth=1 dim=1
   //if(!layer15_out[0].empty()) nnet::dense_large_stream<layer15_t, layer16_t, config16>(layer15_out, layer16_out, w16, b16);

   //hls::stream<layer17_t> layer17_out[N_LAYER_16];
   //#pragma HLS STREAM variable=layer17_out depth=1 dim=1
   //if(!layer16_out[0].empty()) nnet::relu_stream<layer16_t, layer17_t, relu_config17>(layer16_out, layer17_out);

  //hls::stream<layer18_t> layer18_out[N_LAYER_18];
  //#pragma HLS STREAM variable=layer18_out depth=1 dim=1
  //if(!layer17_out[0].empty()) nnet::dense_large_stream<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18, b18);
  //if(!layer18_out[0].empty()) nnet::relu_stream<layer18_t, result_t, relu_config19>(layer18_out, layer19_out);

  //nnet::relu_stream<layer18_t, result_t, relu_config19>(layer18_out, layer19_out);
}

void image_stream(bool iReset,	      
		  hls::stream<input_t>    input[N_INPUT_2_1],
                  hls::stream<layer13_t>  layer135_out[N_LAYER_12],
                  model_default_t w8[262144]) { //N_OUTPUTS_4*N_LAYER_12]) { 
  
    #pragma HLS interface bram port=w8
#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 3840>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 40960>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b4, "b4.txt");
        nnet::load_weights_from_txt<model_default_t, 32768>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b6, "b6.txt");
        //nnet::load_weights_from_txt<model_default_t, 262144>(w8, "w8.txt");
        //nnet::load_weights_from_txt<model_default_t, 512>(b8, "b8.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w10, "w10.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w12, "w12.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b12, "b12.txt");
        loaded_weights = true;
    }
#endif

   static hls::stream<layer2_t> layer2_out[N_FILT_2];
   #pragma HLS STREAM variable=layer2_out depth=1 dim=1
   if(!input[0].empty()) nnet::conv_1d_stream<input_t, layer2_t, config2>(iReset,input, layer2_out, w2, b2);
   
   static hls::stream<layer4_t> layer4_out[N_FILT_4];
   #pragma HLS STREAM variable=layer4_out depth=1 dim=1
   if(!layer2_out[0].empty()) nnet::conv_1d_stream<layer3_t, layer4_t, config4>(iReset,layer2_out, layer4_out, w4, b4);

   static hls::stream<layer6_t> layer6_out[N_LAYER_6];
   #pragma HLS STREAM variable=layer6_out depth=1 dim=1
   if(!layer4_out[0].empty()) nnet::dense_large_stream<layer5_t, layer6_t, config6>(layer4_out, layer6_out, w6, b6);

   static hls::stream<layer7_t>   layer7_out[N_LAYER_6];
   #pragma HLS STREAM variable=layer7_out depth=1 dim=1
   if(!layer6_out[0].empty()) nnet::relu_stream<layer6_t, layer7_t, relu_config7>(layer6_out, layer7_out);

   static hls::stream<layer8_t>  layer8_out[N_LAYER_8];
   #pragma HLS STREAM variable=layer8_out depth=1 dim=1
   if(!layer7_out[0].empty()) nnet::dense_large_stream<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8);

   static hls::stream<layer9_t> layer9_out[N_LAYER_8];
   #pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0
   if(!layer8_out[0].empty()) nnet::relu_stream<layer8_t, layer9_t, relu_config9>(layer8_out, layer9_out);
   //nnet::relu_stream2<layer8_t, layer9_t, relu_config9>(layer8_out, layer135_out);

   static hls::stream<layer10_t> layer10_out[N_LAYER_10];
   #pragma HLS STREAM variable=layer10_out depth=1 dim=1
   if(!layer9_out[0].empty()) nnet::dense_large_stream<layer9_t, layer10_t, config10>(layer9_out, layer10_out, w10, b10);

   static hls::stream<layer11_t> layer11_out[N_LAYER_10];
   #pragma HLS STREAM variable=layer11_out depth=1 dim=1
   if(!layer10_out[0].empty()) nnet::relu_stream<layer10_t, layer11_t, relu_config11>(layer10_out, layer11_out);

   static hls::stream<layer12_t> layer12_out[N_LAYER_12];
   #pragma HLS STREAM variable=layer12_out depth=1 dim=1
   if(!layer11_out[0].empty()) nnet::dense_large_stream<layer11_t, layer12_t, config12>(layer11_out, layer12_out, w12, b12);

   //layer13_t layer13_out[N_LAYER_12];
   //#pragma HLS ARRAY_PARTITION variable=layer13_out complete dim=0
   if(!layer12_out[0].empty()) nnet::relu_stream<layer12_t, layer13_t, relu_config13>(layer12_out, layer135_out);
}
