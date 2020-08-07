#include "ap_fixed.h"
#include <parameters.h>

//how many consecutive sets of inputs to run over per kernel execution
#define COMPRESSION 32
#define STREAMSIZE 10
#define BIGSTREAMSIZE_IN 97 //96.25
#define BIGSTREAMSIZE_OUT 1 //50.53125

//in : 56*11*5 = 3080
//out: 7*7*33  = 1617
//out: 1*1*2  = 2

#define IN_STREAM_LEN (N_INPUT_1_1*N_INPUT_2_1)
#define OUT_STREAM_LEN 1
#define DATA_SIZE_IN N_INPUT_3_1
#define DATA_SIZE_OUT N_LAYER_52

typedef ap_fixed<16,6> data_t;
typedef ap_uint<512>    bigdata_t;

#define NW1 147456
#define NW2 294912
#define NW3 589824
#define NW4 589824

