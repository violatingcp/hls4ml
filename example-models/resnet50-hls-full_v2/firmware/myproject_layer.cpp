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

#include "myproject_layer.h"

//hls-fpga-machine-learning insert weights
//#include "weights/w167.h"
//#include "weights/b167.h"
#include "weights/w2.h"
#include "weights/b2.h"

void myproject_layer(
	       hls::stream<input_t>  gpu_0_data_0[N_INPUT_1_1],
	       hls::stream<result_t> layer4_out[N_FILT_2]
	       //model_default_t w2[9408]
	       //unsigned short &const_size_in_1,
	       //unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=gpu_0_data_0,layer4_out 
    #pragma HLS DATAFLOW 
  //#pragma HLS interface bram port=w2

  //const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
  //const_size_out_1 = N_LAYER_175;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        //nnet::load_weights_from_txt<model_default_t, 2359296>(w167, "w167.txt");
	//nnet::load_weights_from_txt<bias167_t, 512>(b167, "b167.txt");
        nnet::load_weights_from_txt<model_default_t, 4704>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 64>(b2, "b2.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    if(!gpu_0_data_0[0].empty()) nnet::conv_2d_large_cl<input_t, result_t, config2>(gpu_0_data_0, layer4_out, w2, b2);
}
