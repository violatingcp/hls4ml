#ifndef PARAMETERS_SPLIT_H_
#define PARAMETERS_SPLIT_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_large.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_conv.h"
#include "nnet_utils/nnet_conv_large.h"
#include "nnet_utils/nnet_conv2d.h"
#include "nnet_utils/nnet_conv2d_large.h"
#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_common.h"
#include "nnet_utils/nnet_batchnorm.h"
#include "nnet_utils/nnet_pooling.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_helpers.h"

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 3
#define N_INPUT_2_1 224
#define N_INPUT_3_1 224

#define N_SUB_INPUT_2_1 230
#define N_SUB_INPUT_3_1 230
#define N_SUB_INPUT_2_1_C 113
#define N_SUB_INPUT_3_1_C 113
//#define N_SUB_INPUT_3_1_C 57

#define N_FILT_2 64
#define N_OUT_HEIGHT_2 112
#define N_OUT_WIDTH_2 16
#define N_SUB_OUT_HEIGHT_2 112
//#define N_SUB_OUT_HEIGHT_2 56
#define N_SUB_OUT_WIDTH_2 112
#define N_FILT_HEIGHT_2 7
#define N_FILT_WIDTH_2 7
#define N_OUT_HEIGHT_5 56
//#define N_OUT_HEIGHT_5 28
#define N_OUT_WIDTH_5  56
#define N_FILT_HEIGHT_5 3
#define N_FILT_WIDTH_5 3
#define N_FILT_5 64

#define N_SUB_LAYER_OUT_1 56
#define N_SUB_LAYER_OUT_2 56
//#define N_SUB_LAYER_OUT_2 28
#define N_LAYER_OUT_3 64

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_uint<1> bias2_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,6> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 147;
    //static const unsigned n_in = 3136; //bug in script
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 7;
    static const unsigned add_lat = 4;
    typedef ap_fixed<16,6> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 3;
    static const unsigned pad_bottom = 3;
    static const unsigned pad_left = 3;
    static const unsigned pad_right = 3;
    static const unsigned in_height = N_SUB_INPUT_3_1;
    static const unsigned in_width = N_SUB_INPUT_2_1;
    static const unsigned n_chan = N_INPUT_1_1;
    static const unsigned filt_height = N_FILT_HEIGHT_2;
    static const unsigned filt_width = N_FILT_WIDTH_2;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = N_SUB_OUT_HEIGHT_2;
    static const unsigned out_width = N_SUB_OUT_WIDTH_2;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
};

struct config3 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config4 : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config5 : nnet::pooling2d_config {
   static const unsigned in_height = N_SUB_OUT_HEIGHT_2;
    static const unsigned in_width = N_SUB_OUT_WIDTH_2;
    static const unsigned n_filt = N_FILT_5;
    static const unsigned n_chan = N_FILT_5;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = N_FILT_HEIGHT_5;
    static const unsigned pool_width =  N_FILT_WIDTH_5;
    static const unsigned filt_height = N_FILT_HEIGHT_5;
    static const unsigned filt_width =  N_FILT_WIDTH_5;
    static const unsigned out_height = N_SUB_LAYER_OUT_1;
    static const unsigned out_width = N_SUB_LAYER_OUT_2;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 128;
};

#endif
