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
  unsigned lY              = iY+CONFIG_T::pad_top+1;// *CONFIG_T::stride_height;

  //Shift register by image height
  #pragma HLS PIPELINE
  for(int i0 = CONFIG_T::pad_left+CONFIG_T::stride_width; i0 < CONFIG_T::filt_width; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      unsigned pYC = (i1+lY) % CONFIG_T::filt_height;
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*lH+i0*lW+i2] = input[i0-CONFIG_T::stride_width][pYC][i2];
      }
    }
  }
  for(int i0 = 0; i0 < CONFIG_T::pad_left+CONFIG_T::stride_width; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*lH+i0*lW+i2] = 0;
      }
    }
  }
}
//with stride
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_small_stride(//To be fixed with stride
			      data_T input[CONFIG_T::stride_width][CONFIG_T::filt_height][CONFIG_T::n_chan],
			      res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) { 
  
  #pragma HLS PIPELINE
  //Shift register by image height
  static const int filt_width = CONFIG_T::filt_width-CONFIG_T::stride_width;
  for(int i0 = 0; i0 < filt_width; i0++) { 
    //#pragma HLS PIPELINE II=1
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*CONFIG_T::filt_width*CONFIG_T::n_chan+i0*CONFIG_T::n_chan+i2] = data[i1*CONFIG_T::filt_width*CONFIG_T::n_chan+(i0+CONFIG_T::stride_width)*CONFIG_T::n_chan+i2];
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
  unsigned lShiftX = iShiftX+CONFIG_T::pad_left-1;
  unsigned lShiftY = iShiftY-CONFIG_T::filt_height+1+CONFIG_T::pad_top;
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

//with stride
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_small(//To be fixed with stride
			      data_T input[CONFIG_T::filt_height][CONFIG_T::n_chan],
			      res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) { 

  #pragma HLS inline
  //Shift register by image height
  static const int filt_width = CONFIG_T::filt_width-1;
  for(int i0 = 0; i0 < filt_width; i0++) { 
    #pragma HLS PIPELINE II=1
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i1*CONFIG_T::filt_width*CONFIG_T::n_chan+i0*CONFIG_T::n_chan+i2] = data[i1*CONFIG_T::filt_width*CONFIG_T::n_chan+(i0+1)*CONFIG_T::n_chan+i2];
      }
    }
  }
  static const int lastheight=(CONFIG_T::filt_width-1)*CONFIG_T::n_chan;
  for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
   #pragma HLS UNROLL
    for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
     data[lastheight+i1*CONFIG_T::filt_width*CONFIG_T::n_chan+i2] = input[i1][i2];
    }
  }
}
template<class data_T, class res_T, typename CONFIG_T>
  void fill_image(
		  data_T input[CONFIG_T::n_filt],
		  res_T  pPixId,
		  hls::stream<res_T>  data [CONFIG_T::n_filt_in]) { //CONFIG_T::n_filt2
  #pragma HLS inline
  #pragma HLS PIPELINE
  for(unsigned i2 = 0; i2 < CONFIG_T::n_filt_in; i2++) {
   #pragma HLS UNROLL
   if(i2 == 0) { 
    data[i2].write(pPixId);
   } else { 
    data[i2].write(input[i2-1]);
   }  
  }
}
template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_1x1(
			      hls::stream<data_T> data[CONFIG_T::n_chan_in],
			      hls::stream<res_T>  res [CONFIG_T::n_filt_in], //Filt Width clocks to read output
			      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
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
    bool iReset = data[0].read();
    if(iReset==0) { 
      pX = 0; 
      pY = 0; 
    }
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      layer_in[i0] =  data[1+i0].read();
    }
    if((pX+1) % CONFIG_T::stride_width == 0 && (pY+1) % CONFIG_T::stride_height == 0) { 
      nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
      nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
      res_T pPixId = 0;
      if(pX > 0 || pY > 0) pPixId = 1;
      nnet::fill_image<data_T,res_T,CONFIG_T>(layer_reluout,pPixId,res);
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
      pX = 0;
      pY = pY+1;
    }
}

