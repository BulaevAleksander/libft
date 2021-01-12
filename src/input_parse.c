/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:12:22 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:12:39 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		pars_links(t_lemin *lemin, t_graph *graph)
{
	char	**tab;
	int		r[2];

	while (pars_head(lemin))
	{
		if (!parse_utils(pars_head(lemin), CHECK_COMMEND))
		{
			if (!(tab = ft_strsplit(pars_head(lemin), '-')))
				terminate(ERROR_MEMORY);
			if (tab_len(tab) != 2 ||
				(r[0] = array_index(graph, tab[0])) < 0 ||
				(r[1] = array_index(graph, tab[1])) < 0)
				terminate(ERROR_INPUT);
			lst_add(graph->nods[r[0]]->edges, r[1], 1);
			lst_add(graph->nods[r[1]]->edges, r[0], 1);
			graph->c_edges += 2;
			tab_delete(tab);
		}
		pars_next(lemin);
	}
}

int			pars_ants(t_lemin *lemin)
{
	int	ants;

	if (parse_utils(pars_next(lemin), CHECK_NANTS))
		if ((ants = (int)ft_atoi(pars_head(lemin))) >= 0)
			return (ants);
	terminate(ERROR_INPUT);
	return (0);
}

void		pars_stdin(t_lemin *lemin)
{
	ft_bzero(lemin, sizeof(t_lemin));
	lemin->ptr = lemin->buffer;
	lemin->nants = pars_ants(lemin);
	lemin->graph = parse_rooms(lemin);
	pars_links(lemin, lemin->graph);
	lemin->paths = paths_fork(lemin->graph, lemin->nants);
}
