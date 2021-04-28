/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:46:39 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:41:13 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_ullint	ft_sqrt(t_ullint nb)
{
	t_ullint	i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}
