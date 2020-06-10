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
#include "nnet_utils/nnet_dense_large_stream.h"

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 4
#define N_INPUT_2_1 224
#define N_INPUT_3_1 224
#define N_INPUT_3_1M 62
#define N_SPLIT 4
#define N_FILT_2 65
#define OUT_HEIGHT_2 112
#define OUT_WIDTH_2 112
#define OUT_WIDTH_2M 28
#define N_FILT_5 65
#define OUT_HEIGHT_5 56
#define OUT_WIDTH_5 56
#define N_FILT_6 65
#define OUT_HEIGHT_6 56
#define OUT_WIDTH_6 56
#define N_FILT_9 65
#define OUT_HEIGHT_9 56
#define OUT_WIDTH_9 56
#define N_FILT_12 257
#define OUT_HEIGHT_12 56
#define OUT_WIDTH_12 56
#define N_FILT_14 257
#define OUT_HEIGHT_14 56
#define OUT_WIDTH_14 56
#define N_FILT_18 65
#define OUT_HEIGHT_18 56
#define OUT_WIDTH_18 56
#define N_FILT_21 65
#define OUT_HEIGHT_21 56
#define OUT_WIDTH_21 56
#define N_FILT_24 257
#define OUT_HEIGHT_24 56
#define OUT_WIDTH_24 56
#define N_FILT_28 65
#define OUT_HEIGHT_28 56
#define OUT_WIDTH_28 56
#define N_FILT_31 65
#define OUT_HEIGHT_31 56
#define OUT_WIDTH_31 56
#define N_FILT_34 257
#define OUT_HEIGHT_34 56
#define OUT_WIDTH_34 56
#define N_FILT_38 129
#define OUT_HEIGHT_38 56
#define OUT_WIDTH_38 56
#define N_FILT_41 129
#define OUT_HEIGHT_41 28
#define OUT_WIDTH_41 28
#define N_FILT_44 513
#define OUT_HEIGHT_44 28
#define OUT_WIDTH_44 28
#define N_FILT_46 513
#define OUT_HEIGHT_46 28
#define OUT_WIDTH_46 28
#define N_FILT_50 129
#define OUT_HEIGHT_50 28
#define OUT_WIDTH_50 28
#define N_FILT_53 129
#define OUT_HEIGHT_53 28
#define OUT_WIDTH_53 28
#define N_FILT_56 513
#define OUT_HEIGHT_56 28
#define OUT_WIDTH_56 28
#define N_FILT_60 129
#define OUT_HEIGHT_60 28
#define OUT_WIDTH_60 28
#define N_FILT_63 129
#define OUT_HEIGHT_63 28
#define OUT_WIDTH_63 28
#define N_FILT_66 513
#define OUT_HEIGHT_66 28
#define OUT_WIDTH_66 28
#define N_FILT_70 129
#define OUT_HEIGHT_70 28
#define OUT_WIDTH_70 28
#define N_FILT_73 129
#define OUT_HEIGHT_73 28
#define OUT_WIDTH_73 28
#define N_FILT_76 513
#define OUT_HEIGHT_76 28
#define OUT_WIDTH_76 28
#define N_FILT_80 257
#define OUT_HEIGHT_80 28
#define OUT_WIDTH_80 28
#define N_FILT_83 257
#define OUT_HEIGHT_83 14
#define OUT_WIDTH_83 14
#define N_FILT_86 1025
#define OUT_HEIGHT_86 14
#define OUT_WIDTH_86 14
#define N_FILT_88 1025
#define OUT_HEIGHT_88 14
#define OUT_WIDTH_88 14
#define N_FILT_92 257
#define OUT_HEIGHT_92 14
#define OUT_WIDTH_92 14
#define N_FILT_95 257
#define OUT_HEIGHT_95 14
#define OUT_WIDTH_95 14
#define N_FILT_98 1025
#define OUT_HEIGHT_98 14
#define OUT_WIDTH_98 14
#define N_FILT_102 257
#define OUT_HEIGHT_102 14
#define OUT_WIDTH_102 14
#define N_FILT_105 257
#define OUT_HEIGHT_105 14
#define OUT_WIDTH_105 14
#define N_FILT_108 1025
#define OUT_HEIGHT_108 14
#define OUT_WIDTH_108 14
#define N_FILT_112 257
#define OUT_HEIGHT_112 14
#define OUT_WIDTH_112 14
#define N_FILT_115 257
#define OUT_HEIGHT_115 14
#define OUT_WIDTH_115 14
#define N_FILT_118 1025
#define OUT_HEIGHT_118 14
#define OUT_WIDTH_118 14
#define N_FILT_122 257
#define OUT_HEIGHT_122 14
#define OUT_WIDTH_122 14
#define N_FILT_125 257
#define OUT_HEIGHT_125 14
#define OUT_WIDTH_125 14
#define N_FILT_128 1025
#define OUT_HEIGHT_128 14
#define OUT_WIDTH_128 14
#define N_FILT_132 257
#define OUT_HEIGHT_132 14
#define OUT_WIDTH_132 14
#define N_FILT_135 257
#define OUT_HEIGHT_135 14
#define OUT_WIDTH_135 14
#define N_FILT_138 1025
#define OUT_HEIGHT_138 14
#define OUT_WIDTH_138 14
#define N_FILT_142 513
#define OUT_HEIGHT_142 14
#define OUT_WIDTH_142 14
#define N_FILT_145 513
#define OUT_HEIGHT_145 7
#define OUT_WIDTH_145 7
#define N_FILT_148 2049
#define OUT_HEIGHT_148 7
#define OUT_WIDTH_148 7
#define N_FILT_150 2049
#define OUT_HEIGHT_150 7
#define OUT_WIDTH_150 7
#define N_FILT_154 513
#define OUT_HEIGHT_154 7
#define OUT_WIDTH_154 7
#define N_FILT_157 513
#define OUT_HEIGHT_157 7
#define OUT_WIDTH_157 7
#define N_FILT_160 2049
#define OUT_HEIGHT_160 7
#define OUT_WIDTH_160 7
#define N_FILT_164 513
#define OUT_HEIGHT_164 7
#define OUT_WIDTH_164 7
#define N_FILT_167 513
#define OUT_HEIGHT_167 7
#define OUT_WIDTH_167 7
#define N_FILT_170 2049
#define OUT_HEIGHT_170 7
#define OUT_WIDTH_170 7
#define N_FILT_174 2049
#define N_LAYER_174 2048
#define OUT_HEIGHT_174 1
#define OUT_WIDTH_174 1
#define N_LAYER_175 1000

