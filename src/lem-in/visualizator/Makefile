# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:09:28 by pcredibl          #+#    #+#              #
#    Updated: 2019/10/18 16:39:18 by pcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_PATH		:= ../../lib
INC_DIR			:= ../../../include
DIR_SDL2		:= ../../lib/sdl2
INC_SDL2		:= ../../lib/sdl2/SDL2.framework/Headers
LIB-SDL2		:= -Wl,-rpath,$(SDL2_DIR) -F $(SDL2_DIR) -framework SDL2

INC				:= -I $(INC_DIR) -I $(INC_SDL2)
LIB				:= -L $(LIB_PATH) -lftprintf $(LIB_SDL2)

CC				:= gcc
CSLAGS			:= -g -Wall -Werror -Wextra

SRC_VIS			:= init.c

OBJ_VIS_PATH		:= ../../../obj
OBJ_VIS			:= $(SRC_VIS:.c=.o)

vpath %.c ./
vpath %.o $(OBJ_VIS_PATH)
vpath %.h $(INC_DIR) $(INC_SDL2)


all: $(OBJ_VIS_PATH) $(OBJ_VIS)

$(OBJ_VIS): %.o:%.c
	$(MAKE) -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(INC) $(LIB) -o $(OBJ_VIS_PATH)/$@  -c $<

$(OBJ_VIS_PATH):
	mkdir -p $@


#.SILENT: all $(OBJ) $(OBJ_VIS_PATH) clean re