NAME					:= lem-in
OBJ_PATH				:= ./obj
DIR_SRC					:= ./src/lem-in
DIR_SRC_VIS				:= ./src/elm-in/visualizator
DIR_INC					:= ./include
DIR_LIBFT				:= .lib/libft/
SDL2_DIR				:= ./src/lib/sdl2
SDL2_INC				:= ./src/lib/sdl2/SDL2.framework/Headers
SDL2_LIB				:= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2


CC						:= gcc
CFLAGS					:= -g -Wall -Wextra -Werror
LFLAGS					:= -I $(INC_PATH) -I $(SDL2_INC)
LIB						:= -L $(LIB_PATH) -lftprintf $(FRAME)

SRC 			:= lem_in.c create_lem.c add_edges_to_lem.c check_lem.c\
					adj_func.c utility.c ft_exit.c validation.c\
					direction.c dfs.c bfs.c path_func.c\
					queue.c suurballe.c renovation.c free_elem.c\
					tactical_moves.c ants.c listpath_func.c init.c
SRC_VIS			= init.c


OBJS					:= $(SRCS:.c=.o)
OBJS_WITH_DIR			:= $(addprefix $(OBJ_PATH), $(OBJS))
LIBFT					:= libft.a

MAKE_LIBFT				:= make -C $(DIR_LIBFT)
MAKE_LS					:= make -C $(DIR_LS)
REMOVE					:= rm -rf

vpath %.c $(DIR_SRC) $(SRC_VIS)
vpath %.o $(DIR_BIN)
vpath %.h $(DIR_INC)
vpath %.a $(DIR_LIBFT)

all: make_other $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_WITH_DIR) $(LIB) $(SDL2_LIB) -o $@ 

$(OBJS): %.o:%.c $(HEADERS) | $(DIR_BIN)
	$(CC) $(CFLAG) $(CFLAGS) $< $(addprefix $(IFLAG), $(DIRS_INC)) $(NFLAG) $(DIR_BIN)$@

$(OBJ_PATH):
	mkdir -p $@

make_other:
	$(MAKE_LIBFT)
	$(MAKE_LS)

clean:
	$(REMOVE) $(OBJS_WITH_DIR)
	$(REMOVE) $(DIR_BIN)
	$(MAKE_LIBFT) clean
	$(MAKE_LS) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_LIBFT) fclean
	$(MAKE_LS) fclean

re: fclean all

echo:
	echo $(DIR_INCLUDE_MINISHELL)

.PHONY: clean fclean re
.SILENT: all $(NAME) $(OBJS) $(DIR_BIN) $(LIBFT) clean fclean re make_other