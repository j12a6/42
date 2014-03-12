/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 13:06:58 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:09:19 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

int		ft_new_token(t_p **p, char **line, int size, int type)
{
	t_p		*new;
	t_p		*move;

	if (!(new = (t_p *)gmalloc(sizeof(t_p))))
		return (-1);
	if (!(new->tok = ft_strsub(*line, 0, size)))
		return (-1);
	*line = *line + size;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	move = *p;
	if (*p)
	{
		while (move->next)
			move = move->next;
		new->prev = move;
		move->next = new;
	}
	else
		*p = new;
	return (0);
}

void	ft_differentiate_word_types(t_p **p)
{
	t_p		*move;

	move = *p;
	while (move)
	{
		if (move->type == WORD)
		{
			if (!move->prev)
				move->type = CMD;
			else if (move->prev->type == WORD || move->prev->type == RED_R
					|| move->prev->type == RED_DR || move->prev->type == RED_L
					|| move->prev->type == CMD || move->prev->type == ARG)
				move->type = ARG;
			else
				move->type = CMD;
		}
		move = move->next;
	}
}

int		ft_clean_list(t_p **p, int ind)
{
	if (ft_delete_quotes_and_spaces(p, ind) == -1)
		return (-1);
	if (ft_delete_backslashes(p) == -1)
		return (-1);
	if (ft_check_wrong_nb_of_pth(*p) == -1)
		return (-1);
	ft_differentiate_word_types(p);
	return (0);
}

int		ft_lexical_analyzer(char *line, t_p **p)
{
	int		ind;
	int		type;
	int		size;

	ind = 0;
	while (*line)
	{
		size = ft_word_size_before_ope(line, &ind, &type);
		if (size != 0)
			ft_new_token(p, &line, size, WORD);
		if (!*line)
			break ;
		size = (type == AND || type == OR || type == RED_DR) ? 2 : 1;
		ft_new_token(p, &line, size, type);
	}
	if (ft_clean_list(p, ind) == -1)
		return (-1);
	return (0);
}
