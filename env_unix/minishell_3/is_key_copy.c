/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 12:18:19 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 17:08:13 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_key_ctrl_u(char *buf)
{
	if (buf[0] == 21 && buf[1] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_i(char *buf)
{
	if (buf[0] == 9 && buf[1] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_h(char *buf)
{
	if (buf[0] == 8 && buf[1] == 0)
		return (1);
	return (0);
}
