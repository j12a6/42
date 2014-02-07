# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 15:40:48 by jaubert           #+#    #+#              #
#    Updated: 2014/02/07 12:55:03 by jaubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_minishell3

CFILE =			main.c						\
				save_cmd_line.c				\
				ft_put_or_del_char.c		\
				only_a_cursor_move.c		\
				move_cursor_up_or_down.c	\
				cut_copy_or_paste.c			\
				ft_list_put_elem.c			\
				ft_list_del_elem.c			\
				ft_lists_len.c				\
				ft_putc.c					\
				ft_slist_to_ts.c			\
				ft_move_in_history.c		\
				update_history.c			\
				is_key_arrow.c				\
				is_key_change_line.c		\
				is_key_copy.c				\
				is_key_cut_or_paste.c		\
				is_key_del_or_enter.c		\
				is_key_fast_move.c			\
				print_line.c				\
				my_sh_exit.c				\
				ft_pwd.c					\
				ft_env.c					\
				ft_change_env.c				\
				ft_cd.c						\
				ft_setenv.c					\
				ft_unsetenv.c				\
				my_bin.c					\
				ft_syst_bin.c				\
				ft_run_small_part.c			\
				ft_run_middle_part_1.c		\
				treat_redir.c				\
				ft_run_middle_part_2.c		\
				ft_run_big_part.c			\
				ft_treat_cmd_line.c

OFILE =			$(CFILE:.c=.o)

AFILE =			$(LIBDIR)libft.a

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror

HDDIR =			includes/

LIBDIR =		libft/

HDFLAGS =		-I$(HDDIR) -I$(LIBDIR)$(HDDIR)

all:			$(NAME)

$(NAME):		$(OFILE)
				make -C $(LIBDIR)
				$(CC) $(CFLAGS) $(HDFLAGS) -o $(NAME) $(OFILE) $(AFILE) -ltermcap

clean:
				rm -f $(OFILE)

fclean:			clean
				rm -f $(NAME)
				make fclean -C $(LIBDIR)

re:				fclean all

.PHONY:			all clean re fclean

%.o:			%.c
				$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@

