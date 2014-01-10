# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 15:40:48 by jaubert           #+#    #+#              #
#    Updated: 2013/12/29 12:57:48 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -pedantic

HDDIR =			./includes/

HDFLAGS =		-I$(HDDIR)

CFILE =			ft_isspace.c		\
				ft_count_digit.c	\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_putstr.c			\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putendl.c		\
				ft_putstr.c			\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putstr_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_free_char2.c		\
				ft_strsplit.c		\
				ft_count_wd.c		\
				get_next_line.c		\
				ft_cpy_char2.c

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

.PHONY:			all clean re fclean

%.o:			%.c
				$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@

