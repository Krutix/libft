/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:32:42 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:17:01 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_suffix(root->left, apply);
		if (root->right)
			btree_apply_suffix(root->right, apply);
		apply(root->item);
	}
}
