/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:04:04 by krutix            #+#    #+#             */
/*   Updated: 2020/11/01 19:15:49 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void		ft_vec_realloc(t_vector *vec, size_t new_reserv)
{
	void	**new_arr;
	size_t	i;

	new_arr = malloc(new_reserv * sizeof(void*));
	if (vec->size > new_reserv)
		vec->size = new_reserv;
	i = -1;
	while (++i < vec->size)
		new_arr[i] = vec->array[i];
	if (vec->array)
		free(vec->array);
	vec->reserv = new_reserv;
	vec->array = new_arr;
}
