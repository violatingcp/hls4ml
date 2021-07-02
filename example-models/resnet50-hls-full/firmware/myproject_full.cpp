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

#include "myproject_full.h"

//hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/s3.h"
#include "weights/b3.h"
#include "weights/w6.h"
#include "weights/s7.h"
#include "weights/b7.h"
#include "weights/w9.h"
#include "weights/s10.h"
#include "weights/b10.h"
#include "weights/w12.h"
#include "weights/s13.h"
#include "weights/b13.h"
#include "weights/w14.h"
#include "weights/s15.h"
#include "weights/b15.h"
#include "weights/w18.h"
#include "weights/s19.h"
#include "weights/b19.h"
#include "weights/w21.h"
#include "weights/s22.h"
#include "weights/b22.h"
#include "weights/w24.h"
#include "weights/s25.h"
#include "weights/b25.h"
#include "weights/w28.h"
#include "weights/s29.h"
#include "weights/b29.h"
#include "weights/w31.h"
#include "weights/b31.h"
#include "weights/s32.h"
#include "weights/b32.h"
#include "weights/w34.h"
#include "weights/s35.h"
#include "weights/b35.h"
#include "weights/w38.h"
#include "weights/b38.h"
#include "weights/s39.h"
#include "weights/b39.h"
#include "weights/w41.h"
#include "weights/s42.h"
#include "weights/b42.h"
#include "weights/w44.h"
#include "weights/s45.h"
#include "weights/b45.h"
#include "weights/w46.h"
#include "weights/s47.h"
#include "weights/b47.h"
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
#include "weights/w154.h"
#include "weights/s155.h"
#include "weights/b155.h"
#include "weights/w157.h"
#include "weights/s158.h"
#include "weights/b158.h"
#include "weights/w160.h"
#include "weights/s161.h"
#include "weights/b161.h"
#include "weights/w164.h"
#include "weights/s165.h"
#include "weights/b165.h"
#include "weights/w167.h"
#include "weights/s168.h"
#include "weights/b168.h"
#include "weights/w170.h"
#include "weights/s171.h"
#include "weights/b171.h"
#include "weights/w175.h"
#include "weights/b175.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_175]) { 
  #ifndef __SYNTHESIS__
  static bool loaded_weights = false;
  if (!loaded_weights) {
        nnet::load_weights_from_txt<model_default_t, 2048000>(w175, "w175.txt");
        nnet::load_weights_from_txt<model_default_t, 1000>(b175, "b175.txt");
        loaded_weights = true;
  }
  #endif
  hls::stream<input_t>   sInput  [N_INPUT_3_1];
  hls::stream<result_t>  sOutput [N_FILT_170];
  layer170_t layer175_full[N_FILT_170];
  #pragma HLS ARRAY_RESHAPE variable=layer7_full block factor=64
  #pragma HLS stream variable=sInput      depth=1
  #pragma HLS stream variable=sOutput     depth=1
  bool lReset = true;
  unsigned iX = 0; 
  unsigned iY = 0; 
  for(unsigned i0 = 0; i0 < N_INPUT_1_1_LARGE; i0++) { 
    for(unsigned i1 = 0; i1 < N_INPUT_2_1; i1++) { 
      for(unsigned i2 = 0; i2 < N_INPUT_3_1; i2++) { 
          #pragma HLS UNROLL
	if(i0*N_INPUT_2_1+i1 < N_INPUT_1_1*N_INPUT_1_1) { 
	  std::cout << "===>  in " << i0 << " -- " << i1 << " -- " << i2 << " -- " << input[i0][i1][i2] << std::endl;
	  sInput[i2].write(input[i0][i1][i2]);
	} else { 
	  input_t pVal = 0;
	  sInput[i2].write(pVal);
	} 
      }
      subimage_stream(lReset,sInput,sOutput);
      lReset = false;
      if(!sOutput[0].empty()) { //it all gets shrunk to one single output
	for(unsigned i2 = 0; i2 < N_FILT_170; i2++) { 
         #pragma HLS UNROLL
         layer175_full[i2] = sOutput[i2].read();
	}
	break;
      }
    }
    std::cout << "---> counters " << i0 << std::endl;
  }
  layer175_t layer175_out[N_LAYER_175];
  #pragma HLS ARRAY_PARTITION variable=layer175_out complete dim=0
  nnet::dense_large<layer170_t, layer175_t, config175>(layer175_full, layer175_out, w175, b175);
  nnet::softmax<layer175_t, result_t, softmax_config176>(layer175_out, output);
  std::cout << "=========> Final Result " << std::endl;
  for(int i0 = 0; i0 < N_LAYER_175; i0++) { 
    std::cout << "====> " << i0 << " -- " << output[i0] << std::endl;
  }
  std::cout << "=======> Done " << std::endl;
}

