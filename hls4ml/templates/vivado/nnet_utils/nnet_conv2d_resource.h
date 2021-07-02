#ifndef NNET_CONV2D_RESOURCE_H_
#define NNET_CONV2D_RESOURCE_H_

#include "ap_shift_reg.h"
#include "nnet_activation.h"
#include "nnet_common.h"
#include "nnet_dense.h"

namespace nnet {

template<class data_T, typename CONFIG_T>
void im2col_2d(
    data_T data[CONFIG_T::in_height * CONFIG_T::in_width * CONFIG_T::n_chan],
    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::out_height * CONFIG_T::out_width])
{
    const int output_h = (CONFIG_T::in_height + CONFIG_T::pad_top + CONFIG_T::pad_bottom -
        (CONFIG_T::dilation_height * (CONFIG_T::filt_height - 1) + 1)) / CONFIG_T::stride_height + 1;
    const int output_w = (CONFIG_T::in_width + CONFIG_T::pad_left + CONFIG_T::pad_right -
        (CONFIG_T::dilation_width * (CONFIG_T::filt_width - 1) + 1)) / CONFIG_T::stride_width + 1;
    const int channel_size = CONFIG_T::in_height * CONFIG_T::in_width;

    for (int channel = CONFIG_T::n_chan; channel--; data += channel_size) {
        for (int kernel_row = 0; kernel_row < CONFIG_T::filt_height; kernel_row++) {
            for (int kernel_col = 0; kernel_col < CONFIG_T::filt_width; kernel_col++) {
                int input_row = -CONFIG_T::pad_top + kernel_row * CONFIG_T::dilation_height;
                for (int output_rows = output_h; output_rows; output_rows--) {
                    if (input_row < 0 || input_row > CONFIG_T::in_height) {
                        for (int output_cols = output_w; output_cols; output_cols--) {
                            *(data_col++) = 0;
                        }
                    } else {
                        int input_col = -CONFIG_T::pad_left + kernel_col * CONFIG_T::dilation_width;
                        for (int output_col = output_w; output_col; output_col--) {
                            if (input_col >= 0 && input_col < CONFIG_T::in_width) {
                                *(data_col++) = data[input_row * CONFIG_T::in_width + input_col];
                            } else {
                                *(data_col++) = 0;
                            }
                            input_col += CONFIG_T::stride_width;
                        }
                    }
                    input_row += CONFIG_T::stride_height;
                }
            }
        }
    }
}


template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_full(
    data_T data[CONFIG_T::in_height * CONFIG_T::in_width * CONFIG_T::n_chan],
    res_T  res[CONFIG_T::out_height * CONFIG_T::out_width * CONFIG_T::n_filt],
    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt])
{
    data_T data_conv[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::out_height * CONFIG_T::out_width];
    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan];
    res_T res_col[CONFIG_T::n_filt];

    //#pragma HLS ARRAY_PARTITION variable=data_conv complete
    #pragma HLS ARRAY_PARTITION variable=data_col complete
    #pragma HLS ARRAY_PARTITION variable=res_col complete

    im2col_2d<data_T, CONFIG_T>(data, data_conv);

    for (int i = 0; i < CONFIG_T::out_height * CONFIG_T::out_width; i++) {
        for (int j = 0; j < CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan; j++) {
            data_col[j] = data[j * CONFIG_T::out_height * CONFIG_T::out_width + i];
        }
        dense<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
        for (int j = 0; j < CONFIG_T::n_filt; j++) {
            //res[i * CONFIG_T::n_filt + j] = res_col[j];
            res[j * CONFIG_T::out_height * CONFIG_T::out_width + i] = res_col[j]; // Transposed order
        }
    }
}

template<class data_T, typename CONFIG_T>
void im2col_2d_cf(
    data_T data[CONFIG_T::n_chan * CONFIG_T::in_height * CONFIG_T::in_width],
    data_T data_col[CONFIG_T::n_chan * CONFIG_T::filt_height * CONFIG_T::filt_width],
    const int row,
    const int col)
{
    const int channel_size = CONFIG_T::in_height * CONFIG_T::in_width;
    int index = 0;
    for (int channel = CONFIG_T::n_chan; channel--; data += channel_size) {
        #pragma HLS UNROLL
        for (int kernel_row = 0; kernel_row < CONFIG_T::filt_height; kernel_row++) {
            int input_row = -CONFIG_T::pad_top + kernel_row * CONFIG_T::dilation_height + row * CONFIG_T::stride_height;
            for (int kernel_col = 0; kernel_col < CONFIG_T::filt_width; kernel_col++) {
                if (input_row < 0 || input_row > CONFIG_T::in_height) {
                    data_col[index++] = 0;
                } else {
                    int input_col = -CONFIG_T::pad_left + kernel_col * CONFIG_T::dilation_width + col * CONFIG_T::stride_width;
                    if (input_col >= 0 && input_col < CONFIG_T::in_width) {
                        //*(data_col++) = data[input_row * CONFIG_T::in_width + input_col];
                        data_col[index++] = data[input_row * CONFIG_T::in_width + input_col];
                    } else {
                        //*(data_col++) = 0;
                        data_col[index++] = 0;
                    }
                    input_col += CONFIG_T::stride_width;
                }
            }
            input_row += CONFIG_T::stride_height;
        }
    }
}

