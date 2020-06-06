#ifndef PARAMETERS_FULL_H_
#define PARAMETERS_FULL_H_

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
#define N_INPUT_1_1_LARGE 1000
#define N_INPUT_1_1 224
#define N_INPUT_2_1 224
#define N_INPUT_3_1 3

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
#define N_FILT_HEIGHT_12 1
#define N_FILT_WIDTH_12 1
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
#define OUT_HEIGHT_41 28
#define OUT_WIDTH_41 28
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
#define N_LAYER_175 1000

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<8,6> model_default_t;
typedef ap_fixed<8,6> input_t;
typedef ap_fixed<8,6> layer2_t;
typedef ap_uint<1> bias2_t;
typedef ap_fixed<8,6> layer3_t;
typedef ap_fixed<8,6> layer4_t;
typedef ap_fixed<8,6> layer5_t;
typedef ap_fixed<8,6> layer6_t;
typedef ap_uint<1> bias6_t;
typedef ap_fixed<8,6> layer7_t;
typedef ap_fixed<8,6> layer8_t;
typedef ap_fixed<8,6> layer9_t;
typedef ap_uint<1> bias9_t;
typedef ap_fixed<8,6> layer10_t;
typedef ap_fixed<8,6> layer11_t;
typedef ap_fixed<8,6> layer12_t;
typedef ap_uint<1> bias12_t;
typedef ap_fixed<8,6> layer13_t;
typedef ap_fixed<8,6> layer14_t;
typedef ap_uint<1> bias14_t;
typedef ap_fixed<8,6> layer15_t;
typedef ap_fixed<8,6> layer16_t;
typedef ap_fixed<8,6> layer17_t;
typedef ap_fixed<8,6> layer18_t;
typedef ap_uint<1> bias18_t;
typedef ap_fixed<8,6> layer19_t;
typedef ap_fixed<8,6> layer20_t;
typedef ap_fixed<8,6> layer21_t;
typedef ap_uint<1> bias21_t;
typedef ap_fixed<8,6> layer22_t;
typedef ap_fixed<8,6> layer23_t;
typedef ap_fixed<8,6> layer24_t;
typedef ap_uint<1> bias24_t;
typedef ap_fixed<8,6> layer25_t;
typedef ap_fixed<8,6> layer26_t;
typedef ap_fixed<8,6> layer27_t;
typedef ap_fixed<8,6> layer28_t;
typedef ap_uint<1> bias28_t;
typedef ap_fixed<8,6> layer29_t;
typedef ap_fixed<8,6> layer30_t;
typedef ap_fixed<8,6> layer31_t;
typedef ap_uint<1> bias31_t;
typedef ap_fixed<8,6> layer32_t;
typedef ap_fixed<8,6> layer33_t;
typedef ap_fixed<8,6> layer34_t;
typedef ap_uint<1> bias34_t;
typedef ap_fixed<8,6> layer35_t;
typedef ap_fixed<8,6> layer36_t;
typedef ap_fixed<8,6> layer37_t;
typedef ap_fixed<8,6> layer38_t;
typedef ap_uint<1> bias38_t;
typedef ap_fixed<8,6> layer39_t;
typedef ap_fixed<8,6> layer41_t;
typedef ap_uint<1> bias41_t;
typedef ap_fixed<8,6> layer44_t;
typedef ap_uint<1> bias44_t;
typedef ap_fixed<8,6> layer45_t;
typedef ap_fixed<8,6> layer46_t;
typedef ap_uint<1> bias46_t;
typedef ap_fixed<8,6> layer47_t;
typedef ap_fixed<8,6> layer48_t;
typedef ap_fixed<8,6> layer49_t;
typedef ap_fixed<8,6> layer50_t;
typedef ap_uint<1> bias50_t;
typedef ap_fixed<8,6> layer51_t;
typedef ap_fixed<8,6> layer52_t;
typedef ap_fixed<8,6> layer53_t;
typedef ap_uint<1> bias53_t;
typedef ap_fixed<8,6> layer54_t;
typedef ap_fixed<8,6> layer55_t;
typedef ap_fixed<8,6> layer56_t;
typedef ap_uint<1> bias56_t;
typedef ap_fixed<8,6> layer57_t;
typedef ap_fixed<8,6> layer58_t;
typedef ap_fixed<8,6> layer59_t;
typedef ap_fixed<8,6> layer60_t;
typedef ap_uint<1> bias60_t;
typedef ap_fixed<8,6> layer61_t;
typedef ap_fixed<8,6> layer62_t;
typedef ap_fixed<8,6> layer63_t;
typedef ap_uint<1> bias63_t;
typedef ap_fixed<8,6> layer64_t;
typedef ap_fixed<8,6> layer65_t;
typedef ap_fixed<8,6> layer66_t;
typedef ap_uint<1> bias66_t;
typedef ap_fixed<8,6> layer67_t;
typedef ap_fixed<8,6> layer68_t;
typedef ap_fixed<8,6> layer69_t;
typedef ap_fixed<8,6> layer70_t;
typedef ap_uint<1> bias70_t;
typedef ap_fixed<8,6> layer71_t;
typedef ap_fixed<8,6> layer72_t;
typedef ap_fixed<8,6> layer73_t;
typedef ap_uint<1> bias73_t;
typedef ap_fixed<8,6> layer74_t;
typedef ap_fixed<8,6> layer75_t;
typedef ap_fixed<8,6> layer76_t;
typedef ap_uint<1> bias76_t;
typedef ap_fixed<8,6> layer77_t;
typedef ap_fixed<8,6> layer78_t;
typedef ap_fixed<8,6> layer79_t;
typedef ap_fixed<8,6> layer80_t;
typedef ap_uint<1> bias80_t;
typedef ap_fixed<8,6> layer81_t;
typedef ap_fixed<8,6> layer83_t;
typedef ap_uint<1> bias83_t;
typedef ap_fixed<8,6> layer84_t;
typedef ap_fixed<8,6> layer85_t;
typedef ap_fixed<8,6> layer86_t;
typedef ap_uint<1> bias86_t;
typedef ap_fixed<8,6> layer87_t;
typedef ap_fixed<8,6> layer88_t;
typedef ap_uint<1> bias88_t;
typedef ap_fixed<8,6> layer89_t;
typedef ap_fixed<8,6> layer90_t;
typedef ap_fixed<8,6> layer91_t;
typedef ap_fixed<8,6> layer92_t;
typedef ap_uint<1> bias92_t;
typedef ap_fixed<8,6> layer93_t;
typedef ap_fixed<8,6> layer94_t;
typedef ap_fixed<8,6> layer95_t;
typedef ap_uint<1> bias95_t;
typedef ap_fixed<8,6> layer96_t;
typedef ap_fixed<8,6> layer97_t;
typedef ap_fixed<8,6> layer98_t;
typedef ap_uint<1> bias98_t;
typedef ap_fixed<8,6> layer99_t;
typedef ap_fixed<8,6> layer100_t;
typedef ap_fixed<8,6> layer101_t;
typedef ap_fixed<8,6> layer102_t;
typedef ap_uint<1> bias102_t;
typedef ap_fixed<8,6> layer103_t;
typedef ap_fixed<8,6> layer104_t;
typedef ap_fixed<8,6> layer105_t;
typedef ap_uint<1> bias105_t;
typedef ap_fixed<8,6> layer106_t;
typedef ap_fixed<8,6> layer107_t;
typedef ap_fixed<8,6> layer108_t;
typedef ap_uint<1> bias108_t;
typedef ap_fixed<8,6> layer109_t;
typedef ap_fixed<8,6> layer110_t;
typedef ap_fixed<8,6> layer111_t;
typedef ap_fixed<8,6> layer112_t;
typedef ap_uint<1> bias112_t;
typedef ap_fixed<8,6> layer113_t;
typedef ap_fixed<8,6> layer114_t;
typedef ap_fixed<8,6> layer115_t;
typedef ap_uint<1> bias115_t;
typedef ap_fixed<8,6> layer116_t;
typedef ap_fixed<8,6> layer117_t;
typedef ap_fixed<8,6> layer118_t;
typedef ap_uint<1> bias118_t;
typedef ap_fixed<8,6> layer119_t;
typedef ap_fixed<8,6> layer120_t;
typedef ap_fixed<8,6> layer121_t;
typedef ap_fixed<8,6> layer122_t;
typedef ap_uint<1> bias122_t;
typedef ap_fixed<8,6> layer123_t;
typedef ap_fixed<8,6> layer124_t;
typedef ap_fixed<8,6> layer125_t;
typedef ap_uint<1> bias125_t;
typedef ap_fixed<8,6> layer126_t;
typedef ap_fixed<8,6> layer127_t;
typedef ap_fixed<8,6> layer128_t;
typedef ap_uint<1> bias128_t;
typedef ap_fixed<8,6> layer129_t;
typedef ap_fixed<8,6> layer130_t;
typedef ap_fixed<8,6> layer131_t;
typedef ap_fixed<8,6> layer132_t;
typedef ap_uint<1> bias132_t;
typedef ap_fixed<8,6> layer133_t;
typedef ap_fixed<8,6> layer134_t;
typedef ap_fixed<8,6> layer135_t;
typedef ap_uint<1> bias135_t;
typedef ap_fixed<8,6> layer136_t;
typedef ap_fixed<8,6> layer137_t;
typedef ap_fixed<8,6> layer138_t;
typedef ap_uint<1> bias138_t;
typedef ap_fixed<8,6> layer139_t;
typedef ap_fixed<8,6> layer140_t;
typedef ap_fixed<8,6> layer141_t;
typedef ap_fixed<8,6> layer142_t;
typedef ap_uint<1> bias142_t;
typedef ap_fixed<8,6> layer145_t;
typedef ap_uint<1> bias145_t;
typedef ap_fixed<8,6> layer146_t;
typedef ap_fixed<8,6> layer147_t;
typedef ap_fixed<8,6> layer148_t;
typedef ap_uint<1> bias148_t;
typedef ap_fixed<8,6> layer149_t;
typedef ap_fixed<8,6> layer150_t;
typedef ap_uint<1> bias150_t;
typedef ap_fixed<8,6> layer151_t;
typedef ap_fixed<8,6> layer152_t;
typedef ap_fixed<8,6> layer153_t;
typedef ap_fixed<8,6> layer154_t;
typedef ap_uint<1> bias154_t;
typedef ap_fixed<8,6> layer155_t;
typedef ap_fixed<8,6> layer156_t;
typedef ap_fixed<8,6> layer157_t;
typedef ap_uint<1> bias157_t;
typedef ap_fixed<8,6> layer158_t;
typedef ap_fixed<8,6> layer159_t;
typedef ap_fixed<8,6> layer160_t;
typedef ap_uint<1> bias160_t;
typedef ap_fixed<8,6> layer161_t;
typedef ap_fixed<8,6> layer162_t;
typedef ap_fixed<8,6> layer163_t;
typedef ap_fixed<8,6> layer164_t;
typedef ap_uint<1> bias164_t;
typedef ap_fixed<8,6> layer165_t;
typedef ap_fixed<8,6> layer166_t;
typedef ap_fixed<8,6> layer167_t;
typedef ap_uint<1> bias167_t;
typedef ap_fixed<8,6> layer168_t;
typedef ap_fixed<8,6> layer169_t;
typedef ap_fixed<8,6> layer170_t;
typedef ap_uint<1> bias170_t;
typedef ap_fixed<8,6> layer171_t;
typedef ap_fixed<8,6> layer172_t;
typedef ap_fixed<8,6> layer173_t;
typedef ap_fixed<8,6> layer174_t;
typedef ap_fixed<8,6> layer175_t;
typedef ap_fixed<8,6> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 147;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 7;
    static const unsigned add_lat = 4;
    typedef ap_fixed<8,6> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
};

