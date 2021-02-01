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
#include "weights/s3.h"
#include "weights/b3.h"
#include "weights/w6.h"
#include "weights/b6.h"

void myproject_in(
     hls::stream<input_t> input_input_data[N_INPUT_3_1],
     hls::stream<result_t> layer6_out[N_FILT_6],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=input_input_data,layer6_out 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
    const_size_out_1 = OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_weightdefault_t, 864>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 640>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b3, "b3.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 18432>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 320>(b6, "b6.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    static hls::stream<layer2_t> layer2_out[N_FILT_2];
    #pragma HLS STREAM variable=layer2_out depth=324 dim=1
    if(!input_input_data[0].empty()) nnet::conv_2d_large_cl<input_t, layer2_t, config2>(input_input_data, layer2_out, w2, b2);

    static hls::stream<layer3_t> layer3_out[N_FILT_2];
    #pragma HLS STREAM variable=layer3_out depth=15 dim=1
    while(!layer2_out[0].empty()) nnet::normalize_stream<layer2_t, layer3_t, config3>(layer2_out, layer3_out, s3, b3);

    static hls::stream<layer4_t> layer4_out[N_FILT_2];
    #pragma HLS STREAM variable=layer4_out depth=15 dim=1
    nnet::Relu_stream<layer3_t, layer4_t, Relu_config4>(layer3_out, layer4_out);

    static hls::stream<layer5_t> layer5_out[N_FILT_5];
    #pragma HLS STREAM variable=layer5_out depth=1 dim=1
    nnet::pad_2d_cl<layer4_t, layer5_t, config5>(layer4_out, layer5_out);

    while(!layer5_out[0].empty()) nnet::conv_2d_large_cl<layer5_t, result_t, config6>(layer5_out, layer6_out, w6, b6);

}


void myproject(
     hls::stream<input_t> input_input_data[N_INPUT_3_1],
     hls::stream<result_t> layer6_out[N_FILT_6],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) { 
for(int i0 = 0; i0 < 640; i0++) {
    for(int i1 = 0; i1 < 320; i1++) {
        myproject_in(input_input_data,layer6_out,const_size_in_1,const_size_out_1);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
}