template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_resource_cf(
    data_T data[CONFIG_T::n_chan * CONFIG_T::in_height * CONFIG_T::in_width],
    res_T  res[CONFIG_T::out_height * CONFIG_T::out_width * CONFIG_T::n_filt],
    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt])
{
    const int nin = CONFIG_T::n_chan * CONFIG_T::filt_width;
    const int nout = CONFIG_T::n_filt;
    const int rufactor = CONFIG_T::reuse_factor;
    const int block_factor = DIV_ROUNDUP(nin*nout, rufactor);

    //#pragma HLS function_instantiate variable=weights,biases
    //#pragma HLS RESOURCE         variable=weights core=RAM_2P_BRAM Commenting out the deisgnation HLS seems to choose correctly
    //#pragma HLS ARRAY_RESHAPE   variable=weights block factor=block_factor
    //#pragma HLS ARRAY_PARTITION variable=biases complete

    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan];
    res_T res_col[CONFIG_T::n_filt];

    #pragma HLS ARRAY_PARTITION variable=data_col complete
    #pragma HLS ARRAY_PARTITION variable=res_col complete
    
    HeightLoop:
    for (int i = 0; i < CONFIG_T::out_height; i++) {
        WidthLoop:
        for (int j = 0; j < CONFIG_T::out_width; j++) {
            #pragma HLS PIPELINE
            im2col_2d_cf<data_T, CONFIG_T>(data, data_col, i, j);
            dense<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
            FiltLoop:
            for (int k = 0; k < CONFIG_T::n_filt; k++) {
                //res[i * CONFIG_T::out_width * CONFIG_T::n_filt + j * CONFIG_T::n_filt + k] = res_col[k];
                res[k * CONFIG_T::out_height * CONFIG_T::out_width + i * CONFIG_T::out_width + j] = res_col[k]; // Transposed order
            }
        }
    }
}

template<class data_T, typename CONFIG_T>
void im2col_2d_cl(
    data_T data[CONFIG_T::in_height * CONFIG_T::in_width * CONFIG_T::n_chan],
    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan],
    const int row,
    const int col)
{
    int index = 0;
    for (int channel = CONFIG_T::n_chan; channel--; data++) {
        #pragma HLS UNROLL
	data_T tmp1      = tmpinput[CONFIG_T::filt_height-i1][i0];
	data_T tmp       = layer_in_row[i1-1][i0].shift(tmp1);
	tmpinput[CONFIG_T::filt_height-i1-1][i0] = tmp;
      }
    }
    shift_right_small<data_T,res_T,CONFIG_T>(tmpinput,output);
}

template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_resource_cl(
    data_T data[CONFIG_T::in_height * CONFIG_T::in_width * CONFIG_T::n_chan],
    res_T  res[CONFIG_T::out_height * CONFIG_T::out_width * CONFIG_T::n_filt],
    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt])
{
    const int nin = CONFIG_T::n_chan * CONFIG_T::filt_width;
    const int nout = CONFIG_T::n_filt;
    const int rufactor = CONFIG_T::reuse_factor;
    const int block_factor = DIV_ROUNDUP(nin*nout, rufactor);

    //#pragma HLS function_instantiate variable=weights,biases
    //#pragma HLS RESOURCE         variable=weights core=RAM_2P_BRAM Commenting out the deisgnation HLS seems to choose correctly
    //#pragma HLS ARRAY_RESHAPE   variable=weights block factor=block_factor
    //#pragma HLS ARRAY_PARTITION variable=biases complete

    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan];
    res_T res_col[CONFIG_T::n_filt];

    #pragma HLS ARRAY_PARTITION variable=data_col complete
    #pragma HLS ARRAY_PARTITION variable=res_col complete
    
    HeightLoop:
    for (int i = 0; i < CONFIG_T::out_height; i++) {
        WidthLoop:
        for (int j = 0; j < CONFIG_T::out_width; j++) {
            #pragma HLS PIPELINE
            im2col_2d_cl<data_T, CONFIG_T>(data, data_col, i, j);
            dense<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
            FiltLoop:
            for (int k = 0; k < CONFIG_T::n_filt; k++) {
                res[i * CONFIG_T::out_width * CONFIG_T::n_filt + j * CONFIG_T::n_filt + k] = res_col[k];
                //res[k * CONFIG_T::out_height * CONFIG_T::out_width + i * CONFIG_T::out_width + j] = res_col[k]; // Transposed order
            }
        }
    }
}

template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_ss(
			 hls::stream<data_T> &data,
			 hls::stream<res_T>  &res ,
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
    
    data_T iReset = data.read();
    for(int i1 = 0; i1 < CONFIG_T::n_chan; i1++) { 
      #pragma HLS UNROLL    
      tmpdata[i1] = data.read(); 
    }
    static res_T  pReset = 0;
    if(iReset==0) { 
      pX = 0; 
      pY = 0; 
      pReset = 0;
      for(unsigned iP = 0; iP < CONFIG_T::pad_left+CONFIG_T::pad_top*rowsize; iP++) nnet::cnnshiftzero_arr<data_T,res_T,CONFIG_T>(layer_in_row,layer_in);
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
	nnet::fill_image_ss<data_T,data_T,CONFIG_T>(layer_reluout,pReset,res);
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
    static int lReset = 0;
    data_T iReset = data[0].read();
    for(int i1 = 0; i1 < CONFIG_T::n_chan; i1++) { 
      #pragma HLS UNROLL
      tmpdata[i1] = data[i1+1].read(); 
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
