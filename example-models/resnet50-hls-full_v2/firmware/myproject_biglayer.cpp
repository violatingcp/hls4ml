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

#include "myproject_biglayer.h"

//hls-fpga-machine-learning insert weights
//#include "weights/w167.h"
#include "weights/b118.h"

void myproject_biglayer(
	       hls::stream<input_t>  gpu_0_data_0[N_FILT_115],
	       hls::stream<result_t> layer4_out[N_FILT_118],
	       model_default_t w118[131072]
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=gpu_0_data_0,layer4_out 
    #pragma HLS DATAFLOW 
    #pragma HLS interface bram port=w118

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        nnet::load_weights_from_txt<model_default_t, 131072>(w118, "w118.txt");
        nnet::load_weights_from_txt<bias118_t, 1024>(b118, "b118.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    //if(!gpu_0_data_0[0].empty()) nnet::conv_2d_large_cl<input_t, result_t, config167>(gpu_0_data_0, layer4_out, w167, b167);
    //for(int i0 = 0; i0 < 49; i0++) { 
    // if(!gpu_0_data_0[0].empty()) nnet::conv_2d_large_cl<input_t, result_t, config167>(gpu_0_data_0, layer4_out, w167, b167);
    //}
    if(!gpu_0_data_0[0].empty()) nnet::conv_2d_large_cl_1x1<layer117_t, layer119_t, config118>(gpu_0_data_0, layer4_out, w118, b118);
}
