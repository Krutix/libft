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
#include "ft_list.h"

t_list	*ft_create_list_i(t_data data)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->data = data;
	return (new_node);
}

t_list	*ft_create_list(size_t data_size)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list) + data_size);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->data = (t_data)(new_node + sizeof(t_list));
	return (new_node);
}
