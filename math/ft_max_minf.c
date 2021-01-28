/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_minf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:29:50 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:29:52 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_maxd(double a1, double a2)
{
	return (a1 < a2 ? a2 : a1);
}

double	ft_mind(double a1, double a2)
{
	return (a1 < a2 ? a1 : a2);
}

float	ft_maxf(float a1, float a2)
{
	return (a1 < a2 ? a2 : a1);
}

float	ft_minf(float a1, float a2)
{
	return (a1 < a2 ? a1 : a2);
}
