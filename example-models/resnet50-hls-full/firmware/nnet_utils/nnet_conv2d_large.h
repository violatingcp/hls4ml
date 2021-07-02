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
			      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/2],
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
			       typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/2],
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
  void cnnshift(hls::stream<data_T> data[CONFIG_T::n_chan_in],
		ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
		data_T output[(CONFIG_T::filt_height*CONFIG_T::filt_width)*(CONFIG_T::n_chan)]) { 

    #pragma HLS PIPELINE
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    
    static const unsigned nchan = CONFIG_T::n_chan;
    data_T tmpinput[CONFIG_T::filt_height][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
    
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      data_T base = data[1+i0].read();
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
  void cnnshiftzero(
		    ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan],
		    data_T output[(CONFIG_T::filt_height*CONFIG_T::filt_width)*(CONFIG_T::n_chan)]) { 

    #pragma HLS PIPELINE
    const static int rowsize = (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right);
    
    static const unsigned nchan = CONFIG_T::n_chan;
    data_T tmpinput[CONFIG_T::filt_height][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
    
    for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      data_T base = 0;
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
void conv_2d_large_cl(
		      hls::stream<data_T> data[CONFIG_T::n_chan_in],
		      hls::stream<res_T>  res [CONFIG_T::n_filt_in], 
		      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/2],
		      typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
		      ) {
  
    //#pragma HLS inline
    const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
    const static int lShiftY = CONFIG_T::filt_height-CONFIG_T::pad_top-1;

    static ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=2
    
    static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in complete

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
      for(int i0 = 0; i0 < CONFIG_T::pad_left; i0++) nnet::cnnshiftzero<data_T,res_T,CONFIG_T>(layer_in_row,layer_in);
    }

    static bool pPass = false;    
    if(pY > lShiftY-1 && pX == lShiftX) pPass = true;
    nnet::cnnshift<data_T,res_T,CONFIG_T>(data,layer_in_row,layer_in);
    unsigned pLoop = 1;
    if(pX == CONFIG_T::in_width-1) pLoop = CONFIG_T::pad_right+1;
    for(int i0 = 0; i0 < pLoop; i0++) { 
      if(i0 > 0) nnet::cnnshiftzero<data_T,res_T,CONFIG_T>(layer_in_row,layer_in); 
      if((i0+pX-lShiftX) % CONFIG_T::stride_width == 0 && (i0+pY-lShiftY) % CONFIG_T::stride_height == 0 && pPass) { 
	nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
	nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
	res_T pPixId = 0;
	if(pX > 0 || pY > 0) pPixId = 1;
	nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,pPixId,res);
      }
     }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
      pX = 0;
      pY = pY+1;
      pPass = false;
      for(int i0 = 0; i0 < CONFIG_T::pad_left; i0++) nnet::cnnshiftzero<data_T,res_T,CONFIG_T>(layer_in_row,layer_in);
    }
}

