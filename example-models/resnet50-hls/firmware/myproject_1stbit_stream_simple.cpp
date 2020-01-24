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


void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]) { 

  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_12];
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
      if(lReset) lReset = false;
      for(unsigned i2 = 0; i2 < N_FILT_12; i2++) { 
       #pragma HLS UNROLL
       output[i0][i1][i2] = sOutput[i2].read();
      }
    }
  }
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>  input[N_INPUT_3_1],
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

    hls::stream<layer6_t> layer6_out[N_FILT_6];
    #pragma HLS stream variable=layer6_out      depth=1
    nnet::conv_2d_large_stream_norm<input_t,layer6_t,config6>(input,layer6_out,w6,b6,s7,b7);
    hls::stream<layer9_t> layer9_out[N_FILT_9];
    #pragma HLS stream variable=layer9_out      depth=1
    nnet::conv_2d_large_stream_norm<layer6_t,layer9_t,config9>(layer6_out,layer9_out,w9,b9,s10,b10);
    //hls::stream<layer9_t> layer12_out[N_FILT_12];
    nnet::conv_2d_large_stream_norm<layer9_t,result_t,config12>(layer9_out,output,w12,b12,s13,b13);

}
