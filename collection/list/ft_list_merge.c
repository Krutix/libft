/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:35:29 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/24 23:05:22 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*buff;

	if (*begin_list1)
	{
		buff = *begin_list1;
		while (buff->next)
			buff = buff->next;
		buff->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
