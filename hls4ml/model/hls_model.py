from __future__ import print_function
import six
import re
import copy
import numpy as np
from collections import OrderedDict

from ..templates import get_backend
from ..writer import get_writer

class HLSConfig(object):
    def __init__(self, config):
        self.config = config

        self.backend = get_backend(self.config.get('Backend', 'Vivado'))
        self.writer = get_writer(self.config.get('Backend', 'Vivado'))

        self.model_precision = {}
        self.layer_type_precision = {}
        self.layer_name_precision = {}

        self.model_rf = None
        self.layer_type_rf = {}
        self.layer_name_rf = {}

        self.model_strategy = 'Latency'
        self.layer_type_strategy = {}
        self.layer_name_strategy = {}

        self.model_compression = False
        self.layer_type_compression = {}
        self.layer_name_compression = {}

        self._parse_hls_config()
        self._validate_hls_config()

    def get_config_value(self, key):
        return self.config.get(key, None)

    def get_project_name(self):
        return self.get_config_value('ProjectName')

    def get_output_dir(self):
        return self.get_config_value('OutputDir')

    def get_precision(self, layer, var='default'):
        precision = self.layer_name_precision.get(layer.name.lower() + '_' + var)
        type_name = layer.name.lower() + '_' + var + '_t'
        if precision is None:
            precision = self.layer_name_precision.get(layer.name.lower() + '_default')
            type_name = layer.name.lower() + '_default_t'

        if precision is None:
            precision = self.layer_type_precision.get(layer.__class__.__name__.lower() + '_' + var)
            type_name = layer.__class__.__name__ + '_' + var + '_t'
        if precision is None:
            precision = self.layer_type_precision.get(layer.__class__.__name__.lower() + '_default')
            type_name = layer.__class__.__name__ + '_default_t'

        if precision is None:
            precision = self.model_precision.get(var)
            type_name = var + '_default_t'
        if precision is None:
            precision = self.model_precision.get('default')
            type_name = 'model_default_t'

        if precision is None:
            raise Exception('No precision for {}->{} found and no default specified.'.format(layer.name, var))

        return (precision, type_name)

    def get_reuse_factor(self, layer):
        rf = self.layer_name_rf.get(layer.name.lower())
        if rf is None:
            rf = self.layer_type_rf.get(layer.__class__.__name__.lower())
        if rf is None:
            rf = self.model_rf

        if rf is None:
            raise Exception('No reuse factor for {} found and no default specified.'.format(layer.name))

        return rf

    def get_merge_factor(self, layer):
        mf = self.model_mf
        if mf is None:
            mf = 1
        return mf

    def get_bram_size(self, layer):
        bf = self.model_bf
        return bf

    def get_strategy(self, layer):
        strategy = self.layer_name_strategy.get(layer.name.lower())
        if strategy is None:
            strategy = self.layer_type_strategy.get(layer.__class__.__name__.lower())
        if strategy is None:
            strategy = self.model_strategy

        return strategy

    def is_resource_strategy(self, layer):
        return self.get_strategy(layer).lower() == 'resource'

    def get_compression(self, layer):
        compression = self.layer_name_compression.get(layer.name.lower())
        if compression is None:
            compression = self.layer_type_compression.get(layer.__class__.__name__.lower())
        if compression is None:
            compression = self.model_compression

        return compression

    def _parse_hls_config(self):
        hls_config = self.config['HLSConfig']
        model_cfg = hls_config.get('Model')
        if model_cfg is not None:
            precision_cfg = model_cfg.get('Precision')
            if precision_cfg is not None:
                if isinstance(precision_cfg, dict):
                    for var, precision in precision_cfg.items():
                        self.model_precision[var] = precision
                else:
                    self.model_precision['default'] = precision_cfg # Default precision for everything

            self.model_rf = model_cfg.get('ReuseFactor')
            self.model_mf = model_cfg.get('MergeFactor')
            self.model_bf = model_cfg.get('BramFactor')
            self.model_strategy = model_cfg.get('Strategy', 'Latency')
            self.model_compression = bool(model_cfg.get('Compression', 0))
            
        layer_type_cfg = hls_config.get('LayerType')
        if layer_type_cfg is not None:
            for layer_type, layer_cfg in layer_type_cfg.items():
                precision_cfg = layer_cfg.get('Precision')
                if isinstance(precision_cfg, dict):
                    for var, precision in precision_cfg.items():
                        self.layer_type_precision[layer_type.lower() + '_' + var] = precision
                else:
                    self.layer_type_precision[layer_type.lower() + '_default'] = precision_cfg

                rf = layer_cfg.get('ReuseFactor')
                if rf is not None:
                    self.layer_type_rf[layer_type.lower()] = rf

                strategy = layer_cfg.get('Strategy')
                if strategy is not None:
                    self.layer_type_strategy[layer_type.lower()] = strategy

                compression = layer_cfg.get('Compression')
                if compression is not None:
                    self.layer_type_compression[layer_type.lower()] = bool(compression)

        layer_name_cfg = hls_config.get('LayerName')
        if layer_name_cfg is not None:
            for layer_name, layer_cfg in layer_name_cfg.items():
                precision_cfg = layer_cfg.get('Precision')
                if isinstance(precision_cfg, dict):
                    for var, precision in precision_cfg.items():
                        self.layer_name_precision[layer_name.lower() + '_' + var] = precision
                else:
                    self.layer_name_precision[layer_name.lower() + '_default'] = precision_cfg

                rf = layer_cfg.get('ReuseFactor')
                if rf is not None:
                    self.layer_name_rf[layer_name.lower()] = rf

                strategy = layer_cfg.get('Strategy')
                if strategy is not None:
                    self.layer_name_strategy[layer_name.lower()] = strategy

                compression = layer_cfg.get('Compression')
                if compression is not None:
                    self.layer_name_compression[layer_name.lower()] = bool(compression)

    def _validate_hls_config(self):
        use_resource = False
        if self.model_strategy.lower() == 'latency' and self.model_compression:
            print('WARNING: Compression enabled while model strategy set to "Latency".')
            use_resource = True
        for layer_type, strategy in self.layer_type_strategy.items():
            if strategy.lower() == 'resource' and self.model_strategy.lower() == 'latency':
                print('WARNING: Strategy for layer type {} set to "Resource", while model strategy set to "Latency".'.format(layer_type))
                use_resource = True

        for layer_name, strategy in self.layer_name_strategy.items():
            if strategy.lower() == 'resource' and self.model_strategy.lower() == 'latency':
                print('WARNING: Strategy for layer {} set to "Resource", while model strategy set to "Latency".'.format(layer_name))
                use_resource = True

        for layer_type, compression in self.layer_type_compression.items():
            if compression and self.model_strategy.lower() == 'latency':
                print('WARNING: Compression enabled for layer type {}, while model strategy set to "Latency".'.format(layer_type))
                use_resource = True

        for layer_name, compression in self.layer_name_compression.items():
            if compression and self.model_strategy.lower() == 'latency':
                print('WARNING: Compression enabled for layer {}, while model strategy set to "Latency".'.format(layer_name))
                use_resource = True

        if use_resource:
            print('WARNING: Changing model strategy to "Resource"')
            self.model_strategy = 'Resource'

