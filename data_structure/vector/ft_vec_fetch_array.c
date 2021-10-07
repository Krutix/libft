/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_fetch_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:31 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/08 00:56:32 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_vec_move(t_vector *vec)
{
	t_vector	out;

	out = *vec;
	vec->array = NULL;
	vec->size = 0;
	vec->capacity = 0;
	return (out);
}

void	*ft_vec_fetch_array(t_vector *vec, size_t *out_size)
{
	void	*array;

	array = vec->array;
	if (out_size)
		*out_size = vec->size;
	vec->array = NULL;
	vec->size = 0;
	vec->capacity = 0;
	return (array);
}
