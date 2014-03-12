/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 09:14:55 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/08 10:56:01 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	ft_signal(int sign)
{
	if (sign == SIGUSR1)
		return ;
	else if (sign == SIGUSR2)
		return ;
}

void	ft_send_bit_by_bit(char c, pid_t pid_s)
{
	int		tmp;
	int		i;

	tmp = 1;
	i = -1;
	while (++i < 8)
	{
		if (c & tmp)
			kill(pid_s, SIGUSR1);
		else
			kill(pid_s, SIGUSR2);
		usleep(10);
/*		if (usleep(1000) == 0)
			--i;
		else*/
			tmp = tmp << 1;
	}
}

void	ft_send_pid_bit_by_bit(pid_t pid_c, pid_t pid_s)
{
	int		tmp;
	int		i;

	tmp = 1;
	i = -1;
	while (++i < 32)
	{
		if (pid_c & tmp)
			kill(pid_s, SIGUSR1);
		else
			kill(pid_s, SIGUSR2);
		usleep(10);
		tmp = tmp << 1;
	}
}

void	ft_send_string(char *str, pid_t pid_s)
{
	int		i;

	i = -1;
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	while (str[++i])
		ft_send_bit_by_bit(str[i], pid_s);
}


int		main(int ac, char **av)
{
	pid_t		pid_s;
	pid_t		pid_c;
	pid_t		len;

	if (ac != 3)
	{
		ft_putendl_fd("Too few or too many arguments", 2);
		return (0);
	}
	pid_s = (pid_t)ft_atoi(av[1]);
	pid_c = getpid();
	ft_send_pid_bit_by_bit(pid_c, pid_s);
	ft_putstr("pid_c = ");
	ft_putnbr(pid_c);
	ft_putchar('\n');
	len = (pid_t)ft_strlen(av[2]);
	ft_putstr("len = ");
	ft_putnbr(len);
	ft_putchar('\n');
	ft_send_pid_bit_by_bit(len, pid_s);
	ft_send_string(av[2], pid_s);
	return (0);
}