class HLSModel(object):
    def __init__(self, config, data_reader, layer_list, inputs=None, outputs=None):
        self.config = HLSConfig(config)
        self.reader = data_reader

        # If not provided, assumes layer_list[0] is input, and layer_list[-1] is output
        self.inputs = inputs if inputs is not None else [layer_list[0]['name']]
        self.outputs = outputs if outputs is not None else [layer_list[-1]['name']]
        self.brams   = []

        self.index = 0
        self.graph = OrderedDict()
        self.output_vars = {}
        self.bram_vars = {}
        self._make_graph(layer_list)

    def _make_graph(self, layer_list):
        for layer in layer_list:
            kind = layer['class_name']
            name = layer['name']
            inputs = layer.get('inputs', [])
            outputs = layer.get('outputs', [])
            if len(inputs) == 0:
                inputs = [next(reversed(self.graph), 'input')]
            if len(outputs) == 0:
                outputs = [name]

            self.graph[name] = self.make_node(kind, name, layer, inputs, outputs)

    def make_node(self, kind, name, attributes, inputs, outputs=None):
        node = layer_map[kind](self, name, attributes, inputs, outputs)
        for o in node.outputs:
            out_var = node.get_output_variable(output_name=o)
            if o in self.outputs:
                out_var.type.name = 'result_t'
            self.output_vars[o] = out_var

        return node

    def insert_node(self, node):
        if len(node.inputs) > 1:
            raise Exception('Cannot insert a node with more than one input (for now).')

        prev_node = next((x for x in self.graph.values() if x.outputs[0] == node.inputs[0]),None)
        next_node = next((x for x in self.graph.values() if x.inputs[0] == prev_node.outputs[0]), None)
        if next_node is not None:
            next_node.inputs[0] = node.outputs[0]

        new_graph = OrderedDict()
        for k, v in self.graph.items():
            new_graph[k] = v
            if k == prev_node.name:
                new_graph[node.name] = node

        self.graph = new_graph

    def remove_node(self, node, rewire=True):
        if rewire:
            if len(node.inputs) > 1 or len(node.outputs) > 1:
                raise Exception('Cannot rewire a node with multiple inputs/outputs')
            #print("Check outputs",node.outputs,"!!!!",self.graph.values())
            #prev_node = (x for x in self.graph.values() if x == node.inputs[0]) #self.graph.get(node.inputs[0])
            #next_node = next((x for x in self.graph.values() if x == node),None)
            prev_node = self.graph.get(node.inputs[0])
            next_node = next((x for x in self.graph.values() if x.inputs[0] == node.outputs[0]), None)
            if prev_node is not None:
                if next_node is not None:
                    #next_node.inputs[0] = prev_node
                    next_node.inputs[0] = prev_node.outputs[0]
                else:
                    if node.outputs[0] in self.outputs:
                        self.outputs = [prev_node.outputs[0] if x == node.outputs[0] else x for x in self.outputs]
                    else:
                        raise Exception('Cannot rewire a node without child')
            else:
                raise Exception('Cannot rewire a node without a parent')

        del self.output_vars[node.outputs[0]]
        del self.graph[node.name]

    def replace_node(self, old_node, new_node):
        prev_node = self.graph.get(old_node.inputs[0])
        next_node = next((x for x in self.graph.values() if x.inputs[0] == old_node.outputs[0]), None)
        if next_node is not None:
            next_node.inputs[0] = new_node.outputs[0]
        if prev_node is not None:
            if new_node.inputs is None or len(new_node.inputs) == 0: # Check if already rewired
                new_node.inputs = [prev_node.outputs[0]]

        self.graph = OrderedDict((new_node.name, new_node) if k == old_node.name else (k, v) for k, v in self.graph.items())

    def get_weights_data(self, layer_name, var_name):
        return self.reader.get_weights_data(layer_name, var_name)

    def quantize_data(self, data, quantize):
        zeros = np.zeros_like(data)
        ones = np.ones_like(data)
        quant_data = data
        if quantize == 1:
            quant_data = np.where(data > 0, ones, zeros).astype('int')
        if quantize == 2:
            quant_data = np.where(data > 0, ones, -ones)
        elif quantize == 3:
            quant_data = np.where(data > 0.5, ones, np.where(data <= -0.5, -ones, zeros))
        return quant_data

    def  merge_weights(self, data):
        quant_data = data.astype(np.int8)
        quant_data = np.ones(data.shape)
        quant_data = np.moveaxis(quant_data,len(quant_data.shape)-1,0)
        #print(data.shape,quant_data[0])
        shape=list(quant_data.shape)
        shape[0]=shape[0]/2
        data_out = np.zeros((shape),dtype=int)
        #print(data_out.shape)
        for i0 in range(quant_data.shape[0]/2):
            data_out[i0] = quant_data[2*i0] + quant_data[2*i0+1]*264
        data_out = np.moveaxis(data_out,0,len(data_out.shape)-1)
        return data_out

    def next_layer(self):
        self.index += 1
        return self.index

    def get_layers(self):
        return self.graph.values()

    def get_input_variables(self):
        variables = []
        for inp in self.inputs:
            variables.append(self.graph[inp].get_output_variable())
        return variables

    def register_output_variable(self, out_name, variable):
        if out_name in self.outputs:
            variable.type.name = 'result_t'
        self.output_vars[out_name] = variable

    def get_output_variables(self):
        variables = []
        for out in self.outputs:
            variables.append(self.output_vars[out])
        return variables

    def register_bram_variable(self, out_name, variable):
        self.brams.append(out_name)
        self.bram_vars[out_name] = variable

    def get_bram_variables(self):
        variables = []
        for bram in self.brams:
            variables.append(self.bram_vars[bram])
        return variables

    def get_layer_output_variable(self, output_name):
        return self.output_vars[output_name]

class HLSType(object):
    def __init__(self, name, precision, **kwargs):
        self.name = name.format(**kwargs)
        self.precision = precision

    def definition_cpp(self):
        return 'typedef {precision} {name};\n'.format(name=self.name, precision=self.precision)

class CompressedType(HLSType):
    def __init__(self, name, precision, index_precision, **kwargs):
        super(CompressedType, self).__init__('compressed_type{index}', precision, **kwargs)
        self.index_precision = index_precision

    def definition_cpp(self):
        cpp_fmt = ('typedef struct {name} {{ '
               '{index} row_index; '
               '{index} col_index; '
               '{precision} weight; }} {name};\n')
        return cpp_fmt.format(name=self.name, index=self.index_precision, precision=self.precision)

class Variable(object):
    def __init__(self, var_name, type_name, precision, **kwargs):
        self.name = var_name.format(**kwargs)
        self.type = HLSType(type_name, precision, **kwargs)
        self.cppname = re.sub(r'\W|^(?=\d)','_', self.name)

class ArrayVariable(Variable):
    def __init__(self, shape, dim_names, var_name='layer{index}', type_name='layer{index}_t', precision=None, pragma='partition',depth=1,cl=False, **kwargs):
        super(ArrayVariable, self).__init__(var_name, type_name, precision, **kwargs)
        self.shape = shape
        self.dim_names = dim_names
        self.streamcnn = False
        self.depth     = depth
        self.cl        = cl
        if pragma == 'partition':
            self.partition()
        elif pragma == 'reshape':
            self.reshape()
        elif pragma == 'stream':
            self.stream(depth=depth)
            self.streamcnn = True
        else:
            self.pragma = None

    def partition(self, type='complete', factor=None, dim=0):
        if factor:
            pragma = '#pragma HLS ARRAY_PARTITION variable={name} {type} factor={factor} dim={dim}'
        else:
            pragma = '#pragma HLS ARRAY_PARTITION variable={name} {type} dim={dim}'

        self.pragma = pragma.format(name=self.name, type=type, factor=factor, dim=dim)

    def reshape(self, type='complete', factor=None, dim=0):
        if factor:
            pragma = '#pragma HLS ARRAY_RESHAPE variable={name} {type} factor={factor} dim={dim}'
        else:
            pragma = '#pragma HLS ARRAY_RESHAPE variable={name} {type} dim={dim}'

        self.pragma = pragma.format(name=self.name, type=type, factor=factor, dim=dim)

    def stream(self, depth=1, dim=1):
        pragma = '#pragma HLS STREAM variable={name} depth={depth} dim={dim}'
        self.pragma = pragma.format(name=self.name, depth=self.depth, dim=dim)

    def get_shape(self):
        return zip(self.dim_names, self.shape)

    def definition_cpp(self):
        if self.streamcnn:
            array_shape = self.size_cpp_cnn()
            return 'static hls::stream<{type}> {name}[{shape}]'.format(type=self.type.name, name=self.cppname, shape=array_shape)
        else:
            array_shape = self.size_cpp()
            return '{type} {name}[{shape}]'.format(type=self.type.name, name=self.cppname, shape=array_shape)

    def size(self):
        nelem = 1
        for dim in self.shape:
            nelem *= dim
        return nelem
    
    def size_cnn(self):
        nelem = 1
        nelem = self.shape[0]
        return nelem

    def size_cpp(self,isSerial=False):
        if isSerial:
            tmp_dim_names = copy.copy(self.dim_names)
            for i0 in range(len(tmp_dim_names)):
                if 'FILT' in tmp_dim_names[i0]:
                    tmp_dim_names[i0] = '('+tmp_dim_names[i0]+'-1)'
            return '*'.join([str(k) for k in tmp_dim_names])
        else:
            return '*'.join([str(k) for k in self.dim_names])

    def size_cpp_cnn(self, cl=False):
        if len(self.dim_names) > 1 and self.cl:
            return  self.dim_names[2]
        if len(self.dim_names) > 1 and not self.cl:
            if 'FILT' in self.dim_names[0]:
                return  self.dim_names[0]
            else:
                return  self.dim_names[2]
        return  self.dim_names[0]

