/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:18 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:25:18 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

t_ft_err	ft_vec_push_back(t_vector *vec, void *data)
{
	if (ft_vec_push_reserv(vec) != ft_err_ok)
		return (ft_err_bad_alloc);
	if (data)
		ft_memcpy(ft_vec_at(vec, vec->size), data, vec->cell_size);
	vec->size++;
	return (ft_err_ok);
}

t_ft_err	ft_vec_push_back_n(t_vector *vec, void *data, size_t size)
{
	if (ft_vec_reserv(vec, vec->size + size) != ft_err_ok)
		return (ft_err_bad_alloc);
	ft_memcpy(ft_vec_at(vec, vec->size), data, size * vec->cell_size);
	vec->size += size;
	return (ft_err_ok);
}
