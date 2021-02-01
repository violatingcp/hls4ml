#ifndef _GALAPAGOS_RESNET_BRIDGE
#define _GALAPAGOS_RESNET_BRIDGE

#include "packet_size.h"
#ifdef CPU
#include "galapagos_interface.hpp"
#else
#include "galapagos_packet.h"
#endif

template <class INPUT_T>
void _hls4ml_galapagos_input_bridge_write_words_4(
                                   galapagos_packet gp_in,
                                   int offset,
                                   hls::stream<INPUT_T >  input[4])

{

    INPUT_T data;
    //std::cout << "GP_IN=" <<  std::hex << gp_in.data.range() << std::dec << std::endl;
    for(int j=0; j<4; j++){
#pragma HLS pipeline II=1 
        data.range() = gp_in.data((j)*8 + offset + 7, (j)*8 + offset );
        
        //DEBUGGING PURPOSES, REWRITING CHANNEL 1 OF EACH PIXEL TO REPRESENT WHICH PIXEL IT IS IN FLIT
        //if(j == 1){
        //    data = (offset - 32)/32;
        ////    //std::cout << "INPUT_SIZE " << std::dec << "[" << j << "]:" << input[j].size() << std::endl;
        //}
        //std::cout << "INPUT_DATA[" << std::dec << j << "]=" << std::hex << data << std::endl;
        input[j].write(data.range());
    }        
}


template <int width, class INPUT_T>
void _hls4ml_galapagos_input_bridge(galapagos_interface * bridge_in,
                                   hls::stream<INPUT_T > input[width]//,
                                   //hls::stream<ap_uint<32> > pixel_index_stream[1]
                                   )
{
//cases 64 - 2048, loop explicitly rolled out to help hls, else non constant loop index gives poor result
    //static int pixel_index = 0;
    
    
    int jj=0;
    if (width == 4){
        ap_uint<32> size;
        //std::cout << "IN INPUT BRIDGE 4" << std::endl;
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        size.range() = gp_in.data.range(31,0);
        for(int i=0;i<size;i++){
            int offset = 32 + i * 4 * 8;
            _hls4ml_galapagos_input_bridge_write_words_4<INPUT_T>(gp_in, offset, input);
        }
    }
    else if (width == 65){
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((j)*8 + 7, (j)*8);
            input[j].write(data);
        }
        gp_in = bridge_in->read();
        INPUT_T data;
        data.range() = gp_in.data.range(7,0);
        input[64].write(data);

    }
    else if(width == 129){
        
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((j)*8 + 7, (j)*8);
            input[j].write(data);
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=64; j<128; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        INPUT_T data;
        data.range() = gp_in.data.range(7,0);
        input[128].write(data);

    }
    else if(width == 257){
        
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((j)*8 + 7, (j)*8);
            input[j].write(data);
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=64; j<128; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=128; j<192; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=192; j<256; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        INPUT_T data;
        data.range() = gp_in.data.range(7,0);
        input[256].write(data);

    }
    else if(width == 513){
        
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((j)*8 + 7, (j)*8);
            input[j].write(data);
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=64; j<128; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=128; j<192; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=192; j<256; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=256; j<320; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=320; j<384; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=384; j<448; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=448; j<512; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        
        
        INPUT_T data;
        data.range() = gp_in.data.range(7,0);
        input[512].write(data);

    }
    else if(width == 1025){
        
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((j)*8 + 7, (j)*8);
            input[j].write(data);
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=64; j<128; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=128; j<192; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=192; j<256; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=256; j<320; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=320; j<384; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=384; j<448; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=448; j<512; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=512; j<576; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=576; j<640; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=640; j<704; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=704; j<768; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=768; j<832; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=832; j<896; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=896; j<960; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=960; j<1024; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        INPUT_T data;
        data.range() = gp_in.data.range(7,0);
        input[1024].write(data);

    }
    
    else if(width == 2049){
        
        galapagos_packet gp_in;
        gp_in = bridge_in->read();
        
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((j)*8 + 7, (j)*8);
            input[j].write(data);
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=64; j<128; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        jj=0;
        for(int j=128; j<192; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=192; j<256; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=256; j<320; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=320; j<384; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=384; j<448; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=448; j<512; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=512; j<576; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=576; j<640; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=640; j<704; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=704; j<768; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=768; j<832; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=832; j<896; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=896; j<960; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=960; j<1024; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1024; j<1088; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1088; j<1152; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1152; j<1216; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1216; j<1280; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1280; j<1344; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1344; j<1408; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1408; j<1472; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1472; j<1536; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1536; j<1600; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1600; j<1664; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        jj=0;
        for(int j=1664; j<1728; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1728; j<1792; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1792; j<1856; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1856; j<1920; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1920; j<1984; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        jj=0;
        for(int j=1984; j<2048; j++){
#pragma HLS pipeline II=1 
            INPUT_T data;
            data.range() = gp_in.data.range((jj)*8 + 7, (jj)*8);
            input[j].write(data);
            jj++;
        }
        gp_in = bridge_in->read();
        
        
        INPUT_T data;
        data.range() = gp_in.data.range(7,0);
        input[2048].write(data);

    }


    //pixel_index+=size;
    //ap_uint<32> data;
    //data.range() = pixel_index;
    //pixel_index_stream[0].write(data);

}
                                   
template <class OUTPUT_T>
void _hls4ml_galapagos_output_bridge_read_words_4(
                                   galapagos_packet  & gp_out,
                                   int offset,
                                   hls::stream<OUTPUT_T >  output[4])
{


    OUTPUT_T data;

    for(int j=0; j<4; j++){
#pragma HLS pipeline II=1 
        data.range() = output[j].read();
        gp_out.data.range((j*8) + offset + 7, (j*8) + offset) = data.range(); 
        //std::cout << "OUTPUT_DATA[" << j << "]=" << data.range() << std::endl;
    }        
}


template <class OUTPUT_T>
void _hls4ml_galapagos_output_bridge_read_words_65(
                                   galapagos_packet  & gp_out,
                                   hls::stream<OUTPUT_T >  output[65],
                                   galapagos_interface * out
                                   )
{

    for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
        if(!output[j].empty()){
            OUTPUT_T data;
            data.range() = output[j].read().range();
            gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
        }
    }
}


