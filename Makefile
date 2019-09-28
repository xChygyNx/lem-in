# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/09/28 10:45:46 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in

OBJ_PATH		= ./src
INC_PATH		= ./include
LIB_PATH		= ./src/lib
SRC_PATH		= ./src/lem-in
MAIN_PATH		= ./main/

CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror
LFLAGS			= -I $(INC_PATH)
LIB				= -L $(LIB_PATH) -lftprintf

SRC 			= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c
SRC				+= adj_func.c utility.c ft_exit.c validation.c
SRC				+= direction.c dfs.c bfs.c path_func.c
SRC				+= queue.c suurballe.c renovation.c free_elem.c
SRC				+= tactical_moves.c ants.c listpath_func.c

OBJ				= $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

norm:
	norminette $(LIB_PATH) | grep "E"
	norminette $(SRC_PATH) | grep "E"
	norminette $(INC_PATH) | grep "E"

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all
