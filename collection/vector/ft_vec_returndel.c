/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_returndel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:14:00 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:14:01 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_vector.h"

void	*ft_vec_returndel(t_vector *vec, void (*del)(void *))
{
	ft_vec_destructor(vec, del);
	return (NULL);
}