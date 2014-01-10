# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 16:07:00 by jaubert           #+#    #+#              #
#    Updated: 2013/12/15 20:35:24 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_ls

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -pedantic -g

HDFLAGS =		-I$(HDDIR)

HDDIR =			./libft/includes/

CFILE =			ft_ls.c							\
				ft_ls_l.c						\
				ft_create_list.c				\
				ft_sort.c						\
				ft_sort_t.c						\
				ft_print_list.c					\
				ft_in_string.c

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
