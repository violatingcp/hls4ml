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
#include "weights/s3.h"
#include "weights/b3.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w9.h"
#include "weights/b9.h"
#include "weights/w13.h"
#include "weights/b13.h"
#include "weights/w18.h"
#include "weights/b18.h"
#include "weights/w22.h"
#include "weights/b22.h"
#include "weights/w27.h"
#include "weights/b27.h"
//#include "weights/w31.h"
#include "weights/b31.h"
//#include "weights/w36.h"
#include "weights/b36.h"
//#include "weights/w40.h"
#include "weights/b40.h"
//#include "weights/w44.h"
#include "weights/b44.h"
#include "weights/s46.h"
#include "weights/b46.h"
#include "weights/w48.h"
#include "weights/b48.h"
#include "weights/s50.h"
#include "weights/b50.h"
#include "weights/w52.h"
#include "weights/b52.h"

void myproject_in(
     hls::stream<input_t> em_barrel[N_INPUT_3_1],
     hls::stream<result_t> layer54_out[N_LAYER_52],
     model_default_t w31[147456],
     model_default_t w36[294912],
     model_default_t w40[589824],
     model_default_t w44[589824]
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS interface bram port=w31,w36,w40,w44
    #pragma HLS INTERFACE axis port=em_barrel,layer54_out 
    #pragma HLS DATAFLOW 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_weightdefault_t, 4>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 4>(b3, "b3.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1600>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 16>(b4, "b4.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 4608>(w9, "w9.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32>(b9, "b9.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 9216>(w13, "w13.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32>(b13, "b13.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 18432>(w18, "w18.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 64>(b18, "b18.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 36864>(w22, "w22.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 64>(b22, "b22.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 73728>(w27, "w27.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 128>(b27, "b27.txt");
        //nnet::load_weights_from_txt<model_weightdefault_t, 147456>(w31, "w31.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 128>(b31, "b31.txt");
        //nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w36, "w36.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(b36, "b36.txt");
        //nnet::load_weights_from_txt<model_weightdefault_t, 589824>(w40, "w40.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(b40, "b40.txt");
        //nnet::load_weights_from_txt<model_weightdefault_t, 589824>(w44, "w44.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 257>(b44, "b44.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(s46, "s46.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(b46, "b46.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 65536>(w48, "w48.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 257>(b48, "b48.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(s50, "s50.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(b50, "b50.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(w52, "w52.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1>(b52, "b52.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    static hls::stream<layer2_t> layer2_out[N_CHANNEL_2];
    #pragma HLS STREAM variable=layer2_out depth=5 dim=1
    nnet::upsampling2d_stream<input_t, layer2_t, config2>(em_barrel, layer2_out);

    static hls::stream<layer3_t> layer3_out[N_CHANNEL_2];
    #pragma HLS STREAM variable=layer3_out depth=15 dim=1
    while(!layer2_out[0].empty()) {
      nnet::normalize_stream<layer2_t, layer3_t, config3>(layer2_out, layer3_out, s3, b3);
      //std::cout<<"in first while"<<std::endl;
    }

    static hls::stream<layer7_t> layer7_out[N_FILT_4];
    #pragma HLS STREAM variable=layer7_out depth=150 dim=1
    while(!layer3_out[0].empty()) {
      nnet::conv_2d_large_cl<layer3_t, layer7_t, config4>(layer3_out, layer7_out, w4, b4);
      //std::cout<<"in second while"<<std::endl;
    }

    static hls::stream<layer8_t> layer8_out[N_FILT_8];
    #pragma HLS STREAM variable=layer8_out depth=150 dim=1
    while(!layer7_out[0].empty()) {
      nnet::pooling2d_cl<layer7_t, layer8_t, config8>(layer7_out, layer8_out);
      //std::cout<<"in third while"<<std::endl;
    }

    static hls::stream<layer12_t> layer12_out[N_FILT_9];
    #pragma HLS STREAM variable=layer12_out depth=31 dim=1
    while(!layer8_out[0].empty()) nnet::conv_2d_large_cl<layer8_t, layer12_t, config9>(layer8_out, layer12_out, w9, b9);

    static hls::stream<layer16_t> layer16_out[N_FILT_13];
    #pragma HLS STREAM variable=layer16_out depth=31 dim=1
    while(!layer12_out[0].empty()) nnet::conv_2d_large_cl<layer12_t, layer16_t, config13>(layer12_out, layer16_out, w13, b13);

    static hls::stream<layer17_t> layer17_out[N_FILT_17];
    #pragma HLS STREAM variable=layer17_out depth=31 dim=1
    while(!layer16_out[0].empty()) nnet::pooling2d_cl<layer16_t, layer17_t, config17>(layer16_out, layer17_out);

    static hls::stream<layer21_t> layer21_out[N_FILT_18];
    #pragma HLS STREAM variable=layer21_out depth=17 dim=1
    while(!layer17_out[0].empty()) nnet::conv_2d_large_cl<layer17_t, layer21_t, config18>(layer17_out, layer21_out, w18, b18);

    static hls::stream<layer25_t> layer25_out[N_FILT_22];
    #pragma HLS STREAM variable=layer25_out depth=17 dim=1
    while(!layer21_out[0].empty()) nnet::conv_2d_large_cl<layer21_t, layer25_t, config22>(layer21_out, layer25_out, w22, b22);

    static hls::stream<layer26_t> layer26_out[N_FILT_26];
    #pragma HLS STREAM variable=layer26_out depth=17 dim=1
    while(!layer25_out[0].empty()) nnet::pooling2d_cl<layer25_t, layer26_t, config26>(layer25_out, layer26_out);

    static hls::stream<layer30_t> layer30_out[N_FILT_27];
    #pragma HLS STREAM variable=layer30_out depth=10 dim=1
    while(!layer26_out[0].empty()) nnet::conv_2d_large_cl<layer26_t, layer30_t, config27>(layer26_out, layer30_out, w27, b27);

    static hls::stream<layer34_t> layer34_out[N_FILT_31];
    #pragma HLS STREAM variable=layer34_out depth=10 dim=1
    while(!layer30_out[0].empty()) nnet::conv_2d_large_cl<layer30_t, layer34_t, config31>(layer30_out, layer34_out, w31, b31);

    static hls::stream<layer35_t> layer35_out[N_FILT_35];
    #pragma HLS STREAM variable=layer35_out depth=10 dim=1
    while(!layer34_out[0].empty()) nnet::pooling2d_cl<layer34_t, layer35_t, config35>(layer34_out, layer35_out);

    static hls::stream<layer39_t> layer39_out[N_FILT_36];
    #pragma HLS STREAM variable=layer39_out depth=7 dim=1
    while(!layer35_out[0].empty()) nnet::conv_2d_large_cl<layer35_t, layer39_t, config36>(layer35_out, layer39_out, w36, b36);

    static hls::stream<layer43_t> layer43_out[N_FILT_40];
    #pragma HLS STREAM variable=layer43_out depth=7 dim=1
    while(!layer39_out[0].empty()) nnet::conv_2d_large_cl<layer39_t, layer43_t, config40>(layer39_out, layer43_out, w40, b40);

    static hls::stream<layer44_t> layer44_out[N_LAYER_44];
    #pragma HLS STREAM variable=layer44_out depth=7 dim=1
    while(!layer43_out[0].empty()) nnet::dense_large_stream<layer43_t, layer44_t, config44>(layer43_out, layer44_out, w44, b44);

    static hls::stream<layer46_t> layer46_out[N_LAYER_44];
    #pragma HLS STREAM variable=layer46_out depth=15 dim=1
    while(!layer44_out[0].empty()) nnet::normalize_stream<layer44_t, layer46_t, config46>(layer44_out, layer46_out, s46, b46);

    static hls::stream<layer47_t> layer47_out[N_LAYER_44];
    #pragma HLS STREAM variable=layer47_out depth=15 dim=1
    while(!layer46_out[0].empty()) nnet::leaky_relu_stream<layer46_t, layer47_t, LeakyReLU_config47>(layer46_out, 0.300000011921, layer47_out);

    static hls::stream<layer48_t> layer48_out[N_LAYER_48];
    #pragma HLS STREAM variable=layer48_out depth=1 dim=1
    while(!layer47_out[0].empty()) nnet::dense_large_stream<layer47_t, layer48_t, config48>(layer47_out, layer48_out, w48, b48);

    static hls::stream<layer50_t> layer50_out[N_LAYER_48];
    #pragma HLS STREAM variable=layer50_out depth=15 dim=1
    while(!layer48_out[0].empty()) nnet::normalize_stream<layer48_t, layer50_t, config50>(layer48_out, layer50_out, s50, b50);

    static hls::stream<layer51_t> layer51_out[N_LAYER_48];
    #pragma HLS STREAM variable=layer51_out depth=15 dim=1
    while(!layer50_out[0].empty()) nnet::leaky_relu_stream<layer50_t, layer51_t, LeakyReLU_config51>(layer50_out, 0.300000011921, layer51_out);

    static hls::stream<layer52_t> layer52_out[N_LAYER_52];
    #pragma HLS STREAM variable=layer52_out depth=1 dim=1
    while(!layer51_out[0].empty()) {
      nnet::dense_large_stream<layer51_t, layer52_t, config52>(layer51_out, layer52_out, w52, b52);
      //std::cout<<"in second to last while"<<std::endl;
    }

    while(!layer52_out[0].empty()) {
      nnet::relu_stream<layer52_t, result_t, relu_config54>(layer52_out, layer54_out);
      std::cout<<"in last while"<<std::endl;
    }

}


void myproject(
     hls::stream<input_t> em_barrel[N_INPUT_3_1],
     hls::stream<result_t> layer54_out[N_LAYER_52],
     model_default_t w31[147456],
     model_default_t w36[294912],
     model_default_t w40[589824],
     model_default_t w44[589824]
) { 
    for(int i0 = 0; i0 < 56; i0++) {
        for(int i1 = 0; i1 < 11; i1++) {
	    //std::cout<<"running inference "<<i0<<" "<<i1<<std::endl;
            myproject_in(em_barrel,layer54_out,w31,w36,w40,w44);
            //std::cout<<"out empty?";
            //for (int il = 0; il < N_LAYER_52; il++) {
            //    std::cout<<" "<<layer54_out[il].empty();
	    // }
            //std::cout<<std::endl;
        }
    }
    /*
    std::cout<<"waiting"<<std::endl;
    while (layer54_out[0].empty()) {
    #pragma HLS latency min=1
    }
    std::cout<<"out empty?";
    for (int il = 0; il < N_LAYER_52; il++) {
        std::cout<<" "<<layer54_out[il].empty();
    }
    std::cout<<std::endl;
    */
}
