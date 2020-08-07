#include "myproject_full_layer2_stream.h"

#include "weights/b103.h"
#include "weights/s103.h"
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/s4.h"
#include "weights/b4.h"
#include "weights/w7.h"
#include "weights/b7.h"
#include "weights/s9.h"
#include "weights/b9.h"
#include "weights/w11.h"
#include "weights/b11.h"
#include "weights/s13.h"
#include "weights/b13.h"
/*
#include "weights/w16.h"
#include "weights/b16.h"
#include "weights/s18.h"
#include "weights/b18.h"
#include "weights/w20.h"
#include "weights/b20.h"
#include "weights/s22.h"
#include "weights/b22.h"
#include "weights/w25.h"
#include "weights/b25.h"
#include "weights/s27.h"
#include "weights/b27.h"
//#include "weights/w29.h"
#include "weights/b29.h"
#include "weights/s31.h"
#include "weights/b31.h"
//#include "weights/w34.h"
#include "weights/b34.h"
#include "weights/s36.h"
#include "weights/b36.h"
// #include "weights/w38.h"
#include "weights/b38.h"
#include "weights/s40.h"
#include "weights/b40.h"
// #include "weights/w42.h"
#include "weights/b42.h"
#include "weights/w46.h"
#include "weights/b46.h"
#include "weights/w50.h"
#include "weights/b50.h"
*/