class InplaceVariable():
    def __init__(self, shape, dim_names, proxy, **kwargs):
        self.shape = shape
        self.dim_names = dim_names
        self.type = proxy.type
        self.name = proxy.name
        self.size = proxy.size
    
    def get_shape(self):
        return zip(self.dim_names, self.shape)

    def definition_cpp(self):
        return None

    def size_cpp(self):
        return '*'.join([str(k) for k in self.dim_names])

class WeightVariable(Variable):
    def __init__(self, var_name, type_name, precision, data, **kwargs):
        super(WeightVariable, self).__init__(var_name, type_name, precision, **kwargs)
        self.data = data
        self.nzeros = -1
        self.shape = list(self.data.shape)
        self.data_length = np.prod(self.data.shape)
        self.nonzeros = np.count_nonzero(self.data)
        self.nzeros = self.data_length - self.nonzeros
        self.min = np.min(self.data)
        self.max = np.max(self.data)
        self._iterator = None
        self.update_precision(precision)

    def __iter__(self):
        self._iterator = np.nditer(self.data, order='C')
        return self

    def __next__(self):
        if not self._iterator.finished:
            value = self._iterator[0]
            self._iterator.iternext()
            return self.precision_fmt % value
        else:
            raise StopIteration

    next = __next__

    def update_precision(self, new_precision):
        self.type.precision = new_precision
        if 'int' in self.type.precision:
            self.precision_fmt = '%d'
        else:
            match = re.search('.+<(.+?)>', self.type.precision)
            if match is not None:
                precision_bits = match.group(1).split(',')
                decimal_bits = int(precision_bits[0]) - int(precision_bits[1])
                decimal_spaces = int(np.floor(np.log10(2 ** decimal_bits - 1))) + 1
                self.precision_fmt = '%.{}f'.format(decimal_spaces)
            else:
                self.precision_fmt = '%f'

    def definition_cpp(self):
        return '{type} {name}[{size}]'.format(type=self.type.name, name=self.cppname, size=self.data_length)

class CompressedWeightVariable(WeightVariable):
    def __init__(self, var_name, type_name, precision, data, reuse_factor, bramport_size, **kwargs):
        super(CompressedWeightVariable, self).__init__(var_name, type_name, precision, data, **kwargs)
        self.extra_zeros = 0
        self.data_length = np.prod(data.shape) - self.nzeros
        while self.data_length % reuse_factor != 0:
            self.extra_zeros += 1
            self.data_length += 1
        self.nonzeros = np.prod(data.shape) - self.nzeros + self.extra_zeros

        # Compress the array
        weights = []
        extra_nzero_cnt = self.extra_zeros
        it = np.nditer(data, order='C', flags=['multi_index'])
        max_idx = 0
        while not it.finished:
            val = it[0]
            if not (val == 0 and extra_nzero_cnt < 1):
                if val == 0:
                    extra_nzero_cnt -= 1
                if it.multi_index[0] > max_idx:
                    max_idx = it.multi_index[0]
                if it.multi_index[1] > max_idx:
                    max_idx = it.multi_index[1]
                weights.append([it.multi_index[1], it.multi_index[0], val])
            it.iternext()
        weights.sort()

        index_precision = 32
        if max_idx > 0:
            index_precision = int(np.log2(max_idx) + 1)
        self.type = CompressedType(type_name, precision, 'ap_uint<{}>'.format(index_precision), **kwargs)
        self.data = weights

    def __iter__(self):
        self._iterator = iter(self.data)
        return self

    def __next__(self):
        value = next(self._iterator)
        value_fmt = self.precision_fmt % value[2]
        return '{ %u, %u, %s }' % (value[1], value[0], value_fmt)

    next = __next__

class Layer(object):
    def __init__(self, model, name, attributes, inputs, outputs=None):
        self.model = model
        self.name = name
        self.index = model.next_layer()
        self.inputs = inputs
        self.outputs = outputs
        if self.outputs is None:
            self.outputs = [self.name]

        self.attributes = attributes

        self._function_template = self.model.config.backend.get_function_template(self.__class__.__name__)
        self._config_template = self.model.config.backend.get_config_template(self.__class__.__name__)
        self._tcl_template = self.model.config.backend.get_tcl_template(self.__class__.__name__)
        self.weights = OrderedDict()
        self.variables = OrderedDict()
        self.precision = OrderedDict()
        accum_t = HLSType(*reversed(self.model.config.get_precision(self, 'accum')))
        self.precision[accum_t.name] = accum_t
        self.set_attr('accum_t', accum_t.precision)

        self.initialize()

    def initialize(self):
        raise NotImplementedError

    def set_attr(self, key, value):
        self.attributes[key] = value

    def get_attr(self, key, default=None):
        return self.attributes.get(key, default)

    def get_input_node(self, input_name=None):
        if input_name is not None:
            return self.model.graph.get(input_name)
        else:
            return self.model.graph.get(self.inputs[0])

    def get_input_variable(self, input_name=None):
        if input_name is not None:
            return self.model.get_layer_output_variable(input_name)
        else:
            return self.model.get_layer_output_variable(self.inputs[0])

    def get_output_nodes(self, output_name=None):
        if output_name is None:
            output_name = self.outputs[0]
        return [node for node in self.model.graph.values() if node.inputs[0] == output_name]

    def get_output_variable(self, output_name=None):
        if output_name is not None:
            return self.variables[output_name]
        else:
            return next(iter(self.variables.values()))

    def get_weights(self, var_name=None):
        if var_name:
            return self.weights[var_name]

        return self.weights.values()

    def get_variables(self):
        return self.variables.values()

    def add_output_variable(self, shape, dim_names, out_name=None, var_name='layer{index}_out', type_name='layer{index}_t', precision=None, pragma='auto', depth=1, cl=False):
        if out_name is None:
            out_name = self.outputs[0]

        if precision is None:
            precision, _ = self.model.config.get_precision(self, var='result')

        if pragma == 'auto':
            if self.model.config.get_config_value('IOType') == 'io_serial':
                pragma = 'stream'
                type_name=type_name
                #type_name='hls::stream<'+type_name+'>'
            else:
                if self.name in self.model.inputs:
                    pragma = 'reshape'
                else:
                    pragma = 'partition'

        out = ArrayVariable(shape, dim_names, var_name=var_name, type_name=type_name, precision=precision, pragma=pragma, index=self.index, depth=depth, cl=cl)
        self.variables[out_name] = out
        self.model.register_output_variable(out_name, out)

        self.precision[out.type.name] = out.type


    def add_internal_variable(self, shape, dim_names, out_name=None, var_name='layer{index}_out', type_name='layer{index}_t', precision=None, pragma='auto'):
        if precision is None:
            precision, _ = self.model.config.get_precision(self, var='result')

        if pragma == 'auto':
            if self.model.config.get_config_value('IOType') == 'io_serial':
                pragma = 'stream'
                type_name='hls::stream<'+type_name+'>'
            else:
                if self.name in self.model.inputs:
                    pragma = 'reshape'
                else:
                    pragma = 'partition'

        out = ArrayVariable(shape, dim_names, var_name=var_name, type_name=type_name, precision=precision, pragma=pragma, index=self.index)
        self.variables[out_name] = out
        self.model.register_output_variable(out_name, out)
        self.precision[out.type.name] = out.type

    def add_weights(self, quantize=0, compression=False):
        data = self.model.get_weights_data(self.name, 'kernel')
        self.add_weights_variable(name='weight', var_name='w{index}', data=data, quantize=quantize, compression=compression)

    def add_bias(self, quantize=0):
        data = self.model.get_weights_data(self.name, 'bias')
        precision = None
        type_name = None
        if data is None:
            data = np.zeros(self.get_output_variable().shape[0])
            precision = 'ap_uint<1>'
            type_name = 'bias{index}_t'
            quantize = 0 # Don't quantize non-existant bias

        self.add_weights_variable(name='bias', var_name='b{index}', type_name=type_name, precision=precision, data=data, quantize=quantize)

    def add_weights_variable(self, name, var_name=None, type_name=None, precision=None, data=None, quantize=0, compression=False):
        if var_name is None:
            var_name = name + '{index}'

        if precision is None:
            precision, _ = self.model.config.get_precision(self, var=name)

        if type_name is None:
            _, type_name = self.model.config.get_precision(self, var=name)

        if data is None:
            data = self.model.get_weights_data(self.name, name)
        elif isinstance(data, six.string_types):
            data = self.model.get_weights_data(self.name, data)

        if quantize > 0 and quantize < 4:
            data = self.model.quantize_data(data, quantize)
            if quantize == 1:
                precision = 'ap_uint<1>'
                type_name = name + '{index}_t'
            elif quantize == 2 or quantize == 3:
                precision = 'ap_int<2>'
                type_name = name + '{index}_t'
        merge_factor = self.model.config.get_merge_factor(self) # merge weights
        if merge_factor == 2: 
            if not ('bias' in name and 'mm' not in self.name): # and 'Conv' in self.name): #only weights
                var = WeightVariable(var_name, type_name=type_name, precision=precision, data=data, index=self.index)
                #quick hack to fuse batch norm
                if 'mm' not in self.name:
                    self.weights[name+'_unmerged']=var
                data = self.model.merge_weights(data)
                precision='ap_uint<16>' # hardcoded for now
        
        type_name='model_weightdefault_t'
        if 'bias' in name:
            type_name='model_default_t'
                #if type_name == 'model_default_t':
                #     precision='ap_uint<16>'

        bramport_size = self.model.config.get_bram_size(self) # merge weights
        if compression:
            rf = self.model.config.get_reuse_factor(self)
            var = CompressedWeightVariable(var_name, type_name=type_name, precision=precision, data=data, reuse_factor=rf, index=self.index)
        else:
            var = WeightVariable(var_name, type_name=type_name, precision=precision, data=data, index=self.index)

        self.weights[name] = var
        self.precision[var.type.name] = var.type
        if(np.prod(data.shape) > bramport_size):
            var_out = var_name.replace("{index}",str(self.index))
            self.model.register_bram_variable(var_out,var)

    def _default_function_params(self):
        params = {}
        params['config'] = 'config{}'.format(self.index)
        params['input_t'] = self.get_input_variable().type.name
        params['output_t'] = self.get_output_variable().type.name
        params['input'] = self.get_input_variable().name
        params['output'] = self.get_output_variable().name

        return params

    def _default_config_params(self):
        params = {}
        params.update(self.attributes)
        params['index'] = self.index
        params['iotype'] = self.model.config.get_config_value('IOType')
        params['reuse'] = self.model.config.get_reuse_factor(self)

        # data types
        for weight_name, variable in self.weights.items():
            params[weight_name + '_t'] = variable.type.name
            mf = self.model.config.get_merge_factor(self)
            if mf > 1:
                params['big'+weight_name + '_t'] = 'model_bigdefault_t'
            else:
                params['big'+weight_name + '_t'] = 'model_default_t'

        return params

    def _default_tcl_params(self):
        params = {}
        params['config'] = 'config{}'.format(self.index)
        params['input_t'] = self.get_input_variable().type.name
        params['output_t'] = self.get_output_variable().type.name
        params['input'] = self.get_input_variable().name
        params['output'] = self.get_output_variable().name
        params['weights'] = None
        params['biases'] = None
        weights = self.get_weights()
        if len(weights) > 1:
            try:
                name_weights =  self.get_weights('weight').name
                name_bias    =  self.get_weights('bias').name
            except:
                try:
                    name_weights =  self.get_weights('scale').name
                    name_bias    =  self.get_weights('bias').name
                except:
                    name_weights =  weights[0].name
                    name_bias    =  weights[1].name
            params['weights']=name_weights
            params['biases']=name_bias
        params['data_format'] = 'cl'
        if self.get_attr('data_format') == 'channels_first':
            params['data_format'] = 'cf'
        params.update(self.attributes)
        #print("tcl template",self._tcl_template)
        return params

    def get_layer_precision(self):
        return self.precision

    # myproject.cpp/h
    def function_cpp(self,iFirst=False):
        raise NotImplementedError

    # parameters.h
    def config_cpp(self):
        raise NotImplementedError
        
    def print_tcl(self):
        raise NotImplementedError 
        
    def get_numbers_cpp(self):
        numbers = ''
        for k, v in self.get_output_variable().get_shape():
            if self.model.config.get_config_value('IOType') == 'io_serial':
                if 'FILT' in k:
                    numbers += '#define {} {}\n'.format(k,v+1)
                elif 'INPUT_3_1' in k and self.get_attr('data_format') == 'channels_last':
                    numbers += '#define {} {}\n'.format(k,v)
                elif 'INPUT_1_1' in k and not self.get_attr('data_format') == 'channels_last':
                    numbers += '#define {} {}\n'.format(k,v+1)
                else:
                    numbers += '#define {} {}\n'.format(k,v)
            else:
                numbers += '#define {} {}\n'.format(k,v)
        return numbers

    def precision_cpp(self):
        return 'typedef {precision} layer{index}_t;'.format(precision=self.get_output_variable().precision, index=self.index)

