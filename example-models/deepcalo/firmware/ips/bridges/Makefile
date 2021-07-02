# defines guard-%

SUBDIRS := $(wildcard */.)

.PHONY: all clean

include ../common/include.mk
SYNTH_ROOT = "."

all: input_bridges output_bridges 

input_bridges: input_4 input_65 input_257 input_129 input_513 input_1025 input_2049 
output_bridges: output_4 output_65 output_257 output_129 output_513 output_1025 output_2049

input_4:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_4 $(galapagos_dir)  $(libGalapagos_dir) input_4 

input_65:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_65 $(galapagos_dir)  $(libGalapagos_dir) input_65

input_129:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_129 $(galapagos_dir)  $(libGalapagos_dir) input_129

input_257:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_257 $(galapagos_dir)  $(libGalapagos_dir) input_257

input_513:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_513 $(galapagos_dir)  $(libGalapagos_dir) input_513

input_1025:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_1025 $(galapagos_dir)  $(libGalapagos_dir) input_1025

input_2049:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_input_bridge_2049 $(galapagos_dir)  $(libGalapagos_dir) input_2049

output_4:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_4 $(galapagos_dir)  $(libGalapagos_dir) output_4

output_65:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_65 $(galapagos_dir)  $(libGalapagos_dir) output_65

output_129:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_129 $(galapagos_dir)  $(libGalapagos_dir) output_129

output_257:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_257 $(galapagos_dir)  $(libGalapagos_dir) output_257

output_513:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_513 $(galapagos_dir)  $(libGalapagos_dir) output_513

output_1025:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_1025 $(galapagos_dir)  $(libGalapagos_dir) output_1025

output_2049:
	mkdir -p ../hls_projects
	vivado_hls synth.tcl -tclargs hls4ml_galapagos_output_bridge_2049 $(galapagos_dir)  $(libGalapagos_dir) output_2049

clean:
	rm -rf $(galapagos_dir)/userIP/hls_projects/hls4ml_galapagos_input_bridge_*
	rm -rf $(galapagos_dir)/userIP/hls_projects/hls4ml_galapagos_output_bridge_*
