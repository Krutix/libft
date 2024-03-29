/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:01:51 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:37:16 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_bool	ft_is_prime(t_ullint nb)
{
	unsigned int	i;
	unsigned int	sqrt;

	if (nb <= 1)
		return (0);
	i = 5;
	if ((nb % 2 == 0 || nb % 3 == 0) && nb != 2 && nb != 3)
		return (ft_false);
	sqrt = ft_sqrt(nb);
	while (i < sqrt)
	{
		if (nb % i == 0)
			return (ft_false);
		i += 2;
	}
	return (ft_true);
}
