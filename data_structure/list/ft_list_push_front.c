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

#include "ft_list.h"

t_bool	ft_list_push_front(t_list **begin_list, t_list *node)
{
	if (!node)
		return (t_false);
	node->next = *begin_list;
	*begin_list = node;
	return (t_true);
}
