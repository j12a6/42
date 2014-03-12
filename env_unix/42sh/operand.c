/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 18:41:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:09:39 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		ft_is_no_quote(char *line)
{
	if (*line == '|' && *(line + 1) == '|')
		return (OR);
	if (*line == '&' && *(line + 1) == '&')
		return (AND);
	if (*line == '>' && *(line + 1) == '>')
		return (RED_DR);
	if (*line == ';')
		return (SEMI_C);
	if (*line == '<')
		return (RED_L);
	if (*line == '>')
		return (RED_R);
	if (*line == '|')
		return (PIPE);
	if (*line == ' ')
		return (SPACE);
	if (*line == '(')
		return (PTH_B);
	if (*line == ')')
		return (PTH_E);
	return (WORD);
}

static int		ft_is_quote(char *line, int *ind)
{
	if (*ind == 1 && *line == '\'')
	{
		*ind = 0;
		return (QUO_S);
	}
	if (*ind == 2 && *line == '\"')
	{
		*ind = 0;
		return (QUO_D);
	}
	if (*ind == 1 || *ind == 2)
		return (WORD);
	if (*line == '\'')
	{
		*ind = 1;
		return (QUO_S);
	}
	if (*line == '\"')
	{
		*ind = 2;
		return (QUO_D);
	}
	return (0);
}

static int		ft_is_operand(char *line, int *ind, int *type_bs)
{
	int		type;

	if (*type_bs == 1)
	{
		*type_bs = 0;
		return (WORD);
	}
	if (*line == '\\')
		*type_bs = 1;
	if ((type = ft_is_quote(line, ind)))
		return (type);
	type = ft_is_no_quote(line);
	return (type);
}

int				ft_word_size_before_ope(char *line, int *ind, int *type)
{
	int		i;
	int		type_bs;

	type_bs = 0;
	i = 0;
	while (*(line + i)
			&& (*type = ft_is_operand(line + i, ind, &type_bs)) == WORD)
		++i;
	return (i);
}