template<unsigned id,class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_nopad(
			    hls::stream<data_T> data[CONFIG_T::n_chan_in],
			    hls::stream<res_T>  res [CONFIG_T::n_filt_in], //Filt Width clocks to read output
			    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt/2],
			    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
			    ) {
  
    //#pragma HLS inline
    const static int lShiftX = CONFIG_T::filt_width-CONFIG_T::pad_left-1;
    const static int lShiftY = CONFIG_T::filt_height-CONFIG_T::pad_top-1;

    static ap_shift_reg<data_T, (CONFIG_T::in_width+CONFIG_T::pad_left+CONFIG_T::pad_right)> layer_in_row[(CONFIG_T::filt_height)-1][CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=2
    
    static data_T layer_in[CONFIG_T::filt_height*CONFIG_T::filt_width*CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=layer_in complete

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
    nnet::cnnshift<data_T,res_T,CONFIG_T>(data,layer_in_row,layer_in);

    if((pX-lShiftX) % CONFIG_T::stride_width == 0 && (pY-lShiftY) % CONFIG_T::stride_height == 0 && pPass) { 
      nnet::dense_large<data_T,res_T,typename CONFIG_T::mult_config>(layer_in,layer_out,weights,biases);
      nnet::relu<res_T,res_T,typename CONFIG_T::relu_config>(layer_out, layer_reluout);
      res_T pPixId = 0;
      if(pX > 0 || pY > 0) pPixId = 1;
      nnet::fill_image<data_T,data_T,CONFIG_T>(layer_reluout,pPixId,res);
    }
    pX = pX+1;
    if(pX == CONFIG_T::in_width) { 
      pX = 0;
      pY = pY+1;
      pPass = false;
    }
}

template<unsigned iX,class data_T, typename CONFIG_T>
void split_inputs(//unsigned iX, 
		  hls::stream<data_T> data[CONFIG_T::in_width][CONFIG_T::n_chan_in],
		  hls::stream<data_T> tmpdata[CONFIG_T::n_chan_in],
		  data_T tmpdata_arr[CONFIG_T::n_split-1][CONFIG_T::filt_width-1][CONFIG_T::n_chan_in]
		  ) { 

    #pragma HLS PIPELINE
    static const unsigned nrange = CONFIG_T::in_width/CONFIG_T::n_split;
    for(int i0 = 0; i0 < nrange; i0++) {
      if(i0 < CONFIG_T::pad_left && iX == 0) {
	for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
         #pragma HLS UNROLL
	 if(i2 == 0) { 
	  data_T pTmp = 1; 
	  tmpdata[i2].write(pTmp);
	 } else { 
	  data_T pTmp = 0; 
	  tmpdata[i2].write(pTmp);
	 }
	} 
      } else {
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
	#pragma HLS UNROLL
	data_T pData = data[iX*nrange+i0-CONFIG_T::pad_left][i2].read();
	tmpdata[i2].write(pData);
	if(i0 <  CONFIG_T::filt_width-1 && iX > 0) tmpdata_arr[iX-1][i0][i2] = pData; 
      }
     }
    }
}
template<unsigned iX, class data_T, typename CONFIG_T>
  void fill_ends(//unsigned iX, 
	       hls::stream<data_T> data[CONFIG_T::in_width][CONFIG_T::n_chan_in],
	       hls::stream<data_T> tmpdata[CONFIG_T::n_chan_in],
	       data_T tmpdata_arr[CONFIG_T::n_split-1][CONFIG_T::filt_width-1][CONFIG_T::n_chan_in]
	       ) { 

  #pragma HLS PIPELINE
  for(int i0 = 0; i0 < CONFIG_T::filt_width-1; i0++) {
    if(iX == CONFIG_T::n_split-1) {
      if(i0 < CONFIG_T::pad_left) { 
	for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
	  data_T pData = data[CONFIG_T::in_width-CONFIG_T::pad_left][i2].read();
	  tmpdata[i2].write(pData);
	}
      } else { 
	for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
         #pragma HLS UNROLL
	  if(i2 == 0) { 
	    data_T pTmp = 1; 
	    tmpdata[i2].write(pTmp);
	  } else { 
	    data_T pTmp = 0; 
	    tmpdata[i2].write(pTmp);
	  }
	}
      }
    } else { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) {
	tmpdata[i2].write(tmpdata_arr[iX][i0][i2]);
      } 
    }
  }
}
     

