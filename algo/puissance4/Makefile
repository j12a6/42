# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 16:07:00 by jaubert           #+#    #+#              #
#    Updated: 2014/03/09 21:26:52 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			puissance4

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -g

HDFLAGS =		-I$(HDDIR) -I./includes/

HDDIR =			./libft/includes/

CFILE =			main.c					\
				play.c					\
				nb_for_row.c			\
				nb_for_column.c			\
				nb_for_diag_up_left.c	\
				nb_for_diag_up_right.c	\
				update_choices.c		\
				have_won.c				\
				reset_save_board.c		\
				print_grid.c

OBJ =			$(CFILE:.c=.o)

AFILE =			./libft/libft.a

LIBMAKE =		make -C libft/

all:			$(NAME)

$(NAME):		$(OBJ)
				$(LIBMAKE)
				$(CC) $(CFLAGS) $(HDFLAGS) -o $(NAME) $(OBJ) $(AFILE)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)
				$(LIBMAKE) fclean

re:				fclean all

lib_all:
				$(LIBMAKE)

lib_clean:
				$(LIBMAKE) clean

lib_fclean:
				$(LIBMAKE) fclean

lib_re:
				$(LIBMAKE) re

.PHONY:			all clean fclean re lib_all lib_clean lib_fclean lib_re

%.o:			%.c
				$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@
