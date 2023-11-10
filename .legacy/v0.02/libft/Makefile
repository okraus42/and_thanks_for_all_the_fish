# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:43:18 by okraus            #+#    #+#              #
#    Updated: 2023/08/17 14:59:52 by okraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://stackoverflow.com/questions/451413/make-makefile-progress-indication
ifndef ECHO
HIT_TOTAL	!=	${MAKE} ${MAKECMDGOALS} --dry-run ECHO="HIT_MARK" | grep -c "HIT_MARK"
HIT_COUNT1	=	$(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
HIT_COUNT2	=	$(eval HIT_M != expr ${HIT_M} + 1)${HIT_M}
HIT_COUNT3	=	$(eval HIT_O != expr ${HIT_O} + $(BAR_LENGTH))${HIT_O}
PERC		=	$(shell expr $(HIT_COUNT3) / $(HIT_TOTAL) | bc)
ECHO		=	echo "[`expr ${HIT_COUNT1} '*' 100 / ${HIT_TOTAL}`%]"
endif

NAME		=	libft.a
INCS		=	libft.h
LIBC		=	ar rcs
CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
OBJ_DIR		=	objects/
SLEEP		=	#sleep 0.5

# SOURCES

SRC			=	$(addprefix $(SRC_LIB_DIR), $(addsuffix .c, $(SRC_LIB))) \
				$(addprefix $(SRC_EX_DIR), $(addsuffix .c, $(SRC_EX))) \
				$(addprefix $(SRC_GNL_DIR), $(addsuffix .c, $(SRC_GNL))) \
				$(addprefix $(SRC_PF_DIR), $(addsuffix .c, $(SRC_PF)))

# Source directories

SRC_LIB_DIR	=	src_libft/
SRC_EX_DIR	=	src_ft_extras/
SRC_GNL_DIR	=	src_ft_get_next_line/
SRC_PF_DIR	=	src_ft_printf/

# Original Libft functions

SRC_LIB		=	ft_atoi \
				ft_bzero \
				ft_calloc \
				ft_isalnum \
				ft_isalpha \
				ft_isascii \
				ft_isdigit \
				ft_isprint \
				ft_itoa \
				ft_lstadd_back \
				ft_lstadd_front \
				ft_lstclear \
				ft_lstdelone \
				ft_lstiter \
				ft_lstlast \
				ft_lstmap \
				ft_lstnew \
				ft_lstsize \
				ft_memchr \
				ft_memcmp \
				ft_memcpy \
				ft_memmove \
				ft_memset \
				ft_putchar_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_putstr_fd \
				ft_split \
				ft_strchr \
				ft_strdup \
				ft_striteri \
				ft_strjoin \
				ft_strlcat \
				ft_strlcpy \
				ft_strlen \
				ft_strmapi \
				ft_strncmp \
				ft_strnstr \
				ft_strrchr \
				ft_strtrim \
				ft_substr \
				ft_tolower \
				ft_toupper

# Extra utility functions

SRC_EX		=	ft_abs \
				ft_atoi_base \
				ft_copy_split \
				ft_dlstadd \
				ft_dlstclear \
				ft_dlstdelone \
				ft_dlstmoveone \
				ft_dlstnew \
				ft_evil_calloc \
				ft_evil_malloc \
				ft_free_split \
				ft_latoi \
				ft_litoa \
				ft_max \
				ft_min \
				ft_print_memory \
				ft_print_memory_plus \
				ft_put_split \
				ft_put_strarray \
				ft_split_add \
				ft_split_rm \
				ft_splitlen \
				ft_stringcopy \
				ft_swap \
				ft_uabsdif \
				ft_umax \
				ft_umin \
				ft_uswap

# Get next line functions

SRC_GNL		=	get_next_line \
				get_next_line_utils

# ft_printf functions

SRC_PF		= 	ft_colour_1 \
				ft_colour_2 \
				ft_padding \
				ft_printf_utils \
				ft_printf \
				ft_printformat \
				ft_string_basebig \
				ft_string_binocthex \
				ft_string_colour \
				ft_string_hexabig \
				ft_string_hexasmall \
				ft_string_integer \
				ft_string_pointer \
				ft_string_string \
				ft_string_unsigned

# Formating

NRM_FORMAT	=	\033[0m

GREEN		=	\033[1;32m
YELLOW		=	\033[1;93m
RED			=	\033[1;31m
REVERSE		=	\033[7m
RETURN		=	\033[1F\r\033[2K

# Printing

BAR_LENGTH	:=	50
PRINT1		=	printf "[$(HIT_COUNT2)/$(HIT_TOTAL)]" ;
PRINT2		=	for num in `seq 1 $(BAR_LENGTH)` ; do \
					if [ $$num -le $(PERC) ] ; then \
						printf "$(REVERSE) $(NRM_FORMAT)" ; \
					else \
						printf " " ; \
        			fi \
    			done

# Objects

OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_LIB))) \
				$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_EX))) \
				$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_GNL))) \
				$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PF)))

# RULES

all:			announce $(NAME)

#				@$(PRINT2)
#				@$(PRINT1)
#				@$(ECHO) All done
#				@echo "$(GREEN)Amazing <<$(REVERSE)libft.a$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"
				

# MESSAGES 

announce: 
				@echo "$(RED)Not compiling because library already exists\n$(NRM_FORMAT)"

# COMPILATION

$(OBJ_DIR)%.o:	$(SRC_LIB_DIR)%.c # start_msg
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling Libft: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_EX_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling extras: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_GNL_DIR)%.c # lib_msg
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling get next line: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_PF_DIR)%.c # gnl_msg
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling ft printf: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(NAME): 		$(OBJ) # pf_msg
				@echo "$(RETURN)$(RETURN)$(RETURN)$(GREEN)LIBFT compilation complete!$(NRM_FORMAT)"
				@$(LIBC) $(NAME) $(OBJ)
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)
				@echo "$(GREEN)Amazing <<$(REVERSE)libft.a$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"

# Remove the object files and the directory

clean:
				@rm -rf $(OBJ_DIR)
				@echo "$(RED)Objects removed!$(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Remove the objects and then the library

fclean:			clean
				@rm -f $(NAME)
				@echo "$(RETURN)$(RED)Library deleted!$(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Remove stuff and make it all again

re: fclean all
	@$(PRINT2)
	@$(PRINT1)
	@$(ECHO)

# Phony stuff for rules

.PHONY: all announce clean fclean re
