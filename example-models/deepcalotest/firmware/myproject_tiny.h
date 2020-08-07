#ifndef MYPROJECT_H_
#define MYPROJECT_H_

#include <iostream>
#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"

#include "parameters.h"

// Prototype of top level function for C-synthesis
void myproject_full_layer2_stream(
				  //input_t em_barrel[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1]
				  //, result_t layer52_out[OUT_HEIGHT_7*OUT_WIDTH_7*N_LAYER_50_short]
				  hls::stream<input_t> em_barrel[N_INPUT_3_1]
				  , hls::stream<result_t> layer52_out[N_LAYER_50]
				  , model_default_t w29[147456]
				  , model_default_t w34[294912]
				  , model_default_t w38[589824]
				  , model_default_t w42[589824] 
				  );


#endif
