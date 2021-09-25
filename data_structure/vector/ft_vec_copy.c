/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:44 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:25:45 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"
#include "stdlib.h"

t_ftE	ft_vec_copy_construct(t_vector *copy, t_vector *sample)
{
	copy->size = sample->size;
	copy->capacity = sample->size;
	copy->cell_size = sample->cell_size;
	copy->array = malloc(sample->size * sample->cell_size);
	if (!copy->array)
		return (ftE_bad_alloc);
	ft_memcpy(copy->array, sample->array, \
		sample->size * sample->cell_size);
	return (ftE_ok);
}
