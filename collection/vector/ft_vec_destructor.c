/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:49 by krutix            #+#    #+#             */
/*   Updated: 2020/11/02 18:24:37 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include/ft_vector.h"

void		ft_vec_destructor(t_vector *vec, void (*del)(void*))
{
	size_t i;

	if (vec->array)
	{
		i = 0;
		if (del)
			while (i < vec->size)
				del(vec->array[i++]);
		free(vec->array);
	}
	free(vec);
}
