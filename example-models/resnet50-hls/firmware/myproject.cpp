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

#include "myproject.h"

//hls-fpga-machine-learning insert weights

#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/s3.h"
#include "weights/b3.h"

void myproject(
    input_t gpu_0_data_0[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer176_out[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=gpu_0_data_0 block factor=224 dim=0 
    #pragma HLS ARRAY_RESHAPE variable=layer176_out complete dim=3 
    #pragma HLS INTERFACE ap_vld port=gpu_0_data_0,layer176_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1;//N_INPUT_3_1;
    const_size_out_1 = N_LAYER_OUT_1;//*N_LAYER_OUT_2*N_LAYER_OUT_3;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 9408>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 56>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b3, "b3.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************
    layer2_t layer2_in_row[N_INPUT_2_1][N_FILT_HEIGHT_2][N_INPUT_1_1];
    #pragma HLS ARRAY_RESHAPE variable=layer2_out_row complete dim=2

    layer2_t layer2_in[N_FILT_HEIGHT_2*N_FILT_WIDTH_2*N_INPUT_1_1];
    #pragma HLS ARRAY_RESHAPE variable=layer2_in complete dim=0

    layer2_t layer2_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer2_out complete dim=0

    layer3_t layer3_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer3_out complete dim=0

    layer4_t layer4_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer4_out complete dim=0

    layer5_t layer5_in_row[N_OUT_WIDTH_2][N_FILT_HEIGHT_5][N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer5_in_row complete dim=2

    layer5_t layer5_in[N_FILT_HEIGHT_5*N_FILT_WIDTH_5*N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer5_in complete dim=0

    layer5_t layer5_out[N_FILT_5];
    #pragma HLS ARRAY_RESHAPE variable=layer5_out complete dim=0

    for(unsigned i0 = 0; i0 < N_INPUT_2_1_C; i0++) { 
      //Processs image
      Loop1:
      for(unsigned i1  = 0; i1 < N_INPUT_3_1_C; i1++) { 
       #pragma HLS PIPELINE II=1
       for(unsigned i2 = 0; i2 < N_INPUT_1_1;   i2++) { 
         layer2_in_row[2*i0][2*i1][i2]         =  gpu_0_data_0[2*i0*N_INPUT_3_1*N_INPUT_1_1+2*i1*N_INPUT_1_1+i2];
       }
       for(unsigned i2 = 0; i2 < N_INPUT_1_1;   i2++) { 
        layer2_in_row[2*i0+1][2*i1+1][i2]     =  gpu_0_data_0[2*(i0+1)*N_INPUT_3_1*N_INPUT_1_1+(2*i1+1)*N_INPUT_1_1+i2];
       }
      }
      //Clear convs
      nnet::reset_down_2dX<layer2_t,layer2_t,config2>(layer2_in_row,layer2_in);
      nnet::reset_down_2dX<layer5_t,layer5_t,config5>(layer5_in_row,layer5_in);
      Loop2:
      for(unsigned i1 = 0; i1 < N_INPUT_3_1_C; i1++) { 
	//nnet::conv_2d_large_cl<input_t, layer2_t, config2>(gpu_0_data_0, layer2_out, w2, b2);
        nnet::shift_right_stride_2d<layer2_t,layer2_t,config2>(i1,layer2_in_row,layer2_in);
	nnet::dense_large<layer2_t,layer2_t,config2::mult_config>(layer2_in,layer2_out,w2,b2);
	nnet::normalize<layer2_t, layer3_t, config3>(layer2_out, layer3_out, s3, b3);
	nnet::relu<layer3_t, layer4_t, relu_config4>(layer3_out, layer4_out);
	nnet::fill_entry_2d<layer4_t,layer5_t,config5>(i1,layer4_out,layer5_in_row);
	nnet::shift_right_stride_2d<layer5_t,layer5_t,config5>(i1,layer5_in_row,layer5_in);
	nnet::maxpool2d_filt_cl<layer5_t, config5>(layer5_in, layer5_out);
	nnet::fill_image_2d<layer5_t,result_t,config5>(i0,i1,layer5_out,layer176_out);
      }
      //Shiftdowns
      nnet::shift_down_small_stride_2d<layer2_t,config2>(layer2_in_row);
      nnet::shift_down_small_stride_2d<layer5_t,config5>(layer5_in_row);
    }
}
