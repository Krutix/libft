/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:01:55 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:30:57 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_ftE	ft_dlist_push_front(t_dlist **begin_list, t_dlist *node)
{
	if (!node)
		return (ftE_bad_alloc);
	node->next = *begin_list;
	if (*begin_list)
		(*begin_list)->prev = node;
	*begin_list = node;
	return (ftE_ok);
}
