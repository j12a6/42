#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:06:10 by makoudad          #+#    #+#              #
#    Updated: 2013/12/14 15:46:20 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = 		gcc -Wall -Wextra -Werror -pedantic

NAME = 		librace.a

SRC = 		ft_strcat.c ft_strncat.c ft_strcpy.c ft_strnew.c ft_strclr.c \
			ft_strsub.c ft_bzero.c ft_putchar.c ft_putendl.c ft_putstr.c \
			ft_strcmp.c ft_strdup.c ft_strlen.c get_next_line.c

OBJ = 		$(SRC:.c=.o)

HDDIR = 	./includes/

HDFLAGS = 	-I$(HDDIR)

RMF = 		rm -f

ARRC = 		ar rc

RANLIB = 	ranlib

all:		$(NAME)

$(NAME):	$(OBJ)
			$(ARRC) $(NAME) $(OBJ)
			$(RANLIB) $(NAME)

clean:
			$(RMF) $(OBJ)

fclean:		clean
			$(RMF) $(NAME)

re:			fclean all

%.o:		%.c
			$(GCC) $(HDFLAGS) -c $< -o $@

.PHONY:		all clean re fclean
