/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:00:34 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:37:12 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

inline static int	ft_memcmp_cmp(const unsigned char *s1, const unsigned char *s2)
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

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	bign;

	bign = n / sizeof(__int64_t);
	while (bign-- != 0)
		if (*((__int64_t*)s1++) != *((__int64_t*)s2++))
			return (ft_memcmp_cmp(s1 - 1, s2 - 1));
	n %= sizeof(__int64_t);
	while (n-- != 0)
		if (*((unsigned char*)s1++) != *((unsigned char*)s2++))
			return (*((unsigned char*)s1 - 1) - *((unsigned char*)s2 - 1));
	return (0);
}
