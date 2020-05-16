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
#define N_INPUT_1_1 96
#define N_INPUT_2_1 2
#define N_OUTPUTS_2 82
#define N_FILT_2 128
#define N_OUTPUTS_4 78
#define N_FILT_4 64
#define N_LAYER_6 512
#define N_LAYER_8 512
#define N_LAYER_10 128
#define N_LAYER_12 128
#define N_LAYER_14 128
#define N_LAYER_16 128
#define N_LAYER_18 4

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
typedef ap_fixed<16,6> layer10_t;
typedef ap_fixed<16,6> layer11_t;
typedef ap_fixed<16,6> layer12_t;
typedef ap_fixed<16,6> layer13_t;
typedef ap_fixed<16,6> layer14_t;
typedef ap_fixed<16,6> layer15_t;
typedef ap_fixed<16,6> layer16_t;
typedef ap_fixed<16,6> layer17_t;
typedef ap_fixed<16,6> layer18_t;
typedef ap_fixed<16,6> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 30;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct config2_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config2 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned n_in = N_INPUT_1_1;
    static const unsigned n_chan = N_INPUT_2_1;
    static const unsigned filt_width = 15;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride = 1;
    static const unsigned dilation = 1;
    static const unsigned n_out = N_OUTPUTS_2;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_relu relu_config;
};


struct config4_mult : nnet::dense_config {
    static const unsigned n_in = 640;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct config4_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config4 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned n_in = N_OUTPUTS_2;
    static const unsigned n_chan = N_FILT_2;
    static const unsigned filt_width = 5;
    static const unsigned n_filt = N_FILT_4;
    static const unsigned stride = 1;
    static const unsigned dilation = 1;
    static const unsigned n_out = N_OUTPUTS_4;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef config4_mult mult_config;
    typedef config4_relu relu_config;
};

struct config5 : nnet::flatten_config {
    static const unsigned n_in = N_FILT_4;
    static const unsigned n_out = N_FILT_4;
    static const unsigned n_iter = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config6 : nnet::dense_config {
    static const unsigned n_in = N_FILT_4;
    static const unsigned n_out = N_LAYER_6;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 32768;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config7 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config8 : nnet::dense_config {
    static const unsigned n_in = N_LAYER_6;
    static const unsigned n_out = N_LAYER_8;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 262144;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config9 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_8;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config10 : nnet::dense_config {
    static const unsigned n_in = N_LAYER_8;
    static const unsigned n_out = N_LAYER_10;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 65536;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config11 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_10;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config12 : nnet::dense_config {
    static const unsigned n_in = N_LAYER_10;
    static const unsigned n_out = N_LAYER_12;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 16384;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config13 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_12;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config135 : nnet::flatten_config {
    static const unsigned n_in = N_LAYER_12;
    static const unsigned n_out = N_OUTPUTS_4*N_LAYER_12;
    static const unsigned n_iter = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config14 : nnet::dense_config {
    static const unsigned n_in = N_OUTPUTS_4*N_LAYER_12;
    static const unsigned n_out = N_LAYER_14;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 1277952;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config15 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_14;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config16 : nnet::dense_config {
    static const unsigned n_in = N_LAYER_14;
    static const unsigned n_out = N_LAYER_16;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 16384;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config17 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_16;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config18 : nnet::dense_config {
    static const unsigned n_in = N_LAYER_16;
    static const unsigned n_out = N_LAYER_18;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 512;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config19 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_18;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


#endif
