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
#include "weights/b44.h"

void myproject_layer(
	       hls::stream<input_t>  layer_in [N_IN],
	       hls::stream<result_t> layer_out[N_OUT],
	       model_default_t w44[589824]
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS interface bram port=w44
    #pragma HLS INTERFACE axis port=layer_in,layer_out 
    #pragma HLS DATAFLOW 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        //nnet::load_weights_from_txt<model_default_t, 2359296>(w167, "w167.txt");
	//nnet::load_weights_from_txt<bias167_t, 512>(b167, "b167.txt");
        //nnet::load_weights_from_txt<model_default_t, 4704>(w2, "w2.txt");
        //nnet::load_weights_from_txt<bias2_t, 64>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_weightdefault_t, 256>(b44, "b44.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    if(!layer_in[0].empty()) nnet::dense_large_stream<layer43_t, layer44_t, config44>(layer_in, layer_out, w44, b44);
}
