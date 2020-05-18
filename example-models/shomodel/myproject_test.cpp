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

#include "firmware/parameters.h"
#include "firmware/myproject.h"

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

  if (fin.is_open() && fpr.is_open()) {
    while ( std::getline(fin,iline) && std::getline (fpr,pline) ) {
      if (e % CHECKPOINT == 0) std::cout << "Processing input " << e << std::endl;
      e++;
      char* cstr=const_cast<char*>(iline.c_str());
      char* current;
      std::vector<float> in;
      current=strtok(cstr," ");
      while(current!=NULL) {
        in.push_back(atof(current));
        current=strtok(NULL," ");
      }
      cstr=const_cast<char*>(pline.c_str());
      std::vector<float> pr;
      current=strtok(cstr," ");
      while(current!=NULL) {
        pr.push_back(atof(current));
        current=strtok(NULL," ");
      }

      //hls-fpga-machine-learning insert data
      input_t input1[N_INPUT_1_1*N_INPUT_2_1] = {in[0],in[1],in[2],in[3],in[4],in[5],in[6],in[7],in[8],in[9],in[10],in[11],in[12],in[13],in[14],in[15],in[16],in[17],in[18],in[19],in[20],in[21],in[22],in[23],in[24],in[25],in[26],in[27],in[28],in[29],in[30],in[31],in[32],in[33],in[34],in[35],in[36],in[37],in[38],in[39],in[40],in[41],in[42],in[43],in[44],in[45],in[46],in[47],in[48],in[49],in[50],in[51],in[52],in[53],in[54],in[55],in[56],in[57],in[58],in[59],in[60],in[61],in[62],in[63],in[64],in[65],in[66],in[67],in[68],in[69],in[70],in[71],in[72],in[73],in[74],in[75],in[76],in[77],in[78],in[79],in[80],in[81],in[82],in[83],in[84],in[85],in[86],in[87],in[88],in[89],in[90],in[91],in[92],in[93],in[94],in[95],in[96],in[97],in[98],in[99],in[100],in[101],in[102],in[103],in[104],in[105],in[106],in[107],in[108],in[109],in[110],in[111],in[112],in[113],in[114],in[115],in[116],in[117],in[118],in[119],in[120],in[121],in[122],in[123],in[124],in[125],in[126],in[127],in[128],in[129],in[130],in[131],in[132],in[133],in[134],in[135],in[136],in[137],in[138],in[139],in[140],in[141],in[142],in[143],in[144],in[145],in[146],in[147],in[148],in[149],in[150],in[151],in[152],in[153],in[154],in[155],in[156],in[157],in[158],in[159],in[160],in[161],in[162],in[163],in[164],in[165],in[166],in[167],in[168],in[169],in[170],in[171],in[172],in[173],in[174],in[175],in[176],in[177],in[178],in[179],in[180],in[181],in[182],in[183],in[184],in[185],in[186],in[187],in[188],in[189],in[190],in[191]};
      result_t layer19_out[N_LAYER_18] = {0,0,0,0};

      //hls-fpga-machine-learning insert top-level-function
      unsigned short size_in1,size_out1;
      //model_default_t w14[1277952];
      model_default_t w8[262144];
      myproject(input1,layer19_out,w8,size_in1,size_out1);

      //hls-fpga-machine-learning insert tb-output
      for(int i = 0; i < N_LAYER_18; i++) {
        fout << layer19_out[i] << " ";
      }
      fout << std::endl;

      if (e % CHECKPOINT == 0) {
        std::cout << "Predictions" << std::endl;
        //hls-fpga-machine-learning insert predictions
        for(int i = 0; i < N_LAYER_18; i++) {
          std::cout << pr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Quantized predictions" << std::endl;
        //hls-fpga-machine-learning insert quantized
        for(int i = 0; i < N_LAYER_18; i++) {
          std::cout << layer19_out[i] << " ";
        }
        std::cout << std::endl;
      }
    }
    fin.close();
    fpr.close();
  } else {
    std::cout << "INFO: Unable to open input/predictions file, using default input." << std::endl;
    //hls-fpga-machine-learning insert zero
    input_t input1[N_INPUT_1_1*N_INPUT_2_1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    result_t layer19_out[N_LAYER_18] = {0,0,0,0};

    //hls-fpga-machine-learning insert top-level-function
    unsigned short size_in1,size_out1;
    //model_default_t w14[1277952];
    model_default_t w8[262144];
    myproject(input1,layer19_out,w8,size_in1,size_out1);

    //hls-fpga-machine-learning insert output
    for(int i = 0; i < N_LAYER_18; i++) {
      std::cout << layer19_out[i] << " ";
    }
    std::cout << std::endl;

    //hls-fpga-machine-learning insert tb-output
    for(int i = 0; i < N_LAYER_18; i++) {
      fout << layer19_out[i] << " ";
    }
    fout << std::endl;
  }

  fout.close();
  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;

  return 0;
}
