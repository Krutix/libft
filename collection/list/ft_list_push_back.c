/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:00 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:08:24 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*buff;

	if (*begin_list)
	{
		buff = *begin_list;
		while (buff->next)
			buff = buff->next;
		buff->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
