# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2022/07/25 22:56:45 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ WORKS ON LINUX +++++++++++++ #

NAME = so_long
SRCS =	main.c \
		map_checker.c \
		utils.c \
		move.c 
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

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra

$(NAME): $(OBJS) | libft  mlx
	@$(CC) $(^) -L$(LIBFT_LIB_DIR) -lft $(MLX_FLAGS) -o $(@)
	@echo "$(COLOUR_GREEN) >>> SO_LONG OK <<< $(COLOUR_END)"

submodule:
	@git submodule update --init --recursive

all: $(NAME) submodule

%.o: %.c
	@$(CC) $(LIBFT_INCLUDE) $(MLX_INCLUDE) -c $(^) -o $(@)

mlx:
	@make -s -C $(MLX_LIB_DIR)
	@echo "$(COLOUR_YELLOW) >>> MLX OK <<< $(COLOUR_END)"

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

test: all
	@echo "Executing so_long"
	@./$(NAME) map.ber

.PHONY: all clean fclean re libft submodule
