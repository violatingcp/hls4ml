#ifndef NNET_CONV2D_LARGE_H_
#define NNET_CONV2D_LARGE_H_

#include "ap_shift_reg.h"
#include "nnet_activation.h"
#include "nnet_common.h"
#include "nnet_batchnorm.h"
#include "nnet_conv2d.h"
#include "nnet_dense_large.h"

namespace nnet {

//Fills the temporary array to be fed in the CNN
template<class data_T, class res_T, typename CONFIG_T>
  void reset_down(unsigned iY,
		  data_T input[CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right][CONFIG_T::filt_height][CONFIG_T::n_chan],
		  res_T  data [CONFIG_T::filt_width*CONFIG_T::filt_height*CONFIG_T::n_chan]) { 
  static const unsigned lW = CONFIG_T::n_chan;
  static const unsigned lH = CONFIG_T::filt_width*CONFIG_T::n_chan;
  unsigned lY              = iY-(CONFIG_T::filt_height-1)+CONFIG_T::pad_top;// *CONFIG_T::stride_height;

  //Shift register by image height
  #pragma HLS PIPELINE
  for(int i0 = CONFIG_T::pad_left+1; i0 < CONFIG_T::filt_width; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      unsigned pYC = (i1+lY) % CONFIG_T::filt_height;
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*lH+i0*lW+i2] = input[i0-1][pYC][i2];
      }
    }
  }
  for(int i0 = 0; i0 < CONFIG_T::pad_left+1; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*lH+i0*lW+i2] = 0;
      }
    }
  }
}
//with stride
template<class data_T, typename CONFIG_T>
  void shift_right(data_T  data[CONFIG_T::filt_width   * CONFIG_T::n_chan]) { 
  
  //Shift register by feature
  static const int filt_width = CONFIG_T::filt_width-1;//CONFIG_T::stride_width;
  for(int i0 = 0; i0 < filt_width; i0++) { 
    #pragma HLS PIPELINE II=1
    for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
     data[i0*CONFIG_T::n_chan+i2] = data[(i0+1)*CONFIG_T::n_chan+i2];
    }
  }
}
//with stride
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_small_stride(//To be fixed with stride
			      data_T input[CONFIG_T::stride_width][CONFIG_T::filt_height][CONFIG_T::n_chan],
			      res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) { 
  
  //Shift register by image height
  static const int filt_width = CONFIG_T::filt_width-CONFIG_T::stride_width;
  for(int i0 = 0; i0 < filt_width; i0++) { 
    #pragma HLS PIPELINE II=1
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*CONFIG_T::filt_width*CONFIG_T::n_chan+i0*CONFIG_T::n_chan+i2] = data[i1*CONFIG_T::filt_width*CONFIG_T::n_chan+(i0+1)*CONFIG_T::n_chan+i2];
      }
    }
  }
  static const int lastheight=(CONFIG_T::filt_width-CONFIG_T::stride_width)*CONFIG_T::n_chan;
  for(int i0 = 0; i0 < CONFIG_T::stride_width; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
     #pragma HLS UNROLL
     for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
       data[lastheight+i1*CONFIG_T::filt_width*CONFIG_T::n_chan+i0*CONFIG_T::n_chan+i2] = input[i0][i1][i2];
     }
    }
  }
}
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_stride(unsigned iShiftX,unsigned iShiftY,
			data_T input[CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right][CONFIG_T::filt_height][CONFIG_T::n_chan],
			res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) { 
  #pragma HLS PIPELINE
  unsigned lShiftX = iShiftX*CONFIG_T::stride_width;
  unsigned lShiftY = iShiftY*CONFIG_T::stride_height-CONFIG_T::filt_height+1;
  static const unsigned minwidth  = CONFIG_T::pad_left;
  static const unsigned maxwidth  = CONFIG_T::pad_left+CONFIG_T::in_width;
  static const unsigned minheight = CONFIG_T::pad_top;
  static const unsigned maxheight = CONFIG_T::pad_top+CONFIG_T::in_height;
  data_T tmpinput[CONFIG_T::stride_width][CONFIG_T::filt_height][CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
  for(unsigned i0 = 0; i0 < CONFIG_T::stride_width;  i0++) {
    int pX = i0+lShiftX;
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      int pY  = i1+lShiftY;
      unsigned pYC = pY % CONFIG_T::filt_height; 
      for(unsigned i2 = 0; i2 < CONFIG_T::n_chan;    i2++) { 
	if(pX >= minwidth && pX < maxwidth && pY >= minheight && pY < maxheight) { 
	  tmpinput[i0][i1][i2] = input[pX][pYC][i2];
	} else { 
	  tmpinput[i0][i1][i2] = 0;
	}
      }
    } 
  }
  shift_right_small_stride<data_T,res_T,CONFIG_T>(tmpinput,data);
}

