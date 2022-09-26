/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:39:04 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 21:52:43 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

long long	ft_atoi(const char *str)
{
	size_t		i;
	t_ullint	nb;
	char		sign;

	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	nb = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return (nb * sign);
}
