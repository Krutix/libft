/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:31:40 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/01 21:50:15 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_swapi(int *a, int *b)
{
	int buff;

	buff = *a;
	*a = *b;
	*b = buff;
}

void	ft_swapf(float *a, float *b)
{
	float buff;

	buff = *a;
	*a = *b;
	*b = buff;
}
