#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:06:10 by makoudad          #+#    #+#              #
#    Updated: 2014/02/07 15:18:28 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = 		gcc -Wall -Wextra -Werror -pedantic -ansi

NAME = 		libft.a

SRC = 		c_call.c						\
			cfree.c							\
			ft_atoi.c						\
			ft_bzero.c						\
			ft_char2_len.c					\
			ft_copy_ts.c					\
			ft_error.c						\
			ft_find.c						\
			ft_free_char2.c					\
			ft_isalnum.c					\
			ft_isalpha.c					\
			ft_isascii.c					\
			ft_isdigit.c					\
			ft_isprint.c					\
			ft_itoa.c						\
			ft_list_mal.c					\
			ft_lstadd.c						\
			ft_lstdel.c						\
			ft_lstdelone.c					\
			ft_lstiter.c					\
			ft_lstmap.c						\
			ft_lstnew.c						\
			ft_memalloc.c					\
			ft_memccpy.c					\
			ft_memchr.c						\
			ft_memcmp.c						\
			ft_memcpy.c						\
			ft_memdel.c						\
			ft_memmove.c					\
			ft_memset.c						\
			ft_put_base.c					\
			ft_put_char2.c					\
			ft_putchar.c					\
			ft_putchar_fd.c					\
			ft_putendl.c					\
			ft_putendl_fd.c					\
			ft_putnbr.c						\
			ft_putnbr_fd.c					\
			ft_putstr.c						\
			ft_putstr_fd.c					\
			ft_sqrt.c						\
			ft_strcat.c						\
			ft_strchr.c						\
			ft_strclr.c						\
			ft_strcmp.c						\
			ft_strcpy.c						\
			ft_strdel.c						\
			ft_strdup.c						\
			ft_strequ.c						\
			ft_striter.c					\
			ft_striteri.c					\
			ft_strjoin.c					\
			ft_strlcat.c					\
			ft_strlen.c						\
			ft_strmap.c						\
			ft_strmapi.c					\
			ft_strncat.c					\
			ft_strncmp.c					\
			ft_strncpy.c					\
			ft_strnequ.c					\
			ft_strnew.c						\
			ft_strnstr.c					\
			ft_strrchr.c					\
			ft_strsplit.c					\
			ft_strsplim.c					\
			ft_strstr.c						\
			ft_strsub.c						\
			ft_strtrim.c					\
			ft_toa.c						\
			ft_tolower.c					\
			ft_toupper.c 					\
			ft_wc_w.c						\
			get_next_line.c					\
			gfree.c							\
			gmalloc.c						\
			grealloc.c						\

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
