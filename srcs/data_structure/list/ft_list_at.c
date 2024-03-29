/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:05:24 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:07:53 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
	size_t	i;
	t_list	*buff;

	i = 0;
	buff = begin_list;
	while (buff && i != nbr)
	{
		buff = buff->next;
		i++;
	}
	return (buff);
}
