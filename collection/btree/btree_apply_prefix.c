/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:33:22 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/25 23:02:40 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*apply)(void *))
{
	if (root)
	{
		apply(root->item);
		if (root->left)
			btree_apply_prefix(root->left, apply);
		if (root->right)
			btree_apply_prefix(root->right, apply);
	}
}
