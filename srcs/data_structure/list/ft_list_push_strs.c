/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:45:32 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:30:59 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(size_t size, char **strs)
{
	t_list	*b_list;
	size_t	i;

	b_list = NULL;
	i = 0;
	while (i < size)
	{
		if (!ft_list_push_front(&b_list, ft_create_list((void *)strs[i])))
		{
			ft_list_clear(b_list, NULL);
			return (NULL);
		}
		i++;
	}
	return (b_list);
}
