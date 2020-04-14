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

#include "myproject_2ndbit.h"
#include "weights/w50.h"
#include "weights/b50.h"
#include "weights/s51.h"
#include "weights/b51.h"
#include "weights/w53.h"
#include "weights/b53.h"
#include "weights/s54.h"
#include "weights/b54.h"
#include "weights/w56.h"
#include "weights/b56.h"
#include "weights/s57.h"
#include "weights/b57.h"
#include "weights/w60.h"
#include "weights/b60.h"
#include "weights/s61.h"
#include "weights/b61.h"
#include "weights/w63.h"
#include "weights/b63.h"
#include "weights/s64.h"
#include "weights/b64.h"
#include "weights/w66.h"
#include "weights/b66.h"
#include "weights/s67.h"
#include "weights/b67.h"
#include "weights/w70.h"
#include "weights/b70.h"
#include "weights/s71.h"
#include "weights/b71.h"
#include "weights/w73.h"
#include "weights/b73.h"
#include "weights/s74.h"
#include "weights/b74.h"
#include "weights/w76.h"
#include "weights/b76.h"
#include "weights/s77.h"
#include "weights/b77.h"
#include "weights/w80.h"
#include "weights/b80.h"
#include "weights/s81.h"
#include "weights/b81.h"
#include "weights/w83.h"
#include "weights/b83.h"
#include "weights/s84.h"
#include "weights/b84.h"
#include "weights/w86.h"
#include "weights/b86.h"
#include "weights/s87.h"
#include "weights/b87.h"
#include "weights/w88.h"
#include "weights/b88.h"
#include "weights/s89.h"
#include "weights/b89.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]) { 

  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_56];
  #pragma HLS stream variable=sInput      depth=1
  #pragma HLS stream variable=sOutput     depth=1
  bool lReset = true;
  unsigned iX = 0; 
  unsigned iY = 0; 
  for(unsigned i0 = 0; i0 < N_INPUT_1_1; i0++) { 
    for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
      for(unsigned i2 = 0; i2 < N_INPUT_3_1; i2++) { 
          #pragma HLS UNROLL
	if(i1 < N_INPUT_2_1-1) sInput[i2].write(input[i0][i1][i2]);
      }
      subimage_stream(lReset,sInput,sOutput);
      lReset = false;
      if(!sOutput[0].empty()) { 
	for(unsigned i2 = 0; i2 < N_FILT_56; i2++) { 
         #pragma HLS UNROLL
	 output[iX][iY][i2] = sOutput[i2].read();
	}
	iY = iY + 1;
	if(iY == N_LAYER_OUT_2) {iY = 0; iX = iX + 1;}
	std::cout << "===> " << iX << " -- " << iY << std::endl;
      }
    }
  }
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>  input[N_INPUT_3_1],
	      hls::stream<result_t> output[N_FILT_56]) { 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 65536>(w50, "w50.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s51, "s51.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b51, "b51.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w53, "w53.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s54, "s54.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b54, "b54.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w56, "w56.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s57, "s57.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b57, "b57.txt");
	nnet::load_weights_from_txt<model_default_t, 65536>(w60, "w60.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s61, "s61.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b61, "b61.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w63, "w63.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s64, "s64.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b64, "b64.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w66, "w66.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s67, "s67.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b67, "b67.txt");
        /*
        nnet::load_weights_from_txt<model_default_t, 65536>(w70, "w70.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s71, "s71.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b71, "b71.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w73, "w73.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s74, "s74.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b74, "b74.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w76, "w76.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s77, "s77.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b77, "b77.txt");
        nnet::load_weights_from_txt<model_default_t, 131072>(w80, "w80.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s81, "s81.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b81, "b81.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w83, "w83.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s84, "s84.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b84, "b84.txt");
        nnet::load_weights_from_txt<model_default_t, 262144>(w86, "w86.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s87, "s87.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b87, "b87.txt");
        nnet::load_weights_from_txt<model_default_t, 524288>(w88, "w88.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(s89, "s89.txt");
        nnet::load_weights_from_txt<model_default_t, 1024>(b89, "b89.txt");
	*/
        loaded_weights = true;
    }
