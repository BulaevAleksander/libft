/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:11:38 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:59:32 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			graph_del_2(t_lemin *in)
{
	unsigned int	i;

	i = 0;
	while (i < in->paths->paths)
	{
		while (in->paths->arr[i]->size)
			lst_pop(in->paths->arr[i]);
		free(in->paths->arr[i]);
		i++;
	}
	free(in->graph->list);
	free(in->graph->names->arr);
	free(in->graph->names);
	free(in->graph->price->v);
	free(in->graph->price->price);
	free(in->graph->price->quality);
	free(in->graph->price);
	free(in->graph->nods);
	free(in->graph);
	free(in->paths->arr);
	free(in->paths->assigm);
	free(in->paths);
}

void				graph_del(t_lemin *lemin)
{
	unsigned int	i;
	t_point_node	*node;

	i = 0;
	while (i < (unsigned int)lemin->graph->c_nodes)
	{
		node = lemin->graph->nods[i];
		while (node->edges->size)
			lst_pop(node->edges);
		free(node->edges);
		free(node);
		i++;
	}
	i = 0;
	while (i < lemin->graph->names->size)
		free(lemin->graph->names->arr[i++]);
	while (lemin->graph->list->size)
		lst_pop(lemin->graph->list);
	graph_del_2(lemin);
}

static t_point_node	*node_init(void)
{
	t_point_node	*node;

	node = ft_protected_memalloc(sizeof(t_point_node), terminate);
	node->edges = ft_protected_memalloc(sizeof(t_li_list), terminate);
	node->par = -1;
	return (node);
}

t_graph				*graph_name(t_array *names,
			const char *start_name, const char *end_name)
{
	t_graph			*graph;
	int				i;

	graph = ft_protected_memalloc(sizeof(t_graph), terminate);
	graph->c_nodes = names->size;
	graph->names = names;
	graph->nods = ft_protected_memalloc(sizeof(t_point_node *) *
										graph->c_nodes, terminate);
	graph->list = ft_protected_memalloc(sizeof(t_li_list), terminate);
	i = 0;
	while (i < graph->c_nodes)
		graph->nods[i++] = node_init();
	array_sorting(names);
	graph->str = array_index(graph, start_name);
	graph->end = array_index(graph, end_name);
	graph->price = pq_tree_new(names->size);
	return (graph);
}

void				graph_res(t_graph *graph)
{
	int				v;
	t_point_node	*node;

	v = 0;
	while (v < graph->c_nodes)
	{
		node = graph->nods[v];
		node->edge[0] = -1;
		node->edge[1] = -1;
		node->cost[0] = MAX_NODE;
		node->cost[1] = MAX_NODE;
		v++;
	}
	node = graph->nods[graph->str];
	node->cost[0] = 0;
	node->cost[1] = 0;
	ft_bzero(graph->price->v, sizeof(int) * (graph->price->size + 1));
	ft_bzero(graph->price->price, sizeof(int) * (graph->price->size + 1));
	ft_bzero(graph->price->quality, sizeof(int) * (graph->price->size + 1));
}
