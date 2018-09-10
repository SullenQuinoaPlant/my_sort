ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif


.PHONY : all
all : $(NAME)

.PHONY : $(NAME)
$(NAME) : $(OUT_DIR_LIB)/$(LIBNAME).a

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	-ar rcs $@ $<
	sed \
		-e'4s@\($(NAME)\.h\)   @lib\1@' \
		-e'13s@ @ LIB@' -e'14s@\( define \)@\1LIB@' \
		$(INC_DIR)/$(NAME).h \
		> $(OUT_DIR_H)/$(LIBNAME).h



#compilation :
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<


.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
