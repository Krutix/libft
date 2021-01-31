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
#include "ft_string.h"
#include "ft_vector.h"

t_bool		ft_vec_realloc(t_vector *vec, size_t new_reserv)
{
	void	*new_arr;

	new_arr = malloc(new_reserv * vec->cell_size);
	if (!new_arr)
		return (t_false);
	if (vec->size > new_reserv)
		*(size_t*)&vec->size = new_reserv;
	ft_memcpy(new_arr, vec->array, vec->size * vec->cell_size);
	if (vec->array)
		free(vec->array);
	*(size_t*)&vec->reserv = new_reserv;
	*(void**)&vec->array = new_arr;
	return (t_true);
}
