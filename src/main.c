/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:34:44 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:59:47 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				main(int argc, char **argv)
{
	t_lemin in;

	if (argc != 1 && argv)
	{
		ft_putstr("Usage: lem-in < addr_map\n");
		exit(0);
	}
	pars_stdin(&in);
	lemin(&in);
	graph_del(&in);
}
