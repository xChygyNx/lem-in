NAME					:= lem-in
OBJ_PATH				:= ./obj
DIR_SRC					:= ./src/lem-in
DIR_SRC_VIS				:= ./src/lem-in/visualizator
DIR_INC					:= ./include
DIR_LIBFT				:= ./src/lib
SDL2_DIR				:= ./src/lib/sdl2
SDL2_INC				:= ./src/lib/sdl2/SDL2.framework/Headers
SDL2_LIB				:= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2


CC						:= gcc
CFLAGS					:= -g -Wall -Wextra -Werror
LFLAGS					:= -I $(INC_PATH) -I $(SDL2_INC)
LIB						:= -L $(LIB_PATH) -lftprintf

SRC 			:= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c\
					adj_func.c utility.c ft_exit.c validation.c\
					direction.c dfs.c bfs.c path_func.c\
					queue.c suurballe.c renovation.c free_elem.c\
					tactical_moves.c ants.c listpath_func.c init.c
SRC_VIS			= init.c


OBJS					:= $(SRCS:.c=.o)
OBJS_WITH_DIR			:= $(addprefix $(OBJ_PATH)/, $(OBJS))
LIBFT					:= libft.a
HEADERS					:= lem_in.h libft.h libftprintf.h visual.h

MAKE_LIBFT				:= make -C $(DIR_LIBFT)
REMOVE					:= rm -rf

vpath %.c $(DIR_SRC) $(SRC_VIS)
vpath %.o $(OBJ_PATH)
vpath %.h $(DIR_INC)
vpath %.a $(DIR_LIBFT)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(CFLAGS) $(OBJS_WITH_DIR) $(LIB) $(SDL2_LIB) -o $@ 

$(OBJS): %.o:%.c $(HEADERS) | $(OBJ_PATH)
	$(CC) -c $(CFLAGS) $< -I $(DIR_INC) -o $(OBJ_PATH)/$@

$(OBJ_PATH):
	mkdir -p $@

clean:
	$(REMOVE) $(OBJ_PATH)
	$(MAKE) clean -C $(LIB_PATH)

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_LIBFT) fclean
	$(MAKE_LS) fclean

re: fclean all

.PHONY: clean fclean re
.SILENT: all $(NAME) $(OBJS) $(DIR_BIN) $(LIBFT) clean fclean re make_other