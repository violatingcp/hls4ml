SUBDIRS := $(wildcard layer*/.) bridges
.PHONY : all $(SUBDIRS)

all : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@
clean:
	for dir in $(SUBDIRS); do\
		export SYNTH_ROOT=dir;\
		$(MAKE) -C $$dir -f Makefile $@; \
	done
