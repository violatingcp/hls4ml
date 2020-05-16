from ..optimizer import OptimizerPass
import re
from collections import OrderedDict

class HLSType(object):
    def __init__(self, name, precision, **kwargs):
        self.name = name.format(**kwargs)
        self.precision = precision

    def definition_cpp(self):
        return 'typedef {precision} {name};\n'.format(name=self.name, precision=self.precision)

class Variable(object):
    def __init__(self, var_name, type_name, precision, **kwargs):
        self.name = var_name.format(**kwargs)
        self.type = HLSType(type_name, precision, **kwargs)
        self.cppname = re.sub(r'\W|^(?=\d)','_', self.name)

class ArrayVariable(Variable):
    def __init__(self, shape, dim_names, var_name='layer{index}', type_name='layer{index}_t', precision=None, pragma='partition', **kwargs):
        super(ArrayVariable, self).__init__(var_name, type_name, precision, **kwargs)
        self.shape = shape
        self.dim_names = dim_names
        self.streamcnn = False
        if pragma == 'partition':
            self.partition()
        elif pragma == 'reshape':
            self.reshape()
        elif pragma == 'stream':
            self.stream()
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
        self.pragma = pragma.format(name=self.name, depth=depth, dim=dim)

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

    def size_cpp(self):
        return '*'.join([str(k) for k in self.dim_names])

    def size_cpp_cnn(self):
        if len(self.dim_names) > 1:
            return  self.dim_names[2]
        return  self.dim_names[0]

class FuseConv(OptimizerPass):
    def match(self, node, lastnodes):
        is_match = node.__class__.__name__  == 'Activation' and \
            lastnodes[0].__class__.__name__ == 'BatchNormalization' and \
            (lastnodes[1].__class__.__name__ == 'Conv2D' or lastnodes[1].__class__.__name__ == 'Conv2DMerge')
        
        #print "Class:",node.__class__.__name__,lastnodes[0].__class__.__name__,lastnodes[1].__class__.__name__,is_match
        return is_match

    def transform(self, model, node,lastnodes):
        # Fuse weight and bias of Dense layer with BN values
        dense_node = lastnodes[1]
        norm_node  = lastnodes[0]
        relu_node  = node
        # for the near future
        dense_weight = dense_node.weights['weight']
        dense_bias = dense_node.weights['bias']
        bn_scale = norm_node.weights['scale']
        bn_bias = norm_node.weights['bias']

        if dense_node.get_attr('strategy') != 'large':
            fused_weight = bn_scale.data * dense_weight.data
        else:
            fused_weight = (bn_scale.data * dense_weight.data.T).T
        fused_bias = bn_scale.data * dense_bias.data + bn_bias.data

        del  model.output_vars[dense_node.outputs[0]]
        del  model.output_vars[norm_node.outputs[0]]
        del  dense_node.variables[dense_node.outputs[0]]
        dense_node.outputs = relu_node.outputs
        dense_node.variables[relu_node.outputs[0]] =  relu_node.variables[relu_node.outputs[0]] 
        next_node = next(x for x in model.graph.values() if x.inputs[0] == relu_node.outputs[0])
        next_node.inputs[0]  = dense_node.outputs[0]
        #next_node.inputs[0] = dense_node.outputs[0]
        del model.graph[relu_node.name]
        del model.graph[norm_node.name]
        #model.remove_node(relu_node,rewire=False)
        #model.remove_node(norm_node,rewire=False)
        dense_node.weights['weight'].data = fused_weight
        dense_node.weights['bias'].data = fused_bias
        dense_node.__class__.__name__ = 'Conv2DMerge'
        return True



class FuseConv2(OptimizerPass):
    def match(self, node, lastnodes):
        #print "Class:",node.__class__.__name__
        is_match = node.__class__.__name__  == 'BatchNormalization' and \
            (lastnodes[0].__class__.__name__ == 'Conv2D' or lastnodes[0].__class__.__name__ == 'Conv2DMerge')
        
        return is_match

    def transform(self, model, node, lastnodes):
        # Fuse weight and bias of Dense layer with BN values
        dense_node = lastnodes[0]
        norm_node  = node
        
        # for the near future
        dense_weight = dense_node.weights['weight']
        dense_bias = dense_node.weights['bias']

        bn_scale = norm_node.weights['scale']
        bn_bias = norm_node.weights['bias']

        if dense_node.get_attr('strategy') != 'large':
            fused_weight = bn_scale.data * dense_weight.data
        else:
            fused_weight = (bn_scale.data * dense_weight.data.T).T
        fused_bias = bn_scale.data * dense_bias.data + bn_bias.data

        #next_node = next(x for x in model.graph.values() if x.inputs[0] == norm_node.outputs[0])
        #next_node.inputs[0]  = dense_node.outputs[0]

        del  dense_node.variables[dense_node.outputs[0]]
        dense_node.outputs = norm_node.outputs
        dense_node.variables[norm_node.outputs[0]] =  norm_node.variables[norm_node.outputs[0]] 
        del model.graph[norm_node.name]
        #next_node = next(x for x in model.graph.values() if x.inputs[0] == norm_node.outputs[0])
        #next_node.inputs[0] = dense_node.outputs[0]
        #model.remove_node(norm_node, rewire=False)
        dense_node.weights['weight'].data = fused_weight
        dense_node.weights['bias'].data = fused_bias
        dense_node.__class__.__name__ = 'Conv2DMerge'
        return True