void myproject_full_layer2_stream_in(
				  hls::stream<input_t> em_barrel[N_INPUT_3_1]
				  , hls::stream<result_t> layer52_out[N_LAYER_50_short]
				  , model_default_t w29[147456]
				  , model_default_t w34[294912]
				  , model_default_t w38[589824]
				  , model_default_t w42[589824]
				  ) {
    #pragma HLS interface bram port=w29,w34,w38,w42
    #pragma HLS INTERFACE axis port=em_barrel,layer52_out
    #pragma HLS DATAFLOW 
    static const input_t alpha = 0.3;

    #ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
    //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 4>(s103, "s103.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b103, "b103.txt");
        nnet::load_weights_from_txt<model_default_t, 1600>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 16>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 16>(s4, "s4.txt");
        nnet::load_weights_from_txt<model_default_t, 16>(b4, "b4.txt");
	nnet::load_weights_from_txt<model_default_t, 4608>(w7, "w7.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b7, "b7.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(s9, "s9.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b9, "b9.txt");
        nnet::load_weights_from_txt<model_default_t, 9216>(w11, "w11.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b11, "b11.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(s13, "s13.txt");
        nnet::load_weights_from_txt<model_default_t, 32>(b13, "b13.txt");
	/*
        nnet::load_weights_from_txt<model_default_t, 18432>(w16, "w16.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b16, "b16.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s18, "s18.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b18, "b18.txt");
        nnet::load_weights_from_txt<model_default_t, 36864>(w20, "w20.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b20, "b20.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(s22, "s22.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b22, "b22.txt");
        nnet::load_weights_from_txt<model_default_t, 73728>(w25, "w25.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b25, "b25.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s27, "s27.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b27, "b27.txt");
        nnet::load_weights_from_txt<model_default_t, 147456>(w29, "w29.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b29, "b29.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(s31, "s31.txt");
        nnet::load_weights_from_txt<model_default_t, 128>(b31, "b31.txt");
        nnet::load_weights_from_txt<model_default_t, 294912>(w34, "w34.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b34, "b34.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s36, "s36.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b36, "b36.txt");
        nnet::load_weights_from_txt<model_default_t, 589824>(w38, "w38.txt"); // Pass in explicitly as a bram
        nnet::load_weights_from_txt<model_default_t, 256>(b38, "b38.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(s40, "s40.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(b40, "b40.txt"); // Pass in explicitly as a bram
	nnet::load_weights_from_txt<model_default_t, 589824>(w42, "w42.txt");
	nnet::load_weights_from_txt<bias42_t, 256>(b42, "b42.txt");
	nnet::load_weights_from_txt<model_default_t, 65536>(w46, "w46.txt");
	nnet::load_weights_from_txt<bias46_t, 256>(b46, "b46.txt");
	nnet::load_weights_from_txt<model_default_t, 256>(w50, "w50.txt");
	nnet::load_weights_from_txt<model_default_t, 1>(b50, "b50.txt");
	*/
	nnet::load_weights_from_txt<model_default_t, 4>(s103, "s103.txt");
	nnet::load_weights_from_txt<model_default_t, 4>(b103, "b103.txt");
	loaded_weights = true;
    }
    #endif

    static hls::stream<layer102_t> layer102_out[N_CHANNEL_102];
    #pragma HLS STREAM variable=layer102_out depth=5
    if(!em_barrel[0].empty()) nnet::upsampling2d_stream<input_t, layer102_t, config102>(em_barrel, layer102_out);
   
    static hls::stream<layer103_t> layer103_out[N_CHANNEL_102];
    #pragma HLS STREAM variable=layer103_out depth=20
    while(!layer102_out[0].empty()) nnet::normalize_stream<layer102_t, layer103_t, config103>(layer102_out, layer103_out, s103, b103);

    static hls::stream<layer2_t> layer2_out[N_FILT_2];
    //#pragma HLS STREAM variable=layer2_out depth=(config2::pad_right+1+config2::pad_bottom*(config2::out_width+config2::pad_right))
    #pragma HLS STREAM variable=layer2_out depth=140
    while(!layer103_out[0].empty()) nnet::conv_2d_large_cl_stream<input_t,layer2_t,config2>(layer103_out,layer2_out,w2,b2,s4,b4,alpha);

    static hls::stream<layer6_t> layer6_out[N_FILT_6];
    //#pragma HLS STREAM variable=layer6_out depth=(config6::pad_right+1+config6::pad_bottom*(config6::out_width+config6::pad_right))
    #pragma HLS stream variable=layer6_out      depth=140
    while(!layer2_out[0].empty()) nnet::pooling2d_cl<layer2_t, layer6_t, config6>(layer2_out,layer6_out);

    static hls::stream<layer7_t> layer7_out[N_FILT_7];
    #pragma HLS stream variable=layer7_out      depth=70
    //#pragma HLS STREAM variable=layer6_out depth=(config7::pad_right+1+config7::pad_bottom*(config7::out_width+config7::pad_right))
    while(!layer6_out[0].empty()) nnet::conv_2d_large_cl_stream<layer6_t,layer2_t,config7>(layer6_out,layer7_out,w7,b7,s9,b9,alpha);

    static hls::stream<layer11_t> layer11_out[N_FILT_11];
    #pragma HLS stream variable=layer11_out      depth=10
    //#pragma HLS STREAM variable=layer6_out depth=(config11::pad_right+1+config11::pad_bottom*(config11::out_width+config11::pad_right))
    //if(!layer7_out[0].empty())  nnet::conv_2d_large_cl_stream<layer7_t,layer11_t,config11>(layer7_out,layer11_out,w11,b11,s13,b13,alpha);
    while(!layer7_out[0].empty())  nnet::conv_2d_large_cl_stream<layer7_t,layer11_t,config11>(layer7_out,layer52_out,w11,b11,s13,b13,alpha);
    
    /*
    static hls::stream<layer15_t> layer15_out[N_FILT_15];
    #pragma HLS stream variable=layer15_out      depth=60
    while(!layer11_out[0].empty()) nnet::pooling2d_cl<layer11_t,layer15_t,config15>(layer11_out,layer15_out);

    static hls::stream<layer16_t> layer16_out[N_FILT_16];
    #pragma HLS stream variable=layer16_out      depth=30
    while(!layer15_out[0].empty()) nnet::conv_2d_large_cl_stream<layer15_t,layer16_t,config16>(layer15_out,layer16_out,w16,b16,s18,b18,alpha);

    static hls::stream<layer20_t> layer20_out[N_FILT_20];
    #pragma HLS stream variable=layer20_out      depth=18
    while(!layer16_out[0].empty()) nnet::conv_2d_large_cl_stream<layer16_t,layer20_t,config20>(layer16_out,layer20_out,w20,b20,s22,b22,alpha);

    static hls::stream<layer24_t> layer24_out[N_FILT_24];
    #pragma HLS stream variable=layer24_out      depth=10
    while(!layer20_out[0].empty()) nnet::pooling2d_cl<layer20_t,layer24_t,config24>(layer20_out,layer24_out);

    static hls::stream<layer25_t> layer25_out[N_FILT_25];
    #pragma HLS stream variable=layer25_out      depth=10
    while(!layer24_out[0].empty()) nnet::conv_2d_large_cl_stream<layer24_t,layer25_t,config25>(layer24_out,layer25_out,w25,b25,s27,b27,alpha);

    static hls::stream<layer29_t> layer29_out[N_FILT_29];
    #pragma HLS stream variable=layer29_out      depth=10
    while(!layer25_out[0].empty()) nnet::conv_2d_large_cl_stream<layer25_t,layer29_t,config29>(layer25_out,layer29_out,w29,b29,s31,b31,alpha);

    static hls::stream<layer33_t> layer33_out[N_FILT_33];
    #pragma HLS stream variable=layer33_out      depth=10
    while(!layer29_out[0].empty()) nnet::pooling2d_cl<layer29_t,layer33_t,config33>(layer29_out,layer33_out);

    static hls::stream<layer34_t> layer34_out[N_FILT_34];
    #pragma HLS stream variable=layer34_out      depth=10
    while(!layer33_out[0].empty()) nnet::conv_2d_large_cl_stream<layer33_t,layer34_t,config34>(layer33_out,layer34_out,w34,b34,s36,b36,alpha);
    
    static hls::stream<layer38_t> layer38_out[N_FILT_38];
    #pragma HLS stream variable=layer38_out      depth=10
    while(!layer34_out[0].empty())  nnet::conv_2d_large_cl_stream<layer34_t,layer38_t,config38>(layer34_out,layer38_out,w38,b38,s40,b40,alpha);
    //if(!em_barrel[0].empty())  nnet::conv_2d_large_cl_stream<layer34_t,layer38_t,config38>(em_barrel,layer38_out,w38,b38,s40,b40,alpha);

    static unsigned pX = 0;
    layer41_t layer41_out[OUT_WIDTH_38*OUT_HEIGHT_38*(N_FILT_38-1)];
    #pragma HLS ARRAY_PARTITION variable=layer41_out block factor=256
    if(!layer38_out[0].empty()) { 
      layer38_t pStatus = layer38_out[0].read();
      for(unsigned i0 = 0; i0 < N_FILT_38-1; i0++) { 
	#pragma HLS UNROLL
	layer38_t pRead = layer38_out[i0-1].read();
	layer41_out[pX*(N_FILT_38-1)+i0] = pRead;
      }
      pX = pX+1;
      //if(pX == OUT_WIDTH_38*OUT_HEIGHT_38 || pStatus == 0) pX = 0;
    }
    if(pX == OUT_WIDTH_38*OUT_HEIGHT_38) { 
      //dense layers
      layer42_t layer42_out[N_LAYER_42];
      #pragma HLS ARRAY_PARTITION variable=layer42_out complete dim=0
      nnet::dense_large<layer41_t, layer42_t, config42>(layer41_out, layer42_out, w42, b42);

      layer45_t layer45_out[N_LAYER_42];
      #pragma HLS ARRAY_PARTITION variable=layer45_out complete dim=0
      nnet::leaky_relu<layer42_t, layer45_t, LeakyReLU_config45>(layer42_out,alpha, layer45_out);

      layer46_t layer46_out[N_LAYER_46];
      #pragma HLS ARRAY_PARTITION variable=layer46_out complete dim=0
      nnet::dense_large<layer45_t, layer46_t, config46>(layer45_out, layer46_out, w46, b46);

      layer49_t layer49_out[N_LAYER_46];
      #pragma HLS ARRAY_PARTITION variable=layer49_out complete dim=0
      nnet::leaky_relu<layer46_t, layer49_t, LeakyReLU_config49>(layer46_out,alpha, layer49_out);

      layer50_t layer50_out[N_LAYER_50];
      #pragma HLS ARRAY_PARTITION variable=layer50_out complete dim=0
      nnet::dense_large<layer49_t, layer50_t, config50>(layer49_out, layer50_out, w50, b50);

      result_t layer52_outf[N_LAYER_50];
      #pragma HLS ARRAY_PARTITION variable=layer52_outf complete dim=0
      nnet::relu<layer50_t, result_t, relu_config52>(layer50_out, layer52_outf);

      for(unsigned i2 = 0; i2 < N_LAYER_50; i2++) { 
	result_t pTmp = layer52_outf[i2];
	layer52_out[i2].write(pTmp); 
      }
      pX = 0;
    }
    */
}

template<typename DATA_T, int SIZE, int LEN_STR>
void read_array_to_stream(hls::stream<DATA_T> out_str[SIZE], DATA_T in_arr[LEN_STR*SIZE]) {
    
    for (int i = 0; i < LEN_STR; i++) {
        #pragma HLS PIPELINE II=1
        for (int j = 0; j < SIZE; j++) {
            out_str[j] << in_arr[i][j];
        }
    }
}

template<typename DATA_T, int SIZE, int LEN_STR>
void write_stream_to_array(DATA_T out_arr[LEN_STR*SIZE], hls::stream<DATA_T> in_str[SIZE]) {

    for (int i = 0; i < LEN_STR; i++) {
        #pragma HLS PIPELINE II=1
        for (int j = 0; j < SIZE; j++) {
            out_arr[i][j] = in_str[j].read();
        }
    }
}

void myproject_full_layer2_stream(
				  //input_t em_barrel[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1]
				  //, result_t layer52_out[OUT_HEIGHT_7*OUT_WIDTH_7*N_LAYER_50_short]
				  hls::stream<input_t> em_barrel[N_INPUT_3_1]
				  , hls::stream<result_t> layer52_out[N_LAYER_50_short]
				  , model_default_t w29[147456]
				  , model_default_t w34[294912]
				  , model_default_t w38[589824]
				  , model_default_t w42[589824]
				  ) {


  //#pragma HLS DATAFLOW
  for(unsigned iY = 0; iY < N_INPUT_1_1; iY++) { 
    for(unsigned iX = 0; iX < N_INPUT_2_1; iX++) { 
      //hls::stream<input_t> in_buf[N_INPUT_3_1];
      //hls::stream<result_t> out_buf[N_LAYER_50_short];
      //#pragma HLS STREAM variable=in_buf  depth=1232 //616
      //#pragma HLS STREAM variable=out_buf depth=1512 //756
      //read_array_to_stream<input_t, N_INPUT_3_1, N_INPUT_1_1*N_INPUT_2_1>(in_buf, em_barrel);
      myproject_full_layer2_stream_in(em_barrel,layer52_out,w29,w34,w38,w42);
      //write_stream_to_array<input_t, N_LAYER_50_short, OUT_HEIGHT_7*OUT_WIDTH_7>(layer52_out, out_buf);
    }
  }
  //std::cout << "===> test " << em_barrel[0].empty() << " -- " << std::endl;
}
