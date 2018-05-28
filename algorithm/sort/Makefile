# Simple make for compiling individual C files into individual executables of 
# the same name. Intended for compiling simple demo/concept programs with 
# multiple executables in same directory This relies on implicit variables 
# and default actions to do the compile of the $(EXE) target. The implicit CC 
# and CFLAGS are redefined here, while RM uses the default 'rm -f'. Only 
# recompiles the specified files and header if they have changed since last 
# compile

# common library and include directory
COMMON_DIR = ../../commonlib
COMMON_LIB = $(COMMON_DIR)/common.o
COMMON_INCL = $(COMMON_DIR)/common.h

EXE = mergesort badmergesort
INCFILES = $(COMMON_INCL)
LDLIBS = $(COMMON_LIB)
CC=gcc
# CARG in following can be optionally assigned on make command line, e.g, make CARG=-DDEBUG
CFLAGS = -gdwarf -Wall  $(CARG)
# Note math.h functions need math lib linked (-lm)
OUTPUT_OPTION = -o $@ -lm

.PHONY: info clean

all: info $(LDLIBS) $(EXE)

info:
	@echo "Info: make for: $(EXE)"

# compile happens here
%: %.c $(INCFILES)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) $(OUTPUT_OPTION)

# compile common object tile
$(LDLIBS): $(INCFILES) 

clean:
	$(RM) $(EXE) *.o
