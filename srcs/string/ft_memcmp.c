/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:00:34 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:42:24 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

inline static int	ft_memcmp_cmp( \
		const unsigned char *s1, const unsigned char *s2)
{
	if (s1[0] != s2[0])
		return (s1[0] - s2[0]);
	if (s1[1] != s2[1])
		return (s1[1] - s2[1]);
	if (s1[2] != s2[2])
		return (s1[2] - s2[2]);
	if (s1[3] != s2[3])
		return (s1[3] - s2[3]);
	if (s1[4] != s2[4])
		return (s1[4] - s2[4]);
	if (s1[5] != s2[5])
		return (s1[5] - s2[5]);
	if (s1[6] != s2[6])
		return (s1[6] - s2[6]);
	if (s1[7] != s2[7])
		return (s1[7] - s2[7]);
	return (0);
}

int	ft_memcmp_s(const void *s1, const void *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return ((!s1 * -1) + (!s2 * 1));
	return (ft_memcmp(s1, s2, n));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			bign;

	bign = n / sizeof(int64_t);
	while (bign-- != 0)
		if (*((int64_t *)s1++) != *((int64_t *)s2++))
			return (ft_memcmp_cmp(s1 - 1, s2 - 1));
	n %= sizeof(int64_t);
	while (n-- != 0)
		if (*((t_uchar *)s1++) != *((t_uchar *)s2++))
			return (*((t_uchar *)s1 - 1) - *((t_uchar *)s2 - 1));
	return (0);
}
