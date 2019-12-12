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
#include "weights/s7.h"
#include "weights/b7.h"
#include "weights/w9.h"
#include "weights/b9.h"
#include "weights/s10.h"
#include "weights/b10.h"
#include "weights/w12.h"
#include "weights/b12.h"
#include "weights/s13.h"
#include "weights/b13.h"
#include "weights/w14.h"
#include "weights/b14.h"
#include "weights/s15.h"
#include "weights/b15.h"
#include "weights/w18.h"
#include "weights/b18.h"
#include "weights/s19.h"
#include "weights/b19.h"
#include "weights/w21.h"
#include "weights/b21.h"
#include "weights/s22.h"
#include "weights/b22.h"
#include "weights/w24.h"
#include "weights/b24.h"
#include "weights/s25.h"
#include "weights/b25.h"
#include "weights/w28.h"
#include "weights/b28.h"
#include "weights/s29.h"
#include "weights/b29.h"
#include "weights/w31.h"
#include "weights/b31.h"
#include "weights/s32.h"
#include "weights/b32.h"
#include "weights/w34.h"
#include "weights/b34.h"
#include "weights/s35.h"
#include "weights/b35.h"
#include "weights/w38.h"
#include "weights/b38.h"
#include "weights/s39.h"
#include "weights/b39.h"
#include "weights/w41.h"
#include "weights/b41.h"
#include "weights/s42.h"
#include "weights/b42.h"
#include "weights/w44.h"
#include "weights/b44.h"
#include "weights/s45.h"
#include "weights/b45.h"
#include "weights/w46.h"
#include "weights/b46.h"
#include "weights/s47.h"
#include "weights/b47.h"
#include "weights/w50.h"
#include "weights/b50.h"
#include "weights/s51.h"
#include "weights/b51.h"
#include "weights/w53.h"
#include "weights/b53.h"
#include "weights/s54.h"
#include "weights/b54.h"
#include "weights/w56.h"
#include "weights/b56.h"
#include "weights/s57.h"
#include "weights/b57.h"
#include "weights/w60.h"
#include "weights/b60.h"
#include "weights/s61.h"
#include "weights/b61.h"
#include "weights/w63.h"
#include "weights/b63.h"
#include "weights/s64.h"
#include "weights/b64.h"
#include "weights/w66.h"
#include "weights/b66.h"
#include "weights/s67.h"
#include "weights/b67.h"
#include "weights/w70.h"
#include "weights/b70.h"
#include "weights/s71.h"
#include "weights/b71.h"
#include "weights/w73.h"
#include "weights/b73.h"
#include "weights/s74.h"
#include "weights/b74.h"
#include "weights/w76.h"
#include "weights/b76.h"
#include "weights/s77.h"
#include "weights/b77.h"
#include "weights/w80.h"
#include "weights/b80.h"
#include "weights/s81.h"
#include "weights/b81.h"
#include "weights/w83.h"
#include "weights/b83.h"
#include "weights/s84.h"
#include "weights/b84.h"
#include "weights/w86.h"
#include "weights/b86.h"
#include "weights/s87.h"
#include "weights/b87.h"
#include "weights/w88.h"
#include "weights/b88.h"
#include "weights/s89.h"
#include "weights/b89.h"
#include "weights/w92.h"
#include "weights/b92.h"
#include "weights/s93.h"
#include "weights/b93.h"
#include "weights/w95.h"
#include "weights/b95.h"
#include "weights/s96.h"
#include "weights/b96.h"
#include "weights/w98.h"
#include "weights/b98.h"
#include "weights/s99.h"
#include "weights/b99.h"
#include "weights/w102.h"
#include "weights/b102.h"
#include "weights/s103.h"
#include "weights/b103.h"
#include "weights/w105.h"
#include "weights/b105.h"
#include "weights/s106.h"
#include "weights/b106.h"
#include "weights/w108.h"
#include "weights/b108.h"
#include "weights/s109.h"
#include "weights/b109.h"
#include "weights/w112.h"
#include "weights/b112.h"
#include "weights/s113.h"
#include "weights/b113.h"
#include "weights/w115.h"
#include "weights/b115.h"
#include "weights/s116.h"
#include "weights/b116.h"
#include "weights/w118.h"
#include "weights/b118.h"
#include "weights/s119.h"
#include "weights/b119.h"
#include "weights/w122.h"
#include "weights/b122.h"
#include "weights/s123.h"
#include "weights/b123.h"
#include "weights/w125.h"
#include "weights/b125.h"
#include "weights/s126.h"
#include "weights/b126.h"
#include "weights/w128.h"
#include "weights/b128.h"
#include "weights/s129.h"
#include "weights/b129.h"
#include "weights/w132.h"
#include "weights/b132.h"
#include "weights/s133.h"
#include "weights/b133.h"
#include "weights/w135.h"
#include "weights/b135.h"
#include "weights/s136.h"
#include "weights/b136.h"
#include "weights/w138.h"
#include "weights/b138.h"
#include "weights/s139.h"
#include "weights/b139.h"
#include "weights/w142.h"
#include "weights/b142.h"
#include "weights/s143.h"
#include "weights/b143.h"
#include "weights/w145.h"
#include "weights/b145.h"
#include "weights/s146.h"
#include "weights/b146.h"
#include "weights/w148.h"
#include "weights/b148.h"
#include "weights/s149.h"
#include "weights/b149.h"
#include "weights/w150.h"
#include "weights/b150.h"
#include "weights/s151.h"
#include "weights/b151.h"
#include "weights/w154.h"
#include "weights/b154.h"
#include "weights/s155.h"
#include "weights/b155.h"
#include "weights/w157.h"
#include "weights/b157.h"
#include "weights/s158.h"
#include "weights/b158.h"
#include "weights/w160.h"
#include "weights/b160.h"
#include "weights/s161.h"
#include "weights/b161.h"
#include "weights/w164.h"
#include "weights/b164.h"
#include "weights/s165.h"
#include "weights/b165.h"
#include "weights/w167.h"
#include "weights/b167.h"
#include "weights/s168.h"
#include "weights/b168.h"
#include "weights/w170.h"
#include "weights/b170.h"
#include "weights/s171.h"
#include "weights/b171.h"
#include "weights/w175.h"
#include "weights/b175.h"

