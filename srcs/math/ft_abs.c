/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:32:16 by krutix            #+#    #+#             */
/*   Updated: 2021/04/28 10:43:18 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

t_ullint	ft_abs(t_llint num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

float	ft_absf(float num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}
