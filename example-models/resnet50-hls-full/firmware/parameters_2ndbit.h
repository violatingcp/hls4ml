#ifndef PARAMETERS_2NDBIT_H_
#define PARAMETERS_2NDBIT_H_

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
#define N_INPUT_3_1 512

#define N_FILT_44 512
#define OUT_HEIGHT_44 28
#define OUT_WIDTH_44 28
#define N_FILT_46 512
#define OUT_HEIGHT_46 28
#define OUT_WIDTH_46 28
#define N_FILT_50 128
#define OUT_HEIGHT_50 28
#define OUT_WIDTH_50 28
#define N_FILT_53 128
#define OUT_HEIGHT_53 28
#define OUT_WIDTH_53 28
#define N_FILT_56 512
#define OUT_HEIGHT_56 28
#define OUT_WIDTH_56 28
#define N_FILT_60 128
#define OUT_HEIGHT_60 28
#define OUT_WIDTH_60 28
#define N_FILT_63 128
#define OUT_HEIGHT_63 28
#define OUT_WIDTH_63 28
#define N_FILT_66 512
#define OUT_HEIGHT_66 28
#define OUT_WIDTH_66 28
#define N_FILT_70 128
#define OUT_HEIGHT_70 28
#define OUT_WIDTH_70 28
#define N_FILT_73 128
#define OUT_HEIGHT_73 28
#define OUT_WIDTH_73 28
#define N_FILT_76 512
#define OUT_HEIGHT_76 28
#define OUT_WIDTH_76 28
#define N_FILT_80 256
#define OUT_HEIGHT_80 28
#define OUT_WIDTH_80 28
#define N_FILT_83 256
#define OUT_HEIGHT_83 14
#define OUT_WIDTH_83 14
#define N_FILT_86 1024
#define OUT_HEIGHT_86 14
#define OUT_WIDTH_86 14
#define N_FILT_88 1024
#define OUT_HEIGHT_88 14
#define OUT_WIDTH_88 14

#define N_LAYER_OUT_1 14
#define N_LAYER_OUT_2 14
#define N_LAYER_OUT_3 1024

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer46_t;
typedef ap_uint<1> bias46_t;
typedef ap_fixed<16,6> layer50_t;
typedef ap_uint<1> bias50_t;
typedef ap_fixed<16,6> layer51_t;
typedef ap_fixed<16,6> layer52_t;
typedef ap_fixed<16,6> layer53_t;
typedef ap_uint<1> bias53_t;
typedef ap_fixed<16,6> layer54_t;
typedef ap_fixed<16,6> layer55_t;
typedef ap_fixed<16,6> layer56_t;
typedef ap_uint<1> bias56_t;
typedef ap_fixed<16,6> layer57_t;
typedef ap_fixed<16,6> layer58_t;
typedef ap_fixed<16,6> layer59_t;
typedef ap_fixed<16,6> layer60_t;
typedef ap_uint<1> bias60_t;
typedef ap_fixed<16,6> layer61_t;
typedef ap_fixed<16,6> layer62_t;
typedef ap_fixed<16,6> layer63_t;
typedef ap_uint<1> bias63_t;
typedef ap_fixed<16,6> layer64_t;
typedef ap_fixed<16,6> layer65_t;
typedef ap_fixed<16,6> layer66_t;
typedef ap_uint<1> bias66_t;
typedef ap_fixed<16,6> layer67_t;
typedef ap_fixed<16,6> layer68_t;
typedef ap_fixed<16,6> layer69_t;
typedef ap_fixed<16,6> layer70_t;
typedef ap_uint<1> bias70_t;
typedef ap_fixed<16,6> layer71_t;
typedef ap_fixed<16,6> layer72_t;
typedef ap_fixed<16,6> layer73_t;
typedef ap_uint<1> bias73_t;
typedef ap_fixed<16,6> layer74_t;
typedef ap_fixed<16,6> layer75_t;
typedef ap_fixed<16,6> layer76_t;
typedef ap_uint<1> bias76_t;
typedef ap_fixed<16,6> layer77_t;
typedef ap_fixed<16,6> layer78_t;
typedef ap_fixed<16,6> layer79_t;
typedef ap_fixed<16,6> layer80_t;
typedef ap_uint<1> bias80_t;
typedef ap_fixed<16,6> layer81_t;
typedef ap_fixed<16,6> layer83_t;
typedef ap_uint<1> bias83_t;
typedef ap_fixed<16,6> layer84_t;
typedef ap_fixed<16,6> layer85_t;
typedef ap_fixed<16,6> layer86_t;
typedef ap_uint<1> bias86_t;
typedef ap_fixed<16,6> layer87_t;
typedef ap_fixed<16,6> layer88_t;
typedef ap_uint<1> bias88_t;
typedef ap_fixed<16,6> result_t;


