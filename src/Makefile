# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 08:24:28 by anastacia         #+#    #+#              #
#    Updated: 2022/09/15 14:42:24 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = so_long
SRC = so_long\
		check_map check_map2\
		moves moves2 animation\
		window window2\
		../get_next_line/get_next_line\
		../get_next_line/get_next_line_utils\


PRINTF = ../printf/libftprintf.a
PRINTF_PATH = ../printf

LIBFT = ../libft/libft.a
LIBFT_PATH = ../libft


CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address
LINKS = -L../mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(SRC:=.o)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LIBFT) $(PRINTF) $(LINKS) -o $(NAME)
	echo "\033[1;36mSo_long is ready!" 

%.o: %.c
	$(CC) $(CFLAGS) -I usr/include -Imlx_linux  -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	$(RM) $(NAME) $(SRC:=.o)
	echo "\033[1;36mSo_long files removed!"

fclean: clean
	$(RM) $(LIBFT) $(PRINTF)
	echo "\033[1;36mTotally clean!"

re: fclean all

.PHONY: all clean fclean re