/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:17:05 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:07:42 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int l_i;
	int r_i;

	l_i = 0;
	r_i = 0;
	if (root == 0)
		return (0);
	l_i = btree_level_count(root->left);
	r_i = btree_level_count(root->right);
	if (l_i > r_i)
		return (l_i + 1);
	else
		return (r_i + 1);
}
