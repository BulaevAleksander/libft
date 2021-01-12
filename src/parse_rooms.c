/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:18:57 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:59:53 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		*parsing_name(const char *line)
{
	char		**t;
	char		*name;

	if (!(t = ft_strsplit(line, ' ')))
		terminate(ERROR_MEMORY);
	if (tab_len(t) != 3 || !parse_utils(t[0], CHECK_ISROOM) ||
		!parse_utils(t[1], CHECK_COORD) || !parse_utils(t[2], CHECK_COORD))
		terminate(ERROR_INPUT);
	name = t[0];
	free(t[1]);
	free(t[2]);
	free(t);
	return (name);
}

static void		parsing_start(t_lemin *in, t_array *names, char **start)
{
	if (*start)
		terminate(ERROR_INPUT);
	while (parse_utils(pars_next(in), CHECK_COMMEND))
		continue;
	*start = parsing_name(pars_head(in));
	array_append(names, *start);
}

static void		parsing_end(t_lemin *in, t_array *names, char **end)
{
	if (*end)
		terminate(ERROR_INPUT);
	while (parse_utils(pars_next(in), CHECK_COMMEND))
		continue;
	*end = parsing_name(pars_head(in));
	array_append(names, *end);
}

t_graph			*parse_rooms(t_lemin *lemin)
{
	t_array		*names;
	char		*start;
	char		*end;

	names = array_new();
	start = NULL;
	end = NULL;
	while (pars_next(lemin) && !parse_utils(pars_head(lemin), CHECK_LINK))
	{
		if (parse_utils(pars_head(lemin), CHECK_START))
			parsing_start(lemin, names, &start);
		else if (parse_utils(pars_head(lemin), CHECK_END))
			parsing_end(lemin, names, &end);
		else if (!parse_utils(pars_head(lemin), CHECK_COMMEND))
			array_append(names, parsing_name(pars_head(lemin)));
	}
	if (!start || !end)
		terminate(ERROR_INPUT);
	if (names->size < 1)
		terminate(ERROR_INPUT);
	return (graph_name(names, start, end));
}