/*
template<class data_T, class res_T, typename CONFIG_T, typename CONFIG_T2>
void conv_2d_large_cl_row_stream(
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

  data_T tmpdata_arr[CONFIG_T::n_split][ntotal][CONFIG_T::n_chan_in];
  #pragma HLS ARRAY_RESHAPE variable=tmpdata_arr complete dim=0

  for(int i0 = 0; i0 < CONFIG_T::pad_left; i0++) { 
    for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
      tmpdata_arr[0][i0][i2] = 0;
    }
  } 
  for(int i0 = 0; i0 < CONFIG_T::pad_right; i0++) { 
    for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
      tmpdata_arr[CONFIG_T::n_split-1][ntotal-CONFIG_T::pad_right+i0][i2] = 0;
    }
  } 
  for(int i0 = 0; i0 < CONFIG_T::in_width; i0++) { 
    unsigned pIndex = (CONFIG_T::pad_left+i0)/nrange;
    if(pIndex == CONFIG_T::n_split) pIndex =  CONFIG_T::n_split-1;
    unsigned pId    = (CONFIG_T::pad_left+i0) - pIndex*nrange;
    for(int i2 = 0; i2 < CONFIG_T::n_chan_in; i2++) { 
      tmpdata_arr[pIndex][pId][i2] = data[i0][i2].read();
    }
  }
  for(int i0     = 0; i0 < CONFIG_T::n_split-1; i0++) { 
    for(int i1   = 0; i1 < CONFIG_T::filt_width-1; i1++) {
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in;  i2++) {
	tmpdata_arr[i0][nrange+i1][i2] = tmpdata_arr[i0+1][i1][i2];
      }
    }
  }
  for(int i1   = 0; i1 < ntotal; i1++) {
    for(int i0     = 0; i0 < CONFIG_T::n_split;      i0++) {
      for(int i2 = 0; i2 < CONFIG_T::n_chan_in;  i2++) {
	tmpdata[i0][i2].write(tmpdata_arr[i0][nrange+i1][i2]);
      }
    }
  } 
  //for(unsigned iX = 0; iX < CONFIG_T::n_split; iX++) { 
  //#pragma HLS UNROLL
  ///split_inputs<0,data_T,CONFIG_T>(data,tmpdata[0],tmpdata_arr);
  //split_inputs<1,data_T,CONFIG_T>(data,tmpdata[1],tmpdata_arr);
  //split_inputs<2,data_T,CONFIG_T>(data,tmpdata[2],tmpdata_arr);
  //split_inputs<3,data_T,CONFIG_T>(data,tmpdata[3],tmpdata_arr);
  //fill_ends<0,data_T,CONFIG_T>(data,tmpdata[0],tmpdata_arr);
  //fill_ends<1,data_T,CONFIG_T>(data,tmpdata[1],tmpdata_arr);
  //fill_ends<2,data_T,CONFIG_T>(data,tmpdata[2],tmpdata_arr);
  //fill_ends<3,data_T,CONFIG_T>(data,tmpdata[3],tmpdata_arr);
  //}
  
  for(int i1 = 0; i1 < ntotal; i1++) {
    conv_2d_large_cl_nopad<1,data_T,res_T,CONFIG_T2>(tmpdata[0],res[0],weights,biases);
    conv_2d_large_cl_nopad<2,data_T,res_T,CONFIG_T2>(tmpdata[1],res[1],weights,biases);
    conv_2d_large_cl_nopad<3,data_T,res_T,CONFIG_T2>(tmpdata[2],res[2],weights,biases);
    conv_2d_large_cl_nopad<4,data_T,res_T,CONFIG_T2>(tmpdata[3],res[3],weights,biases);
  }
}
*/


 template<class data_T, class res_T, typename CONFIG_T, typename CONFIG_T2>
   void conv_2d_large_cl_row_stream(
				    hls::stream<data_T> data[CONFIG_T::n_split][CONFIG_T::n_chan_in],
				    hls::stream<res_T>  res [CONFIG_T::n_split][CONFIG_T::n_filt_in],
				    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
				    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]
				    ) {

  #pragma HLS DATAFLOW
  #pragma HLS ARRAY_RESHAPE variable=data complete dim=0

   static const unsigned nrange = CONFIG_T::in_width/CONFIG_T::n_split;
   static const unsigned ntotal = nrange+CONFIG_T::filt_width-1;

   for(int i1 = 0; i1 < ntotal; i1++) {
     conv_2d_large_cl_nopad<1,data_T,res_T,CONFIG_T2>(data[0],res[0],weights,biases);
     conv_2d_large_cl_nopad<2,data_T,res_T,CONFIG_T2>(data[1],res[1],weights,biases);
     conv_2d_large_cl_nopad<3,data_T,res_T,CONFIG_T2>(data[2],res[2],weights,biases);
     conv_2d_large_cl_nopad<4,data_T,res_T,CONFIG_T2>(data[3],res[3],weights,biases);
     conv_2d_large_cl_nopad<5,data_T,res_T,CONFIG_T2>(data[4],res[4],weights,biases);
     conv_2d_large_cl_nopad<6,data_T,res_T,CONFIG_T2>(data[5],res[5],weights,biases);
     conv_2d_large_cl_nopad<7,data_T,res_T,CONFIG_T2>(data[6],res[6],weights,biases);
     conv_2d_large_cl_nopad<8,data_T,res_T,CONFIG_T2>(data[7],res[7],weights,biases);

     //conv_2d_large_cl_nopad<9,data_T,res_T,CONFIG_T2>(data[8],res[8],weights,biases);
     //conv_2d_large_cl_nopad<10,data_T,res_T,CONFIG_T2>(data[9],res[9],weights,biases);
     //conv_2d_large_cl_nopad<11,data_T,res_T,CONFIG_T2>(data[10],res[10],weights,biases);
     //conv_2d_large_cl_nopad<12,data_T,res_T,CONFIG_T2>(data[11],res[11],weights,biases);
     //conv_2d_large_cl_nopad<13,data_T,res_T,CONFIG_T2>(data[12],res[12],weights,biases);
     //conv_2d_large_cl_nopad<14,data_T,res_T,CONFIG_T2>(data[13],res[13],weights,biases);
     //conv_2d_large_cl_nopad<15,data_T,res_T,CONFIG_T2>(data[14],res[14],weights,biases);
     //conv_2d_large_cl_nopad<16,data_T,res_T,CONFIG_T2>(data[15],res[15],weights,biases);
   }
 }





}
#endif
