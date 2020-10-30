/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:33:09 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/25 23:03:08 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*apply)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, apply);
		apply(root->item);
		if (root->right)
			btree_apply_infix(root->right, apply);
	}
}
