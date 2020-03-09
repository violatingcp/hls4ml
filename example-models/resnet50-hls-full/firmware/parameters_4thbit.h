#ifndef PARAMETERS_4THBIT_H_
#define PARAMETERS_4THBIT_H_

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
#define N_INPUT_1_1 7
#define N_INPUT_2_1 7
#define N_INPUT_3_1 512

#define N_FILT_145 512
#define OUT_HEIGHT_145 7
#define OUT_WIDTH_145 7
#define N_FILT_148 2048
#define OUT_HEIGHT_148 7
#define OUT_WIDTH_148 7
#define N_FILT_150 2048
#define OUT_HEIGHT_150 7
#define OUT_WIDTH_150 7
#define N_FILT_154 512
#define OUT_HEIGHT_154 7
#define OUT_WIDTH_154 7
#define N_FILT_157 512
#define OUT_HEIGHT_157 7
#define OUT_WIDTH_157 7
#define N_FILT_160 2048
#define OUT_HEIGHT_160 7
#define OUT_WIDTH_160 7
#define N_FILT_164 512
#define OUT_HEIGHT_164 7
#define OUT_WIDTH_164 7
#define N_FILT_167 512
#define OUT_HEIGHT_167 7
#define OUT_WIDTH_167 7
#define N_FILT_170 2048
#define OUT_HEIGHT_170 7
#define OUT_WIDTH_170 7
#define OUT_HEIGHT_174 1
#define OUT_WIDTH_174 1
#define N_FILT_174 2048
//#define N_LAYER_175 1000
#define N_LAYER_175 3584

#define N_LAYER_OUT_1 7
#define N_LAYER_OUT_2 7
#define N_LAYER_OUT_3 2048


typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> layer145_t;
typedef ap_uint<1> bias145_t;
typedef ap_fixed<16,6> layer146_t;
typedef ap_fixed<16,6> layer147_t;
typedef ap_fixed<16,6> layer148_t;
typedef ap_uint<1> bias148_t;
typedef ap_fixed<16,6> layer149_t;
typedef ap_fixed<16,6> layer150_t;
typedef ap_uint<1> bias150_t;
typedef ap_fixed<16,6> layer151_t;
typedef ap_fixed<16,6> layer152_t;
typedef ap_fixed<16,6> layer153_t;
typedef ap_fixed<16,6> layer154_t;
typedef ap_uint<1> bias154_t;
typedef ap_fixed<16,6> layer155_t;
typedef ap_fixed<16,6> layer156_t;
typedef ap_fixed<16,6> layer157_t;
typedef ap_uint<1> bias157_t;
typedef ap_fixed<16,6> layer158_t;
typedef ap_fixed<16,6> layer159_t;
typedef ap_fixed<16,6> layer160_t;
typedef ap_uint<1> bias160_t;
typedef ap_fixed<16,6> layer161_t;
typedef ap_fixed<16,6> layer162_t;
typedef ap_fixed<16,6> layer163_t;
typedef ap_fixed<16,6> layer164_t;
typedef ap_uint<1> bias164_t;
typedef ap_fixed<16,6> layer165_t;
typedef ap_fixed<16,6> layer166_t;
typedef ap_fixed<16,6> layer167_t;
typedef ap_uint<1> bias167_t;
typedef ap_fixed<16,6> layer168_t;
typedef ap_fixed<16,6> layer169_t;
typedef ap_fixed<16,6> layer170_t;
typedef ap_uint<1> bias170_t;
typedef ap_fixed<16,6> layer171_t;
typedef ap_fixed<16,6> layer172_t;
typedef ap_fixed<16,6> layer173_t;
typedef ap_fixed<16,6> layer174_t;
typedef ap_fixed<16,6> layer175_t;
typedef ap_fixed<16,6> result_t;

struct config154_mult : nnet::dense_config {
    static const unsigned n_in = 2048;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2048;
    static const unsigned block_factor = 512;
    typedef ap_fixed<16,6> accum_t;
    typedef bias154_t bias_t;
    typedef model_default_t weight_t;
};

struct config154_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_154;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config154_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_154;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config154 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_148;
    static const unsigned in_width = OUT_WIDTH_148;
    static const unsigned n_chan = N_FILT_148;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_154;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_154;
    static const unsigned out_width = OUT_WIDTH_154;
    static const unsigned reuse_factor = 128;
    static const unsigned block_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias154_t bias_t;
    typedef model_default_t weight_t;
    typedef config154_mult mult_config;
    typedef config154_norm norm_config;
    typedef config154_relu relu_config;

};

