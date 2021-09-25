/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:00 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 23:04:08 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ftE	ft_list_push_back(t_list **begin_list, t_list *node)
{
	t_list	*buff;

	if (!node)
		return (ftE_bad_alloc);
	if (*begin_list)
	{
		buff = *begin_list;
		while (buff->next)
			buff = buff->next;
		buff->next = node;
	}
	else
		*begin_list = node;
	return (ftE_ok);
}
