/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:32:16 by krutix            #+#    #+#             */
/*   Updated: 2021/01/28 17:28:43 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

t_ullint	ft_abs(t_llint num)
{
	int const		i = num >= 0;
	t_ullint const	ti = 0ull - i;

	return ((num & ti) | (-num & ~ti));
}

float		ft_absf(float num)
{
	union {
		t_uint	i;
		float	f;
	} *f = (void*)&num;
	f->i = f->i & 0x7fffffff;
	return (f->f);
}
