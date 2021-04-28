/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_minf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:29:50 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:40:01 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	ft_maxd(double a1, double a2)
{
	if (a1 < a2)
		return (a2);
	else
		return (a1);
}

double	ft_mind(double a1, double a2)
{
	if (a1 < a2)
		return (a1);
	else
		return (a2);
}

float	ft_maxf(float a1, float a2)
{
	if (a1 < a2)
		return (a2);
	else
		return (a1);
}

float	ft_minf(float a1, float a2)
{
	if (a1 < a2)
		return (a1);
	else
		return (a2);
}