void subimage_stream(bool iReset, 
	      hls::stream<input_t>    input[N_INPUT_3_1],
	      hls::stream<layer170_t> output[N_FILT_170]) { 
  
       #pragma HLS DATAFLOW

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 9408>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s3, "s3.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b3, "b3.txt");
        nnet::load_weights_from_txt<model_default_t, 4096>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s7, "s7.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b7, "b7.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w9, "w9.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s10, "s10.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b10, "b10.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w12, "w12.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s13, "s13.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b13, "b13.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w14, "w14.txt");
	nnet::load_weights_from_txt<model_default_t, 256>(s15, "s15.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b15, "b15.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w18, "w18.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s19, "s19.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b19, "b19.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w21, "w21.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s22, "s22.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b22, "b22.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w24, "w24.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s25, "s25.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b25, "b25.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w28, "w28.txt");
	nnet::load_weights_from_txt<model_default_t, 64>(s29, "s29.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b29, "b29.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w31, "w31.txt");
	nnet::load_weights_from_txt<model_default_t, 64>(s32, "s32.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b32, "b32.txt");
        nnet::load_weights_from_txt<model_default_t, 16384>(w34, "w34.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s35, "s35.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b35, "b35.txt");
        nnet::load_weights_from_txt<model_default_t, 32768>(w38, "w38.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s39, "s39.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b39, "b39.txt");
	nnet::load_weights_from_txt<model_default_t, 147456>(w41, "w41.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s42, "s42.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b42, "b42.txt");
	nnet::load_weights_from_txt<model_default_t, 147456>(w41, "w41.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s42, "s42.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b42, "b42.txt");
        nnet::load_weights_from_txt<model_default_t, 65536>(w44, "w44.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s45, "s45.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b45, "b45.txt");
        nnet::load_weights_from_txt<model_default_t, 131072>(w46, "w46.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s47, "s47.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b47, "b47.txt");
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
        nnet::load_weights_from_txt<model_default_t, 1048576>(w154, "w154.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s155, "s155.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b155, "b155.txt");
        nnet::load_weights_from_txt<model_default_t, 2359296>(w157, "w157.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s158, "s158.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b158, "b158.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w160, "w160.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s161, "s161.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b161, "b161.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w164, "w164.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s165, "s165.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b165, "b165.txt");
        nnet::load_weights_from_txt<model_default_t, 2359296>(w167, "w167.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(s168, "s168.txt");
        nnet::load_weights_from_txt<model_default_t, 512>(b168, "b168.txt");
        nnet::load_weights_from_txt<model_default_t, 1048576>(w170, "w170.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(s171, "s171.txt");
        nnet::load_weights_from_txt<model_default_t, 2048>(b171, "b171.txt");
        loaded_weights = true;
    }
#endif

    static hls::stream<layer2_t> layer2_out[N_FILT_2];
    #pragma HLS stream variable=layer2_out      depth=1
    if(!input[0].empty()) nnet::conv_2d_large_stream_norm_nobias<input_t,layer2_t,config2>(iReset,input,layer2_out,w2,s3,b3);
        
    static hls::stream<layer5_t> layer5_out[N_FILT_5];
    #pragma HLS stream variable=layer5_out      depth=1
    if(!layer2_out[0].empty()) nnet::pool_2d_large_stream<layer2_t,layer5_t,config5>(layer2_out,layer5_out);

    static hls::stream<layer5_t>  layer6_in1[N_FILT_5];
    static hls::stream<layer5_t>  layer6_in2[N_FILT_5];
    #pragma HLS stream variable=layer6_in1      depth=1
    #pragma HLS stream variable=layer6_in2      depth=1
    if(!layer5_out[0].empty()) nnet::split<layer5_t,layer5_t,config6>(layer5_out,layer6_in1,layer6_in2);

    static hls::stream<layer14_t> layer14_out[N_FILT_14];
    #pragma HLS stream variable=layer14_out      depth=1
    if(!layer6_in2[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer6_t,layer14_t,config14>(iReset,layer6_in2,layer14_out,w14,s15,b15);

    static hls::stream<layer6_t> layer6_out[N_FILT_6];
    #pragma HLS stream variable=layer6_out      depth=1
    if(!layer6_in1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer5_t,layer6_t,config6>(iReset,layer6_in1,layer6_out,w6,s7,b7);

    static hls::stream<layer9_t> layer9_out[N_FILT_9];
    #pragma HLS stream variable=layer9_out      depth=1
    if(!layer6_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer6_t,layer9_t,config9>(iReset,layer6_out,layer9_out,w9,s10,b10);

    static hls::stream<layer12_t> layer12_out[N_FILT_12];
    #pragma HLS stream variable=layer12_out      depth=1
    if(!layer9_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer9_t,layer12_t,config12>(iReset,layer9_out,layer12_out,w12,s13,b13);

    static hls::stream<layer14_t> layer14_out2[N_FILT_14];
    #pragma HLS stream variable=layer14_out2      depth=1
    if(!layer12_out[0].empty() && !layer14_out[0].empty()) nnet::addrelu<layer12_t,layer14_t,config14>(layer12_out,layer14_out,layer14_out2);

    static hls::stream<layer18_t>  layer18_in1[N_FILT_14];
    static hls::stream<layer18_t>  layer18_in2[N_FILT_14];
    #pragma HLS stream variable=layer18_in1      depth=1
    #pragma HLS stream variable=layer18_in2      depth=1
    if(!layer14_out2[0].empty()) nnet::split<layer14_t,layer18_t,config18>(layer14_out2,layer18_in1,layer18_in2);

    static hls::stream<layer18_t> layer18_out[N_FILT_18];
    #pragma HLS stream variable=layer18_out      depth=1
    if(!layer18_in1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer14_t,layer18_t,config18>(iReset,layer18_in1,layer18_out,w18,s19,b19);

    static hls::stream<layer21_t> layer21_out[N_FILT_21];
    #pragma HLS stream variable=layer21_out      depth=1
    if(!layer18_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer18_t,layer21_t,config21>(iReset,layer18_out,layer21_out,w21,s22,b22);

    static hls::stream<layer24_t> layer24_out[N_FILT_24];
    #pragma HLS stream variable=layer24_out      depth=1
    if(!layer21_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer21_t,layer24_t,config24>(iReset,layer21_out,layer24_out,w24,s25,b25);

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
    if(!layer28_in1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer24_t,layer28_t,config28>(iReset,layer28_in1,layer28_out,w28,s29,b29);

    static hls::stream<layer31_t> layer31_out[N_FILT_31];
    #pragma HLS stream variable=layer31_out      depth=1
    if(!layer28_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer28_t,layer31_t,config31>(iReset,layer28_out,layer31_out,w31,s32,b32);

    static hls::stream<layer34_t> layer34_out[N_FILT_34];
    #pragma HLS stream variable=layer34_out      depth=1
    if(!layer31_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer31_t,layer34_t,config34>(iReset,layer31_out,layer34_out,w34,s35,b35);
    
    static hls::stream<layer34_t> layer34_out2[N_FILT_34];
    #pragma HLS stream variable=layer34_out2      depth=1
    if(!layer28_in2[0].empty() && !layer34_out[0].empty()) nnet::addrelu<layer34_t,layer34_t,config34>(layer28_in2,layer34_out,layer34_out2);


    static hls::stream<layer34_t>  layer34_out3[N_FILT_34];
    static hls::stream<layer34_t>  layer34_out4[N_FILT_34];
    #pragma HLS stream variable=layer34_out3      depth=1
    #pragma HLS stream variable=layer34_out4      depth=1
    if(!layer34_out2[0].empty()) nnet::split<layer34_t,layer34_t,config38>(layer34_out2,layer34_out3,layer34_out4);


    static hls::stream<layer38_t> layer38_out[N_FILT_38];
    #pragma HLS stream variable=layer38_out      depth=1
    if(!layer34_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer34_t,layer38_t,config38>(iReset,layer34_out3,layer38_out,w38,s39,b39);

    static hls::stream<layer41_t> layer41_out[N_FILT_41];
    #pragma HLS stream variable=layer41_out      depth=1
    if(!layer38_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer38_t,layer41_t,config41>(iReset,layer38_out,layer41_out,w41,s42,b42);

    static hls::stream<layer44_t> layer44_out[N_FILT_44];
    #pragma HLS stream variable=layer44_out      depth=1
    if(!layer41_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer41_t,layer44_t,config44>(iReset,layer41_out,layer44_out,w44,s45,b45);

    static hls::stream<layer46_t> layer46_out[N_FILT_46];
    #pragma HLS stream variable=layer46_out      depth=1
    if(!layer34_out4[0].empty()) nnet::conv_2d_large_stream_norm_resnet<layer34_t,layer46_t,config46>(iReset,layer34_out4,layer46_out,w46,s47,b47);

    static hls::stream<layer46_t> layer46_out2[N_FILT_46];
    #pragma HLS stream variable=layer46_out2      depth=1
    if(!layer44_out[0].empty()) nnet::addrelu<layer46_t,layer46_t,config46>(layer44_out,layer46_out,layer46_out2);

    static hls::stream<layer50_t>  layer50_out1[N_FILT_46];
    static hls::stream<layer50_t>  layer50_out2[N_FILT_46];
    #pragma HLS stream variable=layer50_out1      depth=1
    #pragma HLS stream variable=layer50_out2      depth=1
    if(!layer46_out2[0].empty()) nnet::split<layer50_t,layer50_t,config50>(layer46_out2,layer50_out1,layer50_out2);
    
    static hls::stream<layer50_t> layer50_out[N_FILT_50];
    #pragma HLS stream variable=layer50_out      depth=1
    if(!layer50_out1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer50_t,layer50_t,config50>(iReset,layer50_out1,layer50_out,w50,s51,b51);


    static hls::stream<layer53_t> layer53_out[N_FILT_53];
    #pragma HLS stream variable=layer53_out      depth=1
    if(!layer50_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer50_t,layer53_t,config53>(iReset,layer50_out,layer53_out,w53,s54,b54);

    static hls::stream<layer56_t> layer56_out[N_FILT_56];
    #pragma HLS stream variable=layer56_out      depth=1
    if(!layer53_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer53_t,layer56_t,config56>(iReset,layer53_out,layer56_out,w56,s57,b57);

    static hls::stream<layer56_t> layer56_out2[N_FILT_56];
    #pragma HLS stream variable=layer56_out2      depth=1
    if(!layer50_out2[0].empty() && !layer56_out[0].empty()) nnet::addrelu<layer56_t,layer56_t,config56>(layer50_out2,layer56_out,layer56_out2);
    //if(!layer50_out2[0].empty() && !layer56_out[0].empty()) nnet::addrelu<layer56_t,layer56_t,config56>(layer50_out2,layer56_out,output);
 
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

    static hls::stream<layer66_t> layer66_out2[N_FILT_66];
    #pragma HLS stream variable=layer66_out2      depth=1
    if(!layer56_out4[0].empty() && !layer66_out[0].empty()) nnet::addrelu<layer66_t,layer66_t,config66>(layer56_out4,layer66_out,layer66_out2);
    
    static hls::stream<layer66_t>  layer66_out3[N_FILT_66];
    static hls::stream<layer66_t>  layer66_out4[N_FILT_66];
    #pragma HLS stream variable=layer66_out3      depth=1
    #pragma HLS stream variable=layer66_out4      depth=1
    if(!layer66_out2[0].empty()) nnet::split<layer66_t,layer66_t,config70>(layer66_out2,layer66_out3,layer66_out4);

    static hls::stream<layer70_t> layer70_out[N_FILT_70];
    #pragma HLS stream variable=layer70_out      depth=1
    if(!layer66_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer66_t,layer70_t,config70>(iReset,layer66_out3,layer70_out,w70,s71,b71);

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
    if(!layer76_out2[0].empty()) nnet::split<layer76_t,layer76_t,config80>(layer76_out2,layer76_out3,layer76_out4);

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
    if(!layer76_out4[0].empty()) nnet::conv_2d_large_stream_norm_resnet<layer76_t,layer88_t,config88>(iReset,layer76_out4,layer88_out,w88,s89,b89);

    static hls::stream<layer88_t> layer88_out2[N_FILT_88];
    #pragma HLS stream variable=layer88_out2      depth=1
    if(!layer88_out[0].empty() && !layer86_out[0].empty()) nnet::addrelu<layer86_t,layer88_t,config88>(layer86_out,layer88_out,layer88_out2);

    static hls::stream<layer92_t>  layer92_out1[N_FILT_88];
    static hls::stream<layer92_t>  layer92_out2[N_FILT_88];
    #pragma HLS stream variable=layer92_out1      depth=1
    #pragma HLS stream variable=layer92_out2      depth=1
    if(!layer88_out2[0].empty()) nnet::split<layer92_t,layer92_t,config92>(layer88_out2,layer92_out1,layer92_out2);

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
    if(!layer105_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer105_t,layer108_t,config108>(iReset,layer105_out,layer108_out,w108,s109,b109);

    static hls::stream<layer108_t> layer108_out2[N_FILT_108];
    #pragma HLS stream variable=layer108_out2      depth=1
    if(!layer98_out4[0].empty() && !layer108_out[0].empty()) nnet::addrelu<layer108_t,layer108_t,config108>(layer98_out4,layer108_out,layer108_out2);

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

    if(!layer115_out[0].empty())std::cout << " layer 115 !! " << std::endl;

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
    if(!layer118_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer118_t,layer122_t,config122>(iReset,layer118_out3,layer122_out,w122,s123,b123);

    hls::stream<layer125_t> layer125_out[N_FILT_125];
    #pragma HLS stream variable=layer125_out      depth=1
    if(!layer122_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer122_t,layer125_t,config125>(iReset,layer122_out,layer125_out,w125,s126,b126);

    if(!layer125_out[0].empty())std::cout << " layer 125 !! " << std::endl;

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

    if(!layer132_out[0].empty())std::cout << " layer 132 !! " << std::endl;

    hls::stream<layer135_t> layer135_out[N_FILT_135];
    #pragma HLS stream variable=layer135_out      depth=1
    if(!layer132_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer132_t,layer135_t,config135>(iReset,layer132_out,layer135_out,w135,s136,b136);

    hls::stream<layer138_t> layer138_out[N_FILT_138];
    #pragma HLS stream variable=layer138_out      depth=1
    if(!layer135_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer135_t,layer138_t,config138>(iReset,layer135_out,layer138_out,w138,s139,b139);

    static hls::stream<layer138_t> layer138_out2[N_FILT_138];
    #pragma HLS stream variable=layer138_out2      depth=1
    if(!layer128_out4[0].empty() && !layer138_out[0].empty()) nnet::addrelu<layer138_t,layer138_t,config138>(layer128_out4,layer138_out,layer138_out2);

    if(!layer138_out2[0].empty())std::cout << " layer 138 !! " << std::endl;

    static hls::stream<layer138_t>  layer138_out3[N_FILT_138];
    static hls::stream<layer138_t>  layer138_out4[N_FILT_138];
    #pragma HLS stream variable=layer138_out3      depth=1
    #pragma HLS stream variable=layer138_out4      depth=1
    if(!layer138_out2[0].empty()) nnet::split<layer138_t,layer138_t,config142>(layer138_out2,layer138_out3,layer138_out4);

    hls::stream<layer142_t> layer142_out[N_FILT_142];
    #pragma HLS stream variable=layer142_out      depth=1
    if(!layer138_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer138_t,layer142_t,config142>(iReset,layer138_out3,layer142_out,w142,s143,b143);

    if(!layer142_out[0].empty())std::cout << " layer 142 !! " << std::endl;

    hls::stream<layer145_t> layer145_out[N_FILT_145];
    #pragma HLS stream variable=layer145_out      depth=1
    if(!layer142_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer142_t,layer145_t,config145>(iReset,layer142_out,layer145_out,w145,s146,b146);

    if(!layer145_out[0].empty())std::cout << " layer 145 !! " << std::endl;

    hls::stream<layer148_t> layer148_out[N_FILT_148];
    #pragma HLS stream variable=layer148_out      depth=1
    if(!layer145_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer145_t,layer148_t,config148>(iReset,layer145_out,layer148_out,w148,s149,b149);
    //if(!layer145_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer145_t,layer148_t,config148>(iReset,layer145_out,output,w148,s149,b149);
    
    hls::stream<layer150_t> layer150_out[N_FILT_150];
    #pragma HLS stream variable=layer150_out      depth=1
    if(!layer138_out4[0].empty()) nnet::conv_2d_large_stream_norm_resnet<layer138_t,layer150_t,config150>(iReset,layer138_out4,layer150_out,w150,s151,b151);

    if(!layer148_out[0].empty())std::cout << " layer 148 !! " << std::endl;

    static hls::stream<layer150_t> layer150_outM[N_FILT_150];
    #pragma HLS stream variable=layer150_outM      depth=1
    if(!layer148_out[0].empty() && !layer150_out[0].empty()) nnet::addrelu<layer148_t,layer150_t,config150>(layer148_out,layer150_out,layer150_outM);

    if(!layer150_outM[0].empty())std::cout << " layer 150 !! " << std::endl;

    static hls::stream<layer150_t>  layer150_out1[N_FILT_150];
    static hls::stream<layer150_t>  layer150_out2[N_FILT_150];
    #pragma HLS stream variable=layer150_out1      depth=1
    #pragma HLS stream variable=layer150_out2      depth=1
    if(!layer150_outM[0].empty())nnet::split<layer150_t,layer150_t,config154>(layer150_outM,layer150_out1,layer150_out2);

    if(!layer150_out1[0].empty())std::cout << " layer 150-1 !! " << std::endl;

    static hls::stream<layer154_t> layer154_out[N_FILT_154];
    #pragma HLS stream variable=layer154_out      depth=1
    if(!layer150_out1[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer150_t,layer154_t,config154>(iReset,layer150_out1,layer154_out,w154,s155,b155);

    if(!layer154_out[0].empty())std::cout << " layer 154 !! " << std::endl;

    static hls::stream<layer157_t> layer157_out[N_FILT_157];
    #pragma HLS stream variable=layer157_out      depth=1
    if(!layer154_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer154_t,layer157_t,config157>(iReset,layer154_out,layer157_out,w157,s158,b158);

    if(!layer157_out[0].empty())std::cout << " layer 157 !! " << std::endl;

    static hls::stream<layer160_t> layer160_out[N_FILT_160];
    #pragma HLS stream variable=layer160_out      depth=1
    if(!layer157_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer160_t,layer160_t,config160>(iReset,layer157_out,layer160_out,w160,s161,b161);

    static hls::stream<layer160_t> layer160_out2[N_FILT_160];
    #pragma HLS stream variable=layer160_out2      depth=1
    if(!layer150_out2[0].empty() && !layer160_out[0].empty()) nnet::addrelu<layer160_t,layer160_t,config160>(layer150_out2,layer160_out,layer160_out2);

    static hls::stream<layer160_t>  layer160_out3[N_FILT_160];
    static hls::stream<layer160_t>  layer160_out4[N_FILT_160];
    #pragma HLS stream variable=layer160_out3      depth=1
    #pragma HLS stream variable=layer160_out4      depth=1
    if(!layer160_out2[0].empty()) nnet::split<layer160_t,layer160_t,config164>(layer160_out2,layer160_out3,layer160_out4);

    if(!layer160_out3[0].empty())std::cout << " layer 160 !! " << std::endl;

    static hls::stream<layer164_t> layer164_out[N_FILT_164];
    #pragma HLS stream variable=layer164_out      depth=1
    if(!layer160_out3[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer160_t,layer164_t,config164>(iReset,layer160_out3,layer164_out,w164,s165,b165);

    static hls::stream<layer167_t> layer167_out[N_FILT_167];
    #pragma HLS stream variable=layer167_out      depth=1
    if(!layer164_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer164_t,layer167_t,config167>(iReset,layer164_out,layer167_out,w167,s168,b168);

    if(!layer167_out[0].empty())std::cout << " layer 167 !! " << std::endl;

    static hls::stream<layer170_t> layer170_out[N_FILT_170];
    #pragma HLS stream variable=layer170_out      depth=1
    if(!layer167_out[0].empty()) nnet::conv_2d_large_stream_norm_nobias<layer167_t,layer170_t,config170>(iReset,layer167_out,layer170_out,w170,s171,b171);

    if(!layer170_out[0].empty())std::cout << " layer 170 !! " << std::endl;

    static hls::stream<layer170_t> layer170_out2[N_FILT_170];
    #pragma HLS stream variable=layer170_out2      depth=1
    if(!layer160_out4[0].empty() && !layer170_out[0].empty()) nnet::addrelu<layer170_t,layer170_t,config170>(layer160_out4,layer170_out,layer170_out2);

    if(!layer170_out2[0].empty())std::cout << " layer 170-f !! " << std::endl;

    //hls::stream<layer5_t> layer5_out[N_FILT_5];
    //#pragma HLS stream variable=layer5_out      depth=1
    if(!layer170_out2[0].empty()) nnet::pool_2d_large_stream_funnel<layer170_t,layer170_t,config174>(iReset, layer170_out2,output);
}

