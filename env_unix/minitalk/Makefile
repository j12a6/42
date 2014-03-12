#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by jaubert           #+#    #+#              #
#    Updated: 2014/03/08 10:54:23 by jaubert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

MAKELIB =	make -C libft/

MAKESERV =	make -C serveur/

MAKECLI =	make -C client/

all:
			$(MAKELIB) all
			$(MAKESERV) all
			$(MAKECLI) all

clean:
			$(MAKELIB)	clean
			$(MAKESERV)	clean
			$(MAKECLI)	clean

fclean:		clean
			$(MAKELIB)	fclean
			$(MAKESERV)	fclean
			$(MAKECLI)	fclean

re:			fclean all

.PHONY:		clean fclean re all
