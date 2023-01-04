# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:34:08 by mruiz-sa          #+#    #+#              #
#    Updated: 2023/01/04 13:33:36 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = 	src/cub3d.c \
		src/checkers.c \
		src/mlx_tools.c \
		src/raycasting.c

CC = gcc
INCLUDES = -I include -I libft -I minilibx/mlx.h
CFLAGS = -Wall -Werror -Wextra $(INCLUDES) -g3
LINKS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

.SILENT:

OBJECTS = $(SRC:.c=.o)

$(NAME): $(OBJECTS)
	@clear
	@make -C minilibx
	@make bonus -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(LINKS) $(OBJECTS) libft/libft.a -o $(NAME)
	@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean: 
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS)

fclean: clean
	@make clean -C ./minilibx
	@make clean -C ./libft
	@rm -rf $(NAME)
	@rm -rf libmlx.a
	@rm -rf libft.a
	@rm -rf cub3d.a

re: fclean all

.PHONY: all clean re