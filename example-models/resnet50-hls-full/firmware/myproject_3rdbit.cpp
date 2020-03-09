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

#include "myproject_3rdbit.h"
#include "weights/w92.h"
#include "weights/s93.h"
#include "weights/b93.h"
#include "weights/w95.h"
#include "weights/s96.h"
#include "weights/b96.h"
#include "weights/w98.h"
#include "weights/s99.h"
#include "weights/b99.h"
#include "weights/w102.h"
#include "weights/s103.h"
#include "weights/b103.h"
#include "weights/w105.h"
#include "weights/s106.h"
#include "weights/b106.h"
#include "weights/w108.h"
#include "weights/s109.h"
#include "weights/b109.h"
#include "weights/w112.h"
#include "weights/s113.h"
#include "weights/b113.h"
#include "weights/w115.h"
#include "weights/s116.h"
#include "weights/b116.h"
#include "weights/w118.h"
#include "weights/s119.h"
#include "weights/b119.h"
#include "weights/w122.h"
#include "weights/s123.h"
#include "weights/b123.h"
#include "weights/w125.h"
#include "weights/b125.h"
#include "weights/s126.h"
#include "weights/b126.h"
#include "weights/w128.h"
#include "weights/s129.h"
#include "weights/b129.h"
#include "weights/w132.h"
#include "weights/s133.h"
#include "weights/b133.h"
#include "weights/w135.h"
#include "weights/s136.h"
#include "weights/b136.h"
#include "weights/w138.h"
#include "weights/s139.h"
#include "weights/b139.h"
#include "weights/w142.h"
#include "weights/s143.h"
#include "weights/b143.h"
#include "weights/w145.h"
#include "weights/s146.h"
#include "weights/b146.h"
#include "weights/w148.h"
#include "weights/s149.h"
#include "weights/b149.h"
#include "weights/w150.h"
#include "weights/s151.h"
#include "weights/b151.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]) { 

  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_150];
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
	for(unsigned i2 = 0; i2 < N_FILT_98; i2++) { 
         #pragma HLS UNROLL
	 output[i0][i1][i2] = sOutput[i2].read();
	}
      }
    }
  }
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>  input[N_INPUT_3_1],
	      hls::stream<result_t> output[N_FILT_150]) { 

#pragma HLS DATAFLOW

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 262144>(w92, "w92.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s93, "s93.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b93, "b93.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w95, "w95.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s96, "s96.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b96, "b96.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w98, "w98.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s99, "s99.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b99, "b99.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w102, "w102.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s103, "s103.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b103, "b103.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w105, "w105.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s106, "s106.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b106, "b106.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w108, "w108.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s109, "s109.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b109, "b109.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w112, "w112.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s113, "s113.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b113, "b113.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w115, "w115.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s116, "s116.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b116, "b116.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w118, "w118.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s119, "s119.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b119, "b119.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w122, "w122.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s123, "s123.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b123, "b123.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w125, "w125.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s126, "s126.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b126, "b126.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w128, "w128.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s129, "s129.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b129, "b129.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w132, "w132.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s133, "s133.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b133, "b133.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w135, "w135.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s136, "s136.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b136, "b136.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w138, "w138.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s139, "s139.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b139, "b139.txt");
        nnet::load_weights_from_txt<model_default_t, 524288>(w142, "w142.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s143, "s143.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b143, "b143.txt");
        nnet::load_weights_from_txt<model_default_t, 2359296>(w145, "w145.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s146, "s146.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b146, "b146.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w148, "w148.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s149, "s149.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b149, "b149.txt");
        nnet::load_weights_from_txt<model_default_t, 2097152>(w150, "w150.txt");
        loaded_weights = true;
    }
#endif


    static hls::stream<layer92_t>  layer92_out1[N_FILT_88];
    static hls::stream<layer92_t>  layer92_out2[N_FILT_88];
    #pragma HLS stream variable=layer92_out1      depth=1
    #pragma HLS stream variable=layer92_out2      depth=1
    if(!input[0].empty()) nnet::split<layer92_t,layer92_t,config92>(input,layer92_out1,layer92_out2);

    hls::stream<layer92_t> layer92_out[N_FILT_92];
    #pragma HLS stream variable=layer92_out      depth=1
    if(!layer92_out1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer88_t,layer92_t,config92>(iReset,layer92_out1,layer92_out,w92,s93,b93);

    hls::stream<layer95_t> layer95_out[N_FILT_95];
    #pragma HLS stream variable=layer95_out      depth=1
    if(!layer92_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer92_t,layer95_t,config95>(iReset,layer92_out,layer95_out,w95,s96,b96);

    hls::stream<layer98_t> layer98_out[N_FILT_98];
    #pragma HLS stream variable=layer98_out      depth=1
    if(!layer95_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer96_t,layer98_t,config98>(iReset,layer95_out,layer98_out,w98,s99,b99);

    static hls::stream<layer98_t> layer98_out2[N_FILT_98];
    #pragma HLS stream variable=layer98_out2      depth=1
    if(!layer92_out2[0].empty() && !layer98_out[0].empty()) nnet::addrelu<layer98_t,layer98_t,config98>(layer92_out2,layer98_out,layer98_out2);

    static hls::stream<layer98_t>  layer98_out3[N_FILT_98];
    static hls::stream<layer98_t>  layer98_out4[N_FILT_98];
    #pragma HLS stream variable=layer98_out3      depth=1
    #pragma HLS stream variable=layer98_out4      depth=1
    if(!layer98_out2[0].empty()) nnet::split<layer98_t,layer98_t,config102>(layer98_out2,layer98_out3,layer98_out4);

    hls::stream<layer102_t> layer102_out[N_FILT_102];
    #pragma HLS stream variable=layer102_out      depth=1
    if(!layer98_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer98_t,layer102_t,config102>(iReset,layer98_out3,layer102_out,w102,s103,b103);

    hls::stream<layer105_t> layer105_out[N_FILT_105];
    #pragma HLS stream variable=layer105_out      depth=1
    if(!layer102_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer102_t,layer105_t,config105>(iReset,layer102_out,layer105_out,w105,s106,b106);

    hls::stream<layer108_t> layer108_out[N_FILT_108];
    #pragma HLS stream variable=layer108_out      depth=1
    if(!layer108_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer105_t,layer108_t,config108>(iReset,layer105_out,layer108_out,w108,s109,b109);

    static hls::stream<layer108_t> layer108_out2[N_FILT_108];
    #pragma HLS stream variable=layer108_out2      depth=1
    if(!layer98_out4[0].empty() && !layer108_out[0].empty()) nnet::addrelu<layer108_t,layer108_t,config108>(layer98_out4,layer108_out,layer108_out2);

}
/*
    static hls::stream<layer108_t>  layer108_out3[N_FILT_108];
    static hls::stream<layer108_t>  layer108_out4[N_FILT_108];
    #pragma HLS stream variable=layer108_out3      depth=1
    #pragma HLS stream variable=layer108_out4      depth=1
    if(!layer108_out2[0].empty()) nnet::split<layer108_t,layer108_t,config112>(layer108_out2,layer108_out3,layer108_out4);

    hls::stream<layer112_t> layer112_out[N_FILT_112];
    #pragma HLS stream variable=layer112_out      depth=1
    if(!layer108_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer108_t,layer112_t,config112>(iReset,layer108_out3,layer112_out,w112,s113,b113);

    hls::stream<layer115_t> layer115_out[N_FILT_115];
    #pragma HLS stream variable=layer115_out      depth=1
    if(!layer112_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer112_t,layer115_t,config115>(iReset,layer112_out,layer115_out,w115,s116,b116);

    hls::stream<layer118_t> layer118_out[N_FILT_118];
    #pragma HLS stream variable=layer118_out      depth=1
    if(!layer115_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer115_t,layer118_t,config118>(iReset,layer115_out,layer118_out,w118,s119,b119);

    static hls::stream<layer118_t> layer118_out2[N_FILT_118];
    #pragma HLS stream variable=layer118_out2      depth=1
    if(!layer108_out4[0].empty() && !layer118_out[0].empty()) nnet::addrelu<layer118_t,layer118_t,config118>(layer108_out4,layer118_out,layer118_out2);

    static hls::stream<layer118_t>  layer118_out3[N_FILT_118];
    static hls::stream<layer118_t>  layer118_out4[N_FILT_118];
    #pragma HLS stream variable=layer118_out3      depth=1
    #pragma HLS stream variable=layer118_out4      depth=1
    if(!layer118_out2[0].empty()) nnet::split<layer118_t,layer118_t,config122>(layer118_out2,layer118_out3,layer118_out4);

    hls::stream<layer122_t> layer122_out[N_FILT_122];
    #pragma HLS stream variable=layer122_out      depth=1
    if(!layer118_out4[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer118_t,layer122_t,config122>(iReset,layer118_out4,layer122_out,w122,s123,b123);

    hls::stream<layer125_t> layer125_out[N_FILT_125];
    #pragma HLS stream variable=layer125_out      depth=1
    if(!layer122_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer122_t,layer125_t,config125>(iReset,layer122_out,layer125_out,w125,s126,b126);

    hls::stream<layer128_t> layer128_out[N_FILT_128];
    #pragma HLS stream variable=layer128_out      depth=1
    if(!layer125_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer125_t,layer128_t,config128>(iReset,layer125_out,layer128_out,w128,s129,b129);

    static hls::stream<layer118_t> layer128_out2[N_FILT_128];
    #pragma HLS stream variable=layer128_out2      depth=1
    if(!layer118_out4[0].empty() && !layer128_out[0].empty()) nnet::addrelu<layer128_t,layer128_t,config128>(layer118_out4,layer128_out,layer128_out2);

    static hls::stream<layer128_t>  layer128_out3[N_FILT_128];
    static hls::stream<layer128_t>  layer128_out4[N_FILT_128];
    #pragma HLS stream variable=layer128_out3      depth=1
    #pragma HLS stream variable=layer128_out4      depth=1
    if(!layer128_out2[0].empty()) nnet::split<layer128_t,layer128_t,config132>(layer128_out2,layer128_out3,layer128_out4);

    hls::stream<layer132_t> layer132_out[N_FILT_132];
    #pragma HLS stream variable=layer132_out      depth=1
    if(!layer128_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer128_t,layer132_t,config132>(iReset,layer128_out3,layer132_out,w132,s133,b133);

    hls::stream<layer135_t> layer135_out[N_FILT_135];
    #pragma HLS stream variable=layer135_out      depth=1
    if(!layer135_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer132_t,layer135_t,config135>(iReset,layer132_out,layer135_out,w135,s136,b136);

    hls::stream<layer138_t> layer138_out[N_FILT_138];
    #pragma HLS stream variable=layer138_out      depth=1
    if(!layer138_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer135_t,layer138_t,config138>(iReset,layer135_out,layer138_out,w138,s139,b139);

    static hls::stream<layer138_t> layer138_out2[N_FILT_138];
    #pragma HLS stream variable=layer138_out2      depth=1
    if(!layer128_out4[0].empty() && !layer138_out[0].empty()) nnet::addrelu<layer138_t,layer138_t,config138>(layer128_out4,layer138_out,layer138_out2);

    static hls::stream<layer138_t>  layer138_out3[N_FILT_138];
    static hls::stream<layer138_t>  layer138_out4[N_FILT_138];
    #pragma HLS stream variable=layer138_out3      depth=1
    #pragma HLS stream variable=layer138_out4      depth=1
    if(!layer138_out2[0].empty()) nnet::split<layer138_t,layer138_t,config142>(layer138_out2,layer138_out3,layer138_out4);

    hls::stream<layer142_t> layer142_out[N_FILT_142];
    #pragma HLS stream variable=layer142_out      depth=1
    if(!layer138_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer138_t,result_t,config142>(iReset,layer138_out3,layer142_out,w142,s143,b143);

    hls::stream<layer145_t> layer145_out[N_FILT_145];
    #pragma HLS stream variable=layer145_out      depth=1
    if(!input[0].empty()) nnet::conv_2d_large_stream_norm_nobias<input_t,layer145_t,config145>(iReset,layer142_out,layer145_out,w145,s146,b146);

    hls::stream<layer148_t> layer148_out[N_FILT_148];
    #pragma HLS stream variable=layer148_out      depth=1
    if(!layer145_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer145_t,layer148_t,config148>(iReset,layer145_out,layer148_out,w148,s149,b149);
    
    hls::stream<layer150_t> layer150_out[N_FILT_150];
    #pragma HLS stream variable=layer150_out      depth=1
    if(!layer138_out4[0].empty()) nnet::conv_2d_large_stream_norm_resnet<layer150_t,layer150_t,config150>(iReset,layer138_out4,layer150_out,w150,s151,b151);

    //static hls::stream<layer150_t> layer150_out2[N_FILT_150];
    //#pragma HLS stream variable=layer150_out2      depth=1
    if(!layer148_out[0].empty() && !layer150_out[0].empty()) nnet::addrelu<layer148_t,layer150_t,config150>(layer148_out,layer150_out,output);
}
