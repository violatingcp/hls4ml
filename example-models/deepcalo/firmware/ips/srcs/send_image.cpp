#include <iostream>


#include "_send_image.hpp"

void send_image ( 
                                           hls::stream<ap_uint<8> > input[4], 
                                           hls::stream<ap_uint<8> > output[N_OUTPUT],

        ){

//#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output


    _send_image(input, output);    


}
