//Numpy array shape [3, 3, 8, 16]
//Min -0.505842626095
//Max 0.516019403934
//Number of zeros 0

#ifndef W8_H_
#define W8_H_
#include "ap_fixed.h"
typedef ap_fixed<16,6> model_weightdefault_t;

#ifndef __SYNTHESIS__
model_weightdefault_t w8[1152];
#else
model_weightdefault_t w8[1152] = {0.0835, -0.1487, -0.0512, 0.0700, 0.0860, 0.0360, -0.2686, -0.0968, -0.1003, 0.1229, 0.0260, -0.0332, 0.0726, -0.2161, 0.2001, -0.0039, -0.1602, 0.2596, -0.0921, -0.0992, 0.1905, 0.0037, -0.0187, 0.1231, 0.1606, -0.0245, 0.1094, -0.0888, 0.2943, 0.1349, -0.1694, -0.0789, -0.0178, 0.1261, 0.2241, -0.0402, 0.3613, 0.1432, -0.0839, 0.0416, 0.0539, 0.2001, 0.2198, -0.0305, 0.3041, 0.2186, 0.1230, 0.0150, 0.1454, 0.0219, 0.0670, 0.0066, -0.0048, -0.0147, 0.1225, 0.0287, 0.1883, -0.0061, 0.0127, -0.0748, -0.1797, -0.1723, 0.1572, -0.1358, 0.0879, -0.1817, -0.0937, -0.0488, -0.2774, -0.2458, -0.1501, -0.1478, 0.0318, 0.0158, -0.1941, 0.2232, 0.0141, 0.0905, -0.1854, -0.1454, 0.0036, -0.3691, -0.2661, 0.1165, 0.3193, 0.1989, -0.1787, -0.0417, 0.1391, -0.2293, 0.0571, 0.0312, 0.0881, 0.0107, -0.3319, -0.0897, 0.1923, -0.1135, -0.1419, 0.2040, 0.3636, 0.0733, -0.0628, 0.1638, 0.2331, -0.1985, 0.1104, 0.2185, 0.1951, -0.0317, 0.1201, -0.0465, 0.1670, -0.2379, 0.1157, 0.1713, -0.1606, -0.0397, -0.1544, -0.0843, 0.2478, 0.0432, 0.1511, -0.1599, 0.0609, 0.0789, -0.0352, 0.1984, 0.0131, 0.0200, 0.0768, -0.2022, -0.0532, 0.0841, -0.0773, -0.0861, 0.0567, -0.3208, -0.0896, 0.0394, -0.2819, -0.2539, -0.1829, -0.0954, 0.1251, -0.1679, 0.1767, 0.1665, 0.3094, 0.2531, 0.0396, 0.2119, -0.0856, -0.0147, -0.0223, -0.1929, 0.1724, 0.0900, -0.0548, -0.0239, -0.1042, -0.0704, -0.1373, -0.2022, 0.1580, -0.0348, -0.0217, -0.0880, 0.1917, 0.0183, -0.1271, -0.1899, 0.0126, -0.1409, -0.0393, 0.0774, 0.1959, 0.1505, 0.0798, -0.2196, 0.0409, -0.1535, -0.0256, -0.1625, 0.0557, 0.1671, 0.0052, 0.1990, -0.1388, -0.2495, -0.2465, -0.0555, 0.1333, 0.2567, -0.1439, 0.1239, -0.0818, -0.1019, 0.1762, 0.0058, 0.0105, -0.0629, 0.2104, -0.0383, -0.0979, -0.0226, -0.2420, -0.0306, 0.1591, 0.1308, 0.2150, 0.3475, 0.1195, -0.0346, 0.1824, 0.0756, 0.1758, 0.3105, 0.0955, -0.0970, -0.0289, 0.0736, 0.2010, 0.0244, 0.0087, -0.0717, -0.0288, 0.0980, 0.1393, -0.0726, 0.2523, 0.1993, 0.2327, 0.0996, -0.1726, 0.2359, 0.1825, -0.1227, -0.0900, 0.1575, -0.0085, 0.3363, 0.1297, -0.1845, 0.1203, -0.0951, 0.2201, -0.0148, -0.2219, 0.2331, 0.0955, -0.0763, 0.1326, 0.1179, 0.0738, 0.0593, -0.0681, 0.1072, 0.2766, 0.1029, 0.3424, 0.0976, -0.1959, 0.1953, 0.1269, 0.1181, 0.2019, -0.1595, 0.1103, -0.1935, -0.0230, -0.0304, 0.0926, 0.1853, 0.1342, -0.1144, -0.0489, -0.1740, -0.0021, -0.0325, 0.0316, 0.1843, -0.0352, -0.0751, -0.2092, -0.1744, -0.0750, -0.0248, -0.1820, -0.0006, 0.0568, -0.0957, -0.0488, 0.0414, -0.1030, -0.2760, -0.1522, 0.1006, 0.1662, 0.0313, -0.2545, -0.0888, 0.0072, -0.0216, -0.0253, 0.1222, 0.2391, 0.0130, 0.1036, 0.0982, 0.2270, 0.2422, -0.0761, -0.0011, -0.0100, 0.0970, 0.0828, 0.0482, -0.1214, -0.0845, 0.1268, 0.0040, 0.1293, 0.0511, 0.2789, 0.0499, 0.2515, 0.0143, 0.1347, 0.1069, -0.1147, -0.1954, 0.1163, 0.2718, 0.2791, 0.0654, 0.0293, -0.1717, -0.1103, -0.1511, -0.0674, -0.0130, -0.2294, -0.1044, 0.1196, -0.1481, -0.1928, 0.1848, -0.0326, -0.0259, 0.0003, 0.0720, -0.2030, -0.2449, -0.1758, 0.0606, 0.2250, 0.0395, 0.1433, 0.3681, -0.0094, 0.0302, -0.0633, -0.1795, 0.1015, 0.0428, -0.1316, -0.0665, 0.0471, -0.1925, -0.0402, -0.0343, -0.0986, -0.1424, 0.0601, -0.0900, 0.0571, 0.0737, -0.1101, -0.1152, -0.1580, -0.0802, -0.0750, 0.0941, 0.0121, 0.0006, -0.0442, -0.0186, -0.0788, -0.0615, 0.0841, -0.0773, 0.0944, 0.1037, -0.0097, -0.0661, 0.1081, 0.0747, 0.0414, 0.1334, -0.1573, 0.0831, 0.0622, 0.0453, 0.1239, -0.0302, -0.1299, -0.1400, -0.1344, -0.1175, 0.0096, -0.1390, -0.1093, 0.0501, 0.0433, -0.1521, -0.1338, 0.1318, -0.0721, -0.0955, -0.0914, -0.1676, -0.0908, -0.1421, -0.1691, 0.0535, 0.0580, 0.0951, -0.0469, -0.1356, -0.1637, -0.0821, 0.1578, -0.1525, 0.2051, 0.2296, -0.0186, 0.2397, 0.0213, -0.1711, -0.0216, -0.1626, 0.0073, 0.2570, -0.1306, -0.0661, -0.1670, -0.0814, -0.2126, -0.1615, -0.0990, -0.3227, -0.0462, 0.1513, -0.1358, 0.0805, 0.0043, -0.0912, 0.1186, 0.1341, -0.0227, -0.0131, -0.1107, -0.0091, 0.2428, -0.1824, -0.1545, -0.0265, -0.0142, -0.1217, -0.0614, 0.0006, -0.2377, -0.0024, 0.2530, -0.1447, 0.1677, -0.1251, -0.0534, -0.0772, 0.1813, -0.2003, -0.2252, 0.2749, -0.2563, -0.1417, 0.1791, 0.0511, 0.2577, 0.0793, 0.0072, 0.0133, 0.2774, -0.0535, 0.0978, -0.1200, 0.0825, 0.1369, 0.2830, -0.1842, 0.2886, 0.0838, 0.2839, 0.1034, 0.1403, 0.3057, -0.0498, 0.1355, -0.1654, -0.1270, 0.1647, 0.1069, 0.1540, 0.0223, -0.1889, 0.1345, -0.0015, 0.3076, 0.0548, 0.0937, 0.2613, -0.0884, 0.0288, 0.2063, -0.0495, 0.1077, -0.0960, 0.1562, -0.1610, -0.2653, 0.0116, -0.0738, 0.0836, -0.0113, -0.2245, -0.0234, -0.1870, -0.0746, -0.0912, -0.0377, -0.0567, -0.0213, -0.1346, 0.0194, -0.0195, 0.1532, 0.1580, -0.0853, -0.0811, -0.0840, -0.0238, 0.1805, -0.0504, 0.1332, 0.1331, -0.1550, 0.0891, 0.0243, 0.0352, -0.0357, -0.1805, 0.4281, 0.0047, -0.3524, 0.0438, 0.1003, 0.1460, -0.0758, 0.1587, 0.1531, -0.1195, -0.1933, -0.1184, -0.0066, 0.0950, 0.2837, 0.1833, -0.0729, -0.1591, 0.1807, -0.1717, -0.0978, 0.0610, 0.0651, 0.0918, 0.0168, 0.0470, 0.0950, -0.0285, 0.3097, 0.1987, 0.1910, 0.1816, 0.0638, 0.1507, 0.1498, 0.3729, 0.3987, -0.0745, 0.2911, -0.0973, -0.1958, -0.0783, 0.0746, 0.0264, -0.0695, -0.0132, 0.0825, 0.0302, 0.0134, 0.2282, -0.0984, 0.1385, 0.0642, 0.0261, 0.0987, 0.2099, -0.2972, 0.0011, -0.0288, -0.0557, -0.1361, -0.2301, -0.2969, 0.1289, -0.0068, 0.2131, 0.0011, 0.1103, -0.0571, 0.0326, -0.0459, -0.0026, -0.0948, -0.1307, -0.2188, -0.2755, -0.2826, 0.1335, -0.4613, -0.0047, -0.5058, -0.2247, -0.0242, -0.3971, -0.0433, -0.4136, -0.2151, -0.0892, -0.1432, 0.0910, -0.1122, -0.1115, -0.1767, -0.1556, 0.0844, -0.0645, 0.0584, 0.1003, -0.0289, 0.0262, -0.1391, 0.0542, -0.0930, -0.0645, 0.1481, 0.1160, 0.0230, 0.1502, 0.0396, -0.0672, -0.0632, -0.1339, -0.0031, 0.0421, 0.0595, 0.0020, -0.1217, -0.1750, 0.0832, 0.0261, -0.1143, 0.1159, 0.0862, 0.0189, 0.1020, -0.0090, 0.1522, -0.1154, 0.0108, 0.0836, -0.0828, 0.0302, -0.1744, -0.1389, -0.0420, -0.1639, 0.0168, 0.0800, -0.1432, -0.0775, -0.1699, 0.0356, 0.0216, -0.0762, 0.0782, 0.0803, -0.1130, -0.1502, 0.0249, 0.0847, 0.0024, 0.1459, -0.0112, 0.1095, -0.0837, -0.0509, -0.1427, -0.0908, -0.0649, -0.0283, 0.1919, 0.1832, 0.3001, 0.1307, 0.1942, 0.0357, 0.2075, 0.1199, 0.2799, 0.0992, -0.0535, 0.0776, -0.0053, 0.3452, 0.2997, 0.0591, 0.2435, -0.0452, 0.0963, 0.0182, -0.0749, 0.1554, 0.1098, 0.0994, 0.1803, -0.1705, 0.1055, -0.0252, 0.1631, 0.2562, 0.3152, -0.0534, 0.1682, -0.0650, -0.1705, 0.0636, 0.1860, 0.2402, 0.1985, -0.0435, 0.0818, 0.0455, -0.0814, -0.0958, 0.3000, -0.0318, 0.0674, -0.2752, -0.1163, -0.1617, -0.2593, 0.0327, -0.3021, 0.0038, -0.0222, -0.1161, 0.0618, 0.0174, 0.1481, 0.0107, -0.0709, -0.0562, -0.0510, -0.0454, 0.0623, -0.1099, 0.0736, -0.1570, -0.0834, 0.0316, -0.2670, -0.1434, 0.1045, -0.0929, -0.0428, -0.3402, -0.1177, 0.1255, 0.1741, 0.1382, 0.0270, 0.0543, 0.0419, -0.2824, -0.1326, 0.1296, 0.0715, 0.0987, -0.0046, -0.2254, 0.0980, -0.1904, -0.0072, 0.0472, 0.0501, -0.0139, 0.1584, 0.1730, -0.0446, 0.1923, 0.0800, 0.1111, 0.1124, -0.1087, 0.3093, 0.0943, 0.1022, 0.1211, -0.1013, 0.2640, 0.2574, -0.0847, 0.3423, 0.0959, 0.1661, 0.3045, -0.0338, 0.0328, 0.0873, -0.0641, 0.3237, 0.0707, -0.0831, -0.0848, 0.0644, 0.2140, 0.1053, 0.2189, 0.3488, -0.0259, -0.1267, 0.2068, -0.1512, -0.0084, 0.1292, -0.0882, 0.1264, 0.0657, 0.1300, -0.0794, -0.0971, 0.0237, -0.0342, 0.0208, 0.2133, 0.0095, 0.0455, -0.2946, -0.3244, 0.0205, -0.1320, -0.0302, 0.1897, 0.2199, -0.2237, -0.2210, -0.1977, 0.1342, -0.2685, 0.0078, 0.1493, 0.0877, 0.0026, -0.0992, 0.1890, -0.0128, -0.0448, 0.1030, -0.0531, -0.1027, 0.3201, -0.2375, 0.0984, -0.1631, -0.3424, -0.1123, 0.0050, -0.2078, 0.0812, -0.3033, -0.0058, 0.0780, -0.0744, -0.1641, -0.0264, -0.0077, 0.0056, -0.0612, -0.0292, 0.0978, 0.1002, 0.2158, -0.1183, -0.1020, 0.2234, -0.2065, 0.2759, -0.0311, 0.2717, 0.1606, 0.0333, -0.1659, 0.2461, 0.1867, 0.2409, 0.0669, 0.2158, -0.1644, 0.0734, -0.0590, -0.1471, 0.0493, 0.2089, 0.2729, 0.2312, 0.1227, -0.0464, 0.0145, -0.0273, -0.1434, 0.0496, 0.2027, 0.1530, -0.1507, -0.1615, 0.0547, -0.0156, 0.1268, -0.0392, -0.1112, 0.0755, 0.0056, 0.0300, 0.0983, 0.2066, -0.2875, 0.0126, 0.0805, -0.2272, 0.0407, -0.0396, -0.0514, -0.1505, -0.0430, 0.0138, 0.1347, -0.0969, 0.0499, -0.1478, -0.0886, 0.0094, -0.1839, 0.1809, -0.0415, -0.1835, -0.0210, 0.1017, 0.0851, 0.0695, -0.4572, 0.0126, 0.3321, 0.0585, 0.0610, -0.0985, -0.1271, 0.3280, -0.1881, 0.0250, -0.0853, -0.1957, 0.1445, -0.0173, 0.1539, 0.0183, -0.1471, 0.2606, 0.0671, -0.0041, -0.1322, -0.0507, 0.1226, -0.1218, 0.0223, 0.0836, 0.3062, 0.4562, -0.1333, 0.0682, -0.1480, -0.1119, -0.0275, -0.1334, 0.0211, -0.1579, -0.0583, 0.0016, -0.1008, -0.0328, 0.2249, -0.1780, 0.0747, -0.0433, -0.1756, 0.3715, -0.1671, -0.0207, -0.1093, 0.0970, 0.0191, 0.4422, -0.0186, -0.1489, 0.0344, 0.0237, 0.3991, 0.0018, 0.0302, 0.1774, 0.1268, -0.0198, -0.0735, -0.1956, 0.5160, 0.1963, -0.0433, 0.2357, 0.1541, 0.2345, 0.0792, -0.1506, 0.2616, 0.1990, 0.0859, 0.4097, -0.0395, 0.0182, 0.1820, -0.0964, 0.3648, 0.1328, -0.0335, -0.1001, 0.0435, 0.2011, 0.2141, -0.3561, 0.1423, 0.0129, 0.1131, 0.1024, -0.1533, 0.1163, -0.0522, -0.0088, 0.0802, -0.0401, -0.1840, 0.0070, 0.2360, 0.0243, -0.0308, 0.0849, 0.2877, 0.1748, 0.1253, 0.1960, -0.0342, 0.0935, 0.1618, 0.0412, -0.3711, 0.0259, 0.3920, 0.2766, 0.3086, -0.0543, 0.0884, 0.0802, -0.1465, 0.0427, 0.0668, 0.1437, -0.0467, 0.1929, 0.2077, -0.2450, 0.2623, 0.2191, -0.0899, 0.4090, -0.0712, 0.1525, 0.0046, 0.0161, -0.0556, -0.2884, 0.1515, -0.1576, -0.2297, -0.2427, -0.2701, -0.1891, -0.3365, -0.1931, 0.0192, -0.1571, -0.0785, 0.1526, 0.1177, -0.0806, 0.1420, -0.0865, 0.0716, -0.1569, 0.1084, -0.0195, -0.2049, -0.1591, 0.2526, -0.1060, -0.0211, -0.0875, -0.1228, -0.0917, 0.1205, -0.1370, 0.0005, -0.1080, -0.2149, -0.1934};
#endif

#endif