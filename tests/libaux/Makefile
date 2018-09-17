ifndef ROOT 
 ROOT := ../..
 include $(ROOT)/Makefile
endif

AUX_SRCS := $(wildcard $(AUX_DIR)/*.c)
AUX_OBJS := $(patsubst %.c,%.o,$(AUX_SRCS))

.PHONY : libaux
libaux : $(LIBS_L)/libaux.a $(LIBS_I)/libaux.h

$(LIBS_I)/libaux.h : $(AUX_DIR)/auxilliaries.h
	sed \
		-e'13,14s@AUXILLIARIES@LIBAUX@'\
		$< > $@

$(LIBS_L)/libaux.a : $(AUX_OBJS)
	-ar rcs $@ $^


#compilation :
$(AUX_DIR)/%.o : $(AUX_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-I $(INC_DIR)\
		-o $@ -c $<
