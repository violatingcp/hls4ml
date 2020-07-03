
import numpy as np
import math

from .templates import Backend

dense_config_template = """struct config{index} : nnet::dense_config {{
    static const unsigned block_factor = {block_factor};
    static const unsigned merge_factor = {merge_factor};
    static const unsigned n_input = {n_input};
    static const unsigned n_output = {n_output};
    static const unsigned n_in = {n_in};
    static const unsigned n_out = {n_out};
    static const unsigned io_type = nnet::{iotype};
    static const unsigned reuse_factor = {reuse};
    static const unsigned n_zeros = {nzeros};
    static const unsigned n_nonzeros = {nonzeros};
    static const bool store_weights_in_bram = false;
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
    typedef {bigweight_t} weightmult_t;
    typedef {index_t} index_t;
}};\n"""

batchnorm_config_template = """struct config{index} : nnet::batchnorm_config {{
    static const unsigned n_in = {n_in};
    static const unsigned n_filt = {n_filt};
    static const unsigned io_type = nnet::{iotype};
    static const unsigned reuse_factor = {reuse};
    static const bool store_weights_in_bram = false;
    typedef {bias_t} bias_t;
    typedef {scale_t} scale_t;
}};\n"""

conv1d_config_template = """struct config{index} : nnet::conv1d_config {{
    static const unsigned pad_left = {pad_left};
    static const unsigned pad_right = {pad_right};
    static const unsigned n_in = {n_in};
    static const unsigned n_chan = {n_chan};
    static const unsigned filt_width = {filt_width};
    static const unsigned n_filt = {n_filt};
    static const unsigned stride = {stride};
    static const unsigned dilation = {dilation};
    static const unsigned n_out = {n_out};
    static const unsigned reuse_factor = {reuse};
    static const unsigned n_zeros = {nzeros};
    static const bool store_weights_in_bram = false;
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
    typedef {config_t} mult_config;
}};\n"""

upsampling2d_config_template = """struct config{index} : nnet::upsampling2d_config {{
    static const unsigned height_factor = {height_factor};
    static const unsigned width_factor = {width_factor};
    static const unsigned in_height = {in_height};
    static const unsigned in_width = {in_width};
    static const unsigned out_height = {out_height};
    static const unsigned out_width = {out_width};
    static const unsigned n_chan    = {n_channel};
    static const nnet::Interp_Op interp_op = nnet::{interp_op};
}};\n"""

conv_mult_config_template = """struct config{index}_mult : nnet::dense_config {{
    static const unsigned n_in = {n_in};
    static const unsigned n_out = {n_out};
    static const unsigned reuse_factor = {reuse};
    static const unsigned merge_factor = {merge_factor};
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
    typedef {bigweight_t} weightmult_t;
}};\n"""

conv2d_config_template = """struct config{index} : nnet::conv2d_config {{
    static const unsigned pad_top = {pad_top};
    static const unsigned pad_bottom = {pad_bottom};
    static const unsigned pad_left = {pad_left};
    static const unsigned pad_right = {pad_right};
    static const unsigned in_height = {in_height};
    static const unsigned in_width = {in_width};
    static const unsigned n_chan = {n_chan};
    static const unsigned n_chan_in = {n_chan_in};
    static const unsigned filt_height = {filt_height};
    static const unsigned filt_width = {filt_width};
    static const unsigned n_filt = {n_filt};
    static const unsigned n_filt_in = {n_filt_in};
    static const unsigned stride_height = {stride_height};
    static const unsigned stride_width = {stride_width};
    static const unsigned out_height = {out_height};
    static const unsigned out_width = {out_width};
    static const unsigned reuse_factor = {reuse};
    static const unsigned n_zeros = {nzeros};
    static const bool store_weights_in_bram = false;
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
    typedef {config_t} mult_config;
    typedef {config_t_relu} relu_config;
}};\n"""


conv_norm_config_template = """struct config{index}_norm : nnet::dense_config {{
    static const unsigned n_in = {n_in};
    static const unsigned n_filt = {n_filt};
    static const unsigned io_type = nnet::{iotype};
    static const unsigned reuse_factor = {reuse};
    static const bool store_weights_in_bram = false;
    typedef {bias_t} bias_t;
    typedef {scale_t} scale_t;
}};\n"""

conv_relu_config_template = """struct config{index}_relu : nnet::activ_config {{
    static const unsigned n_in = {n_in};
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::{iotype};
}};\n"""


conv2dmerge_config_template = """struct config{index} : nnet::conv2d_config {{
    static const unsigned pad_top = {pad_top};
    static const unsigned pad_bottom = {pad_bottom};
    static const unsigned pad_left = {pad_left};
    static const unsigned pad_right = {pad_right};
    static const unsigned in_height = {in_height};
    static const unsigned in_width = {in_width};
    static const unsigned n_chan = {n_chan};
    static const unsigned filt_height = {filt_height};
    static const unsigned filt_width = {filt_width};
    static const unsigned n_filt = {n_filt};
    static const unsigned stride_height = {stride_height};
    static const unsigned stride_width = {stride_width};
    static const unsigned out_height = {out_height};
    static const unsigned out_width = {out_width};
    static const unsigned reuse_factor = {reuse};
    static const unsigned n_zeros = {nzeros};
    static const bool store_weights_in_bram = false;
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
    typedef {config_t} mult_config;
    typedef {config_t_relu} relu_config;
}};\n"""

activ_config_template = """struct {type}_config{index} : nnet::activ_config {{
    static const unsigned n_in = {n_in};
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::{iotype};
}};\n"""

pooling1d_config_template = """struct config{index} : nnet::pooling1d_config {{
    static const unsigned n_in = {n_in};
    static const unsigned pool_size = {pool_size};
    static const unsigned n_out = {n_out};
    static const unsigned pad_left = {pad_left};
    static const unsigned pad_right = {pad_right};
    static const unsigned stride = {stride};
    static const nnet::Pool_Op pool_op = nnet::{pool_op};
}};\n"""

pooling2d_config_template = """struct config{index} : nnet::pooling2d_config {{
    static const unsigned in_height = {in_height};
    static const unsigned in_width = {in_width};
    static const unsigned n_filt = {n_filt};
    static const unsigned n_chan = {n_chan};
    static const unsigned n_filt_in = {n_filt_in};
    static const unsigned n_chan_in = {n_chan_in};
    static const unsigned stride_height = {stride_height};
    static const unsigned stride_width = {stride_width};
    static const unsigned pool_height = {pool_height};
    static const unsigned pool_width = {pool_width};
    static const unsigned filt_height = {pool_height};
    static const unsigned filt_width = {pool_width};
    static const unsigned out_height = {out_height};
    static const unsigned out_width = {out_width};
    static const unsigned pad_top = {pad_top};
    static const unsigned pad_bottom = {pad_bottom};
    static const unsigned pad_left = {pad_left};
    static const unsigned pad_right = {pad_right};
    static const nnet::Pool_Op pool_op = nnet::{pool_op};
    static const unsigned reuse = {reuse};
}};\n"""

merge_config_template = """struct config{index} : nnet::merge_config {{
    static const unsigned n_elem = {n_elem};
}};\n"""

split_config_template = """struct config{index} : nnet::split_config {{
    static const unsigned n_elem = {n_elem};
}};\n"""

concat_config_template = """struct config{index} : nnet::concat_config {{
    static const unsigned n_elem1_0 = {n_elem1_0};
    static const unsigned n_elem1_1 = {n_elem1_1};
    static const unsigned n_elem1_2 = {n_elem1_2};
    static const unsigned n_elem2_0 = {n_elem2_0};
    static const unsigned n_elem2_1 = {n_elem2_1};
    static const unsigned n_elem2_2 = {n_elem2_2};

    static const unsigned axis = {axis};
}};\n"""

'''config_templates = {
    'Dense'                  : dense_config_template,
    'BinaryDense'            : dense_config_template,
    'BatchNormalization'     : batchnorm_config_template,
    'Conv1D'                 : [conv1d_config_template, conv_mult_config_template],
    'Conv2D'                 : [conv2d_config_template, conv_mult_config_template],
    'Upsampling2D'           : upsampling2d_config_template,
    'Conv2DMerge'            : [conv2dmerge_config_template, convmerge_mult_config_template],
    'Activation'             : activ_config_template,
    'ParametrizedActivation' : activ_config_template,
    'PReLU'                  : activ_config_template,
    'Pooling1D'              : pooling1d_config_template,
    'Pooling2D'              : pooling2d_config_template,
    'Merge'                  : merge_config_template,
    'Split'                  : split_config_template,
    'Concatenate'            : concat_config_template,
}'''

