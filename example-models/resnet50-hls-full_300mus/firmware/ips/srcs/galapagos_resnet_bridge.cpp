
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
                                   
//void hls4ml_galapagos_input_bridge_128(galapagos_interface * bridge_in,
//                                   hls::stream<ap_uint<8> > input[128])
                                   
//void hls4ml_galapagos_input_bridge_128(galapagos_interface * bridge_in,
//                                   hls::stream<ap_uint<8> > input[128])
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_in
//#pragma HLS array_partition variable=input
//#pragma HLS INTERFACE ap_ctrl_none port=return
//    _hls4ml_galapagos_input_bridge <128> (bridge_in, input);
//}
//                                   
//
//void hls4ml_galapagos_input_bridge_256(galapagos_interface * bridge_in,
//                                   hls::stream<ap_uint<8> > input[256])
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_in
//#pragma HLS array_partition variable=input
//#pragma HLS INTERFACE ap_ctrl_none port=return
//    _hls4ml_galapagos_input_bridge <256> (bridge_in, input);
//}
//                                   
//
//void hls4ml_galapagos_input_bridge_512(galapagos_interface * bridge_in,
//                                   hls::stream<ap_uint<8> > input[512])
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_in
//#pragma HLS array_partition variable=input
//#pragma HLS INTERFACE ap_ctrl_none port=return
//    _hls4ml_galapagos_input_bridge <512> (bridge_in, input);
//}
//
//void hls4ml_galapagos_input_bridge_1024(galapagos_interface * bridge_in,
//                                   hls::stream<ap_uint<8> > input[1024])
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_in
//#pragma HLS array_partition variable=input
//#pragma HLS INTERFACE ap_ctrl_none port=return
//    _hls4ml_galapagos_input_bridge <1024> (bridge_in, input);
//}
//                                   
//
//void hls4ml_galapagos_input_bridge_2048(galapagos_interface * bridge_in,
//                                   hls::stream<ap_uint<8> > input[2048])
//{
//#pragma HLS INTERFACE axis register both port=bridge_in
//#pragma HLS array_partition variable=input block factor=2
//#pragma HLS INTERFACE ap_ctrl_none port=return
//    _hls4ml_galapagos_input_bridge <2048> (bridge_in, input);
//}
                                   

                                   

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

//void hls4ml_galapagos_output_bridge_129 (
//                                    ap_uint<16> size,
//                                    hls::stream<ap_uint<8>> output[129],
//                                    galapagos_interface * bridge_output,
//                                    const ap_uint <8> dest
//                    )
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_output
//#pragma HLS INTERFACE axis register both port=output 
//#pragma HLS INTERFACE ap_ctrl_none port=dest
//#pragma HLS INTERFACE ap_ctrl_none port=size
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//    _hls4ml_galapagos_output_bridge <129> (size, output, bridge_output, dest);
//}
//
//
//
//void hls4ml_galapagos_output_bridge_128 (
//                                    ap_uint<16> size,
//                                    hls::stream<ap_uint<8>> output[128],
//                                    galapagos_interface * bridge_output,
//                                    const ap_uint <8> dest
//                    )
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_output
//#pragma HLS INTERFACE axis register both port=output bundle="output"
////#pragma HLS array_partition variable=output bundle="output"
//#pragma HLS INTERFACE ap_ctrl_none port=dest
//#pragma HLS INTERFACE ap_ctrl_none port=size
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//    _hls4ml_galapagos_output_bridge <128> (size, output, bridge_output, dest);
//}
//
//void hls4ml_galapagos_output_bridge_256 (
//                                    ap_uint<16> size,
//                                    hls::stream<ap_uint<8>> output[256],
//                                    galapagos_interface * bridge_output,
//                                    const ap_uint <8> dest
//                    )
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_output
//#pragma HLS INTERFACE axis register both port=output bundle="output"
////#pragma HLS array_partition variable=output bundle="output"
//#pragma HLS INTERFACE ap_ctrl_none port=dest
//#pragma HLS INTERFACE ap_ctrl_none port=size
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//    _hls4ml_galapagos_output_bridge <256> (size, output, bridge_output, dest);
//}
//
//
//void hls4ml_galapagos_output_bridge_512 (
//                                    ap_uint<16> size,
//                                    hls::stream<ap_uint<8>> output[512],
//                                    galapagos_interface * bridge_output,
//                                    const ap_uint <8> dest
//                    )
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_output
//#pragma HLS array_partition variable=output
//#pragma HLS INTERFACE ap_ctrl_none port=dest
//#pragma HLS INTERFACE ap_ctrl_none port=size
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//    _hls4ml_galapagos_output_bridge <512> (size, output, bridge_output, dest);
//}
//
//
//void hls4ml_galapagos_output_bridge_1024 (
//                                    ap_uint<16> size,
//                                    hls::stream<ap_uint<8>> output[1024],
//                                    galapagos_interface * bridge_output,
//                                    const ap_uint <8> dest
//                    )
//{
//
//#pragma HLS INTERFACE axis register both port=bridge_output
//#pragma HLS array_partition variable=output
//#pragma HLS INTERFACE ap_ctrl_none port=dest
//#pragma HLS INTERFACE ap_ctrl_none port=size
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//    _hls4ml_galapagos_output_bridge <1024> (size, output, bridge_output, dest);
//}
//
//
//void hls4ml_galapagos_output_bridge_2048 (
//                                    ap_uint<16> size,
//                                    hls::stream<ap_uint<8>> output[2048],
//                                    galapagos_interface * bridge_output,
//                                    const ap_uint <8> dest
//                    )
//{
//#pragma HLS INTERFACE axis register both port=bridge_output
//#pragma HLS array_partition variable=output block factor=2
//#pragma HLS INTERFACE ap_ctrl_none port=dest
//#pragma HLS INTERFACE ap_ctrl_none port=size
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//
//    _hls4ml_galapagos_output_bridge <2048> (size, output, bridge_output, dest);
//}
