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
#include "nnet_utils/nnet_upsampling2d.h"
#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_common.h"
#include "nnet_utils/nnet_batchnorm.h"
#include "nnet_utils/nnet_pooling.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_helpers.h"

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 28
#define N_INPUT_2_1 28
#define N_INPUT_3_1 2
#define OUT_HEIGHT_2 26
#define OUT_WIDTH_2 26
#define N_FILT_2 5
#define OUT_HEIGHT_4 13
#define OUT_WIDTH_4 13
#define N_FILT_4 5
#define OUT_HEIGHT_5 11
#define OUT_WIDTH_5 11
#define N_FILT_5 9
#define OUT_HEIGHT_7 5
#define OUT_WIDTH_7 5
#define N_FILT_7 9
#define OUT_HEIGHT_8 3
#define OUT_WIDTH_8 3
#define N_FILT_8 17
#define N_LAYER_10 17
#define N_LAYER_12 11
//#define N_LAYER_12 5

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_fixed<16,6> model_weightdefault_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,6> layer6_t;
typedef ap_fixed<16,6> layer7_t;
typedef ap_fixed<16,6> layer8_t;
typedef ap_fixed<16,6> layer9_t;
typedef ap_fixed<16,6> layer10_t;
typedef ap_fixed<16,6> layer11_t;
typedef ap_fixed<16,6> layer12_t;
typedef ap_fixed<16,6> result_t;
typedef ap_uint<27> model_bigdefault_t;

//hls-fpga-machine-learning insert layer-config
struct config2_relu : nnet::activ_config {
    static const unsigned n_in = 4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 9;
    static const unsigned n_out = 4;
    static const unsigned reuse_factor = 3;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = N_INPUT_1_1;
    static const unsigned in_width = N_INPUT_2_1;
    static const unsigned n_chan = N_INPUT_3_1-1;
    static const unsigned n_chan_in = N_INPUT_3_1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_2-1;
    static const unsigned n_filt_in = N_FILT_2;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 18;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_relu relu_config;
};

struct relu_config3 : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config4 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_2;
    static const unsigned in_width = OUT_WIDTH_2;
    static const unsigned n_filt = N_FILT_4-1;
    static const unsigned n_chan = N_FILT_2-1;
    static const unsigned n_filt_in = N_FILT_4;
    static const unsigned n_chan_in = N_FILT_2;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;
    static const unsigned filt_height = 2;
    static const unsigned filt_width = 2;
    static const unsigned out_height = OUT_HEIGHT_4;
    static const unsigned out_width = OUT_WIDTH_4;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 20000;
};

struct config5_relu : nnet::activ_config {
    static const unsigned n_in = 8;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config5_mult : nnet::dense_config {
    static const unsigned n_in = 36;
    static const unsigned n_out = 8;
    static const unsigned reuse_factor = 18;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config5 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_4;
    static const unsigned in_width = OUT_WIDTH_4;
    static const unsigned n_chan = N_FILT_4-1;
    static const unsigned n_chan_in = N_FILT_4;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_5-1;
    static const unsigned n_filt_in = N_FILT_5;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_5;
    static const unsigned out_width = OUT_WIDTH_5;
    static const unsigned reuse_factor = 144;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config5_mult mult_config;
    typedef config5_relu relu_config;
};

struct relu_config6 : nnet::activ_config {
    static const unsigned n_in = N_FILT_5;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config7 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_5;
    static const unsigned in_width = OUT_WIDTH_5;
    static const unsigned n_filt = N_FILT_7-1;
    static const unsigned n_chan = N_FILT_5-1;
    static const unsigned n_filt_in = N_FILT_7;
    static const unsigned n_chan_in = N_FILT_5;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;
    static const unsigned filt_height = 2;
    static const unsigned filt_width = 2;
    static const unsigned out_height = OUT_HEIGHT_7;
    static const unsigned out_width = OUT_WIDTH_7;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 20000;
};

struct config8_relu : nnet::activ_config {
    static const unsigned n_in = 16;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config8_mult : nnet::dense_config {
    static const unsigned n_in = 72;
    static const unsigned n_out = 16;
    static const unsigned reuse_factor = 72;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config8 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_7;
    static const unsigned in_width = OUT_WIDTH_7;
    static const unsigned n_chan = N_FILT_7-1;
    static const unsigned n_chan_in = N_FILT_7;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_8-1;
    static const unsigned n_filt_in = N_FILT_8;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_8;
    static const unsigned out_width = OUT_WIDTH_8;
    static const unsigned reuse_factor = 576;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config8_mult mult_config;
    typedef config8_relu relu_config;
};

struct relu_config9 : nnet::activ_config {
    static const unsigned n_in = N_FILT_8;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config10 : nnet::dense_config {
    static const unsigned block_factor = 9;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_FILT_8;
    static const unsigned n_output = N_LAYER_10;
    static const unsigned n_in = OUT_HEIGHT_8*OUT_WIDTH_8*(N_FILT_8-1);
    static const unsigned n_out = N_LAYER_10-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = (OUT_HEIGHT_8*OUT_WIDTH_8*(N_FILT_8-1));
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 144;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config11 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_10;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config12 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_LAYER_10;
    static const unsigned n_output = N_LAYER_12;
    static const unsigned n_in = N_LAYER_10-1;
    static const unsigned n_out = N_LAYER_12-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = (N_LAYER_10-1);
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 160;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct softmax_config13 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_12;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};


#endif