void myproject(
    input_t gpu_0_data_0[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer176_out[N_LAYER_175],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=gpu_0_data_0 complete dim=0 
    #pragma HLS ARRAY_RESHAPE variable=layer176_out complete dim=0 
    #pragma HLS INTERFACE ap_vld port=gpu_0_data_0,layer176_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
    const_size_out_1 = N_LAYER_175;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 9408>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 56>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b3, "b3.txt");
        nnet::load_weights_from_txt<model_default_t, 4096>(w6, "w6.txt");
        nnet::load_weights_from_txt<bias6_t, 56>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s7, "s7.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b7, "b7.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w9, "w9.txt");
        nnet::load_weights_from_txt<bias9_t, 56>(b9, "b9.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s10, "s10.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w12, "w12.txt");
        nnet::load_weights_from_txt<bias12_t, 56>(b12, "b12.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s13, "s13.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b13, "b13.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w14, "w14.txt");
        nnet::load_weights_from_txt<bias14_t, 56>(b14, "b14.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s15, "s15.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b15, "b15.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w18, "w18.txt");
        nnet::load_weights_from_txt<bias18_t, 56>(b18, "b18.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s19, "s19.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b19, "b19.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w21, "w21.txt");
        nnet::load_weights_from_txt<bias21_t, 56>(b21, "b21.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s22, "s22.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b22, "b22.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w24, "w24.txt");
        nnet::load_weights_from_txt<bias24_t, 56>(b24, "b24.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s25, "s25.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b25, "b25.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w28, "w28.txt");
        nnet::load_weights_from_txt<bias28_t, 56>(b28, "b28.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s29, "s29.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b29, "b29.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w31, "w31.txt");
        nnet::load_weights_from_txt<bias31_t, 56>(b31, "b31.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s32, "s32.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b32, "b32.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w34, "w34.txt");
        nnet::load_weights_from_txt<bias34_t, 56>(b34, "b34.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s35, "s35.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b35, "b35.txt");
        nnet::load_weights_from_txt<model_default_t, 32768>(w38, "w38.txt");
        nnet::load_weights_from_txt<bias38_t, 56>(b38, "b38.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s39, "s39.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b39, "b39.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w41, "w41.txt");
        nnet::load_weights_from_txt<bias41_t, 28>(b41, "b41.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s42, "s42.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b42, "b42.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w44, "w44.txt");
        nnet::load_weights_from_txt<bias44_t, 28>(b44, "b44.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s45, "s45.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b45, "b45.txt");
        nnet::load_weights_from_txt<model_default_t, 131072>(w46, "w46.txt");
        nnet::load_weights_from_txt<bias46_t, 28>(b46, "b46.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s47, "s47.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b47, "b47.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w50, "w50.txt");
        nnet::load_weights_from_txt<bias50_t, 28>(b50, "b50.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s51, "s51.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b51, "b51.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w53, "w53.txt");
        nnet::load_weights_from_txt<bias53_t, 28>(b53, "b53.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s54, "s54.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b54, "b54.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w56, "w56.txt");
        nnet::load_weights_from_txt<bias56_t, 28>(b56, "b56.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s57, "s57.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b57, "b57.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w60, "w60.txt");
        nnet::load_weights_from_txt<bias60_t, 28>(b60, "b60.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s61, "s61.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b61, "b61.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w63, "w63.txt");
        nnet::load_weights_from_txt<bias63_t, 28>(b63, "b63.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s64, "s64.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b64, "b64.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w66, "w66.txt");
        nnet::load_weights_from_txt<bias66_t, 28>(b66, "b66.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s67, "s67.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b67, "b67.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w70, "w70.txt");
        nnet::load_weights_from_txt<bias70_t, 28>(b70, "b70.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s71, "s71.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b71, "b71.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w73, "w73.txt");
        nnet::load_weights_from_txt<bias73_t, 28>(b73, "b73.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s74, "s74.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b74, "b74.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w76, "w76.txt");
        nnet::load_weights_from_txt<bias76_t, 28>(b76, "b76.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s77, "s77.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b77, "b77.txt");
        nnet::load_weights_from_txt<model_default_t, 131072>(w80, "w80.txt");
        nnet::load_weights_from_txt<bias80_t, 28>(b80, "b80.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s81, "s81.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b81, "b81.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w83, "w83.txt");
        nnet::load_weights_from_txt<bias83_t, 14>(b83, "b83.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s84, "s84.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b84, "b84.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w86, "w86.txt");
        nnet::load_weights_from_txt<bias86_t, 14>(b86, "b86.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s87, "s87.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b87, "b87.txt");
        nnet::load_weights_from_txt<model_default_t, 524288>(w88, "w88.txt");
        nnet::load_weights_from_txt<bias88_t, 14>(b88, "b88.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s89, "s89.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b89, "b89.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w92, "w92.txt");
        nnet::load_weights_from_txt<bias92_t, 14>(b92, "b92.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s93, "s93.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b93, "b93.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w95, "w95.txt");
        nnet::load_weights_from_txt<bias95_t, 14>(b95, "b95.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s96, "s96.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b96, "b96.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w98, "w98.txt");
        nnet::load_weights_from_txt<bias98_t, 14>(b98, "b98.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s99, "s99.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b99, "b99.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w102, "w102.txt");
        nnet::load_weights_from_txt<bias102_t, 14>(b102, "b102.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s103, "s103.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b103, "b103.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w105, "w105.txt");
        nnet::load_weights_from_txt<bias105_t, 14>(b105, "b105.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s106, "s106.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b106, "b106.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w108, "w108.txt");
        nnet::load_weights_from_txt<bias108_t, 14>(b108, "b108.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s109, "s109.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b109, "b109.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w112, "w112.txt");
        nnet::load_weights_from_txt<bias112_t, 14>(b112, "b112.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s113, "s113.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b113, "b113.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w115, "w115.txt");
        nnet::load_weights_from_txt<bias115_t, 14>(b115, "b115.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s116, "s116.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b116, "b116.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w118, "w118.txt");
        nnet::load_weights_from_txt<bias118_t, 14>(b118, "b118.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s119, "s119.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b119, "b119.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w122, "w122.txt");
        nnet::load_weights_from_txt<bias122_t, 14>(b122, "b122.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s123, "s123.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b123, "b123.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w125, "w125.txt");
        nnet::load_weights_from_txt<bias125_t, 14>(b125, "b125.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s126, "s126.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b126, "b126.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w128, "w128.txt");
        nnet::load_weights_from_txt<bias128_t, 14>(b128, "b128.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s129, "s129.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b129, "b129.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w132, "w132.txt");
        nnet::load_weights_from_txt<bias132_t, 14>(b132, "b132.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s133, "s133.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b133, "b133.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w135, "w135.txt");
        nnet::load_weights_from_txt<bias135_t, 14>(b135, "b135.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s136, "s136.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b136, "b136.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w138, "w138.txt");
        nnet::load_weights_from_txt<bias138_t, 14>(b138, "b138.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s139, "s139.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b139, "b139.txt");
        nnet::load_weights_from_txt<model_default_t, 524288>(w142, "w142.txt");
        nnet::load_weights_from_txt<bias142_t, 14>(b142, "b142.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s143, "s143.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b143, "b143.txt");
        nnet::load_weights_from_txt<model_default_t, 2359296>(w145, "w145.txt");
        nnet::load_weights_from_txt<bias145_t, 7>(b145, "b145.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s146, "s146.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b146, "b146.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w148, "w148.txt");
        nnet::load_weights_from_txt<bias148_t, 7>(b148, "b148.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s149, "s149.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b149, "b149.txt");
        nnet::load_weights_from_txt<model_default_t, 2097152>(w150, "w150.txt");
        nnet::load_weights_from_txt<bias150_t, 7>(b150, "b150.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s151, "s151.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b151, "b151.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w154, "w154.txt");
        nnet::load_weights_from_txt<bias154_t, 7>(b154, "b154.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s155, "s155.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b155, "b155.txt");
        nnet::load_weights_from_txt<model_default_t, 2359296>(w157, "w157.txt");
        nnet::load_weights_from_txt<bias157_t, 7>(b157, "b157.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s158, "s158.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b158, "b158.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w160, "w160.txt");
        nnet::load_weights_from_txt<bias160_t, 7>(b160, "b160.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s161, "s161.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b161, "b161.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w164, "w164.txt");
        nnet::load_weights_from_txt<bias164_t, 7>(b164, "b164.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s165, "s165.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b165, "b165.txt");
        nnet::load_weights_from_txt<model_default_t, 2359296>(w167, "w167.txt");
        nnet::load_weights_from_txt<bias167_t, 7>(b167, "b167.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s168, "s168.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b168, "b168.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w170, "w170.txt");
        nnet::load_weights_from_txt<bias170_t, 7>(b170, "b170.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s171, "s171.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b171, "b171.txt");
        nnet::load_weights_from_txt<model_default_t, 2048000>(w175, "w175.txt");
        nnet::load_weights_from_txt<model_default_t, 1000>(b175, "b175.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    layer2_t layer2_out[N_FILT_2*OUT_HEIGHT_2*OUT_WIDTH_2];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0
    nnet::conv_2d_large_cl<input_t, layer2_t, config2>(gpu_0/data_0, layer2_out, w2, b2);

    layer3_t layer3_out[N_FILT_2*OUT_HEIGHT_2*OUT_WIDTH_2];
    #pragma HLS ARRAY_PARTITION variable=layer3_out complete dim=0
    nnet::normalize<layer2_t, layer3_t, config3>(layer2_out, layer3_out, s3, b3);

    layer4_t layer4_out[N_FILT_2*OUT_HEIGHT_2*OUT_WIDTH_2];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0
    nnet::relu<layer3_t, layer4_t, relu_config4>(layer3_out, layer4_out);

    layer5_t layer5_out[OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0
    nnet::pooling2d_cl<layer4_t, config5>(layer4_out, layer5_out);

    layer6_t layer6_out[N_FILT_6*OUT_HEIGHT_6*OUT_WIDTH_6];
    #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0
    nnet::conv_2d_large_cl<layer5_t, layer6_t, config6>(layer5_out, layer6_out, w6, b6);

    layer7_t layer7_out[N_FILT_6*OUT_HEIGHT_6*OUT_WIDTH_6];
    #pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0
    nnet::normalize<layer6_t, layer7_t, config7>(layer6_out, layer7_out, s7, b7);

    layer8_t layer8_out[N_FILT_6*OUT_HEIGHT_6*OUT_WIDTH_6];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0
    nnet::relu<layer7_t, layer8_t, relu_config8>(layer7_out, layer8_out);

    layer9_t layer9_out[N_FILT_9*OUT_HEIGHT_9*OUT_WIDTH_9];
    #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0
    nnet::conv_2d_large_cl<layer8_t, layer9_t, config9>(layer8_out, layer9_out, w9, b9);

    layer10_t layer10_out[N_FILT_9*OUT_HEIGHT_9*OUT_WIDTH_9];
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
    nnet::normalize<layer9_t, layer10_t, config10>(layer9_out, layer10_out, s10, b10);

    layer11_t layer11_out[N_FILT_9*OUT_HEIGHT_9*OUT_WIDTH_9];
    #pragma HLS ARRAY_PARTITION variable=layer11_out complete dim=0
    nnet::relu<layer10_t, layer11_t, relu_config11>(layer10_out, layer11_out);

    layer12_t layer12_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_PARTITION variable=layer12_out complete dim=0
    nnet::conv_2d_large_cl<layer11_t, layer12_t, config12>(layer11_out, layer12_out, w12, b12);

    layer13_t layer13_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_PARTITION variable=layer13_out complete dim=0
    nnet::normalize<layer12_t, layer13_t, config13>(layer12_out, layer13_out, s13, b13);

    layer14_t layer14_out[N_FILT_14*OUT_HEIGHT_14*OUT_WIDTH_14];
    #pragma HLS ARRAY_PARTITION variable=layer14_out complete dim=0
    nnet::conv_2d_large_cl<layer5_t, layer14_t, config14>(layer5_out, layer14_out, w14, b14);

    layer15_t layer15_out[N_FILT_14*OUT_HEIGHT_14*OUT_WIDTH_14];
    #pragma HLS ARRAY_PARTITION variable=layer15_out complete dim=0
    nnet::normalize<layer14_t, layer15_t, config15>(layer14_out, layer15_out, s15, b15);

    layer16_t layer16_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_PARTITION variable=layer16_out complete dim=0
    nnet::add<layer13_t, layer15_t, layer16_t, config16>(layer13_out, layer15_out, layer16_out);

    layer17_t layer17_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_PARTITION variable=layer17_out complete dim=0
    nnet::relu<layer16_t, layer17_t, relu_config17>(layer16_out, layer17_out);

    layer18_t layer18_out[N_FILT_18*OUT_HEIGHT_18*OUT_WIDTH_18];
    #pragma HLS ARRAY_PARTITION variable=layer18_out complete dim=0
    nnet::conv_2d_large_cl<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18, b18);

    layer19_t layer19_out[N_FILT_18*OUT_HEIGHT_18*OUT_WIDTH_18];
    #pragma HLS ARRAY_PARTITION variable=layer19_out complete dim=0
    nnet::normalize<layer18_t, layer19_t, config19>(layer18_out, layer19_out, s19, b19);

    layer20_t layer20_out[N_FILT_18*OUT_HEIGHT_18*OUT_WIDTH_18];
    #pragma HLS ARRAY_PARTITION variable=layer20_out complete dim=0
    nnet::relu<layer19_t, layer20_t, relu_config20>(layer19_out, layer20_out);

    layer21_t layer21_out[N_FILT_21*OUT_HEIGHT_21*OUT_WIDTH_21];
    #pragma HLS ARRAY_PARTITION variable=layer21_out complete dim=0
    nnet::conv_2d_large_cl<layer20_t, layer21_t, config21>(layer20_out, layer21_out, w21, b21);

    layer22_t layer22_out[N_FILT_21*OUT_HEIGHT_21*OUT_WIDTH_21];
    #pragma HLS ARRAY_PARTITION variable=layer22_out complete dim=0
    nnet::normalize<layer21_t, layer22_t, config22>(layer21_out, layer22_out, s22, b22);

    layer23_t layer23_out[N_FILT_21*OUT_HEIGHT_21*OUT_WIDTH_21];
    #pragma HLS ARRAY_PARTITION variable=layer23_out complete dim=0
    nnet::relu<layer22_t, layer23_t, relu_config23>(layer22_out, layer23_out);

    layer24_t layer24_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_PARTITION variable=layer24_out complete dim=0
    nnet::conv_2d_large_cl<layer23_t, layer24_t, config24>(layer23_out, layer24_out, w24, b24);

    layer25_t layer25_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_PARTITION variable=layer25_out complete dim=0
    nnet::normalize<layer24_t, layer25_t, config25>(layer24_out, layer25_out, s25, b25);

    layer26_t layer26_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_PARTITION variable=layer26_out complete dim=0
    nnet::add<layer25_t, layer17_t, layer26_t, config26>(layer25_out, layer17_out, layer26_out);

    layer27_t layer27_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_PARTITION variable=layer27_out complete dim=0
    nnet::relu<layer26_t, layer27_t, relu_config27>(layer26_out, layer27_out);

    layer28_t layer28_out[N_FILT_28*OUT_HEIGHT_28*OUT_WIDTH_28];
    #pragma HLS ARRAY_PARTITION variable=layer28_out complete dim=0
    nnet::conv_2d_large_cl<layer27_t, layer28_t, config28>(layer27_out, layer28_out, w28, b28);

    layer29_t layer29_out[N_FILT_28*OUT_HEIGHT_28*OUT_WIDTH_28];
    #pragma HLS ARRAY_PARTITION variable=layer29_out complete dim=0
    nnet::normalize<layer28_t, layer29_t, config29>(layer28_out, layer29_out, s29, b29);

    layer30_t layer30_out[N_FILT_28*OUT_HEIGHT_28*OUT_WIDTH_28];
    #pragma HLS ARRAY_PARTITION variable=layer30_out complete dim=0
    nnet::relu<layer29_t, layer30_t, relu_config30>(layer29_out, layer30_out);

    layer31_t layer31_out[N_FILT_31*OUT_HEIGHT_31*OUT_WIDTH_31];
    #pragma HLS ARRAY_PARTITION variable=layer31_out complete dim=0
    nnet::conv_2d_large_cl<layer30_t, layer31_t, config31>(layer30_out, layer31_out, w31, b31);

    layer32_t layer32_out[N_FILT_31*OUT_HEIGHT_31*OUT_WIDTH_31];
    #pragma HLS ARRAY_PARTITION variable=layer32_out complete dim=0
    nnet::normalize<layer31_t, layer32_t, config32>(layer31_out, layer32_out, s32, b32);

    layer33_t layer33_out[N_FILT_31*OUT_HEIGHT_31*OUT_WIDTH_31];
    #pragma HLS ARRAY_PARTITION variable=layer33_out complete dim=0
    nnet::relu<layer32_t, layer33_t, relu_config33>(layer32_out, layer33_out);

    layer34_t layer34_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_PARTITION variable=layer34_out complete dim=0
    nnet::conv_2d_large_cl<layer33_t, layer34_t, config34>(layer33_out, layer34_out, w34, b34);

    layer35_t layer35_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_PARTITION variable=layer35_out complete dim=0
    nnet::normalize<layer34_t, layer35_t, config35>(layer34_out, layer35_out, s35, b35);

    layer36_t layer36_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_PARTITION variable=layer36_out complete dim=0
    nnet::add<layer35_t, layer27_t, layer36_t, config36>(layer35_out, layer27_out, layer36_out);

    layer37_t layer37_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_PARTITION variable=layer37_out complete dim=0
    nnet::relu<layer36_t, layer37_t, relu_config37>(layer36_out, layer37_out);

    layer38_t layer38_out[N_FILT_38*OUT_HEIGHT_38*OUT_WIDTH_38];
    #pragma HLS ARRAY_PARTITION variable=layer38_out complete dim=0
    nnet::conv_2d_large_cl<layer37_t, layer38_t, config38>(layer37_out, layer38_out, w38, b38);

    layer39_t layer39_out[N_FILT_38*OUT_HEIGHT_38*OUT_WIDTH_38];
    #pragma HLS ARRAY_PARTITION variable=layer39_out complete dim=0
    nnet::normalize<layer38_t, layer39_t, config39>(layer38_out, layer39_out, s39, b39);

    layer40_t layer40_out[N_FILT_38*OUT_HEIGHT_38*OUT_WIDTH_38];
    #pragma HLS ARRAY_PARTITION variable=layer40_out complete dim=0
    nnet::relu<layer39_t, layer40_t, relu_config40>(layer39_out, layer40_out);

    layer41_t layer41_out[N_FILT_41*OUT_HEIGHT_41*OUT_WIDTH_41];
    #pragma HLS ARRAY_PARTITION variable=layer41_out complete dim=0
    nnet::conv_2d_large_cl<layer40_t, layer41_t, config41>(layer40_out, layer41_out, w41, b41);

    layer42_t layer42_out[N_FILT_41*OUT_HEIGHT_41*OUT_WIDTH_41];
    #pragma HLS ARRAY_PARTITION variable=layer42_out complete dim=0
    nnet::normalize<layer41_t, layer42_t, config42>(layer41_out, layer42_out, s42, b42);

    layer43_t layer43_out[N_FILT_41*OUT_HEIGHT_41*OUT_WIDTH_41];
    #pragma HLS ARRAY_PARTITION variable=layer43_out complete dim=0
    nnet::relu<layer42_t, layer43_t, relu_config43>(layer42_out, layer43_out);

    layer44_t layer44_out[N_FILT_44*OUT_HEIGHT_44*OUT_WIDTH_44];
    #pragma HLS ARRAY_PARTITION variable=layer44_out complete dim=0
    nnet::conv_2d_large_cl<layer43_t, layer44_t, config44>(layer43_out, layer44_out, w44, b44);

    layer45_t layer45_out[N_FILT_44*OUT_HEIGHT_44*OUT_WIDTH_44];
    #pragma HLS ARRAY_PARTITION variable=layer45_out complete dim=0
    nnet::normalize<layer44_t, layer45_t, config45>(layer44_out, layer45_out, s45, b45);

    layer46_t layer46_out[N_FILT_46*OUT_HEIGHT_46*OUT_WIDTH_46];
    #pragma HLS ARRAY_PARTITION variable=layer46_out complete dim=0
    nnet::conv_2d_large_cl<layer37_t, layer46_t, config46>(layer37_out, layer46_out, w46, b46);

    layer47_t layer47_out[N_FILT_46*OUT_HEIGHT_46*OUT_WIDTH_46];
    #pragma HLS ARRAY_PARTITION variable=layer47_out complete dim=0
    nnet::normalize<layer46_t, layer47_t, config47>(layer46_out, layer47_out, s47, b47);

    layer48_t layer48_out[N_FILT_44*OUT_HEIGHT_44*OUT_WIDTH_44];
    #pragma HLS ARRAY_PARTITION variable=layer48_out complete dim=0
    nnet::add<layer45_t, layer47_t, layer48_t, config48>(layer45_out, layer47_out, layer48_out);

    layer49_t layer49_out[N_FILT_44*OUT_HEIGHT_44*OUT_WIDTH_44];
    #pragma HLS ARRAY_PARTITION variable=layer49_out complete dim=0
    nnet::relu<layer48_t, layer49_t, relu_config49>(layer48_out, layer49_out);

    layer50_t layer50_out[N_FILT_50*OUT_HEIGHT_50*OUT_WIDTH_50];
    #pragma HLS ARRAY_PARTITION variable=layer50_out complete dim=0
    nnet::conv_2d_large_cl<layer49_t, layer50_t, config50>(layer49_out, layer50_out, w50, b50);

    layer51_t layer51_out[N_FILT_50*OUT_HEIGHT_50*OUT_WIDTH_50];
    #pragma HLS ARRAY_PARTITION variable=layer51_out complete dim=0
    nnet::normalize<layer50_t, layer51_t, config51>(layer50_out, layer51_out, s51, b51);

    layer52_t layer52_out[N_FILT_50*OUT_HEIGHT_50*OUT_WIDTH_50];
    #pragma HLS ARRAY_PARTITION variable=layer52_out complete dim=0
    nnet::relu<layer51_t, layer52_t, relu_config52>(layer51_out, layer52_out);

    layer53_t layer53_out[N_FILT_53*OUT_HEIGHT_53*OUT_WIDTH_53];
    #pragma HLS ARRAY_PARTITION variable=layer53_out complete dim=0
    nnet::conv_2d_large_cl<layer52_t, layer53_t, config53>(layer52_out, layer53_out, w53, b53);

    layer54_t layer54_out[N_FILT_53*OUT_HEIGHT_53*OUT_WIDTH_53];
    #pragma HLS ARRAY_PARTITION variable=layer54_out complete dim=0
    nnet::normalize<layer53_t, layer54_t, config54>(layer53_out, layer54_out, s54, b54);

    layer55_t layer55_out[N_FILT_53*OUT_HEIGHT_53*OUT_WIDTH_53];
    #pragma HLS ARRAY_PARTITION variable=layer55_out complete dim=0
    nnet::relu<layer54_t, layer55_t, relu_config55>(layer54_out, layer55_out);

    layer56_t layer56_out[N_FILT_56*OUT_HEIGHT_56*OUT_WIDTH_56];
    #pragma HLS ARRAY_PARTITION variable=layer56_out complete dim=0
    nnet::conv_2d_large_cl<layer55_t, layer56_t, config56>(layer55_out, layer56_out, w56, b56);

    layer57_t layer57_out[N_FILT_56*OUT_HEIGHT_56*OUT_WIDTH_56];
    #pragma HLS ARRAY_PARTITION variable=layer57_out complete dim=0
    nnet::normalize<layer56_t, layer57_t, config57>(layer56_out, layer57_out, s57, b57);

    layer58_t layer58_out[N_FILT_56*OUT_HEIGHT_56*OUT_WIDTH_56];
    #pragma HLS ARRAY_PARTITION variable=layer58_out complete dim=0
    nnet::add<layer57_t, layer49_t, layer58_t, config58>(layer57_out, layer49_out, layer58_out);

    layer59_t layer59_out[N_FILT_56*OUT_HEIGHT_56*OUT_WIDTH_56];
    #pragma HLS ARRAY_PARTITION variable=layer59_out complete dim=0
    nnet::relu<layer58_t, layer59_t, relu_config59>(layer58_out, layer59_out);

    layer60_t layer60_out[N_FILT_60*OUT_HEIGHT_60*OUT_WIDTH_60];
    #pragma HLS ARRAY_PARTITION variable=layer60_out complete dim=0
    nnet::conv_2d_large_cl<layer59_t, layer60_t, config60>(layer59_out, layer60_out, w60, b60);

    layer61_t layer61_out[N_FILT_60*OUT_HEIGHT_60*OUT_WIDTH_60];
    #pragma HLS ARRAY_PARTITION variable=layer61_out complete dim=0
    nnet::normalize<layer60_t, layer61_t, config61>(layer60_out, layer61_out, s61, b61);

    layer62_t layer62_out[N_FILT_60*OUT_HEIGHT_60*OUT_WIDTH_60];
    #pragma HLS ARRAY_PARTITION variable=layer62_out complete dim=0
    nnet::relu<layer61_t, layer62_t, relu_config62>(layer61_out, layer62_out);

    layer63_t layer63_out[N_FILT_63*OUT_HEIGHT_63*OUT_WIDTH_63];
    #pragma HLS ARRAY_PARTITION variable=layer63_out complete dim=0
    nnet::conv_2d_large_cl<layer62_t, layer63_t, config63>(layer62_out, layer63_out, w63, b63);

    layer64_t layer64_out[N_FILT_63*OUT_HEIGHT_63*OUT_WIDTH_63];
    #pragma HLS ARRAY_PARTITION variable=layer64_out complete dim=0
    nnet::normalize<layer63_t, layer64_t, config64>(layer63_out, layer64_out, s64, b64);

    layer65_t layer65_out[N_FILT_63*OUT_HEIGHT_63*OUT_WIDTH_63];
    #pragma HLS ARRAY_PARTITION variable=layer65_out complete dim=0
    nnet::relu<layer64_t, layer65_t, relu_config65>(layer64_out, layer65_out);

    layer66_t layer66_out[N_FILT_66*OUT_HEIGHT_66*OUT_WIDTH_66];
    #pragma HLS ARRAY_PARTITION variable=layer66_out complete dim=0
    nnet::conv_2d_large_cl<layer65_t, layer66_t, config66>(layer65_out, layer66_out, w66, b66);

    layer67_t layer67_out[N_FILT_66*OUT_HEIGHT_66*OUT_WIDTH_66];
    #pragma HLS ARRAY_PARTITION variable=layer67_out complete dim=0
    nnet::normalize<layer66_t, layer67_t, config67>(layer66_out, layer67_out, s67, b67);

    layer68_t layer68_out[N_FILT_66*OUT_HEIGHT_66*OUT_WIDTH_66];
    #pragma HLS ARRAY_PARTITION variable=layer68_out complete dim=0
    nnet::add<layer67_t, layer59_t, layer68_t, config68>(layer67_out, layer59_out, layer68_out);

    layer69_t layer69_out[N_FILT_66*OUT_HEIGHT_66*OUT_WIDTH_66];
    #pragma HLS ARRAY_PARTITION variable=layer69_out complete dim=0
    nnet::relu<layer68_t, layer69_t, relu_config69>(layer68_out, layer69_out);

    layer70_t layer70_out[N_FILT_70*OUT_HEIGHT_70*OUT_WIDTH_70];
    #pragma HLS ARRAY_PARTITION variable=layer70_out complete dim=0
    nnet::conv_2d_large_cl<layer69_t, layer70_t, config70>(layer69_out, layer70_out, w70, b70);

    layer71_t layer71_out[N_FILT_70*OUT_HEIGHT_70*OUT_WIDTH_70];
    #pragma HLS ARRAY_PARTITION variable=layer71_out complete dim=0
    nnet::normalize<layer70_t, layer71_t, config71>(layer70_out, layer71_out, s71, b71);

    layer72_t layer72_out[N_FILT_70*OUT_HEIGHT_70*OUT_WIDTH_70];
    #pragma HLS ARRAY_PARTITION variable=layer72_out complete dim=0
    nnet::relu<layer71_t, layer72_t, relu_config72>(layer71_out, layer72_out);

    layer73_t layer73_out[N_FILT_73*OUT_HEIGHT_73*OUT_WIDTH_73];
    #pragma HLS ARRAY_PARTITION variable=layer73_out complete dim=0
    nnet::conv_2d_large_cl<layer72_t, layer73_t, config73>(layer72_out, layer73_out, w73, b73);

    layer74_t layer74_out[N_FILT_73*OUT_HEIGHT_73*OUT_WIDTH_73];
    #pragma HLS ARRAY_PARTITION variable=layer74_out complete dim=0
    nnet::normalize<layer73_t, layer74_t, config74>(layer73_out, layer74_out, s74, b74);

    layer75_t layer75_out[N_FILT_73*OUT_HEIGHT_73*OUT_WIDTH_73];
    #pragma HLS ARRAY_PARTITION variable=layer75_out complete dim=0
    nnet::relu<layer74_t, layer75_t, relu_config75>(layer74_out, layer75_out);

    layer76_t layer76_out[N_FILT_76*OUT_HEIGHT_76*OUT_WIDTH_76];
    #pragma HLS ARRAY_PARTITION variable=layer76_out complete dim=0
    nnet::conv_2d_large_cl<layer75_t, layer76_t, config76>(layer75_out, layer76_out, w76, b76);

    layer77_t layer77_out[N_FILT_76*OUT_HEIGHT_76*OUT_WIDTH_76];
    #pragma HLS ARRAY_PARTITION variable=layer77_out complete dim=0
    nnet::normalize<layer76_t, layer77_t, config77>(layer76_out, layer77_out, s77, b77);

    layer78_t layer78_out[N_FILT_76*OUT_HEIGHT_76*OUT_WIDTH_76];
    #pragma HLS ARRAY_PARTITION variable=layer78_out complete dim=0
    nnet::add<layer77_t, layer69_t, layer78_t, config78>(layer77_out, layer69_out, layer78_out);

    layer79_t layer79_out[N_FILT_76*OUT_HEIGHT_76*OUT_WIDTH_76];
    #pragma HLS ARRAY_PARTITION variable=layer79_out complete dim=0
    nnet::relu<layer78_t, layer79_t, relu_config79>(layer78_out, layer79_out);

    layer80_t layer80_out[N_FILT_80*OUT_HEIGHT_80*OUT_WIDTH_80];
    #pragma HLS ARRAY_PARTITION variable=layer80_out complete dim=0
    nnet::conv_2d_large_cl<layer79_t, layer80_t, config80>(layer79_out, layer80_out, w80, b80);

    layer81_t layer81_out[N_FILT_80*OUT_HEIGHT_80*OUT_WIDTH_80];
    #pragma HLS ARRAY_PARTITION variable=layer81_out complete dim=0
    nnet::normalize<layer80_t, layer81_t, config81>(layer80_out, layer81_out, s81, b81);

    layer82_t layer82_out[N_FILT_80*OUT_HEIGHT_80*OUT_WIDTH_80];
    #pragma HLS ARRAY_PARTITION variable=layer82_out complete dim=0
    nnet::relu<layer81_t, layer82_t, relu_config82>(layer81_out, layer82_out);

    layer83_t layer83_out[N_FILT_83*OUT_HEIGHT_83*OUT_WIDTH_83];
    #pragma HLS ARRAY_PARTITION variable=layer83_out complete dim=0
    nnet::conv_2d_large_cl<layer82_t, layer83_t, config83>(layer82_out, layer83_out, w83, b83);

    layer84_t layer84_out[N_FILT_83*OUT_HEIGHT_83*OUT_WIDTH_83];
    #pragma HLS ARRAY_PARTITION variable=layer84_out complete dim=0
    nnet::normalize<layer83_t, layer84_t, config84>(layer83_out, layer84_out, s84, b84);

    layer85_t layer85_out[N_FILT_83*OUT_HEIGHT_83*OUT_WIDTH_83];
    #pragma HLS ARRAY_PARTITION variable=layer85_out complete dim=0
    nnet::relu<layer84_t, layer85_t, relu_config85>(layer84_out, layer85_out);

    layer86_t layer86_out[N_FILT_86*OUT_HEIGHT_86*OUT_WIDTH_86];
    #pragma HLS ARRAY_PARTITION variable=layer86_out complete dim=0
    nnet::conv_2d_large_cl<layer85_t, layer86_t, config86>(layer85_out, layer86_out, w86, b86);

    layer87_t layer87_out[N_FILT_86*OUT_HEIGHT_86*OUT_WIDTH_86];
    #pragma HLS ARRAY_PARTITION variable=layer87_out complete dim=0
    nnet::normalize<layer86_t, layer87_t, config87>(layer86_out, layer87_out, s87, b87);

    layer88_t layer88_out[N_FILT_88*OUT_HEIGHT_88*OUT_WIDTH_88];
    #pragma HLS ARRAY_PARTITION variable=layer88_out complete dim=0
    nnet::conv_2d_large_cl<layer79_t, layer88_t, config88>(layer79_out, layer88_out, w88, b88);

    layer89_t layer89_out[N_FILT_88*OUT_HEIGHT_88*OUT_WIDTH_88];
    #pragma HLS ARRAY_PARTITION variable=layer89_out complete dim=0
    nnet::normalize<layer88_t, layer89_t, config89>(layer88_out, layer89_out, s89, b89);

    layer90_t layer90_out[N_FILT_86*OUT_HEIGHT_86*OUT_WIDTH_86];
    #pragma HLS ARRAY_PARTITION variable=layer90_out complete dim=0
    nnet::add<layer87_t, layer89_t, layer90_t, config90>(layer87_out, layer89_out, layer90_out);

    layer91_t layer91_out[N_FILT_86*OUT_HEIGHT_86*OUT_WIDTH_86];
    #pragma HLS ARRAY_PARTITION variable=layer91_out complete dim=0
    nnet::relu<layer90_t, layer91_t, relu_config91>(layer90_out, layer91_out);

    layer92_t layer92_out[N_FILT_92*OUT_HEIGHT_92*OUT_WIDTH_92];
    #pragma HLS ARRAY_PARTITION variable=layer92_out complete dim=0
    nnet::conv_2d_large_cl<layer91_t, layer92_t, config92>(layer91_out, layer92_out, w92, b92);

    layer93_t layer93_out[N_FILT_92*OUT_HEIGHT_92*OUT_WIDTH_92];
    #pragma HLS ARRAY_PARTITION variable=layer93_out complete dim=0
    nnet::normalize<layer92_t, layer93_t, config93>(layer92_out, layer93_out, s93, b93);

    layer94_t layer94_out[N_FILT_92*OUT_HEIGHT_92*OUT_WIDTH_92];
    #pragma HLS ARRAY_PARTITION variable=layer94_out complete dim=0
    nnet::relu<layer93_t, layer94_t, relu_config94>(layer93_out, layer94_out);

    layer95_t layer95_out[N_FILT_95*OUT_HEIGHT_95*OUT_WIDTH_95];
    #pragma HLS ARRAY_PARTITION variable=layer95_out complete dim=0
    nnet::conv_2d_large_cl<layer94_t, layer95_t, config95>(layer94_out, layer95_out, w95, b95);

    layer96_t layer96_out[N_FILT_95*OUT_HEIGHT_95*OUT_WIDTH_95];
    #pragma HLS ARRAY_PARTITION variable=layer96_out complete dim=0
    nnet::normalize<layer95_t, layer96_t, config96>(layer95_out, layer96_out, s96, b96);

    layer97_t layer97_out[N_FILT_95*OUT_HEIGHT_95*OUT_WIDTH_95];
    #pragma HLS ARRAY_PARTITION variable=layer97_out complete dim=0
    nnet::relu<layer96_t, layer97_t, relu_config97>(layer96_out, layer97_out);

    layer98_t layer98_out[N_FILT_98*OUT_HEIGHT_98*OUT_WIDTH_98];
    #pragma HLS ARRAY_PARTITION variable=layer98_out complete dim=0
    nnet::conv_2d_large_cl<layer97_t, layer98_t, config98>(layer97_out, layer98_out, w98, b98);

    layer99_t layer99_out[N_FILT_98*OUT_HEIGHT_98*OUT_WIDTH_98];
    #pragma HLS ARRAY_PARTITION variable=layer99_out complete dim=0
    nnet::normalize<layer98_t, layer99_t, config99>(layer98_out, layer99_out, s99, b99);

    layer100_t layer100_out[N_FILT_98*OUT_HEIGHT_98*OUT_WIDTH_98];
    #pragma HLS ARRAY_PARTITION variable=layer100_out complete dim=0
    nnet::add<layer99_t, layer91_t, layer100_t, config100>(layer99_out, layer91_out, layer100_out);

    layer101_t layer101_out[N_FILT_98*OUT_HEIGHT_98*OUT_WIDTH_98];
    #pragma HLS ARRAY_PARTITION variable=layer101_out complete dim=0
    nnet::relu<layer100_t, layer101_t, relu_config101>(layer100_out, layer101_out);

    layer102_t layer102_out[N_FILT_102*OUT_HEIGHT_102*OUT_WIDTH_102];
    #pragma HLS ARRAY_PARTITION variable=layer102_out complete dim=0
    nnet::conv_2d_large_cl<layer101_t, layer102_t, config102>(layer101_out, layer102_out, w102, b102);

    layer103_t layer103_out[N_FILT_102*OUT_HEIGHT_102*OUT_WIDTH_102];
    #pragma HLS ARRAY_PARTITION variable=layer103_out complete dim=0
    nnet::normalize<layer102_t, layer103_t, config103>(layer102_out, layer103_out, s103, b103);

    layer104_t layer104_out[N_FILT_102*OUT_HEIGHT_102*OUT_WIDTH_102];
    #pragma HLS ARRAY_PARTITION variable=layer104_out complete dim=0
    nnet::relu<layer103_t, layer104_t, relu_config104>(layer103_out, layer104_out);

    layer105_t layer105_out[N_FILT_105*OUT_HEIGHT_105*OUT_WIDTH_105];
    #pragma HLS ARRAY_PARTITION variable=layer105_out complete dim=0
    nnet::conv_2d_large_cl<layer104_t, layer105_t, config105>(layer104_out, layer105_out, w105, b105);

    layer106_t layer106_out[N_FILT_105*OUT_HEIGHT_105*OUT_WIDTH_105];
    #pragma HLS ARRAY_PARTITION variable=layer106_out complete dim=0
    nnet::normalize<layer105_t, layer106_t, config106>(layer105_out, layer106_out, s106, b106);

    layer107_t layer107_out[N_FILT_105*OUT_HEIGHT_105*OUT_WIDTH_105];
    #pragma HLS ARRAY_PARTITION variable=layer107_out complete dim=0
    nnet::relu<layer106_t, layer107_t, relu_config107>(layer106_out, layer107_out);

    layer108_t layer108_out[N_FILT_108*OUT_HEIGHT_108*OUT_WIDTH_108];
    #pragma HLS ARRAY_PARTITION variable=layer108_out complete dim=0
    nnet::conv_2d_large_cl<layer107_t, layer108_t, config108>(layer107_out, layer108_out, w108, b108);

    layer109_t layer109_out[N_FILT_108*OUT_HEIGHT_108*OUT_WIDTH_108];
    #pragma HLS ARRAY_PARTITION variable=layer109_out complete dim=0
    nnet::normalize<layer108_t, layer109_t, config109>(layer108_out, layer109_out, s109, b109);

    layer110_t layer110_out[N_FILT_108*OUT_HEIGHT_108*OUT_WIDTH_108];
    #pragma HLS ARRAY_PARTITION variable=layer110_out complete dim=0
    nnet::add<layer109_t, layer101_t, layer110_t, config110>(layer109_out, layer101_out, layer110_out);

    layer111_t layer111_out[N_FILT_108*OUT_HEIGHT_108*OUT_WIDTH_108];
    #pragma HLS ARRAY_PARTITION variable=layer111_out complete dim=0
    nnet::relu<layer110_t, layer111_t, relu_config111>(layer110_out, layer111_out);

    layer112_t layer112_out[N_FILT_112*OUT_HEIGHT_112*OUT_WIDTH_112];
    #pragma HLS ARRAY_PARTITION variable=layer112_out complete dim=0
    nnet::conv_2d_large_cl<layer111_t, layer112_t, config112>(layer111_out, layer112_out, w112, b112);

    layer113_t layer113_out[N_FILT_112*OUT_HEIGHT_112*OUT_WIDTH_112];
    #pragma HLS ARRAY_PARTITION variable=layer113_out complete dim=0
    nnet::normalize<layer112_t, layer113_t, config113>(layer112_out, layer113_out, s113, b113);

    layer114_t layer114_out[N_FILT_112*OUT_HEIGHT_112*OUT_WIDTH_112];
    #pragma HLS ARRAY_PARTITION variable=layer114_out complete dim=0
    nnet::relu<layer113_t, layer114_t, relu_config114>(layer113_out, layer114_out);

    layer115_t layer115_out[N_FILT_115*OUT_HEIGHT_115*OUT_WIDTH_115];
    #pragma HLS ARRAY_PARTITION variable=layer115_out complete dim=0
    nnet::conv_2d_large_cl<layer114_t, layer115_t, config115>(layer114_out, layer115_out, w115, b115);

    layer116_t layer116_out[N_FILT_115*OUT_HEIGHT_115*OUT_WIDTH_115];
    #pragma HLS ARRAY_PARTITION variable=layer116_out complete dim=0
    nnet::normalize<layer115_t, layer116_t, config116>(layer115_out, layer116_out, s116, b116);

    layer117_t layer117_out[N_FILT_115*OUT_HEIGHT_115*OUT_WIDTH_115];
    #pragma HLS ARRAY_PARTITION variable=layer117_out complete dim=0
    nnet::relu<layer116_t, layer117_t, relu_config117>(layer116_out, layer117_out);

    layer118_t layer118_out[N_FILT_118*OUT_HEIGHT_118*OUT_WIDTH_118];
    #pragma HLS ARRAY_PARTITION variable=layer118_out complete dim=0
    nnet::conv_2d_large_cl<layer117_t, layer118_t, config118>(layer117_out, layer118_out, w118, b118);

    layer119_t layer119_out[N_FILT_118*OUT_HEIGHT_118*OUT_WIDTH_118];
    #pragma HLS ARRAY_PARTITION variable=layer119_out complete dim=0
    nnet::normalize<layer118_t, layer119_t, config119>(layer118_out, layer119_out, s119, b119);

    layer120_t layer120_out[N_FILT_118*OUT_HEIGHT_118*OUT_WIDTH_118];
    #pragma HLS ARRAY_PARTITION variable=layer120_out complete dim=0
    nnet::add<layer119_t, layer111_t, layer120_t, config120>(layer119_out, layer111_out, layer120_out);

    layer121_t layer121_out[N_FILT_118*OUT_HEIGHT_118*OUT_WIDTH_118];
    #pragma HLS ARRAY_PARTITION variable=layer121_out complete dim=0
    nnet::relu<layer120_t, layer121_t, relu_config121>(layer120_out, layer121_out);

    layer122_t layer122_out[N_FILT_122*OUT_HEIGHT_122*OUT_WIDTH_122];
    #pragma HLS ARRAY_PARTITION variable=layer122_out complete dim=0
    nnet::conv_2d_large_cl<layer121_t, layer122_t, config122>(layer121_out, layer122_out, w122, b122);

    layer123_t layer123_out[N_FILT_122*OUT_HEIGHT_122*OUT_WIDTH_122];
    #pragma HLS ARRAY_PARTITION variable=layer123_out complete dim=0
    nnet::normalize<layer122_t, layer123_t, config123>(layer122_out, layer123_out, s123, b123);

    layer124_t layer124_out[N_FILT_122*OUT_HEIGHT_122*OUT_WIDTH_122];
    #pragma HLS ARRAY_PARTITION variable=layer124_out complete dim=0
    nnet::relu<layer123_t, layer124_t, relu_config124>(layer123_out, layer124_out);

    layer125_t layer125_out[N_FILT_125*OUT_HEIGHT_125*OUT_WIDTH_125];
    #pragma HLS ARRAY_PARTITION variable=layer125_out complete dim=0
    nnet::conv_2d_large_cl<layer124_t, layer125_t, config125>(layer124_out, layer125_out, w125, b125);

    layer126_t layer126_out[N_FILT_125*OUT_HEIGHT_125*OUT_WIDTH_125];
    #pragma HLS ARRAY_PARTITION variable=layer126_out complete dim=0
    nnet::normalize<layer125_t, layer126_t, config126>(layer125_out, layer126_out, s126, b126);

    layer127_t layer127_out[N_FILT_125*OUT_HEIGHT_125*OUT_WIDTH_125];
    #pragma HLS ARRAY_PARTITION variable=layer127_out complete dim=0
    nnet::relu<layer126_t, layer127_t, relu_config127>(layer126_out, layer127_out);

    layer128_t layer128_out[N_FILT_128*OUT_HEIGHT_128*OUT_WIDTH_128];
    #pragma HLS ARRAY_PARTITION variable=layer128_out complete dim=0
    nnet::conv_2d_large_cl<layer127_t, layer128_t, config128>(layer127_out, layer128_out, w128, b128);

    layer129_t layer129_out[N_FILT_128*OUT_HEIGHT_128*OUT_WIDTH_128];
    #pragma HLS ARRAY_PARTITION variable=layer129_out complete dim=0
    nnet::normalize<layer128_t, layer129_t, config129>(layer128_out, layer129_out, s129, b129);

    layer130_t layer130_out[N_FILT_128*OUT_HEIGHT_128*OUT_WIDTH_128];
    #pragma HLS ARRAY_PARTITION variable=layer130_out complete dim=0
    nnet::add<layer129_t, layer121_t, layer130_t, config130>(layer129_out, layer121_out, layer130_out);

    layer131_t layer131_out[N_FILT_128*OUT_HEIGHT_128*OUT_WIDTH_128];
    #pragma HLS ARRAY_PARTITION variable=layer131_out complete dim=0
    nnet::relu<layer130_t, layer131_t, relu_config131>(layer130_out, layer131_out);

    layer132_t layer132_out[N_FILT_132*OUT_HEIGHT_132*OUT_WIDTH_132];
    #pragma HLS ARRAY_PARTITION variable=layer132_out complete dim=0
    nnet::conv_2d_large_cl<layer131_t, layer132_t, config132>(layer131_out, layer132_out, w132, b132);

    layer133_t layer133_out[N_FILT_132*OUT_HEIGHT_132*OUT_WIDTH_132];
    #pragma HLS ARRAY_PARTITION variable=layer133_out complete dim=0
    nnet::normalize<layer132_t, layer133_t, config133>(layer132_out, layer133_out, s133, b133);

    layer134_t layer134_out[N_FILT_132*OUT_HEIGHT_132*OUT_WIDTH_132];
    #pragma HLS ARRAY_PARTITION variable=layer134_out complete dim=0
    nnet::relu<layer133_t, layer134_t, relu_config134>(layer133_out, layer134_out);

    layer135_t layer135_out[N_FILT_135*OUT_HEIGHT_135*OUT_WIDTH_135];
    #pragma HLS ARRAY_PARTITION variable=layer135_out complete dim=0
    nnet::conv_2d_large_cl<layer134_t, layer135_t, config135>(layer134_out, layer135_out, w135, b135);

    layer136_t layer136_out[N_FILT_135*OUT_HEIGHT_135*OUT_WIDTH_135];
    #pragma HLS ARRAY_PARTITION variable=layer136_out complete dim=0
    nnet::normalize<layer135_t, layer136_t, config136>(layer135_out, layer136_out, s136, b136);

    layer137_t layer137_out[N_FILT_135*OUT_HEIGHT_135*OUT_WIDTH_135];
    #pragma HLS ARRAY_PARTITION variable=layer137_out complete dim=0
    nnet::relu<layer136_t, layer137_t, relu_config137>(layer136_out, layer137_out);

    layer138_t layer138_out[N_FILT_138*OUT_HEIGHT_138*OUT_WIDTH_138];
    #pragma HLS ARRAY_PARTITION variable=layer138_out complete dim=0
    nnet::conv_2d_large_cl<layer137_t, layer138_t, config138>(layer137_out, layer138_out, w138, b138);

    layer139_t layer139_out[N_FILT_138*OUT_HEIGHT_138*OUT_WIDTH_138];
    #pragma HLS ARRAY_PARTITION variable=layer139_out complete dim=0
    nnet::normalize<layer138_t, layer139_t, config139>(layer138_out, layer139_out, s139, b139);

    layer140_t layer140_out[N_FILT_138*OUT_HEIGHT_138*OUT_WIDTH_138];
    #pragma HLS ARRAY_PARTITION variable=layer140_out complete dim=0
    nnet::add<layer139_t, layer131_t, layer140_t, config140>(layer139_out, layer131_out, layer140_out);

    layer141_t layer141_out[N_FILT_138*OUT_HEIGHT_138*OUT_WIDTH_138];
    #pragma HLS ARRAY_PARTITION variable=layer141_out complete dim=0
    nnet::relu<layer140_t, layer141_t, relu_config141>(layer140_out, layer141_out);

    layer142_t layer142_out[N_FILT_142*OUT_HEIGHT_142*OUT_WIDTH_142];
    #pragma HLS ARRAY_PARTITION variable=layer142_out complete dim=0
    nnet::conv_2d_large_cl<layer141_t, layer142_t, config142>(layer141_out, layer142_out, w142, b142);

    layer143_t layer143_out[N_FILT_142*OUT_HEIGHT_142*OUT_WIDTH_142];
    #pragma HLS ARRAY_PARTITION variable=layer143_out complete dim=0
    nnet::normalize<layer142_t, layer143_t, config143>(layer142_out, layer143_out, s143, b143);

    layer144_t layer144_out[N_FILT_142*OUT_HEIGHT_142*OUT_WIDTH_142];
    #pragma HLS ARRAY_PARTITION variable=layer144_out complete dim=0
    nnet::relu<layer143_t, layer144_t, relu_config144>(layer143_out, layer144_out);

    layer145_t layer145_out[N_FILT_145*OUT_HEIGHT_145*OUT_WIDTH_145];
    #pragma HLS ARRAY_PARTITION variable=layer145_out complete dim=0
    nnet::conv_2d_large_cl<layer144_t, layer145_t, config145>(layer144_out, layer145_out, w145, b145);

    layer146_t layer146_out[N_FILT_145*OUT_HEIGHT_145*OUT_WIDTH_145];
    #pragma HLS ARRAY_PARTITION variable=layer146_out complete dim=0
    nnet::normalize<layer145_t, layer146_t, config146>(layer145_out, layer146_out, s146, b146);

    layer147_t layer147_out[N_FILT_145*OUT_HEIGHT_145*OUT_WIDTH_145];
    #pragma HLS ARRAY_PARTITION variable=layer147_out complete dim=0
    nnet::relu<layer146_t, layer147_t, relu_config147>(layer146_out, layer147_out);

    layer148_t layer148_out[N_FILT_148*OUT_HEIGHT_148*OUT_WIDTH_148];
    #pragma HLS ARRAY_PARTITION variable=layer148_out complete dim=0
    nnet::conv_2d_large_cl<layer147_t, layer148_t, config148>(layer147_out, layer148_out, w148, b148);

    layer149_t layer149_out[N_FILT_148*OUT_HEIGHT_148*OUT_WIDTH_148];
    #pragma HLS ARRAY_PARTITION variable=layer149_out complete dim=0
    nnet::normalize<layer148_t, layer149_t, config149>(layer148_out, layer149_out, s149, b149);

    layer150_t layer150_out[N_FILT_150*OUT_HEIGHT_150*OUT_WIDTH_150];
    #pragma HLS ARRAY_PARTITION variable=layer150_out complete dim=0
    nnet::conv_2d_large_cl<layer141_t, layer150_t, config150>(layer141_out, layer150_out, w150, b150);

    layer151_t layer151_out[N_FILT_150*OUT_HEIGHT_150*OUT_WIDTH_150];
    #pragma HLS ARRAY_PARTITION variable=layer151_out complete dim=0
    nnet::normalize<layer150_t, layer151_t, config151>(layer150_out, layer151_out, s151, b151);

    layer152_t layer152_out[N_FILT_148*OUT_HEIGHT_148*OUT_WIDTH_148];
    #pragma HLS ARRAY_PARTITION variable=layer152_out complete dim=0
    nnet::add<layer149_t, layer151_t, layer152_t, config152>(layer149_out, layer151_out, layer152_out);

    layer153_t layer153_out[N_FILT_148*OUT_HEIGHT_148*OUT_WIDTH_148];
    #pragma HLS ARRAY_PARTITION variable=layer153_out complete dim=0
    nnet::relu<layer152_t, layer153_t, relu_config153>(layer152_out, layer153_out);

    layer154_t layer154_out[N_FILT_154*OUT_HEIGHT_154*OUT_WIDTH_154];
    #pragma HLS ARRAY_PARTITION variable=layer154_out complete dim=0
    nnet::conv_2d_large_cl<layer153_t, layer154_t, config154>(layer153_out, layer154_out, w154, b154);

    layer155_t layer155_out[N_FILT_154*OUT_HEIGHT_154*OUT_WIDTH_154];
    #pragma HLS ARRAY_PARTITION variable=layer155_out complete dim=0
    nnet::normalize<layer154_t, layer155_t, config155>(layer154_out, layer155_out, s155, b155);

    layer156_t layer156_out[N_FILT_154*OUT_HEIGHT_154*OUT_WIDTH_154];
    #pragma HLS ARRAY_PARTITION variable=layer156_out complete dim=0
    nnet::relu<layer155_t, layer156_t, relu_config156>(layer155_out, layer156_out);

    layer157_t layer157_out[N_FILT_157*OUT_HEIGHT_157*OUT_WIDTH_157];
    #pragma HLS ARRAY_PARTITION variable=layer157_out complete dim=0
    nnet::conv_2d_large_cl<layer156_t, layer157_t, config157>(layer156_out, layer157_out, w157, b157);

    layer158_t layer158_out[N_FILT_157*OUT_HEIGHT_157*OUT_WIDTH_157];
    #pragma HLS ARRAY_PARTITION variable=layer158_out complete dim=0
    nnet::normalize<layer157_t, layer158_t, config158>(layer157_out, layer158_out, s158, b158);

    layer159_t layer159_out[N_FILT_157*OUT_HEIGHT_157*OUT_WIDTH_157];
    #pragma HLS ARRAY_PARTITION variable=layer159_out complete dim=0
    nnet::relu<layer158_t, layer159_t, relu_config159>(layer158_out, layer159_out);

    layer160_t layer160_out[N_FILT_160*OUT_HEIGHT_160*OUT_WIDTH_160];
    #pragma HLS ARRAY_PARTITION variable=layer160_out complete dim=0
    nnet::conv_2d_large_cl<layer159_t, layer160_t, config160>(layer159_out, layer160_out, w160, b160);

    layer161_t layer161_out[N_FILT_160*OUT_HEIGHT_160*OUT_WIDTH_160];
    #pragma HLS ARRAY_PARTITION variable=layer161_out complete dim=0
    nnet::normalize<layer160_t, layer161_t, config161>(layer160_out, layer161_out, s161, b161);

    layer162_t layer162_out[N_FILT_160*OUT_HEIGHT_160*OUT_WIDTH_160];
    #pragma HLS ARRAY_PARTITION variable=layer162_out complete dim=0
    nnet::add<layer161_t, layer153_t, layer162_t, config162>(layer161_out, layer153_out, layer162_out);

    layer163_t layer163_out[N_FILT_160*OUT_HEIGHT_160*OUT_WIDTH_160];
    #pragma HLS ARRAY_PARTITION variable=layer163_out complete dim=0
    nnet::relu<layer162_t, layer163_t, relu_config163>(layer162_out, layer163_out);

    layer164_t layer164_out[N_FILT_164*OUT_HEIGHT_164*OUT_WIDTH_164];
    #pragma HLS ARRAY_PARTITION variable=layer164_out complete dim=0
    nnet::conv_2d_large_cl<layer163_t, layer164_t, config164>(layer163_out, layer164_out, w164, b164);

    layer165_t layer165_out[N_FILT_164*OUT_HEIGHT_164*OUT_WIDTH_164];
    #pragma HLS ARRAY_PARTITION variable=layer165_out complete dim=0
    nnet::normalize<layer164_t, layer165_t, config165>(layer164_out, layer165_out, s165, b165);

    layer166_t layer166_out[N_FILT_164*OUT_HEIGHT_164*OUT_WIDTH_164];
    #pragma HLS ARRAY_PARTITION variable=layer166_out complete dim=0
    nnet::relu<layer165_t, layer166_t, relu_config166>(layer165_out, layer166_out);

    layer167_t layer167_out[N_FILT_167*OUT_HEIGHT_167*OUT_WIDTH_167];
    #pragma HLS ARRAY_PARTITION variable=layer167_out complete dim=0
    nnet::conv_2d_large_cl<layer166_t, layer167_t, config167>(layer166_out, layer167_out, w167, b167);

    layer168_t layer168_out[N_FILT_167*OUT_HEIGHT_167*OUT_WIDTH_167];
    #pragma HLS ARRAY_PARTITION variable=layer168_out complete dim=0
    nnet::normalize<layer167_t, layer168_t, config168>(layer167_out, layer168_out, s168, b168);

    layer169_t layer169_out[N_FILT_167*OUT_HEIGHT_167*OUT_WIDTH_167];
    #pragma HLS ARRAY_PARTITION variable=layer169_out complete dim=0
    nnet::relu<layer168_t, layer169_t, relu_config169>(layer168_out, layer169_out);

    layer170_t layer170_out[N_FILT_170*OUT_HEIGHT_170*OUT_WIDTH_170];
    #pragma HLS ARRAY_PARTITION variable=layer170_out complete dim=0
    nnet::conv_2d_large_cl<layer169_t, layer170_t, config170>(layer169_out, layer170_out, w170, b170);

    layer171_t layer171_out[N_FILT_170*OUT_HEIGHT_170*OUT_WIDTH_170];
    #pragma HLS ARRAY_PARTITION variable=layer171_out complete dim=0
    nnet::normalize<layer170_t, layer171_t, config171>(layer170_out, layer171_out, s171, b171);

    layer172_t layer172_out[N_FILT_170*OUT_HEIGHT_170*OUT_WIDTH_170];
    #pragma HLS ARRAY_PARTITION variable=layer172_out complete dim=0
    nnet::add<layer171_t, layer163_t, layer172_t, config172>(layer171_out, layer163_out, layer172_out);

    layer173_t layer173_out[N_FILT_170*OUT_HEIGHT_170*OUT_WIDTH_170];
    #pragma HLS ARRAY_PARTITION variable=layer173_out complete dim=0
    nnet::relu<layer172_t, layer173_t, relu_config173>(layer172_out, layer173_out);

    layer174_t layer174_out[OUT_HEIGHT_174*OUT_WIDTH_174*N_FILT_174];
    #pragma HLS ARRAY_PARTITION variable=layer174_out complete dim=0
    nnet::pooling2d_cl<layer173_t, config174>(layer173_out, layer174_out);

    layer175_t layer175_out[N_LAYER_175];
    #pragma HLS ARRAY_PARTITION variable=layer175_out complete dim=0
    nnet::dense_large<layer174_t, layer175_t, config175>(layer174_out, layer175_out, w175, b175);

    nnet::softmax<layer175_t, result_t, softmax_config176>(layer175_out, layer176_out);

}
