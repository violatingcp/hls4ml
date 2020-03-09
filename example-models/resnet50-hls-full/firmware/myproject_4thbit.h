#ifndef MYPROJECT_4THBIT_H_
#define MYPROJECT_4THBIT_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"

#include "parameters_4thbit.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3]);
/*
	      model_default_t w154[1048576],
	      model_default_t w157[2359296],
	      model_default_t w160[1048576],
	      model_default_t w164[1048576],
	      model_default_t w167[2359296],
	      model_default_t w170[1048576]);
*/
void subimage_stream(bool iReset,
		     hls::stream<input_t>  input[N_INPUT_3_1],
		     hls::stream<result_t> output[N_FILT_170]);
/*
		     model_default_t w154[1048576],
		     model_default_t w157[2359296],
		     model_default_t w160[1048576],
		     model_default_t w164[1048576],
		     model_default_t w167[2359296],
		     model_default_t w170[1048576]);
*/
#endif
