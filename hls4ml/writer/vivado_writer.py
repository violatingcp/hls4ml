from __future__ import print_function
import tarfile
import yaml
from shutil import copyfile
import numpy as np
import os
import re
import glob
from collections import OrderedDict
import json

from .writers import Writer

class VivadoWriter(Writer):

    def print_array_to_cpp(self, var, odir, write_txt_file=True):
        #######################################
        ## Print weight array to C++
        #######################################

        #var.data = np.transpose(var.data, axes=[3, 2, 1, 0])
        #var.data = np.transpose(var.data, axes=[0, 3, 2, 1])

        h_file = open("{}/firmware/weights/{}.h".format(odir,var.name),"w")
        if write_txt_file:
            txt_file = open("{}/firmware/weights/{}.txt".format(odir,var.name),"w")

        #meta data
        h_file.write("//Numpy array shape {}\n".format(var.shape))
        h_file.write("//Min {:.12f}\n".format(np.min(var.min)))
        h_file.write("//Max {:.12f}\n".format(np.max(var.max)))
        h_file.write("//Number of zeros {}\n".format(var.nzeros))
        h_file.write("\n")

        h_file.write("#ifndef {}_H_\n".format(var.name.upper()))
        h_file.write("#define {}_H_\n".format(var.name.upper()))
        h_file.write("\n")

        if write_txt_file:
            h_file.write("#ifndef __SYNTHESIS__\n")
            h_file.write(var.definition_cpp() + ";\n")
            h_file.write("#else\n")

        h_file.write(var.definition_cpp() + " = {")

        #fill c++ array.
        #not including internal brackets for multidimensional case
        sep = ''
        for x in var:
            h_file.write(sep + x)
            if write_txt_file:
                txt_file.write(sep + x)
            sep = ", "
        h_file.write("};\n")
        if write_txt_file:
            h_file.write("#endif\n")
            txt_file.close()
        h_file.write("\n#endif\n")
        h_file.close()

    def write_project_dir(self, model):
        if not os.path.isdir("{}/firmware/weights".format(model.config.get_output_dir())):
            os.makedirs("{}/firmware/weights".format(model.config.get_output_dir()))

    def copy_dir(self,model,indir,outdir):
        filedir = os.path.dirname(os.path.abspath(__file__))
        srcpath = os.path.join(filedir,indir)
        dstpath = ('{}/'+outdir).format(model.config.get_output_dir())
        if not os.path.exists(dstpath):
            os.mkdir(dstpath)
        files = [os.path.basename(h) for h in glob.glob(srcpath + '*')]
        for h in files:
            copyfile(srcpath + h, dstpath + h)


    def write_model_json(self, model):


        tensor_list = []
        tensor_map = {}
        layer_map = {}
        layer_output_map = {}

        for layer in model.get_layers():
            if 'Input' in layer.__class__.__name__:
                continue
            if 'Activation' in layer.__class__.__name__:
                continue
            if 'Dense' in layer.__class__.__name__:
                continue
            #print("first iteration layer" + str(layer.index))
            layer_map[layer.index] = layer

            #if ('Merge' in layer.__class__.__name__):
            #    print ("merge strat: " + str(layer.get_attr('op').lower()))
            #if('Activation' in layer.__class__.__name__):
            #    print ("activation strat: " + str(layer.get_attr('activation')))

            if ('Conv2D' in layer.__class__.__name__) or ('Merge' in layer.__class__.__name__) or  ('Pooling' in layer.__class__.__name__)  or ('Activation' in layer.__class__.__name__):
                variable = layer.get_output_variable()
                if variable.name in tensor_map:
                    tensor_map[variable.name]["output"].append(layer.index)
                else:
                    tensor_map[variable.name] = {"input": [], "output": [layer.index]}
                layer_output_map[layer.index] = [variable.name]
                #print('n_chan_out: name: ' +  variable.name + " DIMS: " + str(variable.shape[0]))
            elif ('Split' in layer.__class__.__name__) :
                variable = layer.get_output_variable()
                if (variable.name) in tensor_map:
                    tensor_map[variable.name ]["output"].append(layer.index)
                    tensor_map[variable.name[:-1] + "2"]["output"].append(layer.index)
                else:
                    tensor_map[variable.name]  = {"input": [], "output": [layer.index]}
                    tensor_map[variable.name[:-1] + "2"]  = {"input": [], "output": [layer.index]}
                layer_output_map[layer.index] = [variable.name, variable.name[:-1] + "2"]
                #print('n_chan_out: name: ' +  variable.name + " DIMS: " + str(variable.shape[0]))
                #print('n_chan_out: name: ' +  variable.name[:-1] + "2 DIMS: " + str(variable.shape[0]))
            else:
                print("Layer not found: type is " +layer.__class__.__name__)


        for layer in model.get_layers():
            if 'Input' in layer.__class__.__name__:
                continue
            if 'Activation' in layer.__class__.__name__:
                continue
            if 'Dense' in layer.__class__.__name__:
                continue
            #print("second iteration layer" + str(layer.index))

            if ('Conv2D' in layer.__class__.__name__) or ('Split' in layer.__class__.__name__) or  ('Pooling' in layer.__class__.__name__) or ('Dense' in layer.__class__.__name__) or ('Activation' in layer.__class__.__name__):
                variable = layer.get_input_variable()
                if variable.name in tensor_map:
                    tensor_map[variable.name]["input"].append([layer.index, 0])
                else:
                    tensor_map[variable.name] = {"input": [[layer.index,0]], "output": []}
                #print('n_chan_out: name: ' +  variable.name + " DIMS: " + str(variable.shape[0]))
            elif ('Merge' in layer.__class__.__name__) :
                variable = layer.get_input_variable(layer.inputs[0])
                if (variable.name) in tensor_map:
                    tensor_map[variable.name ]["input"].append([layer.index, 0])
                else:
                    tensor_map[variable.name]  = {"input": [[layer.index]], "input2": [], "output": []}
                #print('n_chan_in_1: name: ' +  variable.name + " DIMS: " + str(variable.shape[0]))
                variable = layer.get_input_variable(layer.inputs[1])
                if (variable.name) in tensor_map:
                    tensor_map[variable.name ]["input"].append([layer.index, 1])
                else:
                    tensor_map[variable.name]  = {"input": [[layer.index, 1]], "output": []}
                #print('n_chan_in_2: name: ' +  variable.name[:-1] + "2 DIMS: " + str(variable.shape[0]))
            else:
                print("Layer not found: type is " +layer.__class__.__name__)


        ips = []
        cpu_dest = 0


        for layer_key in layer_map.keys():
            layer = layer_map[layer_key]
            kernel_name = ''
            input_ports = []
            output_ports = []
            if ('Conv2D' in layer.__class__.__name__):
                data_format = ''
                onexone = ''
                strategy = ''
                if(layer.get_attr("data_format") == 'channels_last'):
                    data_format = '_cl'
                if(layer.is1x1):
                    onexone = '_1x1'
                if(layer.get_attr('strategy') != None):
                    strategy = "_" + layer.get_attr("strategy")
                kernel_name = "conv_2d" + strategy + data_format + onexone
                input_ports = [{"name":"input", "width": layer.get_input_variable().shape[0] + 1}]

                #print (layer_key)
                #print (layer.get_output_variable().name)
                #print (tensor_map[layer.get_output_variable().name]['input'])

                if not(tensor_map[layer.get_output_variable().name]['input'] == []):
                    output_inst = "layer" + str(layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].index)
                    output_port_name = 'input'
                    if  'Merge' in layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].__class__.__name__:
                        if tensor_map[layer.get_output_variable().name]['input'][0][1] == 1:
                            output_port_name = 'input2'
                        else:
                            output_port_name = 'input1'
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "output_inst": output_inst, "output_port":output_port_name}]
                else:
                #no layer to accept output, final layer send back to cpu
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "dest": cpu_dest}]
            elif ('Pooling' in layer.__class__.__name__):
                data_format = ''
                onexone = ''
                strategy = ''
                if(layer.get_attr("data_format") == 'channels_last'):
                    data_format = '_cl'
                if(layer.is1x1):
                    onexone = '_1x1'
                if(layer.get_attr('strategy') != None):
                    strategy = "_" + layer.get_attr("strategy")
                kernel_name = "pooling2d" + strategy + data_format + onexone
                input_ports = [{"name":"input", "width": layer.get_input_variable().shape[0] +1}]

                if not(tensor_map[layer.get_output_variable().name]['input'] == []):
                    output_inst = "layer" + str(layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].index)
                    output_port_name = 'input'
                    if  'Merge' in layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].__class__.__name__:
                        if tensor_map[layer.get_output_variable().name]['input'][0][1] == 1:
                            output_port_name = 'input2'
                        else:
                            output_port_name = 'input1'
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "output_inst": output_inst, "output_port":output_port_name}]
                else:
                #no layer to accept output, final layer send back to cpu
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "dest": cpu_dest}]
            elif ('Dense' in layer.__class__.__name__):
                kernel_name = "dense_" + layer.get_attr("strategy")
                input_ports = [{"name":"input", "width": layer.get_input_variable().shape[0] + 1}]

                #print(layer_key)
                #print(layer.get_output_variable().name)
                #print (tensor_map[layer.get_output_variable().name]['input'])


                if not(tensor_map[layer.get_output_variable().name]['input'] == []):
                    output_inst = "layer" + str(layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].index)
                    output_port_name = 'input'
                    if  'Merge' in layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].__class__.__name__:
                        if tensor_map[layer.get_output_variable().name]['input'][0][1] == 1:
                            output_port_name = 'input2'
                        else:
                            output_port_name = 'input1'
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "output_inst": output_inst, "output_port":output_port_name}]
                else:
                #no layer to accept output, final layer send back to cpu
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "dest": cpu_dest}]
            elif ('Split' in layer.__class__.__name__):
                kernel_name = "nnet_split"
                input_ports = [{"name":"input", "width": layer.get_input_variable().shape[0] + 1}]

                if not(tensor_map[layer.get_output_variable().name]['input'] == []):
                    output_inst = "layer" + str(layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].index)
                    output_port_name = 'input'
                    if  'Merge' in layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].__class__.__name__:
                        if tensor_map[layer.get_output_variable().name]['input'][0][1] == 1:
                            output_port_name = 'input2'
                        else:
                            output_port_name = 'input1'
                    output_ports.append({"name":"output", "width": layer.get_output_variable().shape[0] + 1, "output_inst": output_inst, "output_port":output_port_name})
                else:
                #no layer to accept output, final layer send back to cpu
                    output_ports.append({"name":"output", "width": layer.get_output_variable().shape[0] + 1, "dest": cpu_dest})

                if not(tensor_map[layer.get_output_variable().name]['input'] == []):
                    output_inst = "layer" + str(layer_map[tensor_map[layer.get_output_variable().name[:-1] + "2"]['input'][0][0]].index)
                    output_port_name = 'input'
                    if  'Merge' in layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].__class__.__name__:
                        if tensor_map[layer.get_output_variable().name]['input'][0][1] == 1:
                            output_port_name = 'input2'
                        else:
                            output_port_name = 'input1'
                    output_ports.append({"name":"output", "width": layer.get_output_variable().shape[0] + 1, "output_inst": output_inst, "output_port":output_port_name})
                else:
                #no layer to accept output, final layer send back to cpu
                    output_ports.append({"name":"output", "width": layer.get_output_variable().shape[0] + 1, "dest": cpu_dest})


            elif ('Merge' in layer.__class__.__name__):
                kernel_name = str(layer.get_attr('op').lower())
                input_ports = [{"name":"input1", "width": layer.get_input_variable(layer.inputs[0]).shape[0] + 1},
                               {"name":"input2", "width": layer.get_input_variable(layer.inputs[1]).shape[1] + 1}
                               ]
                output_inst = "layer" + str(layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].index)
                output_port_name = 'input'

                if not(tensor_map[layer.get_output_variable().name]['input'] == []):
                    if  'Merge' in layer_map[tensor_map[layer.get_output_variable().name]['input'][0][0]].__class__.__name__:
                        if tensor_map[layer.get_output_variable().name]['input'][0][1] == 1:
                            output_port_name = 'input2'
                        else:
                            output_port_name = 'input1'
                    output_ports = [{"name":"output", "width": layer.get_output_variable().shape[0] + 1, "output_inst": output_inst, "output_port":output_port_name}]
                else:
                #no layer to accept output, final layer send back to cpu
                    output_ports.append({"name":"output", "width": layer.get_output_variable().shape[0] + 1, "dest": cpu_dest})
            else:
                kernel_name = "UNKNOWN"

            ip = {"inst": "layer" + str(layer_key), "kernel":kernel_name, "inputs":input_ports, "outputs":output_ports}
            ips.append(ip)



        #print (tensor_map)
        #print(ips)
        ips = {"ips":ips}
        r = json.dumps(ips, indent=4, separators=(',', ': '), sort_keys=True)
        f = open("{}/firmware/model.json".format(model.config.get_output_dir()),"w")
        f.write(str(r))

    def write_tcl_dir(self, model):

        odir = model.config.get_output_dir()
        if not os.path.isdir("{}/firmware/ips".format(model.config.get_output_dir())):
            os.makedirs("{}/firmware/ips".format(model.config.get_output_dir()))

        m_top_file = open("{}/firmware/ips/Makefile".format(model.config.get_output_dir()),"w")
        m_top_file.write("SUBDIRS := $(wildcard layer*/.) bridges\n")
        m_top_file.write(".PHONY : all $(SUBDIRS)\n\n")
        m_top_file.write("all : $(SUBDIRS)\n\n")
        m_top_file.write("$(SUBDIRS) :\n")
        m_top_file.write("	$(MAKE) -C $@\n")
        m_top_file.write("clean:\n\tfor dir in $(SUBDIRS); do\\\n\t\texport SYNTH_ROOT=dir;\\\n\t\t$(MAKE) -C $$dir -f Makefile $@; \\\n\tdone\n")
        m_top_file.close()

        for layer in model.get_layers():
            if 'Input' in layer.__class__.__name__:
                continue
            params = layer._default_config_params()
