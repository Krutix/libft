/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_returndel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:14:00 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:36:29 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vec_returndel(t_vector *vec, void (*del)(t_data))
{
	(void)del;
	ft_vec_destructor(vec);
	return (NULL);
}
