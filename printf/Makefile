# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 05:34:24 by anastacia         #+#    #+#              #
#    Updated: 2022/09/13 17:28:05 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = libftprintf.a
SRC = ft_printf ft_put_di ft_put_u ft_put_base\
	ft_put_pointer ft_put_base_hex ft_put_hex ft_put_base_pointer\
	libft/ft_putchar libft/ft_putstr libft/ft_itoa libft/ft_strlen

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.
AR = ar rc

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(AR) $(NAME) $(SRC:=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC:=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re