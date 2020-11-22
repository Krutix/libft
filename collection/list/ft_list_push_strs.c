/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:45:32 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:35:55 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*b_list;
	t_data	k;
	int		i;

	if (size <= 0)
		return (0);
	i = -1;
	b_list = 0;
	while (++i < size)
	{
		k.p = strs[i];
		ft_list_push_front(&b_list, k);
	}
	return (b_list);
}