struct config2_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config2_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 3;
    static const unsigned pad_bottom = 3;
    static const unsigned pad_left = 3;
    static const unsigned pad_right = 3;
    static const unsigned in_height = N_INPUT_1_1;
    static const unsigned in_width = N_INPUT_2_1;
    static const unsigned n_chan = N_INPUT_3_1;
    static const unsigned filt_height = N_FILT_HEIGHT_2;
    static const unsigned filt_width = N_FILT_WIDTH_2;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<8,6> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_norm norm_config;
    typedef config2_relu relu_config;
};

struct config5 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_2;
    static const unsigned in_width = OUT_WIDTH_2;
    static const unsigned n_filt = N_FILT_5;
    static const unsigned n_chan = N_FILT_2;
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
    static const unsigned reuse_factor = 8;
    typedef ap_fixed<8,6> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
};

struct config6_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_6;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config6_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
    typedef config6_mult mult_config;
    typedef config6_norm norm_config;
    typedef config6_relu relu_config;
};


struct config9_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias9_t bias_t;
    typedef model_default_t weight_t;
};

struct config9_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_9;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = true;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config9_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_9;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<8,6> accum_t;
    typedef bias9_t bias_t;
    typedef model_default_t weight_t;
    typedef config9_mult mult_config;
    typedef config9_norm norm_config;
    typedef config9_relu relu_config;
};