//hls-fpga-machine-learning insert layer-precision
typedef ap_uint<27> model_default_t;
typedef ap_uint<27> model_bigdefault_t;
typedef ap_uint<8> input_t;
typedef ap_uint<8> layer2_t;
typedef ap_uint<1> bias2_t;
typedef ap_uint<8> layer4_t;
typedef ap_uint<8> layer3_t;
typedef ap_uint<8> layer5_t;
typedef ap_uint<8> layer177_t;
typedef ap_uint<8> layer6_t;
typedef ap_uint<1> bias6_t;
typedef ap_uint<8> layer8_t;
typedef ap_uint<8> layer7_t;
typedef ap_uint<8> layer9_t;
typedef ap_uint<1> bias9_t;
typedef ap_uint<8> layer11_t;
typedef ap_uint<8> layer10_t;
typedef ap_uint<8> layer12_t;
typedef ap_uint<1> bias12_t;
typedef ap_uint<8> layer13_t;
typedef ap_uint<8> layer14_t;
typedef ap_uint<1> bias14_t;
typedef ap_uint<8> layer15_t;
typedef ap_uint<8> layer16_t;
typedef ap_uint<8> layer17_t;
typedef ap_uint<8> layer178_t;
typedef ap_uint<8> layer18_t;
typedef ap_uint<1> bias18_t;
typedef ap_uint<8> layer20_t;
typedef ap_uint<8> layer19_t;
typedef ap_uint<8> layer21_t;
typedef ap_uint<1> bias21_t;
typedef ap_uint<8> layer23_t;
typedef ap_uint<8> layer22_t;
typedef ap_uint<8> layer24_t;
typedef ap_uint<1> bias24_t;
typedef ap_uint<8> layer25_t;
typedef ap_uint<8> layer26_t;
typedef ap_uint<8> layer27_t;
typedef ap_uint<8> layer179_t;
typedef ap_uint<8> layer28_t;
typedef ap_uint<1> bias28_t;
typedef ap_uint<8> layer30_t;
typedef ap_uint<8> layer29_t;
typedef ap_uint<8> layer31_t;
typedef ap_uint<1> bias31_t;
typedef ap_uint<8> layer33_t;
typedef ap_uint<8> layer32_t;
typedef ap_uint<8> layer34_t;
typedef ap_uint<1> bias34_t;
typedef ap_uint<8> layer35_t;
typedef ap_uint<8> layer36_t;
typedef ap_uint<8> layer37_t;
typedef ap_uint<8> layer180_t;
typedef ap_uint<8> layer38_t;
typedef ap_uint<1> bias38_t;
typedef ap_uint<8> layer40_t;
typedef ap_uint<8> layer39_t;
typedef ap_uint<8> layer41_t;
typedef ap_uint<1> bias41_t;
typedef ap_uint<8> layer43_t;
typedef ap_uint<8> layer42_t;
typedef ap_uint<8> layer44_t;
typedef ap_uint<1> bias44_t;
typedef ap_uint<8> layer45_t;
typedef ap_uint<8> layer46_t;
typedef ap_uint<1> bias46_t;
typedef ap_uint<8> layer47_t;
typedef ap_uint<8> layer48_t;
typedef ap_uint<8> layer49_t;
typedef ap_uint<8> layer181_t;
typedef ap_uint<8> layer50_t;
typedef ap_uint<1> bias50_t;
typedef ap_uint<8> layer52_t;
typedef ap_uint<8> layer51_t;
typedef ap_uint<8> layer53_t;
typedef ap_uint<1> bias53_t;
typedef ap_uint<8> layer55_t;
typedef ap_uint<8> layer54_t;
typedef ap_uint<8> layer56_t;
typedef ap_uint<1> bias56_t;
typedef ap_uint<8> layer57_t;
typedef ap_uint<8> layer58_t;
typedef ap_uint<8> layer59_t;
typedef ap_uint<8> layer182_t;
typedef ap_uint<8> layer60_t;
typedef ap_uint<1> bias60_t;
typedef ap_uint<8> layer62_t;
typedef ap_uint<8> layer61_t;
typedef ap_uint<8> layer63_t;
typedef ap_uint<1> bias63_t;
typedef ap_uint<8> layer65_t;
typedef ap_uint<8> layer64_t;
typedef ap_uint<8> layer66_t;
typedef ap_uint<1> bias66_t;
typedef ap_uint<8> layer67_t;
typedef ap_uint<8> layer68_t;
typedef ap_uint<8> layer69_t;
typedef ap_uint<8> layer183_t;
typedef ap_uint<8> layer70_t;
typedef ap_uint<1> bias70_t;
typedef ap_uint<8> layer72_t;
typedef ap_uint<8> layer71_t;
typedef ap_uint<8> layer73_t;
typedef ap_uint<1> bias73_t;
typedef ap_uint<8> layer75_t;
typedef ap_uint<8> layer74_t;
typedef ap_uint<8> layer76_t;
typedef ap_uint<1> bias76_t;
typedef ap_uint<8> layer77_t;
typedef ap_uint<8> layer78_t;
typedef ap_uint<8> layer79_t;
typedef ap_uint<8> layer184_t;
typedef ap_uint<8> layer80_t;
typedef ap_uint<1> bias80_t;
typedef ap_uint<8> layer82_t;
typedef ap_uint<8> layer81_t;
typedef ap_uint<8> layer83_t;
typedef ap_uint<1> bias83_t;
typedef ap_uint<8> layer85_t;
typedef ap_uint<8> layer84_t;
typedef ap_uint<8> layer86_t;
typedef ap_uint<1> bias86_t;
typedef ap_uint<8> layer87_t;
typedef ap_uint<8> layer88_t;
typedef ap_uint<1> bias88_t;
typedef ap_uint<8> layer89_t;
typedef ap_uint<8> layer90_t;
typedef ap_uint<8> layer91_t;
typedef ap_uint<8> layer185_t;
typedef ap_uint<8> layer92_t;
typedef ap_uint<1> bias92_t;
typedef ap_uint<8> layer94_t;
typedef ap_uint<8> layer93_t;
typedef ap_uint<8> layer95_t;
typedef ap_uint<1> bias95_t;
typedef ap_uint<8> layer97_t;
typedef ap_uint<8> layer96_t;
typedef ap_uint<8> layer98_t;
typedef ap_uint<1> bias98_t;
typedef ap_uint<8> layer99_t;
typedef ap_uint<8> layer100_t;
typedef ap_uint<8> layer101_t;
typedef ap_uint<8> layer186_t;
typedef ap_uint<8> layer102_t;
typedef ap_uint<1> bias102_t;
typedef ap_uint<8> layer104_t;
typedef ap_uint<8> layer103_t;
typedef ap_uint<8> layer105_t;
typedef ap_uint<1> bias105_t;
typedef ap_uint<8> layer107_t;
typedef ap_uint<8> layer106_t;
typedef ap_uint<8> layer108_t;
typedef ap_uint<1> bias108_t;
typedef ap_uint<8> layer109_t;
typedef ap_uint<8> layer110_t;
typedef ap_uint<8> layer111_t;
typedef ap_uint<8> layer187_t;
typedef ap_uint<8> layer112_t;
typedef ap_uint<1> bias112_t;
typedef ap_uint<8> layer114_t;
typedef ap_uint<8> layer113_t;
typedef ap_uint<8> layer115_t;
typedef ap_uint<1> bias115_t;
typedef ap_uint<8> layer117_t;
typedef ap_uint<8> layer116_t;
typedef ap_uint<8> layer118_t;
typedef ap_uint<1> bias118_t;
typedef ap_uint<8> layer119_t;
typedef ap_uint<8> layer120_t;
typedef ap_uint<8> layer121_t;
typedef ap_uint<8> layer188_t;
typedef ap_uint<8> layer122_t;
typedef ap_uint<1> bias122_t;
typedef ap_uint<8> layer124_t;
typedef ap_uint<8> layer123_t;
typedef ap_uint<8> layer125_t;
typedef ap_uint<1> bias125_t;
typedef ap_uint<8> layer127_t;
typedef ap_uint<8> layer126_t;
typedef ap_uint<8> layer128_t;
typedef ap_uint<1> bias128_t;
typedef ap_uint<8> layer129_t;
typedef ap_uint<8> layer130_t;
typedef ap_uint<8> layer131_t;
typedef ap_uint<8> layer189_t;
typedef ap_uint<8> layer132_t;
typedef ap_uint<1> bias132_t;
typedef ap_uint<8> layer134_t;
typedef ap_uint<8> layer133_t;
typedef ap_uint<8> layer135_t;
typedef ap_uint<1> bias135_t;
typedef ap_uint<8> layer137_t;
typedef ap_uint<8> layer136_t;
typedef ap_uint<8> layer138_t;
typedef ap_uint<1> bias138_t;
typedef ap_uint<8> layer139_t;
typedef ap_uint<8> layer140_t;
typedef ap_uint<8> layer141_t;
typedef ap_uint<8> layer190_t;
typedef ap_uint<8> layer142_t;
typedef ap_uint<1> bias142_t;
typedef ap_uint<8> layer144_t;
typedef ap_uint<8> layer143_t;
typedef ap_uint<8> layer145_t;
typedef ap_uint<1> bias145_t;
typedef ap_uint<8> layer147_t;
typedef ap_uint<8> layer146_t;
typedef ap_uint<8> layer148_t;
typedef ap_uint<1> bias148_t;
typedef ap_uint<8> layer149_t;
typedef ap_uint<8> layer150_t;
typedef ap_uint<1> bias150_t;
typedef ap_uint<8> layer151_t;
typedef ap_uint<8> layer152_t;
typedef ap_uint<8> layer153_t;
typedef ap_uint<8> layer191_t;
typedef ap_uint<8> layer154_t;
typedef ap_uint<1> bias154_t;
typedef ap_uint<8> layer156_t;
typedef ap_uint<8> layer155_t;
typedef ap_uint<8> layer157_t;
typedef ap_uint<1> bias157_t;
typedef ap_uint<8> layer159_t;
typedef ap_uint<8> layer158_t;
typedef ap_uint<8> layer160_t;
typedef ap_uint<1> bias160_t;
typedef ap_uint<8> layer161_t;
typedef ap_uint<8> layer162_t;
typedef ap_uint<8> layer163_t;
typedef ap_uint<8> layer192_t;
typedef ap_uint<8> layer164_t;
typedef ap_uint<1> bias164_t;
typedef ap_uint<8> layer166_t;
typedef ap_uint<8> layer165_t;
typedef ap_uint<8> layer167_t;
typedef ap_uint<1> bias167_t;
typedef ap_uint<8> layer169_t;
typedef ap_uint<8> layer168_t;
typedef ap_uint<8> layer170_t;
typedef ap_uint<1> bias170_t;
typedef ap_uint<8> layer171_t;
typedef ap_uint<8> layer172_t;
typedef ap_uint<8> layer173_t;
typedef ap_uint<8> layer174_t;
typedef ap_uint<8> layer175_t;
typedef ap_uint<8> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config2_mult : nnet::dense_config {
    static const unsigned n_in = 147;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 3;
    typedef ap_uint<8> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 3;
    static const unsigned pad_bottom = 3;
    static const unsigned pad_left = 3;
    static const unsigned pad_right = 3;
    static const unsigned in_height = N_INPUT_2_1;
    static const unsigned in_width = N_INPUT_3_1;
    static const unsigned n_chan = N_INPUT_1_1-1;
    static const unsigned n_chan_in = N_INPUT_1_1-1;
    static const unsigned filt_height = 7;
    static const unsigned filt_width = 7;
    static const unsigned n_filt = N_FILT_2-1;
    static const unsigned n_filt_in = N_FILT_2-1;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 0;
    static const unsigned n_split = N_SPLIT;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_relu relu_config;
};

