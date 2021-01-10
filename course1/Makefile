#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifeq ($(PLATFORM),HOST)
	CC := gcc
	SRCS := $(SOURCES)
	INC := $(INCLUDES)
	FLAGS = $(CFLAGS) $(INC)
 	OBJDUMP := objdump
	LD := ld
	SIZE := size
	LINKER_FILE :=
else
	CC := arm-none-eabi-gcc 
	SRCS := $(SOURCES) $(MSP432_SRCS)
	INC := $(INCLUDES) $(MSP432_INC) $(ARM_INC)
	FLAGS = $(CFLAGS) $(ARM_CFLAGS) $(INC)
	OBJDUMP := arm-none-eabi-objdump
	LD := arm-none-eabi-ld
	SIZE := arm-none-eabi-size
	LINKER_FILE := -T msp432p401r.lds
endif

# Architectures Specific Flags
CPU := cortex-m4
ARCH := armv7e-m
SPECS := nosys.specs
ARM_CFLAGS = -mtune=$(CPU) 		\
		 	 -mthumb			\
			 -march=$(ARCH)		\
			 -mfloat-abi=hard 	\
			 -mfpu=fpv4-sp-d16 	\
			 --specs=$(SPECS)	

# Compiler Flags and Defines
TARGET = c1m2.out
MAP = c1m2.map
LDFLAGS = -N $(LINKER_FILE) -fPIC -static-libgcc -Xlinker -Map=$(MAP) -static
CFLAGS = -Wall					\
		 -Wextra				\
		 -Wconversion			\
		 -pedantic				\
		 -g						\
		 -O0					\
		 -std=c99				\
		 -D$(PLATFORM)
CPPFLAGS := -E
ODFLAGS := -S --disassemble

PREPROCESSED = $(SRCS:.c=.i)

%.i : %.c
	$(CC) -c $< $(CPPFLAGS) $(FLAGS) -o $@

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $< $(FLAGS) -o $@

ASM = $(OBJS:.o=.asm)

%.asm : %.o
	$(OBJDUMP) $(ODFLAGS) $< > $@

DEPENDENCY = $(SRCS:.c=.d)

%.d : %.c
	$(CC) -MM $(FLAGS) $< -o $@	

.PHONY: compile-all
compile-all: $(PREPROCESSED)

.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(MAP) $(ASM) $(DEPENDENCY) $(PREPROCESSED) $(OBJS) $(TARGET)
	
.PHONY: help
help:
    $(info For indepent rules you need to add the "src/" before de file, example "make src/main.o")