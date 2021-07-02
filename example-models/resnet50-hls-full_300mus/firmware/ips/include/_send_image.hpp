#ifndef _SEND_IMAGE
#define _SEND_IMAGE

#include <iostream>

#include "../../parameters.h"


void _send_image ( 
                                           hls::stream<ap_uint<8> > input[4], 
                                           hls::stream<ap_uint<8> > output[N_OUTPUT] 
        ){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis both port=input
#pragma HLS INTERFACE axis both port=output

#pragma HLS DATAFLOW
    if(!input[0].empty()){
        input[0].read();
    }

    static int flit_index = 0;

    for(int pixel_index = 0; pixel_index<N_INPUT_3_1*N_INPUT_2_1; pixel_index++){
        
        
        for(int i=0; i<N_OUTPUT; i++){
            ap_uint <8> data;
            if(i==0){
                if(pixel_index==0){
                    data.range() = 0;
                }
                else{
                    data.range() = 1;
                }
            }
            else{
                if(pixel_index >= 0 && pixel_index <=31){
                    if(i==1){
                        data.range() = 0x09;
                    }
                    else if(i == 2){
                        data.range() = 0x01;
                    }
                    else if(i == 3){
                        data.range() = 0x02;
                    }
                }
                else{
                   data.range() = 0x01;
                }
            }
            output[i].write(data);
        }
        if(pixel_index%8 == 0){
            flit_index+=1;
        }

    }

}

#endif
