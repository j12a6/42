/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 16:57:37 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/06 14:28:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int		main(void)
{
	int		fd;
	char	*line;
fd = 0;
//	fd = open("text.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr("line = ");
		ft_putstr(line);
		ft_putchar('\n');
		free((void *)line);
	}
	ft_putstr(line);
	close(fd);
/*	fd = open("text.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr("line = ");
		ft_putstr(line);
		ft_putchar('\n');
		free((void *)line);
	}
	close(fd);
	
	fd = open("text.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr("line = ");
		ft_putstr(line);
		ft_putchar('\n');
		free((void *)line);
	}
	close(fd);*/
	return (0);
}
