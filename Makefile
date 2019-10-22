# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aks <aks@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/22 11:25:43 by aks              ###   ########.fr        #
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

CC				:= gcc
CFLAGS			= -g -Wall -Wextra -Werror
LFLAGS			= -I $(LIB_DIR)/libft -I $(LIB_DIR)/inc
LFLAGS			+= -I $(INC_DIR) -I $(SDL2_INC)

LIBS			= -L $(LIB_DIR) -lftprintf

#SDL2_DIRS
UNAME 			= $(shell uname -s)
ifeq ($(UNAME), Linux)
	SDL2_INC	= /usr/include/SDL2
	CFLAGS		+= $(shell sdl2-config --cflags) 
	LIBS		+= $(shell sdl2-config --libs) 
else
	SDL2_INC	= ~/Library/Frameworks/SDL2.framework/Headers
	SDL2_DIR	= ~/Library/Frameworks/
	LIBS		+= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2
endif

HEADERS			:= lem_in.h visual.h

SRC 			:= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c\
				adj_func.c utility.c ft_exit.c validation.c\
				direction.c dfs.c bfs.c path_func.c\
				queue.c suurballe.c renovation.c free_elem.c\
				tactical_moves.c ants.c listpath_func.c flags.c

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
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBS) -o $@
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
