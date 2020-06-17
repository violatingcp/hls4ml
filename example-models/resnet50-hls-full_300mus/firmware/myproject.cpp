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
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/w9.h"
#include "weights/b9.h"
#include "weights/w12.h"
#include "weights/b12.h"
#include "weights/w14.h"
#include "weights/b14.h"
#include "weights/w18.h"
#include "weights/b18.h"
#include "weights/w21.h"
#include "weights/b21.h"
#include "weights/w24.h"
#include "weights/b24.h"
#include "weights/w28.h"
#include "weights/b28.h"
#include "weights/w31.h"
#include "weights/b31.h"
#include "weights/w34.h"
#include "weights/b34.h"
#include "weights/w38.h"
#include "weights/b38.h"
#include "weights/w41.h"
#include "weights/b41.h"
#include "weights/w44.h"
#include "weights/b44.h"
#include "weights/w46.h"
#include "weights/b46.h"
#include "weights/w50.h"
#include "weights/b50.h"
#include "weights/w53.h"
#include "weights/b53.h"
#include "weights/w56.h"
#include "weights/b56.h"
#include "weights/w60.h"
#include "weights/b60.h"
#include "weights/w63.h"
#include "weights/b63.h"
#include "weights/w66.h"
#include "weights/b66.h"
#include "weights/w70.h"
#include "weights/b70.h"
#include "weights/w73.h"
#include "weights/b73.h"
#include "weights/w76.h"
#include "weights/b76.h"
#include "weights/w80.h"
#include "weights/b80.h"
#include "weights/w83.h"
#include "weights/b83.h"
#include "weights/w86.h"
#include "weights/b86.h"
#include "weights/w88.h"
#include "weights/b88.h"
#include "weights/w92.h"
#include "weights/b92.h"
#include "weights/w95.h"
#include "weights/b95.h"
#include "weights/w98.h"
#include "weights/b98.h"
#include "weights/w102.h"
#include "weights/b102.h"
#include "weights/w105.h"
#include "weights/b105.h"
#include "weights/w108.h"
#include "weights/b108.h"
#include "weights/w112.h"
#include "weights/b112.h"
#include "weights/w115.h"
#include "weights/b115.h"
#include "weights/w118.h"
#include "weights/b118.h"
#include "weights/w122.h"
#include "weights/b122.h"
#include "weights/w125.h"
#include "weights/b125.h"
#include "weights/w128.h"
#include "weights/b128.h"
#include "weights/w132.h"
#include "weights/b132.h"
#include "weights/w135.h"
#include "weights/b135.h"
#include "weights/w138.h"
#include "weights/b138.h"
#include "weights/w142.h"
#include "weights/b142.h"
#include "weights/w145.h"
#include "weights/b145.h"
#include "weights/w148.h"
#include "weights/b148.h"
#include "weights/w150.h"
#include "weights/b150.h"
#include "weights/w154.h"
#include "weights/b154.h"
#include "weights/w157.h"
#include "weights/b157.h"
#include "weights/w160.h"
#include "weights/b160.h"
#include "weights/w164.h"
#include "weights/b164.h"
#include "weights/w167.h"
#include "weights/b167.h"
#include "weights/w170.h"
#include "weights/b170.h"
#include "weights/w175.h"
#include "weights/b175.h"

