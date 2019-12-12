//Numpy array shape [28]
//Min 0.000000000000
//Max 0.000000000000
//Number of zeros 28

#ifndef B50_H_
#define B50_H_

#ifndef __SYNTHESIS__
bias50_t b50[28];
#else
bias50_t b50[28] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

#endif
