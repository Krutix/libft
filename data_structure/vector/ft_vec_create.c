/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:40 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:25:41 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void	ft_vec_construct(t_vector *vec, t_uint cell_size)
{
	vec->cell_size = cell_size;
	vec->size = 0;
	vec->capacity = 0;
	vec->array = NULL;
}