dense_function_template = 'nnet::dense_{strategy}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
batchnorm_function_template = 'nnet::normalize{strategy}<{input_t}, {output_t}, {config}>({input}, {output}, {scale}, {bias});'
conv1d_function_template = 'nnet::conv_1d_{strategy}_{data_format}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
conv2d_function_template = 'nnet::conv_2d_{strategy}_{data_format}{1x1}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
upsampling2d_function_template = 'nnet::upsampling2d_{strategy}<{input_t}, {output_t}, {config}>({input}, {output});'
conv2dmerge_function_template = 'nnet::conv_2d_merge_{strategy}_{data_format}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
activ_function_template = 'nnet::{activation}{strategy}<{input_t}, {output_t}, {config}>({input}, {output});'
param_activ_function_template = 'nnet::{activation}{strategy}<{input_t}, {output_t}, {config}>({input}, {param}, {output});'
pooling1d_function_template = 'nnet::pooling1d<{input_t}, {config}>({input}, {output});'
pooling2d_function_template = 'nnet::pooling2d_{data_format}{1x1}<{input_t}, {output_t}, {config}>({input}, {output});'
merge_function_template = 'nnet::{merge}<{input1_t}, {input2_t}, {output_t}, {config}>({input1}, {input2}, {output});'
split_function_template = 'nnet::split<{input_t}, {output_t}, {config}>({input}, {output1}, {output2});'

'''function_templates = {
    'Dense'                  : dense_function_template,
    'BinaryDense'            : dense_function_template,
    'BatchNormalization'     : batchnorm_function_template,
    'Conv1D'                 : conv1d_function_template,
    'Conv2D'                 : conv2d_function_template,
    'Conv2DMerge'            : conv2dmerge_function_template,
    'UpSampling2D'           : upsampling2d_function_template,
    'Activation'             : activ_function_template,
    'ParametrizedActivation' : param_activ_function_template,
    'PReLU'                  : param_activ_function_template,
    'Pooling1D'              : pooling1d_function_template,
    'Pooling2D'              : pooling2d_function_template,
    'Merge'                  : merge_function_template,
    'Concatenate'            : merge_function_template,
    'Split'                  : split_function_template,   
}'''


dense_tcl_template = """set arg_0 "-I . -DN_1={n_in} -DN_2={n_out}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set arg_3 "-DN_WEIGHTS={n_weights} -DWEIGHTS={weights}  -DBIASES={biases}"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_{strategy}
\n
source ../common/build.tcl
\n"""


batchnorm_tcl_template = """set arg_0 "-I . -DN_1={n_in} -DN_2={n_filt}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set arg_3 "-DWEIGHTS={scale}  -DBIASES={biases}"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type normalize
\n
source ../common/build.tcl
\n"""

upsampling2d_tcl_template = """set arg_0 "-I . -DN_1={n_in} -DN_2={n_in}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type upsampling2d{strategy}
\n
source ../common/build.tcl
\n"""

activ_tcl_template = """set arg_0 "-I . -DN_1={n_in} -DN_2={n_in}"
set arg_1 "-DCONFIG={activation}_{config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type {activation}{strategy}
\n
source ../common/build.tcl
\n"""

merge_tcl_template = """set arg_0 "-I . -DN_1={n_elem} -DN_2={n_elem}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_1_T={input1_t} -DINPUT_2_T={input2_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type {merge}
\n
source ../common/build.tcl
\n"""

pooling2d_tcl_template = """set arg_0 "-I . -DN_INPUT={n_chan_in} -DN_OUTPUT={n_filt_in}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_{data_format}{1x1}
\n
source ../common/build.tcl
\n"""

conv_2d_tcl_template = """set arg_0 "-I . -DN_INPUT={n_chan_in} -DN_OUTPUT={n_filt_in}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set arg_3 "-DN_WEIGHTS={n_weights} -DWEIGHTS={weights}  -DBIASES={biases}"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_{strategy}_{data_format}{1x1}_port
\n
source ../common/build.tcl
\n"""

split_tcl_template = """set arg_0 "-I . -DN={n_elem}" 
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type nnet_split
\n
source ../common/build.tcl
\n"""