struct config2M : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = N_INPUT_2_1;
    static const unsigned in_width = N_INPUT_3_1M;
    static const unsigned n_chan = N_INPUT_1_1-1;
    static const unsigned n_chan_in = N_INPUT_1_1;
    static const unsigned filt_height = 7;
    static const unsigned filt_width = 7;
    static const unsigned n_filt = N_FILT_2-1;
    static const unsigned n_filt_in = N_FILT_2;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2M;
    static const unsigned reuse_factor = 2;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias2_t bias_t;
    typedef model_default_t weight_t;
    typedef config2_mult mult_config;
    typedef config2_relu relu_config;
};

struct config5 : nnet::pooling2d_config {
    static const unsigned in_height = 112;
    static const unsigned in_width = OUT_HEIGHT_2;
    static const unsigned n_filt = N_FILT_5-1;
    static const unsigned n_chan = N_FILT_2-1;
    static const unsigned n_filt_in = N_FILT_5;
    static const unsigned n_chan_in = N_FILT_2;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned pool_height = 3;
    static const unsigned pool_width = 3;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned out_height = OUT_HEIGHT_5;
    static const unsigned out_width = OUT_WIDTH_5;
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const nnet::Pool_Op pool_op = nnet::Max;
    static const unsigned reuse = 200000;
};

struct config177 : nnet::split_config {
    static const unsigned n_elem = N_FILT_5;
};

struct config6_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config6_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
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
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_6-1;
    static const unsigned n_filt_in = N_FILT_6;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_6;
    static const unsigned out_width = OUT_WIDTH_6;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias6_t bias_t;
    typedef model_default_t weight_t;
    typedef config6_mult mult_config;
    typedef config6_relu relu_config;
};

