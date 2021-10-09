/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:31:59 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 03:36:54 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

t_ft_err	ft_strtol_m(const char *str, t_ullint max_abs, t_llint *r)
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
		return (ft_err_fail);
	nb = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb > max_abs)
			return (ft_err_overflow);
	}
	*r = nb * sign;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i])
		return (ft_err_fail);
	return (ft_err_ok);
}

t_ft_err	ft_strtoi_m(const char *str, t_ullint max_abs, int *r)
{
	t_llint		nb;
	t_ft_err	b;

	b = ft_strtol_m(str, max_abs, &nb);
	*r = nb;
	return (b);
}

t_ft_err	ft_strtoul_m(const char *str, t_ullint max_abs, t_ullint *r)
{
	size_t		i;
	t_ullint	nb;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (!(str[i] && '0' <= str[i] && str[i] <= '9'))
		return (ft_err_fail);
	nb = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb > max_abs)
			return (ft_err_overflow);
	}
	*r = nb;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i])
		return (ft_err_fail);
	return (ft_err_ok);
}

t_ft_err	ft_strtou_m(const char *str, t_ullint max_abs, t_uint *r)
{
	t_ullint	nb;
	t_ft_err	b;

	b = ft_strtoul_m(str, max_abs, &nb);
	*r = nb;
	return (b);
}
