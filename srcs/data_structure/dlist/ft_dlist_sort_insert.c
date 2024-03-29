/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:24:26 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:24:27 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_sort_insert(t_dlist **begin_list, t_dlist *node, int (*cmp)())
{
	t_dlist	*current;

	if (cmp((*begin_list)->data, node->data) >= 0)
	{
		node->prev = NULL;
		node->next = *begin_list;
		if (node->next)
			node->next->prev = node;
		*begin_list = node;
		return ;
	}
	current = (*begin_list);
	while (current->next && cmp(current->next->data, node->data) < 0)
		current = current->next;
	node->next = current->next;
	if (current->next)
		current->next->prev = node;
	node->prev = current;
	current->next = node;
}
