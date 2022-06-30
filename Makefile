# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2022/06/30 15:15:14 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ WORKS ON LINUX +++++++++++++ #

NAME = so_long
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

CCFLAGS = gcc -Wall -Wextra -Werror -g
#directories with .a
LIBFT_LIB_DIR = LIBFT/
MLX_LIB_DIR = mlx_linux/
#directories with .h
LIBFT_INCLUDE = -ILIBFT/include
MLX_INCLUDE = -Imlx_linux

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra

$(NAME): $(OBJS) | libft
	@$(CC) $(^) -L$(LIBFT_LIB_DIR) -lft $(MLX_FLAGS) -o $(@)
	@echo "$(COLOUR_GREEN) >>> SO_LONG OK <<< $(COLOUR_END)"

submodule:
	@git submodule update --init --recursive

all: $(NAME) submodule

%.o: %.c
	@$(CC) $(LIBFT_INCLUDE) $(MLX_INCLUDE) -c $(^) -o $(@)

libft:
	@make -s -C $(LIBFT_LIB_DIR)

clean:
	@make clean -s -C $(LIBFT_LIB_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -s -C $(LIBFT_LIB_DIR)
	@rm -f $(NAME)
	@echo "$(COLOUR_YELLOW) SO_LONG CLEANED $(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re libft submodule
