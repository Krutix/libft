/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:57:33 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 09:20:59 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include "ftdef.h"
# include "ft_list.h"

typedef struct s_dlist
{
	struct s_dlist	*next;
	void			*data;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_create_dlist(void *data);
t_dlist				*ft_create_dlist_i(size_t data_size);
t_bool				ft_dlist_push_back(t_dlist **begin_list, t_dlist *node);
t_bool				ft_dlist_push_front(t_dlist **begin_list, t_dlist *node);
void				ft_dlist_insert(t_dlist *insert_pos, t_dlist *node);
void				ft_dlist_remove_node(t_dlist **begin_list, t_dlist *node, \
							void (*free_fct)(void*));
void				ft_dlist_remove_if(t_dlist **begin_list, void *data_ref, \
							int (*cmp)(), void (*free_fct)(void*));
void				ft_dlist_sort_insert(t_dlist **begin_list, \
							t_dlist *node, int (*cmp)());
void				ft_dlist_sort(t_dlist **begin_list, void(*upd)(void*, void*), \
							void *addition_data, int(*cmp)());

#endif