struct config12_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
};

struct config12_norm : nnet::batchnorm_config {
  static const unsigned n_in = N_FILT_12;
  static const unsigned n_filt = 256;
  static const unsigned io_type = nnet::io_parallel;
  static const unsigned reuse_factor = 32;
  static const bool store_weights_in_bram = false;
  typedef model_default_t bias_t;
  typedef model_default_t scale_t;
};

struct config12_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_12;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef config12_mult mult_config;
    typedef config12_norm norm_config;
    typedef config12_relu relu_config;
};


struct config14_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias14_t bias_t;
    typedef model_default_t weight_t;
};

struct config14_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_14;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};
/// Fix me should be 17th
struct config14_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_12;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
};

struct config14 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_WIDTH_5;
    static const unsigned in_width = OUT_HEIGHT_5;
    static const unsigned n_chan = N_FILT_5;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_14;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_14;
    static const unsigned out_width = OUT_WIDTH_14;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef config14_mult mult_config;
    typedef config14_norm norm_config;
    typedef config14_relu relu_config;
};

struct config16 : nnet::merge_config {
  static const unsigned n_elem = N_FILT_12;
};

struct config18_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias18_t bias_t;
    typedef model_default_t weight_t;
};

struct config18_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_18;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config18_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_18;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
};

