# defines guard-%

SUBDIRS := $(wildcard */.)

.PHONY: all clean

include ../common/include.mk
SYNTH_ROOT = "."

all: input_bridges output_bridges 

input_bridges: input_4 input_65 input_257 
output_bridges: output_4 output_65 output_257

input_4:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_4 $(galapagos_dir)  $(libGalapagos_dir) input_4 

input_65:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_65 $(galapagos_dir)  $(libGalapagos_dir) input_65

input_257:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_257 $(galapagos_dir)  $(libGalapagos_dir) input_257

output_4:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_4 $(galapagos_dir)  $(libGalapagos_dir) output_4

output_65:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_65 $(galapagos_dir)  $(libGalapagos_dir) output_65

output_257:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_257 $(galapagos_dir)  $(libGalapagos_dir) output_257

clean:
	rm -rf $(galapagos_dir)/userIP/hls_projects/hls4ml_galapagos_input_bridge_*
	rm -rf $(galapagos_dir)/userIP/hls_projects/hls4ml_galapagos_output_bridge_*
