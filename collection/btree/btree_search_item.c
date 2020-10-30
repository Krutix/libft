/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 21:58:01 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/26 18:06:49 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *))
{
	void *data;

	if (root)
	{
		data = 0;
		if (root->left)
			data = btree_search_item(root->left, data_ref, cmpf);
		if (data)
			return (data);
		if (cmpf(data_ref, root->item) == 0)
			return (root->item);
		if (root->right)
			data = btree_search_item(root->right, data_ref, cmpf);
		if (data)
			return (data);
	}
	return (0);
}
