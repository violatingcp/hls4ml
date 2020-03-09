#ifndef PARAMETERS_3RDBIT_H_
#define PARAMETERS_3RDBIT_H_

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
#define N_INPUT_1_1 14
#define N_INPUT_2_1 14
#define N_INPUT_3_1 1024

#define N_FILT_83 256
#define OUT_HEIGHT_83 14
#define OUT_WIDTH_83 14
#define N_FILT_86 1024
#define OUT_HEIGHT_86 14
#define OUT_WIDTH_86 14
#define N_FILT_88 1024
#define OUT_HEIGHT_88 14
#define OUT_WIDTH_88 14
#define N_FILT_92 256
#define OUT_HEIGHT_92 14
#define OUT_WIDTH_92 14
#define N_FILT_95 256
#define OUT_HEIGHT_95 14
#define OUT_WIDTH_95 14
#define N_FILT_98 1024
#define OUT_HEIGHT_98 14
#define OUT_WIDTH_98 14
#define N_FILT_102 256
#define OUT_HEIGHT_102 14
#define OUT_WIDTH_102 14
#define N_FILT_105 256
#define OUT_HEIGHT_105 14
#define OUT_WIDTH_105 14
#define N_FILT_108 1024
#define OUT_HEIGHT_108 14
#define OUT_WIDTH_108 14
#define N_FILT_112 256
#define OUT_HEIGHT_112 14
#define OUT_WIDTH_112 14
#define N_FILT_115 256
#define OUT_HEIGHT_115 14
#define OUT_WIDTH_115 14
#define N_FILT_118 1024
#define OUT_HEIGHT_118 14
#define OUT_WIDTH_118 14
#define N_FILT_122 256
#define OUT_HEIGHT_122 14
#define OUT_WIDTH_122 14
#define N_FILT_125 256
#define OUT_HEIGHT_125 14
#define OUT_WIDTH_125 14
#define N_FILT_128 1024
#define OUT_HEIGHT_128 14
#define OUT_WIDTH_128 14
#define N_FILT_132 256
#define OUT_HEIGHT_132 14
#define OUT_WIDTH_132 14
#define N_FILT_135 256
#define OUT_HEIGHT_135 14
#define OUT_WIDTH_135 14
#define N_FILT_138 1024
#define OUT_HEIGHT_138 14
#define OUT_WIDTH_138 14
#define N_FILT_142 512
#define OUT_HEIGHT_142 14
#define OUT_WIDTH_142 14
#define N_FILT_145 512
#define OUT_HEIGHT_145 7
#define OUT_WIDTH_145 7
#define N_FILT_148 2048
#define OUT_HEIGHT_148 7
#define OUT_WIDTH_148 7
#define N_FILT_150 2048
#define OUT_HEIGHT_150 7
#define OUT_WIDTH_150 7

#define N_LAYER_OUT_1 7
#define N_LAYER_OUT_2 7
#define N_LAYER_OUT_3 2048


typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<16,6> layer83_t;
typedef ap_uint<1> bias83_t;
typedef ap_fixed<16,6> layer84_t;
typedef ap_fixed<16,6> layer85_t;
typedef ap_fixed<16,6> layer86_t;
typedef ap_uint<1> bias86_t;
typedef ap_fixed<16,6> layer87_t;
typedef ap_fixed<16,6> layer88_t;
typedef ap_uint<1> bias88_t;
typedef ap_fixed<16,6> layer89_t;
typedef ap_fixed<16,6> layer90_t;
typedef ap_fixed<16,6> layer91_t;
typedef ap_fixed<16,6> layer92_t;
typedef ap_uint<1> bias92_t;
typedef ap_fixed<16,6> layer93_t;
typedef ap_fixed<16,6> layer94_t;
typedef ap_fixed<16,6> layer95_t;
typedef ap_uint<1> bias95_t;
typedef ap_fixed<16,6> layer96_t;
typedef ap_fixed<16,6> layer97_t;
typedef ap_fixed<16,6> layer98_t;
typedef ap_uint<1> bias98_t;
typedef ap_fixed<16,6> layer99_t;
typedef ap_fixed<16,6> layer100_t;
typedef ap_fixed<16,6> layer101_t;
typedef ap_fixed<16,6> layer102_t;
typedef ap_uint<1> bias102_t;
typedef ap_fixed<16,6> layer103_t;
typedef ap_fixed<16,6> layer104_t;
typedef ap_fixed<16,6> layer105_t;
typedef ap_uint<1> bias105_t;
typedef ap_fixed<16,6> layer106_t;
typedef ap_fixed<16,6> layer107_t;
typedef ap_fixed<16,6> layer108_t;
typedef ap_uint<1> bias108_t;
typedef ap_fixed<16,6> layer109_t;
typedef ap_fixed<16,6> layer110_t;
typedef ap_fixed<16,6> layer111_t;
typedef ap_fixed<16,6> layer112_t;
typedef ap_uint<1> bias112_t;
typedef ap_fixed<16,6> layer113_t;
typedef ap_fixed<16,6> layer114_t;
typedef ap_fixed<16,6> layer115_t;
typedef ap_uint<1> bias115_t;
typedef ap_fixed<16,6> layer116_t;
typedef ap_fixed<16,6> layer117_t;
typedef ap_fixed<16,6> layer118_t;
typedef ap_uint<1> bias118_t;
typedef ap_fixed<16,6> layer119_t;
typedef ap_fixed<16,6> layer120_t;
typedef ap_fixed<16,6> layer121_t;
typedef ap_fixed<16,6> layer122_t;
typedef ap_uint<1> bias122_t;
typedef ap_fixed<16,6> layer123_t;
typedef ap_fixed<16,6> layer124_t;
typedef ap_fixed<16,6> layer125_t;
typedef ap_uint<1> bias125_t;
typedef ap_fixed<16,6> layer126_t;
typedef ap_fixed<16,6> layer127_t;
typedef ap_fixed<16,6> layer128_t;
typedef ap_uint<1> bias128_t;
typedef ap_fixed<16,6> layer129_t;
typedef ap_fixed<16,6> layer130_t;
typedef ap_fixed<16,6> layer131_t;
typedef ap_fixed<16,6> layer132_t;
typedef ap_uint<1> bias132_t;
typedef ap_fixed<16,6> layer133_t;
typedef ap_fixed<16,6> layer134_t;
typedef ap_fixed<16,6> layer135_t;
typedef ap_uint<1> bias135_t;
typedef ap_fixed<16,6> layer136_t;
typedef ap_fixed<16,6> layer137_t;
typedef ap_fixed<16,6> layer138_t;
typedef ap_uint<1> bias138_t;
typedef ap_fixed<16,6> layer139_t;
typedef ap_fixed<16,6> layer140_t;
typedef ap_fixed<16,6> layer141_t;
typedef ap_fixed<16,6> layer142_t;
typedef ap_uint<1> bias142_t;
typedef ap_fixed<16,6> layer145_t;
typedef ap_uint<1> bias145_t;
typedef ap_fixed<16,6> layer146_t;
typedef ap_fixed<16,6> layer147_t;
typedef ap_fixed<16,6> layer148_t;
typedef ap_uint<1> bias148_t;
typedef ap_fixed<16,6> layer149_t;
typedef ap_fixed<16,6> layer150_t;
typedef ap_uint<1> bias150_t;

struct config92_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias92_t bias_t;
    typedef model_default_t weight_t;
};

struct config92_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_92;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config92_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_92;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


struct config92 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_86;
    static const unsigned in_width = OUT_WIDTH_86;
    static const unsigned n_chan = N_FILT_86;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_92;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_92;
    static const unsigned out_width = OUT_WIDTH_92;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias92_t bias_t;
    typedef model_default_t weight_t;
    typedef config92_mult mult_config;
    typedef config92_norm norm_config;
    typedef config92_relu relu_config;
};

struct config95_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 2304;
    typedef ap_fixed<16,6> accum_t;
    typedef bias95_t bias_t;
    typedef model_default_t weight_t;
};

struct config95_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_95;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config95_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_95;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config95 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_92;
    static const unsigned in_width = OUT_WIDTH_92;
    static const unsigned n_chan = N_FILT_92;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_95;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_95;
    static const unsigned out_width = OUT_WIDTH_95;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias95_t bias_t;
    typedef model_default_t weight_t;
    typedef config95_mult mult_config;
    typedef config95_norm norm_config;
    typedef config95_relu relu_config;
};

struct config98_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias98_t bias_t;
    typedef model_default_t weight_t;
};

struct config98_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_98;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config98_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_98;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config98 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_95;
    static const unsigned in_width = OUT_WIDTH_95;
    static const unsigned n_chan = N_FILT_95;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_98;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_98;
    static const unsigned out_width = OUT_WIDTH_98;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias98_t bias_t;
    typedef model_default_t weight_t;
    typedef config98_mult mult_config;
    typedef config98_norm norm_config;
    typedef config98_relu relu_config;
};

