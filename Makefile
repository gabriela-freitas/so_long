# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2022/06/25 20:53:39 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

CCFLAGS = gcc -Wall -Wextra -Werror -g
#directories with .a
LIBFT_LIB_DIR = LIBFT/
MLX_LIB_DIR = /usr/local/lib/
#directories with .h
LIBFT_INCLUDE = -ILIBFT/include
MLX_INCLUDE = -I/usr/local/include/mlx.h

MLX_MAC_FLAGS = -L$(MLX_LIB_DIR) -lmlx -framework OpenGL -framework AppKit

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# ^ primeira dependencia
# @ nome da regra


$(NAME): $(OBJS) | libft
	@$(CC) $(^) -L$(LIBFT_LIB_DIR) -lft $(MLX_MAC_FLAGS) -o $(@)
	@echo "$(COLOUR_GREEN) >>> SO_LONG OK <<< $(COLOUR_END)"

submodule:
	@git submodule update --init --recursive

all: $(NAME) submodule

%.o: %.c
	@$(CC) $(LIBFT_INCLUDE) $(MLX_INCLUDE) -c $(^) -o $(@)

libft:
	@make -C $(LIBFT_LIB_DIR)

clean:
	@make clean -C $(LIBFT_LIB_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_LIB_DIR)
	@rm -f $(NAME)
	@echo "$(COLOUR_YELLOW) SO_LONG CLEANED $(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re libft submodule
