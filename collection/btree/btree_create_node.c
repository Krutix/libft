/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:33:31 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/25 21:30:38 by fdiego           ###   ########.fr       */
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
