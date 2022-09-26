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

#include "ft_dlist.h"
#include <stdlib.h>

void	ft_dlist_remove_if(t_dlist **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void*))
{
	t_dlist	*buff;
	t_dlist	*next;

	buff = *begin_list;
	while (buff)
	{
		next = buff->next;
		if (cmp(buff->data, data_ref) == 0)
		{
			if (free_fct)
				free_fct(buff->data);
			if (buff->prev)
				buff->prev->next = buff->next;
			else
				*begin_list = buff->next;
			if (buff->next)
				buff->next->prev = buff->prev;
			free(buff);
		}
		buff = next;
	}
}
