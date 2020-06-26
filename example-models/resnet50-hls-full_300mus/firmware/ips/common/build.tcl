
set curDir [pwd]
set layerName [lindex $argv 0]
set nnet_utils_dir [lindex $argv 1]
set galapagos_dir [lindex $argv 2]
set underscore "_"
set rtl_prefix $layerName$underscore

cd $galapagos_dir/userIP/hls_projects
open_project resnet_$layerName 
set_top  $layer_type 
open_solution "solution1"
config_rtl -prefix "$rtl_prefix"
set_part xczu19eg-ffvc1760-2-i 
catch {config_array_partition -maximum_size 4096}
add_files $curDir/../srcs/$layer_type.cpp -cflags "-std=c++11  -I $curDir/$nnet_utils_dir -I $curDir  -I $curDir/../include $args"
create_clock -period 250MHz -name default
csynth_design
export_design -format ip_catalog
close_project

quit
