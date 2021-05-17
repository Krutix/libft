/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:16:16 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:34:53 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stddef.h>

static void	__ft_dlist_insert(t_dlist **sorted, t_dlist **sorted_end, \
										t_dlist *node, int(*cmp)())
{
	t_dlist	*current;

	if (!*sorted)
	{
		*sorted = node;
		*sorted_end = node;
	}
	else
	{
		current = *sorted_end;
		while (current && cmp(current->data, node->data) > 0)
			current = current->prev;
		if (current)
		{
			if (current == *sorted_end)
				*sorted_end = node;
			node->next = current->next;
			if (node->next)
				node->next->prev = node;
			current->next = node;
			node->prev = current;
		}
		else
			ft_dlist_push_front(sorted, node);
	}
}

void	ft_dlist_sort(t_dlist **begin_list, void(*upd)(void*, void*), \
									void *addition_data, int(*cmp)())
{
	t_dlist	*sorted;
	t_dlist	*sorted_end;
	t_dlist	*current;
	t_dlist	*next;

	sorted = NULL;
	sorted_end = *begin_list;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		if (upd)
			upd(current->data, addition_data);
		current->next = NULL;
		current->prev = NULL;
		__ft_dlist_insert(&sorted, &sorted_end, current, cmp);
		current = next;
	}
	*begin_list = sorted;
}
