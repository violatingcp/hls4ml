//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include "firmware/weights/w8.h"
//#include "firmware/weights/w10.h"
#include "firmware/parameters.h"
#include "firmware/myproject.h"

#define CHECKPOINT 5000

int main(int argc, char **argv) {
  //load input data from text file
  std::ifstream fin("tb_data/tb_input_features.dat");
  //load predictions from text file
  std::ifstream fpr("tb_data/tb_output_predictions.dat");

#ifdef RTL_SIM
  std::string RESULTS_LOG = "tb_data/rtl_cosim_results.log";
#else
  std::string RESULTS_LOG = "tb_data/csim_results.log";
#endif
  std::ofstream fout(RESULTS_LOG);

  std::string iline;
  std::string pline;
  int e = 0;
  
  std::cout << "INFO: Unable to open input/predictions file, using default input." << std::endl;
  //hls-fpga-machine-learning insert zero
  model_weightdefault_t w8[1152];
  model_weightdefault_t w10[2304];
  for(int iX = 0; iX < 10; iX++) { 
    input_t pTest = 0;
    hls::stream<input_t> input1[N_INPUT_3_1];
    for(int i0 = 0; i0 <  28*28; i0++) {
      //for(int i0 = 0; i0 <  28*17+3+5+2+8; i0++) {
      //for(int i0 = 0; i0 <  28*9+3+5+2; i0++) {
	 for(int i2 = 0; i2 < 2; i2++) {
	   if(i2 == 0) input1[i2].write(pTest);
	   if(i2 >  0 && i0 < 1)  input1[i2].write(iX);
	   if(i2 >  0 && i0 > 0)  input1[i2].write(0);
	   if(pTest == 0) pTest = 1;
	 }
     }
     hls::stream<result_t> layer13_out[N_LAYER_12];
     unsigned short size_in1,size_out1;
     myproject(input1,layer13_out);//,w8, w10,size_in1,size_out1);

     for(int i0 = 0; i0 < N_LAYER_12; i0++) {
       fout << layer13_out[i0].read() << " ";
     }
     fout << std::endl;

     std::cout << "input1 ";
     for(int i0 = 0; i0 < N_INPUT_3_1; i0++) { 
       std::cout << " " <<  input1[i0].empty();
       if(!input1[i0].empty()) std::cout << "--> " << input1[i0].read();
     }
     std::cout << std::endl;

     std::cout << "Layer  13";
     for(int i0 = 0; i0 < N_LAYER_12; i0++) { 
       std::cout << " " << layer13_out[i0].empty();
     }
     std::cout << std::endl;
     std::cout << "----> Done " << std::endl;

  }
  fout.close();
  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;
  return 0;
}
