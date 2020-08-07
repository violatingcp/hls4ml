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
#define N_INPUT_1_1 56
#define N_INPUT_2_1 11
#define N_INPUT_3_1 5
#define OUT_HEIGHT_2 56
#define OUT_WIDTH_2 55
#define N_CHANNEL_2 5
#define OUT_HEIGHT_4 56
#define OUT_WIDTH_4 55
#define N_FILT_4 17
#define OUT_HEIGHT_8 28
#define OUT_WIDTH_8 27
#define N_FILT_8 17
#define OUT_HEIGHT_9 28
#define OUT_WIDTH_9 27
#define N_FILT_9 33
#define OUT_HEIGHT_13 28
#define OUT_WIDTH_13 27
#define N_FILT_13 33
#define OUT_HEIGHT_17 14
#define OUT_WIDTH_17 13
#define N_FILT_17 33
#define OUT_HEIGHT_18 14
#define OUT_WIDTH_18 13
#define N_FILT_18 65
#define OUT_HEIGHT_22 14
#define OUT_WIDTH_22 13
#define N_FILT_22 65
#define OUT_HEIGHT_26 7
#define OUT_WIDTH_26 6
#define N_FILT_26 65
#define OUT_HEIGHT_27 7
#define OUT_WIDTH_27 6
#define N_FILT_27 129
#define OUT_HEIGHT_31 7
#define OUT_WIDTH_31 6
#define N_FILT_31 129
#define OUT_HEIGHT_35 3
#define OUT_WIDTH_35 3
#define N_FILT_35 129
#define OUT_HEIGHT_36 3
#define OUT_WIDTH_36 3
#define N_FILT_36 257
#define OUT_HEIGHT_40 3
#define OUT_WIDTH_40 3
#define N_FILT_40 257
#define N_LAYER_44 257
#define N_LAYER_48 257
#define N_LAYER_52 2

#define N_IN N_FILT_40
#define N_OUT N_LAYER_44

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<12,4> model_default_t;
typedef ap_fixed<12,4> input_t;
typedef ap_fixed<12,4> layer2_t;
typedef ap_fixed<12,4> layer3_t;
typedef ap_fixed<12,4> model_weightdefault_t;
typedef ap_fixed<12,4> layer4_t;
typedef ap_fixed<12,4> layer7_t;
typedef ap_fixed<12,4> layer6_t;
typedef ap_fixed<12,4> layer8_t;
typedef ap_fixed<12,4> layer9_t;
typedef ap_fixed<12,4> layer12_t;
typedef ap_fixed<12,4> layer11_t;
typedef ap_fixed<12,4> layer13_t;
typedef ap_fixed<12,4> layer16_t;
typedef ap_fixed<12,4> layer15_t;
typedef ap_fixed<12,4> layer17_t;
typedef ap_fixed<12,4> layer18_t;
typedef ap_fixed<12,4> layer21_t;
typedef ap_fixed<12,4> layer20_t;
typedef ap_fixed<12,4> layer22_t;
typedef ap_fixed<12,4> layer25_t;
typedef ap_fixed<12,4> layer24_t;
typedef ap_fixed<12,4> layer26_t;
typedef ap_fixed<12,4> layer27_t;
typedef ap_fixed<12,4> layer30_t;
typedef ap_fixed<12,4> layer29_t;
typedef ap_fixed<12,4> layer31_t;
typedef ap_fixed<12,4> layer34_t;
typedef ap_fixed<12,4> layer33_t;
typedef ap_fixed<12,4> layer35_t;
typedef ap_fixed<12,4> layer36_t;
typedef ap_fixed<12,4> layer39_t;
typedef ap_fixed<12,4> layer38_t;
typedef ap_fixed<12,4> layer40_t;
typedef ap_fixed<12,4> layer43_t;
typedef ap_fixed<12,4> layer42_t;
typedef ap_fixed<12,4> layer44_t;
typedef ap_fixed<12,4> layer46_t;
typedef ap_fixed<12,4> layer47_t;
typedef ap_fixed<12,4> layer48_t;
typedef ap_fixed<12,4> layer50_t;
typedef ap_fixed<12,4> layer51_t;
typedef ap_fixed<12,4> layer52_t;
typedef ap_fixed<12,4> result_t;
typedef ap_uint<27> model_bigdefault_t;

//hls-fpga-machine-learning insert layer-config
struct config2 : nnet::upsampling2d_config {
    static const unsigned height_factor = 1;
    static const unsigned width_factor = 5;
    static const unsigned in_height = N_INPUT_1_1;
    static const unsigned in_width = N_INPUT_2_1;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned n_chan    = N_CHANNEL_2;
    static const nnet::Interp_Op interp_op = nnet::nearest;
};

