#ifndef MYPROJECT_3RDBIT_H_
#define MYPROJECT_3RDBIT_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"

#include "parameters_3rdbit.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]);

void subimage_stream(bool iReset,
		     hls::stream<input_t>  input[N_INPUT_3_1],
		     hls::stream<result_t> output[N_FILT_150]);
#endif
