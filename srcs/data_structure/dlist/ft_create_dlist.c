/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:44:50 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:36:03 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string.h"
#include "stdio.h"
#include "ft_string.h"
#include "ft_dlist.h"

t_dlist	*ft_create_dlist(void *data)
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
	new_node->data = ((void *)new_node) + sizeof(t_dlist);
	ft_bzero(new_node->data, data_size);
	return (new_node);
}
