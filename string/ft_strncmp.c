/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:01:43 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/23 03:37:05 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

inline static int	ft_strlen_check(const char *char_ptr)	
{
	if (char_ptr[0] == 0)
		return (1);
	if (char_ptr[1] == 0)
		return (2);
	if (char_ptr[2] == 0)
		return (3);
	if (char_ptr[3] == 0)
		return (4);
	if (char_ptr[4] == 0)
		return (5);
	if (char_ptr[5] == 0)
		return (6);
	if (char_ptr[6] == 0)
		return (7);
	if (char_ptr[7] == 0)
		return (8);
	return (0);
}

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

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	bign;

	bign = n / sizeof(__int64_t);
	while (bign-- != 0)
	{
		if (ft_strlen_check(s1) && ft_strlen_check(s1) == ft_strlen_check(s2))
			return (0);
		else if (*((__int64_t*)s1) != *((__int64_t*)s2))
			return (ft_memcmp_cmp((const unsigned char*)s1 - 1, (const unsigned char*)s2 - 1));
	}
	n %= sizeof(__int64_t);
	while (n-- != 0 && (*s1 || *s2))
		if (*((unsigned char*)s1++) != *((unsigned char*)s2++))
			return (*((unsigned char*)s1 - 1) - *((unsigned char*)s2 - 1));
	return (0);
}
