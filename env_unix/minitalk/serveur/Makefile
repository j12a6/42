#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by jaubert           #+#    #+#              #
#    Updated: 2014/03/08 10:56:20 by jaubert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Werror -Wextra

LIBH =		../libft/includes/

LIBA =		../libft/libft.a

HDFLAGS =	-I$(LIBH)

NAME =		serveur

SRC =		serveur.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(GCC) -o $(NAME) $(OBJ) $(LIBA) $(HDFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean re

%.o:		%.c
			$(GCC) $(HDFLAGS) -c $< -o $@
