/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:48 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:25:49 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vec_at(t_vector *vec, size_t pos)
{
	return (vec->array + (pos * vec->cell_size));
}

void	*ft_vec_back(t_vector *vec)
{
	return (ft_vec_at(vec, vec->size - 1));
}

void	*ft_vec_front(t_vector *vec)
{
	return (vec->array);
}