struct config102_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias102_t bias_t;
    typedef model_default_t weight_t;
};

struct config102_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_102;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config102_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_102;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config102 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_98;
    static const unsigned in_width = OUT_WIDTH_98;
    static const unsigned n_chan = N_FILT_98;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_102;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_102;
    static const unsigned out_width = OUT_WIDTH_102;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias102_t bias_t;
    typedef model_default_t weight_t;
    typedef config102_mult mult_config;
    typedef config102_norm norm_config;
    typedef config102_relu relu_config;
};

struct config105_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias105_t bias_t;
    typedef model_default_t weight_t;
};

struct config105_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_105;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config105_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_105;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config105 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_102;
    static const unsigned in_width = OUT_WIDTH_102;
    static const unsigned n_chan = N_FILT_102;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_105;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_105;
    static const unsigned out_width = OUT_WIDTH_105;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias105_t bias_t;
    typedef model_default_t weight_t;
    typedef config105_mult mult_config;
    typedef config105_norm norm_config;
    typedef config105_relu relu_config;
};

struct config108_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias108_t bias_t;
    typedef model_default_t weight_t;
};

struct config108_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_108;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config108_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_108;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config108 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_105;
    static const unsigned in_width = OUT_WIDTH_105;
    static const unsigned n_chan = N_FILT_105;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_108;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_108;
    static const unsigned out_width = OUT_WIDTH_108;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias108_t bias_t;
    typedef model_default_t weight_t;
    typedef config108_mult mult_config;
    typedef config108_norm norm_config;
    typedef config108_relu relu_config;
};

struct config112_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias112_t bias_t;
    typedef model_default_t weight_t;
};

struct config112_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_112;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config112_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_112;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config112 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_108;
    static const unsigned in_width = OUT_WIDTH_108;
    static const unsigned n_chan = N_FILT_108;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_112;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_112;
    static const unsigned out_width = OUT_WIDTH_112;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias112_t bias_t;
    typedef model_default_t weight_t;
    typedef config112_mult mult_config;
    typedef config112_norm norm_config;
    typedef config112_relu relu_config;
};


struct config115_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias115_t bias_t;
    typedef model_default_t weight_t;
};

struct config115_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_115;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config115_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_115;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


struct config115 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_112;
    static const unsigned in_width = OUT_WIDTH_112;
    static const unsigned n_chan = N_FILT_112;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_115;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_115;
    static const unsigned out_width = OUT_WIDTH_115;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias115_t bias_t;
    typedef model_default_t weight_t;
    typedef config115_mult mult_config;
    typedef config115_norm norm_config;
    typedef config115_relu relu_config;
};

struct config118_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias118_t bias_t;
    typedef model_default_t weight_t;
};

struct config118_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_118;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config118_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_118;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config118 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_115;
    static const unsigned in_width = OUT_WIDTH_115;
    static const unsigned n_chan = N_FILT_115;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_118;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_118;
    static const unsigned out_width = OUT_WIDTH_118;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias118_t bias_t;
    typedef model_default_t weight_t;
    typedef config118_mult mult_config;
    typedef config118_norm norm_config;
    typedef config118_relu relu_config;
};

struct config122_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias122_t bias_t;
    typedef model_default_t weight_t;
};

struct config122_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_122;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config122_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_122;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config122 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_118;
    static const unsigned in_width = OUT_WIDTH_118;
    static const unsigned n_chan = N_FILT_118;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_122;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_122;
    static const unsigned out_width = OUT_WIDTH_122;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias122_t bias_t;
    typedef model_default_t weight_t;
    typedef config122_mult mult_config;
    typedef config122_norm norm_config;
    typedef config122_relu relu_config;
};

struct config125_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias125_t bias_t;
    typedef model_default_t weight_t;
};

struct config125_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_125;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config125_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_125;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config125 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_122;
    static const unsigned in_width = OUT_WIDTH_122;
    static const unsigned n_chan = N_FILT_122;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_125;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_125;
    static const unsigned out_width = OUT_WIDTH_125;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias125_t bias_t;
    typedef model_default_t weight_t;
    typedef config125_mult mult_config;
    typedef config125_norm norm_config;
    typedef config125_relu relu_config;
};

struct config128_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias128_t bias_t;
    typedef model_default_t weight_t;
};

