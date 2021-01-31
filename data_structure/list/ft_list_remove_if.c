/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:18:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:30:03 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, t_data data_ref,
					int (*cmp)(), void (*free_fct)(t_data))
{
	t_list	*buff;
	t_list	*prev;
	t_list	*next;

	buff = *begin_list;
	prev = NULL;
	while (buff)
	{
		next = buff->next;
		if (cmp(buff->data, data_ref) == 0)
		{
			if (free_fct)
				free_fct(buff->data);
			if (prev)
				prev->next = buff->next;
			else
				*begin_list = buff->next;
			free(buff);
		}
		else
			prev = buff;
		buff = next;
	}
}
