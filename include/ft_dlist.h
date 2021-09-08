/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:18:36 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:18:50 by fdiego           ###   ########.fr       */
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

extern t_dlist		*ft_create_dlist(void *data);
extern t_dlist		*ft_create_dlist_i(size_t data_size);
extern t_bool		ft_dlist_push_back(t_dlist **begin_list, t_dlist *node);
extern t_bool		ft_dlist_push_front(t_dlist **begin_list, t_dlist *node);
extern void			ft_dlist_insert(t_dlist *insert_pos, t_dlist *node);
extern void			ft_dlist_remove_node(t_dlist **begin_list, t_dlist *node, \
							void (*free_fct)(void*));
extern void			ft_dlist_remove_if(t_dlist **begin_list, void *data_ref, \
							int (*cmp)(), void (*free_fct)(void*));
extern void			ft_dlist_sort_insert(t_dlist **begin_list, \
							t_dlist *node, int (*cmp)());
extern void			ft_dlist_sort(t_dlist **begin_list, \
							t_updfunc upd, \
							void *addition_data, \
							t_cmpfunc cmp);

#endif
