
#include "_galapagos_resnet_bridge.hpp"


void hls4ml_galapagos_input_bridge_4(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[4]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{
#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    //_hls4ml_galapagos_input_bridge <4> (bridge_in, input, pixel_index_stream);
    _hls4ml_galapagos_input_bridge <4> (bridge_in, input);
}
                                   

void hls4ml_galapagos_input_bridge_65(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[65]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{

#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    _hls4ml_galapagos_input_bridge <65> (bridge_in, input);//, pixel_index_stream);
}

void hls4ml_galapagos_input_bridge_129(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[129]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{

#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    _hls4ml_galapagos_input_bridge <129> (bridge_in, input);//, pixel_index_stream);
}

void hls4ml_galapagos_input_bridge_257(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[257]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{

#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    _hls4ml_galapagos_input_bridge <257> (bridge_in, input);//, pixel_index_stream);
}
                                   
void hls4ml_galapagos_input_bridge_513(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[513]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{

#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    _hls4ml_galapagos_input_bridge <513> (bridge_in, input);//, pixel_index_stream);
}

void hls4ml_galapagos_input_bridge_1025(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[1025]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{

#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    _hls4ml_galapagos_input_bridge <1025> (bridge_in, input);//, pixel_index_stream);
}
                                   
void hls4ml_galapagos_input_bridge_2049(galapagos_interface * bridge_in,
                                   hls::stream<ap_uint<8> > input[2049]//,
                                   //hls::stream <ap_uint<32> > pixel_index_stream[1]
                                   )
{

#pragma HLS INTERFACE axis register both port=bridge_in
#pragma HLS INTERFACE axis register both port=input
#pragma HLS array_partition variable=input
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=pixel_index_stream
    _hls4ml_galapagos_input_bridge <2049> (bridge_in, input);//, pixel_index_stream);
}
                                   

void hls4ml_galapagos_output_bridge_4 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[4],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{
#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output bundle="output"
//#pragma HLS array_partition variable=output
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return


    _hls4ml_galapagos_output_bridge <4> (size, output, bridge_output, dest);
}


void hls4ml_galapagos_output_bridge_65 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[65],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output 
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return

    _hls4ml_galapagos_output_bridge <65> (size, output, bridge_output, dest);
}

void hls4ml_galapagos_output_bridge_129 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[129],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output 
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return

    _hls4ml_galapagos_output_bridge <129> (size, output, bridge_output, dest);
}



void hls4ml_galapagos_output_bridge_257 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[257],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output 
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return

    _hls4ml_galapagos_output_bridge <257> (size, output, bridge_output, dest);
}

void hls4ml_galapagos_output_bridge_513 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[513],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output 
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return

    _hls4ml_galapagos_output_bridge <513> (size, output, bridge_output, dest);
}

void hls4ml_galapagos_output_bridge_1025 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[1025],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output 
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return

    _hls4ml_galapagos_output_bridge <1025> (size, output, bridge_output, dest);
}


void hls4ml_galapagos_output_bridge_2049 (
                                    ap_uint<16> size,
                                    hls::stream<ap_uint<8>> output[2049],
                                    galapagos_interface * bridge_output,
                                    const ap_uint <8> dest
                    )
{

#pragma HLS INTERFACE axis register both port=bridge_output
#pragma HLS INTERFACE axis register both port=output 
#pragma HLS INTERFACE ap_ctrl_none port=dest
#pragma HLS INTERFACE ap_ctrl_none port=size
#pragma HLS INTERFACE ap_ctrl_none port=return

    _hls4ml_galapagos_output_bridge <2049> (size, output, bridge_output, dest);
}


