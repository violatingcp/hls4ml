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
//#define N_INPUT_1_1 640
//#define N_INPUT_2_1 320
//#define N_INPUT_3_1 4
//#define OUT_HEIGHT_2 640
//#define OUT_WIDTH_2 320
//#define N_FILT_2 33
//#define OUT_HEIGHT_5 322
//#define OUT_WIDTH_5 642
//#define N_FILT_5 33
//#define OUT_HEIGHT_6 320
//#define OUT_WIDTH_6 160
//#define N_FILT_6 65


#define N_INPUT_1_1 64
#define N_INPUT_2_1 32
#define N_INPUT_3_1 4
#define OUT_HEIGHT_2 64
#define OUT_WIDTH_2 32
#define N_FILT_2 33
#define OUT_HEIGHT_5 66
#define OUT_WIDTH_5 34
#define N_FILT_5 33
#define OUT_HEIGHT_6 32
#define OUT_WIDTH_6 16
#define N_FILT_6 65

//hls-fpga-machine-learning insert layer-precision
typedef ap_uint<1> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_fixed<16,6> model_weightdefault_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,6> result_t;
typedef ap_uint<27> model_bigdefault_t;

//hls-fpga-machine-learning insert layer-config
struct config2_relu : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 27;
    static const unsigned n_out = 32;
    static const unsigned reuse_factor = 27;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
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
    static const unsigned reuse_factor = 3;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_relu relu_config;
};

struct config3 : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned n_filt = 32;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t scale_t;
};

struct Relu_config4 : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config5 : nnet::pad_config {
    static const unsigned in_height = OUT_HEIGHT_2;
    static const unsigned in_width = OUT_WIDTH_2;
    static const unsigned n_chan = N_FILT_2;
    static const unsigned out_height = OUT_HEIGHT_5;
    static const unsigned out_width = OUT_WIDTH_5;
};

struct config6_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config6_mult : nnet::dense_config {
    static const unsigned n_in = 288;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 36;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config6 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_5;
    static const unsigned in_width = OUT_WIDTH_5;
    static const unsigned n_chan = N_FILT_5-1;
    static const unsigned n_chan_in = N_FILT_5;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_6-1;
    static const unsigned n_filt_in = N_FILT_6;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_6;
    static const unsigned out_width = OUT_WIDTH_6;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config6_mult mult_config;
    typedef config6_relu relu_config;
};


#endif
