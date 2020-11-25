/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:49 by krutix            #+#    #+#             */
/*   Updated: 2020/11/19 23:00:52 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void		ft_vec_destructor(t_vector *vec, void (*del)(t_data))
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
