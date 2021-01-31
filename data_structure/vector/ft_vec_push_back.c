/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:13:15 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 22:57:13 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

t_bool		ft_vec_push_back(t_vector *vec, void *data)
{
	if (!ft_vec_push_reserv(vec))
		return (t_false);
	ft_memcpy(ft_vec_at(vec, vec->size), data, vec->cell_size);
	(*(size_t*)&vec->size)++;
	return (t_true);
}
