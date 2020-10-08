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
#include "firmware/myproject.h"
#include "firmware/weights/w27.h"
#include "firmware/weights/w31.h"
#include "firmware/weights/w36.h"
#include "firmware/weights/w40.h"
#include "firmware/weights/w44.h"
#include "firmware/weights/w48.h"
#include "firmware/parameters.h"


#define CHECKPOINT 5000

int main(int argc, char **argv)
{
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
  
  //model_weightdefault_t w27[73728];
  //model_weightdefault_t w31[147456];
  //model_weightdefault_t w36[294912];
  //model_weightdefault_t w40[589824];
  //model_weightdefault_t w44[589824];
  //model_weightdefault_t w48[65536];
  for(int iX = 0; iX < 3; iX++) { 
    input_t pTest = 0;
    hls::stream<input_t> em_barrel[N_INPUT_3_1];
    for(int i0 = 0; i0 < 11*56; i0++) {
	for(int i2 = 0; i2 < N_INPUT_3_1; i2++) {
	  if(i2 == 0) em_barrel[i2].write(pTest);
	  if(i2 >  0 && i0 < 1)  em_barrel[i2].write(iX+1);
	  if(i2 >  0 && i0 > 0)  em_barrel[i2].write(iX+1);
	  if(pTest == 0) pTest = 1;
        }
    }
    hls::stream<result_t> layer54_out[N_LAYER_52];//layer34_out[N_FILT_31]
    myproject(em_barrel,layer54_out,w27, w31, w36, w40, w44, w48);
    std::cout << "----> here " << std::endl;
    for(int i1 = 0; i1 < 1; i1++) {
      for(int i0 = 0; i0 < N_LAYER_52; i0++) {
	fout << layer54_out[i0].read() << " ";
      }
      fout << std::endl;
    }
     std::cout << "input1 ";
     for(int i0 = 0; i0 < 5; i0++) { 
       std::cout << " " <<  em_barrel[i0].empty();
       if(!em_barrel[i0].empty()) std::cout << "--> " << em_barrel[i0].read();
     }
     std::cout << std::endl;

     std::cout << "Layer  13";
     for(int i0 = 0; i0 < N_CHANNEL_2; i0++) { 
       std::cout << " " << layer54_out[i0].empty();
     }
     std::cout << std::endl;
     std::cout << "----> Done " << std::endl;

  }
  fout.close();
  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;

  return 0;
}