#            if 'Conv2D' in layer.__class__.__name__:
            if not os.path.isdir("{}/firmware/ips/layer{}".format(model.config.get_output_dir(),layer.index)):
                os.makedirs("{}/firmware/ips/layer{}".format(model.config.get_output_dir(),layer.index))
            t_file = open("{}/firmware/ips/layer{}/synth.tcl".format(odir,layer.index),"w")
            t_file.write(layer.print_tcl())
            t_file.close()
            h_file = open("{}/firmware/ips/layer{}/layer_params.h".format(odir,layer.index),"w")
            h_file.write("#ifndef LAYER{}_PARAMS\n".format(layer.index))
            h_file.write("#define LAYER{}_PARAMS\n".format(layer.index))
            for w in layer.get_weights():
            #h_file.write("#include \"w{}.h\" \n".format(var.name))
                if not 'w' in w.name:
                    h_file.write("#include \"weights/{}.h\" \n".format(w.name))
            h_file.write("#endif\n".format(layer.index))
            h_file.close()
            m_file = open("{}/firmware/ips/layer{}/Makefile".format(odir,layer.index),"w")
            m_file.write('SUBDIRS := $(wildcard */.)\n\n')
            m_file.write('.PHONY: all clean\n')
            m_file.write('include ../common/include.mk\n')
            m_file.write('SYNTH_ROOT = "."\n\n')
            m_file.write('basefile=/home/pharris/aigean/galapagos/userIP/hls_projects/resnet_$(project_name)/solution1/impl/report/verilog/$(project_name)_conv_2d_large_cl_1x1_port_export.rpt\n\n')
            m_file.write('all:\n')
            m_file.write('\t mkdir -p "$(galapagos_dir)/userIP/hls_projects"\n')
            m_file.write('\t vivado_hls $(SYNTH_ROOT)/synth.tcl -tclargs $(project_name) $(nnet_utils_dir) $(galapagos_dir)\n')
            m_file.write('\t echo $(project_name)\n\n\n')
            m_file.write('clean:\n')
            m_file.write('\t rm -rf $(galapagos_dir)/userIP/hls_projects/resnet_$(project_name)\n')
            m_file.close()


        self.copy_dir(model,'../templates/vivado/AIgean/srcs/','firmware/ips/srcs/'),
        self.copy_dir(model,'../templates/vivado/AIgean/common/','firmware/ips/common/'),
        self.copy_dir(model,'../templates/vivado/AIgean/include/','firmware/ips/include/'),
        self.copy_dir(model,'../templates/vivado/AIgean/bridges/','firmware/ips/bridges/'),

    def write_project_cpp(self, model):
        ###################
        ## myproject.cpp
        ###################

        filedir = os.path.dirname(os.path.abspath(__file__))
        f = open(os.path.join(filedir,'../templates/vivado/firmware/myproject.cpp'),'r')
        fout = open('{}/firmware/{}.cpp'.format(model.config.get_output_dir(), model.config.get_project_name()),'w')
        serial=''
        if model.config.get_config_value('IOType') == 'io_serial':
            serial='_in'

        model_inputs  = model.get_input_variables()
        model_outputs = model.get_output_variables()
        model_brams   = model.get_bram_variables()

        indent = '    '
        cl=False
        for line in f.readlines():
            #Add headers to weights and biases
            if 'myproject' in line:
                if 'void' in line:
                    newline = line.replace('myproject', model.config.get_project_name()+serial)
                else:
                    newline = line.replace('myproject', model.config.get_project_name())
            elif '//hls-fpga-machine-learning insert header' in line:
                inputs_str = ', '.join([i.definition_cpp() for i in model_inputs])
                outputs_str = ', '.join([o.definition_cpp() for o in model_outputs])
                if len(model_brams) > 0: 
                    brams_str  = ',\n'.join([o.definition_cpp() for o in model_brams])
                insize_str = ', '.join(['unsigned short &const_size_in_{}'.format(i) for i in range(1, len(model_inputs) + 1)])
                outsize_str = ', '.join(['unsigned short &const_size_out_{}'.format(i) for i in range(1, len(model_outputs) + 1)])
                inputs_str=inputs_str.replace('static','')
                outputs_str=outputs_str.replace('static','')

                newline = ''
                newline += indent + inputs_str + ',\n'
                newline += indent + outputs_str + ',\n'
                if len(model_brams) > 0: 
                    newline += indent + brams_str + ',\n'
                newline += indent + insize_str + ',\n'
                newline += indent + outsize_str + '\n'

            elif '//hls-fpga-machine-learning insert weights' in line:
                newline = line
                for layer in model.get_layers():
                    for w in layer.get_weights():
                        if w.name not in model.brams:
                            newline += '#include "weights/{}.h"\n'.format(w.name)

            elif '//hls-fpga-machine-learning insert load weights' in line:
                newline = line
                for layer in model.get_layers():
                    for w in layer.get_weights():
                        if w.__class__.__name__ == 'CompressedWeightVariable':
                            newline += indent + '    nnet::load_compressed_weights_from_txt<{}, {}>({}, "{}.txt");\n'.format(w.type.name, w.nonzeros, w.name, w.name)
                        else:
                            newline += indent + '    nnet::load_weights_from_txt<{}, {}>({}, "{}.txt");\n'.format(w.type.name, w.data_length, w.name, w.name)

            #Add input/output type
            elif '//hls-fpga-machine-learning insert IO' in line:
                newline = line
                all_inputs = [i.cppname for i in model_inputs]
                all_outputs = [o.cppname for o in model_outputs]
                if model.config.get_config_value("IOType") == "io_parallel":
                    for i in model_inputs: newline += indent + '#pragma HLS ARRAY_RESHAPE variable={} complete dim=0 \n'.format(i.cppname)
                    for o in model_outputs: newline += indent + '#pragma HLS ARRAY_RESHAPE variable={} complete dim=0 \n'.format(o.cppname)
                    newline += indent + '#pragma HLS INTERFACE ap_vld port={},{} \n'.format(','.join(all_inputs), ','.join(all_outputs))
                    if model.config.model_strategy == 'Resource':
                        newline += indent + '#pragma HLS DATAFLOW \n'
                    else:
                        newline += indent + '#pragma HLS PIPELINE \n'
                if model.config.get_config_value("IOType") == "io_serial":
                    newline += indent + '#pragma HLS INTERFACE axis port={},{} \n'.format(','.join(all_inputs), ','.join(all_outputs))
                    #newline += indent + '#pragma HLS DATAFLOW \n'

                inval_str = '\n    '.join(['const_size_in_{} = {};'.format(i, inp.size_cpp()) for i, inp in enumerate(model_inputs, 1)])
                outval_str = '\n    '.join(['const_size_out_{} = {};'.format(i, out.size_cpp()) for i, out in enumerate(model_outputs, 1)])
                newline += '\n' + indent + inval_str
                newline += '\n' + indent + outval_str
                newline += '\n'

            elif '//hls-fpga-machine-learning insert layers' in line:
                newline = line + '\n'
                inputs = model.get_input_variables()
                outputs = model.get_output_variables()
                first=True
                for layer in model.get_layers():
                    vars = layer.get_variables()
                    for var in vars:
                        if var.cl:
                            cl=True
                        if var not in inputs and var not in outputs:
                            def_cpp = var.definition_cpp()
                            if def_cpp is not None:
                                newline += '    ' + def_cpp + ';\n'
                                if var.pragma:
                                    newline += '    ' + var.pragma + '\n'

                    func = layer.function_cpp(first)
                    if 'put' not in layer.name: #put is short for input
                        first=False
                    if func:
                        for line in func:
                            newline += '    ' + line + '\n'
                        newline += '\n'

            #Just copy line
            else:
                newline = line

            fout.write(newline)

        fout.write('\n')
        fout.write('\n')
        if model.config.get_config_value('IOType') == 'io_serial':
            newline = 'void {}(\n'.format(model.config.get_project_name())
            inputs_str = ', '.join([i.definition_cpp().replace('static','') for i in model_inputs])
            outputs_str = ', '.join([o.definition_cpp().replace('static','') for o in model_outputs])
            if len(model_brams) > 0:
                brams_str  = ',\n'.join([o.definition_cpp() for o in model_brams])
            insize_str = ', '.join(['unsigned short &const_size_in_{}'.format(i) for i in range(1, len(model_inputs) + 1)])
            outsize_str = ', '.join(['unsigned short &const_size_out_{}'.format(o) for o in range(1, len(model_outputs) + 1)])
            newline += indent + inputs_str  + ',\n'
            newline += indent + outputs_str + ',\n'
            if len(model_brams) > 0:
                newline += indent + brams_str + ',\n'
            newline += indent + insize_str  + ',\n'
            newline += indent + outsize_str + '\n'
            newline += ') { \n'
            for inp in model.get_input_variables():
                shape=inp.shape
                #add a for loop
                irange=[shape[0],shape[1]]
                if not cl:
                    irange=[shape[1],shape[2]]
                if len(shape) == 2: 
                    irange=[shape[0]] if cl else [shape[1]]
                for i0 in range(len(irange)):
                    for i1 in range(i0):
                        newline += indent
                    newline += 'for(int i{} = 0; i{} < {}; i{}++) {{\n'.format(i0,i0,irange[i0],i0)
                for i1 in range(len(irange)):
                    newline += indent
                inputs=', '.join([i.name for i in model_inputs]) 
                outputs=', '.join([i.name for i in model_outputs]) 
                brams=', '.join([i.name for i in model_brams]) 
                insize=', '.join(['const_size_in_{}'.format(i) for i in range(1, len(model_inputs) + 1)])
                outsize=', '.join(['const_size_out_{}'.format(o) for o in range(1, len(model_outputs) + 1)])
                if len(model_brams) > 0: 
                       newline += ('{}{}'.format(model.config.get_project_name(),serial))+'('+inputs+','+outputs+','+brams+','+insize+','+outsize+');\n'
                else:
                       newline += ('{}{}'.format(model.config.get_project_name(),serial))+'('+inputs+','+outputs+','+insize+','+outsize+');\n'
                for i0 in irange:
                    for i1 in range(i0):
                        newline += indent
                    newline += '}\n'
            newline+='}\n'
            fout.write(newline)
        f.close()
        fout.close()

    def write_project_header(self, model):
        #######################
        ## myproject.h
        #######################

        filedir = os.path.dirname(os.path.abspath(__file__))
        f = open(os.path.join(filedir,'../templates/vivado/firmware/myproject.h'),'r')
        fout = open('{}/firmware/{}.h'.format(model.config.get_output_dir(), model.config.get_project_name()),'w')

        model_inputs = model.get_input_variables()
        model_outputs = model.get_output_variables()
        model_brams   = model.get_bram_variables()

        indent = '    '

        for line in f.readlines():

            if 'MYPROJECT' in line:
                newline = line.replace('MYPROJECT',format(model.config.get_project_name().upper()))
            elif 'void myproject(' in line:
                newline = 'void {}(\n'.format(model.config.get_project_name())
            elif '//hls-fpga-machine-learning insert header' in line:
                inputs_str  = ', '.join([i.definition_cpp().replace('static','') for i in model_inputs])
                outputs_str = ', '.join([o.definition_cpp().replace('static','') for o in model_outputs])
                if len(model_brams) > 0:
                    brams_str   = ',\n'.join([o.definition_cpp() for o in model_brams])
                insize_str  = ', '.join(['unsigned short &const_size_in_{}'.format(i) for i in range(1, len(model_inputs) + 1)])
                outsize_str = ', '.join(['unsigned short &const_size_out_{}'.format(o) for o in range(1, len(model_outputs) + 1)])

                newline = ''
                newline += indent + inputs_str + ',\n'
                newline += indent + outputs_str + ',\n'
                if len(model_brams) > 0:
                    newline += indent + brams_str + ',\n'
                newline += indent + insize_str + ',\n'
                newline += indent + outsize_str + '\n'
            else:
                newline = line
            fout.write(newline)

        f.close()
        fout.close()

    def write_parameters(self, model):
        filedir = os.path.dirname(os.path.abspath(__file__))
        f = open(os.path.join(filedir,'../templates/vivado/firmware/parameters.h'),'r')
        fout = open('{}/firmware/parameters.h'.format(model.config.get_output_dir()),'w')

        for line in f.readlines():

            #Insert numbers
            if '//hls-fpga-machine-learning insert numbers' in line:
                newline = line
                numbers = OrderedDict.fromkeys([layer.get_numbers_cpp() for layer in model.get_layers()])
                newline += ''.join(numbers)

            elif '//hls-fpga-machine-learning insert layer-precision' in line:
                newline = line
                all_precision = OrderedDict()
                for layer in model.get_layers():
                    layer_precision = layer.get_layer_precision()
                    all_precision.update(layer_precision)
                for used_type in all_precision.values():
                    newline += used_type.definition_cpp()

            elif "//hls-fpga-machine-learning insert layer-config" in line:
                newline = line
                for layer in model.get_layers():
                    config = layer.config_cpp()
                    if config:
                        newline += config + '\n'
            else:
                newline = line
            fout.write(newline)
        f.close()
        fout.close()

    def write_weights(self, model):
        for layer in model.get_layers():
            for weights in layer.get_weights():
                self.print_array_to_cpp(weights, model.config.get_output_dir())

    def write_test_bench(self, model):
        ###################
        ## test bench
        ###################

        filedir = os.path.dirname(os.path.abspath(__file__))

        if not os.path.exists('{}/tb_data/'.format(model.config.get_output_dir())):
            os.mkdir('{}/tb_data/'.format(model.config.get_output_dir()))
        input_data = model.config.get_config_value('InputData')
        output_predictions = model.config.get_config_value('OutputPredictions')
        if input_data is not None:
            copyfile(input_data, '{}/tb_data/tb_input_features.dat'.format(model.config.get_output_dir()))
        if output_predictions is not None:
            copyfile(output_predictions, '{}/tb_data/tb_output_predictions.dat'.format(model.config.get_output_dir()))

        f = open(os.path.join(filedir,'../templates/vivado/myproject_test.cpp'),'r')
        fout = open('{}/{}_test.cpp'.format(model.config.get_output_dir(), model.config.get_project_name()),'w')

        for line in f.readlines():
            indent = ' ' * (len(line) - len(line.lstrip(' ')))

            #Insert numbers
            if 'myproject' in line:
                newline = line.replace('myproject', model.config.get_project_name())
            elif '//hls-fpga-machine-learning insert data' in line:
                newline = line
                model_brams   = model.get_bram_variables()
                for bram in model_brams:
                    newline += bram.definition_cpp()+';\n'
                for inp in model.get_input_variables():
                    input_str = '      ' + inp.definition_cpp() + ' = {};\n'
                    default_val = ','.join('in[{}]'.format(i) for i in range(inp.size()-1))
                    newline += input_str.format('{' + default_val + '}')
                for out in model.get_output_variables():
                    output_str = '      ' + out.definition_cpp() + ' = {};\n'
                    default_val = ','.join(str(o) for o in [0] * out.size())
                    newline += output_str.format('{' + default_val + '}')
            elif '//hls-fpga-machine-learning insert zero' in line:
                newline = line
                for inp in model.get_input_variables():
                    input_str = '    ' + inp.definition_cpp() + ' = {};\n'
                    default_val = ','.join(str(i) for i in [0] * inp.size())
                    newline += input_str.format('{' + default_val + '}')
                for out in model.get_output_variables():
                    output_str = '    ' + out.definition_cpp() + ' = {};\n'
                    default_val = ','.join(str(o) for o in [0] * out.size())
                    newline += output_str.format('{' + default_val + '}')
            elif '//hls-fpga-machine-learning insert top-level-function' in line:
                newline = line

                size_str = indent + 'unsigned short {},{};\n'
                input_size_vars  = ','.join(['size_in{}'.format(i) for i in range(1, len(model.get_input_variables()) + 1)])
                output_size_vars = ','.join(['size_out{}'.format(o) for o in range(1, len(model.get_output_variables()) + 1)])
                newline += size_str.format(input_size_vars, output_size_vars)

                input_vars = ','.join([i.cppname for i in model.get_input_variables()])
                output_vars = ','.join([o.cppname for o in model.get_output_variables()])
                bram_vars   =', '.join([i.name for i in model.get_bram_variables()]) 
                if len(model.get_bram_variables()) > 0: 
                    top_level = indent + '{}({},{},{},{},{});\n'.format(model.config.get_project_name(), input_vars, output_vars, bram_vars, input_size_vars, output_size_vars)
                else: 
                    top_level = indent + '{}({},{},{},{});\n'.format(model.config.get_project_name(), input_vars, output_vars, input_size_vars, output_size_vars)
                newline += top_level
            elif '//hls-fpga-machine-learning insert predictions' in line:
                newline = line
                for out in model.get_output_variables():
                    newline += indent + 'for(int i = 0; i < {}; i++) {{\n'.format(out.size_cpp())
                    newline += indent + '  std::cout << pr[i] << " ";\n'
                    newline += indent + '}\n'
                    newline += indent + 'std::cout << std::endl;\n'
            elif '//hls-fpga-machine-learning insert tb-output' in line:
                newline = line
                for out in model.get_output_variables():
                    newline += indent + 'for(int i = 0; i < {}; i++) {{\n'.format(out.size_cpp())
                    newline += indent + '  fout << {}[i] << " ";\n'.format(out.cppname)
                    newline += indent + '}\n'
                    newline += indent + 'fout << std::endl;\n'
            elif '//hls-fpga-machine-learning insert output' in line or '//hls-fpga-machine-learning insert quantized' in line:
                newline = line
                for out in model.get_output_variables():
                    newline += indent + 'for(int i = 0; i < {}; i++) {{\n'.format(out.size_cpp())
                    newline += indent + '  std::cout << {}[i] << " ";\n'.format(out.cppname)
                    newline += indent + '}\n'
                    newline += indent + 'std::cout << std::endl;\n'
            else:
                newline = line
            fout.write(newline)
        f.close()
        fout.close()

    def write_test_bench_serial(self, model):
        ###################
        ## test bench
        ###################

        filedir = os.path.dirname(os.path.abspath(__file__))

        if not os.path.exists('{}/tb_data/'.format(model.config.get_output_dir())):
            os.mkdir('{}/tb_data/'.format(model.config.get_output_dir()))
        input_data = model.config.get_config_value('InputData')
        output_predictions = model.config.get_config_value('OutputPredictions')
        if input_data is not None:
            copyfile(input_data, '{}/tb_data/tb_input_features.dat'.format(model.config.get_output_dir()))
        if output_predictions is not None:
            copyfile(output_predictions, '{}/tb_data/tb_output_predictions.dat'.format(model.config.get_output_dir()))

        f = open(os.path.join(filedir,'../templates/vivado/myproject_test.cpp'),'r')
        fout = open('{}/{}_test.cpp'.format(model.config.get_output_dir(), model.config.get_project_name()),'w')

        for line in f.readlines():
            indent = ' ' * (len(line) - len(line.lstrip(' ')))

            #Insert numbers
            if 'myproject' in line:
                newline = line.replace('myproject', model.config.get_project_name())
            elif '//hls-fpga-machine-learning insert data' in line:
                newline = line
                model_brams   = model.get_bram_variables()
                for bram in model_brams:
                    newline += bram.definition_cpp()+';\n'
                for inp in model.get_input_variables():
                    newline+= 'unsigned index=0;\n'
                    input_str = '      ' + inp.definition_cpp().replace('static','') + ';\n'
                    newline += input_str
                    shape=inp.shape
                    #add a for loop
                    for i0 in range(len(shape)): 
                        if i0 != len(shape)-1:
                            newline += indent + 'for(int i{} = 0; i{} < {}; i{}++) {{\n'.format(i0,i0,shape[i0],i0)
                        else:
                            newline += indent + 'for(int i{} = 0; i{} < {}+1; i{}++) {{\n'.format(i0,i0,shape[i0],i0)
                    cl=inp.cl
                    val=0 if cl else 2
                    if val > 0: 
                        val = len(shape)-1
                    newline += indent + '  {}[i{}].write(in[index]);index++;\n'.format(inp.cppname,val)
                    for i0 in range(len(shape)): 
                        newline += indent + '}\n'
                for out in model.get_output_variables():
                    output_str = '      ' + out.definition_cpp().replace('static','') + ';\n'
                    newline += output_str
            elif '//hls-fpga-machine-learning insert zero' in line:
                newline = line
                model_brams   = model.get_bram_variables()
                for bram in model_brams:
                    newline += bram.definition_cpp()+';\n'
                for inp in model.get_input_variables():
                    newline+= '{} pTest = 1;\n'.format(inp.type.name)
                    input_str = '    ' + inp.definition_cpp().replace('static','') + ';\n'
                    newline += input_str
                    shape=inp.shape
                    #add a for loop
                    for i0 in range(len(shape)): 
                        if i0 != len(shape)-1:
                            newline += indent + 'for(int i{} = 0; i{} < {}; i{}++) {{\n'.format(i0,i0,shape[i0],i0)
                        else:
                            newline += indent + 'for(int i{} = 0; i{} < {}+1; i{}++) {{\n'.format(i0,i0,shape[i0],i0)
                    cl=inp.cl
                    val=0 if cl else 2
                    ifstate=''
                    if val > 0: 
                        val = len(shape)-1
                        ifstate='if(i'
                        for i in range(val):
                            ifstate+=str(i)
                            if i < val-1:
                                ifstate+="== 0 && i"
                            else:
                                ifstate+="== 0)"
                    ifnotstate=ifstate.replace('if(','if(!')
                    newline += indent + ifstate    + ' {}[i{}].write(0);\n'.format(inp.cppname,val)
                    newline += indent + ifnotstate + ' {}[i{}].write(1);\n'.format(inp.cppname,val)
                    for i0 in range(len(shape)): 
                        newline += indent + '}\n'
                for out in model.get_output_variables():
                    output_str = '    ' + out.definition_cpp().replace('static','') + ';\n'
                    newline += output_str
            elif '//hls-fpga-machine-learning insert top-level-function' in line:
                newline = line
                size_str = indent + 'unsigned short {},{};\n'
                input_size_vars = ','.join(['size_in{}'.format(i) for i in range(1, len(model.get_input_variables()) + 1)])
                output_size_vars = ','.join(['size_out{}'.format(o) for o in range(1, len(model.get_output_variables()) + 1)])
                newline += size_str.format(input_size_vars, output_size_vars)

                input_vars = ','.join([i.cppname for i in model.get_input_variables()])
                output_vars = ','.join([o.cppname for o in model.get_output_variables()])
                bram_vars   =', '.join([i.name for i in model.get_bram_variables()]) 
                if len(model.get_bram_variables()) > 0: 
                    top_level = indent + '{}({},{},{},{},{});\n'.format(model.config.get_project_name(), input_vars, output_vars, bram_vars, input_size_vars, output_size_vars)
                else: 
                    top_level = indent + '{}({},{},{},{});\n'.format(model.config.get_project_name(), input_vars, output_vars, input_size_vars, output_size_vars)
                newline += top_level
            elif '//hls-fpga-machine-learning insert predictions' in line:
                newline = line
                for out in model.get_output_variables():
                    newline += indent + 'for(int i = 0; i < {}; i++) {{\n'.format(out.size_cpp())
                    newline += indent + '  std::cout << pr[i] << " ";\n'
                    newline += indent + '}\n'
                    newline += indent + 'std::cout << std::endl;\n'
            elif '//hls-fpga-machine-learning insert tb-output' in line:
                newline = line
                for out in model.get_output_variables():
                    shape=out.shape
                    for i0 in range(len(shape)): 
                        if i0 != len(shape)-1:
                            newline += indent + 'for(int i{} = 0; i{} < {}; i{}++) {{\n'.format(i0,i0,shape[i0],i0)
                        else:
                            newline += indent + 'for(int i{} = 0; i{} < {}+1; i{}++) {{\n'.format(i0,i0,shape[i0],i0)
                    cl=out.cl
                    val=2 if not cl and len(shape) > 1 else 0
                    newline += indent + '  fout << {}[i{}].read() << " ";\n'.format(out.cppname,val)
                    for i0 in range(len(shape)): 
                        newline += indent + '}\n'
                    newline += indent + 'fout << std::endl;\n'
            else:
                newline = line
            fout.write(newline)
        f.close()
        fout.close()

    def write_build_script(self, model):
        ###################
        # build_prj.tcl
        ###################

        filedir = os.path.dirname(os.path.abspath(__file__))

        f = open(os.path.join(filedir,'../templates/vivado/build_prj.tcl'),'r')
        fout = open('{}/build_prj.tcl'.format(model.config.get_output_dir()),'w')

        for line in f.readlines():

            line = line.replace('myproject',model.config.get_project_name())

            if 'set_part {xcku115-flvb2104-2-i}' in line:
                line = 'set_part {{{}}}\n'.format(model.config.get_config_value('XilinxPart'))
            elif 'create_clock -period 5 -name default' in line:
                line = 'create_clock -period {} -name default\n'.format(model.config.get_config_value('ClockPeriod'))

            fout.write(line)
        f.close()
        fout.close()


        ###################
        # vivado_synth.tcl
        ###################

        f = open(os.path.join(filedir,'../templates/vivado/vivado_synth.tcl'),'r')
        fout = open('{}/vivado_synth.tcl'.format(model.config.get_output_dir()),'w')
        for line in f.readlines():
            line = line.replace('myproject', model.config.get_project_name())
            if '-part' in line:
                line = 'synth_design -top {} -part {}\n'.format(model.config.get_project_name(), model.config.get_config_value('XilinxPart'))

            fout.write(line)
        f.close()
        fout.close()

    def write_nnet_utils(self, model):
        ###################
        ## nnet_utils
        ###################

        filedir = os.path.dirname(os.path.abspath(__file__))

        srcpath = os.path.join(filedir,'../templates/vivado/nnet_utils/')
        dstpath = '{}/firmware/nnet_utils/'.format(model.config.get_output_dir())

        if not os.path.exists(dstpath):
            os.mkdir(dstpath)

        headers = [os.path.basename(h) for h in glob.glob(srcpath + '*.h')]

        for h in headers:
            copyfile(srcpath + h, dstpath + h)

    def write_tar(self, model):
        ###################
        # Tarball output
        ###################

        with tarfile.open(model.config.get_output_dir() + '.tar.gz', mode='w:gz') as archive:
            archive.add(model.config.get_output_dir(), recursive=True)

    def write_hls(self, model):
        print('Writing HLS project')
        self.write_project_dir(model)
        self.write_project_cpp(model)
        self.write_project_header(model)
        self.write_weights(model)
        self.write_parameters(model)
        if model.config.get_config_value('IOType') == 'io_serial':
            self.write_test_bench_serial(model)
        else:
            self.write_test_bench(model)
        self.write_build_script(model)
        self.write_nnet_utils(model)
        self.write_model_json(model)
        self.write_tcl_dir(model)
        self.write_tar(model)
        print('Done')
