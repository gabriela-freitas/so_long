# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 20:35:26 by gafreita          #+#    #+#              #
#    Updated: 2022/06/26 17:20:08 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

CCFLAGS = gcc -Wall -Wextra -Werror -g
#directories with .a
LIBFT_LIB_DIR = LIBFT/
#directories with .h
LIBFT_INCLUDE = -ILIBFT/include

UNAME = $(shell uname)

LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -L$(LMLX) -L$(LIBFT_DIR) -lft

ifeq ($(UNAME), Darwin)
	# mac
	CC = gcc
	LFLAGS = -L$(MLX_DIR) -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -lft
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

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
