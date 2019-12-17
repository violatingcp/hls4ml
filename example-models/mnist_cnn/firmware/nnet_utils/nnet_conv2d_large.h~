#ifndef NNET_CONV2D_LARGE_H_
#define NNET_CONV2D_LARGE_H_

#include "nnet_common.h"
#include "nnet_conv2d.h"
#include "nnet_dense_large.h"

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
        dense_large<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
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
void conv_2d_large_cf(
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
            #pragma HLS PIPELINE II=CONFIG_T::reuse_factor
            im2col_2d_cf<data_T, CONFIG_T>(data, data_col, i, j);
            dense_large<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
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
  //#pragma HLS inline REGION
  static const int nchan  = CONFIG_T::n_chan;
  static const int filth  = CONFIG_T::filt_height-CONFIG_T::pad_top;
  static const int filtw  = CONFIG_T::filt_width;
  static const int padt   = -CONFIG_T::pad_top; 
  static const int padl   = -CONFIG_T::pad_left; 
  static const int height = CONFIG_T::in_height; 
  static const int width  = CONFIG_T::in_width; 
  int shifth = row * CONFIG_T::stride_height;
  int shiftw = col * CONFIG_T::stride_width;
  unsigned index = 0;
  data_T temp    = 0; 
  int input_row  = 0;
  int input_col  = 0;
  int dataindex  = 0;

  //for (int channel = CONFIG_T::n_chan; channel--; data++) {  
  for (int channel = 0; channel < nchan; channel++) {  
    #pragma HLS UNROLL
    for (int kernel_row =  0; kernel_row < filth; kernel_row++) {//add dilation
      #pragma HLS UNROLL
      input_row = padt+kernel_row+shifth;
      for (int kernel_col = 0; kernel_col < filtw; kernel_col++) {
        #pragma HLS UNROLL
	input_col = padl + kernel_col + shiftw;
	if (input_row < 0 || input_row >= height || input_col < 0 || input_col >= width) {
	  temp=0; 
	} else {
	  dataindex=input_row * width * nchan + input_col * nchan + channel;
	  temp =  data[dataindex];
	}
	data_col[index] = temp;
	index++;
      }
    }
  }
}
//Fills the temporary array to be fed in the CNN 
template<class data_T, class res_T, typename CONFIG_T>
  void fill_image(unsigned iShiftX,unsigned iShiftY,
		  data_T input[CONFIG_T::n_chan],
		  res_T  data [CONFIG_T::out_width * CONFIG_T::n_chan]) { 
  //		  res_T  data [CONFIG_T::out_height][CONFIG_T::out_width * CONFIG_T::n_chan]) { 
  #pragma HLS PIPELINE
  const unsigned lShift = iShiftY*CONFIG_T::out_width*CONFIG_T::n_chan+iShiftX*CONFIG_T::n_chan;
  for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) {
    data[lShift+i2] = input[i2];
  }
}
//Fills the temporary array to be fed in the CNN 
template<class data_T, class res_T, typename CONFIG_T>
void fill_entry(unsigned iShift,
		data_T input[CONFIG_T::n_chan],
		res_T  data [CONFIG_T::filt_width   * CONFIG_T::out_width * CONFIG_T::n_chan]) { 
  #pragma HLS PIPELINE
  static const unsigned lShift = iShift*CONFIG_T::filt_height*CONFIG_T::n_chan+(CONFIG_T::filt_height-1)*CONFIG_T::n_chan;
  for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) {
    data[lShift+i2] = input[i2];
  }
}
//Fills the temporary array to be fed in the CNN 
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_small(//To be fixed with stride
		 data_T input[CONFIG_T::filt_height * CONFIG_T::n_chan],
                 res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) { 
  //Shift register by image height
  for(int i0 = 0; i0 < CONFIG_T::filt_width-1; i0++) { 
    #pragma HLS PIPELINE II=1
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i0*CONFIG_T::filt_height*CONFIG_T::n_chan+i1*CONFIG_T::n_chan+i2] = data[(i0+1)*CONFIG_T::filt_height*CONFIG_T::n_chan+i1*CONFIG_T::n_chan+i2];
      }
    }
  }
  static const unsigned lastheight=(CONFIG_T::filt_width-1)*(CONFIG_T::filt_height)*CONFIG_T::n_chan;
  for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
    #pragma HLS UNROLL
    for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
      data[lastheight+i1*CONFIG_T::n_chan+i2] = input[i1*CONFIG_T::n_chan+i2];
    }
  }
}
template<class data_T, class res_T, typename CONFIG_T>
void shift_right(unsigned iShift,
		 data_T input[CONFIG_T::out_height*CONFIG_T::filt_height * CONFIG_T::n_chan],
                 res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) {
  #pragma HLS PIPELINE
  const unsigned shift=iShift*CONFIG_T::filt_height * CONFIG_T::n_chan;
  data_T tmpinput[CONFIG_T::filt_height * CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
  for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      tmpinput[i1*CONFIG_T::n_chan+i0] = input[shift+i0*CONFIG_T::filt_height+i1];
    }
  } 
  shift_right_small<data_T,res_T,CONFIG_T>(tmpinput,data);
}
//with stride
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_small_stride(//To be fixed with stride
			      data_T input[CONFIG_T::stride_width][CONFIG_T::filt_height * CONFIG_T::n_chan],
			      res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) { 
  
  //Shift register by image height
  static const unsigned filt_width = CONFIG_T::filt_width-CONFIG_T::stride_width;
  for(unsigned i0 = 0; i0 < filt_width; i0++) { 
    #pragma HLS PIPELINE II=1
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i0*CONFIG_T::filt_height*CONFIG_T::n_chan+i1*CONFIG_T::n_chan+i2] = data[(i0+1)*CONFIG_T::filt_height*CONFIG_T::n_chan+i1*CONFIG_T::n_chan+i2];
      }
    }
  }
  static const unsigned lastheight=(CONFIG_T::filt_width-CONFIG_T::stride_width)*(CONFIG_T::filt_height)*CONFIG_T::n_chan;
  for(unsigned i0 = 0; i0 < CONFIG_T::stride_width; i0++) { 
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
     #pragma HLS UNROLL
     for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
      data[lastheight+i0*CONFIG_T::filt_height+i1*CONFIG_T::n_chan+i2] = input[i0][i1*CONFIG_T::n_chan+i2];
     }
    }
  }
}
template<class data_T, class res_T, typename CONFIG_T>
void shift_right_stride(unsigned iShift,
			data_T input[CONFIG_T::out_height*CONFIG_T::filt_height * CONFIG_T::n_chan],
			res_T  data[CONFIG_T::filt_width   * CONFIG_T::filt_height * CONFIG_T::n_chan]) {
  #pragma HLS PIPELINE
  const unsigned shift=(iShift-1)*CONFIG_T::filt_height * CONFIG_T::n_chan*CONFIG_T::stride_width;
  data_T tmpinput[CONFIG_T::stride_width][CONFIG_T::filt_height * CONFIG_T::n_chan]; //note this breaks for stride larger than filter size
  #pragma HLS ARRAY_RESHAPE variable=tmpinput complete dim=0
  unsigned index = 0;
  for(int i0 = 0; i0 < CONFIG_T::stride_width; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::n_chan; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::filt_height; i2++) { 
	tmpinput[i0][i2*CONFIG_T::n_chan+i1] = input[index];
	index++;
      }
    } 
  }
  shift_right_small_stride<data_T,res_T,CONFIG_T>(tmpinput,data);
}
//Fills the temporary array to be fed in the CNN
template<class data_T, class res_T, typename CONFIG_T>
void reset_down(//To be fixed with stride
  		 data_T input[CONFIG_T::out_width  * CONFIG_T::filt_height* CONFIG_T::n_chan],
                 res_T  data [CONFIG_T::filt_width * CONFIG_T::filt_height* CONFIG_T::n_chan]) { 
  //Shift register by image height
  #pragma HLS PIPELINE
  for(int i0 = 0; i0 < CONFIG_T::filt_width; i0++) { 
    for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i0*CONFIG_T::filt_height*CONFIG_T::n_chan+i1*CONFIG_T::n_chan+i2] = input[i0*CONFIG_T::filt_height*CONFIG_T::n_chan+i1*CONFIG_T::n_chan+i2];
      }
    }
  }
}
//Shifts whole row
template<class data_T, class res_T, typename CONFIG_T>
void shift_down(//To be fixed with stride
  		 data_T input[CONFIG_T::out_width * CONFIG_T::n_chan],
                 res_T  data [CONFIG_T::filt_height* CONFIG_T::out_width * CONFIG_T::n_chan]) { 
  //Shift register by image height
  #pragma HLS PIPELINE 
  for(int i1 = 0; i1 < CONFIG_T::out_width; i1++) { 
    for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
      for(int i0 = 0; i0 < CONFIG_T::filt_height-1; i0++) { 
	data[i1*CONFIG_T::n_chan*CONFIG_T::filt_height+i2*CONFIG_T::filt_height+i0] = data[i1*CONFIG_T::n_chan*CONFIG_T::filt_height+i2*CONFIG_T::filt_height + i0+1];
      }
    }
  }
  for(int i1 = 0; i1 < CONFIG_T::out_width; i1++) {
    for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) {
      data[i1*CONFIG_T::n_chan*CONFIG_T::filt_height+i2*CONFIG_T::filt_height+CONFIG_T::filt_height-1] = input[i1*CONFIG_T::n_chan+i2];
    }
  }
}