struct config50_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias50_t bias_t;
    typedef model_default_t weight_t;
};

struct config50_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_50;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config50_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_50;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config50 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_44;
    static const unsigned in_width = OUT_WIDTH_44;
    static const unsigned n_chan = N_FILT_44;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_50;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_50;
    static const unsigned out_width = OUT_WIDTH_50;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias50_t bias_t;
    typedef model_default_t weight_t;
    typedef config50_mult mult_config;
    typedef config50_norm norm_config;
    typedef config50_relu relu_config;
};


struct config53_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias53_t bias_t;
    typedef model_default_t weight_t;
};

struct config53_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_53;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config53_relu : nnet::activ_config {
  static const unsigned n_in = N_FILT_53;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config53 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_50;
    static const unsigned in_width = OUT_WIDTH_50;
    static const unsigned n_chan = N_FILT_50;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_53;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_53;
    static const unsigned out_width = OUT_WIDTH_53;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias53_t bias_t;
    typedef model_default_t weight_t;
    typedef config53_mult mult_config;
    typedef config53_norm norm_config;
    typedef config53_relu relu_config;
};

struct config56_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias56_t bias_t;
    typedef model_default_t weight_t;
};

struct config56_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_56;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config56_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_56;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config56 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_53;
    static const unsigned in_width = OUT_WIDTH_53;
    static const unsigned n_chan = N_FILT_53;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_56;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_56;
    static const unsigned out_width = OUT_WIDTH_56;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias56_t bias_t;
    typedef model_default_t weight_t;
    typedef config56_mult mult_config;
    typedef config56_norm norm_config;
    typedef config56_relu relu_config;
};

struct config60_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias60_t bias_t;
    typedef model_default_t weight_t;
};

struct config60_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_60;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config60_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_60;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config60 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_56;
    static const unsigned in_width = OUT_WIDTH_56;
    static const unsigned n_chan = N_FILT_56;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_60;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_60;
    static const unsigned out_width = OUT_WIDTH_60;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias60_t bias_t;
    typedef model_default_t weight_t;
    typedef config60_mult mult_config;
    typedef config60_norm norm_config;
    typedef config60_relu relu_config;
};

struct config63_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias63_t bias_t;
    typedef model_default_t weight_t;
};

struct config63_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_63;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config63_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_63;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config63 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_60;
    static const unsigned in_width = OUT_WIDTH_60;
    static const unsigned n_chan = N_FILT_60;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_63;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_63;
    static const unsigned out_width = OUT_WIDTH_63;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias63_t bias_t;
    typedef model_default_t weight_t;
    typedef config63_mult mult_config;
    typedef config63_norm norm_config;
    typedef config63_relu relu_config;
};

struct config66_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias66_t bias_t;
    typedef model_default_t weight_t;
};

struct config66_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_66;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};


