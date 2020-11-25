/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_returndel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:14:00 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 22:56:46 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vec_returndel(t_vector *vec, void (*del)(t_data))
{
	ft_vec_destructor(vec, del);
	return (NULL);
}