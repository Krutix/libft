/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:42:16 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/30 23:07:50 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space_base(char ch)
{
	if (ch == ' ' || (9 <= ch && ch <= 13))
		return (1);
	return (0);
}

int	base_validate(char *base)
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

int	in_base(char ch, char *base)
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

int	ft_atoi_base(char *str, char *base)
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
	while (str[i] && is_white_space_base(str[i]) && in_base(str[i], base) == -1)
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
