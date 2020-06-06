from ..optimizer import OptimizerPass

class FuseDenseAndBatchNormalization(OptimizerPass):
    def match(self, node,lastnodes=None):
        is_match = node.__class__.__name__ == 'BatchNormalization' and \
                   lastnodes[0].__class__.__name__ == 'Dense' and \
                   lastnodes[0].get_attr('quantize') == 0
        return is_match

    def transform(self, model, node, lastnodes=None):
        # Fuse weight and bias of Dense layer with BN values
        dense_node = lastnodes[0] 

        dense_weight = dense_node.weights['weight']
        dense_bias = dense_node.weights['bias']

        bn_scale = node.weights['scale']
        bn_bias = node.weights['bias']

        if dense_node.get_attr('strategy') != 'large':
            fused_weight = bn_scale.data * dense_weight.data
        else:
            fused_weight = (bn_scale.data * dense_weight.data.T).T
        fused_bias = bn_scale.data * dense_bias.data + bn_bias.data

        model.remove_node(node, rewire=False)
        #model.remove_node(node, rewire=True)
        dense_node.weights['weight'].data = fused_weight
        dense_node.weights['bias'].data = fused_bias

        return True
