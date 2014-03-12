/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:49:40 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

int			ft_init_tree(t_tree **t)
{
	if (!(*t = (t_tree *)gmalloc(sizeof(**t))))
		return (-1);
	(*t)->fa = NULL;
	(*t)->le = NULL;
	(*t)->ri = NULL;
	(*t)->p = NULL;
	return (0);
}

t_p			*ft_p_list_new_elem(char *tok, int type)
{
	t_p		*new;

	if (!(new = (t_p *)gmalloc(sizeof(t_p))))
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->tok = ft_strdup(tok);
	new->type = type;
	return (new);
}

int			ft_p_list_sub(t_p **list, t_p *start, t_p *end)
{
	t_p		*new;
	t_p		*move;

	move = NULL;
	while (start != end)
	{
		if (!(new = ft_p_list_new_elem(start->tok, start->type)))
			return (-1);
		if (move)
		{
			move->next = new;
			new->prev = move;
			move = new;
		}
		else
		{
			*list = new;
			move = *list;
		}
		start = start->next;
	}
	return (0);
}

int			ft_new_tree_elem(t_tree **t, t_p *keep)
{
	if (ft_init_tree(&((*t)->le)) == -1 || ft_init_tree(&((*t)->ri)) == -1)
		return (-1);
	(*t)->le->fa = *t;
	(*t)->ri->fa = *t;
	if (ft_p_list_sub(&((*t)->le->p), (*t)->p, keep) == -1)
		return (-1);
	if (ft_p_list_sub(&((*t)->ri->p), keep->next, NULL) == -1)
		return (-1);
	(*t)->p->type = keep->type;
	ft_free_list((*t)->p->next);
	(*t)->p->next = NULL;
	gfree((void *)(*t)->p->tok);
	(*t)->p->tok = NULL;
	if ((*t)->le->p)
	{
		if (ft_syntaxical_analyzer(&((*t)->le)) == -1)
			return (-1);
	}
	if ((*t)->ri->p)
	{
		if (ft_syntaxical_analyzer(&((*t)->ri)) == -1)
			return (-1);
	}
	return (0);
}

int			ft_put_parenthesis_in_tree(t_tree **t)
{
	t_p		*move;

	move = (*t)->p;
	if ((*t)->p->type == PTH_B && (*t)->p->next->type == PTH_E)
		return (ft_error_msg("badly placed ", "()'s"));
	if (ft_init_tree(&((*t)->le)) == -1)
		return (-1);
	(*t)->le->fa = *t;
	while (move && move->next)
		move = move->next;
	if (ft_p_list_sub(&((*t)->le->p), (*t)->p->next, move) == -1)
		return (-1);
	ft_free_list((*t)->p->next);
	(*t)->p->next = NULL;
	gfree((void *)(*t)->p->tok);
	(*t)->p->tok = NULL;
	(*t)->p->type = PTH;
	return (0);
}
