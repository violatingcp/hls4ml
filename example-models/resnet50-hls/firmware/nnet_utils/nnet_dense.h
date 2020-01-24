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

#ifndef NNET_DENSE_H_
#define NNET_DENSE_H_

#include "nnet_common.h"
#include "nnet_helpers.h"
#include "hls_stream.h"
#include <math.h>

namespace nnet {

struct dense_config
{
    // Internal data type definitions
    typedef float bias_t;
    typedef float weight_t;
    typedef float accum_t;

    // Layer Sizes
    static const unsigned n_in = 10;
    static const unsigned n_out = 10;

    // Resource reuse info
    static const unsigned io_type = io_parallel;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const unsigned n_zeros = 0;
    // partitioning arrays cyclically to go with roll factors?
};

/* ---
 * 4 different methods to perform the product of input and weight, depending on the
 * types of each. Use std::enable_if<>::type for the return type since partial
 * template specification is not allowed by c++
 * --- */

template<class data_T, class weight_T, class ret_T>
inline typename std::enable_if<std::is_same<data_T, ap_uint<1>>::value
        and std::is_same<weight_T, ap_uint<1>>::value, ap_uint<1>>::type
product(ap_uint<1> a, ap_uint<1> w){
    // specialisation for 1-bit weights and incoming data
    #pragma HLS inline off
    return a == w;
}

template<class data_T, class weight_T, class ret_T>
inline typename std::enable_if<(not std::is_same<data_T, ap_uint<1>>::value)
        and std::is_same<weight_T, ap_uint<1>>::value, ret_T>::type
product(data_T a, ap_uint<1> w){
    // Specialisation for 1-bit weights, arbitrary data
    #pragma HLS inline off
    return w == 0 ? (data_T) -a : a;
}

template<class data_T, class weight_T, class ret_T>
inline typename std::enable_if<(not std::is_same<data_T, ap_uint<2>>::value)
        and std::is_same<weight_T, ap_int<2>>::value, ret_T>::type
product(data_T a, ap_int<2> w){
    // Specialisation for 2-bit weights, arbitrary data
    #pragma HLS inline off
    if (w == 0) return (data_T) 0;
    else if(w == -1) return (data_T) -a;
    else return (data_T) a; // if(w == 1)
}

template<class data_T, class weight_T, class ret_T>
inline typename std::enable_if<(not std::is_same<data_T, ap_uint<1>>::value)
        and (not std::is_same<weight_T, ap_uint<1>>::value), ret_T>::type
product(data_T a, weight_T w){
    // 'Normal' product
    #pragma HLS inline off
    return a * w;
}

template<class data_T, class res_T, typename CONFIG_T>
inline typename std::enable_if<std::is_same<data_T, ap_uint<1>>::value
        and std::is_same<typename CONFIG_T::weight_t, ap_uint<1>>::value, ap_int<nnet::ceillog2(CONFIG_T::n_in) + 2>>::type
cast(typename CONFIG_T::accum_t x){
  return (ap_int<nnet::ceillog2(CONFIG_T::n_in) + 2>) (x - CONFIG_T::n_in / 2) * 2;
}

template<class data_T, class res_T, typename CONFIG_T>
inline typename std::enable_if<(not std::is_same<data_T, ap_uint<1>>::value), res_T>::type
cast(typename CONFIG_T::accum_t x){
  return (res_T) x;
}

template<class data_T, class res_T, typename CONFIG_T>
void dense_latency(
    data_T    data[CONFIG_T::n_in],
    res_T     res[CONFIG_T::n_out],
    typename CONFIG_T::weight_t  weights[CONFIG_T::n_in*CONFIG_T::n_out],
    typename CONFIG_T::bias_t    biases[CONFIG_T::n_out])
{
    data_T cache;
    typename CONFIG_T::accum_t mult[CONFIG_T::n_in*CONFIG_T::n_out];
    typename CONFIG_T::accum_t acc[CONFIG_T::n_out];

    // Use a function_instantiate in case it helps to explicitly optimize unchanging weights/biases
    #pragma HLS function_instantiate variable=weights,biases

    if (CONFIG_T::io_type == io_parallel){
        // For parallel inputs:
        //   - completely partition arrays -- target fabric
        //   - if we have an unroll factor, limit number of multipliers
        #pragma HLS PIPELINE II=CONFIG_T::reuse_factor

        // #pragma HLS ARRAY_PARTITION variable=weights complete // remove this line for now, it breaks compression sometimes
        #pragma HLS ARRAY_PARTITION variable=biases complete
        #pragma HLS ARRAY_PARTITION variable=mult complete
        #pragma HLS ARRAY_PARTITION variable=acc complete

        int multiplier_limit  = ceil(float(CONFIG_T::n_in*CONFIG_T::n_out) / float(CONFIG_T::reuse_factor)) - floor(float(CONFIG_T::n_zeros) / float(CONFIG_T::reuse_factor));
        #pragma HLS ALLOCATION instances=product limit=multiplier_limit function

    } else if (CONFIG_T::io_type == io_serial){
        // Only reduce cycle_factor if n_out is evenly divisible by reuse_factor
        // Otherwise, HLS wont be happy
        int cycle_factor = CONFIG_T::n_out / CONFIG_T::reuse_factor;
        int reused_cycle = DIV_ROUNDUP(CONFIG_T::n_out, CONFIG_T::reuse_factor);
        if (cycle_factor != reused_cycle) {
            cycle_factor = CONFIG_T::n_out;
        }
        /*int cycle_factor = CONFIG_T::n_out;
        float reused_cycle = CONFIG_T::n_out / CONFIG_T::reuse_factor;
        if (reused_cycle == ceil(reused_cycle)){
            // Dont use "ceil" here; as of 2018.2, HLS crashes mysteriously
            cycle_factor = cycle_factor / CONFIG_T::reuse_factor;
        }*/
        #pragma HLS ARRAY_PARTITION variable=weights cyclic factor=cycle_factor
        #pragma HLS ARRAY_PARTITION variable=mult cyclic factor=cycle_factor
        #pragma HLS ARRAY_PARTITION variable=acc complete
        #pragma HLS DATAFLOW
        #pragma HLS STREAM variable=mult depth=1
        #pragma HLS STREAM variable=acc depth=1
        if (CONFIG_T::store_weights_in_bram){
            #pragma HLS RESOURCE variable=weights core=ROM_2P_BRAM
        }
    }

    // Do the matrix-multiply
    Product1: for(int ii = 0; ii < CONFIG_T::n_in; ii++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS PIPELINE
        }
        cache = data[ii];
        Product2: for(int jj = 0; jj < CONFIG_T::n_out; jj++) {
            if (CONFIG_T::io_type == io_serial) {
                int multiplier_limit  = ceil(float(CONFIG_T::n_out) / float(CONFIG_T::reuse_factor));
                #pragma HLS ALLOCATION instances=product limit=multiplier_limit function
            }
        int index = ii*CONFIG_T::n_out+jj;
        mult[index] = product<data_T, typename CONFIG_T::weight_t, typename CONFIG_T::accum_t>(cache, weights[index]);
        }
    }

