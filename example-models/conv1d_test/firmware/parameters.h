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
#define N_INPUT_1_1 80
#define N_INPUT_2_1 3
#define N_OUTPUTS_2 66
#define N_FILT_2 9
#define N_OUTPUTS_4 62
#define N_FILT_4 5
#define N_LAYER_6 33
#define N_LAYER_8 33
#define N_LAYER_10 9
#define N_LAYER_12 9
#define N_LAYER_14 9
#define N_LAYER_16 9
#define N_LAYER_18 5

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
typedef ap_fixed<16,6> layer13_t;
typedef ap_fixed<16,6> layer14_t;
typedef ap_fixed<16,6> layer15_t;
typedef ap_fixed<16,6> layer16_t;
typedef ap_fixed<16,6> layer17_t;
typedef ap_fixed<16,6> layer18_t;
typedef ap_fixed<16,6> result_t;
typedef ap_uint<27> model_bigdefault_t;

//hls-fpga-machine-learning insert layer-config
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 30;
    static const unsigned n_out = 8;
    static const unsigned reuse_factor = 100000;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config2 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned n_in = N_INPUT_1_1;
    static const unsigned n_chan = N_INPUT_2_1-1;
    static const unsigned n_chan_in = N_INPUT_2_1;
    static const unsigned filt_width = 15;
    static const unsigned n_filt = N_FILT_2-1;
    static const unsigned n_filt_in = N_FILT_2;
    static const unsigned stride = 1;
    static const unsigned dilation = 1;
    static const unsigned n_out = N_OUTPUTS_2;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config2_mult mult_config;
};

struct relu_config3 : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config4_mult : nnet::dense_config {
    static const unsigned n_in = 40;
    static const unsigned n_out = 4;
    static const unsigned reuse_factor = 100000;
    static const unsigned merge_factor = 1;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
};

struct config4 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned n_in = N_OUTPUTS_2;
    static const unsigned n_chan = N_FILT_2-1;
    static const unsigned n_chan_in = N_FILT_2;
    static const unsigned filt_width = 5;
    static const unsigned n_filt = N_FILT_4-1;
    static const unsigned n_filt_in = N_FILT_4;
    static const unsigned stride = 1;
    static const unsigned dilation = 1;
    static const unsigned n_out = N_OUTPUTS_4;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef config4_mult mult_config;
};

struct relu_config5 : nnet::activ_config {
    static const unsigned n_in = N_FILT_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config6 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_FILT_4;
    static const unsigned n_output = N_LAYER_6;
    static const unsigned n_in = (N_FILT_4-1);
    static const unsigned n_out = (N_LAYER_6-1);
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 128;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config7 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config8 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_LAYER_6;
    static const unsigned n_output = N_LAYER_8;
    static const unsigned n_in = N_LAYER_6-1;
    static const unsigned n_out = N_LAYER_8-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 1024;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config9 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_8;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config10 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_LAYER_8;
    static const unsigned n_output = N_LAYER_10;
    static const unsigned n_in = N_LAYER_8-1;
    static const unsigned n_out = N_LAYER_10-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 256;
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
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 64;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config13 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_12;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config14 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_LAYER_12;
    static const unsigned n_output = N_LAYER_14;
    static const unsigned n_in = N_LAYER_12-1;
    static const unsigned n_out = N_LAYER_14-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 3968;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config15 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_14;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config16 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_LAYER_14;
    static const unsigned n_output = N_LAYER_16;
    static const unsigned n_in = N_LAYER_14-1;
    static const unsigned n_out = N_LAYER_16-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 64;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config17 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_16;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config18 : nnet::dense_config {
    static const unsigned block_factor = 1;
    static const unsigned merge_factor = 1;
    static const unsigned n_input = N_LAYER_16;
    static const unsigned n_output = N_LAYER_18;
    static const unsigned n_in = N_LAYER_16-1;
    static const unsigned n_out = N_LAYER_18-1;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 100000;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 32;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_weightdefault_t weight_t;
    typedef model_default_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct relu_config19 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_18;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};


#endif
