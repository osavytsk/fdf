# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 18:31:53 by osavytsk          #+#    #+#              #
#    Updated: 2018/10/30 18:33:34 by osavytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
LIB_DIR = ./libft/
MLX_DIR = ./minilibx/

_SRC = printing.c keycode.c main.c mtx_manip.c \
		parsing.c reading.c addit.c \

SRC = $(_SRC:%.c=$(SRC_DIR)%.c)$
OBJ = $(_SRC:%.c=%.o)$

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft -g -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: fclean all