struct config9_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config9_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 48;
    typedef ap_uint<8> accum_t;
    typedef bias9_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config9 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_6;
    static const unsigned in_width = OUT_WIDTH_6;
    static const unsigned n_chan = N_FILT_6-1;
    static const unsigned n_chan_in = N_FILT_6;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_9-1;
    static const unsigned n_filt_in = N_FILT_9;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_9;
    static const unsigned out_width = OUT_WIDTH_9;
    static const unsigned reuse_factor = 48;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias9_t bias_t;
    typedef model_default_t weight_t;
    typedef config9_mult mult_config;
    typedef config9_relu relu_config;
};

struct config12_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config12_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config12 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_9;
    static const unsigned in_width = OUT_WIDTH_9;
    static const unsigned n_chan = N_FILT_9-1;
    static const unsigned n_chan_in = N_FILT_9;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_12-1;
    static const unsigned n_filt_in = N_FILT_12;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_12;
    static const unsigned out_width = OUT_WIDTH_12;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef config12_mult mult_config;
    typedef config12_relu relu_config;
};

struct config14_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config14_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias14_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config14 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_5;
    static const unsigned in_width = OUT_WIDTH_5;
    static const unsigned n_chan = N_FILT_5-1;
    static const unsigned n_chan_in = N_FILT_5;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_14-1;
    static const unsigned n_filt_in = N_FILT_14;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_14;
    static const unsigned out_width = OUT_WIDTH_14;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias14_t bias_t;
    typedef model_default_t weight_t;
    typedef config14_mult mult_config;
    typedef config14_relu relu_config;
};

struct config16 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_12;
};

struct config178 : nnet::split_config {
    static const unsigned n_elem = N_FILT_12;
};

struct config18_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config18_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias18_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config18 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_12;
    static const unsigned in_width = OUT_WIDTH_12;
    static const unsigned n_chan = N_FILT_12-1;
    static const unsigned n_chan_in = N_FILT_12;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_18-1;
    static const unsigned n_filt_in = N_FILT_18;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_18;
    static const unsigned out_width = OUT_WIDTH_18;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias18_t bias_t;
    typedef model_default_t weight_t;
    typedef config18_mult mult_config;
    typedef config18_relu relu_config;
};

struct config21_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config21_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 48;
    typedef ap_uint<8> accum_t;
    typedef bias21_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config21 : nnet::conv2d_config {
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
    static const unsigned n_filt = N_FILT_21-1;
    static const unsigned n_filt_in = N_FILT_21;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_21;
    static const unsigned out_width = OUT_WIDTH_21;
    static const unsigned reuse_factor = 48;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias21_t bias_t;
    typedef model_default_t weight_t;
    typedef config21_mult mult_config;
    typedef config21_relu relu_config;
};

struct config24_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config24_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias24_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config24 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_21;
    static const unsigned in_width = OUT_WIDTH_21;
    static const unsigned n_chan = N_FILT_21-1;
    static const unsigned n_chan_in = N_FILT_21;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_24-1;
    static const unsigned n_filt_in = N_FILT_24;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_24;
    static const unsigned out_width = OUT_WIDTH_24;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias24_t bias_t;
    typedef model_default_t weight_t;
    typedef config24_mult mult_config;
    typedef config24_relu relu_config;
};

struct config26 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_24;
};

struct config179 : nnet::split_config {
    static const unsigned n_elem = N_FILT_24;
};

struct config28_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config28_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias28_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config28 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_24;
    static const unsigned in_width = OUT_WIDTH_24;
    static const unsigned n_chan = N_FILT_24-1;
    static const unsigned n_chan_in = N_FILT_24;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_28-1;
    static const unsigned n_filt_in = N_FILT_28;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_28;
    static const unsigned out_width = OUT_WIDTH_28;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias28_t bias_t;
    typedef model_default_t weight_t;
    typedef config28_mult mult_config;
    typedef config28_relu relu_config;
};

struct config31_relu : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config31_mult : nnet::dense_config {
    static const unsigned n_in = 576;
    static const unsigned n_out = 64;
    static const unsigned reuse_factor = 48;
    typedef ap_uint<8> accum_t;
    typedef bias31_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config31 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_28;
    static const unsigned in_width = OUT_WIDTH_28;
    static const unsigned n_chan = N_FILT_28-1;
    static const unsigned n_chan_in = N_FILT_28;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_31-1;
    static const unsigned n_filt_in = N_FILT_31;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_31;
    static const unsigned out_width = OUT_WIDTH_31;
    static const unsigned reuse_factor = 48;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias31_t bias_t;
    typedef model_default_t weight_t;
    typedef config31_mult mult_config;
    typedef config31_relu relu_config;
};

struct config34_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config34_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias34_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config34 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_31;
    static const unsigned in_width = OUT_WIDTH_31;
    static const unsigned n_chan = N_FILT_31-1;
    static const unsigned n_chan_in = N_FILT_31;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_34-1;
    static const unsigned n_filt_in = N_FILT_34;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_34;
    static const unsigned out_width = OUT_WIDTH_34;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias34_t bias_t;
    typedef model_default_t weight_t;
    typedef config34_mult mult_config;
    typedef config34_relu relu_config;
};

struct config36 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_34;
};

struct config180 : nnet::split_config {
    static const unsigned n_elem = N_FILT_34;
};

struct config38_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config38_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias38_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config38 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_34;
    static const unsigned in_width = OUT_WIDTH_34;
    static const unsigned n_chan = N_FILT_34-1;
    static const unsigned n_chan_in = N_FILT_34;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_38-1;
    static const unsigned n_filt_in = N_FILT_38;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_38;
    static const unsigned out_width = OUT_WIDTH_38;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias38_t bias_t;
    typedef model_default_t weight_t;
    typedef config38_mult mult_config;
    typedef config38_relu relu_config;
};

struct config41_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config41_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 48;
    typedef ap_uint<8> accum_t;
    typedef bias41_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config41 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_38;
    static const unsigned in_width = OUT_WIDTH_38;
    static const unsigned n_chan = N_FILT_38-1;
    static const unsigned n_chan_in = N_FILT_38;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_41-1;
    static const unsigned n_filt_in = N_FILT_41;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_41;
    static const unsigned out_width = OUT_WIDTH_41;
    static const unsigned reuse_factor = 48;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias41_t bias_t;
    typedef model_default_t weight_t;
    typedef config41_mult mult_config;
    typedef config41_relu relu_config;
};

struct config44_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config44_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias44_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config44 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_41;
    static const unsigned in_width = OUT_WIDTH_41;
    static const unsigned n_chan = N_FILT_41-1;
    static const unsigned n_chan_in = N_FILT_41;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_44-1;
    static const unsigned n_filt_in = N_FILT_44;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_44;
    static const unsigned out_width = OUT_WIDTH_44;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias44_t bias_t;
    typedef model_default_t weight_t;
    typedef config44_mult mult_config;
    typedef config44_relu relu_config;
};

