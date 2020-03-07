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

#include "myproject_smalllayer.h"

//#include "weights/w167.h"
//#include "weights/b167.h"


void subimage(bool iReset,
	      hls::stream<input_t>  input[N_INPUT_3_1],
	      hls::stream<result_t> output[N_LAYER_OUT_3],
	      hls::stream<model_default_t> w41[config41::mult_config::n_out]) {  
      //#pragma HLS resource core=AXI4Stream variable=w41
      if(!input[0].empty()) nnet::conv_2d_large_stream_norm_nobias<input_t,result_t,config41>(input,output,w41);
}


