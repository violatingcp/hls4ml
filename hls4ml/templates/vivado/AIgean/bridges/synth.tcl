set curDir [pwd]

set bridge_name [lindex $argv 0]
set galapagos_dir [lindex $argv 1]
set libGalapagos_dir [lindex $argv 2]
set prefix_name [lindex $argv 3]

cd $galapagos_dir/userIP/hls_projects

open_project $bridge_name 
set_top $bridge_name 
open_solution "solution1"
config_rtl -prefix $prefix_name 
set_part xczu19eg-ffvc1760-2-i 
catch {config_array_partition -maximum_size 4096}
add_files $curDir/../srcs/galapagos_resnet_bridge.cpp -cflags "-std=c++11 -I $curDir/$libGalapagos_dir -I $curDir/../include -DINTERFACE_100G"
create_clock -period 300MHz -name default
csynth_design
export_design -format ip_catalog 
close_project

