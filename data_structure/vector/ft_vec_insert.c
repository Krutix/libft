/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:21:30 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/11 19:04:44 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

t_ft_err	ft_vec_insert(t_vector *vec, void *data, size_t pos)
{
	if (ft_vec_push_reserv(vec) != ft_err_ok)
		return (ft_err_bad_alloc);
	ft_memmove(ft_vec_at(vec, pos + 1), ft_vec_at(vec, pos), \
				vec->cell_size * (vec->size - pos));
	if (data)
		ft_memcpy(ft_vec_at(vec, pos), data, vec->cell_size);
	else
		ft_bzero(ft_vec_at(vec, pos), vec->cell_size);
	vec->size++;
	return (ft_err_ok);
}