struct config3 : nnet::batchnorm_config {
    static const unsigned n_in = N_CHANNEL_2;
    static const unsigned n_filt = 4;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 25000;
    static const bool store_weights_in_bram = false;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t scale_t;
};

struct config4_relu : nnet::activ_config {
    static const unsigned n_in = 16;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config4_mult : nnet::dense_config {
    static const unsigned n_in = 100;
    static const unsigned n_out = 16;
    static const unsigned reuse_factor = 5;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config4 : nnet::conv2d_config {
    static const unsigned pad_top = 2;
    static const unsigned pad_bottom = 2;
    static const unsigned pad_left = 2;
    static const unsigned pad_right = 2;
    static const unsigned in_height = OUT_HEIGHT_2;
    static const unsigned in_width = OUT_WIDTH_2;
    static const unsigned n_chan = N_CHANNEL_2-1;
    static const unsigned n_chan_in = N_CHANNEL_2;
    static const unsigned filt_height = 5;
    static const unsigned filt_width = 5;
    static const unsigned n_filt = N_FILT_4-1;
    static const unsigned n_filt_in = N_FILT_4;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_4;
    static const unsigned out_width = OUT_WIDTH_4;
    static const unsigned reuse_factor = 5;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config4_mult mult_config;
    typedef config4_relu relu_config;
};

struct config8 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_4;
    static const unsigned in_width = OUT_WIDTH_4;
    static const unsigned n_filt = N_FILT_8-1;
    static const unsigned n_chan = N_FILT_4-1;
    static const unsigned n_filt_in = N_FILT_8;
    static const unsigned n_chan_in = N_FILT_4;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;
    static const unsigned filt_height = 2;
    static const unsigned filt_width = 2;
    static const unsigned out_height = OUT_HEIGHT_8;
    static const unsigned out_width = OUT_WIDTH_8;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 25000;
};

struct config9_relu : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config9_mult : nnet::dense_config {
    static const unsigned n_in = 144;
    static const unsigned n_out = 32;
    static const unsigned reuse_factor = 24;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config9 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_8;
    static const unsigned in_width = OUT_WIDTH_8;
    static const unsigned n_chan = N_FILT_8-1;
    static const unsigned n_chan_in = N_FILT_8;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_9-1;
    static const unsigned n_filt_in = N_FILT_9;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_9;
    static const unsigned out_width = OUT_WIDTH_9;
    static const unsigned reuse_factor = 24;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config9_mult mult_config;
    typedef config9_relu relu_config;
};

struct config13_relu : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config13_mult : nnet::dense_config {
    static const unsigned n_in = 288;
    static const unsigned n_out = 32;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config13 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_9;
    static const unsigned in_width = OUT_WIDTH_9;
    static const unsigned n_chan = N_FILT_9-1;
    static const unsigned n_chan_in = N_FILT_9;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_13-1;
    static const unsigned n_filt_in = N_FILT_13;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_13;
    static const unsigned out_width = OUT_WIDTH_13;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config13_mult mult_config;
    typedef config13_relu relu_config;
};

struct config17 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_13;
    static const unsigned in_width = OUT_WIDTH_13;
    static const unsigned n_filt = N_FILT_17-1;
    static const unsigned n_chan = N_FILT_13-1;
    static const unsigned n_filt_in = N_FILT_17;
    static const unsigned n_chan_in = N_FILT_13;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;
    static const unsigned filt_height = 2;
    static const unsigned filt_width = 2;
    static const unsigned out_height = OUT_HEIGHT_17;
    static const unsigned out_width = OUT_WIDTH_17;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 25000;
};

struct config18_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config18_mult : nnet::dense_config {
    static const unsigned n_in = 288;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 96;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config18 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_17;
    static const unsigned in_width = OUT_WIDTH_17;
    static const unsigned n_chan = N_FILT_17-1;
    static const unsigned n_chan_in = N_FILT_17;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_18-1;
    static const unsigned n_filt_in = N_FILT_18;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_18;
    static const unsigned out_width = OUT_WIDTH_18;
    static const unsigned reuse_factor = 96;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config18_mult mult_config;
    typedef config18_relu relu_config;
};

struct config22_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config22_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 96;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config22 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_18;
    static const unsigned in_width = OUT_WIDTH_18;
    static const unsigned n_chan = N_FILT_18-1;
    static const unsigned n_chan_in = N_FILT_18;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_22-1;
    static const unsigned n_filt_in = N_FILT_22;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_22;
    static const unsigned out_width = OUT_WIDTH_22;
    static const unsigned reuse_factor = 96;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config22_mult mult_config;
    typedef config22_relu relu_config;
};

