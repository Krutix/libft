/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:57:33 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/26 15:35:26 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ftdef.h"

typedef struct		s_list
{
	struct s_list	*next;
	t_data			data;
}					t_list;

t_list	*ft_create_elem(t_data data);
void	ft_list_push_back(t_list **begin_list, t_data data);
void	ft_list_push_front(t_list **begin_list, t_data data);
t_list	*ft_list_push_strs(int size, char **strs);

int		ft_list_size(t_list *begin_list);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_find(t_list *begin_list, t_data data_ref, int (*cmp)());

void	ft_list_clear(t_list *begin_list, void (*free_fct)(t_data));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(t_data),
							t_data data_ref, int (*cmp)());
void	ft_list_foreach(t_list *begin_list, void (*f)(t_data));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_remove_if(t_list **begin_list, t_data data_ref,
					int (*cmp)(), void (*free_fct)(t_data));
void	ft_list_reverse(t_list **begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());

#endif