struct config46_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config46_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 32;
    typedef ap_uint<8> accum_t;
    typedef bias46_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config46 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_34;
    static const unsigned in_width = OUT_WIDTH_34;
    static const unsigned n_chan = N_FILT_34-1;
    static const unsigned n_chan_in = N_FILT_34;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_46-1;
    static const unsigned n_filt_in = N_FILT_46;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_46;
    static const unsigned out_width = OUT_WIDTH_46;
    static const unsigned reuse_factor = 32;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias46_t bias_t;
    typedef model_default_t weight_t;
    typedef config46_mult mult_config;
    typedef config46_relu relu_config;
};

struct config48 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_44;
};

struct config181 : nnet::split_config {
    static const unsigned n_elem = N_FILT_44;
};

struct config50_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config50_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias50_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config50 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_44;
    static const unsigned in_width = OUT_WIDTH_44;
    static const unsigned n_chan = N_FILT_44-1;
    static const unsigned n_chan_in = N_FILT_44;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_50-1;
    static const unsigned n_filt_in = N_FILT_50;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_50;
    static const unsigned out_width = OUT_WIDTH_50;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias50_t bias_t;
    typedef model_default_t weight_t;
    typedef config50_mult mult_config;
    typedef config50_relu relu_config;
};

struct config53_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config53_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 192;
    typedef ap_uint<8> accum_t;
    typedef bias53_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config53 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_50;
    static const unsigned in_width = OUT_WIDTH_50;
    static const unsigned n_chan = N_FILT_50-1;
    static const unsigned n_chan_in = N_FILT_50;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_53-1;
    static const unsigned n_filt_in = N_FILT_53;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_53;
    static const unsigned out_width = OUT_WIDTH_53;
    static const unsigned reuse_factor = 192;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias53_t bias_t;
    typedef model_default_t weight_t;
    typedef config53_mult mult_config;
    typedef config53_relu relu_config;
};

struct config56_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config56_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias56_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config56 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_53;
    static const unsigned in_width = OUT_WIDTH_53;
    static const unsigned n_chan = N_FILT_53-1;
    static const unsigned n_chan_in = N_FILT_53;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_56-1;
    static const unsigned n_filt_in = N_FILT_56;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_56;
    static const unsigned out_width = OUT_WIDTH_56;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias56_t bias_t;
    typedef model_default_t weight_t;
    typedef config56_mult mult_config;
    typedef config56_relu relu_config;
};

struct config58 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_56;
};

struct config182 : nnet::split_config {
    static const unsigned n_elem = N_FILT_56;
};

struct config60_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config60_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias60_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config60 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_56;
    static const unsigned in_width = OUT_WIDTH_56;
    static const unsigned n_chan = N_FILT_56-1;
    static const unsigned n_chan_in = N_FILT_56;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_60-1;
    static const unsigned n_filt_in = N_FILT_60;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_60;
    static const unsigned out_width = OUT_WIDTH_60;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias60_t bias_t;
    typedef model_default_t weight_t;
    typedef config60_mult mult_config;
    typedef config60_relu relu_config;
};

struct config63_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config63_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 192;
    typedef ap_uint<8> accum_t;
    typedef bias63_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config63 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_60;
    static const unsigned in_width = OUT_WIDTH_60;
    static const unsigned n_chan = N_FILT_60-1;
    static const unsigned n_chan_in = N_FILT_60;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_63-1;
    static const unsigned n_filt_in = N_FILT_63;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_63;
    static const unsigned out_width = OUT_WIDTH_63;
    static const unsigned reuse_factor = 192;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias63_t bias_t;
    typedef model_default_t weight_t;
    typedef config63_mult mult_config;
    typedef config63_relu relu_config;
};

struct config66_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config66_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias66_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config66 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_63;
    static const unsigned in_width = OUT_WIDTH_63;
    static const unsigned n_chan = N_FILT_63-1;
    static const unsigned n_chan_in = N_FILT_63;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_66-1;
    static const unsigned n_filt_in = N_FILT_66;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_66;
    static const unsigned out_width = OUT_WIDTH_66;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias66_t bias_t;
    typedef model_default_t weight_t;
    typedef config66_mult mult_config;
    typedef config66_relu relu_config;
};

struct config68 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_66;
};

struct config183 : nnet::split_config {
    static const unsigned n_elem = N_FILT_66;
};

struct config70_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config70_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias70_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config70 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_66;
    static const unsigned in_width = OUT_WIDTH_66;
    static const unsigned n_chan = N_FILT_66-1;
    static const unsigned n_chan_in = N_FILT_66;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_70-1;
    static const unsigned n_filt_in = N_FILT_70;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_70;
    static const unsigned out_width = OUT_WIDTH_70;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias70_t bias_t;
    typedef model_default_t weight_t;
    typedef config70_mult mult_config;
    typedef config70_relu relu_config;
};

struct config73_relu : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config73_mult : nnet::dense_config {
    static const unsigned n_in = 1152;
    static const unsigned n_out = 128;
    static const unsigned reuse_factor = 192;
    typedef ap_uint<8> accum_t;
    typedef bias73_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config73 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_70;
    static const unsigned in_width = OUT_WIDTH_70;
    static const unsigned n_chan = N_FILT_70-1;
    static const unsigned n_chan_in = N_FILT_70;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_73-1;
    static const unsigned n_filt_in = N_FILT_73;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_73;
    static const unsigned out_width = OUT_WIDTH_73;
    static const unsigned reuse_factor = 192;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias73_t bias_t;
    typedef model_default_t weight_t;
    typedef config73_mult mult_config;
    typedef config73_relu relu_config;
};

struct config76_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config76_mult : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias76_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config76 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_73;
    static const unsigned in_width = OUT_WIDTH_73;
    static const unsigned n_chan = N_FILT_73-1;
    static const unsigned n_chan_in = N_FILT_73;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_76-1;
    static const unsigned n_filt_in = N_FILT_76;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_76;
    static const unsigned out_width = OUT_WIDTH_76;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias76_t bias_t;
    typedef model_default_t weight_t;
    typedef config76_mult mult_config;
    typedef config76_relu relu_config;
};

struct config78 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_76;
};

struct config184 : nnet::split_config {
    static const unsigned n_elem = N_FILT_76;
};

struct config80_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config80_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias80_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config80 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_76;
    static const unsigned in_width = OUT_WIDTH_76;
    static const unsigned n_chan = N_FILT_76-1;
    static const unsigned n_chan_in = N_FILT_76;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_80-1;
    static const unsigned n_filt_in = N_FILT_80;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_80;
    static const unsigned out_width = OUT_WIDTH_80;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias80_t bias_t;
    typedef model_default_t weight_t;
    typedef config80_mult mult_config;
    typedef config80_relu relu_config;
};

