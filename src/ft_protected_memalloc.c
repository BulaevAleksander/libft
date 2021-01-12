/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protected_memalloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:06:47 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:49:13 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		*ft_protected_memalloc(size_t size, void err_manager(char))
{
	void	*p;

	p = ft_memalloc(size);
	if (p == NULL)
		err_manager(ERROR_MEMORY);
	return (p);
}

size_t		tab_len(char **tab)
{
	size_t	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void		tab_delete(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void		terminate(char err)
{
	ft_printf("\n");
	if (err > 0 && err < 127)
	{
		if (err == ERROR_MEMORY)
			ft_putendl_fd("Error Memory", 2);
		else if (err == ERROR_INPUT || err == ERROR_PATH)
			ft_putendl_fd("ERROR", 2);
		else if (err == ERROR_READ)
			ft_putendl_fd("Error STDIN", 2);
		exit(1);
	}
	ft_printf("Uncatch error");
}