template<class data_T, class res_T, typename CONFIG_T>
  void conv_2d_large_cl_stride(
			       hls::stream<data_T> data[CONFIG_T::n_chan_in],
			       hls::stream<res_T>  res [CONFIG_T::n_filt_in], //Filt Width clocks to read output
			       typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
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
  data_T iReset = data[0].read();
  if(iReset==0) { 
    pX = 0; 
    pY = 0; 
  }
  static bool pPass = false;    
  if(pY > lShiftY-1 && pX == lShiftX) pPass = true;
  data_T pData = 0;
  for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
   #pragma HLS UNROLL
    pData = data[i0+1].read();
    layer_in_row[pX+CONFIG_T::pad_left][(CONFIG_T::pad_top+pY) % CONFIG_T::filt_height][i0] =  pData;
  } 
  //Add for loop for last row
  if(pX == lShiftX && pPass) nnet::reset_down<data_T,data_T,CONFIG_T>(pY,layer_in_row,layer_in);
  if((pX-lShiftX) % CONFIG_T::stride_width == 0 && (pY-lShiftY) % CONFIG_T::stride_height == 0 && pPass) { 
    nnet::shift_right_stride<data_T,data_T,CONFIG_T>(pX,pY,layer_in_row,layer_in);
    nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
    nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
    res_T pPixId = 0;
    if(pX > 0 || pY > 0) pPixId = 1;
    nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,pPixId,res);
  }
  pX = pX+1;
  if(pX == CONFIG_T::in_height) { 
    pX = 0;
    pY = pY+1;
    pPass = false;
  }
}


template<class data_T, class res_T, typename CONFIG_T>
  void cnnshift_arr(data_T data[CONFIG_T::n_chan],
		    ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
		    data_T output[(CONFIG_T::filt_height*CONFIG_T::filt_width)*(CONFIG_T::n_chan)]) { 

    #pragma HLS PIPELINE
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    
    data_T tmpinput[CONFIG_T::filt_height][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
    
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      tmpinput[CONFIG_T::filt_height-1][i0] = data[i0];
      for(unsigned i1 = 1; i1 < CONFIG_T::filt_height; i1++) {
        #pragma HLS UNROLL
	data_T tmp1      = tmpinput[CONFIG_T::filt_height-i1][i0];
	data_T tmp       = layer_in_row[i1-1][i0].shift(tmp1);
	tmpinput[CONFIG_T::filt_height-i1-1][i0] = tmp;
      }
    }
    shift_right_small<data_T,res_T,CONFIG_T>(tmpinput,output);
}

