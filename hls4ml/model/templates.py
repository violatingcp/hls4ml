
dense_config_template = """struct config{index} : nnet::dense_config {{
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

conv_mult_config_template = """struct config{index}_mult : nnet::dense_config {{
    static const unsigned n_in = {n_in};
    static const unsigned n_out = {n_out};
    static const unsigned reuse_factor = {reuse};
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
}};\n"""


conv2d_activ_config_template = """struct {type}_config{index}_relu : nnet::activ_config {{
    static const unsigned n_in = {n_in};
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::{iotype};
}};\n"""

conv2d_config_template = """struct config{index} : nnet::conv2d_config {{
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
    typedef {config_t} relu_config;
}};\n"""


conv2dmerge_mult_config_template = """struct config{index}_mult : nnet::dense_config {{
    static const unsigned n_in = {n_in};
    static const unsigned n_out = {n_out};
    static const unsigned reuse_factor = {reuse};
    typedef {accum_t} accum_t;
    typedef {bias_t} bias_t;
    typedef {weight_t} weight_t;
}};\n"""


conv2dmerge_activ_config_template = """struct {type}_config{index}_relu : nnet::activ_config {{
    static const unsigned n_in = {n_in};
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::{iotype};
}};\n"""

conv2dmerge_batchnorm_config_template = """struct config{index}_norm : nnet::batchnorm_config {{
    static const unsigned n_in = {n_in};
    static const unsigned n_filt = {n_filt};
    static const unsigned io_type = nnet::{iotype};
    static const unsigned reuse_factor = {reuse};
    static const bool store_weights_in_bram = false;
    typedef {bias_t} bias_t;
    typedef {scale_t} scale_t;
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
    typedef {config_t} relu_config;
    typedef {config_t} norm_config;
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
    static const unsigned stride_height = {stride_height};
    static const unsigned stride_width = {stride_width};
    static const unsigned pool_height = {pool_height};
    static const unsigned pool_width = {pool_width};
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

config_templates = {
    'Dense'                  : dense_config_template,
    'BinaryDense'            : dense_config_template,
    'BatchNormalization'     : batchnorm_config_template,
    'Conv1D'                 : [conv1d_config_template, conv_mult_config_template],
    'Conv2D'                 : [conv2d_config_template, conv_mult_config_template,conv2d_activ_config_template],
    'Conv2DMerge'            : [conv2dmerge_config_template, conv2dmerge_mult_config_template,conv2dmerge_activ_config_template,conv2dmerge_norm_config_template],
    'Activation'             : activ_config_template,
    'ParametrizedActivation' : activ_config_template,
    'PReLU'                  : activ_config_template,
    'Pooling1D'              : pooling1d_config_template,
    'Pooling2D'              : pooling2d_config_template,
    'Merge'                  : merge_config_template,
    'Split'                  : split_config_template,
    'Concatenate'            : concat_config_template,
}

dense_function_template = 'nnet::dense_{strategy}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
batchnorm_function_template = 'nnet::normalize<{input_t}, {output_t}, {config}>({input}, {output}, {scale}, {bias});'
conv1d_function_template = 'nnet::conv_1d_{strategy}_{data_format}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
conv2d_function_template = 'if(!{input}[0].empty())nnet::conv_2d_{strategy}_{data_format}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
conv2dmerge_function_template = 'nnet::conv_2d_merge_{strategy}_{data_format}<{input_t}, {output_t}, {config}>({input}, {output}, {w}, {b});'
activ_function_template = 'nnet::{activation}<{input_t}, {output_t}, {config}>({input}, {output});'
param_activ_function_template = 'nnet::{activation}<{input_t}, {output_t}, {config}>({input}, {param}, {output});'
pooling1d_function_template = 'nnet::pooling1d<{input_t}, {config}>({input}, {output});'
pooling2d_function_template = 'nnet::pooling2d_{data_format}<{input_t}, {config}>({input}, {output});'
merge_function_template = 'nnet::{merge}<{input1_t}, {input2_t}, {output_t}, {config}>({input1}, {input2}, {output});'
split_function_template = 'nnet::split<{input1_t}, {output_t}, {config}>({input}, {output1}, {output2});'
pad_function_template    = 'nnet::pad_2d_cl<{input_t}, {output_t}, {config}>({input}, {output});'

function_templates = {
    'Dense'                  : dense_function_template,
    'BinaryDense'            : dense_function_template,
    'BatchNormalization'     : batchnorm_function_template,
    'Conv1D'                 : conv1d_function_template,
    'Conv2D'                 : conv2d_function_template,
    'Pad'                    : pad_function_template,
    'Conv2DMerge'            : conv2dmerge_function_template,
    'Activation'             : activ_function_template,
    'ParametrizedActivation' : param_activ_function_template,
    'PReLU'                  : param_activ_function_template,
    'Pooling1D'              : pooling1d_function_template,
    'Pooling2D'              : pooling2d_function_template,
    'Merge'                  : merge_function_template,
    'Concatenate'            : merge_function_template,
    'Split'                  : split_function_template,
}

dense_tcl_template = """set arg_0 "-I . -DN_1={n_in} -DN_2={n_out}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set arg_3 "-DWEIGHTS={weights}  -DBIASES={biases}"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type dense_{strategy}
}};\n"""

merge_tcl_template = """set arg_0 "-I . -DN_1={n_elem} -DN_2={n_elem}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_1_T={input1_t} -DINPUT_2_T={input2_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type {merge}
}};\n"""

pooling2d_tcl_template = """set arg_0 "-I . -DN_INPUT={n_chan} -DN_OUTPUT={n_filt}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type pooling2d_{data_format}
}};\n"""

conv_2d_tcl_template = """set arg_0 "-I . -DN_INPUT={n_chan} -DN_OUTPUT={n_filt}"
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set arg_3 "-DWEIGHTS={weights}  -DBIASES={biases}"
set args "$arg_0 $arg_1 $arg_2 $arg_3"
set layer_type conv_2d_{strategy}_{data_format}
}};\n"""

split_tcl_template = """set arg_0 "-I . -DN={n_elem}" 
set arg_1 "-DCONFIG={config}"
set arg_2 "-DINPUT_T={input_t} -DLAYER_T={output_t}"
set args "$arg_0 $arg_1 $arg_2"
set layer_type nnet_split
}};\n"""

tcl_templates = {
    'Dense'                  : dense_tcl_template,
    'BinaryDense'            : dense_tcl_template,
    'Conv1D'                 : conv2d_tcl_template,
    'Conv2D'                 : conv2d_tcl_template,
    'Activation'             : activ_tcl_template,
    'Pooling1D'              : pooling2d_tcl_template,
    'Pooling2D'              : pooling2d_tcl_template,
    'Merge'                  : merge_tcl_template,
    'Concatenate'            : merge_tcl_template,
    'Split'                  : split_tcl_template,   
}



def get_config_template(kind):
    return config_templates.get(kind)

def get_function_template(kind):
    return function_templates.get(kind)

def get_tcl_template(kind):
    return tcl_templates.get(kind)

def register_templates(name, function_template, config_template, tcl_template):
    global function_templates
    global config_templates
    global tcl_templates

    function_templates[name] = function_template
    config_templates[name] = config_template
    tcl_templates[name] = tcl_template
