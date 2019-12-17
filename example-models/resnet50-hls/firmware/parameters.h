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
#define N_INPUT_1_1 3
#define N_INPUT_2_1 224
#define N_INPUT_3_1 224

//#define N_INPUT_2_1_C 112
//#define N_INPUT_3_1_C 112

#define N_INPUT_2_1_C 12
#define N_INPUT_3_1_C 12

#define N_FILT_2 64
#define OUT_HEIGHT_2 56
#define OUT_WIDTH_2 56
#define N_FILT_HEIGHT_2 7
#define N_FILT_WIDTH_2 7
#define OUT_HEIGHT_5 56
#define OUT_WIDTH_5 56
#define N_POOL_HEIGHT_5 3
#define N_POOL_WIDTH_5 3
#define N_FILT_5 64
#define N_FILT_6 64
#define OUT_HEIGHT_6 56
#define OUT_WIDTH_6 56
#define N_FILT_HEIGHT_6 1
#define N_FILT_WIDTH_6 1
#define N_FILT_9 64
#define OUT_HEIGHT_9 56
#define OUT_WIDTH_9 56
#define N_FILT_HEIGHT_9 3
#define N_FILT_WIDTH_9 3
#define N_FILT_12 256
#define OUT_HEIGHT_12 56
#define OUT_WIDTH_12 56
#define N_FILT_14 256
#define OUT_HEIGHT_14 56
#define OUT_WIDTH_14 56
#define N_FILT_18 64
#define OUT_HEIGHT_18 56
#define OUT_WIDTH_18 56
#define N_FILT_21 64
#define OUT_HEIGHT_21 56
#define OUT_WIDTH_21 56
#define N_FILT_24 256
#define OUT_HEIGHT_24 56
#define OUT_WIDTH_24 56
#define N_FILT_28 64
#define OUT_HEIGHT_28 56
#define OUT_WIDTH_28 56
#define N_FILT_31 64
#define OUT_HEIGHT_31 56
#define OUT_WIDTH_31 56
#define N_FILT_34 256
#define OUT_HEIGHT_34 56
#define OUT_WIDTH_34 56
#define N_FILT_38 128
#define OUT_HEIGHT_38 56
#define OUT_WIDTH_38 56
#define N_FILT_41 128
//#define N_LAYER_175 1000
#define N_LAYER_175 3584

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
typedef ap_uint<1> bias12_t;
typedef ap_fixed<16,6> layer13_t;
typedef ap_fixed<16,6> layer14_t;
typedef ap_uint<1> bias14_t;
typedef ap_fixed<16,6> layer15_t;
typedef ap_fixed<16,6> layer16_t;
typedef ap_fixed<16,6> layer17_t;
typedef ap_fixed<16,6> layer18_t;
typedef ap_uint<1> bias18_t;
typedef ap_fixed<16,6> layer19_t;
typedef ap_fixed<16,6> layer20_t;
typedef ap_fixed<16,6> layer21_t;
typedef ap_uint<1> bias21_t;
typedef ap_fixed<16,6> layer22_t;
typedef ap_fixed<16,6> layer23_t;
typedef ap_fixed<16,6> layer24_t;
typedef ap_uint<1> bias24_t;
typedef ap_fixed<16,6> layer25_t;
typedef ap_fixed<16,6> layer26_t;
typedef ap_fixed<16,6> layer27_t;
typedef ap_fixed<16,6> layer28_t;
typedef ap_uint<1> bias28_t;
typedef ap_fixed<16,6> layer29_t;
typedef ap_fixed<16,6> layer30_t;
typedef ap_fixed<16,6> layer31_t;
typedef ap_uint<1> bias31_t;
typedef ap_fixed<16,6> layer32_t;
typedef ap_fixed<16,6> layer33_t;
typedef ap_fixed<16,6> layer34_t;
typedef ap_uint<1> bias34_t;
typedef ap_fixed<16,6> layer35_t;
typedef ap_fixed<16,6> layer36_t;
typedef ap_fixed<16,6> layer37_t;
typedef ap_fixed<16,6> layer38_t;
typedef ap_uint<1> bias38_t;
typedef ap_fixed<16,6> layer39_t;
typedef ap_fixed<16,6> layer175_t;
typedef ap_fixed<16,6> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 147;
    //static const unsigned n_in = 3136; //bug in script
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 294;
    typedef ap_fixed<16,6> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 3;
    static const unsigned pad_bottom = 3;
    static const unsigned pad_left = 3;
    static const unsigned pad_right = 3;
    static const unsigned in_height = N_INPUT_2_1;
    static const unsigned in_width = N_INPUT_3_1;
    static const unsigned n_chan = N_INPUT_1_1;
    static const unsigned filt_height = N_FILT_HEIGHT_2;
    static const unsigned filt_width = N_FILT_WIDTH_2;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 112;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
};

struct config3 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config4 : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config5 : nnet::pooling2d_config {
    static const unsigned in_height = 112;
    static const unsigned in_width = OUT_HEIGHT_2;
    static const unsigned n_filt = N_FILT_5;
    static const unsigned n_chan = N_FILT_5;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = N_POOL_HEIGHT_5;
    static const unsigned pool_width =  N_POOL_WIDTH_5;
    static const unsigned filt_height = N_POOL_HEIGHT_5;
    static const unsigned filt_width =  N_POOL_WIDTH_5;
    static const unsigned out_height = OUT_HEIGHT_5;
    static const unsigned out_width = OUT_WIDTH_5;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 128;
};

