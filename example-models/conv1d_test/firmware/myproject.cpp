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

void myproject_in(
     hls::stream<input_t> input1[N_INPUT_1_1],
     hls::stream<result_t> layer19_out[N_LAYER_18],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=input1,layer19_out 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1;
    const_size_out_1 = N_LAYER_18;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_weightdefault_t, 240>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 160>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b4, "b4.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 128>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1024>(w8, "w8.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b8, "b8.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(w10, "w10.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 64>(w12, "w12.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b12, "b12.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 3968>(w14, "w14.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b14, "b14.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 64>(w16, "w16.txt");
        nnet::load_weights_from_txt<model_default_t, 8>(b16, "b16.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32>(w18, "w18.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b18, "b18.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    static hls::stream<layer2_t> layer2_out[N_OUTPUTS_2];
    #pragma HLS STREAM variable=layer2_out depth=1 dim=1
    if(!input1[0].empty()) nnet::conv_1d_large_cl<input_t, layer2_t, config2>(input1, layer2_out, w2, b2);

    static hls::stream<layer3_t> layer3_out[N_OUTPUTS_2];
    #pragma HLS STREAM variable=layer3_out depth=1 dim=1
    while(!layer2_out[0].empty()) nnet::relu_stream<layer2_t, layer3_t, relu_config3>(layer2_out, layer3_out);

    static hls::stream<layer4_t> layer4_out[N_OUTPUTS_4];
    #pragma HLS STREAM variable=layer4_out depth=1 dim=1
    while(!layer3_out[0].empty()) nnet::conv_1d_large_cl<layer3_t, layer4_t, config4>(layer3_out, layer4_out, w4, b4);

    static hls::stream<layer5_t> layer5_out[N_OUTPUTS_4];
    #pragma HLS STREAM variable=layer5_out depth=1 dim=1
    while(!layer4_out[0].empty()) nnet::relu_stream<layer4_t, layer5_t, relu_config5>(layer4_out, layer5_out);

    static hls::stream<layer6_t> layer6_out[N_LAYER_6];
    #pragma HLS STREAM variable=layer6_out depth=1 dim=1
    while(!layer5_out[0].empty()) nnet::dense_large_stream<layer5_t, layer6_t, config6>(layer5_out, layer6_out, w6, b6);

    static hls::stream<layer7_t> layer7_out[N_LAYER_6];
    #pragma HLS STREAM variable=layer7_out depth=1 dim=1
    while(!layer6_out[0].empty()) nnet::relu_stream<layer6_t, layer7_t, relu_config7>(layer6_out, layer7_out);

    static hls::stream<layer8_t> layer8_out[N_LAYER_8];
    #pragma HLS STREAM variable=layer8_out depth=1 dim=1
    while(!layer7_out[0].empty()) nnet::dense_large_stream<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8);

    static hls::stream<layer9_t> layer9_out[N_LAYER_8];
    #pragma HLS STREAM variable=layer9_out depth=1 dim=1
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

    static hls::stream<layer13_t> layer13_out[N_LAYER_12];
    #pragma HLS STREAM variable=layer13_out depth=1 dim=1
    while(!layer12_out[0].empty()) nnet::relu_stream<layer12_t, layer13_t, relu_config13>(layer12_out, layer13_out);

    static hls::stream<layer14_t> layer14_out[N_LAYER_14];
    #pragma HLS STREAM variable=layer14_out depth=1 dim=1
    while(!layer13_out[0].empty()) nnet::dense_large_stream<layer13_t, layer14_t, config14>(layer13_out, layer14_out, w14, b14);

    static hls::stream<layer15_t> layer15_out[N_LAYER_14];
    #pragma HLS STREAM variable=layer15_out depth=1 dim=1
    while(!layer14_out[0].empty()) nnet::relu_stream<layer14_t, layer15_t, relu_config15>(layer14_out, layer15_out);

    static hls::stream<layer16_t> layer16_out[N_LAYER_16];
    #pragma HLS STREAM variable=layer16_out depth=1 dim=1
    while(!layer15_out[0].empty()) nnet::dense_large_stream<layer15_t, layer16_t, config16>(layer15_out, layer16_out, w16, b16);

    static hls::stream<layer17_t> layer17_out[N_LAYER_16];
    #pragma HLS STREAM variable=layer17_out depth=1 dim=1
    while(!layer16_out[0].empty()) nnet::relu_stream<layer16_t, layer17_t, relu_config17>(layer16_out, layer17_out);

    static hls::stream<layer18_t> layer18_out[N_LAYER_18];
    #pragma HLS STREAM variable=layer18_out depth=1 dim=1
    while(!layer17_out[0].empty()) nnet::dense_large_stream<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18, b18);

    while(!layer18_out[0].empty()) nnet::relu_stream<layer18_t, result_t, relu_config19>(layer18_out, layer19_out);

}


void myproject(
     hls::stream<input_t> input1[N_INPUT_1_1],
     hls::stream<result_t> layer19_out[N_LAYER_18],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) { 
  for(int i0 = 0; i0 < 80; i0++) {
   myproject_in(input1,layer19_out,const_size_in_1,const_size_out_1);
   }
}
