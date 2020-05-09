from __future__ import absolute_import

from .optimizer import OptimizerPass, register_pass, get_optimizer, optimize_model


from .passes.nop import EliminateLinearActivation
from .passes.bn_quant import MergeBatchNormAndQuantizedTanh, QuantizeDenseOutput
from .passes.dense_bn_fuse import FuseDenseAndBatchNormalization
from .passes.fuse_conv     import FuseConv,FuseConv2

register_pass('eliminate_linear_activation', EliminateLinearActivation)
register_pass('merge_batch_norm_quantized_tanh', MergeBatchNormAndQuantizedTanh)
register_pass('quantize_dense_output', QuantizeDenseOutput)
register_pass('fuse_dense_batch_norm', FuseDenseAndBatchNormalization)
register_pass('fuse_conv', FuseConv)
register_pass('fuse_conv2', FuseConv2)