#endif

    static hls::stream<layer50_t>  layer50_out1[N_FILT_46];
    static hls::stream<layer50_t>  layer50_out2[N_FILT_46];
    #pragma HLS stream variable=layer50_out1      depth=1
    #pragma HLS stream variable=layer50_out2      depth=1
    if(!input[0].empty())nnet::split<layer50_t,layer50_t,config50>(input,layer50_out1,layer50_out2);
    
    static hls::stream<layer50_t> layer50_out[N_FILT_50];
    #pragma HLS stream variable=layer50_out      depth=1
    if(!layer50_out1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer50_t,layer50_t,config50>(iReset,layer50_out1,layer50_out,w50,s51,b51);
    //if(!input[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer50_t,layer50_t,config50>(iReset,input,layer50_out,w50,s51,b51);

    static hls::stream<layer53_t> layer53_out[N_FILT_53];
    #pragma HLS stream variable=layer53_out      depth=1
    if(!layer50_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer50_t,layer53_t,config53>(iReset,layer50_out,layer53_out,w53,s54,b54);

    static hls::stream<layer56_t> layer56_out[N_FILT_56];
    #pragma HLS stream variable=layer56_out      depth=1
    if(!layer53_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer53_t,layer56_t,config56>(iReset,layer53_out,layer56_out,w56,s57,b57);

    static hls::stream<layer56_t> layer56_out2[N_FILT_56];
    #pragma HLS stream variable=layer56_out2      depth=1
    if(!layer50_out2[0].empty() && !layer56_out[0].empty()) nnet::addrelu<layer50_t,layer56_t,config56>(layer50_out2,layer56_out,layer56_out2);

    static hls::stream<layer56_t>  layer56_out3[N_FILT_56];
    static hls::stream<layer56_t>  layer56_out4[N_FILT_56];
    #pragma HLS stream variable=layer56_out3      depth=1
    #pragma HLS stream variable=layer56_out4      depth=1
    if(!layer56_out2[0].empty()) nnet::split<layer56_t,layer56_t,config60>(layer56_out2,layer56_out3,layer56_out4);

    static hls::stream<layer60_t> layer60_out[N_FILT_60];
    #pragma HLS stream variable=layer60_out      depth=1
    if(!layer56_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer56_t,layer60_t,config60>(iReset,layer56_out3,layer60_out,w60,s61,b61);

    static hls::stream<layer63_t> layer63_out[N_FILT_63];
    #pragma HLS stream variable=layer63_out      depth=1
    if(!layer60_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer60_t,layer63_t,config63>(iReset,layer60_out,layer63_out,w63,s64,b64);

    static hls::stream<layer66_t> layer66_out[N_FILT_66];
    #pragma HLS stream variable=layer66_out      depth=1
    if(!layer63_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer63_t,layer66_t,config66>(iReset,layer63_out,layer66_out,w66,s67,b67);


    //static hls::stream<layer66_t> layer66_out2[N_FILT_66];
    //#pragma HLS stream variable=layer66_out2      depth=1
   if(!layer56_out4[0].empty() && !layer66_out[0].empty()) nnet::addrelu<layer66_t,layer66_t,config66>(layer56_out4,layer66_out,output);//layer66_out2);
    
    /*
    static hls::stream<layer66_t>  layer66_out3[N_FILT_66];
    static hls::stream<layer66_t>  layer66_out4[N_FILT_66];
    #pragma HLS stream variable=layer66_out3      depth=1
    #pragma HLS stream variable=layer66_out4      depth=1
    if(!layer66_out2[0].empty()) nnet::split<layer66_t,layer66_t,config70>(layer66_out2,layer66_out3,layer66_out4);

    static hls::stream<layer70_t> layer70_out[N_FILT_70];
    #pragma HLS stream variable=layer70_out      depth=1
    if(!layer66_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer66_t,layer70_t,config70>(iReset,layer66_out,layer70_out,w70,s71,b71);

    static hls::stream<layer73_t> layer73_out[N_FILT_73];
    #pragma HLS stream variable=layer73_out      depth=1
    if(!layer70_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer70_t,layer73_t,config73>(iReset,layer70_out,layer73_out,w73,s74,b74);

    static hls::stream<layer76_t> layer76_out[N_FILT_76];
    #pragma HLS stream variable=layer76_out      depth=1
    if(!layer73_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer73_t,layer76_t,config76>(iReset,layer73_out,layer76_out,w76,s77,b77);

    static hls::stream<layer76_t> layer76_out2[N_FILT_76];
    #pragma HLS stream variable=layer76_out2      depth=1
    if(!layer66_out4[0].empty() && !layer76_out[0].empty()) nnet::addrelu<layer66_t,layer66_t,config66>(layer66_out4,layer76_out,layer76_out2);

    static hls::stream<layer76_t>  layer76_out3[N_FILT_76];
    static hls::stream<layer76_t>  layer76_out4[N_FILT_76];
    #pragma HLS stream variable=layer76_out3      depth=1
    #pragma HLS stream variable=layer76_out4      depth=1
    if(!layer76_out2[0].empty()) nnet::split<layer76_t,layer76_t,config76>(layer76_out2,layer76_out3,layer76_out4);

    static hls::stream<layer80_t> layer80_out[N_FILT_80];
    #pragma HLS stream variable=layer80_out      depth=1
    if(!layer76_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer76_t,layer80_t,config80>(iReset,layer76_out3,layer80_out,w80,s81,b81);

    static hls::stream<layer83_t> layer83_out[N_FILT_83];
    #pragma HLS stream variable=layer83_out      depth=1
    if(!layer80_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer80_t,layer83_t,config83>(iReset,layer80_out,layer83_out,w83,s84,b84);

    static hls::stream<layer86_t> layer86_out[N_FILT_86];
    #pragma HLS stream variable=layer86_out      depth=1
    if(!layer83_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer83_t,layer86_t,config86>(iReset,layer83_out,layer86_out,w86,s87,b87);
    
    static hls::stream<layer88_t> layer88_out[N_FILT_88];
    #pragma HLS stream variable=layer88_out      depth=1
    if(!layer76_out4[0].empty()) nnet::conv_2d_large_stream_norm_resnet<layer86_t,layer88_t,config88>(iReset,layer76_out4,layer88_out,w88,s89,b89);

    //static hls::stream<layer76_t> layer88_out2[N_FILT_76];
    //#pragma HLS stream variable=layer88_out2      depth=1
    if(!layer88_out[0].empty() && !layer86_out[0].empty()) nnet::addrelu<layer86_t,layer88_t,config88>(layer86_out,layer88_out,output);
    */
}

