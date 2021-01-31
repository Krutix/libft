/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create_reserv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:12:10 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/23 05:51:31 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

t_vector	*ft_vec_create(t_uint cell_size)
{
	t_vector *vec;

	vec = malloc(sizeof(vec));
	if (!vec)
		return (NULL);
	ft_vec_construct(vec, cell_size);
	return (vec);
}

void	ft_vec_construct(t_vector *vec, t_uint cell_size)
{
	*(t_uint*)&vec->cell_size = cell_size;
	*(size_t*)&vec->size = 0;
	*(size_t*)&vec->reserv = 0;
	*(void**)&vec->array = NULL;
}
