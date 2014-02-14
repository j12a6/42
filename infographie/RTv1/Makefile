# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 16:07:00 by jaubert           #+#    #+#              #
#    Updated: 2014/02/13 18:18:26 by makoudad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			RTv1

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -g

MINIFLAGS =		-L/usr/X11/lib -lmlx -lXext -lX11

HDFLAGS =		-I$(HDDIR) -I./includes/

HDDIR =			./libft/includes/

CFILE =			main.c					\
				raytracing.c			\
				sol_equ_quadratic.c		\
				operation_on_vectors.c	\
				create_light_list.c		\
				create_plane_list.c		\
				create_sphere_list.c	\
				find_nearest_plane.c	\
				find_nearest_sphere.c	\
				ft_atod.c				\
				nearest_object.c		\
				save_scene.c			\
				draw_pixel_in_image.c

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
