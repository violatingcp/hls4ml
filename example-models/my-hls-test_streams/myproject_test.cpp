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
      input_t input1[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1] = {in[0],in[1],in[2],in[3],in[4],in[5],in[6],in[7],in[8],in[9],in[10],in[11],in[12],in[13],in[14],in[15],in[16],in[17],in[18],in[19],in[20],in[21],in[22],in[23],in[24],in[25],in[26],in[27],in[28],in[29],in[30],in[31],in[32],in[33],in[34],in[35],in[36],in[37],in[38],in[39],in[40],in[41],in[42],in[43],in[44],in[45],in[46],in[47],in[48],in[49],in[50],in[51],in[52],in[53],in[54],in[55],in[56],in[57],in[58],in[59],in[60],in[61],in[62],in[63],in[64],in[65],in[66],in[67],in[68],in[69],in[70],in[71],in[72],in[73],in[74],in[75],in[76],in[77],in[78],in[79],in[80],in[81],in[82],in[83],in[84],in[85],in[86],in[87],in[88],in[89],in[90],in[91],in[92],in[93],in[94],in[95],in[96],in[97],in[98],in[99],in[100],in[101],in[102],in[103],in[104],in[105],in[106],in[107],in[108],in[109],in[110],in[111],in[112],in[113],in[114],in[115],in[116],in[117],in[118],in[119],in[120],in[121],in[122],in[123],in[124],in[125],in[126],in[127],in[128],in[129],in[130],in[131],in[132],in[133],in[134],in[135],in[136],in[137],in[138],in[139],in[140],in[141],in[142],in[143],in[144],in[145],in[146],in[147],in[148],in[149],in[150],in[151],in[152],in[153],in[154],in[155],in[156],in[157],in[158],in[159],in[160],in[161],in[162],in[163],in[164],in[165],in[166],in[167],in[168],in[169],in[170],in[171],in[172],in[173],in[174],in[175],in[176],in[177],in[178],in[179],in[180],in[181],in[182],in[183],in[184],in[185],in[186],in[187],in[188],in[189],in[190],in[191],in[192],in[193],in[194],in[195],in[196],in[197],in[198],in[199],in[200],in[201],in[202],in[203],in[204],in[205],in[206],in[207],in[208],in[209],in[210],in[211],in[212],in[213],in[214],in[215],in[216],in[217],in[218],in[219],in[220],in[221],in[222],in[223],in[224],in[225],in[226],in[227],in[228],in[229],in[230],in[231],in[232],in[233],in[234],in[235],in[236],in[237],in[238],in[239],in[240],in[241],in[242],in[243],in[244],in[245],in[246],in[247],in[248],in[249],in[250],in[251],in[252],in[253],in[254],in[255],in[256],in[257],in[258],in[259],in[260],in[261],in[262],in[263],in[264],in[265],in[266],in[267],in[268],in[269],in[270],in[271],in[272],in[273],in[274],in[275],in[276],in[277],in[278],in[279],in[280],in[281],in[282],in[283],in[284],in[285],in[286],in[287],in[288],in[289],in[290],in[291],in[292],in[293],in[294],in[295],in[296],in[297],in[298],in[299],in[300],in[301],in[302],in[303],in[304],in[305],in[306],in[307],in[308],in[309],in[310],in[311],in[312],in[313],in[314],in[315],in[316],in[317],in[318],in[319],in[320],in[321],in[322],in[323],in[324],in[325],in[326],in[327],in[328],in[329],in[330],in[331],in[332],in[333],in[334],in[335],in[336],in[337],in[338],in[339],in[340],in[341],in[342],in[343],in[344],in[345],in[346],in[347],in[348],in[349],in[350],in[351],in[352],in[353],in[354],in[355],in[356],in[357],in[358],in[359],in[360],in[361],in[362],in[363],in[364],in[365],in[366],in[367],in[368],in[369],in[370],in[371],in[372],in[373],in[374],in[375],in[376],in[377],in[378],in[379],in[380],in[381],in[382],in[383],in[384],in[385],in[386],in[387],in[388],in[389],in[390],in[391],in[392],in[393],in[394],in[395],in[396],in[397],in[398],in[399],in[400],in[401],in[402],in[403],in[404],in[405],in[406],in[407],in[408],in[409],in[410],in[411],in[412],in[413],in[414],in[415],in[416],in[417],in[418],in[419],in[420],in[421],in[422],in[423],in[424],in[425],in[426],in[427],in[428],in[429],in[430],in[431],in[432],in[433],in[434],in[435],in[436],in[437],in[438],in[439],in[440],in[441],in[442],in[443],in[444],in[445],in[446],in[447],in[448],in[449],in[450],in[451],in[452],in[453],in[454],in[455],in[456],in[457],in[458],in[459],in[460],in[461],in[462],in[463],in[464],in[465],in[466],in[467],in[468],in[469],in[470],in[471],in[472],in[473],in[474],in[475],in[476],in[477],in[478],in[479],in[480],in[481],in[482],in[483],in[484],in[485],in[486],in[487],in[488],in[489],in[490],in[491],in[492],in[493],in[494],in[495],in[496],in[497],in[498],in[499],in[500],in[501],in[502],in[503],in[504],in[505],in[506],in[507],in[508],in[509],in[510],in[511],in[512],in[513],in[514],in[515],in[516],in[517],in[518],in[519],in[520],in[521],in[522],in[523],in[524],in[525],in[526],in[527],in[528],in[529],in[530],in[531],in[532],in[533],in[534],in[535],in[536],in[537],in[538],in[539],in[540],in[541],in[542],in[543],in[544],in[545],in[546],in[547],in[548],in[549],in[550],in[551],in[552],in[553],in[554],in[555],in[556],in[557],in[558],in[559],in[560],in[561],in[562],in[563],in[564],in[565],in[566],in[567],in[568],in[569],in[570],in[571],in[572],in[573],in[574],in[575],in[576],in[577],in[578],in[579],in[580],in[581],in[582],in[583],in[584],in[585],in[586],in[587],in[588],in[589],in[590],in[591],in[592],in[593],in[594],in[595],in[596],in[597],in[598],in[599],in[600],in[601],in[602],in[603],in[604],in[605],in[606],in[607],in[608],in[609],in[610],in[611],in[612],in[613],in[614],in[615],in[616],in[617],in[618],in[619],in[620],in[621],in[622],in[623],in[624],in[625],in[626],in[627],in[628],in[629],in[630],in[631],in[632],in[633],in[634],in[635],in[636],in[637],in[638],in[639],in[640],in[641],in[642],in[643],in[644],in[645],in[646],in[647],in[648],in[649],in[650],in[651],in[652],in[653],in[654],in[655],in[656],in[657],in[658],in[659],in[660],in[661],in[662],in[663],in[664],in[665],in[666],in[667],in[668],in[669],in[670],in[671],in[672],in[673],in[674],in[675],in[676],in[677],in[678],in[679],in[680],in[681],in[682],in[683],in[684],in[685],in[686],in[687],in[688],in[689],in[690],in[691],in[692],in[693],in[694],in[695],in[696],in[697],in[698],in[699],in[700],in[701],in[702],in[703],in[704],in[705],in[706],in[707],in[708],in[709],in[710],in[711],in[712],in[713],in[714],in[715],in[716],in[717],in[718],in[719],in[720],in[721],in[722],in[723],in[724],in[725],in[726],in[727],in[728],in[729],in[730],in[731],in[732],in[733],in[734],in[735],in[736],in[737],in[738],in[739],in[740],in[741],in[742],in[743],in[744],in[745],in[746],in[747],in[748],in[749],in[750],in[751],in[752],in[753],in[754],in[755],in[756],in[757],in[758],in[759],in[760],in[761],in[762],in[763],in[764],in[765],in[766],in[767],in[768],in[769],in[770],in[771],in[772],in[773],in[774],in[775],in[776],in[777],in[778],in[779],in[780],in[781],in[782],in[783]};
      result_t layer10_out[N_LAYER_9] = {0,0,0,0,0,0,0,0,0,0};
      //result_t layer3_out[OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2] = {0};

      //hls-fpga-machine-learning insert top-level-function
      unsigned short size_in1,size_out1;
      myproject(input1,layer10_out,size_in1,size_out1);

      //hls-fpga-machine-learning insert tb-output
      for(int i = 0; i < N_LAYER_9; i++) {
        fout << layer10_out[i] << " ";
      }
      fout << std::endl;

      if (e % CHECKPOINT == 0) {
        std::cout << "Predictions" << std::endl;
        //hls-fpga-machine-learning insert predictions
        for(int i = 0; i < N_LAYER_9; i++) {
          std::cout << pr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Quantized predictions" << std::endl;
        //hls-fpga-machine-learning insert quantized
        for(int i = 0; i < N_LAYER_9; i++) {
          //std::cout << layer10_out[i] << " ";
        }
        std::cout << std::endl;
      }
    }
    fin.close();
    fpr.close();
  } else {
    std::cout << "INFO: Unable to open input/predictions file, using default input." << std::endl;
    //hls-fpga-machine-learning insert zero
    input_t input1[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //result_t layer10_out[N_LAYER_9] = {0,0,0,0,0,0,0,0,0,0};
    result_t layer3_out[OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2] = {0};
    //hls-fpga-machine-learning insert top-level-function
    unsigned short size_in1,size_out1;
    myproject(input1,layer3_out,size_in1,size_out1);

    //hls-fpga-machine-learning insert output
    for(int i = 0; i < OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2; i++) {
      //std::cout << layer3_out[i] << " ";
    }
    std::cout << std::endl;

    //hls-fpga-machine-learning insert tb-output
    for(int i = 0; i < N_LAYER_9; i++) {
      fout << layer3_out[i] << " ";
    }
    fout << std::endl;
  }

  fout.close();
  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;

  return 0;
}