'''tcl_templates = {
    'Dense'                  : dense_tcl_template,
    'BinaryDense'            : dense_tcl_template,
    'BatchNormalization'     : batchnorm_tcl_template,
    'Conv1D'                 : conv2d_tcl_template,
    'Conv2D'                 : conv2d_tcl_template,
    'UpSampling2D'           : upsampling2d_tcl_template,
    'Activation'             : activ_tcl_template,
    'Pooling1D'              : pooling2d_tcl_template,
    'Pooling2D'              : pooling2d_tcl_template,
    'Merge'                  : merge_tcl_template,
    'Concatenate'            : merge_tcl_template,
    'Split'                  : split_tcl_template,   
}'''


class VivadoBackend(Backend):
    def __init__(self):
        super(VivadoBackend, self).__init__('Vivado')
        self.register_templates('Dense'                  , dense_function_template,       dense_config_template, dense_tcl_template)
        self.register_templates('BinaryDense'            , dense_function_template,       dense_config_template, dense_tcl_template)
        self.register_templates('BatchNormalization'     , batchnorm_function_template,   batchnorm_config_template, batchnorm_tcl_template)
        self.register_templates('Conv1D'                 , conv1d_function_template,      [conv1d_config_template, conv_mult_config_template],conv_2d_tcl_template)
        self.register_templates('Conv2D'                 , conv2d_function_template,      [conv2d_config_template, conv_mult_config_template,conv_relu_config_template],conv_2d_tcl_template)
        self.register_templates('Conv2DMerge'            , conv2dmerge_function_template, [conv2d_config_template, conv_mult_config_template, conv_norm_config_template, conv_relu_config_template],conv_2d_tcl_template)
        self.register_templates('UpSampling2D'           , upsampling2d_function_template, upsampling2d_config_template,upsampling2d_tcl_template)
        self.register_templates('Activation'             , activ_function_template,       activ_config_template,activ_tcl_template)
        self.register_templates('ParametrizedActivation' , param_activ_function_template, activ_config_template,activ_tcl_template)
        self.register_templates('PReLU'                  , param_activ_function_template, activ_config_template,activ_tcl_template)
        self.register_templates('Pooling1D'              , pooling1d_function_template,   pooling1d_config_template,pooling2d_tcl_template)
        self.register_templates('Pooling2D'              , pooling2d_function_template,   pooling2d_config_template,pooling2d_tcl_template)
        self.register_templates('Merge'                  , merge_function_template,       merge_config_template,merge_tcl_template)
        self.register_templates('Concatenate'            , merge_function_template,       concat_config_template,merge_tcl_template)
        self.register_templates('Split'                  , split_function_template,       split_config_template,split_tcl_template)
    
    def get_valid_reuse_factors(self, layer):
        n_in = 0
        n_out = 0
        if layer.__class__.__name__ == 'Dense':
            n_in = layer.get_attr('n_in')
            n_out = layer.get_attr('n_out')
        elif layer.__class__.__name__ == 'Conv1D':
            n_in = layer.get_attr('n_chan') * layer.get_attr('filt_width')
            n_out = layer.get_attr('n_filt')
        elif layer.__class__.__name__ == 'Conv2D':
            n_in = layer.get_attr('n_chan') * layer.get_attr('filt_height') * layer.get_attr('filt_width')
            n_out = layer.get_attr('n_filt')
        elif layer.__class__.__name__ == 'Conv2DMerge':
            n_in = layer.get_attr('n_chan') * layer.get_attr('filt_height') * layer.get_attr('filt_width')
            n_out = layer.get_attr('n_filt')

        max_rf = n_in * n_out
        valid_reuse_factors = []
        for rf in range(1, max_rf):
            _assert = self._check_conditions(n_in, n_out, rf)
            if _assert:
                valid_reuse_factors.append(rf)
        # Avoid using RF=1
        if valid_reuse_factors[0] == 1:
            valid_reuse_factors.pop(0)
        return valid_reuse_factors

    def _check_conditions(self, n_in, n_out, rf):
        multfactor = min(n_in, rf)
        multiplier_limit = int(math.ceil((n_in * n_out) / float(multfactor)))
        #
        # THIS ASSERTION IS FOR THE FUNCTIONAL CORRECTNESS OF THE DENSE LAYER
        #
        _assert = (((multiplier_limit % n_out) == 0) or (rf >= n_in))
        _assert = _assert and (((rf % n_in) == 0) or (rf < n_in))
        #
        # THIS ASSERTION IS FOR QoR AND EXECUTION TIME OF VIVADO HLS
        #
        _assert = _assert and (((n_in * n_out) % rf) == 0)

        return _assert

