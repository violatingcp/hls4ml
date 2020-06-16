#set galapagos_path $::env(GALAPAGOS_PATH)
#set board_name $::env(GALAPAGOS_BOARD_NAME)
#set part_name $::env(GALAPAGOS_PART)
#set src_path_root [pwd] 
#
#cd $galapagos_path/hlsBuild/${board_name}/ip
#
#
#
set curDir [pwd]

set bridge_name [lindex $argv 0]
set galapagos_dir [lindex $argv 1]
set libGalapagos_dir [lindex $argv 2]
set prefix_name [lindex $argv 3]

cd $galapagos_dir/userIP/hls_projects
#cd ../hls_projects
#set input_sizes "3 "

#foreach in_size $input_sizes {
open_project $bridge_name 
set_top $bridge_name 
open_solution "solution1"
config_rtl -prefix $prefix_name 
set_part xczu19eg-ffvc1760-2-i 
add_files $curDir/../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I $libGalapagos_dir -I $curDir/../include -DINTERFACE_100G"
create_clock -period 300MHz -name default
csynth_design
export_design -format ip_catalog
close_project
#}

#set output_sizes "64 128 256 512 1024 2048"
#
#foreach out_size $output_sizes {
#    open_project hls4ml_galapagos_output_bridge_$out_size
#    set_top hls4ml_galapagos_output_bridge_$out_size
#    open_solution "solution1"
#    set_part xczu19eg-ffvc1760-2-i 
#    add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#    create_clock -period 300MHz -name default
#    csynth_design
#    export_design -format ip_catalog
#}


#close_project
#open_project  hls4ml_galapagos_input_bridge_one_in_2048
#set_top hls4ml_galapagos_input_bridge_one_in_2048
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog
#close_project
#
#open_project  hls4ml_galapagos_input_bridge_one_in_1024
#set_top hls4ml_galapagos_input_bridge_one_in_2048
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog
#
#open_project  hls4ml_galapagos_input_bridge_one_in_512
#set_top hls4ml_galapagos_input_bridge_one_in_2048
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog
#
#open_project  hls4ml_galapagos_input_bridge_one_in_256
#set_top hls4ml_galapagos_input_bridge_one_in_2048
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog
#
#open_project  hls4ml_galapagos_input_bridge_one_in_128
#set_top hls4ml_galapagos_input_bridge_one_in_2048
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog
#
#open_project  hls4ml_galapagos_input_bridge_one_in_64
#set_top hls4ml_galapagos_input_bridge_one_in_2048
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog

#open_project hls4ml_galapagos_output_bridge
#set_top hls4ml_galapagos_output_bridge
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 300MHz -name default
#csynth_design
#export_design -format ip_catalog
#close_project


#open_project galapagos_bridge_256_in 
#set_top galapagos_bridge_256_in 
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 250MHz -name default
#csynth_design
#export_design -format ip_catalog
#close_project
#
#
#open_project galapagos_bridge_256_out 
#set_top galapagos_bridge_256_out 
#open_solution "solution1"
#set_part xczu19eg-ffvc1760-2-i 
#add_files ../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I/home/tarafdar/workDir/libGalapagos -DINTERFACE_100G"
#create_clock -period 250MHz -name default
#csynth_design
#export_design -format ip_catalog
#close_project