class FuseMerge(OptimizerPass):
    def match(self, node, lastnodes):
        #print "Class:",node.__class__.__name__
        is_match = node.__class__.__name__  == 'Activation' and \
            (lastnodes[0].__class__.__name__ == 'Merge')
        return is_match

    def transform(self, model, node, lastnodes):
        # Fuse weight and bias of Dense layer with BN values
        add_node = lastnodes[0]
        relu_node  = node
        del  model.output_vars[add_node.outputs[0]]
        del  add_node.variables[add_node.outputs[0]]
        next_node = next(x for x in model.graph.values() if x.inputs[0] == relu_node.outputs[0])
        add_node.outputs = relu_node.outputs
        add_node.variables[relu_node.outputs[0]] =  relu_node.variables[relu_node.outputs[0]] 
        next_node.inputs[0]  = add_node.outputs[0]
        del model.graph[relu_node.name]
        return True

class FuseSplit(OptimizerPass):
    def __init__(self):
        self.count = 0
        self.inputs =[]
        self.nodes  =[]
        self.matchedInput = None
        self.matchedNode  = None

    def match(self, node, lastnodes):
        is_match = False
        for input_var in node.inputs: 
            if input_var in self.inputs:
                is_match = True
                self.matchedInput = input_var
                self.matchedNode  = self.nodes[self.inputs.index(input_var)]
            else:
                self.inputs.append(input_var)
                self.nodes.append(node)
        return is_match

    def transform(self, model, node, lastnodes):
        #for input_var in node.inputs:
        #    if input_var in self.inputs:
        #        prev_node = model.graph.get(self.matchedInput)
        #for x in model.graph.values():
        #out0 = ArrayVariable(shape, dim_names, var_name=var_name, type_name=type_name, precision=precision, pragma=pragma, index=self.index)
        #out1 = ArrayVariable(shape, dim_names, var_name=var_name, type_name=type_name, precision=precision, pragma=pragma, index=self.index)
        #model.register_output_variable(self.matchedInput+'0',out0)
        #model.register_output_variable(self.matchedInput+'1',out1)
        #next_node = next(x for x in model.graph.values() if x.inputs[0] == relu_node.outputs[0])
        layer = {}
        layer['name']       = 'Split_'+str(self.count)
        layer['class_name'] = 'Split'
        layer['inputs']     = [self.matchedInput]#[node.inputs[node.inputs.index(self.matchedInput)] ]
        layer['outputs']    = ['Split_'+str(self.count)+'_output1','Split_'+str(self.count)+'_output2']
        #layer.variables     = OrderedDict()
        #layer.precision     = OrderedDict()
        #inp1  = node.get_input_variable(self.matchedInput)
        #shape = inp1.shape
        #dims  = inp1.dim_names
        #self.add_output_variable(model,layer,shape,dims,'output1')
        #self.add_output_variable(model,layer,shape,dims,'output2')
        new_node = model.make_node('Split',layer['name'],layer,layer['inputs'],layer['outputs'])
        #input1 = new_node.get_output_variable('output1')  
        #input2 = new_node.get_output_variable('output2') 
        #input1 = self.matchedNode.inputs[self.matchedNode.inputs.index(self.matchedInput)]
        #input2 = node.inputs[node.inputs.index(self.matchedInput)]  
        #new_node.inputs[0] = node.inputs[node.inputs.index(self.matchedInput)]
        self.matchedNode.inputs[self.matchedNode.inputs.index(self.matchedInput)] = new_node.outputs[0]
        node.inputs[node.inputs.index(self.matchedInput)]  = new_node.outputs[1]
        model.insert_node(new_node)
        #print("replacing:",input1, self.matchedNode.inputs[self.matchedNode.inputs.index(self.matchedInput)],self.matchedNode.inputs)
        #print("replacing:",input2, self.matchedNode.inputs[self.matchedNode.inputs.index(self.matchedInput)],node.inputs)
        
        #self.matchedNode.inputs[self.matchedNode.inputs.index(self.matchedInput)] = new_node.outputs[0]
        #node.inputs[node.inputs.index(self.matchedInput)]                         = new_node.outputs[0]
        #self.matchedNode.inputs.index(self.matchedInput) = new_node.get_output_variable('output1') 
        #node.inputs.index(self.matchedInput)             = new_node.get_output_variable('output2') 
        self.count = self.count + 1


    def add_output_variable(self, model, layer, shape, dim_names, out_name=None, var_name='layer{index}_out', type_name='layer{index}_t', precision=None, pragma='auto'):
        if out_name is None:
            out_name = layer.outputs[0]

        pragma = 'stream'
        type_name=type_name
        out = ArrayVariable(shape, dim_names, var_name=var_name, type_name=type_name, precision=precision, pragma=pragma, index=self.count)
        layer.variables[out_name] = out
        model.register_output_variable(out_name, out)
        layer.precision[out.type.name] = out.type
