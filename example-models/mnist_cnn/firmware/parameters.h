#ifndef PARAMETERS_H_

#define PARAMETERS_H_

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
#define N_INPUT_1_1 28
#define N_INPUT_2_1 28
#define N_INPUT_3_1 1
#define OUT_HEIGHT_2 26
#define OUT_WIDTH_2 26
#define N_FILT_WIDTH_2  3
#define N_FILT_HEIGHT_2 3
#define N_FILT_2 32
#define OUT_HEIGHT_4 24
#define OUT_WIDTH_4 24
#define N_FILT_WIDTH_4  3
#define N_FILT_HEIGHT_4 3
#define N_FILT_4 64
#define OUT_HEIGHT_6 12
#define OUT_WIDTH_6 12
#define N_FILT_WIDTH_6  2
#define N_FILT_HEIGHT_6 2
#define N_FILT_6 64
#define N_LAYER_7_IN 256
#define N_LAYER_7 128
#define N_LAYER_9 10

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,6> layer6_t;
typedef ap_fixed<16,6> layer7_t;
typedef ap_fixed<16,6> layer8_t;
typedef ap_fixed<16,6> layer9_t;
typedef ap_fixed<16,6> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 9;
    static const unsigned n_in1 = N_FILT_HEIGHT_2;
    static const unsigned n_in2 = N_FILT_WIDTH_2;
    static const unsigned n_in3 = N_INPUT_3_1;
    static const unsigned n_out = 32;
    static const unsigned reuse_factor = 18;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct config2_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct relu_config3 : nnet::activ_config {
  static const unsigned n_in = N_FILT_2;
  static const unsigned table_size = 1024;
  static const unsigned io_type = nnet::io_parallel;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = N_INPUT_1_1;
    static const unsigned in_width = N_INPUT_2_1;
    static const unsigned n_chan = N_INPUT_3_1;
    static const unsigned filt_height = N_FILT_HEIGHT_2;
    static const unsigned filt_width = N_FILT_WIDTH_2;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_relu relu_config;
};

struct config4_mult : nnet::dense_config {
    static const unsigned n_in = 288;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct config4_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct relu_config5 : nnet::activ_config {
  static const unsigned n_in = N_FILT_4;
  static const unsigned table_size = 1024;
  static const unsigned io_type = nnet::io_parallel;
};

struct config4 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_2;
    static const unsigned in_width = OUT_WIDTH_2;
    static const unsigned n_chan = N_FILT_2;
    static const unsigned filt_height = N_FILT_HEIGHT_4;
    static const unsigned filt_width = N_FILT_WIDTH_4;
    static const unsigned n_filt = N_FILT_4;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_4;
    static const unsigned out_width = OUT_WIDTH_4;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef config4_mult mult_config;
    typedef config4_relu relu_config;
};

struct config6 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_4;
    static const unsigned in_width = OUT_WIDTH_4;
    static const unsigned n_filt = N_FILT_6;
    static const unsigned n_chan = N_FILT_6;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = N_FILT_HEIGHT_6;
    static const unsigned pool_width = N_FILT_WIDTH_6;
    static const unsigned filt_height = N_FILT_HEIGHT_6;
    static const unsigned filt_width = N_FILT_WIDTH_6;
    static const unsigned out_height = OUT_HEIGHT_6;
    static const unsigned out_width = OUT_WIDTH_6;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 64;
};

struct config7 : nnet::dense_config {
    static const unsigned n_in = OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6;
    static const unsigned n_out = N_LAYER_7;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 18432;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 1179648;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config8 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_7;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config9 : nnet::dense_config {
    static const unsigned n_in = N_LAYER_7;
    static const unsigned n_out = N_LAYER_9;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 1280;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct softmax_config10 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_9;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


#endif
