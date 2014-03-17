/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 10:48:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/21 15:28:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_word_size(char *str, char c)
{
	int		i;
	int		size_of_word;

	i = 0;
	while (*(str + i) && *(str + i) == c)
		++i;
	size_of_word = 0;
	while (*(str + i) && *(str + i) != c)
	{
		++i;
		++size_of_word;
	}
	return (size_of_word);
}
