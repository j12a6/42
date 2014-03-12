/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_cut_paste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 14:20:04 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/06 17:50:24 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_key_ctrl_r(char *buf)
{
	if (buf[0] == 18 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_t(char *buf)
{
	if (buf[0] == 20 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_f(char *buf)
{
	if (buf[0] == 6 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_g(char *buf)
{
	if (buf[0] == 7 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		return (1);
	return (0);
}
