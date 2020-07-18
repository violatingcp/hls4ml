//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef NNET_MERGE_H_
#define NNET_MERGE_H_

#include "nnet_common.h"
#include "hls_stream.h"
#include <math.h>

namespace nnet {

struct merge_config
{
    static const unsigned n_elem = 10;
};

struct split_config
{
  static const unsigned n_elem = 10;
};

struct mux_config
{
  static const unsigned n_elem_full = 10;
  static const unsigned n_elem = 10;
  static const unsigned mux    = 1;
};

struct concat_config {
    static const unsigned n_elem1_0 = 10;
    static const unsigned n_elem1_1 = 10;
    static const unsigned n_elem1_2 = 10;
    static const unsigned n_elem2_0 = 10;
    static const unsigned n_elem2_1 = 10;
    static const unsigned n_elem2_2 = 10;

    static const unsigned axis = -1;
};

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void add(
    input1_T data1[CONFIG_T::n_filt],
    input2_T data2[CONFIG_T::n_filt],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_filt; ii++) {
      #pragma HLS UNROLL
      res[ii] = data1[ii] + data2[ii];
    }
}


template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void addrelu_old(
    input1_T data1[CONFIG_T::n_elem],
    input2_T data2[CONFIG_T::n_elem],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
      #pragma HLS UNROLL
      res[ii] = data1[ii] + data2[ii];
      if(res[ii] < 0) res[ii] = 0; 
    }
}

template<class input_T, class res_T, typename CONFIG_T>
void split(
	 hls::stream<input_T>  data[CONFIG_T::n_elem],
	 hls::stream<res_T>    res1[CONFIG_T::n_elem],
	 hls::stream<res_T>    res2[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
      #pragma HLS UNROLL
      input_T pData = data[ii].read();
      res1[ii].write(pData);
      res2[ii].write(pData);
    }
}


template<class input_T, class res_T, typename CONFIG_T>
void mux(
	 hls::stream<input_T>  data[CONFIG_T::n_elem_full],
	 hls::stream<res_T>    res [CONFIG_T::n_elem])
{
  static const int factor=CONFIG_T::n_elem;
  for (int jj=0; jj<CONFIG_T::n_mux; jj++) {
    for (int ii=0; ii<factor; ii++) {
      #pragma HLS UNROLL
      input_T pData = data[1+factor*jj+ii].read();
      res[ii].write(pData);
    }
  }
}


template<class input_T, class res_T, typename CONFIG_T>
void demux(
	 hls::stream<input_T>  data[CONFIG_T::n_elem],
	 hls::stream<res_T>    res [CONFIG_T::n_elem_full])
{
  static const int factor=CONFIG_T::n_elem;
  for (int jj=0; jj<CONFIG_T::n_mux; jj++) {
    for (int ii=0; ii<factor; ii++) {
      #pragma HLS UNROLL
      input_T pData = data[ii].read();
      res[1+factor*jj+ii].write(pData);
    }
  }
}

template<class input_T, class res_T, typename CONFIG_T>
void split_mux(
	 hls::stream<input_T>  data[CONFIG_T::n_elem_full],
	 hls::stream<res_T>    res1[CONFIG_T::n_elem_full],
	 hls::stream<res_T>    res2[CONFIG_T::n_elem_full])
{
  hls::stream<input_T>  tmpdata[CONFIG_T::n_elem];
  #pragma HLS STREAM variable=tmpdata depth=CONFIG_T::n_mux dim=1

  hls::stream<input_T>  tmpres1[CONFIG_T::n_elem];
  #pragma HLS STREAM variable=tmpres1 depth=CONFIG_T::n_mux dim=1

  hls::stream<input_T>  tmpres2[CONFIG_T::n_elem];
  #pragma HLS STREAM variable=tmpres2 depth=CONFIG_T::n_mux dim=1

  res_T pTmp = (res_T) data[0].read();
  mux<input_T,res_T,CONFIG_T>(data,tmpdata);
  for(unsigned i0 = 0; i0 < CONFIG_T::n_mux; i0++) { 
	split<input_T,res_T,CONFIG_T>(tmpdata,tmpres1,tmpres2);
  }
  res1[0].write(pTmp);
  res2[0].write(pTmp);
  demux<input_T,res_T,CONFIG_T>(tmpres1,res1);
  demux<input_T,res_T,CONFIG_T>(tmpres2,res2);
}

