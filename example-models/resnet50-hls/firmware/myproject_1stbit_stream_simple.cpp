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

#include "myproject_1stbit_stream_simple.h"

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

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]) { 

  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_14];
  #pragma HLS stream variable=sInput      depth=1
  #pragma HLS stream variable=sOutput     depth=1
  bool lReset = true;
  for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
    for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
      for(unsigned i2 = 0; i2 < N_INPUT_3_1; i2++) { 
          #pragma HLS UNROLL
	  sInput[i2].write(input[i0][i1][i2]);
      }
      subimage_stream(lReset,sInput,sOutput);
      lReset = false;
      if(!sOutput[0].empty()) { 
	for(unsigned i2 = 0; i2 < N_FILT_34; i2++) { 
         #pragma HLS UNROLL
	 output[i0][i1][i2] = sOutput[i2].read();
	}
      }
    }
  }
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>  input[N_INPUT_3_1],
	      hls::stream<result_t> output[N_FILT_34]) { 
  
       #pragma HLS DATAFLOW

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 4096>(w6, "w6.txt");
        nnet::load_weights_from_txt<bias6_t, 64>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s7, "s7.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b7, "b7.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w9, "w9.txt");
        nnet::load_weights_from_txt<bias9_t, 64>(b9, "b9.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s10, "s10.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w12, "w12.txt");
        nnet::load_weights_from_txt<bias12_t, 256>(b12, "b12.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s13, "s13.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b13, "b13.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w14, "w14.txt");
        nnet::load_weights_from_txt<bias14_t, 256>(b14, "b14.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s15, "s15.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b15, "b15.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w18, "w18.txt");
        nnet::load_weights_from_txt<bias18_t, 64>(b18, "b18.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s19, "s19.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b19, "b19.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w21, "w21.txt");
        nnet::load_weights_from_txt<bias21_t, 64>(b21, "b21.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s22, "s22.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b22, "b22.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w24, "w24.txt");
        nnet::load_weights_from_txt<bias24_t, 256>(b24, "b24.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s25, "s25.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b25, "b25.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w28, "w28.txt");
        nnet::load_weights_from_txt<bias28_t, 64>(b28, "b28.txt");
	nnet::load_weights_from_txt<model_default_t, 64>(s29, "s29.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b29, "b29.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w31, "w31.txt");
        nnet::load_weights_from_txt<bias31_t, 64>(b31, "b31.txt");
	nnet::load_weights_from_txt<model_default_t, 64>(s32, "s32.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b32, "b32.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w34, "w34.txt");
        nnet::load_weights_from_txt<bias34_t,256>(b34, "b34.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s35, "s35.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b35, "b35.txt");
        nnet::load_weights_from_txt<model_default_t, 32768>(w38, "w38.txt");
        nnet::load_weights_from_txt<bias38_t,128>(b38, "b38.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s39, "s39.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b39, "b39.txt");
        loaded_weights = true;
    }
#endif

    static hls::stream<input_t>  layer6_in1[N_FILT_5];
    static hls::stream<input_t>  layer6_in2[N_FILT_5];
    #pragma HLS stream variable=layer6_in1      depth=1
    #pragma HLS stream variable=layer6_in2      depth=1
    nnet::split<input_t,input_t,config6>(input,layer6_in1,layer6_in2);
    
    static hls::stream<layer6_t> layer6_out[N_FILT_6];
    #pragma HLS stream variable=layer6_out      depth=1
    if(!layer6_in1[0].empty()) nnet::conv_2d_large_stream_norm<input_t,layer6_t,config6>(iReset,layer6_in1,layer6_out,w6,b6,s7,b7);

    static hls::stream<layer14_t> layer14_out[N_FILT_14];
    #pragma HLS stream variable=layer14_out      depth=1
    if(!layer6_in2[0].empty()) nnet::conv_2d_large_stream_norm<layer6_t,layer14_t,config14>(iReset,layer6_in2,layer14_out,w14,b14,s15,b15);

    static hls::stream<layer9_t> layer9_out[N_FILT_9];
    #pragma HLS stream variable=layer9_out      depth=1
    if(!layer6_out[0].empty()) nnet::conv_2d_large_stream_norm<layer6_t,layer9_t,config9>(iReset,layer6_out,layer9_out,w9,b9,s10,b10);

    static hls::stream<layer12_t> layer12_out[N_FILT_12];
    #pragma HLS stream variable=layer12_out      depth=1
    if(!layer9_out[0].empty()) nnet::conv_2d_large_stream_norm<layer9_t,layer12_t,config12>(iReset,layer9_out,layer12_out,w12,b12,s13,b13);

    static hls::stream<layer14_t> layer14_out2[N_FILT_14];
    #pragma HLS stream variable=layer14_out2      depth=1
    if(!layer12_out[0].empty() && !layer14_out[0].empty()) nnet::addrelu<layer12_t,result_t,config14>(layer12_out,layer14_out,layer14_out2);

    static hls::stream<layer18_t>  layer18_in1[N_FILT_14];
    static hls::stream<layer18_t>  layer18_in2[N_FILT_14];
    #pragma HLS stream variable=layer18_in1      depth=1
    #pragma HLS stream variable=layer18_in2      depth=1
    if(!layer14_out2[0].empty()) nnet::split<layer14_t,layer18_t,config18>(layer14_out2,layer18_in1,layer18_in2);

    static hls::stream<layer18_t> layer18_out[N_FILT_18];
    #pragma HLS stream variable=layer18_out      depth=1
    if(!layer18_in1[0].empty()) nnet::conv_2d_large_stream_norm<layer14_t,layer18_t,config18>(iReset,layer18_in1,layer18_out,w18,b18,s19,b19);

    static hls::stream<layer21_t> layer21_out[N_FILT_21];
    #pragma HLS stream variable=layer21_out      depth=1
    if(!layer18_out[0].empty()) nnet::conv_2d_large_stream_norm<layer18_t,layer21_t,config21>(iReset,layer18_out,layer21_out,w21,b21,s22,b22);

    static hls::stream<layer24_t> layer24_out[N_FILT_24];
    #pragma HLS stream variable=layer24_out      depth=1
    if(!layer21_out[0].empty()) nnet::conv_2d_large_stream_norm<layer21_t,layer24_t,config24>(iReset,layer21_out,layer24_out,w24,b24,s25,b25);

    static hls::stream<layer24_t> layer26_out[N_FILT_24];
    #pragma HLS stream variable=layer26_out      depth=1
    if(!layer18_in2[0].empty() && !layer24_out[0].empty()) nnet::addrelu<layer18_t,layer24_t,config24>(layer18_in2,layer24_out,layer26_out);

    static hls::stream<layer24_t>  layer28_in1[N_FILT_24];
    static hls::stream<layer24_t>  layer28_in2[N_FILT_24];
    #pragma HLS stream variable=layer28_in1      depth=1
    #pragma HLS stream variable=layer28_in2      depth=1
    if(!layer26_out[0].empty()) nnet::split<layer24_t,layer24_t,config28>(layer26_out,layer28_in1,layer28_in2);

    static hls::stream<layer28_t> layer28_out[N_FILT_28];
    #pragma HLS stream variable=layer28_out      depth=1
    if(!layer28_in1[0].empty()) nnet::conv_2d_large_stream_norm<layer24_t,layer28_t,config28>(iReset,layer28_in1,layer28_out,w28,b28,s29,b29);

    static hls::stream<layer31_t> layer31_out[N_FILT_31];
    #pragma HLS stream variable=layer31_out      depth=1
    if(!layer28_out[0].empty()) nnet::conv_2d_large_stream_norm<layer28_t,layer31_t,config31>(iReset,layer28_out,layer31_out,w31,b31,s32,b32);

    static hls::stream<layer34_t> layer34_out[N_FILT_34];
    #pragma HLS stream variable=layer31_out      depth=1
    if(!layer31_out[0].empty()) nnet::conv_2d_large_stream_norm<layer31_t,layer34_t,config34>(iReset,layer31_out,layer34_out,w34,b34,s35,b35);
    
    if(!layer28_in2[0].empty() && !layer34_out[0].empty()) nnet::addrelu<layer34_t,result_t,config34>(layer28_in2,layer34_out,output);

}

