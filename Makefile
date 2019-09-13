# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:47:32 by pcredibl          #+#    #+#              #
#    Updated: 2019/09/13 20:19:39 by astripeb         ###   ########.fr        #
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
SRC				+= direction.c dfs.c bfs.c path_func.c bfs_utility.c
SRC				+= queue.c suurballe.c renovation.c buffer.c

OBJ				= $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

#вставить CFLAGS перед сдачей
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	$(CC) -g $(LFLAGS) $(OBJ) $(LIB) -o $(NAME)

#вставить CFLAGS перед сдачей
$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	$(CC) -g $(LFLAGS) -o $@ -c $<

norm:
	norminette $(LIB_PATH) | grep "E"
	norminette $(SRC_PATH) | grep "E"
	norminette $(INC_PATH) | grep "E"

clean:
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all