struct config18 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_12;
    static const unsigned in_width = OUT_WIDTH_12;
    static const unsigned n_chan = N_FILT_14;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_18;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_18;
    static const unsigned out_width = OUT_WIDTH_18;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias18_t bias_t;
    typedef model_default_t weight_t;
    typedef config18_mult mult_config;
    typedef config18_norm norm_config;
    typedef config18_relu relu_config;
};

struct config21_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_21;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 2;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config21_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_21;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 2;
};

struct config21_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 64;
    typedef ap_fixed<8,6> accum_t;
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
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias21_t bias_t;
    typedef model_default_t weight_t;
    typedef config21_mult mult_config;
    typedef config21_norm norm_config;
    typedef config21_relu relu_config;
};

struct config24_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias24_t bias_t;
    typedef model_default_t weight_t;
};

struct config24_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_24;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config24_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_24;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias24_t bias_t;
    typedef model_default_t weight_t;
    typedef config24_mult mult_config;
    typedef config24_norm norm_config;
    typedef config24_relu relu_config;
};

struct config26 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_24;
};

struct config28_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias28_t bias_t;
    typedef model_default_t weight_t;
};

struct config28_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_28;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config28_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_28;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias28_t bias_t;
    typedef model_default_t weight_t;
    typedef config28_mult mult_config;
    typedef config28_norm norm_config;
    typedef config28_relu relu_config;
};

struct config31_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias31_t bias_t;
    typedef model_default_t weight_t;
};

