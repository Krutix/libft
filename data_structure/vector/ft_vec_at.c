/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:25:48 by fdiego            #+#    #+#             */
/*   Updated: 2021/09/27 17:12:32 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vec_at(const t_vector *vec, size_t pos)
{
	return (vec->array + (pos * vec->cell_size));
}

void	*ft_vec_back(const t_vector *vec)
{
	return (ft_vec_at(vec, vec->size - 1));
}

void	*ft_vec_front(const t_vector *vec)
{
	return (vec->array);
}
