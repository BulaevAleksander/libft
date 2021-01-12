/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:46:43 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 22:06:08 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void				dijkstra_hidden_act(t_graph *graph, int w, char act)
{
	if (act == 0)
	{
		graph->nods[w]->edge[0] = graph->nods[w]->edge[1];
		graph->nods[w]->cost[0] = graph->nods[w]->cost[1] +
		graph->nods[w]->price[1] - graph->nods[w]->price[0];
		pq_tree_ins(graph->price, 2 * w, graph->nods[w]->cost[0]);
	}
	else if (act == 1)
	{
		graph->nods[w]->edge[1] = graph->nods[w]->edge[0];
		graph->nods[w]->cost[1] = graph->nods[w]->cost[0] +
		graph->nods[w]->price[0] - graph->nods[w]->price[1];
		pq_tree_ins(graph->price, 2 * w + 1, graph->nods[w]->cost[1]);
	}
}

static void				dijkstra_hidden(t_graph *graph, int w)
{
	t_point_node	*node;

	node = graph->nods[w];
	if (node->split && node->cost[0] > node->cost[1] +
		node->price[1] - node->price[0] && w != graph->str)
		dijkstra_hidden_act(graph, w, 0);
	if (!node->split && node->cost[1] > node->cost[0] +
		node->price[0] - node->price[1] && w != graph->end)
		dijkstra_hidden_act(graph, w, 1);
}

static void				dijkstra_relax_act(t_graph *graph, int v,
											int w, char act)
{
	if (act == 0)
	{
		graph->nods[w]->edge[1] = v;
		graph->nods[w]->cost[1] = graph->nods[v]->cost[0] - 1 +
		graph->nods[v]->price[0] - graph->nods[w]->price[1];
		pq_tree_ins(graph->price, w * 2 + 1, graph->nods[w]->cost[1]);
	}
	else if (act == 1)
	{
		graph->nods[w]->edge[0] = v;
		graph->nods[w]->cost[0] = graph->nods[v]->cost[1] + 1 +
		graph->nods[v]->price[1] - graph->nods[w]->price[0];
		pq_tree_ins(graph->price, w * 2, graph->nods[w]->cost[0]);
	}
	dijkstra_hidden(graph, w);
}

static void				dijkstra_relax(t_graph *graph, int v, int w)
{
	if (v == graph->end || w == graph->str || graph->nods[w]->par == v)
		return ;
	else if (
			graph->nods[v]->par == w &&
			graph->nods[v]->cost[0] < MAX_NODE &&
		graph->nods[w]->cost[1] > graph->nods[v]->cost[0] +
		graph->nods[v]->price[0] - graph->nods[w]->price[1] - 1)
		dijkstra_relax_act(graph, v, w, 0);
	else if (
			graph->nods[v]->par != w &&
			graph->nods[v]->cost[1] < MAX_NODE && -1 +
			graph->nods[w]->cost[0] > graph->nods[v]->cost[1] +
			graph->nods[v]->price[1] - graph->nods[w]->price[0])
		dijkstra_relax_act(graph, v, w, 1);
}

void					dijkstra(t_graph *graph, int *res)
{
	t_lnk				*link;
	int					v;
	int					i;

	i = -1;
	graph_res(graph);
	pq_tree_add(graph->price, 2 * graph->str + 1, 0);
	while (graph->price->size > 0)
	{
		v = pq_tree_pop(graph->price) / 2;
		link = graph->nods[v]->edges->first;
		while (link)
		{
			dijkstra_relax(graph, v, link->v);
			link = link->nxt;
		}
	}
	while (++i < graph->c_nodes)
	{
		graph->nods[i]->price[0] = graph->nods[i]->cost[0];
		graph->nods[i]->price[1] = graph->nods[i]->cost[1];
	}
	*res = (graph->nods[graph->end]->edge[0] >= 0);
}
