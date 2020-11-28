/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:01:43 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/26 14:38:04 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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
	size_t			bign;
	const uint64_t	himagic = 0x8080808080808080LL;
	const uint64_t	lomagic = 0x0101010101010101LL;
	uint64_t		s1_longword;
	uint64_t		s2_longword;

	bign = n / sizeof(int64_t);
	while (bign-- != 0)
	{
		s1_longword = *(int64_t*)s1;
		s2_longword = *(int64_t*)s2;
		if (((s1_longword - lomagic) & ~s1_longword & himagic) != 0 ||
			((s2_longword - lomagic) & ~s2_longword & himagic) != 0)
			break;
		if (*((int64_t*)s1++) != *((int64_t*)s2++))
			return (ft_memcmp_cmp((const unsigned char*)s1 - 1, (const unsigned char*)s2 - 1));
	}
	n %= sizeof(int64_t);
	while (n-- != 0 && (*s1 || *s2))
		if (*((uchar*)s1++) != *((uchar*)s2++))
			return (*((uchar*)s1 - 1) - *((uchar*)s2 - 1));
	return (0);
}
