/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:45:32 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:09:55 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front_(t_list **begin_list, void *data)
{
	t_list *new_node;

	new_node = ft_create_elem(data);
	if (!new_node)
		return ;
	new_node->next = *begin_list;
	*begin_list = new_node;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*b_list;
	int		i;

	if (size <= 0)
		return (0);
	i = -1;
	b_list = 0;
	while (++i < size)
		ft_list_push_front_(&b_list, strs[i]);
	return (b_list);
}
