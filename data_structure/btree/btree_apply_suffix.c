/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:32:42 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:07:33 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

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
