/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:47:42 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:37:08 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb <= __INT_MAX__)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
