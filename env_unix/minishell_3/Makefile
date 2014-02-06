# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 15:40:48 by jaubert           #+#    #+#              #
#    Updated: 2014/01/31 07:40:14 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_minishell3

CFILE =			main.c					\
				ft_mysh_exit.c			\
				ft_pwd.c				\
				ft_env.c				\
				ft_change_env.c			\
				ft_cd.c					\
				ft_setenv.c				\
				ft_unsetenv.c			\
				ft_my_bin.c				\
				ft_syst_bin.c			\
				ft_run_small_part.c		\
				ft_run_middle_part_1.c	\
				treat_redir.c			\
				ft_run_middle_part_2.c	\
				ft_run_big_part.c

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

