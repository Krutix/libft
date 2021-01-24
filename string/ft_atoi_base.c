/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:42:16 by fdiego            #+#    #+#             */
/*   Updated: 2020/12/31 23:02:10 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

<<<<<<< HEAD
int	base_validate(char *base)
=======
static int	base_validate(char *base)
>>>>>>> 30180586a5ca73ee032a9d6e0bedc168b58a2910
{
	int i;
	int base_size;

	base_size = 0;
	i = -1;
	while (base[base_size])
	{
		if (base[base_size] == '-' || base[base_size] == '+')
			return (-1);
		if (!(32 <= base[base_size] && base[base_size] <= 126))
			return (-1);
		i = -1;
		while (++i < base_size)
			if (base[i] == base[base_size])
				return (-1);
		base_size++;
	}
	return (base_size);
}

static int	in_base(char ch, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, char *base)
{
	int n;
	int i;
	int sign;
	int base_size;

	i = 0;
	n = 0;
	sign = 1;
	base_size = base_validate(base);
	if (base_size < 2)
		return (0);
	while (str[i] && ft_isspace(str[i]) && in_base(str[i], base) == -1)
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && in_base(str[i], base) != -1)
	{
		n = n * base_size + in_base(str[i], base);
		i++;
	}
	n *= sign;
	return (n);
}
