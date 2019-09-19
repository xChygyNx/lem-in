# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 22:04:52 by astripeb          #+#    #+#              #
#    Updated: 2019/09/19 23:25:29 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

#KOSTYL'
INCLUDES		= ../../include

SRC_LIB_PATH	= ./libft
SRC_PRINTF_PATH = ./ft_printf
OBJ_PATH		= ./

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFLAGS			= -I $(INCLUDES)

SOURCES_LIBFT 	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
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
		   word_count.c ft_isdigitstr.c ft_char_count.c ft_len_arr.c buffer.c

SOURCES_PRINTF = ft_putnbr_f.c print_str.c print_pointer.c utility_func.c\
			print_num.c print_char.c ft_printf.c parse_mod.c print_double.c\
			set_color.c long_arithmetic.c long_arithmetic_2.c count_print.c\
			ft_dtoa.c ft_dtoa_2.c ft_dtoa_3.c ft_fprintf.c set_precision.c\
			print_binary.c ft_dtoe.c print_scientific.c utility_func_2.c

SRCS = $(addprefix $(LIBFT_PATH)/,$(SOURCES_LIBFT))
SRCS += $(addprefix $(PRINTF_PATH)/,$(SOURCES_PRINTF))

OBJ = $(addprefix $(OBJ_PATH),$(SOURCES_LIBFT:.c=.o))
OBJ += $(addprefix $(OBJ_PATH),$(SOURCES_PRINTF:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o:$(SRC_LIB_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o:$(SRC_PRINTF_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean $(NAME)
