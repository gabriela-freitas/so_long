# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:37:12 by gafreita          #+#    #+#              #
#    Updated: 2022/06/23 19:37:13 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_ALL =	sources/memory/ft_memchr.c \
			sources/memory/ft_realloc.c \
			sources/memory/ft_calloc.c \
			sources/memory/ft_bzero.c \
			sources/memory/ft_memset.c \
			sources/memory/ft_memcmp.c \
			sources/memory/ft_memcpy.c \
			sources/memory/ft_memmove.c \
			sources/str_new/ft_substr.c \
			sources/str_new/ft_striteri.c \
			sources/str_new/ft_split.c \
			sources/str_new/ft_strmapi.c \
			sources/str_h/ft_strlcat.c \
			sources/str_h/ft_strdup.c \
			sources/str_h/ft_strnstr.c \
			sources/str_h/ft_strrchr.c \
			sources/str_h/ft_strncmp.c \
			sources/str_h/ft_strjoin.c \
			sources/str_h/ft_tolower.c \
			sources/str_h/ft_strchr.c \
			sources/str_h/ft_strlcpy.c \
			sources/str_h/ft_strtrim.c \
			sources/str_h/ft_strlen.c \
			sources/str_h/ft_toupper.c \
			sources/ft_lists/ft_lstnew.c \
			sources/ft_lists/ft_lstiter.c \
			sources/ft_lists/ft_lstsize.c \
			sources/ft_lists/ft_lstdelone.c \
			sources/ft_lists/ft_lstclear.c \
			sources/ft_lists/ft_lstadd_front.c \
			sources/ft_lists/ft_lstadd_back.c \
			sources/ft_lists/ft_lstlast.c \
			sources/ft_lists/ft_lstmap.c \
			sources/converters/ft_itoa.c \
			sources/converters/ft_atoi.c \
			sources/checkers/ft_isascii.c \
			sources/checkers/ft_isdigit.c \
			sources/checkers/ft_isprint.c \
			sources/checkers/ft_isalnum.c \
			sources/checkers/ft_isalpha.c \
			sources/get_next_line/get_next_line.c \
			sources/print/ft_putstr_fd.c \
			sources/print/count_printf.c \
			sources/print/ft_putnbr_fd.c \
			sources/print/ft_putendl_fd.c \
			sources/print/ft_printf.c \
			sources/print/ft_putchar_fd.c \

OBJS_ALL =	$(SRCS_ALL:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB_DIR = include/

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m

.c.o:
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -c $(<) -o $(@)

all: $(NAME)

$(NAME): $(OBJS_ALL)
	@ar rcs $(NAME) $(OBJS_ALL)
	@echo "$(COLOUR_GREEN)LIBFT OK$(COLOUR_END)"
# @mkdir -p obj
# @mv $(OBJS_ALL) obj


clean:
	@rm -f $(OBJS_ALL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
