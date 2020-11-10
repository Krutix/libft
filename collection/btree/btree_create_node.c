/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:33:31 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:07:29 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *new;

	new = malloc(sizeof(t_btree));
	if (new == NULL)
		return (new);
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
