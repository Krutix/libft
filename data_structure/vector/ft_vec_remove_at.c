/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_remove_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:06 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:25:06 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"

void	ft_vec_remove_at(t_vector *vec, size_t pos, t_destr_func del)
{
	if (del)
		del(ft_vec_at(vec, pos));
	ft_memmove(ft_vec_at(vec, pos), ft_vec_at(vec, pos + 1), \
			(vec->size - 1 - pos) * vec->cell_size);
	vec->size--;
}

void	ft_vec_pop_front(t_vector *vec, t_destr_func del)
{
	ft_vec_remove_at(vec, 0, del);
}
