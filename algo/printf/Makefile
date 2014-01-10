# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 10:07:00 by jaubert           #+#    #+#              #
#    Updated: 2013/12/22 19:37:58 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -pedantic -g

HDFLAGS =		-I$(HDDIR)

HDDIR =			./

CFILE =			ft_strlen.c						\
				ft_putchar.c					\
				ft_putstr.c						\
				ft_putnbr.c						\
				ft_putnbr_long.c				\
				ft_putbase.c					\
				ft_putnbr.c						\
				ft_printf.c


OBJ =			$(CFILE:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

%.o:			%.c
				$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@
