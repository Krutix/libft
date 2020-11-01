/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:49 by krutix            #+#    #+#             */
/*   Updated: 2020/11/01 20:29:24 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void		ft_vec_destructor(t_vector *vec, void (*del)(void*))
{
	size_t i;

	if (vec->array)
	{
		i = 0;
		if (del)
		while (i < vec->size)
			des(vec->array[i++]);
		free(vec->array);
	}
	free(vec);
}
