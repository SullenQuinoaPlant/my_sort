TARGETS := \
	default_t_sort_randomizer \
	sort_ar_ip \
	sort_ar_shfl_ip
NAME = mysort
LIBNAME = lib$(NAME)

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)
LIBS_I := $(ROOT)
OUT_DIR_LIB := $(ROOT)
OUT_DIR_H := $(INC_DIR)

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)
