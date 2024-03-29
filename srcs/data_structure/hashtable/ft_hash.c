/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:21:33 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/05 18:11:38 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

size_t	ft_hash_int(int *i)
{
	return (*i ^ (*i << 1));
}

size_t	ft_hash_str(char **str)
{
	size_t	hash;
	size_t	idx;

	hash = 0;
	idx = 0;
	while ((*str)[idx])
	{
		hash += (*str)[idx] * (idx + 1);
		idx++;
	}
	return (hash);
}