//Shifts whole row
template<class data_T, typename CONFIG_T>
void shift_down_small(//To be fixed with stride
		      data_T  data [CONFIG_T::filt_height* CONFIG_T::out_width * CONFIG_T::n_chan]) {
  //Shift register by image height
  #pragma HLS PIPELINE 
  for(int i1 = 0; i1 < CONFIG_T::out_width; i1++) { 
    for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
      for(int i0 = 0; i0 < CONFIG_T::filt_height-1; i0++) { 
	data[i1*CONFIG_T::n_chan*CONFIG_T::filt_height+i2*CONFIG_T::filt_height+i0] = data[i1*CONFIG_T::n_chan*CONFIG_T::filt_height+i2*CONFIG_T::filt_height+i0+1];
      }
    }
  }
}

//Shifts whole row
template<class data_T, typename CONFIG_T>
void shift_down_small_stride(//To be fixed with stride
			     data_T  data [CONFIG_T::filt_height* CONFIG_T::out_width * CONFIG_T::n_chan]) {
  //Shift register by image height
  #pragma HLS PIPELINE 
  for(unsigned i0 = 0; i0 < CONFIG_T::out_width; i0++) { 
    for(unsigned i1 = 0; i1 < CONFIG_T::filt_height-CONFIG_T::stride_height; i1++) { 
      for(unsigned i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data[i0*CONFIG_T::n_chan*CONFIG_T::filt_height+i1*CONFIG_T::n_chan+i2] = data[i0*CONFIG_T::n_chan*CONFIG_T::filt_height+(i1+CONFIG_T::stride_height)*CONFIG_T::n_chan+i2];
      }
    }
  }
}


