NAME = mysort
LIBNAME = lib$(NAME)
GIT_REPO = https://github.com/SullenQuinoaPlant/my_sort.git

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(ROOT)/targets.mk
SRCS := $(patsubst %,$(SRC_DIR)/%.c,$(TARGETS))
INCS := $(wildcard $(INC_DIR)/*.h)
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

DEPENDENCIES = libmyhash libft

CC := gcc
#CC := /Users/nmauvari/Applications/GCC/bin/gcc-8.1
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)

TEST_DIR := $(ROOT)/tests
AUX_DIR := $(TEST_DIR)/libaux
RELEAS_DIR := $(ROOT)/release