struct config6_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
};

struct config6 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_WIDTH_5;
    static const unsigned in_width = N_FILT_5;
    static const unsigned n_chan = OUT_HEIGHT_5;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_6;
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
    static const unsigned reuse_factor = 1152;
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
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_9;
    static const unsigned out_width = OUT_WIDTH_9;
    static const unsigned reuse_factor = 144;
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
    static const unsigned reuse_factor = 128;
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
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
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
    static const unsigned n_in = N_FILT_12;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config14_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias14_t bias_t;
    typedef model_default_t weight_t;
};

struct config14 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_WIDTH_5;
    static const unsigned in_width = N_FILT_5;
    static const unsigned n_chan = OUT_HEIGHT_5;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_14;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_14;
    static const unsigned out_width = OUT_WIDTH_14;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias14_t bias_t;
    typedef model_default_t weight_t;
    typedef config14_mult mult_config;
};

struct config15 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_14;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config16 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_12*OUT_HEIGHT_12*OUT_WIDTH_12;
};

struct relu_config17 : nnet::activ_config {
    static const unsigned n_in = N_FILT_12;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config18_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias18_t bias_t;
    typedef model_default_t weight_t;
};

struct config18 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_12;
    static const unsigned in_width = OUT_WIDTH_12;
    static const unsigned n_chan = N_FILT_12;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_18;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_18;
    static const unsigned out_width = OUT_WIDTH_18;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias18_t bias_t;
    typedef model_default_t weight_t;
    typedef config18_mult mult_config;
};

struct config19 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_18;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config20 : nnet::activ_config {
    static const unsigned n_in = N_FILT_18;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config21_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 144;
    typedef ap_fixed<16,6> accum_t;
    typedef bias21_t bias_t;
    typedef model_default_t weight_t;
};

struct config21 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_18;
    static const unsigned in_width = OUT_WIDTH_18;
    static const unsigned n_chan = N_FILT_18;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_21;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_21;
    static const unsigned out_width = OUT_WIDTH_21;
    static const unsigned reuse_factor = 144;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias21_t bias_t;
    typedef model_default_t weight_t;
    typedef config21_mult mult_config;
};

struct config22 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_21;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config23 : nnet::activ_config {
    static const unsigned n_in = N_FILT_21;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config24_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias24_t bias_t;
    typedef model_default_t weight_t;
};

struct config24 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_21;
    static const unsigned in_width = OUT_WIDTH_21;
    static const unsigned n_chan = N_FILT_21;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_24;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_24;
    static const unsigned out_width = OUT_WIDTH_24;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias24_t bias_t;
    typedef model_default_t weight_t;
    typedef config24_mult mult_config;
};

struct config25 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_24;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config26 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_24*OUT_HEIGHT_24*OUT_WIDTH_24;
};

struct relu_config27 : nnet::activ_config {
    static const unsigned n_in = N_FILT_24;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config28_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias28_t bias_t;
    typedef model_default_t weight_t;
};

struct config28 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_24;
    static const unsigned in_width = OUT_WIDTH_24;
    static const unsigned n_chan = N_FILT_24;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_28;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_28;
    static const unsigned out_width = OUT_WIDTH_28;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias28_t bias_t;
    typedef model_default_t weight_t;
    typedef config28_mult mult_config;
};

struct config29 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_28;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config30 : nnet::activ_config {
    static const unsigned n_in = N_FILT_28;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config31_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 144;
    typedef ap_fixed<16,6> accum_t;
    typedef bias31_t bias_t;
    typedef model_default_t weight_t;
};

struct config31 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_28;
    static const unsigned in_width = OUT_WIDTH_28;
    static const unsigned n_chan = N_FILT_28;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_31;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_31;
    static const unsigned out_width = OUT_WIDTH_31;
    static const unsigned reuse_factor = 144;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias31_t bias_t;
    typedef model_default_t weight_t;
    typedef config31_mult mult_config;
};

struct config32 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_31;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config33 : nnet::activ_config {
    static const unsigned n_in = N_FILT_31;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config34_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias34_t bias_t;
    typedef model_default_t weight_t;
};

struct config34 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_31;
    static const unsigned in_width = OUT_WIDTH_31;
    static const unsigned n_chan = N_FILT_31;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_34;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_34;
    static const unsigned out_width = OUT_WIDTH_34;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias34_t bias_t;
    typedef model_default_t weight_t;
    typedef config34_mult mult_config;
};

struct config35 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_34;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config36 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_34*OUT_HEIGHT_34*OUT_WIDTH_34;
};

struct relu_config37 : nnet::activ_config {
    static const unsigned n_in = N_FILT_34;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config38_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias38_t bias_t;
    typedef model_default_t weight_t;
};

struct config38 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_34;
    static const unsigned in_width = OUT_WIDTH_34;
    static const unsigned n_chan = N_FILT_34;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_38;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_38;
    static const unsigned out_width = OUT_WIDTH_38;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef bias38_t bias_t;
    typedef model_default_t weight_t;
    typedef config38_mult mult_config;
};

struct config39 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_38;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct relu_config40 : nnet::activ_config {
    static const unsigned n_in = N_FILT_38;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct softmax_config176 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_175;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


#endif
