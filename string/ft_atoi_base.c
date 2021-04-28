/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:42:16 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:31:38 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_llint	ft_atoi_base(char *str, char *base)
{
	t_ullint	n;
	int			i;
	int			sign;
	int			base_size;

	i = 0;
	n = 0;
	sign = 1;
	base_size = ft_strlen(base);
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && ft_strchr(base, str[i]) != NULL)
	{
		n = n * base_size + (ft_strchr(base, str[i]) - base);
		i++;
	}
	n *= sign;
	return (n);
}
