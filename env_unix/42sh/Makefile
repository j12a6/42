#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/03/05 14:17:00 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Werror -Wextra -g

LIBH =		./libft/includes/

LIBA =		./libft/libft.a

LIBLS =		./includes/

HDFLAGS =	-I$(LIBH) -I$(LIBLS)

MAKELIB =	make -C libft/

NAME =		ft_sh

SRC =		main.c							\
			change_terminal_mode.c			\
			save_line.c						\
			is_key_arrow.c					\
			is_key_ctrl_d.c					\
			is_key_change_line.c			\
			is_key_copy.c					\
			is_key_cut_paste.c				\
			is_key_del_or_enter.c			\
			is_key_fast_move.c				\
			ft_len.c						\
			ft_list_put_elem.c				\
			fast_cursor_move.c				\
			ft_change_line.c				\
			ft_list_del.c					\
			print.c							\
			ft_cut_copy_or_paste.c			\
			do_line.c						\
			historic.c						\
			ft_check_env_and_signal.c		\
			operand.c						\
			delete_backslashes.c			\
			delete_quotes_and_spaces.c		\
			lexical_analyzer.c				\
			syntaxical_analyzer.c			\
			find_priority_operand.c			\
			create_tree.c					\
			execute_all.c					\
			perform_cmd.c					\
			perform_all_redir.c				\
			echo.c							\
			ft_value.c						\
			ft_cd.c							\
			ft_env.c						\
			ft_unsetenv.c					\
			exe_the_cmd.c					\
			ft_setenv.c						\
			free.c							\
			ft_exit.c


OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB)
			$(GCC) -o $(NAME) $(OBJ) $(LIBA) $(HDFLAGS) -ltermcap

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

lall:
			$(MAKELIB)

lclean:
			$(MAKELIB) clean

lfclean:
			$(MAKELIB) fclean

lre:		lfclean lall

.PHONY:		clean fclean re all lall lclean lfclean lre

%.o:		%.c
			$(GCC) $(HDFLAGS) -c $< -o $@
