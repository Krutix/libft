/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:13:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 22:57:13 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

t_bool		ft_vec_push_back(t_vector *vec, t_data data)
{
	if (vec->reserv == vec->size)
		if (!ft_vec_realloc(vec, vec->reserv != 0 ? vec->reserv * 2 : 4))
			return (t_false);
	vec->array[vec->size++] = data;
	return (t_true);
}
