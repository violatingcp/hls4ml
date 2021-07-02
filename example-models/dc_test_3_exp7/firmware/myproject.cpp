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
#include "weights/w5.h"
#include "weights/b5.h"
#include "weights/w8.h"
#include "weights/b8.h"
#include "weights/w10.h"
#include "weights/b10.h"
#include "weights/w12.h"
#include "weights/b12.h"

void myproject_in(
		  hls::stream<input_t>  input1[N_INPUT_3_1],
		  hls::stream<result_t> layer13_out[N_LAYER_12]
		  //model_weightdefault_t w8[1152],
		  //model_weightdefault_t w10[2304]
		  //unsigned short &const_size_in_1,
		  //unsigned short &const_size_out_1
		  ) {

    //hls-fpga-machine-learning insert IO
    //#pragma HLS INTERFACE axis port=input1,layer2_out 
    #pragma HLS DATAFLOW 
    //#pragma HLS INTERFACE axis port=input1,layer13_out

  //const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
  //const_size_out_1 = N_LAYER_12;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_weightdefault_t, 36>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 288>(w5, "w5.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b5, "b5.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1152>(w8, "w8.txt");
        nnet::load_weights_from_txt<model_default_t, 16>(b8, "b8.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 2304>(w10, "w10.txt");
        nnet::load_weights_from_txt<model_default_t, 16>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 160>(w12, "w12.txt");
        nnet::load_weights_from_txt<model_default_t, 10>(b12, "b12.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    static hls::stream<layer2_t> layer2_out[N_FILT_2];
    #pragma HLS STREAM variable=layer2_out depth=2 dim=1
    if(!input1[0].empty())  nnet::conv_2d_large_cl<input_t, layer2_t, config2>(input1, layer2_out, w2, b2);
    static hls::stream<layer3_t> layer3_out[N_FILT_2];
    #pragma HLS STREAM variable=layer3_out depth=2 dim=1
    while(!layer2_out[0].empty()) nnet::relu_stream<layer2_t, layer3_t, relu_config3>(layer2_out, layer3_out);
    static hls::stream<layer4_t> layer4_out[N_FILT_4];
    #pragma HLS STREAM variable=layer4_out depth=2 dim=1
    while(!layer3_out[0].empty()) nnet::pooling2d_cl<layer3_t, layer4_t, config4>(layer3_out, layer4_out);
    static hls::stream<layer5_t> layer5_out[N_FILT_5];
    #pragma HLS STREAM variable=layer5_out depth=2 dim=1
    while(!layer4_out[0].empty()) nnet::conv_2d_large_cl<layer4_t, layer5_t, config5>(layer4_out, layer5_out, w5, b5);
    static hls::stream<layer6_t> layer6_out[N_FILT_5];
    #pragma HLS STREAM variable=layer6_out depth=2 dim=1
    while(!layer5_out[0].empty()) nnet::relu_stream<layer5_t, layer6_t, relu_config6>(layer5_out, layer6_out);
    static hls::stream<layer7_t> layer7_out[N_FILT_7];
    #pragma HLS STREAM variable=layer7_out depth=2 dim=1
    while(!layer6_out[0].empty()) nnet::pooling2d_cl<layer6_t, layer7_t, config7>(layer6_out, layer7_out);
    static hls::stream<layer8_t> layer8_out[N_FILT_8];
    #pragma HLS STREAM variable=layer8_out depth=2 dim=1
    while(!layer7_out[0].empty()) nnet::conv_2d_large_cl<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8);
    static hls::stream<layer9_t> layer9_out[N_FILT_8];
    #pragma HLS STREAM variable=layer9_out depth=2 dim=1
    while(!layer8_out[0].empty()) nnet::relu_stream<layer8_t, layer9_t, relu_config9>(layer8_out, layer9_out);
    static hls::stream<layer10_t> layer10_out[N_LAYER_10];
    #pragma HLS STREAM variable=layer10_out depth=1 dim=1
    while(!layer9_out[0].empty()) nnet::dense_large_stream<layer9_t, layer10_t, config10>(layer9_out, layer10_out, w10, b10);
    static hls::stream<layer11_t> layer11_out[N_LAYER_10];
    #pragma HLS STREAM variable=layer11_out depth=1 dim=1
    while(!layer10_out[0].empty()) nnet::relu_stream<layer10_t, layer11_t, relu_config11>(layer10_out, layer11_out);
    static hls::stream<layer12_t> layer12_out[N_LAYER_12];
    #pragma HLS STREAM variable=layer12_out depth=1 dim=1
    while(!layer11_out[0].empty()) nnet::dense_large_stream<layer11_t, layer12_t, config12>(layer11_out, layer12_out, w12, b12);
    if(!layer12_out[0].empty()) nnet::softmax_stream<layer12_t, result_t, softmax_config13>(layer12_out, layer13_out);
}

void myproject(
               hls::stream<input_t>   input1[N_INPUT_3_1],
               hls::stream<result_t>  layer13_out[N_LAYER_12]
	       //model_weightdefault_t w8[1152],
	       //model_weightdefault_t w10[2304]
	       //unsigned short &const_size_in_1,
	       //unsigned short &const_size_out_1
	       ) { 

  //#pragma HLS DATAFLOW
  #pragma HLS INTERFACE axis port=input1,layer13_out

  //static hls::stream<layer12_t> layer12b_out[N_LAYER_12];
  //#pragma HLS STREAM variable=layer12b_out depth=2 dim=1                                                                                                                                                                        

  for(int i1 = 0; i1 < 28*28; i1++) {
   myproject_in(input1,layer13_out);//,w8, w10);
  }
  /*
  std::cout << "--->> Filling " << std::endl;
  for(int i0 = 0; i0 < 1; i0++) { 
    for(int i1 = 0; i1 < N_LAYER_12; i1++) {
      result_t pTmp = (result_t) layer12b_out[i1].read();
      layer13_out[i1].write(pTmp);
    }
  }
  std::cout << "---> Done  " << std::endl;
  std::cout << "-------> Checks " << std::endl;
  std::cout << "input1 ";
  for(int i0 = 0; i0 < N_INPUT_3_1; i0++) { 
   std::cout << " " <<  input1[i0].empty();
  }
  std::cout << std::endl;

  std::cout << "Layer  2";
  for(int i0 = 0; i0 < N_LAYER_10; i0++) { 
   std::cout << " " << layer12b_out[i0].empty();
  }
  std::cout << std::endl;
  std::cout << "-------> Done " << std::endl;
  */
  /*
  std::cout << "Layer  13";
  for(int i0 = 0; i0 < N_LAYER_12; i0++) { 
  std::cout << " " << layer13_out[i0].empty();
  }
  std::cout << std::endl;
  std::cout << "-------> Done " << std::endl;
  */
}

