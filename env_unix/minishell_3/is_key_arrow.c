/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 16:47:29 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 17:07:45 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_key_arrow_left(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
		return (1);
	return (0);
}

int		ft_is_key_arrow_right(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
		return (1);
	return (0);
}

int		ft_is_key_arrow_up(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
		return (1);
	return (0);
}

int		ft_is_key_arrow_down(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
		return (1);
	return (0);
}
