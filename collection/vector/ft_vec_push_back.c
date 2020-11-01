/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:13:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/01 19:26:27 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void		ft_vec_push_back(t_vector *vec, void *data)
{
	if (vec->reserv == vec->size)
		ft_vec_realloc(vec, vec->reserv * 2);
	vec->array[vec->size++] = data;
}
