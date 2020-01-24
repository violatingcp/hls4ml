#ifndef PARAMETERS_1STBIT_H_
#define PARAMETERS_1STBIT_H_

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
#define N_INPUT_1_1 56
#define N_INPUT_2_1 56
#define N_INPUT_2_1_C 58
#define N_INPUT_3_1 64
#define OUT_WIDTH_5 56
#define OUT_HEIGHT_5 56
#define N_FILT_5 64

#define N_FILT_6 64
#define OUT_HEIGHT_6 56
#define OUT_WIDTH_6 56
#define N_FILT_HEIGHT_6 1
#define N_FILT_WIDTH_6 1
#define N_FILT_9 64
#define OUT_HEIGHT_9 59
#define OUT_WIDTH_9 58
#define N_FILT_HEIGHT_9 3
#define N_FILT_WIDTH_9 3
#define N_FILT_12 256
#define OUT_HEIGHT_12 56
#define OUT_WIDTH_12 56
#define N_FILT_HEIGHT_12 1
#define N_FILT_WIDTH_12 1
#define N_FILT_13 256
#define N_LAYER_OUT_1 28
#define N_LAYER_OUT_2 28
#define N_LAYER_OUT_3 128


//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_uint<1> bias2_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,6> layer6_t;
typedef ap_uint<1> bias6_t;
typedef ap_fixed<16,6> layer7_t;
typedef ap_fixed<16,6> layer8_t;
typedef ap_fixed<16,6> layer9_t;
typedef ap_uint<1> bias9_t;
typedef ap_fixed<16,6> layer10_t;
typedef ap_fixed<16,6> layer11_t;
typedef ap_fixed<16,6> layer12_t;
typedef ap_fixed<16,6> layer13_t;
typedef ap_uint<1> bias12_t;
typedef ap_fixed<16,6> result_t;

struct config6_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 8;
    typedef ap_fixed<16,6> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
};

struct config6 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_5;
    static const unsigned in_width = OUT_WIDTH_5;
    static const unsigned n_chan = N_FILT_5;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt  = N_FILT_6;
    static const unsigned n_filt2 = N_FILT_6;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_6;
    static const unsigned out_width = OUT_WIDTH_6;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
    typedef config6_mult mult_config;
};

struct config7 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_6;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config8 : nnet::activ_config {
    static const unsigned n_in = N_FILT_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config9_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 36;
    typedef ap_fixed<16,6> accum_t;
    typedef bias9_t bias_t;
    typedef model_default_t weight_t;
};

struct config9 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_6;
    static const unsigned in_width = OUT_WIDTH_6;
    static const unsigned n_chan = N_FILT_6;
    static const unsigned filt_height = N_FILT_HEIGHT_9;
    static const unsigned filt_width = N_FILT_WIDTH_9;
    static const unsigned n_filt = N_FILT_9;
    static const unsigned n_filt2 = N_FILT_9;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_9;
    static const unsigned out_width = OUT_WIDTH_9;
    static const unsigned reuse_factor = 576;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias9_t bias_t;
    typedef model_default_t weight_t;
    typedef config9_mult mult_config;
};

struct config10 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_9;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config11 : nnet::activ_config {
    static const unsigned n_in = N_FILT_9;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config12_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<16,6> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
};

struct config12 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_9;
    static const unsigned in_width = OUT_WIDTH_9;
    static const unsigned n_chan = N_FILT_9;
    static const unsigned filt_height = N_FILT_HEIGHT_12;
    static const unsigned filt_width = N_FILT_WIDTH_12;
    static const unsigned n_filt = N_FILT_12;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_12;
    static const unsigned out_width = OUT_WIDTH_12;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef config12_mult mult_config;
};

struct config13 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

#endif
