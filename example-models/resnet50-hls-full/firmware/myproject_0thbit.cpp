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

#include "myproject_0thbit.h"

//hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/s3.h"
#include "weights/b3.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]) { 
  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_5];
  #pragma HLS stream variable=sInput      depth=1
  #pragma HLS stream variable=sOutput     depth=1
  bool lReset = true;
  unsigned iX = 0; 
  unsigned iY = 0; 
  for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
    for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
      for(unsigned i2 = 0; i2 < N_INPUT_3_1; i2++) { 
          #pragma HLS UNROLL
	  sInput[i2].write(input[i0][i1][i2]);
      }
      subimage_stream(lReset,sInput,sOutput);
      lReset = false;
      if(!sOutput[0].empty()) { //it all gets shrunk to one single output
	for(unsigned i2 = 0; i2 < N_FILT_5; i2++) { 
         #pragma HLS UNROLL
	 output[iX][iY][i2] = sOutput[i2].read();
	}
	iY = iY + 1;
	if(iY == N_LAYER_OUT_2) {iY = 0; iX = iX + 1;}
	std::cout << "===here out " << iX << " -- " << iY << " -- " << N_LAYER_OUT_2 << std::endl;
      }
    }
  }
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>    input[N_INPUT_3_1],
	      hls::stream<layer5_t> output[N_FILT_5]) { 
  
       #pragma HLS DATAFLOW

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 9408>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b3, "b3.txt");
        loaded_weights = true;
    }
#endif

    static hls::stream<layer2_t> layer2_out[N_FILT_2];
    #pragma HLS stream variable=layer2_out      depth=1
    if(!input[0].empty()) nnet::conv_2d_large_stream_norm_nobias<input_t,layer2_t,config2>(iReset,input,layer2_out,w2,s3,b3);

    //hls::stream<layer5_t> layer5_out[N_FILT_5];
    //#pragma HLS stream variable=layer5_out      depth=1
    if(!layer2_out[0].empty()) nnet::pool_2d_large_stream<layer2_t,layer5_t,config5>(layer2_out,output);
}