void myproject(
    static hls::stream<input_t> gpu_0_data_0[N_INPUT_1_1],
    static hls::stream<result_t> layer176_out[N_LAYER_175],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=gpu_0_data_0,layer176_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
    const_size_out_1 = N_LAYER_175;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_weightdefault_t, 4704>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 64>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 2048>(w6, "w6.txt");
        nnet::load_weights_from_txt<bias6_t, 64>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 18432>(w9, "w9.txt");
        nnet::load_weights_from_txt<bias9_t, 64>(b9, "b9.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 8192>(w12, "w12.txt");
        nnet::load_weights_from_txt<bias12_t, 256>(b12, "b12.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 8192>(w14, "w14.txt");
        nnet::load_weights_from_txt<bias14_t, 256>(b14, "b14.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 8192>(w18, "w18.txt");
        nnet::load_weights_from_txt<bias18_t, 64>(b18, "b18.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 18432>(w21, "w21.txt");
        nnet::load_weights_from_txt<bias21_t, 64>(b21, "b21.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 8192>(w24, "w24.txt");
        nnet::load_weights_from_txt<bias24_t, 256>(b24, "b24.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 8192>(w28, "w28.txt");
        nnet::load_weights_from_txt<bias28_t, 64>(b28, "b28.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 18432>(w31, "w31.txt");
        nnet::load_weights_from_txt<bias31_t, 64>(b31, "b31.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 8192>(w34, "w34.txt");
        nnet::load_weights_from_txt<bias34_t, 256>(b34, "b34.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 16384>(w38, "w38.txt");
        nnet::load_weights_from_txt<bias38_t, 128>(b38, "b38.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 73728>(w41, "w41.txt");
        nnet::load_weights_from_txt<bias41_t, 128>(b41, "b41.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w44, "w44.txt");
        nnet::load_weights_from_txt<bias44_t, 512>(b44, "b44.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 65536>(w46, "w46.txt");
        nnet::load_weights_from_txt<bias46_t, 512>(b46, "b46.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w50, "w50.txt");
        nnet::load_weights_from_txt<bias50_t, 128>(b50, "b50.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 73728>(w53, "w53.txt");
        nnet::load_weights_from_txt<bias53_t, 128>(b53, "b53.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w56, "w56.txt");
        nnet::load_weights_from_txt<bias56_t, 512>(b56, "b56.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w60, "w60.txt");
        nnet::load_weights_from_txt<bias60_t, 128>(b60, "b60.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 73728>(w63, "w63.txt");
        nnet::load_weights_from_txt<bias63_t, 128>(b63, "b63.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w66, "w66.txt");
        nnet::load_weights_from_txt<bias66_t, 512>(b66, "b66.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w70, "w70.txt");
        nnet::load_weights_from_txt<bias70_t, 128>(b70, "b70.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 73728>(w73, "w73.txt");
        nnet::load_weights_from_txt<bias73_t, 128>(b73, "b73.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 32768>(w76, "w76.txt");
        nnet::load_weights_from_txt<bias76_t, 512>(b76, "b76.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 65536>(w80, "w80.txt");
        nnet::load_weights_from_txt<bias80_t, 256>(b80, "b80.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w83, "w83.txt");
        nnet::load_weights_from_txt<bias83_t, 256>(b83, "b83.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w86, "w86.txt");
        nnet::load_weights_from_txt<bias86_t, 1024>(b86, "b86.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 262144>(w88, "w88.txt");
        nnet::load_weights_from_txt<bias88_t, 1024>(b88, "b88.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w92, "w92.txt");
        nnet::load_weights_from_txt<bias92_t, 256>(b92, "b92.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w95, "w95.txt");
        nnet::load_weights_from_txt<bias95_t, 256>(b95, "b95.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w98, "w98.txt");
        nnet::load_weights_from_txt<bias98_t, 1024>(b98, "b98.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w102, "w102.txt");
        nnet::load_weights_from_txt<bias102_t, 256>(b102, "b102.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w105, "w105.txt");
        nnet::load_weights_from_txt<bias105_t, 256>(b105, "b105.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w108, "w108.txt");
        nnet::load_weights_from_txt<bias108_t, 1024>(b108, "b108.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w112, "w112.txt");
        nnet::load_weights_from_txt<bias112_t, 256>(b112, "b112.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w115, "w115.txt");
        nnet::load_weights_from_txt<bias115_t, 256>(b115, "b115.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w118, "w118.txt");
        nnet::load_weights_from_txt<bias118_t, 1024>(b118, "b118.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w122, "w122.txt");
        nnet::load_weights_from_txt<bias122_t, 256>(b122, "b122.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w125, "w125.txt");
        nnet::load_weights_from_txt<bias125_t, 256>(b125, "b125.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w128, "w128.txt");
        nnet::load_weights_from_txt<bias128_t, 1024>(b128, "b128.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w132, "w132.txt");
        nnet::load_weights_from_txt<bias132_t, 256>(b132, "b132.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 294912>(w135, "w135.txt");
        nnet::load_weights_from_txt<bias135_t, 256>(b135, "b135.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 131072>(w138, "w138.txt");
        nnet::load_weights_from_txt<bias138_t, 1024>(b138, "b138.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 262144>(w142, "w142.txt");
        nnet::load_weights_from_txt<bias142_t, 512>(b142, "b142.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1179648>(w145, "w145.txt");
        nnet::load_weights_from_txt<bias145_t, 512>(b145, "b145.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 524288>(w148, "w148.txt");
        nnet::load_weights_from_txt<bias148_t, 2048>(b148, "b148.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1048576>(w150, "w150.txt");
        nnet::load_weights_from_txt<bias150_t, 2048>(b150, "b150.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 524288>(w154, "w154.txt");
        nnet::load_weights_from_txt<bias154_t, 512>(b154, "b154.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1179648>(w157, "w157.txt");
        nnet::load_weights_from_txt<bias157_t, 512>(b157, "b157.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 524288>(w160, "w160.txt");
        nnet::load_weights_from_txt<bias160_t, 2048>(b160, "b160.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 524288>(w164, "w164.txt");
        nnet::load_weights_from_txt<bias164_t, 512>(b164, "b164.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1179648>(w167, "w167.txt");
        nnet::load_weights_from_txt<bias167_t, 512>(b167, "b167.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 524288>(w170, "w170.txt");
        nnet::load_weights_from_txt<bias170_t, 2048>(b170, "b170.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 1024000>(w175, "w175.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 500>(b175, "b175.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    static hls::stream<layer4_t> layer4_out[N_FILT_2];
    #pragma HLS STREAM variable=layer4_out depth=1 dim=1
    if(!gpu_0_data_0[0].empty()) nnet::conv_2d_large_cl<input_t, layer4_t, config2>(gpu_0_data_0, layer4_out, w2, b2);

    static hls::stream<layer5_t> layer5_out[N_FILT_5];
    #pragma HLS STREAM variable=layer5_out depth=1 dim=1
    if(!layer4_out[0].empty()) nnet::pooling2d_cl<layer4_t, layer5_t, config5>(layer4_out, layer5_out);

    static hls::stream<layer177_t> layer177_out1[N_FILT_5];
    #pragma HLS STREAM variable=layer177_out1 depth=1 dim=1
    static hls::stream<layer177_t> layer177_out2[N_FILT_5];
    #pragma HLS STREAM variable=layer177_out2 depth=1 dim=1
    if(!layer5_out[0].empty()) nnet::split<layer5_t, layer177_t, config177>(layer5_out, layer177_out1, layer177_out2);

    static hls::stream<layer8_t> layer8_out[N_FILT_6];
    #pragma HLS STREAM variable=layer8_out depth=1 dim=1
    if(!layer177_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer177_t, layer8_t, config6>(layer177_out1, layer8_out, w6, b6);

    static hls::stream<layer11_t> layer11_out[N_FILT_9];
    #pragma HLS STREAM variable=layer11_out depth=1 dim=1
    if(!layer8_out[0].empty()) nnet::conv_2d_large_cl<layer8_t, layer11_t, config9>(layer8_out, layer11_out, w9, b9);

    static hls::stream<layer13_t> layer13_out[N_FILT_12];
    #pragma HLS STREAM variable=layer13_out depth=1 dim=1
    if(!layer11_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer11_t, layer13_t, config12>(layer11_out, layer13_out, w12, b12);

    static hls::stream<layer15_t> layer15_out[N_FILT_14];
    #pragma HLS STREAM variable=layer15_out depth=1 dim=1
    if(!layer177_out2[0].empty()) nnet::conv_2d_large_cl_1x1<layer177_t, layer15_t, config14>(layer177_out2, layer15_out, w14, b14);

    static hls::stream<layer17_t> layer17_out[N_FILT_12];
    #pragma HLS STREAM variable=layer17_out depth=1 dim=1
    if(!layer13_out[0].empty()) nnet::add<layer13_t, layer15_t, layer17_t, config16>(layer13_out, layer15_out, layer17_out);

    static hls::stream<layer178_t> layer178_out1[N_FILT_12];
    #pragma HLS STREAM variable=layer178_out1 depth=1 dim=1
    static hls::stream<layer178_t> layer178_out2[N_FILT_12];
    #pragma HLS STREAM variable=layer178_out2 depth=1 dim=1
    if(!layer17_out[0].empty()) nnet::split<layer17_t, layer178_t, config178>(layer17_out, layer178_out1, layer178_out2);

    static hls::stream<layer20_t> layer20_out[N_FILT_18];
    #pragma HLS STREAM variable=layer20_out depth=1 dim=1
    if(!layer178_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer178_t, layer20_t, config18>(layer178_out1, layer20_out, w18, b18);

    static hls::stream<layer23_t> layer23_out[N_FILT_21];
    #pragma HLS STREAM variable=layer23_out depth=1 dim=1
    if(!layer20_out[0].empty()) nnet::conv_2d_large_cl<layer20_t, layer23_t, config21>(layer20_out, layer23_out, w21, b21);

    static hls::stream<layer25_t> layer25_out[N_FILT_24];
    #pragma HLS STREAM variable=layer25_out depth=1 dim=1
    if(!layer23_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer23_t, layer25_t, config24>(layer23_out, layer25_out, w24, b24);

    static hls::stream<layer27_t> layer27_out[N_FILT_24];
    #pragma HLS STREAM variable=layer27_out depth=1 dim=1
    if(!layer25_out[0].empty()) nnet::add<layer25_t, layer178_t, layer27_t, config26>(layer25_out, layer178_out2, layer27_out);

    static hls::stream<layer179_t> layer179_out1[N_FILT_24];
    #pragma HLS STREAM variable=layer179_out1 depth=1 dim=1
    static hls::stream<layer179_t> layer179_out2[N_FILT_24];
    #pragma HLS STREAM variable=layer179_out2 depth=1 dim=1
    if(!layer27_out[0].empty()) nnet::split<layer27_t, layer179_t, config179>(layer27_out, layer179_out1, layer179_out2);

    static hls::stream<layer30_t> layer30_out[N_FILT_28];
    #pragma HLS STREAM variable=layer30_out depth=1 dim=1
    if(!layer179_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer179_t, layer30_t, config28>(layer179_out1, layer30_out, w28, b28);

    static hls::stream<layer33_t> layer33_out[N_FILT_31];
    #pragma HLS STREAM variable=layer33_out depth=1 dim=1
    if(!layer30_out[0].empty()) nnet::conv_2d_large_cl<layer30_t, layer33_t, config31>(layer30_out, layer33_out, w31, b31);

    static hls::stream<layer35_t> layer35_out[N_FILT_34];
    #pragma HLS STREAM variable=layer35_out depth=1 dim=1
    if(!layer33_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer33_t, layer35_t, config34>(layer33_out, layer35_out, w34, b34);

    static hls::stream<layer37_t> layer37_out[N_FILT_34];
    #pragma HLS STREAM variable=layer37_out depth=1 dim=1
    if(!layer35_out[0].empty()) nnet::add<layer35_t, layer179_t, layer37_t, config36>(layer35_out, layer179_out2, layer37_out);

    static hls::stream<layer180_t> layer180_out1[N_FILT_34];
    #pragma HLS STREAM variable=layer180_out1 depth=1 dim=1
    static hls::stream<layer180_t> layer180_out2[N_FILT_34];
    #pragma HLS STREAM variable=layer180_out2 depth=1 dim=1
    if(!layer37_out[0].empty()) nnet::split<layer37_t, layer180_t, config180>(layer37_out, layer180_out1, layer180_out2);

    static hls::stream<layer40_t> layer40_out[N_FILT_38];
    #pragma HLS STREAM variable=layer40_out depth=1 dim=1
    if(!layer180_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer180_t, layer40_t, config38>(layer180_out1, layer40_out, w38, b38);

    static hls::stream<layer43_t> layer43_out[N_FILT_41];
    #pragma HLS STREAM variable=layer43_out depth=1 dim=1
    if(!layer40_out[0].empty()) nnet::conv_2d_large_cl<layer40_t, layer43_t, config41>(layer40_out, layer43_out, w41, b41);

    static hls::stream<layer45_t> layer45_out[N_FILT_44];
    #pragma HLS STREAM variable=layer45_out depth=1 dim=1
    if(!layer43_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer43_t, layer45_t, config44>(layer43_out, layer45_out, w44, b44);

    static hls::stream<layer47_t> layer47_out[N_FILT_46];
    #pragma HLS STREAM variable=layer47_out depth=1 dim=1
    if(!layer180_out2[0].empty()) nnet::conv_2d_large_cl_1x1<layer180_t, layer47_t, config46>(layer180_out2, layer47_out, w46, b46);

    static hls::stream<layer49_t> layer49_out[N_FILT_44];
    #pragma HLS STREAM variable=layer49_out depth=1 dim=1
    if(!layer45_out[0].empty()) nnet::add<layer45_t, layer47_t, layer49_t, config48>(layer45_out, layer47_out, layer49_out);

    static hls::stream<layer181_t> layer181_out1[N_FILT_44];
    #pragma HLS STREAM variable=layer181_out1 depth=1 dim=1
    static hls::stream<layer181_t> layer181_out2[N_FILT_44];
    #pragma HLS STREAM variable=layer181_out2 depth=1 dim=1
    if(!layer49_out[0].empty()) nnet::split<layer49_t, layer181_t, config181>(layer49_out, layer181_out1, layer181_out2);

    static hls::stream<layer52_t> layer52_out[N_FILT_50];
    #pragma HLS STREAM variable=layer52_out depth=1 dim=1
    if(!layer181_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer181_t, layer52_t, config50>(layer181_out1, layer52_out, w50, b50);

    static hls::stream<layer55_t> layer55_out[N_FILT_53];
    #pragma HLS STREAM variable=layer55_out depth=1 dim=1
    if(!layer52_out[0].empty()) nnet::conv_2d_large_cl<layer52_t, layer55_t, config53>(layer52_out, layer55_out, w53, b53);

    static hls::stream<layer57_t> layer57_out[N_FILT_56];
    #pragma HLS STREAM variable=layer57_out depth=1 dim=1
    if(!layer55_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer55_t, layer57_t, config56>(layer55_out, layer57_out, w56, b56);

    static hls::stream<layer59_t> layer59_out[N_FILT_56];
    #pragma HLS STREAM variable=layer59_out depth=1 dim=1
    if(!layer57_out[0].empty()) nnet::add<layer57_t, layer181_t, layer59_t, config58>(layer57_out, layer181_out2, layer59_out);

    static hls::stream<layer182_t> layer182_out1[N_FILT_56];
    #pragma HLS STREAM variable=layer182_out1 depth=1 dim=1
    static hls::stream<layer182_t> layer182_out2[N_FILT_56];
    #pragma HLS STREAM variable=layer182_out2 depth=1 dim=1
    if(!layer59_out[0].empty()) nnet::split<layer59_t, layer182_t, config182>(layer59_out, layer182_out1, layer182_out2);

    static hls::stream<layer62_t> layer62_out[N_FILT_60];
    #pragma HLS STREAM variable=layer62_out depth=1 dim=1
    if(!layer182_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer182_t, layer62_t, config60>(layer182_out1, layer62_out, w60, b60);

    static hls::stream<layer65_t> layer65_out[N_FILT_63];
    #pragma HLS STREAM variable=layer65_out depth=1 dim=1
    if(!layer62_out[0].empty()) nnet::conv_2d_large_cl<layer62_t, layer65_t, config63>(layer62_out, layer65_out, w63, b63);

    static hls::stream<layer67_t> layer67_out[N_FILT_66];
    #pragma HLS STREAM variable=layer67_out depth=1 dim=1
    if(!layer65_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer65_t, layer67_t, config66>(layer65_out, layer67_out, w66, b66);

    static hls::stream<layer69_t> layer69_out[N_FILT_66];
    #pragma HLS STREAM variable=layer69_out depth=1 dim=1
    if(!layer67_out[0].empty()) nnet::add<layer67_t, layer182_t, layer69_t, config68>(layer67_out, layer182_out2, layer69_out);

    static hls::stream<layer183_t> layer183_out1[N_FILT_66];
    #pragma HLS STREAM variable=layer183_out1 depth=1 dim=1
    static hls::stream<layer183_t> layer183_out2[N_FILT_66];
    #pragma HLS STREAM variable=layer183_out2 depth=1 dim=1
    if(!layer69_out[0].empty()) nnet::split<layer69_t, layer183_t, config183>(layer69_out, layer183_out1, layer183_out2);

    static hls::stream<layer72_t> layer72_out[N_FILT_70];
    #pragma HLS STREAM variable=layer72_out depth=1 dim=1
    if(!layer183_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer183_t, layer72_t, config70>(layer183_out1, layer72_out, w70, b70);

    static hls::stream<layer75_t> layer75_out[N_FILT_73];
    #pragma HLS STREAM variable=layer75_out depth=1 dim=1
    if(!layer72_out[0].empty()) nnet::conv_2d_large_cl<layer72_t, layer75_t, config73>(layer72_out, layer75_out, w73, b73);

    static hls::stream<layer77_t> layer77_out[N_FILT_76];
    #pragma HLS STREAM variable=layer77_out depth=1 dim=1
    if(!layer75_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer75_t, layer77_t, config76>(layer75_out, layer77_out, w76, b76);

    static hls::stream<layer79_t> layer79_out[N_FILT_76];
    #pragma HLS STREAM variable=layer79_out depth=1 dim=1
    if(!layer77_out[0].empty()) nnet::add<layer77_t, layer183_t, layer79_t, config78>(layer77_out, layer183_out2, layer79_out);

    static hls::stream<layer184_t> layer184_out1[N_FILT_76];
    #pragma HLS STREAM variable=layer184_out1 depth=1 dim=1
    static hls::stream<layer184_t> layer184_out2[N_FILT_76];
    #pragma HLS STREAM variable=layer184_out2 depth=1 dim=1
    if(!layer79_out[0].empty()) nnet::split<layer79_t, layer184_t, config184>(layer79_out, layer184_out1, layer184_out2);

    static hls::stream<layer82_t> layer82_out[N_FILT_80];
    #pragma HLS STREAM variable=layer82_out depth=1 dim=1
    if(!layer184_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer184_t, layer82_t, config80>(layer184_out1, layer82_out, w80, b80);

    static hls::stream<layer85_t> layer85_out[N_FILT_83];
    #pragma HLS STREAM variable=layer85_out depth=1 dim=1
    if(!layer82_out[0].empty()) nnet::conv_2d_large_cl<layer82_t, layer85_t, config83>(layer82_out, layer85_out, w83, b83);

    static hls::stream<layer87_t> layer87_out[N_FILT_86];
    #pragma HLS STREAM variable=layer87_out depth=1 dim=1
    if(!layer85_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer85_t, layer87_t, config86>(layer85_out, layer87_out, w86, b86);

    static hls::stream<layer89_t> layer89_out[N_FILT_88];
    #pragma HLS STREAM variable=layer89_out depth=1 dim=1
    if(!layer184_out2[0].empty()) nnet::conv_2d_large_cl_1x1<layer184_t, layer89_t, config88>(layer184_out2, layer89_out, w88, b88);

    static hls::stream<layer91_t> layer91_out[N_FILT_86];
    #pragma HLS STREAM variable=layer91_out depth=1 dim=1
    if(!layer87_out[0].empty()) nnet::add<layer87_t, layer89_t, layer91_t, config90>(layer87_out, layer89_out, layer91_out);

    static hls::stream<layer185_t> layer185_out1[N_FILT_86];
    #pragma HLS STREAM variable=layer185_out1 depth=1 dim=1
    static hls::stream<layer185_t> layer185_out2[N_FILT_86];
    #pragma HLS STREAM variable=layer185_out2 depth=1 dim=1
    if(!layer91_out[0].empty()) nnet::split<layer91_t, layer185_t, config185>(layer91_out, layer185_out1, layer185_out2);

    static hls::stream<layer94_t> layer94_out[N_FILT_92];
    #pragma HLS STREAM variable=layer94_out depth=1 dim=1
    if(!layer185_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer185_t, layer94_t, config92>(layer185_out1, layer94_out, w92, b92);

    static hls::stream<layer97_t> layer97_out[N_FILT_95];
    #pragma HLS STREAM variable=layer97_out depth=1 dim=1
    if(!layer94_out[0].empty()) nnet::conv_2d_large_cl<layer94_t, layer97_t, config95>(layer94_out, layer97_out, w95, b95);

    static hls::stream<layer99_t> layer99_out[N_FILT_98];
    #pragma HLS STREAM variable=layer99_out depth=1 dim=1
    if(!layer97_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer97_t, layer99_t, config98>(layer97_out, layer99_out, w98, b98);

    static hls::stream<layer101_t> layer101_out[N_FILT_98];
    #pragma HLS STREAM variable=layer101_out depth=1 dim=1
    if(!layer99_out[0].empty()) nnet::add<layer99_t, layer185_t, layer101_t, config100>(layer99_out, layer185_out2, layer101_out);

    static hls::stream<layer186_t> layer186_out1[N_FILT_98];
    #pragma HLS STREAM variable=layer186_out1 depth=1 dim=1
    static hls::stream<layer186_t> layer186_out2[N_FILT_98];
    #pragma HLS STREAM variable=layer186_out2 depth=1 dim=1
    if(!layer101_out[0].empty()) nnet::split<layer101_t, layer186_t, config186>(layer101_out, layer186_out1, layer186_out2);

    static hls::stream<layer104_t> layer104_out[N_FILT_102];
    #pragma HLS STREAM variable=layer104_out depth=1 dim=1
    if(!layer186_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer186_t, layer104_t, config102>(layer186_out1, layer104_out, w102, b102);

    static hls::stream<layer107_t> layer107_out[N_FILT_105];
    #pragma HLS STREAM variable=layer107_out depth=1 dim=1
    if(!layer104_out[0].empty()) nnet::conv_2d_large_cl<layer104_t, layer107_t, config105>(layer104_out, layer107_out, w105, b105);

    static hls::stream<layer109_t> layer109_out[N_FILT_108];
    #pragma HLS STREAM variable=layer109_out depth=1 dim=1
    if(!layer107_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer107_t, layer109_t, config108>(layer107_out, layer109_out, w108, b108);

    static hls::stream<layer111_t> layer111_out[N_FILT_108];
    #pragma HLS STREAM variable=layer111_out depth=1 dim=1
    if(!layer109_out[0].empty()) nnet::add<layer109_t, layer186_t, layer111_t, config110>(layer109_out, layer186_out2, layer111_out);

    static hls::stream<layer187_t> layer187_out1[N_FILT_108];
    #pragma HLS STREAM variable=layer187_out1 depth=1 dim=1
    static hls::stream<layer187_t> layer187_out2[N_FILT_108];
    #pragma HLS STREAM variable=layer187_out2 depth=1 dim=1
    if(!layer111_out[0].empty()) nnet::split<layer111_t, layer187_t, config187>(layer111_out, layer187_out1, layer187_out2);

    static hls::stream<layer114_t> layer114_out[N_FILT_112];
    #pragma HLS STREAM variable=layer114_out depth=1 dim=1
    if(!layer187_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer187_t, layer114_t, config112>(layer187_out1, layer114_out, w112, b112);

    static hls::stream<layer117_t> layer117_out[N_FILT_115];
    #pragma HLS STREAM variable=layer117_out depth=1 dim=1
    if(!layer114_out[0].empty()) nnet::conv_2d_large_cl<layer114_t, layer117_t, config115>(layer114_out, layer117_out, w115, b115);

    static hls::stream<layer119_t> layer119_out[N_FILT_118];
    #pragma HLS STREAM variable=layer119_out depth=1 dim=1
    if(!layer117_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer117_t, layer119_t, config118>(layer117_out, layer119_out, w118, b118);

    static hls::stream<layer121_t> layer121_out[N_FILT_118];
    #pragma HLS STREAM variable=layer121_out depth=1 dim=1
    if(!layer119_out[0].empty()) nnet::add<layer119_t, layer187_t, layer121_t, config120>(layer119_out, layer187_out2, layer121_out);

    static hls::stream<layer188_t> layer188_out1[N_FILT_118];
    #pragma HLS STREAM variable=layer188_out1 depth=1 dim=1
    static hls::stream<layer188_t> layer188_out2[N_FILT_118];
    #pragma HLS STREAM variable=layer188_out2 depth=1 dim=1
    if(!layer121_out[0].empty()) nnet::split<layer121_t, layer188_t, config188>(layer121_out, layer188_out1, layer188_out2);

    static hls::stream<layer124_t> layer124_out[N_FILT_122];
    #pragma HLS STREAM variable=layer124_out depth=1 dim=1
    if(!layer188_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer188_t, layer124_t, config122>(layer188_out1, layer124_out, w122, b122);

    static hls::stream<layer127_t> layer127_out[N_FILT_125];
    #pragma HLS STREAM variable=layer127_out depth=1 dim=1
    if(!layer124_out[0].empty()) nnet::conv_2d_large_cl<layer124_t, layer127_t, config125>(layer124_out, layer127_out, w125, b125);

    static hls::stream<layer129_t> layer129_out[N_FILT_128];
    #pragma HLS STREAM variable=layer129_out depth=1 dim=1
    if(!layer127_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer127_t, layer129_t, config128>(layer127_out, layer129_out, w128, b128);

    static hls::stream<layer131_t> layer131_out[N_FILT_128];
    #pragma HLS STREAM variable=layer131_out depth=1 dim=1
    if(!layer129_out[0].empty()) nnet::add<layer129_t, layer188_t, layer131_t, config130>(layer129_out, layer188_out2, layer131_out);

    static hls::stream<layer189_t> layer189_out1[N_FILT_128];
    #pragma HLS STREAM variable=layer189_out1 depth=1 dim=1
    static hls::stream<layer189_t> layer189_out2[N_FILT_128];
    #pragma HLS STREAM variable=layer189_out2 depth=1 dim=1
    if(!layer131_out[0].empty()) nnet::split<layer131_t, layer189_t, config189>(layer131_out, layer189_out1, layer189_out2);

    static hls::stream<layer134_t> layer134_out[N_FILT_132];
    #pragma HLS STREAM variable=layer134_out depth=1 dim=1
    if(!layer189_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer189_t, layer134_t, config132>(layer189_out1, layer134_out, w132, b132);

    static hls::stream<layer137_t> layer137_out[N_FILT_135];
    #pragma HLS STREAM variable=layer137_out depth=1 dim=1
    if(!layer134_out[0].empty()) nnet::conv_2d_large_cl<layer134_t, layer137_t, config135>(layer134_out, layer137_out, w135, b135);

    static hls::stream<layer139_t> layer139_out[N_FILT_138];
    #pragma HLS STREAM variable=layer139_out depth=1 dim=1
    if(!layer137_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer137_t, layer139_t, config138>(layer137_out, layer139_out, w138, b138);

    static hls::stream<layer141_t> layer141_out[N_FILT_138];
    #pragma HLS STREAM variable=layer141_out depth=1 dim=1
    if(!layer139_out[0].empty()) nnet::add<layer139_t, layer189_t, layer141_t, config140>(layer139_out, layer189_out2, layer141_out);

    static hls::stream<layer190_t> layer190_out1[N_FILT_138];
    #pragma HLS STREAM variable=layer190_out1 depth=1 dim=1
    static hls::stream<layer190_t> layer190_out2[N_FILT_138];
    #pragma HLS STREAM variable=layer190_out2 depth=1 dim=1
    if(!layer141_out[0].empty()) nnet::split<layer141_t, layer190_t, config190>(layer141_out, layer190_out1, layer190_out2);

    static hls::stream<layer144_t> layer144_out[N_FILT_142];
    #pragma HLS STREAM variable=layer144_out depth=1 dim=1
    if(!layer190_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer190_t, layer144_t, config142>(layer190_out1, layer144_out, w142, b142);

    static hls::stream<layer147_t> layer147_out[N_FILT_145];
    #pragma HLS STREAM variable=layer147_out depth=1 dim=1
    if(!layer144_out[0].empty()) nnet::conv_2d_large_cl<layer144_t, layer147_t, config145>(layer144_out, layer147_out, w145, b145);

    static hls::stream<layer149_t> layer149_out[N_FILT_148];
    #pragma HLS STREAM variable=layer149_out depth=1 dim=1
    if(!layer147_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer147_t, layer149_t, config148>(layer147_out, layer149_out, w148, b148);

    static hls::stream<layer151_t> layer151_out[N_FILT_150];
    #pragma HLS STREAM variable=layer151_out depth=1 dim=1
    if(!layer190_out2[0].empty()) nnet::conv_2d_large_cl_1x1<layer190_t, layer151_t, config150>(layer190_out2, layer151_out, w150, b150);

    static hls::stream<layer153_t> layer153_out[N_FILT_148];
    #pragma HLS STREAM variable=layer153_out depth=1 dim=1
    if(!layer149_out[0].empty()) nnet::add<layer149_t, layer151_t, layer153_t, config152>(layer149_out, layer151_out, layer153_out);

    static hls::stream<layer191_t> layer191_out1[N_FILT_148];
    #pragma HLS STREAM variable=layer191_out1 depth=1 dim=1
    static hls::stream<layer191_t> layer191_out2[N_FILT_148];
    #pragma HLS STREAM variable=layer191_out2 depth=1 dim=1
    if(!layer153_out[0].empty()) nnet::split<layer153_t, layer191_t, config191>(layer153_out, layer191_out1, layer191_out2);

    static hls::stream<layer156_t> layer156_out[N_FILT_154];
    #pragma HLS STREAM variable=layer156_out depth=1 dim=1
    if(!layer191_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer191_t, layer156_t, config154>(layer191_out1, layer156_out, w154, b154);

    static hls::stream<layer159_t> layer159_out[N_FILT_157];
    #pragma HLS STREAM variable=layer159_out depth=1 dim=1
    if(!layer156_out[0].empty()) nnet::conv_2d_large_cl<layer156_t, layer159_t, config157>(layer156_out, layer159_out, w157, b157);

    static hls::stream<layer161_t> layer161_out[N_FILT_160];
    #pragma HLS STREAM variable=layer161_out depth=1 dim=1
    if(!layer159_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer159_t, layer161_t, config160>(layer159_out, layer161_out, w160, b160);

    static hls::stream<layer163_t> layer163_out[N_FILT_160];
    #pragma HLS STREAM variable=layer163_out depth=1 dim=1
    if(!layer161_out[0].empty()) nnet::add<layer161_t, layer191_t, layer163_t, config162>(layer161_out, layer191_out2, layer163_out);

    static hls::stream<layer192_t> layer192_out1[N_FILT_160];
    #pragma HLS STREAM variable=layer192_out1 depth=1 dim=1
    static hls::stream<layer192_t> layer192_out2[N_FILT_160];
    #pragma HLS STREAM variable=layer192_out2 depth=1 dim=1
    if(!layer163_out[0].empty()) nnet::split<layer163_t, layer192_t, config192>(layer163_out, layer192_out1, layer192_out2);

    static hls::stream<layer166_t> layer166_out[N_FILT_164];
    #pragma HLS STREAM variable=layer166_out depth=1 dim=1
    if(!layer192_out1[0].empty()) nnet::conv_2d_large_cl_1x1<layer192_t, layer166_t, config164>(layer192_out1, layer166_out, w164, b164);

    static hls::stream<layer169_t> layer169_out[N_FILT_167];
    #pragma HLS STREAM variable=layer169_out depth=1 dim=1
    if(!layer166_out[0].empty()) nnet::conv_2d_large_cl<layer166_t, layer169_t, config167>(layer166_out, layer169_out, w167, b167);

    static hls::stream<layer171_t> layer171_out[N_FILT_170];
    #pragma HLS STREAM variable=layer171_out depth=1 dim=1
    if(!layer169_out[0].empty()) nnet::conv_2d_large_cl_1x1<layer169_t, layer171_t, config170>(layer169_out, layer171_out, w170, b170);

    static hls::stream<layer173_t> layer173_out[N_FILT_170];
    #pragma HLS STREAM variable=layer173_out depth=1 dim=1
    if(!layer171_out[0].empty()) nnet::add<layer171_t, layer192_t, layer173_t, config172>(layer171_out, layer192_out2, layer173_out);

    static hls::stream<layer174_t> layer174_out[N_FILT_174];
    #pragma HLS STREAM variable=layer174_out depth=1 dim=1
    if(!layer173_out[0].empty()) nnet::pooling2d_cl_1x1<layer173_t, layer174_t, config174>(layer173_out, layer174_out);

    static hls::stream<layer175_t> layer175_out[N_LAYER_175];
    #pragma HLS STREAM variable=layer175_out depth=1 dim=1
    if(!layer174_out[0].empty()) nnet::dense_large_stream<layer174_t, layer175_t, config175>(layer174_out, layer175_out, w175, b175);

    if(!layer175_out[0].empty()) nnet::softmax_stream<layer175_t, result_t, softmax_config176>(layer175_out, layer176_out);

}
