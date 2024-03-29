/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:31:59 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:32:00 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

t_bool	ft_strtol_m(const char *str, t_ullint max_abs, int64_t *r)
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
	if (!(str[i] && '0' <= str[i] && str[i] <= '9'))
		return (t_false);
	nb = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb > max_abs)
			return (t_false);
	}
	*r = nb * sign;
	return (!str[i]);
}

t_bool	ft_strtoi_m(const char *str, t_ullint max_abs, int32_t *r)
{
	int64_t	nb;
	t_bool	b;

	b = ft_strtol_m(str, max_abs, &nb);
	*r = nb;
	return (b);
}