struct config66_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_66;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config66 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_63;
    static const unsigned in_width = OUT_WIDTH_63;
    static const unsigned n_chan = N_FILT_63;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_66;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_66;
    static const unsigned out_width = OUT_WIDTH_66;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias66_t bias_t;
    typedef model_default_t weight_t;
    typedef config66_mult mult_config;
    typedef config66_norm norm_config;
    typedef config66_relu relu_config;
};

struct config70_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias70_t bias_t;
    typedef model_default_t weight_t;
};

struct config70_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_70;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config70_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_70;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config70 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_66;
    static const unsigned in_width = OUT_WIDTH_66;
    static const unsigned n_chan = N_FILT_66;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_70;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_70;
    static const unsigned out_width = OUT_WIDTH_70;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias70_t bias_t;
    typedef model_default_t weight_t;
    typedef config70_mult mult_config;
    typedef config70_norm norm_config;
    typedef config70_relu relu_config;
};

struct config73_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias73_t bias_t;
    typedef model_default_t weight_t;
};

struct config73_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_73;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config73_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_73;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config73 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_70;
    static const unsigned in_width = OUT_WIDTH_70;
    static const unsigned n_chan = N_FILT_70;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_73;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_73;
    static const unsigned out_width = OUT_WIDTH_73;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias73_t bias_t;
    typedef model_default_t weight_t;
    typedef config73_mult mult_config;
    typedef config73_norm norm_config;
    typedef config73_relu relu_config;
};

struct config76_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias76_t bias_t;
    typedef model_default_t weight_t;
};

struct config76_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_76;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config76_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_76;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config76 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_73;
    static const unsigned in_width = OUT_WIDTH_73;
    static const unsigned n_chan = N_FILT_73;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_76;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_76;
    static const unsigned out_width = OUT_WIDTH_76;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias76_t bias_t;
    typedef model_default_t weight_t;
    typedef config76_mult mult_config;
    typedef config76_norm norm_config;
    typedef config76_relu relu_config;
};


struct config80_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias80_t bias_t;
    typedef model_default_t weight_t;
};

struct config80_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_80;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config80_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_80;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config80 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_76;
    static const unsigned in_width = OUT_WIDTH_76;
    static const unsigned n_chan = N_FILT_76;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_80;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_80;
    static const unsigned out_width = OUT_WIDTH_80;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias80_t bias_t;
    typedef model_default_t weight_t;
    typedef config80_mult mult_config;
    typedef config80_norm norm_config;
    typedef config80_relu relu_config;
};


struct config83_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias83_t bias_t;
    typedef model_default_t weight_t;
};

struct config83_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_83;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config83_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_83;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config83 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_80;
    static const unsigned in_width = OUT_WIDTH_80;
    static const unsigned n_chan = N_FILT_80;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_83;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_83;
    static const unsigned out_width = OUT_WIDTH_83;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias83_t bias_t;
    typedef model_default_t weight_t;
    typedef config83_mult mult_config;
    typedef config83_norm norm_config;
    typedef config83_relu relu_config;
};

struct config86_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias86_t bias_t;
    typedef model_default_t weight_t;
};

struct config86_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_86;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config86_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_86;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config86 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_83;
    static const unsigned in_width = OUT_WIDTH_83;
    static const unsigned n_chan = N_FILT_83;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_86;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_86;
    static const unsigned out_width = OUT_WIDTH_86;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias86_t bias_t;
    typedef model_default_t weight_t;
    typedef config86_mult mult_config;
    typedef config86_norm norm_config;
    typedef config86_relu relu_config;
};

struct config88_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias88_t bias_t;
    typedef model_default_t weight_t;
};

struct config88_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_88;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config88_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_88;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config88 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_76;
    static const unsigned in_width = OUT_WIDTH_76;
    static const unsigned n_chan = N_FILT_76;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_88;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_88;
    static const unsigned out_width = OUT_WIDTH_88;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias88_t bias_t;
    typedef model_default_t weight_t;
    typedef config88_mult mult_config;
    typedef config88_norm norm_config;
    typedef config88_relu relu_config;
};


#endif
