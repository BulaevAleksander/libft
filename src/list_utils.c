/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:14:48 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:49:33 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		lst_add(t_li_list *lst, int val, char act)
{
	t_lnk	*link;

	link = ft_protected_memalloc(sizeof(t_lnk), terminate);
	link->v = val;
	if (act == 0)
	{
		link->prv = lst->last;
		lst->size++;
		lst->last = link;
		if (lst->size == 1)
			lst->first = link;
		else
			lst->last->prv->nxt = link;
	}
	else if (act == 1)
	{
		link->nxt = lst->first;
		lst->size++;
		lst->first = link;
		if (lst->size == 1)
			lst->last = link;
		else
			lst->first->nxt->prv = lst->first;
	}
}

int			lst_pop(t_li_list *lst)
{
	t_lnk	*tmp;
	int		val;

	val = lst->first->v;
	tmp = lst->first;
	lst->first = lst->first->nxt;
	free(tmp);
	lst->size--;
	if (lst->size == 0)
		lst->last = NULL;
	else
		lst->first->prv = NULL;
	return (val);
}
