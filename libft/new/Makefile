# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:43:18 by okraus            #+#    #+#              #
#    Updated: 2023/12/30 15:55:32 by okraus           ###   ########.fr        #
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
INCS		=	header/libft.h
LIBC		=	ar rcs
CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
OBJ_DIR		=	objects/
SLEEP		=	#sleep 0.5

# SOURCES

SRC			=	$(addprefix $(SRC_LIB_DIR), $(SRC_LIB)) \
				$(addprefix $(SRC_EX_DIR), $(SRC_EX)) \
				$(addprefix $(SRC_GNL_DIR), $(SRC_GNL)) \
				$(addprefix $(SRC_PF_DIR), $(SRC_PF))

# Source directories

SRC_LIB_DIR	=	src_libft/
SRC_EX_DIR	=	src_ft_extras/
SRC_GNL_DIR	=	src_ft_get_next_line/
SRC_PF_DIR	=	src_ft_printf/

# Original Libft functions

SRC_LIB		=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c

# Extra utility functions

SRC_EX		=	ft_abs.c \
				ft_atoi_base.c \
				ft_copy_split.c \
				ft_dlstadd.c \
				ft_dlstclear.c \
				ft_dlstdelone.c \
				ft_dlstmoveone.c \
				ft_dlstnew.c \
				ft_evil_calloc.c \
				ft_evil_malloc.c \
				ft_free_split.c \
				ft_gettime.c \
				ft_isblank.c \
				ft_iscntrl.c \
				ft_isgraph.c \
				ft_islower.c \
				ft_ispunct.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_isxdigit.c \
				ft_latoi.c \
				ft_litoa.c \
				ft_max.c \
				ft_min.c \
				ft_print_memory.c \
				ft_print_memory_plus.c \
				ft_put_split.c \
				ft_put_strarray.c \
				ft_readfile.c \
				ft_split_add.c \
				ft_split_rm.c \
				ft_splitlen.c \
				ft_stringcopy.c \
				ft_swap.c \
				ft_uabsdif.c \
				ft_umax.c \
				ft_umin.c \
				ft_uswap.c

# Get next line functions

SRC_GNL		=	get_next_line.c \
				get_next_line_utils.c

# ft_printf functions

SRC_PF		= 	ft_printf.c \
				ft_vprintf.c \
				ft_init0.c \
				ft_init1.c \
				ft_init2.c \
				ft_init3.c \
				ft_init4.c \
				ft_process_list.c \
				ft_process_colours.c \
				ft_process_unsigned.c \
				ft_process_other.c \
				ft_join_strings.c \
				ft_utils.c \
				ft_utils_str_free.c \
				ft_utils_pad.c \
				ft_utils_flags_prec_width.c

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

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_LIB:.c=.o)) \
				$(addprefix $(OBJ_DIR), $(SRC_EX:.c=.o)) \
				$(addprefix $(OBJ_DIR), $(SRC_GNL:.c=.o)) \
				$(addprefix $(OBJ_DIR), $(SRC_PF:.c=.o))

# RULES

all:			announce $(NAME)

bonus:			all
#				@$(PRINT2)
#				@$(PRINT1)
#				@$(ECHO) All done
#				@echo "$(GREEN)Amazing <<$(REVERSE)libft.a$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"
				

# MESSAGES 

announce: 
				@echo "$(RED)Not compiling because library already exists\n$(NRM_FORMAT)"

# COMPILATION

$(OBJ_DIR)%.o:	$(SRC_LIB_DIR)%.c $(INCS)
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling Libft: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_EX_DIR)%.c $(INCS)
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling extras: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_GNL_DIR)%.c $(INCS)
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling get next line: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_PF_DIR)%.c $(INCS)
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling ft printf: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(NAME): 		$(OBJ)
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

.PHONY: all announce clean fclean re bonus
