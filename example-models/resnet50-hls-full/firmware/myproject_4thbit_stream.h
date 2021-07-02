#ifndef MYPROJECT_4THBITSTREAM_H_
#define MYPROJECT_4THBITSTREAM_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

#include "parameters_4thbit.h"

void subimage(      
	      input_t input[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1],
	      result_t output[N_LAYER_OUT_1][N_LAYER_OUT_2][N_LAYER_OUT_3],
	      hls::stream<model_default_t> w154[512],
	      hls::stream<model_default_t> w157[512],
	      hls::stream<model_default_t> w160[512],
	      hls::stream<model_default_t> w164[512],
	      hls::stream<model_default_t> w167[512],
	      hls::stream<model_default_t> w170[512]);

void subimage_stream(bool iReset,
		     hls::stream<input_t>  input[N_INPUT_3_1],
		     hls::stream<result_t> output[N_FILT_170],
		     hls::stream<model_default_t> w154[512],
		     hls::stream<model_default_t> w157[512],
		     hls::stream<model_default_t> w160[512],
		     hls::stream<model_default_t> w164[512],
		     hls::stream<model_default_t> w167[512],
		     hls::stream<model_default_t> w170[512]);

#endif
