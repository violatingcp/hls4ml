#ifndef NNET_UPSAMPLING2D_H_
#define NNET_UPSAMPLING2D_H_

#include "nnet_common.h"
#include <cstdlib>

namespace nnet {

// Nearest Pixels
template <typename T, typename CONFIG_T>
T pixel_nearest_cl(T data[], int h, int w, int c) {
    //int data_h = round((float)(h + 0.5)*CONFIG_T::height_factor - 0.5); // Multiply by fixed point (don't divide)
    //int data_w = round((float)(w + 0.5)*CONFIG_T::width_factor - 0.5);
    int data_h = (int)((h+0.5)*CONFIG_T::height_factor - 0.5);
    int data_w = (int)((w+0.5)*CONFIG_T::height_factor - 0.5);
  

    // Check channel first vs. channel last
    // Channel last implementation
    int data_index =  data_h * CONFIG_T::in_width*CONFIG_T::n_channel
                    + data_w * CONFIG_T::n_channel
                    + c;

    return data[data_index];
}

template <typename T, typename CONFIG_T>
T pixel_nearest_cf(T data[], int h, int w, int c) {
    //int data_h = round((float)(h + 0.5)*CONFIG_T::height_factor - 0.5);
    //int data_w = round((float)(w + 0.5)*CONFIG_T::width_factor - 0.5);
    int data_h = (int)((h+0.5)*CONFIG_T::height_factor - 0.5);
    int data_w = (int)((w+0.5)*CONFIG_T::height_factor - 0.5);

    // channel first implementation
    int data_index = c * CONFIG_T::in_width * CONFIG_T::in_height
                   + data_h * CONFIG_T::in_width
                   + data_w;

    return data[data_index];
}


// Bilinear interpolation
template <typename CONFIG_T>
int clamp_address_cl(int h, int w, int c) {
    if(h<0) h=0;
    if(w<0) w=0;
    if(h>=CONFIG_T::in_height) h=CONFIG_T::in_height-1;
    if(w>=CONFIG_T::in_width)  w=CONFIG_T::in_width-1;
    
    return h * CONFIG_T::in_width*CONFIG_T::n_channel + w * CONFIG_T::n_channel + c;
}


template <typename T, typename CONFIG_T>
T pixel_bilinear_cl(T data[], int h, int w, int c) {
    float hf = (float)(h+0.5)*CONFIG_T::height_factor - 0.5;
    float wf = (float)(w+0.5)*CONFIG_T::width_factor - 0.5;

    int data_h = floor(hf);
    int data_w = floor(wf);

    T dh = (T)(hf - (float)data_h);
    T dw = (T)(wf - (float)data_w);

    // Check boundary conditions
    T V1, V2, V3, V4;
    V1 = data[clamp_address_cl<CONFIG_T>(data_h, data_w, c)]; // (0, 0)
    V2 = data[clamp_address_cl<CONFIG_T>(data_h, data_w+1, c)]; // (1, 0)
    V3 = data[clamp_address_cl<CONFIG_T>(data_h+1, data_w, c)]; // (0, 1)
    V4 = data[clamp_address_cl<CONFIG_T>(data_h+1, data_w+1, c)]; // (1, 1)

//    return (T)dx*V1;
    return (T)((V2-V1)*dw + (V3-V1)*dh + (V1-V2-V3+V4)*dw*dh + V1);
}

template <typename T, typename CONFIG_T>
T pixel_bilinear_cf(T data[], int h, int w, int c) {
}

// Interpolation operators
enum Interp_Op { nearest, bilinear };
template<typename T, Interp_Op op, typename CONFIG_T>
T interp_op_cl(T x[], int h, int w, int c){
	switch(op){
        case nearest: return pixel_nearest_cl<T, CONFIG_T>(x, h, w, c);
        case bilinear: return pixel_bilinear_cl<T, CONFIG_T>(x, h, w, c);
   	}
}

template<typename T, Interp_Op op, typename CONFIG_T>
T interp_op_cf(T x[], int h, int w, int c){
    switch(op){
        case nearest: return pixel_nearest_cf<T, CONFIG_T>(x, h, w, c);
        case bilinear: return pixel_bilinear_cf<T, CONFIG_T>(x, h, w, c);
    }
}

struct upsampling2d_config {
    static const unsigned height_factor = 1;
    static const unsigned width_factorz = 1;
    static const unsigned in_height = 10;
    static const unsigned in_width = 10;
    static const unsigned out_height = 10;
    static const unsigned out_width = 10;
    static const unsigned n_channel = 3;
    static const Interp_Op interp_op = nearest;
};

template<class data_T, class res_T, typename CONFIG_T>
// Implement streaming
void upsampling2d_cf(
    data_T data[CONFIG_T::in_height*CONFIG_T::in_width*CONFIG_T::n_channel],
    res_T  res[CONFIG_T::out_height*CONFIG_T::out_width*CONFIG_T::n_channel]
)
{
  #pragma HLS PIPELINE
    InterpChan: for(int cc = 0; cc < CONFIG_T::n_channel; cc++){
        InterpHeight: for(int oh = 0; oh < CONFIG_T::out_height; oh++) {
            InterpWidth: for(int ow = 0; ow < CONFIG_T::out_width; ow++) {
                int res_index = cc * CONFIG_T::out_width*CONFIG_T::out_height
                              + oh * CONFIG_T::out_width
                              + ow;
                res[res_index] = interp_op_cf<data_T, CONFIG_T::interp_op, CONFIG_T>(data, oh, ow, cc); 
            }
        }
    } 
}

template<class data_T, class res_T, typename CONFIG_T>
void upsampling2d_cl(
    data_T data[CONFIG_T::in_height*CONFIG_T::in_width*CONFIG_T::n_channel],
    res_T  res[CONFIG_T::out_height*CONFIG_T::out_width*CONFIG_T::n_channel]
)
{
  #pragma HLS PIPELINE
    // Channel Last: format = [None, Height, Width, Channel]
    InterpHeight: for(int oh = 0; oh < CONFIG_T::out_height; oh++) {
        InterpWidth: for(int ow = 0; ow < CONFIG_T::out_width; ow++) {
            InterpChan: for(int cc = 0; cc < CONFIG_T::n_channel; cc++){
                // Nearest Neighbor implementation
                // For each pixel in the output image, find the nearest neighbor in the input image
                // Index in the result image
                int res_index = oh * CONFIG_T::out_width*CONFIG_T::n_channel
                              + ow * CONFIG_T::n_channel
                              + cc;

                res[res_index] = interp_op_cl<data_T, CONFIG_T::interp_op, CONFIG_T>(data, oh, ow, cc);
            } // end by-channel loop
        } // end by-width loop
    } // end by-height loop
}

//Pixel by Pixel => we could do larger streams
template<class data_T, class res_T, typename CONFIG_T>
void upsampling2d_stream(
			 hls::stream<data_T> data[CONFIG_T::n_chan],
			 hls::stream<res_T>  res[CONFIG_T::n_chan]
) {
  static unsigned pX=0; 
  static data_T layer_in_row[CONFIG_T::in_width][CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in_row complete dim=0

  static data_T layer_in[CONFIG_T::n_chan];
  #pragma HLS ARRAY_RESHAPE variable=layer_in complete dim=0
  for(int i0 = 0; i0 < CONFIG_T::n_chan; i0++) {
      #pragma HLS UNROLL
      data_T pTmp = data[i0].read();
      layer_in_row[pX][i0] =  pTmp;
      layer_in[i0] = pTmp;
  }
  for(unsigned iW = 0; iW < CONFIG_T::width_factor; iW++) { 
    #pragma HLS PIPELINE
    for(unsigned i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
      res_T pTmp = layer_in[i0];
      res[i0].write(pTmp); 
    }
  }
  if(pX == CONFIG_T::in_width && CONFIG_T::height_factor > 1) { 
    for(unsigned iH = 0; iH < CONFIG_T::height_factor; iH++) { 
     for(unsigned iX = 0; iX < CONFIG_T::out_width; iX++) { 
      #pragma HLS PIPELINE
      for(unsigned i0 = 0; i0 < CONFIG_T::n_chan; i0++) { 
       res_T pTmp = layer_in_row[iX][i0];
       res[i0].write(pTmp); 
      }
     }
    }
    pX = 0;
    pX = pX + 1;
  }
}

} // End nnet namespace

#endif
