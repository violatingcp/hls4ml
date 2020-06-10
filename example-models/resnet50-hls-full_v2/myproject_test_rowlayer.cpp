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

#include "firmware/parameters.h"
#include "firmware/myproject_rowlayer.h"


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

  bool iReset=true;
  //hls::stream<input_t>  inputstream[N_INPUT_2_1][N_INPUT_1_1];
  hls::stream<input_t>  inputstream[N_SPLIT][N_INPUT_1_1];
  hls::stream<result_t> outputstream[N_SPLIT][N_FILT_2-1];
  
  input_t pTmp = 0; 
  for(int i2 = 0; i2 < 64*224; i2++) { 
    for(int i1 = 0; i1 < N_SPLIT; i1++) { 
      for(int i0 = 0; i0 < N_INPUT_1_1; i0++) { 
	inputstream[i1][i0].write(pTmp);
      }
      pTmp = pTmp+1;
    }
  }
  myproject_rowlayer(inputstream,outputstream);
  for(int i0 = 0; i0 < 28; i0++) { 
    for(int i1 = 0; i1 < N_SPLIT; i1++) { 
      for(int i2 = 0; i2 < N_FILT_2-1; i2++) { 
	outputstream[i1][i2].read();
      }
    }
  }
  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;

  return 0;
}
