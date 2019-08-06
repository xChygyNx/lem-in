# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yura <yura@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by yura              #+#    #+#              #
#    Updated: 2019/08/06 16:44:59 by yura             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
OBJ_PATH = ./
INC_PATH = ./include
LIBFT_PATH = ./src/libft
PRINTF_PATH = ./src/libft/ft_printf
LEM_IN_PATH =./src/lem-in
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -I $(INC_PATH)
MAIN_PATH = ./main/

SOURCES_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
		   ft_strncpy.c	ft_strcat.c	ft_strncat.c ft_strlcat.c ft_strchr.c\
		   ft_strrchr.c ft_strstr.c	ft_strnstr.c ft_strcmp.c ft_strncmp.c\
		   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
		   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c	ft_memdel.c\
		   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
		   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
		   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
		   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_del_mem.c\
		   ft_free_arr.c ft_isspace.c ft_strsplit_sp.c ft_int_len.c\
		   get_next_line.c ft_max.c ft_min.c ft_abs.c ft_putchar_utf8.c\
		   ft_putchar_utf8_fd.c ft_llitoa.c ft_strjoin_f.c ft_strjoin_s.c\
		   ft_putstr_utf8.c ft_putstr_utf8_fd.c ft_to_uppercase.c ft_lstrlen.c\
		   ft_putnstr_utf8_fd.c ft_lenwchar.c page_del.c free_tab.c word_len.c\
		   word_count.c

SOURCES_PRINTF = ft_putnbr_f.c print_str.c print_pointer.c utility_func.c\
			print_num.c print_char.c ft_printf.c parse_mod.c print_double.c\
			set_color.c long_arithmetic.c long_arithmetic_2.c count_print.c\
		   ft_dtoa.c ft_dtoa_2.c ft_dtoa_3.c ft_fprintf.c set_precision.c\
		   print_binary.c ft_dtoe.c print_scientific.c utility_func_2.c

LEM-IN_SRC = create_anthill.c

SRCS = $(addprefix $(LIBFT_PATH)/,$(SOURCES_LIBFT))
SRCS += $(addprefix $(PRINTF_PATH)/,$(SOURCES_PRINTF))

OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES_LIBFT:.c=.o))
OBJ += $(addprefix $(OBJ_PATH)/,$(SOURCES_PRINTF:.c=.o))

all: re
	@$(CC) $(LFLAGS) $(CFLAGS) -g $(MAIN_PATH)lem-in.c ./src/lem-in/create_anthill.c $(NAME) -o lem-in
	@$(MAKE) clean

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o:$(LIBFT_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o:$(PRINTF_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

main: re
	@$(CC) $(LFLAGS) $(MAIN_PATH)lem-in.c $(NAME) -o lem-in
	@$(MAKE) clean

norm:
	norminette $(LIBFT_PATH)
	norminette $(PRINTF_PATH)
	norminette $(LEM_IN_PATH)
	norminette $(INC_PATH)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@rm -f lem-in

re: fclean $(NAME)