class Input(Layer):
    def initialize(self):
        shape = self.attributes['input_shape']
        if shape[0] is None:
            shape = shape[1:]
        dims = ['N_INPUT_{}_{}'.format(i, self.index) for i in range(1, len(shape) + 1)]
        cl=True if self.get_attr('data_format') == 'channels_last' else False 
        self.add_output_variable(shape, dims, var_name=self.name, type_name='input_t',cl=cl)

    def function_cpp(self,iFirst=False):
        return None

    def config_cpp(self):
        return None

class Reshape(Layer):
    def initialize(self):
        shape = self.attributes['target_shape']
        if shape[0] is None:
            shape = shape[1:]
        dims = ['N_SIZE_{}_{}'.format(i, self.index) for i in range(1, len(shape) + 1)]

        out_name = self.outputs[0]
        proxy = self.get_input_variable()
        out = InplaceVariable(shape, dims, proxy, index=self.get_input_node().index)

        self.variables[out_name] = out
        self.model.register_output_variable(out_name, out)

    def function_cpp(self,iFirst=False):
        return None

    def config_cpp(self):
        return None

class Dense(Layer):
    def initialize(self):
        shape = [self.attributes['n_out']]
        dims = ['N_LAYER_{}'.format(self.index)]
        quantize = self.get_attr('quantize', default=0)
        compression = self.model.config.get_compression(self)
        self.set_attr('n_in',self.get_input_variable().size())
        #self.set_attr('n_out') = self.get_output_variable()
        if self.model.config.is_resource_strategy(self):
            if self.model.config.backend.name == 'Vivado':
                valid_rf = self.model.config.backend.get_valid_reuse_factors(self)
                chosen_rf = self.model.config.get_reuse_factor(self)
                if chosen_rf not in valid_rf:
                    print('WARNING: Using invalid ReuseFactor={} with "Resource" strategy in layer "{}". Valid ReuseFactor(s): {}'
                        .format(chosen_rf, self.name, ','.join(map(str, valid_rf))))
            if compression:
                self.set_attr('strategy', 'compressed')
            else:
                self.set_attr('strategy', 'large')
        else:
            self.set_attr('strategy', 'latency')
        
        if self.model.config.get_config_value('IOType') == 'io_serial':
            shape[0] += 1
        self.add_output_variable(shape, dims)
        self.add_weights(quantize=quantize, compression=compression)
        index_t = 'ap_uint<1>'
        if self.model.config.is_resource_strategy(self):
            if self.model.config.get_compression(self):
                index_t = self.get_weights('weight').type.index_precision
            else:
                if self.model.config.backend.name == 'Vivado':
                    self.weights['weight'].data = np.transpose(self.weights['weight'].data)
        self.set_attr('index_t', index_t)
        self.add_bias(quantize=quantize)

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['strategy'] = self.get_attr('strategy')
        params['w'] = self.get_weights('weight').name
        params['b'] = self.get_weights('bias').name
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            params['strategy'] += '_stream'
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['n_input'] = self.get_input_variable().size_cpp_cnn()
            params['n_output'] = self.get_output_variable().size_cpp(isSerial=True)
            params['n_in'] = self.get_input_variable().size_cpp(isSerial=True)+'-1'
            params['n_out'] = self.get_output_variable().size_cpp(isSerial=True)+'-1'
            if len(self.get_input_variable().shape) > 1:
                params['n_in'] = self.get_input_variable().size_cpp(isSerial=True)
                params['block_factor'] =  (self.get_input_variable().size()/self.get_input_variable().shape[2])
            #elif len(self.get_input_variable().shape) > 1:
            #    print('input2',self.get_input_variable(),',',self.get_input_variable().shape,',',self.get_input_variable().size())
            #    params['block_factor'] =  (self.get_input_variable().size()/self.get_input_variable().shape[1])
            else:
                params['block_factor'] = 1
        else:
            params['n_input'] = self.get_input_variable().size_cpp(isSerial=False)
            params['n_output'] = self.get_output_variable().size_cpp(isSerial=False)
            params['n_in'] = self.get_input_variable().size_cpp(isSerial=False)
            params['n_out'] = self.get_output_variable().size_cpp(isSerial=False)
            params['block_factor'] = 1
        
        params['merge_factor'] = self.model.config.get_merge_factor(self)
        params['nzeros'] = self.get_weights('weight').nzeros
        params['nonzeros'] = self.get_weights('weight').nonzeros

        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        print(params)
        params['n_weights']=self.get_weights('weight').data_length
        params['weights']=self.get_weights('weight').name
        #params['strategy'] += '_stream'
        return self._tcl_template.format(**params)

