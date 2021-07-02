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
#include "weights/w4.h"
#include "weights/b4.h"
//#include "weights/w7.h"
//#include "weights/b7.h"
//#include "weights/w9.h"
//#include "weights/b9.h"

void myproject(
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
        nnet::load_weights_from_txt<model_default_t, 288>(w2, "w2.txt");
	nnet::load_weights_from_txt<model_default_t, 32>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 18432>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b4, "b4.txt");
        //nnet::load_weights_from_txt<model_default_t, 1179648>(w7, "w7.txt");
        //nnet::load_weights_from_txt<model_default_t, 128>(b7, "b7.txt");
        //nnet::load_weights_from_txt<model_default_t, 1280>(w9, "w9.txt");
        //nnet::load_weights_from_txt<model_default_t, 10>(b9, "b9.txt");
        loaded_weights = true;
	}
#endif

    input_t input_stream1[config2::filt_width*config2::filt_height * config2::n_chan];      
    #pragma HLS ARRAY_RESHAPE variable=input_stream1 complete dim=0
    for(int i0 = 0; i0 < config2::filt_width*config2::filt_height * config2::n_chan; i0++) { 
     #pragma HLS UNROLL
     input_stream1[i0] = 0;
    }

    input_t input_stream2[config4::filt_width*config4::filt_height * config4::n_chan];      
    #pragma HLS ARRAY_RESHAPE variable=input_stream2 complete dim=0
    for(int i0 = 0; i0 < config4::filt_width*config4::filt_height * config4::n_chan; i0++) { 
     #pragma HLS UNROLL
     input_stream2[i0] = 0;
    }

    input_t input_rows[config2::filt_height*config2::out_width * config2::n_chan];      
    #pragma HLS ARRAY_RESHAPE variable=input_rows complete dim=0

    layer2_t layer2_out[config2::n_filt];      
    #pragma HLS ARRAY_RESHAPE variable=layer2_out complete dim=0

    layer3_t layer3_out[config4::n_chan];      
    #pragma HLS ARRAY_RESHAPE variable=layer3_out complete dim=0

    layer3_t layer3_out_row[config4::filt_height*config4::out_width * config4::n_chan];      
    #pragma HLS ARRAY_RESHAPE variable=layer3_out_row complete dim=0
    //#pragma HLS ARRAY_RESHAPE variable=layer3_out_row block factor=9
    //config2::out_width * config2::n_filt

    layer4_t layer4_out[config4::n_filt];      
    #pragma HLS ARRAY_RESHAPE variable=layer4_out complete dim=0

    //layer5_t layer5_out[config4::n_filt];      
    //#pragma HLS ARRAY_RESHAPE variable=layer5_out complete dim=0

    layer9_t layer9_out[N_LAYER_9];
    #pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0
    
    for(unsigned i0 = 0; i0 < config2::out_height; i0++) {//Note to self: Loop needs to extended for padding and layer iterations (at min out_height1+filt2+filt3+....)
     for(int i1 = 0; i1 < config2::out_width; i1++) { 
      #pragma HLS UNROLL
      for(int i2 = 0; i2 < config2::n_chan; i2++) { 
       input_rows[i1*config2::n_chan*config2::filt_height+i2*config2::filt_height] = input1[i0*N_INPUT_2_1*N_INPUT_3_1+i1*N_INPUT_3_1+i2];
      }
     }
     nnet::reset_down<input_t,layer2_t,config2>(input_stream1,input_rows);
     nnet::reset_down<input_t,layer3_t,config4>(input_stream2,layer3_out_row);
     for(unsigned i1 = 0; i1 < config2::out_width; i1++) {//See above note
       //input_t tmpinput[config2::filt_height * config2::n_chan];
       //     for(unsigned i2 = 0; i2 < config2::n_chan; i2++) {
       //    for(unsigned i3 = 0; i3 < config2::filt_height; i3++) {
       //  tmpinput[i1*config2::n_chan+i0] = input_rows[i1*config2::filt_height * config2::n_chan+i0*config2::filt_height+i1];
	 // }
	//}
       //nnet::shift_right_small<input_t,input_t,config2>(tmpinput,input_stream1);
       nnet::shift_right<input_t,input_t,config2>(i1,input_rows,input_stream1);
       nnet::dense_large<input_t,layer2_t,config2::mult_config>(input_stream1,layer2_out,w2,b2);
       nnet::relu<layer2_t, layer3_t, relu_config3>(layer2_out, layer3_out);
       //nnet::fill_entryp<layer3_t,layer3_t,config4>(layer3_out,layer3_out_row);//[i1*config4::filt_height*config4::n_chan]);
       //nnet::fill_entry<layer3_t,layer3_t,config4>(i1,layer3_out,layer3_out_row);
       //Above line blows up resources
       for(unsigned i2 = 0; i2 < config4::n_chan; i2++) {
        #pragma HLS UNROLL
        layer3_out_row[i1*config4::filt_height*config4::n_chan+i2*config4::filt_height] = layer3_out[i2];
       }
       nnet::shift_right<layer3_t,layer3_t,config4>(i1,input_stream2,layer3_out_row);
       nnet::dense_large<layer3_t, layer4_t, config4::mult_config>(input_stream2, layer4_out, w4, b4);
       //nnet::relu<layer4_t, layer5_t, relu_config5>(layer4_out, layer5_out);
       for(int i2 = 0; i2 < N_LAYER_9; i2++) { 
         layer9_out[i2] = layer4_out[i2];
       }
      }
     //clear vertical
     nnet::shift_down_small<input_t,config2>(input_rows);
     nnet::shift_down_small<input_t,config4>(layer3_out_row);
    }
    /*
       //for(unsigned i2 = 0; i2 < config4::n_chan; i2++) {
       //	std::cout << "--> " << layer2_out[i2] << " -- " << layer3_out_row[i1*config4::filt_height*config4::n_chan+i2*config4::filt_height] << " -- " << layer3_out[i2] << std::endl;
       //} 
    std::cout << "c2" << std::endl;
    std::cout << "r2" << std::endl;
    layer6_t layer6_out[OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer6_out block factor=144
    nnet::pooling2d_cl<layer5_t, config6>(layer5_out, layer6_out);
    std::cout << "p1" << std::endl;
    //layer7_t layer7_out[N_LAYER_7];
    //#pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0
    //nnet::dense_large<layer6_t, layer7_t, config7>(layer6_out, layer7_out, w7, b7);
    //std::cout << "d1" << std::endl;
    layer8_t layer8_out[N_LAYER_7];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0
    nnet::relu<layer7_t, layer8_t, relu_config8>(layer7_out, layer8_out);
    std::cout << "d2" << std::endl;
    layer9_t layer9_out[N_LAYER_9];
    #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0
    nnet::dense_large<layer8_t, layer9_t, config9>(layer8_out, layer9_out, w9, b9);
    std::cout << "d3" << std::endl;
    */
    nnet::relu<layer9_t, result_t, softmax_config10>(layer9_out, layer10_out);
    //nnet::softmax<layer9_t, result_t, softmax_config10>(layer9_out, layer10_out);
}