template<class data_T, class res_T, typename CONFIG_T>
  void fill_image(
		  data_T input[CONFIG_T::n_filt],
		  hls::stream<res_T>  data [CONFIG_T::n_filt]) { //CONFIG_T::n_filt2
  #pragma HLS PIPELINE
  for(unsigned i2 = 0; i2 < CONFIG_T::n_filt; i2++) {
    #pragma HLS UNROLL
    data[i2].write(input[i2]);
  }
}

template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_1x1(
			      hls::stream<data_T> data[CONFIG_T::n_chan],
			      hls::stream<res_T>  res [CONFIG_T::n_filt], //Filt Width clocks to read output
			      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
			      typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
			      ) {
  
    static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in complete

    static res_T layer_reluout[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

    static res_T layer_out[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0

    static int pX=0; 
    static int pY=0;
    bool lReset = data[0].read();
    if(lReset==1) { 
      pX = 0; 
      pY = 0; 
    }
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      layer_in[i0] =  data[i0].read();
    }
    if((pX+1) % CONFIG_T::stride_width == 0 && (pY+1) % CONFIG_T::stride_height == 0) { 
	nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights);
	nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
	nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,res);
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
      pX = 0;
      pY = pY+1;
    }
}

template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl(
			  hls::stream<data_T> data[CONFIG_T::n_chan],
			  hls::stream<res_T>  res [CONFIG_T::n_filt], //Filt Width clocks to read output
			  typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
			  typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
			  ) {
  const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
  const static int lShiftY = CONFIG_T::filt_height-CONFIG_T::pad_top-1;
  
  static data_T layer_in_row[CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right][CONFIG_T::filt_height][CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=3

  static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in complete dim=0

  static res_T layer_reluout[CONFIG_T::n_filt];
  #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

  static res_T layer_out[CONFIG_T::n_filt];
  #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0

  static int pX=0; 
  static int pY=0;
  bool lReset = data[0].read();
  if(lReset==1) { 
    pX = 0; 
    pY = 0; 
  }
  static bool pPass = false;    
  if(pY > lShiftY-1 && pX == lShiftX) pPass = true;
  for(int i0 = 1; i0 < CONFIG_T::n_chan; i0++) {
   #pragma HLS UNROLL
   layer_in_row[pX+CONFIG_T::pad_left][(CONFIG_T::pad_top+pY) % CONFIG_T::filt_height][i0] =  data[i0].read();
  } 
  if(pX == lShiftX && pPass) nnet::reset_down<data_T,data_T,CONFIG_T>(pY,layer_in_row,layer_in);
  if((pX+1) % CONFIG_T::stride_width == 0 && (pY+1) % CONFIG_T::stride_height == 0 && pPass) { 
    nnet::shift_right_stride<data_T,data_T,CONFIG_T>(pX,pY,layer_in_row,layer_in);
    nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
    nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
    nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,res);
  }
  pX = pX+1;
  if(pX == CONFIG_T::in_height) { 
    pX = 0;
    pY = pY+1;
    pPass = false;
  }
}

template<class data_T, class res_T, typename CONFIG_T>
  void conv_1d_stream(bool iReset,
		    hls::stream<data_T> data[CONFIG_T::n_chan],
		    hls::stream<res_T>  res [CONFIG_T::n_filt], //Filt Width clocks to read output
		    typename CONFIG_T::weight_t weights[CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
		    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
		    ) {
  const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
  
  static data_T layer_in[CONFIG_T::filt_width*CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in complete dim=0

  static res_T layer_reluout[CONFIG_T::n_filt];
  #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

  static res_T layer_out[CONFIG_T::n_filt];
  #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0

  static int pX=0; 
  if(iReset) { 
    pX = 0; 
  }
  static bool pPass = false;    
  if(pX == lShiftX) pPass = true;
  nnet::shift_right<data_T,CONFIG_T>(layer_in);
  for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
   #pragma HLS UNROLL
    layer_in[i0] =  data[i0].read();
  } 
  if((pX+1) % CONFIG_T::stride == 0 && pPass) { 
    nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
    nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
    nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,res);
  }
  pX = pX+1;
}


}
#endif
