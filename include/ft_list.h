/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:16:57 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:16:58 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ftdef.h"

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*ft_create_list(void *data);
t_list				*ft_create_list_i(size_t data_size);
t_ftE				ft_list_push_back(t_list **begin_list, t_list *node);
t_ftE				ft_list_push_front(t_list **begin_list, t_list *node);
t_list				*ft_list_push_strs(int size, char **strs);

size_t				ft_list_size(t_list *begin_list);
t_list				*ft_list_at(t_list *begin_list, size_t nbr);
t_list				*ft_list_last(t_list *begin_list);
t_list				*ft_list_find(t_list *begin_list, void const *data_ref, \
							int (*cmp)());

void				ft_list_clear(t_list *begin_list, void (*free_fct)(void*));
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void*), \
							void *data_ref, int (*cmp)());
void				ft_list_foreach(t_list *begin_list, void (*f)(void*));
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void				ft_list_remove_if(t_list **begin_list, void *data_ref, \
							int (*cmp)(), void (*free_fct)(void*));
void				ft_list_reverse(t_list **begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());

#endif
