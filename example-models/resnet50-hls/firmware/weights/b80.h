//Numpy array shape [28]
//Min 0.000000000000
//Max 0.000000000000
//Number of zeros 28

#ifndef B80_H_
#define B80_H_

#ifndef __SYNTHESIS__
bias80_t b80[28];
#else
bias80_t b80[28] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

#endif