struct config31_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_31;
    static const unsigned n_filt = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config31_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_31;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias31_t bias_t;
    typedef model_default_t weight_t;
    typedef config31_mult mult_config;
    typedef config31_norm norm_config;
    typedef config31_relu relu_config;
};

struct config34_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias34_t bias_t;
    typedef model_default_t weight_t;
};

struct config34_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_34;
    static const unsigned n_filt = 256;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config34_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_34;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
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
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef config34_mult mult_config;
    typedef config34_norm norm_config;
    typedef config34_relu relu_config;
};

struct config36 : nnet::merge_config {
  static const unsigned n_elem = N_FILT_34;
};

struct config38_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 32;
    typedef ap_fixed<8,6> accum_t;
    typedef bias38_t bias_t;
    typedef model_default_t weight_t;
};

struct config38_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_38;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config38_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_38;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
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
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias38_t bias_t;
    typedef model_default_t weight_t;
    typedef config38_mult mult_config;
    typedef config38_norm norm_config;
    typedef config38_relu relu_config;
};


struct config41_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<8,6> accum_t;
    typedef bias41_t bias_t;
    typedef model_default_t weight_t;
};

struct config41_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_41;
    static const unsigned n_filt = 128;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config41_relu : nnet::activ_config {
  static const unsigned n_in = N_FILT_41;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config41 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_38;
    static const unsigned in_width = OUT_WIDTH_38;
    static const unsigned n_chan = N_FILT_38;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_41;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_41;
    static const unsigned out_width = OUT_WIDTH_41;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias41_t bias_t;
    typedef model_default_t weight_t;
    typedef config41_mult mult_config;
    typedef config41_norm norm_config;
    typedef config41_relu relu_config;
};

struct config44_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<8,6> accum_t;
    typedef bias44_t bias_t;
    typedef model_default_t weight_t;
};

struct config44_norm : nnet::batchnorm_config {
  static const unsigned n_in = N_FILT_44;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config44_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_44;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
};

struct config44 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_41;
    static const unsigned in_width = OUT_WIDTH_41;
    static const unsigned n_chan = N_FILT_41;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_44;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_44;
    static const unsigned out_width = OUT_WIDTH_44;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias44_t bias_t;
    typedef model_default_t weight_t;
    typedef config44_mult mult_config;
    typedef config44_norm norm_config;
    typedef config44_relu relu_config;
};

struct config46_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<8,6> accum_t;
    typedef bias46_t bias_t;
    typedef model_default_t weight_t;
};

struct config46_norm : nnet::batchnorm_config {
    static const unsigned n_in = N_FILT_46;
    static const unsigned n_filt = 512;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 128;
    static const bool store_weights_in_bram = false;
    typedef model_default_t bias_t;
    typedef model_default_t scale_t;
};

struct config46_relu : nnet::activ_config {
    static const unsigned n_in = N_FILT_46;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config46 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_34;
    static const unsigned in_width = OUT_WIDTH_34;
    static const unsigned n_chan = N_FILT_34;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_46;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_46;
    static const unsigned out_width = OUT_WIDTH_46;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<8,6> accum_t;
    typedef bias46_t bias_t;
    typedef model_default_t weight_t;
    typedef config46_mult mult_config;
    typedef config46_norm norm_config;
    typedef config46_relu relu_config;
};

struct config50_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias50_t bias_t;
    typedef model_default_t weight_t;
    typedef config50_mult mult_config;
    typedef config50_norm norm_config;
    typedef config50_relu relu_config;
};


struct config53_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 576;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias60_t bias_t;
    typedef model_default_t weight_t;
    typedef config60_mult mult_config;
    typedef config60_norm norm_config;
    typedef config60_relu relu_config;
};

struct config63_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 576;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias70_t bias_t;
    typedef model_default_t weight_t;
    typedef config70_mult mult_config;
    typedef config70_norm norm_config;
    typedef config70_relu relu_config;
};

struct config73_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 576;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias76_t bias_t;
    typedef model_default_t weight_t;
    typedef config76_mult mult_config;
    typedef config76_norm norm_config;
    typedef config76_relu relu_config;
};


