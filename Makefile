# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/19 13:36:32 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= lem-in

#LIBFTPRINTF_DIRS
LIB_DIR			:= ./libftprintf

#PROJECT_DIRS
INC_DIR			:= ./include
OBJ_DIR			:= ./obj
SRC_DIR			:= ./src/algorithm
SRC_VIS_DIR		:= ./src/visio

#SDL2_DIRS
## УСТАНОВИЛ в эту папку SDL2 по туториалу который ты мне скинул
## https://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/index.php
## часть которая X-CODE касается не надо делать
## советую тебе тоже так сделать
SDL2_INC		= ~/Library/Frameworks/SDL2.framework/Headers
SDL2_DIR		= ~/Library/Frameworks/
## флаги сохранил, если не получится, мои закоментишь
#SDL2_INC		:= ./sdl2/SDL2.framework/Headers
#SDL2_DIR		:= ./sdl2

CC				:= gcc
CFLAGS			:= -g -Wall -Wextra -Werror
LFLAGS			= -I $(LIB_DIR)/libft -I $(LIB_DIR)/inc
LFLAGS			+= -I $(INC_DIR) -I $(SDL2_INC)

LIB				= -L $(LIB_DIR) -lftprintf
LIB				+= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2

HEADERS			:= lem_in.h visual.h

SRC 			:= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c\
				adj_func.c utility.c ft_exit.c validation.c\
				direction.c dfs.c bfs.c path_func.c\
				queue.c suurballe.c renovation.c free_elem.c\
				tactical_moves.c ants.c listpath_func.c

SRC_VIS			:= init.c

OBJ_LEM			:= $(SRC:.c=.o)
OBJ_VIS			:= $(SRC_VIS:.c=.o)
OBJ				:= $(OBJ_LEM) $(OBJ_VIS)

vpath %.c $(SRC_DIR) $(SRC_VIS_DIR)
vpath %.o $(OBJ_DIR)
vpath %.h $(INC_DIR) $(SDL2_INC)

GREEN 			:= \033[0;32m
RED 			:= \033[0;31m
RESET			:= \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(SDL_LIB) $(HEADERS)
	$(MAKE) -C $(LIB_DIR)
	echo "$(GREEN)libftprintf.a created$(RESET)"
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIB) -o $@
	echo "$(GREEN)DONE ✅$(RESET)"

$(OBJ_VIS):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<
	echo "$(GREEN)$@ was created$(RESET)"

$(OBJ_LEM):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<
	echo "$(GREEN)$@ was created$(RESET)"

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)
	echo "$(RED)objects files was deleted$(RESET)"

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(NAME)
	echo "$(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.SILENT: all $(NAME) $(OBJ) $(OBJ_DIR) clean fclean re

.PHONY: clean fclean re all libftprintf
