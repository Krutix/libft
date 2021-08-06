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

t_bool	ft_vec_push_back(t_vector *vec, void *data)
{
	if (!ft_vec_push_reserv(vec))
		return (t_false);
	if (data)
		ft_memcpy(ft_vec_at(vec, vec->size), data, vec->cell_size);
	vec->size++;
	return (t_true);
}
