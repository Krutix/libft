/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_fetch_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:26:50 by krutix            #+#    #+#             */
/*   Updated: 2020/11/22 22:36:24 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_data	*ft_vec_fetch_array(t_vector *vec, size_t *out_size)
{
	t_data	*array;

	array = vec->array;
	if (out_size)
		*out_size = vec->size;
	vec->array = NULL;
	vec->size = 0;
	vec->reserv = 0;
	return (array);
}
