PROJECT = dac_sampling
BUILD_DIR = bin
DRIVER_DIR = drivers

CFILES = main.c
CFILES += $(wildcard $(DRIVER_DIR)/*.c)

# TODO - you will need to edit these two lines!
DEVICE = stm32l152re#stm32f411vet6
# OOCD_FILE = board/stm32f4discovery.cfg

LDSCRIPT = ./stm32-clicker.ld
LDFLAGS += -u _printf_float

# You shouldn't have to edit anything below here.
#VPATH += $(SHARED_DIR)
#INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
INCLUDES += $(patsubst %,-I%, . $(DRIVER_DIR))

OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ./rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