class Conv1D(Layer):
    def initialize(self):
        cl=False
        if self.get_attr('data_format') == 'channels_last':
            shape = [self.attributes['n_out'], self.attributes['n_filt']]
            dims = ['N_OUTPUTS_{}'.format(self.index), 'N_FILT_{}'.format(self.index)]
            cl=True
        else:
            shape = [self.attributes['n_filt'], self.attributes['n_out']]
            dims = ['N_FILT_{}'.format(self.index), 'N_OUTPUTS_{}'.format(self.index)]
        depth=1
        self.add_output_variable(shape, dims, depth=depth,cl=cl)
        self.add_weights()
        self.add_bias()
        if self.model.config.is_resource_strategy(self):
            self.set_attr('strategy', 'large')
            if self.model.config.backend.name == 'Vivado':
                valid_rf = self.model.config.backend.get_valid_reuse_factors(self)
                chosen_rf = self.model.config.get_reuse_factor(self)
                if chosen_rf not in valid_rf:
                    print('WARNING: Using invalid ReuseFactor={} with "Resource" strategy in layer "{}". Valid ReuseFactor(s): {}'
                        .format(chosen_rf, self.name, ','.join(map(str, valid_rf))))
                
                self.weights['weight'].data = np.transpose(self.weights['weight'].data, axes=[2, 1, 0]) #(W,C,F) => (F,C,W)
        else:
            self.set_attr('strategy', 'latency')

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['strategy'] = self.get_attr('strategy')
        params['data_format'] = 'cf' if self.get_attr('data_format') == 'channels_first' else 'cl'
        params['w'] = self.get_weights('weight').name
        params['b'] = self.get_weights('bias').name
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        input_dims = self.get_input_variable().dim_names
        if self.get_attr('data_format') == 'channels_last':
            params['n_in'] = '*'.join([str(k) for k in input_dims[:-1]])
            params['n_chan_in'] = input_dims[-1]
            params['n_chan'] = input_dims[-1]-1
        else:
            params['n_in'] = '*'.join([str(k) for k in input_dims[1:]])
            params['n_chan'] = input_dims[0]
            params['n_chan_in'] = input_dims[-1]-1
        params['dilation'] = self.get_attr('dilation', 1)
        params['n_filt_in'] = 'N_FILT_{}'.format(self.index)
        params['n_filt'] = 'N_FILT_{}-'.format(self.index)
        params['n_out'] = 'N_OUTPUTS_{}'.format(self.index)
        params['nzeros'] = self.get_weights('weight').nzeros
        params['config_t'] = 'std::nullptr_t'

        if self.model.config.is_resource_strategy(self):
            params['config_t'] = 'config{}_mult'.format(self.index)
            conv_config = self._config_template[0].format(**params)

            mult_params = self._default_config_params()
            mult_params['n_in'] = self.get_attr('n_chan') * self.get_attr('filt_width')
            mult_params['n_out'] = self.get_attr('n_filt')
            mult_config = self._config_template[1].format(**mult_params)

            return mult_config + '\n' + conv_config
        else:
            return self._config_template[0].format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['n_filt_in'] = 'N_FILT_{}'.format(self.index)
        params['n_chan_in'] = input_dims[-1]
        return self._tcl_template.format(**params)

class Conv2D(Layer):
    def initialize(self):
        cl=False
        if self.get_attr('data_format') == 'channels_last':
            shape = [self.attributes['out_height'], self.attributes['out_width'], self.attributes['n_filt']]
            dims = ['OUT_HEIGHT_{}'.format(self.index), 'OUT_WIDTH_{}'.format(self.index), 'N_FILT_{}'.format(self.index)]
            cl=True
        else:
            shape = [self.attributes['n_filt'], self.attributes['out_height'], self.attributes['out_width']]
            dims = ['N_FILT_{}'.format(self.index), 'OUT_HEIGHT_{}'.format(self.index), 'OUT_WIDTH_{}'.format(self.index)]
        self.is1x1 = False
        #self.get_attr('filt_height') * self.get_attr('filt_width')
        if(self.attributes['filt_height'] == 1 and self.attributes['filt_width'] == 1) : 
            self.is1x1 = True
        depth=(self.attributes['pad_right']+2+self.attributes['pad_bottom']*(self.attributes['out_width']+self.attributes['pad_right']))
        self.add_output_variable(shape, dims,depth=depth,cl=cl)
        #self.add_internal_variable(shapeinternal,diminternal,'dummy','dummy{index}_out',type_name='model_bigdefault_t',precision='ap_uint<27>')
        self.add_weights()
        self.add_bias()
        if self.model.config.is_resource_strategy(self):
            self.set_attr('strategy', 'large')
        else:
            self.set_attr('strategy', 'latency')
        params = self._default_function_params()
        params['reuse'] = self.reuse_factor()
        self.weights['weight'].data = np.transpose(self.weights['weight'].data, axes=[3, 0, 1, 2]) #(H,W,C,F) => (F,C,H,W)

    def reuse_factor(self):
        if self.get_attr('strategy') == 'latency':
            return self.model.config.get_reuse_factor(self)
        if self.model.config.backend.name == 'Vivado':
            valid_rf = self.model.config.backend.get_valid_reuse_factors(self)
            chosen_rf = self.model.config.get_reuse_factor(self)
            #use chosen to balance the throughput in clocks
            shape = self.get_output_variable().shape
            if chosen_rf < 6*shape[1]*shape[2]: #6 clock min
                print("Chosen latency cannot be achieved with a signle stream!!!!!! Please consider custom stream in ",self.index,shape[1],shape[2])
            else: 
                chosen_rf = chosen_rf-6*shape[1]*shape[2]
            approxrf=float(chosen_rf)/shape[1]/shape[2]
            if self.get_attr('data_format') == 'channels_last':
                approxrf=float(chosen_rf)/shape[0]/shape[1]
            print("Approx RF2",shape[0],shape[1],shape[2],approxrf,self.get_attr('data_format'),self.name)
            chosen_rf = valid_rf[0]
            for rf in valid_rf:
                if approxrf < rf:
                    break
                chosen_rf = rf
            print("Choosing RF",chosen_rf,self.name)
            params = self._default_function_params()
            if chosen_rf not in valid_rf:
                print('WARNING: Using invalid ReuseFactor={} with "Resource" strategy in layer "{}". Valid ReuseFactor(s): {}'
                      .format(chosen_rf, self.name, ','.join(map(str, valid_rf))))
            return chosen_rf
        else:
            return self.model.config.get_reuse_factor(self)

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['strategy'] = self.get_attr('strategy')
        params['data_format'] = 'cf' if self.get_attr('data_format') == 'channels_first' else 'cl'
        params['w'] = self.get_weights('weight').name
        params['b'] = self.get_weights('bias').name
        params['1x1'] = ''
        if self.is1x1:
            params['1x1'] = '_1x1'
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            self.get_input_variable(self.inputs[0]).name = self.get_input_variable(self.inputs[0]).name.replace("/","_")
            params['input']=params['input'].replace("/","_")
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        valid_rf = self.model.config.backend.get_valid_reuse_factors(self)
        chosen_rf = self.model.config.get_reuse_factor(self)
        shape=[1,1]
        if self.get_attr('data_format') == 'channels_last':
            shape[0] = self.get_input_variable().shape[0]
            shape[1] = self.get_input_variable().shape[1]
        else:
            shape[0] = self.get_input_variable().shape[1]
            shape[1] = self.get_input_variable().shape[2]

        params['reuse'] = self.reuse_factor()

        if self.get_attr('data_format') == 'channels_last':
            params['in_height'] = self.get_input_variable().dim_names[0]
            params['in_width'] = self.get_input_variable().dim_names[1]
            params['n_chan'] = self.get_input_variable().dim_names[2]+'-1'
            params['n_chan_in'] = self.get_input_variable().dim_names[2]
            params['out_height'] = self.get_output_variable().dim_names[0]
            params['out_width'] = self.get_output_variable().dim_names[1]
            params['n_filt'] = self.get_output_variable().dim_names[2]+'-1'
            params['n_filt_in'] = self.get_output_variable().dim_names[2]
        else:
            params['n_chan'] = self.get_input_variable().dim_names[0]+'-1'
            params['n_chan_in'] = self.get_input_variable().dim_names[0]
            params['in_height'] = self.get_input_variable().dim_names[1]
            params['in_width'] = self.get_input_variable().dim_names[2]
            params['n_filt'] = self.get_output_variable().dim_names[0]+'-1'
            params['n_filt_in'] = self.get_output_variable().dim_names[0]
            params['out_height'] = self.get_output_variable().dim_names[1]
            params['out_width'] = self.get_output_variable().dim_names[2]
        params['dilation'] = self.get_attr('dilation', 1)
        params['nzeros'] = self.get_weights('weight').nzeros
        params['config_t'] = 'std::nullptr_t'

        if self.model.config.is_resource_strategy(self):
            params['config_t'] = 'config{}_mult'.format(self.index)
            params['config_t_relu'] = 'config{}_relu'.format(self.index)
            conv_config = self._config_template[0].format(**params)
            
            mult_params = self._default_config_params()
            mult_params['reuse'] = params['reuse']
            mult_params['merge_factor'] = self.model.config.get_merge_factor(self)
            if self.get_attr('data_format') == 'channels_last':
                mult_params['n_in'] = self.get_input_variable().shape[2] * self.get_attr('filt_height') * self.get_attr('filt_width')
            else:
                mult_params['n_in'] = self.get_input_variable().shape[0] * self.get_attr('filt_height') * self.get_attr('filt_width')
            mult_params['n_out'] = self.get_attr('n_filt')
            mult_config = self._config_template[1].format(**mult_params)

            relu_params = self._default_config_params()
            relu_params['n_in'] = self.get_attr('n_filt') 
            relu_params['n_out'] = self.get_attr('n_filt') 
            relu_config = self._config_template[2].format(**relu_params)

            return relu_config + '\n' + mult_config + '\n' + conv_config
        else:
            return self._config_template[0].format(**params)
    

    def print_tcl(self):
        params = self._default_tcl_params()
        if self.get_attr('data_format') == 'channels_last':
            params['n_chan_in'] =  self.get_input_variable().dim_names[2]
            params['n_filt_in'] = self.get_output_variable().dim_names[2]
        else:
            params['n_chan_in'] =  self.get_input_variable().dim_names[0]
            params['n_filt_in'] = self.get_output_variable().dim_names[0]
        params['n_weights']=self.get_weights('weight').data_length
        params['weights']=self.get_weights('weight').name
        params['1x1'] = ''
        if self.is1x1:
            params['1x1'] = '_1x1'
        return self._tcl_template.format(**params)

class Conv2DMerge(Layer):
    def initialize(self):
        print("!!!!!!!!!!!!! the merge")
        cl=False
        if self.get_attr('data_format') == 'channels_last':
            shape = [self.attributes['n_filt']]
            dims = ['N_FILT_{}'.format(self.index)]
            cl=True
        else:
            shape = [self.attributes['n_filt']]
            dims = ['N_FILT_{}'.format(self.index)]
        self.add_output_variable(shape, dims,cl=cl)

        self.add_weights()
        self.add_bias()
        if self.model.config.is_resource_strategy(self):
            self.set_attr('strategy', 'large')
            if self.model.config.backend.name == 'Vivado':
                valid_rf = self.model.config.backend.get_valid_reuse_factors(self)
                chosen_rf = self.model.config.get_reuse_factor(self)
                if chosen_rf not in valid_rf:
                    print('WARNING: Using invalid ReuseFactor={} with "Resource" strategy in layer "{}". Valid ReuseFactor(s): {}'
                        .format(chosen_rf, self.name, ','.join(map(str, valid_rf))))
                self.weights['weight'].data = np.transpose(self.weights['weight'].data, axes=[3, 0, 1, 2]) #(H,W,C,F) => (F,C,H,W)
                #self.weights['weight'].data = np.transpose(self.weights['weight'].data, axes=[1, 3, 2, 0]) #(H,W,C,F) => (F,C,H,W)
        else:
            self.set_attr('strategy', 'latency')

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['strategy'] = self.get_attr('strategy')
        params['data_format'] = 'cf' if self.get_attr('data_format') == 'channels_first' else 'cl'
        params['w'] = self.get_weights('weight').name
        params['b'] = self.get_weights('bias').name
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        if self.get_attr('data_format') == 'channels_last':
            params['in_height'] = self.get_input_variable().dim_names[0]
            params['in_width'] = self.get_input_variable().dim_names[1]
            params['n_chan'] = self.get_input_variable().dim_names[2]+'-1'
            params['n_chan_in'] = self.get_input_variable().dim_names[2]
            params['out_height'] = self.get_output_variable().dim_names[0]
            params['out_width'] = self.get_output_variable().dim_names[1]
            params['n_filt'] = self.get_output_variable().dim_names[2]+'-1'
            params['n_filt_in'] = self.get_output_variable().dim_names[2]
        else:
            params['n_chan'] = self.get_input_variable().dim_names[0]+'-1'
            params['n_chan_in'] = self.get_input_variable().dim_names[0]
            params['in_height'] = self.get_input_variable().dim_names[1]
            params['in_width'] = self.get_input_variable().dim_names[2]
            params['n_filt'] = self.get_output_variable().dim_names[0]+'-1'
            params['n_filt_in'] = self.get_output_variable().dim_names[0]
            params['out_height'] = self.get_output_variable().dim_names[1]
            params['out_width'] = self.get_output_variable().dim_names[2]
        params['dilation'] = self.get_attr('dilation', 1)
        params['nzeros'] = self.get_weights('weight').nzeros
        params['config_t'] = 'std::nullptr_t'

        if self.model.config.is_resource_strategy(self):
            mult_params = self._default_config_params()
            mult_params['reuse'] = params['reuse']
            mult_params['n_in'] = self.get_attr('n_chan') * self.get_attr('filt_height') * self.get_attr('filt_width')
            mult_params['n_out'] = self.get_attr('n_filt')
            mult_config = self._config_template[1].format(**mult_params)

            relu_params = self._default_config_params()
            relu_params['n_in'] = self.get_attr('n_filt') 
            relu_params['n_out'] = self.get_attr('n_filt') 
            relu_config = self._config_template[2].format(**relu_params)

            return relu_config + '\n' + mult_config + '\n' + conv_config
        else:
            return self._config_template[0].format(**params)


        if self.model.config.is_resource_strategy(self):
            params['config_t_relu'] = 'config{}_relu'.format(self.index)
            conv_config = self._config_template[0].format(**params)

            relu_params = self._default_config_params()
            relu_params['n_in'] = self.get_attr('n_filt') 
            relu_config = self._config_template[1].format(**relu_params)

            return relu_config + '\n' + conv_config
        else:
            return self._config_template[0].format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['n_chan_in'] =  self.get_input_variable().dim_names[0]
        params['n_filt_in'] = self.get_output_variable().dim_names[0]
        params['n_weights']=self.get_weights('weight').data_length
        params['weights']=self.get_weights('weight').name
        if self.is1x1:
            params['1x1'] = '_1x1'
        return self._tcl_template.format(**params)

class Pooling1D(Layer):
    def initialize(self):
        shape = [self.attributes['n_out'], self.attributes['n_filt']]
        dims = ['N_OUTPUTS_{}'.format(self.index), 'N_FILT_{}'.format(self.index)]
        self.add_output_variable(shape, dims)
        self.set_attr('pool_op', self.get_attr('class_name').split('Pooling')[0])

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        params['n_in'] = self.get_input_variable().size_cpp()
        params['n_out'] = self.get_output_variable().size_cpp()

        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['n_chan_in'] =  self.get_input_variable().dim_names[0]
        params['n_filt_in'] = self.get_output_variable().dim_names[0]
        return self._tcl_template.format(**params)

