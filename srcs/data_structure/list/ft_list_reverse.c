/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:31:54 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:10:04 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*buff;
	t_list	*prev;
	t_list	*next;

	prev = 0;
	buff = *begin_list;
	while (buff)
	{
		next = buff->next;
		buff->next = prev;
		if (!next)
			*begin_list = buff;
		prev = buff;
		buff = next;
	}
}