    // Initialize accumulator with input biases
    ResetAccum: for(int iacc = 0; iacc < CONFIG_T::n_out; iacc++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS UNROLL
        }
        acc[iacc] = (typename CONFIG_T::accum_t) biases[iacc];
    }

    // Accumulate multiplication result
    Accum1: for(int ii = 0; ii < CONFIG_T::n_in; ii++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS PIPELINE
        }
        Accum2: for(int jj = 0; jj < CONFIG_T::n_out; jj++) {
        int index = ii*CONFIG_T::n_out+jj;
        acc[jj] += mult[index];
        }
    }

    // Cast to "res_t" type
    Result: for(int ires = 0; ires < CONFIG_T::n_out; ires++){
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS UNROLL
        }
        //res[ires] = (res_T) (acc[ires]);
        res[ires] = cast<data_T, res_T, CONFIG_T>(acc[ires]);
    }
}
 template<class data_T, class res_T, typename CONFIG_T>
void dense(
    data_T    data[CONFIG_T::n_in],
    res_T     res[CONFIG_T::n_out],
    typename CONFIG_T::weight_t  weights[CONFIG_T::n_in*CONFIG_T::n_out],
    typename CONFIG_T::bias_t    biases[CONFIG_T::n_out])
{

    // Pipelining force all the loops being unrolled
    // #pragma HLS PIPELINE II=CONFIG_T::reuse_factor
    // #pragma HLS DATAFLOW

    // Replace ceil function with home-made macro prevents Vivado 2018.2 segfault
    const int totals_multipliers = CONFIG_T::n_in*CONFIG_T::n_out;
    const int multiplier_limit = DIV_ROUNDUP(CONFIG_T::n_in*CONFIG_T::n_out, CONFIG_T::reuse_factor);
    // #pragma HLS ALLOCATION instances=mul limit=multiplier_limit operation

    // Workaround the above restriction.
    // Use a function_instantiate in case it helps to explicitly optimize unchanging weights/biases
    //#pragma HLS function_instantiate variable=weights,biases
    //#pragma HLS RESOURCE        variable=weights core=ROM_1P_BRAM
    //if(CONFIG_T::store_weights_in_bram) { 
    //#pragma HLS RESOURCE        variable=weights core=ROM_2P_BRAM
    //}
    //#pragma HLS RESOURCE variable=weights core=XPM_MEMORY uram
    // #pragma HLS ARRAY_RESHAPE   variable=weights block factor=multiplier_limit
    #pragma HLS ARRAY_RESHAPE   variable=weights block factor=multiplier_limit
    #pragma HLS ARRAY_RESHAPE   variable=biases complete
    
    // typename CONFIG_T::accum_t mult[CONFIG_T::n_in*CONFIG_T::n_out];
    typename CONFIG_T::accum_t acc[CONFIG_T::n_out];
    // #pragma HLS ARRAY_RESHAPE variable=mult    block factor=multiplier_limit
    #pragma HLS ARRAY_RESHAPE variable=acc complete
    //    #pragma HLS DEPENDENCE variable=acc,weights,biases inter false
    // #pragma HLS DEPENDENCE variable=acc inter false

    // typename CONFIG_T::accum_t acc_tmp[CONFIG_T::n_out];
    // #pragma HLS ARRAY_PARTITION variable=acc_tmp complete
    // #pragma HLS DEPENDENCE variable=acc_tmp inter false

    // Initialize accumulator with input biases
    ResetAccum: for(int iacc = 0; iacc < CONFIG_T::n_out; iacc++) {
        #pragma HLS UNROLL
        acc[iacc] = (typename CONFIG_T::accum_t) biases[iacc];
    }

    // core functionality
    int rufactor=CONFIG_T::reuse_factor;
    // a tmp mult for each reuse loop iteration
    typename CONFIG_T::accum_t mult[multiplier_limit];
    #pragma HLS ARRAY_RESHAPE variable=mult complete
    //#pragma HLS DEPENDENCE variable=mult inter false

    const int ADD_LAT = DIV_ROUNDUP(multiplier_limit,CONFIG_T::n_out);
    //printf("rufactor = %i, add latency = %i, multiplier limit = %i \n", rufactor, ADD_LAT, multiplier_limit);
    ReuseLoop: for (int ir = 0; ir < rufactor; ir++){
        #pragma HLS PIPELINE II=1 
        ///////// --------------------------------------
      //printf("on this clock tick: %i \n", ir);
        MultLoop: 
        for (int im = 0; im < multiplier_limit; im++){
            int w_index   = ir + rufactor * im;
            int out_index = w_index / CONFIG_T::n_out;
            int  in_index = w_index % CONFIG_T::n_out;
            if (w_index >= CONFIG_T::n_in*CONFIG_T::n_out) continue; // check out of bounds
            mult[im] = data[in_index] * weights[w_index];
            // acc[out_index] += mult[im];
            // acc[out_index] += data[in_index] * weights[w_index];
            //printf("m++ ir = %i, im = %i, w_index = %i, in_index = %i, out_index = %i \n", ir, im, w_index, in_index, out_index);
        }
        // AccumLoop:
        // for (int im = 0; im < multiplier_limit; im++){
        //     int w_index   = ir + rufactor * im;
        //     int out_index = w_index % CONFIG_T::n_out;
        //     if (w_index >= CONFIG_T::n_in*CONFIG_T::n_out) continue; // check out of bounds
        //     acc[out_index] += mult[im];
        // }

        // special loop for accumulation
        typename CONFIG_T::accum_t acc_lat[CONFIG_T::n_out][ADD_LAT];
        #pragma HLS ARRAY_RESHAPE variable=acc_lat complete dim=0
        //#pragma HLS DEPENDENCE variable=acc_lat inter false

        AddLatencyInit: 
        for (int ii = 0; ii < CONFIG_T::n_out; ii++){
            for (int ij= 0; ij < ADD_LAT; ij++){
                #pragma UNROLL
                acc_lat[ii][ij] = 0;
            }
        }

        AccumLoop:
        // for (int im = 0; im < multiplier_limit; im += ADD_LAT){
        //     #pragma UNROLL
        //     for (int il = 0; il < ADD_LAT; il++){
        //         #pragma UNROLL
        //         // int w_index   = ir + rufactor * (im+il);
        //         int w_index   = ir * multiplier_limit + (im+il);
        //         int out_index = w_index % CONFIG_T::n_out;
        //         if (w_index >= CONFIG_T::n_in*CONFIG_T::n_out) continue; // check out of bounds
        //         acc_lat[out_index][il] += mult[im+il];
        //         // printf("im = %i; il = %i; w_index = %i; out_index = %i \n", im, il, w_index, out_index);
        //     }
        // }
        for (int io = 0; io < CONFIG_T::n_out; io++){
            #pragma HLS UNROLL
            for (int ia = 0; ia < ADD_LAT; ia++){
                #pragma HLS UNROLL
                int w_index_acc    = ir * multiplier_limit + (io*ADD_LAT + ia);
                int mult_index_acc = (io*ADD_LAT + ia); 
                int out_index_acc  = w_index_acc % CONFIG_T::n_out;
                
                if (mult_index_acc >= multiplier_limit) continue;
                if (w_index_acc >= CONFIG_T::n_in*CONFIG_T::n_out) continue; // check out of bounds
                
                acc_lat[out_index_acc][ia] += mult[mult_index_acc];
                printf("a++ ir = %i, io = %i, ia = %i, w_index = %i, out_index = %i, mult_index = %i \n", ir, io, ia, w_index_acc, out_index_acc, mult_index_acc);
            }
        }
        // printf("\n");

        FullAccum: 
        for (int ii = 0; ii < CONFIG_T::n_out; ii++){
            #pragma HLS UNROLL
            for (int ij= 0; ij < ADD_LAT; ij++){
                acc[ii] += acc_lat[ii][ij];
            }
        }    
        ///////// --------------------------------------

    }

    // Cast to "res_t" type
    Result: for(int ires = 0; ires < CONFIG_T::n_out; ires++){
        #pragma HLS UNROLL
        //printf("acc[%i] = %0.4f ", ires, (float) acc[ires]);
        res[ires] = (res_T) (acc[ires]);
    }    
    //printf("\n");

}
 /*
template<class data_T, class res_T, typename CONFIG_T>
void dense(
    data_T    data[CONFIG_T::n_in],
    res_T     res[CONFIG_T::n_out],
    typename CONFIG_T::weight_t  weights[CONFIG_T::n_in*CONFIG_T::n_out],
    typename CONFIG_T::bias_t    biases[CONFIG_T::n_out])
{
    data_T cache;
    typename CONFIG_T::accum_t mult[CONFIG_T::n_in*CONFIG_T::n_out];
    typename CONFIG_T::accum_t acc[CONFIG_T::n_out];

    // Use a function_instantiate in case it helps to explicitly optimize unchanging weights/biases
    //#pragma HLS function_instantiate variable=weights,biases

        // For parallel inputs:
        //   - completely partition arrays -- target fabric
        //   - if we have an unroll factor, limit number of multipliers
        #pragma HLS PIPELINE II=CONFIG_T::reuse_factor

        static const int block_factor       = (CONFIG_T::n_in*CONFIG_T::n_out/CONFIG_T::reuse_factor); //DIV_ROUNDUP(CONFIG_T::n_in*CONFIG_T::n_out, CONFIG_T::reuse_factor);
	//std::cout << " ---> " << CONFIG_T::n_in*CONFIG_T::n_out << " -- " << CONFIG_T::reuse_factor << " --- " << (CONFIG_T::n_in*CONFIG_T::n_out/CONFIG_T::reuse_factor) << std::endl;
        //#pragma HLS ARRAY_PARTITION variable=weights block factor=block_factor // remove this line for now, it breaks compression sometimes
        //#pragma HLS ARRAY_PARTITION variable=weights complete // remove this line for now, it breaks compression sometimes
        #pragma HLS ARRAY_RESHAPE variable=biases complete
        //#pragma HLS ARRAY_RESHAPE   variable=weights block factor=block_factor
        #pragma HLS ARRAY_RESHAPE   variable=mult block factor=block_factor
        //#pragma HLS ARRAY_PARTITION   variable=mult complete
        #pragma HLS ARRAY_RESHAPE variable=acc complete

	int multiplier_limit  = ceil(float(CONFIG_T::n_in*CONFIG_T::n_out) / float(CONFIG_T::reuse_factor)) - floor(float(CONFIG_T::n_zeros) / float(CONFIG_T::reuse_factor));
	#pragma HLS ALLOCATION instances=mul limit=multiplier_limit operation

    // Do the matrix-multiply
    Product1: for(int ii = 0; ii < CONFIG_T::n_in; ii++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS PIPELINE
        }
        cache = data[ii];
        Product2: for(int jj = 0; jj < CONFIG_T::n_out; jj++) {
            mult[ii*CONFIG_T::n_out+jj] = cache * weights[ii*CONFIG_T::n_out+jj];
        }
    }

    // Initialize accumulator with input biases
    ResetAccum: for(int iacc = 0; iacc < CONFIG_T::n_out; iacc++) {
        #pragma HLS UNROLL
        acc[iacc] = (typename CONFIG_T::accum_t) biases[iacc];
    }

    // special loop for accumulation
    typename CONFIG_T::accum_t acc_lat[CONFIG_T::n_out][CONFIG_T::add_lat];
    #pragma HLS ARRAY_RESHAPE variable=acc_lat complete dim=0
    AddLatencyInit: 
    for (int ii = 0; ii < CONFIG_T::n_out; ii++){
      for (int ij= 0; ij < CONFIG_T::add_lat; ij++){
        #pragma UNROLL
	acc_lat[ii][ij] = 0;
      }
    }

         #pragma HLS UNROLL
	  for (int ia = 0; ia < CONFIG_T::add_lat; ia++){
          #pragma HLS UNROLL
	  int index = ii*CONFIG_T::n_out+io;
	  acc_lat[io][ia] += mult[index];
	}
      }
    }

 FullAccum: 
    for (int ii = 0; ii < CONFIG_T::n_out; ii++){
      #pragma HLS UNROLL
      for (int ij= 0; ij < CONFIG_T::add_lat; ij++){
	acc[ii] += acc_lat[ii][ij];
      }
     }
    // Cast to "res_t" type
    Result: for(int ires = 0; ires < CONFIG_T::n_out; ires++){
        #pragma HLS UNROLL
        res[ires] = (res_T) (acc[ires]);
    }    
}
template<class data_T, class res_T, typename CONFIG_T>
void dense(
    data_T    data[CONFIG_T::n_in],
    res_T     res[CONFIG_T::n_out],
    typename CONFIG_T::weight_t  weights[CONFIG_T::n_in*CONFIG_T::n_out],
    typename CONFIG_T::bias_t    biases[CONFIG_T::n_out])
{
    data_T cache;
    typename CONFIG_T::accum_t mult[CONFIG_T::n_in*CONFIG_T::n_out];
    typename CONFIG_T::accum_t acc[CONFIG_T::n_out];


    #pragma HLS function_instantiate variable=weights,biases
    //#pragma HLS RESOURCE variable=weights core=RAM_2P_BRAM Commenting out the deisgnation HLS seems to choose correctly
    #pragma HLS ARRAY_RESHAPE   variable=weights block factor=block_factor
    #pragma HLS ARRAY_RESHAPE variable=biases complete

    typename CONFIG_T::accum_t acc[CONFIG_T::n_out];
    #pragma HLS ARRAY_PARTITION variable=acc complete

    InitAccum:
    for (int iacc = 0; iacc < nout; iacc++) {
        #pragma HLS UNROLL
        acc[iacc] = (typename CONFIG_T::accum_t) biases[iacc];
    }


        // #pragma HLS ARRAY_PARTITION variable=weights complete // remove this line for now, it breaks compression sometimes
        #pragma HLS ARRAY_PARTITION variable=biases complete
        #pragma HLS ARRAY_PARTITION variable=mult complete
        #pragma HLS ARRAY_PARTITION variable=acc complete

        int multiplier_limit  = ceil(float(CONFIG_T::n_in*CONFIG_T::n_out) / float(CONFIG_T::reuse_factor)) - floor(float(CONFIG_T::n_zeros) / float(CONFIG_T::reuse_factor));
        #pragma HLS ALLOCATION instances=product limit=multiplier_limit function

    } 

    // Do the matrix-multiply
    Product1: for(int ii = 0; ii < CONFIG_T::n_in; ii++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS PIPELINE
        }
        cache = data[ii];
        Product2: for(int jj = 0; jj < CONFIG_T::n_out; jj++) {
            if (CONFIG_T::io_type == io_serial) {
                int multiplier_limit  = ceil(float(CONFIG_T::n_out) / float(CONFIG_T::reuse_factor));
                #pragma HLS ALLOCATION instances=product limit=multiplier_limit function
            }
        int index = ii*CONFIG_T::n_out+jj;
        mult[index] = product<data_T, typename CONFIG_T::weight_t, typename CONFIG_T::accum_t>(cache, weights[index]);
        }
    }

    // Initialize accumulator with input biases
    ResetAccum: for(int iacc = 0; iacc < CONFIG_T::n_out; iacc++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS UNROLL
        }
        acc[iacc] = (typename CONFIG_T::accum_t) biases[iacc];
    }

    // Accumulate multiplication result
    Accum1: for(int ii = 0; ii < CONFIG_T::n_in; ii++) {
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS PIPELINE
        }
        Accum2: for(int jj = 0; jj < CONFIG_T::n_out; jj++) {
        int index = ii*CONFIG_T::n_out+jj;
        acc[jj] += mult[index];
        }
    }

    // Cast to "res_t" type
    Result: for(int ires = 0; ires < CONFIG_T::n_out; ires++){
        if (CONFIG_T::io_type == io_serial){
            #pragma HLS UNROLL
        }
        //res[ires] = (res_T) (acc[ires]);
        res[ires] = cast<data_T, res_T, CONFIG_T>(acc[ires]);
    }
}
*/
}

#endif
