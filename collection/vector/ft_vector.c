/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:13:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/30 15:23:25 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void		ft_vec_realloc(t_vector *vec, unsigned int new_reserv)
{
	unsigned int *new_arr;
	unsigned int i;

	new_arr = malloc(new_reserv * sizeof(unsigned int));
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

void		ft_vec_constructor(t_vector **vec)
{
	*vec = malloc(sizeof(t_vector));
	(*vec)->size = 0;
	(*vec)->array = NULL;
	(*vec)->reserv = 4;
	ft_vec_realloc(*vec, (*vec)->reserv);
}

void		ft_vec_destructor(t_vector *vec)
{
	if (vec->array)
		free(vec->array);
	free(vec);
}

void		ft_vec_push_back(t_vector *vec, int nbr)
{
	if (vec->reserv == vec->size)
		ft_vec_realloc(vec, vec->reserv * 2);
	vec->array[vec->size] = nbr;
	vec->size++;
}

void		*return_clean_vec(t_vector *vec)
{
	ft_vec_destructor(vec);
	return (NULL);
}
