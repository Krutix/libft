/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:33:22 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:07:22 by krutix           ###   ########.fr       */
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
