/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:18:02 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 22:06:33 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static size_t		arr_rec(const t_array *array, const char *val,
							size_t start, size_t end)
{
	int				diff;

	diff = ft_strcmp(array->arr[start + (end - start) / 2], val);
	if (diff == 0)
		return (start + (end - start) / 2);
	else if (end - start <= 1)
		return (-1);
	else
		return (arr_rec(array, val, (diff < 0) ? start +
				(end - start) / 2 : start,
		(diff < 0) ? end : start + (end - start) / 2));
}

size_t				array_index(t_graph *graph, const char *val)
{
	return (arr_rec(graph->names, val, 0, graph->names->size));
}

void				array_append(t_array *array, char *val)
{
	char			**arr;
	unsigned int	i;

	if (array->size == array->capacity)
	{
		arr = ft_protected_memalloc(sizeof(char *) * array->capacity * 2,
									terminate);
		i = -1;
		while (++i < array->size)
			arr[i] = array->arr[i];
		array->capacity = array->capacity * 2;
		free(array->arr);
		array->arr = arr;
	}
	array->arr[array->size++] = val;
}

t_array				*array_new(void)
{
	t_array			*array;

	array = ft_protected_memalloc(sizeof(t_array), terminate);
	array->arr = ft_protected_memalloc(sizeof(char *) * CAP,
			terminate);
	array->capacity = CAP;
	return (array);
}
