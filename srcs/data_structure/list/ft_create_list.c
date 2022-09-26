/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:44:50 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:32:20 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string.h"
#include "stdio.h"
#include "ft_string.h"
#include "ft_list.h"

t_list	*ft_create_list(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->data = data;
	return (new_node);
}

t_list	*ft_create_list_i(size_t data_size)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list) + data_size);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->data = ((void *)new_node) + sizeof(t_list);
	ft_bzero(new_node->data, data_size);
	return (new_node);
}