struct config26 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_22;
    static const unsigned in_width = OUT_WIDTH_22;
    static const unsigned n_filt = N_FILT_26-1;
    static const unsigned n_chan = N_FILT_22-1;
    static const unsigned n_filt_in = N_FILT_26;
    static const unsigned n_chan_in = N_FILT_22;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;
    static const unsigned filt_height = 2;
    static const unsigned filt_width = 2;
    static const unsigned out_height = OUT_HEIGHT_26;
    static const unsigned out_width = OUT_WIDTH_26;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 25000;
};

struct config27_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config27_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 576;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config27 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_26;
    static const unsigned in_width = OUT_WIDTH_26;
    static const unsigned n_chan = N_FILT_26-1;
    static const unsigned n_chan_in = N_FILT_26;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_27-1;
    static const unsigned n_filt_in = N_FILT_27;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_27;
    static const unsigned out_width = OUT_WIDTH_27;
    static const unsigned reuse_factor = 576;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config27_mult mult_config;
    typedef config27_relu relu_config;
};

struct config31_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config31_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 576;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config31 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_27;
    static const unsigned in_width = OUT_WIDTH_27;
    static const unsigned n_chan = N_FILT_27-1;
    static const unsigned n_chan_in = N_FILT_27;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_31-1;
    static const unsigned n_filt_in = N_FILT_31;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_31;
    static const unsigned out_width = OUT_WIDTH_31;
    static const unsigned reuse_factor = 576;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config31_mult mult_config;
    typedef config31_relu relu_config;
};

struct config35 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_31;
    static const unsigned in_width = OUT_WIDTH_31;
    static const unsigned n_filt = N_FILT_35-1;
    static const unsigned n_chan = N_FILT_31-1;
    static const unsigned n_filt_in = N_FILT_35;
    static const unsigned n_chan_in = N_FILT_31;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 2;
    static const unsigned pool_width = 2;
    static const unsigned filt_height = 2;
    static const unsigned filt_width = 2;
    static const unsigned out_height = OUT_HEIGHT_35;
    static const unsigned out_width = OUT_WIDTH_35;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 25000;
};

struct config36_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config36_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 2304;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config36 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_35;
    static const unsigned in_width = OUT_WIDTH_35;
    static const unsigned n_chan = N_FILT_35-1;
    static const unsigned n_chan_in = N_FILT_35;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_36-1;
    static const unsigned n_filt_in = N_FILT_36;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_36;
    static const unsigned out_width = OUT_WIDTH_36;
    static const unsigned reuse_factor = 2304;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config36_mult mult_config;
    typedef config36_relu relu_config;
};

struct config40_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config40_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 2304;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config40 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_36;
    static const unsigned in_width = OUT_WIDTH_36;
    static const unsigned n_chan = N_FILT_36-1;
    static const unsigned n_chan_in = N_FILT_36;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_40-1;
    static const unsigned n_filt_in = N_FILT_40;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_40;
    static const unsigned out_width = OUT_WIDTH_40;
    static const unsigned reuse_factor = 2304;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config40_mult mult_config;
    typedef config40_relu relu_config;
};

struct config44 : nnet::dense_config {
    static const unsigned block_factor = 9;
    //static const unsigned block_factor = 1;
    static const unsigned n_input = N_FILT_40;
    static const unsigned n_output = N_LAYER_44;
    static const unsigned n_in = OUT_HEIGHT_40*OUT_WIDTH_40*(N_FILT_40-1);
    static const unsigned n_out = N_LAYER_44-1;
    static const unsigned io_type = nnet::io_serial;
    //static const unsigned reuse_factor = 49152;//46080;// 1=> 23040;// 2 and 3 => 4608;
    //static const unsigned reuse_factor = 12288;
    //static const unsigned reuse_factor = 12288;
    static const unsigned reuse_factor = 2304; //layer2
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 589824;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct config46 : nnet::batchnorm_config {
    static const unsigned n_in = N_LAYER_44;
    static const unsigned n_filt = -1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t scale_t;
};

struct LeakyReLU_config47 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_44;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config48 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned n_input = N_LAYER_44;
    static const unsigned n_output = N_LAYER_48;
    static const unsigned n_in = N_LAYER_44-1;
    static const unsigned n_out = N_LAYER_48-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 256;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 65536;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct config50 : nnet::batchnorm_config {
    static const unsigned n_in = N_LAYER_48;
    static const unsigned n_filt = -1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t scale_t;
};

struct LeakyReLU_config51 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_48;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config52 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned n_input = N_LAYER_48;
    static const unsigned n_output = N_LAYER_52;
    static const unsigned n_in = N_LAYER_48-1;
    static const unsigned n_out = N_LAYER_52-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 256;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 256;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<12,4> accum_t;
    typedef model_weightdefault_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config54 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_52;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};


#endif
