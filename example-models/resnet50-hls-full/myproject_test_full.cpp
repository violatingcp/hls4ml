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

#include "firmware/parameters_full.h"
#include "firmware/myproject_full.h"


#define CHECKPOINT 10

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


  std::string iline;
  std::string pline;
  int e = 0;

  input_t   gpu_0_data_0[N_INPUT_1_1][N_INPUT_2_1][N_INPUT_3_1];
  result_t  layer176_out[N_LAYER_175];

  //hls-fpga-machine-learning insert top-level-function
  //bool iReset = true;
  //  subimage(iReset, gpu_0_data_0,layer176_out);
  for(int i0 = 0; i0 < N_INPUT_1_1; i0++) { 
    for(int i1 = 0; i1 < N_INPUT_2_1; i1++) { 
      for(int i2 = 0; i2 < N_INPUT_3_1; i2++) { 
	input_t var = rand()*0.01;
	gpu_0_data_0[i0][i1][i2] = var;
	std::cout << i0 << " -- " << i1 << " -- " << i2 << "---> v " << var << std::endl;
      }
    }
  }
  subimage(gpu_0_data_0,layer176_out);
  //hls-fpga-machine-learning insert output
  // for(int i = 0; i < N_LAYER_OUT_3; i++) {
  //    std::cout << layer176_out[i].read() << " ";
  //  }
  //  std::cout << std::endl;

  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;

  return 0;
}