struct config80_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 512;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias80_t bias_t;
    typedef model_default_t weight_t;
    typedef config80_mult mult_config;
    typedef config80_norm norm_config;
    typedef config80_relu relu_config;
};


struct config83_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 576;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias83_t bias_t;
    typedef model_default_t weight_t;
    typedef config83_mult mult_config;
    typedef config83_norm norm_config;
    typedef config83_relu relu_config;
};

struct config86_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 256;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias86_t bias_t;
    typedef model_default_t weight_t;
    typedef config86_mult mult_config;
    typedef config86_norm norm_config;
    typedef config86_relu relu_config;
};

struct config88_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias88_t bias_t;
    typedef model_default_t weight_t;
    typedef config88_mult mult_config;
    typedef config88_norm norm_config;
    typedef config88_relu relu_config;
};

struct config92_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_fixed<8,6> accum_t;
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
    static const unsigned in_height = OUT_HEIGHT_88;//86
    static const unsigned in_width = OUT_WIDTH_88;//86
    static const unsigned n_chan = N_FILT_88;//86
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias95_t bias_t;
    typedef model_default_t weight_t;
    typedef config95_mult mult_config;
    typedef config95_norm norm_config;
    typedef config95_relu relu_config;
};

struct config98_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 256;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias98_t bias_t;
    typedef model_default_t weight_t;
    typedef config98_mult mult_config;
    typedef config98_norm norm_config;
    typedef config98_relu relu_config;
};

struct config102_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 1024;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias102_t bias_t;
    typedef model_default_t weight_t;
    typedef config102_mult mult_config;
    typedef config102_norm norm_config;
    typedef config102_relu relu_config;
};

struct config105_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 2304;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias105_t bias_t;
    typedef model_default_t weight_t;
    typedef config105_mult mult_config;
    typedef config105_norm norm_config;
    typedef config105_relu relu_config;
};

struct config108_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 256;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias138_t bias_t;
    typedef model_default_t weight_t;
    typedef config138_mult mult_config;
    typedef config138_norm norm_config;
    typedef config138_relu relu_config;
};

struct config142_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 1024;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias142_t bias_t;
    typedef model_default_t weight_t;
    typedef config142_mult mult_config;
    typedef config142_norm norm_config;
    typedef config142_relu relu_config;
};


struct config145_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 4608;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias150_t bias_t;
    typedef model_default_t weight_t;
    typedef config150_mult mult_config;
    typedef config150_norm norm_config;
    typedef config150_relu relu_config;
};

struct config154_mult : nnet::dense_config {
    static const unsigned n_in = 2048;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2048;
    static const unsigned block_factor = 512;
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
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
    typedef ap_fixed<8,6> accum_t;
    typedef bias170_t bias_t;
    typedef model_default_t weight_t;
    typedef config170_mult mult_config;
    typedef config170_norm norm_config;
    typedef config170_relu relu_config;
};

struct config174 : nnet::pooling2d_config {
    static const unsigned in_height = OUT_HEIGHT_170;
    static const unsigned in_width = OUT_WIDTH_170;
    static const unsigned n_filt = N_FILT_174;
    static const unsigned n_chan = N_FILT_174;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned pool_height = 7;
    static const unsigned pool_width = 7;
    static const unsigned filt_height = 7;
    static const unsigned filt_width =  7;
    static const unsigned out_height = OUT_HEIGHT_174;
    static const unsigned out_width = OUT_WIDTH_174;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Average;
    static const unsigned reuse = 128;
    static const unsigned reuse_factor = 16;
};

struct config175 : nnet::dense_config {
    static const unsigned n_in = OUT_HEIGHT_174*OUT_WIDTH_174*N_FILT_174;
    static const unsigned n_out = N_LAYER_175;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = OUT_HEIGHT_174*OUT_WIDTH_174*N_FILT_174;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 2048000;
    static const bool store_weights_in_bram = true;
    typedef ap_fixed<8,6> accum_t;
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