template<int width, class OUTPUT_T>
void _hls4ml_galapagos_output_bridge (
                                    ap_uint<32> size,
                                    hls::stream<OUTPUT_T > output[width],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

    int jj;
    if(width == 4){
        galapagos_packet gp_out;
        gp_out.data.range(31,0) = size;
        gp_out.data = gp_out.data & 0x0ffff;
        for(int i=0; i<size; i++){
#pragma HLS pipeline II=1 
            int offset = 32 + i*4*8;
            _hls4ml_galapagos_output_bridge_read_words_4<OUTPUT_T>(gp_out, offset, output);
        }
//        std::cout << "GP_OUT " << std::hex << gp_out.data << std::dec << std::endl; 
        gp_out.dest = dest;
        gp_out.last = 1;
        gp_out.user =  1;
        bridge_output->write(gp_out);
    }
    else if(width == 65){
        galapagos_packet gp_out;
        gp_out.last = 0;
        gp_out.dest = dest;
        gp_out.user = 2;
        for(int j=0; j<64; j++){
#pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
            }
        }
        bridge_output->write(gp_out);
        gp_out.last = 1;
        OUTPUT_T data;
        data.range() = output[64].read().range();
        gp_out.data.range(7, 0) = data.range();
        bridge_output->write(gp_out);
    }
    else if(width == 129){
        galapagos_packet gp_out;
        gp_out.last = 0;
        gp_out.dest = dest;
        gp_out.user = 3;
        for(int j=0; j<64; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
            }
        }
        bridge_output->write(gp_out);
        jj=0;
        for(int j=64; j<128; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        gp_out.last = 1;
        OUTPUT_T data;
        data.range() = output[129].read().range();
        gp_out.data.range(7, 0) = data.range();
        bridge_output->write(gp_out);
    }
    else if(width == 257){
        galapagos_packet gp_out;
        gp_out.last = 0;
        gp_out.dest = dest;
        gp_out.user = 5;
        for(int j=0; j<64; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
            }
        }
        bridge_output->write(gp_out);
        jj=0;
        for(int j=64; j<128; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=128; j<192; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=192; j<256; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        gp_out.last = 1;
        OUTPUT_T data;
        data.range() = output[256].read().range();
        gp_out.data.range(7, 0) = data.range();
        bridge_output->write(gp_out);
    }
    else if(width == 513){
        galapagos_packet gp_out;
        gp_out.last = 0;
        gp_out.dest = dest;
        gp_out.user = 5;
        for(int j=0; j<64; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
            }
        }
        bridge_output->write(gp_out);
        jj=0;
        for(int j=64; j<128; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=128; j<192; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=192; j<256; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=256; j<320; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=320; j<384; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=384; j<448; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=448; j<512; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        gp_out.last = 1;
        OUTPUT_T data;
        data.range() = output[512].read().range();
        gp_out.data.range(7, 0) = data.range();
        bridge_output->write(gp_out);
    }
    
    else if(width == 1025){
        galapagos_packet gp_out;
        gp_out.last = 0;
        gp_out.dest = dest;
        gp_out.user = 5;
        for(int j=0; j<64; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
            }
        }
        bridge_output->write(gp_out);
        jj=0;
        for(int j=64; j<128; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=128; j<192; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=192; j<256; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=256; j<320; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=320; j<384; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=384; j<448; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=448; j<512; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        jj=0; 
        for(int j=512; j<576; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=576; j<640; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=640; j<704; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=704; j<768; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=768; j<832; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=832; j<896; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=896; j<960; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=960; j<1024; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        gp_out.last = 1;
        OUTPUT_T data;
        data.range() = output[1024].read().range();
        gp_out.data.range(7, 0) = data.range();
        bridge_output->write(gp_out);
    }

    else if(width == 2049){
        galapagos_packet gp_out;
        gp_out.last = 0;
        gp_out.dest = dest;
        gp_out.user = 5;
        for(int j=0; j<64; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((j)*8 + 7, (j)*8) = data.range();
            }
        }
        bridge_output->write(gp_out);
        jj=0;
        for(int j=64; j<128; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=128; j<192; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);

        jj=0; 
        for(int j=192; j<256; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=256; j<320; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=320; j<384; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=384; j<448; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=448; j<512; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }

        jj=0; 
        for(int j=512; j<576; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=576; j<640; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=640; j<704; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=704; j<768; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=768; j<832; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=832; j<896; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=896; j<960; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=960; j<1024; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1024; j<1088; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1088; j<1152; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1152; j<1216; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1216; j<1280; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1280; j<1344; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1344; j<1408; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1408; j<1472; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1472; j<1536; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1536; j<1600; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1600; j<1664; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1664; j<1728; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1728; j<1792; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1792; j<1856; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1856; j<1920; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1920; j<1984; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        jj=0; 
        for(int j=1984; j<2048; j++){
    #pragma HLS pipeline II=1 
            if(!output[j].empty()){
                OUTPUT_T data;
                data.range() = output[j].read().range();
                gp_out.data.range((jj)*8 + 7, (jj)*8) = data.range();
            }
            jj++;
        }
        bridge_output->write(gp_out);
        
        
        gp_out.last = 1;
        OUTPUT_T data;
        data.range() = output[2048].read().range();
        gp_out.data.range(7, 0) = data.range();
        bridge_output->write(gp_out);

    }

}

#endif