class Pooling2D(Layer):
    def initialize(self):
        cl=False
        if self.get_attr('data_format') == 'channels_last':
            shape = [self.attributes['out_height'],self.attributes['out_width'],self.attributes['n_filt']]
            dims = ['OUT_HEIGHT_{}'.format(self.index),'OUT_WIDTH_{}'.format(self.index),'N_FILT_{}'.format(self.index)]
            cl=True
        else:
            shape = [self.attributes['n_filt'], self.attributes['out_height'], self.attributes['out_width']]
            dims = ['N_FILT_{}'.format(self.index), 'OUT_HEIGHT_{}'.format(self.index), 'OUT_WIDTH_{}'.format(self.index)]

        depth=(self.attributes['pad_right']+2+self.attributes['pad_bottom']*(self.attributes['out_width']+self.attributes['pad_right']))
        print("adding :",shape,dims)
        self.add_output_variable(shape, dims,cl=cl,depth=depth)
        self.set_attr('pool_op', self.get_attr('class_name').split('Pooling')[0])
        self.is1x1 = False
        if(self.attributes['out_height'] == 1 and self.attributes['out_width'] == 1) : 
            self.is1x1 = True

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['data_format'] = 'cf' if self.get_attr('data_format') == 'channels_first' else 'cl'
        params['1x1'] = ''
        if self.is1x1:
            params['1x1'] = '_1x1'
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        if self.get_attr('data_format') == 'channels_last':
            params['n_in'] = self.get_input_variable().dim_names[2]
            params['in_height'] = self.get_input_variable().dim_names[0]
            params['in_width'] = self.get_input_variable().dim_names[1]
            params['out_height'] = self.get_output_variable().dim_names[0]
            params['out_width'] = self.get_output_variable().dim_names[1]
            params['n_filt'] = self.get_output_variable().dim_names[2]+'-1'
            params['n_filt_in'] = self.get_output_variable().dim_names[2]
            params['n_chan'] = self.get_input_variable().dim_names[2]+'-1'
            params['n_chan_in'] = self.get_input_variable().dim_names[2]
        else:
            params['n_in'] = self.get_input_variable().dim_names[0]
            params['in_height'] = self.get_input_variable().dim_names[1]
            params['in_width'] = self.get_input_variable().dim_names[2]
            params['out_height'] = self.get_output_variable().dim_names[1]
            params['out_width'] = self.get_output_variable().dim_names[2]
            params['n_filt'] = self.get_output_variable().dim_names[0]+'-1'
            params['n_filt_in'] = self.get_output_variable().dim_names[0]
            params['n_chan'] = self.get_input_variable().dim_names[0]+'-1'
            params['n_chan_in'] = self.get_input_variable().dim_names[0]
        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        if self.get_attr('data_format') == 'channels_last':            
            params['n_chan_in'] =  self.get_input_variable().dim_names[2]
            params['n_filt_in'] = self.get_output_variable().dim_names[2]
        else:
            params['n_chan_in'] =  self.get_input_variable().dim_names[0]
            params['n_filt_in'] = self.get_output_variable().dim_names[0]

        params['1x1'] = ''
        if self.is1x1:
            params['1x1'] = '_1x1'        
        return self._tcl_template.format(**params)

class Activation(Layer):
    def initialize(self):
        inp = self.get_input_variable()
        shape = inp.shape
        dims = inp.dim_names
        cl=inp.cl
        depth=inp.depth
        self.add_output_variable(shape, dims,cl=cl,depth=depth)
        
    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['activation'] = self.get_attr('activation')
        params['config'] = '{}_config{}'.format(self.get_attr('activation'), self.index)
        params['strategy']=''
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            params['strategy'] = '_stream'
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        params['type'] = self.get_attr('activation')
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['n_in'] = self.get_input_variable().size_cpp_cnn()
        else:
            params['n_in'] = self.get_input_variable().size_cpp()

        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['activation'] = self.get_attr('activation')
        params['n_in'] = self.get_input_variable().size_cpp()
        params['strategy']=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['strategy'] = '_stream'
        return self._tcl_template.format(**params)

class ParametrizedActivation(Activation):
    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['activation'] = self._get_act_function_name()
        params['param'] = self.get_attr('activ_param', 1.0)
        params['config'] = '{}_config{}'.format(self.get_attr('activation'), self.index)
        header=''
        params['strategy']=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            params['strategy'] = '_stream'
        return [header+self._function_template.format(**params)]

    def _get_act_function_name(self):
        act = self.get_attr('activation').lower()
        if act == 'leakyrelu':
            return 'leaky_relu'
        elif act == 'thresholdedrelu':
            return 'thresholded_relu'
        else:
            return act # ELU activation

    def print_tcl(self):
        params = self._default_tcl_params()
        params['activation'] = self.get_attr('activation')
        params['n_in'] = self.get_input_variable().size_cpp()
        params['strategy']=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['strategy'] = '_stream'
        return self._tcl_template.format(**params)


class PReLU(Activation):
    def initialize(self):
        super(PReLU, self).initialize()
        self.add_weights_variable(name='alpha', var_name='a{index}')

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['activation'] = self.get_attr('activation').lower()
        params['param'] = self.get_weights('alpha').name
        params['config'] = '{}_config{}'.format(self.get_attr('activation'), self.index)
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        return [header+self._function_template.format(**params)]

    def print_tcl(self):
        params = self._default_tcl_params()
        return self._tcl_template.format(**params)

class BatchNormalization(Layer):
    def initialize(self):
        inp = self.get_input_variable()
        shape = inp.shape
        dims = inp.dim_names
        #if 'FILT' not in dims[0] and len(dims) > 2:
        #    dims  = [dims[2],dims[1],dims[0]]
        #    shape = [shape[2],shape[1],shape[0]]
        depth=15 # randome number for now
        self.add_output_variable(shape, dims,depth=depth)

        gamma = self.model.get_weights_data(self.name, 'gamma')
        beta = self.model.get_weights_data(self.name, 'beta')
        mean = self.model.get_weights_data(self.name, 'moving_mean')
        var = self.model.get_weights_data(self.name, 'moving_variance')

        scale = gamma / np.sqrt(var + self.get_attr('epsilon'))
        bias = beta - gamma * mean / np.sqrt(var + self.get_attr('epsilon'))

        self.add_weights_variable(name='scale', var_name='s{index}', data=scale)
        self.add_weights_variable(name='bias', var_name='b{index}', data=bias)

    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['scale'] = self.get_weights('scale').name
        params['bias'] = self.get_weights('bias').name
        params['strategy'] = ''
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            params['strategy'] = '_stream'
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        params['n_in'] = self.get_input_variable().size_cpp()
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if not self.get_input_variable().cl or len(self.get_input_variable().dim_names) < 3:
                params['n_in'] = self.get_input_variable().dim_names[0]
            else:
                params['n_in'] = self.get_input_variable().dim_names[2]
        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['n_in'] = self.get_input_variable().size_cpp_cpp()
        params['scale'] = self.get_weights('scale').name
        params['bias'] = self.get_weights('bias').name
        return self._tcl_template.format(**params)

