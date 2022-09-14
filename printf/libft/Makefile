# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 04:19:24 by anastacia         #+#    #+#              #
#    Updated: 2022/09/13 17:28:18 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = libft.a
SRC = ft_strlen ft_itoa ft_putchar ft_putstr\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I lft.h
AR = ar rc

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(AR) $(NAME) $(SRC:=.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC:=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re