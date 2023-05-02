SHELL=/bin/bash

CC := cc65816
AS := as65816
LD := ln65816

CODE_MODEL := large
DATA_MODEL := large
CLIB := clib-lc-ld.a
PRG := constest

CFLAGS := -I include \
	  --code-model $(CODE_MODEL) \
	  --data-model $(DATA_MODEL) \
	  -O2 \
	  --speed 

LDCONFIG := minimal.scm

SRC_C := $(wildcard src/*.c) 

OBJS := 	$(SRC_C:.c=.o)

LDFLAGS := $(CLIB) --override __program_start \
		  $(LDCONFIG) \
		  --list-file $(PRG).lst \
		  --cross-reference \
		  --verbose \
			--rtattr exit=simplified \
			--rom-code \
		  --output-format pgz

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(PRG).pgz

$(PRG).pgz: $(OBJS)
	@echo "Linking..."
	@$(LD) $(LDFLAGS) -o $(PRG).elf $^

clean:
	@find src -type f -name *.o | xargs rm -f
	@rm -f ./*.bin ./*.lst *.pgz *.elf

.SUFFIXES:
