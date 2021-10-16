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

t_ft_err	ft_list_push_front(t_list **begin_list, t_list *node)
{
	if (!node)
		return (ft_err_bad_alloc);
	node->next = *begin_list;
	*begin_list = node;
	return (ft_err_ok);
}