template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl(
    data_T data[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan],
    res_T  res[CONFIG_T::n_filt],
    typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
    typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt])
{
    const int nin = CONFIG_T::n_chan * CONFIG_T::filt_width;
    const int nout = CONFIG_T::n_filt;
    const int rufactor = CONFIG_T::reuse_factor;
    const int block_factor = DIV_ROUNDUP(nin*nout, rufactor);
    static const int nfilt  =  CONFIG_T::n_filt;
    static const int owidth =  CONFIG_T::out_width;
    static const int oheight =  CONFIG_T::out_height;

    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=data_col complete
    unsigned index=0;
    unsigned dataindex=0;
    for(int i0 = 0; i0 < CONFIG_T::filt_width; i0++) {  
     //This needs to be reuse factor and needs to be II of previous layer
     #pragma HLS PIPELINE II=1
     dataindex=0;
     for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
        data_col[index] = data[dataindex];
	index++;
	dataindex++;
      }
      res_T res_col[CONFIG_T::n_filt];
      #pragma HLS ARRAY_RESHAPE variable=res_col complete
      dense_large<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
      FiltLoop:
      for (int k = 0; k < CONFIG_T::n_filt; k++) {
       #pragma HLS UNROLL
       res[i1*CONFIG_T::n_chan+k] = res_col[k];
      }
     }
    }
}


template<class data_T, class res_T, typename CONFIG_T>
void conv_2d_large_cl_stream(
		      hls::stream<data_T> data[CONFIG_T::filt_height * CONFIG_T::n_chan],
		      hls::stream<res_T>  res [CONFIG_T::n_filt], //Filt Width clocks to read output
		      //res_T  res [CONFIG_T::n_filt], //Filt Width clocks to read output
		      typename CONFIG_T::weight_t weights[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan * CONFIG_T::n_filt],
		      typename CONFIG_T::bias_t   biases[CONFIG_T::n_filt]) {
    
    const int nin = CONFIG_T::n_chan * CONFIG_T::filt_width;
    const int nout = CONFIG_T::n_filt;
    const int rufactor = CONFIG_T::reuse_factor;
    const int block_factor = DIV_ROUNDUP(nin*nout, rufactor);
    static const int nfilt  =  CONFIG_T::n_filt;
    static const int owidth =  CONFIG_T::out_width;
    static const int oheight =  CONFIG_T::out_height;

    //Im2col right here with streams => Missing Stride and Padding
    data_T data_col[CONFIG_T::filt_height * CONFIG_T::filt_width * CONFIG_T::n_chan];
    #pragma HLS ARRAY_RESHAPE variable=data_col complete
    unsigned index=0;
    unsigned dataindex=0;
    for(int i0 = 0; i0 < CONFIG_T::filt_width; i0++) {  
     //This needs to be reuse factor and needs to be II of previous layer
     #pragma HLS PIPELINE II=1
     dataindex=0;
     for(int i1 = 0; i1 < CONFIG_T::filt_height; i1++) { 
      for(int i2 = 0; i2 < CONFIG_T::n_chan; i2++) { 
	data_col[index] = data[dataindex].read();
	index++;
	dataindex++;
      }
      res_T res_col[CONFIG_T::n_filt];
      #pragma HLS ARRAY_RESHAPE variable=res_col complete
      dense_large<data_T, res_T, typename CONFIG_T::mult_config>(data_col, res_col, weights, biases);
      FiltLoop:
      for (int k = 0; k < CONFIG_T::n_filt; k++) {
       #pragma HLS UNROLL
       res[i1*CONFIG_T::n_chan+k].write(res_col[k]);
      }
     }
    }
 }

}
#endif