template<class data_T, class res_T, typename CONFIG_T>
  void cnnshift(hls::stream<data_T> data[CONFIG_T::n_chan],
		//ap_shift_reg<data_T, (CONFIG_T::in_width)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
		ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
		data_T output[(CONFIG_T::filt_height*CONFIG_T::filt_width)*(CONFIG_T::n_chan)]) { 

    #pragma HLS PIPELINE
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    
    data_T tmpinput[CONFIG_T::filt_height][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
    
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      data_T base = data[i0].read();
      tmpinput[CONFIG_T::filt_height-1][i0] = base;
      for(unsigned i1 = 1; i1 < CONFIG_T::filt_height; i1++) {
        #pragma HLS UNROLL
	data_T tmp1      = tmpinput[CONFIG_T::filt_height-i1][i0];
	data_T tmp       = layer_in_row[i1-1][i0].shift(tmp1);
	tmpinput[CONFIG_T::filt_height-i1-1][i0] = tmp;
      }
    }
    shift_right_small<data_T,res_T,CONFIG_T>(tmpinput,output);
}
template<class data_T, class res_T, typename CONFIG_T>
  void cnnshiftzero_arr(
			ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
			data_T output[(CONFIG_T::filt_height*CONFIG_T::filt_width)*(CONFIG_T::n_chan)]) { 

    #pragma HLS inline
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    
    data_T tmpinput[CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
    for(unsigned iY = 0; iY < CONFIG_T::n_chan; iY++) { 
      tmpinput[iY] = 0;
    }
    nnet::cnnshift_arr<data_T,res_T,CONFIG_T>(tmpinput,layer_in_row,output);
}

template<class data_T, class res_T, typename CONFIG_T>
  void cnnshiftzero(
		    ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
		    data_T output[(CONFIG_T::filt_height*CONFIG_T::filt_width)*(CONFIG_T::n_chan)]) { 

    #pragma HLS inline
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    
    hls::stream<data_T> tmpinput[CONFIG_T::n_chan];
    #pragma HLS STREAM variable=tmpinput depth=1 dim=1
    for(unsigned i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
      #pragma HLS UNROLL
      tmpinput[i0].write(0);
    }
    nnet::cnnshift<data_T,res_T,CONFIG_T>(tmpinput,layer_in_row,output);
}
template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl(
		      hls::stream<data_T> data[CONFIG_T::n_chan_in],
		      hls::stream<res_T>  res [CONFIG_T::n_filt_in], 
		      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
		      typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
		      ) {
  

    const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
    const static int lShiftY = CONFIG_T::filt_height-CONFIG_T::pad_top-1;
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);

    static ap_shift_reg<data_T,rowsize> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=2

    data_T tmpdata[CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpdata complete    

    static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in complete

    res_T layer_reluout[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

    res_T layer_out[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0
    static int pX=0; 
    static int pY=0;
    
    data_T iReset = data[0].read();
    for(int i1 = 0; i1 < CONFIG_T::n_chan; i1++) { 
      #pragma HLS UNROLL    
      tmpdata[i1] = data[i1+1].read(); 
    }
    static res_T  pReset = 0;
    if(iReset==0) { 
      pX = 0; 
      pY = 0; 
      pReset = 0;
      for(unsigned iX = 0; iX < CONFIG_T::pad_left+CONFIG_T::pad_top*rowsize; iX++) nnet::cnnshiftzero_arr<data_T,res_T,CONFIG_T>(layer_in_row,layer_in);
    }
    nnet::cnnshift_arr<data_T,res_T,CONFIG_T>(tmpdata,layer_in_row,layer_in);
    unsigned pLoop = 1;
    if(pX == CONFIG_T::in_width-1) pLoop = CONFIG_T::pad_right+1;
    if(pX == CONFIG_T::in_width-1 && pY == CONFIG_T::in_height-1) pLoop = CONFIG_T::pad_right+1+CONFIG_T::pad_bottom*(rowsize-CONFIG_T::pad_left); //Fill the end with zeros for bottom paddings
    for(unsigned i0 = 0; i0 < pLoop; i0++) { 
      if(i0 > 0) nnet::cnnshiftzero_arr<data_T,res_T,CONFIG_T>(layer_in_row,layer_in); 
      if((pX-lShiftX) % CONFIG_T::stride_width == 0 && (pY-lShiftY) % CONFIG_T::stride_height == 0 && pY > lShiftY-1 && pX > lShiftX-1) { 
	nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
	nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
	nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,pReset,res);
	if(pReset == 0) pReset = 1;
      }
      pX = pX+1;
      if(pX == CONFIG_T::in_width+CONFIG_T::pad_right) { 
	pX = 0;
	pY = pY+1;
	for(unsigned iY = 0; iY < CONFIG_T::pad_left; iY++) nnet::cnnshiftzero_arr<data_T,res_T,CONFIG_T>(layer_in_row,layer_in);
      }
    }
}
template<unsigned id,class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_nopad(
			    hls::stream<data_T> data[CONFIG_T::n_chan_in],
			    hls::stream<res_T>  res [CONFIG_T::n_filt_in], //Filt Width clocks to read output
			    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
			    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
			    ) {
  
    //#pragma HLS inline
    const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
    const static int lShiftY = CONFIG_T::filt_height-CONFIG_T::pad_top-1;

    static ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=2
    
    data_T tmpdata[CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpdata complete    

    static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in complete

    res_T layer_reluout[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

    res_T layer_out[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0
    
    static int pX=0; 
    static int pY=0;
    static res_T lReset = 0; 

    data_T iReset = data[0].read();
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
      #pragma HLS UNROLL
      tmpdata[i0] = data[i0+1].read(); 
    }
    nnet::cnnshift_arr<data_T,res_T,CONFIG_T>(tmpdata,layer_in_row,layer_in);
    if(iReset==0) { 
      pX = 0; 
      pY = 0; 
      lReset = 0;
    }
    if((pX-lShiftX) % CONFIG_T::stride_width == 0 && (pY-lShiftY) % CONFIG_T::stride_height == 0 && pY > lShiftY-1 && pX > lShiftX-1) { 
      nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
      nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
      res_T pPixId = lReset;
      if(lReset == 0) lReset = 1;
      nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,pPixId,res);
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
      pX = 0;
      pY = pY+1;
    }
}
template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_nopad_pad(
			    hls::stream<data_T> data[CONFIG_T::n_chan_in],
			    hls::stream<res_T>  res [CONFIG_T::n_filt_in], 
			    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
			    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
			    ) {

    // #pragma HLS PIPELINE

    const static int lShiftX = CONFIG_T::filt_width-1;
    const static int lShiftY = CONFIG_T::filt_height-1;

    static ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=2

    data_T tmpdata[CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpdata complete

    static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in complete

    res_T layer_reluout[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

    res_T layer_out[CONFIG_T::n_filt];
    #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0

    static int pX=0; 
    static int pY=0;
    static res_T  pReset = 0;
    
    data_T iReset = data[0].read();
    for(int i1 = 0; i1 < CONFIG_T::n_chan; i1++) { 
      #pragma HLS UNROLL
      tmpdata[i1] = data[i1+1].read(); 
    }
    if(iReset==0) { 
      pX = 0; 
      pY = 0; 
      pReset = 0;
    }
    nnet::cnnshift_arr<data_T,res_T,CONFIG_T>(tmpdata,layer_in_row,layer_in);
    if((pX-lShiftX) % CONFIG_T::stride_width == 0 && (pY-lShiftY) % CONFIG_T::stride_height == 0 && pY > lShiftY-1 && pX > lShiftX-1) { 
      data_T tmplayer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
      #pragma HLS ARRAY_PARTITION variable=tmplayer_in complete
      for(unsigned itmp = 0; itmp <  CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan; itmp++) { 
	#pragma HLS UNROLL
	tmplayer_in[itmp] = layer_in[itmp];
      }
      nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
      nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
      nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,pReset,res);
      if(pReset == 0) pReset = 1;
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right) { 
      pX = 0;
      pY = pY+1;
    }
}


template<class data_T, class res_T, typename CONFIG_T>
void zeropad(
	     unsigned &iN,
	     hls::stream<data_T> data[CONFIG_T::n_chan_in],
	     hls::stream<res_T>  res [CONFIG_T::n_chan_in]
	     ) {
  
    #pragma HLS PIPELINE
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    static int pX=0; 
    static int pY=0;

    data_T tmpdata[CONFIG_T::n_chan_in];
    #pragma HLS ARRAY_RESHAPE variable=tmpdata complete    

    for(int i1 = 0; i1 < CONFIG_T::n_chan_in; i1++) { 
      #pragma HLS UNROLL
      tmpdata[i1] = data[i1].read(); 
    }
    static res_T  pReset = 0;
    if(tmpdata[0]==0) { 
      pX = 0; 
      pY = 0; 
      pReset = 0;
      for(unsigned i1 = 0; i1 < CONFIG_T::pad_left+CONFIG_T::pad_top*rowsize; i1++) { 
	#pragma HLS PIPELINE II=1
	iN++;
	for(unsigned i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) {
	  res_T pTmp = 0;
	  if(i2 == 0) pTmp = pReset;
	  res[i2].write(pTmp);
	  if(pReset == 0) pReset = 1;
	}
       }
    }
    for(unsigned i0 = 0; i0 < CONFIG_T::n_chan_in; i0++) {
      #pragma HLS UNROLL
      res_T pTmp = tmpdata[i0];
      if(i0 == 0) pTmp = pReset;
      res[i0].write(pTmp);
    }
    iN++;
    unsigned pLoop = 0;
    if(pX == CONFIG_T::in_width-1) pLoop = CONFIG_T::pad_right+CONFIG_T::pad_left;
    if(pX == CONFIG_T::in_width-1 && pY == CONFIG_T::in_height-1) pLoop = CONFIG_T::pad_right+CONFIG_T::pad_bottom*rowsize; //Fill the end with zeros for bottom paddings
    for(unsigned i0 = 0; i0 < pLoop; i0++) { 
      iN++;
     for(unsigned i1 = 0; i1 < CONFIG_T::n_chan_in; i1++) {
      #pragma HLS UNROLL
      res_T pTmp = 0;
      if(i1 == 0) pTmp = 1;
      res[i1].write(pTmp);
     }
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
	pX = 0;
	pY = pY+1;
    }
}

template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl2(
		      hls::stream<data_T> data[CONFIG_T::n_chan_in],
		      hls::stream<res_T>  res [CONFIG_T::n_filt_in], 
		      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
		      typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
		      ) {

    const static unsigned rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    const static unsigned depth   = 2*(CONFIG_T::pad_left+CONFIG_T::pad_top*rowsize);
    hls::stream<res_T>  ptmp[CONFIG_T::n_chan_in];	  
    #pragma HLS STREAM variable=ptmp depth=depth dim=1
    unsigned iN=0;
    zeropad<data_T,res_T,CONFIG_T>(iN,data,ptmp);
    //while(!ptmp[0].empty()) {
    for(unsigned i0 = 0; i0 < iN; i0++) { 
      conv_2d_large_cl_nopad_pad<data_T,res_T,CONFIG_T>(ptmp,res,weights,biases);
    }
}

template<class data_T, class res_T, typename CONFIG_T>
void pad_2d_cl(
	    hls::stream<data_T> data[CONFIG_T::n_chan],
	    hls::stream<res_T>  res [CONFIG_T::n_chan] 
	    ) {

    #pragma HLS PIPELINE
    const static unsigned rowsize  = (CONFIG_T::out_width);
    const static unsigned padtop   = ((CONFIG_T::out_height)-(CONFIG_T::in_height))/2;
    const static unsigned padleft  = ((CONFIG_T::out_width)-(CONFIG_T::in_width))/2;
    const static unsigned allpadtop = padleft+(padtop*rowsize);
    static int pX=0; 
    static int pY=0;
    std::cout << CONFIG_T::out_height << " -- " << CONFIG_T::in_height << "---> " << allpadtop << " --" << padleft << " -- " << rowsize << std::endl;

    data_T tmpdata[CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpdata complete    

    for(int i1 = 0; i1 < CONFIG_T::n_chan; i1++) { 
      #pragma HLS UNROLL
      tmpdata[i1] = data[i1].read(); 
    }
    static res_T  pReset = 0;
    if(tmpdata[0]==0) { 
      pX = 0; 
      pY = 0; 
      pReset = 0;
      for(unsigned i1 = 0; i1 < allpadtop; i1++) { 
	#pragma HLS PIPELINE II=1
	for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) {
	  res_T pTmp = 0;
	  if(i2 == 0) pTmp = pReset;
	  res[i2].write(pTmp);
	  if(pReset == 0) pReset = 1;
	}
       }
    }
    for(unsigned i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      res_T pTmp = tmpdata[i0];
      if(i0 == 0) pTmp = pReset;
      res[i0].write(pTmp);
    }
    unsigned pLoop = 0;
    if(pX == CONFIG_T::in_width-1) pLoop = padleft+padleft;
    if(pX == CONFIG_T::in_width-1 && pY == CONFIG_T::in_height-1) pLoop = padleft+padtop*rowsize; //Fill the end with zeros for bottom paddings
    for(unsigned i0 = 0; i0 < pLoop; i0++) { 
     for(unsigned i1 = 0; i1 < CONFIG_T::n_chan; i1++) {
      #pragma HLS UNROLL
      res_T pTmp = 0;
      if(i1 == 0) pTmp = 1;
      res[i1].write(pTmp);
     }
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
	pX = 0;
	pY = pY+1;
    }
}

template<class data_T, class res_T, typename CONFIG_T, typename CONFIG_T2>
void conv_2d_large_cl_row_stream(bool iReset,
                                 hls::stream<data_T> data[CONFIG_T::in_width][CONFIG_T::n_chan_in],
				 hls::stream<res_T>  res [CONFIG_T::n_split][CONFIG_T::n_filt_in],
				 typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/2],
				 typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
				 ) {

  #pragma HLS DATAFLOW
  #pragma HLS ARRAY_RESHAPE variable=data complete dim=0

  static const unsigned nrange = CONFIG_T::in_width/CONFIG_T::n_split;
  static const unsigned ntotal = nrange+CONFIG_T::filt_width-1;
  hls::stream<data_T> tmpdata[CONFIG_T::n_split][CONFIG_T::n_chan_in];
  #pragma HLS STREAM variable=tmpdata depth=ntotal dim=2

  for(int i0 = 0; i0 < CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right; i0++) {
    unsigned pIndex = i0/nrange;
    if(pIndex > CONFIG_T::n_split-1) pIndex = CONFIG_T::n_split-1;                                                                                                                                                             
    if(i0 < CONFIG_T::pad_left) {
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
       #pragma HLS UNROLL
       if(i2 == 0) { 
         data_T pTmp = 1; 
         tmpdata[pIndex][i2].write(pTmp);
       } else { 
         data_T pTmp = 0; 
	 tmpdata[pIndex][i2].write(pTmp);
       }
      } 
    } else if(i0 > ( CONFIG_T::in_width+CONFIG_T::pad_left-1) ) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
       #pragma HLS UNROLL
       if(i2 == 0) { 
         data_T pTmp = 1; 
         tmpdata[pIndex][i2].write(pTmp);
       } else { 
         data_T pTmp = 0; 
	 tmpdata[pIndex][i2].write(pTmp);
       }
      } 
    } else { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
	#pragma HLS UNROLL
	data_T pData = data[i0-CONFIG_T::pad_left][i2].read();
	tmpdata[pIndex][i2].write(pData);
	if(i0 % nrange <  CONFIG_T::filt_width && i0 > nrange) tmpdata[pIndex-1][i2].write(pData);
      }
    }
  }
  for(int i1 = 0; i1 < ntotal; i1++) {
    conv_2d_large_cl_nopad<1,data_T,res_T,CONFIG_T2>(tmpdata[0],res[0],weights,biases);
    conv_2d_large_cl_nopad<2,data_T,res_T,CONFIG_T2>(tmpdata[1],res[1],weights,biases);
    conv_2d_large_cl_nopad<3,data_T,res_T,CONFIG_T2>(tmpdata[2],res[2],weights,biases);
    conv_2d_large_cl_nopad<4,data_T,res_T,CONFIG_T2>(tmpdata[3],res[3],weights,biases);
  }
}
template<class data_T, class res_T, typename CONFIG_T>
void conv_1d_large_cl(
		      hls::stream<data_T> data[CONFIG_T::n_chan_in],
		      hls::stream<res_T>  res [CONFIG_T::n_filt_in], //Filt Width clocks to read output
		      typename CONFIG_T::weight_t weights[CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/CONFIG_T::mult_config::merge_factor],
		      typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
		      ) {
  const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
  
  static ap_shift_reg<data_T, (CONFIG_T::filt_width)> layer_in_row[CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=2  
  
  static data_T layer_in[CONFIG_T::filt_width*CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in complete dim=0

  static res_T layer_reluout[CONFIG_T::n_filt];
  #pragma HLS ARRAY_RESHAPE variable=layer_reluout complete dim=0

  static res_T layer_out[CONFIG_T::n_filt];
  #pragma HLS ARRAY_RESHAPE variable=layer_out complete dim=0

  static int pX=0; 
  data_T iReset = data[0].read();
  if(iReset == 0) { 
    pX = 0; 
    for(int iX = 0; iX < CONFIG_T::pad_left; iX++) { 
      for(int i0 = 0; i0 < CONFIG_T::n_chan_in; i0++) {
	data_T tmp = 0;
	layer_in_row[i0].shift(0,tmp);
      }
    }
  }
  for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
    #pragma HLS UNROLL
    data_T tmp = data[i0+1].read();
    layer_in_row[i0].shift(0,tmp);
  }
  if((pX+1) % CONFIG_T::stride == 0 && pX > lShiftX-1) { 
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
     #pragma HLS UNROLL
     for(int i1 = 0; i1 < CONFIG_T::filt_width; i1++) {
      data_T tmp = layer_in_row[i0].read(i1);
      layer_in[i1*CONFIG_T::n_chan+i0] = tmp;		       
     }
    }
    nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
    //nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
    res_T pPixId = 0;
    if(pX > 0) pPixId = 1;
    nnet::fill_image<data_T,res_T,CONFIG_T>(layer_out,pPixId,res);
  }
  pX = pX+1;
}



}
#endif
