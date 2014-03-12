# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 15:40:48 by jaubert           #+#    #+#              #
#    Updated: 2014/01/17 21:43:09 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			filler	

CFILE =			main.c					\
				init_player_info.c		\
				save_map.c				\
				save_piece.c

OFILE =			$(CFILE:.c=.o)

AFILE =			$(LIBDIR)libft.a

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -pedantic -g

HDDIR =			includes/

LIBDIR =		libft/

HDFLAGS =		-I$(HDDIR) -I$(LIBDIR)$(HDDIR)

all:			$(NAME)

$(NAME):		$(OFILE)
				make -C $(LIBDIR)
				$(CC) $(CFLAGS) $(HDFLAGS) -o $(NAME) $(OFILE) $(AFILE)

clean:
				rm -f $(OFILE)

fclean:			clean
				rm -f $(NAME)
				make fclean -C $(LIBDIR)

re:				fclean all

.PHONY:			all clean re fclean

%.o:			%.c
				$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@