struct config83_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config83_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 192;
    typedef ap_uint<8> accum_t;
    typedef bias83_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config83 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_80;
    static const unsigned in_width = OUT_WIDTH_80;
    static const unsigned n_chan = N_FILT_80-1;
    static const unsigned n_chan_in = N_FILT_80;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_83-1;
    static const unsigned n_filt_in = N_FILT_83;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_83;
    static const unsigned out_width = OUT_WIDTH_83;
    static const unsigned reuse_factor = 192;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias83_t bias_t;
    typedef model_default_t weight_t;
    typedef config83_mult mult_config;
    typedef config83_relu relu_config;
};

struct config86_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config86_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias86_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config86 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_83;
    static const unsigned in_width = OUT_WIDTH_83;
    static const unsigned n_chan = N_FILT_83-1;
    static const unsigned n_chan_in = N_FILT_83;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_86-1;
    static const unsigned n_filt_in = N_FILT_86;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_86;
    static const unsigned out_width = OUT_WIDTH_86;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias86_t bias_t;
    typedef model_default_t weight_t;
    typedef config86_mult mult_config;
    typedef config86_relu relu_config;
};

struct config88_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config88_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 128;
    typedef ap_uint<8> accum_t;
    typedef bias88_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config88 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_76;
    static const unsigned in_width = OUT_WIDTH_76;
    static const unsigned n_chan = N_FILT_76-1;
    static const unsigned n_chan_in = N_FILT_76;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_88-1;
    static const unsigned n_filt_in = N_FILT_88;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_88;
    static const unsigned out_width = OUT_WIDTH_88;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias88_t bias_t;
    typedef model_default_t weight_t;
    typedef config88_mult mult_config;
    typedef config88_relu relu_config;
};

struct config90 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_86;
};

struct config185 : nnet::split_config {
    static const unsigned n_elem = N_FILT_86;
};

struct config92_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config92_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias92_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config92 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_86;
    static const unsigned in_width = OUT_WIDTH_86;
    static const unsigned n_chan = N_FILT_86-1;
    static const unsigned n_chan_in = N_FILT_86;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_92-1;
    static const unsigned n_filt_in = N_FILT_92;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_92;
    static const unsigned out_width = OUT_WIDTH_92;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias92_t bias_t;
    typedef model_default_t weight_t;
    typedef config92_mult mult_config;
    typedef config92_relu relu_config;
};

struct config95_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config95_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 768;
    typedef ap_uint<8> accum_t;
    typedef bias95_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config95 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_92;
    static const unsigned in_width = OUT_WIDTH_92;
    static const unsigned n_chan = N_FILT_92-1;
    static const unsigned n_chan_in = N_FILT_92;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_95-1;
    static const unsigned n_filt_in = N_FILT_95;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_95;
    static const unsigned out_width = OUT_WIDTH_95;
    static const unsigned reuse_factor = 768;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias95_t bias_t;
    typedef model_default_t weight_t;
    typedef config95_mult mult_config;
    typedef config95_relu relu_config;
};

struct config98_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config98_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias98_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config98 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_95;
    static const unsigned in_width = OUT_WIDTH_95;
    static const unsigned n_chan = N_FILT_95-1;
    static const unsigned n_chan_in = N_FILT_95;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_98-1;
    static const unsigned n_filt_in = N_FILT_98;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_98;
    static const unsigned out_width = OUT_WIDTH_98;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias98_t bias_t;
    typedef model_default_t weight_t;
    typedef config98_mult mult_config;
    typedef config98_relu relu_config;
};

struct config100 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_98;
};

struct config186 : nnet::split_config {
    static const unsigned n_elem = N_FILT_98;
};

struct config102_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config102_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias102_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config102 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_98;
    static const unsigned in_width = OUT_WIDTH_98;
    static const unsigned n_chan = N_FILT_98-1;
    static const unsigned n_chan_in = N_FILT_98;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_102-1;
    static const unsigned n_filt_in = N_FILT_102;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_102;
    static const unsigned out_width = OUT_WIDTH_102;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias102_t bias_t;
    typedef model_default_t weight_t;
    typedef config102_mult mult_config;
    typedef config102_relu relu_config;
};

struct config105_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config105_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 768;
    typedef ap_uint<8> accum_t;
    typedef bias105_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config105 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_102;
    static const unsigned in_width = OUT_WIDTH_102;
    static const unsigned n_chan = N_FILT_102-1;
    static const unsigned n_chan_in = N_FILT_102;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_105-1;
    static const unsigned n_filt_in = N_FILT_105;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_105;
    static const unsigned out_width = OUT_WIDTH_105;
    static const unsigned reuse_factor = 768;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias105_t bias_t;
    typedef model_default_t weight_t;
    typedef config105_mult mult_config;
    typedef config105_relu relu_config;
};

struct config108_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config108_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias108_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config108 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_105;
    static const unsigned in_width = OUT_WIDTH_105;
    static const unsigned n_chan = N_FILT_105-1;
    static const unsigned n_chan_in = N_FILT_105;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_108-1;
    static const unsigned n_filt_in = N_FILT_108;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_108;
    static const unsigned out_width = OUT_WIDTH_108;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias108_t bias_t;
    typedef model_default_t weight_t;
    typedef config108_mult mult_config;
    typedef config108_relu relu_config;
};

struct config110 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_108;
};

struct config187 : nnet::split_config {
    static const unsigned n_elem = N_FILT_108;
};

struct config112_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config112_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias112_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config112 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_108;
    static const unsigned in_width = OUT_WIDTH_108;
    static const unsigned n_chan = N_FILT_108-1;
    static const unsigned n_chan_in = N_FILT_108;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_112-1;
    static const unsigned n_filt_in = N_FILT_112;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_112;
    static const unsigned out_width = OUT_WIDTH_112;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias112_t bias_t;
    typedef model_default_t weight_t;
    typedef config112_mult mult_config;
    typedef config112_relu relu_config;
};

struct config115_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config115_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 768;
    typedef ap_uint<8> accum_t;
    typedef bias115_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config115 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_112;
    static const unsigned in_width = OUT_WIDTH_112;
    static const unsigned n_chan = N_FILT_112-1;
    static const unsigned n_chan_in = N_FILT_112;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_115-1;
    static const unsigned n_filt_in = N_FILT_115;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_115;
    static const unsigned out_width = OUT_WIDTH_115;
    static const unsigned reuse_factor = 768;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias115_t bias_t;
    typedef model_default_t weight_t;
    typedef config115_mult mult_config;
    typedef config115_relu relu_config;
};

