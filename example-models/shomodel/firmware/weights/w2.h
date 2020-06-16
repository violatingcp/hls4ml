//Numpy array shape [15, 2, 128]
//Min -4.018606662750
//Max 4.884557247162
//Number of zeros 0

#ifndef W2_H_
#define W2_H_

#ifndef __SYNTHESIS__
model_default_t w2[3840];
#else
model_default_t w2[3840] = {-0.1525, -0.0725, -0.1171, -0.0584, -0.1108, -0.1681, -0.3398, -0.2268, -0.1692, 0.0013, 0.0855, -0.9765, -0.3000, 0.3778, 0.2045, -0.1556, -0.0878, 0.1003, 0.0888, 0.0359, 0.0093, -0.2743, -0.2773, -0.3421, -0.4557, -0.6528, 0.4728, 2.1830, 1.7828, 1.5102, -1.2060, -0.9544, -0.8284, -1.1589, -1.4132, -0.0910, 1.2961, 2.3034, 1.7219, 1.7290, 2.1142, 1.9014, 1.0799, 1.3788, 1.4624, 3.3660, 2.2920, 1.7931, 1.6991, 1.5478, 1.6099, 1.8475, 1.5955, 1.0618, 1.2347, 0.9773, 0.3312, 0.6641, 0.8358, 0.8783, -0.1753, 0.0671, -0.0147, -0.0448, -0.0772, -0.0557, -0.2350, 0.1482, -0.0295, -0.0509, 0.0247, -0.0386, 0.0304, 0.0599, -0.0420, 0.1090, 0.0582, 0.0207, 0.0053, 0.0788, 0.0475, 0.1431, -0.0341, -0.1130, -0.0180, 0.0236, 0.0677, 0.1505, -0.1452, -0.0885, -0.5254, -0.3544, -1.5667, -1.3663, -1.4789, 1.6414, 0.3857, 0.9659, 0.5240, 0.2412, -0.1959, -0.1019, 0.1546, 0.1099, 0.0739, -0.3836, -0.3546, 0.0789, 0.6127, 0.4436, 1.7390, 1.8084, -0.5331, -0.5275, -0.8094, -0.4966, -0.2443, -0.2227, -0.1450, 0.4545, -0.0751, -0.0508, 0.0399, 0.0388, 0.0310, -0.0911, 0.0433, 0.0444, 0.0457, -0.0994, 0.0454, -0.0773, 0.0132, -0.0342, -0.0205, 0.0035, 0.0355, -0.0287, -0.0120, 0.0182, -0.1201, 0.0079, 0.0528, -0.0253, -0.0612, -0.0667, 0.0872, 0.0124, -0.0360, 0.0260, 0.3320, 0.0855, -0.8545, 0.3674, -1.6225, -0.8903, -0.2756, 0.4416, 1.3524, 1.2182, 0.3774, 0.3524, -0.1297, 0.2747, -0.0403, 0.5129, -0.8140, -0.5070, -0.4345, 1.7710, 1.2790, 1.6181, 1.6592, 0.5194, -0.0049, -0.1383, -0.4094, 0.3191, 0.2838, 0.5835, -0.2025, 1.3649, -0.8753, 1.8003, 0.4224, -0.5813, -0.7311, 1.3720, 1.5801, -0.0921, -0.7473, 0.3875, -0.0082, -0.6898, -0.1834, -0.1055, -1.0126, -0.2308, -1.5998, -0.1567, 3.3099, -1.7602, -0.7534, 0.8149, 1.4706, 0.5366, 0.0524, 0.8671, 0.7630, 0.0717, 0.0331, 0.0314, 0.0397, 0.0401, -0.0265, -0.0257, -0.0371, -0.0302, -0.0149, -0.0190, -0.1137, -0.0023, -0.0720, 0.0235, -0.0540, -0.0519, -0.0753, -0.0043, 0.0359, -0.0105, 0.0291, -0.0329, 0.0365, -0.0489, -0.0334, -0.1108, 0.0030, 0.0313, 0.0019, 0.0379, -0.0420, 0.0298, 0.0503, -0.0448, 0.0269, -0.0472, -0.0369, 0.0156, -0.0108, 0.0133, 0.0031, 0.0195, -0.0279, -0.0157, -0.0119, -0.0471, -0.0174, 0.0397, 0.0448, 0.0362, -0.0189, -0.0109, -0.0179, -0.0248, 0.0113, -0.0490, -0.0170, 0.0006, 0.0040, -0.0255, 0.7773, 0.4613, 0.3633, 0.3576, 0.5711, 0.9814, 1.3703, 2.0004, 0.7412, 0.8949, 1.0955, 0.6971, 0.8542, 0.8398, 1.2076, 3.7057, 2.6121, 1.9267, 2.1444, 2.3232, 2.2409, 2.6371, 1.7216, -0.3904, -0.3032, -0.1943, -0.2840, -0.3684, -0.5819, -0.2583, 0.0923, 0.0495, -0.4942, -0.3220, 0.1456, 1.4220, 1.1661, 0.6010, -0.6163, -0.5342, -0.3493, -0.4721, -0.4013, -0.1333, -0.4285, 0.0457, 0.4942, 0.4963, 0.8533, 1.3272, -0.3524, -1.1614, -1.0755, -0.2072, -0.4736, 0.0457, 0.0913, 0.3369, 0.1318, 0.4140, -0.0297, -0.0015, 0.0310, 0.0244, 0.0144, -0.0081, -0.0485, 0.0424, 0.0566, -0.0505, -0.0095, -0.0125, 0.0423, -0.0278, -0.0089, -0.0389, 0.0188, -0.0225, 0.0163, 0.0409, -0.0307, -0.0416, -0.0262, -0.0033, 0.0112, 0.0200, 0.0124, 0.0042, -0.0139, 0.0227, 0.4231, -0.0903, 0.3983, -0.9381, -0.1588, 1.1494, 0.6995, 0.2581, -0.5734, -0.1137, -0.1031, 0.1190, -0.1851, -0.1326, -0.4274, 0.2555, 0.0432, -0.4171, -0.0699, 0.7692, 0.9351, -0.8333, -0.4921, -0.4309, 0.1182, -0.0041, -0.0227, -0.1389, -0.1768, 0.2853, -0.0322, -0.0333, 0.0391, 0.0458, -0.0403, 0.0462, -0.0148, -0.0405, -0.0403, -0.0392, 0.0114, 0.0130, 0.0109, -0.0510, 0.0135, -0.0333, -0.0469, 0.0468, 0.0166, 0.0192, 0.0190, 0.0247, 0.0398, 0.0373, -0.0084, 0.0258, -0.0166, 0.0442, -0.0131, 0.0035, 0.8388, 0.1229, -0.4674, -0.8456, -1.9101, -0.7495, 0.0351, 1.0235, 1.3996, 1.1741, 0.5664, 0.3468, 0.1202, -0.2056, 0.3300, 1.0525, -0.6269, -0.0999, -0.2810, 1.6168, 1.4579, 1.6370, 1.6850, 1.0042, 0.0581, -0.2698, -0.3249, 0.4533, 0.1289, 0.9925, 0.1756, 0.1526, 0.4878, 0.0319, -1.3959, 2.6082, -0.9723, -1.8440, 1.6633, 0.0012, -0.2129, -0.1043, 0.1224, -0.1381, -0.1608, -0.2487, 0.4171, -0.0471, -0.4281, 1.5156, 0.9434, -3.3165, 1.2822, 0.8441, -0.2874, -0.1280, 0.0371, -0.0427, -0.0502, 0.1525, -0.0252, 0.0221, 0.0327, -0.0375, -0.0531, 0.0312, 0.0123, 0.0256, -0.0301, 0.0424, -0.0118, 0.0035, -0.0425, -0.0235, -0.0203, 0.0415, 0.0336, -0.0360, -0.0086, 0.0383, -0.0223, -0.0406, -0.0427, 0.0462, -0.0200, 0.0327, 0.0098, -0.0004, -0.0341, -0.0111, 0.0320, -0.0400, -0.0054, -0.0083, 0.0217, 0.0080, -0.0080, -0.0070, 0.0039, 0.0058, -0.0383, -0.0164, -0.0310, -0.0393, -0.0133, 0.0225, -0.0351, 0.0323, -0.0063, 0.0034, -0.0272, 0.0242, -0.0386, -0.0292, 0.0501, -0.0226, 0.0093, 0.0159, -0.0226, 0.0028, 0.0094, 0.0400, -0.0276, -0.0113, 0.0203, -0.0316, -0.0045, 0.0010, -0.0098, 0.0364, 0.0142, -0.0446, 0.0464, -0.0404, 0.0491, -0.0334, 0.0411, -0.0168, -0.0126, 0.0180, 0.0216, -0.0028, -0.0261, -0.0127, 0.0048, -0.0507, -0.0212, -0.0491, -0.0136, -0.0257, 0.0289, -0.0075, 0.0360, 0.0439, 0.0401, 0.0199, -0.0316, 0.0082, 0.0348, 0.0365, -0.0038, 0.0167, -0.0074, -0.0381, -0.0007, -0.0433, 0.0024, 0.0360, -0.0138, -0.0150, -0.0056, -0.0034, 0.0098, 0.0323, 0.0663, -0.0194, 0.0011, 0.0336, -0.0142, -0.0038, -0.0087, -0.0407, 0.0218, 0.0525, 0.0465, 0.0386, -0.0102, -0.0408, -0.0245, -0.0087, 0.0002, 0.0239, -0.0108, 0.0099, -0.0353, -0.0462, 0.0243, -0.0363, -0.0319, 0.0054, 0.0183, 0.0286, -0.0290, 0.0237, 0.0164, -0.0482, -0.0364, 0.0199, 0.0171, -0.0500, -0.2309, -0.0306, -0.9723, -1.0187, 0.5609, 0.5777, 0.7224, 0.5214, -1.8454, 1.7609, -0.1501, -0.1889, 0.4150, -0.2873, 0.2570, 0.2521, 0.2754, 0.0883, -0.9869, 0.0545, -2.3729, 3.2724, -2.0593, -0.1720, 0.5595, -0.3975, -0.0501, 0.1104, -0.3202, -0.0236, -0.0155, 0.0122, 0.8092, 0.1649, -2.4648, -1.2421, 1.5431, 1.8912, 1.4088, 0.5487, -0.5521, -1.3593, 0.8227, 0.1568, -0.0808, 2.1680, 1.0112, 0.7722, -0.3183, -0.4154, -1.8249, -1.7521, -0.2202, 1.1192, 1.4477, 1.4115, -0.2317, 0.3317, 0.5994, 0.4796, -0.0547, -0.0227, -0.0347, 0.0186, -0.0300, -0.0773, 0.0187, 0.0679, 0.0326, 0.0536, 0.0290, 0.0242, -0.0043, 0.0409, -0.0561, -0.0107, -0.0562, -0.0356, -0.0567, 0.0289, 0.0453, 0.0086, 0.0331, -0.0191, 0.0478, 0.0592, 0.0808, -0.0262, 0.0170, 0.0705, 0.1338, 0.1281, 0.0867, 0.0321, -0.1262, -0.0418, 0.0733, -0.7747, -0.8864, -0.7514, -0.9537, -1.2177, -0.4500, 0.8335, 0.6735, -0.5544, -0.7201, -0.5461, -0.4822, -0.6983, -0.6261, -0.5608, -0.4627, 0.0654, 0.4479, 0.5906, 0.8867, 0.7468, 0.5932, 0.6630, 0.1745, 0.0737, 0.4775, 0.4406, -0.0178, -0.1737, -0.0100, -0.1011, -1.0244, -0.8767, -0.3750, -0.1550, -0.1330, -0.0994, 0.0536, -0.3954, -0.2941, -0.2651, -0.7550, -0.6597, -0.5912, -0.3462, -0.7503, -0.6482, 0.4516, 0.8434, 0.6531, 0.6363, 0.7092, 0.6980, -0.3609, -0.5531, -0.7862, -1.0167, -0.9590, 0.0863, 1.5623, -0.3817, -0.3013, -0.2498, -0.1305, -0.4599, 0.1828, -0.2631, 0.0113, -0.2723, -0.0387, -0.4720, -0.7448, 1.3092, 2.1128, 3.3545, -0.4164, -0.5593, -0.1547, 0.6507, -0.2370, 0.1304, -0.2405, 0.4128, -1.9770, -1.4570, -0.9525, -0.4499, -0.5895, -0.8098, -0.2369, -0.5213, 0.2876, 0.1027, 0.3710, -0.4635, -0.9714, -1.7011, -1.7630, -0.5882, 0.0095, 0.1951, 0.1612, 0.3832, 0.3979, 0.1705, 0.4849, -0.4317, -0.5877, -1.0045, -1.0898, -1.7281, -0.8949, -0.5581, -0.0670, 0.3301, 0.3015, 0.1183, 0.1456, -0.1616, 0.5610, -1.7302, 1.5954, 1.9037, -0.4906, -0.3247, 0.9576, 0.5011, 0.2745, -0.1238, 0.0272, -0.3685, -0.2772, -0.2176, 0.0507, -1.0274, -0.4474, 2.7540, -1.5710, 0.7647, 0.6072, -0.0973, 0.1938, 0.0314, 0.0138, -0.0033, 0.0160, -0.0370, 0.0224, -0.0443, 0.0158, 0.0067, 0.0124, 0.0160, -0.0317, -0.0486, -0.0407, 0.0499, 0.0353, -0.0026, 0.0021, -0.0049, -0.0488, 0.0244, 0.0448, -0.0165, 0.0152, -0.0006, 0.0018, -0.0234, 0.0284, 0.0127, 0.0057, -0.0071, -0.0464, -0.0086, 0.0314, 0.0489, -0.0199, 0.0451, -0.0127, 0.0501, -0.0364, 0.0377, -0.0178, 0.0128, -0.0461, 0.0240, -0.0344, -0.0324, 0.0416, 0.0005, -0.0149, 0.0367, 0.0219, 0.0522, 0.0317, 0.0245, 0.0513, -0.0473, 0.0349, -0.0591, 0.0346, 0.0245, -1.6078, -1.6519, -1.3352, -1.0631, -1.4354, -1.3558, -0.5819, -0.4283, -0.1201, 0.4851, 1.1745, 1.1895, 0.4298, -0.3702, -1.1723, -2.3418, -1.0258, -0.2948, -0.0056, 0.0709, -0.6169, -1.4720, -1.4669, -1.4478, -1.3367, -0.9135, -1.0379, -1.1181, -2.1863, -3.6674, -0.0735, 0.1449, 0.4445, 0.3488, 0.0017, -0.0602, 0.6297, -1.8833, -0.5645, 0.0331, -0.1850, 0.6806, 0.2002, 0.0027, 0.2523, 0.2830, 0.2287, -0.4227, -0.3287, -0.2819, -0.3319, -0.6029, 2.0705, 1.7767, 0.8446, 1.1420, -0.4994, -0.2205, -0.2079, 0.1055, 1.3206, 1.2731, 0.8339, 1.1976, 1.2337, 1.6749, 0.1435, 1.9306, 1.5792, 1.5013, 1.7387, 1.4962, 1.3823, 1.4132, 1.3298, 0.2390, 0.0571, 0.1122, 0.2628, -0.1958, -0.7304, -0.7168, 0.4880, -0.1875, -0.1010, -0.1145, -0.4392, -0.6561, -1.3268, -1.6492, -0.2014, -0.2256, -0.4977, -0.4575, 0.0419, -1.5656, -0.2275, 1.8915, 2.5481, 0.1988, -0.9024, -0.7450, -0.3913, -0.5541, -0.7556, -0.1855, -0.6922, 0.0533, 0.0507, -0.2410, 0.3011, 1.2990, 0.4283, -1.3349, -2.1197, -0.9978, -0.3693, -0.9414, -0.5886, -0.6848, -1.9588, -1.7019, -2.0407, -1.4254, -2.3793, -1.9048, -0.9665, -0.5536, -0.7443, -0.9181, -1.1757, -1.2499, -1.0990, -1.1170, -1.2875, -0.3548, -0.5517, -0.0878, -0.1715, 0.0615, 1.5939, 1.6352, 1.2986, 0.8426, 0.7933, 0.8755, 0.7702, 1.1628, 1.3018, 1.9028, 0.0395, 0.0312, -0.0405, 0.0354, 0.0497, 0.0002, -0.0334, 0.0226, 0.0260, 0.0233, -0.0362, 0.0318, 0.0115, -0.0084, -0.0258, -0.0311, -0.0293, -0.0495, -0.0389, -0.0542, 0.0273, -0.0243, 0.0163, -0.0012, 0.0392, 0.0540, 0.0240, 0.0512, -0.0447, -0.0093, -0.0014, -0.0568, 0.0978, -0.0246, 0.1406, -0.4153, -0.0729, -0.2038, -0.0416, 0.0020, 0.0343, 0.0410, 0.0066, 0.0715, 0.0402, 0.1288, 0.1716, -0.0412, 0.3005, 0.2518, -0.2803, 0.0982, -0.1209, -0.0296, 0.0376, 0.0149, -0.0134, 0.1060, -0.0281, 0.0260, -0.4458, 0.2788, 0.4238, -1.5957, 2.7535, -1.0379, -1.0780, -1.2170, 0.2373, 0.7478, 0.2469, 0.0749, -0.1413, -0.4867, 0.0875, 0.5257, -0.0959, 0.2519, 1.3304, -0.7721, -2.0730, -0.5906, 1.1066, 0.8694, -0.0528, -0.3584, -0.1490, 0.0922, 0.0568, 0.2488, -0.3056, 0.1352, -0.1024, -0.1559, 0.0161, 0.1877, 0.1778, -1.8605, 0.1347, 0.8313, 0.7597, 0.1988, 0.1858, 0.0753, 0.1964, -0.1669, -0.3558, 0.1701, -0.0130, 0.0651, -0.0772, -1.2367, -0.3070, 1.2479, 1.0962, 0.2178, 0.2071, 0.3368, 0.1744, 0.3082, -0.3249, -1.1566, 1.2845, 0.1159, 0.6248, -0.0217, -0.1005, 0.0402, -0.4637, -0.6649, -0.0346, -0.2422, 0.1107, 0.0616, -0.3113, -0.2761, -2.6929, 1.9839, 0.2042, -0.3162, -0.3608, -0.1742, -0.1585, -0.4341, 0.3795, 0.8903, 0.7604, 0.2291, 0.0613, 0.2090, -0.0145, 0.0535, 0.0559, -0.0513, -0.0082, -0.0208, 0.0286, 0.0027, -0.0233, 0.0470, 0.0318, 0.0126, -0.0199, -0.0323, -0.0200, -0.0134, -0.0124, 0.0067, 0.0442, -0.0385, 0.0140, -0.0009, 0.0234, 0.0324, -0.0303, -0.0115, 0.0444, 0.0348, 0.0289, -0.0085, -0.2021, -0.2236, 0.0422, 0.1768, 0.4198, 0.3899, 0.0804, 0.1598, 0.4125, 0.4990, 0.1677, 0.3243, 0.6713, 1.7008, -3.1826, 0.2846, 0.3341, 0.4163, 0.1842, 0.2466, 0.0708, -0.0299, 0.0074, 0.2062, 0.3376, -0.0016, 0.0432, 0.1467, 0.4431, 1.0336, 0.1102, -0.1464, -0.0414, -0.0757, -0.0371, 0.0164, -0.2330, 0.0247, 0.2550, 0.4297, 0.4586, 0.2067, -0.3641, -0.8385, -0.8187, -0.2568, -0.2510, -0.3430, -0.1744, -0.2784, -0.3390, -0.2716, -0.3907, -0.3704, -0.3395, -0.5350, -0.8464, -0.7164, -0.0497, 0.5354, 0.3999, 0.2107, 0.0278, 0.8755, 0.0645, -0.0750, -0.1275, 0.5497, -1.9727, -0.7000, 0.8508, 0.3688, 1.0022, 1.1949, 1.5676, 1.1587, 0.6066, 0.4490, 0.3932, -0.1488, -0.1091, -0.4190, -0.8678, -0.4296, 3.8551, 2.2739, 1.5535, 1.1685, 1.3980, 1.5849, -2.0536, -1.8798, -1.4209, -1.8582, 1.0631, 1.3862, 0.7719, 0.7234, 0.7521, 0.3413, -0.4178, -0.6250, 0.0343, -0.2063, 0.0895, -2.5577, -1.2945, 0.3295, 0.3775, 1.6537, 0.6339, 0.1499, 0.4392, 0.6383, 0.8521, 0.8677, 0.3361, 0.5168, 0.7320, 0.5486, -0.0201, -0.4419, -0.5816, -0.6022, -0.1944, -0.0305, 0.0156, -0.0581, 0.0322, -0.0851, -0.1403, -0.1862, -0.3130, -0.2420, -0.0959, -0.5822, -0.5411, -0.5708, -0.4618, 0.2227, 0.2059, 0.1899, 0.1441, -0.0214, 0.0110, 0.0722, -0.0221, 0.2038, 0.4536, 0.3555, 0.3573, 0.1397, -0.1608, 0.9398, -1.1720, -0.7418, -1.0754, -2.5205, 0.7284, 0.2595, 0.4651, 0.1843, -0.0834, 0.7718, 0.7036, 2.1517, 1.1837, 0.2300, -0.1498, 2.5683, 1.7418, 0.6127, 0.0404, 1.0845, 0.4403, 0.5101, 1.4601, 0.8556, 1.1975, 1.5492, 1.1407, 0.7339, 0.8055, 0.5319, 0.6545, 1.4600, 2.2652, 1.7042, 0.8495, -0.2943, -0.4921, -0.5827, -0.2044, 0.1122, -0.3851, -0.5224, 0.1405, 0.2080, 0.6725, 0.6314, -0.1041, -0.7847, -1.5888, -1.0682, -1.2942, -0.6765, -0.3719, -0.1591, -0.0497, -0.5889, 0.0861, 0.1489, -0.0011, -0.1217, 0.0817, -0.0057, 0.0585, -0.0491, -0.0775, -0.0998, -0.0172, 0.0720, -0.1030, -0.0895, -0.0535, -0.0671, -0.0980, -0.2776, -0.1861, -0.1190, -0.2348, -0.1056, -0.1520, -0.1357, -0.0101, -0.0048, -0.0626, -0.0901, 0.0241, -0.0072, 0.0083, -0.0127, -0.0079, 0.0008, -0.0363, -0.0299, 0.0331, 0.0185, -0.0064, -0.0246, -0.0083, 0.0245, -0.0135, 0.0350, -0.0432, -0.0266, 0.0115, -0.0460, 0.0328, 0.0241, -0.0395, -0.0212, 0.0210, 0.0324, -0.0131, 0.0124, 0.0471, -0.0068, 0.0437, 0.0310, 0.0973, 0.3407, 0.8467, -0.2305, 0.1222, -1.5055, 2.3725, -0.8196, -0.7411, -0.4862, 0.0121, 0.8776, -0.2648, -0.0637, 0.2106, 0.2172, -0.3341, -0.0539, -0.1929, -0.6853, 2.3197, -1.4456, -1.2395, 0.1529, 0.4090, 0.3075, -0.1586, -0.0694, 0.1722, -0.2334, 2.0287, 1.5901, 1.2188, 1.3338, 0.7425, 0.4946, -0.0475, 0.2565, 0.3806, 0.2865, 0.3520, 0.0252, -0.1471, -0.2825, -0.5815, -2.6351, -2.1117, -1.7565, -1.7174, -1.6638, -1.5701, -1.1442, -0.6321, -0.7404, -0.9725, -1.1940, -1.3524, -1.3765, -1.6172, -2.1744, 0.0139, -0.0145, 0.0215, 0.0452, 0.0176, -0.0420, 0.0208, 0.0052, 0.0013, 0.0219, 0.0216, 0.0223, 0.0009, -0.0132, 0.0529, 0.0224, -0.0538, 0.0319, 0.0156, 0.0503, 0.0132, 0.0351, 0.0180, -0.0130, 0.0340, -0.0485, 0.0059, -0.0475, 0.0273, 0.0049, 0.0036, -0.0487, 0.0276, -0.0304, 0.0064, -0.0476, 0.0327, -0.0066, -0.0521, -0.0179, 0.0468, -0.0091, -0.0261, 0.0082, -0.0182, 0.0312, 0.0293, -0.0359, 0.0323, -0.0174, 0.0361, 0.0266, -0.0322, -0.0270, -0.0181, -0.0146, -0.0357, -0.0221, 0.0429, 0.0440, -0.0230, 0.0202, 0.0367, 0.0398, 0.0201, -0.0250, -0.0191, 0.0181, 0.0278, 0.0199, 0.0226, 0.0171, 0.0287, -0.0280, -0.0107, 0.0196, 0.0084, -0.0460, -0.0219, 0.0067, 0.0409, 0.0093, -0.0598, -0.0135, 0.0004, 0.0121, -0.0114, 0.0219, 0.0193, 0.0200, 0.1248, 0.2969, -0.4188, 0.2652, -1.4075, -0.4550, 1.0571, 2.3790, -1.3736, 0.7435, 0.6724, -0.2752, -0.0751, 0.0119, -0.2532, 0.6492, -0.0885, -0.2961, -0.2944, 2.0890, 1.4377, 1.8124, -1.7312, 1.2273, 1.4366, 1.3999, -0.3689, 0.7819, 0.6323, 0.7287, -1.5551, -1.3849, -1.3314, -1.1548, -1.5523, -1.3242, -1.9282, -1.0545, -1.8855, -1.6885, -1.2965, -1.2411, -1.1263, -1.0972, -1.2909, -0.7606, -0.5951, -0.5814, -0.2957, -0.0586, -0.2213, -0.2995, -0.6954, -0.0225, 1.3652, 1.3592, 1.4889, 1.4921, 1.7466, 2.0736, -0.0600, -0.0193, -0.0172, 0.0085, 0.0996, -0.0242, 0.0611, 0.0514, 0.0393, -0.0164, -0.0278, 0.0670, -0.0219, -0.0358, 0.0278, 0.0529, 0.0527, 0.0096, -0.0181, -0.0057, 0.0470, 0.0051, 0.0548, 0.0137, -0.0242, 0.0285, -0.0217, -0.0325, -0.0043, -0.0246, -0.0473, -0.0319, 0.0301, -0.0336, 0.0362, -0.0223, -0.0061, 0.0402, 0.0067, -0.0086, 0.0193, 0.0502, 0.0441, -0.0364, 0.0081, -0.0099, -0.0170, 0.0471, 0.0032, -0.0534, 0.0290, 0.0392, -0.0435, 0.0060, -0.0432, -0.0290, -0.0567, 0.0255, 0.0519, 0.0152, -0.0352, 0.0181, 0.0239, -0.0283, 0.0445, -0.0275, 0.0162, -0.0435, -0.0210, -0.0182, 0.0581, -0.0219, 0.0211, 0.0222, 0.0387, -0.0063, -0.0144, 0.0174, 0.0348, -0.0441, -0.0249, 0.0341, -0.0437, 0.0264, 0.0088, -0.0291, 0.0417, 0.0264, -0.0329, -0.0290, 0.0052, 0.0514, -0.0016, -0.0116, 0.0460, 0.0289, -0.0510, -0.0385, -0.0515, -0.0093, 0.0010, -0.0396, 0.0232, 0.0022, 0.0475, 0.0218, 0.0258, -0.0250, -0.0144, 0.0049, -0.0330, -0.0184, 0.0024, 0.0351, 0.0187, -0.0517, 0.0270, -0.0053, 0.0359, 0.0135, -0.1852, 0.0036, 0.1540, 1.5408, 1.1069, 0.4668, 0.7482, 0.6380, 0.5968, 0.8425, 0.7956, 0.6580, 0.3697, -0.0493, 0.0248, 0.2905, 0.4275, 0.7572, 1.0539, -0.2074, -0.5134, -0.6438, -0.2581, 0.0149, -0.3411, -0.6189, -0.7790, -0.8332, -0.9384, -0.8461, 0.0685, 0.5178, 0.2650, 0.4847, 0.3497, 0.0454, 0.2738, 1.2872, -0.5020, -1.4811, 0.8133, -0.0699, 0.5891, 0.2867, 1.1279, -0.2394, -0.4297, -0.3997, -0.4167, -0.2109, -0.0478, -0.3151, -0.9300, -1.1257, 4.8846, 2.0567, 0.0697, 1.3522, 0.8084, -0.9914, 0.0062, -0.0183, -0.0160, 0.0339, -0.0006, -0.0356, 0.0103, -0.0291, 0.0368, 0.0381, -0.0439, -0.0136, -0.0311, 0.0175, -0.0076, -0.0321, 0.0205, -0.0532, -0.0356, 0.0127, 0.0214, -0.0093, 0.0457, -0.0191, 0.0472, -0.0497, -0.0261, -0.0010, 0.0045, -0.0329, -0.5210, -0.1839, -0.2391, -0.3518, -0.1038, -0.0847, -0.3123, -0.0658, -0.0697, -0.7453, -0.1774, 0.0415, 0.0904, 0.1152, 0.3196, 0.4085, -0.2002, -0.1687, -0.0570, -0.0346, -0.0667, 0.0527, -0.1092, -0.1154, 1.1672, 1.7194, -0.0067, -0.0138, 0.2748, 0.3205, -0.4254, -1.3176, -1.1122, 1.5718, 0.5914, -0.0340, 0.0747, 0.3016, 0.2161, 0.3495, 0.3556, 0.5070, 0.0935, 0.1835, 0.4885, -1.6731, -2.6345, -1.8687, 1.6651, 0.2335, 0.7896, 0.9309, 0.4240, 0.3481, -0.2523, 0.0547, 0.0280, 0.1293, 0.2334, 0.6017, -0.3794, -0.0937, -0.3665, -0.4914, -0.4396, -0.5601, -0.9126, -0.9974, 0.4999, 0.4097, 0.3777, 0.3233, 0.3221, 0.4964, 0.2812, -0.6067, -0.3168, -0.2801, -0.3125, -0.2739, -0.4329, 0.1861, 1.6122, 0.1435, -0.1983, 0.2054, 0.3808, 0.2924, 0.1954, 0.3523, -1.0585, -1.1868, -1.1780, -0.9565, -1.2792, -1.2042, -1.3129, -0.8213, -0.8891, -0.8520, -0.6540, -0.9349, -1.3520, -1.2876, -1.2746, -2.4730, -2.0692, -1.6242, -1.6714, -1.3608, -0.7883, -0.3638, -0.1511, -0.2845, -0.2881, -0.5350, -0.6297, -0.1263, 0.2272, 0.4669, -0.0952, -0.2603, -0.1355, -1.9191, 0.4196, 1.7871, -0.1732, 0.1396, -0.0018, -0.2529, -0.0968, -0.0781, -0.0820, -0.2578, -0.0619, -0.1326, 0.4263, -1.0520, 0.1573, 2.4993, 1.3038, -0.5536, -0.3936, -0.2960, -0.0444, -0.0562, 0.2472, 0.4638, 0.0827, 0.2067, -0.5108, -0.8107, 0.3069, 0.9978, -0.0146, -0.3083, -0.0178, 0.0058, -0.0008, -0.2773, -1.2183, -1.1120, 1.3801, -0.2443, 0.8618, 1.3818, 1.8785, 1.2887, -0.3820, -0.6173, -0.2433, 0.1349, -0.1617, -0.2361, -0.2732, -0.0182, 2.0895, -2.7262, 0.3483, -0.5499, -0.0062, 0.0319, 0.0477, -0.0402, -0.0008, -0.0257, 0.0247, 0.0266, 0.0093, -0.0300, -0.0392, -0.0046, -0.0349, 0.0419, 0.0422, 0.0517, 0.0180, 0.0395, -0.0230, 0.0208, 0.0408, -0.0198, -0.0170, 0.0197, 0.0068, -0.0450, 0.0012, 0.0002, 0.0274, 0.0127, 1.7854, 1.7475, 1.5539, 1.9905, 1.6081, 0.9987, 1.2812, 1.0786, 1.1974, 1.2794, 1.3381, 1.2486, 1.3463, 1.5155, 1.7963, 2.8199, 1.7997, 1.2756, 0.6035, -0.8978, -0.5451, -0.1339, -0.1251, 0.1807, 0.1913, 0.3064, 0.4287, 0.3837, -0.0747, -0.6651, -0.0439, 0.3144, 0.0242, 0.1636, 0.2549, -2.1166, 2.3123, -0.3995, -1.1534, 2.1401, 0.7468, -0.3526, -0.3067, -0.2627, 0.3515, -0.1189, -0.2155, -0.0781, 0.1955, 0.7748, -0.0903, -2.2406, 2.8416, -2.5522, 0.1803, 1.2225, 0.7401, 0.1151, 0.3980, 0.2431, 0.6629, 0.3269, 0.5384, 0.7574, 1.1041, 1.0791, 0.5114, 0.1700, -0.0109, -0.2848, -0.5442, -0.7250, -0.9216, -0.9211, -1.2198, -1.3598, -0.7868, -0.8596, -0.6573, -0.6623, -1.1450, -1.2154, -0.6931, -0.5886, -0.9851, -1.0247, -0.8777, -1.0640, -1.0102, -1.2139, -0.0086, -0.0373, -0.0315, 0.0159, 0.0399, -0.0401, 0.0056, 0.0385, 0.0430, 0.0116, -0.0496, 0.0176, 0.0185, -0.0446, -0.0283, -0.0009, -0.0254, -0.0003, 0.0335, 0.0381, -0.0216, -0.0361, 0.0433, 0.0092, 0.0018, 0.0355, -0.0087, 0.0399, 0.0393, 0.0356, -1.0913, -0.8919, -1.2486, -1.5479, -0.5395, -1.3703, -1.9996, -1.8301, -0.9700, -0.6193, -0.1923, 0.1444, 0.1708, -0.1018, -0.1768, -0.3985, -1.0721, -0.7065, -0.1904, -0.4711, -0.4454, -0.1266, 2.0129, 1.8221, 1.6997, 1.4617, 1.3662, 1.2389, 1.4608, 1.9332, 0.2192, -0.3107, -0.0455, 0.2976, 0.0504, 0.1650, -0.3690, -0.0188, 0.0068, 0.4402, 3.8663, -2.4851, -1.5974, -2.4724, -1.2782, 0.3462, 0.2601, 0.4938, 0.3063, 0.3566, 0.4538, 0.5371, 0.1549, 0.4356, 1.1219, -1.6660, -1.7444, -0.0915, 1.4450, 3.8272, 0.0172, -0.0480, 0.0353, 0.0096, -0.0023, 0.0317, -0.0132, 0.0420, -0.0468, 0.0538, 0.0492, -0.0087, 0.0396, 0.0332, 0.0345, -0.0226, -0.0265, -0.0349, 0.0306, -0.0206, 0.0083, -0.0403, -0.0118, -0.0297, 0.0289, -0.0196, 0.0494, 0.0136, 0.0337, 0.0116, 1.0800, 1.2494, 0.5509, 0.6149, -0.1340, 0.9934, 1.5358, 0.2491, 0.4759, 0.3847, 0.4747, 0.5574, 0.2904, 0.3149, 0.0938, 0.9116, 0.1101, 0.0707, -0.3228, 0.6753, 1.6828, 1.8897, -0.6651, -0.5754, -0.3888, -0.1662, -0.4941, -0.4428, -0.4396, -0.5287, 0.0031, 0.0210, 0.0372, 0.0316, 0.0040, -0.0039, 0.0249, -0.0266, -0.0323, -0.0412, -0.0006, -0.0191, -0.0463, 0.0007, 0.0121, -0.0116, 0.0502, -0.0497, 0.0125, 0.0050, -0.0228, 0.0090, 0.0203, -0.0188, -0.0177, -0.0211, -0.0365, -0.0056, -0.0562, -0.0180, 0.4625, 0.2846, 0.0431, 0.5252, -0.5478, 0.5161, -2.3712, -0.8774, -0.4605, 0.2450, 0.3796, -0.4727, 0.3947, 0.1951, -0.0907, 0.4533, 0.6277, -0.1027, 0.8262, 0.9105, 3.2256, -0.9209, -0.5840, -1.0264, -0.6026, -0.1279, -0.3438, -0.4846, -0.5200, 0.2347, -0.0148, 0.0496, -0.0393, 0.0410, -0.0110, 0.0560, -0.0028, 0.0116, -0.0287, 0.0370, -0.0040, 0.0259, 0.0165, -0.0424, 0.0205, -0.0294, -0.0110, -0.0021, 0.0517, -0.0387, -0.0359, -0.0153, 0.0203, 0.0454, -0.0034, 0.0452, -0.0301, 0.0392, 0.0512, -0.0409, 0.4968, 0.2136, 0.4120, 1.0118, 0.7415, 0.0946, -0.2353, -0.3271, -0.8694, -0.9207, -0.4371, -0.4680, -0.5004, -0.2863, -0.5831, 0.1310, -0.0320, 0.2109, 0.0909, -0.5878, -0.7665, -0.7702, -0.8041, -0.4593, 0.0342, 0.7306, 0.3808, 0.0825, 0.2113, 0.4666, -0.1844, -0.4482, -0.7333, 0.4765, 1.8309, 1.7315, -1.7903, -1.5872, 0.3413, -0.0536, -0.1071, -0.1922, -0.2985, -0.0392, -0.0008, 0.3051, 0.7801, 0.2225, 1.1466, -0.0096, -2.1962, -1.4932, 0.4274, 0.5907, 0.9255, 0.8865, -0.0869, 0.4070, 0.2034, 0.9125, 0.3999, 0.3424, 0.5685, 0.5609, 1.2324, 1.5376, 0.9437, -0.1464, -1.0810, -1.5947, -1.9439, -1.6912, -1.4961, -1.3570, -1.8330, -0.5640, 0.1218, -0.0533, -0.0934, -0.3346, -0.9739, -2.1604, -1.7337, -1.1300, -1.1503, -0.6669, 0.0657, 0.1246, 0.5008, 0.1688, 0.1488, 0.3445, -0.0269, -0.3144, 0.4537, 2.0526, -2.0883, 3.2416, -1.5452, 0.2329, -1.0819, 0.4439, -0.3069, 0.1311, 0.4044, -0.3725, -0.0342, 0.0425, -0.4363, -0.4317, 0.7300, -1.8125, 1.7274, 1.0505, 1.2294, -0.2647, -0.1086, 0.1549, -0.0091, 0.0530, 0.0387, -0.0419, -0.0195, 0.0418, 0.0183, -0.0314, -0.0012, 0.0345, -0.0479, 0.0230, -0.0255, -0.0019, -0.0037, -0.0189, 0.0379, 0.0480, 0.0173, 0.0200, 0.0049, 0.0509, -0.0055, -0.0476, 0.0335, -0.0021, -0.0064, -0.0230, 0.0500, -0.0079, 0.0501, 0.0162, 0.5537, -0.2355, -1.4160, -1.0971, -0.1756, 2.3508, -0.2711, -0.0923, -0.3924, -0.3214, -0.2276, -0.0079, -0.2827, -0.5573, -0.1209, 0.5108, -0.5017, -0.8733, 0.9382, 3.7833, 0.6160, -0.7368, -0.1827, -0.0266, -0.1943, -0.4676, -0.4554, -0.1387, -0.6174, 0.2958, -0.0291, -0.0912, -0.0219, 1.0189, 0.9281, 0.7370, 0.4061, 0.3613, 0.4053, 0.5529, 0.1504, 0.0960, 0.1843, 0.2702, 0.4833, 0.4186, 0.3546, 0.6213, 0.9223, 0.3107, -0.6808, -0.6849, -0.4788, -0.5032, -0.4557, -0.3304, -0.3416, -0.2075, -0.3469, -0.4387, -0.1669, -0.2086, -0.2209, -0.1770, -0.1805, -0.0715, -0.1978, -0.3181, 0.0202, 0.4349, 0.2166, 0.0624, -0.1619, -0.2126, -0.3928, -0.4175, -0.4008, -0.4490, -0.3645, -0.3105, -0.0818, 0.0734, 0.1391, 0.0145, -0.4179, -0.3643, -0.2667, -0.3361, -0.2594, 0.0014, -0.1128, -0.6358, -0.8628, -0.0366, 1.0719, 1.0962, 0.1147, -0.1423, -0.0582, -0.0040, -0.1542, -0.6209, -0.2951, -0.0966, -0.0369, -0.3179, -0.2176, 0.0407, 0.9633, 1.0166, 0.9601, -0.8774, -0.5486, -0.3179, -0.2189, -0.5204, -0.2477, -0.0199, -0.1323, 0.2816, -0.8416, -0.7810, -0.8305, -0.6575, -0.4307, -0.4746, -0.4083, -0.2250, -0.2882, -0.3920, -0.5099, -0.5138, -0.7195, -0.7578, -0.6643, -0.7842, -0.5519, -0.6586, -0.4451, -0.3110, -0.3744, -0.4043, -0.4660, -0.3956, -0.7122, -0.7421, -0.7465, -0.4914, -0.2254, -0.0170, 0.0206, -0.0430, 0.0413, -0.0141, -0.0037, 0.0200, 0.0493, -0.0389, 0.0055, -0.0382, 0.0003, -0.0273, -0.0068, -0.0259, -0.0093, 0.0213, 0.0161, 0.0416, 0.0379, -0.0186, -0.0459, 0.0291, 0.0160, 0.0437, -0.0090, 0.0078, -0.0043, -0.0073, 0.0157, 0.0488, 0.4725, 0.3622, 1.9368, 1.9834, -4.0186, 1.2666, 0.0137, 0.0481, -0.0852, 0.0892, 0.1172, 0.0585, -0.1592, -0.1866, 0.0937, 0.8014, 0.9727, 0.6759, -1.7753, -1.9289, 1.6556, 0.4891, 0.2298, 0.4163, 0.0778, 0.5628, 0.5907, 0.2382, 0.2896, 0.5039, 0.4779, -0.1040, 0.6518, 0.4431, 0.2032, 0.3683, 2.4056, -0.7480, -1.9984, -2.2794, -1.8986, -0.7504, -0.4879, -0.9646, -0.4702, 0.8952, 1.0730, 0.9989, 0.7479, 0.4112, 0.4209, 0.6204, 3.4816, 2.0576, 0.3984, -0.3019, -0.8568, -0.7022, -0.0786, 0.1561, -0.5716, -0.3921, -0.2376, 0.3490, 0.1626, -0.5061, 0.0904, -1.7947, -0.6284, 0.1641, 0.2497, 0.4284, 0.6145, 0.4557, -0.0119, 0.3886, -0.0769, -0.0279, -0.3786, -0.4348, -0.4643, -0.6136, 0.5142, 2.0687, 1.2434, 0.4733, 0.0360, -0.1283, -0.3937, -0.1394, 0.0091, 0.0219, 0.0329, -0.0486, 0.0495, 0.0540, -0.0527, 0.0012, -0.0223, 0.0449, -0.0347, -0.0071, 0.0124, 0.0192, -0.0088, -0.0314, -0.0255, 0.0384, -0.0516, 0.0157, 0.0438, -0.0118, -0.0161, 0.0308, 0.0167, 0.0255, -0.0500, 0.0457, 0.0131, -0.0173, -0.3626, -0.0462, -0.2684, -0.5472, -0.3576, -0.5097, -0.0891, -0.2340, 0.0712, -0.1534, -1.3565, -0.2446, -0.0731, -0.4719, -0.6419, -0.2566, -0.1783, -0.7070, -0.0369, 0.0592, 0.1216, -0.3902, -0.3506, -0.2144, -0.7385, 1.4656, 1.5477, 1.0921, 0.7336, 0.8992, -0.0308, 0.1721, 0.3828, -0.1218, 0.0480, 0.5214, -1.1791, -0.7554, -0.7923, -0.8520, 0.3598, 1.1210, 0.9320, 0.9550, 0.4446, 0.5007, -0.2379, -0.6543, -0.2964, -0.2564, -0.4675, 1.6534, 1.3447, 1.0255, 1.0113, 0.6470, 0.6007, -0.2044, -0.6968, -0.4329, 0.0527, -0.0001, 0.0217, 0.0463, -0.0314, 0.0521, -0.0162, 0.0210, 0.0294, 0.0323, -0.0453, -0.0160, 0.0438, 0.0454, -0.0206, -0.0535, 0.0100, -0.0448, 0.0287, 0.0368, -0.0180, 0.0380, 0.0268, 0.0436, 0.0451, -0.0314, 0.0108, -0.0361, 0.0486, -0.0510, -0.0314, -0.0304, 0.0336, -0.0488, 0.0291, 0.0370, -0.0475, -0.0461, -0.0226, 0.0249, 0.0315, 0.0137, 0.0337, -0.0374, 0.0025, -0.0198, 0.0215, 0.0423, -0.0459, -0.0119, -0.0144, -0.0008, -0.0253, -0.0249, -0.0315, -0.0323, -0.0029, 0.0508, 0.0367, -0.0158, 0.0533, -0.0040, 0.0266, -0.0147, 0.0150, 0.0504, -0.0264, -0.0138, -0.0253, 0.0066, -0.0075, 0.0424, -0.0329, -0.0455, 0.0006, -0.0124, -0.0254, -0.0019, 0.0404, -0.0296, -0.0252, 0.0417, -0.0107, 0.0414, -0.0077, 0.0128, 0.0024, 0.0110, 0.0040, 0.0205, -0.6635, -0.7154, -0.8148, -0.5733, 0.0082, -0.6412, -0.7158, -0.1910, -0.6199, -1.7107, -0.9507, -0.4740, -0.3455, -0.6416, -1.2343, -0.0550, 0.1376, -0.0597, -0.1665, -0.1036, 0.0493, -0.3566, -0.4567, -0.7845, 0.6682, 1.5952, 1.1738, 1.1442, 1.6809, 2.1056, -0.4076, -0.3883, -0.3293, -0.3546, -0.3035, -0.7550, -1.3066, 0.3443, 0.6890, 0.3900, 0.3218, 0.2642, 0.3111, 0.2952, 0.4349, 0.0068, -0.0834, 0.1543, -0.1911, -0.2559, -0.5889, 0.6846, 1.2369, 0.3332, 0.0290, 0.3121, 0.5223, 0.3873, 0.1826, 0.4248, 0.0344, -0.0298, -0.0431, 0.0289, -0.0219, -0.0176, -0.0252, 0.0143, 0.0499, 0.0317, -0.0130, -0.0434, -0.0040, 0.0098, 0.0018, -0.0110, 0.0293, -0.0398, 0.0382, 0.0142, -0.0013, 0.0058, 0.0355, -0.0000, -0.0000, -0.0083, 0.0496, -0.0222, 0.0008, 0.0346, 0.0415, 0.0378, -0.1554, -0.1748, -0.1477, -0.0975, -0.0919, -0.0260, 0.0149, -0.4975, -0.6450, -0.6709, -0.2330, 0.1539, 0.0723, -0.0385, -0.3356, -0.5309, -0.2330, -0.2740, -0.4088, -0.3632, -0.2316, -0.3228, -0.4768, -0.3787, 0.6039, 0.7452, 0.6150, 0.5238, -0.2056, -0.5020, -0.2450, -0.3656, -0.2132, 0.0715, -0.0119, 0.0189, 0.1184, -0.0243, -0.0132, -0.7463, -1.0771, -0.3454, -0.1207, -0.4724, -0.7124, -0.0528, -0.1179, -0.2377, -0.1484, -0.2567, -0.0759, -0.0689, -0.1164, -0.2607, 0.0406, 1.1086, 0.4027, -0.0658, -0.5047, -1.0420, 1.1533, 0.8554, -2.9412, 0.5259, 0.6944, 0.3486, 0.5639, -1.4253, -0.3664, 0.3840, 0.9995, -0.7190, 0.5068, -0.5435, 0.3667, -0.9444, 2.0288, -0.1224, -2.5680, 0.5412, 0.1520, -0.3562, 0.7884, 0.5571, 0.4783, -0.1928, 0.3128, -0.4738, 0.0001, 0.0312, -0.0533, 0.7904, 1.5697, 1.1448, 0.0336, 0.0225, 0.1612, -0.1616, 0.1627, -0.1261, -0.0798, -0.2342, -0.1638, 0.3941, 0.6292, 0.5441, 0.3783, -0.4563, -0.9656, -0.2184, 0.0008, 0.1844, -0.1234, -0.5323, -0.2171, -0.4511, -0.2895, -0.1639, 1.8862, 1.0619, 1.6173, 0.6584, -0.5148, -0.7880, -0.3698, -0.0078, -0.1400, 0.2860, -0.5490, -0.0483, 0.2126, 0.3102, 0.0493, -2.3348, -1.8579, -1.8113, -2.0621, -2.5316, -1.6629, -0.0498, 0.0263, 0.0103, 0.0176, 1.0641, 0.5158, -0.0013, 0.0208, -0.0639, 0.0024, 0.0120, -0.0335, -0.0564, 0.0315, 0.0068, 0.0323, 0.0016, 0.0307, 0.0893, 0.0476, -0.0195, -0.0345, -0.0094, -0.0056, -0.0008, 0.0239, 0.0511, 0.0302, -0.0264, -0.0027, -0.0032, -0.0369, 0.0355, -0.0802, -0.0491, -0.0211, -0.0336, -0.0272, -0.0992, 0.0164, -0.0378, -0.0475, 0.0821, 0.0432, 0.0175, 0.0461, 0.0396, 0.0272, -0.0083, -0.0282, -0.0077, 0.0315, 0.0152, -0.0285, -0.0020, 0.0226, 0.0508, -0.0156, -0.0665, 0.0197, 0.0018, 0.0037, -0.0685, -0.0350, -0.0409, 0.0192, 0.0280, 0.0040, -0.0161, -0.3168, -0.3028, -0.2176, -0.3799, -0.4148, -0.6907, -1.2683, -0.7791, -0.0476, 0.1786, 0.2158, 0.2418, 0.5796, 0.8634, 0.8017, -0.2188, -0.1593, -0.0454, -0.1041, -0.5220, -0.1625, 0.7198, 1.3505, 0.6679, 0.4647, 0.5505, 0.8348, 0.6957, 0.2854, 0.1779, -0.0047, -0.0948, 0.2224, 0.1471, -0.3342, 0.1571, 0.4987, -0.6542, -0.8863, 1.9349, 2.0708, -1.6053, -1.1320, -0.3369, 0.0037, 0.4442, 0.0651, -0.0067, 0.0725, 0.2996, 0.0190, -0.0221, 0.2527, 1.8826, -0.2437, -2.1281, -0.5559, 0.4101, 0.3988, -0.0459, 0.0812, 0.2059, -0.0083, 0.0521, -0.1380, 0.0096, -0.0001, 0.0878, 0.0663, 0.0284, 0.0290, -0.0219, 0.0003, 0.0252, 0.0237, 0.0849, 0.0034, -0.1650, -0.0252, -0.1343, 0.0020, -0.0298, -0.0594, -0.0209, -0.1214, -0.0208, -0.0308, -0.0884, 0.0342, 0.0722, -0.0217, 0.0333, -0.0451, 0.0372, -0.0049, -0.0516, -0.0461, -0.0298, -0.0534, -0.0354, -0.0518, -0.0385, 0.0027, -0.0271, -0.0201, 0.0366, 0.0293, -0.0315, 0.0401, -0.0155, 0.0309, -0.0403, 0.0050, 0.0131, -0.0053, -0.0249, 0.0035, 0.0013, 0.0276, -0.0227, -0.6341, -0.6552, -1.3476, -0.9061, -0.9739, 1.2138, 1.2181, 0.8891, 0.3294, 0.0584, 0.1747, 0.0820, 0.5271, 0.5058, 0.3096, -0.3721, -0.4549, -0.4602, 0.5177, 1.1972, 0.8289, 0.9340, 0.3692, -0.3602, -0.3258, 0.0784, -0.0666, -0.0556, 0.2580, 0.5495, 0.0301, 0.5824, 1.5228, -0.0604, -0.2062, -0.2899, -0.2725, -0.1761, -0.3997, -0.2878, -0.0676, 0.0573, -0.2072, -0.5568, 0.0684, 3.0395, 2.6044, 1.7755, -0.8601, -0.6041, -0.4767, -0.2785, -0.4972, -0.3011, -0.1504, -0.0544, 0.1058, 0.2051, -0.3763, 0.3216, -0.2360, 0.0476, -0.0553, -0.0841, 0.0008, 0.1220, 0.1151, 0.1117, -0.0000, 0.1514, -0.0772, 0.0249, -0.3248, 2.8491, -1.1156, 1.3148, -0.3395, -0.4687, -0.2099, -0.2450, -0.1343, -0.3002, 0.0385, 0.1216, -0.0408, 0.0596, -0.2611, -0.6502, -0.4542, 0.8916, 1.0250, 0.8292, -0.4244, -0.8948, -0.6296, -0.4689, 0.1279, -0.7297, 1.3743, 0.7333, 0.4748, 0.1115, 0.7508, 0.3623, 0.3293, -1.9077, -1.6505, -1.5056, -0.9244, -0.3343, 0.6129, 0.5486, 0.5725, -1.3196, -0.1225, -0.1627, -0.1639, -0.3347, -0.0349, 0.0259, 0.0056, -0.0086, 0.0542, -0.0099, 0.0199, 0.0005, 0.0372, 0.0485, 0.0316, 0.0053, -0.0424, -0.0258, -0.0457, 0.0089, 0.0208, -0.0079, -0.0095, -0.0094, 0.0316, 0.0316, -0.0419, 0.0018, -0.0367, -0.0474, 0.0321, -0.0294, 0.0030, -0.0430, -0.0318, 0.0358, 0.0101, 0.0033, -0.0097, 0.0285, -0.0183, 0.0035, 0.0199, 0.0274, 0.0479, -0.0271, -0.0269, 0.0008, -0.0447, -0.0244, -0.0535, -0.0209, -0.0112, -0.0278, 0.0120, -0.0260, 0.0057, 0.0227, -0.0180, -0.0118, 0.0526, 0.0381, -0.0224, 0.0042, 0.0075, -0.0262, -0.0413, 0.0260, 0.0426, -0.0455, 0.0288, -0.0231, -0.0027, -0.0054, 0.0384, 0.0251, -0.0425, 0.0222, 0.0525, 0.0114, -0.0243, -0.0359, -0.0196, -0.0479, -0.0322, -0.0069, -0.0490, 0.0402, 0.0099, 0.0076, -0.0419, 0.0158, 0.0428, -0.0005, -0.0212, 0.0284, 0.9373, 1.1135, 0.9955, 1.0922, 0.9180, 1.8315, 0.5062, 1.0133, 1.3374, 0.2557, 1.2548, 0.8816, 0.8197, 0.7957, 0.9997, 2.9681, 2.1937, 2.2484, 1.9564, 2.1764, 3.0400, -0.6905, -0.3411, -0.3516, -0.4122, -0.0138, -0.1942, -0.1907, -0.5339, -0.6499, 1.0628, 1.0540, -2.1588, 1.2380, 1.6948, 0.9165, -0.5681, -0.6770, -0.1215, 0.0479, -0.4374, -0.5345, -0.3429, -0.4949, -0.3353, 0.5481, 0.9973, 0.8857, 0.4935, 2.0158, -2.3470, 0.1496, 0.1986, 0.1874, 0.2631, 0.4757, 0.2338, 0.1413, 0.0003, 0.4083, -0.2295, -0.0847, 0.2734, -0.2187, -0.2239, -0.7202, -0.3294, -0.2407, -0.1181, -0.0741, 0.1112, 0.0876, 0.0478, 0.0283, 0.9747, 1.8531, 2.3323, 1.3234, 1.4082, -0.9706, -0.3762, -0.2843, -0.3897, -0.4694, -0.5044, -0.2423, -0.5728, -0.5627, -0.2644, -0.0830, -0.2224, -0.2703, -0.5422, -0.3565, -0.6787, -0.6857, -0.7576, -0.4910, 0.3882, -0.2844, -0.4576, -0.2632, -0.4329, -0.3650, -0.1936, -1.1817, -1.1584, -0.9007, -0.6032, -0.5821, 0.3027, 0.3929, 0.2565, -0.3667, 0.0067, -0.1131, -0.3814, 0.0490, 0.3058, 0.3148};
#endif

#endif