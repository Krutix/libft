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

t_vector	*ft_vec_create_reserv(size_t reserv)
{
	t_vector *vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	vec->size = 0;
	vec->array = NULL;
	vec->reserv = reserv;
	if (!ft_vec_realloc(vec, vec->reserv))
	{
		free(vec);
		return (NULL);
	}
	return (vec);
}
