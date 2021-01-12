/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:03:09 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:49:07 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			array_insert(t_array *array)
{
	unsigned int	i[2];

	ft_bzero(i, sizeof(int) * 2);
	while (i[0] < array->size - 1)
	{
		if (ft_strcmp(array->arr[i[0]], array->arr[i[0] + 1]) > 0)
		{
			i[1] = i[0] + 1;
			while (i[1] > 0)
			{
				if (ft_strcmp(array->arr[i[1]], array->arr[i[1] - 1]) < 0)
					ft_memswap(&array->arr[i[1]], &array->arr[i[1] - 1],
					sizeof(array->arr[i[1]]));
				else
					break ;
				i[1]--;
			}
		}
		i[0]++;
	}
}

static int			array_part(t_array *array, int low, int high)
{
	int				test[2];

	test[0] = low;
	test[1] = high + 1;
	while (array)
	{
		while (ft_strcmp(array->arr[++test[0]],
		array->arr[low]) <= 0 && test[0] != high)
			continue;
		while (ft_strcmp(array->arr[low],
		array->arr[--test[1]]) <= 0 && test[1] != low)
			continue;
		if (test[0] < test[1])
			ft_memswap(&array->arr[test[0]],
			&array->arr[test[1]], sizeof(array->arr[test[1]]));
		else
			break ;
	}
	ft_memswap(&array->arr[test[1]],
	&array->arr[low], sizeof(array->arr[test[1]]));
	return (test[1]);
}

static void			array_sort_req(t_array *array, int low, int high)
{
	if (low >= high)
		return ;
	array_sort_req(array, low, array_part(array, low, high));
	array_sort_req(array, array_part(array, low, high) + 1, high);
}

void				array_sorting(t_array *array)
{
	if (array->size <= 1)
		return ;
	else if (array->size <= 7)
		array_insert(array);
	else
		array_sort_req(array, 0, array->size - 1);
}