struct config128_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_128;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config128_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config128 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_125;
    static const unsigned in_width = OUT_WIDTH_125;
    static const unsigned n_chan = N_FILT_125;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_128;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_128;
    static const unsigned out_width = OUT_WIDTH_128;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias128_t bias_t;
    typedef model_default_t weight_t;
    typedef config128_mult mult_config;
    typedef config128_norm norm_config;
    typedef config128_relu relu_config;
};

struct config132_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias132_t bias_t;
    typedef model_default_t weight_t;
};

struct config132_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_132;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config132_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_132;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config132 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_128;
    static const unsigned in_width = OUT_WIDTH_128;
    static const unsigned n_chan = N_FILT_128;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_132;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_132;
    static const unsigned out_width = OUT_WIDTH_132;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias132_t bias_t;
    typedef model_default_t weight_t;
    typedef config132_mult mult_config;
    typedef config132_norm norm_config;
    typedef config132_relu relu_config;
};

struct config135_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias135_t bias_t;
    typedef model_default_t weight_t;
};

struct config135_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_135;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config135_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_135;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config135 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_132;
    static const unsigned in_width = OUT_WIDTH_132;
    static const unsigned n_chan = N_FILT_132;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_135;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_135;
    static const unsigned out_width = OUT_WIDTH_135;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias135_t bias_t;
    typedef model_default_t weight_t;
    typedef config135_mult mult_config;
    typedef config135_norm norm_config;
    typedef config135_relu relu_config;
};


struct config138_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias138_t bias_t;
    typedef model_default_t weight_t;
};

struct config138_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_138;
    static const unsigned n_filt = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config138_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_138;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config138 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_135;
    static const unsigned in_width = OUT_WIDTH_135;
    static const unsigned n_chan = N_FILT_135;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_138;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_138;
    static const unsigned out_width = OUT_WIDTH_138;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias138_t bias_t;
    typedef model_default_t weight_t;
    typedef config138_mult mult_config;
    typedef config138_norm norm_config;
    typedef config138_relu relu_config;
};

struct config142_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias142_t bias_t;
    typedef model_default_t weight_t;
};

struct config142_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_142;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config142_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_142;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config142 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_138;
    static const unsigned in_width = OUT_WIDTH_138;
    static const unsigned n_chan = N_FILT_138;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_142;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_142;
    static const unsigned out_width = OUT_WIDTH_142;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias142_t bias_t;
    typedef model_default_t weight_t;
    typedef config142_mult mult_config;
    typedef config142_norm norm_config;
    typedef config142_relu relu_config;
};


struct config145_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias145_t bias_t;
    typedef model_default_t weight_t;
};

struct config145_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_145;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config145_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_145;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config145 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_142;
    static const unsigned in_width = OUT_WIDTH_142;
    static const unsigned n_chan = N_FILT_142;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_145;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_145;
    static const unsigned out_width = OUT_WIDTH_145;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias145_t bias_t;
    typedef model_default_t weight_t;
    typedef config145_mult mult_config;
    typedef config145_norm norm_config;
    typedef config145_relu relu_config;
};

struct config148_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias148_t bias_t;
    typedef model_default_t weight_t;
};

struct config148_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_148;
    static const unsigned n_filt = 2048;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config148_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_148;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


struct config148 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_145;
    static const unsigned in_width = OUT_WIDTH_145;
    static const unsigned n_chan = N_FILT_145;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_148;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_148;
    static const unsigned out_width = OUT_WIDTH_148;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias148_t bias_t;
    typedef model_default_t weight_t;
    typedef config148_mult mult_config;
    typedef config148_norm norm_config;
    typedef config148_relu relu_config;
};

struct config150_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<16,6> accum_t;
    typedef bias150_t bias_t;
    typedef model_default_t weight_t;
};

struct config150_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_150;
    static const unsigned n_filt = 2048;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config150_relu : nnet::activ_config  {
    static const unsigned n_in = N_FILT_148;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config150 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_138;
    static const unsigned in_width = OUT_WIDTH_138;
    static const unsigned n_chan = N_FILT_138;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_150;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_150;
    static const unsigned out_width = OUT_WIDTH_150;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<16,6> accum_t;
    typedef bias150_t bias_t;
    typedef model_default_t weight_t;
    typedef config150_mult mult_config;
    typedef config150_norm norm_config;
    typedef config150_relu relu_config;
};

#endif
