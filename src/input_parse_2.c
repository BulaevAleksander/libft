/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:11:52 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:49:20 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

const char		*pars_head(t_lemin *lemin)
{
	if (lemin->end)
		return (NULL);
	else if (!lemin->line)
		pars_next(lemin);
	return (lemin->line);
}

static void		pars_to_next_line(t_lemin *lemin)
{
	lemin->line = lemin->ptr;
	if (!(lemin->ptr = ft_strchr(lemin->ptr, '\n')))
		terminate(ERROR_INPUT);
	*(lemin->ptr) = '\0';
}

const char		*pars_next(t_lemin *lemin)
{
	int			r;
	int			c;

	if (lemin->end)
		return (NULL);
	lemin->ptr++;
	if (ft_strchr(lemin->ptr, '\n') == NULL)
	{
		c = ft_strlen(lemin->ptr);
		ft_memmove(lemin->buffer, lemin->ptr, c + 1);
		lemin->ptr = lemin->buffer;
		r = read(0, lemin->buffer + c, BF - c);
		if (r < 0)
			terminate(ERROR_READ);
		if (r == 0)
		{
			lemin->line = lemin->ptr;
			lemin->end = 1;
			return (lemin->line);
		}
		lemin->buffer[c + r] = '\0';
		write(1, lemin->buffer + c, r);
	}
	pars_to_next_line(lemin);
	return (lemin->line);
}
