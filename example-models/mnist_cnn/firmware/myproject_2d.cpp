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

#include "myproject_2d.h"

//hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w7.h"
#include "weights/b7.h"
#include "weights/w9.h"
#include "weights/b9.h"

void myproject_2d(
    input_t input1[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer10_out[N_LAYER_9],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=input1 complete dim=0 
    #pragma HLS ARRAY_RESHAPE variable=layer10_out complete dim=0 
    #pragma HLS INTERFACE ap_vld port=input1,layer10_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1;
    const_size_out_1 = N_LAYER_9;

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 288>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 18432>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b4, "b4.txt");
        nnet::load_weights_from_txt<model_default_t, 1179648>(w7, "w7.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b7, "b7.txt");
        nnet::load_weights_from_txt<model_default_t, 1280>(w9, "w9.txt");
        nnet::load_weights_from_txt<model_default_t, 10>(b9, "b9.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    layer2_t layer2_in_row[N_INPUT_1_1][N_FILT_HEIGHT_2][N_INPUT_3_1];
    #pragma HLS ARRAY_RESHAPE variable=layer2_out_row complete dim=3
    
    layer2_t layer2_in[N_FILT_HEIGHT_2*N_FILT_WIDTH_2*N_INPUT_3_1];
    #pragma HLS ARRAY_RESHAPE variable=layer2_in complete 

    layer2_t layer2_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer2_out complete dim=0
    
    layer3_t layer3_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer3_out complete dim=0
    
    //Layer 4 CNN input subImage x row
    layer4_t layer4_in_row[OUT_WIDTH_2][N_FILT_HEIGHT_4][N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer4_in_row complete dim=3
    
    //Layer 4 Input array to the dense layer
    layer4_t layer4_in[N_FILT_HEIGHT_4*N_FILT_WIDTH_4*N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer4_in complete 

    //Layer 4 Output array from the dense layer
    layer4_t layer4_out[N_FILT_4];
    #pragma HLS ARRAY_RESHAPE variable=layer4_out complete dim=0
    
    //Usual Relu 
    layer5_t layer5_out[N_FILT_4];
    #pragma HLS ARRAY_RESHAPE variable=layer5_out complete dim=0

    //Input layer into pool
    layer6_t layer6_in_row[OUT_WIDTH_4][N_FILT_HEIGHT_6][N_FILT_4];
    #pragma HLS ARRAY_RESHAPE variable=layer6_in_row complete dim=3

    //Input layer into dense layer
    layer6_t layer6_in[N_FILT_HEIGHT_6*N_FILT_WIDTH_6*N_FILT_4];
    #pragma HLS ARRAY_RESHAPE variable=layer6_in complete 

    //Layer 6 Output array from the dense layer
    layer6_t layer6_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer6_out complete dim=0
    //Output Image to the CNN    
    layer7_t layer7_in[OUT_WIDTH_6][OUT_HEIGHT_6][N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer7_in complete dim=3

    ///////////// CNN core
    //Loop over vertically
    for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
      //Read in the input image to bottom row of buffer
      for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) {
       #pragma HLS PIPELINE II=1
       for(int i2 = 0; i2 < N_INPUT_3_1; i2++) {       
        layer2_in_row[i1][N_FILT_HEIGHT_2-1][i2] = input1[i0*N_INPUT_2_1*N_INPUT_3_1+i1*N_INPUT_3_1+i2];
       }
      }
      //Fill the dense layer input buffer with inputs one row lower
      nnet::reset_down_2dX<input_t,layer2_t,config2>(layer2_in_row,layer2_in);
      nnet::reset_down_2dX<input_t,layer4_t,config4>(layer4_in_row,layer4_in);
      nnet::reset_down_2dX<input_t,layer6_t,config6>(layer6_in_row,layer6_in);
      //Loop over Horizontally
      for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
       //move the input buffer right one pixel (Perhaps this should go later)
       nnet::shift_right_2dX<input_t,input_t,config2>(i1,layer2_in_row,layer2_in);
       //finally do the matrix multiply of the first followed by relu
       nnet::dense_large<input_t,layer2_t,config2::mult_config>(layer2_in,layer2_out,w2,b2);
       nnet::relu<layer2_t, layer3_t, relu_config3>(layer2_out, layer3_out);
       //Now setup the next input buffer => FYI the below code uses to many HLS resources ask Phil for a crappy fix
       nnet::fill_entry_2d<layer3_t,layer4_t,config4>(i1,layer3_out,layer4_in_row);
       //move the input buffer right one pixel (Perhaps this should go later)
       nnet::shift_right_2dX<layer4_t,layer4_t,config4>(i1,layer4_in_row,layer4_in);
       nnet::dense_large<layer4_t,layer4_t,config4::mult_config>(layer4_in, layer4_out, w4, b4);
       nnet::relu<layer4_t, layer5_t, relu_config5>(layer4_out, layer5_out);
       //Setup the next layer => again see Phil for fix
       nnet::fill_entry_2d<layer5_t,layer6_t,config6>(i1,layer5_out,layer6_in_row);
       //Now same bit for pooling
       nnet::shift_right_2dX<layer4_t,layer4_t,config6>(i1,layer6_in_row,layer6_in);
       nnet::maxpool2d_filt_cl<layer6_t, config6>(layer6_in, layer6_out);
       //Finally we want to fill the giant output image vector => putting in stride in a hacky way
       if(i0 % config6::stride_height == 0 && i1 % config6::stride_width == 0 && i0 < config6::out_width && i1 < config6::out_height) nnet::fill_image_2d<layer6_t,result_t,config6>(i0,i1,layer6_out,layer7_in);
     }
     //Shift the whole row down by moving everything up and making it zeros
     nnet::shift_down_small_2d<layer2_t,config2>(layer2_in_row);
     nnet::shift_down_small_2d<layer4_t,config4>(layer4_in_row);
     nnet::shift_down_small_2d<layer6_t,config6>(layer6_in_row);
   }

   //Now fill a dummy output so we don't run the million by million dense multiply
   //layer9_t layer9_out[N_LAYER_9];
   //#pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0     
   //for(unsigned i0 = 0; i0 < N_LAYER_9; i0++) { 
   //  layer9_out[i0] = layer7_in[0][0][i0];
   //}

    ////// Below is the actual end to the network
    layer7_t layer7_full[OUT_WIDTH_6*OUT_HEIGHT_6*N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer7_full block factor=64

    unsigned index=0; 
    for(unsigned i0 = 0; i0 < OUT_WIDTH_6;   i0++) { 
     for(unsigned i1 = 0; i1 < OUT_HEIGHT_6; i1++) { 
      for(unsigned i2 = 0; i2 < N_FILT_6;    i2++) { 
       layer7_full[index] = layer7_in[i0][i1][i2];
       index++;
      }
     }
    }
    
    layer7_t layer7_out[N_LAYER_7];
    #pragma HLS ARRAY_RESHAPE variable=layer7_out complete dim=0
    nnet::dense_large<layer7_t, layer7_t, config7>(layer7_full, layer7_out, w7, b7);

    layer8_t layer8_out[N_LAYER_7];
    #pragma HLS ARRAY_RESHAPE variable=layer8_out complete dim=0
    nnet::relu<layer7_t, layer8_t, relu_config8>(layer7_out, layer8_out);

    layer9_t layer9_out[N_LAYER_9];
    #pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0
    nnet::dense_large<layer8_t, layer9_t, config9>(layer8_out, layer9_out, w9, b9);
    nnet::softmax<layer9_t, result_t, softmax_config10>(layer9_out, layer10_out);
}
