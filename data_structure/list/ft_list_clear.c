/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:05:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 23:01:51 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, t_destrfunc del)
{
	t_list	*buff;

	while (begin_list)
	{
		buff = begin_list;
		if (del)
			del(buff->data);
		begin_list = buff->next;
		free(buff);
	}
}
