//
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

#include "myproject_1stbit_simple.h"

//hls-fpga-machine-learning insert weights

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

void subimage(
      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
      hls::stream<result_t> output[N_FILT_12]) { 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
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
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************
    layer6_t layer6_in_row[N_INPUT_1_1][N_FILT_HEIGHT_6][N_INPUT_3_1];
    #pragma HLS ARRAY_RESHAPE variable=layer6_in_row complete dim=2

    layer6_t layer6_in[N_FILT_HEIGHT_6*N_FILT_WIDTH_6*N_FILT_5];
    #pragma HLS ARRAY_RESHAPE variable=layer6_in complete dim=0

    layer6_t layer6_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer6_out complete dim=0

    layer7_t layer7_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer7_out complete dim=0

    layer8_t layer8_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer8_out complete dim=0

    layer9_t layer9_in_row[OUT_WIDTH_6][N_FILT_HEIGHT_9][N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer9_in_row complete dim=2

    layer9_t layer9_in[N_FILT_HEIGHT_9*N_FILT_WIDTH_9*N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer9_in complete dim=0

    layer9_t layer9_out[N_FILT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0

    layer10_t layer10_out[N_FILT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer10_out complete dim=0

    layer11_t layer11_out[N_FILT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer11_out complete dim=0

    layer12_t layer12_in[N_FILT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer12_in complete dim=0

    layer12_t layer12_in_row[OUT_WIDTH_9][N_FILT_HEIGHT_12][N_FILT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer12_in_row complete dim=2

    layer12_t layer12_out[N_FILT_12];
    #pragma HLS ARRAY_RESHAPE variable=layer12_out complete dim=0

    layer12_t layer13_out[N_FILT_13];
    #pragma HLS ARRAY_RESHAPE variable=layer13_out complete dim=0

    unsigned pY = 0; 
    for(unsigned i0 = 0; i0 < N_INPUT_2_1; i0++) { 
      //Processs image
      Loop1:
      for(unsigned i1 = 0; i1 < N_INPUT_1_1; i1++) { 
        #pragma HLS PIPELINE II=1
	for(unsigned i2 = 0; i2 < N_INPUT_3_1;   i2++) { 
	 layer6_in_row[i1][0][i2] =  input[i1][i0][i2];
	}
       }
      //Clear convs
      nnet::reset_down_2dXNew<layer6_t,layer6_t,config6>(i0,layer6_in_row,layer6_in);
      nnet::reset_down_2dXNew<layer9_t,layer9_t,config9>(i0,layer9_in_row,layer9_in);
      nnet::reset_down_2dXNew<layer12_t,layer12_t,config12>(i0,layer12_in_row,layer12_in);
      Loop2:
      unsigned pX = 0; 
      for(unsigned i1 = 0; i1 < N_INPUT_1_1; i1++) { 
	nnet::dense_large<layer6_t,layer6_t,config6::mult_config>(layer6_in,layer6_out,w6,b6);
       	nnet::normalize2<layer6_t, layer7_t, config7>(layer6_out, layer7_out, s7, b7);
	nnet::relu<layer7_t, layer8_t, relu_config8>(layer7_out, layer8_out);
	nnet::fill_entry_2d<layer8_t,layer9_t,config9>(i1,layer8_out,layer9_in_row);
	nnet::dense_large<layer9_t,layer9_t,config9::mult_config>(layer9_in,layer9_out,w9,b9);
	nnet::normalize2<layer9_t, layer10_t, config10>(layer9_out, layer10_out, s10, b10);
	nnet::relu<layer10_t, layer11_t, relu_config11>(layer10_out, layer11_out);
	nnet::fill_entry_2d<layer12_t,layer12_t,config12>(i1+config9::pad_left,layer11_out,layer12_in_row);//note padding has to keep moving right to reflect above layers
	nnet::dense_large<layer12_t,layer12_t,config12::mult_config>(layer12_in,layer12_out,w12,b12);
	//nnet::normalize2<layer12_t, layer13_t, config13>(layer12_out, layer13_out, s13, b13);	
	if(i0 % 2 == 0 && i1 % 2 == 0 && i0 > (config9::filt_height-1) ) {
          nnet::fill_image_2dS1<layer12_t,result_t,config12>(layer12_out,output);
	} 
	pX = pX+1;
	nnet::shift_right_2dNew<layer6_t,layer6_t,config6>(i0,i1,layer6_in_row,layer6_in);//add padding
	nnet::shift_right_2dNew<layer9_t,layer9_t,config9>(i0,i1,layer9_in_row,layer9_in);//add padding
	nnet::shift_right_2dNew<layer12_t, layer12_t, config12>(i0,i1,layer12_in_row,layer12_in);
      }
      pY = pY+1;
    }
}


