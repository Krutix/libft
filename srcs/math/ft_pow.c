/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:06:59 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:40:58 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_math.h"

t_llint	ft_pow(t_llint nb, size_t power)
{
	int	res;

	res = 1;
	while (power != 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