struct config118_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config118_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias118_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config118 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_115;
    static const unsigned in_width = OUT_WIDTH_115;
    static const unsigned n_chan = N_FILT_115-1;
    static const unsigned n_chan_in = N_FILT_115;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_118-1;
    static const unsigned n_filt_in = N_FILT_118;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_118;
    static const unsigned out_width = OUT_WIDTH_118;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias118_t bias_t;
    typedef model_default_t weight_t;
    typedef config118_mult mult_config;
    typedef config118_relu relu_config;
};

struct config120 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_118;
};

struct config188 : nnet::split_config {
    static const unsigned n_elem = N_FILT_118;
};

struct config122_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config122_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias122_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config122 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_118;
    static const unsigned in_width = OUT_WIDTH_118;
    static const unsigned n_chan = N_FILT_118-1;
    static const unsigned n_chan_in = N_FILT_118;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_122-1;
    static const unsigned n_filt_in = N_FILT_122;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_122;
    static const unsigned out_width = OUT_WIDTH_122;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias122_t bias_t;
    typedef model_default_t weight_t;
    typedef config122_mult mult_config;
    typedef config122_relu relu_config;
};

struct config125_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config125_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 768;
    typedef ap_uint<8> accum_t;
    typedef bias125_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config125 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_122;
    static const unsigned in_width = OUT_WIDTH_122;
    static const unsigned n_chan = N_FILT_122-1;
    static const unsigned n_chan_in = N_FILT_122;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_125-1;
    static const unsigned n_filt_in = N_FILT_125;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_125;
    static const unsigned out_width = OUT_WIDTH_125;
    static const unsigned reuse_factor = 768;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias125_t bias_t;
    typedef model_default_t weight_t;
    typedef config125_mult mult_config;
    typedef config125_relu relu_config;
};

struct config128_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config128_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias128_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config128 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_125;
    static const unsigned in_width = OUT_WIDTH_125;
    static const unsigned n_chan = N_FILT_125-1;
    static const unsigned n_chan_in = N_FILT_125;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_128-1;
    static const unsigned n_filt_in = N_FILT_128;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_128;
    static const unsigned out_width = OUT_WIDTH_128;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias128_t bias_t;
    typedef model_default_t weight_t;
    typedef config128_mult mult_config;
    typedef config128_relu relu_config;
};

struct config130 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_128;
};

struct config189 : nnet::split_config {
    static const unsigned n_elem = N_FILT_128;
};

struct config132_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config132_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias132_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config132 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_128;
    static const unsigned in_width = OUT_WIDTH_128;
    static const unsigned n_chan = N_FILT_128-1;
    static const unsigned n_chan_in = N_FILT_128;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_132-1;
    static const unsigned n_filt_in = N_FILT_132;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_132;
    static const unsigned out_width = OUT_WIDTH_132;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias132_t bias_t;
    typedef model_default_t weight_t;
    typedef config132_mult mult_config;
    typedef config132_relu relu_config;
};

struct config135_relu : nnet::activ_config {
    static const unsigned n_in = 256;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config135_mult : nnet::dense_config {
    static const unsigned n_in = 2304;
    static const unsigned n_out = 256;
    static const unsigned reuse_factor = 768;
    typedef ap_uint<8> accum_t;
    typedef bias135_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config135 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_132;
    static const unsigned in_width = OUT_WIDTH_132;
    static const unsigned n_chan = N_FILT_132-1;
    static const unsigned n_chan_in = N_FILT_132;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_135-1;
    static const unsigned n_filt_in = N_FILT_135;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_135;
    static const unsigned out_width = OUT_WIDTH_135;
    static const unsigned reuse_factor = 768;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias135_t bias_t;
    typedef model_default_t weight_t;
    typedef config135_mult mult_config;
    typedef config135_relu relu_config;
};

struct config138_relu : nnet::activ_config {
    static const unsigned n_in = 1024;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config138_mult : nnet::dense_config {
    static const unsigned n_in = 256;
    static const unsigned n_out = 1024;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias138_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config138 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_135;
    static const unsigned in_width = OUT_WIDTH_135;
    static const unsigned n_chan = N_FILT_135-1;
    static const unsigned n_chan_in = N_FILT_135;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_138-1;
    static const unsigned n_filt_in = N_FILT_138;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_138;
    static const unsigned out_width = OUT_WIDTH_138;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias138_t bias_t;
    typedef model_default_t weight_t;
    typedef config138_mult mult_config;
    typedef config138_relu relu_config;
};

struct config140 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_138;
};

struct config190 : nnet::split_config {
    static const unsigned n_elem = N_FILT_138;
};

struct config142_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config142_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias142_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config142 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_138;
    static const unsigned in_width = OUT_WIDTH_138;
    static const unsigned n_chan = N_FILT_138-1;
    static const unsigned n_chan_in = N_FILT_138;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_142-1;
    static const unsigned n_filt_in = N_FILT_142;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_142;
    static const unsigned out_width = OUT_WIDTH_142;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias142_t bias_t;
    typedef model_default_t weight_t;
    typedef config142_mult mult_config;
    typedef config142_relu relu_config;
};

struct config145_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config145_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 768;
    typedef ap_uint<8> accum_t;
    typedef bias145_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config145 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_142;
    static const unsigned in_width = OUT_WIDTH_142;
    static const unsigned n_chan = N_FILT_142-1;
    static const unsigned n_chan_in = N_FILT_142;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_145-1;
    static const unsigned n_filt_in = N_FILT_145;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_145;
    static const unsigned out_width = OUT_WIDTH_145;
    static const unsigned reuse_factor = 768;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias145_t bias_t;
    typedef model_default_t weight_t;
    typedef config145_mult mult_config;
    typedef config145_relu relu_config;
};

struct config148_relu : nnet::activ_config {
    static const unsigned n_in = 2048;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config148_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 2048;
    typedef ap_uint<8> accum_t;
    typedef bias148_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config148 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_145;
    static const unsigned in_width = OUT_WIDTH_145;
    static const unsigned n_chan = N_FILT_145-1;
    static const unsigned n_chan_in = N_FILT_145;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_148-1;
    static const unsigned n_filt_in = N_FILT_148;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_148;
    static const unsigned out_width = OUT_WIDTH_148;
    static const unsigned reuse_factor = 2048;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias148_t bias_t;
    typedef model_default_t weight_t;
    typedef config148_mult mult_config;
    typedef config148_relu relu_config;
};

struct config150_relu : nnet::activ_config {
    static const unsigned n_in = 2048;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config150_mult : nnet::dense_config {
    static const unsigned n_in = 1024;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 512;
    typedef ap_uint<8> accum_t;
    typedef bias150_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config150 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_138;
    static const unsigned in_width = OUT_WIDTH_138;
    static const unsigned n_chan = N_FILT_138-1;
    static const unsigned n_chan_in = N_FILT_138;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_150-1;
    static const unsigned n_filt_in = N_FILT_150;
    static const unsigned stride_height = 2;
    static const unsigned stride_width = 2;
    static const unsigned out_height = OUT_HEIGHT_150;
    static const unsigned out_width = OUT_WIDTH_150;
    static const unsigned reuse_factor = 512;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias150_t bias_t;
    typedef model_default_t weight_t;
    typedef config150_mult mult_config;
    typedef config150_relu relu_config;
};

struct config152 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_148;
};