class UpSampling2D(Layer):
    def initialize(self):
        cl=False
        if self.get_attr('data_format') == 'channels_last':
            shape = [self.attributes['out_height'], self.attributes['out_width'], self.attributes['n_channel']]
            dims = ['OUT_HEIGHT_{}'.format(self.index), 'OUT_WIDTH_{}'.format(self.index), 'N_CHANNEL_{}'.format(self.index)]
            cl=True
        else:
            shape = [self.attributes['n_channel'], self.attributes['out_height'], self.attributes['out_width']]
            dims = ['N_CHANNEL_{}'.format(self.index), 'OUT_HEIGHT_{}'.format(self.index), 'OUT_WIDTH_{}'.format(self.index)]
        depth=(self.attributes['out_width']/self.attributes['in_width'])
        if (self.attributes['out_height']/self.attributes['in_height']) > 1:
            depth*=(self.attributes['out_height']/self.attributes['in_height'])*self.attributes['out_width']
        self.add_output_variable(shape, dims, cl=cl,depth=depth)
        self.set_attr('interp_op', self.get_attr('interpolation'))


    def function_cpp(self,iFirst=False):
        params = self._default_function_params()
        params['data_format'] = 'cf' if self.get_attr('data_format') == 'channels_first' else 'cl'
        params['strategy'] = ''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            params['strategy'] = 'stream'
        return [self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        if self.get_attr('data_format') == 'channels_last':
            params['in_height'] = self.get_input_variable().dim_names[0]
            params['in_width'] = self.get_input_variable().dim_names[1]
            params['out_height'] = self.get_output_variable().dim_names[0]
            params['out_width'] = self.get_output_variable().dim_names[1]
            params['n_channel'] = self.get_output_variable().dim_names[2]
        else:
            params['in_height'] = self.get_input_variable().dim_names[1]
            params['in_width'] = self.get_input_variable().dim_names[2]
            params['out_height'] = self.get_output_variable().dim_names[1]
            params['out_width'] = self.get_output_variable().dim_names[2]
            params['n_channel'] = self.get_output_variable().dim_names[0]
        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['n_in'] = self.get_input_variable().size_cpp_cnn()
        params['strategy']=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['strategy'] = '_stream'
        return self._tcl_template.format(**params)

class Merge(Layer):
    def initialize(self):
        assert(len(self.inputs) == 2)
        inp1 = self.get_input_variable(self.inputs[0])
        inp2 = self.get_input_variable(self.inputs[1])
        shape = inp1.shape
        assert(inp1.shape == inp2.shape)
        dims = inp1.dim_names
        self.add_output_variable(shape, dims)

    def function_cpp(self,iFirst=False):
        params = {}
        params['merge'] = self.get_attr('op').lower()
        params['config'] = 'config{}'.format(self.index)
        params['input1_t'] = self.get_input_variable(self.inputs[0]).type.name
        params['input2_t'] = self.get_input_variable(self.inputs[1]).type.name
        params['output_t'] = self.get_output_variable().type.name
        params['input1'] = self.get_input_variable(self.inputs[0]).name
        params['input2'] = self.get_input_variable(self.inputs[1]).name
        params['output'] = self.get_output_variable().name
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            size = self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            size = self.get_input_variable(self.inputs[0]).size()
        params['strategy']=''
        if size > 1000:
            params['strategy']='_mux'
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        params['n_mux'] = 1
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['n_elem']      = self.get_input_variable(self.inputs[0]).size_cpp_cnn()
            params['n_elem_full'] = self.get_input_variable(self.inputs[0]).size_cpp_cnn()
            size=self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp()
            params['n_elem_full'] = self.get_input_variable(self.inputs[0]).size_cpp()
            size=self.get_input_variable(self.inputs[0]).size()
        if size > 1000: 
            n_elem_full = float(size)
            factor = n_elem_full/float(1000)
            outfactor = 1
            for i0 in range(int(factor+1),int(n_elem_full)):
                if int(n_elem_full) % i0 == 0:
                    outfactor = i0
                    break
            params['n_mux'] = outfactor
            params['n_elem'] = int(n_elem_full)/int(outfactor)
        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        params['merge'] = self.get_attr('op').lower()
        params['input1_t'] = self.get_input_variable(self.inputs[0]).type.name
        params['input2_t'] = self.get_input_variable(self.inputs[1]).type.name
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp_cnn()
        else:
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp()
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            size = self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            size = self.get_input_variable(self.inputs[0]).size()
        params['strategy']=''
        if size > 1000:
            strategy='_mux'
        return self._tcl_template.format(**params)

class Split(Layer):
    def initialize(self):
        assert(len(self.inputs) == 1)
        inp1 = self.get_input_variable(self.inputs[0])
        shape = inp1.shape
        dims = inp1.dim_names
        self.add_output_variable(shape, dims,self.name+'_output1',"layer{index}_out1")
        self.add_output_variable(shape, dims,self.name+'_output2',"layer{index}_out2")

    def function_cpp(self,iFirst=False):
        params = {}
        params['config']    = 'config{}'.format(self.index)
        params['input_t']   = self.get_input_variable(self.inputs[0]).type.name
        params['output_t'] = self.get_output_variable(self.name+'_output1').type.name
        params['input']     = self.get_input_variable(self.inputs[0]).name
        params['output1']   = self.get_output_variable(self.name+'_output1').name
        params['output2']   = self.get_output_variable(self.name+'_output2').name
        header=''
        if self.model.config.get_config_value('IOType') == 'io_serial':
            if iFirst:
                header='if(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
            else:
                header='while(!'+ self.get_input_variable(self.inputs[0]).name+'[0].empty()) '
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            size = self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            size = self.get_input_variable(self.inputs[0]).size()
        params['strategy']=''
        if size > 1000:
            strategy='_mux'
        return [header+self._function_template.format(**params)]

    def config_cpp(self):
        params = self._default_config_params()
        params['n_mux'] = 1
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp_cnn()
            params['n_elem_full'] = self.get_input_variable(self.inputs[0]).size_cpp_cnn()
            size=self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp()
            params['n_elem_full'] = self.get_input_variable(self.inputs[0]).size_cpp()
            size=self.get_input_variable(self.inputs[0]).size()
        if size > 1000: 
            params['n_elem_full'] = params['n_elem']
            n_elem_full = float(size)
            factor = n_elem_full/float(1000)
            outfactor = 1
            for i0 in range(int(factor+1),int(n_elem_full)):
                if int(n_elem_full) % i0 == 0:
                    outfactor = i0
                    break
            params['n_mux'] = outfactor
            params['n_elem'] = int(n_elem_full)/int(outfactor)
        return self._config_template.format(**params)

    def print_tcl(self):
        params = self._default_tcl_params()
        if self.model.config.get_config_value('IOType') == 'io_serial':
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp_cnn()
        else:
            params['n_elem'] = self.get_input_variable(self.inputs[0]).size_cpp()
        params['input_t']   = self.get_input_variable(self.inputs[0]).type.name
        params['output_t'] = self.get_output_variable(self.name+'_output1').type.name
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            size = self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            size = self.get_input_variable(self.inputs[0]).size()
        params['strategy']=''
        if size > 1000:
            strategy='_mux'
        return self._tcl_template.format(**params)

class Concatenate(Merge):
    def initialize(self):
        assert(len(self.inputs) == 2)
        inp1 = self.get_input_variable(self.inputs[0])
        inp2 = self.get_input_variable(self.inputs[1])
        shape = [sum(x) for x in zip(inp1.shape, inp2.shape)]
        rank = len(shape)
        if rank > 1:
            dims = ['OUT_CONCAT_{}_{}'.format(i, self.index) for i in range(rank)]
        else:
            dims = ['OUT_CONCAT_{}'.format(self.index)]
        self.add_output_variable(shape, dims)

    def config_cpp(self):
        params = self._default_config_params()
        for i in range(3):
            params.setdefault('n_elem1_{}'.format(i), 0)
            params.setdefault('n_elem2_{}'.format(i), 0)
        inp1 = self.get_input_variable(self.inputs[0])
        inp2 = self.get_input_variable(self.inputs[1])
        for i, (s1, s2) in enumerate(zip(inp1.shape, inp2.shape)):
            params['n_elem1_{}'.format(i)] = s1
            params['n_elem2_{}'.format(i)] = s2

        return self._config_template.format(**params)

    def print_tcl(self):
        #params['merge'] = self.get_attr('op').lower()
        params = self._default_tcl_params()
        for i, (s1, s2) in enumerate(zip(inp1.shape, inp2.shape)):
            params['n_elem1_{}'.format(i)] = s1
            params['n_elem2_{}'.format(i)] = s2
        size=1
        if self.model.config.get_config_value('IOType') == 'io_serial':
            size = self.get_input_variable(self.inputs[0]).size_cnn()
        else:
            size = self.get_input_variable(self.inputs[0]).size()
        params['strategy']=''
        if size > 1000:
            strategy='_mux'
        params['strategy']='_mux'
        return self._tcl_template.format(**params)

layer_map = {
    'InputLayer'         : Input,
    'Activation'         : Activation,
    'LeakyReLU'          : ParametrizedActivation,
    'ThresholdedReLU'    : ParametrizedActivation,
    'ELU'                : ParametrizedActivation,
    'PReLU'              : PReLU,
    'Reshape'            : Reshape,
    'Dense'              : Dense,
    'BinaryDense'        : Dense,
    'TernaryDense'       : Dense,
    'Conv1D'             : Conv1D,
    'Conv2D'             : Conv2D,
    'Conv2DMerge'        : Conv2DMerge,
    'BinaryConv2D'       : Conv2D,
    'UpSampling2D'       : UpSampling2D,
    'BatchNormalization' : BatchNormalization,
    'MaxPooling1D'       : Pooling1D,
    'AveragePooling1D'   : Pooling1D,
    'MaxPooling2D'       : Pooling2D,
    'AveragePooling2D'   : Pooling2D,
    'Merge'              : Merge,
    'Split'              : Split,
    'Concatenate'        : Concatenate,
}

def register_layer(name, clazz):
    global layer_map
    layer_map[name] = clazz
