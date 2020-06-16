SUBDIRS := $(wildcard */.)

.PHONY: all clean
include ../common/include.mk
SYNTH_ROOT = "."

all:
	 mkdir -p "$(galapagos_dir)/userIP/hls_projects"
	 vivado_hls $(SYNTH_ROOT)/synth.tcl -tclargs $(project_name) $(nnet_utils_dir) $(galapagos_dir)
	 echo $(project_name)


clean:
	 rm -rf $(galapagos_dir)/userIP/hls_projects/resnet_$(project_name)
