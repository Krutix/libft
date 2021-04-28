/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:46:30 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:25:51 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_itoa(t_llint num)
{
	char			*num_str;
	unsigned int	unum;
	size_t			size;
	int				unirminus;

	unirminus = (num < 0);
	unum = num;
	if (num < 0)
		unum = -(unsigned)num;
	size = ft_ulen(unum) + unirminus;
	num_str = malloc(sizeof(char) * (size + 1));
	if (!num_str)
		return (NULL);
	num_str[size--] = '\0';
	while (unum >= 10)
	{
		num_str[size--] = unum % 10 + '0';
		unum /= 10;
	}
	num_str[size--] = unum % 10 + '0';
	if (unirminus == 1)
		num_str[size] = '-';
	return (num_str);
}
