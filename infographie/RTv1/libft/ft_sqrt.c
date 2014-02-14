/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 19:32:19 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/07 15:52:16 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_sqrt(double n)
{
	double	precision;
	double	elem;

	precision = 0.00001;
	elem = n;
	while ((elem * elem >= n + precision) || (elem * elem <= n - precision))
		elem = (elem + n / elem) / 2;
	return (elem);
}
