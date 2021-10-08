/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_remove_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:06 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/08 23:27:35 by fdiego           ###   ########.fr       */
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

void	ft_vec_remove_all(t_vector *vec, void *sample, \
						t_destr_func destr, t_cmp_func cmp)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		if (cmp(ft_vec_at(vec, i), sample) == 0)
			ft_vec_remove_at(vec, i, destr);
	}
}