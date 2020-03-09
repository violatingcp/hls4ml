//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
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

#ifndef MYPROJECTBIGLAYER_H_
#define MYPROJECTBIGLAYER_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"

#include "parameters_smalllayer.h"


void subimage(bool iReset,
	      hls::stream<input_t> input[N_INPUT_3_1],
	      hls::stream<result_t> layer41_out[N_LAYER_OUT_3],
	      model_default_t weights[config41::mult_config::n_in*config41::mult_config::n_out]);

#endif
