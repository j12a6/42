/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ts_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 10:28:50 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:09:17 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ts_len(char **ts)
{
	int		i;

	i = 0;
	while (ts[i])
		++i;
	return (i);
}