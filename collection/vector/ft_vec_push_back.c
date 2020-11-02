/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:13:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:24:48 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include/ft_vector.h"

t_bool		ft_vec_push_back(t_vector *vec, void *data)
{
	if (vec->reserv == vec->size)
		if (!ft_vec_realloc(vec, vec->reserv != 0 ? vec->reserv * 2 : 4))
			return (t_false);
	vec->array[vec->size++] = data;
	return (t_true);
}
