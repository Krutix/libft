/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 22:26:28 by fdiego            #+#    #+#             */
/*   Updated: 2020/12/31 22:36:13 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	ft_swap_n(void *v1, void *v2, size_t n)
{
	while (n >= 8)
	{
		ft_swap_8(v1, v2);
		n -= 8;
		v1 += 8;
		v2 += 8;
	}
	while (n-- != 0)
		ft_swap_1(v1++, v2++);
}

void	ft_swap_8(int64_t *v1, int64_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}

void	ft_swap_4(int32_t *v1, int32_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}

void	ft_swap_2(int16_t *v1, int16_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}

void	ft_swap_1(int8_t *v1, int8_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}
