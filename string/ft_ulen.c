/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:06:52 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 19:36:51 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

t_uint	ft_ulen(t_ullint num)
{
	t_uint i;

	i = 1;
	while (t_true)
	{
		if (num < 10)
			return (i);
		if (num < 100)
			return (i + 1);
		if (num < 1000)
			return (i + 2);
		if (num < 10000)
			return (i + 3);
		i += 4;
		num /= 10000;
	}
}

t_uint	ft_ulen_16(t_ullint num)
{
	t_uint i;

	i = 1;
	while (t_true)
	{
		if (num < 16)
			return (i);
		if (num < 16 * 16)
			return (i + 1);
		if (num < 16 * 16 * 16)
			return (i + 2);
		if (num < 16 * 16 * 16 * 16)
			return (i + 3);
		i += 4;
		num /= 16 * 16 * 16 * 16;
	}
}

t_uint	ft_ulen_n(t_ullint num, t_uint base)
{
	t_uint			i;
	t_uint const	base2 = base * base;
	t_uint const	base3 = base2 * base;
	t_uint const	base4 = base3 * base;

	i = 1;
	while (t_true)
	{
		if (num < base)
			return (i);
		if (num < base2)
			return (i + 1);
		if (num < base3)
			return (i + 2);
		if (num < base4)
			return (i + 3);
		i += 4;
		num /= base4;
	}
}

t_uint	ft_ulen_2(t_ullint num)
{
	t_uint i;

	i = 1;
	while (t_true)
	{
		if (num < 2)
			return (i);
		if (num < 4)
			return (i + 1);
		if (num < 8)
			return (i + 2);
		if (num < 16)
			return (i + 3);
		if (num < 32)
			return (i + 4);
		if (num < 64)
			return (i + 5);
		if (num < 128)
			return (i + 6);
		if (num < 256)
			return (i + 7);
		i += 8;
		num /= 256;
	}
}