struct config157_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 4608;
    static const unsigned block_factor = 512;
    typedef ap_fixed<16,6> accum_t;
    typedef bias157_t bias_t;
    typedef model_default_t weight_t;
};

struct config157_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_157;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config157_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_157;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config157 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_154;
    static const unsigned in_width = OUT_WIDTH_154;
    static const unsigned n_chan = N_FILT_154;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_157;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_157;
    static const unsigned out_width = OUT_WIDTH_157;
    static const unsigned reuse_factor = 128;
    static const unsigned block_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias157_t bias_t;
    typedef model_default_t weight_t;
    typedef config157_mult mult_config;
    typedef config157_norm norm_config;
    typedef config157_relu relu_config;
};

struct config160_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 2048;
    static const unsigned block_factor = 512;
    typedef ap_fixed<16,6> accum_t;
    typedef bias160_t bias_t;
    typedef model_default_t weight_t;
};

struct config160_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_160;
    static const unsigned n_filt = 2048;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config160_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_160;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


struct config160 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_157;
    static const unsigned in_width = OUT_WIDTH_157;
    static const unsigned n_chan = N_FILT_157;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_160;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_160;
    static const unsigned out_width = OUT_WIDTH_160;
    static const unsigned reuse_factor = 128;
    static const unsigned block_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias160_t bias_t;
    typedef model_default_t weight_t;
    typedef config160_mult mult_config;
    typedef config160_norm norm_config;
    typedef config160_relu relu_config;
};

struct config164_mult : nnet::dense_config {
    static const unsigned n_in = 2048;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2048;
    static const unsigned block_factor = 512;
    typedef ap_fixed<16,6> accum_t;
    typedef bias164_t bias_t;
    typedef model_default_t weight_t;
};

struct config164_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_164;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config164_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_164;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config164 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_160;
    static const unsigned in_width = OUT_WIDTH_160;
    static const unsigned n_chan = N_FILT_160;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_164;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_164;
    static const unsigned out_width = OUT_WIDTH_164;
    static const unsigned reuse_factor = 128;
    static const unsigned block_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias164_t bias_t;
    typedef model_default_t weight_t;
    typedef config164_mult mult_config;
    typedef config164_norm norm_config;
    typedef config164_relu relu_config;
};

struct config167_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 4608;
    static const unsigned block_factor = 512;
    typedef ap_fixed<16,6> accum_t;
    typedef bias167_t bias_t;
    typedef model_default_t weight_t;
};

struct config167_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_167;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config167_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_167;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config167 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_164;
    static const unsigned in_width = OUT_WIDTH_164;
    static const unsigned n_chan = N_FILT_164;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_167;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_167;
    static const unsigned out_width = OUT_WIDTH_167;
    static const unsigned reuse_factor = 128;
    static const unsigned block_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias167_t bias_t;
    typedef model_default_t weight_t;
    typedef config167_mult mult_config;
    typedef config167_norm norm_config;
    typedef config167_relu relu_config;
};

struct config170_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 2048;
    static const unsigned block_factor = 512;
    typedef ap_fixed<16,6> accum_t;
    typedef bias170_t bias_t;
    typedef model_default_t weight_t;
};

struct config170_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_170;
    static const unsigned n_filt = 2048;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config170_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_170;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config170 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_167;
    static const unsigned in_width = OUT_WIDTH_167;
    static const unsigned n_chan = N_FILT_167;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_170;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_170;
    static const unsigned out_width = OUT_WIDTH_170;
    static const unsigned reuse_factor = 128;
    static const unsigned block_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias170_t bias_t;
    typedef model_default_t weight_t;
    typedef config170_mult mult_config;
    typedef config170_norm norm_config;
    typedef config170_relu relu_config;
};

struct config174 : nnet::pooling2d_config {
    static const unsigned in_height = 7;
    static const unsigned in_width = OUT_HEIGHT_170;
    static const unsigned n_filt = N_FILT_174;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned pool_height = 7;
    static const unsigned pool_width = 7;
    static const unsigned out_height = OUT_HEIGHT_174;
    static const unsigned out_width = OUT_WIDTH_174;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Average;
    static const unsigned reuse = 128;
};

struct config175 : nnet::dense_config {
    static const unsigned n_in = OUT_HEIGHT_174*OUT_WIDTH_174*N_FILT_174;
    static const unsigned n_out = N_LAYER_175;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 10*OUT_HEIGHT_174*OUT_WIDTH_174*N_FILT_174;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 2048000;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<16,6> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct softmax_config176 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_175;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


#endif
