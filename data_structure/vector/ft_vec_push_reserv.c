/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_reserv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:14 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:25:15 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_ftE	ft_vec_push_reserv(t_vector *vec)
{
	size_t	alloc_size;

	if (vec->capacity == vec->size)
	{
		alloc_size = vec->capacity * 2;
		if (alloc_size == 0)
			alloc_size = 4;
		if (ft_vec_realloc(vec, alloc_size) != ftE_ok)
			return (ftE_bad_alloc);
	}
	return (ftE_ok);
}
