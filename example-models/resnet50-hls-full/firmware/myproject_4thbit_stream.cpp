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

#include "myproject_4thbit_stream.h"

#include "weights/s155.h"
#include "weights/b155.h"
#include "weights/s158.h"
#include "weights/b158.h"
#include "weights/s161.h"
#include "weights/b161.h"
#include "weights/s165.h"
#include "weights/b165.h"
#include "weights/s168.h"
#include "weights/b168.h"
#include "weights/s171.h"
#include "weights/b171.h"


void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3],
	      hls::stream<model_default_t> w154[512],
	      hls::stream<model_default_t> w157[512],
	      hls::stream<model_default_t> w160[512],
	      hls::stream<model_default_t> w164[512],
	      hls::stream<model_default_t> w167[512],
	      hls::stream<model_default_t> w170[512]) { 

  //#pragma HLS interface bram port=w154
  //#pragma HLS interface bram port=w157
  //#pragma HLS interface bram port=w160
  //#pragma HLS interface bram port=w164
  //#pragma HLS interface bram port=w167
  //#pragma HLS interface bram port=w170

  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_170];
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
      subimage_stream(lReset,sInput,sOutput,w154,w157,w160,w164,w167,w170);
      lReset = false;
      if(!sOutput[0].empty()) { 
	for(unsigned i2 = 0; i2 < N_FILT_170; i2++) { 
         #pragma HLS UNROLL
	 output[iX][iY][i2] = sOutput[i2].read();
	}
	iY = iY + 1;
	if(iY == N_LAYER_OUT_2) {iY = 0; iX = iX + 1;}
      }
    }
  }
}

void subimage_stream(bool iReset, 
		     hls::stream<input_t>  input[N_INPUT_3_1],
		     hls::stream<result_t> output[N_FILT_170],
		     hls::stream<model_default_t> w154[512],
		     hls::stream<model_default_t> w157[512],
		     hls::stream<model_default_t> w160[512],
		     hls::stream<model_default_t> w164[512],
		     hls::stream<model_default_t> w167[512],
		     hls::stream<model_default_t> w170[512]) { 

  //#pragma HLS interface bram port=w154
  //#pragma HLS interface bram port=w157
  //#pragma HLS interface bram port=w160
  //#pragma HLS interface bram port=w164
  //#pragma HLS interface bram port=w167
  //#pragma HLS interface bram port=w170

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 512>(s155, "s155.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b155, "b155.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s158, "s158.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b158, "b158.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s161, "s161.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b161, "b161.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s165, "s165.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b165, "b165.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s168, "s168.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b168, "b168.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s171, "s171.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b171, "b171.txt");
        loaded_weights = true;
    }
#endif

    static hls::stream<layer150_t>  layer150_out1[N_FILT_150];
    static hls::stream<layer150_t>  layer150_out2[N_FILT_150];
    #pragma HLS stream variable=layer150_out1      depth=1
    #pragma HLS stream variable=layer150_out2      depth=1
    if(!input[0].empty())nnet::split<layer150_t,layer150_t,config154>(input,layer150_out1,layer150_out2);

    static hls::stream<layer154_t> layer154_out[N_FILT_154];
    #pragma HLS stream variable=layer154_out      depth=1
    if(!layer150_out1[0].empty()) nnet::conv_2d_large_stream_norm_nobias_stream<layer150_t,layer154_t,config154>(iReset,layer150_out1,layer154_out,w154,s155,b155);

    static hls::stream<layer157_t> layer157_out[N_FILT_157];
    #pragma HLS stream variable=layer157_out      depth=1
    if(!layer154_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias_stream<layer154_t,layer157_t,config157>(iReset,layer154_out,layer157_out,w157,s158,b158);

    static hls::stream<layer160_t> layer160_out[N_FILT_160];
    #pragma HLS stream variable=layer160_out      depth=1
    if(!layer160_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias_stream<layer160_t,layer160_t,config160>(iReset,layer157_out,layer160_out,w160,s161,b161);

    static hls::stream<layer160_t> layer160_out2[N_FILT_160];
    #pragma HLS stream variable=layer160_out2      depth=1
    if(!layer150_out2[0].empty() && !layer160_out[0].empty()) nnet::addrelu<layer160_t,layer160_t,config160>(layer150_out2,layer160_out,layer160_out2);

    static hls::stream<layer160_t>  layer160_out3[N_FILT_160];
    static hls::stream<layer160_t>  layer160_out4[N_FILT_160];
    #pragma HLS stream variable=layer160_out3      depth=1
    #pragma HLS stream variable=layer160_out4      depth=1
    if(!layer160_out2[0].empty()) nnet::split<layer160_t,layer160_t,config164>(layer160_out2,layer160_out3,layer160_out4);

    static hls::stream<layer164_t> layer164_out[N_FILT_164];
    #pragma HLS stream variable=layer164_out      depth=1
    if(!layer160_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias_stream<layer160_t,layer164_t,config164>(iReset,layer160_out3,layer164_out,w164,s165,b165);

    static hls::stream<layer167_t> layer167_out[N_FILT_167];
    #pragma HLS stream variable=layer167_out      depth=1
    if(!layer164_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias_stream<layer164_t,layer167_t,config167>(iReset,layer164_out,layer167_out,w167,s168,b168);

    static hls::stream<layer170_t> layer170_out[N_FILT_170];
    #pragma HLS stream variable=layer170_out      depth=1
    if(!layer167_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias_stream<layer167_t,layer170_t,config170>(iReset,layer167_out,layer170_out,w170,s171,b171);

    //static hls::stream<layer170_t> layer170_out2[N_FILT_170];
    //#pragma HLS stream variable=layer170_out2      depth=1
    if(!layer160_out4[0].empty() && !layer170_out[0].empty()) nnet::addrelu<layer170_t,layer170_t,config170>(layer160_out4,layer170_out,output);
}
