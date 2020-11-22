/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:46:30 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 03:15:57 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	unum_size(unsigned int n)
{
	size_t i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int num)
{
	char			*num_str;
	unsigned int	unum;
	size_t			size;
	int				unirminus;

	unirminus = (num < 0);
	unum = num < 0 ? -(unsigned)num : (unsigned)num;
	size = unum_size(unum) + unirminus;
	if (!(num_str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	num_str[size--] = '\0';
	while (unum >= 10)
	{
		num_str[size--] = unum % 10 + '0';
		unum /= 10;
	}
	num_str[size--] = unum % 10 + '0';
	unirminus == 1 ? num_str[size] = '-' : (void)num_str;
	return (num_str);
}
