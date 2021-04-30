/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:12:10 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:30:33 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

t_vector	*ft_vec_create(t_uint cell_size)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	ft_vec_construct(vec, cell_size);
	return (vec);
}

void	ft_vec_construct(t_vector *vec, t_uint cell_size)
{
	vec->cell_size = cell_size;
	vec->size = 0;
	vec->reserv = 0;
	vec->array = NULL;
}
