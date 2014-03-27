# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/20 15:44:10 by jaubert           #+#    #+#              #
#    Updated: 2014/03/27 18:44:52 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			RT

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -g

MINIFLAGS =		-L/usr/X11/lib -lmlx -lXext -lX11

HDFLAGS =		-I$(HDDIR) -I./includes/

HDDIR =			./libft/includes/

CFILE =			main.c							\
				sol_equ_quadratic.c				\
				camera.c						\
				operations_on_colors.c			\
				operations_on_vectors.c			\
				operations_on_vectors_2.c		\
				operations_on_matrix.c			\
				intersecting_a_box.c			\
				intersecting_a_sphere.c			\
				intersecting_a_plane.c			\
				intersecting_a_disk.c			\
				intersecting_a_cone.c			\
				intersecting_a_cylinder.c		\
				draw.c							\
				init_object_structure.c			\
				treat_a_sphere.c				\
				treat_a_box.c					\
				treat_a_disk.c					\
				treat_a_plane.c					\
				treat_a_cone.c					\
				treat_a_cylinder.c				\
				ft_diffuse_object.c				\
				ft_hit_light.c					\
				ft_error.c

OBJ =			$(CFILE:.c=.o)

AFILE =			./libft/libft.a

LIBMAKE =		make -C libft/

all:			$(NAME)

$(NAME):		$(OBJ)
				$(LIBMAKE)
				$(CC) $(MINIFLAGS) $(CFLAGS) $(HDFLAGS) -o $(NAME) $(OBJ) $(AFILE)

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