template<class input_T, class res_T, typename CONFIG_T>
void add(
	 hls::stream<input_T> data1[CONFIG_T::n_elem],
	 hls::stream<input_T> data2[CONFIG_T::n_elem],
	 hls::stream<res_T>   res  [CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
      #pragma HLS UNROLL
      res_T pData = data1[ii].read()+data2[ii].read();
      res[ii].write(pData);
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void addrelu(
	 hls::stream<input1_T> data1[CONFIG_T::n_elem],
	 hls::stream<input2_T> data2[CONFIG_T::n_elem],
	 hls::stream<res_T>    res  [CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
      #pragma HLS UNROLL
      res_T pData = data1[ii].read()+data2[ii].read();
      if(pData < 0) pData = 0;
      res[ii].write(pData);
    }
}

 template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void addrelu_mux(
	 hls::stream<input1_T> data1[CONFIG_T::n_elem_full],
	 hls::stream<input2_T> data2[CONFIG_T::n_elem_full],
	 hls::stream<res_T>    res  [CONFIG_T::n_elem_full])
{
  hls::stream<input1_T>  tmpdata1[CONFIG_T::n_elem];
  #pragma HLS STREAM variable=tmpdata1 depth=CONFIG_T::n_mux dim=1

  hls::stream<input2_T>  tmpdata2[CONFIG_T::n_elem];
  #pragma HLS STREAM variable=tmpdata2 depth=CONFIG_T::n_mux dim=1

  hls::stream<res_T>  tmpres[CONFIG_T::n_elem];
  #pragma HLS STREAM variable=tmpres depth=CONFIG_T::n_mux dim=1
  
  res_T pTmp1 = (res_T) data1[0].read();
  res_T pTmp2 = (res_T) data2[0].read();
  mux<input1_T,input1_T,CONFIG_T>(data1,tmpdata1);
  mux<input2_T,input2_T,CONFIG_T>(data2,tmpdata2);
  for(unsigned i0 = 0; i0 < CONFIG_T::n_mux; i0++) { 
    addrelu<input1_T,input2_T,res_T,CONFIG_T>(tmpdata1,tmpdata2,tmpres);
  }
  res[0].write(pTmp1);
  demux<res_T,res_T,CONFIG_T>(tmpres,res);
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void subtract(
    input1_T data1[CONFIG_T::n_elem],
	input2_T data2[CONFIG_T::n_elem],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
        res[ii] = data1[ii] - data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void multiply(
    input1_T data1[CONFIG_T::n_elem],
	input2_T data2[CONFIG_T::n_elem],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
        res[ii] = data1[ii] * data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void average(
    input1_T data1[CONFIG_T::n_elem],
	input2_T data2[CONFIG_T::n_elem],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
        res[ii] = data1[ii] * data2[ii] / (res_T) 2;
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void maximum(
    input1_T data1[CONFIG_T::n_elem],
	input2_T data2[CONFIG_T::n_elem],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
        res[ii] = (data1[ii] > data2[ii]) ? data1[ii] : data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void minimum(
    input1_T data1[CONFIG_T::n_elem],
	input2_T data2[CONFIG_T::n_elem],
    res_T res[CONFIG_T::n_elem])
{
    for (int ii=0; ii<CONFIG_T::n_elem; ii++) {
        res[ii] = (data1[ii] < data2[ii]) ? data1[ii] : data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate1d(
    input1_T data1[CONFIG_T::n_elem1_0], 
	input2_T data2[CONFIG_T::n_elem2_0],
    res_T res[CONFIG_T::n_elem1_0 + CONFIG_T::n_elem2_0])
{
    for (int ii=0; ii<CONFIG_T::n_elem1_0; ii++) {
        res[ii] = data1[ii];
    }
    for (int ii=0; ii<CONFIG_T::n_elem2_0; ii++) {
        res[CONFIG_T::n_elem1_0 + ii] = data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate2d_0(
    input1_T data1[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1], 
	input2_T data2[CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1],
    res_T res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1])
{
    for (int ii=0; ii<CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1; ii++) {
        res[ii] = data1[ii];
    }
    for (int ii=0; ii<CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1; ii++) {
        res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 + ii] = data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate2d_1(
    input1_T data1[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1], 
	input2_T data2[CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1],
    res_T res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1])
{
    for (int ii=0; ii<CONFIG_T::n_elem1_0; ii++) {
        for (int jj=0; jj<CONFIG_T::n_elem1_1; jj++) {
            res[ii * (CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_1) + jj] = data1[ii * CONFIG_T::n_elem1_1 + jj];
        }
        for (int jj=0; jj<CONFIG_T::n_elem2_1; jj++) {
            res[ii * (CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_1) + CONFIG_T::n_elem1_1 + jj] = data2[ii * CONFIG_T::n_elem2_1 + jj];
        }
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate2d(
    input1_T data1[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1], 
	input2_T data2[CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1],
    res_T res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1])
{
    if (CONFIG_T::axis == 1 || CONFIG_T::axis == -1) {
        concatenate2d_1<input1_T, input2_T, res_T, CONFIG_T>(data1, data2, res);
    } else {
        concatenate2d_0<input1_T, input2_T, res_T, CONFIG_T>(data1, data2, res);
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate3d_0(
input1_T data1[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2],
	input2_T data2[CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2],
    res_T res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2])
{
    for (int ii=0; ii<CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2; ii++) {
        res[ii] = data1[ii];
    }
    for (int ii=0; ii<CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2; ii++) {
        res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2 + ii] = data2[ii];
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate3d_1(
input1_T data1[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2], 
	input2_T data2[CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2],
    res_T res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2])
{
    for (int ii=0; ii<CONFIG_T::n_elem1_0; ii++) {
        for (int jj=0; jj<CONFIG_T::n_elem1_1; jj++) {
            for (int kk=0; kk<CONFIG_T::n_elem1_2; kk++) {
                int res_idx = ii * (CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_1) * CONFIG_T::n_elem1_2
                            + jj * CONFIG_T::n_elem1_2
                            + kk;
                int data_idx = ii * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2
                             + jj * CONFIG_T::n_elem1_2
                             + kk;
                res[res_idx] = data1[data_idx];
            }
        }
        for (int jj=0; jj<CONFIG_T::n_elem2_1; jj++) {
            for (int kk=0; kk<CONFIG_T::n_elem2_2; kk++) {
                int res_idx = ii * (CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_1) * CONFIG_T::n_elem1_2
                            + (jj + CONFIG_T::n_elem1_1) * CONFIG_T::n_elem1_2
                            + kk;
                int data_idx = ii * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2
                             + jj * CONFIG_T::n_elem2_2
                             + kk;
                res[res_idx] = data2[data_idx];
            }
        }
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate3d_2(
input1_T data1[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2], 
	input2_T data2[CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2],
    res_T res[CONFIG_T::n_elem1_0 * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_0 * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2])
{
    for (int ii=0; ii<CONFIG_T::n_elem1_0; ii++) {
        for (int jj=0; jj<CONFIG_T::n_elem1_1; jj++) {
            for (int kk=0; kk<CONFIG_T::n_elem1_2; kk++) {
                int res_idx = ii * CONFIG_T::n_elem1_1 * (CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_2)
                            + jj * (CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_2)
                            + kk;
                int data_idx = ii * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2
                             + jj * CONFIG_T::n_elem1_2
                             + kk;
                res[res_idx] = data1[data_idx];
            }
            for (int kk=0; kk<CONFIG_T::n_elem1_2; kk++) {
                res[ii * (CONFIG_T::n_elem1_1 + CONFIG_T::n_elem2_1) + CONFIG_T::n_elem1_1 + jj] = data1[ii * CONFIG_T::n_elem2_1 + jj];
                int res_idx = ii * CONFIG_T::n_elem1_1 * (CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_2)
                            + jj * (CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2_2)
                            + kk + CONFIG_T::n_elem1_2;
                int data_idx = ii * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2
                             + jj * CONFIG_T::n_elem2_2
                             + kk;
                res[res_idx] = data2[data_idx];
            }
        }
    }
}

template<class input1_T, class input2_T, class res_T, typename CONFIG_T>
void concatenate3d(
    input1_T data1[CONFIG_T::n_elem1[0] * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2], 
	input2_T data2[CONFIG_T::n_elem2[0] * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2],
    res_T res[CONFIG_T::n_elem1[0] * CONFIG_T::n_elem1_1 * CONFIG_T::n_elem1_2 + CONFIG_T::n_elem2[0] * CONFIG_T::n_elem2_1 * CONFIG_T::n_elem2_2])
{
    if (CONFIG_T::axis == 2 || CONFIG_T::axis == -1) {
        concatenate3d_2<input1_T, input2_T, res_T, CONFIG_T>(data1, data2, res);
    } else if (CONFIG_T::axis == 1) {
        concatenate3d_1<input1_T, input2_T, res_T, CONFIG_T>(data1, data2, res);
    } else {
        concatenate3d_0<input1_T, input2_T, res_T, CONFIG_T>(data1, data2, res);
    }
}

}

#endif
