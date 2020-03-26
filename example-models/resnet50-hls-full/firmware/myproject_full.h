#ifndef MYPROJECT_FULL_H_
#define MYPROJECT_FULL_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"

#include "parameters_full.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_175]);

void subimage_stream(bool iReset,
		     hls::stream<input_t>  input[N_INPUT_3_1],
		     hls::stream<result_t> layer170_out[N_FILT_170]);
#endif
