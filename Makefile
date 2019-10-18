# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/18 18:15:22 by pcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include ./src/lem-in/visualizator/Makefile

NAME			:= lem-in

OBJ_PATH		:= ./obj
INC_PATH		:= ./include
SDL2_INC		:= ./src/lib/sdl2/SDL2.framework/Headers
LIB_PATH		:= ./src/lib
SRC_PATH		:= ./src/lem-in
SRC_VIS_PATH	:= ./src/lem-in/visualizator
#MAIN_PATH		:= ./main/
SDL2_DIR		:= ./src/lib/sdl2
SDL2_LIB		:= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2

CC				:= gcc
CFLAGS			:= -g -Wall -Wextra -Werror
LFLAGS			:= -I $(INC_PATH) -I $(SDL2_INC)
LIB				:= -L $(LIB_PATH) -lftprintf

SRC 			:= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c\
				 adj_func.c utility.c ft_exit.c validation.c\
				 direction.c dfs.c bfs.c path_func.c\
				 queue.c suurballe.c renovation.c free_elem.c\
				 tactical_moves.c ants.c listpath_func.c
SRC_VIS			:= init.c

OBJ_LEM			:= $(SRC:.c=.o)
OBJ_VIS			:= $(SRC_VIS:.c=.o)
OBJ				:= $(OBJ_LEM) $(OBJ_VIS)

vpath %.c $(SRC_PATH) $(SRC_VIS_PATH)
vpath %.o $(OBJ_PATH)
vpath %.h $(INC_PATH) $(SDL2_INC)

#MAKE_DIR_OBJ	:= mkdir -p $(OBJ_PATH)

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(SDL_LIB)
	$(MAKE) -C $(LIB_PATH)
	#$(MAKE) -C $(VIS_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(OBJ_PATH)/, $(OBJ)) $(LIB) $(SDL2_LIB) -o $(NAME)

$(OBJ_VIS): %.o:%.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_PATH)/$@  -c $<

$(OBJ_LEM): %.o:%.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_PATH)/$@ -c $<

$(OBJ_PATH):
	mkdir -p $@

clean:
	$(MAKE) clean -C $(LIB_PATH)
	#$(MAKE) clean -C $(VIS_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	#$(MAKE) fclean -C $(LIB_PATH)
	#rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

#.SILENT: all $(NAME) $(OBJ) $(OBJ_PATH) clean fclean re
