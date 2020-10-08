#include "ap_fixed.h"
#include <parameters.h>

//how many consecutive sets of inputs to run over per kernel execution
#define COMPRESSION 32
#define STREAMSIZE 2
#define BIGSTREAMSIZE_IN  72
#define BIGSTREAMSIZE_OUT 73

#define IN_STREAM_LEN  9
#define OUT_STREAM_LEN 9


#define DATA_SIZE_IN  (N_FILT_36-1)
#define DATA_SIZE_OUT N_FILT_40

typedef ap_fixed<16,6> data_t;
typedef ap_uint<512>    bigdata_t;

#define NW1 147456
#define NW2 294912
#define NW3 589824
//#define NW4 589824

