/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:04:04 by krutix            #+#    #+#             */
/*   Updated: 2020/11/19 22:56:31 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

t_bool		ft_vec_realloc(t_vector *vec, size_t new_reserv)
{
	t_data	*new_arr;
	size_t	i;

	new_arr = malloc(new_reserv * sizeof(t_data));
	if (!new_arr)
		return (t_false);
	if (vec->size > new_reserv)
		vec->size = new_reserv;
	i = -1;
	while (++i < vec->size)
		new_arr[i] = vec->array[i];
	if (vec->array)
		free(vec->array);
	vec->reserv = new_reserv;
	vec->array = new_arr;
	return (t_true);
}
