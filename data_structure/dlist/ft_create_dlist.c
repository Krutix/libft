/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:44:50 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 23:01:21 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string.h"
#include "stdio.h"
#include "ft_string.h"
#include "ft_dlist.h"

t_dlist	*ft_create_dlist(void* data)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = data;
	return (new_node);
}

t_dlist	*ft_create_dlist_i(size_t data_size)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist) + data_size);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = ((void*)new_node) + sizeof(t_dlist);
	ft_bzero(new_node->data, data_size);
	return (new_node);
}
