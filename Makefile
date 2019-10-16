# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/16 21:57:22 by pcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in

OBJ_PATH		= ./src
INC_PATH		= ./include
LIB_PATH		= ./src/lib
VIS_PATH		= .src/lem-in/visualizator
SRC_PATH		= ./src/lem-in
#MAIN_PATH		= ./main/
SDL2_DIR		= ./src/lib/sdl2
SDL2_INC		= ./src/lib/sdl2/SDL2.framework/Headers
SDL2_LIB		= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2

CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror
LFLAGS			= -I $(INC_PATH) -I $(SDL2_INC)
LIB				= -L $(LIB_PATH) -lftprintf $(FRAME)

SRC 			= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c
SRC				+= adj_func.c utility.c ft_exit.c validation.c
SRC				+= direction.c dfs.c bfs.c path_func.c
SRC				+= queue.c suurballe.c renovation.c free_elem.c
SRC				+= tactical_moves.c ants.c listpath_func.c init.c
SRC_VIS			= init.c

OBJ				= $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))
OBJ_VIS			= $(addprefix $(OBJ_PATH)/,$(SRC_VIS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_VIS) $(SDL_LIB) $(SDL)
	@$(MAKE) -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(OBJ_VIS) $(LIB) $(SDL2_LIB) -o $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o:$(VIS_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all
