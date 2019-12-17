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
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/s7.h"
#include "weights/b7.h"
#include "weights/w9.h"
#include "weights/b9.h"
/*
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
*/


void myproject(
    input_t gpu_0_data_0[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer176_out[N_LAYER_175],
    unsigned short &const_size_in_1,
    unsigned short &const_size_out_1
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=gpu_0_data_0 block factor=224 dim=0 
    #pragma HLS ARRAY_RESHAPE variable=layer176_out complete dim=0 
    #pragma HLS INTERFACE ap_vld port=gpu_0_data_0,layer176_out 
    #pragma HLS DATAFLOW 

    const_size_in_1 = N_INPUT_1_1*N_INPUT_2_1;//N_INPUT_3_1;
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
        /*
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
	*/
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
    layer2_t layer2_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer2_out complete dim=0

    layer2_t layer2_in_row[N_INPUT_1_1*N_INPUT_2_1*N_FILT_HEIGHT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer2_out_row block factor=21 dim=0
    //#pragma HLS ARRAY_RESHAPE variable=layer2_out_row complete block factor=N_INPUT_1_1*N_FILT_HEIGHT_2 dim=0
    //for(unsigned i0 = 0; i0 < N_FILT_2*OUT_WIDTH_2*N_FILT_HEIGHT_2; i0++) { 
    //  layer2_in_row[i0] = 0;
    // }

    layer2_t layer2_in[N_FILT_HEIGHT_2*N_FILT_WIDTH_2*N_INPUT_1_1];
    #pragma HLS ARRAY_RESHAPE variable=layer2_in complete dim=0
    //nnet::zero<layer6_t,config6>(layer6_in);

    layer3_t layer3_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer3_out complete dim=0

    layer4_t layer4_out[N_FILT_2];
    #pragma HLS ARRAY_RESHAPE variable=layer4_out complete dim=0

    layer5_t layer5_out[N_FILT_5];
    #pragma HLS ARRAY_RESHAPE variable=layer5_out complete dim=0

    layer5_t layer5_in_row[OUT_WIDTH_5*N_FILT_5*N_POOL_HEIGHT_5];
    #pragma HLS ARRAY_RESHAPE variable=layer5_out block factor=64
    //#pragma HLS ARRAY_RESHAPE variable=layer5_out complete dim=0

    layer5_t layer5_in[N_POOL_HEIGHT_5*N_POOL_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_RESHAPE variable=layer5_in complete dim=0

    layer6_t layer6_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer6_out complete dim=0

    layer6_t layer6_in_row[N_FILT_6*N_FILT_HEIGHT_6*OUT_WIDTH_6];
    #pragma HLS ARRAY_RESHAPE variable=layer6_out_row block factor=64 dim=0
    //#pragma HLS ARRAY_RESHAPE variable=layer6_out_row complete dim=0

    layer6_t layer6_in[N_FILT_HEIGHT_6*N_FILT_WIDTH_6*N_FILT_5];
    #pragma HLS ARRAY_RESHAPE variable=layer6_in complete dim=0
    //nnet::zero<layer6_t,config6>(layer6_in);

    layer7_t layer7_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer7_out complete dim=0

    layer8_t layer8_out[N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer8_out complete dim=0

    layer9_t layer9_out[N_FILT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer9_out complete dim=0

    layer9_t layer9_in_row[N_FILT_9*OUT_HEIGHT_9*N_FILT_HEIGHT_9];
    #pragma HLS ARRAY_RESHAPE variable=layer9_out_row block factor=192 dim=0

    layer9_t layer9_in[N_FILT_HEIGHT_9*N_FILT_WIDTH_9*N_FILT_6];
    #pragma HLS ARRAY_RESHAPE variable=layer6_in complete dim=0
    
    for(unsigned i0 = 0; i0 < N_INPUT_2_1_C; i0++) { 
      //Processs image
      Loop1:
      for(unsigned i1  = 0; i1 < N_INPUT_3_1_C; i1++) { 
       #pragma HLS PIPELINE II=1
       for(unsigned i2 = 0; i2 < N_INPUT_1_1;   i2++) { 
         layer2_in_row[i1*config2::n_chan*config2::filt_height+i2*config2::filt_height] =  gpu_0_data_0[i0*N_INPUT_3_1*N_INPUT_1_1+i1*N_INPUT_1_1+i2];
       }
      }
      //Clear convs
      nnet::reset_down<input_t,layer2_t,config2>(layer2_in,layer2_in_row);
      nnet::reset_down<input_t,layer5_t,config5>(layer5_in,layer5_in_row);
      nnet::reset_down<input_t,layer6_t,config6>(layer6_in,layer6_in_row);
      //nnet::reset_down<input_t,layer9_t,config9>(layer9_in,layer9_in_row);
      Loop2:
      for(unsigned i1 = 0; i1 < N_INPUT_3_1_C; i1++) { 
	//nnet::conv_2d_large_cl<input_t, layer2_t, config2>(gpu_0_data_0, layer2_out, w2, b2);
	nnet::shift_right_stride<input_t,input_t,config2>(i1,layer2_in,layer2_in_row);
	nnet::dense_large<input_t,layer2_t,config2::mult_config>(layer2_in,layer2_out,w2,b2);
	nnet::normalize<layer2_t, layer3_t, config3>(layer2_out, layer3_out, s3, b3);
	nnet::relu<layer3_t, layer4_t, relu_config4>(layer3_out, layer4_out);
	//
	nnet::fill_entry<layer4_t,layer5_t,config2>(i1,layer4_out,layer5_in_row);
	nnet::shift_right_stride<layer5_t,layer5_t,config5>(i1,layer5_in,layer5_in_row);
	nnet::pooling2d_filt_cl<layer5_t, config5>(layer5_in, layer5_out);
	//nnet::conv_2d_large_cl<layer5_t, layer6_t, config6>(layer5_out, layer6_out, w6, b6);
	nnet::fill_entry<layer5_t,layer6_t,config5>(i1,layer5_out,layer6_in_row);
	nnet::shift_right_stride<layer6_t,layer5_t,config6>(i1,layer6_in,layer6_in_row);
	nnet::dense_large<layer6_t,layer6_t,config6::mult_config>(layer6_in,layer6_out,w6,b6);
       	nnet::normalize<layer6_t, layer7_t, config7>(layer6_out, layer7_out, s7, b7);
	nnet::relu<layer7_t, layer8_t, relu_config8>(layer7_out, layer8_out);
	//nnet::conv_2d_large_cl<layer8_t, layer9_t, config9>(layer8_out, layer9_out, w9, b9);
	nnet::fill_entry<layer9_t,layer9_t,config6>(i1,layer9_out,layer9_in_row);
	nnet::shift_right_stride<layer9_t,layer9_t,config9>(i1,layer9_in,layer9_in_row);
	nnet::dense_large<layer9_t,layer9_t,config9::mult_config>(layer9_in,layer9_out,w2,b2);
	//nnet::fill_image<layer9_t,result_t,config9>(i0,i1,layer9_out,layer176_out);
      }
      //Shiftdowns
      nnet::shift_down_small_stride<layer2_t,config2>(layer2_in_row);
      nnet::shift_down_small_stride<layer5_t,config5>(layer5_in_row);
      nnet::shift_down_small       <layer6_t,config6>(layer6_in_row);
      nnet::shift_down_small       <layer9_t,config9>(layer9_in_row);
      for(unsigned i1 = 0; i1 < 56; i1++) { 
       layer176_out[i0*56+i1] =  layer9_out[i1];
      }
    }
    /*
    layer10_t layer10_out[N_FILT_9*OUT_HEIGHT_9*OUT_WIDTH_9];
    #pragma HLS ARRAY_RESHAPE variable=layer10_out complete dim=0
    nnet::normalize<layer9_t, layer10_t, config10>(layer9_out, layer10_out, s10, b10);

    layer11_t layer11_out[N_FILT_9*OUT_HEIGHT_9*OUT_WIDTH_9];
    #pragma HLS ARRAY_RESHAPE variable=layer11_out complete dim=0
    nnet::relu<layer10_t, layer11_t, relu_config11>(layer10_out, layer11_out);

    layer12_t layer12_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_RESHAPE variable=layer12_out complete dim=0
    nnet::conv_2d_large_cl<layer11_t, layer12_t, config12>(layer11_out, layer12_out, w12, b12);

    layer13_t layer13_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_RESHAPE variable=layer13_out complete dim=0
    nnet::normalize<layer12_t, layer13_t, config13>(layer12_out, layer13_out, s13, b13);

    layer14_t layer14_out[N_FILT_14*OUT_HEIGHT_14*OUT_WIDTH_14];
    #pragma HLS ARRAY_RESHAPE variable=layer14_out complete dim=0
    nnet::conv_2d_large_cl<layer5_t, layer14_t, config14>(layer5_out, layer14_out, w14, b14);

    layer15_t layer15_out[N_FILT_14*OUT_HEIGHT_14*OUT_WIDTH_14];
    #pragma HLS ARRAY_RESHAPE variable=layer15_out complete dim=0
    nnet::normalize<layer14_t, layer15_t, config15>(layer14_out, layer15_out, s15, b15);

    layer16_t layer16_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_RESHAPE variable=layer16_out complete dim=0
    nnet::add<layer13_t, layer15_t, layer16_t, config16>(layer13_out, layer15_out, layer16_out);

    layer17_t layer17_out[N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12];
    #pragma HLS ARRAY_RESHAPE variable=layer17_out complete dim=0
    nnet::relu<layer16_t, layer17_t, relu_config17>(layer16_out, layer17_out);

    layer18_t layer18_out[N_FILT_18*OUT_HEIGHT_18*OUT_WIDTH_18];
    #pragma HLS ARRAY_RESHAPE variable=layer18_out complete dim=0
    nnet::conv_2d_large_cl<layer17_t, layer18_t, config18>(layer17_out, layer18_out, w18, b18);

    layer19_t layer19_out[N_FILT_18*OUT_HEIGHT_18*OUT_WIDTH_18];
    #pragma HLS ARRAY_RESHAPE variable=layer19_out complete dim=0
    nnet::normalize<layer18_t, layer19_t, config19>(layer18_out, layer19_out, s19, b19);

    layer20_t layer20_out[N_FILT_18*OUT_HEIGHT_18*OUT_WIDTH_18];
    #pragma HLS ARRAY_RESHAPE variable=layer20_out complete dim=0
    nnet::relu<layer19_t, layer20_t, relu_config20>(layer19_out, layer20_out);

    layer21_t layer21_out[N_FILT_21*OUT_HEIGHT_21*OUT_WIDTH_21];
    #pragma HLS ARRAY_RESHAPE variable=layer21_out complete dim=0
    nnet::conv_2d_large_cl<layer20_t, layer21_t, config21>(layer20_out, layer21_out, w21, b21);

    layer22_t layer22_out[N_FILT_21*OUT_HEIGHT_21*OUT_WIDTH_21];
    #pragma HLS ARRAY_RESHAPE variable=layer22_out complete dim=0
    nnet::normalize<layer21_t, layer22_t, config22>(layer21_out, layer22_out, s22, b22);

    layer23_t layer23_out[N_FILT_21*OUT_HEIGHT_21*OUT_WIDTH_21];
    #pragma HLS ARRAY_RESHAPE variable=layer23_out complete dim=0
    nnet::relu<layer22_t, layer23_t, relu_config23>(layer22_out, layer23_out);

    layer24_t layer24_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_RESHAPE variable=layer24_out complete dim=0
    nnet::conv_2d_large_cl<layer23_t, layer24_t, config24>(layer23_out, layer24_out, w24, b24);

    layer25_t layer25_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_RESHAPE variable=layer25_out complete dim=0
    nnet::normalize<layer24_t, layer25_t, config25>(layer24_out, layer25_out, s25, b25);

    layer26_t layer26_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_RESHAPE variable=layer26_out complete dim=0
    nnet::add<layer25_t, layer17_t, layer26_t, config26>(layer25_out, layer17_out, layer26_out);

    layer27_t layer27_out[N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24];
    #pragma HLS ARRAY_RESHAPE variable=layer27_out complete dim=0
    nnet::relu<layer26_t, layer27_t, relu_config27>(layer26_out, layer27_out);

    layer28_t layer28_out[N_FILT_28*OUT_HEIGHT_28*OUT_WIDTH_28];
    #pragma HLS ARRAY_RESHAPE variable=layer28_out complete dim=0
    nnet::conv_2d_large_cl<layer27_t, layer28_t, config28>(layer27_out, layer28_out, w28, b28);

    layer29_t layer29_out[N_FILT_28*OUT_HEIGHT_28*OUT_WIDTH_28];
    #pragma HLS ARRAY_RESHAPE variable=layer29_out complete dim=0
    nnet::normalize<layer28_t, layer29_t, config29>(layer28_out, layer29_out, s29, b29);

    layer30_t layer30_out[N_FILT_28*OUT_HEIGHT_28*OUT_WIDTH_28];
    #pragma HLS ARRAY_RESHAPE variable=layer30_out complete dim=0
    nnet::relu<layer29_t, layer30_t, relu_config30>(layer29_out, layer30_out);

    layer31_t layer31_out[N_FILT_31*OUT_HEIGHT_31*OUT_WIDTH_31];
    #pragma HLS ARRAY_RESHAPE variable=layer31_out complete dim=0
    nnet::conv_2d_large_cl<layer30_t, layer31_t, config31>(layer30_out, layer31_out, w31, b31);

    layer32_t layer32_out[N_FILT_31*OUT_HEIGHT_31*OUT_WIDTH_31];
    #pragma HLS ARRAY_RESHAPE variable=layer32_out complete dim=0
    nnet::normalize<layer31_t, layer32_t, config32>(layer31_out, layer32_out, s32, b32);

    layer33_t layer33_out[N_FILT_31*OUT_HEIGHT_31*OUT_WIDTH_31];
    #pragma HLS ARRAY_RESHAPE variable=layer33_out complete dim=0
    nnet::relu<layer32_t, layer33_t, relu_config33>(layer32_out, layer33_out);

    layer34_t layer34_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_RESHAPE variable=layer34_out complete dim=0
    nnet::conv_2d_large_cl<layer33_t, layer34_t, config34>(layer33_out, layer34_out, w34, b34);

    layer35_t layer35_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_RESHAPE variable=layer35_out complete dim=0
    nnet::normalize<layer34_t, layer35_t, config35>(layer34_out, layer35_out, s35, b35);

    layer36_t layer36_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_RESHAPE variable=layer36_out complete dim=0
    nnet::add<layer35_t, layer27_t, layer36_t, config36>(layer35_out, layer27_out, layer36_out);
    
    layer37_t layer37_out[N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34];
    #pragma HLS ARRAY_RESHAPE variable=layer37_out complete dim=0
    nnet::relu<layer36_t, layer37_t, relu_config37>(layer36_out, layer37_out);

    */
}
