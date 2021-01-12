/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:12:43 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:49:24 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static size_t	step_once(t_lnk **ants, t_lemin *in)
{
	size_t		i[2];

	ft_bzero(i, sizeof(i));
	while (i[0] < in->nants)
	{
		if (ants[i[0]])
		{
			if (i[1] > 0)
				ft_printf("%cL%i-%s", ' ', i[0] + 1,
						in->graph->names->arr[ants[i[0]]->v]);
			else
				ft_printf("%cL%i-%s", '\n', i[0] + 1,
						in->graph->names->arr[ants[i[0]]->v]);
			i[1]++;
			ants[i[0]] = ants[i[0]]->nxt;
		}
		i[0]++;
	}
	return (i[1]);
}

void			lemin(t_lemin *lemin)
{
	t_lnk		**ants;
	int			activ_ants;
	int			i;

	activ_ants = 0;
	ants = ft_protected_memalloc(sizeof(t_lnk *) * lemin->nants, terminate);
	while (activ_ants < (int)lemin->nants)
	{
		i = -1;
		while (++i < (int)lemin->paths->paths && activ_ants < (int)lemin->nants)
		{
			if (lemin->paths->assigm[i])
				ants[activ_ants++] = paths_navigate(lemin->paths, i);
		}
		step_once(ants, lemin);
	}
	while (step_once(ants, lemin) > 0)
		continue ;
	ft_printf("\n");
	free(ants);
}
