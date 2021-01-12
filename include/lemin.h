/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:46:12 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 21:47:43 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./../libft/includes/libftfull.h"
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <sys/types.h>
# include <limits.h>

# define CAP			2
# define MAX_NODE		100000
# define BF				2048
# define ERROR_MEMORY	1
# define ERROR_INPUT	2
# define ERROR_READ		3
# define ERROR_PATH		4

# define CHECK_COMMEND	0
# define CHECK_COORD	1
# define CHECK_END		2
# define CHECK_LINK		3
# define CHECK_NANTS	4
# define CHECK_ISROOM	5
# define CHECK_START	6

typedef struct			s_pq_tree
{
	int					*v;
	int					*price;
	int					*quality;
	size_t				size;
}						t_pq_tree;

typedef struct			s_lnk
{
	int					v;
	struct s_lnk		*nxt;
	struct s_lnk		*prv;
}						t_lnk;

typedef struct			s_ti_list
{
	t_lnk				*first;
	t_lnk				*last;
	size_t				size;
}						t_li_list;

typedef struct			s_array
{
	unsigned int		size;
	unsigned int		capacity;
	char				**arr;
}						t_array;

typedef struct			s_point_node
{
	t_li_list			*edges;
	int					par;
	char				split;
	int					price[2];
	int					edge[2];
	int					cost[2];
}						t_point_node;

typedef struct			s_graph
{
	int					c_nodes;
	int					c_edges;
	t_array				*names;
	t_point_node		**nods;
	t_li_list			*list;
	int					str;
	int					end;
	t_pq_tree			*price;
}						t_graph;

typedef struct			s_paths
{
	size_t				paths;
	size_t				steps;
	t_li_list			**arr;
	size_t				*assigm;
}						t_paths;

typedef struct			s_lemin
{
	char				buffer[BF + 1];
	char				*ptr;
	char				*line;
	char				end;
	size_t				nants;
	t_graph				*graph;
	t_paths				*paths;
}						t_lemin;

void					array_append(t_array *array, char *val);
t_array					*array_new(void);
void					array_sorting(t_array *array);
size_t					array_index(t_graph *graph, const char *val);
t_graph					*graph_name(t_array *names, const char *start_name,
									const char *end_name);
void					dijkstra(t_graph *graph, int *res);
void					graph_res(t_graph *graph);
void					graph_del(t_lemin *lemin);
int						lst_pop(t_li_list *lst);
void					lst_add(t_li_list *lst, int val, char act);

t_pq_tree				*pq_tree_new(size_t max_size);
int						pq_tree_pop(t_pq_tree *min_price);
void					pq_tree_add(t_pq_tree *min_price, int i, int val);
void					pq_tree_ins(t_pq_tree *m_p, int i, int val);
void					pq_tree_down(t_pq_tree *p, size_t c);

void					pars_links(t_lemin *lemin, t_graph *graph);
int						pars_ants(t_lemin *lemin);
t_graph					*parse_rooms(t_lemin *lemin);

t_paths					*paths_fork(t_graph *graph, size_t ants);
t_lnk					*paths_navigate(t_paths *paths, size_t i);
void					path_assign_multi(t_paths *paths, size_t ants);
void					paths_delete(t_paths *paths);
size_t					paths_length(const t_paths *paths, size_t i);

void					pars_stdin(t_lemin *lemin);
const char				*pars_next(t_lemin *lemin);
const char				*pars_head(t_lemin *lemin);

void					*ft_protected_memalloc(size_t size,
						void err_manager(char));
int						parse_utils(const char *s, char act);
void					tab_delete(char **tab);
size_t					tab_len(char **tab);
void					terminate(char err);
void					lemin(t_lemin *lemin);
void					suurballe(t_graph *graph);

#endif
