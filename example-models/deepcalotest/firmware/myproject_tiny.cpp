#include "myproject_tiny.h"

void myproject_full_layer2_stream_in(
				  hls::stream<input_t> em_barrel[N_INPUT_3_1]
				  , hls::stream<result_t> layer52_out[N_LAYER_50]
				  , model_default_t w29[147456]
				  , model_default_t w34[294912]
				  , model_default_t w38[589824]
				  , model_default_t w42[589824]
				  ) {
    #pragma HLS interface bram port=w29,w34,w38,w42
    #pragma HLS INTERFACE axis port=em_barrel,layer52_out
    #pragma HLS DATAFLOW 

    int outi = 0;
    if(!em_barrel[0].empty()) {
        for (int il = 0; il < N_INPUT_3_1; il++) {
            #pragma HLS LOOP UNROLL
            result_t tmp_mult = (em_barrel[il].read())*w29[(il+outi)%147456];
            layer52_out[(il+outi)%N_LAYER_50].write(tmp_mult);
        }
        outi = outi + N_INPUT_3_1;
        if (outi >= 147456) outi = outi - 147456;
    }
}

void myproject_full_layer2_stream(
				  hls::stream<input_t> em_barrel[N_INPUT_3_1]
				  , hls::stream<result_t> layer52_out[N_LAYER_50]
				  , model_default_t w29[147456]
				  , model_default_t w34[294912]
				  , model_default_t w38[589824]
				  , model_default_t w42[589824]
				  ) {

  for(unsigned iY = 0; iY < N_INPUT_1_1; iY++) { 
    for(unsigned iX = 0; iX < N_INPUT_2_1; iX++) { 
      myproject_full_layer2_stream_in(em_barrel,layer52_out,w29,w34,w38,w42);
    }
  }
  std::cout << "===> test " << em_barrel[0].empty() << " -- " << std::endl;
}
