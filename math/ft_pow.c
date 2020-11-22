/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:06:59 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 21:37:29 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_math.h"

llint	ft_pow(llint nb, size_t power)
{
	int res;

	res = 1;
	while (power != 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
