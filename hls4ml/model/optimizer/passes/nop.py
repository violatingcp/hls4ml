from ..optimizer import OptimizerPass

class EliminateLinearActivation(OptimizerPass):
    def match(self, node, lastnodes=None):
        return node.__class__.__name__ == 'Activation' and node.get_attr('activation') == 'linear'
    
    def transform(self, model, node,lastnodes=None):
        model.remove_node(node)
        return True