struct config191 : nnet::split_config {
    static const unsigned n_elem = N_FILT_148;
};

struct config154_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config154_mult : nnet::dense_config {
    static const unsigned n_in = 2048;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2048;
    typedef ap_uint<8> accum_t;
    typedef bias154_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config154 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_148;
    static const unsigned in_width = OUT_WIDTH_148;
    static const unsigned n_chan = N_FILT_148-1;
    static const unsigned n_chan_in = N_FILT_148;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_154-1;
    static const unsigned n_filt_in = N_FILT_154;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_154;
    static const unsigned out_width = OUT_WIDTH_154;
    static const unsigned reuse_factor = 2048;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias154_t bias_t;
    typedef model_default_t weight_t;
    typedef config154_mult mult_config;
    typedef config154_relu relu_config;
};

struct config157_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config157_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2304;
    typedef ap_uint<8> accum_t;
    typedef bias157_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config157 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_154;
    static const unsigned in_width = OUT_WIDTH_154;
    static const unsigned n_chan = N_FILT_154-1;
    static const unsigned n_chan_in = N_FILT_154;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_157-1;
    static const unsigned n_filt_in = N_FILT_157;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_157;
    static const unsigned out_width = OUT_WIDTH_157;
    static const unsigned reuse_factor = 2304;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias157_t bias_t;
    typedef model_default_t weight_t;
    typedef config157_mult mult_config;
    typedef config157_relu relu_config;
};

struct config160_relu : nnet::activ_config {
    static const unsigned n_in = 2048;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config160_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 2048;
    typedef ap_uint<8> accum_t;
    typedef bias160_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config160 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_157;
    static const unsigned in_width = OUT_WIDTH_157;
    static const unsigned n_chan = N_FILT_157-1;
    static const unsigned n_chan_in = N_FILT_157;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_160-1;
    static const unsigned n_filt_in = N_FILT_160;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_160;
    static const unsigned out_width = OUT_WIDTH_160;
    static const unsigned reuse_factor = 2048;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias160_t bias_t;
    typedef model_default_t weight_t;
    typedef config160_mult mult_config;
    typedef config160_relu relu_config;
};

struct config162 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_160;
};

struct config192 : nnet::split_config {
    static const unsigned n_elem = N_FILT_160;
};

struct config164_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config164_mult : nnet::dense_config {
    static const unsigned n_in = 2048;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2048;
    typedef ap_uint<8> accum_t;
    typedef bias164_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config164 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_160;
    static const unsigned in_width = OUT_WIDTH_160;
    static const unsigned n_chan = N_FILT_160-1;
    static const unsigned n_chan_in = N_FILT_160;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_164-1;
    static const unsigned n_filt_in = N_FILT_164;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_164;
    static const unsigned out_width = OUT_WIDTH_164;
    static const unsigned reuse_factor = 2048;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias164_t bias_t;
    typedef model_default_t weight_t;
    typedef config164_mult mult_config;
    typedef config164_relu relu_config;
};

struct config167_relu : nnet::activ_config {
    static const unsigned n_in = 512;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config167_mult : nnet::dense_config {
    static const unsigned n_in = 4608;
    static const unsigned n_out = 512;
    static const unsigned reuse_factor = 2304;
    typedef ap_uint<8> accum_t;
    typedef bias167_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config167 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_164;
    static const unsigned in_width = OUT_WIDTH_164;
    static const unsigned n_chan = N_FILT_164-1;
    static const unsigned n_chan_in = N_FILT_164;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_167-1;
    static const unsigned n_filt_in = N_FILT_167;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_167;
    static const unsigned out_width = OUT_WIDTH_167;
    static const unsigned reuse_factor = 2304;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias167_t bias_t;
    typedef model_default_t weight_t;
    typedef config167_mult mult_config;
    typedef config167_relu relu_config;
};

struct config170_relu : nnet::activ_config {
    static const unsigned n_in = 2048;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};

struct config170_mult : nnet::dense_config {
    static const unsigned n_in = 512;
    static const unsigned n_out = 2048;
    static const unsigned reuse_factor = 2048;
    typedef ap_uint<8> accum_t;
    typedef bias170_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
};

struct config170 : nnet::conv2d_config {
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_height = OUT_HEIGHT_167;
    static const unsigned in_width = OUT_WIDTH_167;
    static const unsigned n_chan = N_FILT_167-1;
    static const unsigned n_chan_in = N_FILT_167;
    static const unsigned filt_height = 1;
    static const unsigned filt_width = 1;
    static const unsigned n_filt = N_FILT_170-1;
    static const unsigned n_filt_in = N_FILT_170;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_170;
    static const unsigned out_width = OUT_WIDTH_170;
    static const unsigned reuse_factor = 2048;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef bias170_t bias_t;
    typedef model_default_t weight_t;
    typedef config170_mult mult_config;
    typedef config170_relu relu_config;
};

struct config172 : nnet::merge_config {
    static const unsigned n_elem = N_FILT_170;
};

struct config174 : nnet::pooling2d_config {
    static const unsigned in_height = 7;
    static const unsigned in_width =  OUT_WIDTH_170;
    static const unsigned n_filt =    N_FILT_174-1;
    static const unsigned n_chan =    N_FILT_174-1;
    static const unsigned n_filt_in = N_FILT_174;
    static const unsigned n_chan_in = N_FILT_174;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned pool_height = 7;
    static const unsigned pool_width = 7;
    static const unsigned filt_height = 7;
    static const unsigned filt_width = 7;
    static const unsigned out_height = OUT_HEIGHT_174;
    static const unsigned out_width = OUT_WIDTH_174;
    static const unsigned pad_top = 0;
    static const unsigned pad_bottom = 0;
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const nnet::Pool_Op pool_op = nnet::Average;
    static const unsigned reuse = 1;
};

struct config175 : nnet::dense_config {
    static const unsigned n_in = (N_FILT_174-1)*OUT_HEIGHT_174*OUT_WIDTH_174;
    static const unsigned n_out = N_LAYER_175;
    static const unsigned io_type = nnet::io_serial;
    static const unsigned reuse_factor = 20480;//10*4096;//20480;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 1024000;
    static const bool store_weights_in_bram = false;
    typedef ap_uint<8> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef model_bigdefault_t weightmult_t;
    typedef ap_uint<1> index_t;
};

struct softmax_config176 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_175;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_serial;
};


#endif
