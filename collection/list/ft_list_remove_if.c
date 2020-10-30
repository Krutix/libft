/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:18:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/24 23:04:27 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *))
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
