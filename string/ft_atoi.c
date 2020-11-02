/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:39:04 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:19:35 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_string.h"
#include <stdlib.h>

int				ft_atoi(const char *str)
{
	size_t			i;
	unsigned int	nb;
	int				sign;

	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return (nb * sign);
}
