/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:36 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/05 21:13:19 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void	ft_vec_destructor(t_vector *vec, t_destrfunc del)
{
	size_t	i;

	if (del)
	{
		i = 0;
		while (i < vec->size)
			del(ft_vec_at(vec, i++));
	}
	free(vec->array);
}
